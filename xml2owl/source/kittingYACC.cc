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
     KITTRAYSEND = 307,
     KITTRAYSSTART = 308,
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
     PARTSKUNAMEEND = 335,
     PARTSKUNAMESTART = 336,
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
     ROBOTEND = 347,
     ROBOTSTART = 348,
     SECONDARYLOCATIONEND = 349,
     SECONDARYLOCATIONSTART = 350,
     SERIALNUMBEREND = 351,
     SERIALNUMBERSTART = 352,
     SHAPEEND = 353,
     SHAPESTART = 354,
     SKUNAMEEND = 355,
     SKUNAMESTART = 356,
     SKUEND = 357,
     SKUSTART = 358,
     SOLIDOBJECTEND = 359,
     SOLIDOBJECTSTART = 360,
     TRAYEND = 361,
     TRAYSTART = 362,
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
     202,   204,   207,   208,   214,   224,   228,   229,   232,   241,
     245,   246,   249,   264,   274,   278,   279,   285,   286,   292,
     293,   299,   303,   307,   308,   314,   318,   322,   324,   327,
     331,   332,   335,   336,   342,   349,   353,   355,   358,   359,
     365,   372,   376,   377,   380,   390,   394,   398,   400,   402,
     404,   406,   408,   410,   412,   418,   422,   426,   427,   433,
     442,   446,   450,   454,   455,   458,   459,   465,   469,   473,
     474,   480,   484,   486,   489,   494,   496,   498,   500,   502,
     504,   506,   508,   510,   512,   514,   516,   518,   520,   522,
     524,   526,   528,   530,   532,   534,   538,   542,   543,   546,
     553,   557,   563,   564,   570,   571,   577,   578,   584,   593,
     597,   601,   603,   606,   610,   611,   617,   618,   624,   628,
     629,   635,   644,   651,   658,   667,   676,   687,   697,   713,
     721,   731,   742,   750,   761,   772,   780,   788,   796,   804,
     812,   818,   824,   829,   839,   852,   863,   874
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     164,     0,    -1,   175,    57,   165,   224,    56,    -1,    12,
      11,   166,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     9,    13,    10,     7,    -1,     9,    13,    10,
       5,    10,     7,    -1,    -1,    15,     6,   177,     4,    14,
      -1,    -1,    17,     6,   179,   173,    16,    -1,    -1,    19,
       6,   181,     4,    18,    -1,     6,   235,   233,   234,    -1,
      -1,    21,     6,   184,   173,    20,    -1,    23,   192,    22,
      -1,    -1,    25,     6,   187,     4,    24,    -1,    -1,    27,
       6,   189,   174,    26,    -1,    -1,    29,     6,   191,   170,
      28,    -1,     6,   235,   257,   263,   195,    -1,     6,   235,
     257,   263,   200,    -1,     6,   235,   257,   263,    -1,    31,
     193,    30,    -1,   194,    -1,   195,   194,    -1,    -1,    33,
       6,   197,   170,    32,    -1,    -1,   198,   196,    -1,   301,
      -1,   320,    -1,   321,    -1,   322,    -1,    35,   199,    34,
      -1,    -1,    37,     6,   202,   167,    36,    -1,    -1,    39,
       6,   204,     4,    38,    -1,    -1,    41,     6,   206,   168,
      40,    -1,    -1,    43,     6,   208,   168,    42,    -1,    -1,
      45,     6,   210,   168,    44,    -1,    -1,    47,     6,   212,
     170,    46,    -1,     6,   235,   216,   245,    -1,    49,   213,
      48,    -1,   214,    -1,   215,   214,    -1,    -1,    51,     6,
     217,   170,    50,    -1,     6,   235,   257,   263,   229,   283,
     203,   268,   264,    -1,    53,   218,    52,    -1,    -1,   220,
     219,    -1,     6,   235,   257,   263,   190,   277,   250,   201,
      -1,    55,   221,    54,    -1,    -1,   223,   222,    -1,     6,
     235,   257,   263,   176,   185,   215,   227,   238,   240,   261,
     271,   279,   286,    -1,     6,   235,   257,   263,   229,   283,
     203,   268,   264,    -1,    59,   225,    58,    -1,    -1,    61,
       6,   228,     4,    60,    -1,    -1,    63,     6,   230,     4,
      62,    -1,    -1,    65,     6,   232,     4,    64,    -1,    67,
     255,    66,    -1,    69,   255,    68,    -1,    -1,    71,     6,
     236,   169,    70,    -1,    73,   272,    72,    -1,    73,   273,
      72,    -1,   237,    -1,   238,   237,    -1,    75,   182,    74,
      -1,    -1,   240,   239,    -1,    -1,    77,     6,   242,   172,
      76,    -1,     6,   235,   268,   256,   289,   294,    -1,    79,
     243,    78,    -1,   244,    -1,   245,   244,    -1,    -1,    81,
       6,   247,   170,    80,    -1,     6,   235,   257,   263,   268,
     264,    -1,    83,   248,    82,    -1,    -1,   250,   249,    -1,
       6,   235,   257,   263,   229,   283,   203,   268,   264,    -1,
      85,   251,    84,    -1,     6,   235,   258,    -1,   312,    -1,
     313,    -1,   314,    -1,   315,    -1,   316,    -1,   317,    -1,
     318,    -1,     6,   235,   290,   292,   295,    -1,    87,   255,
      86,    -1,    89,   254,    88,    -1,    -1,    91,     6,   259,
     170,    90,    -1,     6,   235,   257,   263,   188,   200,   231,
     288,    -1,    93,   260,    92,    -1,    95,   253,    94,    -1,
      95,   254,    94,    -1,    -1,   263,   262,    -1,    -1,    97,
       6,   265,   171,    96,    -1,     6,   235,   188,    -1,    99,
     266,    98,    -1,    -1,   101,     6,   269,   170,   100,    -1,
     103,   276,   102,    -1,   270,    -1,   271,   270,    -1,     6,
     235,   257,   263,    -1,   297,    -1,   298,    -1,   299,    -1,
     300,    -1,   301,    -1,   302,    -1,   303,    -1,   304,    -1,
     305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,
     310,    -1,   311,    -1,   319,    -1,   320,    -1,   321,    -1,
     322,    -1,   323,    -1,   105,   272,   104,    -1,   105,   273,
     104,    -1,    -1,   275,   274,    -1,     6,   235,   188,   267,
     281,   198,    -1,   107,   218,   106,    -1,     6,   235,   205,
     207,   209,    -1,    -1,   109,     6,   280,     4,   108,    -1,
      -1,   111,     6,   282,     4,   110,    -1,    -1,   113,     6,
     284,     4,   112,    -1,     6,   235,   257,   263,   229,   283,
     203,   275,    -1,   115,   285,   114,    -1,   117,   182,   116,
      -1,   287,    -1,   288,   287,    -1,   119,   278,   118,    -1,
      -1,   121,     6,   291,   168,   120,    -1,    -1,   123,     6,
     293,   168,   122,    -1,   125,   278,   124,    -1,    -1,   127,
       6,   296,   168,   126,    -1,   129,     6,   235,   257,   263,
     229,   283,   203,    -1,   130,     6,   235,   257,   263,   195,
      -1,   131,     6,   235,   257,   263,   200,    -1,   132,     6,
     235,   257,   263,   188,   281,   231,    -1,   133,     6,   235,
     257,   263,   188,   281,   231,    -1,   135,     6,   235,   257,
     263,   229,   283,   203,   268,   264,    -1,   136,     6,   235,
     257,   263,   190,   277,   250,   201,    -1,   137,     6,   235,
     257,   263,   176,   185,   215,   227,   238,   240,   261,   271,
     279,   286,    -1,   138,     6,   235,   257,   263,   226,   220,
      -1,   139,     6,   235,   257,   263,   226,   223,   211,   183,
      -1,   140,     6,   235,   257,   263,   229,   283,   203,   268,
     264,    -1,   142,     6,   235,   257,   263,   268,   264,    -1,
     143,     6,   235,   257,   263,   229,   283,   203,   246,   241,
      -1,   144,     6,   235,   257,   263,   229,   283,   203,   268,
     264,    -1,   145,     6,   235,   257,   263,   252,   250,    -1,
     148,     6,   235,   258,   256,   289,   294,    -1,   149,     6,
     235,   258,   256,   289,   294,    -1,   150,     6,   235,   258,
     256,   289,   294,    -1,   151,     6,   235,   258,   256,   289,
     294,    -1,   152,     6,   235,   258,   188,    -1,   153,     6,
     235,   258,   188,    -1,   154,     6,   235,   258,    -1,   155,
       6,   235,   257,   263,   188,   200,   231,   288,    -1,   158,
       6,   235,   257,   263,   188,   281,   231,   186,   229,   178,
     180,    -1,   159,     6,   235,   257,   263,   188,   281,   231,
     186,   229,    -1,   160,     6,   235,   257,   263,   188,   281,
     231,   186,   229,    -1,   162,     6,   235,   257,   263,   229,
     283,   203,   275,    -1
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
     676,   679,   685,   685,   691,   700,   706,   707,   713,   721,
     727,   728,   734,   747,   756,   761,   761,   770,   770,   778,
     778,   787,   792,   797,   797,   802,   804,   809,   812,   818,
     824,   825,   832,   832,   838,   844,   849,   852,   859,   859,
     865,   872,   878,   879,   885,   894,   899,   904,   906,   908,
     910,   912,   914,   916,   921,   927,   932,   937,   937,   942,
     951,   956,   959,   966,   967,   974,   974,   980,   985,   990,
     990,   995,  1000,  1003,  1009,  1015,  1017,  1019,  1021,  1023,
    1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1058,  1060,  1066,  1067,  1074,
    1081,  1086,  1092,  1092,  1101,  1101,  1109,  1109,  1117,  1126,
    1131,  1136,  1139,  1145,  1150,  1150,  1155,  1155,  1160,  1165,
    1165,  1170,  1181,  1191,  1201,  1212,  1223,  1235,  1246,  1262,
    1273,  1284,  1296,  1306,  1318,  1330,  1340,  1348,  1356,  1364,
    1373,  1381,  1389,  1397,  1409,  1423,  1435,  1447
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
  "KITDESIGNSTART", "KITTRAYSKUNAMEEND", "KITTRAYSKUNAMESTART",
  "KITTRAYSEND", "KITTRAYSSTART", "KITEND", "KITSTART",
  "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART", "LARGECONTAINEREND",
  "LARGECONTAINERSTART", "LENGTHUNITEND", "LENGTHUNITSTART", "LENGTHEND",
  "LENGTHSTART", "MAXIMUMLOADWEIGHTEND", "MAXIMUMLOADWEIGHTSTART",
  "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART", "MINIMUMPOINTEND",
  "MINIMUMPOINTSTART", "NAMEEND", "NAMESTART", "OBJECTEND", "OBJECTSTART",
  "OTHEROBSTACLEEND", "OTHEROBSTACLESTART", "PARTQUANTITYEND",
  "PARTQUANTITYSTART", "PARTREFANDPOSEEND", "PARTREFANDPOSESTART",
  "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND", "PARTSTART",
  "PARTSTRAYEND", "PARTSTRAYSTART", "POINTEND", "POINTSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "REFOBJECTEND",
  "REFOBJECTSTART", "ROBOTEND", "ROBOTSTART", "SECONDARYLOCATIONEND",
  "SECONDARYLOCATIONSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SHAPEEND", "SHAPESTART", "SKUNAMEEND", "SKUNAMESTART", "SKUEND",
  "SKUSTART", "SOLIDOBJECTEND", "SOLIDOBJECTSTART", "TRAYEND", "TRAYSTART",
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
  "y_KitTraySkuName_XmlIDREF", "$@15", "y_KitTrayType",
  "y_KitTrays_KitTrayType_0_u", "y_KitTrays_KitTrayType_0_uList",
  "y_KitType", "y_Kit_KitType_0_u", "y_Kit_KitType_0_uList",
  "y_KittingWorkstationType", "y_LargeContainerType",
  "y_LargeContainer_LargeContainerType", "y_LengthUnit_LengthUnitType",
  "$@16", "y_Length_PositiveDecimalType", "$@17",
  "y_MaximumLoadWeight_PositiveDecimalType", "$@18",
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
  "y_Tray_KitTrayType", "y_VectorType", "y_WeightUnit_WeightUnitType",
  "$@25", "y_Weight_PositiveDecimalType", "$@26",
  "y_Width_PositiveDecimalType", "$@27", "y_WorkTableType",
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
     215,   215,   217,   216,   218,   219,   220,   220,   221,   222,
     223,   223,   224,   225,   226,   228,   227,   230,   229,   232,
     231,   233,   234,   236,   235,   237,   237,   238,   238,   239,
     240,   240,   242,   241,   243,   244,   245,   245,   247,   246,
     248,   249,   250,   250,   251,   252,   253,   254,   254,   254,
     254,   254,   254,   254,   255,   256,   257,   259,   258,   260,
     261,   262,   262,   263,   263,   265,   264,   266,   267,   269,
     268,   270,   271,   271,   272,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   274,   275,   275,   276,
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
       1,     2,     0,     5,     9,     3,     0,     2,     8,     3,
       0,     2,    14,     9,     3,     0,     5,     0,     5,     0,
       5,     3,     3,     0,     5,     3,     3,     1,     2,     3,
       0,     2,     0,     5,     6,     3,     1,     2,     0,     5,
       6,     3,     0,     2,     9,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     0,     5,     8,
       3,     3,     3,     0,     2,     0,     5,     3,     3,     0,
       5,     3,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     2,     6,
       3,     5,     0,     5,     0,     5,     0,     5,     8,     3,
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
       2,    14,     4,    83,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,   124,    84,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   121,   122,     0,     0,     0,    60,     0,   117,     0,
       0,     0,     0,     0,     0,   200,   201,     0,   106,     0,
      24,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    16,   123,     0,    59,    75,
       0,    87,    90,     8,     0,     0,   115,     0,     0,     0,
     196,   197,   198,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    88,     0,   118,     0,     0,     0,   173,     0,
      12,     0,     0,    35,    31,    62,     0,    96,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,    91,     0,   174,     0,     0,
       0,     0,   178,    28,     0,     0,    36,     0,     0,     0,
      97,    76,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,   176,     0,   114,    50,     0,     0,     0,    34,     0,
       0,    95,   134,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,     0,    89,     0,   120,     0,     0,     0,
     133,     0,     6,     0,     0,   179,     0,    52,     0,   161,
     123,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,   131,   162,
       0,    72,   175,     0,     0,     0,     0,    54,    33,   129,
       0,     0,     0,   182,     0,   183,     0,     0,     0,     0,
       0,     0,     0,    66,    70,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,   177,     0,    51,     0,     0,    32,
       0,     0,    77,     0,     0,     0,    41,    42,    43,    44,
       0,     0,     0,     0,    29,     0,   102,     0,     0,     0,
     189,     0,     0,     0,   192,     0,     0,     0,     0,   195,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,   169,   180,    53,     0,     0,    94,     0,   166,
       0,   181,    45,   164,     0,   184,   185,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    67,     0,     0,     0,
      71,     0,   125,     0,     0,     0,   105,     0,   103,     0,
       0,     0,     0,   157,    82,     0,     0,     0,    39,   163,
     123,    55,   130,     0,     0,    48,     0,    79,     0,     0,
       0,   160,     0,   187,     0,   123,     0,    56,     0,     0,
       0,   190,     0,     0,     0,     0,     0,   123,     0,     0,
       0,   171,   203,     0,     0,     0,     0,   207,     0,     0,
     128,   159,     0,    78,     0,     0,     0,     0,   186,    30,
     123,    46,    90,     0,    65,     0,     0,    69,    22,   191,
       9,     0,    98,     0,   193,   194,     0,     0,   101,     0,
     172,    25,     0,   205,   206,     0,   158,   119,   127,     0,
      40,     0,   167,     0,   165,     0,     0,     0,     0,     0,
       0,   123,     0,   126,     0,    92,     0,   123,   170,     0,
       0,     0,     0,     0,    37,     0,    49,    80,     0,     5,
       0,     0,     0,    57,     0,    11,     0,     0,     0,     0,
       0,     0,    17,     0,   204,   155,   156,     0,   157,     0,
      47,     0,     0,     0,    23,    99,    10,     0,     0,     0,
      26,     0,    19,     0,   168,     0,     0,     0,   102,    93,
       0,   100,     0,     0,    38,     0,   188,    73,     0,   104,
      18,     0,    64,    68,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   600,   313,    44,   124,   551,   627,
     606,   191,     3,    55,    79,   591,   631,   614,   643,   264,
     511,   582,    70,   524,   589,    95,   134,   370,   458,    84,
     235,   193,   194,   570,   617,   531,   405,   365,   503,   577,
     451,   535,   231,   316,   276,   356,   319,   398,   469,   545,
     102,    86,    87,   137,   237,   460,   466,   420,   509,   470,
     421,    14,   419,   373,   105,   138,   362,   448,   455,   537,
     345,   388,    19,    26,   121,   122,   225,   183,   554,   608,
     239,   197,   198,   515,   584,   519,   478,   429,   428,   380,
      67,    34,   108,    90,    25,    72,   106,   266,   226,    56,
      42,   424,   513,   487,   439,   323,   400,   268,   269,   160,
     161,   566,   527,   308,   416,   128,   311,   391,   411,   496,
     404,   494,   393,   351,   521,   522,   110,   186,   270,   229,
     314,   130,   273,   354,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    35,
      36,    37,    38,    39,    40,    41,   177,   178,   179,   180,
     181
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -488
static const yytype_int16 yypact[] =
{
      45,    48,    72,    17,    67,  -488,    79,    52,    68,    78,
      92,  -488,   101,    39,    57,   105,   111,  -488,   116,    34,
    -488,  -488,  -488,  -488,    -9,  -488,   120,   121,   122,   123,
     124,   125,   126,   129,    38,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,     8,  -488,    81,    39,    39,    39,    39,    39,
      39,    39,  -488,   142,    28,   131,  -488,  -488,    58,    58,
      58,    58,    58,    58,    58,  -488,    39,    61,    89,   146,
     135,   179,    99,    99,    99,    99,   160,   160,  -488,   184,
      58,  -488,  -488,    39,   170,   208,  -488,     2,  -488,   209,
      98,    98,    98,    98,   213,  -488,  -488,   207,  -488,    34,
    -488,    39,   174,   217,  -488,   151,   221,    39,   140,   222,
     102,   102,   102,   102,  -488,  -488,  -488,   178,  -488,  -488,
     364,  -488,   151,  -488,   164,   109,  -488,    39,   114,   222,
    -488,  -488,  -488,  -488,   251,     5,   250,   181,   257,    39,
     258,   260,   263,   269,   270,   271,   279,   281,   283,   284,
     285,   286,   287,   288,   290,   291,   295,   297,   299,   300,
     191,   237,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,   -28,  -488,   304,   190,   275,  -488,   193,
    -488,   292,   313,  -488,   293,  -488,   316,  -488,   181,   265,
      34,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,  -488,  -488,   317,   320,  -488,   225,  -488,   323,   203,
     327,   294,  -488,  -488,    39,   305,  -488,   221,    39,   256,
    -488,  -488,  -488,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    39,   262,    39,   246,   333,  -488,   -51,
     336,  -488,   335,  -488,  -488,   337,   301,    34,  -488,   298,
     241,  -488,   249,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,   278,  -488,    34,  -488,    39,   247,   344,
    -488,   236,  -488,   232,   336,  -488,   336,  -488,   347,  -488,
    -488,  -488,   348,    99,   -24,     5,     6,     1,     1,   -24,
       0,     8,   -22,   -22,   -24,   -20,   -24,   -24,   -25,     1,
       1,     1,     1,   -24,   209,   289,  -488,   160,  -488,  -488,
     349,  -488,  -488,   234,   336,   319,   336,  -488,     6,  -488,
      98,   351,   252,   293,   -91,  -488,   253,   253,   252,   354,
     259,   131,   357,  -488,  -488,   252,   272,   252,   252,   361,
    -488,   339,   253,   253,   253,   252,   302,   209,  -488,     1,
     273,   367,    39,   261,  -488,   254,  -488,   334,   336,  -488,
     221,   102,  -488,   371,   340,   352,  -488,  -488,  -488,  -488,
     372,   318,   318,   340,  -488,   375,  -488,   135,    39,   329,
     332,    31,   340,   382,  -488,   340,   340,    39,   306,   308,
     318,   318,   318,   318,   340,  -488,   321,   339,   386,   253,
     303,    34,  -488,  -488,  -488,   350,   309,  -488,   389,  -488,
     391,  -488,  -488,  -488,   392,  -488,  -488,   241,   221,    39,
     296,    -7,     2,    34,  -488,   375,  -488,   393,   397,   374,
    -488,   241,  -488,   324,   241,    34,  -488,   400,  -488,   307,
     383,   383,   383,  -488,  -488,   318,    39,   312,  -488,  -488,
    -488,  -488,  -488,   353,   409,  -488,   413,  -488,   272,   390,
      34,  -488,   414,  -488,   151,  -488,   369,  -488,    39,   365,
     416,  -488,   272,   419,   420,   355,   272,  -488,    39,   343,
     317,  -488,   307,   423,   373,   373,   373,   325,   307,   160,
    -488,   401,   -24,  -488,   326,   431,   330,   433,  -488,  -488,
    -488,  -488,   151,   -24,  -488,   221,    34,  -488,  -488,  -488,
    -488,   346,  -488,   437,  -488,  -488,   -24,    34,  -488,   328,
    -488,  -488,   422,  -488,  -488,   364,  -488,   307,  -488,   439,
    -488,   252,  -488,   408,  -488,   384,   -24,   443,   -28,   252,
     403,  -488,   446,  -488,   221,  -488,   252,  -488,  -488,   448,
     449,   435,   358,   360,  -488,   340,  -488,  -488,   252,  -488,
     421,   225,   340,  -488,     0,  -488,   436,   378,   455,   340,
     -20,   442,  -488,   461,  -488,  -488,  -488,   221,  -488,   340,
    -488,   -51,   241,   259,  -488,  -488,  -488,   385,   241,   272,
    -488,   446,  -488,   438,   325,   241,   236,   272,  -488,  -488,
     272,  -488,   452,   465,  -488,   272,  -488,  -488,    -7,  -488,
    -488,   453,  -488,  -488,  -488
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -488,  -488,  -488,  -488,  -488,  -290,  -488,  -184,  -488,  -488,
    -159,  -488,  -488,   143,  -488,  -488,  -488,  -488,  -488,   -44,
    -488,  -488,   104,  -394,  -488,   -69,  -488,  -127,  -488,  -488,
    -488,  -172,   153,  -488,  -488,  -488,  -488,  -326,  -169,  -488,
    -288,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,   -78,    63,  -488,  -488,    16,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,   149,    21,  -488,  -244,  -488,  -387,  -488,
    -488,  -488,   -45,  -488,  -115,   -19,  -488,   -58,  -488,  -488,
    -488,   314,  -488,  -488,  -488,  -488,  -488,  -385,  -488,  -488,
    -488,   432,  -304,   -55,   -10,    56,  -488,  -488,   -90,  -488,
     -89,  -233,  -488,  -488,  -488,  -324,  -488,  -259,  -114,   -74,
     -60,  -488,  -129,  -488,  -113,   387,  -110,  -488,  -334,  -488,
    -271,  -488,  -488,  -123,  -487,   -14,   -76,  -488,  -488,  -488,
    -488,   -99,  -488,  -488,  -488,  -488,  -488,  -488,   154,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,   156,   157,   161,
    -488
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
      93,    80,   236,    53,   353,   456,   355,   135,    94,   369,
     502,   461,   399,   412,    66,   560,   192,   372,    99,   361,
     386,   364,   144,   479,   480,   481,   482,   223,   431,   432,
     433,    85,   267,   279,     1,   430,   117,    10,   309,    11,
     379,     4,   125,   103,   395,   224,   397,   156,   157,   158,
      54,    54,     5,    54,     6,    54,   477,     7,   467,    12,
     560,   322,   187,   436,    13,   368,   468,   525,   526,   116,
     375,     8,   377,   378,   200,    54,    54,   413,   528,   385,
      54,    54,    15,    54,   422,   488,   425,   426,   445,    16,
      18,   485,    21,    20,   434,    73,    74,    75,    76,    77,
      78,    22,    23,    24,    43,   457,    52,    45,    46,    47,
      48,    49,    50,   498,   471,    51,    98,   473,   474,    27,
      28,    29,    30,    31,    32,    33,   483,   512,    65,    71,
     516,    57,    83,   282,    69,    81,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    27,    28,    29,    30,
      31,    32,    33,    82,    85,    88,    89,    94,    97,   277,
     242,   236,   100,   280,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   101,   107,   446,   109,   303,   114,
     305,   115,   118,   119,   120,   123,   126,   129,   127,   136,
     185,   358,   188,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   648,   184,   190,   195,   389,   366,   367,
     196,   199,   347,   221,   201,   538,   202,   320,   360,   203,
     381,   382,   383,   384,   499,   204,   205,   206,   390,   549,
     562,   563,   564,   555,   401,   207,   629,   208,   571,   209,
     210,   211,   212,   213,   214,   346,   215,   216,   637,   579,
     595,   217,   447,   218,   640,   219,   220,   618,   602,   222,
     227,   645,   586,   228,   622,   609,   230,   232,   233,   234,
     437,   628,   238,   263,   192,   241,   265,   619,   267,   271,
     272,   635,   598,   274,   281,   278,   304,   275,   306,   307,
     312,   315,   322,   317,    54,   344,   318,   441,   321,   348,
     349,   350,   352,   357,   359,   392,   394,   402,   387,   396,
     414,   580,   310,   418,   410,   403,   415,   427,   435,   423,
     139,   440,   438,   463,   364,   442,   444,   449,   453,   450,
     443,   459,   475,   454,   104,   465,   452,   464,   472,   484,
     476,   477,   486,   493,   491,   510,   641,   495,   497,   507,
     607,   532,   501,   508,   647,   514,   518,   649,   523,   492,
     530,   489,   652,   534,   500,   533,   543,   536,   539,   547,
     541,   544,   548,   550,   520,   558,   552,   182,   556,   561,
     565,   490,   553,   633,   569,   573,   361,   575,   572,   590,
     574,   529,   583,   585,   588,   594,   596,   599,   597,   603,
     605,   576,   611,   505,   613,   612,   624,   620,   625,   626,
     568,   639,   615,   546,   616,   517,   630,   632,   650,   651,
     644,   654,   642,   557,   371,   417,   559,   623,   363,   653,
     462,   506,   374,   504,   578,   542,    68,   621,   601,   634,
     540,   592,   604,   140,   141,   142,   143,   144,   610,   145,
     146,   147,   148,   149,   150,   593,   151,   152,   153,   154,
     638,   636,   240,   646,   567,     0,   189,     0,   406,   155,
     407,   408,   156,   157,   158,   409,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587
};

