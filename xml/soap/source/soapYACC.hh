/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     ANGLEUNITEND = 271,
     ANGLEUNITSTART = 272,
     ANYORDERORDERINGCONSTRUCTEND = 273,
     ANYORDERORDERINGCONSTRUCTSTART = 274,
     ARRAYNUMBEREND = 275,
     ARRAYNUMBERSTART = 276,
     ARRAYRADIUSEND = 277,
     ARRAYRADIUSSTART = 278,
     ATTACHENDEFFECTOREND = 279,
     ATTACHENDEFFECTORSTART = 280,
     BASEEND = 281,
     BASESTART = 282,
     CAPACITYEND = 283,
     CAPACITYSTART = 284,
     CHANGINGSTATIONEND = 285,
     CHANGINGSTATIONSTART = 286,
     COUNTORDERINGCONSTRUCTEND = 287,
     COUNTORDERINGCONSTRUCTSTART = 288,
     CREATEKITEND = 289,
     CREATEKITSTART = 290,
     CUPDIAMETEREND = 291,
     CUPDIAMETERSTART = 292,
     DESCRIPTIONEND = 293,
     DESCRIPTIONSTART = 294,
     DESIGNNAMEEND = 295,
     DESIGNNAMESTART = 296,
     DETACHENDEFFECTOREND = 297,
     DETACHENDEFFECTORSTART = 298,
     DIAMETEREND = 299,
     DIAMETERSTART = 300,
     DOMAINEND = 301,
     DOMAINSTART = 302,
     EFFECTEND = 303,
     EFFECTSTART = 304,
     ENDEFFECTORCHANGINGSTATIONPARAMETEREND = 305,
     ENDEFFECTORCHANGINGSTATIONPARAMETERSTART = 306,
     ENDEFFECTORHOLDERPARAMETEREND = 307,
     ENDEFFECTORHOLDERPARAMETERSTART = 308,
     ENDEFFECTORHOLDEREND = 309,
     ENDEFFECTORHOLDERSTART = 310,
     ENDEFFECTORNAMEEND = 311,
     ENDEFFECTORNAMESTART = 312,
     ENDEFFECTORPARAMETEREND = 313,
     ENDEFFECTORPARAMETERSTART = 314,
     ENDEFFECTOREND = 315,
     ENDEFFECTORSTART = 316,
     EXISTORDERINGCONSTRUCTEND = 317,
     EXISTORDERINGCONSTRUCTSTART = 318,
     EXPRESSIONEND = 319,
     EXPRESSIONSTART = 320,
     EXTERNALSHAPEEND = 321,
     EXTERNALSHAPESTART = 322,
     F1EQUALF2END = 323,
     F1EQUALF2START = 324,
     F1GREATERF2END = 325,
     F1GREATERF2START = 326,
     F1GREATEROREQUALF2END = 327,
     F1GREATEROREQUALF2START = 328,
     F1LESSF2END = 329,
     F1LESSF2START = 330,
     F1LESSOREQUALF2END = 331,
     F1LESSOREQUALF2START = 332,
     F1NAMEEND = 333,
     F1NAMESTART = 334,
     F2NAMEEND = 335,
     F2NAMESTART = 336,
     FINISHEDEND = 337,
     FINISHEDSTART = 338,
     FUNCTIONNAMEEND = 339,
     FUNCTIONNAMESTART = 340,
     FUNCTIONOPERATIONEND = 341,
     FUNCTIONOPERATIONSTART = 342,
     FUNCTIONEND = 343,
     FUNCTIONSTART = 344,
     GRASPPOSEEND = 345,
     GRASPPOSESTART = 346,
     HASTOPEND = 347,
     HASTOPSTART = 348,
     HEIGHTEND = 349,
     HEIGHTSTART = 350,
     HELDOBJECTEND = 351,
     HELDOBJECTSTART = 352,
     IEND = 353,
     ISTART = 354,
     INCONTACTWITHEND = 355,
     INCONTACTWITHSTART = 356,
     INTERNALSHAPEEND = 357,
     INTERNALSHAPESTART = 358,
     JEND = 359,
     JSTART = 360,
     KEND = 361,
     KSTART = 362,
     KITDESIGNNAMEEND = 363,
     KITDESIGNNAMESTART = 364,
     KITDESIGNEND = 365,
     KITDESIGNSTART = 366,
     KITPARAMETEREND = 367,
     KITPARAMETERSTART = 368,
     KITTRAYPARAMETEREND = 369,
     KITTRAYPARAMETERSTART = 370,
     KITTRAYSKUNAMEEND = 371,
     KITTRAYSKUNAMESTART = 372,
     KITTRAYEND = 373,
     KITTRAYSTART = 374,
     KITEND = 375,
     KITSTART = 376,
     KITTINGWORKSTATIONEND = 377,
     KITTINGWORKSTATIONSTART = 378,
     LARGEBOXWITHEMPTYKITTRAYSPARAMETEREND = 379,
     LARGEBOXWITHEMPTYKITTRAYSPARAMETERSTART = 380,
     LARGEBOXWITHKITSPARAMETEREND = 381,
     LARGEBOXWITHKITSPARAMETERSTART = 382,
     LARGECONTAINEREND = 383,
     LARGECONTAINERSTART = 384,
     LENGTHUNITEND = 385,
     LENGTHUNITSTART = 386,
     LENGTHEND = 387,
     LENGTHSTART = 388,
     MAXIMUMLOADWEIGHTEND = 389,
     MAXIMUMLOADWEIGHTSTART = 390,
     MAXIMUMPOINTEND = 391,
     MAXIMUMPOINTSTART = 392,
     MINIMUMPOINTEND = 393,
     MINIMUMPOINTSTART = 394,
     MODELFILENAMEEND = 395,
     MODELFILENAMESTART = 396,
     MODELFORMATNAMEEND = 397,
     MODELFORMATNAMESTART = 398,
     MODELNAMEEND = 399,
     MODELNAMESTART = 400,
     NAMEEND = 401,
     NAMESTART = 402,
     NOTPREDICATENAMEEND = 403,
     NOTPREDICATENAMESTART = 404,
     OBJECTONTABLEEND = 405,
     OBJECTONTABLESTART = 406,
     OBJECTEND = 407,
     OBJECTSTART = 408,
     ONTOPWITHCONTACTEND = 409,
     ONTOPWITHCONTACTSTART = 410,
     ORIENTATIONSTANDARDDEVIATIONEND = 411,
     ORIENTATIONSTANDARDDEVIATIONSTART = 412,
     OTHEROBSTACLEEND = 413,
     OTHEROBSTACLESTART = 414,
     PARTNAMEEND = 415,
     PARTNAMESTART = 416,
     PARTPARAMETEREND = 417,
     PARTPARAMETERSTART = 418,
     PARTQUANTITYEND = 419,
     PARTQUANTITYSTART = 420,
     PARTREFANDPOSENAMEEND = 421,
     PARTREFANDPOSENAMESTART = 422,
     PARTREFANDPOSEEND = 423,
     PARTREFANDPOSESTART = 424,
     PARTSKUNAMEEND = 425,
     PARTSKUNAMESTART = 426,
     PARTEND = 427,
     PARTSTART = 428,
     PARTIALLYINEND = 429,
     PARTIALLYINSTART = 430,
     PARTSTRAYPARAMETEREND = 431,
     PARTSTRAYPARAMETERSTART = 432,
     POINTEND = 433,
     POINTSTART = 434,
     POSITIONINORDEREDLISTEND = 435,
     POSITIONINORDEREDLISTSTART = 436,
     POSITIONSTANDARDDEVIATIONEND = 437,
     POSITIONSTANDARDDEVIATIONSTART = 438,
     PRECONDITIONEND = 439,
     PRECONDITIONSTART = 440,
     PREDICATEGROUPELEMENTEND = 441,
     PREDICATEGROUPELEMENTSTART = 442,
     PREDICATENAMEEND = 443,
     PREDICATENAMESTART = 444,
     PREDICATEOCCURRENCEEND = 445,
     PREDICATEOCCURRENCESTART = 446,
     PREDICATEEND = 447,
     PREDICATESTART = 448,
     PRIMARYLOCATIONEND = 449,
     PRIMARYLOCATIONSTART = 450,
     PUTKITTRAYEND = 451,
     PUTKITTRAYSTART = 452,
     PUTKITEND = 453,
     PUTKITSTART = 454,
     PUTPARTEND = 455,
     PUTPARTSTART = 456,
     RCC8SETEND = 457,
     RCC8SETSTART = 458,
     REFOBJECTNAMEEND = 459,
     REFOBJECTNAMESTART = 460,
     REFERENCENAMEEND = 461,
     REFERENCENAMESTART = 462,
     REQUIREMENTEND = 463,
     REQUIREMENTSTART = 464,
     ROBOTPARAMETEREND = 465,
     ROBOTPARAMETERSTART = 466,
     ROBOTEND = 467,
     ROBOTSTART = 468,
     SOAPEND = 469,
     SOAPSTART = 470,
     SECONDARYLOCATIONEND = 471,
     SECONDARYLOCATIONSTART = 472,
     SERIALNUMBEREND = 473,
     SERIALNUMBERSTART = 474,
     SKUNAMEEND = 475,
     SKUNAMESTART = 476,
     SKUEND = 477,
     SKUSTART = 478,
     SLOTEND = 479,
     SLOTSTART = 480,
     STATERELATIONNAMEEND = 481,
     STATERELATIONNAMESTART = 482,
     TAKEKITTRAYEND = 483,
     TAKEKITTRAYSTART = 484,
     TAKEKITEND = 485,
     TAKEKITSTART = 486,
     TAKEPARTEND = 487,
     TAKEPARTSTART = 488,
     TARGETNAMEEND = 489,
     TARGETNAMESTART = 490,
     TIMESTAMPEND = 491,
     TIMESTAMPSTART = 492,
     UNDERWITHCONTACTEND = 493,
     UNDERWITHCONTACTSTART = 494,
     VALUEEND = 495,
     VALUESTART = 496,
     VARIABLEEND = 497,
     VARIABLESTART = 498,
     WEIGHTUNITEND = 499,
     WEIGHTUNITSTART = 500,
     WEIGHTEND = 501,
     WEIGHTSTART = 502,
     WIDTHEND = 503,
     WIDTHSTART = 504,
     WORKTABLEPARAMETEREND = 505,
     WORKTABLEPARAMETERSTART = 506,
     WORKVOLUMEEND = 507,
     WORKVOLUMESTART = 508,
     XAXISEND = 509,
     XAXISSTART = 510,
     XEND = 511,
     XSTART = 512,
     YEND = 513,
     YSTART = 514,
     ZAXISEND = 515,
     ZAXISSTART = 516,
     ZEND = 517,
     ZSTART = 518,
     ACTIONBASETYPEDECL = 519,
     ANYORDERORDERINGCONSTRUCTTYPEDECL = 520,
     ATTACHENDEFFECTORTYPEDECL = 521,
     BOXVOLUMETYPEDECL = 522,
     BOXYSHAPETYPEDECL = 523,
     COUNTORDERINGCONSTRUCTTYPEDECL = 524,
     CREATEKITTYPEDECL = 525,
     CYLINDRICALSHAPETYPEDECL = 526,
     DETACHENDEFFECTORTYPEDECL = 527,
     DOMAINTYPEDECL = 528,
     EFFECTTYPEDECL = 529,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 530,
     ENDEFFECTORHOLDERTYPEDECL = 531,
     ENDEFFECTORTYPEDECL = 532,
     EXISTORDERINGCONSTRUCTTYPEDECL = 533,
     EXTERNALSHAPETYPEDECL = 534,
     FUNCTIONBOOLEANEXPRESSIONTYPEDECL = 535,
     FUNCTIONOPERATIONTYPEDECL = 536,
     FUNCTIONTODECIMALBOOLTYPEDECL = 537,
     FUNCTIONTODECIMALEQUALTYPEDECL = 538,
     FUNCTIONTODECIMALGREATEROREQUALTYPEDECL = 539,
     FUNCTIONTODECIMALGREATERTYPEDECL = 540,
     FUNCTIONTODECIMALLESSOREQUALTYPEDECL = 541,
     FUNCTIONTODECIMALLESSTYPEDECL = 542,
     FUNCTIONTOFUNCTIONBOOLTYPEDECL = 543,
     FUNCTIONTOFUNCTIONEQUALTYPEDECL = 544,
     FUNCTIONTOFUNCTIONGREATEROREQUALTYPEDECL = 545,
     FUNCTIONTOFUNCTIONGREATERTYPEDECL = 546,
     FUNCTIONTOFUNCTIONLESSOREQUALTYPEDECL = 547,
     FUNCTIONTOFUNCTIONLESSTYPEDECL = 548,
     FUNCTIONTYPEDECL = 549,
     GRIPPEREFFECTORTYPEDECL = 550,
     HUMANTYPEDECL = 551,
     INCONTACTWITHTYPEDECL = 552,
     INTERNALSHAPETYPEDECL = 553,
     KITDESIGNTYPEDECL = 554,
     KITTRAYTYPEDECL = 555,
     KITTYPEDECL = 556,
     KITTINGWORKSTATIONTYPEDECL = 557,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 558,
     LARGEBOXWITHKITSTYPEDECL = 559,
     LARGECONTAINERTYPEDECL = 560,
     MECHANICALCOMPONENTTYPEDECL = 561,
     NOSKUOBJECTTYPEDECL = 562,
     ONTOPWITHCONTACTTYPEDECL = 563,
     ORDEREDLISTORDERINGCONSTRUCTTYPEDECL = 564,
     ORDERINGCONSTRUCTTYPEDECL = 565,
     PARTREFANDPOSETYPEDECL = 566,
     PARTTYPEDECL = 567,
     PARTIALLYINTYPEDECL = 568,
     PARTSBINTYPEDECL = 569,
     PARTSTRAYTYPEDECL = 570,
     PARTSVESSELTYPEDECL = 571,
     PHYSICALLOCATIONTYPEDECL = 572,
     POINTTYPEDECL = 573,
     POSELOCATIONINTYPEDECL = 574,
     POSELOCATIONONTYPEDECL = 575,
     POSELOCATIONTYPEDECL = 576,
     POSEONLYLOCATIONTYPEDECL = 577,
     PRECONDITIONTYPEDECL = 578,
     PREDICATEGROUPELEMENTTYPEDECL = 579,
     PREDICATETYPEDECL = 580,
     PUTKITTRAYTYPEDECL = 581,
     PUTKITTYPEDECL = 582,
     PUTPARTTYPEDECL = 583,
     RELATIVELOCATIONINTYPEDECL = 584,
     RELATIVELOCATIONONTYPEDECL = 585,
     RELATIVELOCATIONTYPEDECL = 586,
     ROBOTACTIONBASETYPEDECL = 587,
     ROBOTTYPEDECL = 588,
     SOAPTYPEDECL = 589,
     SHAPEDESIGNTYPEDECL = 590,
     SKUOBJECTTYPEDECL = 591,
     SLOTTYPEDECL = 592,
     STATERELATIONTYPEDECL = 593,
     STOCKKEEPINGUNITTYPEDECL = 594,
     TAKEKITTRAYTYPEDECL = 595,
     TAKEKITTYPEDECL = 596,
     TAKEPARTTYPEDECL = 597,
     UNDERWITHCONTACTTYPEDECL = 598,
     VACUUMEFFECTORMULTICUPTYPEDECL = 599,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 600,
     VACUUMEFFECTORTYPEDECL = 601,
     VECTORTYPEDECL = 602,
     WORKTABLETYPEDECL = 603
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForSOAP *                  XmlHeaderForSOAPVal;
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

  SOAPFile *                          SOAPFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  AnyOrderOrderingConstructType *     AnyOrderOrderingConstructTypeVal;
  AttachEndEffectorType *             AttachEndEffectorTypeVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  CountOrderingConstructType *        CountOrderingConstructTypeVal;
  CreateKitType *                     CreateKitTypeVal;
  CylindricalShapeType *              CylindricalShapeTypeVal;
  DetachEndEffectorType *             DetachEndEffectorTypeVal;
  DomainType *                        DomainTypeVal;
  EffectType *                        EffectTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExistOrderingConstructType *        ExistOrderingConstructTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  FunctionOperationType *             FunctionOperationTypeVal;
  FunctionToFunctionEqualType *       FunctionToFunctionEqualTypeVal;
  FunctionToFunctionGreaterOrEqualType * FunctionToFunctionGreaterOrEqualTypeVal;
  FunctionToFunctionGreaterType *     FunctionToFunctionGreaterTypeVal;
  FunctionToFunctionLessOrEqualType * FunctionToFunctionLessOrEqualTypeVal;
  FunctionToFunctionLessType *        FunctionToFunctionLessTypeVal;
  FunctionType *                      FunctionTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
  InContactWithType *                 InContactWithTypeVal;
  InternalShapeType *                 InternalShapeTypeVal;
  KitDesignType *                     KitDesignTypeVal;
  KitTrayType *                       KitTrayTypeVal;
  KitType *                           KitTypeVal;
  KittingWorkstationType *            KittingWorkstationTypeVal;
  LargeBoxWithEmptyKitTraysType *     LargeBoxWithEmptyKitTraysTypeVal;
  LargeBoxWithKitsType *              LargeBoxWithKitsTypeVal;
  LargeContainerType *                LargeContainerTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  std::list<BoxVolumeType *> *        ListBoxVolumeTypeVal;
  std::list<EndEffectorHolderType *> * ListEndEffectorHolderTypeVal;
  std::list<FunctionToFunctionEqualType *> * ListFunctionToFunctionEqualTypeVal;
  std::list<FunctionToFunctionGreaterOrEqualType *> * ListFunctionToFunctionGreaterOrEqualTypeVal;
  std::list<FunctionToFunctionGreaterType *> * ListFunctionToFunctionGreaterTypeVal;
  std::list<FunctionToFunctionLessOrEqualType *> * ListFunctionToFunctionLessOrEqualTypeVal;
  std::list<FunctionToFunctionLessType *> * ListFunctionToFunctionLessTypeVal;
  std::list<FunctionType *> *         ListFunctionTypeVal;
  std::list<KitDesignType *> *        ListKitDesignTypeVal;
  std::list<KitTrayType *> *          ListKitTrayTypeVal;
  std::list<KitType *> *              ListKitTypeVal;
  std::list<PartRefAndPoseType *> *   ListPartRefAndPoseTypeVal;
  std::list<PartType *> *             ListPartTypeVal;
  std::list<PhysicalLocationType *> * ListPhysicalLocationTypeVal;
  std::list<PredicateGroupElementType *> * ListPredicateGroupElementTypeVal;
  std::list<PredicateType *> *        ListPredicateTypeVal;
  std::list<SlotType *> *             ListSlotTypeVal;
  std::list<SolidObjectType *> *      ListSolidObjectTypeVal;
  std::list<StockKeepingUnitType *> * ListStockKeepingUnitTypeVal;
  std::list<XmlIDREF *> *             ListXmlIDREFVal;
  std::list<XmlNMTOKEN *> *           ListXmlNMTOKENVal;
  MechanicalComponentType *           MechanicalComponentTypeVal;
  NoSkuObjectType *                   NoSkuObjectTypeVal;
  OnTopWithContactType *              OnTopWithContactTypeVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  PartType *                          PartTypeVal;
  PartiallyInType *                   PartiallyInTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsVesselType *                   PartsVesselTypeVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  PreconditionType *                  PreconditionTypeVal;
  PredicateGroupElementType *         PredicateGroupElementTypeVal;
  PredicateType *                     PredicateTypeVal;
  PutKitTrayType *                    PutKitTrayTypeVal;
  PutKitType *                        PutKitTypeVal;
  PutPartType *                       PutPartTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotType *                         RobotTypeVal;
  SOAPType *                          SOAPTypeVal;
  SkuObjectType *                     SkuObjectTypeVal;
  SlotType *                          SlotTypeVal;
  SolidObjectType *                   SolidObjectTypeVal;
  StockKeepingUnitType *              StockKeepingUnitTypeVal;
  TakeKitTrayType *                   TakeKitTrayTypeVal;
  TakeKitType *                       TakeKitTypeVal;
  TakePartType *                      TakePartTypeVal;
  UnderWithContactType *              UnderWithContactTypeVal;
  VacuumEffectorMultiCupType *        VacuumEffectorMultiCupTypeVal;
  VacuumEffectorSingleCupType *       VacuumEffectorSingleCupTypeVal;
  VacuumEffectorType *                VacuumEffectorTypeVal;
  VectorType *                        VectorTypeVal;
  WeightUnitType *                    WeightUnitTypeVal;
  WorkTableType *                     WorkTableTypeVal;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


