
#ifndef BOXVOLUME_H_
#define BOXVOLUME_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include <vector>
 #include "Robot.h"
 class Robot;
 #include <vector>
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "Point.h"
 class Point;
class BoxVolume: public DataThing{private:
std::string name;
int BoxVolumeID;
DAO* dao;
Point* hasBoxVolume_MaximumPoint;
Point* hasBoxVolume_MinimumPoint;
std::vector<KittingWorkstation*> hasWorkstation_OtherObstacles;
std::vector<Robot*> hasRobot_WorkVolume;
public:
BoxVolume(std::string name);
~BoxVolume();
 void get(int id);
 void get(std::string name);
void set(int id, BoxVolume* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getBoxVolumeID();
void setBoxVolumeID(int _BoxVolumeID);
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasBoxVolume_MaximumPoint();
void sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint);
Point* gethasBoxVolume_MinimumPoint();
void sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint);
std::vector<KittingWorkstation*> gethasWorkstation_OtherObstacles();
void sethasWorkstation_OtherObstacles(std::vector<KittingWorkstation*> _hasWorkstation_OtherObstacles);
std::vector<Robot*> gethasRobot_WorkVolume();
void sethasRobot_WorkVolume(std::vector<Robot*> _hasRobot_WorkVolume);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* BOXVOLUME_H_ */