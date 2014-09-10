/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced under the GNU Public license
------------------------------------------------------------------------------
******************************************************************************/
/*
  Usage: USARTruth -p <port> -h <host> -n <name> -c <class>

  Connects as a client to the <port> on optional <host>, sends 
  for the location of an object named <name> of class <class>.
  All arguments are optional.
  and prints the response.

  <port> defaults to 3989
  <host> defaults to "localhost".
  <string> defaults to CR LF.
*/
#include <string>
#include <stdio.h>		// printf
#include "USARTruth.hh"
#include "SolidObject.h"
//#include "genericModel.h"
#include "recurseLocation.h"

int main(int argc, char *argv[])
{
  SensorReturn truthValue;
  USARTruth usarTruth;
  std::string objectClass = "USARPhysObj.PartC";
  std::string objectName = "part_c_6";
  std::string host = "10.108.21.213";
  ulapi_integer port = 3989;
  SolidObject *object = new SolidObject(objectName);
  RecurseLocation recurseLocation;
  int opt;

  while ((opt = getopt (argc, argv, "c:h:n:p:")) != -1)
    switch (opt)
      {
      case 'c':
	objectClass = std::string(optarg);
	break;
      case 'h':
	host = std::string(optarg);
	break;
      case 'n':
	objectName = std::string(optarg);
	break;
      case 'p':
	port = atoi(optarg);
	break;
      case '?':
      default:
	printf( "%s usage: -p <port> -h <host> -n <name> -c <class>\n", argv[0] );
	return 0;
	break;
      }
  usarTruth.connect(host, port);
  usarTruth.setDebug(1);
  truthValue = usarTruth.getTruth(objectClass, objectName);
  if( truthValue.valid )
    {
      printf( "Value returned for direct call to getTruth %s:%s\n",
	      truthValue.objectClass.c_str(), truthValue.name.c_str());
      printf( "\tTime: %f\n \tPoint: <%f %f %f>\n\txAxis:%s <%f %f %f>\n\tzAxis:%s <%f %f %f>\n",
	      truthValue.time,
	      truthValue.pose.getPointX(),
	      truthValue.pose.getPointY(),
	      truthValue.pose.getPointZ(),
	      truthValue.pose.getXAxisName().c_str(),
	      truthValue.pose.getXAxisI(),
	      truthValue.pose.getXAxisJ(),
	      truthValue.pose.getXAxisK(),
	      truthValue.pose.getZAxisName().c_str(),
	      truthValue.pose.getZAxisI(),
	      truthValue.pose.getZAxisJ(),
	      truthValue.pose.getZAxisK() );
    }
  else
    printf( "no valid data returned for direct call to getTruth\n" );
  recurseLocation.sensorConnect(host);
  object->get(objectName);
  //  USARModel = GenericModel::getModel(solidObject);
  recurseLocation.clear();
  recurseLocation.recurse(object);
  recurseLocation.computeGlobalLoc();
  recurseLocation.printMe(1);

}
