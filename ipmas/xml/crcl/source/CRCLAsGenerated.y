%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#ifdef OWL
#include "owlCRCLClasses.hh"
#else
#include "CRCLClasses.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

CRCLProgramFile * CRCLProgramTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);

%}

%union {
  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForCRCLProgram *           XmlHeaderForCRCLProgramVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlInteger *                        XmlIntegerVal;
  XmlString *                         XmlStringVal;

  CRCLProgramFile *                   CRCLProgramFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  CRCLProgramType *                   CRCLProgramTypeVal;
  CRCLProgramType_1001_TypeChoicePair * CRCLProgramType_1001_TypeChoicePairVal;
  CRCLProgramType_1001_Type *         CRCLProgramType_1001_TypeVal;
  CloseGripperType *                  CloseGripperTypeVal;
  CloseToolChangerType *              CloseToolChangerTypeVal;
  DwellType *                         DwellTypeVal;
  EndCanonType *                      EndCanonTypeVal;
  InitCanonType *                     InitCanonTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  std::list<CRCLProgramType_1001_TypeChoicePair *> * ListCRCLProgramType_1001_TypeChoicePairVal;
  std::list<PoseType *> *             ListPoseTypeVal;
  MessageType *                       MessageTypeVal;
  MoveStraightToType *                MoveStraightToTypeVal;
  MoveThroughToType *                 MoveThroughToTypeVal;
  OpenGripperType *                   OpenGripperTypeVal;
  OpenToolChangerType *               OpenToolChangerTypeVal;
  PointType *                         PointTypeVal;
  PoseType *                          PoseTypeVal;
  SetAbsoluteAccelerationType *       SetAbsoluteAccelerationTypeVal;
  SetAbsoluteSpeedType *              SetAbsoluteSpeedTypeVal;
  SetAngleUnitsType *                 SetAngleUnitsTypeVal;
  SetEndAngleToleranceType *          SetEndAngleToleranceTypeVal;
  SetEndPointToleranceType *          SetEndPointToleranceTypeVal;
  SetIntermediatePointToleranceType * SetIntermediatePointToleranceTypeVal;
  SetLengthUnitsType *                SetLengthUnitsTypeVal;
  SetRelativeAccelerationType *       SetRelativeAccelerationTypeVal;
  SetRelativeSpeedType *              SetRelativeSpeedTypeVal;
  VectorType *                        VectorTypeVal;
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForCRCLProgramVal>    y_XmlHeaderForCRCLProgram
%type <XmlVersionVal>                 y_XmlVersion
%type <CRCLProgramFileVal>            y_CRCLProgramFile
%type <XmlDecimalVal>                 y_XmlDecimal
%type <XmlIntegerVal>                 y_XmlInteger
%type <XmlStringVal>                  y_XmlString

%type <XmlDecimalVal>                 y_Acceleration_XmlDecimal
%type <CRCLProgramTypeVal>            y_CRCLProgramType
%type <CRCLProgramType_1001_TypeVal>  y_CRCLProgramType_1001_CRCLProgr1002
%type <CRCLProgramType_1001_TypeVal>  y_CRCLProgramType_1001_Type
%type <CRCLProgramType_1001_TypeChoicePairVal> y_CRCLProgramType_1001_TypeChoicePair
%type <CloseGripperTypeVal>           y_CloseGripperType
%type <CloseGripperTypeVal>           y_CloseGripper_CloseGripperType
%type <CloseToolChangerTypeVal>       y_CloseToolChangerType
%type <CloseToolChangerTypeVal>       y_CloseToolChanger_CloseToolChan1003
%type <XmlDecimalVal>                 y_DwellTime_XmlDecimal
%type <DwellTypeVal>                  y_DwellType
%type <DwellTypeVal>                  y_Dwell_DwellType
%type <EndCanonTypeVal>               y_EndCanonType
%type <EndCanonTypeVal>               y_EndCanon_EndCanonType
%type <PoseTypeVal>                   y_EndPosition_PoseType
%type <XmlDecimalVal>                 y_I_XmlDecimal
%type <InitCanonTypeVal>              y_InitCanonType
%type <InitCanonTypeVal>              y_InitCanon_InitCanonType
%type <XmlDecimalVal>                 y_J_XmlDecimal
%type <XmlDecimalVal>                 y_K_XmlDecimal
%type <ListCRCLProgramType_1001_TypeChoicePairVal> y_ListCRCLProgramType_1001_TypeChoicePair
%type <ListPoseTypeVal>               y_ListWaypoint_PoseType_1_u
%type <MessageTypeVal>                y_MessageType
%type <MessageTypeVal>                y_Message_MessageType
%type <XmlStringVal>                  y_Message_XmlString
%type <MoveStraightToTypeVal>         y_MoveStraightToType
%type <MoveStraightToTypeVal>         y_MoveStraightTo_MoveStraightToType
%type <MoveThroughToTypeVal>          y_MoveThroughToType
%type <MoveThroughToTypeVal>          y_MoveThroughTo_MoveThroughToType
%type <XmlIntegerVal>                 y_NumPositions_XmlInteger
%type <OpenGripperTypeVal>            y_OpenGripperType
%type <OpenGripperTypeVal>            y_OpenGripper_OpenGripperType
%type <OpenToolChangerTypeVal>        y_OpenToolChangerType
%type <OpenToolChangerTypeVal>        y_OpenToolChanger_OpenToolChangerType
%type <XmlDecimalVal>                 y_Percent_XmlDecimal
%type <PointTypeVal>                  y_PointType
%type <PointTypeVal>                  y_Point_PointType
%type <PoseTypeVal>                   y_PoseType
%type <SetAbsoluteAccelerationTypeVal> y_SetAbsoluteAccelerationType
%type <SetAbsoluteAccelerationTypeVal> y_SetAbsoluteAcceleration_SetAbs1004
%type <SetAbsoluteSpeedTypeVal>       y_SetAbsoluteSpeedType
%type <SetAbsoluteSpeedTypeVal>       y_SetAbsoluteSpeed_SetAbsoluteSp1005
%type <SetAngleUnitsTypeVal>          y_SetAngleUnitsType
%type <SetAngleUnitsTypeVal>          y_SetAngleUnits_SetAngleUnitsType
%type <SetEndAngleToleranceTypeVal>   y_SetEndAngleToleranceType
%type <SetEndAngleToleranceTypeVal>   y_SetEndAngleTolerance_SetEndAng1006
%type <SetEndPointToleranceTypeVal>   y_SetEndPointToleranceType
%type <SetEndPointToleranceTypeVal>   y_SetEndPointTolerance_SetEndPoi1007
%type <SetIntermediatePointToleranceTypeVal> y_SetIntermediatePointToleranceType
%type <SetIntermediatePointToleranceTypeVal> y_SetIntermediatePointTolerance_1008
%type <SetLengthUnitsTypeVal>         y_SetLengthUnitsType
%type <SetLengthUnitsTypeVal>         y_SetLengthUnits_SetLengthUnitsType
%type <SetRelativeAccelerationTypeVal> y_SetRelativeAccelerationType
%type <SetRelativeAccelerationTypeVal> y_SetRelativeAcceleration_SetRel1009
%type <SetRelativeSpeedTypeVal>       y_SetRelativeSpeedType
%type <SetRelativeSpeedTypeVal>       y_SetRelativeSpeed_SetRelativeSp1010
%type <XmlDecimalVal>                 y_Speed_XmlDecimal
%type <XmlDecimalVal>                 y_Tolerance_XmlDecimal
%type <AngleUnitTypeVal>              y_UnitName_AngleUnitType
%type <LengthUnitTypeVal>             y_UnitName_LengthUnitType
%type <VectorTypeVal>                 y_VectorType
%type <PoseTypeVal>                   y_Waypoint_PoseType_1_u
%type <VectorTypeVal>                 y_XAxis_VectorType
%type <XmlDecimalVal>                 y_X_XmlDecimal
%type <XmlDecimalVal>                 y_Y_XmlDecimal
%type <VectorTypeVal>                 y_ZAxis_VectorType
%type <XmlDecimalVal>                 y_Z_XmlDecimal

%token <iVal> BAD
%token <sVal> DATASTRING
%token <iVal> ENCODING
%token <iVal> ENDITEM
%token <iVal> ENDVERSION
%token <sVal> SCHEMALOCATION
%token <iVal> STARTVERSION
%token <sVal> TERMINALSTRING
%token <iVal> XMLNSPREFIX
%token <iVal> XMLNSTARGET
%token <iVal> XMLVERSION

%token <iVal> ACCELERATIONEND
%token <iVal> ACCELERATIONSTART
%token <iVal> CRCLPROGRAMEND
%token <iVal> CRCLPROGRAMSTART
%token <iVal> CLOSEGRIPPEREND
%token <iVal> CLOSEGRIPPERSTART
%token <iVal> CLOSETOOLCHANGEREND
%token <iVal> CLOSETOOLCHANGERSTART
%token <iVal> DWELLTIMEEND
%token <iVal> DWELLTIMESTART
%token <iVal> DWELLEND
%token <iVal> DWELLSTART
%token <iVal> ENDCANONEND
%token <iVal> ENDCANONSTART
%token <iVal> ENDPOSITIONEND
%token <iVal> ENDPOSITIONSTART
%token <iVal> IEND
%token <iVal> ISTART
%token <iVal> INITCANONEND
%token <iVal> INITCANONSTART
%token <iVal> JEND
%token <iVal> JSTART
%token <iVal> KEND
%token <iVal> KSTART
%token <iVal> MESSAGEEND
%token <iVal> MESSAGESTART
%token <iVal> MOVESTRAIGHTTOEND
%token <iVal> MOVESTRAIGHTTOSTART
%token <iVal> MOVETHROUGHTOEND
%token <iVal> MOVETHROUGHTOSTART
%token <iVal> NUMPOSITIONSEND
%token <iVal> NUMPOSITIONSSTART
%token <iVal> OPENGRIPPEREND
%token <iVal> OPENGRIPPERSTART
%token <iVal> OPENTOOLCHANGEREND
%token <iVal> OPENTOOLCHANGERSTART
%token <iVal> PERCENTEND
%token <iVal> PERCENTSTART
%token <iVal> POINTEND
%token <iVal> POINTSTART
%token <iVal> SETABSOLUTEACCELERATIONEND
%token <iVal> SETABSOLUTEACCELERATIONSTART
%token <iVal> SETABSOLUTESPEEDEND
%token <iVal> SETABSOLUTESPEEDSTART
%token <iVal> SETANGLEUNITSEND
%token <iVal> SETANGLEUNITSSTART
%token <iVal> SETENDANGLETOLERANCEEND
%token <iVal> SETENDANGLETOLERANCESTART
%token <iVal> SETENDPOINTTOLERANCEEND
%token <iVal> SETENDPOINTTOLERANCESTART
%token <iVal> SETINTERMEDIATEPOINTTOLERANCEEND
%token <iVal> SETINTERMEDIATEPOINTTOLERANCESTART
%token <iVal> SETLENGTHUNITSEND
%token <iVal> SETLENGTHUNITSSTART
%token <iVal> SETRELATIVEACCELERATIONEND
%token <iVal> SETRELATIVEACCELERATIONSTART
%token <iVal> SETRELATIVESPEEDEND
%token <iVal> SETRELATIVESPEEDSTART
%token <iVal> SPEEDEND
%token <iVal> SPEEDSTART
%token <iVal> TOLERANCEEND
%token <iVal> TOLERANCESTART
%token <iVal> UNITNAMEEND
%token <iVal> UNITNAMESTART
%token <iVal> WAYPOINTEND
%token <iVal> WAYPOINTSTART
%token <iVal> XAXISEND
%token <iVal> XAXISSTART
%token <iVal> XEND
%token <iVal> XSTART
%token <iVal> YEND
%token <iVal> YSTART
%token <iVal> ZAXISEND
%token <iVal> ZAXISSTART
%token <iVal> ZEND
%token <iVal> ZSTART


%token <iVal> CLOSEGRIPPERTYPEDECL
%token <iVal> CLOSETOOLCHANGERTYPEDECL
%token <iVal> DWELLTYPEDECL
%token <iVal> ENDCANONTYPEDECL
%token <iVal> INITCANONTYPEDECL
%token <iVal> MESSAGETYPEDECL
%token <iVal> MIDDLECOMMANDTYPEDECL
%token <iVal> MOVESTRAIGHTTOTYPEDECL
%token <iVal> MOVETHROUGHTOTYPEDECL
%token <iVal> OPENGRIPPERTYPEDECL
%token <iVal> OPENTOOLCHANGERTYPEDECL
%token <iVal> SETABSOLUTEACCELERATIONTYPEDECL
%token <iVal> SETABSOLUTESPEEDTYPEDECL
%token <iVal> SETANGLEUNITSTYPEDECL
%token <iVal> SETENDANGLETOLERANCETYPEDECL
%token <iVal> SETENDPOINTTOLERANCETYPEDECL
%token <iVal> SETINTERMEDIATEPOINTTOLERANCETYPEDECL
%token <iVal> SETLENGTHUNITSTYPEDECL
%token <iVal> SETRELATIVEACCELERATIONTYPEDECL
%token <iVal> SETRELATIVESPEEDTYPEDECL

%%

y_CRCLProgramFile :
	  y_XmlVersion CRCLPROGRAMSTART y_XmlHeaderForCRCLProgram
	  y_CRCLProgramType CRCLPROGRAMEND
	  {$$ = new CRCLProgramFile($1, $3, $4);
	   CRCLProgramTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForCRCLProgram:
	  XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForCRCLProgram($2);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2, false);
	  }
	;

