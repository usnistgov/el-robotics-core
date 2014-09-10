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
  \file   usarSimInf.cpp
  \brief  Class that controls the connection to USARSim.
  Provides methods to connect to USARSim and add objects to the world.
  \author Stephen Balakirsky
  \date   12/14/2012
  \copyright Georgia Tech Research Institute
*/
#include "usarSimInf.h"

/*! \brief Creates UsarSimInf object
    This creates the object and sends the Init string to USARSim in order to create the world controller.
    \param connectIn 1 to connect to USARSim, 0 else
    \param hostname  USARSim host
    \param portIn USARSim port
    \return None
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

/*! \brief Place an object into the simulation
    Note that this method will change the coordinate frame from z-down to z-up. To do this it
    will rotate every position 180 degrees about x (y and z are flipped).
    \param className USARSim class to spawn
    \param name unique name of object
    \param where where to locate it
    \param permanent 1 - always keep, 0 - delete on exit
    \return Always returns 1. Not very useful!
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

  converter << where.frame.pose.getPointX();
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << -where.frame.pose.getPointY(); // swap axis (rotation about x)
  //  converter << where.frame.pointXYZ[1];
  output += converter.str() + ", ";

  converter.str(std::string());
  converter << -where.frame.pose.getPointZ(); // swap axis (rotation about x)
  //  converter << where.frame.pointXYZ[2];
  output += converter.str() + "}{Rotation  ";

  where.frame.pose.getRollPitchYaw(&roll, &pitch, &yaw);
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

  if( connected )
    ulapi_socket_write(socket_fd, output.c_str(), output.length());
  else
    printf( "Would have sent: %s\n", output.c_str() );

  return 1;
}
