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
     HEIGHTEND = 293,
     HEIGHTSTART = 294,
     IEND = 295,
     ISTART = 296,
     JEND = 297,
     JSTART = 298,
     KEND = 299,
     KSTART = 300,
     KITDESIGNNAMEEND = 301,
     KITDESIGNNAMESTART = 302,
     KITDESIGNEND = 303,
     KITDESIGNSTART = 304,
     KITTRAYSKUNAMEEND = 305,
     KITTRAYSKUNAMESTART = 306,
     KITEND = 307,
     KITSTART = 308,
     KITTINGWORKSTATIONEND = 309,
     KITTINGWORKSTATIONSTART = 310,
     LARGECONTAINEREND = 311,
     LARGECONTAINERSTART = 312,
     LENGTHUNITEND = 313,
     LENGTHUNITSTART = 314,
     LENGTHEND = 315,
     LENGTHSTART = 316,
     MAXIMUMLOADWEIGHTEND = 317,
     MAXIMUMLOADWEIGHTSTART = 318,
     MAXIMUMPOINTEND = 319,
     MAXIMUMPOINTSTART = 320,
     MINIMUMPOINTEND = 321,
     MINIMUMPOINTSTART = 322,
     NAMEEND = 323,
     NAMESTART = 324,
     OBJECTEND = 325,
     OBJECTSTART = 326,
     OTHEROBSTACLEEND = 327,
     OTHEROBSTACLESTART = 328,
     PARTQUANTITYEND = 329,
     PARTQUANTITYSTART = 330,
     PARTREFANDPOSEEND = 331,
     PARTREFANDPOSESTART = 332,
     PARTSKUNAMEEND = 333,
     PARTSKUNAMESTART = 334,
     PARTEND = 335,
     PARTSTART = 336,
     PARTSTRAYEND = 337,
     PARTSTRAYSTART = 338,
     POINTEND = 339,
     POINTSTART = 340,
     PRIMARYLOCATIONEND = 341,
     PRIMARYLOCATIONSTART = 342,
     REFOBJECTEND = 343,
     REFOBJECTSTART = 344,
     ROBOTEND = 345,
     ROBOTSTART = 346,
     SECONDARYLOCATIONEND = 347,
     SECONDARYLOCATIONSTART = 348,
     SERIALNUMBEREND = 349,
     SERIALNUMBERSTART = 350,
     SHAPEEND = 351,
     SHAPESTART = 352,
     SKUNAMEEND = 353,
     SKUNAMESTART = 354,
     SKUEND = 355,
     SKUSTART = 356,
     SOLIDOBJECTEND = 357,
     SOLIDOBJECTSTART = 358,
     TRAYEND = 359,
     TRAYSTART = 360,
     TRAYSEND = 361,
     TRAYSSTART = 362,
     WEIGHTUNITEND = 363,
     WEIGHTUNITSTART = 364,
     WEIGHTEND = 365,
     WEIGHTSTART = 366,
     WIDTHEND = 367,
     WIDTHSTART = 368,
     WORKTABLEEND = 369,
     WORKTABLESTART = 370,
     WORKVOLUMEEND = 371,
     WORKVOLUMESTART = 372,
     XAXISEND = 373,
     XAXISSTART = 374,
     XEND = 375,
     XSTART = 376,
     YEND = 377,
     YSTART = 378,
     ZAXISEND = 379,
     ZAXISSTART = 380,
     ZEND = 381,
     ZSTART = 382,
     BOXVOLUMETYPEDECL = 383,
     BOXYOBJECTTYPEDECL = 384,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 385,
     ENDEFFECTORHOLDERTYPEDECL = 386,
     ENDEFFECTORTYPEDECL = 387,
     GRIPPEREFFECTORTYPEDECL = 388,
     KITDESIGNTYPEDECL = 389,
     KITTRAYTYPEDECL = 390,
     KITTYPEDECL = 391,
     KITTINGWORKSTATIONTYPEDECL = 392,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 393,
     LARGEBOXWITHKITSTYPEDECL = 394,
     LARGECONTAINERTYPEDECL = 395,
     PARTREFANDPOSETYPEDECL = 396,
     PARTTYPEDECL = 397,
     PARTSBINTYPEDECL = 398,
     PARTSTRAYTYPEDECL = 399,
     PARTSTRAYWITHPARTSTYPEDECL = 400,
     PHYSICALLOCATIONTYPEDECL = 401,
     POINTTYPEDECL = 402,
     POSELOCATIONINTYPEDECL = 403,
     POSELOCATIONONTYPEDECL = 404,
     POSELOCATIONTYPEDECL = 405,
     POSEONLYLOCATIONTYPEDECL = 406,
     RELATIVELOCATIONINTYPEDECL = 407,
     RELATIVELOCATIONONTYPEDECL = 408,
     RELATIVELOCATIONTYPEDECL = 409,
     ROBOTTYPEDECL = 410,
     SHAPEDESIGNTYPEDECL = 411,
     STOCKKEEPINGUNITTYPEDECL = 412,
     VACUUMEFFECTORMULTICUPTYPEDECL = 413,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 414,
     VACUUMEFFECTORTYPEDECL = 415,
     VECTORTYPEDECL = 416,
     WORKTABLETYPEDECL = 417
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
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  161
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNRULES -- Number of states.  */
#define YYNSTATES  655

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

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
     155,   156,   157,   158,   159,   160,   161,   162
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
     136,   139,   141,   143,   145,   147,   151,   152,   158,   159,
     165,   166,   172,   173,   179,   180,   186,   187,   193,   198,
     202,   204,   207,   208,   214,   224,   233,   237,   238,   241,
     256,   266,   270,   271,   277,   278,   284,   285,   291,   295,
     299,   300,   306,   310,   314,   316,   319,   323,   324,   327,
     328,   334,   341,   345,   347,   350,   351,   357,   364,   368,
     369,   372,   382,   386,   390,   392,   394,   396,   398,   400,
     402,   404,   410,   414,   418,   419,   425,   434,   438,   442,
     446,   447,   450,   451,   457,   461,   465,   466,   472,   476,
     478,   481,   486,   488,   490,   492,   494,   496,   498,   500,
     502,   504,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   526,   530,   534,   535,   538,   545,   549,   553,
     554,   557,   563,   564,   570,   571,   577,   578,   584,   593,
     597,   601,   603,   606,   610,   611,   617,   618,   624,   628,
     629,   635,   644,   651,   658,   667,   676,   687,   697,   713,
     721,   731,   742,   750,   761,   772,   780,   788,   796,   804,
     812,   818,   824,   829,   839,   852,   863,   874
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     164,     0,    -1,   175,    55,   165,   222,    54,    -1,    12,
      11,   166,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     9,    13,    10,     7,    -1,     9,    13,    10,
       5,    10,     7,    -1,    -1,    15,     6,   177,     4,    14,
      -1,    -1,    17,     6,   179,   173,    16,    -1,    -1,    19,
       6,   181,     4,    18,    -1,     6,   233,   231,   232,    -1,
      -1,    21,     6,   184,   173,    20,    -1,    23,   192,    22,
      -1,    -1,    25,     6,   187,     4,    24,    -1,    -1,    27,
       6,   189,   174,    26,    -1,    -1,    29,     6,   191,   170,
      28,    -1,     6,   233,   255,   261,   195,    -1,     6,   233,
     255,   261,   200,    -1,     6,   233,   255,   261,    -1,    31,
     193,    30,    -1,   194,    -1,   195,   194,    -1,    -1,    33,
       6,   197,   170,    32,    -1,    -1,   198,   196,    -1,   301,
      -1,   320,    -1,   321,    -1,   322,    -1,    35,   199,    34,
      -1,    -1,    37,     6,   202,   167,    36,    -1,    -1,    39,
       6,   204,     4,    38,    -1,    -1,    41,     6,   206,   168,
      40,    -1,    -1,    43,     6,   208,   168,    42,    -1,    -1,
      45,     6,   210,   168,    44,    -1,    -1,    47,     6,   212,
     170,    46,    -1,     6,   233,   216,   243,    -1,    49,   213,
      48,    -1,   214,    -1,   215,   214,    -1,    -1,    51,     6,
     217,   170,    50,    -1,     6,   233,   255,   261,   227,   283,
     203,   266,   262,    -1,     6,   233,   255,   261,   190,   275,
     248,   201,    -1,    53,   219,    52,    -1,    -1,   221,   220,
      -1,     6,   233,   255,   261,   176,   185,   215,   225,   236,
     238,   259,   269,   279,   286,    -1,     6,   233,   255,   261,
     227,   283,   203,   266,   262,    -1,    57,   223,    56,    -1,
      -1,    59,     6,   226,     4,    58,    -1,    -1,    61,     6,
     228,     4,    60,    -1,    -1,    63,     6,   230,     4,    62,
      -1,    65,   253,    64,    -1,    67,   253,    66,    -1,    -1,
      69,     6,   234,   169,    68,    -1,    71,   270,    70,    -1,
      71,   271,    70,    -1,   235,    -1,   236,   235,    -1,    73,
     182,    72,    -1,    -1,   238,   237,    -1,    -1,    75,     6,
     240,   172,    74,    -1,     6,   233,   266,   254,   289,   294,
      -1,    77,   241,    76,    -1,   242,    -1,   243,   242,    -1,
      -1,    79,     6,   245,   170,    78,    -1,     6,   233,   255,
     261,   266,   262,    -1,    81,   246,    80,    -1,    -1,   248,
     247,    -1,     6,   233,   255,   261,   227,   283,   203,   266,
     262,    -1,    83,   249,    82,    -1,     6,   233,   256,    -1,
     312,    -1,   313,    -1,   314,    -1,   315,    -1,   316,    -1,
     317,    -1,   318,    -1,     6,   233,   290,   292,   295,    -1,
      85,   253,    84,    -1,    87,   252,    86,    -1,    -1,    89,
       6,   257,   170,    88,    -1,     6,   233,   255,   261,   188,
     200,   229,   288,    -1,    91,   258,    90,    -1,    93,   251,
      92,    -1,    93,   252,    92,    -1,    -1,   261,   260,    -1,
      -1,    95,     6,   263,   171,    94,    -1,     6,   233,   188,
      -1,    97,   264,    96,    -1,    -1,    99,     6,   267,   170,
      98,    -1,   101,   274,   100,    -1,   268,    -1,   269,   268,
      -1,     6,   233,   255,   261,    -1,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   301,    -1,   302,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,
     309,    -1,   310,    -1,   311,    -1,   319,    -1,   320,    -1,
     321,    -1,   322,    -1,   323,    -1,   103,   270,   102,    -1,
     103,   271,   102,    -1,    -1,   273,   272,    -1,     6,   233,
     188,   265,   281,   198,    -1,   105,   218,   104,    -1,   107,
     218,   106,    -1,    -1,   277,   276,    -1,     6,   233,   205,
     207,   209,    -1,    -1,   109,     6,   280,     4,   108,    -1,
      -1,   111,     6,   282,     4,   110,    -1,    -1,   113,     6,
     284,     4,   112,    -1,     6,   233,   255,   261,   227,   283,
     203,   273,    -1,   115,   285,   114,    -1,   117,   182,   116,
      -1,   287,    -1,   288,   287,    -1,   119,   278,   118,    -1,
      -1,   121,     6,   291,   168,   120,    -1,    -1,   123,     6,
     293,   168,   122,    -1,   125,   278,   124,    -1,    -1,   127,
       6,   296,   168,   126,    -1,   129,     6,   233,   255,   261,
     227,   283,   203,    -1,   130,     6,   233,   255,   261,   195,
      -1,   131,     6,   233,   255,   261,   200,    -1,   132,     6,
     233,   255,   261,   188,   281,   229,    -1,   133,     6,   233,
     255,   261,   188,   281,   229,    -1,   135,     6,   233,   255,
     261,   227,   283,   203,   266,   262,    -1,   136,     6,   233,
     255,   261,   190,   275,   248,   201,    -1,   137,     6,   233,
     255,   261,   176,   185,   215,   225,   236,   238,   259,   269,
     279,   286,    -1,   138,     6,   233,   255,   261,   224,   277,
      -1,   139,     6,   233,   255,   261,   224,   221,   211,   183,
      -1,   140,     6,   233,   255,   261,   227,   283,   203,   266,
     262,    -1,   142,     6,   233,   255,   261,   266,   262,    -1,
     143,     6,   233,   255,   261,   227,   283,   203,   244,   239,
      -1,   144,     6,   233,   255,   261,   227,   283,   203,   266,
     262,    -1,   145,     6,   233,   255,   261,   250,   248,    -1,
     148,     6,   233,   256,   254,   289,   294,    -1,   149,     6,
     233,   256,   254,   289,   294,    -1,   150,     6,   233,   256,
     254,   289,   294,    -1,   151,     6,   233,   256,   254,   289,
     294,    -1,   152,     6,   233,   256,   188,    -1,   153,     6,
     233,   256,   188,    -1,   154,     6,   233,   256,    -1,   155,
       6,   233,   255,   261,   188,   200,   229,   288,    -1,   158,
       6,   233,   255,   261,   188,   281,   229,   186,   227,   178,
     180,    -1,   159,     6,   233,   255,   261,   188,   281,   229,
     186,   227,    -1,   160,     6,   233,   255,   261,   188,   281,
     229,   186,   227,    -1,   162,     6,   233,   255,   261,   227,
     283,   203,   273,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   391,   391,   401,   406,   418,   426,   434,   442,   450,
     458,   466,   474,   482,   487,   498,   498,   506,   506,   512,
     512,   521,   527,   527,   533,   539,   539,   548,   548,   554,
     554,   560,   567,   571,   577,   583,   586,   593,   593,   600,
     601,   615,   617,   619,   621,   626,   631,   631,   636,   636,
     644,   644,   649,   649,   654,   654,   659,   659,   665,   671,
     676,   679,   685,   685,   691,   700,   708,   714,   715,   721,
     734,   743,   748,   748,   757,   757,   765,   765,   774,   779,
     784,   784,   789,   791,   796,   799,   805,   811,   812,   819,
     819,   825,   831,   836,   839,   846,   846,   852,   859,   865,
     866,   872,   881,   886,   891,   893,   895,   897,   899,   901,
     903,   908,   914,   919,   924,   924,   929,   938,   943,   946,
     953,   954,   961,   961,   967,   972,   977,   977,   982,   987,
     990,   996,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,
    1018,  1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,
    1038,  1040,  1045,  1047,  1053,  1054,  1061,  1068,  1073,  1079,
    1080,  1086,  1092,  1092,  1101,  1101,  1109,  1109,  1117,  1126,
    1131,  1136,  1139,  1145,  1150,  1150,  1155,  1155,  1160,  1165,
    1165,  1170,  1181,  1191,  1201,  1212,  1223,  1235,  1246,  1262,
    1272,  1283,  1295,  1305,  1317,  1329,  1339,  1347,  1355,  1363,
    1372,  1380,  1388,  1396,  1408,  1422,  1434,  1446
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
  "HEIGHTEND", "HEIGHTSTART", "IEND", "ISTART", "JEND", "JSTART", "KEND",
  "KSTART", "KITDESIGNNAMEEND", "KITDESIGNNAMESTART", "KITDESIGNEND",
  "KITDESIGNSTART", "KITTRAYSKUNAMEEND", "KITTRAYSKUNAMESTART", "KITEND",
  "KITSTART", "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART",
  "LARGECONTAINEREND", "LARGECONTAINERSTART", "LENGTHUNITEND",
  "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART", "MAXIMUMLOADWEIGHTEND",
  "MAXIMUMLOADWEIGHTSTART", "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART",
  "MINIMUMPOINTEND", "MINIMUMPOINTSTART", "NAMEEND", "NAMESTART",
  "OBJECTEND", "OBJECTSTART", "OTHEROBSTACLEEND", "OTHEROBSTACLESTART",
  "PARTQUANTITYEND", "PARTQUANTITYSTART", "PARTREFANDPOSEEND",
  "PARTREFANDPOSESTART", "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND",
  "PARTSTART", "PARTSTRAYEND", "PARTSTRAYSTART", "POINTEND", "POINTSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "REFOBJECTEND",
  "REFOBJECTSTART", "ROBOTEND", "ROBOTSTART", "SECONDARYLOCATIONEND",
  "SECONDARYLOCATIONSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SHAPEEND", "SHAPESTART", "SKUNAMEEND", "SKUNAMESTART", "SKUEND",
  "SKUSTART", "SOLIDOBJECTEND", "SOLIDOBJECTSTART", "TRAYEND", "TRAYSTART",
  "TRAYSEND", "TRAYSSTART", "WEIGHTUNITEND", "WEIGHTUNITSTART",
  "WEIGHTEND", "WEIGHTSTART", "WIDTHEND", "WIDTHSTART", "WORKTABLEEND",
  "WORKTABLESTART", "WORKVOLUMEEND", "WORKVOLUMESTART", "XAXISEND",
  "XAXISSTART", "XEND", "XSTART", "YEND", "YSTART", "ZAXISEND",
  "ZAXISSTART", "ZEND", "ZSTART", "BOXVOLUMETYPEDECL",
  "BOXYOBJECTTYPEDECL", "ENDEFFECTORCHANGINGSTATIONTYPEDECL",
  "ENDEFFECTORHOLDERTYPEDECL", "ENDEFFECTORTYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "KITDESIGNTYPEDECL", "KITTRAYTYPEDECL",
  "KITTYPEDECL", "KITTINGWORKSTATIONTYPEDECL",
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
  "y_Height_PositiveDecimalType", "$@10", "y_I_XmlDecimal", "$@11",
  "y_J_XmlDecimal", "$@12", "y_K_XmlDecimal", "$@13",
  "y_KitDesignName_XmlIDREF", "$@14", "y_KitDesignType",
  "y_KitDesign_KitDesignType_u", "y_KitDesign_KitDesignType_uList",
  "y_KitTraySkuName_XmlIDREF", "$@15", "y_KitTrayType", "y_KitType",
  "y_Kit_KitType_0_u", "y_Kit_KitType_0_uList", "y_KittingWorkstationType",
  "y_LargeContainerType", "y_LargeContainer_LargeContainerType",
  "y_LengthUnit_LengthUnitType", "$@16", "y_Length_PositiveDecimalType",
  "$@17", "y_MaximumLoadWeight_PositiveDecimalType", "$@18",
  "y_MaximumPoint_PointType", "y_MinimumPoint_PointType", "y_Name_XmlID",
  "$@19", "y_Object_SolidObjectType_u", "y_Object_SolidObjectType_uList",
  "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList",
  "y_PartQuantity_XmlNonNegativeInteger", "$@20", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuName_XmlIDREF",
  "$@21", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PartsTrayType", "y_PartsTray_PartsTrayType", "y_PhysicalLocationType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObject_XmlIDREF", "$@22",
  "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@23", "y_ShapeDesignType",
  "y_Shape_ShapeDesignType", "y_SkuName_XmlIDREF", "$@24",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SolidObjectType", "y_SolidObjectTypeAny",
  "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Tray_KitTrayType", "y_Trays_KitTrayType_0_u",
  "y_Trays_KitTrayType_0_uList", "y_VectorType",
  "y_WeightUnit_WeightUnitType", "$@25", "y_Weight_PositiveDecimalType",
  "$@26", "y_Width_PositiveDecimalType", "$@27", "y_WorkTableType",
  "y_WorkTable_WorkTableType", "y_WorkVolume_BoxVolumeType_u",
  "y_WorkVolume_BoxVolumeType_uList", "y_XAxis_VectorType",
  "y_X_XmlDecimal", "$@28", "y_Y_XmlDecimal", "$@29", "y_ZAxis_VectorType",
  "y_Z_XmlDecimal", "$@30", "y_x_BoxyObjectType",
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
     415,   416,   417
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   175,   177,   176,   179,   178,   181,
     180,   182,   184,   183,   185,   187,   186,   189,   188,   191,
     190,   192,   193,   193,   194,   195,   195,   197,   196,   198,
     198,   199,   199,   199,   199,   200,   202,   201,   204,   203,
     206,   205,   208,   207,   210,   209,   212,   211,   213,   214,
     215,   215,   217,   216,   218,   219,   220,   221,   221,   222,
     223,   224,   226,   225,   228,   227,   230,   229,   231,   232,
     234,   233,   235,   235,   236,   236,   237,   238,   238,   240,
     239,   241,   242,   243,   243,   245,   244,   246,   247,   248,
     248,   249,   250,   251,   252,   252,   252,   252,   252,   252,
     252,   253,   254,   255,   257,   256,   258,   259,   260,   260,
     261,   261,   263,   262,   264,   265,   267,   266,   268,   269,
     269,   270,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   272,   272,   273,   273,   274,   275,   276,   277,
     277,   278,   280,   279,   282,   281,   284,   283,   285,   286,
     287,   288,   288,   289,   291,   290,   293,   292,   294,   296,
     295,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     0,     5,     0,     5,     0,
       5,     4,     0,     5,     3,     0,     5,     0,     5,     0,
       5,     5,     5,     4,     3,     1,     2,     0,     5,     0,
       2,     1,     1,     1,     1,     3,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     4,     3,
       1,     2,     0,     5,     9,     8,     3,     0,     2,    14,
       9,     3,     0,     5,     0,     5,     0,     5,     3,     3,
       0,     5,     3,     3,     1,     2,     3,     0,     2,     0,
       5,     6,     3,     1,     2,     0,     5,     6,     3,     0,
       2,     9,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     3,     0,     5,     8,     3,     3,     3,
       0,     2,     0,     5,     3,     3,     0,     5,     3,     1,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     0,     2,     6,     3,     3,     0,
       2,     5,     0,     5,     0,     5,     0,     5,     8,     3,
       3,     1,     2,     3,     0,     5,     0,     5,     3,     0,
       5,     8,     6,     6,     8,     8,    10,     9,    15,     7,
       9,    10,     7,    10,    10,     7,     7,     7,     7,     7,
       5,     5,     4,     9,    12,    10,    10,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    14,     4,    80,     0,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,   121,    81,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   118,   119,     0,     0,     0,    60,     0,   114,     0,
       0,     0,     0,     0,     0,   200,   201,     0,   103,     0,
      24,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    16,   120,     0,    59,    72,
       0,    84,    87,     8,     0,     0,   112,     0,     0,     0,
     196,   197,   198,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    85,     0,   115,     0,     0,     0,   173,     0,
      12,     0,     0,    35,    31,    62,     0,    93,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,     0,     0,    88,     0,   174,     0,     0,
       0,     0,   178,    28,     0,     0,    36,     0,     0,     0,
      94,    73,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,   176,     0,   111,    50,     0,     0,     0,    34,     0,
       0,    92,   131,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,     0,    86,     0,   117,     0,     0,     0,
     130,     0,     6,     0,     0,   179,     0,    52,     0,   161,
     120,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,   128,   162,
       0,    69,   175,     0,     0,     0,     0,    54,    33,   126,
       0,     0,     0,   182,     0,   183,     0,     0,     0,     0,
       0,     0,     0,   159,    67,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   177,     0,    51,     0,     0,    32,
       0,     0,    74,     0,     0,     0,    41,    42,    43,    44,
       0,     0,     0,     0,    29,     0,    99,     0,     0,     0,
     189,     0,     0,     0,   192,     0,     0,     0,     0,   195,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,   169,   180,    53,     0,     0,    91,     0,   166,
       0,   181,    45,   164,     0,   184,   185,     0,     0,     0,
       0,     0,     0,     0,    71,     0,   160,     0,     0,     0,
      68,     0,   122,     0,     0,     0,   102,     0,   100,     0,
       0,     0,     0,   154,    79,     0,     0,     0,    39,   163,
     120,    55,   127,     0,     0,    48,     0,    76,     0,     0,
       0,   157,     0,   187,     0,   120,     0,    56,     0,     0,
       0,   190,     0,     0,     0,     0,     0,   120,     0,     0,
       0,   171,   203,     0,     0,     0,     0,   207,     0,     0,
     125,   156,     0,    75,     0,     0,     0,     0,   186,    30,
     120,    46,    87,     0,   158,     0,     0,    66,    22,   191,
       9,     0,    95,     0,   193,   194,     0,     0,    98,     0,
     172,    25,     0,   205,   206,     0,   155,   116,   124,     0,
      40,     0,   167,     0,   165,     0,     0,     0,     0,     0,
       0,   120,     0,   123,     0,    89,     0,   120,   170,     0,
       0,     0,     0,     0,    37,     0,    49,    77,     0,     5,
       0,     0,     0,    57,     0,    11,     0,     0,     0,     0,
       0,     0,    17,     0,   204,   152,   153,     0,   154,     0,
      47,     0,     0,     0,    23,    96,    10,     0,     0,     0,
      26,     0,    19,     0,   168,     0,     0,     0,    99,    90,
       0,    97,     0,     0,    38,     0,   188,    70,     0,   101,
      18,     0,    64,    65,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   600,   313,    44,   124,   551,   627,
     606,   191,     3,    55,    79,   591,   631,   614,   643,   264,
     511,   582,    70,   524,   589,    95,   134,   370,   458,    84,
     235,   193,   194,   570,   617,   531,   405,   365,   503,   577,
     451,   535,   231,   316,   276,   356,   319,   398,   469,   545,
     102,    86,    87,   137,   237,   460,   509,   470,   421,    14,
     419,   373,   105,   138,   362,   448,   455,   537,   345,   388,
      19,    26,   121,   122,   225,   183,   554,   608,   239,   197,
     198,   515,   584,   519,   478,   429,   428,   380,    67,    34,
     108,    90,    25,    72,   106,   266,   226,    56,    42,   424,
     513,   487,   439,   323,   400,   268,   269,   160,   161,   566,
     527,   308,   416,   466,   420,   128,   311,   391,   411,   496,
     404,   494,   393,   351,   521,   522,   110,   186,   270,   229,
     314,   130,   273,   354,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    35,
      36,    37,    38,    39,    40,    41,   177,   178,   179,   180,
     181
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -490
static const yytype_int16 yypact[] =
{
      41,    39,    70,    17,    67,  -490,    71,    44,    80,    95,
      99,  -490,    97,    42,    59,   103,   111,  -490,   116,    36,
    -490,  -490,  -490,  -490,   -22,  -490,   120,   129,   133,   134,
     135,   136,   137,   138,    62,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,    10,  -490,    77,    42,    42,    42,    42,    42,
      42,    42,  -490,   143,    28,   128,  -490,  -490,    63,    63,
      63,    63,    63,    63,    63,  -490,    42,    91,    92,   148,
     106,   179,   101,   101,   101,   101,   160,   160,  -490,   184,
      63,  -490,  -490,    42,   170,   208,  -490,    12,  -490,   209,
      98,    98,    98,    98,   213,  -490,  -490,   207,  -490,    36,
    -490,    42,   174,   217,  -490,   153,   221,    42,   142,   222,
     102,   102,   102,   102,  -490,  -490,  -490,   178,  -490,  -490,
     364,  -490,   153,  -490,   144,   109,  -490,    42,   145,   222,
    -490,  -490,  -490,  -490,   250,     5,   249,   183,   252,    42,
     255,   258,   260,   263,   269,   270,   271,   279,   281,   283,
     284,   285,   286,   287,   288,   290,   291,   295,   297,   299,
     236,   239,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,  -490,   -26,  -490,   304,   190,   275,  -490,   193,
    -490,   292,   313,  -490,   293,  -490,   316,  -490,   183,   265,
      36,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,  -490,  -490,   319,   320,  -490,   227,  -490,   323,   203,
     327,   294,  -490,  -490,    42,   305,  -490,   221,    42,   262,
    -490,  -490,  -490,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    42,   264,    42,   244,   333,  -490,   -46,
     336,  -490,   335,  -490,  -490,   337,   300,    36,  -490,   296,
     243,  -490,   251,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,  -490,   289,  -490,    36,  -490,    42,   248,   343,
    -490,   235,  -490,   231,   336,  -490,   336,  -490,   346,  -490,
    -490,  -490,   347,   101,   -20,     5,    -5,     2,     2,   -20,
       3,    10,   -17,   -17,   -20,   -18,   -20,   -20,    -9,     2,
       2,     2,     2,   -20,   209,   298,  -490,   160,  -490,  -490,
     349,  -490,  -490,   234,   336,   317,   336,  -490,    -5,  -490,
      98,   352,   246,   293,   -91,  -490,   253,   253,   246,   354,
     261,   128,   357,  -490,  -490,   246,   272,   246,   246,   362,
    -490,   334,   253,   253,   253,   246,   307,   209,  -490,     2,
     277,   368,    42,   266,  -490,   257,  -490,   339,   336,  -490,
     221,   102,  -490,   369,   338,   342,  -490,  -490,  -490,  -490,
     372,   322,   322,   338,  -490,   373,  -490,   106,    42,   330,
     280,     1,   338,   382,  -490,   338,   338,    42,   308,   310,
     322,   322,   322,   322,   338,  -490,   326,   334,   383,   253,
     301,    36,  -490,  -490,  -490,   350,   312,  -490,   389,  -490,
     391,  -490,  -490,  -490,   392,  -490,  -490,   243,   221,    42,
     302,    -2,    12,    36,  -490,   373,  -490,   393,   396,   374,
    -490,   243,  -490,   324,   243,    36,  -490,   399,  -490,   303,
     386,   386,   386,  -490,  -490,   322,    42,   321,  -490,  -490,
    -490,  -490,  -490,   348,   409,  -490,   411,  -490,   272,   390,
      36,  -490,   413,  -490,   153,  -490,   315,  -490,    42,   370,
     417,  -490,   272,   420,   419,   351,   272,  -490,    42,   355,
     319,  -490,   303,   423,   371,   371,   371,   331,   303,   160,
    -490,   397,   -20,  -490,   325,   432,   328,   435,  -490,  -490,
    -490,  -490,   153,   -20,  -490,   221,    36,  -490,  -490,  -490,
    -490,   353,  -490,   434,  -490,  -490,   -20,    36,  -490,   329,
    -490,  -490,   425,  -490,  -490,   364,  -490,   303,  -490,   437,
    -490,   246,  -490,   406,  -490,   384,   -20,   444,   -26,   246,
     403,  -490,   446,  -490,   221,  -490,   246,  -490,  -490,   448,
     449,   438,   356,   359,  -490,   338,  -490,  -490,   246,  -490,
     418,   227,   338,  -490,     3,  -490,   436,   381,   458,   338,
     -18,   440,  -490,   460,  -490,  -490,  -490,   221,  -490,   338,
    -490,   -46,   243,   261,  -490,  -490,  -490,   394,   243,   272,
    -490,   446,  -490,   439,   331,   243,   235,   272,  -490,  -490,
     272,  -490,   451,   465,  -490,   272,  -490,  -490,    -2,  -490,
    -490,   452,  -490,  -490,  -490
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -490,  -490,  -490,  -490,  -490,  -290,  -490,  -184,  -490,  -490,
    -159,  -490,  -490,   146,  -490,  -490,  -490,  -490,  -490,   -44,
    -490,  -490,   104,  -395,  -490,   -69,  -490,  -130,  -490,  -490,
    -490,  -172,   154,  -490,  -490,  -490,  -490,  -335,  -170,  -490,
    -288,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,   -78,    64,  -490,  -490,    15,  -490,  -490,  -490,  -490,
    -490,   149,    21,  -490,  -244,  -490,  -373,  -490,  -490,  -490,
     -45,  -490,  -115,   -19,  -490,   -58,  -490,  -490,  -490,   314,
    -490,  -490,  -490,  -490,  -490,  -385,  -490,  -490,  -490,   433,
    -307,   -55,   -10,    56,  -490,  -490,   -92,  -490,   -89,  -233,
    -490,  -490,  -490,  -324,  -490,  -259,  -113,   -74,   -60,  -490,
    -129,  -490,  -112,  -490,  -490,   385,  -111,  -490,  -339,  -490,
    -271,  -490,  -490,  -123,  -489,   -13,   -76,  -490,  -490,  -490,
    -490,   -99,  -490,  -490,  -490,  -490,  -490,  -490,   152,  -490,
    -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,  -490,
    -490,  -490,  -490,  -490,  -490,  -490,  -490,   156,   157,   161,
    -490
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      58,    59,    60,    61,    62,    63,    64,   182,    96,   104,
     310,   376,   131,   132,   133,   111,   112,   113,    91,    92,
      93,    80,   236,   399,   353,    53,   355,   135,   412,    94,
     364,   461,   369,   560,    66,   502,   192,   386,    99,   456,
     372,   361,   144,   431,   432,   433,   430,   223,   467,    10,
       1,    11,     4,   279,   468,   267,   117,   479,   480,   481,
     482,    85,   125,   309,   395,   224,   397,   156,   157,   158,
       5,   103,     6,    54,   379,    54,    54,     7,   560,   477,
     436,   322,   187,     8,    54,   368,   525,   526,    54,   116,
     375,    12,   377,   378,   200,    54,    54,   413,    54,   385,
     488,    13,   485,    54,   422,    16,   425,   426,   445,    15,
      21,    18,   528,    20,   434,    73,    74,    75,    76,    77,
      78,    22,    23,    24,    43,   457,    27,    28,    29,    30,
      31,    32,    33,   498,   471,    45,    98,   473,   474,    46,
      47,    48,    49,    50,    51,    57,   483,   512,    52,    65,
     516,    69,    71,   282,    83,    85,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    27,    28,    29,    30,
      31,    32,    33,    81,    82,    88,    89,    94,    97,   277,
     242,   236,   100,   280,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   101,   107,   446,   109,   303,   114,
     305,   115,   118,   119,   120,   123,   126,   129,   127,   136,
     185,   358,   184,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   648,   190,   195,   199,   389,   366,   367,
     196,   201,   347,   188,   202,   538,   203,   320,   360,   204,
     381,   382,   383,   384,   499,   205,   206,   207,   390,   549,
     562,   563,   564,   555,   401,   208,   629,   209,   571,   210,
     211,   212,   213,   214,   215,   346,   216,   217,   637,   579,
     595,   218,   447,   219,   640,   220,   221,   618,   602,   222,
     227,   645,   586,   228,   622,   609,   230,   232,   233,   234,
     437,   628,   238,   241,   192,   263,   265,   619,   267,   271,
     272,   635,   598,   274,   306,   278,   304,   275,   281,   307,
     312,   315,   322,   317,    54,   318,   321,   441,   348,   349,
     350,   352,   357,   359,   344,   392,   394,   396,   402,   403,
     414,   580,   310,   418,   410,   387,   415,   423,   427,   364,
     139,   435,   440,   463,   438,   449,   452,   450,   453,   459,
     442,   444,   475,   443,   104,   454,   464,   465,   472,   486,
     476,   477,   484,   493,   491,   510,   641,   495,   497,   507,
     607,   532,   508,   514,   647,   518,   501,   649,   533,   489,
     492,   523,   652,   534,   500,   536,   543,   530,   539,   541,
     520,   544,   547,   548,   550,   552,   553,   182,   556,   561,
     569,   490,   361,   633,   565,   558,   573,   572,   574,   575,
     585,   529,   590,   594,   596,   588,   597,   583,   599,   603,
     605,   576,   611,   505,   620,   612,   624,   613,   615,   625,
     568,   616,   626,   546,   630,   517,   632,   650,   639,   651,
     654,   644,   642,   557,   623,   417,   559,   371,   653,   363,
     506,   462,   374,   504,   578,   542,   601,    68,   621,   634,
     540,   592,   604,   140,   141,   142,   143,   144,   610,   145,
     146,   147,   148,   149,   150,   593,   151,   152,   153,   154,
     636,   638,   240,   646,   189,   567,   406,     0,     0,   155,
     407,   408,   156,   157,   158,   409,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587
};

