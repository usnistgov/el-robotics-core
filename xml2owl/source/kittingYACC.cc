/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.3"

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
#include "kittingClasses.hh"   // for kitting classes

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingWorkstationFile * KittingWorkstationTree; // the parse tree

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
     ANGLEUNITEND = 269,
     ANGLEUNITSTART = 270,
     ARRAYNUMBEREND = 271,
     ARRAYNUMBERSTART = 272,
     ARRAYRADIUSEND = 273,
     ARRAYRADIUSSTART = 274,
     BASEEND = 275,
     BASESTART = 276,
     CAPACITYEND = 277,
     CAPACITYSTART = 278,
     CHANGINGSTATIONEND = 279,
     CHANGINGSTATIONSTART = 280,
     CUPDIAMETEREND = 281,
     CUPDIAMETERSTART = 282,
     DESCRIPTIONEND = 283,
     DESCRIPTIONSTART = 284,
     DESIGNNAMEEND = 285,
     DESIGNNAMESTART = 286,
     DIAMETEREND = 287,
     DIAMETERSTART = 288,
     ENDEFFECTORHOLDEREND = 289,
     ENDEFFECTORHOLDERSTART = 290,
     ENDEFFECTORNAMEEND = 291,
     ENDEFFECTORNAMESTART = 292,
     ENDEFFECTOREND = 293,
     ENDEFFECTORSTART = 294,
     EXTERNALSHAPEEND = 295,
     EXTERNALSHAPESTART = 296,
     FINISHEDEND = 297,
     FINISHEDSTART = 298,
     GRASPPOSEEND = 299,
     GRASPPOSESTART = 300,
     HASTOPEND = 301,
     HASTOPSTART = 302,
     HEIGHTEND = 303,
     HEIGHTSTART = 304,
     HELDOBJECTEND = 305,
     HELDOBJECTSTART = 306,
     IEND = 307,
     ISTART = 308,
     INTERNALSHAPEEND = 309,
     INTERNALSHAPESTART = 310,
     JEND = 311,
     JSTART = 312,
     KEND = 313,
     KSTART = 314,
     KITDESIGNNAMEEND = 315,
     KITDESIGNNAMESTART = 316,
     KITDESIGNEND = 317,
     KITDESIGNSTART = 318,
     KITTRAYSKUNAMEEND = 319,
     KITTRAYSKUNAMESTART = 320,
     KITTRAYEND = 321,
     KITTRAYSTART = 322,
     KITEND = 323,
     KITSTART = 324,
     KITTINGWORKSTATIONEND = 325,
     KITTINGWORKSTATIONSTART = 326,
     LARGECONTAINEREND = 327,
     LARGECONTAINERSTART = 328,
     LENGTHUNITEND = 329,
     LENGTHUNITSTART = 330,
     LENGTHEND = 331,
     LENGTHSTART = 332,
     MAXIMUMLOADWEIGHTEND = 333,
     MAXIMUMLOADWEIGHTSTART = 334,
     MAXIMUMPOINTEND = 335,
     MAXIMUMPOINTSTART = 336,
     MINIMUMPOINTEND = 337,
     MINIMUMPOINTSTART = 338,
     MODELFILENAMEEND = 339,
     MODELFILENAMESTART = 340,
     MODELNAMEEND = 341,
     MODELNAMESTART = 342,
     MODELTYPENAMEEND = 343,
     MODELTYPENAMESTART = 344,
     NAMEEND = 345,
     NAMESTART = 346,
     OBJECTEND = 347,
     OBJECTSTART = 348,
     ORIENTATIONSTANDARDDEVIATIONEND = 349,
     ORIENTATIONSTANDARDDEVIATIONSTART = 350,
     OTHEROBSTACLEEND = 351,
     OTHEROBSTACLESTART = 352,
     PARTNAMEEND = 353,
     PARTNAMESTART = 354,
     PARTQUANTITYEND = 355,
     PARTQUANTITYSTART = 356,
     PARTREFANDPOSENAMEEND = 357,
     PARTREFANDPOSENAMESTART = 358,
     PARTREFANDPOSEEND = 359,
     PARTREFANDPOSESTART = 360,
     PARTSKUNAMEEND = 361,
     PARTSKUNAMESTART = 362,
     PARTEND = 363,
     PARTSTART = 364,
     PARTSTRAYEND = 365,
     PARTSTRAYSTART = 366,
     POINTEND = 367,
     POINTSTART = 368,
     POSITIONSTANDARDDEVIATIONEND = 369,
     POSITIONSTANDARDDEVIATIONSTART = 370,
     PRIMARYLOCATIONEND = 371,
     PRIMARYLOCATIONSTART = 372,
     REFOBJECTNAMEEND = 373,
     REFOBJECTNAMESTART = 374,
     ROBOTEND = 375,
     ROBOTSTART = 376,
     SECONDARYLOCATIONEND = 377,
     SECONDARYLOCATIONSTART = 378,
     SERIALNUMBEREND = 379,
     SERIALNUMBERSTART = 380,
     SHAPEEND = 381,
     SHAPESTART = 382,
     SKUNAMEEND = 383,
     SKUNAMESTART = 384,
     SKUEND = 385,
     SKUSTART = 386,
     SLOTEND = 387,
     SLOTSTART = 388,
     SOLIDOBJECTEND = 389,
     SOLIDOBJECTSTART = 390,
     TIMESTAMPEND = 391,
     TIMESTAMPSTART = 392,
     WEIGHTUNITEND = 393,
     WEIGHTUNITSTART = 394,
     WEIGHTEND = 395,
     WEIGHTSTART = 396,
     WIDTHEND = 397,
     WIDTHSTART = 398,
     WORKVOLUMEEND = 399,
     WORKVOLUMESTART = 400,
     XAXISEND = 401,
     XAXISSTART = 402,
     XEND = 403,
     XSTART = 404,
     YEND = 405,
     YSTART = 406,
     ZAXISEND = 407,
     ZAXISSTART = 408,
     ZEND = 409,
     ZSTART = 410,
     BOXVOLUMETYPEDECL = 411,
     BOXYSHAPETYPEDECL = 412,
     CYLINDRICALSHAPETYPEDECL = 413,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 414,
     ENDEFFECTORHOLDERTYPEDECL = 415,
     ENDEFFECTORTYPEDECL = 416,
     EXTERNALSHAPETYPEDECL = 417,
     GRIPPEREFFECTORTYPEDECL = 418,
     HUMANTYPEDECL = 419,
     INTERNALSHAPETYPEDECL = 420,
     KITDESIGNTYPEDECL = 421,
     KITTRAYTYPEDECL = 422,
     KITTYPEDECL = 423,
     KITTINGWORKSTATIONTYPEDECL = 424,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 425,
     LARGEBOXWITHKITSTYPEDECL = 426,
     LARGECONTAINERTYPEDECL = 427,
     MECHANICALCOMPONENTTYPEDECL = 428,
     PARTREFANDPOSETYPEDECL = 429,
     PARTTYPEDECL = 430,
     PARTSBINTYPEDECL = 431,
     PARTSTRAYTYPEDECL = 432,
     PARTSTRAYWITHPARTSTYPEDECL = 433,
     PHYSICALLOCATIONTYPEDECL = 434,
     POINTTYPEDECL = 435,
     POSELOCATIONINTYPEDECL = 436,
     POSELOCATIONONTYPEDECL = 437,
     POSELOCATIONTYPEDECL = 438,
     POSEONLYLOCATIONTYPEDECL = 439,
     RELATIVELOCATIONINTYPEDECL = 440,
     RELATIVELOCATIONONTYPEDECL = 441,
     RELATIVELOCATIONTYPEDECL = 442,
     ROBOTTYPEDECL = 443,
     SHAPEDESIGNTYPEDECL = 444,
     SLOTTYPEDECL = 445,
     STOCKKEEPINGUNITTYPEDECL = 446,
     VACUUMEFFECTORMULTICUPTYPEDECL = 447,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 448,
     VACUUMEFFECTORTYPEDECL = 449,
     VECTORTYPEDECL = 450,
     WORKTABLETYPEDECL = 451
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingWorkstation *    XmlHeaderForKittingWorkstationVal;
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

  KittingWorkstationFile *            KittingWorkstationFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  std::list<BoxVolumeType *> *        BoxVolumeTypeListVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  CylindricalShapeType *              CylindricalShapeTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
  std::list<XmlIDREF *> *             IDREFListVal;
  InternalShapeType *                 InternalShapeTypeVal;
  std::list<KitDesignType *> *        KitDesignTypeListVal;
  KitDesignType *                     KitDesignTypeVal;
  std::list<KitTrayType *> *          KitTrayTypeListVal;
  KitTrayType *                       KitTrayTypeVal;
  std::list<KitType *> *              KitTypeListVal;
  KitType *                           KitTypeVal;
  KittingWorkstationType *            KittingWorkstationTypeVal;
  LargeBoxWithEmptyKitTraysType *     LargeBoxWithEmptyKitTraysTypeVal;
  LargeBoxWithKitsType *              LargeBoxWithKitsTypeVal;
  LargeContainerType *                LargeContainerTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  MechanicalComponentType *           MechanicalComponentTypeVal;
  std::list<PartRefAndPoseType *> *   PartRefAndPoseTypeListVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  std::list<PartType *> *             PartTypeListVal;
  PartType *                          PartTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsTrayWithPartsType *            PartsTrayWithPartsTypeVal;
  std::list<PhysicalLocationType *> * PhysicalLocationTypeListVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotType *                         RobotTypeVal;
  ShapeDesignType *                   ShapeDesignTypeVal;
  std::list<SlotType *> *             SlotTypeListVal;
  SlotType *                          SlotTypeVal;
  std::list<SolidObjectType *> *      SolidObjectTypeListVal;
  SolidObjectType *                   SolidObjectTypeVal;
  std::list<StockKeepingUnitType *> * StockKeepingUnitTypeListVal;
  StockKeepingUnitType *              StockKeepingUnitTypeVal;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  190
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNRULES -- Number of states.  */
#define YYNSTATES  766

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   451

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
     195,   196
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    17,    19,    21,    23,
      25,    27,    29,    31,    33,    38,    45,    46,    52,    53,
      59,    60,    66,    70,    75,    76,    82,    86,    87,    93,
      94,   100,   101,   107,   108,   114,   123,   131,   135,   137,
     140,   141,   147,   148,   151,   153,   155,   157,   158,   162,
     170,   171,   175,   176,   182,   183,   187,   188,   194,   195,
     201,   202,   206,   207,   213,   215,   217,   218,   222,   223,
     229,   230,   236,   237,   243,   248,   252,   254,   257,   258,
     264,   273,   277,   281,   282,   285,   297,   301,   302,   305,
     321,   330,   334,   335,   341,   342,   348,   349,   355,   359,
     366,   370,   371,   377,   378,   379,   385,   386,   392,   393,
     399,   403,   405,   408,   409,   410,   416,   420,   421,   424,
     425,   426,   432,   433,   439,   440,   446,   453,   457,   459,
     462,   463,   469,   478,   482,   483,   486,   495,   499,   501,
     503,   505,   507,   509,   515,   519,   521,   523,   525,   526,
     527,   533,   537,   538,   544,   555,   559,   563,   564,   567,
     568,   574,   576,   578,   580,   584,   585,   591,   595,   597,
     600,   605,   609,   610,   613,   615,   617,   619,   621,   623,
     625,   627,   629,   631,   633,   635,   637,   639,   641,   643,
     645,   647,   649,   651,   655,   656,   659,   666,   667,   668,
     674,   680,   681,   687,   688,   694,   695,   701,   705,   707,
     710,   714,   715,   721,   722,   728,   732,   733,   739,   749,
     758,   768,   777,   786,   798,   806,   816,   829,   846,   856,
     868,   878,   886,   896,   908,   918,   928,   939,   950,   961,
     968,   975,   987,  1003,  1017
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     198,     0,    -1,   210,    71,   199,   271,    70,    -1,    11,
     200,    -1,     8,    10,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     9,    13,    10,     7,    -1,     9,    13,
      10,     5,    10,     7,    -1,    -1,    15,     6,   212,     4,
      14,    -1,    -1,    17,     6,   214,   208,    16,    -1,    -1,
      19,     6,   216,     4,    18,    -1,    21,   281,    20,    -1,
       6,   289,   280,   282,    -1,    -1,    23,     6,   220,   208,
      22,    -1,    25,   230,    24,    -1,    -1,    27,     6,   223,
       4,    26,    -1,    -1,    29,     6,   225,   209,    28,    -1,
      -1,    31,     6,   227,   205,    30,    -1,    -1,    33,     6,
     229,     4,    32,    -1,     6,   289,   319,   325,   252,   240,
     217,   233,    -1,     6,   289,   319,   325,   252,   240,   238,
      -1,    35,   231,    34,    -1,   232,    -1,   233,   232,    -1,
      -1,    37,     6,   235,   205,    36,    -1,    -1,   236,   234,
      -1,   365,    -1,   384,    -1,   385,    -1,    -1,    39,   237,
      38,    -1,     6,   289,   224,   243,   287,   283,   285,    -1,
      -1,    41,   239,    40,    -1,    -1,    43,     6,   242,   201,
      42,    -1,    -1,    45,   316,    44,    -1,    -1,    47,     6,
     245,   201,    46,    -1,    -1,    49,     6,   247,     4,    48,
      -1,    -1,    51,   337,    50,    -1,    -1,    53,     6,   250,
     203,    52,    -1,   360,    -1,   361,    -1,    -1,    55,   251,
      54,    -1,    -1,    57,     6,   254,   203,    56,    -1,    -1,
      59,     6,   256,   203,    58,    -1,    -1,    61,     6,   258,
     205,    60,    -1,     6,   289,   262,   305,    -1,    63,   259,
      62,    -1,   260,    -1,   261,   260,    -1,    -1,    65,     6,
     263,   205,    64,    -1,     6,   289,   319,   325,   252,   240,
     330,   326,    -1,    67,   264,    66,    -1,    67,   264,    66,
      -1,    -1,   267,   266,    -1,     6,   289,   319,   325,   252,
     240,   226,   265,   310,   336,   241,    -1,    69,   268,    68,
      -1,    -1,   270,   269,    -1,     6,   289,   319,   325,   252,
     240,   211,   221,   261,   274,   292,   296,   323,   333,   344,
      -1,     6,   289,   319,   325,   252,   240,   330,   326,    -1,
      73,   272,    72,    -1,    -1,    75,     6,   275,     4,    74,
      -1,    -1,    77,     6,   277,     4,    76,    -1,    -1,    79,
       6,   279,     4,    78,    -1,    81,   314,    80,    -1,     6,
     289,   319,   325,   252,   240,    -1,    83,   314,    82,    -1,
      -1,    85,     6,   284,   209,    84,    -1,    -1,    -1,    87,
       6,   286,   209,    86,    -1,    -1,    89,     6,   288,   209,
      88,    -1,    -1,    91,     6,   290,   204,    90,    -1,    93,
     337,    92,    -1,   291,    -1,   292,   291,    -1,    -1,    -1,
      95,     6,   294,     4,    94,    -1,    97,   218,    96,    -1,
      -1,   296,   295,    -1,    -1,    -1,    99,     6,   298,   205,
      98,    -1,    -1,   101,     6,   300,   207,   100,    -1,    -1,
     103,     6,   302,   205,   102,    -1,     6,   289,   330,   315,
     352,   357,    -1,   105,   303,   104,    -1,   304,    -1,   305,
     304,    -1,    -1,   107,     6,   307,   205,   106,    -1,     6,
     289,   319,   325,   252,   240,   330,   326,    -1,   109,   308,
     108,    -1,    -1,   310,   309,    -1,     6,   289,   319,   325,
     252,   240,   330,   326,    -1,   111,   311,   110,    -1,   378,
      -1,   379,    -1,   380,    -1,   381,    -1,   382,    -1,     6,
     289,   353,   355,   358,    -1,   113,   314,   112,    -1,   378,
      -1,   379,    -1,   380,    -1,    -1,    -1,   115,     6,   318,
       4,   114,    -1,   117,   313,   116,    -1,    -1,   119,     6,
     321,   205,   118,    -1,     6,   289,   319,   325,   252,   240,
     224,   238,   278,   351,    -1,   121,   322,   120,    -1,   123,
     313,   122,    -1,    -1,   325,   324,    -1,    -1,   125,     6,
     327,   206,   124,    -1,   360,    -1,   361,    -1,   364,    -1,
     127,   328,   126,    -1,    -1,   129,     6,   331,   205,   128,
      -1,   131,   340,   130,    -1,   332,    -1,   333,   332,    -1,
       6,   289,   301,   297,    -1,   133,   334,   132,    -1,    -1,
     336,   335,    -1,   362,    -1,   363,    -1,   365,    -1,   366,
      -1,   367,    -1,   368,    -1,   369,    -1,   370,    -1,   371,
      -1,   372,    -1,   373,    -1,   374,    -1,   375,    -1,   376,
      -1,   377,    -1,   383,    -1,   384,    -1,   385,    -1,   386,
      -1,   135,   337,   134,    -1,    -1,   339,   338,    -1,     6,
     289,   224,   329,   346,   236,    -1,    -1,    -1,   137,     6,
     342,   202,   136,    -1,     6,   289,   249,   253,   255,    -1,
      -1,   139,     6,   345,     4,   138,    -1,    -1,   141,     6,
     347,     4,   140,    -1,    -1,   143,     6,   349,     4,   142,
      -1,   145,   218,   144,    -1,   350,    -1,   351,   350,    -1,
     147,   343,   146,    -1,    -1,   149,     6,   354,   203,   148,
      -1,    -1,   151,     6,   356,   203,   150,    -1,   153,   343,
     152,    -1,    -1,   155,     6,   359,   203,   154,    -1,   157,
       6,   289,   224,   243,   276,   348,   246,   244,    -1,   158,
       6,   289,   224,   243,   228,   246,   244,    -1,   159,     6,
     289,   319,   325,   252,   240,   217,   233,    -1,   160,     6,
     289,   319,   325,   252,   240,   238,    -1,   162,     6,   289,
     224,   243,   287,   283,   285,    -1,   163,     6,   289,   319,
     325,   252,   240,   224,   346,   278,   248,    -1,   164,     6,
     289,   319,   325,   252,   240,    -1,   167,     6,   289,   319,
     325,   252,   240,   330,   326,    -1,   168,     6,   289,   319,
     325,   252,   240,   226,   265,   310,   336,   241,    -1,   169,
       6,   289,   319,   325,   252,   240,   211,   221,   261,   274,
     292,   296,   323,   333,   344,    -1,   170,     6,   289,   319,
     325,   252,   240,   273,   267,    -1,   171,     6,   289,   319,
     325,   252,   240,   273,   270,   257,   219,    -1,   172,     6,
     289,   319,   325,   252,   240,   330,   326,    -1,   173,     6,
     289,   319,   325,   252,   240,    -1,   175,     6,   289,   319,
     325,   252,   240,   330,   326,    -1,   176,     6,   289,   319,
     325,   252,   240,   330,   326,   306,   299,    -1,   177,     6,
     289,   319,   325,   252,   240,   330,   326,    -1,   178,     6,
     289,   319,   325,   252,   240,   312,   310,    -1,   181,     6,
     289,   320,   341,   315,   352,   357,   317,   293,    -1,   182,
       6,   289,   320,   341,   315,   352,   357,   317,   293,    -1,
     184,     6,   289,   320,   341,   315,   352,   357,   317,   293,
      -1,   185,     6,   289,   320,   341,   224,    -1,   186,     6,
     289,   320,   341,   224,    -1,   188,     6,   289,   319,   325,
     252,   240,   224,   238,   278,   351,    -1,   192,     6,   289,
     319,   325,   252,   240,   224,   346,   278,   248,   222,   276,
     213,   215,    -1,   193,     6,   289,   319,   325,   252,   240,
     224,   346,   278,   248,   222,   276,    -1,   196,     6,   289,
     319,   325,   252,   240,   339,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   451,   451,   461,   466,   472,   480,   488,   496,   504,
     512,   520,   528,   536,   544,   549,   560,   560,   568,   568,
     574,   574,   583,   588,   594,   594,   600,   606,   606,   615,
     615,   621,   621,   627,   627,   635,   645,   654,   660,   663,
     670,   670,   677,   678,   684,   686,   688,   694,   695,   700,
     708,   709,   714,   714,   720,   721,   726,   726,   731,   731,
     740,   741,   746,   746,   751,   753,   759,   760,   765,   765,
     770,   770,   775,   775,   781,   787,   792,   795,   801,   801,
     807,   816,   821,   827,   828,   834,   844,   850,   851,   857,
     870,   879,   884,   884,   893,   893,   901,   901,   910,   915,
     923,   928,   928,   935,   936,   936,   941,   941,   947,   947,
     952,   957,   960,   967,   968,   968,   977,   983,   984,   992,
     993,   993,   998,   998,  1004,  1004,  1010,  1016,  1021,  1024,
    1031,  1031,  1037,  1046,  1052,  1053,  1059,  1068,  1073,  1075,
    1077,  1079,  1081,  1086,  1092,  1097,  1099,  1101,  1107,  1108,
    1108,  1117,  1122,  1122,  1128,  1139,  1144,  1151,  1152,  1159,
    1159,  1165,  1167,  1169,  1174,  1179,  1179,  1184,  1189,  1192,
    1198,  1204,  1210,  1211,  1217,  1219,  1221,  1223,  1225,  1227,
    1229,  1231,  1233,  1235,  1237,  1239,  1241,  1243,  1245,  1247,
    1249,  1251,  1253,  1258,  1264,  1265,  1272,  1280,  1281,  1281,
    1287,  1293,  1293,  1302,  1302,  1310,  1310,  1318,  1323,  1326,
    1332,  1337,  1337,  1342,  1342,  1347,  1352,  1352,  1357,  1367,
    1377,  1390,  1402,  1412,  1426,  1437,  1449,  1462,  1478,  1490,
    1503,  1515,  1526,  1538,  1551,  1563,  1575,  1586,  1597,  1608,
    1617,  1626,  1640,  1656,  1671
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BAD", "DATASTRING", "ENCODING",
  "ENDITEM", "ENDVERSION", "SCHEMALOCATION", "STARTVERSION",
  "TERMINALSTRING", "XMLNSPREFIX", "XMLNSTARGET", "XMLVERSION",
  "ANGLEUNITEND", "ANGLEUNITSTART", "ARRAYNUMBEREND", "ARRAYNUMBERSTART",
  "ARRAYRADIUSEND", "ARRAYRADIUSSTART", "BASEEND", "BASESTART",
  "CAPACITYEND", "CAPACITYSTART", "CHANGINGSTATIONEND",
  "CHANGINGSTATIONSTART", "CUPDIAMETEREND", "CUPDIAMETERSTART",
  "DESCRIPTIONEND", "DESCRIPTIONSTART", "DESIGNNAMEEND", "DESIGNNAMESTART",
  "DIAMETEREND", "DIAMETERSTART", "ENDEFFECTORHOLDEREND",
  "ENDEFFECTORHOLDERSTART", "ENDEFFECTORNAMEEND", "ENDEFFECTORNAMESTART",
  "ENDEFFECTOREND", "ENDEFFECTORSTART", "EXTERNALSHAPEEND",
  "EXTERNALSHAPESTART", "FINISHEDEND", "FINISHEDSTART", "GRASPPOSEEND",
  "GRASPPOSESTART", "HASTOPEND", "HASTOPSTART", "HEIGHTEND", "HEIGHTSTART",
  "HELDOBJECTEND", "HELDOBJECTSTART", "IEND", "ISTART", "INTERNALSHAPEEND",
  "INTERNALSHAPESTART", "JEND", "JSTART", "KEND", "KSTART",
  "KITDESIGNNAMEEND", "KITDESIGNNAMESTART", "KITDESIGNEND",
  "KITDESIGNSTART", "KITTRAYSKUNAMEEND", "KITTRAYSKUNAMESTART",
  "KITTRAYEND", "KITTRAYSTART", "KITEND", "KITSTART",
  "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART", "LARGECONTAINEREND",
  "LARGECONTAINERSTART", "LENGTHUNITEND", "LENGTHUNITSTART", "LENGTHEND",
  "LENGTHSTART", "MAXIMUMLOADWEIGHTEND", "MAXIMUMLOADWEIGHTSTART",
  "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART", "MINIMUMPOINTEND",
  "MINIMUMPOINTSTART", "MODELFILENAMEEND", "MODELFILENAMESTART",
  "MODELNAMEEND", "MODELNAMESTART", "MODELTYPENAMEEND",
  "MODELTYPENAMESTART", "NAMEEND", "NAMESTART", "OBJECTEND", "OBJECTSTART",
  "ORIENTATIONSTANDARDDEVIATIONEND", "ORIENTATIONSTANDARDDEVIATIONSTART",
  "OTHEROBSTACLEEND", "OTHEROBSTACLESTART", "PARTNAMEEND", "PARTNAMESTART",
  "PARTQUANTITYEND", "PARTQUANTITYSTART", "PARTREFANDPOSENAMEEND",
  "PARTREFANDPOSENAMESTART", "PARTREFANDPOSEEND", "PARTREFANDPOSESTART",
  "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND", "PARTSTART",
  "PARTSTRAYEND", "PARTSTRAYSTART", "POINTEND", "POINTSTART",
  "POSITIONSTANDARDDEVIATIONEND", "POSITIONSTANDARDDEVIATIONSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "REFOBJECTNAMEEND",
  "REFOBJECTNAMESTART", "ROBOTEND", "ROBOTSTART", "SECONDARYLOCATIONEND",
  "SECONDARYLOCATIONSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SHAPEEND", "SHAPESTART", "SKUNAMEEND", "SKUNAMESTART", "SKUEND",
  "SKUSTART", "SLOTEND", "SLOTSTART", "SOLIDOBJECTEND", "SOLIDOBJECTSTART",
  "TIMESTAMPEND", "TIMESTAMPSTART", "WEIGHTUNITEND", "WEIGHTUNITSTART",
  "WEIGHTEND", "WEIGHTSTART", "WIDTHEND", "WIDTHSTART", "WORKVOLUMEEND",
  "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND",
  "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "BOXVOLUMETYPEDECL", "BOXYSHAPETYPEDECL", "CYLINDRICALSHAPETYPEDECL",
  "ENDEFFECTORCHANGINGSTATIONTYPEDECL", "ENDEFFECTORHOLDERTYPEDECL",
  "ENDEFFECTORTYPEDECL", "EXTERNALSHAPETYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "HUMANTYPEDECL", "INTERNALSHAPETYPEDECL",
  "KITDESIGNTYPEDECL", "KITTRAYTYPEDECL", "KITTYPEDECL",
  "KITTINGWORKSTATIONTYPEDECL", "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL",
  "LARGEBOXWITHKITSTYPEDECL", "LARGECONTAINERTYPEDECL",
  "MECHANICALCOMPONENTTYPEDECL", "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL",
  "PARTSBINTYPEDECL", "PARTSTRAYTYPEDECL", "PARTSTRAYWITHPARTSTYPEDECL",
  "PHYSICALLOCATIONTYPEDECL", "POINTTYPEDECL", "POSELOCATIONINTYPEDECL",
  "POSELOCATIONONTYPEDECL", "POSELOCATIONTYPEDECL",
  "POSEONLYLOCATIONTYPEDECL", "RELATIVELOCATIONINTYPEDECL",
  "RELATIVELOCATIONONTYPEDECL", "RELATIVELOCATIONTYPEDECL",
  "ROBOTTYPEDECL", "SHAPEDESIGNTYPEDECL", "SLOTTYPEDECL",
  "STOCKKEEPINGUNITTYPEDECL", "VACUUMEFFECTORMULTICUPTYPEDECL",
  "VACUUMEFFECTORSINGLECUPTYPEDECL", "VACUUMEFFECTORTYPEDECL",
  "VECTORTYPEDECL", "WORKTABLETYPEDECL", "$accept",
  "y_KittingWorkstationFile", "y_XmlHeaderForKittingWorkstation",
  "y_SchemaLocation", "y_XmlBoolean", "y_XmlDateTime", "y_XmlDecimal",
  "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN", "y_XmlNonNegativeInteger",
  "y_XmlPositiveInteger", "y_XmlString", "y_XmlVersion",
  "y_AngleUnit_AngleUnitType", "$@1", "y_ArrayNumber_XmlPositiveInteger",
  "$@2", "y_ArrayRadius_PositiveDecimalType", "$@3",
  "y_Base_MechanicalComponentType", "y_BoxVolumeType",
  "y_Capacity_XmlPositiveInteger", "$@4",
  "y_ChangingStation_EndEffectorChangingStationType",
  "y_CupDiameter_PositiveDecimalType", "$@5", "y_Description_XmlString",
  "$@6", "y_DesignName_XmlIDREF", "$@7", "y_Diameter_PositiveDecimalType",
  "$@8", "y_EndEffectorChangingStationType", "y_EndEffectorHolderType",
  "y_EndEffectorHolder_EndEffectorHolderType_u",
  "y_EndEffectorHolder_EndEffectorHolderType_uList",
  "y_EndEffectorName_XmlIDREF_0_u", "$@9",
  "y_EndEffectorName_XmlIDREF_0_uList", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType_0", "y_ExternalShapeType",
  "y_ExternalShape_ExternalShapeType_0", "y_Finished_XmlBoolean", "$@10",
  "y_GraspPose_PoseLocationType_0", "y_HasTop_XmlBoolean", "$@11",
  "y_Height_PositiveDecimalType", "$@12", "y_HeldObject_SolidObjectType_0",
  "y_I_XmlDecimal", "$@13", "y_InternalShapeTypeAny",
  "y_InternalShape_InternalShapeType_0", "y_J_XmlDecimal", "$@14",
  "y_K_XmlDecimal", "$@15", "y_KitDesignName_XmlIDREF", "$@16",
  "y_KitDesignType", "y_KitDesign_KitDesignType_u",
  "y_KitDesign_KitDesignType_uList", "y_KitTraySkuName_XmlIDREF", "$@17",
  "y_KitTrayType", "y_KitTray_KitTrayType", "y_KitTray_KitTrayType_0_u",
  "y_KitTray_KitTrayType_0_uList", "y_KitType", "y_Kit_KitType_0_u",
  "y_Kit_KitType_0_uList", "y_KittingWorkstationType",
  "y_LargeContainerType", "y_LargeContainer_LargeContainerType",
  "y_LengthUnit_LengthUnitType", "$@18", "y_Length_PositiveDecimalType",
  "$@19", "y_MaximumLoadWeight_PositiveDecimalType", "$@20",
  "y_MaximumPoint_PointType", "y_MechanicalComponentType",
  "y_MinimumPoint_PointType", "y_ModelFileName_XmlString", "$@21",
  "y_ModelName_XmlString_0", "$@22", "y_ModelTypeName_XmlString", "$@23",
  "y_Name_XmlID", "$@24", "y_Object_SolidObjectType_u",
  "y_Object_SolidObjectType_uList",
  "y_OrientationStandardDeviation_PositiveDecimalType_0", "$@25",
  "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList", "y_PartName_XmlIDREF_0", "$@26",
  "y_PartQuantity_XmlNonNegativeInteger", "$@27",
  "y_PartRefAndPoseName_XmlIDREF", "$@28", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuName_XmlIDREF",
  "$@29", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PartsTrayType", "y_PartsTray_PartsTrayType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PoseLocationTypeAny",
  "y_PositionStandardDeviation_PositiveDecimalType_0", "$@30",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObjectName_XmlIDREF",
  "$@31", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@32", "y_ShapeDesignTypeAny",
  "y_Shape_ShapeDesignType", "y_SkuName_XmlIDREF", "$@33",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SlotType", "y_Slot_SlotType_0_u", "y_Slot_SlotType_0_uList",
  "y_SolidObjectTypeAny", "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Timestamp_XmlDateTime_0", "$@34", "y_VectorType",
  "y_WeightUnit_WeightUnitType", "$@35", "y_Weight_PositiveDecimalType",
  "$@36", "y_Width_PositiveDecimalType", "$@37",
  "y_WorkVolume_BoxVolumeType_u", "y_WorkVolume_BoxVolumeType_uList",
  "y_XAxis_VectorType", "y_X_XmlDecimal", "$@38", "y_Y_XmlDecimal", "$@39",
  "y_ZAxis_VectorType", "y_Z_XmlDecimal", "$@40", "y_x_BoxyShapeType",
  "y_x_CylindricalShapeType", "y_x_EndEffectorChangingStationType",
  "y_x_EndEffectorHolderType", "y_x_ExternalShapeType",
  "y_x_GripperEffectorType", "y_x_HumanType", "y_x_KitTrayType",
  "y_x_KitType", "y_x_KittingWorkstationType",
  "y_x_LargeBoxWithEmptyKitTraysType", "y_x_LargeBoxWithKitsType",
  "y_x_LargeContainerType", "y_x_MechanicalComponentType", "y_x_PartType",
  "y_x_PartsBinType", "y_x_PartsTrayType", "y_x_PartsTrayWithPartsType",
  "y_x_PoseLocationInType", "y_x_PoseLocationOnType",
  "y_x_PoseOnlyLocationType", "y_x_RelativeLocationInType",
  "y_x_RelativeLocationOnType", "y_x_RobotType",
  "y_x_VacuumEffectorMultiCupType", "y_x_VacuumEffectorSingleCupType",
  "y_x_WorkTableType", 0
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
     445,   446,   447,   448,   449,   450,   451
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   210,   212,   211,   214,   213,
     216,   215,   217,   218,   220,   219,   221,   223,   222,   225,
     224,   227,   226,   229,   228,   230,   231,   232,   233,   233,
     235,   234,   236,   236,   237,   237,   237,   238,   238,   239,
     240,   240,   242,   241,   243,   243,   245,   244,   247,   246,
     248,   248,   250,   249,   251,   251,   252,   252,   254,   253,
     256,   255,   258,   257,   259,   260,   261,   261,   263,   262,
     264,   265,   266,   267,   267,   268,   269,   270,   270,   271,
     272,   273,   275,   274,   277,   276,   279,   278,   280,   281,
     282,   284,   283,   285,   286,   285,   288,   287,   290,   289,
     291,   292,   292,   293,   294,   293,   295,   296,   296,   297,
     298,   297,   300,   299,   302,   301,   303,   304,   305,   305,
     307,   306,   308,   309,   310,   310,   311,   312,   313,   313,
     313,   313,   313,   314,   315,   316,   316,   316,   317,   318,
     317,   319,   321,   320,   322,   323,   324,   325,   325,   327,
     326,   328,   328,   328,   329,   331,   330,   332,   333,   333,
     334,   335,   336,   336,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   338,   339,   339,   340,   341,   342,   341,
     343,   345,   344,   347,   346,   349,   348,   350,   351,   351,
     352,   354,   353,   356,   355,   357,   359,   358,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     0,     5,     0,     5,
       0,     5,     3,     4,     0,     5,     3,     0,     5,     0,
       5,     0,     5,     0,     5,     8,     7,     3,     1,     2,
       0,     5,     0,     2,     1,     1,     1,     0,     3,     7,
       0,     3,     0,     5,     0,     3,     0,     5,     0,     5,
       0,     3,     0,     5,     1,     1,     0,     3,     0,     5,
       0,     5,     0,     5,     4,     3,     1,     2,     0,     5,
       8,     3,     3,     0,     2,    11,     3,     0,     2,    15,
       8,     3,     0,     5,     0,     5,     0,     5,     3,     6,
       3,     0,     5,     0,     0,     5,     0,     5,     0,     5,
       3,     1,     2,     0,     0,     5,     3,     0,     2,     0,
       0,     5,     0,     5,     0,     5,     6,     3,     1,     2,
       0,     5,     8,     3,     0,     2,     8,     3,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     0,     0,
       5,     3,     0,     5,    10,     3,     3,     0,     2,     0,
       5,     1,     1,     1,     3,     0,     5,     3,     1,     2,
       4,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     2,     6,     0,     0,     5,
       5,     0,     5,     0,     5,     0,     5,     3,     1,     2,
       3,     0,     5,     0,     5,     3,     0,     5,     9,     8,
       9,     8,     8,    11,     7,     9,    12,    16,     9,    11,
       9,     7,     9,    11,     9,     9,    10,    10,    10,     6,
       6,    11,    15,    13,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    14,     0,     3,     0,     0,     0,     4,     0,     0,
       2,    15,   108,     0,   157,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,    66,     8,     0,
       0,     0,     0,     0,     0,   151,     0,     0,    50,   158,
     109,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,     0,     0,     0,     0,   197,   197,   197,   197,   197,
       0,     0,    67,   156,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    16,
       0,     0,     0,   198,     0,     0,     0,     0,     0,   239,
     240,    54,    54,    54,     0,     0,     0,     0,    76,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
      77,     0,   153,     6,     0,     0,   144,     0,     0,     0,
     148,   148,   148,     0,     0,   145,   146,   147,     0,     0,
       0,     0,     0,     0,    17,   157,     0,    75,    92,     0,
     111,   117,   199,     0,     0,     0,   210,     0,     0,   113,
     113,   113,    13,     0,    55,    94,     0,     0,    33,     0,
       0,   106,     0,   103,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   112,     0,   211,
       0,     0,     0,     0,   215,   149,     0,   236,   237,   238,
      30,     0,   205,     0,     0,    58,     0,   219,     0,   101,
       0,    49,    50,    78,     0,   128,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
     118,     0,     0,   213,     0,   143,    62,     0,     0,     0,
     114,     0,     0,   218,     0,     0,    56,     0,     0,   104,
       0,     0,     0,     0,   129,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,     0,     7,     0,     0,   216,     0,    68,     0,   200,
       0,     0,    95,     0,    34,     0,     0,   107,     0,     0,
       0,     0,     0,     0,   127,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,     0,   116,     0,   155,     0,     0,
       0,   169,    89,   212,     0,     0,     0,     0,    70,   150,
       0,   206,    59,     5,     0,   102,     0,     0,     0,     0,
      38,    35,    79,     0,     0,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,     0,     0,   157,     0,   167,   201,
     214,     0,    63,     0,     0,   115,    57,   105,     0,    22,
       0,     0,    39,   165,     0,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,     0,     0,    23,    66,     0,     0,
     217,    69,     0,   157,     0,    37,     0,     0,     0,    47,
       0,   224,     0,     0,     0,     0,     0,     0,   231,     0,
       0,     0,     0,     0,     0,     0,   194,    98,     0,    50,
       0,     0,     0,    71,    66,   157,     0,   126,     0,     0,
     221,     0,     0,     0,     0,     0,     0,    83,    87,     0,
       0,     0,     0,     0,   134,    47,     0,     0,   244,   100,
       0,     0,     0,   161,   162,   163,     0,    42,   202,    50,
      66,   166,   220,     0,    44,    45,    46,     0,     0,   225,
      31,     0,   134,     0,     0,     0,   228,     0,   230,   232,
       0,   234,     0,     0,   235,     0,     0,     0,     0,   195,
      47,     0,   164,   203,   196,    99,    50,    48,     0,    60,
     159,     0,     0,     0,   172,     0,     0,    91,     0,    84,
       0,     0,     0,    88,     0,     0,     0,   137,     0,   135,
       0,    60,    60,     0,     0,     0,     0,     0,    43,    47,
      96,     0,   223,     0,     0,     0,    81,     0,     0,   157,
       0,    72,     0,     0,     0,   229,   130,     0,   233,   157,
       0,     0,     0,   208,   241,     0,     0,   193,     0,    54,
       0,    40,    36,     0,     0,    10,     0,    32,   157,     0,
       0,   226,   173,   117,    66,    82,     0,     0,    86,    24,
       0,   122,    66,     0,   133,     0,   209,     0,     0,     0,
     154,     0,   204,     0,     0,    61,   160,    66,    52,     0,
       0,     0,    50,     0,   157,     0,     0,     0,    50,   157,
     207,    27,     0,   243,     0,     0,    97,    50,     0,     0,
     171,     0,     0,    73,    66,    12,     0,   131,    11,     0,
       0,    66,     0,     0,     0,   103,    41,     0,     0,     0,
     119,     0,     0,    50,    25,   123,     0,    50,     0,    18,
       0,   242,   222,     0,    53,   124,     0,   170,   227,    90,
       0,   136,     0,    28,     0,    20,    80,     0,   120,     0,
       0,     0,     0,     0,     0,   134,   132,    19,     0,   125,
       0,   172,    21,   121,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,   394,   134,   333,    39,   111,   646,
     709,   706,   173,     3,    77,   104,   714,   744,   731,   752,
     351,   326,   625,   685,    91,   668,   712,    99,   143,   514,
     581,   151,   244,   106,   441,   400,   401,   608,   673,   574,
     543,   510,    75,    63,   651,   698,   121,   247,   346,   180,
     295,   612,   233,   336,    58,    48,   288,   387,   339,   434,
     592,   656,   128,   108,   109,   186,   301,   583,   552,   589,
     556,   623,   593,   557,    15,   555,   517,   131,   187,   149,
     241,   579,   643,   425,   398,   466,   183,   298,   251,   349,
     153,   248,    19,    25,   160,   161,   237,   341,   280,   228,
     737,   754,   628,   687,   720,   747,   303,   255,   256,   595,
     660,   631,   599,   564,   563,   524,    31,   114,    95,   144,
     169,   289,    24,    65,    92,   328,   281,    49,    37,   549,
     613,   532,   501,   404,   476,   330,   331,   680,   652,   617,
     207,   569,   528,   379,    80,   112,   138,   382,   469,   537,
     606,   177,   292,   633,   634,   116,   164,   282,   231,   334,
     140,   285,   385,    59,    60,   208,   209,   535,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    32,    33,    34,    35,    36,   223,   224,   225,   226
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -607
static const yytype_int16 yypact[] =
{
      35,    41,    57,   -10,    64,  -607,    75,    38,    83,    98,
     107,  -607,   112,  -607,    17,    54,   123,  -607,   126,    28,
    -607,  -607,  -607,   -92,  -607,   142,   141,   143,   144,   145,
     146,    32,  -607,  -607,  -607,  -607,  -607,   -35,  -607,    65,
      17,    17,    17,    17,    17,  -607,   -78,   -92,   113,  -607,
    -607,    37,    37,    37,    37,    37,   151,   152,   105,  -607,
    -607,    39,   154,   147,   157,    27,    27,    27,    27,    27,
      17,    17,  -607,  -607,    17,   125,   160,   148,  -607,   161,
      55,    55,    55,   140,   140,   140,   140,   140,  -607,  -607,
     165,   109,   170,  -607,   169,    29,    29,    29,   171,  -607,
    -607,   133,   133,   133,   175,    17,   156,   176,  -607,   -23,
    -607,    63,   179,    17,    72,   199,    53,    53,    53,  -607,
     -44,   108,   174,   120,   196,    28,  -607,    17,   149,   206,
    -607,   121,  -607,  -607,    79,    67,  -607,    17,    71,   199,
     168,   168,   168,   253,   214,  -607,  -607,  -607,   254,   116,
     255,   237,   283,   207,  -607,  -607,   226,  -607,  -607,   -57,
    -607,   121,  -607,   287,   150,   241,  -607,   153,   290,   203,
     203,   203,  -607,   271,  -607,  -607,   294,   237,  -607,   296,
     256,  -607,   298,   219,   -35,   301,   204,   306,   305,   308,
     309,   310,   311,   313,   314,   315,   317,   318,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   243,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,   -68,  -607,
     330,   182,   333,   284,  -607,  -607,   336,  -607,  -607,  -607,
    -607,   339,  -607,   256,   340,  -607,   341,  -607,   253,  -607,
     342,  -607,   113,  -607,   343,  -607,   204,   272,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,  -607,   344,   345,
    -607,   221,   349,  -607,   352,  -607,  -607,   353,   286,   356,
    -607,   285,   378,  -607,   357,   380,  -607,   297,   253,  -607,
     369,   170,    17,   289,  -607,  -607,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    17,   295,    17,   274,   389,
    -607,   -90,  -607,   248,   349,  -607,   349,  -607,   391,  -607,
     288,   395,  -607,   261,  -607,   358,   400,  -607,   329,   253,
     401,   373,   346,   282,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,   331,  -607,    28,  -607,    17,   291,
     408,  -607,  -607,  -607,   265,   349,   364,   349,  -607,  -607,
     332,  -607,  -607,  -607,   372,  -607,   334,    17,   399,   419,
    -607,   373,  -607,   421,    55,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   169,   347,  -607,   140,  -607,  -607,
    -607,   275,  -607,   375,   349,  -607,  -607,  -607,    28,  -607,
      17,   394,  -607,  -607,    29,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   354,   169,  -607,   -35,   312,   428,
    -607,  -607,   377,  -607,    28,  -607,   170,    53,   369,   397,
     140,  -607,   282,   402,   147,   365,   365,   282,  -607,   282,
     282,   282,   335,   140,   140,   140,  -607,  -607,   355,   113,
     -99,   299,   303,  -607,   -35,  -607,   316,  -607,   373,  -137,
    -607,   299,   337,   436,   376,   148,   439,  -607,  -607,   337,
     337,   337,   337,   441,  -607,   397,   299,   299,   319,  -607,
     140,   442,   338,  -607,  -607,  -607,   443,  -607,  -607,   113,
     -35,  -607,   373,   412,  -607,  -607,  -607,   374,   445,  -607,
    -607,   446,  -607,   109,    17,   383,   393,    -1,  -607,  -607,
     351,  -607,    17,   359,   361,   374,   374,   374,   -57,  -607,
     397,    17,  -607,  -607,   424,  -607,   113,  -607,   450,   414,
    -607,   170,    17,   405,   361,   -23,    28,  -607,   446,  -607,
     457,   461,   449,  -607,   462,   379,    28,  -607,   467,  -607,
     348,   414,   414,   350,   374,   140,   470,   469,  -607,   397,
    -607,   -57,  -607,   473,   448,    28,  -607,   -24,   121,  -607,
     415,  -607,    17,   420,   476,  -607,  -607,   477,  -607,  -607,
      17,   381,   344,  -607,   348,   460,   460,  -607,   348,   133,
     360,  -607,  -607,   486,   447,  -607,   367,  -607,  -607,   490,
     493,  -607,  -607,   121,   -35,  -607,   170,    28,  -607,  -607,
     170,  -607,   -35,    28,  -607,   362,  -607,   496,   108,   108,
     348,   120,  -607,   170,   425,  -607,  -607,   -35,  -607,    17,
     384,   -68,   113,   432,  -607,   500,   403,   501,   113,  -607,
    -607,  -607,   491,  -607,   207,   471,  -607,   113,   400,   407,
    -607,   221,   282,  -607,   -35,  -607,   495,  -607,  -607,   413,
     282,   -35,   511,   512,   502,   219,  -607,   282,   481,   513,
     426,   -90,   337,   113,  -607,  -607,   337,   113,   498,  -607,
     520,  -607,  -607,   337,  -607,  -607,   521,  -607,  -607,  -607,
     402,  -607,   282,  -607,   500,  -607,  -607,   170,  -607,   376,
     337,   516,   524,   427,   170,  -607,  -607,  -607,   515,  -607,
     438,   361,  -607,  -607,   -24,  -607
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -607,  -607,  -607,  -607,  -160,  -607,  -309,  -607,  -268,  -607,
    -607,  -205,  -226,  -607,    56,  -607,  -607,  -607,  -607,  -607,
      68,   -91,  -607,  -607,    30,   -89,  -607,   -71,  -607,  -192,
    -607,  -607,  -607,  -607,  -607,  -389,    42,  -607,  -607,  -607,
    -607,  -504,  -607,   -82,  -215,  -607,   -95,   366,  -607,   382,
    -607,  -506,  -607,  -607,  -607,  -142,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -100,    -2,  -607,  -607,   -36,  -196,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,    69,   -31,  -607,  -535,
    -607,  -519,  -607,  -607,  -607,  -607,  -138,  -607,  -158,  -607,
    -113,  -607,   -40,  -607,  -155,   -55,   -29,  -607,  -607,   -93,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,   363,  -607,  -607,
    -607,  -607,  -607,  -542,  -607,  -607,   514,  -388,   -64,  -607,
       2,  -607,  -120,    46,  -607,  -607,  -117,  -607,  -118,  -438,
    -607,  -607,  -607,  -420,  -607,  -320,  -136,  -607,  -607,  -194,
    -536,  -607,  -607,  -607,    60,  -607,   429,  -151,  -607,  -476,
    -607,  -607,  -607,  -606,   -66,   -58,  -607,  -607,  -607,  -607,
     -94,  -607,  -607,    73,    74,  -607,  -607,  -607,    66,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,   456,   458,   459,  -607,  -607,  -607,    76,    77,  -607
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      51,    52,    53,    54,    55,   155,   227,   122,   123,   130,
     584,   381,   442,   100,   101,   102,   103,    96,    97,   649,
      46,   565,   297,   141,   142,   384,   190,   386,   666,   278,
      85,    86,   603,   352,    87,   547,   464,   184,   117,   118,
     107,   329,   252,    10,     1,    11,   600,   601,   602,   380,
     566,   567,   129,   279,     4,   204,   205,     5,    56,    57,
     590,     6,   512,   531,   666,   125,   604,   519,   591,   520,
     521,   522,   348,   135,     7,   644,   431,   498,   433,    56,
      57,   558,   559,   560,   561,   638,     8,   156,    47,    26,
      27,    12,    28,    29,    30,   635,   636,   165,    66,    67,
      68,    69,   188,   189,    14,   642,   190,   191,    18,   650,
     192,   193,   194,   195,   196,   197,   198,    16,   199,   200,
     201,   202,    17,   396,    20,   472,    81,    82,    83,    84,
      21,   203,    22,   692,   693,   204,   205,    26,    27,   206,
      28,   238,   239,   170,   171,    23,    38,    40,    45,    41,
      42,    43,    44,   442,    62,    50,    64,    70,    71,    72,
      74,    73,    76,    78,    79,    88,    89,    93,    94,    98,
     300,   105,   107,    90,   110,   113,   115,   119,   120,   124,
     126,   132,   127,   133,   136,   148,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   137,   139,   150,   506,   152,
     154,   157,   158,   761,   159,   162,   163,   166,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   426,   172,   174,   176,
     175,   178,   353,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   722,   168,   739,   374,   179,   376,   741,   181,
     726,   185,   182,   229,   232,   746,   235,   733,   236,   240,
     242,   230,   245,   246,   249,   234,   250,   253,   467,   254,
     257,   258,   756,   614,   259,   260,   261,   262,   473,   263,
     264,   265,   750,   266,   267,   499,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   283,   284,   427,   286,
     444,   287,   290,   291,   294,   338,   305,   296,   299,   302,
     325,   327,   329,   332,   505,   504,   468,   438,   335,   337,
     340,   342,   539,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   343,   507,   345,   347,   477,   540,   683,   344,
     350,   375,   686,   354,   377,   378,   383,   388,   576,   390,
     474,   381,   389,   391,   393,   695,   392,   397,   399,   511,
     402,   403,   424,   395,   429,   430,   432,   530,   436,   439,
     437,   428,   525,   526,   527,   440,   435,   443,   475,   470,
     465,   471,   502,   513,   497,   503,   509,   529,   516,   500,
     536,   538,   550,   551,   541,   554,   523,   562,   571,   573,
     577,   580,   582,   578,   568,   587,   610,   575,   594,   570,
     588,   607,   548,   621,   572,   611,   619,   622,   626,   597,
     598,   616,   624,   630,   640,   641,   629,   645,   647,   753,
     627,   655,   659,   661,   637,   130,   760,   667,   658,   664,
     674,   676,   703,   632,   609,   648,   678,   675,   227,   679,
     672,   654,   691,   696,   705,   708,   690,   716,   713,   707,
     719,   662,   682,   725,   586,   728,   700,   724,   729,   735,
     688,   730,   596,   734,   743,   736,   745,   748,   758,   759,
     677,   605,   757,   762,   639,   697,   763,   684,   718,   751,
     515,   665,   615,   689,   671,   553,   508,   669,   749,   765,
     542,   585,   620,   755,   618,   518,   715,   732,   694,   243,
     681,    61,   723,   653,   701,   721,   704,   764,   167,   727,
     738,   711,   670,   533,   534,   544,   145,     0,   146,   147,
       0,     0,   657,     0,     0,   545,   546,     0,     0,     0,
     663,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     702,     0,     0,     0,     0,     0,   710,     0,     0,   293,
       0,     0,     0,     0,     0,   717,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   699,
       0,   740,     0,     0,     0,   742
};

