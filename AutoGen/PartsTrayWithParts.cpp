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

#include "PartsTrayWithParts.h"


#include "DAO.h"
#include "Part.h"
#include "PartsTray.h"

PartsTrayWithParts::PartsTrayWithParts (std::string name):SolidObject (name)
{
  this->name = name;
  dao = NULL;
  hasPartsTrayWithParts_Tray = NULL;

}

PartsTrayWithParts::~PartsTrayWithParts ()
{
  delete (dao);
  delete (hasPartsTrayWithParts_Tray);
  for (std::size_t i = 0; i < hadByPart_PartsTrayWithParts.size (); i++)
    delete (hadByPart_PartsTrayWithParts[i]);
}

std::string PartsTrayWithParts::getname ()
{
  return name;
}

int
PartsTrayWithParts::getPartsTrayWithPartsID ()
{
  return PartsTrayWithPartsID;
}

DAO *
PartsTrayWithParts::getdao ()
{
  return dao;
}

PartsTray *
PartsTrayWithParts::gethasPartsTrayWithParts_Tray ()
{
  return hasPartsTrayWithParts_Tray;
}

std::vector < Part * >*PartsTrayWithParts::gethadByPart_PartsTrayWithParts ()
{
  return &hadByPart_PartsTrayWithParts;
}

void
PartsTrayWithParts::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
PartsTrayWithParts::sethasPartsTrayWithParts_Tray (PartsTray *
						   _hasPartsTrayWithParts_Tray)
{
  this->hasPartsTrayWithParts_Tray = _hasPartsTrayWithParts_Tray;
}

void
PartsTrayWithParts::sethadByPart_PartsTrayWithParts (std::vector <
						     Part *
						     >_hadByPart_PartsTrayWithParts)
{
  this->hadByPart_PartsTrayWithParts = _hadByPart_PartsTrayWithParts;
}

void
PartsTrayWithParts::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("SolidObject");
  temp = dao->get (name);
  delete (dao);
  SolidObject::copy (temp);
  dao = new DAO ("PartsTrayWithParts");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
PartsTrayWithParts::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  SolidObject *temp = (SolidObject *) this;
  temp->set (name);
  data["name"] = name;
  ss.str ("");
  ss << PartsTrayWithPartsID;
  data["PartsTrayWithPartsID"] = ss.str ();
  if (hasPartsTrayWithParts_Tray != NULL)
    data["hasPartsTrayWithParts_Tray"] =
      hasPartsTrayWithParts_Tray->getname ();
  for (unsigned int i = 0; i < hadByPart_PartsTrayWithParts.size (); ++i)
    {
      ss.str ("");
      hadByPart_PartsTrayWithParts[i]->get (hadByPart_PartsTrayWithParts[i]->
					    getname ());
      ss << hadByPart_PartsTrayWithParts[i]->getPartID ();
      data["hadByPart_PartsTrayWithParts"] =
	data["hadByPart_PartsTrayWithParts"] + " " + ss.str ();
    }
  dao = new DAO ("PartsTrayWithParts");
  dao->set (data);
  delete (dao);
}

void
PartsTrayWithParts::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < PartsTrayWithParts * >tmp;
  this->name = object["PartsTrayWithParts._NAME"];
  this->PartsTrayWithPartsID =
    std::atof (object["PartsTrayWithParts.PartsTrayWithPartsID"].c_str ());
  if (this->hasPartsTrayWithParts_Tray == NULL
      && object["hasPartsTrayWithParts_Tray/PartsTray._NAME"] != "")
    {
      this->hasPartsTrayWithParts_Tray =
	new PartsTray (object["hasPartsTrayWithParts_Tray/PartsTray._NAME"]);
    }
  if (this->hadByPart_PartsTrayWithParts.empty ()
      && object["hadByPart_PartsTrayWithParts/Part._NAME"] != "")
    {
      temp = Explode (object["hadByPart_PartsTrayWithParts/Part._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hadByPart_PartsTrayWithParts.push_back (new Part (temp[i]));
	}
    }

} std::vector < std::string >
  PartsTrayWithParts::Explode (const std::string & str, char separator)
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
