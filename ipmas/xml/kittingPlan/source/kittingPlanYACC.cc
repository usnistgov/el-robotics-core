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
#include "owlKittingPlanClasses.hh"
#else
#include "kittingPlanClasses.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingPlanFile * KittingPlanTree; // the parse tree

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
     ELSEDOEND = 301,
     ELSEDOSTART = 302,
     ELSEIFEND = 303,
     ELSEIFSTART = 304,
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
     ELSEDOTYPEDECL = 486,
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
  ElseDoType *                        ElseDoTypeVal;
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
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  312
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  161
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  571

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   566

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
     305,   306,   307,   308,   309,   310,   311
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    17,    19,    21,    23,
      25,    27,    29,    31,    36,    43,    47,    51,    55,    56,
      62,    64,    66,    68,    70,    72,    74,    76,    78,    80,
      84,    88,    92,    94,    96,    98,   100,   102,   104,   106,
     108,   110,   112,   114,   115,   121,   125,   126,   130,   134,
     135,   141,   142,   148,   149,   155,   159,   160,   166,   167,
     173,   174,   180,   181,   187,   198,   199,   202,   205,   207,
     208,   211,   214,   216,   219,   221,   224,   226,   227,   230,
     234,   235,   241,   242,   248,   253,   254,   260,   261,   262,
     268,   269,   275,   277,   279,   281,   283,   285,   286,   292,
     293,   299,   300,   306,   308,   310,   312,   314,   316,   318,
     320,   322,   324,   326,   328,   330,   332,   334,   336,   338,
     340,   342,   346,   347,   353,   357,   358,   364,   370,   374,
     375,   376,   382,   383,   389,   390,   396,   397,   403,   404,
     410,   411,   417,   423,   427,   431,   435,   439,   444,   448,
     449,   455,   456,   457,   463,   467,   468,   474,   475,   481,
     485,   489,   495,   499,   500,   506,   507,   513,   517,   518,
     524,   530,   537,   543,   548,   555,   561,   567,   571,   577,
     583,   590,   596,   602,   607,   613,   619,   624,   630,   635,
     640,   646,   651,   656,   662,   673,   684,   695,   701,   708,
     715,   722,   729,   736,   742,   748,   754,   760,   766,   770,
     775,   781,   786
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     313,     0,    -1,   324,    95,   314,   355,    94,    -1,    11,
     315,    -1,     8,    10,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,
      -1,     9,    13,    10,     7,    -1,     9,    13,    10,     5,
      10,     7,    -1,    15,   330,    14,    -1,    17,   330,    16,
      -1,    19,   330,    18,    -1,    -1,    19,     6,   329,   317,
      18,    -1,   433,    -1,   435,    -1,   444,    -1,   445,    -1,
     446,    -1,   453,    -1,   457,    -1,   467,    -1,   471,    -1,
      27,   334,    26,    -1,    29,   334,    28,    -1,    31,   334,
      30,    -1,   430,    -1,   436,    -1,   437,    -1,   438,    -1,
     439,    -1,   441,    -1,   442,    -1,   447,    -1,   448,    -1,
     450,    -1,   468,    -1,    -1,    41,     6,   336,   322,    40,
      -1,     6,   364,   405,    -1,    -1,    47,   337,    46,    -1,
      49,   408,    48,    -1,    -1,    51,     6,   341,   320,    50,
      -1,    -1,    55,     6,   343,   320,    54,    -1,    -1,    71,
       6,   345,   317,    70,    -1,    73,   408,    72,    -1,    -1,
      77,     6,   348,   317,    76,    -1,    -1,    79,     6,   350,
     317,    78,    -1,    -1,    85,     6,   352,   320,    84,    -1,
      -1,    87,     6,   354,   320,    86,    -1,     6,   364,   384,
     387,   378,   376,   380,   357,   362,   386,    -1,    -1,   356,
     339,    -1,   357,   369,    -1,   369,    -1,    -1,   358,   393,
      -1,   359,   404,    -1,   404,    -1,   360,   406,    -1,   406,
      -1,   361,   407,    -1,   407,    -1,    -1,   362,   420,    -1,
     103,   375,   102,    -1,    -1,   117,     6,   365,   318,   116,
      -1,    -1,   119,     6,   367,   321,   118,    -1,     6,   364,
     401,   383,    -1,    -1,   123,     6,   370,   318,   122,    -1,
      -1,    -1,   125,     6,   372,     4,   124,    -1,    -1,   129,
       6,   374,   320,   128,    -1,   454,    -1,   455,    -1,   456,
      -1,   461,    -1,   462,    -1,    -1,   141,     6,   377,   323,
     140,    -1,    -1,   143,     6,   379,   316,   142,    -1,    -1,
     145,     6,   381,   322,   144,    -1,   431,    -1,   432,    -1,
     434,    -1,   440,    -1,   443,    -1,   449,    -1,   451,    -1,
     452,    -1,   458,    -1,   459,    -1,   460,    -1,   463,    -1,
     464,    -1,   465,    -1,   466,    -1,   469,    -1,   470,    -1,
     472,    -1,   147,   382,   146,    -1,    -1,   149,     6,   385,
     320,   148,    -1,   151,   382,   150,    -1,    -1,   153,     6,
     388,   323,   152,    -1,     6,   364,   423,   425,   428,    -1,
     155,   389,   154,    -1,    -1,    -1,   157,     6,   392,     4,
     156,    -1,    -1,   159,     6,   394,   321,   158,    -1,    -1,
     163,     6,   396,   320,   162,    -1,    -1,   165,     6,   398,
     319,   164,    -1,    -1,   167,     6,   400,   320,   166,    -1,
      -1,   173,     6,   402,   321,   172,    -1,     6,   364,   401,
     358,   383,    -1,   183,   368,   182,    -1,   183,   382,   182,
      -1,   183,   382,   182,    -1,   183,   403,   182,    -1,     6,
     364,   409,   405,    -1,   185,   334,   184,    -1,    -1,   187,
       6,   411,   320,   186,    -1,    -1,    -1,   189,     6,   413,
     316,   188,    -1,   191,   330,   190,    -1,    -1,   191,     6,
     416,   317,   190,    -1,    -1,   193,     6,   418,   319,   192,
      -1,     6,   364,   415,    -1,   195,   419,   194,    -1,     6,
     364,   344,   347,   349,    -1,   205,   421,   204,    -1,    -1,
     207,     6,   424,   317,   206,    -1,    -1,   209,     6,   426,
     317,   208,    -1,   211,   421,   210,    -1,    -1,   213,     6,
     429,   317,   212,    -1,   216,     6,   364,   331,   332,    -1,
     219,     6,   364,   399,   342,   340,    -1,   226,     6,   364,
     353,   351,    -1,   228,     6,   364,   328,    -1,   229,     6,
     364,   399,   342,   340,    -1,   230,     6,   364,   325,   326,
      -1,   235,     6,   364,   325,   326,    -1,   237,     6,   364,
      -1,   238,     6,   364,   325,   326,    -1,   239,     6,   364,
     325,   326,    -1,   242,     6,   364,   346,   356,   338,    -1,
     252,     6,   364,   325,   326,    -1,   253,     6,   364,   325,
     326,    -1,   254,     6,   364,   373,    -1,   256,     6,   364,
     325,   326,    -1,   257,     6,   364,   325,   326,    -1,   258,
       6,   364,   327,    -1,   260,     6,   364,   325,   326,    -1,
     261,     6,   364,   333,    -1,   263,     6,   364,   359,    -1,
     264,     6,   364,   331,   332,    -1,   265,     6,   364,   359,
      -1,   268,     6,   364,   361,    -1,   274,     6,   364,   325,
     326,    -1,   276,     6,   364,   397,   412,   390,   422,   427,
     391,   371,    -1,   277,     6,   364,   397,   412,   390,   422,
     427,   391,   371,    -1,   279,     6,   364,   397,   412,   390,
     422,   427,   391,   371,    -1,   280,     6,   364,   410,   395,
      -1,   281,     6,   364,   399,   353,   363,    -1,   282,     6,
     364,   399,   351,   363,    -1,   283,     6,   364,   399,   373,
     363,    -1,   284,     6,   364,   397,   412,   335,    -1,   285,
       6,   364,   397,   412,   335,    -1,   293,     6,   364,   360,
     366,    -1,   296,     6,   364,   399,   353,    -1,   297,     6,
     364,   399,   351,    -1,   298,     6,   364,   399,   373,    -1,
     300,     6,   364,   325,   326,    -1,   301,     6,   364,    -1,
     302,     6,   364,   360,    -1,   306,     6,   364,   417,   414,
      -1,   307,     6,   364,   417,    -1,   310,     6,   364,   409,
     405,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   721,   721,   731,   736,   750,   758,   766,   774,   782,
     798,   806,   814,   822,   827,   838,   843,   848,   853,   853,
     866,   868,   870,   872,   874,   876,   878,   880,   882,   902,
     907,   912,   922,   924,   926,   928,   930,   932,   934,   936,
     938,   940,   942,   974,   974,   994,  1000,  1001,  1006,  1021,
    1021,  1048,  1048,  1116,  1116,  1121,  1140,  1140,  1145,  1145,
    1167,  1167,  1172,  1172,  1216,  1255,  1256,  1323,  1326,  1360,
    1361,  1394,  1398,  1404,  1407,  1413,  1417,  1424,  1425,  1441,
    1492,  1492,  1497,  1497,  1503,  1519,  1519,  1525,  1526,  1526,
    1547,  1547,  1593,  1595,  1597,  1599,  1601,  1606,  1606,  1612,
    1612,  1618,  1618,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1658,  1663,  1668,  1668,  1673,  1678,  1678,  1684,  1690,  1705,
    1706,  1706,  1715,  1715,  1726,  1726,  1731,  1731,  1737,  1737,
    1765,  1765,  1837,  1844,  1849,  1854,  1859,  1872,  1878,  1883,
    1883,  1890,  1891,  1891,  1897,  1902,  1902,  1907,  1907,  1912,
    1917,  1922,  1958,  1963,  1963,  1968,  1968,  1973,  1978,  1978,
    1983,  1991,  2010,  2028,  2035,  2044,  2077,  2085,  2092,  2100,
    2132,  2214,  2222,  2230,  2248,  2256,  2264,  2271,  2279,  2286,
    2294,  2302,  2320,  2350,  2358,  2369,  2380,  2391,  2399,  2407,
    2415,  2423,  2432,  2455,  2464,  2472,  2480,  2488,  2496,  2503,
    2540,  2548,  2555
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
  "A1START", "A2END", "A2START", "AEND", "ASTART", "ANGLEUNITEND",
  "ANGLEUNITSTART", "ARRAYNUMBEREND", "ARRAYNUMBERSTART", "ARRAYRADIUSEND",
  "ARRAYRADIUSSTART", "B1END", "B1START", "B2END", "B2START", "BEND",
  "BSTART", "BASEEND", "BASESTART", "CAPACITYEND", "CAPACITYSTART",
  "CHANGINGSTATIONEND", "CHANGINGSTATIONSTART", "CUPDIAMETEREND",
  "CUPDIAMETERSTART", "DESCRIPTIONEND", "DESCRIPTIONSTART",
  "DESIGNNAMEEND", "DESIGNNAMESTART", "DIAMETEREND", "DIAMETERSTART",
  "ELSEDOEND", "ELSEDOSTART", "ELSEIFEND", "ELSEIFSTART",
  "ENDEFFECTORHOLDERNAMEEND", "ENDEFFECTORHOLDERNAMESTART",
  "ENDEFFECTORHOLDEREND", "ENDEFFECTORHOLDERSTART", "ENDEFFECTORNAMEEND",
  "ENDEFFECTORNAMESTART", "ENDEFFECTOREND", "ENDEFFECTORSTART",
  "EXTERNALSHAPEEND", "EXTERNALSHAPESTART", "FINISHEDEND", "FINISHEDSTART",
  "GRASPPOSEEND", "GRASPPOSESTART", "HASTOPEND", "HASTOPSTART",
  "HEIGHTEND", "HEIGHTSTART", "HELDOBJECTEND", "HELDOBJECTSTART", "IEND",
  "ISTART", "IFEND", "IFSTART", "INTERNALSHAPEEND", "INTERNALSHAPESTART",
  "JEND", "JSTART", "KEND", "KSTART", "KITDESIGNNAMEEND",
  "KITDESIGNNAMESTART", "KITDESIGNEND", "KITDESIGNSTART", "KITNAMEEND",
  "KITNAMESTART", "KITTRAYNAMEEND", "KITTRAYNAMESTART",
  "KITTRAYSKUNAMEEND", "KITTRAYSKUNAMESTART", "KITTRAYEND", "KITTRAYSTART",
  "KITEND", "KITSTART", "KITTINGPLANEND", "KITTINGPLANSTART",
  "LARGECONTAINEREND", "LARGECONTAINERSTART", "LENGTHUNITEND",
  "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART", "LOCATIONEND",
  "LOCATIONSTART", "MAXIMUMLOADWEIGHTEND", "MAXIMUMLOADWEIGHTSTART",
  "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART", "MINIMUMPOINTEND",
  "MINIMUMPOINTSTART", "MODELFILENAMEEND", "MODELFILENAMESTART",
  "MODELFORMATNAMEEND", "MODELFORMATNAMESTART", "MODELNAMEEND",
  "MODELNAMESTART", "NAMEEND", "NAMESTART", "NUMBEROFSTEPSEND",
  "NUMBEROFSTEPSSTART", "OBJECTONTABLEEND", "OBJECTONTABLESTART",
  "OBJECTEND", "OBJECTSTART", "ORIENTATIONSTANDARDDEVIATIONEND",
  "ORIENTATIONSTANDARDDEVIATIONSTART", "OTHEROBSTACLEEND",
  "OTHEROBSTACLESTART", "PARTNAMEEND", "PARTNAMESTART", "PARTQUANTITYEND",
  "PARTQUANTITYSTART", "PARTREFANDPOSENAMEEND", "PARTREFANDPOSENAMESTART",
  "PARTREFANDPOSEEND", "PARTREFANDPOSESTART", "PARTSKUNAMEEND",
  "PARTSKUNAMESTART", "PARTEND", "PARTSTART", "PLANAUTHOREND",
  "PLANAUTHORSTART", "PLANDATEANDTIMEEND", "PLANDATEANDTIMESTART",
  "PLANDESCRIPTIONEND", "PLANDESCRIPTIONSTART", "PLANELEMENTEND",
  "PLANELEMENTSTART", "PLANIDEND", "PLANIDSTART", "PLANROOTEND",
  "PLANROOTSTART", "PLANVERSIONEND", "PLANVERSIONSTART", "POINTEND",
  "POINTSTART", "POSITIONSTANDARDDEVIATIONEND",
  "POSITIONSTANDARDDEVIATIONSTART", "PREDECESSOREND", "PREDECESSORSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "PROPERTYEND",
  "PROPERTYSTART", "REFOBJECTNAMEEND", "REFOBJECTNAMESTART",
  "ROBOTNAMEEND", "ROBOTNAMESTART", "ROBOTEND", "ROBOTSTART",
  "SECONDARYLOCATIONEND", "SECONDARYLOCATIONSTART", "SEQUENCENUMBEREND",
  "SEQUENCENUMBERSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SKUNAMEEND", "SKUNAMESTART", "SKUEND", "SKUSTART", "SLOTEND",
  "SLOTSTART", "STEPEND", "STEPSTART", "TESTEND", "TESTSTART",
  "THINGNAMEEND", "THINGNAMESTART", "TIMESTAMPEND", "TIMESTAMPSTART",
  "VALEND", "VALSTART", "VARNAMEEND", "VARNAMESTART", "VARIABLEEND",
  "VARIABLESTART", "WEIGHTUNITEND", "WEIGHTUNITSTART", "WEIGHTEND",
  "WEIGHTSTART", "WIDTHEND", "WIDTHSTART", "WORKVOLUMEEND",
  "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND",
  "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "ACTIONBASETYPEDECL", "ACTIONGROUPBASETYPEDECL", "ANDTYPEDECL",
  "ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL",
  "ARITHMETICEXPRESSIONTYPEDECL", "ATTACHENDEFFECTORTYPEDECL",
  "BINARYARITHMETICEXPRESSIONTYPEDECL", "BINARYBOOLEANEXPRESSIONTYPEDECL",
  "BOOLEANCONSTANTTYPEDECL", "BOOLEANEXPRESSIONTYPEDECL",
  "BOXVOLUMETYPEDECL", "BOXYSHAPETYPEDECL", "CREATEKITTYPEDECL",
  "CYLINDRICALSHAPETYPEDECL", "DECIMALTYPEDECL",
  "DETACHENDEFFECTORTYPEDECL", "DIVTYPEDECL", "ELSEDOTYPEDECL",
  "ENDEFFECTORCHANGINGSTATIONTYPEDECL", "ENDEFFECTORHOLDERTYPEDECL",
  "ENDEFFECTORTYPEDECL", "EQUALTYPEDECL", "EXTERNALSHAPETYPEDECL",
  "FALSETYPEDECL", "GREATEROREQUALTYPEDECL", "GREATERTYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "HUMANTYPEDECL", "IFACTIONGROUPTYPEDECL",
  "INTERNALSHAPETYPEDECL", "KITDESIGNTYPEDECL", "KITTRAYTYPEDECL",
  "KITTYPEDECL", "KITTINGPLANTYPEDECL", "KITTINGWORKSTATIONTYPEDECL",
  "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL", "LARGEBOXWITHKITSTYPEDECL",
  "LARGECONTAINERTYPEDECL", "LESSOREQUALTYPEDECL", "LESSTYPEDECL",
  "LOCATEPARTTYPEDECL", "MECHANICALCOMPONENTTYPEDECL", "MINUSTYPEDECL",
  "MODTYPEDECL", "NEGATETYPEDECL", "NOSKUOBJECTTYPEDECL",
  "NOTEQUALTYPEDECL", "NOTTYPEDECL", "NUMBEREDPLANELEMENTTYPEDECL",
  "ONEOFACTIONGROUPTYPEDECL", "ORTYPEDECL", "ORDEREDACTIONGROUPTYPEDECL",
  "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL",
  "PARTIALLYORDEREDACTIONGROUPTYPEDECL", "PARTSBINTYPEDECL",
  "PARTSTRAYTYPEDECL", "PARTSVESSELTYPEDECL", "PHYSICALLOCATIONTYPEDECL",
  "PLANELEMENTBASETYPEDECL", "PLUSTYPEDECL", "POINTTYPEDECL",
  "POSELOCATIONINTYPEDECL", "POSELOCATIONONTYPEDECL",
  "POSELOCATIONTYPEDECL", "POSEONLYLOCATIONTYPEDECL", "PROPVALTYPEDECL",
  "PUTKITTRAYTYPEDECL", "PUTKITTYPEDECL", "PUTPARTTYPEDECL",
  "RELATIVELOCATIONINTYPEDECL", "RELATIVELOCATIONONTYPEDECL",
  "RELATIVELOCATIONTYPEDECL", "ROBOTACTIONBASETYPEDECL", "ROBOTTYPEDECL",
  "SENSORACTIONBASETYPEDECL", "SHAPEDESIGNTYPEDECL", "SKUOBJECTTYPEDECL",
  "SLOTTYPEDECL", "SOMEOFACTIONGROUPTYPEDECL",
  "STEPWITHPREDECESSORSTYPEDECL", "STOCKKEEPINGUNITTYPEDECL",
  "TAKEKITTRAYTYPEDECL", "TAKEKITTYPEDECL", "TAKEPARTTYPEDECL",
  "TESTANDSTEPTYPEDECL", "TIMESTYPEDECL", "TRUETYPEDECL",
  "UNORDEREDACTIONGROUPTYPEDECL", "VACUUMEFFECTORMULTICUPTYPEDECL",
  "VACUUMEFFECTORSINGLECUPTYPEDECL", "VACUUMEFFECTORTYPEDECL",
  "VARSETTYPEDECL", "VARVALTYPEDECL", "VARIABLEDECLARATIONTYPEDECL",
  "VECTORTYPEDECL", "WHILEACTIONGROUPTYPEDECL", "WORKTABLETYPEDECL",
  "$accept", "y_KittingPlanFile", "y_XmlHeaderForKittingPlan",
  "y_SchemaLocation", "y_XmlDateTime", "y_XmlDecimal", "y_XmlID",
  "y_XmlIDREF", "y_XmlNMTOKEN", "y_XmlPositiveInteger", "y_XmlString",
  "y_XmlToken", "y_XmlVersion", "y_A1_ArithmeticExpressionType",
  "y_A2_ArithmeticExpressionType", "y_A_ArithmeticExpressionType",
  "y_A_XmlDecimal", "$@1", "y_ArithmeticExpressionTypeAny",
  "y_B1_BooleanExpressionType", "y_B2_BooleanExpressionType",
  "y_B_BooleanExpressionType", "y_BooleanExpressionTypeAny",
  "y_Description_XmlString", "$@7", "y_ElseDoType",
  "y_ElseDo_ElseDoType_0", "y_ElseIf_TestAndStepType_0_u",
  "y_EndEffectorHolderName_XmlNMTOKEN", "$@10",
  "y_EndEffectorName_XmlNMTOKEN", "$@12", "y_I_XmlDecimal", "$@16",
  "y_If_TestAndStepType", "y_J_XmlDecimal", "$@17", "y_K_XmlDecimal",
  "$@18", "y_KitName_XmlNMTOKEN", "$@20", "y_KitTrayName_XmlNMTOKEN",
  "$@21", "y_KittingPlanType", "y_ListElseIf_TestAndStepType_0_u",
  "y_ListObject_XmlID_1_u", "y_ListPredecessor_XmlPositiveInteger_0_u",
  "y_ListStep_NumberedPlanElementType_1_u",
  "y_ListStep_PlanElementBaseType_1_u",
  "y_ListStep_StepWithPredecessorsType_1_u",
  "y_ListVariable_VariableDeclarationTy1009",
  "y_Location_PhysicalLocationType", "y_Name_XmlID", "$@29",
  "y_NumberOfSteps_XmlPositiveInteger", "$@30",
  "y_NumberedPlanElementType", "y_Object_XmlID_1_u", "$@31",
  "y_OrientationStandardDeviation_P1004", "$@32", "y_PartName_XmlNMTOKEN",
  "$@34", "y_PhysicalLocationTypeAny", "y_PlanAuthor_XmlToken", "$@38",
  "y_PlanDateAndTime_XmlDateTime", "$@39", "y_PlanDescription_XmlString",
  "$@40", "y_PlanElementBaseTypeAny", "y_PlanElement_PlanElementBaseType",
  "y_PlanId_XmlNMTOKEN", "$@41", "y_PlanRoot_PlanElementBaseType",
  "y_PlanVersion_XmlToken", "$@42", "y_PointType", "y_Point_PointType",
  "y_PositionStandardDeviation_Posi1006", "$@43",
  "y_Predecessor_XmlPositiveInteger_0_u", "$@44", "y_Property_XmlNMTOKEN",
  "$@45", "y_RefObjectName_XmlIDREF", "$@46", "y_RobotName_XmlNMTOKEN",
  "$@47", "y_SequenceNumber_XmlPositiveInteger", "$@48",
  "y_StepWithPredecessorsType", "y_Step_NumberedPlanElementType_1_u",
  "y_Step_PlanElementBaseType", "y_Step_PlanElementBaseType_1_u",
  "y_Step_StepWithPredecessorsType_1_u", "y_TestAndStepType",
  "y_Test_BooleanExpressionType", "y_ThingName_XmlNMTOKEN", "$@51",
  "y_Timestamp_XmlDateTime_0", "$@52", "y_Val_ArithmeticExpressionType",
  "y_Val_XmlDecimal", "$@53", "y_VarName_XmlIDREF", "$@54",
  "y_VariableDeclarationType", "y_Variable_VariableDeclarationTy1009",
  "y_VectorType", "y_XAxis_VectorType", "y_X_XmlDecimal", "$@58",
  "y_Y_XmlDecimal", "$@59", "y_ZAxis_VectorType", "y_Z_XmlDecimal", "$@60",
  "y_x_AndType", "y_x_AttachEndEffectorType", "y_x_CreateKitType",
  "y_x_DecimalType", "y_x_DetachEndEffectorType", "y_x_DivType",
  "y_x_EqualType", "y_x_FalseType", "y_x_GreaterOrEqualType",
  "y_x_GreaterType", "y_x_IfActionGroupType", "y_x_LessOrEqualType",
  "y_x_LessType", "y_x_LocatePartType", "y_x_MinusType", "y_x_ModType",
  "y_x_NegateType", "y_x_NotEqualType", "y_x_NotType",
  "y_x_OneOfActionGroupType", "y_x_OrType", "y_x_OrderedActionGroupType",
  "y_x_PartiallyOrderedActionGroupType", "y_x_PlusType",
  "y_x_PoseLocationInType", "y_x_PoseLocationOnType",
  "y_x_PoseOnlyLocationType", "y_x_PropValType", "y_x_PutKitTrayType",
  "y_x_PutKitType", "y_x_PutPartType", "y_x_RelativeLocationInType",
  "y_x_RelativeLocationOnType", "y_x_SomeOfActionGroupType",
  "y_x_TakeKitTrayType", "y_x_TakeKitType", "y_x_TakePartType",
  "y_x_TimesType", "y_x_TrueType", "y_x_UnorderedActionGroupType",
  "y_x_VarSetType", "y_x_VarValType", "y_x_WhileActionGroupType", 0
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
     565,   566
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   324,   325,   326,   327,   329,   328,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   331,
     332,   333,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   336,   335,   337,   338,   338,   339,   341,
     340,   343,   342,   345,   344,   346,   348,   347,   350,   349,
     352,   351,   354,   353,   355,   356,   356,   357,   357,   358,
     358,   359,   359,   360,   360,   361,   361,   362,   362,   363,
     365,   364,   367,   366,   368,   370,   369,   371,   372,   371,
     374,   373,   375,   375,   375,   375,   375,   377,   376,   379,
     378,   381,   380,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   383,   385,   384,   386,   388,   387,   389,   390,   391,
     392,   391,   394,   393,   396,   395,   398,   397,   400,   399,
     402,   401,   403,   404,   405,   406,   407,   408,   409,   411,
     410,   412,   413,   412,   414,   416,   415,   418,   417,   419,
     420,   421,   422,   424,   423,   426,   425,   427,   429,   428,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     3,     3,     3,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     0,     3,     3,     0,
       5,     0,     5,     0,     5,     3,     0,     5,     0,     5,
       0,     5,     0,     5,    10,     0,     2,     2,     1,     0,
       2,     2,     1,     2,     1,     2,     1,     0,     2,     3,
       0,     5,     0,     5,     4,     0,     5,     0,     0,     5,
       0,     5,     1,     1,     1,     1,     1,     0,     5,     0,
       5,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     5,     3,     0,     5,     5,     3,     0,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     5,     3,     3,     3,     3,     4,     3,     0,
       5,     0,     0,     5,     3,     0,     5,     0,     5,     3,
       3,     5,     3,     0,     5,     0,     5,     3,     0,     5,
       5,     6,     5,     4,     6,     5,     5,     3,     5,     5,
       6,     5,     5,     4,     5,     5,     4,     5,     4,     4,
       5,     4,     4,     5,    10,    10,    10,     5,     6,     6,
       6,     6,     6,     5,     5,     5,     5,     5,     3,     4,
       5,     4,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     3,     0,     0,     0,     4,     0,     0,
       2,    14,    80,     0,     0,     0,   122,     0,     0,     7,
       0,     0,   125,     0,     0,    81,     9,     0,     0,    99,
       0,     0,   123,    12,     0,     0,    97,     0,     0,   126,
       5,     0,     0,   101,     0,    77,    68,   100,     0,     0,
      85,     0,    67,    98,    11,     0,     0,     0,     0,    64,
      78,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     0,
      65,     0,   183,     0,   189,    72,   191,     0,   192,    76,
       0,     0,     0,     0,     0,    74,     0,     0,     0,   209,
       0,     0,     0,     0,   155,   138,     0,     0,    62,     0,
     172,     0,     0,     0,    46,    90,     0,     0,    71,     0,
       0,    75,     0,     0,     0,     0,     0,   203,    73,   204,
     205,   206,   157,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,   212,
       0,     0,    51,     0,   171,     0,    60,   174,     0,    55,
       0,     0,   180,    66,     0,     0,   143,     0,   146,     0,
     198,   199,   200,   145,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     6,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,   208,   144,   156,
     139,     0,     0,    63,     0,   147,     0,    47,    48,    91,
     140,     0,    84,     0,     0,     0,     0,     0,     0,    79,
      10,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,    52,     0,    61,    45,     0,     0,
       0,   142,    70,     0,     0,     0,     0,     0,    83,     0,
     173,     0,     0,     0,     0,   186,     0,     0,     0,     0,
     211,     0,     0,   170,     0,     0,   176,   178,   179,   181,
     182,   187,     0,   190,    50,     0,   121,   132,     0,   151,
     151,   151,   151,   151,    18,   175,   184,   185,     0,   193,
     149,     0,   197,   207,    29,     0,    15,     0,    31,   141,
       0,   136,     0,     0,     0,     0,     0,     0,     0,    17,
       0,   134,    30,    16,     0,     0,   152,     0,     0,     0,
       0,     0,   201,   202,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    19,   150,     0,
     137,     0,     0,   128,     0,     0,     0,   129,   129,   129,
       0,   135,   153,     0,     0,     0,   162,     0,     0,    87,
      87,    87,     0,   163,     0,     0,     0,     0,   167,   130,
       0,   194,   195,   196,    44,     0,   165,     0,   127,    53,
       0,     0,     0,    88,     0,     0,   168,     0,    56,     0,
     161,     0,     0,   164,     0,     0,     0,     0,    58,   131,
       0,   166,     0,    54,     0,     0,    89,   169,    57,     0,
      59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,    51,   299,    30,   326,    37,   371,
      65,    44,     3,   385,   426,   415,   410,   468,   275,   383,
     423,   392,   226,   482,   510,   307,   252,   253,   244,   352,
     187,   301,   527,   547,   160,   541,   557,   550,   565,   190,
     304,   157,   245,    15,   194,    55,   363,   164,   174,   168,
      61,   260,    19,    25,   207,   324,   197,    56,    66,   531,
     552,   162,   254,   318,    41,    52,    34,    45,    48,    59,
      91,   362,    24,    31,    69,    28,    38,   491,   478,   519,
     542,   402,   460,   452,   486,   439,   475,   155,   241,   311,
     398,   200,   165,   239,   175,   169,   193,   183,   418,   470,
     463,   489,   214,   153,   240,   181,   265,   111,    70,   505,
     493,   514,   535,   525,   545,   507,   538,   555,   227,    92,
      93,   276,    94,   277,   228,   229,   230,   231,    95,   232,
     233,    96,   278,   279,   280,   234,   235,    97,   236,    98,
      99,   281,   319,   320,   321,   282,   100,   101,   102,   322,
     323,   103,   104,   105,   106,   283,   237,   107,   108,   284,
     109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -446
