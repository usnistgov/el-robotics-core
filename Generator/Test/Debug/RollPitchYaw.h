
#ifndef ROLLPITCHYAW_H_
#define ROLLPITCHYAW_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
class RollPitchYaw: public DataThing {private:
float hasRpy_Roll;
float hasRpy_Pitch;
float hasRpy_Yaw;
std::string name;
int id;
DAO* dao;
public:
RollPitchYaw(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, RollPitchYaw* obj);
void set(std::string name, RollPitchYaw* obj);
float gethasRpy_Roll();
void sethasRpy_Roll(float _hasRpy_Roll);
float gethasRpy_Pitch();
void sethasRpy_Pitch(float _hasRpy_Pitch);
float gethasRpy_Yaw();
void sethasRpy_Yaw(float _hasRpy_Yaw);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(RollPitchYaw const& object);
}; 
#endif /* ROLLPITCHYAW_H_ */