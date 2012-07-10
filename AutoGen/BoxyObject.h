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


#ifndef BOXYOBJECT_H_
#define BOXYOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
class DAO;
class BoxyObject:public SolidObject
{
private:
  double hasBox_Height;
  double hasBox_Width;
  double hasBox_Length;
    std::string name;
  int BoxyObjectID;
  DAO *dao;
public:
    BoxyObject (std::string name);
   ~BoxyObject ();
  void get (int id);
  void get (std::string name);
  void set (int id, BoxyObject * obj);
  void set (std::string name);
  double gethasBox_Height ();
  void sethasBox_Height (double _hasBox_Height);
  double gethasBox_Width ();
  void sethasBox_Width (double _hasBox_Width);
  double gethasBox_Length ();
  void sethasBox_Length (double _hasBox_Length);
    std::string getname ();
  int getBoxyObjectID ();
  DAO *getdao ();
  void setdao (DAO * _dao);
  void copy (std::map < std::string, std::string > object);
    std::vector < std::string > Explode (const std::string & str,
					 char separator);
};
#endif /* BOXYOBJECT_H_ */
