#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include <sstream>
#include <tf/transform_datatypes.h>
//#include "crcl.h"
//#include "RCS.h"

#ifndef Deg2Rad
#define Deg2Rad(Ang)    ( (double) ( Ang * M_PI / 180.0 ) )
#define Rad2Deg(Ang)    ( (double) ( Ang * 180.0 / M_PI ) )
#define MM2Meter(d)     ( (double) ( d / 1000.00 ) )
#define Meter2MM(d)     ( (double) ( d * 1000.00 ) )
#endif
typedef Eigen::Matrix<double, 3, 3, Eigen::ColMajor> MatrixCol3Xd;
typedef Eigen::Matrix<double, 3, 3, Eigen::ColMajor> MatrixRow3Xd;

void TestMatrixDominance() {
    std::stringstream ss;
    printf("---\n");
    std::cout << "Eigen matrix 0,1,2,3,4,5,6,7,8 becomes:\n";
    Eigen::Matrix3d m;
    m << 0, 1, 2, 3, 4, 5, 6, 7, 8;
    printf("%f %f %f\n", m(0, 0), m(0, 1), m(0, 2));
    printf("%f %f %f\n", m(1, 0), m(1, 1), m(1, 2));
    printf("%f %f %f\n", m(2, 0), m(2, 1), m(2, 2));

    printf("---\n");
    std::cout << "Eigen declared column major matrix 0,1,2,3,4,5,6,7,8 becomes:\n";
    MatrixCol3Xd mcol;
    mcol.resize(3, 3);
    mcol << 0, 1, 2, 3, 4, 5, 6, 7, 8;
    printf("%f %f %f\n", mcol(0, 0), mcol(0, 1), mcol(0, 2));
    printf("%f %f %f\n", mcol(1, 0), mcol(1, 1), mcol(1, 2));
    printf("%f %f %f\n", mcol(2, 0), mcol(2, 1), mcol(2, 2));
    ss << mcol;
    std::cout << ss.str();
    printf("\n---\n");
    std::cout << "Eigen declared row major matrix 0,1,2,3,4,5,6,7,8 becomes:\n";

    MatrixRow3Xd mrow;
    mrow.resize(3, 3);
    mrow << 0, 1, 2, 3, 4, 5, 6, 7, 8;
    printf("%f %f %f\n", mrow(0, 0), mrow(0, 1), mrow(0, 2));
    printf("%f %f %f\n", mrow(1, 0), mrow(1, 1), mrow(1, 2));
    printf("%f %f %f\n", mrow(2, 0), mrow(2, 1), mrow(2, 2));
    ss.str("");
    ss << mrow;
    std::cout << ss.str();

    printf("\n---\n");
    std::cout << "tf::matrix 0,1,2,3,4,5,6,7,8 becomes:\n";
    tf::Matrix3x3 mout(0, 1, 2,
            3, 4, 5,
            6, 7, 8);
    printf("%f %f %f\n", mout[0][0], mout[0][1], mout[0][2]);
    printf("%f %f %f\n", mout[1][0], mout[1][1], mout[1][2]);
    printf("%f %f %f\n", mout[2][0], mout[2][1], mout[2][2]);

}

tf::Matrix3x3 GetTfRotationMatrix(tf::Vector3 xaxis, tf::Vector3 zaxis) {
    tf::Matrix3x3 m;
    tf::Vector3 yaxis = zaxis.cross(xaxis);
    m.setValue(xaxis.getX(), yaxis.getX(), zaxis.getX(),
            xaxis.getY(), yaxis.getY(), zaxis.getY(),
            xaxis.getZ(), yaxis.getZ(), zaxis.getZ());
    return m;
}

tf::Matrix3x3 GetTfRotationMatrix(double roll, double pitch, double yaw) {
    tf::Matrix3x3 m;
    m.setRPY(roll, pitch, yaw);
    return m;
}

void GetRPY(const tf::Matrix3x3 &m, double &r, double &p, double &y) {
    m.getRPY(r, p, y);
}

void GetHighland(const tf::Matrix3x3 & m, tf::Vector3 & xaxis, tf::Vector3 & zaxis) {
    tf::Vector3 v1, v2, v3;
    xaxis = m.getColumn(0);
    zaxis = m.getColumn(2);
}

void TestRpy(double r, double p, double y) {
    tf::Matrix3x3 m;
    tf::Vector3 v1, v2, v3;
    tf::Quaternion q;
    printf("IN: %f %f %f\n", r, p, y);
    m.setRPY(r, p, y);

    v1 = m.getColumn(0);
    v2 = m.getColumn(1);
    v3 = m.getColumn(2);

    // the rotation matrix, by visual columns
    printf("%f %f %f\n", v1.getX(), v2.getX(), v3.getX());
    printf("%f %f %f\n", v1.getY(), v2.getY(), v3.getY());
    printf("%f %f %f\n", v1.getZ(), v2.getZ(), v3.getZ());

    // the rotation matrix, by matrix[row][column]
    printf("---\n");
    printf("%f %f %f\n", m[0][0], m[0][1], m[0][2]);
    printf("%f %f %f\n", m[1][0], m[1][1], m[1][2]);
    printf("%f %f %f\n", m[2][0], m[2][1], m[2][2]);
    tf::Matrix3x3 mout(v1.getX(), v2.getX(), v3.getX(),
            v1.getY(), v2.getY(), v3.getY(),
            v1.getZ(), v2.getZ(), v3.getZ());

    // the quaternion
    q.setRPY(r, p, y);
    printf("---\n");
    printf("%f %f %f %f\n", q.getX(), q.getY(), q.getZ(), q.getW());

    // check the output rpy
    mout.getRPY(r, p, y);
    printf("---\n");
    printf("OUT: %f %f %f\n", r, p, y);
}

TEST(TestSuite, testCaseRpy) {
    //std::cout << "Check row versus column major matrice\n";
    // TestRpy(0.1, 0, 0);
    double r = 90, p = 0, y = 90;
    printf(" IN: %f %f %f\n", r, p, y);
    tf::Matrix3x3 m = GetTfRotationMatrix(Deg2Rad(r), Deg2Rad(p), Deg2Rad(y));
    GetRPY(m, r, p, y);
    printf("OUT: %f %f %f\n", Rad2Deg(r), Rad2Deg(p), Rad2Deg(y));
    tf::Vector3 xaxis, zaxis;
    GetHighland(m, xaxis, zaxis);
    printf("%f %f %f\n", xaxis.getX(), xaxis.getY(), xaxis.getZ());
    printf("%f %f %f\n", zaxis.getX(), zaxis.getY(), zaxis.getZ());

}

TEST(TestSuite, testCase1) {
    ASSERT_EQ(1, 1) << "Vectors 1 and 1 not equal";
    //TestMatrixDominance();
    double r, p, y;
    //tf::Matrix3x3 m = GetTfRotationMatrix(tf::Vector3(0, 0, 1), tf::Vector3(1, 0, 0));
    tf::Matrix3x3 m = GetTfRotationMatrix(tf::Vector3(0, 0.1, 0), tf::Vector3(0, 0, 0));
    m.getRPY(r, p, y);
    // std::cout << "TF Set/GetRPY Roll pitch yaw = (-180., -90., 0.)" << Rad2Deg(r) << ":" << Rad2Deg(p) << ":" << Rad2Deg(y) << std::endl;
    std::cout << "TF Set/GetRPY Roll pitch yaw = ([0,.1,0][0,0,0].)" << Rad2Deg(r) << ":" << Rad2Deg(p) << ":" << Rad2Deg(y) << std::endl;
}

int main(int argc, char ** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}