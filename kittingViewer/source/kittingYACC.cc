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
#ifdef VIEWER                    // added by hand
#include "kittingClassesView.hh" // for kitting classes in viewer, added by hand
#else                            // added by hand
#include "kittingClasses.hh"     // for kitting classes in parser
#endif                           // added by hand

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
     ENDEFFECTORHOLDERSEND = 287,
     ENDEFFECTORHOLDERSSTART = 288,
     ENDEFFECTORNAMEEND = 289,
     ENDEFFECTORNAMESTART = 290,
     ENDEFFECTOREND = 291,
     ENDEFFECTORSTART = 292,
     EXTERNALSHAPEEND = 293,
     EXTERNALSHAPESTART = 294,
     FINISHEDEND = 295,
     FINISHEDSTART = 296,
     GRASPPOSEEND = 297,
     GRASPPOSESTART = 298,
     HASTOPEND = 299,
     HASTOPSTART = 300,
     HEIGHTEND = 301,
     HEIGHTSTART = 302,
     HELDOBJECTEND = 303,
     HELDOBJECTSTART = 304,
     IEND = 305,
     ISTART = 306,
     INTERNALSHAPEEND = 307,
     INTERNALSHAPESTART = 308,
     JEND = 309,
     JSTART = 310,
     KEND = 311,
     KSTART = 312,
     KITDESIGNNAMEEND = 313,
     KITDESIGNNAMESTART = 314,
     KITDESIGNEND = 315,
     KITDESIGNSTART = 316,
     KITTRAYSKUNAMEEND = 317,
     KITTRAYSKUNAMESTART = 318,
     KITTRAYSEND = 319,
     KITTRAYSSTART = 320,
     KITEND = 321,
     KITSTART = 322,
     KITTINGWORKSTATIONEND = 323,
     KITTINGWORKSTATIONSTART = 324,
     LARGECONTAINEREND = 325,
     LARGECONTAINERSTART = 326,
     LENGTHUNITEND = 327,
     LENGTHUNITSTART = 328,
     LENGTHEND = 329,
     LENGTHSTART = 330,
     MAXIMUMLOADWEIGHTEND = 331,
     MAXIMUMLOADWEIGHTSTART = 332,
     MAXIMUMPOINTEND = 333,
     MAXIMUMPOINTSTART = 334,
     MINIMUMPOINTEND = 335,
     MINIMUMPOINTSTART = 336,
     MODELFILENAMEEND = 337,
     MODELFILENAMESTART = 338,
     MODELNAMEEND = 339,
     MODELNAMESTART = 340,
     MODELTYPENAMEEND = 341,
     MODELTYPENAMESTART = 342,
     NAMEEND = 343,
     NAMESTART = 344,
     OBJECTEND = 345,
     OBJECTSTART = 346,
     OTHEROBSTACLEEND = 347,
     OTHEROBSTACLESTART = 348,
     PARTQUANTITYEND = 349,
     PARTQUANTITYSTART = 350,
     PARTREFANDPOSEEND = 351,
     PARTREFANDPOSESTART = 352,
     PARTSKUNAMEEND = 353,
     PARTSKUNAMESTART = 354,
     PARTEND = 355,
     PARTSTART = 356,
     PARTSTRAYEND = 357,
     PARTSTRAYSTART = 358,
     POINTEND = 359,
     POINTSTART = 360,
     PRIMARYLOCATIONEND = 361,
     PRIMARYLOCATIONSTART = 362,
     REFOBJECTEND = 363,
     REFOBJECTSTART = 364,
     ROBOTEND = 365,
     ROBOTSTART = 366,
     SECONDARYLOCATIONEND = 367,
     SECONDARYLOCATIONSTART = 368,
     SERIALNUMBEREND = 369,
     SERIALNUMBERSTART = 370,
     SHAPEEND = 371,
     SHAPESTART = 372,
     SKUNAMEEND = 373,
     SKUNAMESTART = 374,
     SKUEND = 375,
     SKUSTART = 376,
     SOLIDOBJECTEND = 377,
     SOLIDOBJECTSTART = 378,
     TRAYEND = 379,
     TRAYSTART = 380,
     WEIGHTUNITEND = 381,
     WEIGHTUNITSTART = 382,
     WEIGHTEND = 383,
     WEIGHTSTART = 384,
     WIDTHEND = 385,
     WIDTHSTART = 386,
     WORKTABLEEND = 387,
     WORKTABLESTART = 388,
     WORKVOLUMEEND = 389,
     WORKVOLUMESTART = 390,
     XAXISEND = 391,
     XAXISSTART = 392,
     XEND = 393,
     XSTART = 394,
     YEND = 395,
     YSTART = 396,
     ZAXISEND = 397,
     ZAXISSTART = 398,
     ZEND = 399,
     ZSTART = 400,
     BOXVOLUMETYPEDECL = 401,
     BOXYSHAPETYPEDECL = 402,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 403,
     ENDEFFECTORHOLDERTYPEDECL = 404,
     ENDEFFECTORTYPEDECL = 405,
     EXTERNALSHAPETYPEDECL = 406,
     GRIPPEREFFECTORTYPEDECL = 407,
     INTERNALSHAPETYPEDECL = 408,
     KITDESIGNTYPEDECL = 409,
     KITTRAYTYPEDECL = 410,
     KITTYPEDECL = 411,
     KITTINGWORKSTATIONTYPEDECL = 412,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 413,
     LARGEBOXWITHKITSTYPEDECL = 414,
     LARGECONTAINERTYPEDECL = 415,
     MECHANICALCOMPONENTTYPEDECL = 416,
     PARTREFANDPOSETYPEDECL = 417,
     PARTTYPEDECL = 418,
     PARTSBINTYPEDECL = 419,
     PARTSTRAYTYPEDECL = 420,
     PARTSTRAYWITHPARTSTYPEDECL = 421,
     PHYSICALLOCATIONTYPEDECL = 422,
     POINTTYPEDECL = 423,
     POSELOCATIONINTYPEDECL = 424,
     POSELOCATIONONTYPEDECL = 425,
     POSELOCATIONTYPEDECL = 426,
     POSEONLYLOCATIONTYPEDECL = 427,
     RELATIVELOCATIONINTYPEDECL = 428,
     RELATIVELOCATIONONTYPEDECL = 429,
     RELATIVELOCATIONTYPEDECL = 430,
     ROBOTTYPEDECL = 431,
     SHAPEDESIGNTYPEDECL = 432,
     STOCKKEEPINGUNITTYPEDECL = 433,
     VACUUMEFFECTORMULTICUPTYPEDECL = 434,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 435,
     VACUUMEFFECTORTYPEDECL = 436,
     VECTORTYPEDECL = 437,
     WORKTABLETYPEDECL = 438
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
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
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
#define YYLAST   609

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  184
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  174
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNRULES -- Number of states.  */
#define YYNSTATES  709

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   438

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
     175,   176,   177,   178,   179,   180,   181,   182,   183
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    16,    18,    20,    22,    24,
      26,    28,    30,    32,    37,    44,    45,    51,    52,    58,
      59,    65,    69,    74,    75,    81,    85,    86,    92,    93,
      99,   100,   106,   115,   123,   127,   129,   132,   133,   139,
     140,   143,   145,   147,   149,   150,   154,   162,   163,   167,
     168,   174,   175,   179,   180,   186,   187,   193,   194,   198,
     199,   205,   207,   208,   212,   213,   219,   220,   226,   227,
     233,   238,   242,   244,   247,   248,   254,   263,   267,   268,
     271,   282,   286,   287,   290,   307,   316,   320,   321,   327,
     328,   334,   335,   341,   345,   352,   356,   357,   363,   364,
     365,   371,   372,   378,   379,   385,   389,   391,   394,   398,
     399,   402,   403,   409,   416,   420,   422,   425,   426,   432,
     441,   445,   446,   449,   458,   462,   464,   466,   468,   470,
     472,   478,   482,   484,   486,   488,   492,   493,   499,   510,
     514,   518,   519,   522,   523,   529,   531,   533,   537,   538,
     544,   548,   550,   553,   555,   557,   559,   561,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   593,   594,   597,   604,   608,   614,   615,   621,
     622,   628,   629,   635,   643,   647,   651,   653,   656,   660,
     661,   667,   668,   674,   678,   679,   685,   695,   705,   714,
     723,   735,   745,   757,   775,   785,   797,   807,   815,   825,
     837,   847,   857,   865,   873,   881,   887,   893,   905,   921,
     935
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     185,     0,    -1,   196,    69,   186,   254,    68,    -1,    12,
      11,   187,    -1,     8,    10,    -1,     4,    -1,     4,    -1,
       4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,
       4,    -1,     9,    13,    10,     7,    -1,     9,    13,    10,
       5,    10,     7,    -1,    -1,    15,     6,   198,     4,    14,
      -1,    -1,    17,     6,   200,   194,    16,    -1,    -1,    19,
       6,   202,     4,    18,    -1,    21,   264,    20,    -1,     6,
     272,   263,   265,    -1,    -1,    23,     6,   206,   194,    22,
      -1,    25,   214,    24,    -1,    -1,    27,     6,   209,     4,
      26,    -1,    -1,    29,     6,   211,   195,    28,    -1,    -1,
      31,     6,   213,   191,    30,    -1,     6,   272,   294,   300,
     236,   224,   203,   217,    -1,     6,   272,   294,   300,   236,
     224,   222,    -1,    33,   215,    32,    -1,   216,    -1,   217,
     216,    -1,    -1,    35,     6,   219,   191,    34,    -1,    -1,
     220,   218,    -1,   337,    -1,   355,    -1,   356,    -1,    -1,
      37,   221,    36,    -1,     6,   272,   210,   227,   270,   266,
     268,    -1,    -1,    39,   223,    38,    -1,    -1,    41,     6,
     226,   188,    40,    -1,    -1,    43,   293,    42,    -1,    -1,
      45,     6,   229,   188,    44,    -1,    -1,    47,     6,   231,
       4,    46,    -1,    -1,    49,   309,    48,    -1,    -1,    51,
       6,   234,   189,    50,    -1,   333,    -1,    -1,    53,   235,
      52,    -1,    -1,    55,     6,   238,   189,    54,    -1,    -1,
      57,     6,   240,   189,    56,    -1,    -1,    59,     6,   242,
     191,    58,    -1,     6,   272,   246,   282,    -1,    61,   243,
      60,    -1,   244,    -1,   245,   244,    -1,    -1,    63,     6,
     247,   191,    62,    -1,     6,   272,   294,   300,   236,   224,
     305,   301,    -1,    65,   248,    64,    -1,    -1,   250,   249,
      -1,     6,   272,   294,   300,   236,   224,   212,   313,   287,
     225,    -1,    67,   251,    66,    -1,    -1,   253,   252,    -1,
       6,   272,   294,   300,   236,   224,   197,   207,   245,   257,
     275,   277,   298,   308,   315,   322,    -1,     6,   272,   294,
     300,   236,   224,   305,   301,    -1,    71,   255,    70,    -1,
      -1,    73,     6,   258,     4,    72,    -1,    -1,    75,     6,
     260,     4,    74,    -1,    -1,    77,     6,   262,     4,    76,
      -1,    79,   291,    78,    -1,     6,   272,   294,   300,   236,
     224,    -1,    81,   291,    80,    -1,    -1,    83,     6,   267,
     195,    82,    -1,    -1,    -1,    85,     6,   269,   195,    84,
      -1,    -1,    87,     6,   271,   195,    86,    -1,    -1,    89,
       6,   273,   190,    88,    -1,    91,   309,    90,    -1,   274,
      -1,   275,   274,    -1,    93,   204,    92,    -1,    -1,   277,
     276,    -1,    -1,    95,     6,   279,   193,    94,    -1,     6,
     272,   305,   292,   325,   330,    -1,    97,   280,    96,    -1,
     281,    -1,   282,   281,    -1,    -1,    99,     6,   284,   191,
      98,    -1,     6,   272,   294,   300,   236,   224,   305,   301,
      -1,   101,   285,   100,    -1,    -1,   287,   286,    -1,     6,
     272,   294,   300,   236,   224,   305,   301,    -1,   103,   288,
     102,    -1,   349,    -1,   350,    -1,   351,    -1,   352,    -1,
     353,    -1,     6,   272,   326,   328,   331,    -1,   105,   291,
     104,    -1,   349,    -1,   350,    -1,   351,    -1,   107,   290,
     106,    -1,    -1,   109,     6,   296,   191,   108,    -1,     6,
     272,   294,   300,   236,   224,   210,   222,   261,   324,    -1,
     111,   297,   110,    -1,   113,   290,   112,    -1,    -1,   300,
     299,    -1,    -1,   115,     6,   302,   192,   114,    -1,   333,
      -1,   336,    -1,   117,   303,   116,    -1,    -1,   119,     6,
     306,   191,   118,    -1,   121,   312,   120,    -1,   307,    -1,
     308,   307,    -1,   334,    -1,   335,    -1,   337,    -1,   338,
      -1,   339,    -1,   340,    -1,   341,    -1,   342,    -1,   343,
      -1,   344,    -1,   345,    -1,   346,    -1,   347,    -1,   348,
      -1,   354,    -1,   355,    -1,   356,    -1,   357,    -1,   123,
     309,   122,    -1,    -1,   311,   310,    -1,     6,   272,   210,
     304,   317,   220,    -1,   125,   248,   124,    -1,     6,   272,
     233,   237,   239,    -1,    -1,   127,     6,   316,     4,   126,
      -1,    -1,   129,     6,   318,     4,   128,    -1,    -1,   131,
       6,   320,     4,   130,    -1,     6,   272,   294,   300,   236,
     224,   311,    -1,   133,   321,   132,    -1,   135,   204,   134,
      -1,   323,    -1,   324,   323,    -1,   137,   314,   136,    -1,
      -1,   139,     6,   327,   189,   138,    -1,    -1,   141,     6,
     329,   189,   140,    -1,   143,   314,   142,    -1,    -1,   145,
       6,   332,   189,   144,    -1,   147,     6,   272,   210,   227,
     259,   319,   230,   228,    -1,   148,     6,   272,   294,   300,
     236,   224,   203,   217,    -1,   149,     6,   272,   294,   300,
     236,   224,   222,    -1,   151,     6,   272,   210,   227,   270,
     266,   268,    -1,   152,     6,   272,   294,   300,   236,   224,
     210,   317,   261,   232,    -1,   155,     6,   272,   294,   300,
     236,   224,   305,   301,    -1,   156,     6,   272,   294,   300,
     236,   224,   212,   313,   287,   225,    -1,   157,     6,   272,
     294,   300,   236,   224,   197,   207,   245,   257,   275,   277,
     298,   308,   315,   322,    -1,   158,     6,   272,   294,   300,
     236,   224,   256,   250,    -1,   159,     6,   272,   294,   300,
     236,   224,   256,   253,   241,   205,    -1,   160,     6,   272,
     294,   300,   236,   224,   305,   301,    -1,   161,     6,   272,
     294,   300,   236,   224,    -1,   163,     6,   272,   294,   300,
     236,   224,   305,   301,    -1,   164,     6,   272,   294,   300,
     236,   224,   305,   301,   283,   278,    -1,   165,     6,   272,
     294,   300,   236,   224,   305,   301,    -1,   166,     6,   272,
     294,   300,   236,   224,   289,   287,    -1,   169,     6,   272,
     295,   292,   325,   330,    -1,   170,     6,   272,   295,   292,
     325,   330,    -1,   172,     6,   272,   295,   292,   325,   330,
      -1,   173,     6,   272,   295,   210,    -1,   174,     6,   272,
     295,   210,    -1,   176,     6,   272,   294,   300,   236,   224,
     210,   222,   261,   324,    -1,   179,     6,   272,   294,   300,
     236,   224,   210,   317,   261,   232,   208,   259,   199,   201,
      -1,   180,     6,   272,   294,   300,   236,   224,   210,   317,
     261,   232,   208,   259,    -1,   183,     6,   272,   294,   300,
     236,   224,   311,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   427,   427,   437,   442,   454,   462,   470,   478,   486,
     494,   502,   510,   518,   523,   534,   534,   542,   542,   548,
     548,   557,   562,   568,   568,   574,   580,   580,   589,   589,
     595,   595,   601,   611,   620,   626,   629,   636,   636,   643,
     644,   650,   652,   654,   660,   661,   666,   674,   675,   680,
     680,   686,   687,   692,   692,   697,   697,   706,   707,   712,
     712,   717,   723,   724,   729,   729,   734,   734,   739,   739,
     745,   751,   756,   759,   765,   765,   771,   780,   786,   787,
     793,   802,   808,   809,   815,   829,   838,   843,   843,   852,
     852,   860,   860,   869,   874,   882,   887,   887,   894,   895,
     895,   900,   900,   906,   906,   911,   916,   919,   925,   931,
     932,   939,   939,   945,   951,   956,   959,   966,   966,   972,
     981,   987,   988,   994,  1003,  1008,  1010,  1012,  1014,  1016,
    1021,  1027,  1032,  1034,  1036,  1041,  1046,  1046,  1051,  1062,
    1067,  1074,  1075,  1082,  1082,  1088,  1090,  1095,  1100,  1100,
    1105,  1110,  1113,  1119,  1121,  1123,  1125,  1127,  1129,  1131,
    1133,  1135,  1137,  1139,  1141,  1143,  1145,  1147,  1149,  1151,
    1153,  1158,  1164,  1165,  1172,  1179,  1184,  1190,  1190,  1199,
    1199,  1207,  1207,  1215,  1224,  1229,  1234,  1237,  1243,  1248,
    1248,  1253,  1253,  1258,  1263,  1263,  1268,  1278,  1291,  1303,
    1313,  1327,  1339,  1351,  1368,  1381,  1394,  1406,  1417,  1429,
    1442,  1454,  1466,  1474,  1482,  1491,  1499,  1507,  1521,  1537,
    1552
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
  "ENDEFFECTORHOLDERSEND", "ENDEFFECTORHOLDERSSTART", "ENDEFFECTORNAMEEND",
  "ENDEFFECTORNAMESTART", "ENDEFFECTOREND", "ENDEFFECTORSTART",
  "EXTERNALSHAPEEND", "EXTERNALSHAPESTART", "FINISHEDEND", "FINISHEDSTART",
  "GRASPPOSEEND", "GRASPPOSESTART", "HASTOPEND", "HASTOPSTART",
  "HEIGHTEND", "HEIGHTSTART", "HELDOBJECTEND", "HELDOBJECTSTART", "IEND",
  "ISTART", "INTERNALSHAPEEND", "INTERNALSHAPESTART", "JEND", "JSTART",
  "KEND", "KSTART", "KITDESIGNNAMEEND", "KITDESIGNNAMESTART",
  "KITDESIGNEND", "KITDESIGNSTART", "KITTRAYSKUNAMEEND",
  "KITTRAYSKUNAMESTART", "KITTRAYSEND", "KITTRAYSSTART", "KITEND",
  "KITSTART", "KITTINGWORKSTATIONEND", "KITTINGWORKSTATIONSTART",
  "LARGECONTAINEREND", "LARGECONTAINERSTART", "LENGTHUNITEND",
  "LENGTHUNITSTART", "LENGTHEND", "LENGTHSTART", "MAXIMUMLOADWEIGHTEND",
  "MAXIMUMLOADWEIGHTSTART", "MAXIMUMPOINTEND", "MAXIMUMPOINTSTART",
  "MINIMUMPOINTEND", "MINIMUMPOINTSTART", "MODELFILENAMEEND",
  "MODELFILENAMESTART", "MODELNAMEEND", "MODELNAMESTART",
  "MODELTYPENAMEEND", "MODELTYPENAMESTART", "NAMEEND", "NAMESTART",
  "OBJECTEND", "OBJECTSTART", "OTHEROBSTACLEEND", "OTHEROBSTACLESTART",
  "PARTQUANTITYEND", "PARTQUANTITYSTART", "PARTREFANDPOSEEND",
  "PARTREFANDPOSESTART", "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND",
  "PARTSTART", "PARTSTRAYEND", "PARTSTRAYSTART", "POINTEND", "POINTSTART",
  "PRIMARYLOCATIONEND", "PRIMARYLOCATIONSTART", "REFOBJECTEND",
  "REFOBJECTSTART", "ROBOTEND", "ROBOTSTART", "SECONDARYLOCATIONEND",
  "SECONDARYLOCATIONSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SHAPEEND", "SHAPESTART", "SKUNAMEEND", "SKUNAMESTART", "SKUEND",
  "SKUSTART", "SOLIDOBJECTEND", "SOLIDOBJECTSTART", "TRAYEND", "TRAYSTART",
  "WEIGHTUNITEND", "WEIGHTUNITSTART", "WEIGHTEND", "WEIGHTSTART",
  "WIDTHEND", "WIDTHSTART", "WORKTABLEEND", "WORKTABLESTART",
  "WORKVOLUMEEND", "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND",
  "XSTART", "YEND", "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "BOXVOLUMETYPEDECL", "BOXYSHAPETYPEDECL",
  "ENDEFFECTORCHANGINGSTATIONTYPEDECL", "ENDEFFECTORHOLDERTYPEDECL",
  "ENDEFFECTORTYPEDECL", "EXTERNALSHAPETYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "INTERNALSHAPETYPEDECL", "KITDESIGNTYPEDECL",
  "KITTRAYTYPEDECL", "KITTYPEDECL", "KITTINGWORKSTATIONTYPEDECL",
  "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL", "LARGEBOXWITHKITSTYPEDECL",
  "LARGECONTAINERTYPEDECL", "MECHANICALCOMPONENTTYPEDECL",
  "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL", "PARTSBINTYPEDECL",
  "PARTSTRAYTYPEDECL", "PARTSTRAYWITHPARTSTYPEDECL",
  "PHYSICALLOCATIONTYPEDECL", "POINTTYPEDECL", "POSELOCATIONINTYPEDECL",
  "POSELOCATIONONTYPEDECL", "POSELOCATIONTYPEDECL",
  "POSEONLYLOCATIONTYPEDECL", "RELATIVELOCATIONINTYPEDECL",
  "RELATIVELOCATIONONTYPEDECL", "RELATIVELOCATIONTYPEDECL",
  "ROBOTTYPEDECL", "SHAPEDESIGNTYPEDECL", "STOCKKEEPINGUNITTYPEDECL",
  "VACUUMEFFECTORMULTICUPTYPEDECL", "VACUUMEFFECTORSINGLECUPTYPEDECL",
  "VACUUMEFFECTORTYPEDECL", "VECTORTYPEDECL", "WORKTABLETYPEDECL",
  "$accept", "y_KittingWorkstationFile",
  "y_XmlHeaderForKittingWorkstation", "y_SchemaLocation", "y_XmlBoolean",
  "y_XmlDecimal", "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN",
  "y_XmlNonNegativeInteger", "y_XmlPositiveInteger", "y_XmlString",
  "y_XmlVersion", "y_AngleUnit_AngleUnitType", "$@1",
  "y_ArrayNumber_XmlPositiveInteger", "$@2",
  "y_ArrayRadius_PositiveDecimalType", "$@3",
  "y_Base_MechanicalComponentType", "y_BoxVolumeType",
  "y_Capacity_XmlPositiveInteger", "$@4",
  "y_ChangingStation_EndEffectorChangingStationType",
  "y_CupDiameter_PositiveDecimalType", "$@5", "y_Description_XmlString",
  "$@6", "y_DesignName_XmlIDREF", "$@7",
  "y_EndEffectorChangingStationType", "y_EndEffectorHolderType",
  "y_EndEffectorHolders_EndEffectorHolderType_u",
  "y_EndEffectorHolders_EndEffectorHolderType_uList",
  "y_EndEffectorName_XmlIDREF_0_u", "$@8",
  "y_EndEffectorName_XmlIDREF_0_uList", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType_0", "y_ExternalShapeType",
  "y_ExternalShape_ExternalShapeType_0", "y_Finished_XmlBoolean", "$@9",
  "y_GraspPose_PoseLocationType_0", "y_HasTop_XmlBoolean", "$@10",
  "y_Height_PositiveDecimalType", "$@11", "y_HeldObject_SolidObjectType_0",
  "y_I_XmlDecimal", "$@12", "y_InternalShapeTypeAny",
  "y_InternalShape_InternalShapeType_0", "y_J_XmlDecimal", "$@13",
  "y_K_XmlDecimal", "$@14", "y_KitDesignName_XmlIDREF", "$@15",
  "y_KitDesignType", "y_KitDesign_KitDesignType_u",
  "y_KitDesign_KitDesignType_uList", "y_KitTraySkuName_XmlIDREF", "$@16",
  "y_KitTrayType", "y_KitTrays_KitTrayType_0_u",
  "y_KitTrays_KitTrayType_0_uList", "y_KitType", "y_Kit_KitType_0_u",
  "y_Kit_KitType_0_uList", "y_KittingWorkstationType",
  "y_LargeContainerType", "y_LargeContainer_LargeContainerType",
  "y_LengthUnit_LengthUnitType", "$@17", "y_Length_PositiveDecimalType",
  "$@18", "y_MaximumLoadWeight_PositiveDecimalType", "$@19",
  "y_MaximumPoint_PointType", "y_MechanicalComponentType",
  "y_MinimumPoint_PointType", "y_ModelFileName_XmlString", "$@20",
  "y_ModelName_XmlString_0", "$@21", "y_ModelTypeName_XmlString", "$@22",
  "y_Name_XmlID", "$@23", "y_Object_SolidObjectType_u",
  "y_Object_SolidObjectType_uList", "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList",
  "y_PartQuantity_XmlNonNegativeInteger", "$@24", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuName_XmlIDREF",
  "$@25", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PartsTrayType", "y_PartsTray_PartsTrayType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PoseLocationTypeAny", "y_PrimaryLocation_PhysicalLocationType",
  "y_RefObject_XmlIDREF", "$@26", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@27", "y_ShapeDesignTypeAny",
  "y_Shape_ShapeDesignType", "y_SkuName_XmlIDREF", "$@28",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SolidObjectTypeAny", "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Tray_KitTrayType", "y_VectorType", "y_WeightUnit_WeightUnitType",
  "$@29", "y_Weight_PositiveDecimalType", "$@30",
  "y_Width_PositiveDecimalType", "$@31", "y_WorkTableType",
  "y_WorkTable_WorkTableType", "y_WorkVolume_BoxVolumeType_u",
  "y_WorkVolume_BoxVolumeType_uList", "y_XAxis_VectorType",
  "y_X_XmlDecimal", "$@32", "y_Y_XmlDecimal", "$@33", "y_ZAxis_VectorType",
  "y_Z_XmlDecimal", "$@34", "y_x_BoxyShapeType",
  "y_x_EndEffectorChangingStationType", "y_x_EndEffectorHolderType",
  "y_x_ExternalShapeType", "y_x_GripperEffectorType", "y_x_KitTrayType",
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
     435,   436,   437,   438
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   196,   198,   197,   200,   199,   202,
     201,   203,   204,   206,   205,   207,   209,   208,   211,   210,
     213,   212,   214,   215,   216,   217,   217,   219,   218,   220,
     220,   221,   221,   221,   222,   222,   223,   224,   224,   226,
     225,   227,   227,   229,   228,   231,   230,   232,   232,   234,
     233,   235,   236,   236,   238,   237,   240,   239,   242,   241,
     243,   244,   245,   245,   247,   246,   248,   249,   250,   250,
     251,   252,   253,   253,   254,   255,   256,   258,   257,   260,
     259,   262,   261,   263,   264,   265,   267,   266,   268,   269,
     268,   271,   270,   273,   272,   274,   275,   275,   276,   277,
     277,   279,   278,   280,   281,   282,   282,   284,   283,   285,
     286,   287,   287,   288,   289,   290,   290,   290,   290,   290,
     291,   292,   293,   293,   293,   294,   296,   295,   297,   298,
     299,   300,   300,   302,   301,   303,   303,   304,   306,   305,
     307,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   310,   311,   311,   312,   313,   314,   316,   315,   318,
     317,   320,   319,   321,   322,   323,   324,   324,   325,   327,
     326,   329,   328,   330,   332,   331,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     0,     5,     0,     5,     0,
       5,     3,     4,     0,     5,     3,     0,     5,     0,     5,
       0,     5,     8,     7,     3,     1,     2,     0,     5,     0,
       2,     1,     1,     1,     0,     3,     7,     0,     3,     0,
       5,     0,     3,     0,     5,     0,     5,     0,     3,     0,
       5,     1,     0,     3,     0,     5,     0,     5,     0,     5,
       4,     3,     1,     2,     0,     5,     8,     3,     0,     2,
      10,     3,     0,     2,    16,     8,     3,     0,     5,     0,
       5,     0,     5,     3,     6,     3,     0,     5,     0,     0,
       5,     0,     5,     0,     5,     3,     1,     2,     3,     0,
       2,     0,     5,     6,     3,     1,     2,     0,     5,     8,
       3,     0,     2,     8,     3,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     1,     3,     0,     5,    10,     3,
       3,     0,     2,     0,     5,     1,     1,     3,     0,     5,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     2,     6,     3,     5,     0,     5,     0,
       5,     0,     5,     7,     3,     3,     1,     2,     3,     0,
       5,     0,     5,     3,     0,     5,     9,     9,     8,     8,
      11,     9,    11,    17,     9,    11,     9,     7,     9,    11,
       9,     9,     7,     7,     7,     5,     5,    11,    15,    13,
       8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    14,     4,   103,     0,   141,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,    62,     7,
       0,     0,     0,     0,     0,     0,   135,     0,     0,    47,
     142,   104,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,   140,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,   215,   216,     0,     0,    48,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    51,    51,
       0,     0,     0,     0,    72,     0,     8,     0,     0,   131,
       0,     0,     0,   212,   213,   214,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,    73,     0,   137,     0,
       0,     0,   188,     0,    12,     0,     0,   132,   133,   134,
       0,     0,     0,     0,    16,   141,     0,    71,    87,     0,
     106,   109,   189,     0,     0,     0,     0,   193,    29,    52,
      89,     0,     0,   101,     0,    98,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   107,     0,     0,
     191,     0,   130,    59,     0,     0,     0,   181,     0,     0,
       0,    96,     0,    46,    47,    74,     0,   115,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,   110,     0,     6,     0,     0,   194,     0,    64,     0,
     176,     0,     0,    55,     0,   196,     0,     0,    99,     0,
       0,     0,     0,   116,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,     0,
     190,     0,     0,     0,     0,    66,    90,     0,     0,    53,
     102,     0,     0,     0,     0,     0,     0,   114,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,     0,   108,     0,   139,
       0,     0,     0,   152,     0,   192,     0,    60,     0,     0,
     182,     0,     0,    97,     0,     0,     0,     0,    35,    32,
      75,     0,     0,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,     0,     0,   141,     0,   150,   177,     0,    84,   195,
      65,     0,    56,     5,     0,   100,     0,    21,     0,     0,
      36,   148,     0,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,     0,     0,    22,    62,     0,     0,     0,     0,    67,
      54,   141,     0,    34,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
       0,     0,     0,   172,    93,     0,    47,     0,     0,     0,
       0,   184,    62,   141,     0,   113,     0,     0,   198,     0,
       0,     0,     0,     0,     0,    78,    82,     0,     0,     0,
       0,     0,   121,    44,     0,     0,   220,    95,     0,     0,
       0,   145,   146,     0,    39,   178,   141,    47,    62,   149,
     197,     0,    41,    42,    43,     0,     0,   201,    30,     0,
     121,     0,     0,     0,   204,     0,   206,   208,     0,   210,
       0,     0,   211,     0,     0,     0,     0,   173,    44,     0,
     147,   179,   174,    62,    94,    47,    45,     0,    57,   143,
       0,     0,     0,     0,     0,     0,    86,     0,    79,     0,
       0,     0,    83,     0,     0,     0,   124,     0,   122,     0,
      57,    57,     0,     0,     0,     0,     0,    40,    47,    44,
      91,     0,   200,     0,     0,     0,   175,     0,   202,     0,
     141,     0,    68,     0,     0,     0,   205,   117,     0,   209,
     141,     0,     0,     0,   186,   217,     0,     0,   171,     0,
      51,     0,    37,   172,    33,     0,     0,     9,     0,    31,
     141,    49,   109,    62,    77,     0,     0,    81,    23,     0,
     111,    62,     0,   120,     0,   187,     0,     0,     0,   138,
       0,   180,     0,   183,     0,    58,   144,    62,     0,     0,
      47,     0,   141,     0,     0,     0,    47,   141,   185,    26,
       0,   219,     0,     0,    92,    47,     0,     0,     0,    69,
      62,    11,     0,   118,    10,     0,     0,    62,     0,     0,
       0,    98,    38,     0,    50,     0,     0,    47,    24,   112,
       0,    47,     0,    17,     0,   218,   199,     0,     0,    85,
       0,   123,     0,    27,     0,    19,    76,   203,     0,     0,
       0,     0,   121,   119,    18,     0,     0,    20,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   394,   254,    40,   107,   608,   665,
     662,   135,     3,    75,   100,   670,   694,   685,   701,   314,
     294,   586,   643,    89,   627,   668,    82,   116,   472,   540,
     102,   399,   358,   359,   567,   632,   532,   501,   468,    73,
      62,   578,   638,   118,   265,   352,   219,   308,   572,   156,
     257,    58,    49,   215,   304,   260,   349,   551,   615,   124,
     104,   105,   168,   270,   542,   548,   514,   584,   552,   515,
      14,   513,   475,   127,   169,   141,   216,   538,   605,   382,
     356,   423,   165,   267,   223,   312,   143,   220,    19,    26,
     150,   151,   251,   208,   589,   645,   272,   227,   228,   554,
     619,   592,   558,   522,   521,   482,    32,    92,    78,   136,
      25,    64,    90,   296,   252,    50,    38,   507,   573,   490,
     458,   362,   434,   298,   299,   188,   527,   486,   341,   510,
     111,   344,   426,   494,   565,   162,   262,   428,   388,   594,
     595,    94,   130,   209,   154,   255,   113,   212,   302,    59,
     189,   190,   492,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    33,    34,    35,    36,    37,
     203,   204,   205,   206
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -560
static const yytype_int16 yypact[] =
{
      39,    48,    78,     3,    74,  -560,    76,    66,    89,   102,
     100,  -560,   103,    24,    47,   109,   119,  -560,   124,    25,
    -560,  -560,  -560,  -560,   -50,  -560,   127,   128,   129,   130,
     131,   132,    27,  -560,  -560,  -560,  -560,  -560,   -30,  -560,
      51,    24,    24,    24,    24,    24,  -560,    -7,   -50,   104,
    -560,  -560,    32,    32,    32,    32,    32,   136,    92,  -560,
      33,   140,   133,   141,    44,    44,    44,   121,   121,    24,
    -560,  -560,    24,   115,   148,   134,  -560,   149,    19,    19,
      19,   151,  -560,  -560,   121,   121,  -560,  -560,   152,    99,
     157,    24,    58,   158,    20,    20,    20,  -560,   142,   142,
     180,    24,   162,   181,  -560,    -5,  -560,    80,    68,  -560,
      24,    73,   158,  -560,  -560,  -560,   225,  -137,   174,   163,
     239,    25,  -560,    24,   196,   252,  -560,   168,  -560,   254,
     120,   212,  -560,   122,  -560,   238,   226,  -560,  -560,  -560,
     261,   138,   264,   188,  -560,  -560,   210,  -560,  -560,   -62,
    -560,   168,  -560,   270,   135,   271,   223,  -560,  -560,  -560,
    -560,   273,   234,  -560,   276,   198,   -30,   278,   190,   281,
     282,   284,   287,   288,   289,   290,   291,   292,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   220,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   -49,   308,
    -560,   307,  -560,  -560,   309,   259,   313,  -560,   312,   274,
     225,  -560,   314,  -560,   104,  -560,   315,  -560,   190,   253,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,  -560,   320,
     321,  -560,   207,  -560,   191,   308,  -560,   308,  -560,   345,
    -560,   279,   350,  -560,   352,  -560,   275,   225,  -560,   335,
     157,    24,   263,  -560,  -560,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    24,   268,    24,   255,   356,  -560,   -47,
    -560,   227,   308,   319,   308,  -560,  -560,   233,   366,  -560,
    -560,   293,   225,   365,   339,   311,   257,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,   304,  -560,    25,  -560,
      24,   260,   368,  -560,   244,  -560,   235,  -560,   328,   308,
    -560,   341,   385,  -560,   310,    24,   373,   389,  -560,   339,
    -560,   390,    44,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   149,   316,  -560,   121,  -560,  -560,   392,  -560,  -560,
    -560,   343,  -560,  -560,   358,  -560,    25,  -560,    24,   371,
    -560,  -560,    19,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   322,   149,  -560,   -30,   305,   400,    24,   277,  -560,
    -560,  -560,    25,  -560,   157,    20,   335,   369,   121,   257,
     374,   133,   336,   336,   257,  -560,   257,   257,   257,   317,
     121,   121,   121,  -560,  -560,   330,   104,   -66,   283,   285,
      25,  -560,   -30,  -560,   306,  -560,   339,  -103,  -560,   283,
     318,   402,   323,   134,   407,  -560,  -560,   318,   318,   318,
     318,   408,  -560,   369,   283,   283,   324,  -560,   121,   409,
     325,  -560,  -560,   410,  -560,  -560,  -560,   104,   -30,  -560,
     339,   381,  -560,  -560,  -560,   342,   412,  -560,  -560,   415,
    -560,    99,    24,   353,   361,    -8,  -560,  -560,   331,  -560,
      24,   327,   326,   342,   342,   342,   -62,  -560,   369,    24,
    -560,  -560,   396,   -30,  -560,   104,  -560,   426,   387,  -560,
     157,    24,   329,   -12,    -5,    25,  -560,   415,  -560,   428,
     431,   416,  -560,   432,   347,    25,  -560,   434,  -560,   332,
     387,   387,   333,   342,   121,   439,   438,  -560,   104,   369,
    -560,   -62,  -560,   445,   420,    25,  -560,   446,  -560,   168,
    -560,   393,  -560,    24,   388,   450,  -560,  -560,   452,  -560,
    -560,    24,   351,   320,  -560,   332,   433,   433,  -560,   332,
     142,   334,  -560,  -560,  -560,   455,   413,  -560,   354,  -560,
    -560,  -560,   168,   -30,  -560,   157,    25,  -560,  -560,   157,
    -560,   -30,    25,  -560,   340,  -560,   458,   174,   174,   332,
     163,  -560,   157,   324,   394,  -560,  -560,   -30,   385,   -49,
     104,   411,  -560,   469,   377,   472,   104,  -560,  -560,  -560,
     460,  -560,   188,   444,  -560,   104,   440,   207,   257,  -560,
     -30,  -560,   461,  -560,  -560,   391,   257,   -30,   480,   481,
     467,   198,  -560,   257,  -560,   -47,   318,   104,  -560,  -560,
     318,   104,   464,  -560,   485,  -560,  -560,   318,   244,  -560,
     374,  -560,   257,  -560,   469,  -560,  -560,  -560,   323,   318,
     476,   489,  -560,  -560,  -560,   477,   -12,  -560,  -560
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -560,  -560,  -560,  -560,  -144,  -237,  -560,  -251,  -560,  -560,
    -197,  -203,  -560,    57,  -560,  -560,  -560,  -560,  -560,    63,
     -92,  -560,  -560,    30,   -89,  -560,   -60,  -560,  -181,  -560,
    -560,  -560,  -349,    45,  -560,  -560,  -560,  -560,  -462,  -560,
     -72,  -196,  -560,   -93,  -560,  -560,  -560,  -560,  -469,  -560,
    -560,  -560,  -132,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     -98,     2,  -560,  -560,   -33,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,    75,   -29,  -560,  -522,  -560,  -484,  -560,  -560,
    -560,  -560,  -136,  -560,  -154,  -560,  -111,  -560,   -41,  -560,
    -146,   -59,  -560,   -91,  -560,  -560,  -560,   337,  -560,  -560,
    -560,  -560,  -560,  -494,  -560,  -560,   474,  -359,   -51,  -560,
    -110,    72,  -560,  -560,  -116,  -560,  -108,  -425,  -560,  -560,
    -560,  -401,  -560,  -290,  -133,  -496,  -560,   -78,  -560,  -172,
     417,  -148,  -560,  -427,  -560,  -560,  -560,  -560,  -158,  -559,
     -68,   -53,  -560,  -560,  -560,  -560,   -83,  -560,  -560,    79,
    -560,  -560,  -560,    65,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   421,   423,   424,  -560,  -560,
    -560,    70,    77,  -560
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      52,    53,    54,    55,    56,   207,   119,   126,    83,   343,
     400,   145,   114,   115,    79,    80,   543,   266,   301,   315,
     303,   523,   421,    47,    98,    99,    95,    96,    84,   577,
     562,    85,    27,    28,   224,    29,   625,   166,   470,   559,
     560,   561,   505,   477,   249,   478,   479,   480,     1,   172,
     108,   549,   516,   517,   518,   519,   103,   524,   525,   550,
     121,     4,   250,   455,   311,   346,   563,   348,   125,   131,
     625,    10,     6,    11,   297,   606,   185,   186,     5,   599,
     342,    57,   146,    48,     7,   489,   170,   171,     8,   557,
     172,   596,   597,   173,   174,   175,   176,   177,   178,   179,
      12,   180,   181,   182,   183,   650,   651,   604,    13,   354,
      15,    16,   391,    18,   184,    20,    21,   185,   186,    27,
      28,   187,    29,    30,    31,    65,    66,    67,    68,    22,
      23,    39,    24,    46,    41,    42,    43,    44,    45,    51,
      57,    63,    69,    61,    70,    71,    72,    76,    74,    77,
      81,   400,   269,    86,    87,    91,    93,    97,   101,    88,
     103,   106,   109,   112,   110,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   464,   120,   117,   122,   123,   128,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   129,   706,   132,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   383,   134,
     316,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   140,
     142,   689,   336,   144,   338,   691,   147,   676,   148,   149,
     152,   153,   696,   155,   157,   680,   158,   160,   159,   161,
     163,   164,   687,   167,   703,   424,   210,   213,   214,   217,
     211,   218,   221,   222,   225,   229,   431,   226,   230,   574,
     231,   699,   456,   232,   233,   234,   235,   236,   237,   384,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   402,   253,   256,   396,   258,   259,   261,   263,   264,
     268,   271,   463,   462,   425,   274,   293,   295,   297,   300,
     497,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   435,
     496,   305,   465,   306,   307,   498,   313,   432,   309,   317,
     337,   310,   340,   350,   641,   339,   535,   345,   644,   347,
     351,   355,   357,   360,   386,   353,   361,   387,   469,   389,
     385,   653,   390,   381,   488,   343,   460,   392,   533,   393,
     483,   484,   485,   397,   395,   398,   401,   422,   427,   429,
     454,   568,   430,   433,   459,   471,   467,   474,   508,   461,
     487,   495,   493,   512,   520,   529,   531,   536,   539,   537,
     481,   541,   457,   546,   499,   534,   547,   557,   528,   556,
     553,   566,   570,   506,   582,   580,   571,   583,   587,   585,
     591,   530,   588,   601,   602,   590,   126,   526,   509,   607,
     609,   623,   611,   576,   617,   598,   618,   614,   620,   634,
     626,   635,   631,   569,   649,   610,   207,   593,   636,   659,
     654,   545,   613,   661,   648,   663,   664,   669,   672,   555,
     674,   640,   621,   678,   682,   679,   684,   683,   564,   646,
     693,   695,   704,   705,   656,   707,   603,   700,   473,   466,
     575,   624,   637,   511,   600,   655,   642,   630,   628,   698,
     708,   500,   647,   544,   581,   579,   671,   686,   476,   652,
     612,   639,    60,   657,   675,   633,   702,   688,   677,   133,
     697,   629,   502,     0,   660,   681,   491,   503,   137,   667,
     138,   139,   616,     0,   504,     0,     0,     0,     0,     0,
     622,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,     0,   658,     0,
       0,     0,     0,     0,   666,     0,     0,     0,     0,     0,
       0,     0,     0,   673,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   690,     0,     0,     0,   692
};

