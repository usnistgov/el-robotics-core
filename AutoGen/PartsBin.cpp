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

#include "PartsBin.h"


#include "DAO.h"

PartsBin::PartsBin (std::string name):BoxyObject (name)
{
  this->name = name;
  dao = NULL;

}

PartsBin::~PartsBin ()
{
  delete (dao);
}

std::string PartsBin::gethasBin_PartQuantity ()
{
  return hasBin_PartQuantity;
}

std::string PartsBin::gethasBin_PartSkuRef ()
{
  return hasBin_PartSkuRef;
}

std::string PartsBin::getname ()
{
  return name;
}

int
PartsBin::getPartsBinID ()
{
  return PartsBinID;
}

DAO *
PartsBin::getdao ()
{
  return dao;
}

void
PartsBin::sethasBin_PartQuantity (std::string _hasBin_PartQuantity)
{
  this->hasBin_PartQuantity = _hasBin_PartQuantity;
}

void
PartsBin::sethasBin_PartSkuRef (std::string _hasBin_PartSkuRef)
{
  this->hasBin_PartSkuRef = _hasBin_PartSkuRef;
}

void
PartsBin::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
PartsBin::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("BoxyObject");
  temp = dao->get (name);
  delete (dao);
  BoxyObject::copy (temp);
  dao = new DAO ("PartsBin");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
PartsBin::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  BoxyObject *temp = (BoxyObject *) this;
  temp->set (name);
  data["hasBin_PartQuantity"] = hasBin_PartQuantity;
  data["hasBin_PartSkuRef"] = hasBin_PartSkuRef;
  data["name"] = name;
  ss.str ("");
  ss << PartsBinID;
  data["PartsBinID"] = ss.str ();
  dao = new DAO ("PartsBin");
  dao->set (data);
  delete (dao);
}

void
PartsBin::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < PartsBin * >tmp;
  this->hasBin_PartQuantity = object["PartsBin.hasBin_PartQuantity"];
  this->hasBin_PartSkuRef = object["PartsBin.hasBin_PartSkuRef"];
  this->name = object["PartsBin._NAME"];
  this->PartsBinID = std::atof (object["PartsBin.PartsBinID"].c_str ());

} std::vector < std::string > PartsBin::Explode (const std::string & str,
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
