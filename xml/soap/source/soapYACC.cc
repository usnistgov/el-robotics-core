/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */



#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#ifdef OWL
#include "owlSoapClasses.hh"
#else
#include "soapClasses.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

SOAPFile * SOAPTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1067

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  349
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  303
/* YYNRULES -- Number of rules.  */
#define YYNRULES  372
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   603

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    16,    18,    20,    22,    24,
      26,    28,    30,    32,    34,    39,    46,    47,    53,    54,
      60,    61,    67,    77,    81,    85,    90,    91,    97,   101,
     110,   114,   115,   121,   122,   128,   129,   130,   136,   137,
     143,   153,   157,   158,   164,   180,   184,   196,   200,   201,
     207,   216,   217,   223,   231,   235,   236,   242,   243,   249,
     251,   253,   255,   256,   260,   261,   267,   275,   276,   280,
     284,   288,   292,   296,   300,   301,   307,   308,   314,   315,
     321,   322,   328,   329,   330,   336,   342,   343,   347,   352,
     357,   362,   367,   372,   378,   382,   383,   387,   388,   394,
     395,   401,   402,   406,   407,   413,   417,   421,   423,   425,
     426,   430,   431,   437,   438,   444,   445,   451,   456,   460,
     461,   467,   468,   474,   475,   481,   488,   492,   496,   508,
     512,   528,   532,   533,   539,   540,   546,   553,   557,   558,
     564,   565,   571,   573,   576,   577,   580,   581,   584,   585,
     588,   589,   592,   593,   596,   597,   600,   602,   605,   607,
     610,   611,   614,   615,   618,   619,   622,   623,   626,   629,
     631,   632,   635,   638,   640,   641,   644,   647,   649,   650,
     653,   656,   658,   661,   663,   666,   668,   669,   672,   675,
     677,   678,   681,   684,   686,   689,   691,   692,   698,   702,
     709,   713,   714,   720,   721,   727,   728,   729,   735,   736,
     742,   743,   749,   753,   757,   761,   765,   766,   767,   773,
     777,   778,   779,   785,   786,   792,   793,   799,   800,   806,
     813,   817,   818,   824,   831,   835,   839,   843,   844,   850,
     852,   854,   856,   858,   860,   866,   870,   872,   874,   876,
     877,   878,   884,   895,   899,   905,   909,   910,   916,   917,
     923,   928,   932,   936,   944,   948,   957,   961,   971,   975,
     976,   982,   983,   989,   990,   996,   997,  1003,  1004,  1010,
    1021,  1025,  1034,  1038,  1039,  1045,  1046,  1052,  1056,  1061,
    1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,
    1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1102,
    1103,  1109,  1117,  1127,  1131,  1140,  1144,  1154,  1158,  1159,
    1160,  1166,  1167,  1168,  1174,  1178,  1182,  1183,  1189,  1190,
    1196,  1202,  1203,  1209,  1210,  1216,  1217,  1223,  1224,  1230,
    1234,  1238,  1239,  1245,  1246,  1252,  1256,  1257,  1263,  1273,
    1282,  1292,  1301,  1313,  1321,  1329,  1342,  1359,  1369,  1381,
    1389,  1397,  1405,  1416,  1427,  1438,  1449,  1460,  1467,  1474,
    1486,  1502,  1516
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     350,     0,    -1,   362,   215,   351,   580,   214,    -1,    12,
      11,   352,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     9,    13,    10,     7,    -1,     9,
      13,    10,     5,    10,     7,    -1,    -1,    17,     6,   364,
       4,    16,    -1,    -1,    21,     6,   366,   360,    20,    -1,
      -1,    23,     6,   368,     4,    22,    -1,     6,   516,   382,
     576,   403,   397,   394,   552,   393,    -1,    25,   369,    24,
      -1,    27,   508,    26,    -1,     6,   516,   507,   509,    -1,
      -1,    29,     6,   374,   360,    28,    -1,    31,   396,    30,
      -1,     6,   516,   382,   455,   457,   616,   552,   393,    -1,
      35,   376,    34,    -1,    -1,    37,     6,   379,     4,    36,
      -1,    -1,    39,     6,   381,   361,    38,    -1,    -1,    -1,
      39,     6,   383,   361,    38,    -1,    -1,    41,     6,   385,
     357,    40,    -1,     6,   516,   382,   576,   403,   397,   394,
     552,   393,    -1,    43,   386,    42,    -1,    -1,    45,     6,
     389,     4,    44,    -1,     6,   516,   499,   503,   498,   485,
     370,   377,   387,   598,   596,   594,   567,   565,   563,    -1,
      47,   390,    46,    -1,     6,   516,   496,   489,   424,   427,
     483,   480,   482,   481,   484,    -1,    49,   392,    48,    -1,
      -1,    51,     6,   395,   358,    50,    -1,     6,   516,   561,
     500,   446,   410,   371,   478,    -1,    -1,    53,     6,   398,
     358,    52,    -1,     6,   516,   561,   500,   446,   410,   406,
      -1,    55,   399,    54,    -1,    -1,    57,     6,   402,   357,
      56,    -1,    -1,    59,     6,   404,   358,    58,    -1,   631,
      -1,   649,    -1,   650,    -1,    -1,    61,   405,    60,    -1,
      -1,    65,     6,   408,   358,    64,    -1,     6,   516,   380,
     435,   512,   510,   514,    -1,    -1,    67,   409,    66,    -1,
      69,   428,    68,    -1,    71,   430,    70,    -1,    73,   429,
      72,    -1,    75,   432,    74,    -1,    77,   431,    76,    -1,
      -1,    79,     6,   417,   357,    78,    -1,    -1,    81,     6,
     419,   357,    80,    -1,    -1,    83,     6,   421,   353,    82,
      -1,    -1,    85,     6,   423,   357,    84,    -1,    -1,    -1,
      85,     6,   425,   357,    84,    -1,     6,   516,   422,   407,
     605,    -1,    -1,    87,   426,    86,    -1,     6,   516,   416,
     418,    -1,     6,   516,   416,   418,    -1,     6,   516,   416,
     418,    -1,     6,   516,   416,   418,    -1,     6,   516,   416,
     418,    -1,     6,   516,   382,   572,   599,    -1,    89,   433,
      88,    -1,    -1,    91,   548,    90,    -1,    -1,    93,     6,
     437,   353,    92,    -1,    -1,    95,     6,   439,     4,    94,
      -1,    -1,    97,   589,    96,    -1,    -1,    99,     6,   442,
     355,    98,    -1,     6,   516,   568,    -1,   101,   443,   100,
      -1,   627,    -1,   628,    -1,    -1,   103,   445,   102,    -1,
      -1,   105,     6,   448,   355,   104,    -1,    -1,   107,     6,
     450,   355,   106,    -1,    -1,   109,     6,   452,   357,   108,
      -1,     6,   516,   459,   493,    -1,   111,   453,   110,    -1,
      -1,   113,     6,   456,   358,   112,    -1,    -1,   115,     6,
     458,   358,   114,    -1,    -1,   117,     6,   460,   357,   116,
      -1,     6,   516,   561,   500,   584,   582,    -1,   119,   461,
     118,    -1,   119,   461,   118,    -1,     6,   516,   561,   500,
     446,   410,   384,   462,   494,   502,   420,    -1,   121,   464,
     120,    -1,     6,   516,   561,   500,   446,   410,   363,   375,
     486,   474,   491,   492,   579,   501,   610,    -1,   123,   466,
     122,    -1,    -1,   125,     6,   469,   358,   124,    -1,    -1,
     127,     6,   471,   358,   126,    -1,     6,   516,   561,   500,
     584,   582,    -1,   129,   472,   128,    -1,    -1,   131,     6,
     475,     4,   130,    -1,    -1,   133,     6,   477,     4,   132,
      -1,   400,    -1,   478,   400,    -1,    -1,   479,   401,    -1,
      -1,   480,   411,    -1,    -1,   481,   412,    -1,    -1,   482,
     413,    -1,    -1,   483,   414,    -1,    -1,   484,   415,    -1,
     434,    -1,   485,   434,    -1,   454,    -1,   486,   454,    -1,
      -1,   487,   463,    -1,    -1,   488,   465,    -1,    -1,   489,
     518,    -1,    -1,   490,   520,    -1,   491,   521,    -1,   521,
      -1,    -1,   492,   526,    -1,   493,   536,    -1,   536,    -1,
      -1,   494,   540,    -1,   495,   554,    -1,   554,    -1,    -1,
     496,   555,    -1,   497,   557,    -1,   557,    -1,   498,   560,
      -1,   560,    -1,   499,   574,    -1,   574,    -1,    -1,   500,
     581,    -1,   501,   586,    -1,   586,    -1,    -1,   502,   588,
      -1,   503,   607,    -1,   607,    -1,   504,   618,    -1,   618,
      -1,    -1,   135,     6,   506,     4,   134,    -1,   137,   546,
     136,    -1,     6,   516,   561,   500,   446,   410,    -1,   139,
     546,   138,    -1,    -1,   141,     6,   511,   361,   140,    -1,
      -1,   143,     6,   513,   361,   142,    -1,    -1,    -1,   145,
       6,   515,   361,   144,    -1,    -1,   147,     6,   517,   356,
     146,    -1,    -1,   149,     6,   519,   357,   148,    -1,   151,
     589,   150,    -1,   153,   589,   152,    -1,     6,   516,   568,
      -1,   155,   522,   154,    -1,    -1,    -1,   157,     6,   525,
       4,   156,    -1,   159,   372,   158,    -1,    -1,    -1,   161,
       6,   528,   357,   160,    -1,    -1,   163,     6,   530,   358,
     162,    -1,    -1,   165,     6,   532,   359,   164,    -1,    -1,
     167,     6,   534,   357,   166,    -1,     6,   516,   584,   547,
     619,   624,    -1,   169,   535,   168,    -1,    -1,   171,     6,
     538,   357,   170,    -1,     6,   516,   561,   500,   584,   582,
      -1,   173,   539,   172,    -1,     6,   516,   568,    -1,   175,
     541,   174,    -1,    -1,   177,     6,   544,   358,   176,    -1,
     643,    -1,   644,    -1,   645,    -1,   646,    -1,   647,    -1,
       6,   516,   620,   622,   625,    -1,   179,   546,   178,    -1,
     643,    -1,   644,    -1,   645,    -1,    -1,    -1,   183,     6,
     550,     4,   182,    -1,     6,   516,   497,   424,   427,   483,
     480,   482,   481,   484,    -1,   185,   551,   184,    -1,     6,
     516,   572,   599,   590,    -1,   187,   553,   186,    -1,    -1,
     189,     6,   556,   357,   188,    -1,    -1,   189,     6,   558,
     357,   188,    -1,     6,   516,   382,   495,    -1,   193,   559,
     192,    -1,   195,   545,   194,    -1,     6,   516,   382,   576,
     457,   552,   393,    -1,   197,   562,   196,    -1,     6,   516,
     382,   576,   455,   470,   552,   393,    -1,   199,   564,   198,
      -1,     6,   516,   382,   576,   529,   455,   543,   552,   393,
      -1,   201,   566,   200,    -1,    -1,   203,     6,   569,   361,
     202,    -1,    -1,   205,     6,   571,   357,   204,    -1,    -1,
     207,     6,   573,   358,   206,    -1,    -1,   209,     6,   575,
     358,   208,    -1,    -1,   211,     6,   577,   358,   210,    -1,
       6,   516,   561,   500,   446,   410,   380,   406,   505,   504,
      -1,   213,   578,   212,    -1,     6,   516,   467,   391,   444,
     604,   542,   523,    -1,   217,   545,   216,    -1,    -1,   219,
       6,   583,   358,   218,    -1,    -1,   221,     6,   585,   357,
     220,    -1,   223,   592,   222,    -1,     6,   516,   533,   527,
      -1,   225,   587,   224,    -1,   629,    -1,   630,    -1,   631,
      -1,   632,    -1,   633,    -1,   634,    -1,   635,    -1,   636,
      -1,   637,    -1,   638,    -1,   639,    -1,   640,    -1,   641,
      -1,   642,    -1,   648,    -1,   649,    -1,   650,    -1,   651,
      -1,    -1,    -1,   227,     6,   591,   357,   226,    -1,     6,
     516,   380,   446,   410,   612,   479,    -1,     6,   516,   382,
     576,   457,   468,   403,   552,   393,    -1,   229,   593,   228,
      -1,     6,   516,   382,   576,   455,   403,   552,   393,    -1,
     231,   595,   230,    -1,     6,   516,   382,   576,   529,   543,
     403,   552,   393,    -1,   233,   597,   232,    -1,    -1,    -1,
     235,     6,   600,   358,   234,    -1,    -1,    -1,   237,     6,
     602,   354,   236,    -1,     6,   516,   568,    -1,   239,   603,
     238,    -1,    -1,   241,     6,   606,   360,   240,    -1,    -1,
     243,     6,   608,   358,   242,    -1,     6,   516,   441,   447,
     449,    -1,    -1,   245,     6,   611,     4,   244,    -1,    -1,
     247,     6,   613,     4,   246,    -1,    -1,   249,     6,   615,
       4,   248,    -1,    -1,   251,     6,   617,   358,   250,    -1,
     253,   372,   252,    -1,   255,   609,   254,    -1,    -1,   257,
       6,   621,   355,   256,    -1,    -1,   259,     6,   623,   355,
     258,    -1,   261,   609,   260,    -1,    -1,   263,     6,   626,
     355,   262,    -1,   268,     6,   516,   380,   435,   476,   614,
     438,   436,    -1,   271,     6,   516,   380,   435,   388,   438,
     436,    -1,   275,     6,   516,   561,   500,   446,   410,   371,
     478,    -1,   276,     6,   516,   561,   500,   446,   410,   406,
      -1,   295,     6,   516,   561,   500,   446,   410,   380,   612,
     505,   440,    -1,   296,     6,   516,   561,   500,   446,   410,
      -1,   300,     6,   516,   561,   500,   584,   582,    -1,   301,
       6,   516,   561,   500,   446,   410,   384,   462,   494,   502,
     420,    -1,   302,     6,   516,   561,   500,   446,   410,   363,
     375,   486,   474,   491,   492,   579,   501,   610,    -1,   303,
       6,   516,   561,   500,   446,   410,   473,   487,    -1,   304,
       6,   516,   561,   500,   446,   410,   473,   488,   451,   373,
      -1,   305,     6,   516,   561,   500,   584,   582,    -1,   306,
       6,   516,   561,   500,   446,   410,    -1,   312,     6,   516,
     561,   500,   584,   582,    -1,   314,     6,   516,   561,   500,
     584,   582,   537,   531,   494,    -1,   315,     6,   516,   561,
     500,   584,   582,   537,   531,   494,    -1,   319,     6,   516,
     570,   601,   547,   619,   624,   549,   524,    -1,   320,     6,
     516,   570,   601,   547,   619,   624,   549,   524,    -1,   322,
       6,   516,   570,   601,   547,   619,   624,   549,   524,    -1,
     329,     6,   516,   570,   601,   380,    -1,   330,     6,   516,
     570,   601,   380,    -1,   333,     6,   516,   561,   500,   446,
     410,   380,   406,   505,   504,    -1,   344,     6,   516,   561,
     500,   446,   410,   380,   612,   505,   440,   378,   476,   365,
     367,    -1,   345,     6,   516,   561,   500,   446,   410,   380,
     612,   505,   440,   378,   476,    -1,   348,     6,   516,   561,
     500,   446,   410,   490,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   742,   742,   752,   757,   769,   777,   785,   793,   801,
     809,   817,   825,   833,   841,   846,   862,   862,   883,   883,
     889,   889,   898,   907,   913,   918,   924,   924,   930,   948,
     956,   961,   961,   970,   970,   977,   978,   978,   984,   984,
     990,   999,  1005,  1005,  1013,  1026,  1031,  1043,  1048,  1048,
    1054,  1064,  1064,  1070,  1079,  1085,  1085,  1091,  1091,  1097,
    1099,  1101,  1107,  1108,  1124,  1124,  1130,  1138,  1139,  1144,
    1149,  1154,  1160,  1165,  1171,  1171,  1176,  1176,  1181,  1181,
    1186,  1186,  1193,  1194,  1194,  1200,  1207,  1208,  1214,  1219,
    1224,  1229,  1234,  1239,  1245,  1251,  1252,  1257,  1257,  1262,
    1262,  1271,  1272,  1277,  1277,  1282,  1287,  1292,  1294,  1300,
    1301,  1306,  1306,  1311,  1311,  1316,  1316,  1322,  1328,  1333,
    1333,  1339,  1339,  1345,  1345,  1351,  1358,  1363,  1368,  1378,
    1383,  1396,  1402,  1402,  1408,  1408,  1414,  1421,  1426,  1426,
    1435,  1435,  1443,  1446,  1454,  1455,  1462,  1463,  1471,  1472,
    1480,  1481,  1489,  1490,  1498,  1499,  1506,  1509,  1515,  1518,
    1525,  1526,  1533,  1534,  1541,  1542,  1550,  1551,  1558,  1561,
    1568,  1569,  1576,  1580,  1587,  1588,  1594,  1598,  1605,  1606,
    1612,  1615,  1621,  1624,  1630,  1633,  1640,  1641,  1648,  1651,
    1658,  1659,  1665,  1668,  1674,  1677,  1683,  1683,  1692,  1697,
    1705,  1710,  1710,  1716,  1716,  1723,  1724,  1724,  1729,  1729,
    1734,  1734,  1740,  1745,  1750,  1755,  1761,  1762,  1762,  1771,
    1777,  1778,  1778,  1783,  1783,  1789,  1789,  1795,  1795,  1801,
    1807,  1812,  1812,  1818,  1825,  1830,  1835,  1840,  1840,  1846,
    1848,  1850,  1852,  1854,  1859,  1865,  1870,  1872,  1874,  1886,
    1887,  1887,  1896,  1908,  1913,  1919,  1925,  1925,  1931,  1931,
    1943,  1954,  1959,  1964,  1971,  1976,  1984,  1989,  1997,  2002,
    2002,  2007,  2007,  2013,  2013,  2019,  2019,  2025,  2025,  2031,
    2042,  2047,  2056,  2062,  2062,  2068,  2068,  2073,  2078,  2084,
    2089,  2091,  2093,  2095,  2097,  2099,  2101,  2103,  2105,  2107,
    2109,  2111,  2113,  2115,  2117,  2119,  2121,  2123,  2129,  2130,
    2130,  2136,  2144,  2153,  2158,  2166,  2171,  2179,  2185,  2186,
    2186,  2193,  2194,  2194,  2200,  2205,  2210,  2210,  2216,  2216,
    2221,  2227,  2227,  2236,  2236,  2244,  2244,  2252,  2252,  2258,
    2263,  2268,  2268,  2273,  2273,  2278,  2283,  2283,  2288,  2298,
    2308,  2321,  2333,  2347,  2358,  2368,  2381,  2397,  2409,  2422,
    2432,  2443,  2453,  2465,  2477,  2488,  2499,  2510,  2519,  2528,
    2542,  2558,  2573
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BAD", "DATASTRING", "ENCODING",
  "ENDITEM", "ENDVERSION", "SCHEMALOCATION", "STARTVERSION",
  "TERMINALSTRING", "XMLNSPREFIX", "XMLNSTARGET", "XMLVERSION", "A1END",
  "A1START", "ANGLEUNITEND", "ANGLEUNITSTART",
  "ANYORDERORDERINGCONSTRUCTEND", "ANYORDERORDERINGCONSTRUCTSTART",
  "ARRAYNUMBEREND", "ARRAYNUMBERSTART", "ARRAYRADIUSEND",
  "ARRAYRADIUSSTART", "ATTACHENDEFFECTOREND", "ATTACHENDEFFECTORSTART",
  "BASEEND", "BASESTART", "CAPACITYEND", "CAPACITYSTART",
  "CHANGINGSTATIONEND", "CHANGINGSTATIONSTART",
  "COUNTORDERINGCONSTRUCTEND", "COUNTORDERINGCONSTRUCTSTART",
  "CREATEKITEND", "CREATEKITSTART", "CUPDIAMETEREND", "CUPDIAMETERSTART",
  "DESCRIPTIONEND", "DESCRIPTIONSTART", "DESIGNNAMEEND", "DESIGNNAMESTART",
  "DETACHENDEFFECTOREND", "DETACHENDEFFECTORSTART", "DIAMETEREND",
  "DIAMETERSTART", "DOMAINEND", "DOMAINSTART", "EFFECTEND", "EFFECTSTART",
  "ENDEFFECTORCHANGINGSTATIONPARAMETEREND",
  "ENDEFFECTORCHANGINGSTATIONPARAMETERSTART",
  "ENDEFFECTORHOLDERPARAMETEREND", "ENDEFFECTORHOLDERPARAMETERSTART",
  "ENDEFFECTORHOLDEREND", "ENDEFFECTORHOLDERSTART", "ENDEFFECTORNAMEEND",
  "ENDEFFECTORNAMESTART", "ENDEFFECTORPARAMETEREND",
  "ENDEFFECTORPARAMETERSTART", "ENDEFFECTOREND", "ENDEFFECTORSTART",
  "EXISTORDERINGCONSTRUCTEND", "EXISTORDERINGCONSTRUCTSTART",
  "EXPRESSIONEND", "EXPRESSIONSTART", "EXTERNALSHAPEEND",
  "EXTERNALSHAPESTART", "F1EQUALF2END", "F1EQUALF2START", "F1GREATERF2END",
  "F1GREATERF2START", "F1GREATEROREQUALF2END", "F1GREATEROREQUALF2START",
  "F1LESSF2END", "F1LESSF2START", "F1LESSOREQUALF2END",
  "F1LESSOREQUALF2START", "F1NAMEEND", "F1NAMESTART", "F2NAMEEND",
  "F2NAMESTART", "FINISHEDEND", "FINISHEDSTART", "FUNCTIONNAMEEND",
  "FUNCTIONNAMESTART", "FUNCTIONOPERATIONEND", "FUNCTIONOPERATIONSTART",
  "FUNCTIONEND", "FUNCTIONSTART", "GRASPPOSEEND", "GRASPPOSESTART",
  "HASTOPEND", "HASTOPSTART", "HEIGHTEND", "HEIGHTSTART", "HELDOBJECTEND",
  "HELDOBJECTSTART", "IEND", "ISTART", "INCONTACTWITHEND",
  "INCONTACTWITHSTART", "INTERNALSHAPEEND", "INTERNALSHAPESTART", "JEND",
  "JSTART", "KEND", "KSTART", "KITDESIGNNAMEEND", "KITDESIGNNAMESTART",
  "KITDESIGNEND", "KITDESIGNSTART", "KITPARAMETEREND", "KITPARAMETERSTART",
  "KITTRAYPARAMETEREND", "KITTRAYPARAMETERSTART", "KITTRAYSKUNAMEEND",
  "KITTRAYSKUNAMESTART", "KITTRAYEND", "KITTRAYSTART", "KITEND",
  "KITSTART", "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART",
  "LARGEBOXWITHEMPTYKITTRAYSPARAMETEREND",
  "LARGEBOXWITHEMPTYKITTRAYSPARAMETERSTART",
  "LARGEBOXWITHKITSPARAMETEREND", "LARGEBOXWITHKITSPARAMETERSTART",
  "LARGECONTAINEREND", "LARGECONTAINERSTART", "LENGTHUNITEND",
  "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART", "MAXIMUMLOADWEIGHTEND",
  "MAXIMUMLOADWEIGHTSTART", "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART",
  "MINIMUMPOINTEND", "MINIMUMPOINTSTART", "MODELFILENAMEEND",
  "MODELFILENAMESTART", "MODELFORMATNAMEEND", "MODELFORMATNAMESTART",
  "MODELNAMEEND", "MODELNAMESTART", "NAMEEND", "NAMESTART",
  "NOTPREDICATENAMEEND", "NOTPREDICATENAMESTART", "OBJECTONTABLEEND",
  "OBJECTONTABLESTART", "OBJECTEND", "OBJECTSTART", "ONTOPWITHCONTACTEND",
  "ONTOPWITHCONTACTSTART", "ORIENTATIONSTANDARDDEVIATIONEND",
  "ORIENTATIONSTANDARDDEVIATIONSTART", "OTHEROBSTACLEEND",
  "OTHEROBSTACLESTART", "PARTNAMEEND", "PARTNAMESTART", "PARTPARAMETEREND",
  "PARTPARAMETERSTART", "PARTQUANTITYEND", "PARTQUANTITYSTART",
  "PARTREFANDPOSENAMEEND", "PARTREFANDPOSENAMESTART", "PARTREFANDPOSEEND",
  "PARTREFANDPOSESTART", "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND",
  "PARTSTART", "PARTIALLYINEND", "PARTIALLYINSTART",
  "PARTSTRAYPARAMETEREND", "PARTSTRAYPARAMETERSTART", "POINTEND",
  "POINTSTART", "POSITIONINORDEREDLISTEND", "POSITIONINORDEREDLISTSTART",
  "POSITIONSTANDARDDEVIATIONEND", "POSITIONSTANDARDDEVIATIONSTART",
  "PRECONDITIONEND", "PRECONDITIONSTART", "PREDICATEGROUPELEMENTEND",
  "PREDICATEGROUPELEMENTSTART", "PREDICATENAMEEND", "PREDICATENAMESTART",
  "PREDICATEOCCURRENCEEND", "PREDICATEOCCURRENCESTART", "PREDICATEEND",
  "PREDICATESTART", "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART",
  "PUTKITTRAYEND", "PUTKITTRAYSTART", "PUTKITEND", "PUTKITSTART",
  "PUTPARTEND", "PUTPARTSTART", "RCC8SETEND", "RCC8SETSTART",
  "REFOBJECTNAMEEND", "REFOBJECTNAMESTART", "REFERENCENAMEEND",
  "REFERENCENAMESTART", "REQUIREMENTEND", "REQUIREMENTSTART",
  "ROBOTPARAMETEREND", "ROBOTPARAMETERSTART", "ROBOTEND", "ROBOTSTART",
  "SOAPEND", "SOAPSTART", "SECONDARYLOCATIONEND", "SECONDARYLOCATIONSTART",
  "SERIALNUMBEREND", "SERIALNUMBERSTART", "SKUNAMEEND", "SKUNAMESTART",
  "SKUEND", "SKUSTART", "SLOTEND", "SLOTSTART", "STATERELATIONNAMEEND",
  "STATERELATIONNAMESTART", "TAKEKITTRAYEND", "TAKEKITTRAYSTART",
  "TAKEKITEND", "TAKEKITSTART", "TAKEPARTEND", "TAKEPARTSTART",
  "TARGETNAMEEND", "TARGETNAMESTART", "TIMESTAMPEND", "TIMESTAMPSTART",
  "UNDERWITHCONTACTEND", "UNDERWITHCONTACTSTART", "VALUEEND", "VALUESTART",
  "VARIABLEEND", "VARIABLESTART", "WEIGHTUNITEND", "WEIGHTUNITSTART",
  "WEIGHTEND", "WEIGHTSTART", "WIDTHEND", "WIDTHSTART",
  "WORKTABLEPARAMETEREND", "WORKTABLEPARAMETERSTART", "WORKVOLUMEEND",
  "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND",
  "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "ACTIONBASETYPEDECL", "ANYORDERORDERINGCONSTRUCTTYPEDECL",
  "ATTACHENDEFFECTORTYPEDECL", "BOXVOLUMETYPEDECL", "BOXYSHAPETYPEDECL",
  "COUNTORDERINGCONSTRUCTTYPEDECL", "CREATEKITTYPEDECL",
  "CYLINDRICALSHAPETYPEDECL", "DETACHENDEFFECTORTYPEDECL",
  "DOMAINTYPEDECL", "EFFECTTYPEDECL", "ENDEFFECTORCHANGINGSTATIONTYPEDECL",
  "ENDEFFECTORHOLDERTYPEDECL", "ENDEFFECTORTYPEDECL",
  "EXISTORDERINGCONSTRUCTTYPEDECL", "EXTERNALSHAPETYPEDECL",
  "FUNCTIONBOOLEANEXPRESSIONTYPEDECL", "FUNCTIONOPERATIONTYPEDECL",
  "FUNCTIONTODECIMALBOOLTYPEDECL", "FUNCTIONTODECIMALEQUALTYPEDECL",
  "FUNCTIONTODECIMALGREATEROREQUALTYPEDECL",
  "FUNCTIONTODECIMALGREATERTYPEDECL",
  "FUNCTIONTODECIMALLESSOREQUALTYPEDECL", "FUNCTIONTODECIMALLESSTYPEDECL",
  "FUNCTIONTOFUNCTIONBOOLTYPEDECL", "FUNCTIONTOFUNCTIONEQUALTYPEDECL",
  "FUNCTIONTOFUNCTIONGREATEROREQUALTYPEDECL",
  "FUNCTIONTOFUNCTIONGREATERTYPEDECL",
  "FUNCTIONTOFUNCTIONLESSOREQUALTYPEDECL",
  "FUNCTIONTOFUNCTIONLESSTYPEDECL", "FUNCTIONTYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "HUMANTYPEDECL", "INCONTACTWITHTYPEDECL",
  "INTERNALSHAPETYPEDECL", "KITDESIGNTYPEDECL", "KITTRAYTYPEDECL",
  "KITTYPEDECL", "KITTINGWORKSTATIONTYPEDECL",
  "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL", "LARGEBOXWITHKITSTYPEDECL",
  "LARGECONTAINERTYPEDECL", "MECHANICALCOMPONENTTYPEDECL",
  "NOSKUOBJECTTYPEDECL", "ONTOPWITHCONTACTTYPEDECL",
  "ORDEREDLISTORDERINGCONSTRUCTTYPEDECL", "ORDERINGCONSTRUCTTYPEDECL",
  "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL", "PARTIALLYINTYPEDECL",
  "PARTSBINTYPEDECL", "PARTSTRAYTYPEDECL", "PARTSVESSELTYPEDECL",
  "PHYSICALLOCATIONTYPEDECL", "POINTTYPEDECL", "POSELOCATIONINTYPEDECL",
  "POSELOCATIONONTYPEDECL", "POSELOCATIONTYPEDECL",
  "POSEONLYLOCATIONTYPEDECL", "PRECONDITIONTYPEDECL",
  "PREDICATEGROUPELEMENTTYPEDECL", "PREDICATETYPEDECL",
  "PUTKITTRAYTYPEDECL", "PUTKITTYPEDECL", "PUTPARTTYPEDECL",
  "RELATIVELOCATIONINTYPEDECL", "RELATIVELOCATIONONTYPEDECL",
  "RELATIVELOCATIONTYPEDECL", "ROBOTACTIONBASETYPEDECL", "ROBOTTYPEDECL",
  "SOAPTYPEDECL", "SHAPEDESIGNTYPEDECL", "SKUOBJECTTYPEDECL",
  "SLOTTYPEDECL", "STATERELATIONTYPEDECL", "STOCKKEEPINGUNITTYPEDECL",
  "TAKEKITTRAYTYPEDECL", "TAKEKITTYPEDECL", "TAKEPARTTYPEDECL",
  "UNDERWITHCONTACTTYPEDECL", "VACUUMEFFECTORMULTICUPTYPEDECL",
  "VACUUMEFFECTORSINGLECUPTYPEDECL", "VACUUMEFFECTORTYPEDECL",
  "VECTORTYPEDECL", "WORKTABLETYPEDECL", "$accept", "y_SOAPFile",
  "y_XmlHeaderForSOAP", "y_SchemaLocation", "y_XmlBoolean",
  "y_XmlDateTime", "y_XmlDecimal", "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN",
  "y_XmlNonNegativeInteger", "y_XmlPositiveInteger", "y_XmlString",
  "y_XmlVersion", "y_AngleUnit_AngleUnitType", "$@2",
  "y_ArrayNumber_XmlPositiveInteger", "$@3",
  "y_ArrayRadius_PositiveDecimalType", "$@4", "y_AttachEndEffectorType",
  "y_AttachEndEffector_AttachEndEffectorType",
  "y_Base_MechanicalComponentType", "y_BoxVolumeType",
  "y_Capacity_XmlPositiveInteger", "$@5",
  "y_ChangingStation_EndEffectorChangingStationType", "y_CreateKitType",
  "y_CreateKit_CreateKitType", "y_CupDiameter_PositiveDecimalType", "$@6",
  "y_Description_XmlString", "$@7", "y_Description_XmlString_0", "$@8",
  "y_DesignName_XmlIDREF", "$@9", "y_DetachEndEffectorType",
  "y_DetachEndEffector_DetachEndEffectorType",
  "y_Diameter_PositiveDecimalType", "$@10", "y_DomainType",
  "y_Domain_DomainType", "y_EffectType", "y_Effect_EffectType",
  "y_EndEffectorChangingStationParameter_XmlNMTOKEN", "$@11",
  "y_EndEffectorChangingStationType",
  "y_EndEffectorHolderParameter_XmlNMTOKEN", "$@12",
  "y_EndEffectorHolderType", "y_EndEffectorHolder_EndEffectorHolderType_u",
  "y_EndEffectorName_XmlIDREF_0_u", "$@13",
  "y_EndEffectorParameter_XmlNMTOKEN", "$@14", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType_0", "y_Expression_XmlNMTOKEN", "$@15",
  "y_ExternalShapeType", "y_ExternalShape_ExternalShapeType_0",
  "y_F1EqualF2_FunctionToFunctionEqualType_0_u",
  "y_F1GreaterF2_FunctionToFunctionGreaterType_0_u",
  "y_F1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u",
  "y_F1LessF2_FunctionToFunctionLessType_0_u",
  "y_F1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u",
  "y_F1Name_XmlIDREF", "$@16", "y_F2Name_XmlIDREF", "$@17",
  "y_Finished_XmlBoolean", "$@18", "y_FunctionName_XmlIDREF", "$@19",
  "y_FunctionName_XmlIDREF_0", "$@20", "y_FunctionOperationType",
  "y_FunctionOperation_FunctionOperationType_0",
  "y_FunctionToFunctionEqualType",
  "y_FunctionToFunctionGreaterOrEqualType",
  "y_FunctionToFunctionGreaterType", "y_FunctionToFunctionLessOrEqualType",
  "y_FunctionToFunctionLessType", "y_FunctionType",
  "y_Function_FunctionType_u", "y_GraspPose_PoseLocationType_0",
  "y_HasTop_XmlBoolean", "$@21", "y_Height_PositiveDecimalType", "$@22",
  "y_HeldObject_SolidObjectType_0", "y_I_XmlDecimal", "$@23",
  "y_InContactWithType", "y_InContactWith_InContactWithType",
  "y_InternalShapeTypeAny", "y_InternalShape_InternalShapeType_0",
  "y_J_XmlDecimal", "$@24", "y_K_XmlDecimal", "$@25",
  "y_KitDesignName_XmlIDREF", "$@26", "y_KitDesignType",
  "y_KitDesign_KitDesignType_u", "y_KitParameter_XmlNMTOKEN", "$@27",
  "y_KitTrayParameter_XmlNMTOKEN", "$@28", "y_KitTraySkuName_XmlIDREF",
  "$@29", "y_KitTrayType", "y_KitTray_KitTrayType",
  "y_KitTray_KitTrayType_0_u", "y_KitType", "y_Kit_KitType_0_u",
  "y_KittingWorkstationType",
  "y_KittingWorkstation_KittingWorkstationType",
  "y_LargeBoxWithEmptyKitTraysParameter_XmlNMTOKEN", "$@30",
  "y_LargeBoxWithKitsParameter_XmlNMTOKEN", "$@31", "y_LargeContainerType",
  "y_LargeContainer_LargeContainerType", "y_LengthUnit_LengthUnitType",
  "$@32", "y_Length_PositiveDecimalType", "$@33",
  "y_ListEndEffectorHolder_EndEffectorHolderType_u",
  "y_ListEndEffectorName_XmlIDREF_0_u",
  "y_ListF1EqualF2_FunctionToFunctionEqualType_0_u",
  "y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u",
  "y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u",
  "y_ListF1LessF2_FunctionToFunctionLessType_0_u",
  "y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u",
  "y_ListFunction_FunctionType_u", "y_ListKitDesign_KitDesignType_u",
  "y_ListKitTray_KitTrayType_0_u", "y_ListKit_KitType_0_u",
  "y_ListNotPredicateName_XmlIDREF_0_u",
  "y_ListObjectOnTable_SolidObjectType_0_u",
  "y_ListObject_SolidObjectType_u",
  "y_ListOtherObstacle_BoxVolumeType_0_u",
  "y_ListPartRefAndPose_PartRefAndPoseType_u", "y_ListPart_PartType_0_u",
  "y_ListPredicateGroupElement_PredicateGroupElementType_u",
  "y_ListPredicateName_XmlIDREF_0_u", "y_ListPredicateName_XmlIDREF_u",
  "y_ListPredicate_PredicateType_u", "y_ListRequirement_XmlNMTOKEN_u",
  "y_ListSecondaryLocation_PhysicalLocationType_0_u",
  "y_ListSku_StockKeepingUnitType_u", "y_ListSlot_SlotType_0_u",
  "y_ListVariable_XmlNMTOKEN_u", "y_ListWorkVolume_BoxVolumeType_u",
  "y_MaximumLoadWeight_PositiveDecimalType", "$@34",
  "y_MaximumPoint_PointType", "y_MechanicalComponentType",
  "y_MinimumPoint_PointType", "y_ModelFileName_XmlString", "$@35",
  "y_ModelFormatName_XmlString", "$@36", "y_ModelName_XmlString_0", "$@37",
  "y_Name_XmlID", "$@38", "y_NotPredicateName_XmlIDREF_0_u", "$@39",
  "y_ObjectOnTable_SolidObjectType_0_u", "y_Object_SolidObjectType_u",
  "y_OnTopWithContactType", "y_OnTopWithContact_OnTopWithContactType",
  "y_OrientationStandardDeviation_PositiveDecimalType_0", "$@40",
  "y_OtherObstacle_BoxVolumeType_0_u", "y_PartName_XmlIDREF_0", "$@41",
  "y_PartParameter_XmlNMTOKEN", "$@42",
  "y_PartQuantity_XmlNonNegativeInteger", "$@43",
  "y_PartRefAndPoseName_XmlIDREF", "$@44", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u", "y_PartSkuName_XmlIDREF",
  "$@45", "y_PartType", "y_Part_PartType_0_u", "y_PartiallyInType",
  "y_PartiallyIn_PartiallyInType", "y_PartsTrayParameter_XmlNMTOKEN",
  "$@46", "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PoseLocationTypeAny",
  "y_PositionStandardDeviation_PositiveDecimalType_0", "$@48",
  "y_PreconditionType", "y_Precondition_PreconditionType",
  "y_PredicateGroupElementType",
  "y_PredicateGroupElement_PredicateGroupElementType_u",
  "y_PredicateName_XmlIDREF_0_u", "$@49", "y_PredicateName_XmlIDREF_u",
  "$@50", "y_PredicateType", "y_Predicate_PredicateType_u",
  "y_PrimaryLocation_PhysicalLocationType", "y_PutKitTrayType",
  "y_PutKitTray_PutKitTrayType", "y_PutKitType", "y_PutKit_PutKitType",
  "y_PutPartType", "y_PutPart_PutPartType", "y_RCC8Set_XmlString", "$@52",
  "y_RefObjectName_XmlIDREF", "$@53", "y_ReferenceName_XmlNMTOKEN", "$@54",
  "y_Requirement_XmlNMTOKEN_u", "$@55", "y_RobotParameter_XmlNMTOKEN",
  "$@56", "y_RobotType", "y_Robot_RobotType", "y_SOAPType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SerialNumber_XmlNMTOKEN", "$@57", "y_SkuName_XmlIDREF", "$@58",
  "y_Sku_StockKeepingUnitType_u", "y_SlotType", "y_Slot_SlotType_0_u",
  "y_SolidObjectTypeAny", "y_StateRelationName_XmlIDREF_0", "$@59",
  "y_StockKeepingUnitType", "y_TakeKitTrayType",
  "y_TakeKitTray_TakeKitTrayType", "y_TakeKitType",
  "y_TakeKit_TakeKitType", "y_TakePartType", "y_TakePart_TakePartType",
  "y_TargetName_XmlNMTOKEN_0", "$@60", "y_Timestamp_XmlDateTime_0", "$@61",
  "y_UnderWithContactType", "y_UnderWithContact_UnderWithContactType",
  "y_Value_XmlPositiveInteger", "$@62", "y_Variable_XmlNMTOKEN_u", "$@63",
  "y_VectorType", "y_WeightUnit_WeightUnitType", "$@64",
  "y_Weight_PositiveDecimalType", "$@65", "y_Width_PositiveDecimalType",
  "$@66", "y_WorkTableParameter_XmlNMTOKEN", "$@67",
  "y_WorkVolume_BoxVolumeType_u", "y_XAxis_VectorType", "y_X_XmlDecimal",
  "$@68", "y_Y_XmlDecimal", "$@69", "y_ZAxis_VectorType", "y_Z_XmlDecimal",
  "$@70", "y_x_BoxyShapeType", "y_x_CylindricalShapeType",
  "y_x_EndEffectorChangingStationType", "y_x_EndEffectorHolderType",
  "y_x_GripperEffectorType", "y_x_HumanType", "y_x_KitTrayType",
  "y_x_KitType", "y_x_KittingWorkstationType",
  "y_x_LargeBoxWithEmptyKitTraysType", "y_x_LargeBoxWithKitsType",
  "y_x_LargeContainerType", "y_x_MechanicalComponentType", "y_x_PartType",
  "y_x_PartsBinType", "y_x_PartsTrayType", "y_x_PoseLocationInType",
  "y_x_PoseLocationOnType", "y_x_PoseOnlyLocationType",
  "y_x_RelativeLocationInType", "y_x_RelativeLocationOnType",
  "y_x_RobotType", "y_x_VacuumEffectorMultiCupType",
  "y_x_VacuumEffectorSingleCupType", "y_x_WorkTableType", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   362,   364,   363,   366,   365,
     368,   367,   369,   370,   371,   372,   374,   373,   375,   376,
     377,   379,   378,   381,   380,   382,   383,   382,   385,   384,
     386,   387,   389,   388,   390,   391,   392,   393,   395,   394,
     396,   398,   397,   399,   400,   402,   401,   404,   403,   405,
     405,   405,   406,   406,   408,   407,   409,   410,   410,   411,
     412,   413,   414,   415,   417,   416,   419,   418,   421,   420,
     423,   422,   424,   425,   424,   426,   427,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   435,   437,   436,   439,
     438,   440,   440,   442,   441,   443,   444,   445,   445,   446,
     446,   448,   447,   450,   449,   452,   451,   453,   454,   456,
     455,   458,   457,   460,   459,   461,   462,   463,   464,   465,
     466,   467,   469,   468,   471,   470,   472,   473,   475,   474,
     477,   476,   478,   478,   479,   479,   480,   480,   481,   481,
     482,   482,   483,   483,   484,   484,   485,   485,   486,   486,
     487,   487,   488,   488,   489,   489,   490,   490,   491,   491,
     492,   492,   493,   493,   494,   494,   495,   495,   496,   496,
     497,   497,   498,   498,   499,   499,   500,   500,   501,   501,
     502,   502,   503,   503,   504,   504,   506,   505,   507,   508,
     509,   511,   510,   513,   512,   514,   515,   514,   517,   516,
     519,   518,   520,   521,   522,   523,   524,   525,   524,   526,
     527,   528,   527,   530,   529,   532,   531,   534,   533,   535,
     536,   538,   537,   539,   540,   541,   542,   544,   543,   545,
     545,   545,   545,   545,   546,   547,   548,   548,   548,   549,
     550,   549,   551,   552,   553,   554,   556,   555,   558,   557,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   569,
     568,   571,   570,   573,   572,   575,   574,   577,   576,   578,
     579,   580,   581,   583,   582,   585,   584,   586,   587,   588,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   590,   591,
     590,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     599,   601,   602,   601,   603,   604,   606,   605,   608,   607,
     609,   611,   610,   613,   612,   615,   614,   617,   616,   618,
     619,   621,   620,   623,   622,   624,   626,   625,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     0,     5,     0,     5,
       0,     5,     9,     3,     3,     4,     0,     5,     3,     8,
       3,     0,     5,     0,     5,     0,     0,     5,     0,     5,
       9,     3,     0,     5,    15,     3,    11,     3,     0,     5,
       8,     0,     5,     7,     3,     0,     5,     0,     5,     1,
       1,     1,     0,     3,     0,     5,     7,     0,     3,     3,
       3,     3,     3,     3,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     0,     5,     5,     0,     3,     4,     4,
       4,     4,     4,     5,     3,     0,     3,     0,     5,     0,
       5,     0,     3,     0,     5,     3,     3,     1,     1,     0,
       3,     0,     5,     0,     5,     0,     5,     4,     3,     0,
       5,     0,     5,     0,     5,     6,     3,     3,    11,     3,
      15,     3,     0,     5,     0,     5,     6,     3,     0,     5,
       0,     5,     1,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     1,     2,     1,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     2,     1,
       0,     2,     2,     1,     0,     2,     2,     1,     0,     2,
       2,     1,     2,     1,     2,     1,     0,     2,     2,     1,
       0,     2,     2,     1,     2,     1,     0,     5,     3,     6,
       3,     0,     5,     0,     5,     0,     0,     5,     0,     5,
       0,     5,     3,     3,     3,     3,     0,     0,     5,     3,
       0,     0,     5,     0,     5,     0,     5,     0,     5,     6,
       3,     0,     5,     6,     3,     3,     3,     0,     5,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     1,     0,
       0,     5,    10,     3,     5,     3,     0,     5,     0,     5,
       4,     3,     3,     7,     3,     8,     3,     9,     3,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,    10,
       3,     8,     3,     0,     5,     0,     5,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       5,     7,     9,     3,     8,     3,     9,     3,     0,     0,
       5,     0,     0,     5,     3,     3,     0,     5,     0,     5,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     3,
       3,     0,     5,     0,     5,     3,     0,     5,     9,     8,
       9,     8,    11,     7,     7,    12,    16,     9,    11,     7,
       7,     7,    10,    10,    10,    10,    10,     6,     6,    11,
      15,    13,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    15,     4,   208,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,   131,     0,     0,     0,     0,   209,
       0,   186,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   109,
       0,     0,   185,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,    67,   187,   275,
       0,     0,   184,   193,     0,   105,     0,   325,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   328,     0,     0,   183,
     192,   269,   324,     0,   236,     0,     0,     0,   321,   321,
     321,   321,   321,     0,     0,   110,   282,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,   156,     0,   182,
       0,   235,     0,   215,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    16,     0,     0,   276,     0,
      35,   261,     0,     0,     0,     0,   157,    13,     0,   214,
       0,   322,     0,     0,     0,     0,     0,   367,   368,    95,
      95,    95,     0,     0,     0,     0,   158,     0,   329,     0,
       0,    35,    94,     0,     0,     0,     0,   270,     9,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,   159,     0,
      36,     0,   260,   177,     0,    35,    23,     0,     0,     0,
       0,   272,     6,     0,     0,   245,     0,     0,     0,   249,
     249,   249,     0,     0,   246,   247,   248,     0,     0,     0,
       0,     0,     0,    17,   186,     0,   118,   138,     0,   170,
     169,     0,     0,     0,   176,     0,   318,     0,    35,    30,
       0,     0,     0,     0,   323,     0,     0,     0,   340,     0,
       0,   216,   216,   216,     0,    96,   140,     0,     0,    42,
       0,     0,   203,     0,   205,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,     0,   168,     0,     0,
     255,   273,     0,    93,     0,     0,     0,    35,    41,     0,
       0,     0,     0,   341,     0,     0,     0,     0,   345,   250,
       0,   364,   365,   366,    34,     0,   335,     0,     0,    99,
       0,   349,     0,   201,     0,    66,    67,   123,     0,   117,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,     0,   171,     0,    37,   318,     0,   319,   277,
       0,     0,     0,     0,     0,    35,   317,     0,     0,     0,
       0,     0,   343,     0,   244,   103,     0,     0,     0,   217,
       0,     0,   348,     0,     0,    97,     0,     0,   206,     0,
       0,     0,     0,   172,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     308,     0,     0,     0,    57,     0,     0,   119,     0,     0,
       0,     0,    35,   315,     0,     0,     0,     0,     7,     0,
       0,   346,     0,   111,     0,   330,     0,     0,   141,     0,
      43,     0,     0,   204,     0,     0,     0,     0,     0,     0,
     230,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,     0,
     219,     0,   280,     0,     0,     0,   188,   130,     0,   254,
     274,     0,     0,     0,    51,     0,     0,     0,   121,     0,
       0,     0,     0,     0,    35,   313,     0,     0,     0,     0,
     342,     0,     0,     0,     0,   113,   251,     0,   336,   100,
       5,     0,   202,     0,     0,     0,     0,   142,    50,   124,
       0,     0,   109,   109,   109,   109,     0,   109,   109,   109,
     109,     0,   109,     0,     0,     0,   109,   109,   109,   109,
       0,     0,   186,     0,   287,   331,   309,   320,   278,     0,
       0,    48,     0,     0,     0,     0,   337,     0,     0,     0,
       0,     0,     0,    35,   268,     0,     0,     0,    44,   344,
       0,   104,     0,     0,   218,    98,   207,     0,    24,     0,
       0,   143,   285,     0,    67,    67,    67,    67,     0,    67,
      67,    67,    67,     0,    67,     0,     0,     0,    67,    67,
      67,    67,     0,     0,    25,   109,   109,     0,     0,    58,
       0,     0,     0,     0,     0,    22,   120,     0,     0,    29,
       0,   223,     0,     0,     0,     0,     0,    35,   266,     0,
       0,   347,   112,     0,   186,     0,    54,     0,     0,     0,
      62,     0,   353,     0,   354,     0,     0,     0,     0,   359,
     360,   361,     0,     0,     0,     0,     0,   166,   198,     0,
      67,    67,     0,     0,    52,     0,     0,   253,     0,     0,
     122,     0,     0,     0,   237,     0,     0,     0,     0,     0,
      35,   264,   114,   109,   186,     0,   229,     0,     0,   351,
       0,   283,     0,     0,     0,     0,   160,   162,     0,     0,
       0,    62,     0,     0,   372,   200,     0,     0,   332,   310,
      49,     0,    82,   181,   178,    47,   338,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,   109,   286,
     350,     0,    59,    60,    61,     0,     0,     0,    38,     0,
     174,     0,     0,     0,   357,     0,   231,     0,   174,   174,
       0,     0,     0,     0,   167,    62,   144,   258,     0,    86,
     180,   164,   224,     0,   316,   314,   132,     0,     0,     0,
       0,   199,    67,    63,   333,     0,   101,     0,     0,     0,
       0,   190,     0,     0,   137,     0,   161,     0,     0,     0,
     163,     0,   225,   362,   363,     0,   101,   101,     0,     0,
     311,     0,    83,     0,   152,     0,    82,   179,   238,     0,
       0,     0,     0,     0,     0,    62,     0,   196,     0,   352,
     284,     0,     0,   126,     0,     0,   175,     0,   186,     0,
     115,     0,     0,     0,   358,     0,     0,     0,   369,   195,
       0,     0,   212,     0,     0,   145,     0,     0,     0,     0,
     146,   256,     0,    86,   165,     0,   312,     0,   134,     0,
       0,    53,     0,     0,     0,    39,   186,     0,     0,     0,
       0,   355,   191,   170,     0,   127,     0,     0,   129,    26,
     232,    11,     0,     0,   194,     0,     0,     0,   279,    55,
     259,     0,     0,    87,     0,   153,   150,     0,   210,   152,
     133,   267,     0,   265,   263,   334,     0,   102,     0,     0,
     234,    78,     0,     0,     0,     0,     0,   186,     0,   226,
     339,    31,     0,   371,     0,    84,     0,     0,     0,     0,
       0,   147,   148,     0,     0,   146,     0,   197,     0,   186,
       0,     0,   289,     0,   136,   116,   109,    12,     0,     0,
       0,     0,     0,    80,     0,     0,     0,    72,     0,     0,
       0,   151,   154,   257,     0,   150,   135,   125,     0,     0,
       0,   220,     0,    67,    27,     0,    18,     0,   370,    56,
       0,    64,     0,    85,     0,     0,     0,    69,     0,     0,
       0,   149,   252,   211,   148,     0,    79,   227,     0,   288,
     356,     0,    32,     0,    20,     0,     0,   326,    74,     0,
      92,     0,     0,    71,     0,     0,     0,   155,   154,   233,
       0,   221,     0,     0,     0,    81,     0,     0,     0,    76,
      88,     0,     0,    70,     0,     0,    46,     0,     0,   174,
      19,     0,    65,     0,     0,     0,    89,     0,     0,    73,
     228,     0,   190,    21,   327,    75,     0,    90,     0,   222,
       0,    77,    91,   128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   571,   233,   489,    32,   199,   132,
     942,  1008,   168,     3,   130,   182,  1011,  1063,  1038,  1084,
     194,   165,   507,   464,   894,   978,   157,   228,   196,   946,
    1009,   177,   242,   190,   261,   753,   838,   271,   230,   250,
     368,    36,    30,   729,   675,   546,   671,   184,   476,   610,
     640,   577,   905,   984,   411,   543,   791,   749,  1015,  1066,
     128,   104,   991,  1051,  1021,   955,  1077,  1045,  1088,  1070,
    1105,   931,  1000,   987,  1040,   819,   907,   909,   864,  1019,
    1049,  1075,  1095,   989,   163,   137,   209,   371,   502,   291,
     434,   879,   357,   492,    45,    38,    99,    77,   427,   564,
     495,   633,   849,   936,   216,   186,   413,   547,   479,   615,
     297,   440,   840,   800,   846,   892,   850,    28,    25,   783,
     869,   873,   962,   803,   756,   219,   298,   248,   365,   578,
     860,   956,  1022,   992,   910,  1052,   138,   187,   804,   805,
     866,   764,   259,   336,   379,   841,   222,   821,   772,   108,
      61,    59,   468,   885,    81,   898,   836,   923,   601,   575,
     664,   294,   437,   252,   372,   375,   505,    19,    26,   914,
     994,   814,   260,   116,    91,   361,   497,   403,  1059,  1098,
     620,   733,   808,   896,  1031,  1080,   442,   380,   759,   851,
     928,   886,    89,    68,   683,   779,    53,   202,   173,   243,
     281,   428,   673,   613,   263,   223,   867,   957,   773,   861,
     135,   109,    41,   690,   628,   626,   559,   557,   487,    85,
     140,   118,   170,   266,   407,    62,   105,   345,   473,   466,
     404,    14,    78,   704,   797,   581,   697,   469,   973,   932,
     317,   539,   668,   534,   485,   420,   418,   352,   350,   273,
     343,   472,   146,   200,    66,    47,  1043,  1087,    83,   133,
     237,   537,   667,   796,   876,   288,   431,   550,   678,   899,
     204,   276,   421,   355,   490,   239,   424,   562,   100,   101,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,    54,    55,    56,    57,    58,   332,
     333,   334,   335
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1002
static const yytype_int16 yypact[] =
{
      69,    88,   108,   -95,   124, -1002,   116,   118,   138,   153,
     150, -1002,   154,    14,   -51,   157,   155, -1002,   161,    45,
   -1002, -1002, -1002, -1002,   163,   123,   167,    14,    53,   171,
      79, -1002,    37,   -11, -1002,    14,   139,   184,   -48, -1002,
    -193, -1002,   -17, -1002,    14,    93,   188,    20,   190,   191,
     192,   193,   195,     8, -1002, -1002, -1002, -1002, -1002,   -66,
     198,  -145, -1002,     2, -1002,    14,   -30,   200,    52,    14,
      14,    14,    14,    14, -1002,  -165,  -193,   143, -1002, -1002,
     205,  -125, -1002, -1002,   206, -1002,     2, -1002,    14,    40,
     209, -1002,    11,    11,    11,    11,    11,   211,   212,   117,
   -1002, -1002,     4,   215,   207,   218, -1002,   217,   -50, -1002,
   -1002, -1002, -1002,     2, -1002,    14,    71,   220,    -8,    -8,
      -8,    -8,    -8,    14,    14, -1002, -1002,    14,   164,   225,
     202, -1002,    26,   218,    14,    44,   232, -1002,    25, -1002,
     235, -1002,     2, -1002, -1002,   234,    62,    62,    62,   203,
     203,   203,   203,   203, -1002, -1002,   241,   156, -1002,    27,
     229, -1002,    14,   182,   266,   238, -1002, -1002,    72, -1002,
     274, -1002,   273,    50,    50,    50,   275, -1002, -1002,   189,
     189,   189,   296,    14,   280,   306, -1002,   -40, -1002,   307,
     133,   229, -1002,    14,   297,   318,   285, -1002, -1002,   125,
     327,    14,   159,   326,    74,    74,    74, -1002,  -189,   210,
     288,   196,   328,   -11, -1002,    14,   236,   336, -1002,   194,
   -1002,   339,   133, -1002,   141,   229, -1002,    14,   315,   344,
     119, -1002, -1002,   115,    96, -1002,    14,   100,   326,   204,
     204,   204,   235,   289, -1002, -1002, -1002,   369,   129,   375,
     291,   382,   248, -1002, -1002,   276, -1002, -1002,   338,   194,
   -1002,   235,    14,   208, -1002,   385,   160,   181,   229, -1002,
      14,   354,   391,   169, -1002,   392,   142,   303, -1002,   144,
     397,   249,   249,   249,   367, -1002, -1002,   403,   291, -1002,
     406,   320, -1002,   410,   272,   -66,   412,   250,   417,   416,
     418,   419,   420,   421,   422,   423,   425,   426,   427,   428,
     429,   431,   433,   435,   436,   437,   442,   271, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   -96, -1002,   415,   141,
   -1002, -1002,   458, -1002,   460,   408,   356,   229, -1002,    14,
     239,   464,   243, -1002,   467,   214,   468,   370, -1002, -1002,
     474, -1002, -1002, -1002, -1002,   477, -1002,   320,   478, -1002,
     479, -1002,   235, -1002,   480, -1002,   143, -1002,   482,   250,
   -1002,   359,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
   -1002,   484,   485, -1002,   261, -1002,   160,   218, -1002, -1002,
     486,   440,   488,   380,   181,   229, -1002,    14,   267,   490,
     299,   497, -1002,   496, -1002, -1002,   498,   396,   504, -1002,
     377,   506, -1002,   469,   507, -1002,   372,   235, -1002,   489,
     274,    14,   349, -1002, -1002,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,    14,   360,    14,   300,   513,  -158, -1002,
     295,   317,   218,   218, -1002,   518,   476, -1002,   519,   277,
     408,   181,   229, -1002,    14,   302,   525,   333, -1002,   278,
     497, -1002,   497, -1002,   527, -1002,   353,   532, -1002,   290,
   -1002,   443,   536, -1002,   401,   235,   538,   487,   432,   324,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   413,
   -1002,   -11, -1002,    14,   329,   543, -1002, -1002,   546, -1002,
   -1002,   321,   346,   218, -1002,   548,   373,   218, -1002,   551,
     373,   440,   399,   181,   229, -1002,    14,   364,   553,   363,
   -1002,   308,   497,   471,   497, -1002, -1002,   409, -1002, -1002,
   -1002,   475, -1002,   434,    14,   544,   565, -1002,   487, -1002,
     566,    62,   -66,   -66,   -66,   -66,  -141,   -66,   -66,   -66,
     -66,  -141,   -66,  -141,  -141,  -141,   -66,   -66,   -66,   -66,
     273,   438, -1002,   203, -1002, -1002, -1002, -1002, -1002,   515,
     218, -1002,   573,   531,   470,   218, -1002,   531,   476,   575,
     407,   356,   181,   229, -1002,    14,   387,   577, -1002, -1002,
     330, -1002,   491,   497, -1002, -1002, -1002,   -11, -1002,    14,
     534, -1002, -1002,    50,   143,   143,   143,   143,   371,   143,
     143,   143,   143,   371,   143,   371,   371,   371,   143,   143,
     143,   143,   450,   273, -1002,   -66,   494,   585,   274, -1002,
     539,   218,    14,   424,   587, -1002, -1002,   492,   218, -1002,
     373, -1002,   588,   408,   408,   380,   181,   229, -1002,    14,
     404, -1002, -1002,   493, -1002,   -11, -1002,   274,    74,   489,
     541,   203, -1002,   597, -1002,   563,   207,   481,   481, -1002,
   -1002, -1002,   444,   444,   203,   203,   203, -1002, -1002,   473,
     143,   143,   361,   381, -1002,   567,   430, -1002,    14,   568,
   -1002,   368,   531,   218, -1002,   373,   373,   495,   399,   181,
     229, -1002, -1002,   -66, -1002,   402, -1002,   487,  -235, -1002,
     374, -1002,   617,   505,   202,   619, -1002, -1002,   621,   463,
     463,   541,   374,   374,   500, -1002,   203,   374, -1002, -1002,
   -1002,   623,   -44, -1002, -1002, -1002, -1002, -1002,   499,   218,
     531,   531,   624,   408,   356,   356,   181,   143,   -66, -1002,
     487,   571, -1002, -1002, -1002,   629,   501,   218, -1002,   631,
   -1002,   156,    14,   520,   535,   -32, -1002,   649, -1002, -1002,
     501,   501,   501,   338, -1002,   541, -1002, -1002,   650,   576,
   -1002,   483, -1002,   502, -1002, -1002, -1002,   373,   407,   533,
     380, -1002,   143, -1002, -1002,   658,   569,   451,   274,    14,
     550,   508,   -40,   -11, -1002,   631, -1002,   664,   667,   646,
   -1002,   274, -1002,   508,   508,   439,   569,   569,   529,   501,
     620,   274, -1002,   674, -1002,   678,   -33, -1002, -1002,   218,
     531,   373,   681,   373,   373,   541,   684, -1002,   338, -1002,
   -1002,   651,   -11, -1002,   683,   -43, -1002,   194, -1002,   572,
   -1002,    14,   574,   687, -1002,   526,   691,   484,   439, -1002,
     661,   661, -1002,   439,   693, -1002,   512,   274,    14,   616,
     628, -1002,   698,   576, -1002,   581, -1002,   531, -1002,   531,
     531, -1002,   461,   702,   612, -1002, -1002,    14,   537,   704,
     705, -1002, -1002,   194,  -141, -1002,   274,   -11, -1002, -1002,
   -1002, -1002,   549,   462, -1002,   706,   210,   210,   439, -1002,
   -1002,   632,   630, -1002,   711, -1002,   652,   274, -1002, -1002,
   -1002, -1002,   218, -1002, -1002, -1002,   584, -1002,  -141,   -11,
   -1002, -1002,    14,   503,   -96,   371,   611, -1002,   716, -1002,
   -1002, -1002,   701, -1002,   274, -1002,   717,   659,    14,   654,
     720, -1002,   656,   542,   274,   628,   605, -1002,   371, -1002,
     536,   578, -1002,   261, -1002, -1002,   -66, -1002,   707,   728,
     727,   713,   682, -1002,   733,   509,   655, -1002,    14,   673,
     736, -1002,   672, -1002,   596,   652, -1002, -1002,  -141,   665,
     740,   590,  -158,   143, -1002,   718, -1002,   743, -1002, -1002,
     274, -1002,   746, -1002,   747,   675,   655, -1002,    14,   685,
     749, -1002,   686, -1002,   656,   371, -1002, -1002,   752, -1002,
   -1002,   563, -1002,   716, -1002,   676,   218, -1002, -1002,   753,
   -1002,   675,   655, -1002,    14,   692,   755, -1002,   672, -1002,
     274, -1002,   505,   744,   761, -1002,   703,   716,   274, -1002,
   -1002,   675,   655, -1002,    14,   690,   686,   602,   274, -1002,
   -1002,   751, -1002,   540,   696,   274, -1002,   675,   655, -1002,
   -1002,   609,   508, -1002, -1002, -1002,   697, -1002,   675, -1002,
     -43, -1002, -1002, -1002
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1002, -1002, -1002, -1002,  -224, -1002,  -460, -1002,  -431,  -132,
   -1002, -1001,  -191, -1002,    65, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,    80,  -119, -1002, -1002,    28, -1002, -1002,  -120,
   -1002,  -140, -1002,  -144, -1002,  -278, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,  -594,   166, -1002, -1002,   237, -1002,
   -1002,  -558, -1002, -1002,  -456, -1002, -1002,  -725, -1002, -1002,
   -1002,  -200, -1002, -1002, -1002, -1002, -1002,  -993, -1002,  -986,
   -1002,  -335, -1002, -1002, -1002,   -80, -1002, -1002,  -124, -1002,
   -1002, -1002, -1002, -1002, -1002,   653,  -114,   441, -1002,   510,
   -1002,  -773, -1002, -1002, -1002, -1002, -1002,  -281, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,  -184,  -606, -1002,  -658, -1002,
   -1002, -1002,   -58,  -292, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,    84,   -49, -1002,  -807, -1002,    47,
   -1002,  -198,  -259,  -226,  -163,  -277, -1002,     1, -1002, -1002,
   -1002, -1002,   -87,  -130, -1002,  -780, -1002, -1002, -1002, -1002,
   -1002,  -229,  -196,  -308, -1002,   -98,  -737, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   -27, -1002, -1002,
   -1002, -1002,  -257, -1002, -1002,  -135, -1002, -1002, -1002, -1002,
      68, -1002,    49, -1002, -1002, -1002, -1002,   445,    97, -1002,
   -1002, -1002, -1002, -1002,   -15, -1002,   735,  -551,  -126, -1002,
     -83, -1002, -1002,  -491, -1002,   592, -1002, -1002,    43, -1002,
   -1002,   708,  -197, -1002, -1002, -1002, -1002, -1002, -1002,   -31,
   -1002,    -1, -1002,   511, -1002,   756, -1002,  -409, -1002, -1002,
    -155, -1002, -1002,  -599, -1002,  -560, -1002,  -464, -1002, -1002,
    -765, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
     414, -1002,    33, -1002, -1002, -1002, -1002, -1002,   737, -1002,
     583,  -210, -1002,  -621, -1002, -1002, -1002, -1002, -1002,  -829,
    -156, -1002, -1002, -1002, -1002,  -199, -1002, -1002, -1002, -1002,
   -1002, -1002,    75, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   618,   626,   627, -1002, -1002, -1002,
      77,    81, -1002
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      33,   159,   337,   218,   536,   480,   240,   241,    42,   508,
     178,   179,   180,   181,   376,   684,   254,    63,   205,   206,
     641,   174,   175,   679,   551,   295,   648,   737,   853,   854,
     561,   653,   563,   655,   656,   657,   810,    75,    86,   136,
     929,   818,    92,    93,    94,    95,    96,   224,   858,   662,
     164,   284,   818,  1071,   709,   112,   711,   712,   713,   617,
     301,   113,  1083,   401,    60,   467,   210,   211,   107,   944,
     338,   185,   552,   855,   856,   857,    76,   847,     1,  1091,
     580,   267,   141,   900,   901,  1090,  1103,   535,   142,   848,
     859,   217,   119,   120,   121,   122,   151,   152,    80,  1107,
     153,     4,   630,    97,   632,  1106,    98,   160,     5,   314,
     315,   169,   719,   924,   136,  1118,   912,   402,    80,   944,
       6,  1117,   903,    10,   346,    11,    48,    49,     8,    50,
      48,    49,  1122,    50,     7,   191,    51,    52,   777,   982,
     983,   811,   812,   107,   621,   771,   816,   362,   363,    12,
     921,    76,   147,   148,   149,   150,   213,   282,   283,    13,
      15,    18,    16,    20,    21,    22,   225,    23,    24,    27,
      29,    31,   874,   693,   234,    34,   439,    35,   828,   829,
      37,   436,   930,    39,    40,    43,   824,   825,   255,   732,
      44,    46,    60,    64,    65,    67,    69,    70,    71,    72,
     268,    73,    74,   414,    79,    84,    88,    90,    87,   277,
     103,   106,   111,   685,   114,   115,   117,   123,   124,   125,
     126,   127,   131,   134,   129,   143,   144,   735,   736,   145,
     154,   155,   641,   156,   158,   339,   161,   723,   162,   167,
     171,   172,   176,   347,   780,   781,   504,   183,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   745,   185,   189,   188,
     192,   481,   193,   195,   197,   471,   916,   738,   198,   201,
     208,   207,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     212,   644,   645,   646,   647,   203,   649,   650,   651,   652,
     214,   654,   215,   220,   573,   658,   659,   660,   661,  1112,
     221,   226,   415,   961,   227,   963,   964,   827,   229,   231,
     785,   232,   236,   249,   602,   238,   870,   235,   553,   251,
     541,   542,   257,   247,   253,   262,   256,   258,   265,   269,
     270,   274,   272,   275,   278,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   665,   975,   286,  1004,   830,   287,   285,
     917,   289,   919,   920,   720,   721,   290,   280,   292,   293,
     482,   341,   344,   296,   340,   342,   348,   349,   353,  1027,
     351,   354,   356,   359,   358,   364,   360,   881,   998,   366,
     622,   609,   369,   370,   509,   614,   373,   374,   377,   378,
     895,   381,   382,   400,   383,   384,   385,   386,   387,   388,
     906,   389,   390,   391,   392,   393,   529,   394,   531,   395,
     694,   396,   397,   398,   699,   700,   701,   702,   399,   705,
     706,   707,   708,   405,   710,   643,  1079,   554,   714,   715,
     716,   717,   787,   666,   408,   743,   409,   410,  1055,   412,
     417,   416,   419,   422,   425,   426,   951,   423,   670,   686,
     429,   430,   433,   677,   467,   435,   438,   698,   441,   444,
     463,   465,   474,   475,   477,   478,   484,   483,   744,   746,
     486,   488,   491,   494,   493,   976,   603,   832,   496,   498,
     499,   501,   532,   500,   503,   788,   506,   510,   530,   533,
     766,   767,   538,   540,   544,   548,   993,   545,   549,   623,
     555,   556,   558,   565,   560,   566,   567,   569,   568,   725,
     570,   572,   576,   739,   574,   580,   731,   637,   579,   605,
     600,   604,   606,  1012,   611,   607,   608,   616,   612,   625,
     627,   750,   619,  1024,   624,   634,   629,   635,   536,   631,
     638,   639,   642,   669,   761,   762,   763,   663,   636,   672,
     674,   681,   676,   689,   682,   688,   718,   831,   696,   722,
     703,   724,   691,   728,   734,   692,   786,    75,   687,   742,
     741,   778,   748,   751,   752,   768,   730,   769,   727,  1065,
     755,   765,   695,   299,   300,   758,   775,   770,   776,   771,
     782,   795,   789,   798,   799,   802,   815,   806,   807,   817,
     826,   833,   875,   301,   302,   834,   835,   839,   303,   304,
     305,   306,   307,   308,   309,   726,   888,   823,   844,  1097,
     310,   813,   311,   312,   845,   852,   862,  1104,   218,   934,
     872,   822,   740,   863,   877,   837,   878,  1111,   883,   880,
     890,   313,   865,   891,  1116,   893,   337,   904,   868,   902,
     908,   884,   314,   315,   911,   926,   316,   918,   922,   927,
     935,   925,   897,   939,   938,   941,   940,   968,   945,   949,
     950,   774,   953,   954,   958,   960,   966,   965,   967,   970,
     971,   972,   981,   979,   980,   986,   985,   988,   997,  1005,
    1007,   990,  1010,  1013,  1014,  1033,  1018,  1002,  1017,  1020,
    1023,  1026,  1035,  1036,  1044,  1034,  1037,   915,  1039,  1041,
     977,  1047,  1048,  1050,  1053,  1030,  1057,  1056,  1006,  1064,
    1042,  1058,  1067,  1068,  1062,  1074,  1069,  1073,  1081,  1089,
    1085,  1094,  1093,  1076,  1100,  1101,  1109,  1102,  1110,  1119,
    1028,   754,   999,  1113,  1115,   843,  1029,  1121,   943,   747,
    1114,   947,   801,  1082,   680,  1123,   913,   889,   618,   959,
    1099,   166,   757,   887,   790,  1078,   995,  1025,   367,  1054,
     933,  1096,   842,   974,  1120,   948,   784,  1032,   432,   809,
     760,   102,   882,   871,   264,   820,   139,    82,   110,  1003,
     470,   279,  1060,   792,   443,   793,   244,     0,     0,   794,
     996,     0,     0,  1061,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     406,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   937,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   952,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     969,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1001,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1016,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1046,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1072,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1092,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-1002))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      27,   133,   259,   187,   468,   414,   205,   206,    35,   440,
     150,   151,   152,   153,   295,   621,   213,    44,   174,   175,
     578,   147,   148,   617,   480,   254,   586,   685,   808,   809,
     490,   591,   492,   593,   594,   595,   761,   103,    65,    89,
      83,    85,    69,    70,    71,    72,    73,   191,   813,   600,
      25,   242,    85,  1046,   653,    86,   655,   656,   657,   550,
     295,    88,  1063,   159,   209,   223,   180,   181,   193,   898,
     261,   111,   481,   810,   811,   812,   217,   109,     9,  1072,
     221,   225,   113,   856,   857,  1071,  1087,   245,   115,   121,
     815,   131,    93,    94,    95,    96,   123,   124,   243,  1092,
     127,    13,   562,   268,   564,  1091,   271,   134,     0,   344,
     345,   142,   663,   878,    89,  1108,   149,   213,   243,   948,
     215,  1107,   859,     5,   268,     7,   319,   320,    12,   322,
     319,   320,  1118,   322,    10,   162,   329,   330,   732,   946,
     947,   762,   763,   193,   553,   189,   767,   282,   283,    11,
     875,   217,   119,   120,   121,   122,   183,   240,   241,     6,
      10,   147,     8,   214,     7,    10,   193,     6,   123,     6,
      47,     4,   830,   633,   201,   122,   376,     6,   784,   785,
     101,   372,   225,   146,   195,    46,   780,   781,   215,   680,
       6,   239,   209,   100,     6,   175,     6,     6,     6,     6,
     227,     6,   194,   347,     6,   203,     6,   155,   238,   236,
      67,     6,     6,   622,   174,     6,   205,     6,     6,   102,
     216,     6,     4,     6,    17,   154,     6,   683,   684,   237,
      66,     6,   790,    31,   208,   262,   192,   668,     6,     4,
       6,   179,    39,   270,   735,   736,   437,     6,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   697,   111,    39,   242,
      88,   415,     6,    35,   202,   407,   870,   686,     4,     6,
      91,     6,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
       4,   582,   583,   584,   585,   255,   587,   588,   589,   590,
      30,   592,     6,     6,   505,   596,   597,   598,   599,  1099,
     187,    24,   349,   917,     6,   919,   920,   783,    43,   204,
     739,     4,     6,    45,   531,   261,   827,   178,   482,   143,
     472,   473,     6,   133,    16,     6,   110,   153,   207,    34,
       6,   236,   233,   257,   254,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   602,   934,     6,   975,   786,   249,    90,
     871,     6,   873,   874,   665,   666,    95,   183,     6,   141,
     417,     6,   211,   117,   186,   235,    42,     6,     6,   998,
     231,   259,    99,     6,   260,    38,   157,   838,   968,     6,
     554,   543,     6,    93,   441,   547,     6,   145,     6,   169,
     851,     4,     6,   152,     6,     6,     6,     6,     6,     6,
     861,     6,     6,     6,     6,     6,   463,     6,   465,     6,
     637,     6,     6,     6,   644,   645,   646,   647,     6,   649,
     650,   651,   652,    38,   654,   581,  1055,   484,   658,   659,
     660,   661,   743,   603,     6,   694,     6,    59,  1028,   113,
       6,   232,   229,     6,     6,   105,   907,   263,   610,   623,
       6,     4,     4,   615,   223,     6,     6,   643,     6,   130,
       6,     6,     6,    53,     6,   115,     6,   230,   695,   698,
     201,     4,     6,   107,     6,   936,   533,   788,     4,   132,
       4,     4,   212,    44,   142,   744,    27,   168,   158,     6,
     720,   721,   227,   206,     6,     6,   957,    51,   251,   556,
     228,     6,   199,     6,   256,   182,     4,    94,   248,   671,
       4,   140,    55,   687,     6,   221,   678,   574,   116,     6,
     137,   222,     6,   984,     6,   234,   210,     6,   185,     6,
     197,   701,   163,   994,   200,   156,   258,    92,  1032,    98,
      26,     6,     6,    58,   714,   715,   716,   139,   144,     6,
      49,     6,   112,     6,   177,   198,   136,   787,    54,     4,
     219,    52,   262,     6,     6,   104,   740,   103,   625,   106,
     196,   733,    61,     6,    41,   244,   114,   226,   184,  1040,
     129,   138,   639,   275,   276,   171,    48,    50,   250,   189,
     125,   247,   220,     6,   119,     6,   766,     6,   165,     6,
       6,    60,   832,   295,   296,     6,   135,     6,   300,   301,
     302,   303,   304,   305,   306,   672,   843,   779,   128,  1080,
     312,   151,   314,   315,   119,     6,     6,  1088,   842,   888,
     127,   162,   689,    87,     6,   797,    97,  1098,   118,   218,
       6,   333,   189,     6,  1105,    29,   933,    57,   176,   150,
       6,   173,   344,   345,     6,   882,   348,     6,     4,     6,
     118,    40,   253,     6,   120,     4,   170,   926,    37,     6,
     188,   728,    86,    75,     6,   124,     4,   246,    96,   172,
       6,     6,     6,   164,   252,    85,    84,     6,   134,   108,
       4,    69,    21,     6,    65,  1006,     6,   224,    74,    73,
     188,   126,     4,     6,    79,    28,    23,   869,    56,     6,
     937,    68,     6,    71,   148,   167,     6,    82,   977,     6,
     241,   161,     6,     6,    36,     6,    81,    72,     6,     6,
      84,     6,    70,    77,    20,     4,    76,    64,   166,   160,
     999,   706,   969,    22,    78,   802,  1000,    80,   897,   699,
     240,   901,   754,  1061,   618,  1120,   866,   845,   551,   913,
    1082,   138,   708,   842,   747,  1054,   959,   995,   288,  1025,
     887,  1078,   801,   933,  1112,   903,   738,  1003,   367,   760,
     713,    76,   839,   828,   222,   772,   108,    61,    81,   974,
     406,   238,  1032,   748,   379,   748,   208,    -1,    -1,   748,
     962,    -1,    -1,  1033,   208,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   908,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   972,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1048,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1094
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   350,   362,    13,     0,   215,    10,    12,   351,
       5,     7,    11,     6,   580,    10,     8,   352,   147,   516,
     214,     7,    10,     6,   123,   467,   517,     6,   466,    47,
     391,     4,   356,   516,   122,     6,   390,   101,   444,   146,
     195,   561,   516,    46,     6,   443,   239,   604,   319,   320,
     322,   329,   330,   545,   643,   644,   645,   646,   647,   500,
     209,   499,   574,   516,   100,     6,   603,   175,   542,     6,
       6,     6,     6,     6,   194,   103,   217,   446,   581,     6,
     243,   503,   574,   607,   203,   568,   516,   238,     6,   541,
     155,   523,   516,   516,   516,   516,   516,   268,   271,   445,
     627,   628,   545,    67,   410,   575,     6,   193,   498,   560,
     607,     6,   568,   516,   174,     6,   522,   205,   570,   570,
     570,   570,   570,     6,     6,   102,   216,     6,   409,    17,
     363,     4,   358,   608,     6,   559,    89,   434,   485,   560,
     569,   568,   516,   154,     6,   237,   601,   601,   601,   601,
     601,   516,   516,   516,    66,     6,    31,   375,   208,   358,
     516,   192,     6,   433,    25,   370,   434,     4,   361,   568,
     571,     6,   179,   547,   547,   547,    39,   380,   380,   380,
     380,   380,   364,     6,   396,   111,   454,   486,   242,    39,
     382,   516,    88,     6,   369,    35,   377,   202,     4,   357,
     602,     6,   546,   255,   619,   619,   619,     6,    91,   435,
     435,   435,     4,   516,    30,     6,   453,   131,   454,   474,
       6,   187,   495,   554,   382,   516,    24,     6,   376,    43,
     387,   204,     4,   354,   516,   178,     6,   609,   261,   624,
     624,   624,   381,   548,   643,   644,   645,   133,   476,    45,
     388,   143,   512,    16,   561,   516,   110,     6,   153,   491,
     521,   383,     6,   553,   554,   207,   572,   382,   516,    34,
       6,   386,   233,   598,   236,   257,   620,   516,   254,   609,
     183,   549,   549,   549,   361,    90,     6,   249,   614,     6,
      95,   438,     6,   141,   510,   500,   117,   459,   475,   275,
     276,   295,   296,   300,   301,   302,   303,   304,   305,   306,
     312,   314,   315,   333,   344,   345,   348,   589,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   648,   649,   650,   651,   492,   521,   361,   516,
     186,     6,   235,   599,   211,   576,   382,   516,    42,     6,
     597,   231,   596,     6,   259,   622,    99,   441,   260,     6,
     157,   524,   524,   524,    38,   477,     6,   438,   389,     6,
      93,   436,   513,     6,   145,   514,   446,     6,   169,   493,
     536,     4,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     152,   159,   213,   526,   579,    38,   572,   573,     6,     6,
      59,   403,   113,   455,   382,   516,   232,     6,   595,   229,
     594,   621,     6,   263,   625,     6,   105,   447,   550,     6,
       4,   615,   436,     4,   439,     6,   361,   511,     6,   410,
     460,     6,   535,   536,   130,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,     6,   372,     6,   578,   223,   501,   586,
     599,   358,   600,   577,     6,    53,   397,     6,   115,   457,
     576,   382,   516,   230,     6,   593,   201,   567,     4,   355,
     623,     6,   442,     6,   107,   449,     4,   525,   132,     4,
      44,     4,   437,   142,   361,   515,    27,   371,   357,   516,
     168,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   516,
     158,   516,   212,     6,   592,   245,   586,   610,   227,   590,
     206,   358,   358,   404,     6,    51,   394,   456,     6,   251,
     616,   403,   576,   382,   516,   228,     6,   566,   199,   565,
     256,   355,   626,   355,   448,     6,   182,     4,   248,    94,
       4,   353,   140,   361,     6,   508,    55,   400,   478,   116,
     221,   584,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     137,   507,   561,   516,   222,     6,     6,   234,   210,   358,
     398,     6,   185,   552,   358,   458,     6,   552,   397,   163,
     529,   576,   382,   516,   200,     6,   564,   197,   563,   258,
     355,    98,   355,   450,   156,    92,   144,   516,    26,     6,
     399,   400,     6,   547,   446,   446,   446,   446,   584,   446,
     446,   446,   446,   584,   446,   584,   584,   584,   446,   446,
     446,   446,   546,   139,   509,   500,   380,   611,   591,    58,
     358,   395,     6,   551,    49,   393,   112,   358,   617,   393,
     394,     6,   177,   543,   455,   576,   382,   516,   198,     6,
     562,   262,   104,   355,   561,   516,    54,   585,   619,   410,
     410,   410,   410,   219,   582,   410,   410,   410,   410,   582,
     410,   582,   582,   582,   410,   410,   410,   410,   136,   546,
     446,   446,     4,   357,    52,   358,   516,   184,     6,   392,
     114,   358,   552,   530,     6,   403,   403,   457,   576,   382,
     516,   196,   106,   500,   561,   357,   624,   371,    61,   406,
     380,     6,    41,   384,   363,   129,   473,   473,   171,   537,
     537,   380,   380,   380,   490,   138,   410,   410,   244,   226,
      50,   189,   497,   557,   516,    48,   250,   393,   358,   544,
     552,   552,   125,   468,   529,   576,   382,   446,   500,   220,
     478,   405,   631,   649,   650,   247,   612,   583,     6,   119,
     462,   375,     6,   472,   487,   488,     6,   165,   531,   531,
     406,   612,   612,   151,   520,   380,   612,     6,    85,   424,
     557,   496,   162,   358,   393,   393,     6,   403,   455,   455,
     576,   410,   446,    60,     6,   135,   505,   358,   385,     6,
     461,   494,   486,   516,   128,   119,   463,   109,   121,   451,
     465,   538,     6,   494,   494,   505,   505,   505,   589,   406,
     479,   558,     6,    87,   427,   189,   489,   555,   176,   469,
     552,   543,   127,   470,   457,   410,   613,     6,    97,   440,
     218,   357,   516,   118,   173,   502,   540,   474,   561,   461,
       6,     6,   464,    29,   373,   357,   532,   253,   504,   618,
     440,   440,   150,   505,    57,   401,   357,   425,     6,   426,
     483,     6,   149,   424,   518,   358,   393,   552,     6,   552,
     552,   406,     4,   506,   589,    40,   561,     6,   539,    83,
     225,   420,   588,   491,   500,   118,   452,   516,   120,     6,
     170,     4,   359,   372,   618,    37,   378,   378,   504,     6,
     188,   357,   516,    86,    75,   414,   480,   556,     6,   427,
     124,   393,   471,   393,   393,   246,     4,    96,   500,   516,
     172,     6,     6,   587,   492,   584,   357,   561,   374,   164,
     252,     6,   476,   476,   402,    84,    85,   422,     6,   432,
      69,   411,   482,   357,   519,   483,   358,   134,   584,   561,
     421,   516,   224,   579,   582,   108,   500,     4,   360,   379,
      21,   365,   357,     6,    65,   407,   516,    74,     6,   428,
      73,   413,   481,   188,   357,   480,   126,   582,   500,   353,
     167,   533,   501,   446,    28,     4,     6,    23,   367,    56,
     423,     6,   241,   605,    79,   416,   516,    68,     6,   429,
      71,   412,   484,   148,   482,   584,    82,     6,   161,   527,
     610,   410,    36,   366,     6,   357,   408,     6,     6,    81,
     418,   416,   516,    72,     6,   430,    77,   415,   481,   582,
     534,     6,   384,   360,   368,    84,   358,   606,   417,     6,
     418,   416,   516,    70,     6,   431,   484,   357,   528,   462,
      20,     4,    64,   360,   357,   419,   418,   416,   516,    76,
     166,   357,   494,    22,   240,    78,   357,   418,   416,   160,
     502,    80,   418,   420
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {(yyval.SOAPFileVal) = new SOAPFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForSOAPVal), (yyvsp[(4) - (5)].SOAPTypeVal));
	   SOAPTree = (yyval.SOAPFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
    break;

  case 3:

    {(yyval.XmlHeaderForSOAPVal) = new XmlHeaderForSOAP((yyvsp[(3) - (3)].SchemaLocationVal));}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal), true);
	    if (strncmp("urn:kitting ", (yyvsp[(2) - (2)].sVal), 12))
	      {
		fprintf(stderr,
	           "wrong targetNamespace in schema location %s\n", (yyvsp[(2) - (2)].sVal));
		exit(1);
	      }
	  }
    break;

  case 5:

    {(yyval.XmlBooleanVal) = new XmlBoolean((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlBooleanVal)->bad)
	     yyerror("bad XmlBoolean");
	  }
    break;

  case 6:

    {(yyval.XmlDateTimeVal) = new XmlDateTime((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDateTimeVal)->bad)
	     yyerror("bad XmlDateTime");
	  }
    break;

  case 7:

    {(yyval.XmlDecimalVal) = new XmlDecimal((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDecimalVal)->bad)
	     yyerror("bad XmlDecimal");
	  }
    break;

  case 8:

    {(yyval.XmlIDVal) = new XmlID((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDVal)->bad)
	     yyerror("bad XmlID");
	  }
    break;

  case 9:

    {(yyval.XmlIDREFVal) = new XmlIDREF((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDREFVal)->bad)
	     yyerror("bad XmlIDREF");
	  }
    break;

  case 10:

    {(yyval.XmlNMTOKENVal) = new XmlNMTOKEN((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNMTOKENVal)->bad)
	     yyerror("bad XmlNMTOKEN");
	  }
    break;

  case 11:

    {(yyval.XmlNonNegativeIntegerVal) = new XmlNonNegativeInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNonNegativeIntegerVal)->bad)
	     yyerror("bad XmlNonNegativeInteger");
	  }
    break;

  case 12:

    {(yyval.XmlPositiveIntegerVal) = new XmlPositiveInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlPositiveIntegerVal)->bad)
	     yyerror("bad XmlPositiveInteger");
	  }
    break;

  case 13:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  }
    break;

  case 14:

    {(yyval.XmlVersionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  }
    break;

  case 15:

    {(yyval.XmlVersionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp((yyvsp[(5) - (6)].sVal), "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  }
    break;

  case 16:

    {yyReadData = 1;}
    break;

  case 17:

    {(yyval.AngleUnitTypeVal) = new AngleUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.AngleUnitTypeVal)->bad)
	     yyerror("bad AngleUnit value");
	  }
    break;

  case 18:

    {yyReadData = 1;}
    break;

  case 19:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 20:

    {yyReadData = 1;}
    break;

  case 21:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad ArrayRadius value");
	  }
    break;

  case 22:

    {(yyval.AttachEndEffectorTypeVal) = new AttachEndEffectorType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].XmlStringVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].XmlNMTOKENVal), (yyvsp[(6) - (9)].XmlNMTOKENVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].PreconditionTypeVal), (yyvsp[(9) - (9)].EffectTypeVal));}
    break;

  case 23:

    {(yyval.AttachEndEffectorTypeVal) = (yyvsp[(2) - (3)].AttachEndEffectorTypeVal);}
    break;

  case 24:

    {(yyval.MechanicalComponentTypeVal) = (yyvsp[(2) - (3)].MechanicalComponentTypeVal);}
    break;

  case 25:

    {(yyval.BoxVolumeTypeVal) = new BoxVolumeType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PointTypeVal), (yyvsp[(4) - (4)].PointTypeVal));}
    break;

  case 26:

    {yyReadData = 1;}
    break;

  case 27:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 28:

    {(yyval.EndEffectorChangingStationTypeVal) = (yyvsp[(2) - (3)].EndEffectorChangingStationTypeVal);}
    break;

  case 29:

    {(yyval.CreateKitTypeVal) = new CreateKitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].XmlStringVal), (yyvsp[(4) - (8)].XmlNMTOKENVal), (yyvsp[(5) - (8)].XmlNMTOKENVal), (yyvsp[(6) - (8)].XmlNMTOKENVal), (yyvsp[(7) - (8)].PreconditionTypeVal), (yyvsp[(8) - (8)].EffectTypeVal));}
    break;

  case 30:

    {(yyval.CreateKitTypeVal) = (yyvsp[(2) - (3)].CreateKitTypeVal);}
    break;

  case 31:

    {yyReadData = 1;}
    break;

  case 32:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad CupDiameter value");
	  }
    break;

  case 33:

    {yyReadData = 1;}
    break;

  case 34:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 35:

    {(yyval.XmlStringVal) = 0;}
    break;

  case 36:

    {yyReadData = 1;}
    break;

  case 37:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 38:

    {yyReadData = 1;}
    break;

  case 39:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 40:

    {(yyval.DetachEndEffectorTypeVal) = new DetachEndEffectorType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].XmlStringVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].XmlNMTOKENVal), (yyvsp[(6) - (9)].XmlNMTOKENVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].PreconditionTypeVal), (yyvsp[(9) - (9)].EffectTypeVal));}
    break;

  case 41:

    {(yyval.DetachEndEffectorTypeVal) = (yyvsp[(2) - (3)].DetachEndEffectorTypeVal);}
    break;

  case 42:

    {yyReadData = 1;}
    break;

  case 43:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Diameter value");
	  }
    break;

  case 44:

    {(yyval.DomainTypeVal) = new DomainType((yyvsp[(2) - (15)].XmlIDVal), (yyvsp[(3) - (15)].ListXmlNMTOKENVal), (yyvsp[(4) - (15)].ListXmlNMTOKENVal), (yyvsp[(5) - (15)].ListPredicateTypeVal), (yyvsp[(6) - (15)].ListFunctionTypeVal), (yyvsp[(7) - (15)].AttachEndEffectorTypeVal), (yyvsp[(8) - (15)].CreateKitTypeVal), (yyvsp[(9) - (15)].DetachEndEffectorTypeVal), (yyvsp[(10) - (15)].TakePartTypeVal), (yyvsp[(11) - (15)].TakeKitTypeVal), (yyvsp[(12) - (15)].TakeKitTrayTypeVal), (yyvsp[(13) - (15)].PutPartTypeVal), (yyvsp[(14) - (15)].PutKitTypeVal), (yyvsp[(15) - (15)].PutKitTrayTypeVal));}
    break;

  case 45:

    {(yyval.DomainTypeVal) = (yyvsp[(2) - (3)].DomainTypeVal);}
    break;

  case 46:

    {(yyval.EffectTypeVal) = new EffectType((yyvsp[(2) - (11)].XmlIDVal), (yyvsp[(3) - (11)].ListXmlIDREFVal), (yyvsp[(4) - (11)].ListXmlIDREFVal), (yyvsp[(5) - (11)].XmlIDREFVal), (yyvsp[(6) - (11)].FunctionOperationTypeVal), (yyvsp[(7) - (11)].ListFunctionToFunctionLessTypeVal), (yyvsp[(8) - (11)].ListFunctionToFunctionEqualTypeVal), (yyvsp[(9) - (11)].ListFunctionToFunctionGreaterOrEqualTypeVal), (yyvsp[(10) - (11)].ListFunctionToFunctionGreaterTypeVal), (yyvsp[(11) - (11)].ListFunctionToFunctionLessOrEqualTypeVal));}
    break;

  case 47:

    {(yyval.EffectTypeVal) = (yyvsp[(2) - (3)].EffectTypeVal);}
    break;

  case 48:

    {yyReadData =
	  1;}
    break;

  case 49:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 50:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].MechanicalComponentTypeVal), (yyvsp[(8) - (8)].ListEndEffectorHolderTypeVal));}
    break;

  case 51:

    {yyReadData = 1;}
    break;

  case 52:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 53:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].EndEffectorTypeVal));}
    break;

  case 54:

    {(yyval.EndEffectorHolderTypeVal) = (yyvsp[(2) - (3)].EndEffectorHolderTypeVal);}
    break;

  case 55:

    {yyReadData = 1;}
    break;

  case 56:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 57:

    {yyReadData = 1;}
    break;

  case 58:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 59:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);}
    break;

  case 60:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);}
    break;

  case 61:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);}
    break;

  case 62:

    {(yyval.EndEffectorTypeVal) = 0;}
    break;

  case 63:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);}
    break;

  case 64:

    {yyReadData = 1;}
    break;

  case 65:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 66:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].PoseLocationTypeVal), (yyvsp[(5) - (7)].XmlStringVal), (yyvsp[(6) - (7)].XmlStringVal), (yyvsp[(7) - (7)].XmlStringVal));}
    break;

  case 67:

    {(yyval.ExternalShapeTypeVal) = 0;}
    break;

  case 68:

    {(yyval.ExternalShapeTypeVal) = (yyvsp[(2) - (3)].ExternalShapeTypeVal);}
    break;

  case 69:

    {(yyval.FunctionToFunctionEqualTypeVal) = (yyvsp[(2) - (3)].FunctionToFunctionEqualTypeVal);}
    break;

  case 70:

    {(yyval.FunctionToFunctionGreaterTypeVal) = (yyvsp[(2) - (3)].FunctionToFunctionGreaterTypeVal);}
    break;

  case 71:

    {(yyval.FunctionToFunctionGreaterOrEqualTypeVal) = (yyvsp[(2) - (3)].FunctionToFunctionGreaterOrEqualTypeVal);}
    break;

  case 72:

    {(yyval.FunctionToFunctionLessTypeVal) = (yyvsp[(2) - (3)].FunctionToFunctionLessTypeVal);}
    break;

  case 73:

    {(yyval.FunctionToFunctionLessOrEqualTypeVal) = (yyvsp[(2) - (3)].FunctionToFunctionLessOrEqualTypeVal);}
    break;

  case 74:

    {yyReadData = 1;}
    break;

  case 75:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 76:

    {yyReadData = 1;}
    break;

  case 77:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 78:

    {yyReadData = 1;}
    break;

  case 79:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);}
    break;

  case 80:

    {yyReadData = 1;}
    break;

  case 81:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 82:

    {(yyval.XmlIDREFVal) = 0;}
    break;

  case 83:

    {yyReadData = 1;}
    break;

  case 84:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 85:

    {(yyval.FunctionOperationTypeVal) = new FunctionOperationType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlIDREFVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlPositiveIntegerVal));}
    break;

  case 86:

    {(yyval.FunctionOperationTypeVal) = 0;}
    break;

  case 87:

    {(yyval.FunctionOperationTypeVal) = (yyvsp[(2) - (3)].FunctionOperationTypeVal);}
    break;

  case 88:

    {(yyval.FunctionToFunctionEqualTypeVal) = new FunctionToFunctionEqualType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 89:

    {(yyval.FunctionToFunctionGreaterOrEqualTypeVal) = new FunctionToFunctionGreaterOrEqualType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 90:

    {(yyval.FunctionToFunctionGreaterTypeVal) = new FunctionToFunctionGreaterType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 91:

    {(yyval.FunctionToFunctionLessOrEqualTypeVal) = new FunctionToFunctionLessOrEqualType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 92:

    {(yyval.FunctionToFunctionLessTypeVal) = new FunctionToFunctionLessType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 93:

    {(yyval.FunctionTypeVal) = new FunctionType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlStringVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));}
    break;

  case 94:

    {(yyval.FunctionTypeVal) = (yyvsp[(2) - (3)].FunctionTypeVal);}
    break;

  case 95:

    {(yyval.PoseLocationTypeVal) = 0;}
    break;

  case 96:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(2) - (3)].PoseLocationTypeVal);}
    break;

  case 97:

    {yyReadData = 1;}
    break;

  case 98:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);}
    break;

  case 99:

    {yyReadData = 1;}
    break;

  case 100:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  }
    break;

  case 101:

    {(yyval.SolidObjectTypeVal) = 0;}
    break;

  case 102:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);}
    break;

  case 103:

    {yyReadData = 1;}
    break;

  case 104:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 105:

    {(yyval.InContactWithTypeVal) = new InContactWithType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));}
    break;

  case 106:

    {(yyval.InContactWithTypeVal) = (yyvsp[(2) - (3)].InContactWithTypeVal);}
    break;

  case 107:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);}
    break;

  case 108:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].CylindricalShapeTypeVal);}
    break;

  case 109:

    {(yyval.InternalShapeTypeVal) = 0;}
    break;

  case 110:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(2) - (3)].InternalShapeTypeVal);}
    break;

  case 111:

    {yyReadData = 1;}
    break;

  case 112:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 113:

    {yyReadData = 1;}
    break;

  case 114:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 115:

    {yyReadData = 1;}
    break;

  case 116:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 117:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].ListPartRefAndPoseTypeVal));}
    break;

  case 118:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);}
    break;

  case 119:

    {yyReadData = 1;}
    break;

  case 120:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 121:

    {yyReadData = 1;}
    break;

  case 122:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 123:

    {yyReadData = 1;}
    break;

  case 124:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 125:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));}
    break;

  case 126:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);}
    break;

  case 127:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);}
    break;

  case 128:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (11)].XmlIDVal), (yyvsp[(3) - (11)].PhysicalLocationTypeVal), (yyvsp[(4) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (11)].InternalShapeTypeVal), (yyvsp[(6) - (11)].ExternalShapeTypeVal), (yyvsp[(7) - (11)].XmlIDREFVal), (yyvsp[(8) - (11)].KitTrayTypeVal), (yyvsp[(9) - (11)].ListPartTypeVal), (yyvsp[(10) - (11)].ListSlotTypeVal), (yyvsp[(11) - (11)].XmlBooleanVal));}
    break;

  case 129:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);}
    break;

  case 130:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (15)].XmlIDVal), (yyvsp[(3) - (15)].PhysicalLocationTypeVal), (yyvsp[(4) - (15)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (15)].InternalShapeTypeVal), (yyvsp[(6) - (15)].ExternalShapeTypeVal), (yyvsp[(7) - (15)].AngleUnitTypeVal), (yyvsp[(8) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(9) - (15)].ListKitDesignTypeVal), (yyvsp[(10) - (15)].LengthUnitTypeVal), (yyvsp[(11) - (15)].ListSolidObjectTypeVal), (yyvsp[(12) - (15)].ListBoxVolumeTypeVal), (yyvsp[(13) - (15)].RobotTypeVal), (yyvsp[(14) - (15)].ListStockKeepingUnitTypeVal), (yyvsp[(15) - (15)].WeightUnitTypeVal));}
    break;

  case 131:

    {(yyval.KittingWorkstationTypeVal) = (yyvsp[(2) - (3)].KittingWorkstationTypeVal);}
    break;

  case 132:

    {yyReadData = 1;}
    break;

  case 133:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 134:

    {yyReadData = 1;}
    break;

  case 135:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 136:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));}
    break;

  case 137:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);}
    break;

  case 138:

    {yyReadData = 1;}
    break;

  case 139:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  }
    break;

  case 140:

    {yyReadData = 1;}
    break;

  case 141:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  }
    break;

  case 142:

    {(yyval.ListEndEffectorHolderTypeVal) = new std::list<EndEffectorHolderType *>;
	   (yyval.ListEndEffectorHolderTypeVal)->push_back((yyvsp[(1) - (1)].EndEffectorHolderTypeVal));}
    break;

  case 143:

    {(yyval.ListEndEffectorHolderTypeVal) = (yyvsp[(1) - (2)].ListEndEffectorHolderTypeVal);
	   (yyval.ListEndEffectorHolderTypeVal)->push_back((yyvsp[(2) - (2)].EndEffectorHolderTypeVal));}
    break;

  case 144:

    {(yyval.ListXmlIDREFVal) = new std::list<XmlIDREF *>;}
    break;

  case 145:

    {(yyval.ListXmlIDREFVal) = (yyvsp[(1) - (2)].ListXmlIDREFVal);
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));}
    break;

  case 146:

    {(yyval.ListFunctionToFunctionEqualTypeVal) = new std::list<FunctionToFunctionEqualType *>;}
    break;

  case 147:

    {(yyval.ListFunctionToFunctionEqualTypeVal) = (yyvsp[(1) - (2)].ListFunctionToFunctionEqualTypeVal);
	   (yyval.ListFunctionToFunctionEqualTypeVal)->push_back((yyvsp[(2) - (2)].FunctionToFunctionEqualTypeVal));}
    break;

  case 148:

    {(yyval.ListFunctionToFunctionGreaterTypeVal) = new std::list<FunctionToFunctionGreaterType *>;}
    break;

  case 149:

    {(yyval.ListFunctionToFunctionGreaterTypeVal) = (yyvsp[(1) - (2)].ListFunctionToFunctionGreaterTypeVal);
	   (yyval.ListFunctionToFunctionGreaterTypeVal)->push_back((yyvsp[(2) - (2)].FunctionToFunctionGreaterTypeVal));}
    break;

  case 150:

    {(yyval.ListFunctionToFunctionGreaterOrEqualTypeVal) = new std::list<FunctionToFunctionGreaterOrEqualType *>;}
    break;

  case 151:

    {(yyval.ListFunctionToFunctionGreaterOrEqualTypeVal) = (yyvsp[(1) - (2)].ListFunctionToFunctionGreaterOrEqualTypeVal);
	   (yyval.ListFunctionToFunctionGreaterOrEqualTypeVal)->push_back((yyvsp[(2) - (2)].FunctionToFunctionGreaterOrEqualTypeVal));}
    break;

  case 152:

    {(yyval.ListFunctionToFunctionLessTypeVal) = new std::list<FunctionToFunctionLessType *>;}
    break;

  case 153:

    {(yyval.ListFunctionToFunctionLessTypeVal) = (yyvsp[(1) - (2)].ListFunctionToFunctionLessTypeVal);
	   (yyval.ListFunctionToFunctionLessTypeVal)->push_back((yyvsp[(2) - (2)].FunctionToFunctionLessTypeVal));}
    break;

  case 154:

    {(yyval.ListFunctionToFunctionLessOrEqualTypeVal) = new std::list<FunctionToFunctionLessOrEqualType *>;}
    break;

  case 155:

    {(yyval.ListFunctionToFunctionLessOrEqualTypeVal) = (yyvsp[(1) - (2)].ListFunctionToFunctionLessOrEqualTypeVal);
	   (yyval.ListFunctionToFunctionLessOrEqualTypeVal)->push_back((yyvsp[(2) - (2)].FunctionToFunctionLessOrEqualTypeVal));}
    break;

  case 156:

    {(yyval.ListFunctionTypeVal) = new std::list<FunctionType *>;
	   (yyval.ListFunctionTypeVal)->push_back((yyvsp[(1) - (1)].FunctionTypeVal));}
    break;

  case 157:

    {(yyval.ListFunctionTypeVal) = (yyvsp[(1) - (2)].ListFunctionTypeVal);
	   (yyval.ListFunctionTypeVal)->push_back((yyvsp[(2) - (2)].FunctionTypeVal));}
    break;

  case 158:

    {(yyval.ListKitDesignTypeVal) = new std::list<KitDesignType *>;
	   (yyval.ListKitDesignTypeVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));}
    break;

  case 159:

    {(yyval.ListKitDesignTypeVal) = (yyvsp[(1) - (2)].ListKitDesignTypeVal);
	   (yyval.ListKitDesignTypeVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));}
    break;

  case 160:

    {(yyval.ListKitTrayTypeVal) = new std::list<KitTrayType *>;}
    break;

  case 161:

    {(yyval.ListKitTrayTypeVal) = (yyvsp[(1) - (2)].ListKitTrayTypeVal);
	   (yyval.ListKitTrayTypeVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));}
    break;

  case 162:

    {(yyval.ListKitTypeVal) = new std::list<KitType *>;}
    break;

  case 163:

    {(yyval.ListKitTypeVal) = (yyvsp[(1) - (2)].ListKitTypeVal);
	   (yyval.ListKitTypeVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));}
    break;

  case 164:

    {(yyval.ListXmlIDREFVal) = new std::list<XmlIDREF *>;}
    break;

  case 165:

    {(yyval.ListXmlIDREFVal) = (yyvsp[(1) - (2)].ListXmlIDREFVal);
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));}
    break;

  case 166:

    {(yyval.ListSolidObjectTypeVal) = new std::list<SolidObjectType *>;}
    break;

  case 167:

    {(yyval.ListSolidObjectTypeVal) = (yyvsp[(1) - (2)].ListSolidObjectTypeVal);
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));}
    break;

  case 168:

    {(yyval.ListSolidObjectTypeVal) = (yyvsp[(1) - (2)].ListSolidObjectTypeVal);
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));}
    break;

  case 169:

    {(yyval.ListSolidObjectTypeVal) = new std::list<SolidObjectType *>;
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));}
    break;

  case 170:

    {(yyval.ListBoxVolumeTypeVal) = new std::list<BoxVolumeType *>;}
    break;

  case 171:

    {(yyval.ListBoxVolumeTypeVal) = (yyvsp[(1) - (2)].ListBoxVolumeTypeVal);
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));}
    break;

  case 172:

    {(yyval.ListPartRefAndPoseTypeVal) = (yyvsp[(1) - (2)].ListPartRefAndPoseTypeVal);
	   (yyval.ListPartRefAndPoseTypeVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));}
    break;

  case 173:

    {(yyval.ListPartRefAndPoseTypeVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.ListPartRefAndPoseTypeVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));}
    break;

  case 174:

    {(yyval.ListPartTypeVal) = new std::list<PartType *>;}
    break;

  case 175:

    {(yyval.ListPartTypeVal) = (yyvsp[(1) - (2)].ListPartTypeVal);
	   (yyval.ListPartTypeVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));}
    break;

  case 176:

    {(yyval.ListPredicateGroupElementTypeVal) = (yyvsp[(1) - (2)].ListPredicateGroupElementTypeVal);
	   (yyval.ListPredicateGroupElementTypeVal)->push_back((yyvsp[(2) - (2)].PredicateGroupElementTypeVal));}
    break;

  case 177:

    {(yyval.ListPredicateGroupElementTypeVal) = new std::list<PredicateGroupElementType *>;
	   (yyval.ListPredicateGroupElementTypeVal)->push_back((yyvsp[(1) - (1)].PredicateGroupElementTypeVal));}
    break;

  case 178:

    {(yyval.ListXmlIDREFVal) = new std::list<XmlIDREF *>;}
    break;

  case 179:

    {(yyval.ListXmlIDREFVal) = (yyvsp[(1) - (2)].ListXmlIDREFVal);
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));}
    break;

  case 180:

    {(yyval.ListXmlIDREFVal) = (yyvsp[(1) - (2)].ListXmlIDREFVal);
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));}
    break;

  case 181:

    {(yyval.ListXmlIDREFVal) = new std::list<XmlIDREF *>;
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(1) - (1)].XmlIDREFVal));}
    break;

  case 182:

    {(yyval.ListPredicateTypeVal) = (yyvsp[(1) - (2)].ListPredicateTypeVal);
	   (yyval.ListPredicateTypeVal)->push_back((yyvsp[(2) - (2)].PredicateTypeVal));}
    break;

  case 183:

    {(yyval.ListPredicateTypeVal) = new std::list<PredicateType *>;
	   (yyval.ListPredicateTypeVal)->push_back((yyvsp[(1) - (1)].PredicateTypeVal));}
    break;

  case 184:

    {(yyval.ListXmlNMTOKENVal) = (yyvsp[(1) - (2)].ListXmlNMTOKENVal);
	   (yyval.ListXmlNMTOKENVal)->push_back((yyvsp[(2) - (2)].XmlNMTOKENVal));}
    break;

  case 185:

    {(yyval.ListXmlNMTOKENVal) = new std::list<XmlNMTOKEN *>;
	   (yyval.ListXmlNMTOKENVal)->push_back((yyvsp[(1) - (1)].XmlNMTOKENVal));}
    break;

  case 186:

    {(yyval.ListPhysicalLocationTypeVal) = new std::list<PhysicalLocationType *>;}
    break;

  case 187:

    {(yyval.ListPhysicalLocationTypeVal) = (yyvsp[(1) - (2)].ListPhysicalLocationTypeVal);
	   (yyval.ListPhysicalLocationTypeVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));}
    break;

  case 188:

    {(yyval.ListStockKeepingUnitTypeVal) = (yyvsp[(1) - (2)].ListStockKeepingUnitTypeVal);
	   (yyval.ListStockKeepingUnitTypeVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));}
    break;

  case 189:

    {(yyval.ListStockKeepingUnitTypeVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.ListStockKeepingUnitTypeVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));}
    break;

  case 190:

    {(yyval.ListSlotTypeVal) = new std::list<SlotType *>;}
    break;

  case 191:

    {(yyval.ListSlotTypeVal) = (yyvsp[(1) - (2)].ListSlotTypeVal);
	   (yyval.ListSlotTypeVal)->push_back((yyvsp[(2) - (2)].SlotTypeVal));}
    break;

  case 192:

    {(yyval.ListXmlNMTOKENVal) = (yyvsp[(1) - (2)].ListXmlNMTOKENVal);
	   (yyval.ListXmlNMTOKENVal)->push_back((yyvsp[(2) - (2)].XmlNMTOKENVal));}
    break;

  case 193:

    {(yyval.ListXmlNMTOKENVal) = new std::list<XmlNMTOKEN *>;
	   (yyval.ListXmlNMTOKENVal)->push_back((yyvsp[(1) - (1)].XmlNMTOKENVal));}
    break;

  case 194:

    {(yyval.ListBoxVolumeTypeVal) = (yyvsp[(1) - (2)].ListBoxVolumeTypeVal);
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));}
    break;

  case 195:

    {(yyval.ListBoxVolumeTypeVal) = new std::list<BoxVolumeType *>;
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));}
    break;

  case 196:

    {yyReadData = 1;}
    break;

  case 197:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  }
    break;

  case 198:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 199:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));}
    break;

  case 200:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 201:

    {yyReadData = 1;}
    break;

  case 202:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 203:

    {yyReadData = 1;}
    break;

  case 204:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 205:

    {(yyval.XmlStringVal) = 0;}
    break;

  case 206:

    {yyReadData = 1;}
    break;

  case 207:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 208:

    {yyReadData = 1;}
    break;

  case 209:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);}
    break;

  case 210:

    {yyReadData = 1;}
    break;

  case 211:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 212:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);}
    break;

  case 213:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);}
    break;

  case 214:

    {(yyval.OnTopWithContactTypeVal) = new OnTopWithContactType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));}
    break;

  case 215:

    {(yyval.OnTopWithContactTypeVal) = (yyvsp[(2) - (3)].OnTopWithContactTypeVal);}
    break;

  case 216:

    {(yyval.PositiveDecimalTypeVal) = 0;}
    break;

  case 217:

    {yyReadData = 1;}
    break;

  case 218:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  }
    break;

  case 219:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);}
    break;

  case 220:

    {(yyval.XmlIDREFVal) = 0;}
    break;

  case 221:

    {yyReadData = 1;}
    break;

  case 222:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 223:

    {yyReadData = 1;}
    break;

  case 224:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 225:

    {yyReadData = 1;}
    break;

  case 226:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);}
    break;

  case 227:

    {yyReadData = 1;}
    break;

  case 228:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 229:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));}
    break;

  case 230:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);}
    break;

  case 231:

    {yyReadData = 1;}
    break;

  case 232:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 233:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));}
    break;

  case 234:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);}
    break;

  case 235:

    {(yyval.PartiallyInTypeVal) = new PartiallyInType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));}
    break;

  case 236:

    {(yyval.PartiallyInTypeVal) = (yyvsp[(2) - (3)].PartiallyInTypeVal);}
    break;

  case 237:

    {yyReadData = 1;}
    break;

  case 238:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 239:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);}
    break;

  case 240:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);}
    break;

  case 241:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);}
    break;

  case 242:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);}
    break;

  case 243:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);}
    break;

  case 244:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));}
    break;

  case 245:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 246:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);}
    break;

  case 247:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);}
    break;

  case 248:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);}
    break;

  case 249:

    {(yyval.PositiveDecimalTypeVal) = 0;}
    break;

  case 250:

    {yyReadData = 1;}
    break;

  case 251:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  }
    break;

  case 252:

    {(yyval.PreconditionTypeVal) = new PreconditionType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].ListXmlIDREFVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].FunctionOperationTypeVal), (yyvsp[(6) - (10)].ListFunctionToFunctionLessTypeVal), (yyvsp[(7) - (10)].ListFunctionToFunctionEqualTypeVal), (yyvsp[(8) - (10)].ListFunctionToFunctionGreaterOrEqualTypeVal), (yyvsp[(9) - (10)].ListFunctionToFunctionGreaterTypeVal), (yyvsp[(10) - (10)].ListFunctionToFunctionLessOrEqualTypeVal));}
    break;

  case 253:

    {(yyval.PreconditionTypeVal) = (yyvsp[(2) - (3)].PreconditionTypeVal);}
    break;

  case 254:

    {(yyval.PredicateGroupElementTypeVal) = new PredicateGroupElementType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlNMTOKENVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlIDREFVal));}
    break;

  case 255:

    {(yyval.PredicateGroupElementTypeVal) = (yyvsp[(2) - (3)].PredicateGroupElementTypeVal);}
    break;

  case 256:

    {yyReadData = 1;}
    break;

  case 257:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 258:

    {yyReadData = 1;}
    break;

  case 259:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 260:

    {(yyval.PredicateTypeVal) = new PredicateType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlStringVal), (yyvsp[(4) - (4)].ListPredicateGroupElementTypeVal));}
    break;

  case 261:

    {(yyval.PredicateTypeVal) = (yyvsp[(2) - (3)].PredicateTypeVal);}
    break;

  case 262:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);}
    break;

  case 263:

    {(yyval.PutKitTrayTypeVal) = new PutKitTrayType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].XmlNMTOKENVal), (yyvsp[(5) - (7)].XmlNMTOKENVal), (yyvsp[(6) - (7)].PreconditionTypeVal), (yyvsp[(7) - (7)].EffectTypeVal));}
    break;

  case 264:

    {(yyval.PutKitTrayTypeVal) = (yyvsp[(2) - (3)].PutKitTrayTypeVal);}
    break;

  case 265:

    {(yyval.PutKitTypeVal) = new PutKitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].XmlStringVal), (yyvsp[(4) - (8)].XmlNMTOKENVal), (yyvsp[(5) - (8)].XmlNMTOKENVal), (yyvsp[(6) - (8)].XmlNMTOKENVal), (yyvsp[(7) - (8)].PreconditionTypeVal), (yyvsp[(8) - (8)].EffectTypeVal));}
    break;

  case 266:

    {(yyval.PutKitTypeVal) = (yyvsp[(2) - (3)].PutKitTypeVal);}
    break;

  case 267:

    {(yyval.PutPartTypeVal) = new PutPartType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].XmlStringVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].XmlNMTOKENVal), (yyvsp[(6) - (9)].XmlNMTOKENVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].PreconditionTypeVal), (yyvsp[(9) - (9)].EffectTypeVal));}
    break;

  case 268:

    {(yyval.PutPartTypeVal) = (yyvsp[(2) - (3)].PutPartTypeVal);}
    break;

  case 269:

    {yyReadData = 1;}
    break;

  case 270:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 271:

    {yyReadData = 1;}
    break;

  case 272:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 273:

    {yyReadData = 1;}
    break;

  case 274:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 275:

    {yyReadData = 1;}
    break;

  case 276:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 277:

    {yyReadData = 1;}
    break;

  case 278:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 279:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].ListBoxVolumeTypeVal));}
    break;

  case 280:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);}
    break;

  case 281:

    {(yyval.SOAPTypeVal) = new SOAPType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].KittingWorkstationTypeVal), (yyvsp[(4) - (8)].DomainTypeVal), (yyvsp[(5) - (8)].InContactWithTypeVal), (yyvsp[(6) - (8)].UnderWithContactTypeVal), (yyvsp[(7) - (8)].PartiallyInTypeVal), (yyvsp[(8) - (8)].OnTopWithContactTypeVal));}
    break;

  case 282:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);}
    break;

  case 283:

    {yyReadData = 1;}
    break;

  case 284:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 285:

    {yyReadData = 1;}
    break;

  case 286:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 287:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);}
    break;

  case 288:

    {(yyval.SlotTypeVal) = new SlotType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));}
    break;

  case 289:

    {(yyval.SlotTypeVal) = (yyvsp[(2) - (3)].SlotTypeVal);}
    break;

  case 290:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);}
    break;

  case 291:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);}
    break;

  case 292:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);}
    break;

  case 293:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].HumanTypeVal);}
    break;

  case 294:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);}
    break;

  case 295:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);}
    break;

  case 296:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);}
    break;

  case 297:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);}
    break;

  case 298:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);}
    break;

  case 299:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);}
    break;

  case 300:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);}
    break;

  case 301:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);}
    break;

  case 302:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);}
    break;

  case 303:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);}
    break;

  case 304:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);}
    break;

  case 305:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);}
    break;

  case 306:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);}
    break;

  case 307:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);}
    break;

  case 308:

    {(yyval.XmlIDREFVal) = 0;}
    break;

  case 309:

    {yyReadData = 1;}
    break;

  case 310:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 311:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].InternalShapeTypeVal), (yyvsp[(5) - (7)].ExternalShapeTypeVal), (yyvsp[(6) - (7)].PositiveDecimalTypeVal), (yyvsp[(7) - (7)].ListXmlIDREFVal));}
    break;

  case 312:

    {(yyval.TakeKitTrayTypeVal) = new TakeKitTrayType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].XmlStringVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].XmlNMTOKENVal), (yyvsp[(6) - (9)].XmlNMTOKENVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].PreconditionTypeVal), (yyvsp[(9) - (9)].EffectTypeVal));}
    break;

  case 313:

    {(yyval.TakeKitTrayTypeVal) = (yyvsp[(2) - (3)].TakeKitTrayTypeVal);}
    break;

  case 314:

    {(yyval.TakeKitTypeVal) = new TakeKitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].XmlStringVal), (yyvsp[(4) - (8)].XmlNMTOKENVal), (yyvsp[(5) - (8)].XmlNMTOKENVal), (yyvsp[(6) - (8)].XmlNMTOKENVal), (yyvsp[(7) - (8)].PreconditionTypeVal), (yyvsp[(8) - (8)].EffectTypeVal));}
    break;

  case 315:

    {(yyval.TakeKitTypeVal) = (yyvsp[(2) - (3)].TakeKitTypeVal);}
    break;

  case 316:

    {(yyval.TakePartTypeVal) = new TakePartType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].XmlStringVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].XmlNMTOKENVal), (yyvsp[(6) - (9)].XmlNMTOKENVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].PreconditionTypeVal), (yyvsp[(9) - (9)].EffectTypeVal));}
    break;

  case 317:

    {(yyval.TakePartTypeVal) = (yyvsp[(2) - (3)].TakePartTypeVal);}
    break;

  case 318:

    {(yyval.XmlNMTOKENVal) = 0;}
    break;

  case 319:

    {yyReadData = 1;}
    break;

  case 320:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 321:

    {(yyval.XmlDateTimeVal) = 0;}
    break;

  case 322:

    {yyReadData = 1;}
    break;

  case 323:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);}
    break;

  case 324:

    {(yyval.UnderWithContactTypeVal) = new UnderWithContactType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));}
    break;

  case 325:

    {(yyval.UnderWithContactTypeVal) = (yyvsp[(2) - (3)].UnderWithContactTypeVal);}
    break;

  case 326:

    {yyReadData = 1;}
    break;

  case 327:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 328:

    {yyReadData = 1;}
    break;

  case 329:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 330:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));}
    break;

  case 331:

    {yyReadData = 1;}
    break;

  case 332:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  }
    break;

  case 333:

    {yyReadData = 1;}
    break;

  case 334:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  }
    break;

  case 335:

    {yyReadData = 1;}
    break;

  case 336:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  }
    break;

  case 337:

    {yyReadData = 1;}
    break;

  case 338:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 339:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);}
    break;

  case 340:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 341:

    {yyReadData = 1;}
    break;

  case 342:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 343:

    {yyReadData = 1;}
    break;

  case 344:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 345:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 346:

    {yyReadData = 1;}
    break;

  case 347:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 348:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlStringVal), (yyvsp[(5) - (9)].PoseLocationTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  }
    break;

  case 349:

    {(yyval.CylindricalShapeTypeVal) = new CylindricalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].XmlBooleanVal));
	   (yyval.CylindricalShapeTypeVal)->printTypp = true;
	  }
    break;

  case 350:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].ListEndEffectorHolderTypeVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  }
    break;

  case 351:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  }
    break;

  case 352:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  }
    break;

  case 353:

    {(yyval.HumanTypeVal) = new HumanType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.HumanTypeVal)->printTypp = true;
	  }
    break;

  case 354:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  }
    break;

  case 355:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (12)].InternalShapeTypeVal), (yyvsp[(7) - (12)].ExternalShapeTypeVal), (yyvsp[(8) - (12)].XmlIDREFVal), (yyvsp[(9) - (12)].KitTrayTypeVal), (yyvsp[(10) - (12)].ListPartTypeVal), (yyvsp[(11) - (12)].ListSlotTypeVal), (yyvsp[(12) - (12)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  }
    break;

  case 356:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (16)].XmlIDVal), (yyvsp[(4) - (16)].PhysicalLocationTypeVal), (yyvsp[(5) - (16)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (16)].InternalShapeTypeVal), (yyvsp[(7) - (16)].ExternalShapeTypeVal), (yyvsp[(8) - (16)].AngleUnitTypeVal), (yyvsp[(9) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (16)].ListKitDesignTypeVal), (yyvsp[(11) - (16)].LengthUnitTypeVal), (yyvsp[(12) - (16)].ListSolidObjectTypeVal), (yyvsp[(13) - (16)].ListBoxVolumeTypeVal), (yyvsp[(14) - (16)].RobotTypeVal), (yyvsp[(15) - (16)].ListStockKeepingUnitTypeVal), (yyvsp[(16) - (16)].WeightUnitTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  }
    break;

  case 357:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].ListKitTrayTypeVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  }
    break;

  case 358:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].ListKitTypeVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  }
    break;

  case 359:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  }
    break;

  case 360:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  }
    break;

  case 361:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  }
    break;

  case 362:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].ListPartTypeVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  }
    break;

  case 363:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].ListPartTypeVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  }
    break;

  case 364:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  }
    break;

  case 365:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  }
    break;

  case 366:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  }
    break;

  case 367:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  }
    break;

  case 368:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  }
    break;

  case 369:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].EndEffectorTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].ListBoxVolumeTypeVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  }
    break;

  case 370:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (15)].InternalShapeTypeVal), (yyvsp[(7) - (15)].ExternalShapeTypeVal), (yyvsp[(8) - (15)].XmlStringVal), (yyvsp[(9) - (15)].PositiveDecimalTypeVal), (yyvsp[(10) - (15)].PositiveDecimalTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeVal), (yyvsp[(12) - (15)].PositiveDecimalTypeVal), (yyvsp[(13) - (15)].PositiveDecimalTypeVal), (yyvsp[(14) - (15)].XmlPositiveIntegerVal), (yyvsp[(15) - (15)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  }
    break;

  case 371:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  }
    break;

  case 372:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].ListSolidObjectTypeVal));
	   (yyval.WorkTableTypeVal)->printTypp = true;
	  }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





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

