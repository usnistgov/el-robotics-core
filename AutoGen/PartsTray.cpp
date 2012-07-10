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

#include "PartsTray.h"


#include "PartsTrayWithParts.h"
#include "DAO.h"

PartsTray::PartsTray (std::string name):BoxyObject (name)
{
  this->name = name;
  dao = NULL;
  hasPartsTrayWithParts_Tray = NULL;

}

PartsTray::~PartsTray ()
{
  delete (dao);
  delete (hasPartsTrayWithParts_Tray);
}

std::string PartsTray::gethasPartsTray_SkuRef ()
{
  return hasPartsTray_SkuRef;
}

std::string PartsTray::gethasPartsTray_SerialNumber ()
{
  return hasPartsTray_SerialNumber;
}

std::string PartsTray::getname ()
{
  return name;
}

int
PartsTray::getPartsTrayID ()
{
  return PartsTrayID;
}

DAO *
PartsTray::getdao ()
{
  return dao;
}

PartsTrayWithParts *
PartsTray::gethasPartsTrayWithParts_Tray ()
{
  return hasPartsTrayWithParts_Tray;
}

void
PartsTray::sethasPartsTray_SkuRef (std::string _hasPartsTray_SkuRef)
{
  this->hasPartsTray_SkuRef = _hasPartsTray_SkuRef;
}

void
PartsTray::sethasPartsTray_SerialNumber (std::
					 string _hasPartsTray_SerialNumber)
{
  this->hasPartsTray_SerialNumber = _hasPartsTray_SerialNumber;
}

void
PartsTray::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
PartsTray::sethasPartsTrayWithParts_Tray (PartsTrayWithParts *
					  _hasPartsTrayWithParts_Tray)
{
  this->hasPartsTrayWithParts_Tray = _hasPartsTrayWithParts_Tray;
}

void
PartsTray::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("BoxyObject");
  temp = dao->get (name);
  delete (dao);
  BoxyObject::copy (temp);
  dao = new DAO ("PartsTray");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
PartsTray::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  BoxyObject *temp = (BoxyObject *) this;
  temp->set (name);
  data["hasPartsTray_SkuRef"] = hasPartsTray_SkuRef;
  data["hasPartsTray_SerialNumber"] = hasPartsTray_SerialNumber;
  data["name"] = name;
  ss.str ("");
  ss << PartsTrayID;
  data["PartsTrayID"] = ss.str ();
  if (hasPartsTrayWithParts_Tray != NULL)
    data["hasPartsTrayWithParts_Tray"] =
      hasPartsTrayWithParts_Tray->getname ();
  dao = new DAO ("PartsTray");
  dao->set (data);
  delete (dao);
}

void
PartsTray::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < PartsTray * >tmp;
  this->hasPartsTray_SkuRef = object["PartsTray.hasPartsTray_SkuRef"];
  this->hasPartsTray_SerialNumber =
    object["PartsTray.hasPartsTray_SerialNumber"];
  this->name = object["PartsTray._NAME"];
  this->PartsTrayID = std::atof (object["PartsTray.PartsTrayID"].c_str ());
  if (this->hasPartsTrayWithParts_Tray == NULL
      && object["hasPartsTrayWithParts_Tray/PartsTrayWithParts._NAME"] != "")
    {
      this->hasPartsTrayWithParts_Tray =
	new
	PartsTrayWithParts (object
			    ["hasPartsTrayWithParts_Tray/PartsTrayWithParts._NAME"]);
    }

}

std::vector < std::string > PartsTray::Explode (const std::string & str,
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
