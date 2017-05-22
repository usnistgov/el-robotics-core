#ifndef ROSTHREAD_H
#define ROSTHREAD_H

#include <QObject>
#include <QThread>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <sensor_msgs/JointState.h>

#include "tablevector.h"
#include <map>

#define StdVector
#ifndef RVector
#ifdef StdVector
#include <vector>
#define RVector  std::vector
#else
#include <QVector>
#define RVector  std::vector
#endif
#endif

struct RobotDef
{
    std::map<std::string, std::vector<std::string> > jointnames;
    std::map<std::string, double  > jointposvalues;  // these are raw values not sorted by robot

    int pubvel;
    int pubeffort;
    int pubpos;
    std::string eelink, world;
    size_t maxjoints()
    {
        size_t jnmax =0;
        std::map<std::string, std::vector<std::string> >::iterator it = jointnames.begin();
        for(; it!= jointnames.end(); it++)
        {
            if((*it).second.size() > jnmax)
                jnmax=(*it).second.size();
        }
        return jnmax;
    }

};
class RosThread : public QThread
{
    Q_OBJECT
public:
    RosThread(QObject *parent = 0);
    void run();

    tf::Pose    xform(std::string world, std::string eelink);
    void setTableItems(QTableItems * tableitems);
    void callback(const sensor_msgs::JointState::ConstPtr& msg);
    void posecallback(const geometry_msgs::Pose::ConstPtr &msg,  std::string &topic);
    void aposecallback(const geometry_msgs::Pose::ConstPtr &msg);
    ///////////////////////////////
    std::vector<std::string> poses;
    std::vector<ros::Subscriber> subs;
    std::map<std::string, tf::Pose> posevalues;

    bool abort;
    tf::TransformListener * listener;
    tf::StampedTransform * transform;

    QTableItems * _tableitems;
    QTableItems * _jnttableitems;
    RVector<RVector<double> > val;
    RobotDef robots;
    ros::Subscriber sub;
signals:
    void master_found_signal(int r);

public slots:

};

#endif // ROSTHREAD_H
