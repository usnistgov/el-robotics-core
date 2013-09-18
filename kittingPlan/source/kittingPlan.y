%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#include "kittingPlanClasses.hh"   // for kittingPlan classes

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingPlanFile * KittingPlanTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);

%}

%union {
  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingPlan *           XmlHeaderForKittingPlanVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDateTime *                       XmlDateTimeVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlID *                             XmlIDVal;
  XmlIDREF *                          XmlIDREFVal;
  XmlNMTOKEN *                        XmlNMTOKENVal;
  XmlPositiveInteger *                XmlPositiveIntegerVal;
  XmlString *                         XmlStringVal;
  XmlToken *                          XmlTokenVal;

  KittingPlanFile *                   KittingPlanFileVal;

  ActionBaseType *                    ActionBaseTypeVal;
  ActionGroupBaseType *               ActionGroupBaseTypeVal;
  AndType *                           AndTypeVal;
  ArithmeticComparisonBooleanExpressionType * ArithmeticComparisonBooleanExpressionTypeVal;
  ArithmeticExpressionType *          ArithmeticExpressionTypeVal;
  AttachEndEffectorType *             AttachEndEffectorTypeVal;
  BinaryArithmeticExpressionType *    BinaryArithmeticExpressionTypeVal;
  BinaryBooleanExpressionType *       BinaryBooleanExpressionTypeVal;
  BooleanConstantType *               BooleanConstantTypeVal;
  BooleanExpressionType *             BooleanExpressionTypeVal;
  CreateKitType *                     CreateKitTypeVal;
  DecimalType *                       DecimalTypeVal;
  DetachEndEffectorType *             DetachEndEffectorTypeVal;
  DivType *                           DivTypeVal;
  ElseType *                          ElseTypeVal;
  EqualType *                         EqualTypeVal;
  FalseType *                         FalseTypeVal;
  GreaterOrEqualType *                GreaterOrEqualTypeVal;
  GreaterType *                       GreaterTypeVal;
  IfActionGroupType *                 IfActionGroupTypeVal;
  KittingPlanType *                   KittingPlanTypeVal;
  LessOrEqualType *                   LessOrEqualTypeVal;
  LessType *                          LessTypeVal;
  LocatePartType *                    LocatePartTypeVal;
  MinusType *                         MinusTypeVal;
  ModType *                           ModTypeVal;
  std::list<XmlNMTOKEN *> *           NMTOKENListVal;
  NegateType *                        NegateTypeVal;
  NotEqualType *                      NotEqualTypeVal;
  NotType *                           NotTypeVal;
  std::list<NumberedPlanElementType *> * NumberedPlanElementTypeListVal;
  NumberedPlanElementType *           NumberedPlanElementTypeVal;
  OneOfActionGroupType *              OneOfActionGroupTypeVal;
  OrType *                            OrTypeVal;
  OrderedActionGroupType *            OrderedActionGroupTypeVal;
  PartiallyOrderedActionGroupType *   PartiallyOrderedActionGroupTypeVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  std::list<PlanElementBaseType *> *  PlanElementBaseTypeListVal;
  PlanElementBaseType *               PlanElementBaseTypeVal;
  PlusType *                          PlusTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  PropValType *                       PropValTypeVal;
  PutKitTrayType *                    PutKitTrayTypeVal;
  PutKitType *                        PutKitTypeVal;
  PutPartType *                       PutPartTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotActionBaseType *               RobotActionBaseTypeVal;
  SensorActionBaseType *              SensorActionBaseTypeVal;
  SomeOfActionGroupType *             SomeOfActionGroupTypeVal;
  std::list<StepWithPredecessorsType *> * StepWithPredecessorsTypeListVal;
  StepWithPredecessorsType *          StepWithPredecessorsTypeVal;
  TakeKitTrayType *                   TakeKitTrayTypeVal;
  TakeKitType *                       TakeKitTypeVal;
  TakePartType *                      TakePartTypeVal;
  std::list<TestAndStepType *> *      TestAndStepTypeListVal;
  TestAndStepType *                   TestAndStepTypeVal;
  TimesType *                         TimesTypeVal;
  TrueType *                          TrueTypeVal;
  UnorderedActionGroupType *          UnorderedActionGroupTypeVal;
  VarSetType *                        VarSetTypeVal;
  VarValType *                        VarValTypeVal;
  std::list<VariableDeclarationType *> * VariableDeclarationTypeListVal;
  VariableDeclarationType *           VariableDeclarationTypeVal;
  VectorType *                        VectorTypeVal;
  WhileActionGroupType *              WhileActionGroupTypeVal;
  std::list<XmlPositiveInteger *> *   positiveIntegerListVal;
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForKittingPlanVal>    y_XmlHeaderForKittingPlan
%type <XmlVersionVal>                 y_XmlVersion
%type <KittingPlanFileVal>            y_KittingPlanFile
%type <XmlDateTimeVal>                y_XmlDateTime
%type <XmlDecimalVal>                 y_XmlDecimal
%type <XmlIDVal>                      y_XmlID
%type <XmlIDREFVal>                   y_XmlIDREF
%type <XmlNMTOKENVal>                 y_XmlNMTOKEN
%type <XmlPositiveIntegerVal>         y_XmlPositiveInteger
%type <XmlStringVal>                  y_XmlString
%type <XmlTokenVal>                   y_XmlToken

%type <ArithmeticExpressionTypeVal>   y_A1_ArithmeticExpressionType
%type <ArithmeticExpressionTypeVal>   y_A2_ArithmeticExpressionType
%type <ArithmeticExpressionTypeVal>   y_A_ArithmeticExpressionType
%type <XmlDecimalVal>                 y_A_XmlDecimal
%type <ArithmeticExpressionTypeVal>   y_ArithmeticExpressionTypeAny
%type <BooleanExpressionTypeVal>      y_B1_BooleanExpressionType
%type <BooleanExpressionTypeVal>      y_B2_BooleanExpressionType
%type <BooleanExpressionTypeVal>      y_B_BooleanExpressionType
%type <BooleanExpressionTypeVal>      y_BooleanExpressionTypeAny
%type <XmlStringVal>                  y_Description_XmlString
%type <TestAndStepTypeVal>            y_ElseIf_TestAndStepType_0_u
%type <TestAndStepTypeListVal>        y_ElseIf_TestAndStepType_0_uList
%type <ElseTypeVal>                   y_ElseType
%type <ElseTypeVal>                   y_Else_ElseType_0
%type <XmlNMTOKENVal>                 y_EndEffectorHolderName_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_EndEffectorName_XmlNMTOKEN
%type <XmlDecimalVal>                 y_I_XmlDecimal
%type <TestAndStepTypeVal>            y_If_TestAndStepType
%type <XmlDecimalVal>                 y_J_XmlDecimal
%type <XmlDecimalVal>                 y_K_XmlDecimal
%type <XmlNMTOKENVal>                 y_KitName_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_KitTrayName_XmlNMTOKEN
%type <KittingPlanTypeVal>            y_KittingPlanType
%type <PhysicalLocationTypeVal>       y_Location_PhysicalLocationType
%type <XmlIDVal>                      y_Name_XmlID
%type <XmlPositiveIntegerVal>         y_NumberOfSteps_XmlPositiveInteger
%type <NumberedPlanElementTypeVal>    y_NumberedPlanElementType
%type <XmlNMTOKENVal>                 y_Object_XmlNMTOKEN_u
%type <NMTOKENListVal>                y_Object_XmlNMTOKEN_uList
%type <PositiveDecimalTypeVal>        y_OrientationStandardDeviation_PositiveDecimalType_0
%type <XmlNMTOKENVal>                 y_PartName_XmlNMTOKEN
%type <PhysicalLocationTypeVal>       y_PhysicalLocationTypeAny
%type <XmlTokenVal>                   y_PlanAuthor_XmlToken
%type <XmlDateTimeVal>                y_PlanDateAndTime_XmlDateTime
%type <XmlStringVal>                  y_PlanDescription_XmlString
%type <PlanElementBaseTypeVal>        y_PlanElementBaseTypeAny
%type <PlanElementBaseTypeVal>        y_PlanElement_PlanElementBaseType
%type <XmlNMTOKENVal>                 y_PlanId_XmlNMTOKEN
%type <PlanElementBaseTypeVal>        y_PlanRoot_PlanElementBaseType
%type <XmlTokenVal>                   y_PlanVersion_XmlToken
%type <PointTypeVal>                  y_PointType
%type <PointTypeVal>                  y_Point_PointType
%type <PositiveDecimalTypeVal>        y_PositionStandardDeviation_PositiveDecimalType_0
%type <XmlPositiveIntegerVal>         y_Predecessor_XmlPositiveInteger_0_u
%type <positiveIntegerListVal>        y_Predecessor_XmlPositiveInteger_0_uList
%type <XmlNMTOKENVal>                 y_Property_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_RefObjectName_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_RobotName_XmlNMTOKEN
%type <XmlPositiveIntegerVal>         y_SequenceNumber_XmlPositiveInteger
%type <StepWithPredecessorsTypeVal>   y_StepWithPredecessorsType
%type <NumberedPlanElementTypeVal>    y_Step_NumberedPlanElementType_u
%type <NumberedPlanElementTypeListVal> y_Step_NumberedPlanElementType_uList
%type <PlanElementBaseTypeVal>        y_Step_PlanElementBaseType
%type <PlanElementBaseTypeVal>        y_Step_PlanElementBaseType_u
%type <PlanElementBaseTypeListVal>    y_Step_PlanElementBaseType_uList
%type <StepWithPredecessorsTypeVal>   y_Step_StepWithPredecessorsType_u
%type <StepWithPredecessorsTypeListVal> y_Step_StepWithPredecessorsType_uList
%type <TestAndStepTypeVal>            y_TestAndStepType
%type <BooleanExpressionTypeVal>      y_Test_BooleanExpressionType
%type <XmlNMTOKENVal>                 y_ThingName_XmlNMTOKEN
%type <ArithmeticExpressionTypeVal>   y_Val_ArithmeticExpressionType
%type <XmlDecimalVal>                 y_Val_XmlDecimal
%type <XmlIDREFVal>                   y_VarName_XmlIDREF
%type <VariableDeclarationTypeVal>    y_VariableDeclarationType
%type <VariableDeclarationTypeVal>    y_Variable_VariableDeclarationType_0_u
%type <VariableDeclarationTypeListVal> y_Variable_VariableDeclarationType_0_uList
%type <VectorTypeVal>                 y_VectorType
%type <VectorTypeVal>                 y_XAxis_VectorType
%type <XmlDecimalVal>                 y_X_XmlDecimal
%type <XmlDecimalVal>                 y_Y_XmlDecimal
%type <VectorTypeVal>                 y_ZAxis_VectorType
%type <XmlDecimalVal>                 y_Z_XmlDecimal
%type <AndTypeVal>                    y_x_AndType
%type <AttachEndEffectorTypeVal>      y_x_AttachEndEffectorType
%type <CreateKitTypeVal>              y_x_CreateKitType
%type <DecimalTypeVal>                y_x_DecimalType
%type <DetachEndEffectorTypeVal>      y_x_DetachEndEffectorType
%type <DivTypeVal>                    y_x_DivType
%type <EqualTypeVal>                  y_x_EqualType
%type <FalseTypeVal>                  y_x_FalseType
%type <GreaterOrEqualTypeVal>         y_x_GreaterOrEqualType
%type <GreaterTypeVal>                y_x_GreaterType
%type <IfActionGroupTypeVal>          y_x_IfActionGroupType
%type <LessOrEqualTypeVal>            y_x_LessOrEqualType
%type <LessTypeVal>                   y_x_LessType
%type <LocatePartTypeVal>             y_x_LocatePartType
%type <MinusTypeVal>                  y_x_MinusType
%type <ModTypeVal>                    y_x_ModType
%type <NegateTypeVal>                 y_x_NegateType
%type <NotEqualTypeVal>               y_x_NotEqualType
%type <NotTypeVal>                    y_x_NotType
%type <OneOfActionGroupTypeVal>       y_x_OneOfActionGroupType
%type <OrTypeVal>                     y_x_OrType
%type <OrderedActionGroupTypeVal>     y_x_OrderedActionGroupType
%type <PartiallyOrderedActionGroupTypeVal> y_x_PartiallyOrderedActionGroupType
%type <PlusTypeVal>                   y_x_PlusType
%type <PoseLocationInTypeVal>         y_x_PoseLocationInType
%type <PoseLocationOnTypeVal>         y_x_PoseLocationOnType
%type <PoseOnlyLocationTypeVal>       y_x_PoseOnlyLocationType
%type <PropValTypeVal>                y_x_PropValType
%type <PutKitTrayTypeVal>             y_x_PutKitTrayType
%type <PutKitTypeVal>                 y_x_PutKitType
%type <PutPartTypeVal>                y_x_PutPartType
%type <RelativeLocationInTypeVal>     y_x_RelativeLocationInType
%type <RelativeLocationOnTypeVal>     y_x_RelativeLocationOnType
%type <SomeOfActionGroupTypeVal>      y_x_SomeOfActionGroupType
%type <TakeKitTrayTypeVal>            y_x_TakeKitTrayType
%type <TakeKitTypeVal>                y_x_TakeKitType
%type <TakePartTypeVal>               y_x_TakePartType
%type <TimesTypeVal>                  y_x_TimesType
%type <TrueTypeVal>                   y_x_TrueType
%type <UnorderedActionGroupTypeVal>   y_x_UnorderedActionGroupType
%type <VarSetTypeVal>                 y_x_VarSetType
%type <VarValTypeVal>                 y_x_VarValType
%type <WhileActionGroupTypeVal>       y_x_WhileActionGroupType

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

%token <iVal> A1END
%token <iVal> A1START
%token <iVal> A2END
%token <iVal> A2START
%token <iVal> AEND
%token <iVal> ASTART
%token <iVal> B1END
%token <iVal> B1START
%token <iVal> B2END
%token <iVal> B2START
%token <iVal> BEND
%token <iVal> BSTART
%token <iVal> DESCRIPTIONEND
%token <iVal> DESCRIPTIONSTART
%token <iVal> ELSEIFEND
%token <iVal> ELSEIFSTART
%token <iVal> ELSEEND
%token <iVal> ELSESTART
%token <iVal> ENDEFFECTORHOLDERNAMEEND
%token <iVal> ENDEFFECTORHOLDERNAMESTART
%token <iVal> ENDEFFECTORNAMEEND
%token <iVal> ENDEFFECTORNAMESTART
%token <iVal> IEND
%token <iVal> ISTART
%token <iVal> IFEND
%token <iVal> IFSTART
%token <iVal> JEND
%token <iVal> JSTART
%token <iVal> KEND
%token <iVal> KSTART
%token <iVal> KITNAMEEND
%token <iVal> KITNAMESTART
%token <iVal> KITTRAYNAMEEND
%token <iVal> KITTRAYNAMESTART
%token <iVal> KITTINGPLANEND
%token <iVal> KITTINGPLANSTART
%token <iVal> LOCATIONEND
%token <iVal> LOCATIONSTART
%token <iVal> NAMEEND
%token <iVal> NAMESTART
%token <iVal> NUMBEROFSTEPSEND
%token <iVal> NUMBEROFSTEPSSTART
%token <iVal> OBJECTEND
%token <iVal> OBJECTSTART
%token <iVal> ORIENTATIONSTANDARDDEVIATIONEND
%token <iVal> ORIENTATIONSTANDARDDEVIATIONSTART
%token <iVal> PARTNAMEEND
%token <iVal> PARTNAMESTART
%token <iVal> PLANAUTHOREND
%token <iVal> PLANAUTHORSTART
%token <iVal> PLANDATEANDTIMEEND
%token <iVal> PLANDATEANDTIMESTART
%token <iVal> PLANDESCRIPTIONEND
%token <iVal> PLANDESCRIPTIONSTART
%token <iVal> PLANELEMENTEND
%token <iVal> PLANELEMENTSTART
%token <iVal> PLANIDEND
%token <iVal> PLANIDSTART
%token <iVal> PLANROOTEND
%token <iVal> PLANROOTSTART
%token <iVal> PLANVERSIONEND
%token <iVal> PLANVERSIONSTART
%token <iVal> POINTEND
%token <iVal> POINTSTART
%token <iVal> POSITIONSTANDARDDEVIATIONEND
%token <iVal> POSITIONSTANDARDDEVIATIONSTART
%token <iVal> PREDECESSOREND
%token <iVal> PREDECESSORSTART
%token <iVal> PROPERTYEND
%token <iVal> PROPERTYSTART
%token <iVal> REFOBJECTNAMEEND
%token <iVal> REFOBJECTNAMESTART
%token <iVal> ROBOTNAMEEND
%token <iVal> ROBOTNAMESTART
%token <iVal> SEQUENCENUMBEREND
%token <iVal> SEQUENCENUMBERSTART
%token <iVal> STEPEND
%token <iVal> STEPSTART
%token <iVal> TESTEND
%token <iVal> TESTSTART
%token <iVal> THINGNAMEEND
%token <iVal> THINGNAMESTART
%token <iVal> VALEND
%token <iVal> VALSTART
%token <iVal> VARNAMEEND
%token <iVal> VARNAMESTART
%token <iVal> VARIABLEEND
%token <iVal> VARIABLESTART
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


%token <iVal> ACTIONBASETYPEDECL
%token <iVal> ACTIONGROUPBASETYPEDECL
%token <iVal> ANDTYPEDECL
%token <iVal> ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL
%token <iVal> ARITHMETICEXPRESSIONTYPEDECL
%token <iVal> ATTACHENDEFFECTORTYPEDECL
%token <iVal> BINARYARITHMETICEXPRESSIONTYPEDECL
%token <iVal> BINARYBOOLEANEXPRESSIONTYPEDECL
%token <iVal> BOOLEANCONSTANTTYPEDECL
%token <iVal> BOOLEANEXPRESSIONTYPEDECL
%token <iVal> CREATEKITTYPEDECL
%token <iVal> DECIMALTYPEDECL
%token <iVal> DETACHENDEFFECTORTYPEDECL
%token <iVal> DIVTYPEDECL
%token <iVal> ELSETYPEDECL
%token <iVal> EQUALTYPEDECL
%token <iVal> FALSETYPEDECL
%token <iVal> GREATEROREQUALTYPEDECL
%token <iVal> GREATERTYPEDECL
%token <iVal> IFACTIONGROUPTYPEDECL
%token <iVal> KITTINGPLANTYPEDECL
%token <iVal> LESSOREQUALTYPEDECL
%token <iVal> LESSTYPEDECL
%token <iVal> LOCATEPARTTYPEDECL
%token <iVal> MINUSTYPEDECL
%token <iVal> MODTYPEDECL
%token <iVal> NEGATETYPEDECL
%token <iVal> NOTEQUALTYPEDECL
%token <iVal> NOTTYPEDECL
%token <iVal> NUMBEREDPLANELEMENTTYPEDECL
%token <iVal> ONEOFACTIONGROUPTYPEDECL
%token <iVal> ORTYPEDECL
%token <iVal> ORDEREDACTIONGROUPTYPEDECL
%token <iVal> PARTIALLYORDEREDACTIONGROUPTYPEDECL
%token <iVal> PHYSICALLOCATIONTYPEDECL
%token <iVal> PLANELEMENTBASETYPEDECL
%token <iVal> PLUSTYPEDECL
%token <iVal> POINTTYPEDECL
%token <iVal> POSELOCATIONINTYPEDECL
%token <iVal> POSELOCATIONONTYPEDECL
%token <iVal> POSELOCATIONTYPEDECL
%token <iVal> POSEONLYLOCATIONTYPEDECL
%token <iVal> PROPVALTYPEDECL
%token <iVal> PUTKITTRAYTYPEDECL
%token <iVal> PUTKITTYPEDECL
%token <iVal> PUTPARTTYPEDECL
%token <iVal> RELATIVELOCATIONINTYPEDECL
%token <iVal> RELATIVELOCATIONONTYPEDECL
%token <iVal> RELATIVELOCATIONTYPEDECL
%token <iVal> ROBOTACTIONBASETYPEDECL
%token <iVal> SENSORACTIONBASETYPEDECL
%token <iVal> SOMEOFACTIONGROUPTYPEDECL
%token <iVal> STEPWITHPREDECESSORSTYPEDECL
%token <iVal> TAKEKITTRAYTYPEDECL
%token <iVal> TAKEKITTYPEDECL
%token <iVal> TAKEPARTTYPEDECL
%token <iVal> TESTANDSTEPTYPEDECL
%token <iVal> TIMESTYPEDECL
%token <iVal> TRUETYPEDECL
%token <iVal> UNORDEREDACTIONGROUPTYPEDECL
%token <iVal> VARSETTYPEDECL
%token <iVal> VARVALTYPEDECL
%token <iVal> VARIABLEDECLARATIONTYPEDECL
%token <iVal> VECTORTYPEDECL
%token <iVal> WHILEACTIONGROUPTYPEDECL

%%

y_KittingPlanFile :
	  y_XmlVersion KITTINGPLANSTART y_XmlHeaderForKittingPlan
	  y_KittingPlanType KITTINGPLANEND
	  {$$ = new KittingPlanFile($1, $3, $4);
	   KittingPlanTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForKittingPlan:
	  XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForKittingPlan($2);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2, false);
	  }
	;

