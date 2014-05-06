///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        CrclSchunkSDH.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Schunk SDH interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core\crcl_schunk_sdh.h"

using namespace std;

namespace crcl_robot
{
  LIBRARY_API CrclSchunkSDH::CrclSchunkSDH (char * initPath)
  {
  }

  LIBRARY_API CrclSchunkSDH::~CrclSchunkSDH ()
  {
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::SetTool (double percent)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::Couple (char *targetID)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::Dwell (int *events, double *params, int numEvents)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::EndCanon (int reason)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::InitCanon ()
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::Message (char *message)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::MoveStraightTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::MoveTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::Decouple (char *targetID)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::GetRobotAxes (robotAxes *axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::GetRobotPose (robotPose *pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::MoveAttractor (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::MoveToAxisTarget (robotAxes axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::RunProgram (char *programName, CRCLProgramParams params)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetAbsoluteAcceleration (double tolerance)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetAbsoluteSpeed (double speed)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetAngleUnits (char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetAxialSpeeds (double *speeds)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetAxialUnits (char **unitNames)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetEndPoseTolerance (robotPose tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetLengthUnits (char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetParameter (char *paramName, void *paramVal)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSchunkSDH::SetRelativeAcceleration (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::SetRelativeSpeed (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclSchunkSDH::StopMotion (int condition)
  {
    return CANON_SUCCESS;
  }
  
} // crcl_robot
