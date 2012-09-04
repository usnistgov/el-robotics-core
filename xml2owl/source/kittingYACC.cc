/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
     DESIGNREFEND = 283,
     DESIGNREFSTART = 284,
     ENDEFFECTORHOLDERSEND = 285,
     ENDEFFECTORHOLDERSSTART = 286,
     ENDEFFECTORREFEND = 287,
     ENDEFFECTORREFSTART = 288,
     ENDEFFECTOREND = 289,
     ENDEFFECTORSTART = 290,
     FINISHEDEND = 291,
     FINISHEDSTART = 292,
     HEIGHTEND = 293,
     HEIGHTSTART = 294,
     IEND = 295,
     ISTART = 296,
     IDEND = 297,
     IDSTART = 298,
     JEND = 299,
     JSTART = 300,
     KEND = 301,
     KSTART = 302,
     KITDESIGNREFEND = 303,
     KITDESIGNREFSTART = 304,
     KITDESIGNEND = 305,
     KITDESIGNSTART = 306,
     KITTRAYSKUREFEND = 307,
     KITTRAYSKUREFSTART = 308,
     KITEND = 309,
     KITSTART = 310,
     KITTINGWORKSTATIONEND = 311,
     KITTINGWORKSTATIONSTART = 312,
     LARGECONTAINEREND = 313,
     LARGECONTAINERSTART = 314,
     LENGTHUNITEND = 315,
     LENGTHUNITSTART = 316,
     LENGTHEND = 317,
     LENGTHSTART = 318,
     MAXIMUMLOADWEIGHTEND = 319,
     MAXIMUMLOADWEIGHTSTART = 320,
     MAXIMUMPOINTEND = 321,
     MAXIMUMPOINTSTART = 322,
     MINIMUMPOINTEND = 323,
     MINIMUMPOINTSTART = 324,
     NAMEEND = 325,
     NAMESTART = 326,
     OBJECTEND = 327,
     OBJECTSTART = 328,
     OTHEROBSTACLEEND = 329,
     OTHEROBSTACLESTART = 330,
     PARTQUANTITYEND = 331,
     PARTQUANTITYSTART = 332,
     PARTREFANDPOSEEND = 333,
     PARTREFANDPOSESTART = 334,
     PARTSKUREFEND = 335,
     PARTSKUREFSTART = 336,
     PARTEND = 337,
     PARTSTART = 338,
     PARTSTRAYEND = 339,
     PARTSTRAYSTART = 340,
     POINTEND = 341,
     POINTSTART = 342,
     PRIMARYLOCATIONEND = 343,
     PRIMARYLOCATIONSTART = 344,
     REFOBJECTEND = 345,
     REFOBJECTSTART = 346,
     REFEND = 347,
     REFSTART = 348,
     ROBOTEND = 349,
     ROBOTSTART = 350,
     SECONDARYLOCATIONEND = 351,
     SECONDARYLOCATIONSTART = 352,
     SERIALNUMBEREND = 353,
     SERIALNUMBERSTART = 354,
     SHAPEEND = 355,
     SHAPESTART = 356,
     SKUREFEND = 357,
     SKUREFSTART = 358,
     SKUEND = 359,
     SKUSTART = 360,
     SOLIDOBJECTEND = 361,
     SOLIDOBJECTSTART = 362,
     TRAYEND = 363,
     TRAYSTART = 364,
     TRAYSEND = 365,
     TRAYSSTART = 366,
     WEIGHTUNITEND = 367,
     WEIGHTUNITSTART = 368,
     WEIGHTEND = 369,
     WEIGHTSTART = 370,
     WIDTHEND = 371,
     WIDTHSTART = 372,
     WORKTABLEEND = 373,
     WORKTABLESTART = 374,
     WORKVOLUMEEND = 375,
     WORKVOLUMESTART = 376,
     XAXISEND = 377,
     XAXISSTART = 378,
     XEND = 379,
     XSTART = 380,
     YEND = 381,
     YSTART = 382,
     ZAXISEND = 383,
     ZAXISSTART = 384,
     ZEND = 385,
     ZSTART = 386,
     BOXVOLUMETYPEDECL = 387,
     BOXYOBJECTTYPEDECL = 388,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 389,
     ENDEFFECTORHOLDERTYPEDECL = 390,
     ENDEFFECTORTYPEDECL = 391,
     GRIPPEREFFECTORTYPEDECL = 392,
     KITDESIGNTYPEDECL = 393,
     KITTRAYTYPEDECL = 394,
     KITTYPEDECL = 395,
     KITTINGWORKSTATIONTYPEDECL = 396,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 397,
     LARGEBOXWITHKITSTYPEDECL = 398,
     LARGECONTAINERTYPEDECL = 399,
     PARTREFANDPOSETYPEDECL = 400,
     PARTTYPEDECL = 401,
     PARTSBINTYPEDECL = 402,
     PARTSTRAYTYPEDECL = 403,
     PARTSTRAYWITHPARTSTYPEDECL = 404,
     PHYSICALLOCATIONTYPEDECL = 405,
     POINTTYPEDECL = 406,
     POSELOCATIONINTYPEDECL = 407,
     POSELOCATIONONTYPEDECL = 408,
     POSELOCATIONTYPEDECL = 409,
     POSEONLYLOCATIONTYPEDECL = 410,
     RELATIVELOCATIONINTYPEDECL = 411,
     RELATIVELOCATIONONTYPEDECL = 412,
     RELATIVELOCATIONTYPEDECL = 413,
     ROBOTTYPEDECL = 414,
     SHAPEDESIGNTYPEDECL = 415,
     STOCKKEEPINGUNITTYPEDECL = 416,
     VACUUMEFFECTORMULTICUPTYPEDECL = 417,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 418,
     VACUUMEFFECTORTYPEDECL = 419,
     VECTORTYPEDECL = 420,
     WORKTABLETYPEDECL = 421
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
#define YYLAST   573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  166
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  677

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   421

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
     165,   166
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    16,    18,    20,    22,    24,
      26,    28,    30,    32,    37,    44,    45,    51,    52,    58,
      59,    65,    70,    71,    77,    81,    82,    88,    89,    95,
      96,   102,   108,   114,   119,   123,   125,   128,   129,   135,
     136,   139,   141,   143,   145,   147,   151,   155,   156,   162,
     163,   169,   170,   176,   177,   183,   184,   190,   191,   197,
     198,   204,   210,   214,   216,   219,   220,   226,   236,   245,
     249,   250,   253,   268,   278,   282,   283,   289,   290,   296,
     297,   303,   307,   311,   312,   318,   322,   326,   328,   331,
     335,   336,   339,   340,   346,   353,   357,   359,   362,   363,
     369,   376,   380,   381,   384,   394,   398,   402,   404,   406,
     408,   410,   412,   414,   416,   422,   426,   430,   431,   437,
     438,   444,   454,   458,   462,   466,   467,   470,   471,   477,
     481,   485,   486,   492,   496,   498,   501,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   526,   528,   530,
     532,   534,   536,   538,   540,   542,   544,   546,   550,   554,
     555,   558,   566,   570,   574,   575,   578,   584,   585,   591,
     592,   598,   599,   605,   614,   618,   622,   624,   627,   631,
     632,   638,   639,   645,   649,   650,   656,   665,   672,   679,
     689,   699,   710,   720,   736,   744,   754,   765,   773,   784,
     795,   803,   811,   819,   827,   835,   841,   847,   852,   863,
     877,   889,   901
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,   179,    57,   169,   229,    56,    -1,    12,
      11,   170,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     9,    13,    10,     7,    -1,     9,    13,    10,
       5,    10,     7,    -1,    -1,    15,     6,   181,     4,    14,
      -1,    -1,    17,     6,   183,   177,    16,    -1,    -1,    19,
       6,   185,     4,    18,    -1,     6,   240,   238,   239,    -1,
      -1,    21,     6,   188,   177,    20,    -1,    23,   196,    22,
      -1,    -1,    25,     6,   191,     4,    24,    -1,    -1,    27,
       6,   193,   178,    26,    -1,    -1,    29,     6,   195,   174,
      28,    -1,     6,   240,   262,   270,   199,    -1,     6,   240,
     262,   270,   205,    -1,     6,   240,   262,   270,    -1,    31,
     197,    30,    -1,   198,    -1,   199,   198,    -1,    -1,    33,
       6,   201,   174,    32,    -1,    -1,   202,   200,    -1,   310,
      -1,   329,    -1,   330,    -1,   331,    -1,    35,   203,    34,
      -1,    35,   203,    34,    -1,    -1,    37,     6,   207,   171,
      36,    -1,    -1,    39,     6,   209,     4,    38,    -1,    -1,
      41,     6,   211,   172,    40,    -1,    -1,    43,     6,   213,
     173,    42,    -1,    -1,    45,     6,   215,   172,    44,    -1,
      -1,    47,     6,   217,   172,    46,    -1,    -1,    49,     6,
     219,   174,    48,    -1,     6,   240,   223,   250,   212,    -1,
      51,   220,    50,    -1,   221,    -1,   222,   221,    -1,    -1,
      53,     6,   224,   174,    52,    -1,     6,   240,   262,   270,
     234,   292,   208,   275,   271,    -1,     6,   240,   262,   270,
     194,   284,   255,   206,    -1,    55,   226,    54,    -1,    -1,
     228,   227,    -1,     6,   240,   262,   270,   180,   189,   222,
     232,   243,   245,   268,   278,   288,   295,    -1,     6,   240,
     262,   270,   234,   292,   208,   275,   271,    -1,    59,   230,
      58,    -1,    -1,    61,     6,   233,     4,    60,    -1,    -1,
      63,     6,   235,     4,    62,    -1,    -1,    65,     6,   237,
       4,    64,    -1,    67,   260,    66,    -1,    69,   260,    68,
      -1,    -1,    71,     6,   241,   173,    70,    -1,    73,   279,
      72,    -1,    73,   280,    72,    -1,   242,    -1,   243,   242,
      -1,    75,   186,    74,    -1,    -1,   245,   244,    -1,    -1,
      77,     6,   247,   176,    76,    -1,     6,   240,   265,   261,
     298,   303,    -1,    79,   248,    78,    -1,   249,    -1,   250,
     249,    -1,    -1,    81,     6,   252,   174,    80,    -1,     6,
     240,   262,   270,   275,   271,    -1,    83,   253,    82,    -1,
      -1,   255,   254,    -1,     6,   240,   262,   270,   234,   292,
     208,   275,   271,    -1,    85,   256,    84,    -1,     6,   240,
     263,    -1,   321,    -1,   322,    -1,   323,    -1,   324,    -1,
     325,    -1,   326,    -1,   327,    -1,     6,   240,   299,   301,
     304,    -1,    87,   260,    86,    -1,    89,   259,    88,    -1,
      -1,    91,     6,   264,   174,    90,    -1,    -1,    93,     6,
     266,   174,    92,    -1,     6,   240,   262,   270,   192,   204,
     236,   297,   212,    -1,    95,   267,    94,    -1,    97,   258,
      96,    -1,    97,   259,    96,    -1,    -1,   270,   269,    -1,
      -1,    99,     6,   272,   175,    98,    -1,     6,   240,   192,
      -1,   101,   273,   100,    -1,    -1,   103,     6,   276,   174,
     102,    -1,   105,   283,   104,    -1,   277,    -1,   278,   277,
      -1,     6,   240,   262,   270,    -1,   306,    -1,   307,    -1,
     308,    -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,
     313,    -1,   314,    -1,   315,    -1,   316,    -1,   317,    -1,
     318,    -1,   319,    -1,   320,    -1,   328,    -1,   329,    -1,
     330,    -1,   331,    -1,   332,    -1,   107,   279,   106,    -1,
     107,   280,   106,    -1,    -1,   282,   281,    -1,     6,   240,
     192,   274,   290,   202,   212,    -1,   109,   225,   108,    -1,
     111,   225,   110,    -1,    -1,   286,   285,    -1,     6,   240,
     210,   214,   216,    -1,    -1,   113,     6,   289,     4,   112,
      -1,    -1,   115,     6,   291,     4,   114,    -1,    -1,   117,
       6,   293,     4,   116,    -1,     6,   240,   262,   270,   234,
     292,   208,   282,    -1,   119,   294,   118,    -1,   121,   186,
     120,    -1,   296,    -1,   297,   296,    -1,   123,   287,   122,
      -1,    -1,   125,     6,   300,   172,   124,    -1,    -1,   127,
       6,   302,   172,   126,    -1,   129,   287,   128,    -1,    -1,
     131,     6,   305,   172,   130,    -1,   133,     6,   240,   262,
     270,   234,   292,   208,    -1,   134,     6,   240,   262,   270,
     199,    -1,   135,     6,   240,   262,   270,   205,    -1,   136,
       6,   240,   262,   270,   192,   290,   236,   212,    -1,   137,
       6,   240,   262,   270,   192,   290,   236,   212,    -1,   139,
       6,   240,   262,   270,   234,   292,   208,   275,   271,    -1,
     140,     6,   240,   262,   270,   194,   284,   255,   206,    -1,
     141,     6,   240,   262,   270,   180,   189,   222,   232,   243,
     245,   268,   278,   288,   295,    -1,   142,     6,   240,   262,
     270,   231,   286,    -1,   143,     6,   240,   262,   270,   231,
     228,   218,   187,    -1,   144,     6,   240,   262,   270,   234,
     292,   208,   275,   271,    -1,   146,     6,   240,   262,   270,
     275,   271,    -1,   147,     6,   240,   262,   270,   234,   292,
     208,   251,   246,    -1,   148,     6,   240,   262,   270,   234,
     292,   208,   275,   271,    -1,   149,     6,   240,   262,   270,
     257,   255,    -1,   152,     6,   240,   263,   261,   298,   303,
      -1,   153,     6,   240,   263,   261,   298,   303,    -1,   154,
       6,   240,   263,   261,   298,   303,    -1,   155,     6,   240,
     263,   261,   298,   303,    -1,   156,     6,   240,   263,   192,
      -1,   157,     6,   240,   263,   192,    -1,   158,     6,   240,
     263,    -1,   159,     6,   240,   262,   270,   192,   204,   236,
     297,   212,    -1,   162,     6,   240,   262,   270,   192,   290,
     236,   212,   190,   234,   182,   184,    -1,   163,     6,   240,
     262,   270,   192,   290,   236,   212,   190,   234,    -1,   164,
       6,   240,   262,   270,   192,   290,   236,   212,   190,   234,
      -1,   166,     6,   240,   262,   270,   234,   292,   208,   282,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   398,   398,   408,   413,   425,   433,   441,   449,   457,
     465,   473,   481,   489,   494,   505,   505,   513,   513,   519,
     519,   528,   534,   534,   540,   546,   546,   555,   555,   561,
     561,   566,   573,   577,   583,   589,   592,   599,   599,   606,
     607,   621,   623,   625,   627,   632,   637,   642,   642,   647,
     647,   655,   655,   660,   660,   665,   665,   670,   670,   675,
     675,   681,   687,   692,   695,   701,   701,   707,   716,   724,
     730,   731,   737,   750,   759,   764,   764,   773,   773,   781,
     781,   790,   795,   800,   800,   805,   807,   812,   815,   821,
     827,   828,   835,   835,   841,   847,   852,   855,   862,   862,
     868,   875,   881,   882,   888,   897,   902,   907,   909,   911,
     913,   915,   917,   919,   924,   930,   935,   940,   940,   945,
     945,   950,   959,   964,   967,   974,   975,   982,   982,   988,
     993,   998,   998,  1003,  1008,  1011,  1017,  1023,  1025,  1027,
    1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1059,  1061,  1066,  1068,  1074,
    1075,  1082,  1089,  1094,  1100,  1101,  1107,  1113,  1113,  1122,
    1122,  1130,  1130,  1138,  1147,  1152,  1157,  1160,  1166,  1171,
    1171,  1176,  1176,  1181,  1186,  1186,  1191,  1202,  1212,  1222,
    1233,  1244,  1256,  1267,  1283,  1293,  1304,  1316,  1326,  1338,
    1350,  1360,  1368,  1376,  1384,  1393,  1401,  1409,  1417,  1429,
    1443,  1455,  1467
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
  "CUPDIAMETERSTART", "DESCRIPTIONEND", "DESCRIPTIONSTART", "DESIGNREFEND",
  "DESIGNREFSTART", "ENDEFFECTORHOLDERSEND", "ENDEFFECTORHOLDERSSTART",
  "ENDEFFECTORREFEND", "ENDEFFECTORREFSTART", "ENDEFFECTOREND",
  "ENDEFFECTORSTART", "FINISHEDEND", "FINISHEDSTART", "HEIGHTEND",
  "HEIGHTSTART", "IEND", "ISTART", "IDEND", "IDSTART", "JEND", "JSTART",
  "KEND", "KSTART", "KITDESIGNREFEND", "KITDESIGNREFSTART", "KITDESIGNEND",
  "KITDESIGNSTART", "KITTRAYSKUREFEND", "KITTRAYSKUREFSTART", "KITEND",
  "KITSTART", "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART",
  "LARGECONTAINEREND", "LARGECONTAINERSTART", "LENGTHUNITEND",
  "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART", "MAXIMUMLOADWEIGHTEND",
  "MAXIMUMLOADWEIGHTSTART", "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART",
  "MINIMUMPOINTEND", "MINIMUMPOINTSTART", "NAMEEND", "NAMESTART",
  "OBJECTEND", "OBJECTSTART", "OTHEROBSTACLEEND", "OTHEROBSTACLESTART",
  "PARTQUANTITYEND", "PARTQUANTITYSTART", "PARTREFANDPOSEEND",
  "PARTREFANDPOSESTART", "PARTSKUREFEND", "PARTSKUREFSTART", "PARTEND",
  "PARTSTART", "PARTSTRAYEND", "PARTSTRAYSTART", "POINTEND", "POINTSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "REFOBJECTEND",
  "REFOBJECTSTART", "REFEND", "REFSTART", "ROBOTEND", "ROBOTSTART",
  "SECONDARYLOCATIONEND", "SECONDARYLOCATIONSTART", "SERIALNUMBEREND",
  "SERIALNUMBERSTART", "SHAPEEND", "SHAPESTART", "SKUREFEND",
  "SKUREFSTART", "SKUEND", "SKUSTART", "SOLIDOBJECTEND",
  "SOLIDOBJECTSTART", "TRAYEND", "TRAYSTART", "TRAYSEND", "TRAYSSTART",
  "WEIGHTUNITEND", "WEIGHTUNITSTART", "WEIGHTEND", "WEIGHTSTART",
  "WIDTHEND", "WIDTHSTART", "WORKTABLEEND", "WORKTABLESTART",
  "WORKVOLUMEEND", "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND",
  "XSTART", "YEND", "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "BOXVOLUMETYPEDECL", "BOXYOBJECTTYPEDECL",
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
  "$@6", "y_DesignRef_XmlIDREF", "$@7", "y_EndEffectorChangingStationType",
  "y_EndEffectorHolderType",
  "y_EndEffectorHolders_EndEffectorHolderType_u",
  "y_EndEffectorHolders_EndEffectorHolderType_uList",
  "y_EndEffectorRef_XmlIDREF_0_u", "$@8",
  "y_EndEffectorRef_XmlIDREF_0_uList", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType", "y_EndEffector_EndEffectorType_0",
  "y_Finished_XmlBoolean", "$@9", "y_Height_PositiveDecimalType", "$@10",
  "y_I_XmlDecimal", "$@11", "y_Id_XmlID", "$@12", "y_J_XmlDecimal", "$@13",
  "y_K_XmlDecimal", "$@14", "y_KitDesignRef_XmlIDREF", "$@15",
  "y_KitDesignType", "y_KitDesign_KitDesignType_u",
  "y_KitDesign_KitDesignType_uList", "y_KitTraySkuRef_XmlIDREF", "$@16",
  "y_KitTrayType", "y_KitType", "y_Kit_KitType_0_u",
  "y_Kit_KitType_0_uList", "y_KittingWorkstationType",
  "y_LargeContainerType", "y_LargeContainer_LargeContainerType",
  "y_LengthUnit_LengthUnitType", "$@17", "y_Length_PositiveDecimalType",
  "$@18", "y_MaximumLoadWeight_PositiveDecimalType", "$@19",
  "y_MaximumPoint_PointType", "y_MinimumPoint_PointType", "y_Name_XmlID",
  "$@20", "y_Object_SolidObjectType_u", "y_Object_SolidObjectType_uList",
  "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList",
  "y_PartQuantity_XmlNonNegativeInteger", "$@21", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuRef_XmlIDREF",
  "$@22", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PartsTrayType", "y_PartsTray_PartsTrayType", "y_PhysicalLocationType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObject_XmlIDREF", "$@23",
  "y_Ref_XmlIDREF", "$@24", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@25", "y_ShapeDesignType",
  "y_Shape_ShapeDesignType", "y_SkuRef_XmlIDREF", "$@26",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SolidObjectType", "y_SolidObjectTypeAny",
  "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Tray_KitTrayType", "y_Trays_KitTrayType_0_u",
  "y_Trays_KitTrayType_0_uList", "y_VectorType",
  "y_WeightUnit_WeightUnitType", "$@27", "y_Weight_PositiveDecimalType",
  "$@28", "y_Width_PositiveDecimalType", "$@29", "y_WorkTableType",
  "y_WorkTable_WorkTableType", "y_WorkVolume_BoxVolumeType_u",
  "y_WorkVolume_BoxVolumeType_uList", "y_XAxis_VectorType",
  "y_X_XmlDecimal", "$@30", "y_Y_XmlDecimal", "$@31", "y_ZAxis_VectorType",
  "y_Z_XmlDecimal", "$@32", "y_x_BoxyObjectType",
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
     415,   416,   417,   418,   419,   420,   421
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   179,   181,   180,   183,   182,   185,
     184,   186,   188,   187,   189,   191,   190,   193,   192,   195,
     194,   196,   197,   197,   198,   199,   199,   201,   200,   202,
     202,   203,   203,   203,   203,   204,   205,   207,   206,   209,
     208,   211,   210,   213,   212,   215,   214,   217,   216,   219,
     218,   220,   221,   222,   222,   224,   223,   225,   226,   227,
     228,   228,   229,   230,   231,   233,   232,   235,   234,   237,
     236,   238,   239,   241,   240,   242,   242,   243,   243,   244,
     245,   245,   247,   246,   248,   249,   250,   250,   252,   251,
     253,   254,   255,   255,   256,   257,   258,   259,   259,   259,
     259,   259,   259,   259,   260,   261,   262,   264,   263,   266,
     265,   267,   268,   269,   269,   270,   270,   272,   271,   273,
     274,   276,   275,   277,   278,   278,   279,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   281,   281,   282,
     282,   283,   284,   285,   286,   286,   287,   289,   288,   291,
     290,   293,   292,   294,   295,   296,   297,   297,   298,   300,
     299,   302,   301,   303,   305,   304,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     0,     5,     0,     5,     0,
       5,     4,     0,     5,     3,     0,     5,     0,     5,     0,
       5,     5,     5,     4,     3,     1,     2,     0,     5,     0,
       2,     1,     1,     1,     1,     3,     3,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     5,     3,     1,     2,     0,     5,     9,     8,     3,
       0,     2,    14,     9,     3,     0,     5,     0,     5,     0,
       5,     3,     3,     0,     5,     3,     3,     1,     2,     3,
       0,     2,     0,     5,     6,     3,     1,     2,     0,     5,
       6,     3,     0,     2,     9,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     0,     5,     0,
       5,     9,     3,     3,     3,     0,     2,     0,     5,     3,
       3,     0,     5,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     0,
       2,     7,     3,     3,     0,     2,     5,     0,     5,     0,
       5,     0,     5,     8,     3,     3,     1,     2,     3,     0,
       5,     0,     5,     3,     0,     5,     8,     6,     6,     9,
       9,    10,     9,    15,     7,     9,    10,     7,    10,    10,
       7,     7,     7,     7,     7,     5,     5,     4,    10,    13,
      11,    11,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    14,     4,    83,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   126,    84,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,   123,   124,     0,     0,     0,    63,     0,   117,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   106,     0,
      24,     0,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    16,   125,     0,    62,    75,
       0,    87,    90,     8,     0,     0,   115,     0,     0,     0,
     201,   202,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    88,     0,   118,     0,     0,     0,   178,     0,
      12,     0,     0,    35,    31,    65,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,    91,     0,   179,     0,     0,
       0,     0,   183,    28,     0,     0,    36,     0,     0,     0,
       0,    61,    97,    76,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   181,     0,   114,    51,     0,     0,     0,
      34,     0,     0,    95,    53,   136,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,     0,    89,     0,   122,
       0,     0,     0,   135,     0,     6,     0,     0,   184,     0,
      55,     0,   166,   125,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,   133,   167,     0,    72,   180,     0,     0,     0,
       0,    57,    33,   119,     0,     0,     0,     0,   187,     0,
     188,     0,     0,     0,     0,     0,     0,     0,   164,    70,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
     182,     0,    52,     0,     0,    32,     0,     0,    54,    77,
       0,     0,     0,    41,    42,    43,    44,     0,     0,     0,
       0,    29,     0,   102,     0,     0,     0,   194,     0,     0,
     131,     0,   197,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,   174,   185,    56,     0,     0,    94,     0,   171,     0,
     186,    46,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,   165,     0,     0,     0,    71,
       0,     0,   127,     0,     0,     0,   105,     0,   103,     0,
       0,     0,     0,     0,   159,    82,     0,     0,     0,    39,
     168,   125,    58,   120,     0,     0,    49,     0,    79,   189,
     190,     0,     0,     0,   162,     0,   192,     0,   125,     0,
      59,     0,     0,     0,   195,     0,     0,     0,     0,     0,
       0,   125,     0,     0,    45,     0,   176,     0,     0,     0,
       0,   212,     0,     0,   130,     0,     0,    78,     0,     0,
       0,     0,   191,    30,   125,    47,    90,     0,   163,     0,
       0,    69,    22,   196,   132,     9,     0,    98,     0,   198,
     199,     0,     0,   101,     0,   208,   177,     0,     0,     0,
       0,     0,   160,     0,   129,     0,    40,   161,     0,   172,
       0,   170,     0,     0,     0,     0,     0,     0,   125,     0,
     128,     0,    92,     0,   125,   175,    25,     0,   210,   211,
       0,     0,   121,    37,     0,    50,    80,     0,     5,     0,
       0,     0,    60,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,     0,   159,     0,    48,     0,
       0,     0,    23,    99,    10,     0,     0,     0,     0,    17,
       0,   209,     0,   173,     0,     0,     0,   102,    93,     0,
     100,    26,     0,    19,    38,     0,   193,    73,     0,   104,
       0,     0,    67,    68,    18,     0,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   619,   316,    44,   124,   566,   645,
     625,   191,     3,    55,    79,   632,   662,   651,   671,   266,
     524,   599,    70,   578,   630,    95,   134,   375,   467,    84,
     235,   193,   194,   586,   635,   545,   412,   439,   370,   516,
     594,   460,   549,   231,   319,   241,   327,   278,   360,   322,
     404,   478,   559,   102,    86,    87,   137,   237,   469,   522,
     479,   428,    14,   426,   378,   105,   138,   367,   457,   464,
     551,   349,   394,    19,    26,   121,   122,   225,   183,   569,
     627,   239,   197,   198,   529,   601,   533,   488,   437,   436,
     386,    67,    34,   108,    90,    25,    72,   106,   326,   406,
     268,   226,    56,    42,   432,   527,   498,   448,   382,   481,
     270,   271,   160,   161,   582,   541,   311,   423,   475,   427,
     128,   314,   397,   418,   507,   411,   505,   399,   355,   536,
     537,   110,   186,   272,   229,   317,   130,   275,   358,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    35,    36,    37,    38,    39,    40,
      41,   177,   178,   179,   180,   181
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -513
static const yytype_int16 yypact[] =
{
      53,    93,   117,    62,   112,  -513,   119,    71,   113,   129,
     126,  -513,   130,    68,    84,   135,   134,  -513,   139,    58,
    -513,  -513,  -513,  -513,    39,  -513,   144,   143,   145,   147,
     148,   151,   152,   153,    72,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,    -5,  -513,    80,    68,    68,    68,    68,    68,
      68,    68,  -513,   156,    11,   175,  -513,  -513,   108,   108,
     108,   108,   108,   108,   108,  -513,    68,   104,   106,   197,
     154,   198,   141,   141,   141,   141,   179,   179,  -513,   226,
     108,  -513,  -513,    68,   209,   227,  -513,     0,  -513,   229,
     109,   109,   109,   109,   230,  -513,  -513,   223,  -513,    58,
    -513,    68,   188,   233,  -513,   167,   239,    68,   158,   260,
     138,   138,   138,   138,  -513,  -513,  -513,   215,  -513,  -513,
     359,  -513,   167,  -513,   183,   150,  -513,    68,   155,   260,
    -513,  -513,  -513,  -513,   272,    -1,   273,   199,   284,    68,
     285,   286,   287,   288,   289,   290,   296,   299,   300,   304,
     307,   310,   312,   316,   317,   319,   320,   321,   323,   324,
     259,   269,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,    14,  -513,   326,   216,   301,  -513,   217,
    -513,   318,   340,  -513,   322,  -513,   341,  -513,   -10,   291,
      58,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,  -513,  -513,   342,   343,  -513,   245,  -513,   346,   224,
     348,   313,  -513,  -513,    68,   327,  -513,   239,    68,   281,
     354,  -513,  -513,  -513,  -513,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    68,   292,    68,   267,   356,
    -513,   -46,   360,  -513,   357,  -513,  -513,   361,   325,    58,
    -513,   328,   275,  -513,  -513,   277,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,   302,  -513,    58,  -513,
      68,   266,   367,  -513,   256,  -513,   252,   360,  -513,   360,
    -513,   371,  -513,  -513,  -513,   372,   141,   144,   -27,    -1,
       8,     4,     4,   -27,     6,    -5,   -25,   -25,   -27,    29,
     -27,   -27,   -22,     4,     4,     4,     4,   -27,   229,   314,
    -513,   179,  -513,  -513,   373,  -513,  -513,   255,   360,   344,
     360,  -513,     8,  -513,   109,   345,   382,   274,   322,   -51,
    -513,   278,   278,   274,   383,   283,   175,   384,  -513,  -513,
     274,   388,   297,   274,   274,   389,  -513,   362,   278,   278,
     278,   274,   332,   229,  -513,     4,   298,   396,    68,   293,
    -513,   271,  -513,   363,   360,  -513,   239,   138,  -513,  -513,
     397,   365,   374,  -513,  -513,  -513,  -513,   400,   347,   347,
     365,  -513,   403,  -513,   154,    68,   352,   303,    78,   365,
    -513,   407,  -513,   365,   365,    68,   333,   335,   -51,   347,
     347,   347,   347,   365,  -513,   351,   362,   410,   278,   308,
      58,  -513,  -513,  -513,   375,   330,  -513,   419,  -513,   420,
    -513,  -513,  -513,   421,   385,   385,   331,   239,    68,   329,
     -15,     0,    58,  -513,   403,  -513,   423,   424,   404,  -513,
     331,   239,  -513,   350,   331,    58,  -513,   427,  -513,   402,
     334,   385,   385,   385,  -513,  -513,   347,    68,   339,  -513,
    -513,  -513,  -513,  -513,   378,   437,  -513,   439,  -513,  -513,
    -513,   297,   416,    58,  -513,   440,  -513,   167,  -513,   337,
    -513,    68,   391,   442,  -513,   297,   355,   445,   444,   376,
     297,  -513,    68,   370,  -513,   342,  -513,   -34,   429,   429,
     429,   349,   334,   179,  -513,    82,   -27,  -513,   353,   455,
     358,   456,  -513,  -513,  -513,  -513,   167,   -27,  -513,   239,
      58,  -513,  -513,  -513,  -513,  -513,   364,  -513,   457,  -513,
    -513,   -27,    58,  -513,   369,  -513,  -513,   458,   398,   398,
     398,   359,  -513,   -34,  -513,   459,  -513,  -513,   274,  -513,
     428,  -513,   406,   -27,   463,    14,   274,   426,  -513,   464,
    -513,   239,  -513,   274,  -513,  -513,  -513,   454,  -513,  -513,
     377,   379,  -513,  -513,   365,  -513,  -513,   274,  -513,   441,
     245,   365,  -513,     6,  -513,   460,   399,   472,   365,    29,
     474,   478,   468,  -513,  -513,   239,  -513,   365,  -513,   -46,
     331,   283,  -513,  -513,  -513,   414,   331,   297,   467,  -513,
     491,  -513,   477,   349,   331,   256,   297,  -513,  -513,   297,
    -513,  -513,   464,  -513,  -513,   297,  -513,  -513,   -15,  -513,
     494,   507,  -513,  -513,  -513,   495,  -513
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -513,  -513,  -513,  -513,  -513,  -275,   185,  -177,  -513,  -513,
    -147,  -513,  -513,   181,  -513,  -513,  -513,  -513,  -513,   -18,
    -513,  -513,   157,  -494,  -513,   -62,  -513,  -104,  -513,  -513,
    -513,  -178,   191,  -513,  -513,  -513,    86,    81,   164,  -139,
    -513,  -313,  -513,  -513,  -513,  -427,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,   -85,   107,  -513,  -513,    56,  -513,
    -513,  -513,  -513,  -513,   195,    63,  -513,  -259,  -513,  -392,
    -513,  -513,  -513,     7,  -513,  -121,    18,  -513,   -20,  -513,
    -513,  -513,   366,  -513,  -513,  -513,  -513,  -513,  -415,  -513,
    -513,  -513,   483,  -316,   -55,     1,   276,  -513,  -513,  -513,
    -513,   -57,  -513,  -116,  -504,  -513,  -513,  -513,  -343,  -513,
    -268,   -80,   -40,   -39,  -513,   -93,  -513,   -97,  -513,  -513,
     417,   -94,  -513,  -349,  -513,  -289,  -513,  -513,  -108,  -512,
       9,   -79,  -513,  -513,  -513,  -513,  -107,  -513,  -513,  -513,
    -513,  -513,  -513,  -358,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,  -513,
    -513,  -513,  -345,  -341,  -340,  -513
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     135,   182,   104,   313,   131,   132,   133,   552,   470,   240,
      53,   413,   111,   112,   113,    96,   236,    66,    91,    92,
      93,   563,   515,   419,   414,   576,   570,   465,   415,   416,
     192,    94,   392,   240,   377,   374,   366,   509,   510,   440,
     441,   442,   357,   369,   359,   579,   580,   490,   491,   492,
     493,    85,    58,    59,    60,    61,    62,    63,    64,   269,
     281,   103,     1,   385,   538,   539,   540,   312,   487,   196,
      54,   576,    54,    80,   373,    54,    10,   445,    11,   380,
     413,   383,   384,   401,   420,   403,   144,   535,   391,   223,
      99,   429,    54,   414,   433,   434,    54,   415,   416,   499,
     116,    54,   443,    54,   542,    54,     4,   466,   117,   224,
     575,   156,   157,   158,   125,   585,   480,     5,   587,     6,
     483,   484,     7,   511,    12,   240,    54,   476,   285,   454,
     494,     8,   381,   477,   187,    13,    15,   525,    16,    18,
      20,   530,    21,   660,    22,    23,   200,    24,    43,    45,
      57,    46,   667,    47,    48,   669,   612,    49,    50,    51,
      52,   672,    65,    27,    28,    29,    30,    31,    32,    33,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     236,    27,    28,    29,    30,    31,    32,    33,    69,    71,
      81,   244,    82,    83,    88,    85,    94,   362,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    89,   455,
      97,   100,   109,   101,   395,   107,   114,   115,   118,   119,
     120,   279,   668,   123,   126,   282,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   127,   129,   136,   371,
     372,   364,   306,   184,   308,   185,   190,   188,   196,   195,
     323,   387,   388,   389,   390,   407,   647,   588,   199,   396,
     512,   201,   202,   203,   204,   205,   206,   656,   596,   614,
     456,   636,   207,   659,   526,   208,   209,   621,   640,   350,
     210,   665,   603,   211,   628,   646,   212,   351,   213,   607,
     608,   609,   214,   215,   654,   216,   217,   218,   637,   219,
     220,   221,   227,   446,   617,    73,    74,    75,    76,    77,
      78,   222,   230,   228,   233,   232,   234,   238,   265,   267,
     269,   243,   273,   192,   276,   274,    98,   280,   277,   283,
     284,   309,   310,   318,   315,   139,   307,   320,   325,   348,
     352,   313,   321,   353,    54,   354,   356,   361,   363,   398,
     324,   400,   597,   393,   402,   546,   104,   408,   409,   421,
     425,   410,   422,   417,   430,   435,   431,   438,   444,   447,
     449,   452,   557,   458,   459,   450,   462,   453,   461,   468,
     473,   451,   463,   482,   474,   571,   497,   486,   487,   495,
     500,   502,   503,   504,   626,   523,   506,   508,   240,   520,
     521,   528,   472,   532,   381,   182,   534,   514,   593,   544,
     547,   548,   485,   550,   553,   561,   555,   558,   562,   565,
     567,   501,   573,   568,   577,   535,   581,   564,   652,   590,
     592,   366,   600,   602,   606,   613,   615,   618,   624,   589,
     616,   631,   591,   518,   622,   513,   644,   638,   648,   643,
     642,   584,   623,   633,   649,   634,   531,   650,   629,   605,
     658,   661,   140,   141,   142,   143,   144,   663,   145,   146,
     147,   148,   149,   150,   543,   151,   152,   153,   154,   664,
     674,   675,   365,   676,   554,   670,   376,   574,   155,   641,
     368,   156,   157,   158,   489,   159,   405,   496,   560,   673,
     519,   471,   379,   424,   517,   556,   595,    68,   620,   572,
     639,   610,   611,   653,   657,   655,   189,   666,     0,     0,
       0,   583,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,   604
};