y_XmlDecimal :
	  DATASTRING
	  {$$ = new XmlDecimal($1);
	   if ($$->bad)
	     yyerror("bad XmlDecimal");
	  }
	;

y_XmlInteger :
	  DATASTRING
	  {$$ = new XmlInteger($1);
	   if ($$->bad)
	     yyerror("bad XmlInteger");
	  }
	;

y_XmlString :
	  DATASTRING
	  {$$ = new XmlString($1);
	   if ($$->bad)
	     yyerror("bad XmlString");
	  }
	;

y_XmlVersion :
	  STARTVERSION XMLVERSION TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(false);
	   if (strcmp($3, "1.0"))
	     yyerror("version number must be 1.0");
	  }
	| STARTVERSION XMLVERSION TERMINALSTRING
	  ENCODING TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(true);
	   if (strcmp($3, "1.0"))
	     yyerror("version number must be 1.0");
	   else if ((strcmp($5, "UTF-8")) && (strcmp($5, "utf-8")))
	     yyerror("encoding must be UTF-8");
	  }
	;

y_Acceleration_XmlDecimal :
	  ACCELERATIONSTART ENDITEM {yyReadData = 1;} y_XmlDecimal
	  ACCELERATIONEND
	  {$$ = $4;}
	;

y_CRCLProgramType :
	  ENDITEM y_InitCanon_InitCanonType
	  y_CRCLProgramType_1001_CRCLProgr1002 y_EndCanon_EndCanonType
	  {$$ = new CRCLProgramType($2, $3, $4);}
	;