y_XmlDateTime :
	  DATASTRING
	  {$$ = new XmlDateTime($1);
	   if ($$->bad)
	     yyerror("bad XmlDateTime");
	  }
	;

y_XmlDecimal :
	  DATASTRING
	  {$$ = new XmlDecimal($1);
	   if ($$->bad)
	     yyerror("bad XmlDecimal");
	  }
	;

y_XmlID :
	  DATASTRING
	  {$$ = new XmlID($1);
	   if ($$->bad)
	     yyerror("bad XmlID");
	  }
	;

y_XmlIDREF :
	  DATASTRING
	  {$$ = new XmlIDREF($1);
	   if ($$->bad)
	     yyerror("bad XmlIDREF");
	  }
	;

y_XmlNMTOKEN :
	  DATASTRING
	  {$$ = new XmlNMTOKEN($1);
	   if ($$->bad)
	     yyerror("bad XmlNMTOKEN");
	  }
	;

y_XmlPositiveInteger :
	  DATASTRING
	  {$$ = new XmlPositiveInteger($1);
	   if ($$->bad)
	     yyerror("bad XmlPositiveInteger");
	  }
	;

y_XmlString :
	  DATASTRING
	  {$$ = new XmlString($1);
	   if ($$->bad)
	     yyerror("bad XmlString");
	  }
	;

