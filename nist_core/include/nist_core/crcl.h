#ifndef CRCL_H_
#define CRCL_H_

typedef enum {
  CANON_SUCCESS = 0,
  CANON_FAILURE,
  CANON_REJECT
} CanonReturn;

struct robotPose {
  double x;
  double y;
  double z;
  double xrot;
  double yrot;
  double zrot;
};

#define CRCL_AXES_MAX 8

struct robotAxes {
  double axis[CRCL_AXES_MAX];
  int axes;
};

struct CRCLProgramParams {
  int param;			/* FIXME -- what are these? */
};

#endif	/* CRCL_H_ */
