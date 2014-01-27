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

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
*****************************************************************************/
/*!
 *	\file		objectGen.cpp
 *	\brief 		Read mysql database and populate usarsim with objects
 *      Usage: -d -t -h <host> -o <objects>, d: debug mode, t: objects are temporary, 
 *	        o: binary flags for what to populate (1=partstrays, 2=kitTrays, 4=parts,
 *              h: use usarSim host <host>
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 30, 2013
 *      \copyright      Georgia Tech Research Institute
 */

#include <string>
#include <stdio.h> // printf
#include "DAO.h"
#include "KitTray.h"
#include "Part.h"
#include "PartsTray.h"
#include "Kit.h"
#include "recurseLocation.h"
#include "usarSimInf.h"
#include "genericModel.h"

/* define flags for population */
#define POPULATE_PART_TRAY 0x1
#define POPULATE_KIT_TRAY  0x2
#define POPULATE_PARTS     0x4

int main(int argc, char *argv[])
{
  //  UsarSimInf usarsim(1,std::string("sbalakirsky-e64")); // connect
  //  UsarSimInf usarsim(0,std::string("sbalakirsky-e64"));  // don't connect
  std::string myPart = "part_b_1";
  //  KitTray *kitTray = new KitTray(myPart);
  // change
  KitTray *kitTray;
  // end of change
  Kit *kit = new Kit(myPart);
  Part *testPart = new Part(myPart);;
  PartsTray *partsTray = new PartsTray(myPart);
  RecurseLocation recurseLocation;
  std::string USARModel;
  std::map<std::string, std::vector<std::string> > results;
  DAO* dao = new DAO("Part");
  std::vector<std::string> attributes;
  int permanent = 1;
  int connectToUSARSim = 1;
  int opt;
  std::string usarsimHost = "sbalakirsky-e64";
  unsigned int populateFlags = 0xFF;

  while ((opt = getopt (argc, argv, "dth:o:")) != -1)
    switch (opt)
      {
      case 'd':
	connectToUSARSim = 0;
	break;
      case 'h':
	usarsimHost = std::string(optarg);
	break;
      case 'o':
	populateFlags = atoi(optarg);
	break;
      case 't':
	permanent = 0;
	break;
      case '?':
	if( optopt == 'h')
	  printf( "option -%c requires an argument.\n", optopt);
	else if( isprint(optopt) )
	  printf( "Unknown option `-%c`.\n", optopt);
	else
	  printf( "Unknown option character `\\x%x`.\n", optopt );
	printf( "Usage: %s -d -t -h <host> -o <flags>\n", argv[0]);
	printf( "\td: debug mode\n" );
	printf( "\to: binary flags for what to populate (1=partstrays, 2=kitTrays, 4=parts)\n");
	printf( "\tt: objects are temporary\n\th: use usarSim host <host>\n");
	return 1;
      default:
	return 1;
      }

  UsarSimInf usarsim(connectToUSARSim, usarsimHost);
  //  recurseLocation.sensorConnect(usarsimHost); object generation does not require this!
  attributes.push_back("_NAME");

  // get the name of all of the partstrays
  if(POPULATE_PART_TRAY&populateFlags)
    {
      results = dao->getAll(attributes, "PartsTray");
      for(unsigned int i=0; (int) i<results["_NAME"].size();i++)
	{
	  myPart = results["_NAME"][i];
	  partsTray->get(myPart);
	  USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(partsTray));
	  /*
	    printf( "partsTrayid for %s is %d with serial %s and model \"%s\"\n", 
	    myPart.c_str(), partsTray->getPartsTrayID(),
	    partsTray->gethasPartsTray_SerialNumber().c_str(),
	    USARModel.c_str());
	  */
	  recurseLocation.clear();
	  recurseLocation.recurse(partsTray);
	  recurseLocation.computeGlobalLoc();
	  if( connectToUSARSim == 0 )
	    recurseLocation.printMe(1);
	  usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			       permanent );
	}
    }
  // get the name of all of the kitTrays
  //  results = dao->getAll(attributes, "KitTray");
  // try for results of kits
  if(POPULATE_KIT_TRAY&populateFlags)
    {
      results = dao->getAll(attributes, "Kit");
      for(int i=0; (int) i<results["_NAME"].size();i++)
	//      for(unsigned int i=0; i<1;i++)
	{
	  myPart = results["_NAME"][i];
	  kit->get(myPart);
	  kitTray = kit->gethasKit_KitTray();
	  kitTray->get(kitTray->getname());
	  USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(kitTray));

	  /*
	    printf( "kitTrayid for %s is %d with serial %s and model \"%s\"\n", 
	    myPart.c_str(), kitTray->getKitTrayID(),
	    kitTray->gethasKitTray_SerialNumber().c_str(),
	    USARModel.c_str());
	  */
	  recurseLocation.clear();
	  recurseLocation.recurse(kit);
	  recurseLocation.computeGlobalLoc();
	  if( connectToUSARSim == 0 )
	    recurseLocation.printMe(1);
	  usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			       permanent);
	}
    }
  // get the name of all of the parts
  if(POPULATE_PARTS&populateFlags)
    {
      results = dao->getAll(attributes, "Part");
      for(unsigned int i=0; i<results["_NAME"].size();i++)
	{
	  myPart = results["_NAME"][i];
	  //      testPart  = new Part(myPart);
	  testPart->get(myPart);
	  USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(testPart));
	  /*
	    printf( "partid for %s is %d with serial %s and model \"%s\"\n", 
	    myPart.c_str(), testPart->getPartID(),
	    testPart->gethasPart_SerialNumber().c_str(),
	    USARModel.c_str());
	  */
	  recurseLocation.clear();
	  recurseLocation.recurse(testPart);
	  recurseLocation.computeGlobalLoc();
	  if( connectToUSARSim == 0 )
	    recurseLocation.printMe(1);
	  usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			       permanent);
	  //      delete testPart;
	  //      sleep(1);
	}
    }
  if( !permanent )
    sleep(20);
  else
    sleep(2);
  return 0;
}
