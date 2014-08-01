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
#include <iostream>
#include <string>
#include <ctype.h>

#include <ulapi.h>

#include "CRCL/timer.hh"
#include "nist_core/crcl.h"
#include "CRCL/crclDefs.hh"

/********************************
Good Points 
MoveTo 300 0 125 180 0 0


**********************************//

int main(int argc, char *argv[])
{
  int debug = 1;
  int option;
  int cmdConnection;
  int script = 1;
  std::string msgOut;
  RCS_TIMER *cycleBlock = new RCS_TIMER(2.);

  while (true) 
    {
      option = getopt(argc, argv, ":cd");
      if (option == -1) break;
      switch (option) 
	{
	case 'd':
	  debug = 1;
	  break;
	case 'c':
	  script = 0;
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
  if( !script )
    {
      for(;;)
	{
	  getline(std::cin, msgOut);
	  ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
	  printf( "Sent: %s\n", msgOut.c_str());
	}
    }
  for(int i=0; i<1; i++ )
    {
      msgOut = "InitCanon";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "MoveTo 1. 2. 3. 4. 5. 6.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "Dwell 1";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "MoveTo 7. 8. 9. 10. 11. 12.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "Dwell 4";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "EndCanon";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      cycleBlock->wait();
    }
}
