///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        crcl_universal.cpp
//  Revision:        1.0 - 24 June, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Universal Robot UR10 interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crcl_universal.h"
#include <fstream>

using namespace std;

namespace crcl_robot
{
  LIBRARY_API CrclUniversal::CrclUniversal (char *initPath) :
    acceptCRCL_(false)
  {
    mssgBuffer_ = new char[8192];
    int val;
    ulapi_init();

  }


  LIBRARY_API CrclUniversal::~CrclUniversal ()
  {
 
  }


  LIBRARY_API CanonReturn CrclUniversal::SetTool (double percent)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::Couple (char *targetID)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::Dwell (int *events, double *params, int numEvents)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::EndCanon (int reason)
  {
    acceptCRCL_ = false;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclUniversal::InitCanon ()
  {
    acceptCRCL_ = true;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclUniversal::Message (char *message)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::MoveStraightTo (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::MoveThroughTo (robotPose *poses,
                                                        int numPoses,
                                                        robotPose *accelerations,
                                                        robotPose *speeds,
                                                        robotPose *tolerances)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::MoveTo (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::Decouple (char *targetID)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::GetRobotAxes (robotAxes *axes)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::GetRobotPose (robotPose *pose)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::MoveAttractor (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::MoveToAxisTarget (robotAxes axes)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::RunProgram (char *programName, CRCLProgramParams params)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetAbsoluteAcceleration (double tolerance)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetAbsoluteSpeed (double speed)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }

   //  ("degree" or "radian")
  LIBRARY_API CanonReturn CrclUniversal::SetAngleUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetAxialSpeeds (double *speeds)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }
    //! TODO
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetAxialUnits (char **unitNames)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetEndPoseTolerance (robotPose tolerances)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetLengthUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetParameter (char *paramName, void *paramVal)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetRelativeAcceleration (double percent)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::SetRelativeSpeed (double percent)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclUniversal::StopMotion (int condition)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }
  

  LIBRARY_API bool CrclUniversal::send ()
  {

    int x;
    //! Send message to robot via serial
    if (serialUsed_)
    {
      printf ("Sending message %s\n", moveMe_.str().c_str());
      x = ulapi_serial_write(serialID_, moveMe_.str().c_str(), strlen(moveMe_.str().c_str()) + 1);
      printf ("%i\n", x);
      return true;
    }
    else
    {
      //! TODO
      return false;
    }
  }


  LIBRARY_API bool CrclUniversal::get ()
  {
    int x = 0;
    if (serialUsed_)
    {
      printf ("getting feedback...\n");
      x = ulapi_serial_read(serialID_, mssgBuffer_, 8192);
      printf ("%d read\n", x);
      return true;
    }
    else
    {
      //! TODO
      return false;
    }
  }

} // crcl_robot
