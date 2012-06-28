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


#ifndef PARTSTRAY_H_
#define PARTSTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "BoxyObject.h"
 class PartsTrayWithParts;
 class DAO;
class PartsTray: public BoxyObject{private:
std::string hasPartsTray_SkuRef;
std::string hasPartsTray_SerialNumber;
std::string name;
int PartsTrayID;
DAO* dao;
PartsTrayWithParts* hasPartsTrayWithParts_Tray;
public:
PartsTray(std::string name);
~PartsTray();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTray* obj);
void set(std::string name);
std::string gethasPartsTray_SkuRef();
void sethasPartsTray_SkuRef(std::string _hasPartsTray_SkuRef);
std::string gethasPartsTray_SerialNumber();
void sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber);
std::string getname();
int getPartsTrayID();
DAO* getdao();
void setdao(DAO* _dao);
PartsTrayWithParts* gethasPartsTrayWithParts_Tray();
void sethasPartsTrayWithParts_Tray(PartsTrayWithParts* _hasPartsTrayWithParts_Tray);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAY_H_ */