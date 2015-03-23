///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        CrpiSchunkSDH.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Schunk SDH interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crpi_schunk_sdh.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

namespace crpi_robot
{

  void readSDH(){
  }


  LIBRARY_API CrpiSchunkSDH::CrpiSchunkSDH (char * initPath)
  {
    server = ulapi_socket_get_client_id (6007, "129.6.225.58");

    if (server < 0)
    {
      cout << "no connection" << endl;
    }
	  else
	  {
	    cout << "connection success" << endl;
	  }
  
  
  }

  LIBRARY_API CrpiSchunkSDH::~CrpiSchunkSDH ()
  {
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::SetTool (double percent)
  {
	  if (percent == 100) 
	  {
		  strcpy(outbuffer,"100");
		  send = ulapi_socket_write(server, outbuffer, sizeof(outbuffer));
		  get = ulapi_socket_read(server, inbuffer, MSG_SIZE);
		  cout << inbuffer << endl;
	  }

	  else if (percent == -100) 
	  {
		  strcpy(outbuffer,"-100");
		  send = ulapi_socket_write(server, outbuffer, sizeof(outbuffer));
		  get = ulapi_socket_read(server, inbuffer, MSG_SIZE);
		  cout << inbuffer << endl;
	  }

	  strcpy(outbuffer,"");
	  strcpy(inbuffer,"");
	  
	  
	return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::Couple (const char *targetID)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::Dwell (int *events, double *params, int numEvents)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::EndCanon (int reason)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::InitCanon ()
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::Message (const char *message)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::MoveStraightTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::MoveTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::Decouple (const char *targetID)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::GetRobotAxes (robotAxes *axes)
  {
    return CANON_FAILURE;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::GetRobotPose (robotPose *pose)
  {
    return CANON_REJECT;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::GetRobotIO (robotIO *io)
  {
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::MoveAttractor (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::MoveToAxisTarget (robotAxes axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::RunProgram (const char *programName, CRPIProgramParams params)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetAbsoluteAcceleration (double tolerance)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetAbsoluteSpeed (double speed)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetAngleUnits (const char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetAxialSpeeds (double *speeds)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetAxialUnits (const char **unitNames)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetEndPoseTolerance (robotPose tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetLengthUnits (const char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetParameter (const char *paramName, void *paramVal)
  {

    int *temp_int = (int*) paramVal;
    int val = *temp_int;

    

    if ((strcmp (paramName, "GRIP_TYPE") == 0))
    {
      strcpy(outbuffer, paramName);
      strcat(outbuffer, ",");
      if (val == 1)
        strcat(outbuffer, "1");
      else if(val == 2)
        strcat(outbuffer, "2");
	  else if(val == 3)
        strcat(outbuffer, "3");

      send = ulapi_socket_write(server, outbuffer, sizeof(outbuffer));

	  get = ulapi_socket_read(server, inbuffer, MSG_SIZE);

      cout << inbuffer << endl;
    }

	strcpy(outbuffer,"");
	strcpy(inbuffer,"");

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiSchunkSDH::SetRelativeAcceleration (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetRelativeSpeed (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::SetRobotIO (robotIO io)
  {
    //! TODO
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiSchunkSDH::StopMotion (int condition)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API void CrpiSchunkSDH::readSDH()
  {  
    get = ulapi_socket_read(server, inbuffer, MSG_SIZE);
  }

  LIBRARY_API void CrpiSchunkSDH::writeSDH()
  {
    
    send = ulapi_socket_write(server, "tap", 3);
  }
  
} // crpi_robot