static const yytype_int16 yypact[] =
{
      24,    28,    67,   -47,    70,  -446,    66,    78,    79,    85,
      86,  -446,    96,  -446,    -6,    22,   116,  -446,   148,     6,
    -446,  -446,  -446,   150,     4,   154,  -446,   153,    17,  -446,
      50,   160,  -446,   167,    33,  -446,  -446,    38,   183,  -446,
     184,    46,  -446,  -446,    40,   193,  -446,   194,    76,  -446,
    -446,    60,   183,  -446,   197,    76,  -446,  -446,    64,   201,
    -446,  -124,  -446,  -446,  -446,    62,   154,  -189,   202,  -446,
    -446,  -446,    87,   204,   205,   206,   207,   208,   209,   210,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    57,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
      -6,    43,  -446,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,  -446,    47,  -446,    72,   155,    72,   168,   111,    61,
      61,    63,    72,    72,    72,    65,    72,    72,    72,    65,
      52,    58,   241,  -446,   243,   196,   246,   174,   196,   247,
    -446,   254,  -446,   255,    61,  -446,    61,   256,    63,  -446,
     155,   174,   111,  -189,   -95,  -446,   155,   174,   111,    65,
     257,    73,  -113,    82,  -446,  -446,   261,   217,  -446,   263,
    -446,   217,    -6,   198,    48,  -446,    -6,    89,  -446,    -6,
      90,  -446,   170,   170,   170,    92,   269,  -446,  -446,  -446,
    -446,  -446,  -446,  -202,  -446,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   103,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -189,  -446,
     284,   160,  -446,   283,  -446,   160,  -446,  -446,    58,  -446,
     285,   247,  -446,  -446,   160,   117,  -446,   117,  -446,  -216,
    -446,  -446,  -446,  -446,  -446,   288,   287,   289,   290,   291,
     292,   293,   294,   295,   296,   104,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,  -446,   121,  -446,   114,
     139,   160,  -446,   231,   160,    82,    -6,   260,   259,   180,
     303,   163,  -446,   305,   306,   307,   308,   309,   214,  -446,
    -446,  -446,  -446,  -446,   314,  -446,   127,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,  -446,   297,   310,  -446,
     310,   310,   310,   310,   310,   298,   297,  -446,  -446,  -446,
    -446,   266,   160,  -446,   237,  -446,    82,  -446,  -446,  -446,
    -446,  -189,  -446,  -116,    -6,    -6,    -6,    -6,    -6,  -446,
    -446,   212,  -446,   304,   310,   310,   310,   312,   310,   135,
     310,    52,  -113,   299,  -202,   315,   315,   315,   315,   315,
     315,  -113,  -446,   299,  -446,   286,  -446,  -446,   314,   181,
     320,  -446,  -446,   169,   169,   169,   169,   169,  -446,   327,
    -446,   315,   315,   315,  -202,  -446,   315,   329,   175,   315,
    -446,   311,  -113,  -446,   325,  -202,  -446,  -446,  -446,  -446,
    -446,  -446,   313,  -446,  -446,   172,  -446,  -446,   334,   152,
     152,   152,   152,   152,  -446,  -446,  -446,  -446,   324,  -446,
    -446,   339,  -446,  -446,  -446,   318,  -446,   331,  -446,  -446,
     314,  -446,   342,   195,   195,   195,   316,   316,   284,  -446,
     160,  -446,  -446,  -446,   191,   288,  -446,   345,   147,   147,
     147,   347,  -446,  -446,   336,   173,   160,  -446,   192,   193,
      -6,   211,   349,   149,   149,   149,  -446,  -446,  -446,   199,
    -446,   176,   151,  -446,    -6,   158,   349,   213,   213,   213,
     201,  -446,  -446,   357,   157,   300,  -446,   159,   361,   248,
     248,   248,   328,  -446,   366,   161,   369,   301,  -446,  -446,
     370,  -446,  -446,  -446,  -446,   284,  -446,   371,  -446,  -446,
     373,   302,   378,  -446,   177,   284,  -446,   284,  -446,   379,
    -446,   232,   380,  -446,   178,   284,   317,   284,  -446,  -446,
     265,  -446,   179,  -446,   319,   284,  -446,  -446,  -446,   321,
    -446
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -446,  -446,  -446,  -446,   -99,  -445,   326,   -82,  -220,  -396,
    -114,   346,  -446,  -213,  -218,  -446,  -446,  -446,  -355,    51,
       7,  -446,  -347,   -66,  -446,  -446,  -446,  -446,   215,  -446,
     244,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -139,
    -446,  -134,  -446,  -446,  -446,  -446,  -446,   264,   258,  -446,
    -446,   -89,  -110,  -446,  -446,  -446,  -446,   348,  -446,  -402,
    -446,  -120,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -172,    42,  -446,  -446,  -446,  -446,  -446,  -446,  -327,  -363,
    -446,  -446,  -446,  -446,  -446,  -271,  -446,   -97,  -446,   156,
    -446,  -446,   -65,  -283,  -117,   240,   164,   162,  -446,  -446,
    -299,  -446,  -446,  -446,  -446,    30,  -446,  -446,  -446,   -94,
    -330,  -446,  -446,  -446,  -446,  -342,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     132,   205,   435,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   300,   355,   484,   206,   303,   266,    67,   267,   424,
      73,   361,   203,     1,   309,   421,   202,    74,   210,   158,
      75,     4,   209,   400,   432,   170,   171,   172,     6,   176,
     177,   178,   204,    76,   268,   269,   270,   208,   211,   448,
     313,   314,   208,   315,   474,    77,   297,     5,   316,   317,
     457,    68,   271,   397,    78,   455,    79,     8,   272,    80,
       7,   351,   248,    10,   354,    11,   255,    12,   173,   257,
     544,    14,    81,    82,    83,   250,    16,   251,   273,   198,
     554,   198,   556,   215,    84,   274,    17,    85,    86,    87,
     562,    18,   564,    88,   261,   262,    20,    89,   532,   533,
     569,    90,   216,    21,   217,   218,   219,   386,   387,   388,
     389,   390,   395,   440,   441,   442,   443,   479,   480,   220,
     221,   464,   465,   466,   467,   520,   521,   222,   223,   494,
     495,   224,   508,   509,    22,    23,    26,    27,    29,    32,
      33,   411,   412,   413,    36,   416,    35,   419,   427,   428,
     429,   430,   431,    39,    40,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,    42,    43,   225,   399,
      46,    47,    49,   445,   446,   447,   356,    50,   449,    54,
      53,   453,    57,    60,    63,    64,    71,   131,   110,   112,
     113,   114,   115,   116,   117,   118,   119,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   133,   152,   154,
     161,   159,   156,   182,   163,   180,   167,   184,   173,   185,
     485,   186,   188,   192,   403,   404,   405,   406,   407,   189,
     195,   196,   199,   212,   213,   238,   499,   242,   243,   246,
     249,   256,   258,   259,   263,   264,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   298,   302,
     310,   306,   325,   327,   336,   328,   329,   330,   331,   332,
     333,   334,   335,   348,   349,   350,   357,   358,   359,   360,
     361,   364,   365,   366,   367,   368,   369,   353,   370,   372,
     394,   396,   417,   409,   382,   384,   437,   436,   422,   391,
     408,   414,   425,   444,   438,   450,   434,   454,   451,   456,
     461,   462,   469,   458,   459,   471,   472,   473,   476,   487,
     477,   490,   492,   496,   497,   504,   500,   481,   513,   498,
     506,   511,   516,   523,   512,   503,   524,   529,   534,   528,
     518,   526,   536,   530,   537,   539,   543,   546,   540,   548,
     502,   549,   551,   553,   560,   558,   561,   563,   559,   566,
     501,   567,    72,   488,   515,   568,   522,   393,    58,   570,
     433,   483,   191,    62,   166,   401,   247,   179,   201,     0,
     305,   420,   517,   312,     0,   308
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-446))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     110,   173,   398,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   241,   305,   468,   119,   245,   228,   151,   230,   384,
     219,   147,   171,     9,   254,   382,   170,   226,   177,   136,
     229,    13,   176,   159,   391,   142,   143,   144,    95,   146,
     147,   148,   172,   242,   256,   257,   258,   174,   178,   414,
     276,   277,   179,   279,   460,   254,   238,     0,   284,   285,
     425,   195,   274,   356,   263,   422,   265,    11,   280,   268,
      10,   301,   192,     5,   304,     7,   196,     8,   183,   199,
     535,     6,   281,   282,   283,    47,    10,    49,   300,   164,
     545,   166,   547,   216,   293,   307,    10,   296,   297,   298,
     555,   117,   557,   302,   203,   204,    94,   306,   520,   521,
     565,   310,   235,     7,   237,   238,   239,   340,   341,   342,
     343,   344,   352,   404,   405,   406,   407,   464,   465,   252,
     253,   440,   441,   442,   443,   508,   509,   260,   261,   479,
     480,   264,   494,   495,     6,   149,     6,   153,     4,     6,
     143,   374,   375,   376,     4,   378,   116,   380,   386,   387,
     388,   389,   390,     6,   141,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   148,     4,   301,   361,
       6,   145,   152,   411,   412,   413,   306,     4,   416,   123,
       6,   419,   142,     6,   140,     4,   144,   150,     6,   122,
       6,     6,     6,     6,     6,     6,     6,   327,   328,   329,
     330,   331,   332,   333,   334,   335,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,   194,   191,   167,
     129,    73,    87,   185,   183,   193,   183,     6,   183,     6,
     470,    55,     6,     6,   364,   365,   366,   367,   368,    85,
       6,     6,     6,     6,   191,   183,   486,     6,    51,     6,
      72,   182,   182,   103,   182,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,   184,     4,     6,
     173,     6,     4,     6,   190,     6,     6,     6,     6,     6,
       6,     6,     6,   182,   190,   166,    46,    48,   128,     6,
     147,     6,     6,     6,     6,     6,   102,    86,     4,   192,
      54,    84,   187,    19,    27,    15,     6,   146,    29,    31,
     118,    19,    17,     6,   165,     6,    50,    26,   163,    14,
       6,   189,    18,    30,   172,     6,    28,    16,     6,   158,
     155,     6,   205,     6,    18,     6,   164,    41,   207,   186,
     211,   162,   204,     6,   188,   154,   209,     6,    40,   210,
     157,    71,     6,   125,   213,     6,     6,     6,    77,     6,
     490,    79,     4,   206,     4,     6,   208,    70,   156,   124,
     489,   212,    66,   475,   504,    76,   510,   346,    52,    78,
     393,   467,   158,    55,   140,   363,   191,   149,   168,    -1,
     248,   381,   506,   257,    -1,   251
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   313,   324,    13,     0,    95,    10,    11,   314,
       5,     7,     8,   315,     6,   355,    10,    10,   117,   364,
      94,     7,     6,   149,   384,   365,     6,   153,   387,     4,
     318,   385,     6,   143,   378,   116,     4,   320,   388,     6,
     141,   376,   148,     4,   323,   379,     6,   145,   380,   152,
       4,   316,   377,     6,   123,   357,   369,   142,   323,   381,
       6,   362,   369,   140,     4,   322,   370,   151,   195,   386,
     420,   144,   318,   219,   226,   229,   242,   254,   263,   265,
     268,   281,   282,   283,   293,   296,   297,   298,   302,   306,
     310,   382,   431,   432,   434,   440,   443,   449,   451,   452,
     458,   459,   460,   463,   464,   465,   466,   469,   470,   472,
       6,   419,   122,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   150,   364,   194,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   191,   415,   167,   399,    87,   353,   399,    73,
     346,   129,   373,   183,   359,   404,   359,   183,   361,   407,
     399,   399,   399,   183,   360,   406,   399,   399,   399,   360,
     193,   417,   185,   409,     6,     6,    55,   342,     6,    85,
     351,   342,     6,   408,   356,     6,     6,   368,   404,     6,
     403,   407,   353,   351,   373,   382,   119,   366,   406,   353,
     351,   373,     6,   191,   414,   216,   235,   237,   238,   239,
     252,   253,   260,   261,   264,   301,   334,   430,   436,   437,
     438,   439,   441,   442,   447,   448,   450,   468,   183,   405,
     416,   400,     6,    51,   340,   354,     6,   340,   364,    72,
      47,    49,   338,   339,   374,   364,   182,   364,   182,   103,
     363,   363,   363,   182,     6,   418,   228,   230,   256,   257,
     258,   274,   280,   300,   307,   330,   433,   435,   444,   445,
     446,   453,   457,   467,   471,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,   184,   382,     4,   317,
     320,   343,     6,   320,   352,   409,     6,   337,   408,   320,
     173,   401,   401,   276,   277,   279,   284,   285,   375,   454,
     455,   456,   461,   462,   367,     4,   319,     6,     6,     6,
       6,     6,     6,     6,     6,     6,   190,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   182,   190,
     166,   320,   341,    86,   320,   405,   364,    46,    48,   128,
       6,   147,   383,   358,     6,     6,     6,     6,     6,   102,
       4,   321,   192,   364,   364,   364,   364,   364,   364,   364,
     364,   364,    27,   331,    15,   325,   325,   325,   325,   325,
     325,    31,   333,   331,    54,   320,    84,   405,   402,   382,
     159,   383,   393,   364,   364,   364,   364,   364,   118,    19,
     328,   325,   325,   325,    19,   327,   325,   187,   410,   325,
     417,   334,    29,   332,   330,    17,   326,   326,   326,   326,
     326,   326,   334,   332,    50,   321,   146,     6,   165,   397,
     397,   397,   397,   397,     6,   326,   326,   326,   330,   326,
       6,   163,   395,   326,    26,   334,    14,   330,    30,   172,
     394,     6,   189,   412,   412,   412,   412,   412,   329,    18,
     411,     6,    28,    16,   321,   398,     6,   155,   390,   390,
     390,    41,   335,   335,   317,   320,   396,   158,   319,   413,
       6,   389,   205,   422,   422,   422,     6,    18,   186,   320,
     164,   316,   364,   154,     6,   421,   211,   427,   427,   427,
     336,   162,   188,   207,   423,   364,   204,   421,   157,   391,
     391,   391,   322,     6,   209,   425,    71,   344,   210,     6,
     125,   371,   371,   371,    40,   424,     6,   213,   428,     6,
      77,   347,   392,     6,   317,   426,     6,   345,     6,    79,
     349,     4,   372,   206,   317,   429,   317,   348,     6,   156,
       4,   208,   317,    70,   317,   350,   124,   212,    76,   317,
      78
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

    {(yyval.KittingPlanFileVal) = new KittingPlanFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForKittingPlanVal), (yyvsp[(4) - (5)].KittingPlanTypeVal));
	   KittingPlanTree = (yyval.KittingPlanFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
    break;

  case 3:

    {(yyval.XmlHeaderForKittingPlanVal) = new XmlHeaderForKittingPlan((yyvsp[(2) - (2)].SchemaLocationVal));}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal), false);
	  }
    break;

  case 5:

    {(yyval.XmlDateTimeVal) = new XmlDateTime((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDateTimeVal)->bad)
	     yyerror("bad XmlDateTime");
	  }
    break;

  case 6:

    {(yyval.XmlDecimalVal) = new XmlDecimal((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDecimalVal)->bad)
	     yyerror("bad XmlDecimal");
	  }
    break;

  case 7:

    {(yyval.XmlIDVal) = new XmlID((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDVal)->bad)
	     yyerror("bad XmlID");
	  }
    break;

  case 8:

    {(yyval.XmlIDREFVal) = new XmlIDREF((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDREFVal)->bad)
	     yyerror("bad XmlIDREF");
	  }
    break;

  case 9:

    {(yyval.XmlNMTOKENVal) = new XmlNMTOKEN((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNMTOKENVal)->bad)
	     yyerror("bad XmlNMTOKEN");
	  }
    break;

  case 10:

    {(yyval.XmlPositiveIntegerVal) = new XmlPositiveInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlPositiveIntegerVal)->bad)
	     yyerror("bad XmlPositiveInteger");
	  }
    break;

  case 11:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  }
    break;

  case 12:

    {(yyval.XmlTokenVal) = new XmlToken((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlTokenVal)->bad)
	     yyerror("bad XmlToken");
	  }
    break;

  case 13:

    {(yyval.XmlVersionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  }
    break;

  case 14:

    {(yyval.XmlVersionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp((yyvsp[(5) - (6)].sVal), "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  }
    break;

  case 15:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);}
    break;

  case 16:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);}
    break;

  case 17:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);}
    break;

  case 18:

    {yyReadData = 1;}
    break;

  case 19:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 20:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].DecimalTypeVal);}
    break;

  case 21:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].DivTypeVal);}
    break;

  case 22:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].MinusTypeVal);}
    break;

  case 23:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].ModTypeVal);}
    break;

  case 24:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].NegateTypeVal);}
    break;

  case 25:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].PlusTypeVal);}
    break;

  case 26:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].PropValTypeVal);}
    break;

  case 27:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].TimesTypeVal);}
    break;

  case 28:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].VarValTypeVal);}
    break;

  case 29:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);}
    break;

  case 30:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);}
    break;

  case 31:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);}
    break;

  case 32:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].AndTypeVal);}
    break;

  case 33:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].EqualTypeVal);}
    break;

  case 34:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].FalseTypeVal);}
    break;

  case 35:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].GreaterOrEqualTypeVal);}
    break;

  case 36:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].GreaterTypeVal);}
    break;

  case 37:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].LessOrEqualTypeVal);}
    break;

  case 38:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].LessTypeVal);}
    break;

  case 39:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].NotEqualTypeVal);}
    break;

  case 40:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].NotTypeVal);}
    break;

  case 41:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].OrTypeVal);}
    break;

  case 42:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].TrueTypeVal);}
    break;

  case 43:

    {yyReadData = 1;}
    break;

  case 44:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 45:

    {(yyval.ElseDoTypeVal) = new ElseDoType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].PlanElementBaseTypeVal));}
    break;

  case 46:

    {(yyval.ElseDoTypeVal) = 0;}
    break;

  case 47:

    {(yyval.ElseDoTypeVal) = (yyvsp[(2) - (3)].ElseDoTypeVal);}
    break;

  case 48:

    {(yyval.TestAndStepTypeVal) = (yyvsp[(2) - (3)].TestAndStepTypeVal);}
    break;

  case 49:

    {yyReadData = 1;}
    break;

  case 50:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 51:

    {yyReadData = 1;}
    break;

  case 52:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 53:

    {yyReadData = 1;}
    break;

  case 54:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 55:

    {(yyval.TestAndStepTypeVal) = (yyvsp[(2) - (3)].TestAndStepTypeVal);}
    break;

  case 56:

    {yyReadData = 1;}
    break;

  case 57:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 58:

    {yyReadData = 1;}
    break;

  case 59:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 60:

    {yyReadData = 1;}
    break;

  case 61:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 62:

    {yyReadData = 1;}
    break;

  case 63:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 64:

    {(yyval.KittingPlanTypeVal) = new KittingPlanType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].XmlNMTOKENVal), (yyvsp[(4) - (10)].XmlTokenVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].XmlTokenVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].ListXmlIDVal), (yyvsp[(9) - (10)].ListVariableDeclarationTypeVal), (yyvsp[(10) - (10)].PlanElementBaseTypeVal));}
    break;

  case 65:

    {(yyval.ListTestAndStepTypeVal) = new std::list<TestAndStepType *>;}
    break;

  case 66:

    {(yyval.ListTestAndStepTypeVal) = (yyvsp[(1) - (2)].ListTestAndStepTypeVal);
	   (yyval.ListTestAndStepTypeVal)->push_back((yyvsp[(2) - (2)].TestAndStepTypeVal));}
    break;

  case 67:

    {(yyval.ListXmlIDVal) = (yyvsp[(1) - (2)].ListXmlIDVal);
	   (yyval.ListXmlIDVal)->push_back((yyvsp[(2) - (2)].XmlIDVal));}
    break;

  case 68:

    {(yyval.ListXmlIDVal) = new std::list<XmlID *>;
	   (yyval.ListXmlIDVal)->push_back((yyvsp[(1) - (1)].XmlIDVal));}
    break;

  case 69:

    {(yyval.ListXmlPositiveIntegerVal) = new std::list<XmlPositiveInteger *>;}
    break;

  case 70:

    {(yyval.ListXmlPositiveIntegerVal) = (yyvsp[(1) - (2)].ListXmlPositiveIntegerVal);
	   (yyval.ListXmlPositiveIntegerVal)->push_back((yyvsp[(2) - (2)].XmlPositiveIntegerVal));}
    break;

  case 71:

    {(yyval.ListNumberedPlanElementTypeVal) = (yyvsp[(1) - (2)].ListNumberedPlanElementTypeVal);
	   (yyval.ListNumberedPlanElementTypeVal)->push_back((yyvsp[(2) - (2)].NumberedPlanElementTypeVal));}
    break;

  case 72:

    {(yyval.ListNumberedPlanElementTypeVal) = new std::list<NumberedPlanElementType *>;
	   (yyval.ListNumberedPlanElementTypeVal)->push_back((yyvsp[(1) - (1)].NumberedPlanElementTypeVal));}
    break;

  case 73:

    {(yyval.ListPlanElementBaseTypeVal) = (yyvsp[(1) - (2)].ListPlanElementBaseTypeVal);
	   (yyval.ListPlanElementBaseTypeVal)->push_back((yyvsp[(2) - (2)].PlanElementBaseTypeVal));}
    break;

  case 74:

    {(yyval.ListPlanElementBaseTypeVal) = new std::list<PlanElementBaseType *>;
	   (yyval.ListPlanElementBaseTypeVal)->push_back((yyvsp[(1) - (1)].PlanElementBaseTypeVal));}
    break;

  case 75:

    {(yyval.ListStepWithPredecessorsTypeVal) = (yyvsp[(1) - (2)].ListStepWithPredecessorsTypeVal);
	   (yyval.ListStepWithPredecessorsTypeVal)->push_back((yyvsp[(2) - (2)].StepWithPredecessorsTypeVal));}
    break;

  case 76:

    {(yyval.ListStepWithPredecessorsTypeVal) = new std::list<StepWithPredecessorsType *>;
	   (yyval.ListStepWithPredecessorsTypeVal)->push_back((yyvsp[(1) - (1)].StepWithPredecessorsTypeVal));}
    break;

  case 77:

    {(yyval.ListVariableDeclarationTypeVal) = new std::list<VariableDeclarationType *>;}
    break;

  case 78:

    {(yyval.ListVariableDeclarationTypeVal) = (yyvsp[(1) - (2)].ListVariableDeclarationTypeVal);
	   (yyval.ListVariableDeclarationTypeVal)->push_back((yyvsp[(2) - (2)].VariableDeclarationTypeVal));}
    break;

  case 79:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);}
    break;

  case 80:

    {yyReadData = 1;}
    break;

  case 81:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);}
    break;

  case 82:

    {yyReadData = 1;}
    break;

  case 83:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 84:

    {(yyval.NumberedPlanElementTypeVal) = new NumberedPlanElementType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlPositiveIntegerVal), (yyvsp[(4) - (4)].PlanElementBaseTypeVal));}
    break;

  case 85:

    {yyReadData = 1;}
    break;

  case 86:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);}
    break;

  case 87:

    {(yyval.PositiveDecimalTypeVal) = 0;}
    break;

  case 88:

    {yyReadData = 1;}
    break;

  case 89:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  }
    break;

  case 90:

    {yyReadData = 1;}
    break;

  case 91:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 92:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);}
    break;

  case 93:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);}
    break;

  case 94:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);}
    break;

  case 95:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);}
    break;

  case 96:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);}
    break;

  case 97:

    {yyReadData = 1;}
    break;

  case 98:

    {(yyval.XmlTokenVal) = (yyvsp[(4) - (5)].XmlTokenVal);}
    break;

  case 99:

    {yyReadData = 1;}
    break;

  case 100:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);}
    break;

  case 101:

    {yyReadData = 1;}
    break;

  case 102:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 103:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].AttachEndEffectorTypeVal);}
    break;

  case 104:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].CreateKitTypeVal);}
    break;

  case 105:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].DetachEndEffectorTypeVal);}
    break;

  case 106:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].IfActionGroupTypeVal);}
    break;

  case 107:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].LocatePartTypeVal);}
    break;

  case 108:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].OneOfActionGroupTypeVal);}
    break;

  case 109:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].OrderedActionGroupTypeVal);}
    break;

  case 110:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PartiallyOrderedActionGroupTypeVal);}
    break;

  case 111:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutKitTrayTypeVal);}
    break;

  case 112:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutKitTypeVal);}
    break;

  case 113:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutPartTypeVal);}
    break;

  case 114:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].SomeOfActionGroupTypeVal);}
    break;

  case 115:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakeKitTrayTypeVal);}
    break;

  case 116:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakeKitTypeVal);}
    break;

  case 117:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakePartTypeVal);}
    break;

  case 118:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].UnorderedActionGroupTypeVal);}
    break;

  case 119:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].VarSetTypeVal);}
    break;

  case 120:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].WhileActionGroupTypeVal);}
    break;

  case 121:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);}
    break;

  case 122:

    {yyReadData = 1;}
    break;

  case 123:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 124:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);}
    break;

  case 125:

    {yyReadData = 1;}
    break;

  case 126:

    {(yyval.XmlTokenVal) = (yyvsp[(4) - (5)].XmlTokenVal);}
    break;

  case 127:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));}
    break;

  case 128:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 129:

    {(yyval.PositiveDecimalTypeVal) = 0;}
    break;

  case 130:

    {yyReadData = 1;}
    break;

  case 131:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  }
    break;

  case 132:

    {yyReadData = 1;}
    break;

  case 133:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 134:

    {yyReadData = 1;}
    break;

  case 135:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 136:

    {yyReadData = 1;}
    break;

  case 137:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 138:

    {yyReadData = 1;}
    break;

  case 139:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 140:

    {yyReadData = 1;}
    break;

  case 141:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);}
    break;

  case 142:

    {(yyval.StepWithPredecessorsTypeVal) = new StepWithPredecessorsType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlPositiveIntegerVal), (yyvsp[(4) - (5)].ListXmlPositiveIntegerVal), (yyvsp[(5) - (5)].PlanElementBaseTypeVal));}
    break;

  case 143:

    {(yyval.NumberedPlanElementTypeVal) = (yyvsp[(2) - (3)].NumberedPlanElementTypeVal);}
    break;

  case 144:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);}
    break;

  case 145:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);}
    break;

  case 146:

    {(yyval.StepWithPredecessorsTypeVal) = (yyvsp[(2) - (3)].StepWithPredecessorsTypeVal);}
    break;

  case 147:

    {(yyval.TestAndStepTypeVal) = new TestAndStepType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].BooleanExpressionTypeVal), (yyvsp[(4) - (4)].PlanElementBaseTypeVal));}
    break;

  case 148:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);}
    break;

  case 149:

    {yyReadData = 1;}
    break;

  case 150:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);}
    break;

  case 151:

    {(yyval.XmlDateTimeVal) = 0;}
    break;

  case 152:

    {yyReadData = 1;}
    break;

  case 153:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);}
    break;

  case 154:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);}
    break;

  case 155:

    {yyReadData = 1;}
    break;

  case 156:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 157:

    {yyReadData = 1;}
    break;

  case 158:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);}
    break;

  case 159:

    {(yyval.VariableDeclarationTypeVal) = new VariableDeclarationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlDecimalVal));}
    break;

  case 160:

    {(yyval.VariableDeclarationTypeVal) = (yyvsp[(2) - (3)].VariableDeclarationTypeVal);}
    break;

  case 161:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));}
    break;

  case 162:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 163:

    {yyReadData = 1;}
    break;

  case 164:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 165:

    {yyReadData = 1;}
    break;

  case 166:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 167:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 168:

    {yyReadData = 1;}
    break;

  case 169:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 170:

    {(yyval.AndTypeVal) = new AndType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].BooleanExpressionTypeVal));
	   (yyval.AndTypeVal)->printTypp = true;
	  }
    break;

  case 171:

    {(yyval.AttachEndEffectorTypeVal) = new AttachEndEffectorType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));
	   (yyval.AttachEndEffectorTypeVal)->printTypp = true;
	  }
    break;

  case 172:

    {(yyval.CreateKitTypeVal) = new CreateKitType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.CreateKitTypeVal)->printTypp = true;
	  }
    break;

  case 173:

    {(yyval.DecimalTypeVal) = new DecimalType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlDecimalVal));
	   (yyval.DecimalTypeVal)->printTypp = true;
	  }
    break;

  case 174:

    {(yyval.DetachEndEffectorTypeVal) = new DetachEndEffectorType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));
	   (yyval.DetachEndEffectorTypeVal)->printTypp = true;
	  }
    break;

  case 175:

    {(yyval.DivTypeVal) = new DivType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.DivTypeVal)->printTypp = true;
	  }
    break;

  case 176:

    {(yyval.EqualTypeVal) = new EqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.EqualTypeVal)->printTypp = true;
	  }
    break;

  case 177:

    {(yyval.FalseTypeVal) = new FalseType((yyvsp[(3) - (3)].XmlIDVal));
	   (yyval.FalseTypeVal)->printTypp = true;
	  }
    break;

  case 178:

    {(yyval.GreaterOrEqualTypeVal) = new GreaterOrEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.GreaterOrEqualTypeVal)->printTypp = true;
	  }
    break;

  case 179:

    {(yyval.GreaterTypeVal) = new GreaterType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.GreaterTypeVal)->printTypp = true;
	  }
    break;

  case 180:

    {(yyval.IfActionGroupTypeVal) = new IfActionGroupType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].TestAndStepTypeVal), (yyvsp[(5) - (6)].ListTestAndStepTypeVal), (yyvsp[(6) - (6)].ElseDoTypeVal));
	   (yyval.IfActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 181:

    {(yyval.LessOrEqualTypeVal) = new LessOrEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.LessOrEqualTypeVal)->printTypp = true;
	  }
    break;

  case 182:

    {(yyval.LessTypeVal) = new LessType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.LessTypeVal)->printTypp = true;
	  }
    break;

  case 183:

    {(yyval.LocatePartTypeVal) = new LocatePartType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlNMTOKENVal));
	   (yyval.LocatePartTypeVal)->printTypp = true;
	  }
    break;

  case 184:

    {(yyval.MinusTypeVal) = new MinusType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.MinusTypeVal)->printTypp = true;
	  }
    break;

  case 185:

    {(yyval.ModTypeVal) = new ModType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.ModTypeVal)->printTypp = true;
	  }
    break;

  case 186:

    {(yyval.NegateTypeVal) = new NegateType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ArithmeticExpressionTypeVal));
	   (yyval.NegateTypeVal)->printTypp = true;
	  }
    break;

  case 187:

    {(yyval.NotEqualTypeVal) = new NotEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.NotEqualTypeVal)->printTypp = true;
	  }
    break;

  case 188:

    {(yyval.NotTypeVal) = new NotType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].BooleanExpressionTypeVal));
	   (yyval.NotTypeVal)->printTypp = true;
	  }
    break;

  case 189:

    {(yyval.OneOfActionGroupTypeVal) = new OneOfActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ListNumberedPlanElementTypeVal));
	   (yyval.OneOfActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 190:

    {(yyval.OrTypeVal) = new OrType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].BooleanExpressionTypeVal));
	   (yyval.OrTypeVal)->printTypp = true;
	  }
    break;

  case 191:

    {(yyval.OrderedActionGroupTypeVal) = new OrderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ListNumberedPlanElementTypeVal));
	   (yyval.OrderedActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 192:

    {(yyval.PartiallyOrderedActionGroupTypeVal) = new PartiallyOrderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ListStepWithPredecessorsTypeVal));
	   (yyval.PartiallyOrderedActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 193:

    {(yyval.PlusTypeVal) = new PlusType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.PlusTypeVal)->printTypp = true;
	  }
    break;

  case 194:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  }
    break;

  case 195:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  }
    break;

  case 196:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  }
    break;

  case 197:

    {(yyval.PropValTypeVal) = new PropValType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.PropValTypeVal)->printTypp = true;
	  }
    break;

  case 198:

    {(yyval.PutKitTrayTypeVal) = new PutKitTrayType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutKitTrayTypeVal)->printTypp = true;
	  }
    break;

  case 199:

    {(yyval.PutKitTypeVal) = new PutKitType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutKitTypeVal)->printTypp = true;
	  }
    break;

  case 200:

    {(yyval.PutPartTypeVal) = new PutPartType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutPartTypeVal)->printTypp = true;
	  }
    break;

  case 201:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  }
    break;

  case 202:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  }
    break;

  case 203:

    {(yyval.SomeOfActionGroupTypeVal) = new SomeOfActionGroupType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ListPlanElementBaseTypeVal), (yyvsp[(5) - (5)].XmlPositiveIntegerVal));
	   (yyval.SomeOfActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 204:

    {(yyval.TakeKitTrayTypeVal) = new TakeKitTrayType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakeKitTrayTypeVal)->printTypp = true;
	  }
    break;

  case 205:

    {(yyval.TakeKitTypeVal) = new TakeKitType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakeKitTypeVal)->printTypp = true;
	  }
    break;

  case 206:

    {(yyval.TakePartTypeVal) = new TakePartType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakePartTypeVal)->printTypp = true;
	  }
    break;

  case 207:

    {(yyval.TimesTypeVal) = new TimesType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.TimesTypeVal)->printTypp = true;
	  }
    break;

  case 208:

    {(yyval.TrueTypeVal) = new TrueType((yyvsp[(3) - (3)].XmlIDVal));
	   (yyval.TrueTypeVal)->printTypp = true;
	  }
    break;

  case 209:

    {(yyval.UnorderedActionGroupTypeVal) = new UnorderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ListPlanElementBaseTypeVal));
	   (yyval.UnorderedActionGroupTypeVal)->printTypp = true;
	  }
    break;

  case 210:

    {(yyval.VarSetTypeVal) = new VarSetType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.VarSetTypeVal)->printTypp = true;
	  }
    break;

  case 211:

    {(yyval.VarValTypeVal) = new VarValType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlIDREFVal));
	   (yyval.VarValTypeVal)->printTypp = true;
	  }
    break;

  case 212:

    {(yyval.WhileActionGroupTypeVal) = new WhileActionGroupType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].PlanElementBaseTypeVal));
	   (yyval.WhileActionGroupTypeVal)->printTypp = true;
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

