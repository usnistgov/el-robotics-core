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

#include "WorkTable.h"


#include "KittingWorkstation.h"
#include "SolidObject.h"
#include "DAO.h"

WorkTable::WorkTable (std::string name):BoxyObject (name)
{
  this->name = name;
  dao = NULL;
  hasWorkstation_WorkTable = NULL;

}

WorkTable::~WorkTable ()
{
  delete (dao);
  delete (hasWorkstation_WorkTable);
  for (std::size_t i = 0; i < hadBySolidObject_WorkTable.size (); i++)
    delete (hadBySolidObject_WorkTable[i]);
}

std::string WorkTable::getname ()
{
  return name;
}

int
WorkTable::getWorkTableID ()
{
  return WorkTableID;
}

DAO *
WorkTable::getdao ()
{
  return dao;
}

std::vector < SolidObject * >*WorkTable::gethadBySolidObject_WorkTable ()
{
  return &hadBySolidObject_WorkTable;
}

KittingWorkstation *
WorkTable::gethasWorkstation_WorkTable ()
{
  return hasWorkstation_WorkTable;
}

void
WorkTable::setdao (DAO * _dao)
{
  this->dao = _dao;
}

void
WorkTable::sethadBySolidObject_WorkTable (std::vector <
					  SolidObject *
					  >_hadBySolidObject_WorkTable)
{
  this->hadBySolidObject_WorkTable = _hadBySolidObject_WorkTable;
}

void
WorkTable::sethasWorkstation_WorkTable (KittingWorkstation *
					_hasWorkstation_WorkTable)
{
  this->hasWorkstation_WorkTable = _hasWorkstation_WorkTable;
}

void
WorkTable::get (std::string name)
{
  std::map < std::string, std::string > temp;
  dao = new DAO ("BoxyObject");
  temp = dao->get (name);
  delete (dao);
  BoxyObject::copy (temp);
  dao = new DAO ("WorkTable");
  temp = dao->get (name);
  delete (dao);
  copy (temp);
}

void
WorkTable::set (std::string name)
{
  std::map < std::string, std::string > data;
  std::stringstream ss;
  BoxyObject *temp = (BoxyObject *) this;
  temp->set (name);
  data["name"] = name;
  ss.str ("");
  ss << WorkTableID;
  data["WorkTableID"] = ss.str ();
  for (unsigned int i = 0; i < hadBySolidObject_WorkTable.size (); ++i)
    {
      ss.str ("");
      hadBySolidObject_WorkTable[i]->get (hadBySolidObject_WorkTable[i]->
					  getname ());
      ss << hadBySolidObject_WorkTable[i]->getSolidObjectID ();
      data["hadBySolidObject_WorkTable"] =
	data["hadBySolidObject_WorkTable"] + " " + ss.str ();
    }
  if (hasWorkstation_WorkTable != NULL)
    data["hasWorkstation_WorkTable"] = hasWorkstation_WorkTable->getname ();
  dao = new DAO ("WorkTable");
  dao->set (data);
  delete (dao);
}

void
WorkTable::copy (std::map < std::string, std::string > object)
{
  std::vector < std::string > temp;
  std::map < std::string, std::string > mapTemp;
  std::map < std::string, std::string > mapTempBis;
  int nbVal = 0;
  int nbValCurrent = 0;
  std::vector < WorkTable * >tmp;
  this->name = object["WorkTable._NAME"];
  this->WorkTableID = std::atof (object["WorkTable.WorkTableID"].c_str ());
  if (this->hadBySolidObject_WorkTable.empty ()
      && object["hadBySolidObject_WorkTable/SolidObject._NAME"] != "")
    {
      temp =
	Explode (object["hadBySolidObject_WorkTable/SolidObject._NAME"], ' ');
      for (unsigned int i = 0; i < temp.size (); i++)
	{
	  this->hadBySolidObject_WorkTable.
	    push_back (new SolidObject (temp[i]));
	}
    }
  if (this->hasWorkstation_WorkTable == NULL
      && object["hasWorkstation_WorkTable/KittingWorkstation._NAME"] != "")
    {
      this->hasWorkstation_WorkTable =
	new
	KittingWorkstation (object
			    ["hasWorkstation_WorkTable/KittingWorkstation._NAME"]);
    }

}

std::vector < std::string > WorkTable::Explode (const std::string & str,
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
