///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        Robot.cpp
//  Revision:        1.0 - 11 March, 2014
//                   2.0 - 20 February, 2015 - Transition from CRCL to CRPI.
//                                             Added CRCL XML handler.
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Robot interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crpi_robot.h"

using namespace std;

#include "nist_core/crpi_robotiq.h"
#include "nist_core/crpi_kuka_lwr.h"
#include "nist_core/crpi_schunk_sdh.h"
#include "nist_core/crpi_demo_hack.h"
#include "nist_core/crpi_universal.h"

//! Explicit instantiations
template class LIBRARY_API crpi_robot::CrpiRobot<crpi_robot::CrpiDemoHack>;
template class LIBRARY_API crpi_robot::CrpiRobot<crpi_robot::CrpiSchunkSDH>;
template class LIBRARY_API crpi_robot::CrpiRobot<crpi_robot::CrpiRobotiq>;
template class LIBRARY_API crpi_robot::CrpiRobot<crpi_robot::CrpiKukaLWR>;
template class LIBRARY_API crpi_robot::CrpiRobot<crpi_robot::CrpiUniversal>;

namespace crpi_robot
{
  template <class T> LIBRARY_API CrpiRobot<T>::CrpiRobot (char * initPath)
  {
    robInterface_ = new T(initPath);
    params_ = new CrclXmlParams();
    xml_ = new CrclXml(params_);
    rotMatrix_ = new matrix(3, 3);
    params_->toolName = "Nothing";
    params_->toolVal = 0.0f;
    v1_ = new vector3D;
    v2_ = new vector3D;
    v3_ = new vector3D;
    params_->status = CANON_REJECT;
  }


