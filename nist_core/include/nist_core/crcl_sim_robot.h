#ifndef CRCL_SIM_ROBOT_H
#define CRCL_SIM_ROBOT_H

#include <ulapi.h>

#include "nist_core/nist_core.h" /* LIBRARY_API */
#include "nist_core/crcl.h" /* robotPose, robotAxes, CRCLProgramParams */
#include "nist_core/crcl_robot.h" /* CRCL_Robot */

#define CRCL_SIM_PERIOD_DEFAULT 0.100 /* seconds per simulation period */

namespace crcl_robot {

  class LIBRARY_API CrclSimRobot {
  public:
    CrclSimRobot(char *init_path);
    CrclSimRobot(double period);
    ~CrclSimRobot();

    CanonReturn Couple (char *targetID);
    CanonReturn Dwell (int *events, double *params, int numEvents);
    CanonReturn EndCanon (int reason);
    CanonReturn InitCanon ();
    CanonReturn Message (char *message);
    CanonReturn MoveStraightTo (robotPose pose);
    CanonReturn MoveThroughTo (robotPose *poses,
			       int numPoses,
			       robotPose *accelerations = NULL,
			       robotPose *speeds = NULL,
			       robotPose *tolerances = NULL);
    CanonReturn Decouple (char *targetID);
    CanonReturn GetRobotAxes (robotAxes *axes);
    CanonReturn GetRobotPose (robotPose *pose);
    CanonReturn MoveAttractor (robotPose pose);
    CanonReturn MoveToAxisTarget (robotAxes axes);
    CanonReturn RunProgram (char *programName, CRCLProgramParams params);
    CanonReturn SetAbsoluteAcceleration (double acceleration);
    CanonReturn SetAbsoluteSpeed (double speed);
    CanonReturn SetAngleUnits (char *unitName);
    CanonReturn SetAxialSpeeds (double *speeds);
    CanonReturn SetAxialUnits (char **unitNames);
    CanonReturn SetEndPoseTolerance (robotPose tolerance);
    CanonReturn SetIntermediatePoseTolerance (robotPose *tolerances);
    CanonReturn SetLengthUnits (char *unitName);
    CanonReturn SetParameter (char *paramName, void *paramVal);
    CanonReturn SetRelativeAcceleration(double percent);
    CanonReturn SetTool (double percent);
    CanonReturn SetRelativeSpeed (double percent);
    CanonReturn StopMotion (int condition);

    // extensions
    CanonReturn GetTool (double *percent);
    CanonReturn GetStatus (robotPose *pose, robotAxes *axes, double *percent);
    double setPeriod(double period);
    double getPeriod();

  private:

    ulapi_mutex_struct mutex;
    robotPose simPose;
    double relativeSpeed;
    double absoluteSpeed;
    double relativeAcceleration;
    double absoluteAcceleration;
    double toolSetting;
    double period;
  };

/* declarations for C-linkable functions, useful for DLLs */

extern "C" {
#if 0
} // a dummy right paren just to match the one above, to prevent indenting
#endif

ULAPI_DECL_SHARED CrclSimRobot *crcl_sim_robot_new(char *init_path);
ULAPI_DECL_SHARED void crcl_sim_robot_delete(CrclSimRobot *r);
ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_move_straight_to(CrclSimRobot *r, double x, double y, double z, double xrot, double yrot, double zrot);
ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_get_robot_pose(CrclSimRobot *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot);

#if 0
{ // another dummy paren to prevent indenting
#endif
}

} /* namespace crcl_robot */

#endif	/* CRCL_SIM_ROBOT_H */

