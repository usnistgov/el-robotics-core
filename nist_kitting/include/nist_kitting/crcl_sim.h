#ifndef SIM_ROBOT_H
#define SIM_ROBOT_H

#include "crcl.h"		/* robotPose, robotAxes, CRCLProgramParams */
#include "crcl_robot.h"		/* CRCL_Robot */

class CRCL_Sim : public CRCL_Robot {
 public:
  CRCL_Sim();
  ~CRCL_Sim() {};

  CanonReturn Couple (char *targetID) {};
  CanonReturn Dwell (int *events, double *params, int numEvents) {};
  CanonReturn EndCanon (int reason) {};
  CanonReturn InitCanon () {};
  CanonReturn Message (char *message) {};
  CanonReturn MoveStraightTo (robotPose pose);
  CanonReturn MoveThroughTo (robotPose *poses,
			     int numPoses,
			     robotPose *accelerations = NULL,
			     robotPose *speeds = NULL,
			     robotPose *tolerances = NULL) {};
  CanonReturn Decouple (char *targetID) {};
  CanonReturn GetRobotAxes (robotAxes *axes) {};
  CanonReturn GetRobotPose (robotPose *pose);
  CanonReturn MoveAttractor (robotPose pose) {};
  CanonReturn MoveToAxisTarget (robotAxes axes) {};
  CanonReturn RunProgram (char *programName, CRCLProgramParams params) {};
  CanonReturn SetAbsoluteAcceleration (double acceleration) {};
  CanonReturn SetAbsoluteSpeed (double speed) {};
  CanonReturn SetAngleUnits (char *unitName) {};
  CanonReturn SetAxialSpeeds (double *speeds) {};
  CanonReturn SetAxialUnits (char **unitNames) {};
  CanonReturn SetEndPoseTolerance (robotPose tolerance) {};
  CanonReturn SetIntermediatePoseTolerance (robotPose *tolerances) {};
  CanonReturn SetLengthUnits (char *unitName) {};
  CanonReturn SetParameter (char *paramName, void *paramVal) {};
  CanonReturn SetTool (double percent) {};
  CanonReturn SetRelativeSpeed (double percent) {};
  CanonReturn StopMotion (int condition);

private:
  robotPose simPose;
};

#endif	/* SIM_ROBOT_H */

