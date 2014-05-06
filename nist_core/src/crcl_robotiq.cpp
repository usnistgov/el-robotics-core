///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        CrclRobotiq.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel, J. Falco
//
//  Description
//  ===========
//  CrclRobotiq interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core\crcl_robotiq.h"

namespace crcl_robot
{
  LIBRARY_API CrclRobotiq::CrclRobotiq (char * initPath)
  {
   iqGrip = new RobotiqGripper::RobotiqGripper();
  }

  LIBRARY_API CrclRobotiq::~CrclRobotiq ()
  {
  }

  LIBRARY_API CanonReturn CrclRobotiq::SetTool (double percent)
  {
    int param = (percent >= 0.5f) ? 2 : 1;
    iqGrip->setGrip(param);
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::Couple (char *targetID)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::Dwell (int *events, double *params, int numEvents)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::EndCanon (int reason)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::InitCanon ()
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::Message (char *message)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclRobotiq::MoveStraightTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::MoveTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::Decouple (char *targetID)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::GetRobotAxes (robotAxes *axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::GetRobotPose (robotPose *pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::MoveAttractor (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::MoveToAxisTarget (robotAxes axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::RunProgram (char *programName, CRCLProgramParams params)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetAbsoluteAcceleration (double tolerance)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetAbsoluteSpeed (double speed)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetAngleUnits (char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetAxialSpeeds (double *speeds)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetAxialUnits (char **unitNames)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetEndPoseTolerance (robotPose tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetLengthUnits (char *unitName)
  {
    return CANON_SUCCESS;
  }


 LIBRARY_API CanonReturn CrclRobotiq::SetParameter (char *paramName, void *paramVal)
  {
    int *temp_int = (int*) paramVal;

    if ((strcmp (paramName, "ACTIVATE") == 0))
    {
      iqGrip->setParameter(1, *temp_int);
    }
    else if (strcmp (paramName, "GRIP_TYPE") == 0)
    {
      iqGrip->setParameter(2, *temp_int);
    }
    else if (strcmp (paramName, "AUTO_CENTER") == 0)
    {
      iqGrip->setParameter(4, *temp_int);
    }
    else if (strcmp (paramName, "AUTO_RELEASE") == 0)
    {
      iqGrip->setParameter(5, *temp_int);
    }
    else if (strcmp (paramName, "ADVANCED_CONTROL") == 0)
    {
      iqGrip->setParameter(6, *temp_int);
    }
    else if (strcmp (paramName, "SCISSOR_CONTROL") == 0)
    {
      iqGrip->setParameter(7, *temp_int);
    }
    else if (strcmp (paramName, "POSITION_FINGER_A") == 0)
    {
      iqGrip->setPositionFingerA(*temp_int);
    }
    else if (strcmp (paramName, "SPEED_FINGER_A") == 0)
    {
      iqGrip->setSpeedFingerA(*temp_int);
    }
    else if (strcmp (paramName, "FORCE_FINGER_A") == 0)
    {
      iqGrip->setForceFingerA(*temp_int);
    }
    else if (strcmp (paramName, "POSITION_FINGER_B") == 0)
    {
      iqGrip->setPositionFingerB(*temp_int);
    }
    else if (strcmp (paramName, "SPEED_FINGER_B") == 0)
    {
      iqGrip->setSpeedFingerB(*temp_int);
    }
    else if (strcmp (paramName, "FORCE_FINGER_B") == 0)
    {
      iqGrip->setForceFingerB(*temp_int);
    }
    else if (strcmp (paramName, "POSITION_FINGER_C") == 0)
    {
      iqGrip->setPositionFingerC(*temp_int);
    }
    else if (strcmp (paramName, "SPEED_FINGER_C") == 0)
    {
      iqGrip->setSpeedFingerC(*temp_int);
    }
    else if (strcmp (paramName, "FORCE_FINGER_C") == 0)
    {
      iqGrip->setForceFingerC(*temp_int);
    }
    else if (strcmp (paramName, "POSITION_SCISSOR") == 0)
    {
      iqGrip->setPositionScissor(*temp_int);
    }
    else if (strcmp (paramName, "SPEED_SCISSOR") == 0)
    {
      iqGrip->setSpeedScissor(*temp_int);
    }
    else if (strcmp (paramName, "FORCE_SCISSOR") == 0)
    {
      iqGrip->setForceScissor(*temp_int);
    }
    else if (strcmp (paramName, "GRIP") == 0)
    {
      iqGrip->setGrip(*temp_int);
    }
    else if (strcmp (paramName, "STATUS") == 0)
    {
      iqGrip->getStatusRegisters();
    }
    else
    {
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetRelativeAcceleration (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::SetRelativeSpeed (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclRobotiq::StopMotion (int condition)
  {
    return CANON_SUCCESS;
  }
  
} // Robot