y_XmlToken :
	  DATASTRING
	  {$$ = new XmlToken($1);
	   if ($$->bad)
	     yyerror("bad XmlToken");
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
	   else if (strcmp($5, "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  }
	;

y_A1_ArithmeticExpressionType :
	  A1START y_ArithmeticExpressionTypeAny A1END
	  {$$ = $2;}
	;

y_A2_ArithmeticExpressionType :
	  A2START y_ArithmeticExpressionTypeAny A2END
	  {$$ = $2;}
	;

y_A_ArithmeticExpressionType :
	  ASTART y_ArithmeticExpressionTypeAny AEND
	  {$$ = $2;}
	;

y_A_XmlDecimal :
	  ASTART ENDITEM {yyReadData = 1;} y_XmlDecimal AEND
	  {$$ = $4;}
	;

y_ArithmeticExpressionTypeAny :
	  y_x_DecimalType
	  {$$ = $1;}
	| y_x_DivType
	  {$$ = $1;}
	| y_x_MinusType
	  {$$ = $1;}
	| y_x_ModType
	  {$$ = $1;}
	| y_x_NegateType
	  {$$ = $1;}
	| y_x_PlusType
	  {$$ = $1;}
	| y_x_PropValType
	  {$$ = $1;}
	| y_x_TimesType
	  {$$ = $1;}
	| y_x_VarValType
	  {$$ = $1;}
	;

y_B1_BooleanExpressionType :
	  B1START y_BooleanExpressionTypeAny B1END
	  {$$ = $2;}
	;

y_B2_BooleanExpressionType :
	  B2START y_BooleanExpressionTypeAny B2END
	  {$$ = $2;}
	;

y_B_BooleanExpressionType :
	  BSTART y_BooleanExpressionTypeAny BEND
	  {$$ = $2;}
	;

y_BooleanExpressionTypeAny :
	  y_x_AndType
	  {$$ = $1;}
	| y_x_EqualType
	  {$$ = $1;}
	| y_x_FalseType
	  {$$ = $1;}
	| y_x_GreaterOrEqualType
	  {$$ = $1;}
	| y_x_GreaterType
	  {$$ = $1;}
	| y_x_LessOrEqualType
	  {$$ = $1;}
	| y_x_LessType
	  {$$ = $1;}
	| y_x_NotEqualType
	  {$$ = $1;}
	| y_x_NotType
	  {$$ = $1;}
	| y_x_OrType
	  {$$ = $1;}
	| y_x_TrueType
	  {$$ = $1;}
	;

y_Description_XmlString :
	  DESCRIPTIONSTART ENDITEM {yyReadData = 1;} y_XmlString
	  DESCRIPTIONEND
	  {$$ = $4;}
	;

y_ElseIf_TestAndStepType_0_u :
	  ELSEIFSTART y_TestAndStepType ELSEIFEND
	  {$$ = $2;}
	;

y_ElseIf_TestAndStepType_0_uList :
	  /* empty */
	  {$$ = new std::list<TestAndStepType *>;}
	| y_ElseIf_TestAndStepType_0_uList y_ElseIf_TestAndStepType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ElseType :
	   ENDITEM y_Name_XmlID y_Step_PlanElementBaseType
	  {$$ = new ElseType($2, $3);}
	;

y_Else_ElseType_0 :
	  /* empty */
	  {$$ = 0;}
	| ELSESTART y_ElseType ELSEEND
	  {$$ = $2;}
	;

y_EndEffectorHolderName_XmlNMTOKEN :
	  ENDEFFECTORHOLDERNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  ENDEFFECTORHOLDERNAMEEND
	  {$$ = $4;}
	;

y_EndEffectorName_XmlNMTOKEN :
	  ENDEFFECTORNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  ENDEFFECTORNAMEEND
	  {$$ = $4;}
	;

y_I_XmlDecimal :
	  ISTART ENDITEM {yyReadData = 1;} y_XmlDecimal IEND
	  {$$ = $4;}
	;

y_If_TestAndStepType :
	  IFSTART y_TestAndStepType IFEND
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

y_KitName_XmlNMTOKEN :
	  KITNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN KITNAMEEND
	  {$$ = $4;}
	;

y_KitTrayName_XmlNMTOKEN :
	  KITTRAYNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  KITTRAYNAMEEND
	  {$$ = $4;}
	;

y_KittingPlanType :
	   ENDITEM y_Name_XmlID y_PlanId_XmlNMTOKEN y_PlanVersion_XmlToken
	  y_PlanDateAndTime_XmlDateTime y_PlanAuthor_XmlToken
	  y_PlanDescription_XmlString y_Object_XmlNMTOKEN_uList
	  y_Variable_VariableDeclarationType_0_uList
	  y_PlanRoot_PlanElementBaseType
	  {$$ = new KittingPlanType($2, $3, $4, $5, $6, $7, $8, $9, $10);}
	;

y_Location_PhysicalLocationType :
	  LOCATIONSTART y_PhysicalLocationTypeAny LOCATIONEND
	  {$$ = $2;}
	;

y_Name_XmlID :
	  NAMESTART ENDITEM {yyReadData = 1;} y_XmlID NAMEEND
	  {$$ = $4;}
	;

y_NumberOfSteps_XmlPositiveInteger :
	  NUMBEROFSTEPSSTART ENDITEM {yyReadData = 1;} y_XmlPositiveInteger
	  NUMBEROFSTEPSEND
	  {$$ = $4;}
	;

y_NumberedPlanElementType :
	   ENDITEM y_Name_XmlID y_SequenceNumber_XmlPositiveInteger
	  y_PlanElement_PlanElementBaseType
	  {$$ = new NumberedPlanElementType($2, $3, $4);}
	;

y_Object_XmlNMTOKEN_u :
	  OBJECTSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN OBJECTEND
	  {$$ = $4;}
	;

y_Object_XmlNMTOKEN_uList :
	  y_Object_XmlNMTOKEN_u
	  {$$ = new std::list<XmlNMTOKEN *>;
	   $$->push_back($1);}
	| y_Object_XmlNMTOKEN_uList y_Object_XmlNMTOKEN_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_OrientationStandardDeviation_PositiveDecimalType_0 :
	  /* empty */
	  {$$ = 0;}
	| ORIENTATIONSTANDARDDEVIATIONSTART ENDITEM {yyReadData = 1;}
	  DATASTRING ORIENTATIONSTANDARDDEVIATIONEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  }
	;

y_PartName_XmlNMTOKEN :
	  PARTNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN PARTNAMEEND
	  {$$ = $4;}
	;

y_PhysicalLocationTypeAny :
	  y_x_PoseLocationInType
	  {$$ = $1;}
	| y_x_PoseLocationOnType
	  {$$ = $1;}
	| y_x_PoseOnlyLocationType
	  {$$ = $1;}
	| y_x_RelativeLocationInType
	  {$$ = $1;}
	| y_x_RelativeLocationOnType
	  {$$ = $1;}
	;

y_PlanAuthor_XmlToken :
	  PLANAUTHORSTART ENDITEM {yyReadData = 1;} y_XmlToken
	  PLANAUTHOREND
	  {$$ = $4;}
	;

y_PlanDateAndTime_XmlDateTime :
	  PLANDATEANDTIMESTART ENDITEM {yyReadData = 1;} y_XmlDateTime
	  PLANDATEANDTIMEEND
	  {$$ = $4;}
	;

y_PlanDescription_XmlString :
	  PLANDESCRIPTIONSTART ENDITEM {yyReadData = 1;} y_XmlString
	  PLANDESCRIPTIONEND
	  {$$ = $4;}
	;

y_PlanElementBaseTypeAny :
	  y_x_AttachEndEffectorType
	  {$$ = $1;}
	| y_x_CreateKitType
	  {$$ = $1;}
	| y_x_DetachEndEffectorType
	  {$$ = $1;}
	| y_x_IfActionGroupType
	  {$$ = $1;}
	| y_x_LocatePartType
	  {$$ = $1;}
	| y_x_OneOfActionGroupType
	  {$$ = $1;}
	| y_x_OrderedActionGroupType
	  {$$ = $1;}
	| y_x_PartiallyOrderedActionGroupType
	  {$$ = $1;}
	| y_x_PutKitTrayType
	  {$$ = $1;}
	| y_x_PutKitType
	  {$$ = $1;}
	| y_x_PutPartType
	  {$$ = $1;}
	| y_x_SomeOfActionGroupType
	  {$$ = $1;}
	| y_x_TakeKitTrayType
	  {$$ = $1;}
	| y_x_TakeKitType
	  {$$ = $1;}
	| y_x_TakePartType
	  {$$ = $1;}
	| y_x_UnorderedActionGroupType
	  {$$ = $1;}
	| y_x_VarSetType
	  {$$ = $1;}
	| y_x_WhileActionGroupType
	  {$$ = $1;}
	;

y_PlanElement_PlanElementBaseType :
	  PLANELEMENTSTART y_PlanElementBaseTypeAny PLANELEMENTEND
	  {$$ = $2;}
	;

y_PlanId_XmlNMTOKEN :
	  PLANIDSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN PLANIDEND
	  {$$ = $4;}
	;

y_PlanRoot_PlanElementBaseType :
	  PLANROOTSTART y_PlanElementBaseTypeAny PLANROOTEND
	  {$$ = $2;}
	;

y_PlanVersion_XmlToken :
	  PLANVERSIONSTART ENDITEM {yyReadData = 1;} y_XmlToken
	  PLANVERSIONEND
	  {$$ = $4;}
	;

y_PointType :
	   ENDITEM y_Name_XmlID y_X_XmlDecimal y_Y_XmlDecimal
	  y_Z_XmlDecimal
	  {$$ = new PointType($2, $3, $4, $5);}
	;

y_Point_PointType :
	  POINTSTART y_PointType POINTEND
	  {$$ = $2;}
	;

y_PositionStandardDeviation_PositiveDecimalType_0 :
	  /* empty */
	  {$$ = 0;}
	| POSITIONSTANDARDDEVIATIONSTART ENDITEM {yyReadData = 1;}
	  DATASTRING POSITIONSTANDARDDEVIATIONEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad PositionStandardDeviation value");
	  }
	;

y_Predecessor_XmlPositiveInteger_0_u :
	  PREDECESSORSTART ENDITEM {yyReadData = 1;} y_XmlPositiveInteger
	  PREDECESSOREND
	  {$$ = $4;}
	;

y_Predecessor_XmlPositiveInteger_0_uList :
	  /* empty */
	  {$$ = new std::list<XmlPositiveInteger *>;}
	| y_Predecessor_XmlPositiveInteger_0_uList
	  y_Predecessor_XmlPositiveInteger_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_Property_XmlNMTOKEN :
	  PROPERTYSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN PROPERTYEND
	  {$$ = $4;}
	;

y_RefObjectName_XmlNMTOKEN :
	  REFOBJECTNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  REFOBJECTNAMEEND
	  {$$ = $4;}
	;

y_RobotName_XmlNMTOKEN :
	  ROBOTNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  ROBOTNAMEEND
	  {$$ = $4;}
	;

y_SequenceNumber_XmlPositiveInteger :
	  SEQUENCENUMBERSTART ENDITEM {yyReadData = 1;}
	  y_XmlPositiveInteger SEQUENCENUMBEREND
	  {$$ = $4;}
	;

y_StepWithPredecessorsType :
	   ENDITEM y_Name_XmlID y_SequenceNumber_XmlPositiveInteger
	  y_Predecessor_XmlPositiveInteger_0_uList
	  y_PlanElement_PlanElementBaseType
	  {$$ = new StepWithPredecessorsType($2, $3, $4, $5);}
	;

y_Step_NumberedPlanElementType_u :
	  STEPSTART y_NumberedPlanElementType STEPEND
	  {$$ = $2;}
	;

y_Step_NumberedPlanElementType_uList :
	  y_Step_NumberedPlanElementType_u
	  {$$ = new std::list<NumberedPlanElementType *>;
	   $$->push_back($1);}
	| y_Step_NumberedPlanElementType_uList
	  y_Step_NumberedPlanElementType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_Step_PlanElementBaseType :
	  STEPSTART y_PlanElementBaseTypeAny STEPEND
	  {$$ = $2;}
	;

y_Step_PlanElementBaseType_u :
	  STEPSTART y_PlanElementBaseTypeAny STEPEND
	  {$$ = $2;}
	;

y_Step_PlanElementBaseType_uList :
	  y_Step_PlanElementBaseType_u
	  {$$ = new std::list<PlanElementBaseType *>;
	   $$->push_back($1);}
	| y_Step_PlanElementBaseType_uList y_Step_PlanElementBaseType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_Step_StepWithPredecessorsType_u :
	  STEPSTART y_StepWithPredecessorsType STEPEND
	  {$$ = $2;}
	;

y_Step_StepWithPredecessorsType_uList :
	  y_Step_StepWithPredecessorsType_u
	  {$$ = new std::list<StepWithPredecessorsType *>;
	   $$->push_back($1);}
	| y_Step_StepWithPredecessorsType_uList
	  y_Step_StepWithPredecessorsType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_TestAndStepType :
	   ENDITEM y_Name_XmlID y_Test_BooleanExpressionType
	  y_Step_PlanElementBaseType
	  {$$ = new TestAndStepType($2, $3, $4);}
	;

y_Test_BooleanExpressionType :
	  TESTSTART y_BooleanExpressionTypeAny TESTEND
	  {$$ = $2;}
	;

y_ThingName_XmlNMTOKEN :
	  THINGNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  THINGNAMEEND
	  {$$ = $4;}
	;

y_Val_ArithmeticExpressionType :
	  VALSTART y_ArithmeticExpressionTypeAny VALEND
	  {$$ = $2;}
	;

y_Val_XmlDecimal :
	  VALSTART ENDITEM {yyReadData = 1;} y_XmlDecimal VALEND
	  {$$ = $4;}
	;

y_VarName_XmlIDREF :
	  VARNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF VARNAMEEND
	  {$$ = $4;}
	;

y_VariableDeclarationType :
	   ENDITEM y_Name_XmlID y_Val_XmlDecimal
	  {$$ = new VariableDeclarationType($2, $3);}
	;

y_Variable_VariableDeclarationType_0_u :
	  VARIABLESTART y_VariableDeclarationType VARIABLEEND
	  {$$ = $2;}
	;

y_Variable_VariableDeclarationType_0_uList :
	  /* empty */
	  {$$ = new std::list<VariableDeclarationType *>;}
	| y_Variable_VariableDeclarationType_0_uList
	  y_Variable_VariableDeclarationType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_VectorType :
	   ENDITEM y_Name_XmlID y_I_XmlDecimal y_J_XmlDecimal
	  y_K_XmlDecimal
	  {$$ = new VectorType($2, $3, $4, $5);}
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

y_x_AndType :
	  ANDTYPEDECL ENDITEM y_Name_XmlID y_B1_BooleanExpressionType
	  y_B2_BooleanExpressionType
	  {$$ = new AndType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_AttachEndEffectorType :
	  ATTACHENDEFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_RobotName_XmlNMTOKEN y_EndEffectorName_XmlNMTOKEN
	  y_EndEffectorHolderName_XmlNMTOKEN
	  {$$ = new AttachEndEffectorType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_CreateKitType :
	  CREATEKITTYPEDECL ENDITEM y_Name_XmlID y_KitTrayName_XmlNMTOKEN
	  y_KitName_XmlNMTOKEN
	  {$$ = new CreateKitType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_DecimalType :
	  DECIMALTYPEDECL ENDITEM y_Name_XmlID y_A_XmlDecimal
	  {$$ = new DecimalType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_DetachEndEffectorType :
	  DETACHENDEFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_RobotName_XmlNMTOKEN y_EndEffectorName_XmlNMTOKEN
	  y_EndEffectorHolderName_XmlNMTOKEN
	  {$$ = new DetachEndEffectorType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_DivType :
	  DIVTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new DivType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_EqualType :
	  EQUALTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new EqualType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_FalseType :
	  FALSETYPEDECL ENDITEM y_Name_XmlID
	  {$$ = new FalseType($3);
	   $$->printTypp = true;
	  }
	;

y_x_GreaterOrEqualType :
	  GREATEROREQUALTYPEDECL ENDITEM y_Name_XmlID
	  y_A1_ArithmeticExpressionType y_A2_ArithmeticExpressionType
	  {$$ = new GreaterOrEqualType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_GreaterType :
	  GREATERTYPEDECL ENDITEM y_Name_XmlID
	  y_A1_ArithmeticExpressionType y_A2_ArithmeticExpressionType
	  {$$ = new GreaterType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_IfActionGroupType :
	  IFACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID y_If_TestAndStepType
	  y_ElseIf_TestAndStepType_0_uList y_Else_ElseType_0
	  {$$ = new IfActionGroupType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_LessOrEqualType :
	  LESSOREQUALTYPEDECL ENDITEM y_Name_XmlID
	  y_A1_ArithmeticExpressionType y_A2_ArithmeticExpressionType
	  {$$ = new LessOrEqualType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_LessType :
	  LESSTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new LessType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_LocatePartType :
	  LOCATEPARTTYPEDECL ENDITEM y_Name_XmlID y_PartName_XmlNMTOKEN
	  {$$ = new LocatePartType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_MinusType :
	  MINUSTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new MinusType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_ModType :
	  MODTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new ModType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_NegateType :
	  NEGATETYPEDECL ENDITEM y_Name_XmlID y_A_ArithmeticExpressionType
	  {$$ = new NegateType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_NotEqualType :
	  NOTEQUALTYPEDECL ENDITEM y_Name_XmlID
	  y_A1_ArithmeticExpressionType y_A2_ArithmeticExpressionType
	  {$$ = new NotEqualType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_NotType :
	  NOTTYPEDECL ENDITEM y_Name_XmlID y_B_BooleanExpressionType
	  {$$ = new NotType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_OneOfActionGroupType :
	  ONEOFACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Step_NumberedPlanElementType_uList
	  {$$ = new OneOfActionGroupType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_OrType :
	  ORTYPEDECL ENDITEM y_Name_XmlID y_B1_BooleanExpressionType
	  y_B2_BooleanExpressionType
	  {$$ = new OrType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_OrderedActionGroupType :
	  ORDEREDACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Step_NumberedPlanElementType_uList
	  {$$ = new OrderedActionGroupType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_PartiallyOrderedActionGroupType :
	  PARTIALLYORDEREDACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Step_StepWithPredecessorsType_uList
	  {$$ = new PartiallyOrderedActionGroupType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_PlusType :
	  PLUSTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new PlusType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationInType :
	  POSELOCATIONINTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlNMTOKEN y_Point_PointType y_XAxis_VectorType
	  y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseLocationInType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationOnType :
	  POSELOCATIONONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlNMTOKEN y_Point_PointType y_XAxis_VectorType
	  y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseLocationOnType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_PoseOnlyLocationType :
	  POSEONLYLOCATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlNMTOKEN y_Point_PointType y_XAxis_VectorType
	  y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseOnlyLocationType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_PropValType :
	  PROPVALTYPEDECL ENDITEM y_Name_XmlID y_ThingName_XmlNMTOKEN
	  y_Property_XmlNMTOKEN
	  {$$ = new PropValType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_PutKitTrayType :
	  PUTKITTRAYTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_KitTrayName_XmlNMTOKEN y_Location_PhysicalLocationType
	  {$$ = new PutKitTrayType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_PutKitType :
	  PUTKITTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_KitName_XmlNMTOKEN y_Location_PhysicalLocationType
	  {$$ = new PutKitType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_PutPartType :
	  PUTPARTTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_PartName_XmlNMTOKEN y_Location_PhysicalLocationType
	  {$$ = new PutPartType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationInType :
	  RELATIVELOCATIONINTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlNMTOKEN y_Description_XmlString
	  {$$ = new RelativeLocationInType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationOnType :
	  RELATIVELOCATIONONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlNMTOKEN y_Description_XmlString
	  {$$ = new RelativeLocationOnType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_SomeOfActionGroupType :
	  SOMEOFACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Step_PlanElementBaseType_uList
	  y_NumberOfSteps_XmlPositiveInteger
	  {$$ = new SomeOfActionGroupType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_TakeKitTrayType :
	  TAKEKITTRAYTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_KitTrayName_XmlNMTOKEN
	  {$$ = new TakeKitTrayType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_TakeKitType :
	  TAKEKITTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_KitName_XmlNMTOKEN
	  {$$ = new TakeKitType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_TakePartType :
	  TAKEPARTTYPEDECL ENDITEM y_Name_XmlID y_RobotName_XmlNMTOKEN
	  y_PartName_XmlNMTOKEN
	  {$$ = new TakePartType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_TimesType :
	  TIMESTYPEDECL ENDITEM y_Name_XmlID y_A1_ArithmeticExpressionType
	  y_A2_ArithmeticExpressionType
	  {$$ = new TimesType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_TrueType :
	  TRUETYPEDECL ENDITEM y_Name_XmlID
	  {$$ = new TrueType($3);
	   $$->printTypp = true;
	  }
	;

y_x_UnorderedActionGroupType :
	  UNORDEREDACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Step_PlanElementBaseType_uList
	  {$$ = new UnorderedActionGroupType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_VarSetType :
	  VARSETTYPEDECL ENDITEM y_Name_XmlID y_VarName_XmlIDREF
	  y_Val_ArithmeticExpressionType
	  {$$ = new VarSetType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_VarValType :
	  VARVALTYPEDECL ENDITEM y_Name_XmlID y_VarName_XmlIDREF
	  {$$ = new VarValType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_WhileActionGroupType :
	  WHILEACTIONGROUPTYPEDECL ENDITEM y_Name_XmlID
	  y_Test_BooleanExpressionType y_Step_PlanElementBaseType
	  {$$ = new WhileActionGroupType($3, $4, $5);
	   $$->printTypp = true;
	  }
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
