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


#ifndef KIT_H_
#define KIT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class LargeBoxWithKits;
 class KitTray;
 class DAO;
 class Part;
class Kit: public SolidObject{private:
std::string hasKit_DesignRef;
bool isKit_Finished;
std::string name;
int KitID;
DAO* dao;
LargeBoxWithKits* hadByKit_LargeBoxWithKits;
KitTray* hasKit_Tray;
std::vector<Part*> hadByPart_Kit;
public:
Kit(std::string name);
~Kit();
 void get(int id);
 void get(std::string name);
void set(int id, Kit* obj);
void set(std::string name);
std::string gethasKit_DesignRef();
void sethasKit_DesignRef(std::string _hasKit_DesignRef);
bool getisKit_Finished();
void setisKit_Finished(bool _isKit_Finished);
std::string getname();
int getKitID();
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithKits* gethadByKit_LargeBoxWithKits();
void sethadByKit_LargeBoxWithKits(LargeBoxWithKits* _hadByKit_LargeBoxWithKits);
KitTray* gethasKit_Tray();
void sethasKit_Tray(KitTray* _hasKit_Tray);
std::vector<Part*>* gethadByPart_Kit();
void sethadByPart_Kit(std::vector<Part*> _hadByPart_Kit);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KIT_H_ */