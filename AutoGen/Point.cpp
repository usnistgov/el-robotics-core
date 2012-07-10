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

#include "Point.h"


#include "BoxVolume.h"
#include "DAO.h"
#include "PartRefAndPose.h"
#include "PoseLocation.h"

Point::Point (std::string name):DataThing (name)
{
  this->name = name;
  dao = NULL;

}

Point::~Point ()
{
  delete (dao);
  for (std::size_t i = 0; i < hasPartRefAndPose_Point.size (); i++)
    delete (hasPartRefAndPose_Point[i]);
  for (std::size_t i = 0; i < hasBoxVolume_MaximumPoint.size (); i++)
    delete (hasBoxVolume_MaximumPoint[i]);
  for (std::size_t i = 0; i < hasBoxVolume_MinimumPoint.size (); i++)
    delete (hasBoxVolume_MinimumPoint[i]);
  for (std::size_t i = 0; i < hasPoseLocation_Point.size (); i++)
    delete (hasPoseLocation_Point[i]);
}

double
Point::gethasPoint_X ()
{
  return hasPoint_X;
}

double
Point::gethasPoint_Y ()
{
  return hasPoint_Y;
}

double
Point::gethasPoint_Z ()
{
  return hasPoint_Z;
}

std::string Point::getname ()
{
  return name;
}

int
Point::getPointID ()
{
  return PointID;
}

DAO *
Point::getdao ()
{
  return dao;
}

std::vector < PartRefAndPose * >*Point::gethasPartRefAndPose_Point ()
{
  return &hasPartRefAndPose_Point;
}

std::vector < BoxVolume * >*Point::gethasBoxVolume_MaximumPoint ()
{
  return &hasBoxVolume_MaximumPoint;
}

std::vector < BoxVolume * >*Point::gethasBoxVolume_MinimumPoint ()
{
  return &hasBoxVolume_MinimumPoint;
}

std::vector < PoseLocation * >*Point::gethasPoseLocation_Point ()
{
  return &hasPoseLocation_Point;
}

void
Point::sethasPoint_X (double _hasPoint_X)
{
  this->hasPoint_X = _hasPoint_X;
}

void
Point::sethasPoint_Y (double _hasPoint_Y)
{
  this->hasPoint_Y = _hasPoint_Y;
}

void
Point::sethasPoint_Z (double _hasPoint_Z)
{
  this->hasPoint_Z = _hasPoint_Z;
}

void
Point::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
Point::sethasPartRefAndPose_Point (std::vector <
				   PartRefAndPose * >_hasPartRefAndPose_Point)
{
  this->hasPartRefAndPose_Point = _hasPartRefAndPose_Point;
}

void
Point::sethasBoxVolume_MaximumPoint (std::vector <
				     BoxVolume * >_hasBoxVolume_MaximumPoint)
{
  this->hasBoxVolume_MaximumPoint = _hasBoxVolume_MaximumPoint;
}

void
Point::sethasBoxVolume_MinimumPoint (std::vector <
				     BoxVolume * >_hasBoxVolume_MinimumPoint)
{
  this->hasBoxVolume_MinimumPoint = _hasBoxVolume_MinimumPoint;
}

void
Point::sethasPoseLocation_Point (std::vector <
				 PoseLocation * >_hasPoseLocation_Point)
{
  this->hasPoseLocation_Point = _hasPoseLocation_Point;
}

void
Point::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("DataThing");
  temp = dao->get (name);
  delete (dao);
  DataThing::copy (temp);
  dao = new DAO ("Point");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
