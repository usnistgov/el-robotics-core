
#ifndef ROLLPITCHYAW_H_
#define ROLLPITCHYAW_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "PartRefAndPose.h"
 class PartRefAndPose;
 #include "Pose.h"
 class Pose;
class RollPitchYaw: public DataThing{private:
double hasRpy_Roll;
double hasRpy_Pitch;
double hasRpy_Yaw;
std::string name;
int RollPitchYawID;
DAO* dao;
Pose* hasPose_Rpy;
PartRefAndPose* hasPartRefAndPose_Rpy;
public:
RollPitchYaw(std::string name);
~RollPitchYaw();
 void get(int id);
 void get(std::string name);
void set(int id, RollPitchYaw* obj);
void set(std::string name);
double gethasRpy_Roll();
void sethasRpy_Roll(double _hasRpy_Roll);
double gethasRpy_Pitch();
void sethasRpy_Pitch(double _hasRpy_Pitch);
double gethasRpy_Yaw();
void sethasRpy_Yaw(double _hasRpy_Yaw);
std::string getname();
void setname(std::string _name);
int getRollPitchYawID();
void setRollPitchYawID(int _RollPitchYawID);
DAO* getdao();
void setdao(DAO* _dao);
Pose* gethasPose_Rpy();
void sethasPose_Rpy(Pose* _hasPose_Rpy);
PartRefAndPose* gethasPartRefAndPose_Rpy();
void sethasPartRefAndPose_Rpy(PartRefAndPose* _hasPartRefAndPose_Rpy);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ROLLPITCHYAW_H_ */