y_CRCLProgramType_1001_CRCLProgr1002 :
	  y_CRCLProgramType_1001_Type
	  {$$ = $1;}
	;

y_CRCLProgramType_1001_Type :
	  y_ListCRCLProgramType_1001_TypeChoicePair
	  {$$ = new CRCLProgramType_1001_Type($1);
	   if ($1->size() < 1)
	     yyerror("at least 1 choice is required");
	  }
	;

y_CRCLProgramType_1001_TypeChoicePair :
	  y_CloseGripper_CloseGripperType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::CloseGripperE;
	   $$->CRCLProgramType_1001_TypeValue.CloseGripper = $1;
	  }
	| y_CloseToolChanger_CloseToolChan1003
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::CloseToolChangerE;
	   $$->CRCLProgramType_1001_TypeValue.CloseToolChanger = $1;
	  }
	| y_Dwell_DwellType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::DwellE;
	   $$->CRCLProgramType_1001_TypeValue.Dwell = $1;
	  }
	| y_Message_MessageType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MessageE;
	   $$->CRCLProgramType_1001_TypeValue.Message = $1;
	  }
	| y_MoveStraightTo_MoveStraightToType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MoveStraightToE;
	   $$->CRCLProgramType_1001_TypeValue.MoveStraightTo = $1;
	  }
	| y_MoveThroughTo_MoveThroughToType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MoveThroughToE;
	   $$->CRCLProgramType_1001_TypeValue.MoveThroughTo = $1;
	  }
	| y_OpenGripper_OpenGripperType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenGripperE;
	   $$->CRCLProgramType_1001_TypeValue.OpenGripper = $1;
	  }
	| y_OpenToolChanger_OpenToolChangerType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenToolChangerE;
	   $$->CRCLProgramType_1001_TypeValue.OpenToolChanger = $1;
	  }
	| y_SetAbsoluteAcceleration_SetAbs1004
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteAccelerationE;
	   $$->CRCLProgramType_1001_TypeValue.SetAbsoluteAcceleration = $1;
	  }
	| y_SetAbsoluteSpeed_SetAbsoluteSp1005
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteSpeedE;
	   $$->CRCLProgramType_1001_TypeValue.SetAbsoluteSpeed = $1;
	  }
	| y_SetAngleUnits_SetAngleUnitsType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAngleUnitsE;
	   $$->CRCLProgramType_1001_TypeValue.SetAngleUnits = $1;
	  }
	| y_SetEndAngleTolerance_SetEndAng1006
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndAngleToleranceE;
	   $$->CRCLProgramType_1001_TypeValue.SetEndAngleTolerance = $1;
	  }
	| y_SetEndPointTolerance_SetEndPoi1007
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndPointToleranceE;
	   $$->CRCLProgramType_1001_TypeValue.SetEndPointTolerance = $1;
	  }
	| y_SetIntermediatePointTolerance_1008
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetIntermediatePointToleranceE;
	   $$->CRCLProgramType_1001_TypeValue.SetIntermediatePointTolerance = $1;
	  }
	| y_SetLengthUnits_SetLengthUnitsType
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetLengthUnitsE;
	   $$->CRCLProgramType_1001_TypeValue.SetLengthUnits = $1;
	  }
	| y_SetRelativeAcceleration_SetRel1009
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeAccelerationE;
	   $$->CRCLProgramType_1001_TypeValue.SetRelativeAcceleration = $1;
	  }
	| y_SetRelativeSpeed_SetRelativeSp1010
	  {$$ = new CRCLProgramType_1001_TypeChoicePair();
	   $$->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeSpeedE;
	   $$->CRCLProgramType_1001_TypeValue.SetRelativeSpeed = $1;
	  }
	;

