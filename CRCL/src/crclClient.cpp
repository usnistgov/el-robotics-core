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
 *	\file		crclClient.cpp
 *	\brief 		Send CRCL commands to server
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 03, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <tinyxml.h>
#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string>
#include <ctype.h>

#include <ulapi.h>

#include "CRCL/timer.hh"
#include "nist_core/crcl.h"
#include "CRCL/crclDefs.hh"

int main(int argc, char *argv[])
{
  int debug = 1;
  int option;
  int cmdConnection;
  std::string msgOut;
  RCS_TIMER *cycleBlock = new RCS_TIMER(2.);

  while (true) 
    {
      option = getopt(argc, argv, ":d");
      if (option == -1) break;
      switch (option) 
	{
	case 'd':
	  debug = 1;
	  break;
	case ':':
	  fprintf(stderr, "missing value for -%c\n", optopt);
	  return 1;
	  break;
	default:
	  fprintf (stderr, "unrecognized option -%c\n", optopt);
	  return 1;
	  break;
	} // switch (option)
    }   // while (true) for getopt

  cmdConnection = ulapi_socket_get_client_id(CRCL_CMD_PORT_DEFAULT, 
					     "localhost");
  if( cmdConnection < 0 )
    return -1;
  for(int i=0; i<1; i++ )
    {
      // msgOut = "InitCanon";
      // ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      // printf( "crclClient writing: %s\n", msgOut.c_str());
      // sleep(2000);

      //msgOut = "Dwell 50";
      //ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      //printf( "crclClient writing: %s\n", msgOut.c_str());
      // //sleep(2);

      // Start Here.
      // msgOut = "MoveTo 200. -300. 400. 178. -2. 90.";
      // ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      // printf( "crclClient writing: %s\n", msgOut.c_str());
      // sleep(10);

      msgOut = "MoveTo -111. -425. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      //**84T-2**

      msgOut = "MoveTo 200. -300. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      msgOut = "MoveTo 200. 352. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(20);

      msgOut = "MoveTo 109. 352. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      //**PK-1**

      msgOut = "MoveTo 200. 351. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      msgOut = "MoveTo 200. -349. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(20);

      msgOut = "MoveTo 188. -349. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      //**60T-3**

      msgOut = "MoveTo 200. -350. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      msgOut = "MoveTo 200. 426. 400. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(24);

      msgOut = "MoveTo 187. 427. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      //**PK-3**

      msgOut = "MoveTo -113. 426. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(11);

      //**36T-3**

      msgOut = "MoveTo 111. 426. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(10);

      //**PK-4**

      msgOut = "MoveTo -189. 426. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(10);

      //**36T-4**

      msgOut = "MoveTo 186. 351. 48. 178. -2. 90.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(12);

      // msgOut = "Dwell 1";
      // ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      // printf( "crclClient writing: %s\n", msgOut.c_str());
      // sleep(2);


      // msgOut = "EndCanon";
      // ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      // printf( "crclClient writing: %s\n", msgOut.c_str());
      // sleep(2);
      cycleBlock->wait();
    }
}
