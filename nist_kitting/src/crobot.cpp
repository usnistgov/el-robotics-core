#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */

#include <nist_core/crcl.h>
#include <nist_core/crcl_robot.h>
#include <nist_core/crcl_sim_robot.h>

using namespace crcl_robot;

extern "C" CrclSimRobot *crcl_sim_robot_new(char *init_path);
extern "C" void crcl_sim_robot_delete(CrclSimRobot *r);
extern "C" CanonReturn crcl_sim_robot_move_straight_to(CrclSimRobot *r, double x, double y, double z, double xrot, double yrot, double zrot);
extern "C" CanonReturn crcl_sim_robot_get_robot_pose(CrclSimRobot *r, double *x, double *y, double *z, double *xrot, double *yrot, double *zrot);

int main(int argc, char *argv[])
{
  CrclSimRobot *robot = crcl_sim_robot_new(NULL);
  double x, y, z, xrot, yrot, zrot;

  x = 1;
  y = -2.2;
  z = 3.14;
  xrot = -0.1;
  yrot = 0.2;
  zrot = -0.3;

  crcl_sim_robot_move_straight_to(robot, x, y, z, xrot, yrot, zrot);

  x = 0;
  y = 0;
  z = 0;
  xrot = 0;
  yrot = 0;
  zrot = 0;

  crcl_sim_robot_get_robot_pose(robot, &x, &y, &z, &xrot, &yrot, &zrot);

  printf("%f %f %f\n", x, y, z);

  return 0;
}
