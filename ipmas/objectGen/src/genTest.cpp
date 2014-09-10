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
  \file   genTest.cpp
  \brief  Connect to USARSim and add objects to the world
  \author Stephen Balakirsky
  \date   11/8/2012
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <unistd.h>
#include "ulapi.hh"

#define PORT 3000

// usage: genTest host class x y z roll pitch yaw

int main(int argc, char *argv[])
{
  ulapi_integer port = PORT;
  ulapi_integer socket_fd;
  char *className;
  char *hostname;
  double x, y, z;
  double roll, pitch, yaw;
  char str[250];

  // setup parameters
  if( argc != 9 )
    {
      printf( "usage: %s: host class x y z roll pitch yaw\n", argv[0] );
      return -1;
    }

  hostname = argv[1];
  className = argv[2];
  x = atof(argv[3]);
  y = atof(argv[4]);
  z = atof(argv[5]);
  roll = atof(argv[6]);
  pitch = atof(argv[7]);
  yaw = atof(argv[8]);

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
  ulapi_snprintf( str, sizeof(str), "INIT {ClassName %s} {Name %s} {Location %f %f %f} {Rotation %f %f %f}\r\n", 
		  className, "UniqueName", x, y, z, roll, pitch, yaw );
  printf( "Sending %s\n", str );
  ulapi_socket_write(socket_fd, str, strlen(str));
  sleep(20);
}