Point::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  DataThing *temp = (DataThing *) this;
  temp->set (name);
  ss.str ("");
  ss << hasPoint_X;
  data["hasPoint_X"] = ss.str ();
  ss.str ("");
  ss << hasPoint_Y;
  data["hasPoint_Y"] = ss.str ();
  ss.str ("");
  ss << hasPoint_Z;
  data["hasPoint_Z"] = ss.str ();
  data["name"] = name;
  ss.str ("");
  ss << PointID;
  data["PointID"] = ss.str ();
  for (unsigned int i = 0; i < hasPartRefAndPose_Point.size (); ++i)
    {
      ss.str ("");
      hasPartRefAndPose_Point[i]->get (hasPartRefAndPose_Point[i]->
				       getname ());
      ss << hasPartRefAndPose_Point[i]->getPartRefAndPoseID ();
      data["hasPartRefAndPose_Point"] =
	data["hasPartRefAndPose_Point"] + " " + ss.str ();
    }
  for (unsigned int i = 0; i < hasBoxVolume_MaximumPoint.size (); ++i)
    {
      ss.str ("");
      hasBoxVolume_MaximumPoint[i]->get (hasBoxVolume_MaximumPoint[i]->
					 getname ());
      ss << hasBoxVolume_MaximumPoint[i]->getBoxVolumeID ();
      data["hasBoxVolume_MaximumPoint"] =
	data["hasBoxVolume_MaximumPoint"] + " " + ss.str ();
    }
  for (unsigned int i = 0; i < hasBoxVolume_MinimumPoint.size (); ++i)
    {
      ss.str ("");
      hasBoxVolume_MinimumPoint[i]->get (hasBoxVolume_MinimumPoint[i]->
					 getname ());
      ss << hasBoxVolume_MinimumPoint[i]->getBoxVolumeID ();
      data["hasBoxVolume_MinimumPoint"] =
	data["hasBoxVolume_MinimumPoint"] + " " + ss.str ();
    }
  for (unsigned int i = 0; i < hasPoseLocation_Point.size (); ++i)
    {
      ss.str ("");
      hasPoseLocation_Point[i]->get (hasPoseLocation_Point[i]->getname ());
      ss << hasPoseLocation_Point[i]->getPoseLocationID ();
      data["hasPoseLocation_Point"] =
	data["hasPoseLocation_Point"] + " " + ss.str ();
    }
  dao = new DAO ("Point");
  dao->set (data);
  delete (dao);
}

void
Point::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < Point * >tmp;
  this->hasPoint_X = std::atof (object["Point.hasPoint_X"].c_str ());
  this->hasPoint_Y = std::atof (object["Point.hasPoint_Y"].c_str ());
  this->hasPoint_Z = std::atof (object["Point.hasPoint_Z"].c_str ());
  this->name = object["Point._NAME"];
  this->PointID = std::atof (object["Point.PointID"].c_str ());
  if (this->hasPartRefAndPose_Point.empty ()
      && object["hasPartRefAndPose_Point/PartRefAndPose._NAME"] != "")
    {
      temp =
	Explode (object["hasPartRefAndPose_Point/PartRefAndPose._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hasPartRefAndPose_Point.
	    push_back (new PartRefAndPose (temp[i]));
	}
    }
  if (this->hasBoxVolume_MaximumPoint.empty ()
      && object["hasBoxVolume_MaximumPoint/BoxVolume._NAME"] != "")
    {
      temp =
	Explode (object["hasBoxVolume_MaximumPoint/BoxVolume._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hasBoxVolume_MaximumPoint.push_back (new BoxVolume (temp[i]));
	}
    }
  if (this->hasBoxVolume_MinimumPoint.empty ()
      && object["hasBoxVolume_MinimumPoint/BoxVolume._NAME"] != "")
    {
      temp =
	Explode (object["hasBoxVolume_MinimumPoint/BoxVolume._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hasBoxVolume_MinimumPoint.push_back (new BoxVolume (temp[i]));
	}
    }
  if (this->hasPoseLocation_Point.empty ()
      && object["hasPoseLocation_Point/PoseLocation._NAME"] != "")
    {
      temp =
	Explode (object["hasPoseLocation_Point/PoseLocation._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hasPoseLocation_Point.push_back (new PoseLocation (temp[i]));
	}
    }

} std::vector < std::string > Point::Explode (const std::string & str,
					      char separator)
{
  std::vector < std::string > result;
  std::size_t pos1 = 0;
  std::size_t pos2 = 0;
  while (pos2 != str.npos)
    {
      pos2 = str.find (separator, pos1);
      if (pos2 != str.npos)
	{
	  if (pos2 > pos1)
	    result.push_back (str.substr (pos1, pos2 - pos1));
	  pos1 = pos2 + 1;
	}
    }
  result.push_back (str.substr (pos1, str.size () - pos1));
  return result;
}
