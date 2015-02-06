#ifndef CRCL_SIM_ROBOT_DL_H
#define CRCL_SIM_ROBOT_DL_H

/* declarations for C-linkable functions, useful for DLLs */

#include <ulapi.h>
#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"
#include "nist_core/crcl_sim_robot.h"

namespace crcl_robot {
#if 0
}
#endif

extern "C" {
#if 0
}
#endif

ULAPI_DECL_SHARED CrclSimRobot *crcl_sim_robot_new(char *init_path);
ULAPI_DECL_SHARED void crcl_sim_robot_delete(CrclSimRobot *r);
ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_move_straight_to(CrclSimRobot *r, double x, double y, double z, double xrot, double yrot, double zrot);
ULAPI_DECL_SHARED CanonReturn crcl_sim_robot_get_robot_pose(CrclSimRobot *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot);

#if 0
{
#endif
}

#if 0
{
#endif
}

#endif	/* CRCL_SIM_ROBOT_DL_H */
