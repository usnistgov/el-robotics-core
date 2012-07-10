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


#ifndef LARGEBOXWITHKITS_H_
#define LARGEBOXWITHKITS_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
class Kit;
class LargeContainer;
class DAO;
class LargeBoxWithKits:public SolidObject
{
private:
  std::string hasLargeBoxWithKits_Capacity;
  std::string hasLargeBoxWithKits_KitDesignRef;
  std::string name;
  int LargeBoxWithKitsID;
  DAO *dao;
  LargeContainer *hasLargeBoxWithKits_LargeContainer;
    std::vector < Kit * >hadByKit_LargeBoxWithKits;
public:
    LargeBoxWithKits (std::string name);
   ~LargeBoxWithKits ();
  void get (int id);
  void get (std::string name);
  void set (int id, LargeBoxWithKits * obj);
  void set (std::string name);
    std::string gethasLargeBoxWithKits_Capacity ();
  void sethasLargeBoxWithKits_Capacity (std::
					string _hasLargeBoxWithKits_Capacity);
    std::string gethasLargeBoxWithKits_KitDesignRef ();
  void sethasLargeBoxWithKits_KitDesignRef (std::
					    string
					    _hasLargeBoxWithKits_KitDesignRef);
    std::string getname ();
  int getLargeBoxWithKitsID ();
  DAO *getdao ();
  void setdao (DAO * _dao);
  LargeContainer *gethasLargeBoxWithKits_LargeContainer ();
  void sethasLargeBoxWithKits_LargeContainer (LargeContainer *
					      _hasLargeBoxWithKits_LargeContainer);
    std::vector < Kit * >*gethadByKit_LargeBoxWithKits ();
  void sethadByKit_LargeBoxWithKits (std::vector <
				     Kit * >_hadByKit_LargeBoxWithKits);
  void copy (std::map < std::string, std::string > object);
    std::vector < std::string > Explode (const std::string & str,
					 char separator);
};
#endif /* LARGEBOXWITHKITS_H_ */
