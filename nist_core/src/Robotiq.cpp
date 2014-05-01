///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        Robotiq.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel, J. Falco
//
//  Description
//  ===========
//  Robotiq interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "Robotiq.h"

namespace Robot
{
  LIBRARY_API Robotiq::Robotiq (char * initPath)
  {
	 iqGrip = new RobotiqGripper::RobotiqGripper();
  }

  LIBRARY_API Robotiq::~Robotiq ()
  {
  }

  LIBRARY_API CanonReturn Robotiq::SetTool (double percent)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::Couple (char *targetID)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::Dwell (int *events, double *params, int numEvents)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::EndCanon (int reason)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::InitCanon ()
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::Message (char *message)
  {
    return SUCCESS;
  }

  LIBRARY_API CanonReturn Robotiq::MoveStraightTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::MoveTo (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::Decouple (char *targetID)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::GetRobotAxes (robotAxes *axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::GetRobotPose (robotPose *pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::MoveAttractor (robotPose pose)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::MoveToAxisTarget (robotAxes axes)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::RunProgram (char *programName, CRCLProgramParams params)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetAbsoluteAcceleration (double tolerance)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetAbsoluteSpeed (double speed)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetAngleUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetAxialSpeeds (double *speeds)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetAxialUnits (char **unitNames)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetEndPoseTolerance (robotPose tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetLengthUnits (char *unitName)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetParameter (char *paramName, void *paramVal)
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
	  cout << "setting PositionScissor = " << temp_int << endl;
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
    else
    {
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetRelativeAcceleration (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::SetRelativeSpeed (double percent)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Robotiq::StopMotion (int condition)
  {
    return SUCCESS;
  }
  
} // Robot
