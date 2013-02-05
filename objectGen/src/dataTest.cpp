/* test of database access */
#include <string>
#include <stdio.h> // printf
#include "database/DAO.h"
#include "database/KitTray.h"
#include "database/Part.h"
#include "database/PartsTray.h"
#include "recurseLocation.h"
#include "kitTrayModel.h"
#include "partModel.h"
#include "partsTrayModel.h"
#include "usarSimInf.h"

int main(int argc, char *argv[])
{
  //  UsarSimInf usarsim(1,std::string("marvin"));
  UsarSimInf usarsim(0,std::string("marvin"));
  std::string myPart = "part_b_1";
  KitTray *kitTray = new KitTray(myPart);
  Part *testPart = new Part(myPart);;
  PartsTray *partsTray = new PartsTray(myPart);
  RecurseLocation recurseLocation;
  KitTrayModel kitTrayModel;
  PartModel partModel;
  PartsTrayModel partsTrayModel;
  std::string USARModel;
  std::map<std::string, std::vector<std::string> > results;
  DAO* dao = new DAO("Part");
  std::vector<std::string> attributes;
  int permanent = 1;

  if( argc > 1 )
    {
      printf( "Objects will not be permanent.\n" );
      permanent = 0;
    }

  attributes.push_back("_NAME");

  // get the name of all of the partstrays
  results = dao->getAll(attributes, "PartsTray");
  for(int i=0; (int) i<results["_NAME"].size();i++)
    {
      myPart = results["_NAME"][i];
      //      testPart  = new Part(myPart);
      partsTray->get(myPart);
      partsTrayModel.setPartsTray(partsTray);
      USARModel = partsTrayModel.getModel();
      /*
      printf( "partsTrayid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), partsTray->getPartsTrayID(),
	      partsTray->gethasPartsTray_SerialNumber().c_str(),
	      USARModel.c_str());
      */
      recurseLocation.clear();
      recurseLocation.recurse(partsTray);
      recurseLocation.computeGlobalLoc();
      //      recurseLocation.printMe(0);
      usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			   permanent );
      //      delete testPart;
      //      sleep(1);
    }

  // get the name of all of the kitTrays
  results = dao->getAll(attributes, "KitTray");
  //  for(int i=0; (int) i<results["_NAME"].size();i++)
  for(int i=0; (int) i<1;i++)
    {
      myPart = results["_NAME"][i];
      //      testPart  = new Part(myPart);
      kitTray->get(myPart);
      kitTrayModel.setKitTray(kitTray);
      USARModel = kitTrayModel.getModel();
      /*
      printf( "kitTrayid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), kitTray->getKitTrayID(),
	      kitTray->gethasKitTray_SerialNumber().c_str(),
	      USARModel.c_str());
      */
      recurseLocation.clear();
      recurseLocation.recurse(kitTray);
      recurseLocation.computeGlobalLoc();
      //      recurseLocation.printMe(0);
      usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			   permanent);
      //      delete testPart;
      //      sleep(1);
    }

  // get the name of all of the parts
  results = dao->getAll(attributes, "Part");
  for(int i=0; (int) i<results["_NAME"].size();i++)
    {
      myPart = results["_NAME"][i];
      //      testPart  = new Part(myPart);
      testPart->get(myPart);
      partModel.setPart(testPart);
      USARModel = partModel.getModel();
/*
      printf( "partid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), testPart->getPartID(),
	      testPart->gethasPart_SerialNumber().c_str(),
	      USARModel.c_str());
*/
      recurseLocation.clear();
      recurseLocation.recurse(testPart);
      recurseLocation.computeGlobalLoc();
      //      recurseLocation.printMe(0);
      usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
			   permanent);
      //      delete testPart;
      //      sleep(1);
    }
  if( !permanent )
    sleep(20);
  else
    sleep(2);
  return 0;
}
