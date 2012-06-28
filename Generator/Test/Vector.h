/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/


#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class DAO;
 class PartRefAndPose;
 class PoseLocation;
class Vector: public DataThing{private:
double hasVector_K;
double hasVector_J;
double hasVector_I;
std::string name;
int VectorID;
DAO* dao;
std::vector<PartRefAndPose*> hasPartRefAndPose_ZAxis;
std::vector<PartRefAndPose*> hasPartRefAndPose_XAxis;
std::vector<PoseLocation*> hasPoseLocation_ZAxis;
std::vector<PoseLocation*> hasPoseLocation_XAxis;
public:
Vector(std::string name);
~Vector();
 void get(int id);
 void get(std::string name);
void set(int id, Vector* obj);
void set(std::string name);
double gethasVector_K();
void sethasVector_K(double _hasVector_K);
double gethasVector_J();
void sethasVector_J(double _hasVector_J);
double gethasVector_I();
void sethasVector_I(double _hasVector_I);
std::string getname();
int getVectorID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<PartRefAndPose*>* gethasPartRefAndPose_ZAxis();
void sethasPartRefAndPose_ZAxis(std::vector<PartRefAndPose*> _hasPartRefAndPose_ZAxis);
std::vector<PartRefAndPose*>* gethasPartRefAndPose_XAxis();
void sethasPartRefAndPose_XAxis(std::vector<PartRefAndPose*> _hasPartRefAndPose_XAxis);
std::vector<PoseLocation*>* gethasPoseLocation_ZAxis();
void sethasPoseLocation_ZAxis(std::vector<PoseLocation*> _hasPoseLocation_ZAxis);
std::vector<PoseLocation*>* gethasPoseLocation_XAxis();
void sethasPoseLocation_XAxis(std::vector<PoseLocation*> _hasPoseLocation_XAxis);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VECTOR_H_ */