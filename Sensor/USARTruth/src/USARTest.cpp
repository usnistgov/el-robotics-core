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
int main(int argc, char *argv[])
{
  SensorReturn truthValue;
  USARTruth usarTruth;

  usarTruth.connect("10.108.21.213", 3989);

  usarTruth.setDebug(0);
  //  truthValue = usarTruth.getTruth("USARPhysObj.partc", "part_c_5");
  truthValue = usarTruth.getTruth("USARPhysObj.partc", "part_c_6");
  if( truthValue.valid )
    {
      printf( "Value returned for %s:%s\n",
	      truthValue.objectClass.c_str(), truthValue.name.c_str());
      printf( "\tTime: %f\n \tPoint: <%f %f %f>\n \tRot: <%f %f %f>\n",
	      truthValue.time,
	      truthValue.point[0],
	      truthValue.point[1],
	      truthValue.point[2],
	      truthValue.rot[0],
	      truthValue.rot[1],
	      truthValue.rot[2]);
    }
  else
    printf( "no valid data returned\n" );
}