y_CloseGripperType :
	   ENDITEM
	  {$$ = new CloseGripperType();}
	;

y_CloseGripper_CloseGripperType :
	  CLOSEGRIPPERSTART y_CloseGripperType CLOSEGRIPPEREND
	  {$$ = $2;}
	;

y_CloseToolChangerType :
	   ENDITEM
	  {$$ = new CloseToolChangerType();}
	;

y_CloseToolChanger_CloseToolChan1003 :
	  CLOSETOOLCHANGERSTART y_CloseToolChangerType CLOSETOOLCHANGEREND
	  {$$ = $2;}
	;

y_DwellTime_XmlDecimal :
	  DWELLTIMESTART ENDITEM {yyReadData = 1;} y_XmlDecimal
	  DWELLTIMEEND
	  {$$ = $4;}
	;

y_DwellType :
	   ENDITEM y_DwellTime_XmlDecimal
	  {$$ = new DwellType($2);}
	;

y_Dwell_DwellType :
	  DWELLSTART y_DwellType DWELLEND
	  {$$ = $2;}
	;

y_EndCanonType :
	   ENDITEM
	  {$$ = new EndCanonType();}
	;

y_EndCanon_EndCanonType :
	  ENDCANONSTART y_EndCanonType ENDCANONEND
	  {$$ = $2;}
	;

