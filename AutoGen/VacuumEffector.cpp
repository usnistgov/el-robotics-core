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

#include "VacuumEffector.h"


#include "DAO.h"

VacuumEffector::VacuumEffector (std::string name):EndEffector (name)
{
  this->name = name;
  dao = NULL;

}

VacuumEffector::~VacuumEffector ()
{
  delete (dao);
}

double
VacuumEffector::gethasVacuumEffector_CupDiameter ()
{
  return hasVacuumEffector_CupDiameter;
}

double
VacuumEffector::gethasVacuumEffector_Length ()
{
  return hasVacuumEffector_Length;
}

std::string VacuumEffector::getname ()
{
  return name;
}

int
VacuumEffector::getVacuumEffectorID ()
{
  return VacuumEffectorID;
}

DAO *
VacuumEffector::getdao ()
{
  return dao;
}

void
VacuumEffector::
sethasVacuumEffector_CupDiameter (double _hasVacuumEffector_CupDiameter)
{
  this->hasVacuumEffector_CupDiameter = _hasVacuumEffector_CupDiameter;
}

void
VacuumEffector::sethasVacuumEffector_Length (double _hasVacuumEffector_Length)
{
  this->hasVacuumEffector_Length = _hasVacuumEffector_Length;
}

void
VacuumEffector::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
VacuumEffector::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("EndEffector");
  temp = dao->get (name);
  delete (dao);
  EndEffector::copy (temp);
  dao = new DAO ("VacuumEffector");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
VacuumEffector::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  EndEffector *temp = (EndEffector *) this;
  temp->set (name);
  ss.str ("");
  ss << hasVacuumEffector_CupDiameter;
  data["hasVacuumEffector_CupDiameter"] = ss.str ();
  ss.str ("");
  ss << hasVacuumEffector_Length;
  data["hasVacuumEffector_Length"] = ss.str ();
  data["name"] = name;
  ss.str ("");
  ss << VacuumEffectorID;
  data["VacuumEffectorID"] = ss.str ();
  dao = new DAO ("VacuumEffector");
  dao->set (data);
  delete (dao);
}

void
VacuumEffector::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < VacuumEffector * >tmp;
  this->hasVacuumEffector_CupDiameter =
    std::atof (object["VacuumEffector.hasVacuumEffector_CupDiameter"].
	       c_str ());
  this->hasVacuumEffector_Length =
    std::atof (object["VacuumEffector.hasVacuumEffector_Length"].c_str ());
  this->name = object["VacuumEffector._NAME"];
  this->VacuumEffectorID =
    std::atof (object["VacuumEffector.VacuumEffectorID"].c_str ());

} std::vector < std::string >
  VacuumEffector::Explode (const std::string & str, char separator)
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
