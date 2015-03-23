///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        crpi.h
//  Revision:        1.0 - 13 March, 2014
//                   2.0 - 12 March, 2015 - Conversion from CRCL to CRPI
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Central Robot Programming Interface type definitions and declarations.
//
///////////////////////////////////////////////////////////////////////////////


#ifndef CRPI_H_
#define CRPI_H_

#include "ulapi.h"
#include <math.h>

typedef enum
{
  CmdCouple = 0,
  CmdDecouple,
  CmdDwell,
  CmdEndCanon,
  CmdGetRobotAxes,
  CmdGetRobotIO,
  CmdGetRobotPose,
  CmdInitCanon,
  CmdMessage,
  CmdMoveAttractor,
  CmdMoveStraightTo,
  CmdMoveThroughTo,
  CmdMoveTo,
  CmdMoveToAxisTarget,
  CmdRunProgram,
  CmdSetAbsoluteAcceleration,
  CmdSetAbsoluteSpeed,
  CmdSetAngleUnits,
  CmdSetAxialSpeeds,
  CmdSetAxialUnits,
  CmdSetEndPoseTolerance,
  CmdSetIntermediatePoseTolerance,
  CmdSetLengthUnits,
  CmdSetParameter,
  CmdSetRelativeAcceleration,
  CmdSetRelativeSpeed,
  CmdSetRobotIO,
  CmdSetTool,
  CmdStopMotion
} CanonCommand;

typedef enum
{
  CANON_SUCCESS = 0,
  CANON_FAILURE,
  CANON_REJECT,
  CANON_RUNNING
} CanonReturn;

typedef enum
{
  METER = 0,
  MM,
  INCH
} CanonLengthUnit;

typedef enum
{
  RADIAN = 0,
  DEGREE
} CanonAngleUnit;

struct orientVect
{
  double i;
  double j;
  double k;

  //! @brief Orientation assignment function
  //!
  //! @param source An existing orientation vector that will be used to
  //!               populate this orientation vector instance
  //!
  orientVect & operator=(const orientVect &source)
  {
    if (this != &source)
    {
      i = source.i;
      j = source.j;
      k = source.k;
    }
    return *this;
  }

  //! @brief Orientation adjustment function:  Addition
  //!
  //! @param pB An existing orientation vector that will be added to the
  //!           current orientation vector
  //!
  orientVect operator+(const orientVect &pB)
  {
    orientVect pC;
    pC.i = i + pB.i;
    pC.j = j + pB.j;
    pC.k = k + pB.k;
    return pC;
  }

  //! @brief Orienatation adjustment function:  Subtraction
  //!
  //! @param pB An existing orientation vector that will be added to the
  //!           current orientation vector
  //!
  orientVect operator-(const orientVect &pB)
  {
    orientVect pC;
    pC.i = i - pB.i;
    pC.j = j - pB.j;
    pC.k = k - pB.k;
    return pC;
  }
};

struct robotPose
{
  double x;
  double y;
  double z;
  double xrot;
  double yrot;
  double zrot;

  //! @brief Pose assignment function
  //!
  //! @param source An existing pose that will be used to populate this pose
  //!               instance
  //!
  robotPose & operator=(const robotPose &source)
  {
    if (this != &source)
    {
      x = source.x;
      y = source.y;
      z = source.z;
      xrot = source.xrot;
      yrot = source.yrot;
      zrot = source.zrot;
    }
    return *this;
  }

  //! @brief Point adjustment function:  Addition
  //!
  //! @param pB An existing pose that will be added to the current pose
  //!
  robotPose operator+(const robotPose &pB)
  {
    robotPose pC;
    pC.x = x + pB.x;
    pC.y = y + pB.y;
    pC.z = z + pB.z;
    pC.xrot = xrot + pB.xrot;
    pC.yrot = yrot + pB.yrot;
    pC.zrot = zrot + pB.zrot;
    return pC;
  }

  //! @brief Point adjustment function:  Subtraction
  //!
  //! @param pB An existing pose that will be added to the current pose
  //!
  robotPose operator-(const robotPose &pB)
  {
    robotPose pC;
    pC.x = x - pB.x;
    pC.y = y - pB.y;
    pC.z = z - pB.z;
    pC.xrot = xrot - pB.xrot;
    pC.yrot = yrot - pB.yrot;
    pC.zrot = zrot - pB.zrot;
    return pC;
  }

  double distance(robotPose &pB)
  {
    return sqrt(((x-pB.x)*(x-pB.x))+((y-pB.y)*(y-pB.y))+((z-pB.z)*(z-pB.z)));
  }
};

#define CRPI_AXES_MAX 8

struct robotAxes
{
  //! @brief Set of axis values
  //!
  //! JAM TODO: Replace with dynamic allocation
  //!
  double axis[CRPI_AXES_MAX];

  //! @brief Size of axis array
  //!
  int axes;

  //! @brief Axes assignment function
  //!
  //! @param source An existing axes set that will be used to populate this set
  //!               instance
  //!
  robotAxes & operator=(const robotAxes &source)
  {
    if (this != &source)
    {
      for (int i = 0; i < CRPI_AXES_MAX; ++i)
      {
        axis[i] = source.axis[i];
      }
      axes = source.axes;
    }
    return *this;
  }

};


#define CRPI_IO_MAX 16

struct robotIO
{
  //! @brief Set of digital I/O values
  //!
  //! JAM TODO: Replace with dynamic memory allocation
  //!
  bool dio[CRPI_IO_MAX];

  //! @brief Set of analog I/O values
  //!
  //! JAM TODO: Replace with dynamic memory allocation
  //!
  double aio[CRPI_IO_MAX];

  //! @brief Number of DI/O values defined
  //!
  int ndio;

  //! @breif Number of AI/O values defined
  int naio;

  //! @brief Default constructor
  //!
  robotIO ()
  {
    for (int i = 0; i < CRPI_IO_MAX; ++i)
    {
      dio[i] = false;
      aio[i] = 0.0f;
    }
    ndio = naio = CRPI_IO_MAX;
  }

  //! @brief Assignment function
  //!
  //! @param source An existing IO structur that will be used to populate this
  //!               instance
  //!
  robotIO & operator=(const robotIO &source)
  {
    if (this != &source)
    {
      for (int i = 0; i < CRPI_IO_MAX; ++i)
      {
        dio[i] = source.dio[i];
        aio[i] = source.aio[i];
      }
      ndio = source.ndio;
      naio = source.naio;
    }
    return *this;
  }
};

struct keepalive
{
  ulapi_mutex_struct *handle;
  bool runThread;
  void *rob;
};

struct CRPIProgramParams
{
  int param;			/* FIXME -- what are these? */
};


#endif	/* CRPI_H_ */
