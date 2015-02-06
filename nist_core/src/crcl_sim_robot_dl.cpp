#include <ulapi.h>
#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"
#include "nist_core/crcl_sim_robot.h"
#include "nist_core/crcl_sim_robot_dl.h"

namespace crcl_robot {

// these C-linkage functions make it easier to import as a DLL

extern "C" {
#if 0
} // a dummy right paren just to match the one above, to prevent indenting
#endif

ULAPI_DECL_SHARED CrclSimRobot *crcl_sim_robot_new(char *init_path)
{
  return new CrclSimRobot(init_path);
}

ULAPI_DECL_SHARED void crcl_sim_robot_delete(CrclSimRobot *r)
{
  if (NULL != r) delete r;
}

ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_move_straight_to(CrclSimRobot *r, double x, double y, double z, double xrot, double yrot, double zrot)
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

ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_get_robot_pose(CrclSimRobot *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot)
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

} // namespace crcl_robot
