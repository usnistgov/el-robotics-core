///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        Schunk_SDH.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Schunk SDH interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "Schunk_SDH.h"

using namespace std;

namespace Robot
{
  LIBRARY_API Schunk_SDH::Schunk_SDH (Logger *logger, char * initPath) :
    logger_(logger)
  {
  }

  LIBRARY_API Schunk_SDH::~Schunk_SDH ()
  {
  }

  LIBRARY_API CanonReturn Schunk_SDH::SetTool (double percent)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::Couple (char *targetID)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::Dwell (int *events, double *params, int numEvents)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::EndCanon (int reason)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::InitCanon ()
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::Message (char *message)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::MoveStraightTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::MoveTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::Decouple (char *targetID)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::GetRobotAxes (robotAxes *axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::GetRobotPose (robotPose *pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::MoveAttractor (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::MoveToAxisTarget (robotAxes axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::RunProgram (char *programName, CRCLProgramParams params)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetAbsoluteAcceleration (double tolerance)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetAbsoluteSpeed (double speed)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetAngleUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetAxialSpeeds (double *speeds)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetAxialUnits (char **unitNames)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetEndPoseTolerance (robotPose tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetLengthUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetParameter (char *paramName, void *paramVal)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Schunk_SDH::SetRelativeAcceleration (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::SetRelativeSpeed (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Schunk_SDH::StopMotion (int condition)
  {
    return SUCCESS;
  }
  

  LIBRARY_API void Schunk_SDH::exception (char *where, char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
} // Robot