y_EndPosition_PoseType :
	  ENDPOSITIONSTART y_PoseType ENDPOSITIONEND
	  {$$ = $2;}
	;

y_I_XmlDecimal :
	  ISTART ENDITEM {yyReadData = 1;} y_XmlDecimal IEND
	  {$$ = $4;}
	;

y_InitCanonType :
	   ENDITEM
	  {$$ = new InitCanonType();}
	;

y_InitCanon_InitCanonType :
	  INITCANONSTART y_InitCanonType INITCANONEND
	  {$$ = $2;}
	;

y_J_XmlDecimal :
	  JSTART ENDITEM {yyReadData = 1;} y_XmlDecimal JEND
	  {$$ = $4;}
	;

y_K_XmlDecimal :
	  KSTART ENDITEM {yyReadData = 1;} y_XmlDecimal KEND
	  {$$ = $4;}
	;

y_ListCRCLProgramType_1001_TypeChoicePair :
	  y_CRCLProgramType_1001_TypeChoicePair
	  {$$ = new std::list<CRCLProgramType_1001_TypeChoicePair *>;
	   $$->push_back($1);
	  }
	| y_ListCRCLProgramType_1001_TypeChoicePair
	  y_CRCLProgramType_1001_TypeChoicePair
	  {$$ = $1;
	   $$->push_back($2);
	  }
	;

