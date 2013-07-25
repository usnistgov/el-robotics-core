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


#ifndef PARTSTRAYWITHPARTS_H_
#define PARTSTRAYWITHPARTS_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class DAO;
 class Part;
 class PartsTray;
class PartsTrayWithParts: public SolidObject{private:
int PartsTrayWithPartsID;
DAO* dao;
PartsTray* hasPartsTrayWithParts_PartsTray;
std::vector<Part*> hadByPart_PartsTrayWithParts;
public:
PartsTrayWithParts(std::string name);
~PartsTrayWithParts();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTrayWithParts* obj);
void set(std::string name);
int getPartsTrayWithPartsID();
DAO* getdao();
void setdao(DAO* _dao);
PartsTray* gethasPartsTrayWithParts_PartsTray();
void sethasPartsTrayWithParts_PartsTray(PartsTray* _hasPartsTrayWithParts_PartsTray);
std::vector<Part*> gethadByPart_PartsTrayWithParts();
void sethadByPart_PartsTrayWithParts(std::vector<Part*> _hadByPart_PartsTrayWithParts);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAYWITHPARTS_H_ */