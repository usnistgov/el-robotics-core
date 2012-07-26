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


#include "SolidObject.h"
 class BoxVolume;
 class EndEffector;
 class KittingWorkstation;
 class DAO;
class Robot: public SolidObject{private:
std::string hasRobot_Description;
std::string hasRobot_Id;
double hasRobot_MaximumLoadWeight;
int RobotID;
DAO* dao;
EndEffector* hadByEndEffector_Robot;
std::vector<BoxVolume*> hasRobot_WorkVolume;
KittingWorkstation* hasWorkstation_Robot;
public:
Robot(std::string name);
~Robot();
 void get(int id);
 void get(std::string name);
void set(int id, Robot* obj);
void set(std::string name);
std::string gethasRobot_Description();
void sethasRobot_Description(std::string _hasRobot_Description);
std::string gethasRobot_Id();
void sethasRobot_Id(std::string _hasRobot_Id);
double gethasRobot_MaximumLoadWeight();
void sethasRobot_MaximumLoadWeight(double _hasRobot_MaximumLoadWeight);
int getRobotID();
DAO* getdao();
void setdao(DAO* _dao);
EndEffector* gethadByEndEffector_Robot();
void sethadByEndEffector_Robot(EndEffector* _hadByEndEffector_Robot);
std::vector<BoxVolume*>* gethasRobot_WorkVolume();
void sethasRobot_WorkVolume(std::vector<BoxVolume*> _hasRobot_WorkVolume);
KittingWorkstation* gethasWorkstation_Robot();
void sethasWorkstation_Robot(KittingWorkstation* _hasWorkstation_Robot);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ROBOT_H_ */