y_ListWaypoint_PoseType_1_u :
	  y_ListWaypoint_PoseType_1_u y_Waypoint_PoseType_1_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Waypoint_PoseType_1_u
	  {$$ = new std::list<PoseType *>;
	   $$->push_back($1);}
	;

y_MessageType :
	   ENDITEM y_Message_XmlString
	  {$$ = new MessageType($2);}
	;

y_Message_MessageType :
	  MESSAGESTART y_MessageType MESSAGEEND
	  {$$ = $2;}
	;

y_Message_XmlString :
	  MESSAGESTART ENDITEM {yyReadData = 1;} y_XmlString MESSAGEEND
	  {$$ = $4;}
	;

y_MoveStraightToType :
	   ENDITEM y_EndPosition_PoseType
	  {$$ = new MoveStraightToType($2);}
	;

y_MoveStraightTo_MoveStraightToType :
	  MOVESTRAIGHTTOSTART y_MoveStraightToType MOVESTRAIGHTTOEND
	  {$$ = $2;}
	;

y_MoveThroughToType :
	   ENDITEM y_ListWaypoint_PoseType_1_u y_NumPositions_XmlInteger
	  {$$ = new MoveThroughToType($2, $3);}
	;

y_MoveThroughTo_MoveThroughToType :
	  MOVETHROUGHTOSTART y_MoveThroughToType MOVETHROUGHTOEND
	  {$$ = $2;}
	;

y_NumPositions_XmlInteger :
	  NUMPOSITIONSSTART ENDITEM {yyReadData = 1;} y_XmlInteger
	  NUMPOSITIONSEND
	  {$$ = $4;}
	;

y_OpenGripperType :
	   ENDITEM
	  {$$ = new OpenGripperType();}
	;

y_OpenGripper_OpenGripperType :
	  OPENGRIPPERSTART y_OpenGripperType OPENGRIPPEREND
	  {$$ = $2;}
	;

y_OpenToolChangerType :
	   ENDITEM
	  {$$ = new OpenToolChangerType();}
	;

y_OpenToolChanger_OpenToolChangerType :
	  OPENTOOLCHANGERSTART y_OpenToolChangerType OPENTOOLCHANGEREND
	  {$$ = $2;}
	;

y_Percent_XmlDecimal :
	  PERCENTSTART ENDITEM {yyReadData = 1;} y_XmlDecimal PERCENTEND
	  {$$ = $4;}
	;

y_PointType :
	  ENDITEM y_X_XmlDecimal y_Y_XmlDecimal y_Z_XmlDecimal
	  {$$ = new PointType($2, $3, $4);}
	;

y_Point_PointType :
	  POINTSTART y_PointType POINTEND
	  {$$ = $2;}
	;

y_PoseType :
	  ENDITEM y_Point_PointType y_ZAxis_VectorType y_XAxis_VectorType
	  {$$ = new PoseType($2, $3, $4);}
	;

y_SetAbsoluteAccelerationType :
	   ENDITEM y_Acceleration_XmlDecimal
	  {$$ = new SetAbsoluteAccelerationType($2);}
	;

y_SetAbsoluteAcceleration_SetAbs1004 :
	  SETABSOLUTEACCELERATIONSTART y_SetAbsoluteAccelerationType
	  SETABSOLUTEACCELERATIONEND
	  {$$ = $2;}
	;

y_SetAbsoluteSpeedType :
	   ENDITEM y_Speed_XmlDecimal
	  {$$ = new SetAbsoluteSpeedType($2);}
	;

y_SetAbsoluteSpeed_SetAbsoluteSp1005 :
	  SETABSOLUTESPEEDSTART y_SetAbsoluteSpeedType SETABSOLUTESPEEDEND
	  {$$ = $2;}
	;

y_SetAngleUnitsType :
	   ENDITEM y_UnitName_AngleUnitType
	  {$$ = new SetAngleUnitsType($2);}
	;

y_SetAngleUnits_SetAngleUnitsType :
	  SETANGLEUNITSSTART y_SetAngleUnitsType SETANGLEUNITSEND
	  {$$ = $2;}
	;

y_SetEndAngleToleranceType :
	   ENDITEM y_Tolerance_XmlDecimal
	  {$$ = new SetEndAngleToleranceType($2);}
	;

y_SetEndAngleTolerance_SetEndAng1006 :
	  SETENDANGLETOLERANCESTART y_SetEndAngleToleranceType
	  SETENDANGLETOLERANCEEND
	  {$$ = $2;}
	;

