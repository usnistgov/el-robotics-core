/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "CRCLClasses.hh"

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

/* class CRCLProgramFile

*/

CRCLProgramFile::CRCLProgramFile() {}

CRCLProgramFile::CRCLProgramFile(
  XmlVersion * versionIn,
  XmlHeaderForCRCLProgram * headerIn,
  CRCLProgramType * CRCLProgramIn)
{
  version = versionIn;
  header = headerIn;
  CRCLProgram = CRCLProgramIn;
}

CRCLProgramFile::~CRCLProgramFile() {}

void CRCLProgramFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<CRCLProgram\n");
  header->printSelf(outFile);
  CRCLProgram->printSelf(outFile);
  fprintf(outFile, "</CRCLProgram>\n");
}

/*********************************************************************/

/* class AngleUnitType

*/

AngleUnitType::AngleUnitType() :
  XmlNMTOKEN() {}

AngleUnitType::AngleUnitType(
 char * valIn) :
  XmlNMTOKEN(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "degree") &&
           strcmp(val.c_str(), "radian"));
}

AngleUnitType::~AngleUnitType() {}

bool AngleUnitType::AngleUnitTypeIsBad()
{
  return (strcmp(val.c_str(), "degree") &&
          strcmp(val.c_str(), "radian"));
}

void AngleUnitType::printSelf(FILE * outFile)
{
  if (AngleUnitTypeIsBad())
    {
      fprintf(stderr, "bad AngleUnitType value, ");
      XmlNMTOKEN::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlNMTOKEN::printSelf(outFile);
}

/*********************************************************************/

/* class CRCLCommandType

*/

CRCLCommandType::CRCLCommandType() {}

CRCLCommandType::~CRCLCommandType() {}

void CRCLCommandType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
}

/*********************************************************************/

/* class CRCLProgramType

*/

CRCLProgramType::CRCLProgramType() {}

CRCLProgramType::CRCLProgramType(
 InitCanonType * InitCanonIn,
 CRCLProgramType_1001_Type * CRCLProgramType_1001In,
 EndCanonType * EndCanonIn)
{
  InitCanon = InitCanonIn;
  CRCLProgramType_1001 = CRCLProgramType_1001In;
  EndCanon = EndCanonIn;
}

CRCLProgramType::~CRCLProgramType() {}

void CRCLProgramType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<InitCanon");
  InitCanon->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</InitCanon>\n");
  CRCLProgramType_1001->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<EndCanon");
  EndCanon->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</EndCanon>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class CloseGripperType

*/

CloseGripperType::CloseGripperType() {}

CloseGripperType::~CloseGripperType() {}

void CloseGripperType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CloseGripperType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class CloseToolChangerType

*/

CloseToolChangerType::CloseToolChangerType() {}

CloseToolChangerType::~CloseToolChangerType() {}

void CloseToolChangerType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CloseToolChangerType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class DwellType

*/

DwellType::DwellType() {}

DwellType::DwellType(
 XmlDecimal * DwellTimeIn) :
  MiddleCommandType()
{
  DwellTime = DwellTimeIn;
  printTypp = false;
}

DwellType::~DwellType() {}

void DwellType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"DwellType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<DwellTime>");
  DwellTime->printSelf(outFile);
  fprintf(outFile, "</DwellTime>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class EndCanonType

*/

EndCanonType::EndCanonType() {}

EndCanonType::~EndCanonType() {}

void EndCanonType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EndCanonType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class InitCanonType

*/

InitCanonType::InitCanonType() {}

InitCanonType::~InitCanonType() {}

void InitCanonType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"InitCanonType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class LengthUnitType

*/

LengthUnitType::LengthUnitType() :
  XmlNMTOKEN() {}

LengthUnitType::LengthUnitType(
 char * valIn) :
  XmlNMTOKEN(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "meter") &&
           strcmp(val.c_str(), "millimeter") &&
           strcmp(val.c_str(), "inch"));
}

LengthUnitType::~LengthUnitType() {}

bool LengthUnitType::LengthUnitTypeIsBad()
{
  return (strcmp(val.c_str(), "meter") &&
          strcmp(val.c_str(), "millimeter") &&
          strcmp(val.c_str(), "inch"));
}

