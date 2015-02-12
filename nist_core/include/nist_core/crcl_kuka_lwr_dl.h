#ifndef CRCL_KUKA_LWR_DL_H
#define CRCL_KUKA_LWR_DL_H

/* declarations for C-linkable functions, useful for DLLs */

#include <ulapi.h>
#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"
#include "nist_core/crcl_kuka_lwr.h"

namespace crcl_robot {
#if 0
}
#endif

extern "C" {
#if 0
}
#endif

ULAPI_DECL_SHARED CrclKukaLWR *crcl_kuka_lwr_new(char *init_path);
ULAPI_DECL_SHARED void crcl_kuka_lwr_delete(CrclKukaLWR *r);
ULAPI_DECL_SHARED CanonReturn crcl_kuka_lwr_move_straight_to(CrclKukaLWR *r, double x, double y, double z, double xrot, double yrot, double zrot);
ULAPI_DECL_SHARED CanonReturn crcl_kuka_lwr_get_robot_pose(CrclKukaLWR *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot);

#if 0
{
#endif
}

#if 0
{
#endif
}

#endif	/* CRCL_KUKA_LWR_DL_H */
