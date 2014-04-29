#ifndef CRCL_H
#define CRCL_H

typedef enum {
  CANON_SUCCESS = 0,
  CANON_FAILURE = 1,
  CANON_REJECT = 2,
} CanonReturn;

typedef int CRCLProgramParams;

typedef struct {
  double x, y, z;
} robotPosition;

typedef struct {
  double x, y, z, w;
} robotOrientation;

typedef struct {
  robotPosition position;
  robotOrientation orientation;
} robotPose;

#define ROBOT_AXES_MAX 8	/* ISSUE -- how can we get the actual number? */

typedef struct {
  double axis[ROBOT_AXES_MAX];
} robotAxes;

#endif	/* CRCL_H */