void LengthUnitType::printSelf(FILE * outFile)
{
  if (LengthUnitTypeIsBad())
    {
      fprintf(stderr, "bad LengthUnitType value, ");
      XmlNMTOKEN::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlNMTOKEN::printSelf(outFile);
}

/*********************************************************************/

/* class MessageType

*/

MessageType::MessageType() {}

MessageType::MessageType(
 XmlString * MessageIn) :
  MiddleCommandType()
{
  Message = MessageIn;
  printTypp = false;
}

MessageType::~MessageType() {}

void MessageType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MessageType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Message>");
  Message->printSelf(outFile);
  fprintf(outFile, "</Message>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class MiddleCommandType

*/

MiddleCommandType::MiddleCommandType() {}

MiddleCommandType::~MiddleCommandType() {}

void MiddleCommandType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MiddleCommandType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class MoveStraightToType

*/

MoveStraightToType::MoveStraightToType() {}

MoveStraightToType::MoveStraightToType(
 PoseType * EndPositionIn) :
  MiddleCommandType()
{
  EndPosition = EndPositionIn;
  printTypp = false;
}

MoveStraightToType::~MoveStraightToType() {}

void MoveStraightToType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MoveStraightToType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<EndPosition");
  EndPosition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</EndPosition>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class MoveThroughToType

*/

MoveThroughToType::MoveThroughToType() {}

MoveThroughToType::MoveThroughToType(
 std::list<PoseType *> * WaypointIn,
 XmlInteger * NumPositionsIn) :
  MiddleCommandType()
{
  Waypoint = WaypointIn;
  NumPositions = NumPositionsIn;
  printTypp = false;
}

MoveThroughToType::~MoveThroughToType() {}

void MoveThroughToType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MoveThroughToType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  {
    std::list<PoseType *>::iterator iter;
    for (iter = Waypoint->begin(); iter != Waypoint->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Waypoint");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Waypoint>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<NumPositions>");
  NumPositions->printSelf(outFile);
  fprintf(outFile, "</NumPositions>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class OpenGripperType

*/

OpenGripperType::OpenGripperType() {}

OpenGripperType::~OpenGripperType() {}

void OpenGripperType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OpenGripperType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class OpenToolChangerType

*/

OpenToolChangerType::OpenToolChangerType() {}

OpenToolChangerType::~OpenToolChangerType() {}

void OpenToolChangerType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OpenToolChangerType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class PointType

*/

PointType::PointType() {}

PointType::PointType(
 XmlDecimal * XIn,
 XmlDecimal * YIn,
 XmlDecimal * ZIn)
{
  X = XIn;
  Y = YIn;
  Z = ZIn;
}

PointType::~PointType() {}

void PointType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<X>");
  X->printSelf(outFile);
  fprintf(outFile, "</X>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Y>");
  Y->printSelf(outFile);
  fprintf(outFile, "</Y>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Z>");
  Z->printSelf(outFile);
  fprintf(outFile, "</Z>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class PoseType

*/

PoseType::PoseType() {}

PoseType::PoseType(
 PointType * PointIn,
 VectorType * ZAxisIn,
 VectorType * XAxisIn)
{
  Point = PointIn;
  ZAxis = ZAxisIn;
  XAxis = XAxisIn;
}

PoseType::~PoseType() {}

void PoseType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetAbsoluteAccelerationType

*/

SetAbsoluteAccelerationType::SetAbsoluteAccelerationType() {}

SetAbsoluteAccelerationType::SetAbsoluteAccelerationType(
 XmlDecimal * AccelerationIn) :
  MiddleCommandType()
{
  Acceleration = AccelerationIn;
  printTypp = false;
}

SetAbsoluteAccelerationType::~SetAbsoluteAccelerationType() {}

void SetAbsoluteAccelerationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetAbsoluteAccelerationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Acceleration>");
  Acceleration->printSelf(outFile);
  fprintf(outFile, "</Acceleration>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetAbsoluteSpeedType

*/

SetAbsoluteSpeedType::SetAbsoluteSpeedType() {}

SetAbsoluteSpeedType::SetAbsoluteSpeedType(
 XmlDecimal * SpeedIn) :
  MiddleCommandType()
{
  Speed = SpeedIn;
  printTypp = false;
}

SetAbsoluteSpeedType::~SetAbsoluteSpeedType() {}

void SetAbsoluteSpeedType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetAbsoluteSpeedType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Speed>");
  Speed->printSelf(outFile);
  fprintf(outFile, "</Speed>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetAngleUnitsType

*/

SetAngleUnitsType::SetAngleUnitsType() {}

SetAngleUnitsType::SetAngleUnitsType(
 AngleUnitType * UnitNameIn) :
  MiddleCommandType()
{
  UnitName = UnitNameIn;
  printTypp = false;
}

SetAngleUnitsType::~SetAngleUnitsType() {}

void SetAngleUnitsType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetAngleUnitsType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<UnitName>");
  UnitName->printSelf(outFile);
  fprintf(outFile, "</UnitName>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetEndAngleToleranceType

*/

SetEndAngleToleranceType::SetEndAngleToleranceType() {}

SetEndAngleToleranceType::SetEndAngleToleranceType(
 XmlDecimal * ToleranceIn) :
  MiddleCommandType()
{
  Tolerance = ToleranceIn;
  printTypp = false;
}

SetEndAngleToleranceType::~SetEndAngleToleranceType() {}

void SetEndAngleToleranceType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetEndAngleToleranceType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Tolerance>");
  Tolerance->printSelf(outFile);
  fprintf(outFile, "</Tolerance>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetEndPointToleranceType

*/

SetEndPointToleranceType::SetEndPointToleranceType() {}

SetEndPointToleranceType::SetEndPointToleranceType(
 XmlDecimal * ToleranceIn) :
  MiddleCommandType()
{
  Tolerance = ToleranceIn;
  printTypp = false;
}

SetEndPointToleranceType::~SetEndPointToleranceType() {}

void SetEndPointToleranceType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetEndPointToleranceType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Tolerance>");
  Tolerance->printSelf(outFile);
  fprintf(outFile, "</Tolerance>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetIntermediatePointToleranceType

*/

SetIntermediatePointToleranceType::SetIntermediatePointToleranceType() {}

SetIntermediatePointToleranceType::SetIntermediatePointToleranceType(
 XmlDecimal * ToleranceIn) :
  MiddleCommandType()
{
  Tolerance = ToleranceIn;
  printTypp = false;
}

SetIntermediatePointToleranceType::~SetIntermediatePointToleranceType() {}

void SetIntermediatePointToleranceType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetIntermediatePointToleranceType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Tolerance>");
  Tolerance->printSelf(outFile);
  fprintf(outFile, "</Tolerance>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetLengthUnitsType

*/

SetLengthUnitsType::SetLengthUnitsType() {}

SetLengthUnitsType::SetLengthUnitsType(
 LengthUnitType * UnitNameIn) :
  MiddleCommandType()
{
  UnitName = UnitNameIn;
  printTypp = false;
}

SetLengthUnitsType::~SetLengthUnitsType() {}

void SetLengthUnitsType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetLengthUnitsType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<UnitName>");
  UnitName->printSelf(outFile);
  fprintf(outFile, "</UnitName>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetRelativeAccelerationType

*/

SetRelativeAccelerationType::SetRelativeAccelerationType() {}

SetRelativeAccelerationType::SetRelativeAccelerationType(
 XmlDecimal * PercentIn) :
  MiddleCommandType()
{
  Percent = PercentIn;
  printTypp = false;
}

SetRelativeAccelerationType::~SetRelativeAccelerationType() {}

void SetRelativeAccelerationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetRelativeAccelerationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Percent>");
  Percent->printSelf(outFile);
  fprintf(outFile, "</Percent>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SetRelativeSpeedType

*/

SetRelativeSpeedType::SetRelativeSpeedType() {}

SetRelativeSpeedType::SetRelativeSpeedType(
 XmlDecimal * PercentIn) :
  MiddleCommandType()
{
  Percent = PercentIn;
  printTypp = false;
}

SetRelativeSpeedType::~SetRelativeSpeedType() {}

void SetRelativeSpeedType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SetRelativeSpeedType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Percent>");
  Percent->printSelf(outFile);
  fprintf(outFile, "</Percent>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class VectorType

*/

VectorType::VectorType() {}

VectorType::VectorType(
 XmlDecimal * IIn,
 XmlDecimal * JIn,
 XmlDecimal * KIn)
{
  I = IIn;
  J = JIn;
  K = KIn;
}

VectorType::~VectorType() {}

void VectorType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<I>");
  I->printSelf(outFile);
  fprintf(outFile, "</I>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<J>");
  J->printSelf(outFile);
  fprintf(outFile, "</J>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<K>");
  K->printSelf(outFile);
  fprintf(outFile, "</K>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class CRCLProgramType_1001_Type

*/

CRCLProgramType_1001_TypeChoicePair::CRCLProgramType_1001_TypeChoicePair() {}

CRCLProgramType_1001_TypeChoicePair::CRCLProgramType_1001_TypeChoicePair(
 whichOne CRCLProgramType_1001_TypeTypeIn,
 CRCLProgramType_1001_TypeVal CRCLProgramType_1001_TypeValueIn)
{
  CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeTypeIn;
  CRCLProgramType_1001_TypeValue = CRCLProgramType_1001_TypeValueIn;
}

CRCLProgramType_1001_TypeChoicePair::~CRCLProgramType_1001_TypeChoicePair() {}

void CRCLProgramType_1001_TypeChoicePair::printSelf(FILE * outFile)
{
  if (CRCLProgramType_1001_TypeType == CloseGripperE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<CloseGripper");
      CRCLProgramType_1001_TypeValue.CloseGripper->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</CloseGripper>\n");
    }
  else if (CRCLProgramType_1001_TypeType == CloseToolChangerE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<CloseToolChanger");
      CRCLProgramType_1001_TypeValue.CloseToolChanger->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</CloseToolChanger>\n");
    }
  else if (CRCLProgramType_1001_TypeType == DwellE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Dwell");
      CRCLProgramType_1001_TypeValue.Dwell->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</Dwell>\n");
    }
  else if (CRCLProgramType_1001_TypeType == MessageE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Message");
      CRCLProgramType_1001_TypeValue.Message->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</Message>\n");
    }
  else if (CRCLProgramType_1001_TypeType == MoveStraightToE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<MoveStraightTo");
      CRCLProgramType_1001_TypeValue.MoveStraightTo->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</MoveStraightTo>\n");
    }
  else if (CRCLProgramType_1001_TypeType == MoveThroughToE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<MoveThroughTo");
      CRCLProgramType_1001_TypeValue.MoveThroughTo->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</MoveThroughTo>\n");
    }
  else if (CRCLProgramType_1001_TypeType == OpenGripperE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OpenGripper");
      CRCLProgramType_1001_TypeValue.OpenGripper->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</OpenGripper>\n");
    }
  else if (CRCLProgramType_1001_TypeType == OpenToolChangerE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OpenToolChanger");
      CRCLProgramType_1001_TypeValue.OpenToolChanger->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</OpenToolChanger>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetAbsoluteAccelerationE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetAbsoluteAcceleration");
      CRCLProgramType_1001_TypeValue.SetAbsoluteAcceleration->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetAbsoluteAcceleration>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetAbsoluteSpeedE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetAbsoluteSpeed");
      CRCLProgramType_1001_TypeValue.SetAbsoluteSpeed->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetAbsoluteSpeed>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetAngleUnitsE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetAngleUnits");
      CRCLProgramType_1001_TypeValue.SetAngleUnits->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetAngleUnits>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetEndAngleToleranceE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetEndAngleTolerance");
      CRCLProgramType_1001_TypeValue.SetEndAngleTolerance->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetEndAngleTolerance>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetEndPointToleranceE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetEndPointTolerance");
      CRCLProgramType_1001_TypeValue.SetEndPointTolerance->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetEndPointTolerance>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetIntermediatePointToleranceE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetIntermediatePointTolerance");
      CRCLProgramType_1001_TypeValue.SetIntermediatePointTolerance->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetIntermediatePointTolerance>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetLengthUnitsE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetLengthUnits");
      CRCLProgramType_1001_TypeValue.SetLengthUnits->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetLengthUnits>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetRelativeAccelerationE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetRelativeAcceleration");
      CRCLProgramType_1001_TypeValue.SetRelativeAcceleration->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetRelativeAcceleration>\n");
    }
  else if (CRCLProgramType_1001_TypeType == SetRelativeSpeedE)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<SetRelativeSpeed");
      CRCLProgramType_1001_TypeValue.SetRelativeSpeed->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</SetRelativeSpeed>\n");
    }
}

CRCLProgramType_1001_Type::CRCLProgramType_1001_Type() {}

CRCLProgramType_1001_Type::CRCLProgramType_1001_Type(
  std::list<CRCLProgramType_1001_TypeChoicePair *> * pairsIn)
{
  pairs = pairsIn;
}

CRCLProgramType_1001_Type::~CRCLProgramType_1001_Type() {}

void CRCLProgramType_1001_Type::printSelf(FILE * outFile)
{
  std::list<CRCLProgramType_1001_TypeChoicePair *>::iterator iter;

  for (iter = pairs->begin(); iter != pairs->end(); iter++)
    {
      (*iter)->printSelf(outFile);
    }
}

/*********************************************************************/

XmlHeaderForCRCLProgram::XmlHeaderForCRCLProgram() {}

XmlHeaderForCRCLProgram::XmlHeaderForCRCLProgram(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForCRCLProgram::~XmlHeaderForCRCLProgram() {}

void XmlHeaderForCRCLProgram::printSelf(
  FILE * outFile)
{
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

