/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*!
  \file   objectGen.cpp
  \brief  Connect to USARSim and add objects to the world from a mySQL database
  \author Stephen Balakirsky
  \date   11/8/2012
*/
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <unistd.h>
#include "ulapi.hh"

using namespace std;
#define PORT 3000

// usage: objectGen usarSim_host 

int placeObject( ulapi_integer socket_fd, const char *className, const char *name, double x, double y, double z, 
		 double roll, double pitch, double yaw )
{
  char str[250];
  
  ulapi_snprintf( str, sizeof(str), "CONTROL {Type Create}{ClassName %s}{Name %s}{Location %f, %f, %f}{Rotation %f, %f %f}{Scale 1, 1, 1}{Physics RigidBody}{Permanent true}\r\n",
		  className, name, x, y, z, roll, pitch, yaw);
  //  printf( "Sending %s\n", str );
  ulapi_socket_write(socket_fd, str, strlen(str));
  return 1;
}

int main(int argc, char *argv[])
{
  ulapi_integer port = PORT;
  ulapi_integer socket_fd;
  string className;
  char *hostname;
  double x, y, z;
  double roll, pitch, yaw;
  char str[250];

  // setup parameters
  if( argc != 2 )
    {
      printf( "usage: %s: usarsim_host\n", argv[0] );
      return -1;
    }

  hostname = argv[1];

  // must initialize the ULAPI API
  if (ulapi_init(UL_USE_DEFAULT) != ULAPI_OK) 
    {
      return -1;
    }

  socket_fd = ulapi_socket_get_client_id(port, hostname);
  if (socket_fd < 0) 
    {
      return -1;
    }
  ulapi_snprintf( str, sizeof(str), "INIT {ClassName USARBotAPI.WorldController} {Location 0, 0, 0} {Rotation 0, 0, 0}\r\n" ); 
  //  printf( "Sending %s\n", str );
  ulapi_socket_write(socket_fd, str, strlen(str));
  placeObject( socket_fd, "WCCrate", "foo", 0, 0, 0, 0, 0, 0 );
  sleep(20);
}
