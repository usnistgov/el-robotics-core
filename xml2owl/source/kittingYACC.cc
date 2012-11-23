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
#ifdef OWL
#include "kittingClassesOwl.hh"   // for kitting classes
#else
#include "kittingClasses.hh"   // for kitting classes
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingWorkStationFile * KittingWorkStationTree; // the parse tree

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
     CAPACITYEND = 275,
     CAPACITYSTART = 276,
     CHANGINGSTATIONEND = 277,
     CHANGINGSTATIONSTART = 278,
     CUPDIAMETEREND = 279,
     CUPDIAMETERSTART = 280,
     DESCRIPTIONEND = 281,
     DESCRIPTIONSTART = 282,
     DESIGNNAMEEND = 283,
     DESIGNNAMESTART = 284,
     ENDEFFECTORHOLDERSEND = 285,
     ENDEFFECTORHOLDERSSTART = 286,
     ENDEFFECTORNAMEEND = 287,
     ENDEFFECTORNAMESTART = 288,
     ENDEFFECTOREND = 289,
     ENDEFFECTORSTART = 290,
     FINISHEDEND = 291,
     FINISHEDSTART = 292,
     HASTOPEND = 293,
     HASTOPSTART = 294,
     HEIGHTEND = 295,
     HEIGHTSTART = 296,
     IEND = 297,
     ISTART = 298,
     JEND = 299,
     JSTART = 300,
     KEND = 301,
     KSTART = 302,
     KITDESIGNNAMEEND = 303,
     KITDESIGNNAMESTART = 304,
     KITDESIGNEND = 305,
     KITDESIGNSTART = 306,
     KITTRAYSKUNAMEEND = 307,
     KITTRAYSKUNAMESTART = 308,
     KITTRAYSEND = 309,
     KITTRAYSSTART = 310,
     KITEND = 311,
     KITSTART = 312,
     KITTINGWORKSTATIONEND = 313,
     KITTINGWORKSTATIONSTART = 314,
     LARGECONTAINEREND = 315,
     LARGECONTAINERSTART = 316,
     LENGTHUNITEND = 317,
     LENGTHUNITSTART = 318,
     LENGTHEND = 319,
     LENGTHSTART = 320,
     MAXIMUMLOADWEIGHTEND = 321,
     MAXIMUMLOADWEIGHTSTART = 322,
     MAXIMUMPOINTEND = 323,
     MAXIMUMPOINTSTART = 324,
     MINIMUMPOINTEND = 325,
     MINIMUMPOINTSTART = 326,
     NAMEEND = 327,
     NAMESTART = 328,
     OBJECTEND = 329,
     OBJECTSTART = 330,
     OTHEROBSTACLEEND = 331,
     OTHEROBSTACLESTART = 332,
     PARTQUANTITYEND = 333,
     PARTQUANTITYSTART = 334,
     PARTREFANDPOSEEND = 335,
     PARTREFANDPOSESTART = 336,
     PARTSKUNAMEEND = 337,
     PARTSKUNAMESTART = 338,
     PARTEND = 339,
     PARTSTART = 340,
     PARTSTRAYEND = 341,
     PARTSTRAYSTART = 342,
     POINTEND = 343,
     POINTSTART = 344,
     PRIMARYLOCATIONEND = 345,
     PRIMARYLOCATIONSTART = 346,
     REFOBJECTEND = 347,
     REFOBJECTSTART = 348,
     ROBOTEND = 349,
     ROBOTSTART = 350,
     SECONDARYLOCATIONEND = 351,
     SECONDARYLOCATIONSTART = 352,
     SERIALNUMBEREND = 353,
     SERIALNUMBERSTART = 354,
     SHAPEEND = 355,
     SHAPESTART = 356,
     SKUNAMEEND = 357,
     SKUNAMESTART = 358,
     SKUEND = 359,
     SKUSTART = 360,
     SOLIDOBJECTEND = 361,
     SOLIDOBJECTSTART = 362,
     TRAYEND = 363,
     TRAYSTART = 364,
     WEIGHTUNITEND = 365,
     WEIGHTUNITSTART = 366,
     WEIGHTEND = 367,
     WEIGHTSTART = 368,
     WIDTHEND = 369,
     WIDTHSTART = 370,
     WORKTABLEEND = 371,
     WORKTABLESTART = 372,
     WORKVOLUMEEND = 373,
     WORKVOLUMESTART = 374,
     XAXISEND = 375,
     XAXISSTART = 376,
     XEND = 377,
     XSTART = 378,
     YEND = 379,
     YSTART = 380,
     ZAXISEND = 381,
     ZAXISSTART = 382,
     ZEND = 383,
     ZSTART = 384,
     BOXVOLUMETYPEDECL = 385,
     BOXYOBJECTTYPEDECL = 386,
     BOXYSHAPETYPEDECL = 387,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 388,
     ENDEFFECTORHOLDERTYPEDECL = 389,
     ENDEFFECTORTYPEDECL = 390,
     GRIPPEREFFECTORTYPEDECL = 391,
     KITDESIGNTYPEDECL = 392,
     KITTRAYTYPEDECL = 393,
     KITTYPEDECL = 394,
     KITTINGWORKSTATIONTYPEDECL = 395,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 396,
     LARGEBOXWITHKITSTYPEDECL = 397,
     LARGECONTAINERTYPEDECL = 398,
     PARTREFANDPOSETYPEDECL = 399,
     PARTTYPEDECL = 400,
     PARTSBINTYPEDECL = 401,
     PARTSTRAYTYPEDECL = 402,
     PARTSTRAYWITHPARTSTYPEDECL = 403,
     PHYSICALLOCATIONTYPEDECL = 404,
     POINTTYPEDECL = 405,
     POSELOCATIONINTYPEDECL = 406,
     POSELOCATIONONTYPEDECL = 407,
     POSELOCATIONTYPEDECL = 408,
     POSEONLYLOCATIONTYPEDECL = 409,
     RELATIVELOCATIONINTYPEDECL = 410,
     RELATIVELOCATIONONTYPEDECL = 411,
     RELATIVELOCATIONTYPEDECL = 412,
     ROBOTTYPEDECL = 413,
     SHAPEDESIGNTYPEDECL = 414,
     STOCKKEEPINGUNITTYPEDECL = 415,
     VACUUMEFFECTORMULTICUPTYPEDECL = 416,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 417,
     VACUUMEFFECTORTYPEDECL = 418,
     VECTORTYPEDECL = 419,
     WORKTABLETYPEDECL = 420
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingWorkStation *    XmlHeaderForKittingWorkStationVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlBoolean *                        XmlBooleanVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlID *                             XmlIDVal;
  XmlIDREF *                          XmlIDREFVal;
  XmlNMTOKEN *                        XmlNMTOKENVal;
  XmlNonNegativeInteger *             XmlNonNegativeIntegerVal;
  XmlPositiveInteger *                XmlPositiveIntegerVal;
  XmlString *                         XmlStringVal;

  KittingWorkStationFile *            KittingWorkStationFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  std::list<BoxVolumeType *> *        BoxVolumeTypeListVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyObjectType *                    BoxyObjectTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  std::list<XmlIDREF *> *             IDREFListVal;
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
#define YYLAST   579

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  164
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNRULES -- Number of states.  */
#define YYNSTATES  648

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   420

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
     165
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    16,    18,    20,    22,    24,
      26,    28,    30,    32,    37,    44,    45,    51,    52,    58,
      59,    65,    70,    71,    77,    81,    82,    88,    89,    95,
      96,   102,   108,   114,   118,   120,   123,   124,   130,   131,
     134,   136,   138,   140,   142,   143,   147,   148,   154,   155,
     161,   162,   168,   169,   175,   176,   182,   183,   189,   190,
     196,   201,   205,   207,   210,   211,   217,   224,   228,   229,
     232,   241,   245,   246,   249,   264,   271,   275,   276,   282,
     283,   289,   290,   296,   300,   304,   305,   311,   315,   319,
     321,   324,   328,   329,   332,   333,   339,   346,   350,   352,
     355,   356,   362,   369,   373,   374,   377,   384,   388,   392,
     394,   396,   398,   400,   402,   404,   406,   412,   416,   420,
     421,   427,   436,   440,   444,   448,   449,   452,   453,   459,
     461,   465,   466,   472,   476,   478,   481,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   526,   530,   534,
     535,   538,   545,   549,   555,   556,   562,   563,   569,   570,
     576,   585,   589,   593,   595,   598,   602,   603,   609,   610,
     616,   620,   621,   627,   636,   645,   652,   659,   668,   677,
     685,   695,   711,   719,   729,   737,   745,   755,   763,   771,
     779,   787,   795,   803,   809,   815,   821,   831,   844,   855,
     866
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,   178,    59,   168,   229,    58,    -1,    12,
      11,   169,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     9,    13,    10,     7,    -1,     9,    13,    10,
       5,    10,     7,    -1,    -1,    15,     6,   180,     4,    14,
      -1,    -1,    17,     6,   182,   176,    16,    -1,    -1,    19,
       6,   184,     4,    18,    -1,     6,   240,   238,   239,    -1,
      -1,    21,     6,   187,   176,    20,    -1,    23,   195,    22,
      -1,    -1,    25,     6,   190,     4,    24,    -1,    -1,    27,
       6,   192,   177,    26,    -1,    -1,    29,     6,   194,   173,
      28,    -1,     6,   240,   262,   268,   198,    -1,     6,   240,
     262,   268,   203,    -1,    31,   196,    30,    -1,   197,    -1,
     198,   197,    -1,    -1,    33,     6,   200,   173,    32,    -1,
      -1,   201,   199,    -1,   307,    -1,   326,    -1,   327,    -1,
     328,    -1,    -1,    35,   202,    34,    -1,    -1,    37,     6,
     205,   170,    36,    -1,    -1,    39,     6,   207,   170,    38,
      -1,    -1,    41,     6,   209,     4,    40,    -1,    -1,    43,
       6,   211,   171,    42,    -1,    -1,    45,     6,   213,   171,
      44,    -1,    -1,    47,     6,   215,   171,    46,    -1,    -1,
      49,     6,   217,   173,    48,    -1,     6,   240,   221,   250,
      -1,    51,   218,    50,    -1,   219,    -1,   220,   219,    -1,
      -1,    53,     6,   222,   173,    52,    -1,     6,   240,   262,
     268,   273,   269,    -1,    55,   223,    54,    -1,    -1,   225,
     224,    -1,     6,   240,   262,   268,   193,   282,   255,   204,
      -1,    57,   226,    56,    -1,    -1,   228,   227,    -1,     6,
     240,   262,   268,   179,   188,   220,   232,   243,   245,   266,
     276,   284,   291,    -1,     6,   240,   262,   268,   273,   269,
      -1,    61,   230,    60,    -1,    -1,    63,     6,   233,     4,
      62,    -1,    -1,    65,     6,   235,     4,    64,    -1,    -1,
      67,     6,   237,     4,    66,    -1,    69,   260,    68,    -1,
      71,   260,    70,    -1,    -1,    73,     6,   241,   172,    72,
      -1,    75,   277,    74,    -1,    75,   278,    74,    -1,   242,
      -1,   243,   242,    -1,    77,   185,    76,    -1,    -1,   245,
     244,    -1,    -1,    79,     6,   247,   175,    78,    -1,     6,
     240,   273,   261,   294,   299,    -1,    81,   248,    80,    -1,
     249,    -1,   250,   249,    -1,    -1,    83,     6,   252,   173,
      82,    -1,     6,   240,   262,   268,   273,   269,    -1,    85,
     253,    84,    -1,    -1,   255,   254,    -1,     6,   240,   262,
     268,   273,   269,    -1,    87,   256,    86,    -1,     6,   240,
     263,    -1,   318,    -1,   319,    -1,   320,    -1,   321,    -1,
     322,    -1,   323,    -1,   324,    -1,     6,   240,   295,   297,
     300,    -1,    89,   260,    88,    -1,    91,   259,    90,    -1,
      -1,    93,     6,   264,   173,    92,    -1,     6,   240,   262,
     268,   191,   203,   236,   293,    -1,    95,   265,    94,    -1,
      97,   258,    96,    -1,    97,   259,    96,    -1,    -1,   268,
     267,    -1,    -1,    99,     6,   270,   174,    98,    -1,   303,
      -1,   101,   271,   100,    -1,    -1,   103,     6,   274,   173,
     102,    -1,   105,   281,   104,    -1,   275,    -1,   276,   275,
      -1,     6,   240,   262,   268,    -1,   302,    -1,   304,    -1,
     305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,
     310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,
     315,    -1,   316,    -1,   317,    -1,   325,    -1,   326,    -1,
     327,    -1,   328,    -1,   329,    -1,   107,   277,   106,    -1,
     107,   278,   106,    -1,    -1,   280,   279,    -1,     6,   240,
     191,   272,   286,   201,    -1,   109,   223,   108,    -1,     6,
     240,   210,   212,   214,    -1,    -1,   111,     6,   285,     4,
     110,    -1,    -1,   113,     6,   287,     4,   112,    -1,    -1,
     115,     6,   289,     4,   114,    -1,     6,   240,   262,   268,
     234,   288,   208,   280,    -1,   117,   290,   116,    -1,   119,
     185,   118,    -1,   292,    -1,   293,   292,    -1,   121,   283,
     120,    -1,    -1,   123,     6,   296,   171,   122,    -1,    -1,
     125,     6,   298,   171,   124,    -1,   127,   283,   126,    -1,
      -1,   129,     6,   301,   171,   128,    -1,   131,     6,   240,
     262,   268,   234,   288,   208,    -1,   132,     6,   240,   191,
     234,   288,   208,   206,    -1,   133,     6,   240,   262,   268,
     198,    -1,   134,     6,   240,   262,   268,   203,    -1,   135,
       6,   240,   262,   268,   191,   286,   236,    -1,   136,     6,
     240,   262,   268,   191,   286,   236,    -1,   138,     6,   240,
     262,   268,   273,   269,    -1,   139,     6,   240,   262,   268,
     193,   282,   255,   204,    -1,   140,     6,   240,   262,   268,
     179,   188,   220,   232,   243,   245,   266,   276,   284,   291,
      -1,   141,     6,   240,   262,   268,   231,   225,    -1,   142,
       6,   240,   262,   268,   231,   228,   216,   186,    -1,   143,
       6,   240,   262,   268,   273,   269,    -1,   145,     6,   240,
     262,   268,   273,   269,    -1,   146,     6,   240,   262,   268,
     273,   269,   251,   246,    -1,   147,     6,   240,   262,   268,
     273,   269,    -1,   148,     6,   240,   262,   268,   257,   255,
      -1,   151,     6,   240,   263,   261,   294,   299,    -1,   152,
       6,   240,   263,   261,   294,   299,    -1,   153,     6,   240,
     263,   261,   294,   299,    -1,   154,     6,   240,   263,   261,
     294,   299,    -1,   155,     6,   240,   263,   191,    -1,   156,
       6,   240,   263,   191,    -1,   157,     6,   240,   263,   191,
      -1,   158,     6,   240,   262,   268,   191,   203,   236,   293,
      -1,   161,     6,   240,   262,   268,   191,   286,   236,   189,
     234,   181,   183,    -1,   162,     6,   240,   262,   268,   191,
     286,   236,   189,   234,    -1,   163,     6,   240,   262,   268,
     191,   286,   236,   189,   234,    -1,   165,     6,   240,   262,
     268,   234,   288,   208,   280,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   398,   398,   408,   413,   425,   433,   441,   449,   457,
     465,   473,   481,   489,   494,   505,   505,   513,   513,   519,
     519,   528,   534,   534,   540,   546,   546,   555,   555,   561,
     561,   567,   574,   581,   587,   590,   597,   597,   604,   605,
     619,   621,   623,   625,   631,   632,   637,   637,   642,   642,
     647,   647,   655,   655,   660,   660,   665,   665,   670,   670,
     676,   682,   687,   690,   696,   696,   702,   709,   715,   716,
     722,   730,   736,   737,   743,   756,   763,   768,   768,   777,
     777,   785,   785,   794,   799,   804,   804,   809,   811,   816,
     819,   825,   831,   832,   839,   839,   845,   851,   856,   859,
     866,   866,   872,   879,   885,   886,   892,   899,   904,   909,
     911,   913,   915,   917,   919,   921,   926,   932,   937,   942,
     942,   947,   956,   961,   964,   971,   972,   979,   979,   990,
     995,  1000,  1000,  1005,  1010,  1013,  1019,  1025,  1027,  1029,
    1031,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,  1049,
    1051,  1053,  1055,  1057,  1059,  1061,  1063,  1068,  1070,  1076,
    1077,  1084,  1091,  1096,  1102,  1102,  1111,  1111,  1119,  1119,
    1127,  1136,  1141,  1146,  1149,  1155,  1160,  1160,  1165,  1165,
    1170,  1175,  1175,  1180,  1191,  1200,  1210,  1220,  1231,  1242,
    1252,  1263,  1279,  1290,  1301,  1311,  1321,  1332,  1342,  1352,
    1360,  1368,  1376,  1385,  1393,  1401,  1409,  1421,  1435,  1447,
    1459
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
  "ARRAYRADIUSEND", "ARRAYRADIUSSTART", "CAPACITYEND", "CAPACITYSTART",
  "CHANGINGSTATIONEND", "CHANGINGSTATIONSTART", "CUPDIAMETEREND",
  "CUPDIAMETERSTART", "DESCRIPTIONEND", "DESCRIPTIONSTART",
  "DESIGNNAMEEND", "DESIGNNAMESTART", "ENDEFFECTORHOLDERSEND",
  "ENDEFFECTORHOLDERSSTART", "ENDEFFECTORNAMEEND", "ENDEFFECTORNAMESTART",
  "ENDEFFECTOREND", "ENDEFFECTORSTART", "FINISHEDEND", "FINISHEDSTART",
  "HASTOPEND", "HASTOPSTART", "HEIGHTEND", "HEIGHTSTART", "IEND", "ISTART",
  "JEND", "JSTART", "KEND", "KSTART", "KITDESIGNNAMEEND",
  "KITDESIGNNAMESTART", "KITDESIGNEND", "KITDESIGNSTART",
  "KITTRAYSKUNAMEEND", "KITTRAYSKUNAMESTART", "KITTRAYSEND",
  "KITTRAYSSTART", "KITEND", "KITSTART", "KITTINGWORKSTATIONEND",
  "KITTINGWORKSTATIONSTART", "LARGECONTAINEREND", "LARGECONTAINERSTART",
  "LENGTHUNITEND", "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART",
  "MAXIMUMLOADWEIGHTEND", "MAXIMUMLOADWEIGHTSTART", "MAXIMUMPOINTEND",
  "MAXIMUMPOINTSTART", "MINIMUMPOINTEND", "MINIMUMPOINTSTART", "NAMEEND",
  "NAMESTART", "OBJECTEND", "OBJECTSTART", "OTHEROBSTACLEEND",
  "OTHEROBSTACLESTART", "PARTQUANTITYEND", "PARTQUANTITYSTART",
  "PARTREFANDPOSEEND", "PARTREFANDPOSESTART", "PARTSKUNAMEEND",
  "PARTSKUNAMESTART", "PARTEND", "PARTSTART", "PARTSTRAYEND",
  "PARTSTRAYSTART", "POINTEND", "POINTSTART", "PRIMARYLOCATIONEND",
  "PRIMARYLOCATIONSTART", "REFOBJECTEND", "REFOBJECTSTART", "ROBOTEND",
  "ROBOTSTART", "SECONDARYLOCATIONEND", "SECONDARYLOCATIONSTART",
  "SERIALNUMBEREND", "SERIALNUMBERSTART", "SHAPEEND", "SHAPESTART",
  "SKUNAMEEND", "SKUNAMESTART", "SKUEND", "SKUSTART", "SOLIDOBJECTEND",
  "SOLIDOBJECTSTART", "TRAYEND", "TRAYSTART", "WEIGHTUNITEND",
  "WEIGHTUNITSTART", "WEIGHTEND", "WEIGHTSTART", "WIDTHEND", "WIDTHSTART",
  "WORKTABLEEND", "WORKTABLESTART", "WORKVOLUMEEND", "WORKVOLUMESTART",
  "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND", "YSTART", "ZAXISEND",
  "ZAXISSTART", "ZEND", "ZSTART", "BOXVOLUMETYPEDECL",
  "BOXYOBJECTTYPEDECL", "BOXYSHAPETYPEDECL",
  "ENDEFFECTORCHANGINGSTATIONTYPEDECL", "ENDEFFECTORHOLDERTYPEDECL",
  "ENDEFFECTORTYPEDECL", "GRIPPEREFFECTORTYPEDECL", "KITDESIGNTYPEDECL",
  "KITTRAYTYPEDECL", "KITTYPEDECL", "KITTINGWORKSTATIONTYPEDECL",
  "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL", "LARGEBOXWITHKITSTYPEDECL",
  "LARGECONTAINERTYPEDECL", "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL",
  "PARTSBINTYPEDECL", "PARTSTRAYTYPEDECL", "PARTSTRAYWITHPARTSTYPEDECL",
  "PHYSICALLOCATIONTYPEDECL", "POINTTYPEDECL", "POSELOCATIONINTYPEDECL",
  "POSELOCATIONONTYPEDECL", "POSELOCATIONTYPEDECL",
  "POSEONLYLOCATIONTYPEDECL", "RELATIVELOCATIONINTYPEDECL",
  "RELATIVELOCATIONONTYPEDECL", "RELATIVELOCATIONTYPEDECL",
  "ROBOTTYPEDECL", "SHAPEDESIGNTYPEDECL", "STOCKKEEPINGUNITTYPEDECL",
  "VACUUMEFFECTORMULTICUPTYPEDECL", "VACUUMEFFECTORSINGLECUPTYPEDECL",
  "VACUUMEFFECTORTYPEDECL", "VECTORTYPEDECL", "WORKTABLETYPEDECL",
  "$accept", "y_KittingWorkStationFile",
  "y_XmlHeaderForKittingWorkStation", "y_SchemaLocation", "y_XmlBoolean",
  "y_XmlDecimal", "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN",
  "y_XmlNonNegativeInteger", "y_XmlPositiveInteger", "y_XmlString",
  "y_XmlVersion", "y_AngleUnit_AngleUnitType", "$@1",
  "y_ArrayNumber_XmlPositiveInteger", "$@2",
  "y_ArrayRadius_PositiveDecimalType", "$@3", "y_BoxVolumeType",
  "y_Capacity_XmlPositiveInteger", "$@4",
  "y_ChangingStation_EndEffectorChangingStationType",
  "y_CupDiameter_PositiveDecimalType", "$@5", "y_Description_XmlString",
  "$@6", "y_DesignName_XmlIDREF", "$@7",
  "y_EndEffectorChangingStationType", "y_EndEffectorHolderType",
  "y_EndEffectorHolders_EndEffectorHolderType_u",
  "y_EndEffectorHolders_EndEffectorHolderType_uList",
  "y_EndEffectorName_XmlIDREF_0_u", "$@8",
  "y_EndEffectorName_XmlIDREF_0_uList", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType_0", "y_Finished_XmlBoolean", "$@9",
  "y_HasTop_XmlBoolean", "$@10", "y_Height_PositiveDecimalType", "$@11",
  "y_I_XmlDecimal", "$@12", "y_J_XmlDecimal", "$@13", "y_K_XmlDecimal",
  "$@14", "y_KitDesignName_XmlIDREF", "$@15", "y_KitDesignType",
  "y_KitDesign_KitDesignType_u", "y_KitDesign_KitDesignType_uList",
  "y_KitTraySkuName_XmlIDREF", "$@16", "y_KitTrayType",
  "y_KitTrays_KitTrayType_0_u", "y_KitTrays_KitTrayType_0_uList",
  "y_KitType", "y_Kit_KitType_0_u", "y_Kit_KitType_0_uList",
  "y_KittingWorkstationType", "y_LargeContainerType",
  "y_LargeContainer_LargeContainerType", "y_LengthUnit_LengthUnitType",
  "$@17", "y_Length_PositiveDecimalType", "$@18",
  "y_MaximumLoadWeight_PositiveDecimalType", "$@19",
  "y_MaximumPoint_PointType", "y_MinimumPoint_PointType", "y_Name_XmlID",
  "$@20", "y_Object_SolidObjectType_u", "y_Object_SolidObjectType_uList",
  "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList",
  "y_PartQuantity_XmlNonNegativeInteger", "$@21", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuName_XmlIDREF",
  "$@22", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PartsTrayType", "y_PartsTray_PartsTrayType", "y_PhysicalLocationType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObject_XmlIDREF", "$@23",
  "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@24", "y_ShapeDesignTypeAny",
  "y_Shape_ShapeDesignType", "y_SkuName_XmlIDREF", "$@25",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SolidObjectType", "y_SolidObjectTypeAny",
  "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Tray_KitTrayType", "y_VectorType", "y_WeightUnit_WeightUnitType",
  "$@26", "y_Weight_PositiveDecimalType", "$@27",
  "y_Width_PositiveDecimalType", "$@28", "y_WorkTableType",
  "y_WorkTable_WorkTableType", "y_WorkVolume_BoxVolumeType_u",
  "y_WorkVolume_BoxVolumeType_uList", "y_XAxis_VectorType",
  "y_X_XmlDecimal", "$@29", "y_Y_XmlDecimal", "$@30", "y_ZAxis_VectorType",
  "y_Z_XmlDecimal", "$@31", "y_x_BoxyObjectType", "y_x_BoxyShapeType",
  "y_x_EndEffectorChangingStationType", "y_x_EndEffectorHolderType",
  "y_x_EndEffectorType", "y_x_GripperEffectorType", "y_x_KitTrayType",
  "y_x_KitType", "y_x_KittingWorkstationType",
  "y_x_LargeBoxWithEmptyKitTraysType", "y_x_LargeBoxWithKitsType",
  "y_x_LargeContainerType", "y_x_PartType", "y_x_PartsBinType",
  "y_x_PartsTrayType", "y_x_PartsTrayWithPartsType",
  "y_x_PoseLocationInType", "y_x_PoseLocationOnType",
  "y_x_PoseLocationType", "y_x_PoseOnlyLocationType",
  "y_x_RelativeLocationInType", "y_x_RelativeLocationOnType",
  "y_x_RelativeLocationType", "y_x_RobotType",
  "y_x_VacuumEffectorMultiCupType", "y_x_VacuumEffectorSingleCupType",
  "y_x_VacuumEffectorType", "y_x_WorkTableType", 0
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
     415,   416,   417,   418,   419,   420
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   178,   180,   179,   182,   181,   184,
     183,   185,   187,   186,   188,   190,   189,   192,   191,   194,
     193,   195,   196,   197,   198,   198,   200,   199,   201,   201,
     202,   202,   202,   202,   203,   203,   205,   204,   207,   206,
     209,   208,   211,   210,   213,   212,   215,   214,   217,   216,
     218,   219,   220,   220,   222,   221,   223,   224,   225,   225,
     226,   227,   228,   228,   229,   230,   231,   233,   232,   235,
     234,   237,   236,   238,   239,   241,   240,   242,   242,   243,
     243,   244,   245,   245,   247,   246,   248,   249,   250,   250,
     252,   251,   253,   254,   255,   255,   256,   257,   258,   259,
     259,   259,   259,   259,   259,   259,   260,   261,   262,   264,
     263,   265,   266,   267,   267,   268,   268,   270,   269,   271,
     272,   274,   273,   275,   276,   276,   277,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   279,   279,   280,
     280,   281,   282,   283,   285,   284,   287,   286,   289,   288,
     290,   291,   292,   293,   293,   294,   296,   295,   298,   297,
     299,   301,   300,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     0,     5,     0,     5,     0,
       5,     4,     0,     5,     3,     0,     5,     0,     5,     0,
       5,     5,     5,     3,     1,     2,     0,     5,     0,     2,
       1,     1,     1,     1,     0,     3,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       4,     3,     1,     2,     0,     5,     6,     3,     0,     2,
       8,     3,     0,     2,    14,     6,     3,     0,     5,     0,
       5,     0,     5,     3,     3,     0,     5,     3,     3,     1,
       2,     3,     0,     2,     0,     5,     6,     3,     1,     2,
       0,     5,     6,     3,     0,     2,     6,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     0,
       5,     8,     3,     3,     3,     0,     2,     0,     5,     1,
       3,     0,     5,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     0,
       2,     6,     3,     5,     0,     5,     0,     5,     0,     5,
       8,     3,     3,     1,     2,     3,     0,     5,     0,     5,
       3,     0,     5,     8,     8,     6,     6,     8,     8,     7,
       9,    15,     7,     9,     7,     7,     9,     7,     7,     7,
       7,     7,     7,     5,     5,     5,     9,    12,    10,    10,
       9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    14,     4,    85,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,     0,     0,   126,    86,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,     0,     0,     0,    62,     0,   119,     0,
       0,     0,     0,     0,     0,   203,   204,   205,     0,   108,
       0,    24,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    16,   125,     0,    61,
      77,     0,    89,    92,     8,     0,     0,   117,     0,     0,
       0,   199,   200,   201,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    90,     0,   120,     0,     0,     0,   175,
       0,    12,     0,     0,    34,    31,    64,     0,    98,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,     0,     0,    93,     0,   176,     0,
       0,     0,     0,   180,    28,     0,     0,    35,     0,     0,
       0,    99,    78,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,   178,     0,   116,    52,     0,     0,     0,    33,
       0,     0,    97,   136,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,     0,    91,     0,   122,     0,     0,
       0,   135,     0,     6,     0,     0,   181,     0,    54,     0,
     163,   125,    65,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,   133,
     164,     0,    74,   177,     0,     0,     0,     0,    56,    44,
     131,     0,     0,     0,   185,     0,   186,     0,     0,     0,
       0,     0,     0,     0,    68,    72,     0,     0,     0,     0,
       0,   104,    44,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,   179,     0,    53,     0,     0,
      32,     0,     0,    79,     0,     0,     0,    40,    41,    42,
      43,     0,     0,     0,     0,   189,    29,     0,   104,     0,
       0,     0,   192,     0,   194,   195,     0,   197,     0,     0,
     198,     0,     0,     0,     0,     0,    83,     0,    44,     0,
       0,     0,     0,   171,   182,    55,     0,     0,    96,     0,
     168,     0,   183,    45,   166,     0,   187,   188,   127,     0,
       0,     0,     0,     0,     0,    76,     0,    69,     0,     0,
       0,    73,     0,     0,     0,   107,     0,   105,     0,     0,
       0,     0,   159,    84,     0,     0,     0,   129,    38,   165,
     125,    57,   132,     0,     0,    50,     0,    81,     0,     0,
       0,   162,     0,   190,     0,   125,     0,    58,     0,     0,
       0,   193,   100,     0,   196,   125,     0,     0,     0,   173,
     206,     0,     0,     0,     0,   210,     0,     0,   130,   161,
       0,    80,     0,     0,     0,     0,     9,     0,    30,   125,
      46,    92,     0,    67,     0,     0,    71,    22,     0,    94,
       0,     0,   103,     0,   174,    25,     0,   208,   209,     0,
     160,   121,     0,     0,    39,     0,   169,     0,   167,     0,
     128,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,   125,   172,     0,     0,     0,     0,     0,     0,    36,
       0,    51,    82,     0,     5,     0,     0,    75,    59,     0,
      11,     0,   101,    10,     0,   106,     0,     0,    17,     0,
     207,   157,   158,     0,     0,   159,    66,    47,     0,     0,
      23,    95,     0,    26,     0,    19,     0,     0,   170,     0,
     104,   102,     0,     0,     0,    37,   191,     0,    18,     0,
       0,   184,    70,    20,    48,     0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   595,   314,    44,   125,   537,   604,
     601,   192,     3,    55,    79,   585,   624,   610,   633,   265,
     511,   577,    70,   522,   583,    95,   135,   371,   459,    84,
     236,   194,   195,   564,   614,   529,   406,   366,   503,   572,
     641,   645,   452,   533,   232,   317,   277,   357,   320,   399,
     470,   544,   103,    86,    87,   138,   238,   461,   467,   422,
     509,   471,   423,    14,   421,   374,   106,   139,   363,   449,
     456,   535,   346,   389,    19,    26,   122,   123,   226,   184,
     514,   579,   240,   198,   199,   473,   548,   517,   477,   430,
     429,   381,    67,    34,   109,    90,    25,    72,   107,   267,
     227,    56,    42,   415,   498,   486,   440,   324,   401,   269,
     270,   161,   162,   560,   525,   309,   418,   129,   312,   392,
     412,   496,   405,   494,   394,   352,   519,   520,   111,   187,
     271,   230,   315,   131,   274,   355,   163,   487,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    35,    36,    37,    38,    39,    40,    41,   178,
     179,   180,   181,   182
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -472
static const yytype_int16 yypact[] =
{
      62,    61,    75,    23,    76,  -472,    88,   105,    92,   101,
     103,  -472,   110,    38,    64,   112,   113,  -472,   114,    33,
    -472,  -472,  -472,  -472,   -22,  -472,   121,   120,   130,   131,
     132,   133,   134,   135,    37,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,    11,  -472,    70,    38,    38,    38,    38,    38,
      38,    38,  -472,   137,   185,   122,  -472,  -472,    51,    51,
      51,    51,    51,    51,    51,  -472,    38,    50,    52,   141,
      98,   144,    63,    63,    63,    63,   124,   124,   124,   149,
      51,  -472,  -472,    38,   138,   148,  -472,    17,  -472,   150,
      36,    36,    36,    36,   153,  -472,  -472,  -472,   168,  -472,
      33,  -472,    38,   139,   177,  -472,    80,   181,    38,    99,
     182,    65,    65,    65,    65,  -472,  -472,  -472,   140,  -472,
    -472,   220,  -472,    80,  -472,   104,    72,  -472,    38,    77,
     182,  -472,  -472,  -472,  -472,   215,     7,   216,   143,   217,
      38,   221,   224,   225,   226,   231,   236,   237,   238,   239,
     240,   241,   244,   247,   248,   250,   251,   252,   253,   254,
     255,   219,   222,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,  -472,   -17,  -472,   288,   170,   257,  -472,
     172,  -472,   275,   296,  -472,   274,  -472,   301,  -472,   143,
     246,    33,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,  -472,  -472,   303,   304,  -472,   206,  -472,   306,
     186,   308,   271,  -472,  -472,    38,   287,  -472,   181,    38,
     242,  -472,  -472,  -472,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    38,   243,    38,   227,   312,  -472,
     -39,   316,  -472,   317,  -472,  -472,   319,   279,    33,  -472,
     277,   228,  -472,   230,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,  -472,   261,  -472,    33,  -472,    38,   229,
     326,  -472,   218,  -472,   223,   316,  -472,   316,  -472,   337,
    -472,  -472,  -472,   338,    63,    -8,     7,     8,     4,     4,
     -27,    12,    11,    -5,    -5,   -27,   -27,   -27,   -27,   -28,
       4,     4,     4,     4,    -8,   150,   276,  -472,   124,  -472,
    -472,   340,  -472,  -472,   233,   316,   307,   316,  -472,     8,
    -472,    36,   342,   249,   274,   -78,  -472,   256,   256,   272,
     364,   263,   122,   367,  -472,  -472,   272,   272,   272,   272,
     368,  -472,   341,   256,   256,   256,   249,   309,   150,  -472,
       4,   283,   371,    38,   264,  -472,   258,  -472,   345,   316,
    -472,   181,    65,  -472,   384,   350,   358,  -472,  -472,  -472,
    -472,   387,   328,   328,   390,  -472,  -472,   391,  -472,    98,
      38,   339,   343,    24,  -472,  -472,   318,  -472,    38,   314,
     321,   328,   328,   328,   328,   350,  -472,   332,   341,   278,
     256,   293,    33,  -472,  -472,  -472,   361,   302,  -472,   404,
    -472,   403,  -472,  -472,  -472,   405,  -472,  -472,  -472,   181,
      38,   305,     3,    17,    33,  -472,   391,  -472,   406,   408,
     394,  -472,   410,   344,    33,  -472,   411,  -472,   299,   397,
     397,   397,  -472,  -472,   328,   418,   325,  -472,  -472,  -472,
    -472,  -472,  -472,   362,   423,  -472,   424,  -472,   425,   407,
      33,  -472,   426,  -472,    80,  -472,   377,  -472,    38,   378,
     427,  -472,  -472,   430,  -472,  -472,    38,   353,   303,  -472,
     299,   432,   374,   374,   374,   333,   299,    38,  -472,   409,
      -8,  -472,   327,   439,   334,   440,  -472,   347,  -472,  -472,
    -472,    80,   -27,  -472,   181,    33,  -472,  -472,   181,  -472,
     -27,    33,  -472,   329,  -472,  -472,   431,  -472,  -472,   220,
    -472,   299,   124,   443,  -472,   249,  -472,   412,  -472,   385,
    -472,   -27,   446,   -17,   272,   413,  -472,   449,   373,   452,
     272,  -472,  -472,   453,   454,   444,   352,   356,   374,  -472,
     350,  -472,  -472,   272,  -472,   428,   206,  -472,  -472,    12,
    -472,   445,  -472,  -472,   381,  -472,   -27,   442,  -472,   462,
    -472,  -472,  -472,   249,   181,  -472,  -472,  -472,   -39,   263,
    -472,  -472,   272,  -472,   449,  -472,   350,   437,   333,   218,
    -472,  -472,   455,   468,   434,  -472,  -472,     3,  -472,   456,
     470,  -472,  -472,  -472,  -472,   446,   441,  -472
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -472,  -472,  -472,  -472,  -168,  -278,  -472,  -220,  -472,  -472,
    -146,  -472,  -472,   151,  -472,  -472,  -472,  -472,  -472,   -38,
    -472,  -472,   109,  -364,  -472,   -77,  -472,  -117,  -472,  -472,
    -472,  -178,   158,  -472,  -472,  -472,  -472,  -332,  -150,  -472,
    -472,  -472,  -406,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,   -75,    69,  -472,  -472,    27,  -472,  -472,
    -472,  -472,  -472,  -472,  -472,   155,    31,  -472,  -289,  -472,
    -369,  -472,  -472,  -472,   -41,  -472,  -120,   -14,  -472,   -46,
    -472,  -472,  -472,   298,  -472,  -472,  -472,  -472,  -472,  -402,
    -472,  -472,  -472,   447,  -297,   -54,    28,    34,  -472,  -472,
     -74,  -472,   -85,  -325,  -472,  -472,  -472,  -302,  -472,  -268,
     -98,   -59,   -56,  -472,  -111,  -472,  -114,   376,  -110,  -472,
    -338,  -472,  -375,  -472,  -472,  -122,  -471,   -16,   -69,  -472,
    -472,  -472,  -472,   -99,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,   146,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
    -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,  -472,
     147,   152,   154,  -472
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      96,    97,   311,   183,    58,    59,    60,    61,    62,    63,
      64,   435,   105,   132,   133,   134,   462,   237,   280,    91,
      92,    93,   112,   113,   114,    80,    53,   400,   369,   482,
     413,    94,   136,   376,   377,   378,   379,   354,   193,   356,
     502,   370,   100,   365,   457,   432,   433,   434,   387,   554,
     431,   424,   425,   426,   427,   386,   373,   362,   145,   380,
     224,   118,   478,   479,   480,   481,   268,   126,    85,    54,
      54,     1,   310,   468,     4,     5,   323,   396,   225,   398,
     104,   469,     6,   157,   158,   159,     7,   188,   476,    54,
     554,   437,    54,    73,    74,    75,    76,    77,    78,   201,
       8,    54,   488,    12,    54,    54,   484,    13,    54,    54,
      10,    18,    11,    15,    99,   526,   523,   524,    16,    21,
      23,   446,    20,    22,    24,    43,    45,    52,   117,    27,
      28,    29,    30,    31,    32,    33,    46,    47,    48,    49,
      50,    51,    57,    65,    71,    69,    81,    83,    82,    85,
      88,    94,    89,    98,   102,   121,   108,   110,   283,   115,
     101,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   447,   116,   120,   615,   124,   237,   127,   128,   119,
     590,    66,   130,   137,   278,   186,   185,   189,   281,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   191,
     634,   200,   196,   304,   197,   306,   140,   202,   637,   243,
     203,   204,   205,   556,   557,   558,   359,   206,   626,   499,
     574,   565,   207,   208,   209,   210,   211,   212,   580,   597,
     213,   367,   368,   214,   215,   605,   216,   217,   218,   219,
     220,   221,   390,   382,   383,   384,   385,   348,   616,   593,
     361,   391,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   402,   222,   228,   229,   223,   631,   233,   613,
     231,   234,   235,   448,   622,   193,   321,   239,   242,   264,
     266,   268,   272,   438,   275,   273,   276,   279,   308,   305,
     313,   307,   282,   316,   575,   318,   319,    54,   578,   322,
     345,   323,   350,   349,   347,   351,    27,    28,    29,    30,
      31,    32,    33,   358,   360,   353,   393,   388,   403,   397,
     311,   141,   442,   142,   143,   144,   145,   395,   146,   147,
     148,   149,   150,   151,   404,   152,   153,   154,   155,   411,
     416,   414,   417,   420,   428,   441,   365,   436,   156,   464,
     443,   157,   158,   159,   439,   160,   444,   474,   105,   445,
     450,   451,   453,   454,   627,   455,   458,   460,   466,   465,
     475,   472,   483,   489,   492,   530,   476,   491,   493,   495,
     485,   497,   507,   501,   508,   510,   512,   516,   518,   500,
     542,   183,   521,   513,   527,   528,   531,   532,   534,   536,
     550,   543,   540,   547,   546,   538,   549,   552,   555,   362,
     559,   566,   563,   567,   569,   570,   568,   582,   584,   589,
     594,   592,   591,   600,   571,   602,   603,   607,   611,   621,
     608,   598,   612,   609,   617,   620,   623,   545,   625,   635,
     490,   638,   639,   640,   643,   551,   644,   646,   632,   647,
     553,   419,   619,   372,   364,   588,   562,   642,   463,   375,
     541,   599,   505,   506,   504,   573,   606,   241,   618,   596,
     586,    68,   515,   587,   628,   630,   190,   636,   629,     0,
     561,   407,   408,     0,     0,     0,     0,   409,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,     0,     0,     0,     0,     0,   581
};

