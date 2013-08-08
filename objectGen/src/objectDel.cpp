/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------
 *****************************************************************************/
/*!
 *	\file		objectDel.cpp
 *	\brief 		Read mysql database and move all contents of kit to "trash"
 *	\author		Stephen Balakirsky, GTRI
 *	\date		Aug 07, 2013
 *      \copyright      Georgia Tech Research Institute
 */

#include <string>
#include <stdio.h> // printf
#include "database/DAO.h"
#include "database/Slot.h"
#include "database/PhysicalLocation.h"
#include "database/Part.h"

int main(int argc, char *argv[])
{
  std::string trashLoc = "trash_table";
  std::string mySlot;
  Slot *slot = new Slot(trashLoc);;
  SolidObject *trashTable;
  SolidObject *partObject = new SolidObject(trashLoc);
  PhysicalLocation *physicalLocation;
  Part *part;
  std::map<std::string, std::vector<std::string> > results;
  DAO* dao = new DAO("Part");
  std::vector<std::string> attributes;
  int opt;

  while ((opt = getopt (argc, argv, "t:")) != -1)
    switch (opt)
      {
      case 't':
	trashLoc = std::string(optarg);
	break;
      case '?':
	if( optopt == 't')
	  printf( "option -%c requires an argument.\n", optopt);
	else if( isprint(optopt) )
	  printf( "Unknown option `-%c`.\n", optopt);
	else
	  printf( "Unknown option character `\\x%x`.\n", optopt );
	printf( "Usage: %s -t, ", argv[0]);
	printf( "t: <trash location> - location to move parts to\n");
	return 1;
      default:
	return 1;
      }

  //  trashTable->get(trashLoc);
  //  printf( "Setting objects to be in trash %s\n", trashTable->getname().c_str());

  attributes.push_back("_NAME");
  // get the name of all of the slots
  results = dao->getAll(attributes, "Slot");
  for(unsigned int i=0; (int) i<results["_NAME"].size();i++)
    {
      trashTable = new SolidObject(trashLoc);
      trashTable->get(trashLoc);
      mySlot = results["_NAME"][i];
      printf( "Looking for slot %s\n", mySlot.c_str() );
      slot->get(mySlot);
      part = slot->gethasSlot_Part();
      printf( "Looking for partObject %s\n", part->getname().c_str());
      partObject->get(part->getname());
      physicalLocation = partObject->gethasSolidObject_PrimaryLocation();
      physicalLocation->get(physicalLocation->getname());
      physicalLocation->sethasPhysicalLocation_RefObject(trashTable);
      physicalLocation->set(physicalLocation->getname());
      slot->sethasSlot_Part(NULL);
      slot->set(slot->getname());
    }
}
