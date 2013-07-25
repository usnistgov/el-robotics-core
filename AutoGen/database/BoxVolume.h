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


#ifndef BOXVOLUME_H_
#define BOXVOLUME_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class Robot;
 class KittingWorkstation;
 class DAO;
 class Point;
class BoxVolume: public DataThing{private:
int BoxVolumeID;
DAO* dao;
KittingWorkstation* hadByOtherObstacle_KittingWorkstation;
Robot* hadByWorkVolume_Robot;
Point* hasBoxVolume_MaximumPoint;
Point* hasBoxVolume_MinimumPoint;
public:
BoxVolume(std::string name);
~BoxVolume();
 void get(int id);
 void get(std::string name);
void set(int id, BoxVolume* obj);
void set(std::string name);
int getBoxVolumeID();
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByOtherObstacle_KittingWorkstation();
void sethadByOtherObstacle_KittingWorkstation(KittingWorkstation* _hadByOtherObstacle_KittingWorkstation);
Robot* gethadByWorkVolume_Robot();
void sethadByWorkVolume_Robot(Robot* _hadByWorkVolume_Robot);
Point* gethasBoxVolume_MaximumPoint();
void sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint);
Point* gethasBoxVolume_MinimumPoint();
void sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* BOXVOLUME_H_ */