static const yytype_int16 yycheck[] =
{
      77,    78,   270,   123,    45,    46,    47,    48,    49,    50,
      51,   386,    87,   112,   113,   114,   418,   195,   238,    73,
      74,    75,    91,    92,    93,    66,    15,   359,   330,   435,
     368,    27,   117,   335,   336,   337,   338,   315,    31,   317,
      37,    29,    83,    35,   413,   383,   384,   385,   345,   520,
     382,   376,   377,   378,   379,   344,    61,    65,   136,    87,
      77,   102,   431,   432,   433,   434,   105,   108,    51,    97,
      97,     9,   111,    49,    13,     0,   103,   355,    95,   357,
      63,    57,    59,   161,   162,   163,    10,   128,    85,    97,
     561,   388,    97,    59,    60,    61,    62,    63,    64,   140,
      12,    97,   440,    11,    97,    97,   438,     6,    97,    97,
       5,    73,     7,    10,    80,   484,   480,   481,     8,     7,
       6,   399,    58,    10,    91,     4,     6,    90,   100,   151,
     152,   153,   154,   155,   156,   157,     6,     6,     6,     6,
       6,     6,    72,     6,    93,    23,    96,     6,    96,    51,
       6,    27,    89,     4,     6,    75,     6,   121,   243,     6,
      22,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   401,    14,     6,   590,     4,   364,    88,     6,    50,
     565,     6,   127,    53,   235,   123,    92,   120,   239,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,     4,
     626,     4,     6,   264,    81,   266,     6,     6,   630,   201,
       6,     6,     6,   522,   523,   524,   321,     6,   613,   459,
     542,   530,     6,     6,     6,     6,     6,     6,   550,   574,
       6,   328,   329,     6,     6,   580,     6,     6,     6,     6,
       6,     6,   347,   340,   341,   342,   343,   308,   593,   571,
     324,   348,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   361,    74,     6,   125,    74,   622,   126,   588,
      43,    26,     6,   402,   606,    31,   278,     6,    62,     6,
       6,   105,     6,   390,     6,   129,    45,    30,     6,    76,
       4,    94,    80,     6,   544,     6,    47,    97,   548,    52,
      69,   103,     6,   104,   306,   117,   151,   152,   153,   154,
     155,   156,   157,     6,     6,   122,     6,    71,     6,    42,
     618,   131,   393,   133,   134,   135,   136,   124,   138,   139,
     140,   141,   142,   143,   115,   145,   146,   147,   148,   113,
       6,    99,   109,     6,     6,     4,    35,    68,   158,   420,
     116,   161,   162,   163,   101,   165,   128,   428,   463,    44,
       6,    41,    34,     6,   614,    67,     6,     6,    55,    60,
      86,    83,    70,   110,   102,   490,    85,    46,     4,     6,
     132,     6,     6,   108,     6,    21,     6,     6,   119,   460,
     505,   541,    25,    79,     6,   100,    64,     4,     4,     4,
     515,    54,     6,     6,    56,    28,     6,    84,     6,    65,
     107,   114,    33,     4,     4,    98,   112,   118,    17,     6,
       4,    66,    40,     4,   539,    82,     4,     4,   106,    78,
       6,    48,   106,    19,    36,    20,    24,   508,     6,    32,
     442,    16,     4,    39,    18,   516,     6,   645,   624,    38,
     518,   372,   599,   332,   326,   562,   527,   637,   419,   334,
     504,   576,   464,   466,   463,   541,   581,   199,   596,   573,
     559,    54,   474,   559,   615,   619,   130,   629,   618,    -1,
     526,   365,   365,    -1,    -1,    -1,    -1,   365,    -1,   365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,   551
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   167,   178,    13,     0,    59,    10,    12,   168,
       5,     7,    11,     6,   229,    10,     8,   169,    73,   240,
      58,     7,    10,     6,    91,   262,   241,   151,   152,   153,
     154,   155,   156,   157,   259,   318,   319,   320,   321,   322,
     323,   324,   268,     4,   172,     6,     6,     6,     6,     6,
       6,     6,    90,    15,    97,   179,   267,    72,   240,   240,
     240,   240,   240,   240,   240,     6,     6,   258,   259,    23,
     188,    93,   263,   263,   263,   263,   263,   263,   263,   180,
     240,    96,    96,     6,   195,    51,   219,   220,     6,    89,
     261,   261,   261,   261,    27,   191,   191,   191,     4,   263,
     240,    22,     6,   218,    63,   219,   232,   264,     6,   260,
     121,   294,   294,   294,   294,     6,    14,   262,   240,    50,
       6,    75,   242,   243,     4,   173,   240,    88,     6,   283,
     127,   299,   299,   299,   299,   192,   268,    53,   221,   233,
       6,   131,   133,   134,   135,   136,   138,   139,   140,   141,
     142,   143,   145,   146,   147,   148,   158,   161,   162,   163,
     165,   277,   278,   302,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   325,   326,
     327,   328,   329,   242,   245,    92,   123,   295,   240,   120,
     283,     4,   177,    31,   197,   198,     6,    81,   249,   250,
       4,   240,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,    74,    74,    77,    95,   244,   266,     6,   125,
     297,    43,   210,   126,    26,     6,   196,   197,   222,     6,
     248,   249,    62,   262,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,     6,   185,     6,   265,   105,   275,
     276,   296,     6,   129,   300,     6,    45,   212,   240,    30,
     173,   240,    80,   268,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   240,    76,   240,    94,     6,   281,
     111,   275,   284,     4,   171,   298,     6,   211,     6,    47,
     214,   262,    52,   103,   273,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,    69,   238,   262,   240,   104,
       6,   117,   291,   122,   171,   301,   171,   213,     6,   268,
       6,   261,    65,   234,   198,    35,   203,   191,   191,   273,
      29,   193,   179,    61,   231,   231,   273,   273,   273,   273,
      87,   257,   191,   191,   191,   191,   234,   260,    71,   239,
     268,   191,   285,     6,   290,   124,   171,    42,   171,   215,
     203,   274,   294,     6,   115,   288,   202,   307,   326,   327,
     328,   113,   286,   286,    99,   269,     6,   109,   282,   188,
       6,   230,   225,   228,   269,   269,   269,   269,     6,   256,
     255,   203,   286,   286,   286,   288,    68,   260,   191,   101,
     272,     4,   240,   116,   128,    44,   171,   173,   299,   235,
       6,    41,   208,    34,     6,    67,   236,   236,     6,   194,
       6,   223,   255,   220,   240,    60,    55,   224,    49,    57,
     216,   227,    83,   251,   240,    86,    85,   254,   236,   236,
     236,   236,   208,    70,   203,   132,   271,   303,   286,   110,
     262,    46,   102,     4,   289,     6,   287,     6,   270,   173,
     240,   108,    37,   204,   232,   262,   223,     6,     6,   226,
      21,   186,     6,    79,   246,   262,     6,   253,   119,   292,
     293,    25,   189,   189,   189,   280,   236,     6,   100,   201,
     268,    64,     4,   209,     4,   237,     4,   174,    28,   262,
       6,   243,   268,    54,   217,   240,    56,     6,   252,     6,
     268,   240,    84,   185,   292,     6,   234,   234,   234,   107,
     279,   293,   240,    33,   199,   234,   114,     4,   112,     4,
      98,   268,   205,   245,   273,   173,   262,   187,   173,   247,
     273,   262,   118,   190,    17,   181,   277,   278,   191,     6,
     288,    40,    66,   273,     4,   170,   266,   269,    48,   268,
       4,   176,    82,     4,   175,   269,   268,     4,     6,    19,
     183,   106,   106,   234,   200,   208,   269,    36,   276,   193,
      20,    78,   273,    24,   182,     6,   288,   173,   280,   284,
     282,   269,   176,   184,   208,    32,   291,   255,    16,     4,
      39,   206,   204,    18,     6,   207,   170,    38
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

    {(yyval.KittingWorkStationFileVal) = new KittingWorkStationFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForKittingWorkStationVal), (yyvsp[(4) - (5)].KittingWorkstationTypeVal));
	   KittingWorkStationTree = (yyval.KittingWorkStationFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  ;}
    break;

  case 3:

    {(yyval.XmlHeaderForKittingWorkStationVal) = new XmlHeaderForKittingWorkStation((yyvsp[(3) - (3)].SchemaLocationVal));;}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal));
	    if (strncmp("urn:kitting ", (yyvsp[(2) - (2)].sVal), 12))
	      {
		fprintf(stderr,
	           "wrong targetNamespace in schema location %s\n", (yyvsp[(2) - (2)].sVal));
		exit(1);
	      }
	  ;}
    break;

  case 5:

    {(yyval.XmlBooleanVal) = new XmlBoolean((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlBooleanVal)->bad)
	     yyerror("bad XmlBoolean");
	  ;}
    break;

  case 6:

    {(yyval.XmlDecimalVal) = new XmlDecimal((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDecimalVal)->bad)
	     yyerror("bad XmlDecimal");
	  ;}
    break;

  case 7:

    {(yyval.XmlIDVal) = new XmlID((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDVal)->bad)
	     yyerror("bad XmlID");
	  ;}
    break;

  case 8:

    {(yyval.XmlIDREFVal) = new XmlIDREF((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIDREFVal)->bad)
	     yyerror("bad XmlIDREF");
	  ;}
    break;

  case 9:

    {(yyval.XmlNMTOKENVal) = new XmlNMTOKEN((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNMTOKENVal)->bad)
	     yyerror("bad XmlNMTOKEN");
	  ;}
    break;

  case 10:

    {(yyval.XmlNonNegativeIntegerVal) = new XmlNonNegativeInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlNonNegativeIntegerVal)->bad)
	     yyerror("bad XmlNonNegativeInteger");
	  ;}
    break;

  case 11:

    {(yyval.XmlPositiveIntegerVal) = new XmlPositiveInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlPositiveIntegerVal)->bad)
	     yyerror("bad XmlPositiveInteger");
	  ;}
    break;

  case 12:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  ;}
    break;

  case 13:

    {(yyval.XmlVersionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  ;}
    break;

  case 14:

    {(yyval.XmlVersionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp((yyvsp[(5) - (6)].sVal), "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  ;}
    break;

  case 15:

    {yyReadData = 1;;}
    break;

  case 16:

    {(yyval.AngleUnitTypeVal) = new AngleUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.AngleUnitTypeVal)->bad)
	     yyerror("bad AngleUnit value");
	  ;}
    break;

  case 17:

    {yyReadData = 1;;}
    break;

  case 18:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 19:

    {yyReadData = 1;;}
    break;

  case 20:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad ArrayRadius value");
	  ;}
    break;

  case 21:

    {(yyval.BoxVolumeTypeVal) = new BoxVolumeType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PointTypeVal), (yyvsp[(4) - (4)].PointTypeVal));;}
    break;

  case 22:

    {yyReadData = 1;;}
    break;

  case 23:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 24:

    {(yyval.EndEffectorChangingStationTypeVal) = (yyvsp[(2) - (3)].EndEffectorChangingStationTypeVal);;}
    break;

  case 25:

    {yyReadData = 1;;}
    break;

  case 26:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad CupDiameter value");
	  ;}
    break;

  case 27:

    {yyReadData = 1;;}
    break;

  case 28:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 29:

    {yyReadData = 1;;}
    break;

  case 30:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 31:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].PhysicalLocationTypeVal), (yyvsp[(4) - (5)].PhysicalLocationTypeListVal), (yyvsp[(5) - (5)].EndEffectorHolderTypeListVal));;}
    break;

  case 32:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].PhysicalLocationTypeVal), (yyvsp[(4) - (5)].PhysicalLocationTypeListVal), (yyvsp[(5) - (5)].EndEffectorTypeVal));;}
    break;

  case 33:

    {(yyval.EndEffectorHolderTypeVal) = (yyvsp[(2) - (3)].EndEffectorHolderTypeVal);;}
    break;

  case 34:

    {(yyval.EndEffectorHolderTypeListVal) = new std::list<EndEffectorHolderType *>;
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(1) - (1)].EndEffectorHolderTypeVal));;}
    break;

  case 35:

    {(yyval.EndEffectorHolderTypeListVal) = (yyvsp[(1) - (2)].EndEffectorHolderTypeListVal);
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(2) - (2)].EndEffectorHolderTypeVal));;}
    break;

  case 36:

    {yyReadData = 1;;}
    break;

  case 37:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 38:

    {(yyval.IDREFListVal) = new std::list<XmlIDREF *>;;}
    break;

  case 39:

    {(yyval.IDREFListVal) = (yyvsp[(1) - (2)].IDREFListVal);
	   (yyval.IDREFListVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));;}
    break;

  case 40:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 41:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 42:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 43:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 44:

    {(yyval.EndEffectorTypeVal) = 0;;}
    break;

  case 45:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 46:

    {yyReadData = 1;;}
    break;

  case 47:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 48:

    {yyReadData = 1;;}
    break;

  case 49:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 50:

    {yyReadData = 1;;}
    break;

  case 51:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 52:

    {yyReadData = 1;;}
    break;

  case 53:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 54:

    {yyReadData = 1;;}
    break;

  case 55:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 56:

    {yyReadData = 1;;}
    break;

  case 57:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 58:

    {yyReadData = 1;;}
    break;

  case 59:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 60:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].PartRefAndPoseTypeListVal));;}
    break;

  case 61:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 62:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 63:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 64:

    {yyReadData = 1;;}
    break;

  case 65:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 66:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 67:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 68:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 69:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 70:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlIDREFVal), (yyvsp[(6) - (8)].KitTrayTypeVal), (yyvsp[(7) - (8)].PartTypeListVal), (yyvsp[(8) - (8)].XmlBooleanVal));;}
    break;

  case 71:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 72:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 73:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 74:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (14)].XmlIDVal), (yyvsp[(3) - (14)].PhysicalLocationTypeVal), (yyvsp[(4) - (14)].PhysicalLocationTypeListVal), (yyvsp[(5) - (14)].AngleUnitTypeVal), (yyvsp[(6) - (14)].EndEffectorChangingStationTypeVal), (yyvsp[(7) - (14)].KitDesignTypeListVal), (yyvsp[(8) - (14)].LengthUnitTypeVal), (yyvsp[(9) - (14)].SolidObjectTypeListVal), (yyvsp[(10) - (14)].BoxVolumeTypeListVal), (yyvsp[(11) - (14)].RobotTypeVal), (yyvsp[(12) - (14)].StockKeepingUnitTypeListVal), (yyvsp[(13) - (14)].WeightUnitTypeVal), (yyvsp[(14) - (14)].WorkTableTypeVal));;}
    break;

  case 75:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 76:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 77:

    {yyReadData = 1;;}
    break;

  case 78:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 79:

    {yyReadData = 1;;}
    break;

  case 80:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 81:

    {yyReadData = 1;;}
    break;

  case 82:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 83:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 84:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 85:

    {yyReadData = 1;;}
    break;

  case 86:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 87:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 88:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 89:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 90:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 91:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 92:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 93:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 94:

    {yyReadData = 1;;}
    break;

  case 95:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 96:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 97:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 98:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 99:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 100:

    {yyReadData = 1;;}
    break;

  case 101:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 102:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 103:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 104:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 105:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 106:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 107:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 108:

    {(yyval.PhysicalLocationTypeVal) = new PhysicalLocationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlIDREFVal));;}
    break;

  case 109:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 110:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 111:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationTypeVal);;}
    break;

  case 112:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 113:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 114:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 115:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationTypeVal);;}
    break;

  case 116:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 117:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 118:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 119:

    {yyReadData = 1;;}
    break;

  case 120:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 121:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlStringVal), (yyvsp[(6) - (8)].EndEffectorTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].BoxVolumeTypeListVal));;}
    break;

  case 122:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 123:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 124:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 125:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 126:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 127:

    {yyReadData = 1;;}
    break;

  case 128:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 129:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 130:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 131:

    {yyReadData = 1;;}
    break;

  case 132:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 133:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 134:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 135:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 136:

    {(yyval.SolidObjectTypeVal) = new SolidObjectType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PhysicalLocationTypeVal), (yyvsp[(4) - (4)].PhysicalLocationTypeListVal));;}
    break;

  case 137:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].BoxyObjectTypeVal);;}
    break;

  case 138:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 139:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 140:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorTypeVal);;}
    break;

  case 141:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 142:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 143:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 144:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 145:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 146:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 147:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 148:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 149:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 150:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 151:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 152:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 153:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 154:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 155:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 156:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 157:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 158:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 159:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 160:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 161:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 162:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 163:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 164:

    {yyReadData = 1;;}
    break;

  case 165:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 166:

    {yyReadData = 1;;}
    break;

  case 167:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 168:

    {yyReadData = 1;;}
    break;

  case 169:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 170:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].PositiveDecimalTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].SolidObjectTypeListVal));;}
    break;

  case 171:

    {(yyval.WorkTableTypeVal) = (yyvsp[(2) - (3)].WorkTableTypeVal);;}
    break;

  case 172:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 173:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 174:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 175:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 176:

    {yyReadData = 1;;}
    break;

  case 177:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 178:

    {yyReadData = 1;;}
    break;

  case 179:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 180:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 181:

    {yyReadData = 1;;}
    break;

  case 182:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 183:

    {(yyval.BoxyObjectTypeVal) = new BoxyObjectType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.BoxyObjectTypeVal)->printTypp = true;
	  ;}
    break;

  case 184:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PositiveDecimalTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 185:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 186:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 187:

    {(yyval.EndEffectorTypeVal) = new EndEffectorType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.EndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 188:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 189:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 190:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlIDREFVal), (yyvsp[(7) - (9)].KitTrayTypeVal), (yyvsp[(8) - (9)].PartTypeListVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 191:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].AngleUnitTypeVal), (yyvsp[(7) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(8) - (15)].KitDesignTypeListVal), (yyvsp[(9) - (15)].LengthUnitTypeVal), (yyvsp[(10) - (15)].SolidObjectTypeListVal), (yyvsp[(11) - (15)].BoxVolumeTypeListVal), (yyvsp[(12) - (15)].RobotTypeVal), (yyvsp[(13) - (15)].StockKeepingUnitTypeListVal), (yyvsp[(14) - (15)].WeightUnitTypeVal), (yyvsp[(15) - (15)].WorkTableTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 192:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].LargeContainerTypeVal), (yyvsp[(7) - (7)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 193:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].LargeContainerTypeVal), (yyvsp[(7) - (9)].KitTypeListVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 194:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 195:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 196:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlIDREFVal), (yyvsp[(7) - (9)].XmlNMTOKENVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 197:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 198:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].PartsTrayTypeVal), (yyvsp[(7) - (7)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 199:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 200:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 201:

    {(yyval.PoseLocationTypeVal) = new PoseLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 202:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 203:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 204:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 205:

    {(yyval.RelativeLocationTypeVal) = new RelativeLocationType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 206:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlStringVal), (yyvsp[(7) - (9)].EndEffectorTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].BoxVolumeTypeListVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 207:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].PhysicalLocationTypeListVal), (yyvsp[(6) - (12)].XmlStringVal), (yyvsp[(7) - (12)].PositiveDecimalTypeVal), (yyvsp[(8) - (12)].PositiveDecimalTypeVal), (yyvsp[(9) - (12)].PositiveDecimalTypeVal), (yyvsp[(10) - (12)].PositiveDecimalTypeVal), (yyvsp[(11) - (12)].XmlPositiveIntegerVal), (yyvsp[(12) - (12)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 208:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlStringVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 209:

    {(yyval.VacuumEffectorTypeVal) = new VacuumEffectorType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlStringVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 210:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].SolidObjectTypeListVal));
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