y_SetEndPointToleranceType :
	   ENDITEM y_Tolerance_XmlDecimal
	  {$$ = new SetEndPointToleranceType($2);}
	;

y_SetEndPointTolerance_SetEndPoi1007 :
	  SETENDPOINTTOLERANCESTART y_SetEndPointToleranceType
	  SETENDPOINTTOLERANCEEND
	  {$$ = $2;}
	;

y_SetIntermediatePointToleranceType :
	   ENDITEM y_Tolerance_XmlDecimal
	  {$$ = new SetIntermediatePointToleranceType($2);}
	;

y_SetIntermediatePointTolerance_1008 :
	  SETINTERMEDIATEPOINTTOLERANCESTART
	  y_SetIntermediatePointToleranceType
	  SETINTERMEDIATEPOINTTOLERANCEEND
	  {$$ = $2;}
	;

y_SetLengthUnitsType :
	   ENDITEM y_UnitName_LengthUnitType
	  {$$ = new SetLengthUnitsType($2);}
	;

y_SetLengthUnits_SetLengthUnitsType :
	  SETLENGTHUNITSSTART y_SetLengthUnitsType SETLENGTHUNITSEND
	  {$$ = $2;}
	;

y_SetRelativeAccelerationType :
	   ENDITEM y_Percent_XmlDecimal
	  {$$ = new SetRelativeAccelerationType($2);}
	;

y_SetRelativeAcceleration_SetRel1009 :
	  SETRELATIVEACCELERATIONSTART y_SetRelativeAccelerationType
	  SETRELATIVEACCELERATIONEND
	  {$$ = $2;}
	;

y_SetRelativeSpeedType :
	   ENDITEM y_Percent_XmlDecimal
	  {$$ = new SetRelativeSpeedType($2);}
	;

y_SetRelativeSpeed_SetRelativeSp1010 :
	  SETRELATIVESPEEDSTART y_SetRelativeSpeedType SETRELATIVESPEEDEND
	  {$$ = $2;}
	;

y_Speed_XmlDecimal :
	  SPEEDSTART ENDITEM {yyReadData = 1;} y_XmlDecimal SPEEDEND
	  {$$ = $4;}
	;

y_Tolerance_XmlDecimal :
	  TOLERANCESTART ENDITEM {yyReadData = 1;} y_XmlDecimal
	  TOLERANCEEND
	  {$$ = $4;}
	;

y_UnitName_AngleUnitType :
	  UNITNAMESTART ENDITEM {yyReadData = 1;} DATASTRING UNITNAMEEND
	  {$$ = new AngleUnitType($4);
	   if ($$->bad)
	     yyerror("bad UnitName value");
	  }
	;

y_UnitName_LengthUnitType :
	  UNITNAMESTART ENDITEM {yyReadData = 1;} DATASTRING UNITNAMEEND
	  {$$ = new LengthUnitType($4);
	   if ($$->bad)
	     yyerror("bad UnitName value");
	  }
	;

y_VectorType :
	  ENDITEM y_I_XmlDecimal y_J_XmlDecimal y_K_XmlDecimal
	  {$$ = new VectorType($2, $3, $4);}
	;

y_Waypoint_PoseType_1_u :
	  WAYPOINTSTART y_PoseType WAYPOINTEND
	  {$$ = $2;}
	;

y_XAxis_VectorType :
	  XAXISSTART y_VectorType XAXISEND
	  {$$ = $2;}
	;

y_X_XmlDecimal :
	  XSTART ENDITEM {yyReadData = 1;} y_XmlDecimal XEND
	  {$$ = $4;}
	;

y_Y_XmlDecimal :
	  YSTART ENDITEM {yyReadData = 1;} y_XmlDecimal YEND
	  {$$ = $4;}
	;

y_ZAxis_VectorType :
	  ZAXISSTART y_VectorType ZAXISEND
	  {$$ = $2;}
	;

y_Z_XmlDecimal :
	  ZSTART ENDITEM {yyReadData = 1;} y_XmlDecimal ZEND
	  {$$ = $4;}
	;

%%

/*********************************************************************/

/* yyerror

Returned Value: int (0)

Called By: yyparse

This prints whatever string the parser provides.

*/

int yyerror(      /* ARGUMENTS       */
 const char * s)  /* string to print */
{
  fflush(stdout);
  fprintf(stderr, "\n%s\n", s);
  exit(1);
  return 0;
}

/*********************************************************************/