static const yytype_int16 yycheck[] =
{
     116,   122,    87,   271,   111,   112,   113,   511,   423,    43,
      15,   369,    91,    92,    93,    77,   194,     6,    73,    74,
      75,   525,    37,   372,   369,   537,   530,   419,   369,   369,
      31,    27,   348,    43,    59,    29,    63,   464,   465,   388,
     389,   390,   317,    35,   319,   539,   540,   439,   440,   441,
     442,    51,    45,    46,    47,    48,    49,    50,    51,   105,
     237,    61,     9,    85,   491,   492,   493,   113,    83,    79,
      97,   583,    97,    66,   333,    97,     5,   393,     7,   338,
     438,   340,   341,   358,   373,   360,   137,   121,   347,    75,
      83,   380,    97,   438,   383,   384,    97,   438,   438,   448,
      99,    97,   391,    97,   496,    97,    13,   420,   101,    95,
     537,   162,   163,   164,   107,    33,   429,     0,   545,    57,
     433,   434,    10,   466,    11,    43,    97,    49,   244,   404,
     443,    12,   103,    55,   127,     6,    10,   480,     8,    71,
      56,   484,     7,   647,    10,     6,   139,    89,     4,     6,
      70,     6,   656,     6,     6,   659,   583,     6,     6,     6,
      88,   665,     6,   152,   153,   154,   155,   156,   157,   158,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     368,   152,   153,   154,   155,   156,   157,   158,    23,    91,
      96,   200,    96,     6,     6,    51,    27,   323,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    87,   406,
       4,    22,   123,     6,   350,     6,     6,    14,    50,     6,
      73,   234,   657,     4,    86,   238,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     6,   129,    53,   331,
     332,   326,   265,    90,   267,   125,     4,   122,    79,     6,
     279,   343,   344,   345,   346,   364,   629,   546,     4,   351,
     467,     6,     6,     6,     6,     6,     6,   640,   557,   588,
     407,   614,     6,   646,   481,     6,     6,   596,   621,   308,
       6,   654,   571,     6,   603,   628,     6,   310,     6,   578,
     579,   580,     6,     6,   637,     6,     6,     6,   617,     6,
       6,    72,     6,   395,   593,    59,    60,    61,    62,    63,
      64,    72,    41,   127,    26,   128,     6,     6,     6,     6,
     105,    60,     6,    31,     6,   131,    80,    30,    45,    78,
       6,    94,     6,     6,     4,     6,    74,     6,    93,    67,
     104,   639,    47,     6,    97,   119,   124,     6,     6,     6,
      52,   126,   559,    69,    40,   501,   471,    42,     6,     6,
       6,   117,   109,   115,     6,     6,    99,    35,    66,   101,
       4,   130,   518,     6,    39,   398,     6,    44,    34,     6,
      58,   118,    65,     6,   111,   531,     6,    84,    83,    68,
     112,    46,    92,     4,   601,    21,     6,     6,    43,     6,
       6,    81,   425,     6,   103,   556,    34,   108,   554,   100,
      62,     4,   435,     4,    28,    54,     6,   110,     6,     4,
       6,   450,    82,    77,    25,   121,   107,   102,   635,     4,
       4,    63,    98,     6,     6,     6,    38,     4,     4,   116,
      64,    17,   114,   472,    48,   468,     4,    36,     4,    80,
      20,   543,   598,   106,     6,   106,   485,    19,   604,   120,
      76,    24,   133,   134,   135,   136,   137,     6,   139,   140,
     141,   142,   143,   144,   497,   146,   147,   148,   149,    32,
      16,     4,   327,    18,   513,   662,   335,   535,   159,   623,
     329,   162,   163,   164,   438,   166,   362,   446,   521,   668,
     474,   424,   337,   376,   471,   517,   556,    54,   595,   532,
     620,   581,   581,   636,   641,   639,   129,   655,    -1,    -1,
      -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   572
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   168,   179,    13,     0,    57,    10,    12,   169,
       5,     7,    11,     6,   229,    10,     8,   170,    71,   240,
      56,     7,    10,     6,    89,   262,   241,   152,   153,   154,
     155,   156,   157,   158,   259,   321,   322,   323,   324,   325,
     326,   327,   270,     4,   173,     6,     6,     6,     6,     6,
       6,     6,    88,    15,    97,   180,   269,    70,   240,   240,
     240,   240,   240,   240,   240,     6,     6,   258,   259,    23,
     189,    91,   263,   263,   263,   263,   263,   263,   263,   181,
     240,    96,    96,     6,   196,    51,   221,   222,     6,    87,
     261,   261,   261,   261,    27,   192,   192,     4,   263,   240,
      22,     6,   220,    61,   221,   232,   264,     6,   260,   123,
     298,   298,   298,   298,     6,    14,   262,   240,    50,     6,
      73,   242,   243,     4,   174,   240,    86,     6,   287,   129,
     303,   303,   303,   303,   193,   270,    53,   223,   233,     6,
     133,   134,   135,   136,   137,   139,   140,   141,   142,   143,
     144,   146,   147,   148,   149,   159,   162,   163,   164,   166,
     279,   280,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   328,   329,   330,
     331,   332,   242,   245,    90,   125,   299,   240,   122,   287,
       4,   178,    31,   198,   199,     6,    79,   249,   250,     4,
     240,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    72,    72,    75,    95,   244,   268,     6,   127,   301,
      41,   210,   128,    26,     6,   197,   198,   224,     6,   248,
      43,   212,   249,    60,   262,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,     6,   186,     6,   267,   105,
     277,   278,   300,     6,   131,   304,     6,    45,   214,   240,
      30,   174,   240,    78,     6,   270,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   240,    74,   240,    94,
       6,   283,   113,   277,   288,     4,   172,   302,     6,   211,
       6,    47,   216,   262,    52,    93,   265,   213,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,    67,   238,
     262,   240,   104,     6,   119,   295,   124,   172,   305,   172,
     215,     6,   270,     6,   261,   173,    63,   234,   199,    35,
     205,   192,   192,   234,    29,   194,   180,    59,   231,   231,
     234,   103,   275,   234,   234,    85,   257,   192,   192,   192,
     192,   234,   260,    69,   239,   270,   192,   289,     6,   294,
     126,   172,    40,   172,   217,   205,   266,   298,    42,     6,
     117,   292,   203,   310,   329,   330,   331,   115,   290,   290,
     292,     6,   109,   284,   189,     6,   230,   286,   228,   292,
       6,    99,   271,   292,   292,     6,   256,   255,    35,   204,
     290,   290,   290,   292,    66,   260,   192,   101,   274,     4,
     240,   118,   130,    44,   172,   174,   303,   235,     6,    39,
     208,    34,     6,    65,   236,   236,   208,   195,     6,   225,
     255,   222,   240,    58,   111,   285,    49,    55,   218,   227,
     208,   276,     6,   208,   208,   240,    84,    83,   254,   203,
     236,   236,   236,   236,   208,    68,   204,     6,   273,   290,
     112,   262,    46,    92,     4,   293,     6,   291,     6,   212,
     212,   275,   174,   240,   108,    37,   206,   232,   262,   225,
       6,     6,   226,    21,   187,   275,   174,   272,    81,   251,
     275,   262,     6,   253,    34,   121,   296,   297,   212,   212,
     212,   282,   236,   240,   100,   202,   270,    62,     4,   209,
       4,   237,   271,    28,   262,     6,   243,   270,   110,   219,
     240,    54,     6,   271,   102,     4,   175,     6,    77,   246,
     271,   270,   240,    82,   186,   212,   296,    25,   190,   190,
     190,   107,   281,   297,   192,    33,   200,   212,   234,   116,
       4,   114,     4,   270,   207,   245,   234,   174,   262,   188,
      98,   252,     6,   234,   262,   120,     6,   234,   234,   234,
     279,   280,   212,     6,   292,    38,    64,   234,     4,   171,
     268,   292,    48,   270,     4,   177,   174,   247,   292,   270,
     191,    17,   182,   106,   106,   201,   208,   292,    36,   278,
     208,   194,    20,    80,     4,   176,   208,   275,     4,     6,
      19,   184,   174,   282,   208,   288,   275,   284,    76,   275,
     271,    24,   183,     6,    32,   275,   295,   271,   255,   271,
     177,   185,   271,   206,    16,     4,    18
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

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PhysicalLocationTypeVal), (yyvsp[(4) - (4)].PhysicalLocationTypeListVal), 0);;}
    break;

  case 34:

    {(yyval.EndEffectorHolderTypeVal) = (yyvsp[(2) - (3)].EndEffectorHolderTypeVal);;}
    break;

  case 35:

    {(yyval.EndEffectorHolderTypeListVal) = new std::list<EndEffectorHolderType *>;
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(1) - (1)].EndEffectorHolderTypeVal));;}
    break;

  case 36:

    {(yyval.EndEffectorHolderTypeListVal) = (yyvsp[(1) - (2)].EndEffectorHolderTypeListVal);
	   (yyval.EndEffectorHolderTypeListVal)->push_back((yyvsp[(2) - (2)].EndEffectorHolderTypeVal));;}
    break;

  case 37:

    {yyReadData = 1;;}
    break;

  case 38:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 39:

    {(yyval.IDREFListVal) = new std::list<XmlIDREF *>;;}
    break;

  case 40:

    {(yyval.IDREFListVal) = (yyvsp[(1) - (2)].IDREFListVal);
	   (yyval.IDREFListVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));;}
    break;

  case 41:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 42:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 43:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 44:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 45:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 46:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 47:

    {yyReadData = 1;;}
    break;

  case 48:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 49:

    {yyReadData = 1;;}
    break;

  case 50:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 51:

    {yyReadData = 1;;}
    break;

  case 52:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 53:

    {yyReadData = 1;;}
    break;

  case 54:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 55:

    {yyReadData = 1;;}
    break;

  case 56:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 57:

    {yyReadData = 1;;}
    break;

  case 58:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 59:

    {yyReadData = 1;;}
    break;

  case 60:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 61:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlIDREFVal), (yyvsp[(4) - (5)].PartRefAndPoseTypeListVal), (yyvsp[(5) - (5)].XmlIDVal));;}
    break;

  case 62:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 63:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 64:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 65:

    {yyReadData = 1;;}
    break;

  case 66:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 67:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 68:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlIDREFVal), (yyvsp[(6) - (8)].KitTrayTypeVal), (yyvsp[(7) - (8)].PartTypeListVal), (yyvsp[(8) - (8)].XmlBooleanVal));;}
    break;

  case 69:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 70:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 71:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 72:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (14)].XmlIDVal), (yyvsp[(3) - (14)].PhysicalLocationTypeVal), (yyvsp[(4) - (14)].PhysicalLocationTypeListVal), (yyvsp[(5) - (14)].AngleUnitTypeVal), (yyvsp[(6) - (14)].EndEffectorChangingStationTypeVal), (yyvsp[(7) - (14)].KitDesignTypeListVal), (yyvsp[(8) - (14)].LengthUnitTypeVal), (yyvsp[(9) - (14)].SolidObjectTypeListVal), (yyvsp[(10) - (14)].BoxVolumeTypeListVal), (yyvsp[(11) - (14)].RobotTypeVal), (yyvsp[(12) - (14)].StockKeepingUnitTypeListVal), (yyvsp[(13) - (14)].WeightUnitTypeVal), (yyvsp[(14) - (14)].WorkTableTypeVal));;}
    break;

  case 73:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 74:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 75:

    {yyReadData = 1;;}
    break;

  case 76:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 77:

    {yyReadData = 1;;}
    break;

  case 78:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 79:

    {yyReadData = 1;;}
    break;

  case 80:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 81:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 82:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 83:

    {yyReadData = 1;;}
    break;

  case 84:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 85:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 86:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 87:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 88:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 89:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 90:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 91:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 92:

    {yyReadData = 1;;}
    break;

  case 93:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 94:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 95:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 96:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 97:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 98:

    {yyReadData = 1;;}
    break;

  case 99:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 100:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 101:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 102:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 103:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 104:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 105:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 106:

    {(yyval.PhysicalLocationTypeVal) = new PhysicalLocationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlIDREFVal));;}
    break;

  case 107:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 108:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 109:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationTypeVal);;}
    break;

  case 110:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 111:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 112:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 113:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationTypeVal);;}
    break;

  case 114:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 115:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 116:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 117:

    {yyReadData = 1;;}
    break;

  case 118:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 119:

    {yyReadData = 1;;}
    break;

  case 120:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 121:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].XmlStringVal), (yyvsp[(6) - (9)].EndEffectorTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].BoxVolumeTypeListVal), (yyvsp[(9) - (9)].XmlIDVal));;}
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

    {(yyval.ShapeDesignTypeVal) = new ShapeDesignType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));;}
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

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].ShapeDesignTypeVal), (yyvsp[(5) - (7)].PositiveDecimalTypeVal), (yyvsp[(6) - (7)].IDREFListVal), (yyvsp[(7) - (7)].XmlIDVal));;}
    break;

  case 162:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 163:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 164:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 165:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 166:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 167:

    {yyReadData = 1;;}
    break;

  case 168:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 169:

    {yyReadData = 1;;}
    break;

  case 170:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 171:

    {yyReadData = 1;;}
    break;

  case 172:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 173:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].PositiveDecimalTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].SolidObjectTypeListVal));;}
    break;

  case 174:

    {(yyval.WorkTableTypeVal) = (yyvsp[(2) - (3)].WorkTableTypeVal);;}
    break;

  case 175:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 176:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 177:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 178:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 179:

    {yyReadData = 1;;}
    break;

  case 180:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 181:

    {yyReadData = 1;;}
    break;

  case 182:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 183:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 184:

    {yyReadData = 1;;}
    break;

  case 185:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 186:

    {(yyval.BoxyObjectTypeVal) = new BoxyObjectType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.BoxyObjectTypeVal)->printTypp = true;
	  ;}
    break;

  case 187:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 188:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 189:

    {(yyval.EndEffectorTypeVal) = new EndEffectorType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlStringVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlIDVal));
	   (yyval.EndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 190:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlStringVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlIDVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 191:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 192:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlIDREFVal), (yyvsp[(7) - (9)].KitTrayTypeVal), (yyvsp[(8) - (9)].PartTypeListVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 193:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].AngleUnitTypeVal), (yyvsp[(7) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(8) - (15)].KitDesignTypeListVal), (yyvsp[(9) - (15)].LengthUnitTypeVal), (yyvsp[(10) - (15)].SolidObjectTypeListVal), (yyvsp[(11) - (15)].BoxVolumeTypeListVal), (yyvsp[(12) - (15)].RobotTypeVal), (yyvsp[(13) - (15)].StockKeepingUnitTypeListVal), (yyvsp[(14) - (15)].WeightUnitTypeVal), (yyvsp[(15) - (15)].WorkTableTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 194:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].LargeContainerTypeVal), (yyvsp[(7) - (7)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 195:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].LargeContainerTypeVal), (yyvsp[(7) - (9)].KitTypeListVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 196:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 197:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 198:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 199:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 200:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].PartsTrayTypeVal), (yyvsp[(7) - (7)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 201:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 202:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 203:

    {(yyval.PoseLocationTypeVal) = new PoseLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 204:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 205:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 206:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 207:

    {(yyval.RelativeLocationTypeVal) = new RelativeLocationType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlIDREFVal));
	   (yyval.RelativeLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 208:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlStringVal), (yyvsp[(7) - (10)].EndEffectorTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].BoxVolumeTypeListVal), (yyvsp[(10) - (10)].XmlIDVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 209:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].PhysicalLocationTypeListVal), (yyvsp[(6) - (13)].XmlStringVal), (yyvsp[(7) - (13)].PositiveDecimalTypeVal), (yyvsp[(8) - (13)].PositiveDecimalTypeVal), (yyvsp[(9) - (13)].XmlIDVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].PositiveDecimalTypeVal), (yyvsp[(12) - (13)].XmlPositiveIntegerVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 210:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].XmlStringVal), (yyvsp[(7) - (11)].PositiveDecimalTypeVal), (yyvsp[(8) - (11)].PositiveDecimalTypeVal), (yyvsp[(9) - (11)].XmlIDVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 211:

    {(yyval.VacuumEffectorTypeVal) = new VacuumEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].XmlStringVal), (yyvsp[(7) - (11)].PositiveDecimalTypeVal), (yyvsp[(8) - (11)].PositiveDecimalTypeVal), (yyvsp[(9) - (11)].XmlIDVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 212:

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