static const yytype_int16 yycheck[] =
{
      45,    46,    47,    48,    49,    50,    51,   122,    77,    87,
     269,   335,   111,   112,   113,    91,    92,    93,    73,    74,
      75,    66,   194,   358,   314,    15,   316,   116,   367,    27,
      35,   416,    29,   522,     6,    37,    31,   344,    83,   412,
      57,    61,   133,   382,   383,   384,   381,    73,    47,     5,
       9,     7,    13,   237,    53,   101,   101,   430,   431,   432,
     433,    49,   107,   109,   354,    91,   356,   158,   159,   160,
       0,    59,    55,    93,    83,    93,    93,    10,   567,    81,
     387,    99,   127,    12,    93,   329,   481,   482,    93,    99,
     334,    11,   336,   337,   139,    93,    93,   368,    93,   343,
     439,     6,   437,    93,   375,     8,   377,   378,   398,    10,
       7,    69,   485,    54,   385,    59,    60,    61,    62,    63,
      64,    10,     6,    87,     4,   413,   148,   149,   150,   151,
     152,   153,   154,   457,   422,     6,    80,   425,   426,     6,
       6,     6,     6,     6,     6,    68,   434,   471,    86,     6,
     474,    23,    89,   242,     6,    49,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   148,   149,   150,   151,
     152,   153,   154,    92,    92,     6,    85,    27,     4,   234,
     200,   363,    22,   238,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     6,     6,   400,   119,   263,     6,
     265,    14,    48,     6,    71,     4,    84,   125,     6,    51,
     121,   320,    88,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   638,     4,     6,     4,   346,   327,   328,
      77,     6,   307,   118,     6,   498,     6,   277,   323,     6,
     339,   340,   341,   342,   458,     6,     6,     6,   347,   512,
     524,   525,   526,   516,   360,     6,   610,     6,   532,     6,
       6,     6,     6,     6,     6,   305,     6,     6,   622,   543,
     571,     6,   401,     6,   628,     6,    70,   595,   579,    70,
       6,   635,   556,   123,   602,   586,    41,   124,    26,     6,
     389,   609,     6,    58,    31,     6,     6,   598,   101,     6,
     127,   619,   576,     6,    90,    30,    72,    43,    76,     6,
       4,     6,    99,     6,    93,    45,    50,   392,   100,     6,
     115,   120,     6,     6,    65,     6,   122,    40,     6,   113,
       6,   545,   621,     6,   111,    67,   105,    95,     6,    35,
       6,    64,     4,   418,    97,     6,    34,    39,     6,     6,
     114,    42,   427,   126,   462,    63,    56,   107,     6,     6,
      82,    81,    66,     4,    44,    21,   629,     6,     6,     6,
     584,   490,     6,    79,   637,     6,   104,   640,    60,   108,
      98,    25,   645,     4,   459,     4,   505,    96,    28,     6,
     117,   106,    52,     6,     4,     6,    75,   542,   517,     6,
      33,   441,    61,   617,   103,    80,     4,   112,   110,     4,
       6,   486,    17,     6,    38,   116,    62,    94,     4,    46,
       4,   540,     4,   463,    36,     6,    20,    19,   102,    78,
     529,   102,     4,   508,    24,   475,     6,    16,    74,     4,
      18,    32,   631,   518,   604,   371,   520,   331,   648,   325,
     465,   417,   333,   462,   542,   504,   578,    54,   601,   618,
     500,   565,   581,   129,   130,   131,   132,   133,   587,   135,
     136,   137,   138,   139,   140,   565,   142,   143,   144,   145,
     621,   623,   198,   636,   129,   528,   364,    -1,    -1,   155,
     364,   364,   158,   159,   160,   364,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   557
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   164,   175,    13,     0,    55,    10,    12,   165,
       5,     7,    11,     6,   222,    10,     8,   166,    69,   233,
      54,     7,    10,     6,    87,   255,   234,   148,   149,   150,
     151,   152,   153,   154,   252,   312,   313,   314,   315,   316,
     317,   318,   261,     4,   169,     6,     6,     6,     6,     6,
       6,     6,    86,    15,    93,   176,   260,    68,   233,   233,
     233,   233,   233,   233,   233,     6,     6,   251,   252,    23,
     185,    89,   256,   256,   256,   256,   256,   256,   256,   177,
     233,    92,    92,     6,   192,    49,   214,   215,     6,    85,
     254,   254,   254,   254,    27,   188,   188,     4,   256,   233,
      22,     6,   213,    59,   214,   225,   257,     6,   253,   119,
     289,   289,   289,   289,     6,    14,   255,   233,    48,     6,
      71,   235,   236,     4,   170,   233,    84,     6,   278,   125,
     294,   294,   294,   294,   189,   261,    51,   216,   226,     6,
     129,   130,   131,   132,   133,   135,   136,   137,   138,   139,
     140,   142,   143,   144,   145,   155,   158,   159,   160,   162,
     270,   271,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   319,   320,   321,
     322,   323,   235,   238,    88,   121,   290,   233,   118,   278,
       4,   174,    31,   194,   195,     6,    77,   242,   243,     4,
     233,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    70,    70,    73,    91,   237,   259,     6,   123,   292,
      41,   205,   124,    26,     6,   193,   194,   217,     6,   241,
     242,    58,   255,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,     6,   182,     6,   258,   101,   268,   269,
     291,     6,   127,   295,     6,    43,   207,   233,    30,   170,
     233,    76,   261,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   233,    72,   233,    90,     6,   274,   109,
     268,   279,     4,   168,   293,     6,   206,     6,    45,   209,
     255,    50,    99,   266,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,    65,   231,   255,   233,   100,     6,
     115,   286,   120,   168,   296,   168,   208,     6,   261,     6,
     254,    61,   227,   195,    35,   200,   188,   188,   227,    29,
     190,   176,    57,   224,   224,   227,   266,   227,   227,    83,
     250,   188,   188,   188,   188,   227,   253,    67,   232,   261,
     188,   280,     6,   285,   122,   168,    40,   168,   210,   200,
     267,   289,     6,   113,   283,   199,   301,   320,   321,   322,
     111,   281,   281,   283,     6,   105,   275,   185,     6,   223,
     277,   221,   283,    95,   262,   283,   283,     6,   249,   248,
     200,   281,   281,   281,   283,    64,   253,   188,    97,   265,
       4,   233,   114,   126,    42,   168,   170,   294,   228,     6,
      39,   203,    34,     6,    63,   229,   229,   203,   191,     6,
     218,   248,   215,   233,    56,   107,   276,    47,    53,   211,
     220,   203,     6,   203,   203,   233,    82,    81,   247,   229,
     229,   229,   229,   203,    66,   200,     6,   264,   281,   108,
     255,    44,    98,     4,   284,     6,   282,     6,   266,   170,
     233,   104,    37,   201,   225,   255,   218,     6,     6,   219,
      21,   183,   266,   263,    79,   244,   266,   255,     6,   246,
     117,   287,   288,    25,   186,   186,   186,   273,   229,   233,
      96,   198,   261,    60,     4,   204,     4,   230,   262,    28,
     255,     6,   236,   261,   106,   212,   233,    52,     6,   262,
       4,   171,     6,    75,   239,   262,   261,   233,    80,   182,
     287,     6,   227,   227,   227,   103,   272,   288,   188,    33,
     196,   227,   112,     4,   110,     4,   261,   202,   238,   227,
     170,   255,   184,    94,   245,     6,   227,   255,   116,   187,
      17,   178,   270,   271,     6,   283,    38,    62,   227,     4,
     167,   259,   283,    46,   261,     4,   173,   170,   240,   283,
     261,     4,     6,    19,   180,   102,   102,   197,   203,   283,
      36,   269,   203,   190,    20,    78,     4,   172,   203,   266,
      24,   179,     6,   170,   273,   203,   279,   266,   275,    74,
     266,   262,   173,   181,    32,   266,   286,   262,   248,   262,
      16,     4,   262,   201,    18
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

    {yyReadData = 1;;}
    break;

  case 47:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 48:

    {yyReadData = 1;;}
    break;

  case 49:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 50:

    {yyReadData = 1;;}
    break;

  case 51:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
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

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 58:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].PartRefAndPoseTypeListVal));;}
    break;

  case 59:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 60:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 61:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 62:

    {yyReadData = 1;;}
    break;

  case 63:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 64:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 65:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlIDREFVal), (yyvsp[(6) - (8)].KitTrayTypeVal), (yyvsp[(7) - (8)].PartTypeListVal), (yyvsp[(8) - (8)].XmlBooleanVal));;}
    break;

  case 66:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 67:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 68:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 69:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (14)].XmlIDVal), (yyvsp[(3) - (14)].PhysicalLocationTypeVal), (yyvsp[(4) - (14)].PhysicalLocationTypeListVal), (yyvsp[(5) - (14)].AngleUnitTypeVal), (yyvsp[(6) - (14)].EndEffectorChangingStationTypeVal), (yyvsp[(7) - (14)].KitDesignTypeListVal), (yyvsp[(8) - (14)].LengthUnitTypeVal), (yyvsp[(9) - (14)].SolidObjectTypeListVal), (yyvsp[(10) - (14)].BoxVolumeTypeListVal), (yyvsp[(11) - (14)].RobotTypeVal), (yyvsp[(12) - (14)].StockKeepingUnitTypeListVal), (yyvsp[(13) - (14)].WeightUnitTypeVal), (yyvsp[(14) - (14)].WorkTableTypeVal));;}
    break;

  case 70:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 71:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 72:

    {yyReadData = 1;;}
    break;

  case 73:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 74:

    {yyReadData = 1;;}
    break;

  case 75:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 76:

    {yyReadData = 1;;}
    break;

  case 77:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 78:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 79:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 80:

    {yyReadData = 1;;}
    break;

  case 81:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 82:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 83:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 84:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 85:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 86:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 87:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 88:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 89:

    {yyReadData = 1;;}
    break;

  case 90:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 91:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 92:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 93:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 94:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 95:

    {yyReadData = 1;;}
    break;

  case 96:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 97:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 98:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 99:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 100:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 101:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (9)].XmlIDVal), (yyvsp[(3) - (9)].PhysicalLocationTypeVal), (yyvsp[(4) - (9)].PhysicalLocationTypeListVal), (yyvsp[(5) - (9)].PositiveDecimalTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));;}
    break;

  case 102:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 103:

    {(yyval.PhysicalLocationTypeVal) = new PhysicalLocationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlIDREFVal));;}
    break;

  case 104:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 105:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 106:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationTypeVal);;}
    break;

  case 107:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 108:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 109:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 110:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationTypeVal);;}
    break;

  case 111:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 112:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 113:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 114:

    {yyReadData = 1;;}
    break;

  case 115:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 116:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlStringVal), (yyvsp[(6) - (8)].EndEffectorTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].BoxVolumeTypeListVal));;}
    break;

  case 117:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 118:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 119:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 120:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 121:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 122:

    {yyReadData = 1;;}
    break;

  case 123:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 124:

    {(yyval.ShapeDesignTypeVal) = new ShapeDesignType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));;}
    break;

  case 125:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 126:

    {yyReadData = 1;;}
    break;

  case 127:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 128:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 129:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 130:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 131:

    {(yyval.SolidObjectTypeVal) = new SolidObjectType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PhysicalLocationTypeVal), (yyvsp[(4) - (4)].PhysicalLocationTypeListVal));;}
    break;

  case 132:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].BoxyObjectTypeVal);;}
    break;

  case 133:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 134:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 135:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorTypeVal);;}
    break;

  case 136:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 137:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 138:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 139:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 140:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 141:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 142:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 143:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 144:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 145:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 146:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 147:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 148:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 149:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 150:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 151:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 152:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 153:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 154:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 155:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 156:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 157:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 158:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 159:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 160:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 161:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 162:

    {yyReadData = 1;;}
    break;

  case 163:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 164:

    {yyReadData = 1;;}
    break;

  case 165:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 166:

    {yyReadData = 1;;}
    break;

  case 167:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 168:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].PositiveDecimalTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].SolidObjectTypeListVal));;}
    break;

  case 169:

    {(yyval.WorkTableTypeVal) = (yyvsp[(2) - (3)].WorkTableTypeVal);;}
    break;

  case 170:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 171:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 172:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 173:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 174:

    {yyReadData = 1;;}
    break;

  case 175:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 176:

    {yyReadData = 1;;}
    break;

  case 177:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
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

    {(yyval.BoxyObjectTypeVal) = new BoxyObjectType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.BoxyObjectTypeVal)->printTypp = true;
	  ;}
    break;

  case 182:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 183:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].PhysicalLocationTypeVal), (yyvsp[(5) - (6)].PhysicalLocationTypeListVal), (yyvsp[(6) - (6)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 184:

    {(yyval.EndEffectorTypeVal) = new EndEffectorType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.EndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 185:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].PositiveDecimalTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 186:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 187:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlIDREFVal), (yyvsp[(7) - (9)].KitTrayTypeVal), (yyvsp[(8) - (9)].PartTypeListVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 188:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].AngleUnitTypeVal), (yyvsp[(7) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(8) - (15)].KitDesignTypeListVal), (yyvsp[(9) - (15)].LengthUnitTypeVal), (yyvsp[(10) - (15)].SolidObjectTypeListVal), (yyvsp[(11) - (15)].BoxVolumeTypeListVal), (yyvsp[(12) - (15)].RobotTypeVal), (yyvsp[(13) - (15)].StockKeepingUnitTypeListVal), (yyvsp[(14) - (15)].WeightUnitTypeVal), (yyvsp[(15) - (15)].WorkTableTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 189:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].LargeContainerTypeVal), (yyvsp[(7) - (7)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 190:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].LargeContainerTypeVal), (yyvsp[(7) - (9)].KitTypeListVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 191:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 192:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 193:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 194:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].PositiveDecimalTypeVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].XmlIDREFVal), (yyvsp[(10) - (10)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 195:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].PartsTrayTypeVal), (yyvsp[(7) - (7)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 196:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 197:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 198:

    {(yyval.PoseLocationTypeVal) = new PoseLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 199:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 200:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 201:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 202:

    {(yyval.RelativeLocationTypeVal) = new RelativeLocationType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlIDREFVal));
	   (yyval.RelativeLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 203:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].XmlStringVal), (yyvsp[(7) - (9)].EndEffectorTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].BoxVolumeTypeListVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 204:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].PhysicalLocationTypeListVal), (yyvsp[(6) - (12)].XmlStringVal), (yyvsp[(7) - (12)].PositiveDecimalTypeVal), (yyvsp[(8) - (12)].PositiveDecimalTypeVal), (yyvsp[(9) - (12)].PositiveDecimalTypeVal), (yyvsp[(10) - (12)].PositiveDecimalTypeVal), (yyvsp[(11) - (12)].XmlPositiveIntegerVal), (yyvsp[(12) - (12)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 205:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlStringVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 206:

    {(yyval.VacuumEffectorTypeVal) = new VacuumEffectorType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlStringVal), (yyvsp[(7) - (10)].PositiveDecimalTypeVal), (yyvsp[(8) - (10)].PositiveDecimalTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 207:

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

