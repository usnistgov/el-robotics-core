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
  \file   usarSimInf.cpp
  \brief  Class that controls the connection to USARSim.
  Provides methods to connect to USARSim and add objects to the world.
  \author Stephen Balakirsky
  \date   12/14/2012
*/
#include "usarSimInf.h"

/*
connectIn: 1 to connect to USARSim, 0 else
hostname: USARSim host
portIn: USARSim port
*/
UsarSimInf::UsarSimInf(int connectIn, std::string hostname, int portIn)
{
  std::string outStr;
  connected = connectIn;
  PORT  = portIn;
  // must initialize the ULAPI API
  if( connected )
    {
      if (ulapi_init(UL_USE_DEFAULT) != ULAPI_OK) 
	{
	  connected = 0;
	  return;
	}
      socket_fd = ulapi_socket_get_client_id(PORT, hostname.c_str());
      if (socket_fd < 0) 
	{
	  connected = 0;
	  return;
	}
      outStr =  "INIT {ClassName USARBotAPI.WorldController} {Location 0, 0, 0} {Rotation 0, 0, 0}\r\n"; 
      ulapi_socket_write(socket_fd, outStr.c_str(), outStr.length());

    }
}

/*
  className: USARSim class to spawn
  name: unique name of object
  where: where to locate it
  permanent: 1 - always keep, 0 - delete on exit
*/
int UsarSimInf::placeObject( std::string className, std::string name, 
			     RecLoc where, int permanent )
{
  std::string output;
  double roll, pitch, yaw;
  std::stringstream converter;

  roll = 0; pitch = 0; yaw = 0;

  /* test code   */
  //  where.xAxis[0] = 0;
  //  where.xAxis[1] = 1;
  //  where.xAxis[2] = 0;
  /*end of test */

  output = "CONTROL {Type Create}{ClassName " + 
    className +
    "}{Name " + 
    name + 
    "}{Location ";

  converter << where.pointXYZ[0];
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << where.pointXYZ[1];
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << where.pointXYZ[2];
  output += converter.str() + "}{Rotation  ";

  where.getRollPitchYaw(&roll, &pitch, &yaw);
  converter.str(std::string());
  converter << roll;
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << pitch;
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << yaw;
  output += converter.str() + 
    "}{Scale 1, 1, 1}{Physics RigidBody}{Permanent ";
  if( permanent )
    output += "true}\r\n";
  else
    output += "false}\r\n";

  printf( "Sending %s\n", output.c_str() );
  ulapi_socket_write(socket_fd, output.c_str(), output.length());
  return 1;
}