static const yytype_int16 yycheck[] =
{
      41,    42,    43,    44,    45,   151,    99,   105,    68,   299,
     359,   121,    95,    96,    65,    66,   510,   220,   255,   270,
     257,   483,   381,    53,    84,    85,    79,    80,    69,    41,
     526,    72,   169,   170,   166,   172,   595,   145,   439,   523,
     524,   525,   469,   444,    93,   446,   447,   448,     9,   152,
      91,    59,   477,   478,   479,   480,    61,   484,   485,    67,
     101,    13,   111,   422,   267,   302,   528,   304,    73,   110,
     629,     5,    69,     7,   121,   571,   179,   180,     0,   563,
     127,   147,   123,   113,    10,   151,   148,   149,    12,   101,
     152,   560,   561,   155,   156,   157,   158,   159,   160,   161,
      11,   163,   164,   165,   166,   627,   628,   569,     6,   312,
      10,     8,   349,    89,   176,    68,     7,   179,   180,   169,
     170,   183,   172,   173,   174,    53,    54,    55,    56,    10,
       6,     4,   107,   106,     6,     6,     6,     6,     6,    88,
     147,   109,     6,    39,    52,   112,     6,     6,    15,   105,
      29,   500,   224,    38,     6,     6,   137,     6,     6,    25,
      61,     4,   104,   143,     6,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   434,     4,    43,    24,     6,   108,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   139,   702,   136,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   338,     4,
     271,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,    75,
      87,   676,   293,    14,   295,   680,    60,   658,     6,    91,
       6,   141,   687,    51,   142,   666,    28,     6,    42,   131,
       6,    83,   673,    63,   699,   383,     6,     6,    55,     6,
     145,    47,     6,    85,     6,     4,   396,    97,     6,   540,
       6,   692,   424,     6,     6,     6,     6,     6,     6,   340,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
      90,   362,     4,     6,   355,     6,    57,     4,     6,    45,
       6,     6,   432,   431,   384,    72,     6,     6,   121,   138,
     462,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   402,
     460,     6,   435,    74,     4,   463,    21,   398,     6,    96,
      92,    86,     6,   130,   615,   110,   498,   140,   619,    50,
       4,     6,    33,    62,     6,    82,   119,   133,   438,   144,
     120,   632,    54,    79,   456,   675,   427,    46,   496,     4,
     450,   451,   452,    20,    84,     6,     6,    81,     6,    56,
      78,   533,    44,    32,     4,    31,    37,    71,     6,   132,
      80,   126,   129,     6,     6,     6,     6,    36,     6,    77,
     103,     6,   117,    70,   118,   497,    65,   101,   488,   102,
      99,    35,     6,   115,     6,   545,    49,     6,     6,    23,
       6,   116,    95,     4,     6,   555,   544,   123,   125,     4,
      30,   100,     6,   124,    66,   122,     6,    64,     6,     4,
      27,    48,   128,   535,     6,   575,   612,   135,   114,    58,
      76,   512,   580,     4,   134,    98,     4,    17,    34,   520,
      40,   613,   590,    22,     4,    94,    19,     6,   529,   621,
      26,     6,    16,     4,   638,    18,   568,   694,   441,   436,
     541,   593,   610,   473,   564,   637,   616,   600,   597,   690,
     706,   466,   622,   511,   547,   544,   652,   671,   443,   630,
     579,   612,    48,   639,   657,   603,   698,   675,   660,   112,
     688,   599,   467,    -1,   642,   667,   457,   467,   117,   647,
     117,   117,   583,    -1,   467,    -1,    -1,    -1,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   640,    -1,
      -1,    -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   655,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,    -1,   681
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   185,   196,    13,     0,    69,    10,    12,   186,
       5,     7,    11,     6,   254,    10,     8,   187,    89,   272,
      68,     7,    10,     6,   107,   294,   273,   169,   170,   172,
     173,   174,   290,   349,   350,   351,   352,   353,   300,     4,
     190,     6,     6,     6,     6,     6,   106,    53,   113,   236,
     299,    88,   272,   272,   272,   272,   272,   147,   235,   333,
     290,    39,   224,   109,   295,   295,   295,   295,   295,     6,
      52,   112,     6,   223,    15,   197,     6,   105,   292,   292,
     292,    29,   210,   210,   272,   272,    38,     6,    25,   207,
     296,     6,   291,   137,   325,   325,   325,     6,   210,   210,
     198,     6,   214,    61,   244,   245,     4,   191,   272,   104,
       6,   314,   143,   330,   330,   330,   211,    43,   227,   227,
       4,   272,    24,     6,   243,    73,   244,   257,   108,   139,
     326,   272,   136,   314,     4,   195,   293,   349,   350,   351,
      75,   259,    87,   270,    14,   294,   272,    60,     6,    91,
     274,   275,     6,   141,   328,    51,   233,   142,    28,    42,
       6,   131,   319,     6,    83,   266,   300,    63,   246,   258,
     148,   149,   152,   155,   156,   157,   158,   159,   160,   161,
     163,   164,   165,   166,   176,   179,   180,   183,   309,   334,
     335,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   354,   355,   356,   357,   274,   277,   327,
       6,   145,   331,     6,    55,   237,   260,     6,    47,   230,
     271,     6,    85,   268,   236,     6,    97,   281,   282,     4,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,    90,    93,
     111,   276,   298,     4,   189,   329,     6,   234,     6,    57,
     239,     4,   320,     6,    45,   228,   195,   267,     6,   224,
     247,     6,   280,   281,    72,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,     6,   204,     6,   297,   121,   307,   308,
     138,   189,   332,   189,   238,     6,    74,     4,   231,     6,
      86,   195,   269,    21,   203,   191,   272,    96,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   272,    92,   272,   110,
       6,   312,   127,   307,   315,   140,   189,    50,   189,   240,
     130,     4,   229,    82,   195,     6,   264,    33,   216,   217,
      62,   119,   305,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,    79,   263,   294,   272,   120,     6,   133,   322,   144,
      54,   189,    46,     4,   188,    84,   272,    20,     6,   215,
     216,     6,   292,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   291,    81,   265,   300,   210,   316,     6,   321,    56,
      44,   294,   272,    32,   306,   325,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,    78,   291,   236,   117,   304,     4,
     272,   132,   300,   294,   191,   330,   203,    37,   222,   210,
     305,    31,   212,   197,    71,   256,   256,   305,   305,   305,
     305,   103,   289,   210,   210,   210,   311,    80,   224,   151,
     303,   333,   336,   129,   317,   126,   294,   236,   300,   118,
     217,   221,   337,   355,   356,   317,   115,   301,     6,   125,
     313,   207,     6,   255,   250,   253,   301,   301,   301,   301,
       6,   288,   287,   222,   317,   317,   123,   310,   210,     6,
     116,     6,   220,   300,   224,   236,    36,    77,   261,     6,
     213,     6,   248,   287,   245,   272,    70,    65,   249,    59,
      67,   241,   252,    99,   283,   272,   102,   101,   286,   261,
     261,   261,   309,   222,   272,   318,    35,   218,   236,   224,
       6,    49,   232,   302,   191,   272,   124,    41,   225,   257,
     294,   248,     6,     6,   251,    23,   205,     6,    95,   278,
     294,     6,   285,   135,   323,   324,   232,   232,   122,   261,
     210,     4,     6,   224,   222,   262,   309,     4,   192,    30,
     294,     6,   275,   300,    64,   242,   272,    66,     6,   284,
       6,   300,   272,   100,   204,   323,    27,   208,   208,   324,
     227,   128,   219,   311,     4,    48,   114,   300,   226,   277,
     236,   191,   294,   206,   191,   279,   236,   294,   134,     6,
     259,   259,   270,   191,    76,   236,   188,   298,   224,    58,
     300,     4,   194,    98,     4,   193,   224,   300,   209,    17,
     199,   266,    34,   224,    40,   308,   305,   236,    22,    94,
     305,   236,     4,     6,    19,   201,   268,   305,   315,   301,
     224,   301,   224,    26,   200,     6,   301,   322,   212,   305,
     194,   202,   313,   301,    16,     4,   287,    18,   225
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

    {(yyval.XmlHeaderForKittingWorkstationVal) = new XmlHeaderForKittingWorkstation((yyvsp[(3) - (3)].SchemaLocationVal));;}
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

    {(yyval.MechanicalComponentTypeVal) = (yyvsp[(2) - (3)].MechanicalComponentTypeVal);;}
    break;

  case 22:

    {(yyval.BoxVolumeTypeVal) = new BoxVolumeType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].PointTypeVal), (yyvsp[(4) - (4)].PointTypeVal));;}
    break;

  case 23:

    {yyReadData = 1;;}
    break;

  case 24:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 25:

    {(yyval.EndEffectorChangingStationTypeVal) = (yyvsp[(2) - (3)].EndEffectorChangingStationTypeVal);;}
    break;

  case 26:

    {yyReadData = 1;;}
    break;

  case 27:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad CupDiameter value");
	  ;}
    break;

  case 28:

    {yyReadData = 1;;}
    break;

  case 29:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 30:

    {yyReadData = 1;;}
    break;

  case 31:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 32:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].MechanicalComponentTypeVal), (yyvsp[(8) - (8)].EndEffectorHolderTypeListVal));;}
    break;

  case 33:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].PhysicalLocationTypeListVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].EndEffectorTypeVal));;}
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

    {(yyval.EndEffectorTypeVal) = 0;;}
    break;

  case 45:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 46:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].PoseLocationTypeVal), (yyvsp[(5) - (7)].XmlStringVal), (yyvsp[(6) - (7)].XmlStringVal), (yyvsp[(7) - (7)].XmlStringVal));;}
    break;

  case 47:

    {(yyval.ExternalShapeTypeVal) = 0;;}
    break;

  case 48:

    {(yyval.ExternalShapeTypeVal) = (yyvsp[(2) - (3)].ExternalShapeTypeVal);;}
    break;

  case 49:

    {yyReadData = 1;;}
    break;

  case 50:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 51:

    {(yyval.PoseLocationTypeVal) = 0;;}
    break;

  case 52:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(2) - (3)].PoseLocationTypeVal);;}
    break;

  case 53:

    {yyReadData = 1;;}
    break;

  case 54:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 55:

    {yyReadData = 1;;}
    break;

  case 56:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 57:

    {(yyval.SolidObjectTypeVal) = 0;;}
    break;

  case 58:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 59:

    {yyReadData = 1;;}
    break;

  case 60:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 61:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 62:

    {(yyval.InternalShapeTypeVal) = 0;;}
    break;

  case 63:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(2) - (3)].InternalShapeTypeVal);;}
    break;

  case 64:

    {yyReadData = 1;;}
    break;

  case 65:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 66:

    {yyReadData = 1;;}
    break;

  case 67:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 68:

    {yyReadData = 1;;}
    break;

  case 69:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 70:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].PartRefAndPoseTypeListVal));;}
    break;

  case 71:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 72:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 73:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 74:

    {yyReadData = 1;;}
    break;

  case 75:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 76:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 77:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 78:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 79:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 80:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlIDREFVal), (yyvsp[(8) - (10)].KitTrayTypeVal), (yyvsp[(9) - (10)].PartTypeListVal), (yyvsp[(10) - (10)].XmlBooleanVal));;}
    break;

  case 81:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 82:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 83:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 84:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (16)].XmlIDVal), (yyvsp[(3) - (16)].PhysicalLocationTypeVal), (yyvsp[(4) - (16)].PhysicalLocationTypeListVal), (yyvsp[(5) - (16)].InternalShapeTypeVal), (yyvsp[(6) - (16)].ExternalShapeTypeVal), (yyvsp[(7) - (16)].AngleUnitTypeVal), (yyvsp[(8) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(9) - (16)].KitDesignTypeListVal), (yyvsp[(10) - (16)].LengthUnitTypeVal), (yyvsp[(11) - (16)].SolidObjectTypeListVal), (yyvsp[(12) - (16)].BoxVolumeTypeListVal), (yyvsp[(13) - (16)].RobotTypeVal), (yyvsp[(14) - (16)].StockKeepingUnitTypeListVal), (yyvsp[(15) - (16)].WeightUnitTypeVal), (yyvsp[(16) - (16)].WorkTableTypeVal));;}
    break;

  case 85:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 86:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 87:

    {yyReadData = 1;;}
    break;

  case 88:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 89:

    {yyReadData = 1;;}
    break;

  case 90:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 91:

    {yyReadData = 1;;}
    break;

  case 92:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 93:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 94:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));;}
    break;

  case 95:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 96:

    {yyReadData = 1;;}
    break;

  case 97:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 98:

    {(yyval.XmlStringVal) = 0;;}
    break;

  case 99:

    {yyReadData = 1;;}
    break;

  case 100:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 101:

    {yyReadData = 1;;}
    break;

  case 102:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 103:

    {yyReadData = 1;;}
    break;

  case 104:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 105:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 106:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 107:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 108:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 109:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 110:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 111:

    {yyReadData = 1;;}
    break;

  case 112:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 113:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 114:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 115:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 116:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 117:

    {yyReadData = 1;;}
    break;

  case 118:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 119:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 120:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 121:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 122:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 123:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 124:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 125:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 126:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 127:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 128:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 129:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 130:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 131:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 132:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 133:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 134:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 135:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 136:

    {yyReadData = 1;;}
    break;

  case 137:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 138:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].BoxVolumeTypeListVal));;}
    break;

  case 139:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 140:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 141:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 142:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 143:

    {yyReadData = 1;;}
    break;

  case 144:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 145:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 146:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].ExternalShapeTypeVal);;}
    break;

  case 147:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 148:

    {yyReadData = 1;;}
    break;

  case 149:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 150:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 151:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 152:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 153:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 154:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 155:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 156:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 157:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 158:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 159:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 160:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 161:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 162:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);;}
    break;

  case 163:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 164:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 165:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 166:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 167:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 168:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 169:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 170:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 171:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 172:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 173:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 174:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 175:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 176:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 177:

    {yyReadData = 1;;}
    break;

  case 178:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 179:

    {yyReadData = 1;;}
    break;

  case 180:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 181:

    {yyReadData = 1;;}
    break;

  case 182:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 183:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].PhysicalLocationTypeListVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].SolidObjectTypeListVal));;}
    break;

  case 184:

    {(yyval.WorkTableTypeVal) = (yyvsp[(2) - (3)].WorkTableTypeVal);;}
    break;

  case 185:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 186:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 187:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 188:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 189:

    {yyReadData = 1;;}
    break;

  case 190:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 191:

    {yyReadData = 1;;}
    break;

  case 192:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 193:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 194:

    {yyReadData = 1;;}
    break;

  case 195:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 196:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlStringVal), (yyvsp[(5) - (9)].PoseLocationTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 197:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 198:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 199:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].XmlStringVal), (yyvsp[(8) - (8)].XmlStringVal));
	   (yyval.ExternalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 200:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 201:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 202:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlIDREFVal), (yyvsp[(9) - (11)].KitTrayTypeVal), (yyvsp[(10) - (11)].PartTypeListVal), (yyvsp[(11) - (11)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 203:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (17)].XmlIDVal), (yyvsp[(4) - (17)].PhysicalLocationTypeVal), (yyvsp[(5) - (17)].PhysicalLocationTypeListVal), (yyvsp[(6) - (17)].InternalShapeTypeVal), (yyvsp[(7) - (17)].ExternalShapeTypeVal), (yyvsp[(8) - (17)].AngleUnitTypeVal), (yyvsp[(9) - (17)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (17)].KitDesignTypeListVal), (yyvsp[(11) - (17)].LengthUnitTypeVal), (yyvsp[(12) - (17)].SolidObjectTypeListVal), (yyvsp[(13) - (17)].BoxVolumeTypeListVal), (yyvsp[(14) - (17)].RobotTypeVal), (yyvsp[(15) - (17)].StockKeepingUnitTypeListVal), (yyvsp[(16) - (17)].WeightUnitTypeVal), (yyvsp[(17) - (17)].WorkTableTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 204:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 205:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].KitTypeListVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 206:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 207:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  ;}
    break;

  case 208:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 209:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlIDREFVal), (yyvsp[(9) - (11)].XmlNMTOKENVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 210:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 211:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].PartsTrayTypeVal), (yyvsp[(9) - (9)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 212:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 213:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 214:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 215:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 216:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 217:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].EndEffectorTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].BoxVolumeTypeListVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 218:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].InternalShapeTypeVal), (yyvsp[(7) - (15)].ExternalShapeTypeVal), (yyvsp[(8) - (15)].XmlStringVal), (yyvsp[(9) - (15)].PositiveDecimalTypeVal), (yyvsp[(10) - (15)].PositiveDecimalTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeVal), (yyvsp[(12) - (15)].PositiveDecimalTypeVal), (yyvsp[(13) - (15)].PositiveDecimalTypeVal), (yyvsp[(14) - (15)].XmlPositiveIntegerVal), (yyvsp[(15) - (15)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 219:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].PhysicalLocationTypeListVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 220:

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

