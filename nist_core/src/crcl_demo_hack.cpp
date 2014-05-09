///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        CrclDemoHack.cpp
//  Revision:        1.0 - 08 April, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  A hack of an interface for the Robotiq gripper on the Kuka arm.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crcl_demo_hack.h"

using namespace std;

namespace crcl_robot
{
  LIBRARY_API CrclDemoHack::CrclDemoHack (char * initPath)
  {
    arm_ = new robotArm (initPath);
    hand_ = new robotHand (initPath);
  }


  LIBRARY_API CrclDemoHack::~CrclDemoHack ()
  {
    delete [] hand_;
    delete [] arm_;
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetTool (double percent)
  {
    return hand_->SetTool(percent);
  }


  LIBRARY_API CanonReturn CrclDemoHack::Couple (char *targetID)
  {
    //! Robot arm and hand are permanently coupled in this hack
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclDemoHack::Dwell (int *events, double *params, int numEvents)
  {
    return arm_->Dwell(events, params, numEvents);
  }


  LIBRARY_API CanonReturn CrclDemoHack::EndCanon (int reason)
  {
    v1 = arm_->EndCanon (reason);
    v2 = hand_->EndCanon (reason);

    if (v1 == CANON_REJECT || v2 == CANON_REJECT)
    {
      return CANON_REJECT;
    }
    else if (v1 == CANON_FAILURE || v2 == CANON_FAILURE)
    {
      return CANON_FAILURE;
    }
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclDemoHack::InitCanon ()
  {
    v1 = arm_->InitCanon ();
    v2 = hand_->InitCanon ();

    if (v1 == CANON_REJECT || v2 == CANON_REJECT)
    {
      return CANON_REJECT;
    }
    else if (v1 == CANON_FAILURE || v2 == CANON_FAILURE)
    {
      return CANON_FAILURE;
    }
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclDemoHack::Message (char *message)
  {
    v1 = arm_->Message (message);
    v2 = hand_->Message (message);

    if (v1 == CANON_REJECT || v2 == CANON_REJECT)
    {
      return CANON_REJECT;
    }
    else if (v1 == CANON_FAILURE || v2 == CANON_FAILURE)
    {
      return CANON_FAILURE;
    }
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclDemoHack::MoveStraightTo (robotPose pose)
  {
    return arm_->MoveStraightTo (pose);
  }


  LIBRARY_API CanonReturn CrclDemoHack::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    return arm_->MoveThroughTo (poses, numPoses, accelerations, speeds, tolerances);
  }


  LIBRARY_API CanonReturn CrclDemoHack::MoveTo (robotPose pose)
  {
    return arm_->MoveTo (pose);
  }


  LIBRARY_API CanonReturn CrclDemoHack::Decouple (char *targetID)
  {
    //! Robot arm and hand are permanently attached in this hack
    return CANON_FAILURE;
  }


  LIBRARY_API CanonReturn CrclDemoHack::GetRobotAxes (robotAxes *axes)
  {
    return arm_->GetRobotAxes (axes);
  }


  LIBRARY_API CanonReturn CrclDemoHack::GetRobotPose (robotPose *pose)
  {
    return arm_->GetRobotPose (pose);
  }


  LIBRARY_API CanonReturn CrclDemoHack::MoveAttractor (robotPose pose)
  {
    return arm_->MoveAttractor (pose);
  }


  LIBRARY_API CanonReturn CrclDemoHack::MoveToAxisTarget (robotAxes axes)
  {
    return arm_->MoveToAxisTarget (axes);
  }


  LIBRARY_API CanonReturn CrclDemoHack::RunProgram (char *programName, CRCLProgramParams params)
  {
    return arm_->RunProgram (programName, params);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetAbsoluteAcceleration (double acceleration)
  {
    return arm_->SetAbsoluteAcceleration (acceleration);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetAbsoluteSpeed (double speed)
  {
    return arm_->SetAbsoluteSpeed (speed);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetAngleUnits (char *unitName)
  {
    return arm_->SetAngleUnits (unitName);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetAxialSpeeds (double *speeds)
  {
    return arm_->SetAxialSpeeds (speeds);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetAxialUnits (char **unitNames)
  {
    return arm_->SetAxialUnits (unitNames);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetEndPoseTolerance (robotPose tolerance)
  {
    return arm_->SetEndPoseTolerance (tolerance);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return arm_->SetIntermediatePoseTolerance (tolerances);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetLengthUnits (char *unitName)
  {
    return arm_->SetLengthUnits (unitName);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetParameter (char *paramName, void *paramVal)
  {
    //! Unfortunately we have to assume we're addressing one robot or the other.  Here, we
    //! assume we're addressing the hand.  Hacking together two robots like this is going
    //! to result in reduced functionality.
    return hand_->SetParameter (paramName, paramVal);
  }

  LIBRARY_API CanonReturn CrclDemoHack::SetRelativeAcceleration (double percent)
  {
    return arm_->SetRelativeAcceleration (percent);
  }


  LIBRARY_API CanonReturn CrclDemoHack::SetRelativeSpeed (double percent)
  {
    return arm_->SetRelativeSpeed (percent);
  }


  LIBRARY_API CanonReturn CrclDemoHack::StopMotion (int condition)
  {
    v1 = arm_->StopMotion (condition);
    v2 = hand_->StopMotion (condition);

    if (v1 == CANON_REJECT || v2 == CANON_REJECT)
    {
      return CANON_REJECT;
    }
    else if (v1 == CANON_FAILURE || v2 == CANON_FAILURE)
    {
      return CANON_FAILURE;
    }
    return CANON_SUCCESS;
  }

} // Robot
