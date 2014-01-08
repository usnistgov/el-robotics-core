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
  Usage: USARTruth {-p <port>} {-h <host>} {-s <string>}

  Connects as a client to the <port> on optional <host>, sends <string>
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

  usarTruth.connect(host, port);
  usarTruth.setDebug(1);
  truthValue = usarTruth.getTruth(objectClass, objectName);
  if( truthValue.valid )
    {
      printf( "Value returned for direct call to getTruth %s:%s\n",
	      truthValue.objectClass.c_str(), truthValue.name.c_str());
      printf( "\tTime: %f\n \tPoint: <%f %f %f>\n\txAxis:%s <%f %f %f>\n\tzAxis:%s <%f %f %f>\n",
	      truthValue.time,
	      truthValue.pose.pointXYZ[0],
	      truthValue.pose.pointXYZ[1],
	      truthValue.pose.pointXYZ[2],
	      truthValue.pose.xAxisName.c_str(),
	      truthValue.pose.xAxis[0],
	      truthValue.pose.xAxis[1],
	      truthValue.pose.xAxis[2],
	      truthValue.pose.zAxisName.c_str(),
	      truthValue.pose.zAxis[0],
	      truthValue.pose.zAxis[1],
	      truthValue.pose.zAxis[2] );
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