static const yytype_int16 yycheck[] =
{
      40,    41,    42,    43,    44,   125,   161,   102,   103,   109,
     552,   331,   401,    84,    85,    86,    87,    81,    82,    43,
      55,   525,   248,   117,   118,   334,   163,   336,   634,    97,
      70,    71,   568,   301,    74,   511,   424,   155,    96,    97,
      63,   131,   184,     5,     9,     7,   565,   566,   567,   139,
     526,   527,    75,   121,    13,   192,   193,     0,   157,   158,
      61,    71,   482,   162,   670,   105,   570,   487,    69,   489,
     490,   491,   298,   113,    10,   611,   385,   465,   387,   157,
     158,   519,   520,   521,   522,   604,    11,   127,   123,   181,
     182,     8,   184,   185,   186,   601,   602,   137,    52,    53,
      54,    55,   159,   160,     6,   609,   163,   164,    91,   133,
     167,   168,   169,   170,   171,   172,   173,    10,   175,   176,
     177,   178,    10,   349,    70,   434,    66,    67,    68,    69,
       7,   188,     6,   668,   669,   192,   193,   181,   182,   196,
     184,   170,   171,   141,   142,   117,     4,     6,   116,     6,
       6,     6,     6,   542,    41,    90,   119,     6,     6,    54,
       6,   122,    15,     6,   137,    40,     6,     6,   113,    29,
     252,     6,    63,    25,     4,     6,   147,     6,    45,     4,
      24,   118,     6,     4,   112,    77,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,     6,   153,    33,   476,    89,
      14,    62,     6,   755,    93,   136,   149,   146,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   376,     4,    44,   143,
       6,     6,   302,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   702,   115,   722,   325,    49,   327,   726,     6,
     710,    65,    85,     6,    53,   733,     6,   717,    95,    28,
       6,   151,     6,    47,     6,   152,    87,     6,   426,   105,
       4,     6,   750,   581,     6,     6,     6,     6,   438,     6,
       6,     6,   742,     6,     6,   467,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    92,     6,   155,   378,     6,
     404,    57,     6,     4,     4,    59,    74,     6,     6,     6,
       6,     6,   131,     4,   474,   473,   427,   397,     6,     6,
       4,    76,   504,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,     4,   477,     4,    88,   444,   505,   656,    32,
      21,    96,   660,   104,   120,     6,   148,     6,   540,     4,
     440,   721,   114,   142,     4,   673,    48,     6,    35,   480,
      64,   129,    81,    84,     6,   150,    52,   499,    46,    20,
      86,   130,   493,   494,   495,     6,    94,     6,    34,   154,
      83,    56,     4,    31,    80,    58,    39,    82,    73,   127,
     141,   138,     6,    67,   128,     6,   111,     6,     6,     6,
      38,     6,     6,    79,   135,    72,     6,   539,   107,   530,
      67,    37,   125,     6,   126,    51,   586,     6,     6,   110,
     109,    66,    23,     6,     4,     6,   596,     4,    30,   747,
     101,    66,     6,     6,   134,   585,   754,    27,    68,   108,
       4,   124,    60,   145,   576,   615,     6,    50,   653,     6,
     140,   619,     6,    78,     4,     4,   144,    36,    17,   106,
     103,   629,   654,   100,   554,     4,   132,    22,     6,     6,
     662,    19,   562,    42,    26,    99,     6,     6,     4,   102,
     648,   571,    16,    18,   605,   677,    98,   657,   698,   744,
     484,   632,   582,   663,   639,   515,   478,   636,   740,   764,
     508,   553,   588,   749,   585,   486,   694,   715,   671,   177,
     653,    47,   704,   618,   681,   701,   684,   761,   139,   711,
     721,   689,   638,   500,   500,   509,   120,    -1,   120,   120,
      -1,    -1,   622,    -1,    -1,   509,   509,    -1,    -1,    -1,
     630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     682,    -1,    -1,    -1,    -1,    -1,   688,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,
      -1,   723,    -1,    -1,    -1,   727
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   198,   210,    13,     0,    71,    10,    11,   199,
       5,     7,     8,   200,     6,   271,    10,    10,    91,   289,
      70,     7,     6,   117,   319,   290,   181,   182,   184,   185,
     186,   313,   378,   379,   380,   381,   382,   325,     4,   204,
       6,     6,     6,     6,     6,   116,    55,   123,   252,   324,
      90,   289,   289,   289,   289,   289,   157,   158,   251,   360,
     361,   313,    41,   240,   119,   320,   320,   320,   320,   320,
       6,     6,    54,   122,     6,   239,    15,   211,     6,   137,
     341,   341,   341,   341,   341,   289,   289,   289,    40,     6,
      25,   221,   321,     6,   113,   315,   315,   315,    29,   224,
     224,   224,   224,   224,   212,     6,   230,    63,   260,   261,
       4,   205,   342,     6,   314,   147,   352,   352,   352,     6,
      45,   243,   243,   243,     4,   289,    24,     6,   259,    75,
     260,   274,   118,     4,   202,   289,   112,     6,   343,   153,
     357,   357,   357,   225,   316,   378,   379,   380,    77,   276,
      33,   228,    89,   287,    14,   319,   289,    62,     6,    93,
     291,   292,   136,   149,   353,   289,   146,   343,   115,   317,
     317,   317,     4,   209,    44,     6,   143,   348,     6,    49,
     246,     6,    85,   283,   325,    65,   262,   275,   159,   160,
     163,   164,   167,   168,   169,   170,   171,   172,   173,   175,
     176,   177,   178,   188,   192,   193,   196,   337,   362,   363,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   383,   384,   385,   386,   291,   296,     6,
     151,   355,    53,   249,   152,     6,    95,   293,   293,   293,
      28,   277,     6,   246,   229,     6,    47,   244,   288,     6,
      87,   285,   252,     6,   105,   304,   305,     4,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,    92,    97,   121,
     295,   323,   354,     6,   155,   358,     6,    57,   253,   318,
       6,     4,   349,   244,     4,   247,     6,   209,   284,     6,
     240,   263,     6,   303,   304,    74,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,     6,   218,     6,   322,   131,
     332,   333,     4,   203,   356,     6,   250,     6,    59,   255,
       4,   294,    76,     4,    32,     4,   245,    88,   209,   286,
      21,   217,   205,   289,   104,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   289,    96,   289,   120,     6,   340,
     139,   332,   344,   148,   203,   359,   203,   254,     6,   114,
       4,   142,    48,     4,   201,    84,   209,     6,   281,    35,
     232,   233,    64,   129,   330,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,    81,   280,   319,   289,   130,     6,
     150,   203,    52,   203,   256,    94,    46,    86,   289,    20,
       6,   231,   232,     6,   315,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   314,    83,   282,   325,   224,   345,
     154,    56,   203,   319,   289,    34,   331,   352,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,    80,   314,   252,
     127,   329,     4,    58,   325,   319,   205,   357,   217,    39,
     238,   224,   330,    31,   226,   211,    73,   273,   273,   330,
     330,   330,   330,   111,   312,   224,   224,   224,   339,    82,
     240,   162,   328,   360,   361,   364,   141,   346,   138,   252,
     325,   128,   233,   237,   365,   384,   385,   346,   125,   326,
       6,    67,   265,   221,     6,   272,   267,   270,   326,   326,
     326,   326,     6,   311,   310,   238,   346,   346,   135,   338,
     224,     6,   126,     6,   236,   240,   252,    38,    79,   278,
       6,   227,     6,   264,   310,   261,   289,    72,    67,   266,
      61,    69,   257,   269,   107,   306,   289,   110,   109,   309,
     278,   278,   278,   337,   238,   289,   347,    37,   234,   240,
       6,    51,   248,   327,   205,   289,    66,   336,   274,   319,
     264,     6,     6,   268,    23,   219,     6,   101,   299,   319,
       6,   308,   145,   350,   351,   248,   248,   134,   278,   224,
       4,     6,   238,   279,   337,     4,   206,    30,   319,    43,
     133,   241,   335,   292,   325,    66,   258,   289,    68,     6,
     307,     6,   325,   289,   108,   218,   350,    27,   222,   222,
     351,   243,   140,   235,     4,    50,   124,   325,     6,     6,
     334,   296,   252,   205,   319,   220,   205,   300,   252,   319,
     144,     6,   276,   276,   287,   205,    78,   252,   242,   289,
     132,   323,   240,    60,   325,     4,   208,   106,     4,   207,
     240,   325,   223,    17,   213,   283,    36,   240,   201,   103,
     301,   333,   330,   252,    22,   100,   330,   252,     4,     6,
      19,   215,   285,   330,    42,     6,    99,   297,   344,   326,
     240,   326,   240,    26,   214,     6,   326,   302,     6,   226,
     330,   208,   216,   205,   298,   265,   326,    16,     4,   102,
     205,   310,    18,    98,   336,   241
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
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

    {(yyval.KittingWorkstationFileVal) = new KittingWorkstationFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForKittingWorkstationVal), (yyvsp[(4) - (5)].KittingWorkstationTypeVal));
	   KittingWorkstationTree = (yyval.KittingWorkstationFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  ;}
    break;

  case 3:

    {(yyval.XmlHeaderForKittingWorkstationVal) = new XmlHeaderForKittingWorkstation((yyvsp[(2) - (2)].SchemaLocationVal));;}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal), false);
	  ;}
    break;

  case 5:

    {(yyval.XmlBooleanVal) = new XmlBoolean((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlBooleanVal)->bad)
	     yyerror("bad XmlBoolean");
	  ;}
    break;

  case 6:

    {(yyval.XmlDateTimeVal) = new XmlDateTime((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDateTimeVal)->bad)
	     yyerror("bad XmlDateTime");
	  ;}
    break;

  case 7:

    {(yyval.XmlDecimalVal) = new XmlDecimal((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDecimalVal)->bad)
	     yyerror("bad XmlDecimal");
	  ;}
    break;

  case 8:

    {(yyval.XmlIDVal) = new XmlID((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDVal)->bad)
	     yyerror("bad XmlID");
	  ;}
    break;

  case 9:

    {(yyval.XmlIDREFVal) = new XmlIDREF((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDREFVal)->bad)
	     yyerror("bad XmlIDREF");
	  ;}
    break;

  case 10:

    {(yyval.XmlNMTOKENVal) = new XmlNMTOKEN((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNMTOKENVal)->bad)
	     yyerror("bad XmlNMTOKEN");
	  ;}
    break;

  case 11:

    {(yyval.XmlNonNegativeIntegerVal) = new XmlNonNegativeInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNonNegativeIntegerVal)->bad)
	     yyerror("bad XmlNonNegativeInteger");
	  ;}
    break;

  case 12:

    {(yyval.XmlPositiveIntegerVal) = new XmlPositiveInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlPositiveIntegerVal)->bad)
	     yyerror("bad XmlPositiveInteger");
	  ;}
    break;

  case 13:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  ;}
    break;

  case 14:

    {(yyval.XmlVersionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  ;}
    break;

  case 15:

    {(yyval.XmlVersionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp((yyvsp[(5) - (6)].sVal), "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  ;}
    break;

  case 16:

    {yyReadData = 1;;}
    break;

  case 17:

    {(yyval.AngleUnitTypeVal) = new AngleUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.AngleUnitTypeVal)->bad)
	     yyerror("bad AngleUnit value");
	  ;}
    break;

  case 18:

    {yyReadData = 1;;}
    break;

  case 19:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 20:

    {yyReadData = 1;;}
    break;

  case 21:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad ArrayRadius value");
	  ;}
    break;

  case 22:

    {(yyval.MechanicalComponentTypeVal) = (yyvsp[(2) - (3)].MechanicalComponentTypeVal);;}
    break;

  case 23:

    {(yyval.BoxVolumeTypeVal) = new BoxVolumeType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PointTypeVal), (yyvsp[(4) - (4)].PointTypeVal));;}
    break;

  case 24:

    {yyReadData = 1;;}
    break;

  case 25:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 26:

    {(yyval.EndEffectorChangingStationTypeVal) = (yyvsp[(2) - (3)].EndEffectorChangingStationTypeVal);;}
    break;

  case 27:

    {yyReadData = 1;;}
    break;

  case 28:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad CupDiameter value");
	  ;}
    break;

  case 29:

    {yyReadData = 1;;}
    break;

  case 30:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 31:

    {yyReadData = 1;;}
    break;

  case 32:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 33:

    {yyReadData = 1;;}
    break;

  case 34:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Diameter value");
	  ;}
    break;

  case 35:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].MechanicalComponentTypeVal), (yyvsp[(8) - (8)].EndEffectorHolderTypeListVal));;}
    break;

  case 36:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].PhysicalLocationTypeListVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].EndEffectorTypeVal));;}
    break;

  case 37:

    {(yyval.EndEffectorHolderTypeVal) = (yyvsp[(2) - (3)].EndEffectorHolderTypeVal);;}
    break;

  case 38:

    {(yyval.EndEffectorHolderTypeListVal) = new std::list<EndEffectorHolderType *>;
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(1) - (1)].EndEffectorHolderTypeVal));;}
    break;

  case 39:

    {(yyval.EndEffectorHolderTypeListVal) = (yyvsp[(1) - (2)].EndEffectorHolderTypeListVal);
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(2) - (2)].EndEffectorHolderTypeVal));;}
    break;

  case 40:

    {yyReadData = 1;;}
    break;

  case 41:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 42:

    {(yyval.IDREFListVal) = new std::list<XmlIDREF *>;;}
    break;

  case 43:

    {(yyval.IDREFListVal) = (yyvsp[(1) - (2)].IDREFListVal);
	   (yyval.IDREFListVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));;}
    break;

  case 44:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 45:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 46:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 47:

    {(yyval.EndEffectorTypeVal) = 0;;}
    break;

  case 48:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 49:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].PoseLocationTypeVal), (yyvsp[(5) - (7)].XmlStringVal), (yyvsp[(6) - (7)].XmlStringVal), (yyvsp[(7) - (7)].XmlStringVal));;}
    break;

  case 50:

    {(yyval.ExternalShapeTypeVal) = 0;;}
    break;

  case 51:

    {(yyval.ExternalShapeTypeVal) = (yyvsp[(2) - (3)].ExternalShapeTypeVal);;}
    break;

  case 52:

    {yyReadData = 1;;}
    break;

  case 53:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 54:

    {(yyval.PoseLocationTypeVal) = 0;;}
    break;

  case 55:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(2) - (3)].PoseLocationTypeVal);;}
    break;

  case 56:

    {yyReadData = 1;;}
    break;

  case 57:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 58:

    {yyReadData = 1;;}
    break;

  case 59:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 60:

    {(yyval.SolidObjectTypeVal) = 0;;}
    break;

  case 61:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 62:

    {yyReadData = 1;;}
    break;

  case 63:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 64:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 65:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].CylindricalShapeTypeVal);;}
    break;

  case 66:

    {(yyval.InternalShapeTypeVal) = 0;;}
    break;

  case 67:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(2) - (3)].InternalShapeTypeVal);;}
    break;

  case 68:

    {yyReadData = 1;;}
    break;

  case 69:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 70:

    {yyReadData = 1;;}
    break;

  case 71:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 72:

    {yyReadData = 1;;}
    break;

  case 73:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 74:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].PartRefAndPoseTypeListVal));;}
    break;

  case 75:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 76:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 77:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 78:

    {yyReadData = 1;;}
    break;

  case 79:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 80:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 81:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 82:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 83:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 84:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 85:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (11)].XmlIDVal), (yyvsp[(3) - (11)].PhysicalLocationTypeVal), (yyvsp[(4) - (11)].PhysicalLocationTypeListVal), (yyvsp[(5) - (11)].InternalShapeTypeVal), (yyvsp[(6) - (11)].ExternalShapeTypeVal), (yyvsp[(7) - (11)].XmlIDREFVal), (yyvsp[(8) - (11)].KitTrayTypeVal), (yyvsp[(9) - (11)].PartTypeListVal), (yyvsp[(10) - (11)].SlotTypeListVal), (yyvsp[(11) - (11)].XmlBooleanVal));;}
    break;

  case 86:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 87:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 88:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 89:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (15)].XmlIDVal), (yyvsp[(3) - (15)].PhysicalLocationTypeVal), (yyvsp[(4) - (15)].PhysicalLocationTypeListVal), (yyvsp[(5) - (15)].InternalShapeTypeVal), (yyvsp[(6) - (15)].ExternalShapeTypeVal), (yyvsp[(7) - (15)].AngleUnitTypeVal), (yyvsp[(8) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(9) - (15)].KitDesignTypeListVal), (yyvsp[(10) - (15)].LengthUnitTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeListVal), (yyvsp[(12) - (15)].BoxVolumeTypeListVal), (yyvsp[(13) - (15)].RobotTypeVal), (yyvsp[(14) - (15)].StockKeepingUnitTypeListVal), (yyvsp[(15) - (15)].WeightUnitTypeVal));;}
    break;

  case 90:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 91:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 92:

    {yyReadData = 1;;}
    break;

  case 93:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 94:

    {yyReadData = 1;;}
    break;

  case 95:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 96:

    {yyReadData = 1;;}
    break;

  case 97:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 98:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 99:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));;}
    break;

  case 100:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 101:

    {yyReadData = 1;;}
    break;

  case 102:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 103:

    {(yyval.XmlStringVal) = 0;;}
    break;

  case 104:

    {yyReadData = 1;;}
    break;

  case 105:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 106:

    {yyReadData = 1;;}
    break;

  case 107:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 108:

    {yyReadData = 1;;}
    break;

  case 109:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 110:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 111:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 112:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 113:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 114:

    {yyReadData = 1;;}
    break;

  case 115:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  ;}
    break;

  case 116:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 117:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 118:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 119:

    {(yyval.XmlIDREFVal) = 0;;}
    break;

  case 120:

    {yyReadData = 1;;}
    break;

  case 121:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 122:

    {yyReadData = 1;;}
    break;

  case 123:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 124:

    {yyReadData = 1;;}
    break;

  case 125:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 126:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 127:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 128:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 129:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 130:

    {yyReadData = 1;;}
    break;

  case 131:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 132:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 133:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 134:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 135:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 136:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 137:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 138:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 139:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 140:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 141:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 142:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 143:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 144:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 145:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 146:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 147:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 148:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 149:

    {yyReadData = 1;;}
    break;

  case 150:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  ;}
    break;

  case 151:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 152:

    {yyReadData = 1;;}
    break;

  case 153:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 154:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].BoxVolumeTypeListVal));;}
    break;

  case 155:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 156:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 157:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 158:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 159:

    {yyReadData = 1;;}
    break;

  case 160:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 161:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 162:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].CylindricalShapeTypeVal);;}
    break;

  case 163:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].ExternalShapeTypeVal);;}
    break;

  case 164:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 165:

    {yyReadData = 1;;}
    break;

  case 166:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 167:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 168:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 169:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 170:

    {(yyval.SlotTypeVal) = new SlotType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));;}
    break;

  case 171:

    {(yyval.SlotTypeVal) = (yyvsp[(2) - (3)].SlotTypeVal);;}
    break;

  case 172:

    {(yyval.SlotTypeListVal) = new std::list<SlotType *>;;}
    break;

  case 173:

    {(yyval.SlotTypeListVal) = (yyvsp[(1) - (2)].SlotTypeListVal);
	   (yyval.SlotTypeListVal)->push_back((yyvsp[(2) - (2)].SlotTypeVal));;}
    break;

  case 174:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 175:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 176:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 177:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].HumanTypeVal);;}
    break;

  case 178:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 179:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 180:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 181:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 182:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 183:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 184:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);;}
    break;

  case 185:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 186:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 187:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 188:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 189:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 190:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 191:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 192:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 193:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 194:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 195:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 196:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 197:

    {(yyval.XmlDateTimeVal) = 0;;}
    break;

  case 198:

    {yyReadData = 1;;}
    break;

  case 199:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);;}
    break;

  case 200:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 201:

    {yyReadData = 1;;}
    break;

  case 202:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 203:

    {yyReadData = 1;;}
    break;

  case 204:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 205:

    {yyReadData = 1;;}
    break;

  case 206:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 207:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 208:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 209:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 210:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 211:

    {yyReadData = 1;;}
    break;

  case 212:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 213:

    {yyReadData = 1;;}
    break;

  case 214:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 215:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 216:

    {yyReadData = 1;;}
    break;

  case 217:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 218:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlStringVal), (yyvsp[(5) - (9)].PoseLocationTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 219:

    {(yyval.CylindricalShapeTypeVal) = new CylindricalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].XmlBooleanVal));
	   (yyval.CylindricalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 220:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 221:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 222:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].XmlStringVal), (yyvsp[(8) - (8)].XmlStringVal));
	   (yyval.ExternalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 223:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 224:

    {(yyval.HumanTypeVal) = new HumanType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.HumanTypeVal)->printTypp = true;
	  ;}
    break;

  case 225:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 226:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].PhysicalLocationTypeListVal), (yyvsp[(6) - (12)].InternalShapeTypeVal), (yyvsp[(7) - (12)].ExternalShapeTypeVal), (yyvsp[(8) - (12)].XmlIDREFVal), (yyvsp[(9) - (12)].KitTrayTypeVal), (yyvsp[(10) - (12)].PartTypeListVal), (yyvsp[(11) - (12)].SlotTypeListVal), (yyvsp[(12) - (12)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 227:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (16)].XmlIDVal), (yyvsp[(4) - (16)].PhysicalLocationTypeVal), (yyvsp[(5) - (16)].PhysicalLocationTypeListVal), (yyvsp[(6) - (16)].InternalShapeTypeVal), (yyvsp[(7) - (16)].ExternalShapeTypeVal), (yyvsp[(8) - (16)].AngleUnitTypeVal), (yyvsp[(9) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (16)].KitDesignTypeListVal), (yyvsp[(11) - (16)].LengthUnitTypeVal), (yyvsp[(12) - (16)].SolidObjectTypeListVal), (yyvsp[(13) - (16)].BoxVolumeTypeListVal), (yyvsp[(14) - (16)].RobotTypeVal), (yyvsp[(15) - (16)].StockKeepingUnitTypeListVal), (yyvsp[(16) - (16)].WeightUnitTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 228:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 229:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].KitTypeListVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 230:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 231:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  ;}
    break;

  case 232:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 233:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlIDREFVal), (yyvsp[(9) - (11)].XmlNMTOKENVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 234:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 235:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].PartsTrayTypeVal), (yyvsp[(9) - (9)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 236:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 237:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 238:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 239:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 240:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 241:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].EndEffectorTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].BoxVolumeTypeListVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 242:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].InternalShapeTypeVal), (yyvsp[(7) - (15)].ExternalShapeTypeVal), (yyvsp[(8) - (15)].XmlStringVal), (yyvsp[(9) - (15)].PositiveDecimalTypeVal), (yyvsp[(10) - (15)].PositiveDecimalTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeVal), (yyvsp[(12) - (15)].PositiveDecimalTypeVal), (yyvsp[(13) - (15)].PositiveDecimalTypeVal), (yyvsp[(14) - (15)].XmlPositiveIntegerVal), (yyvsp[(15) - (15)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 243:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].PhysicalLocationTypeListVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 244:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].SolidObjectTypeListVal));
	   (yyval.WorkTableTypeVal)->printTypp = true;
	  ;}
    break;



      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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

