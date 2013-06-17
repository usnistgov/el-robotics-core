/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*!
  \file   viewerCanonicalMsg.cc
  \brief  copies the text of canonical robot commands into the commandString
          array of the KittingViewer.
  \author Tom Kramer
  \date   02/01/2013

*/

#include <stdio.h>
#include <string.h>
#include "canonicalMsg.hh"
#include "kittingViewer.hh"
#define snprintf sprintf_s
#define strncpy strncpy_s

/********************************************************************/

void CloseGripperMsg::process()
{
  strncpy(KittingViewer::commandString[1], "CloseGripper()", TEXTSIZE);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void CloseToolChangerMsg::process()
{
  strncpy(KittingViewer::commandString[1], "CloseToolChanger()", TEXTSIZE);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void DwellMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE, "Dwell(%f)", time);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void EndCanonMsg::process()
{
  strncpy(KittingViewer::commandString[1], "EndCanon()", TEXTSIZE);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void InitCanonMsg::process()
{
  strncpy(KittingViewer::commandString[1], "InitCanon()", TEXTSIZE);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void MessageMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE, "Message(\"%s\")",
	  message.c_str());
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void MoveStraightToMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "MoveStraightTo({{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}})",
	  pose->origin.x, pose->origin.y, pose->origin.z,
	  pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	  pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void MoveThroughToMsg::process()
{
  int n;
  int m;
  Pose * pose;

  pose = poses[0];
  m = snprintf(KittingViewer::commandString[1], TEXTSIZE,
	      "MoveThroughTo({{{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}}",
	      pose->origin.x, pose->origin.y, pose->origin.z,
	      pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	      pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
  for (n = 1; n < num; n++)
    {
      pose = poses[n];
      m = snprintf(KittingViewer::commandString[n+1], TEXTSIZE,
		  "  {{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}}",
		  pose->origin.x, pose->origin.y, pose->origin.z,
		  pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
		  pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
    }
  snprintf(KittingViewer::commandString[n] + m, TEXTSIZE, "}, %d)", num);
  KittingViewer::commandString[n+1][0] = 0;
}

/********************************************************************/

void MoveToMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "MoveTo({{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}})",
	  pose->origin.x, pose->origin.y, pose->origin.z,
	  pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	  pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void OpenGripperMsg::process()
{
  strncpy(KittingViewer::commandString[1], "OpenGripper()", TEXTSIZE);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void OpenToolChangerMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE, "OpenToolChanger()");
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetAbsoluteAccelerationMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetAbsoluteAcceleration(%f)", acceleration);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetAbsoluteSpeedMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetAbsoluteSpeed(%f)", speed);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetAngleUnitsMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetAngleUnits(\"%s\")", unitName.c_str());
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetEndAngleToleranceMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetEndAngleTolerance(%f)", tolerance);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetEndPointToleranceMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetEndPointTolerance(%f)", tolerance);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetIntermediatePointToleranceMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetIntermediatePointTolerance(%f)", tolerance);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetLengthUnitsMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetLengthUnits(\"%s\")", unitName.c_str());
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetRelativeAccelerationMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetRelativeAcceleration(%f)", percent);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void SetRelativeSpeedMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	  "SetRelativeSpeed(%f)", percent);
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/

void UnreadableMsg::process()
{
  snprintf(KittingViewer::commandString[1], TEXTSIZE,
	   "%s", commandString.c_str());
  KittingViewer::commandString[2][0] = 0;
}

/********************************************************************/
