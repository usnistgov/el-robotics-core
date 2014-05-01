///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        DemoHack.cpp
//  Revision:        1.0 - 08 April, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  A hack of an interface for the Robotiq gripper on the Kuka arm.
//
///////////////////////////////////////////////////////////////////////////////

#include "DemoHack.h"

using namespace std;

namespace Robot
{
  LIBRARY_API DemoHack::DemoHack (Logger *logger, char * initPath) :
    logger_(logger)
  {
    arm_ = new robotArm (logger, initPath);
    hand_ = new robotHand (logger, initPath);
  }


  LIBRARY_API DemoHack::~DemoHack ()
  {
    delete [] hand_;
    delete [] arm_;
  }


  LIBRARY_API CanonReturn DemoHack::SetTool (double percent)
  {
    return hand_->SetTool(percent);
  }


  LIBRARY_API CanonReturn DemoHack::Couple (char *targetID)
  {
    //! Robot arm and hand are permanently coupled in this hack
    return REJECT;
  }


  LIBRARY_API CanonReturn DemoHack::Dwell (int *events, double *params, int numEvents)
  {
    return arm_->Dwell(events, params, numEvents);
  }


  LIBRARY_API CanonReturn DemoHack::EndCanon (int reason)
  {
    v1 = arm_->EndCanon (reason);
    v2 = hand_->EndCanon (reason);

    if (v1 == REJECT || v2 == REJECT)
    {
      return REJECT;
    }
    else if (v1 == FAILURE || v2 == FAILURE)
    {
      return FAILURE;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn DemoHack::InitCanon ()
  {
    v1 = arm_->InitCanon ();
    v2 = hand_->InitCanon ();

    if (v1 == REJECT || v2 == REJECT)
    {
      return REJECT;
    }
    else if (v1 == FAILURE || v2 == FAILURE)
    {
      return FAILURE;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn DemoHack::Message (char *message)
  {
    v1 = arm_->Message (message);
    v2 = hand_->Message (message);

    if (v1 == REJECT || v2 == REJECT)
    {
      return REJECT;
    }
    else if (v1 == FAILURE || v2 == FAILURE)
    {
      return FAILURE;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn DemoHack::MoveStraightTo (robotPose pose)
  {
    return arm_->MoveStraightTo (pose);
  }


  LIBRARY_API CanonReturn DemoHack::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return arm_->MoveThroughTo (poses, numPoses, accelerations, speeds, tolerances);
  }


  LIBRARY_API CanonReturn DemoHack::MoveTo (robotPose pose)
  {
    return arm_->MoveTo (pose);
  }


  LIBRARY_API CanonReturn DemoHack::Decouple (char *targetID)
  {
    //! Robot arm and hand are permanently attached in this hack
    return FAILURE;
  }


  LIBRARY_API CanonReturn DemoHack::GetRobotAxes (robotAxes *axes)
  {
    return arm_->GetRobotAxes (axes);
  }


  LIBRARY_API CanonReturn DemoHack::GetRobotPose (robotPose *pose)
  {
    return arm_->GetRobotPose (pose);
  }


  LIBRARY_API CanonReturn DemoHack::MoveAttractor (robotPose pose)
  {
    return arm_->MoveAttractor (pose);
  }


  LIBRARY_API CanonReturn DemoHack::MoveToAxisTarget (robotAxes axes)
  {
    return arm_->MoveToAxisTarget (axes);
  }


  LIBRARY_API CanonReturn DemoHack::RunProgram (char *programName, CRCLProgramParams params)
  {
    return arm_->RunProgram (programName, params);
  }


  LIBRARY_API CanonReturn DemoHack::SetAbsoluteAcceleration (double acceleration)
  {
    return arm_->SetAbsoluteAcceleration (acceleration);
  }


  LIBRARY_API CanonReturn DemoHack::SetAbsoluteSpeed (double speed)
  {
    return arm_->SetAbsoluteSpeed (speed);
  }


  LIBRARY_API CanonReturn DemoHack::SetAngleUnits (char *unitName)
  {
    return arm_->SetAngleUnits (unitName);
  }


  LIBRARY_API CanonReturn DemoHack::SetAxialSpeeds (double *speeds)
  {
    return arm_->SetAxialSpeeds (speeds);
  }


  LIBRARY_API CanonReturn DemoHack::SetAxialUnits (char **unitNames)
  {
    return arm_->SetAxialUnits (unitNames);
  }


  LIBRARY_API CanonReturn DemoHack::SetEndPoseTolerance (robotPose tolerance)
  {
    return arm_->SetEndPoseTolerance (tolerance);
  }


  LIBRARY_API CanonReturn DemoHack::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return arm_->SetIntermediatePoseTolerance (tolerances);
  }


  LIBRARY_API CanonReturn DemoHack::SetLengthUnits (char *unitName)
  {
    return arm_->SetLengthUnits (unitName);
  }


  LIBRARY_API CanonReturn DemoHack::SetParameter (char *paramName, void *paramVal)
  {
    //! Unfortunately we have to assume we're addressing one robot or the other.  Here, we
    //! assume we're addressing the hand.  Hacking together two robots like this is going
    //! to result in reduced functionality.
    return hand_->SetParameter (paramName, paramVal);
  }

  LIBRARY_API CanonReturn DemoHack::SetRelativeAcceleration (double percent)
  {
    return arm_->SetRelativeAcceleration (percent);
  }


  LIBRARY_API CanonReturn DemoHack::SetRelativeSpeed (double percent)
  {
    return arm_->SetRelativeSpeed (percent);
  }


  LIBRARY_API CanonReturn DemoHack::StopMotion (int condition)
  {
    v1 = arm_->StopMotion (condition);
    v2 = hand_->StopMotion (condition);

    if (v1 == REJECT || v2 == REJECT)
    {
      return REJECT;
    }
    else if (v1 == FAILURE || v2 == FAILURE)
    {
      return FAILURE;
    }
    return SUCCESS;
  }
  

  LIBRARY_API void DemoHack::exception (char *where, char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
} // Robot
