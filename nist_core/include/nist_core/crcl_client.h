#ifndef CRCL_CLIENT_H
#define CRCL_CLIENT_H

#include <ulapi.h>		/* ulapi_mutex_struct */

#include "nist_core/crcl.h" /* robotPose, robotAxes, CRCLProgramParams */
#include "nist_core/crcl_robot.h"

#define CRCL_CLIENT_HOST_DEFAULT "localhost"
#define CRCL_CLIENT_CMD_PORT_DEFAULT 1234
#define CRCL_CLIENT_STAT_PORT_DEFAULT 1235

namespace crcl_robot {

  class LIBRARY_API CrclClient {
  public:
    CrclClient();
    ~CrclClient();

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

    bool connect(const char *host, int cmd_port, int stat_port);
    bool connect();
    bool isConnected();
    CanonReturn getCmdResult();
    CanonReturn getStatResult();
    void startCmd();
    bool cmdDone();
    void startStat();
    bool statDone();

  private:

    ulapi_mutex_struct mutex;
    int cmd_socket;
    int stat_socket;
    bool connected;
    CanonReturn cmdResult;
    CanonReturn statResult;
    bool cmdDoneFlag;
    bool statDoneFlag;

    CanonReturn setCmdResult(const char *str);
    CanonReturn setStatResult(const char *str);
  };

}      /* namespace crcl_robot */

#endif	/* CRCL_CLIENT_H */

