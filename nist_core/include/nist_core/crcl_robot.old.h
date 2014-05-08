#ifndef CRCL_ROBOT_H_
#define CRCL_ROBOT_H_

#include <stddef.h>		 /* NULL */
#include "nist_core/nist_core.h" /* LIBRARY_API */
#include "nist_core/crcl.h"    /* CanonReturn, robotPose, robotAxes */

namespace crcl_robot {

  template <class T> class LIBRARY_API CrclRobot {
  public:

    CrclRobot(const char *init_path);
     ~CrclRobot();
    CanonReturn Couple(char *targetID);
    CanonReturn Dwell(int *events, double *params, int numEvents);
    CanonReturn EndCanon(int reason);
    CanonReturn InitCanon();
    CanonReturn Message(char *message);
    CanonReturn MoveStraightTo(robotPose pose);
    CanonReturn MoveThroughTo(robotPose * poses,
			      int numPoses,
			      robotPose * accelerations = NULL,
			      robotPose * speeds = NULL,
			      robotPose * tolerances = NULL);
    CanonReturn MoveTo(robotPose pose);
    CanonReturn Decouple(char *targetID);
    CanonReturn GetRobotAxes(robotAxes * axes);
    CanonReturn GetRobotPose(robotPose * pose);
    CanonReturn MoveAttractor(robotPose pose);
    CanonReturn MoveToAxisTarget(robotAxes axes);
    // this is different from the document
    CanonReturn RunProgram(char *programName, CRCLProgramParams params);
    CanonReturn SetAbsoluteAcceleration(double acceleration);
    CanonReturn SetAbsoluteSpeed(double speed);
    CanonReturn SetAngleUnits(char *unitName);
    CanonReturn SetAxialSpeeds(double *speeds);
    CanonReturn SetAxialUnits(char **unitNames);
    CanonReturn SetEndPoseTolerance(robotPose tolerance);
    CanonReturn SetIntermediatePoseTolerance(robotPose * tolerances);
    CanonReturn SetLengthUnits(char *unitName);
    CanonReturn SetParameter(char *paramName, void *paramVal);
    CanonReturn SetRelativeAcceleration(double percent);
    CanonReturn SetTool(double percent);
    CanonReturn SetRelativeSpeed(double percent);
    CanonReturn StopMotion(int condition = 2); /* an enum type? */

 private:
      T *robInterface_;
  };					       /* crcl_robot */

} /* namespace crcl_robot */

#endif	/* CRCL_ROBOT_H_ */


