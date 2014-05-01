///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        Robot.cpp
//  Revision:        1.0 - 11 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Robot interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "Robot.h"

using namespace std;

//! Explicit instantiations
template class LIBRARY_API Robot::CRCL_Robot<Robot::DemoHack>;
template class LIBRARY_API Robot::CRCL_Robot<Robot::Schunk_SDH>;
template class LIBRARY_API Robot::CRCL_Robot<Robot::Robotiq>;
template class LIBRARY_API Robot::CRCL_Robot<Robot::Kuka_LWR>;
//template class LIBRARY_API Robot::CRCL_Robot<Robot::Universal_UR10>;


namespace Robot
{
  template <class T> LIBRARY_API CRCL_Robot<T>::CRCL_Robot (Logger *logger, char * initPath) :
    logger_(logger)
  {
    robInterface_ = new T(logger, initPath);
  }


  template <class T> LIBRARY_API CRCL_Robot<T>::~CRCL_Robot ()
  {
    delete robInterface_;
    logger_ = NULL;
  }


  template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetTool (double percent)
	{
		return robInterface_->SetTool (percent);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::Couple (char *targetID)
  {
		return robInterface_->Couple(targetID);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::Dwell (int *events, double *params, int numEvents)
  {
		return robInterface_->Dwell (events, params, numEvents);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::EndCanon (int reason)
  {
		return robInterface_->EndCanon (reason);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::InitCanon ()
  {
		return robInterface_->InitCanon ();
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::Message (char *message)
  {
		return robInterface_->Message (message);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::MoveStraightTo (robotPose pose)
  {
		return robInterface_->MoveStraightTo (pose);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::MoveThroughTo (robotPose *poses,
                                                                           int numPoses,
                                                                           robotPose *accelerations,
                                                                           robotPose *speeds,
                                                                           robotPose *tolerances)
  {
		return robInterface_->MoveThroughTo (poses, numPoses, accelerations, speeds, tolerances);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::MoveTo (robotPose pose)
  {
		return robInterface_->MoveTo (pose);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::Decouple (char *targetID)
  {
		return robInterface_->Decouple (targetID);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::GetRobotAxes (robotAxes *axes)
  {
		return robInterface_->GetRobotAxes (axes);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::GetRobotPose (robotPose *pose)
  {
		return robInterface_->GetRobotPose (pose);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::MoveAttractor (robotPose pose)
  {
		return robInterface_->MoveAttractor (pose);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::MoveToAxisTarget (robotAxes axes)
  {
		return robInterface_->MoveToAxisTarget (axes);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::RunProgram (char *programName, CRCLProgramParams params)
  {
		return robInterface_->RunProgram (programName, params);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetAbsoluteAcceleration (double tolerance)
  {
		return robInterface_->SetAbsoluteAcceleration (tolerance);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetAbsoluteSpeed (double speed)
  {
		return robInterface_->SetAbsoluteSpeed (speed);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetAngleUnits (char *unitName)
  {
		return robInterface_->SetAngleUnits (unitName);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetAxialSpeeds (double *speeds)
  {
		return robInterface_->SetAxialSpeeds (speeds);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetAxialUnits (char **unitNames)
  {
		return robInterface_->SetAxialUnits (unitNames);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetEndPoseTolerance (robotPose tolerance)
  {
		return robInterface_->SetEndPoseTolerance (tolerance);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
		return robInterface_->SetIntermediatePoseTolerance (tolerances);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetLengthUnits (char *unitName)
  {
		return robInterface_->SetLengthUnits (unitName);
	}


  template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetParameter (char *paramName, void *paramVal)
  {
    return robInterface_->SetParameter (paramName, paramVal);
  }


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetRelativeAcceleration (double percent)
  {
		return robInterface_->SetRelativeAcceleration (percent);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::SetRelativeSpeed (double percent)
  {
		return robInterface_->SetRelativeSpeed (percent);
	}


	template <class T> LIBRARY_API CanonReturn CRCL_Robot<T>::StopMotion (int condition)
  {
		return robInterface_->StopMotion (condition);
	}


  template <class T> LIBRARY_API void CRCL_Robot<T>::exception (char *where, char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
} // Robot
