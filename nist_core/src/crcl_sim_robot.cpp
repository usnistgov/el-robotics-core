#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

#include <sstream>
#include <string>

#include <ulapi.h>

#include "nist_core/nist_core.h"
#include "nist_core/crcl.h"
#include "nist_core/crcl_sim_robot.h"

/*
  Testing into simulator using a socket for move messages.
*/
#undef TESTING
#ifdef TESTING
static int port = 52336;
static char host[] = "speedy";
static int socket_client_fd = -1;
#endif

namespace crcl_robot {

// these C-linkage functions make it easier to import as a DLL

extern "C" {
#if 0
} // a dummy right paren just to match the one above, to prevent indenting
#endif

CrclSimRobot *crcl_sim_robot_new(char *init_path)
{
  return new CrclSimRobot(init_path);
}

void crcl_sim_robot_delete(CrclSimRobot *r)
{
  if (NULL != r) delete r;
}

CanonReturn crcl_sim_robot_move_straight_to(CrclSimRobot *r, double x, double y, double z, double xrot, double yrot, double zrot)
{
  robotPose end;

  end.x = x;
  end.y = y;
  end.z = z;
  end.xrot = xrot;
  end.yrot = yrot;
  end.zrot = zrot;

  return r->MoveStraightTo(end);
}

CanonReturn crcl_sim_robot_get_robot_pose(CrclSimRobot *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot)
{
  robotPose end;
  CanonReturn retval;

  retval = r->GetRobotPose(&end);

  *x = end.x;
  *y = end.y;
  *z = end.z;
  *xrot = end.xrot;
  *yrot = end.yrot;
  *zrot = end.zrot;

  return retval;
}

#if 0
{ // another dummy paren to prevent indenting
#endif
}

  LIBRARY_API CrclSimRobot::CrclSimRobot(char *init_path)
  {
    ulapi_mutex_init(&mutex, 1);

    simPose.x = 0;
    simPose.y = 0;
    simPose.z = 0;

    simPose.xrot = 0;
    simPose.yrot = 0;
    simPose.zrot = 0;

    absoluteSpeed = 1;
    toolSetting = 0;

    period = CRCL_SIM_PERIOD_DEFAULT;

#ifdef TESTING
    // Testing socket into robot simulator
    printf("connecting to %s on %d\n", host, port);
    socket_client_fd = ulapi_socket_get_client_id(port, host);
    printf("got %d\n", socket_client_fd);
#endif
  }

  LIBRARY_API CrclSimRobot::~CrclSimRobot()
  {
#ifdef TESTING
    // More testing
    if (socket_client_fd >= 0) ulapi_socket_close(socket_client_fd);
    socket_client_fd = -1;
#endif
  }

  LIBRARY_API double CrclSimRobot::setPeriod(double p)
  {
    period = p;

    return period;
  }

  LIBRARY_API double CrclSimRobot::getPeriod()
  {
    return period;
  }

#define SQ(x) ((x)*(x))

  static double robotPoseDiff(robotPose &p1, robotPose &p2)
  {
    // ignore orientation part
    return sqrt(SQ(p1.x - p2.x) +
		SQ(p1.y - p2.y) +
		SQ(p1.z - p2.z));
  }

#define LOCKIT ulapi_mutex_take(&mutex)
#define UNLOCKIT ulapi_mutex_give(&mutex)

  LIBRARY_API CanonReturn CrclSimRobot::MoveStraightTo(robotPose end)
  {
    robotPose here;
    double dist;
    double time;
    double xincr, yincr, zincr;
    double tfrac;

    LOCKIT;
    here = simPose;
    UNLOCKIT;

#ifdef TESTING
    // Testing -- convert pose to joints, send to simulator

    std::ostringstream buffer;
    buffer << end.x << " ";
    buffer << end.y << " ";
    buffer << end.z << " ";
    buffer << 0.1 << " ";
    buffer << 0.3 << "\n";

    printf("%s\n", (buffer.str()).c_str());
    if (socket_client_fd >= 0) {
      ulapi_socket_write(socket_client_fd, (buffer.str()).c_str(), strlen((buffer.str()).c_str()));
    }
#endif

    dist = robotPoseDiff(end, here);

    if (absoluteSpeed < FLT_MIN) time = FLT_MAX;
    else time = dist / absoluteSpeed;

    if (time < period) {
      LOCKIT;
      simPose = end;
      UNLOCKIT;
      return CANON_SUCCESS;
    }

    tfrac = period / time;
    xincr = (end.x - here.x) * tfrac;
    yincr = (end.y - here.y) * tfrac;
    zincr = (end.z - here.z) * tfrac;
    time += ulapi_time();

    while (ulapi_time() < time) {
      LOCKIT;
      simPose.x += xincr;
      simPose.y += xincr;
      simPose.z += xincr;
      UNLOCKIT;
      ulapi_sleep(period < FLT_MIN ? 1 : period);
    }

    LOCKIT;
    simPose = end;
    UNLOCKIT;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::SetTool(double percent)
  {
#define PERCENT_PER_SEC 33
    double here;
    double dist;
    double time;
    double incr;
    double tfrac;

    LOCKIT;
    here = toolSetting;
    UNLOCKIT;

    dist = percent - here;
    time = fabs(dist) / PERCENT_PER_SEC;

    if (time < period) {
      LOCKIT;
      toolSetting = percent;
      UNLOCKIT;
      return CANON_SUCCESS;
    }

    tfrac = period / time;
    incr = dist * tfrac;
    time += ulapi_time();

    while (ulapi_time() < time) {
      LOCKIT;
      toolSetting += incr;
      UNLOCKIT;
      ulapi_sleep(period < FLT_MIN ? 1 : period);
    }

    LOCKIT;
    toolSetting = percent;
    UNLOCKIT;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::StopMotion(int condition)
  {
    // any other move command will have been interrupted by now,
    // so just return OK

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::GetRobotPose (robotPose *pose)
  {
    LOCKIT;
    *pose = simPose;
    UNLOCKIT;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::GetRobotAxes (robotAxes *axes)
  {
    LOCKIT;
    // so trivial
    axes->axis[0] = simPose.x * 2;
    axes->axis[1] = simPose.y * 0.5;
    axes->axis[2] = -simPose.z;
    axes->axis[3] = simPose.xrot * 10;
    axes->axis[4] = simPose.yrot * 20;
    axes->axis[5] = simPose.zrot * 30;
    UNLOCKIT;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::GetTool (double *percent)
  {
    LOCKIT;
    *percent = toolSetting;
    UNLOCKIT;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::GetStatus (robotPose *pose, robotAxes *axes, double *percent)
  {
    GetRobotPose(pose);
    GetRobotAxes(axes);
    GetTool(percent);

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::SetRelativeSpeed(double percent)
  {
    if (percent < 0) percent = 0;

    relativeSpeed = percent;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::SetAbsoluteSpeed(double speed)
  {
    if (speed < 0) speed = 0;

    absoluteSpeed = speed;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::SetRelativeAcceleration(double percent)
  {
    if (percent < 0) percent = 0;

    relativeAcceleration = percent;

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrclSimRobot::SetAbsoluteAcceleration(double acceleration)
  {
    if (acceleration < 0) acceleration = 0;

    absoluteAcceleration = acceleration;

    return CANON_SUCCESS;
  }

} // namespace crcl_robot
