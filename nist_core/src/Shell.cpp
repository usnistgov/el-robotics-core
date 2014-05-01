///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        Shell.h
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Empty robot interface class source file.  Create a local copy of this file
//  for a new robot interface.
//
///////////////////////////////////////////////////////////////////////////////

#include "Shell.h"

using namespace std;

namespace Robot
{
  LIBRARY_API Shell::Shell (char * initPath) 
  {
  }

  LIBRARY_API Shell::~Shell ()
  {
  }

  LIBRARY_API CanonReturn Shell::SetTool (double percent)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::Couple (char *targetID)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::Dwell (int *events, double *params, int numEvents)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::EndCanon (int reason)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::InitCanon ()
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::Message (char *message)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::MoveStraightTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::MoveTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::Decouple (char *targetID)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::GetRobotAxes (robotAxes *axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::GetRobotPose (robotPose *pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::MoveAttractor (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::MoveToAxisTarget (robotAxes axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::RunProgram (char *programName, CRCLProgramParams params)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetAbsoluteAcceleration (double tolerance)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetAbsoluteSpeed (double speed)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetAngleUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetAxialSpeeds (double *speeds)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetAxialUnits (char **unitNames)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetEndPoseTolerance (robotPose tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetLengthUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetParameter (char *paramName, void *paramVal)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Shell::SetRelativeAcceleration (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::SetRelativeSpeed (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Shell::StopMotion (int condition)
  {
    return SUCCESS;
  }
  
} // Robot