static const yytype_int16 yycheck[] =
{
      45,    46,    47,    48,    49,    50,    51,   122,    77,    87,
     269,   335,   111,   112,   113,    91,    92,    93,    73,    74,
      75,    66,   194,    15,   314,   412,   316,   116,    27,    29,
      37,   416,   358,   367,     6,   522,    31,    59,    83,    63,
     344,    35,   133,   430,   431,   432,   433,    75,   382,   383,
     384,    49,   103,   237,     9,   381,   101,     5,   109,     7,
      85,    13,   107,    61,   354,    93,   356,   158,   159,   160,
      95,    95,     0,    95,    57,    95,    83,    10,    47,    11,
     567,   101,   127,   387,     6,   329,    55,   481,   482,    99,
     334,    12,   336,   337,   139,    95,    95,   368,   485,   343,
      95,    95,    10,    95,   375,   439,   377,   378,   398,     8,
      71,   437,     7,    56,   385,    59,    60,    61,    62,    63,
      64,    10,     6,    89,     4,   413,    88,     6,     6,     6,
       6,     6,     6,   457,   422,     6,    80,   425,   426,   148,
     149,   150,   151,   152,   153,   154,   434,   471,     6,    91,
     474,    70,     6,   242,    23,    94,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   148,   149,   150,   151,
     152,   153,   154,    94,    49,     6,    87,    27,     4,   234,
     200,   363,    22,   238,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     6,     6,   400,   119,   263,     6,
     265,    14,    48,     6,    73,     4,    86,   125,     6,    51,
     121,   320,   118,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   638,    90,     4,     6,   346,   327,   328,
      79,     4,   307,    72,     6,   498,     6,   277,   323,     6,
     339,   340,   341,   342,   458,     6,     6,     6,   347,   512,
     524,   525,   526,   516,   360,     6,   610,     6,   532,     6,
       6,     6,     6,     6,     6,   305,     6,     6,   622,   543,
     571,     6,   401,     6,   628,     6,     6,   595,   579,    72,
       6,   635,   556,   123,   602,   586,    41,   124,    26,     6,
     389,   609,     6,     6,    31,    60,     6,   598,   103,     6,
     127,   619,   576,     6,    78,    30,    74,    43,    92,     6,
       4,     6,   101,     6,    95,    67,    45,   392,    50,   102,
       6,   115,   120,     6,     6,     6,   122,     6,    69,    40,
       6,   545,   621,     6,   111,   113,   107,     6,    66,    97,
       6,     4,    99,   418,    35,   114,    42,     6,     6,    39,
     126,     6,   427,    65,   462,    53,    34,    58,     6,    68,
      84,    83,     6,     4,    44,    21,   629,     6,     6,     6,
     584,   490,   106,     6,   637,    81,     6,   640,    25,   100,
      98,   108,   645,     4,   459,    62,   505,     4,    28,    54,
       6,    52,     6,     4,   117,    82,     6,   542,   517,     6,
     105,   441,    77,   617,    33,     4,    63,     4,   112,    17,
     110,   486,    96,     6,   116,     6,    38,     4,    64,    46,
       4,   540,     4,   463,    19,     6,    20,    36,    80,     4,
     529,    76,   104,   508,   104,   475,    24,     6,    16,     4,
      32,    18,   631,   518,   331,   371,   520,   604,   325,   648,
     417,   465,   333,   462,   542,   504,    54,   601,   578,   618,
     500,   565,   581,   129,   130,   131,   132,   133,   587,   135,
     136,   137,   138,   139,   140,   565,   142,   143,   144,   145,
     623,   621,   198,   636,   528,    -1,   129,    -1,   364,   155,
     364,   364,   158,   159,   160,   364,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   557
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   164,   175,    13,     0,    57,    10,    12,   165,
       5,     7,    11,     6,   224,    10,     8,   166,    71,   235,
      56,     7,    10,     6,    89,   257,   236,   148,   149,   150,
     151,   152,   153,   154,   254,   312,   313,   314,   315,   316,
     317,   318,   263,     4,   169,     6,     6,     6,     6,     6,
       6,     6,    88,    15,    95,   176,   262,    70,   235,   235,
     235,   235,   235,   235,   235,     6,     6,   253,   254,    23,
     185,    91,   258,   258,   258,   258,   258,   258,   258,   177,
     235,    94,    94,     6,   192,    49,   214,   215,     6,    87,
     256,   256,   256,   256,    27,   188,   188,     4,   258,   235,
      22,     6,   213,    61,   214,   227,   259,     6,   255,   119,
     289,   289,   289,   289,     6,    14,   257,   235,    48,     6,
      73,   237,   238,     4,   170,   235,    86,     6,   278,   125,
     294,   294,   294,   294,   189,   263,    51,   216,   228,     6,
     129,   130,   131,   132,   133,   135,   136,   137,   138,   139,
     140,   142,   143,   144,   145,   155,   158,   159,   160,   162,
     272,   273,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   319,   320,   321,
     322,   323,   237,   240,    90,   121,   290,   235,   118,   278,
       4,   174,    31,   194,   195,     6,    79,   244,   245,     4,
     235,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    72,    72,    75,    93,   239,   261,     6,   123,   292,
      41,   205,   124,    26,     6,   193,   194,   217,     6,   243,
     244,    60,   257,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,     6,   182,     6,   260,   103,   270,   271,
     291,     6,   127,   295,     6,    43,   207,   235,    30,   170,
     235,    78,   263,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   235,    74,   235,    92,     6,   276,   109,
     270,   279,     4,   168,   293,     6,   206,     6,    45,   209,
     257,    50,   101,   268,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,    67,   233,   257,   235,   102,     6,
     115,   286,   120,   168,   296,   168,   208,     6,   263,     6,
     256,    63,   229,   195,    35,   200,   188,   188,   229,    29,
     190,   176,    59,   226,   226,   229,   268,   229,   229,    85,
     252,   188,   188,   188,   188,   229,   255,    69,   234,   263,
     188,   280,     6,   285,   122,   168,    40,   168,   210,   200,
     269,   289,     6,   113,   283,   199,   301,   320,   321,   322,
     111,   281,   281,   283,     6,   107,   277,   185,     6,   225,
     220,   223,   283,    97,   264,   283,   283,     6,   251,   250,
     200,   281,   281,   281,   283,    66,   255,   188,    99,   267,
       4,   235,   114,   126,    42,   168,   170,   294,   230,     6,
      39,   203,    34,     6,    65,   231,   231,   203,   191,     6,
     218,   250,   215,   235,    58,    53,   219,    47,    55,   211,
     222,   203,     6,   203,   203,   235,    84,    83,   249,   231,
     231,   231,   231,   203,    68,   200,     6,   266,   281,   108,
     257,    44,   100,     4,   284,     6,   282,     6,   268,   170,
     235,   106,    37,   201,   227,   257,   218,     6,     6,   221,
      21,   183,   268,   265,    81,   246,   268,   257,     6,   248,
     117,   287,   288,    25,   186,   186,   186,   275,   231,   235,
      98,   198,   263,    62,     4,   204,     4,   232,   264,    28,
     257,     6,   238,   263,    52,   212,   235,    54,     6,   264,
       4,   171,     6,    77,   241,   264,   263,   235,    82,   182,
     287,     6,   229,   229,   229,   105,   274,   288,   188,    33,
     196,   229,   112,     4,   110,     4,   263,   202,   240,   229,
     170,   257,   184,    96,   247,     6,   229,   257,   116,   187,
      17,   178,   272,   273,     6,   283,    38,    64,   229,     4,
     167,   261,   283,    46,   263,     4,   173,   170,   242,   283,
     263,     4,     6,    19,   180,   104,   104,   197,   203,   283,
      36,   271,   203,   190,    20,    80,     4,   172,   203,   268,
      24,   179,     6,   170,   275,   203,   279,   268,   277,    76,
     268,   264,   173,   181,    32,   268,   286,   264,   250,   264,
      16,     4,   264,   201,    18
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

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 66:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 67:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
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

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].XmlStringVal), (yyvsp[(6) - (8)].EndEffectorTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].BoxVolumeTypeListVal));;}
    break;

  case 120:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 121:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 122:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 123:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 124:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 125:

    {yyReadData = 1;;}
    break;

  case 126:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 127:

    {(yyval.ShapeDesignTypeVal) = new ShapeDesignType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlStringVal));;}
    break;

  case 128:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 129:

    {yyReadData = 1;;}
    break;

  case 130:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 131:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 132:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 133:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 134:

    {(yyval.SolidObjectTypeVal) = new SolidObjectType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PhysicalLocationTypeVal), (yyvsp[(4) - (4)].PhysicalLocationTypeListVal));;}
    break;

  case 135:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].BoxyObjectTypeVal);;}
    break;

  case 136:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 137:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 138:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorTypeVal);;}
    break;

  case 139:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 140:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 141:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 142:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 143:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 144:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 145:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 146:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 147:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 148:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 149:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 150:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 151:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 152:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 153:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 154:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 155:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 156:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 157:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 158:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 159:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 160:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
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

