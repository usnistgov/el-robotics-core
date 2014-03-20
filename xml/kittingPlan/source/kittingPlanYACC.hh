/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BAD = 258,
     DATASTRING = 259,
     ENCODING = 260,
     ENDITEM = 261,
     ENDVERSION = 262,
     SCHEMALOCATION = 263,
     STARTVERSION = 264,
     TERMINALSTRING = 265,
     XMLNSPREFIX = 266,
     XMLNSTARGET = 267,
     XMLVERSION = 268,
     A1END = 269,
     A1START = 270,
     A2END = 271,
     A2START = 272,
     AEND = 273,
     ASTART = 274,
     ANGLEUNITEND = 275,
     ANGLEUNITSTART = 276,
     ARRAYNUMBEREND = 277,
     ARRAYNUMBERSTART = 278,
     ARRAYRADIUSEND = 279,
     ARRAYRADIUSSTART = 280,
     B1END = 281,
     B1START = 282,
     B2END = 283,
     B2START = 284,
     BEND = 285,
     BSTART = 286,
     BASEEND = 287,
     BASESTART = 288,
     CAPACITYEND = 289,
     CAPACITYSTART = 290,
     CHANGINGSTATIONEND = 291,
     CHANGINGSTATIONSTART = 292,
     CUPDIAMETEREND = 293,
     CUPDIAMETERSTART = 294,
     DESCRIPTIONEND = 295,
     DESCRIPTIONSTART = 296,
     DESIGNNAMEEND = 297,
     DESIGNNAMESTART = 298,
     DIAMETEREND = 299,
     DIAMETERSTART = 300,
     ELSEIFEND = 301,
     ELSEIFSTART = 302,
     ELSEEND = 303,
     ELSESTART = 304,
     ENDEFFECTORHOLDERNAMEEND = 305,
     ENDEFFECTORHOLDERNAMESTART = 306,
     ENDEFFECTORHOLDEREND = 307,
     ENDEFFECTORHOLDERSTART = 308,
     ENDEFFECTORNAMEEND = 309,
     ENDEFFECTORNAMESTART = 310,
     ENDEFFECTOREND = 311,
     ENDEFFECTORSTART = 312,
     EXTERNALSHAPEEND = 313,
     EXTERNALSHAPESTART = 314,
     FINISHEDEND = 315,
     FINISHEDSTART = 316,
     GRASPPOSEEND = 317,
     GRASPPOSESTART = 318,
     HASTOPEND = 319,
     HASTOPSTART = 320,
     HEIGHTEND = 321,
     HEIGHTSTART = 322,
     HELDOBJECTEND = 323,
     HELDOBJECTSTART = 324,
     IEND = 325,
     ISTART = 326,
     IFEND = 327,
     IFSTART = 328,
     INTERNALSHAPEEND = 329,
     INTERNALSHAPESTART = 330,
     JEND = 331,
     JSTART = 332,
     KEND = 333,
     KSTART = 334,
     KITDESIGNNAMEEND = 335,
     KITDESIGNNAMESTART = 336,
     KITDESIGNEND = 337,
     KITDESIGNSTART = 338,
     KITNAMEEND = 339,
     KITNAMESTART = 340,
     KITTRAYNAMEEND = 341,
     KITTRAYNAMESTART = 342,
     KITTRAYSKUNAMEEND = 343,
     KITTRAYSKUNAMESTART = 344,
     KITTRAYEND = 345,
     KITTRAYSTART = 346,
     KITEND = 347,
     KITSTART = 348,
     KITTINGPLANEND = 349,
     KITTINGPLANSTART = 350,
     LARGECONTAINEREND = 351,
     LARGECONTAINERSTART = 352,
     LENGTHUNITEND = 353,
     LENGTHUNITSTART = 354,
     LENGTHEND = 355,
     LENGTHSTART = 356,
     LOCATIONEND = 357,
     LOCATIONSTART = 358,
     MAXIMUMLOADWEIGHTEND = 359,
     MAXIMUMLOADWEIGHTSTART = 360,
     MAXIMUMPOINTEND = 361,
     MAXIMUMPOINTSTART = 362,
     MINIMUMPOINTEND = 363,
     MINIMUMPOINTSTART = 364,
     MODELFILENAMEEND = 365,
     MODELFILENAMESTART = 366,
     MODELFORMATNAMEEND = 367,
     MODELFORMATNAMESTART = 368,
     MODELNAMEEND = 369,
     MODELNAMESTART = 370,
     NAMEEND = 371,
     NAMESTART = 372,
     NUMBEROFSTEPSEND = 373,
     NUMBEROFSTEPSSTART = 374,
     OBJECTONTABLEEND = 375,
     OBJECTONTABLESTART = 376,
     OBJECTEND = 377,
     OBJECTSTART = 378,
     ORIENTATIONSTANDARDDEVIATIONEND = 379,
     ORIENTATIONSTANDARDDEVIATIONSTART = 380,
     OTHEROBSTACLEEND = 381,
     OTHEROBSTACLESTART = 382,
     PARTNAMEEND = 383,
     PARTNAMESTART = 384,
     PARTQUANTITYEND = 385,
     PARTQUANTITYSTART = 386,
     PARTREFANDPOSENAMEEND = 387,
     PARTREFANDPOSENAMESTART = 388,
     PARTREFANDPOSEEND = 389,
     PARTREFANDPOSESTART = 390,
     PARTSKUNAMEEND = 391,
     PARTSKUNAMESTART = 392,
     PARTEND = 393,
     PARTSTART = 394,
     PLANAUTHOREND = 395,
     PLANAUTHORSTART = 396,
     PLANDATEANDTIMEEND = 397,
     PLANDATEANDTIMESTART = 398,
     PLANDESCRIPTIONEND = 399,
     PLANDESCRIPTIONSTART = 400,
     PLANELEMENTEND = 401,
     PLANELEMENTSTART = 402,
     PLANIDEND = 403,
     PLANIDSTART = 404,
     PLANROOTEND = 405,
     PLANROOTSTART = 406,
     PLANVERSIONEND = 407,
     PLANVERSIONSTART = 408,
     POINTEND = 409,
     POINTSTART = 410,
     POSITIONSTANDARDDEVIATIONEND = 411,
     POSITIONSTANDARDDEVIATIONSTART = 412,
     PREDECESSOREND = 413,
     PREDECESSORSTART = 414,
     PRIMARYLOCATIONEND = 415,
     PRIMARYLOCATIONSTART = 416,
     PROPERTYEND = 417,
     PROPERTYSTART = 418,
     REFOBJECTNAMEEND = 419,
     REFOBJECTNAMESTART = 420,
     ROBOTNAMEEND = 421,
     ROBOTNAMESTART = 422,
     ROBOTEND = 423,
     ROBOTSTART = 424,
     SECONDARYLOCATIONEND = 425,
     SECONDARYLOCATIONSTART = 426,
     SEQUENCENUMBEREND = 427,
     SEQUENCENUMBERSTART = 428,
     SERIALNUMBEREND = 429,
     SERIALNUMBERSTART = 430,
     SKUNAMEEND = 431,
     SKUNAMESTART = 432,
     SKUEND = 433,
     SKUSTART = 434,
     SLOTEND = 435,
     SLOTSTART = 436,
     STEPEND = 437,
     STEPSTART = 438,
     TESTEND = 439,
     TESTSTART = 440,
     THINGNAMEEND = 441,
     THINGNAMESTART = 442,
     TIMESTAMPEND = 443,
     TIMESTAMPSTART = 444,
     VALEND = 445,
     VALSTART = 446,
     VARNAMEEND = 447,
     VARNAMESTART = 448,
     VARIABLEEND = 449,
     VARIABLESTART = 450,
     WEIGHTUNITEND = 451,
     WEIGHTUNITSTART = 452,
     WEIGHTEND = 453,
     WEIGHTSTART = 454,
     WIDTHEND = 455,
     WIDTHSTART = 456,
     WORKVOLUMEEND = 457,
     WORKVOLUMESTART = 458,
     XAXISEND = 459,
     XAXISSTART = 460,
     XEND = 461,
     XSTART = 462,
     YEND = 463,
     YSTART = 464,
     ZAXISEND = 465,
     ZAXISSTART = 466,
     ZEND = 467,
     ZSTART = 468,
     ACTIONBASETYPEDECL = 469,
     ACTIONGROUPBASETYPEDECL = 470,
     ANDTYPEDECL = 471,
     ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL = 472,
     ARITHMETICEXPRESSIONTYPEDECL = 473,
     ATTACHENDEFFECTORTYPEDECL = 474,
     BINARYARITHMETICEXPRESSIONTYPEDECL = 475,
     BINARYBOOLEANEXPRESSIONTYPEDECL = 476,
     BOOLEANCONSTANTTYPEDECL = 477,
     BOOLEANEXPRESSIONTYPEDECL = 478,
     BOXVOLUMETYPEDECL = 479,
     BOXYSHAPETYPEDECL = 480,
     CREATEKITTYPEDECL = 481,
     CYLINDRICALSHAPETYPEDECL = 482,
     DECIMALTYPEDECL = 483,
     DETACHENDEFFECTORTYPEDECL = 484,
     DIVTYPEDECL = 485,
     ELSETYPEDECL = 486,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 487,
     ENDEFFECTORHOLDERTYPEDECL = 488,
     ENDEFFECTORTYPEDECL = 489,
     EQUALTYPEDECL = 490,
     EXTERNALSHAPETYPEDECL = 491,
     FALSETYPEDECL = 492,
     GREATEROREQUALTYPEDECL = 493,
     GREATERTYPEDECL = 494,
     GRIPPEREFFECTORTYPEDECL = 495,
     HUMANTYPEDECL = 496,
     IFACTIONGROUPTYPEDECL = 497,
     INTERNALSHAPETYPEDECL = 498,
     KITDESIGNTYPEDECL = 499,
     KITTRAYTYPEDECL = 500,
     KITTYPEDECL = 501,
     KITTINGPLANTYPEDECL = 502,
     KITTINGWORKSTATIONTYPEDECL = 503,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 504,
     LARGEBOXWITHKITSTYPEDECL = 505,
     LARGECONTAINERTYPEDECL = 506,
     LESSOREQUALTYPEDECL = 507,
     LESSTYPEDECL = 508,
     LOCATEPARTTYPEDECL = 509,
     MECHANICALCOMPONENTTYPEDECL = 510,
     MINUSTYPEDECL = 511,
     MODTYPEDECL = 512,
     NEGATETYPEDECL = 513,
     NOSKUOBJECTTYPEDECL = 514,
     NOTEQUALTYPEDECL = 515,
     NOTTYPEDECL = 516,
     NUMBEREDPLANELEMENTTYPEDECL = 517,
     ONEOFACTIONGROUPTYPEDECL = 518,
     ORTYPEDECL = 519,
     ORDEREDACTIONGROUPTYPEDECL = 520,
     PARTREFANDPOSETYPEDECL = 521,
     PARTTYPEDECL = 522,
     PARTIALLYORDEREDACTIONGROUPTYPEDECL = 523,
     PARTSBINTYPEDECL = 524,
     PARTSTRAYTYPEDECL = 525,
     PARTSVESSELTYPEDECL = 526,
     PHYSICALLOCATIONTYPEDECL = 527,
     PLANELEMENTBASETYPEDECL = 528,
     PLUSTYPEDECL = 529,
     POINTTYPEDECL = 530,
     POSELOCATIONINTYPEDECL = 531,
     POSELOCATIONONTYPEDECL = 532,
     POSELOCATIONTYPEDECL = 533,
     POSEONLYLOCATIONTYPEDECL = 534,
     PROPVALTYPEDECL = 535,
     PUTKITTRAYTYPEDECL = 536,
     PUTKITTYPEDECL = 537,
     PUTPARTTYPEDECL = 538,
     RELATIVELOCATIONINTYPEDECL = 539,
     RELATIVELOCATIONONTYPEDECL = 540,
     RELATIVELOCATIONTYPEDECL = 541,
     ROBOTACTIONBASETYPEDECL = 542,
     ROBOTTYPEDECL = 543,
     SENSORACTIONBASETYPEDECL = 544,
     SHAPEDESIGNTYPEDECL = 545,
     SKUOBJECTTYPEDECL = 546,
     SLOTTYPEDECL = 547,
     SOMEOFACTIONGROUPTYPEDECL = 548,
     STEPWITHPREDECESSORSTYPEDECL = 549,
     STOCKKEEPINGUNITTYPEDECL = 550,
     TAKEKITTRAYTYPEDECL = 551,
     TAKEKITTYPEDECL = 552,
     TAKEPARTTYPEDECL = 553,
     TESTANDSTEPTYPEDECL = 554,
     TIMESTYPEDECL = 555,
     TRUETYPEDECL = 556,
     UNORDEREDACTIONGROUPTYPEDECL = 557,
     VACUUMEFFECTORMULTICUPTYPEDECL = 558,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 559,
     VACUUMEFFECTORTYPEDECL = 560,
     VARSETTYPEDECL = 561,
     VARVALTYPEDECL = 562,
     VARIABLEDECLARATIONTYPEDECL = 563,
     VECTORTYPEDECL = 564,
     WHILEACTIONGROUPTYPEDECL = 565,
     WORKTABLETYPEDECL = 566
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingPlan *           XmlHeaderForKittingPlanVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlBoolean *                        XmlBooleanVal;
  XmlDateTime *                       XmlDateTimeVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlID *                             XmlIDVal;
  XmlIDREF *                          XmlIDREFVal;
  XmlNMTOKEN *                        XmlNMTOKENVal;
  XmlNonNegativeInteger *             XmlNonNegativeIntegerVal;
  XmlPositiveInteger *                XmlPositiveIntegerVal;
  XmlString *                         XmlStringVal;
  XmlToken *                          XmlTokenVal;

  KittingPlanFile *                   KittingPlanFileVal;

  ActionBaseType *                    ActionBaseTypeVal;
  ActionGroupBaseType *               ActionGroupBaseTypeVal;
  AndType *                           AndTypeVal;
  AngleUnitType *                     AngleUnitTypeVal;
  ArithmeticComparisonBooleanExpressionType * ArithmeticComparisonBooleanExpressionTypeVal;
  ArithmeticExpressionType *          ArithmeticExpressionTypeVal;
  AttachEndEffectorType *             AttachEndEffectorTypeVal;
  BinaryArithmeticExpressionType *    BinaryArithmeticExpressionTypeVal;
  BinaryBooleanExpressionType *       BinaryBooleanExpressionTypeVal;
  BooleanConstantType *               BooleanConstantTypeVal;
  BooleanExpressionType *             BooleanExpressionTypeVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  CreateKitType *                     CreateKitTypeVal;
  CylindricalShapeType *              CylindricalShapeTypeVal;
  DecimalType *                       DecimalTypeVal;
  DetachEndEffectorType *             DetachEndEffectorTypeVal;
  DivType *                           DivTypeVal;
  ElseType *                          ElseTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  EqualType *                         EqualTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  FalseType *                         FalseTypeVal;
  GreaterOrEqualType *                GreaterOrEqualTypeVal;
  GreaterType *                       GreaterTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
  IfActionGroupType *                 IfActionGroupTypeVal;
  InternalShapeType *                 InternalShapeTypeVal;
  KitDesignType *                     KitDesignTypeVal;
  KitTrayType *                       KitTrayTypeVal;
  KitType *                           KitTypeVal;
  KittingPlanType *                   KittingPlanTypeVal;
  KittingWorkstationType *            KittingWorkstationTypeVal;
  LargeBoxWithEmptyKitTraysType *     LargeBoxWithEmptyKitTraysTypeVal;
  LargeBoxWithKitsType *              LargeBoxWithKitsTypeVal;
  LargeContainerType *                LargeContainerTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  LessOrEqualType *                   LessOrEqualTypeVal;
  LessType *                          LessTypeVal;
  std::list<BoxVolumeType *> *        ListBoxVolumeTypeVal;
  std::list<EndEffectorHolderType *> * ListEndEffectorHolderTypeVal;
  std::list<KitDesignType *> *        ListKitDesignTypeVal;
  std::list<KitTrayType *> *          ListKitTrayTypeVal;
  std::list<KitType *> *              ListKitTypeVal;
  std::list<NumberedPlanElementType *> * ListNumberedPlanElementTypeVal;
  std::list<PartRefAndPoseType *> *   ListPartRefAndPoseTypeVal;
  std::list<PartType *> *             ListPartTypeVal;
  std::list<PhysicalLocationType *> * ListPhysicalLocationTypeVal;
  std::list<PlanElementBaseType *> *  ListPlanElementBaseTypeVal;
  std::list<SlotType *> *             ListSlotTypeVal;
  std::list<SolidObjectType *> *      ListSolidObjectTypeVal;
  std::list<StepWithPredecessorsType *> * ListStepWithPredecessorsTypeVal;
  std::list<StockKeepingUnitType *> * ListStockKeepingUnitTypeVal;
  std::list<TestAndStepType *> *      ListTestAndStepTypeVal;
  std::list<VariableDeclarationType *> * ListVariableDeclarationTypeVal;
  std::list<XmlIDREF *> *             ListXmlIDREFVal;
  std::list<XmlID *> *                ListXmlIDVal;
  std::list<XmlPositiveInteger *> *   ListXmlPositiveIntegerVal;
  LocatePartType *                    LocatePartTypeVal;
  MechanicalComponentType *           MechanicalComponentTypeVal;
  MinusType *                         MinusTypeVal;
  ModType *                           ModTypeVal;
  NegateType *                        NegateTypeVal;
  NoSkuObjectType *                   NoSkuObjectTypeVal;
  NotEqualType *                      NotEqualTypeVal;
  NotType *                           NotTypeVal;
  NumberedPlanElementType *           NumberedPlanElementTypeVal;
  OneOfActionGroupType *              OneOfActionGroupTypeVal;
  OrType *                            OrTypeVal;
  OrderedActionGroupType *            OrderedActionGroupTypeVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  PartType *                          PartTypeVal;
  PartiallyOrderedActionGroupType *   PartiallyOrderedActionGroupTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsVesselType *                   PartsVesselTypeVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
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
  RobotType *                         RobotTypeVal;
  SensorActionBaseType *              SensorActionBaseTypeVal;
  SkuObjectType *                     SkuObjectTypeVal;
  SlotType *                          SlotTypeVal;
  SolidObjectType *                   SolidObjectTypeVal;
  SomeOfActionGroupType *             SomeOfActionGroupTypeVal;
  StepWithPredecessorsType *          StepWithPredecessorsTypeVal;
  StockKeepingUnitType *              StockKeepingUnitTypeVal;
  TakeKitTrayType *                   TakeKitTrayTypeVal;
  TakeKitType *                       TakeKitTypeVal;
  TakePartType *                      TakePartTypeVal;
  TestAndStepType *                   TestAndStepTypeVal;
  TimesType *                         TimesTypeVal;
  TrueType *                          TrueTypeVal;
  UnorderedActionGroupType *          UnorderedActionGroupTypeVal;
  VacuumEffectorMultiCupType *        VacuumEffectorMultiCupTypeVal;
  VacuumEffectorSingleCupType *       VacuumEffectorSingleCupTypeVal;
  VacuumEffectorType *                VacuumEffectorTypeVal;
  VarSetType *                        VarSetTypeVal;
  VarValType *                        VarValTypeVal;
  VariableDeclarationType *           VariableDeclarationTypeVal;
  VectorType *                        VectorTypeVal;
  WeightUnitType *                    WeightUnitTypeVal;
  WhileActionGroupType *              WhileActionGroupTypeVal;
  WorkTableType *                     WorkTableTypeVal;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