  template <class T> LIBRARY_API CrpiRobot<T>::~CrpiRobot ()
  {
    delete robInterface_;
  }


  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetTool (double percent)
	{
    CanonReturn val;
    params_->status = CANON_RUNNING;
    params_->toolVal = percent;
		val = robInterface_->SetTool (percent);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::Couple (const char *targetID)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    params_->toolName = targetID;
    val = robInterface_->Couple(targetID);
    params_->status = val;
		return val;
	}


  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::Decouple (const char *targetID)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    params_->toolName = "Nothing";
		val = robInterface_->Decouple (targetID);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::Dwell (int *events, double *params, int numEvents)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->Dwell (events, params, numEvents);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::EndCanon (int reason)
  {
    CanonReturn val = robInterface_->EndCanon (reason);
    if (val == CANON_SUCCESS)
    {
      params_->status = CANON_REJECT;
    }
		return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::GetRobotAxes (robotAxes *axes)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    val = robInterface_->GetRobotAxes (axes);
    *params_->axes = *axes;
    params_->status = val;
		return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::GetRobotPose (robotPose *pose)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->GetRobotPose (pose);
    RPYMatrixConvert (*pose, *rotMatrix_);
    params_->xaxis.i = rotMatrix_->at (0, 0);
    params_->xaxis.j = rotMatrix_->at (1, 0);
    params_->xaxis.k = rotMatrix_->at (2, 0);

    params_->zaxis.i = rotMatrix_->at (0, 2);
    params_->zaxis.j = rotMatrix_->at (1, 2);
    params_->zaxis.k = rotMatrix_->at (2, 2);
    params_->status = val;
    return val;
	}

  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::GetRobotIO (robotIO *io)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    val = robInterface_->GetRobotIO (io);
    params_->status = val;
    return val;
  }


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::InitCanon ()
  {
    params_->status = robInterface_->InitCanon ();
		return params_->status;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::Message (const char *message)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->Message (message);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::MoveStraightTo (robotPose pose)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->MoveStraightTo (pose);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::MoveThroughTo (robotPose *poses,
                                                                           int numPoses,
                                                                           robotPose *accelerations,
                                                                           robotPose *speeds,
                                                                           robotPose *tolerances)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->MoveThroughTo (poses, numPoses, accelerations, speeds, tolerances);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::MoveTo (robotPose pose)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->MoveTo (pose);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::MoveAttractor (robotPose pose)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->MoveAttractor (pose);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::MoveToAxisTarget (robotAxes axes)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->MoveToAxisTarget (axes);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::RunProgram (const char *programName, CRPIProgramParams params)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->RunProgram (programName, params);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetAbsoluteAcceleration (double tolerance)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetAbsoluteAcceleration (tolerance);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetAbsoluteSpeed (double speed)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetAbsoluteSpeed (speed);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetAngleUnits (const char *unitName)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetAngleUnits (unitName);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetAxialSpeeds (double *speeds)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetAxialSpeeds (speeds);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetAxialUnits (const char **unitNames)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetAxialUnits (unitNames);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetEndPoseTolerance (robotPose tolerance)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetEndPoseTolerance (tolerance);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetIntermediatePoseTolerance (tolerances);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetLengthUnits (const char *unitName)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetLengthUnits (unitName);
    params_->status = val;
    return val;
	}


  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetParameter (const char *paramName, void *paramVal)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    val = robInterface_->SetParameter (paramName, paramVal);
    params_->status = val;
    return val;
  }


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetRelativeAcceleration (double percent)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetRelativeAcceleration (percent);
    params_->status = val;
    return val;
	}


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetRelativeSpeed (double percent)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->SetRelativeSpeed (percent);
    params_->status = val;
    return val;
	}


  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::SetRobotIO (robotIO io)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
    val = robInterface_->SetRobotIO (io);
    params_->status = val;
    return val;
  }


	template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::StopMotion (int condition)
  {
    CanonReturn val;
    params_->status = CANON_RUNNING;
		val = robInterface_->StopMotion (condition);
    params_->status = val;
    return val;
	}


  template <class T> LIBRARY_API CanonReturn CrpiRobot<T>::XmlHandler (std::string& str)
  {
    xml_->parse(str); //! Populate the params_ structure based on the XML string

    //! Get the CRPI 6DOF pose from the 2-vector representation CRCL uses
    v1_->i = params_->xaxis.i;
    v1_->j = params_->xaxis.j;
    v1_->k = params_->xaxis.k;

    v2_->i = params_->zaxis.i;
    v2_->j = params_->zaxis.j;
    v2_->k = params_->zaxis.k;

    v3_->i = -((v1_->j * v2_->k) - (v1_->k * v2_->j));
    v3_->j = -((v1_->k * v2_->i) - (v1_->i * v2_->k));
    v3_->k = -((v1_->i * v2_->j) - (v1_->j * v2_->i));

    rotMatrix_->at(0, 0) = v1_->i;
    rotMatrix_->at(1, 0) = v1_->j;
    rotMatrix_->at(2, 0) = v1_->k;
    rotMatrix_->at(0, 1) = v3_->i;
    rotMatrix_->at(1, 1) = v3_->j;
    rotMatrix_->at(2, 1) = v3_->k;
    rotMatrix_->at(0, 2) = v2_->i;
    rotMatrix_->at(1, 2) = v2_->j;
    rotMatrix_->at(2, 2) = v2_->k;

    matrixRPYconvert (*rotMatrix_, *params_->pose);

    params_->pose->xrot *= (180.0f / 3.141592654f);
    params_->pose->yrot *= (180.0f / 3.141592654f);
    params_->pose->zrot *= (180.0f / 3.141592654f);

    switch (params_->cmd)
    {
    case CmdCouple:
      return Couple (params_->str.c_str());
      break;
    case CmdDecouple:
      return Decouple (params_->str.c_str());
      break;
    case CmdDwell:
      //! JAM: TODO
      break;
    case CmdEndCanon:
      return EndCanon ((int)params_->numPositions);
      break;
    case CmdGetRobotAxes:
      //return GetRobotAxes (params_->axes);
      break;
    case CmdGetRobotIO:
      //! JAM: TODO
      break;
    case CmdGetRobotPose:
      return GetRobotPose (params_->pose);
      break;
    case CmdInitCanon:
      return InitCanon ();
      break;
    case CmdMessage:
      return Message (params_->str.c_str());
      break;
    case CmdMoveAttractor:
      return MoveAttractor (*params_->pose);
      break;
    case CmdMoveStraightTo:
      return MoveStraightTo (*params_->pose);
      break;
    case CmdMoveThroughTo:
      break;
    case CmdMoveTo:
      if (params_->moveStraight)
      {
        return MoveStraightTo (*params_->pose);
      }
      else
      {
        return MoveTo (*params_->pose);
      }
      break;
    case CmdMoveToAxisTarget:
      return MoveToAxisTarget (*params_->axes);
      break;
    case CmdRunProgram:
      //! JAM: TODO
      break;
    case CmdSetAbsoluteAcceleration:
      return SetAbsoluteAcceleration (params_->numPositions);
      break;
    case CmdSetAbsoluteSpeed:
      return SetAbsoluteSpeed (params_->numPositions);
      break;
    case CmdSetAngleUnits:
      return SetAngleUnits (params_->str.c_str());
      break;
    case CmdSetAxialSpeeds:
      //! JAM: TODO
      break;
    case CmdSetAxialUnits:
      //! JAM: TODO
      break;
    case CmdSetEndPoseTolerance:
      break;
    case CmdSetIntermediatePoseTolerance:
      break;
    case CmdSetLengthUnits:
      return SetLengthUnits (params_->str.c_str());
      break;
    case CmdSetParameter:
      //SetParameter (params_->str.c_str(), *(params_->numPositions));
      break;
    case CmdSetRelativeAcceleration:
      return SetRelativeAcceleration (params_->numPositions);
      break;
    case CmdSetRelativeSpeed:
      return SetRelativeSpeed (params_->numPositions);
      break;
    case CmdSetRobotIO:
      break;
    case CmdSetTool:
      return SetTool (params_->numPositions);
      break;
    case CmdStopMotion:
      //! JAM: TODO
      break;
    default:
      break;
    }
    return CANON_REJECT;
  }


  template <class T> LIBRARY_API bool CrpiRobot<T>::matrixRPYconvert (matrix &m, robotPose &pose)
  {
    pose.yrot = atan2(-(m.at(2, 0)), sqrt((m.at(0, 0) * m.at(0, 0)) + (m.at(1, 0) * m.at(1, 0))));

    if (fabs(pose.yrot - 1.57079632679489661923f) < 1.0e-4)
    {
      pose.xrot = atan2 (m.at(0, 1), m.at(1, 1));
      pose.yrot = 1.57079632679489661923f;
      pose.zrot = 0.0f;
    }
    else if (fabs(pose.yrot + 1.57079632679489661923f) < 1.0e-4)
    {
      pose.xrot = -atan2(m.at(0, 1), m.at(1, 1));
      pose.yrot = -1.57079632679489661923f;
      pose.zrot = 0.0f;
    }
    else
    {
      pose.xrot = atan2(m.at(2, 1), m.at(2, 2));
      pose.zrot = atan2(m.at(1, 0), m.at(0, 0));
    }

    return true;
  }
 

  template <class T> LIBRARY_API bool CrpiRobot<T>::RPYMatrixConvert (const robotPose &pose, matrix &m)
  {
    double sa, sb, sg;
    double ca, cb, cg;

    sa = sin(pose.zrot);
    sb = sin(pose.yrot);
    sg = sin(pose.xrot);

    ca = cos(pose.zrot);
    cb = cos(pose.yrot);
    cg = cos(pose.xrot);

    m.at(0, 0) = ca * cb;
    m.at(0, 1) = ca * sb * sg - sa * cg;
    m.at(0, 2) = ca * sb * cg + sa * sg;

    m.at(1, 0) = sa * cb;
    m.at(1, 1) = sa * sb * sg + ca * cg;
    m.at(1, 2) = sa * sb * cg - ca * sg;

    m.at(2, 0) = -sb;
    m.at(2, 1) = cb * sg;
    m.at(2, 2) = cb * cg;

    return true;
  }

} // Robot
