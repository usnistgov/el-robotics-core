///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        CrpiRobotiq.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel, J. Falco
//
//  Description
//  ===========
//  CrpiRobotiq interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crpi_robotiq.h"


namespace crpi_robot
{
  void livemanRobotiq (void *param)
  {
    keepalive *ka = (keepalive*)param;
    int val;

    while (ka->runThread)
    {
      ((CrpiRobotiq*)ka->rob)->SetParameter("STATUS", &val);

      //! Don't slam your processor!  You don't need to poll at full speed.
      Sleep (5000);
    }
    return;
  }

  LIBRARY_API CrpiRobotiq::CrpiRobotiq (char * initPath)
  {
    iqGrip = new RobotiqGripper::RobotiqGripper();
    grasped_ = false;

    task = ulapi_task_new();
    ka_.handle = ulapi_mutex_new(99);
    ka_.rob = this;
    ka_.runThread = true;

    ulapi_task_start((ulapi_task_struct*)task, livemanRobotiq, &ka_, ulapi_prio_lowest(), 0);
  }

  LIBRARY_API CrpiRobotiq::~CrpiRobotiq ()
  {
    ka_.runThread = false;
    delete [] iqGrip;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::SetTool (double percent)
  {
    int param;
    if (percent >= 0.5f)
    {
      param = (grasped_) ? 2 : 1;
      grasped_ = false;
    }
    else
    {
      param = 1;
      grasped_ = true;
    }

//    int param = (percent >= 0.5f) ? 2 : 1;
    iqGrip->setGrip(param);
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::Couple (const char *targetID)
  {
    int param;
    if (strcmp(targetID, "gripper_gear") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=200;
      SetParameter("POSITION_SCISSOR", &param);
      param=10;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
    else if (strcmp(targetID, "gripper_top_cover") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=240;
      SetParameter("POSITION_SCISSOR", &param);
      param=0;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
    else if (strcmp(targetID, "gripper_bottom_cover") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=180;
      SetParameter("POSITION_SCISSOR", &param);
      param=0;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
    else if (strcmp(targetID, "gripper_finger_test_a") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=180;
      SetParameter("POSITION_SCISSOR", &param);
      param=0;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
      else if (strcmp(targetID, "gripper_finger_test_b") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=180;
      SetParameter("POSITION_SCISSOR", &param);
      param=0;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
    else if (strcmp(targetID, "gripper_finger_test_c") == 0)
    {
      param = 1;
      SetParameter("ADVANCED_CONTROL", &param);
      SetParameter("SCISSOR_CONTROL", &param);
      param=100;
      SetParameter("SPEED_FINGER_A", &param);
      SetParameter("SPEED_FINGER_B", &param);
      SetParameter("SPEED_FINGER_C", &param);
      SetParameter("SPEED_SCISSOR", &param);
      param=100;
      SetParameter("FORCE_FINGER_A", &param);
      SetParameter("FORCE_FINGER_B", &param);
      SetParameter("FORCE_FINGER_C", &param);
      SetParameter("FORCE_SCISSOR", &param);
      param=180;
      SetParameter("POSITION_SCISSOR", &param);
      param=0;
      SetParameter("POSITION_FINGER_A", &param);
      param=30;
      SetParameter("POSITION_FINGER_B", &param);
      SetParameter("POSITION_FINGER_C", &param);
      SetTool (0.9);
    }
    else
    {
      return CANON_FAILURE;
    }
    strcpy (configName, targetID);

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::Dwell (int *events, double *params, int numEvents)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::EndCanon (int reason)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::InitCanon ()
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::Message (const char *message)
  {
    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::MoveStraightTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::MoveTo (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::Decouple (const char *targetID)
  {
    if (strcmp(targetID, configName) != 0)
    {
      return CANON_FAILURE;
    }

    if (strcmp(targetID, configName) == 0)
    {
      strcpy (configName, "nothing");
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::GetRobotAxes (robotAxes *axes)
  {
    //! TODO
    return CANON_FAILURE;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::GetRobotPose (robotPose *pose)
  {
    return CANON_REJECT;
  }

  LIBRARY_API CanonReturn CrpiRobotiq::GetRobotIO (robotIO *io)
  {
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::MoveAttractor (robotPose pose)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::MoveToAxisTarget (robotAxes axes)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::RunProgram (const char *programName, CRPIProgramParams params)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetAbsoluteAcceleration (double tolerance)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetAbsoluteSpeed (double speed)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetAngleUnits (const char *unitName)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetAxialSpeeds (double *speeds)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetAxialUnits (const char **unitNames)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetEndPoseTolerance (robotPose tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetLengthUnits (const char *unitName)
  {
    return CANON_SUCCESS;
  }


 LIBRARY_API CanonReturn CrpiRobotiq::SetParameter (const char *paramName, void *paramVal)
  {
    int *temp_int = (int*) paramVal;

    //WaitForSingleObject (ka_.handle, INFINITE);
    ulapi_mutex_take(ka_.handle);

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
    //ReleaseMutex (ka_.handle);
    ulapi_mutex_give(ka_.handle);

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetRelativeAcceleration (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetRelativeSpeed (double percent)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::SetRobotIO (robotIO io)
  {
    //! TODO
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiRobotiq::StopMotion (int condition)
  {
    return CANON_SUCCESS;
  }
  
} // Robot
