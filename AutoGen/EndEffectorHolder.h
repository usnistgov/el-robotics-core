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


#ifndef ENDEFFECTORHOLDER_H_
#define ENDEFFECTORHOLDER_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
class EndEffector;
class EndEffectorChangingStation;
class DAO;
class EndEffectorHolder:public SolidObject
{
private:
  std::string name;
  int EndEffectorHolderID;
  DAO *dao;
  EndEffectorChangingStation *hadByEndEffectorHolder_ChangingStation;
  EndEffector *hasEndEffectorHolder_EndEffector;
public:
    EndEffectorHolder (std::string name);
   ~EndEffectorHolder ();
  void get (int id);
  void get (std::string name);
  void set (int id, EndEffectorHolder * obj);
  void set (std::string name);
    std::string getname ();
  int getEndEffectorHolderID ();
  DAO *getdao ();
  void setdao (DAO * _dao);
  EndEffectorChangingStation *gethadByEndEffectorHolder_ChangingStation ();
  void sethadByEndEffectorHolder_ChangingStation (EndEffectorChangingStation *
						  _hadByEndEffectorHolder_ChangingStation);
  EndEffector *gethasEndEffectorHolder_EndEffector ();
  void sethasEndEffectorHolder_EndEffector (EndEffector *
					    _hasEndEffectorHolder_EndEffector);
  void copy (std::map < std::string, std::string > object);
    std::vector < std::string > Explode (const std::string & str,
					 char separator);
};
#endif /* ENDEFFECTORHOLDER_H_ */
