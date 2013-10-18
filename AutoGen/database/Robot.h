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


#ifndef ROBOT_H_
#define ROBOT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "NoSkuObject.h"
 class BoxVolume;
 class EndEffector;
 class KittingWorkstation;
 class DAO;
class Robot: public NoSkuObject{private:
std::string hasRobot_Description;
double hasRobot_MaximumLoadWeight;
int RobotID;
DAO* dao;
EndEffector* hadByEndEffector_Robot;
std::vector<BoxVolume*> hadByWorkVolume_Robot;
KittingWorkstation* hasKittingWorkstation_Robot;
public:
Robot(std::string name);
~Robot();
 void get(int id);
 void get(std::string name);
void set(int id, Robot* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasRobot_Description();
void sethasRobot_Description(std::string _hasRobot_Description);
double gethasRobot_MaximumLoadWeight();
void sethasRobot_MaximumLoadWeight(double _hasRobot_MaximumLoadWeight);
int getRobotID();
void setRobotID(int _RobotID);
DAO* getdao();
void setdao(DAO* _dao);
EndEffector* gethadByEndEffector_Robot();
void sethadByEndEffector_Robot(EndEffector* _hadByEndEffector_Robot);
std::vector<BoxVolume*> gethadByWorkVolume_Robot();
void sethadByWorkVolume_Robot(std::vector<BoxVolume*> _hadByWorkVolume_Robot);
KittingWorkstation* gethasKittingWorkstation_Robot();
void sethasKittingWorkstation_Robot(KittingWorkstation* _hasKittingWorkstation_Robot);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ROBOT_H_ */