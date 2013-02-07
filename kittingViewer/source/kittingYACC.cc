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



#include <stdio.h>               // for stderr
#include <string.h>              // for strcat
#include <stdlib.h>              // for malloc, free
#ifdef VIEWER                    // added by hand
#include "kittingClassesView.hh" // for kitting classes in viewer, added by hand
#else                            // added by hand
#include "kittingClasses.hh"     // for kitting classes in parser, added by hand
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
#define YYLAST   916

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  184
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  181
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNRULES -- Number of states.  */
#define YYNSTATES  771

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
     140,   143,   145,   147,   149,   151,   152,   156,   164,   165,
     169,   170,   176,   177,   181,   182,   188,   189,   195,   196,
     200,   201,   207,   209,   210,   214,   215,   221,   222,   228,
     229,   235,   240,   244,   246,   249,   250,   256,   265,   269,
     270,   273,   284,   288,   289,   292,   309,   318,   322,   323,
     329,   330,   336,   337,   343,   347,   354,   358,   359,   365,
     366,   367,   373,   374,   380,   381,   387,   391,   395,   397,
     400,   404,   405,   408,   409,   415,   422,   426,   428,   431,
     432,   438,   447,   451,   452,   455,   464,   468,   472,   474,
     476,   478,   480,   482,   484,   486,   492,   496,   498,   500,
     502,   506,   507,   513,   524,   528,   532,   536,   537,   540,
     541,   547,   549,   551,   553,   557,   558,   564,   568,   570,
     573,   580,   582,   584,   586,   588,   590,   592,   594,   596,
     598,   600,   602,   604,   606,   608,   610,   612,   614,   616,
     618,   620,   624,   628,   629,   632,   639,   643,   649,   650,
     656,   657,   663,   664,   670,   678,   682,   686,   688,   691,
     695,   696,   702,   703,   709,   713,   714,   720,   730,   740,
     749,   761,   770,   782,   788,   798,   810,   828,   838,   850,
     860,   868,   878,   890,   900,   910,   918,   926,   934,   942,
     948,   954,   960,   972,   988,  1002,  1016
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
      31,     6,   213,   191,    30,    -1,     6,   272,   295,   301,
     236,   224,   203,   217,    -1,     6,   272,   295,   301,   236,
     224,   222,    -1,    33,   215,    32,    -1,   216,    -1,   217,
     216,    -1,    -1,    35,     6,   219,   191,    34,    -1,    -1,
     220,   218,    -1,   340,    -1,   361,    -1,   362,    -1,   363,
      -1,    -1,    37,   221,    36,    -1,     6,   272,   210,   227,
     270,   266,   268,    -1,    -1,    39,   223,    38,    -1,    -1,
      41,     6,   226,   188,    40,    -1,    -1,    43,   294,    42,
      -1,    -1,    45,     6,   229,   188,    44,    -1,    -1,    47,
       6,   231,     4,    46,    -1,    -1,    49,   311,    48,    -1,
      -1,    51,     6,   234,   189,    50,    -1,   335,    -1,    -1,
      53,   235,    52,    -1,    -1,    55,     6,   238,   189,    54,
      -1,    -1,    57,     6,   240,   189,    56,    -1,    -1,    59,
       6,   242,   191,    58,    -1,     6,   272,   246,   282,    -1,
      61,   243,    60,    -1,   244,    -1,   245,   244,    -1,    -1,
      63,     6,   247,   191,    62,    -1,     6,   272,   295,   301,
     236,   224,   306,   302,    -1,    65,   248,    64,    -1,    -1,
     250,   249,    -1,     6,   272,   295,   301,   236,   224,   212,
     315,   287,   225,    -1,    67,   251,    66,    -1,    -1,   253,
     252,    -1,     6,   272,   295,   301,   236,   224,   197,   207,
     245,   257,   275,   277,   299,   309,   317,   324,    -1,     6,
     272,   295,   301,   236,   224,   306,   302,    -1,    71,   255,
      70,    -1,    -1,    73,     6,   258,     4,    72,    -1,    -1,
      75,     6,   260,     4,    74,    -1,    -1,    77,     6,   262,
       4,    76,    -1,    79,   292,    78,    -1,     6,   272,   295,
     301,   236,   224,    -1,    81,   292,    80,    -1,    -1,    83,
       6,   267,   195,    82,    -1,    -1,    -1,    85,     6,   269,
     195,    84,    -1,    -1,    87,     6,   271,   195,    86,    -1,
      -1,    89,     6,   273,   190,    88,    -1,    91,   310,    90,
      -1,    91,   311,    90,    -1,   274,    -1,   275,   274,    -1,
      93,   204,    92,    -1,    -1,   277,   276,    -1,    -1,    95,
       6,   279,   193,    94,    -1,     6,   272,   306,   293,   327,
     332,    -1,    97,   280,    96,    -1,   281,    -1,   282,   281,
      -1,    -1,    99,     6,   284,   191,    98,    -1,     6,   272,
     295,   301,   236,   224,   306,   302,    -1,   101,   285,   100,
      -1,    -1,   287,   286,    -1,     6,   272,   295,   301,   236,
     224,   306,   302,    -1,   103,   288,   102,    -1,     6,   272,
     296,    -1,   353,    -1,   354,    -1,   355,    -1,   356,    -1,
     357,    -1,   358,    -1,   359,    -1,     6,   272,   328,   330,
     333,    -1,   105,   292,   104,    -1,   353,    -1,   354,    -1,
     356,    -1,   107,   291,   106,    -1,    -1,   109,     6,   297,
     191,   108,    -1,     6,   272,   295,   301,   236,   224,   210,
     222,   261,   326,    -1,   111,   298,   110,    -1,   113,   290,
     112,    -1,   113,   291,   112,    -1,    -1,   301,   300,    -1,
      -1,   115,     6,   303,   192,   114,    -1,   335,    -1,   339,
      -1,   341,    -1,   117,   304,   116,    -1,    -1,   119,     6,
     307,   191,   118,    -1,   121,   314,   120,    -1,   308,    -1,
     309,   308,    -1,     6,   272,   295,   301,   236,   224,    -1,
     336,    -1,   337,    -1,   338,    -1,   340,    -1,   342,    -1,
     343,    -1,   344,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   352,    -1,
     360,    -1,   361,    -1,   362,    -1,   363,    -1,   364,    -1,
     123,   310,   122,    -1,   123,   311,   122,    -1,    -1,   313,
     312,    -1,     6,   272,   210,   305,   319,   220,    -1,   125,
     248,   124,    -1,     6,   272,   233,   237,   239,    -1,    -1,
     127,     6,   318,     4,   126,    -1,    -1,   129,     6,   320,
       4,   128,    -1,    -1,   131,     6,   322,     4,   130,    -1,
       6,   272,   295,   301,   236,   224,   313,    -1,   133,   323,
     132,    -1,   135,   204,   134,    -1,   325,    -1,   326,   325,
      -1,   137,   316,   136,    -1,    -1,   139,     6,   329,   189,
     138,    -1,    -1,   141,     6,   331,   189,   140,    -1,   143,
     316,   142,    -1,    -1,   145,     6,   334,   189,   144,    -1,
     147,     6,   272,   210,   227,   259,   321,   230,   228,    -1,
     148,     6,   272,   295,   301,   236,   224,   203,   217,    -1,
     149,     6,   272,   295,   301,   236,   224,   222,    -1,   150,
       6,   272,   295,   301,   236,   224,   210,   319,   261,   232,
      -1,   151,     6,   272,   210,   227,   270,   266,   268,    -1,
     152,     6,   272,   295,   301,   236,   224,   210,   319,   261,
     232,    -1,   153,     6,   272,   210,   227,    -1,   155,     6,
     272,   295,   301,   236,   224,   306,   302,    -1,   156,     6,
     272,   295,   301,   236,   224,   212,   315,   287,   225,    -1,
     157,     6,   272,   295,   301,   236,   224,   197,   207,   245,
     257,   275,   277,   299,   309,   317,   324,    -1,   158,     6,
     272,   295,   301,   236,   224,   256,   250,    -1,   159,     6,
     272,   295,   301,   236,   224,   256,   253,   241,   205,    -1,
     160,     6,   272,   295,   301,   236,   224,   306,   302,    -1,
     161,     6,   272,   295,   301,   236,   224,    -1,   163,     6,
     272,   295,   301,   236,   224,   306,   302,    -1,   164,     6,
     272,   295,   301,   236,   224,   306,   302,   283,   278,    -1,
     165,     6,   272,   295,   301,   236,   224,   306,   302,    -1,
     166,     6,   272,   295,   301,   236,   224,   289,   287,    -1,
     169,     6,   272,   296,   293,   327,   332,    -1,   170,     6,
     272,   296,   293,   327,   332,    -1,   171,     6,   272,   296,
     293,   327,   332,    -1,   172,     6,   272,   296,   293,   327,
     332,    -1,   173,     6,   272,   296,   210,    -1,   174,     6,
     272,   296,   210,    -1,   175,     6,   272,   296,   210,    -1,
     176,     6,   272,   295,   301,   236,   224,   210,   222,   261,
     326,    -1,   179,     6,   272,   295,   301,   236,   224,   210,
     319,   261,   232,   208,   259,   199,   201,    -1,   180,     6,
     272,   295,   301,   236,   224,   210,   319,   261,   232,   208,
     259,    -1,   181,     6,   272,   295,   301,   236,   224,   210,
     319,   261,   232,   208,   259,    -1,   183,     6,   272,   295,
     301,   236,   224,   313,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   438,   438,   448,   453,   465,   473,   481,   489,   497,
     505,   513,   521,   529,   534,   545,   545,   553,   553,   559,
     559,   568,   573,   579,   579,   585,   591,   591,   600,   600,
     606,   606,   612,   622,   631,   637,   640,   647,   647,   654,
     655,   672,   674,   676,   678,   684,   685,   690,   698,   699,
     704,   704,   710,   711,   716,   716,   721,   721,   730,   731,
     736,   736,   747,   753,   754,   759,   759,   764,   764,   769,
     769,   775,   781,   786,   789,   795,   795,   801,   810,   816,
     817,   823,   832,   838,   839,   845,   859,   868,   873,   873,
     882,   882,   890,   890,   899,   904,   912,   917,   917,   924,
     925,   925,   930,   930,   936,   936,   941,   943,   948,   951,
     957,   963,   964,   971,   971,   977,   983,   988,   991,   998,
     998,  1004,  1013,  1019,  1020,  1026,  1035,  1040,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1062,  1068,  1079,  1081,  1083,
    1088,  1093,  1093,  1098,  1109,  1114,  1117,  1124,  1125,  1132,
    1132,  1144,  1146,  1148,  1153,  1158,  1158,  1163,  1168,  1171,
    1177,  1185,  1187,  1189,  1191,  1193,  1195,  1197,  1199,  1201,
    1203,  1205,  1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,
    1223,  1228,  1230,  1236,  1237,  1244,  1251,  1256,  1262,  1262,
    1271,  1271,  1279,  1279,  1287,  1296,  1301,  1306,  1309,  1315,
    1320,  1320,  1325,  1325,  1330,  1335,  1335,  1340,  1350,  1363,
    1375,  1389,  1399,  1413,  1421,  1433,  1445,  1462,  1475,  1488,
    1500,  1511,  1523,  1536,  1548,  1560,  1568,  1576,  1584,  1593,
    1601,  1609,  1617,  1631,  1647,  1662,  1677
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
  "y_PartsTrayType", "y_PartsTray_PartsTrayType", "y_PhysicalLocationType",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PoseLocationTypeAny", "y_PrimaryLocation_PhysicalLocationType",
  "y_RefObject_XmlIDREF", "$@26", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@27", "y_ShapeDesignTypeAny",
  "y_Shape_ShapeDesignType", "y_SkuName_XmlIDREF", "$@28",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SolidObjectType", "y_SolidObjectTypeAny",
  "y_SolidObject_SolidObjectType_0_u",
  "y_SolidObject_SolidObjectType_0_uList", "y_StockKeepingUnitType",
  "y_Tray_KitTrayType", "y_VectorType", "y_WeightUnit_WeightUnitType",
  "$@29", "y_Weight_PositiveDecimalType", "$@30",
  "y_Width_PositiveDecimalType", "$@31", "y_WorkTableType",
  "y_WorkTable_WorkTableType", "y_WorkVolume_BoxVolumeType_u",
  "y_WorkVolume_BoxVolumeType_uList", "y_XAxis_VectorType",
  "y_X_XmlDecimal", "$@32", "y_Y_XmlDecimal", "$@33", "y_ZAxis_VectorType",
  "y_Z_XmlDecimal", "$@34", "y_x_BoxyShapeType",
  "y_x_EndEffectorChangingStationType", "y_x_EndEffectorHolderType",
  "y_x_EndEffectorType", "y_x_ExternalShapeType",
  "y_x_GripperEffectorType", "y_x_InternalShapeType", "y_x_KitTrayType",
  "y_x_KitType", "y_x_KittingWorkstationType",
  "y_x_LargeBoxWithEmptyKitTraysType", "y_x_LargeBoxWithKitsType",
  "y_x_LargeContainerType", "y_x_MechanicalComponentType", "y_x_PartType",
  "y_x_PartsBinType", "y_x_PartsTrayType", "y_x_PartsTrayWithPartsType",
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
     220,   221,   221,   221,   221,   222,   222,   223,   224,   224,
     226,   225,   227,   227,   229,   228,   231,   230,   232,   232,
     234,   233,   235,   236,   236,   238,   237,   240,   239,   242,
     241,   243,   244,   245,   245,   247,   246,   248,   249,   250,
     250,   251,   252,   253,   253,   254,   255,   256,   258,   257,
     260,   259,   262,   261,   263,   264,   265,   267,   266,   268,
     269,   268,   271,   270,   273,   272,   274,   274,   275,   275,
     276,   277,   277,   279,   278,   280,   281,   282,   282,   284,
     283,   285,   286,   287,   287,   288,   289,   290,   291,   291,
     291,   291,   291,   291,   291,   292,   293,   294,   294,   294,
     295,   297,   296,   298,   299,   300,   300,   301,   301,   303,
     302,   304,   304,   304,   305,   307,   306,   308,   309,   309,
     310,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   312,   313,   313,   314,   315,   316,   318,   317,
     320,   319,   322,   321,   323,   324,   325,   326,   326,   327,
     329,   328,   331,   330,   332,   334,   333,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     0,     5,     0,     5,     0,
       5,     3,     4,     0,     5,     3,     0,     5,     0,     5,
       0,     5,     8,     7,     3,     1,     2,     0,     5,     0,
       2,     1,     1,     1,     1,     0,     3,     7,     0,     3,
       0,     5,     0,     3,     0,     5,     0,     5,     0,     3,
       0,     5,     1,     0,     3,     0,     5,     0,     5,     0,
       5,     4,     3,     1,     2,     0,     5,     8,     3,     0,
       2,    10,     3,     0,     2,    16,     8,     3,     0,     5,
       0,     5,     0,     5,     3,     6,     3,     0,     5,     0,
       0,     5,     0,     5,     0,     5,     3,     3,     1,     2,
       3,     0,     2,     0,     5,     6,     3,     1,     2,     0,
       5,     8,     3,     0,     2,     8,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     1,     1,     1,
       3,     0,     5,    10,     3,     3,     3,     0,     2,     0,
       5,     1,     1,     1,     3,     0,     5,     3,     1,     2,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     0,     2,     6,     3,     5,     0,     5,
       0,     5,     0,     5,     7,     3,     3,     1,     2,     3,
       0,     5,     0,     5,     3,     0,     5,     9,     9,     8,
      11,     8,    11,     5,     9,    11,    17,     9,    11,     9,
       7,     9,    11,     9,     9,     7,     7,     7,     7,     5,
       5,     5,    11,    15,    13,    13,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     3,     0,     0,
       2,    14,     4,   104,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,    63,     7,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,    48,   148,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,   145,   146,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,   229,   230,   231,
       0,   127,     0,    49,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    52,    52,     0,     0,
       0,     0,    73,     0,     8,     0,     0,   136,     0,     0,
       0,   225,   226,   227,   228,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    74,     0,   142,     0,     0,
       0,   199,     0,    12,     0,     0,   137,   138,   139,     0,
       0,     0,     0,    16,   147,     0,    72,    88,     0,   108,
     111,   200,     0,     0,     0,     0,   204,    29,    53,    90,
       0,     0,   102,     0,    99,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   109,     0,     0,   202,     0,   135,    60,     0,
       0,     0,   192,     0,     0,     0,    97,     0,    47,    48,
      75,     0,   117,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     112,     0,     6,     0,     0,   205,     0,    65,     0,   187,
       0,     0,    56,     0,   207,     0,     0,   100,     0,     0,
       0,     0,   118,    89,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,   201,     0,     0,     0,     0,    67,    91,     0,
       0,    54,   103,     0,     0,     0,     0,     0,     0,   116,
      63,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,     0,   110,     0,   144,     0,     0,     0,   159,     0,
     203,     0,    61,     0,     0,   193,     0,     0,    98,     0,
       0,     0,     0,    35,    32,    76,     0,     0,    48,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,     0,
       0,   147,     0,   157,   188,     0,    85,   206,    66,     0,
      57,     5,     0,   101,     0,    21,     0,     0,    36,   155,
       0,   160,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,     0,     0,    22,    63,     0,     0,     0,     0,
      68,    55,   147,     0,    34,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,   183,    94,     0,    48,
       0,     0,     0,     0,   195,    63,   147,     0,   115,     0,
       0,   209,     0,     0,     0,     0,     0,     0,     0,    79,
      83,     0,     0,     0,     0,     0,   123,    45,     0,     0,
       0,   236,    96,     0,     0,     0,     0,   151,   152,   153,
       0,    39,   189,   147,    48,    63,   156,   208,     0,    41,
      42,    43,    44,     0,     0,     0,   214,    30,     0,   123,
       0,     0,     0,   217,     0,   219,   221,     0,   223,     0,
       0,   224,     0,     0,     0,     0,     0,   184,    45,     0,
       0,   154,   190,   185,    63,    95,    48,    46,     0,    58,
      58,   149,     0,     0,     0,     0,     0,     0,    87,     0,
      80,     0,     0,     0,    84,     0,     0,     0,   126,     0,
     124,     0,    58,    58,    58,     0,     0,     0,     0,     0,
       0,     0,    40,    48,    45,    92,     0,   210,   212,     0,
       0,     0,   186,     0,   215,     0,   147,     0,    69,     0,
       0,     0,   218,   119,     0,   222,   147,     0,     0,     0,
     197,   232,     0,     0,     0,   181,   182,     0,    52,    52,
       0,    37,   183,    33,     0,     0,     9,     0,    31,   147,
      50,   111,    63,    78,     0,     0,    82,    23,     0,   113,
      63,     0,   122,     0,   198,     0,     0,     0,     0,   143,
       0,   213,   191,     0,   194,     0,    59,   150,    63,     0,
       0,    48,     0,   147,     0,     0,     0,    48,   147,   196,
      26,     0,   234,   235,     0,     0,    93,    48,     0,     0,
       0,    70,    63,    11,     0,   120,    10,     0,     0,    63,
       0,     0,     0,    99,    38,     0,    51,     0,     0,    48,
      24,   114,     0,    48,     0,    17,     0,   233,   211,     0,
       0,    86,     0,   125,     0,    27,     0,    19,    77,   216,
       0,     0,     0,     0,   123,   121,    18,     0,     0,    20,
      81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    17,   432,   283,    44,   125,   667,   727,
     724,   154,     3,    89,   118,   732,   756,   747,   763,   346,
     326,   642,   704,   106,   686,   730,    97,   135,   516,   592,
     120,   437,   393,   394,   622,   693,   583,   548,   511,    87,
      72,   634,   699,   137,   294,   387,   244,   340,   627,   175,
     286,    66,    55,   240,   336,   289,   384,   603,   674,   143,
     122,   123,   187,   299,   594,   600,   563,   640,   604,   564,
      14,   562,   519,   146,   188,   160,   241,   589,   664,   420,
     391,   464,   184,   296,   248,   344,   162,   245,    19,    26,
     169,   170,   280,   233,   645,   706,   301,   252,   253,   606,
     678,   648,   610,   571,   570,   526,    69,    34,   109,    92,
     155,    25,    74,   107,   328,   281,    56,    42,   556,   629,
     536,   501,   397,   475,   330,   331,   210,   211,   577,   531,
     376,   559,   129,   379,   467,   541,   620,   181,   291,   469,
     426,   650,   651,   111,   149,   234,   173,   284,   131,   237,
     334,    67,   212,   213,   214,   538,   215,   539,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    35,
      36,    37,    38,    39,    40,    41,   227,   228,   229,   230,
     231
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -619
static const yytype_int16 yypact[] =
{
      50,    56,    72,    21,    82,  -619,    81,    73,    88,   102,
     110,  -619,   116,    39,    66,   132,   130,  -619,   139,    52,
    -619,  -619,  -619,  -619,   -20,  -619,   156,   155,   157,   158,
     159,   160,   161,   163,    64,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,   -37,  -619,    74,    39,    39,    39,    39,    39,
      39,    39,  -619,    24,     4,   133,  -619,  -619,    71,    71,
      71,    71,    71,    71,    71,   175,   152,  -619,    39,    93,
      94,   201,   193,   203,   147,   147,   147,   147,   225,   225,
     225,    39,  -619,    71,  -619,  -619,    39,   218,   271,   253,
    -619,   273,   149,   149,   149,   149,   278,  -619,  -619,  -619,
     225,  -619,   225,  -619,  -619,   281,   227,   285,    39,   186,
     287,   151,   151,   151,   151,  -619,   252,   252,   292,    39,
     275,   294,  -619,   -23,  -619,   194,   162,  -619,    39,   167,
     287,  -619,  -619,  -619,  -619,   301,   -34,   231,   220,   295,
      52,  -619,    39,   248,   304,  -619,   223,  -619,   305,   174,
     265,  -619,   176,  -619,   291,   279,  -619,  -619,  -619,   316,
     192,   318,   242,  -619,  -619,   263,  -619,  -619,   307,  -619,
     223,  -619,   322,   184,   325,   277,  -619,  -619,  -619,  -619,
     327,   288,  -619,   328,   251,   -37,   332,   243,   335,    39,
     336,   337,   338,   340,   341,   342,   343,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     280,   282,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   -50,   361,  -619,   362,  -619,  -619,   363,
     284,   367,  -619,   368,   330,   301,  -619,   373,  -619,   133,
    -619,   374,  -619,   243,   310,    52,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,  -619,  -619,   377,   378,
    -619,   264,  -619,   235,   361,  -619,   361,  -619,   380,  -619,
     313,   384,  -619,   383,  -619,   306,   301,  -619,   369,   285,
      39,   297,  -619,  -619,  -619,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    39,   302,    39,   286,   389,
    -619,   -59,  -619,   257,   361,   359,   361,  -619,  -619,   268,
     395,  -619,  -619,   319,   301,   394,   370,   345,   289,  -619,
     -37,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,   326,  -619,    52,  -619,    39,   290,   398,  -619,   293,
    -619,   267,  -619,   360,   361,  -619,   372,   409,  -619,   331,
      39,   399,   414,  -619,   370,  -619,   421,   147,   133,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   273,
     364,  -619,   225,  -619,  -619,   422,  -619,  -619,  -619,   375,
    -619,  -619,   385,  -619,    52,  -619,    39,   400,  -619,  -619,
     149,  -619,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   365,   273,  -619,   -37,   317,   426,    39,   303,
    -619,  -619,  -619,    52,  -619,   285,   151,   369,   396,   225,
     225,   289,   405,   193,   371,   371,   289,  -619,   289,   289,
     289,   344,   225,   225,   225,   225,  -619,  -619,   366,   133,
     -72,   312,   324,    52,  -619,   -37,  -619,   333,  -619,   370,
     -92,  -619,   312,   312,   329,   442,   376,   253,   446,  -619,
    -619,   329,   329,   329,   329,   447,  -619,   396,   312,   312,
     312,   379,  -619,   225,   448,   452,   381,  -619,  -619,  -619,
     454,  -619,  -619,  -619,   133,   -37,  -619,   370,   425,  -619,
    -619,  -619,  -619,   392,   392,   468,  -619,  -619,   470,  -619,
     227,    39,   407,   415,   -13,  -619,  -619,   382,  -619,    39,
     387,   390,   392,   392,   392,   392,   307,  -619,   396,    39,
      39,  -619,  -619,   444,   -37,  -619,   133,  -619,   478,   443,
     443,  -619,   285,    39,   386,   -10,   -23,    52,  -619,   470,
    -619,   487,   488,   472,  -619,   490,   403,    52,  -619,   493,
    -619,   388,   443,   443,   443,   391,   393,   392,   225,   225,
     496,   497,  -619,   133,   396,  -619,   -54,  -619,  -619,   501,
     476,    52,  -619,   505,  -619,   223,  -619,   450,  -619,    39,
     441,   511,  -619,  -619,   512,  -619,  -619,    39,   419,   377,
    -619,   388,   494,   494,   494,  -619,  -619,   388,   252,   252,
     397,  -619,  -619,  -619,   516,   474,  -619,   412,  -619,  -619,
    -619,   223,   -37,  -619,   285,    52,  -619,  -619,   285,  -619,
     -37,    52,  -619,   402,  -619,   521,   231,   231,   231,   388,
     220,  -619,  -619,   285,   379,   453,  -619,  -619,   -37,   409,
     -50,   133,   473,  -619,   524,   434,   529,   133,  -619,  -619,
    -619,   520,  -619,  -619,   242,   504,  -619,   133,   499,   264,
     289,  -619,   -37,  -619,   518,  -619,  -619,   449,   289,   -37,
     537,   538,   526,   251,  -619,   289,  -619,   -59,   329,   133,
    -619,  -619,   329,   133,   525,  -619,   540,  -619,  -619,   329,
     293,  -619,   405,  -619,   289,  -619,   524,  -619,  -619,  -619,
     376,   329,   531,   551,  -619,  -619,  -619,   539,   -10,  -619,
    -619
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -619,  -619,  -619,  -619,  -143,  -252,  -619,  -272,  -619,  -619,
    -198,  -223,  -619,    77,  -619,  -619,  -619,  -619,  -619,    85,
     -84,  -619,  -619,    49,  -614,  -619,   -55,  -619,  -185,  -619,
    -619,  -619,  -379,    59,  -619,  -619,  -619,  -619,  -501,  -619,
     173,  -199,  -619,  -109,  -619,  -619,  -619,  -619,  -471,  -619,
    -619,  -619,  -168,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -114,    10,  -619,  -619,   -27,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,    89,   -19,  -619,  -530,  -619,  -517,  -619,  -619,
    -619,  -619,  -141,  -619,  -157,  -619,  -112,  -619,   -45,  -619,
    -163,   -56,  -619,   -91,  -619,  -619,  -619,   334,  -619,  -619,
    -619,  -619,  -619,  -511,  -619,  -619,  -619,   527,  -377,   -47,
    -619,  -122,    54,  -619,  -619,  -118,  -619,   -94,  -457,  -619,
    -619,  -619,  -437,  -619,  -320,  -136,     8,  -541,  -619,   -77,
    -619,  -174,   458,  -148,  -619,  -382,  -619,  -619,  -619,  -619,
    -160,  -618,   -66,   -74,  -619,  -619,  -619,  -619,  -100,  -619,
    -619,    92,  -619,  -619,  -619,  -619,    83,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,   459,
     460,  -619,   461,  -619,  -619,  -619,  -619,    90,    91,    95,
    -619
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      58,    59,    60,    61,    62,    63,    64,   232,   138,   145,
      68,   378,   132,   133,   134,   438,    53,   249,   164,   112,
     113,   114,   295,    83,    98,    99,   572,   347,    93,    94,
      95,   633,   333,   684,   335,   616,   100,   590,   121,   687,
     688,   102,   462,   278,   514,   116,   601,   117,   595,   521,
     144,   522,   523,   524,   602,   611,   612,   613,   614,     1,
     193,   279,   329,   126,   565,   566,   567,   568,   377,     4,
     185,   684,     5,   343,   140,    65,    54,   617,    10,   534,
      11,   535,   381,   150,   383,   665,   498,   206,   207,   208,
       6,   609,     7,     8,   190,   191,   192,   165,   193,    12,
     657,   194,   195,   196,   197,   198,   199,   200,    13,   201,
     202,   203,   204,    75,    76,    77,    78,    79,    80,   628,
      15,   389,   205,   663,    16,   206,   207,   208,    18,   209,
     553,   554,   429,   304,    20,    27,    28,   101,    30,    21,
      22,   652,   653,   654,   255,    23,   573,   574,   575,    27,
      28,    29,    30,    31,    32,    33,   711,   712,   713,    24,
      43,    45,    57,    46,    47,    48,    49,    50,   438,    51,
      52,    65,    71,    27,    28,    29,    30,    31,    32,    33,
      73,    81,   398,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   507,    82,    84,    85,    86,    88,    90,
     350,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   421,    91,   768,    96,   348,   103,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   104,   105,   108,
     371,   751,   373,   738,   115,   753,   110,   119,   121,   124,
     127,   742,   758,   128,   130,   136,   139,   499,   749,   141,
     142,   148,   147,   151,   765,   153,   159,   161,   166,   163,
     167,   171,   472,   189,   168,   172,   174,   761,   176,   177,
     630,   178,   179,   180,   182,   183,   186,   465,   235,   236,
     422,   238,   239,   242,   246,   243,   247,   544,   250,   254,
     251,   288,   256,   257,   258,   434,   259,   260,   261,   262,
     440,   506,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   282,   476,   466,   285,   287,
     276,   290,   277,   332,   292,   293,   508,   586,   505,   297,
     300,   543,   303,   325,   327,   329,   337,   338,   339,   341,
     345,   473,   342,   349,   372,   375,   374,   380,   385,   386,
     390,   388,   702,   392,   424,   419,   705,   395,   396,   382,
     423,   427,   545,   431,   428,   433,   623,   378,   430,   435,
     436,   715,   298,   503,   512,   513,   425,   439,   468,   471,
     502,   470,   474,   510,   500,   504,   515,   527,   528,   529,
     530,   540,   518,   497,   555,   463,   532,   525,   557,   584,
     542,   546,   561,   569,   579,   190,   191,   192,   580,   193,
     582,   587,   194,   195,   196,   197,   198,   199,   200,   588,
     201,   202,   203,   204,   591,   636,   593,   598,   578,   621,
     599,   605,   145,   205,   625,   646,   206,   207,   208,   608,
     209,   609,   626,   638,   639,   641,   643,   581,   644,   647,
     660,   558,   576,   661,   701,   666,   668,   676,   232,   669,
     632,   670,   707,   655,   673,   656,   597,   677,   679,   682,
     695,   685,   696,   649,   607,   692,   697,   710,   723,   716,
     717,   721,   725,   726,   618,   619,   709,   731,   734,   736,
     740,   744,   672,   741,   745,   746,   757,   766,   631,   690,
     691,   755,   680,   703,   739,   767,   718,   769,   762,   708,
     517,   743,   509,   658,   659,   683,   560,   760,   547,   770,
     596,   441,   637,   733,   520,   698,   748,   635,   714,   671,
     700,    70,   719,   737,   615,   694,   764,   302,   152,   750,
     759,   689,   537,   549,   675,   156,   157,   158,     0,     0,
     550,   551,   681,     0,     0,   552,     0,     0,     0,   722,
       0,     0,     0,     0,   729,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   720,     0,     0,     0,     0,     0,
     728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   752,     0,     0,     0,   754
};

static const yytype_int16 yycheck[] =
{
      45,    46,    47,    48,    49,    50,    51,   170,   117,   123,
       6,   331,   112,   113,   114,   394,    53,   185,   140,    93,
      94,    95,   245,    68,    79,    80,   527,   299,    75,    76,
      77,    41,   284,   651,   286,   576,    81,   554,    61,   653,
     654,    86,   419,    93,   481,   100,    59,   102,   559,   486,
      73,   488,   489,   490,    67,   572,   573,   574,   575,     9,
     152,   111,   121,   108,   521,   522,   523,   524,   127,    13,
     164,   689,     0,   296,   119,   147,   113,   578,     5,   151,
       7,   153,   334,   128,   336,   626,   463,   179,   180,   181,
      69,   101,    10,    12,   148,   149,   150,   142,   152,    11,
     617,   155,   156,   157,   158,   159,   160,   161,     6,   163,
     164,   165,   166,    59,    60,    61,    62,    63,    64,   590,
      10,   344,   176,   624,     8,   179,   180,   181,    89,   183,
     512,   513,   384,   255,    68,   169,   170,    83,   172,     7,
      10,   612,   613,   614,   189,     6,   528,   529,   530,   169,
     170,   171,   172,   173,   174,   175,   686,   687,   688,   107,
       4,     6,    88,     6,     6,     6,     6,     6,   547,     6,
     106,   147,    39,   169,   170,   171,   172,   173,   174,   175,
     109,     6,   350,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   475,    52,   112,   112,     6,    15,     6,
     304,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   373,   105,   764,    29,   300,    38,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,     6,    25,     6,
     325,   738,   327,   720,     6,   742,   137,     6,    61,     4,
     104,   728,   749,     6,   143,    43,     4,   465,   735,    24,
       6,   139,   108,   136,   761,     4,    75,    87,    60,    14,
       6,     6,   434,     6,    91,   141,    51,   754,   142,    28,
     592,    42,     6,   131,     6,    83,    63,   421,     6,   145,
     375,     6,    55,     6,     6,    47,    85,   505,     6,     4,
      97,    57,     6,     6,     6,   390,     6,     6,     6,     6,
     397,   473,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     4,   440,   422,     6,     6,
      90,     4,    90,   138,     6,    45,   476,   545,   472,     6,
       6,   503,    72,     6,     6,   121,     6,    74,     4,     6,
      21,   436,    86,    96,    92,     6,   110,   140,   130,     4,
       6,    82,   674,    33,     6,    79,   678,    62,   119,    50,
     120,   144,   506,     4,    54,    84,   584,   737,    46,    20,
       6,   693,   249,   468,   479,   480,   133,     6,     6,    44,
       4,    56,    32,    37,   117,   132,    31,   492,   493,   494,
     495,   129,    71,    78,   115,    81,    80,   103,     6,   543,
     126,   118,     6,     6,     6,   148,   149,   150,     6,   152,
       6,    36,   155,   156,   157,   158,   159,   160,   161,    77,
     163,   164,   165,   166,     6,   597,     6,    70,   533,    35,
      65,    99,   596,   176,     6,   607,   179,   180,   181,   102,
     183,   101,    49,     6,     6,    23,     6,   116,    95,     6,
       4,   125,   123,     6,   672,     4,    30,    66,   671,   631,
     124,     6,   680,   122,    64,   122,   561,     6,     6,   100,
       4,    27,    48,   135,   569,   128,   114,     6,     4,    76,
     698,    58,    98,     4,   579,   580,   134,    17,    34,    40,
      22,     4,   636,    94,     6,    19,     6,    16,   593,   658,
     659,    26,   646,   675,   722,     4,   699,    18,   756,   681,
     483,   729,   477,   618,   619,   649,   517,   752,   509,   768,
     560,   398,   599,   714,   485,   669,   733,   596,   690,   635,
     671,    54,   700,   719,   576,   662,   760,   253,   130,   737,
     750,   657,   500,   510,   639,   136,   136,   136,    -1,    -1,
     510,   510,   647,    -1,    -1,   510,    -1,    -1,    -1,   703,
      -1,    -1,    -1,    -1,   708,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,
     707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     717,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   739,    -1,    -1,    -1,   743
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   185,   196,    13,     0,    69,    10,    12,   186,
       5,     7,    11,     6,   254,    10,     8,   187,    89,   272,
      68,     7,    10,     6,   107,   295,   273,   169,   170,   171,
     172,   173,   174,   175,   291,   353,   354,   355,   356,   357,
     358,   359,   301,     4,   190,     6,     6,     6,     6,     6,
       6,     6,   106,    53,   113,   236,   300,    88,   272,   272,
     272,   272,   272,   272,   272,   147,   235,   335,     6,   290,
     291,    39,   224,   109,   296,   296,   296,   296,   296,   296,
     296,     6,    52,   272,   112,   112,     6,   223,    15,   197,
       6,   105,   293,   293,   293,   293,    29,   210,   210,   210,
     272,   296,   272,    38,     6,    25,   207,   297,     6,   292,
     137,   327,   327,   327,   327,     6,   210,   210,   198,     6,
     214,    61,   244,   245,     4,   191,   272,   104,     6,   316,
     143,   332,   332,   332,   332,   211,    43,   227,   227,     4,
     272,    24,     6,   243,    73,   244,   257,   108,   139,   328,
     272,   136,   316,     4,   195,   294,   353,   354,   356,    75,
     259,    87,   270,    14,   295,   272,    60,     6,    91,   274,
     275,     6,   141,   330,    51,   233,   142,    28,    42,     6,
     131,   321,     6,    83,   266,   301,    63,   246,   258,     6,
     148,   149,   150,   152,   155,   156,   157,   158,   159,   160,
     161,   163,   164,   165,   166,   176,   179,   180,   181,   183,
     310,   311,   336,   337,   338,   340,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   360,   361,   362,
     363,   364,   274,   277,   329,     6,   145,   333,     6,    55,
     237,   260,     6,    47,   230,   271,     6,    85,   268,   236,
       6,    97,   281,   282,     4,   272,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,    90,    90,    93,   111,
     276,   299,     4,   189,   331,     6,   234,     6,    57,   239,
       4,   322,     6,    45,   228,   195,   267,     6,   224,   247,
       6,   280,   281,    72,   295,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,     6,   204,     6,   298,   121,
     308,   309,   138,   189,   334,   189,   238,     6,    74,     4,
     231,     6,    86,   195,   269,    21,   203,   191,   272,    96,
     301,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   272,    92,   272,   110,     6,   314,   127,   308,   317,
     140,   189,    50,   189,   240,   130,     4,   229,    82,   195,
       6,   264,    33,   216,   217,    62,   119,   306,   236,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,    79,
     263,   295,   272,   120,     6,   133,   324,   144,    54,   189,
      46,     4,   188,    84,   272,    20,     6,   215,   216,     6,
     293,   224,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   292,    81,   265,   301,   210,   318,     6,   323,
      56,    44,   295,   272,    32,   307,   327,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,    78,   292,   236,
     117,   305,     4,   272,   132,   301,   295,   191,   332,   203,
      37,   222,   210,   210,   306,    31,   212,   197,    71,   256,
     256,   306,   306,   306,   306,   103,   289,   210,   210,   210,
     210,   313,    80,   224,   151,   153,   304,   335,   339,   341,
     129,   319,   126,   295,   236,   301,   118,   217,   221,   340,
     361,   362,   363,   319,   319,   115,   302,     6,   125,   315,
     207,     6,   255,   250,   253,   302,   302,   302,   302,     6,
     288,   287,   222,   319,   319,   319,   123,   312,   210,     6,
       6,   116,     6,   220,   301,   224,   236,    36,    77,   261,
     261,     6,   213,     6,   248,   287,   245,   272,    70,    65,
     249,    59,    67,   241,   252,    99,   283,   272,   102,   101,
     286,   261,   261,   261,   261,   310,   311,   222,   272,   272,
     320,    35,   218,   236,   224,     6,    49,   232,   232,   303,
     191,   272,   124,    41,   225,   257,   295,   248,     6,     6,
     251,    23,   205,     6,    95,   278,   295,     6,   285,   135,
     325,   326,   232,   232,   232,   122,   122,   261,   210,   210,
       4,     6,   224,   222,   262,   311,     4,   192,    30,   295,
       6,   275,   301,    64,   242,   272,    66,     6,   284,     6,
     301,   272,   100,   204,   325,    27,   208,   208,   208,   326,
     227,   227,   128,   219,   313,     4,    48,   114,   301,   226,
     277,   236,   191,   295,   206,   191,   279,   236,   295,   134,
       6,   259,   259,   259,   270,   191,    76,   236,   188,   299,
     224,    58,   301,     4,   194,    98,     4,   193,   224,   301,
     209,    17,   199,   266,    34,   224,    40,   309,   306,   236,
      22,    94,   306,   236,     4,     6,    19,   201,   268,   306,
     317,   302,   224,   302,   224,    26,   200,     6,   302,   324,
     212,   306,   194,   202,   315,   302,    16,     4,   287,    18,
     225
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

    {(yyval.EndEffectorTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 45:

    {(yyval.EndEffectorTypeVal) = 0;;}
    break;

  case 46:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 47:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].PoseLocationTypeVal), (yyvsp[(5) - (7)].XmlStringVal), (yyvsp[(6) - (7)].XmlStringVal), (yyvsp[(7) - (7)].XmlStringVal));;}
    break;

  case 48:

    {(yyval.ExternalShapeTypeVal) = 0;;}
    break;

  case 49:

    {(yyval.ExternalShapeTypeVal) = (yyvsp[(2) - (3)].ExternalShapeTypeVal);;}
    break;

  case 50:

    {yyReadData = 1;;}
    break;

  case 51:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 52:

    {(yyval.PoseLocationTypeVal) = 0;;}
    break;

  case 53:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(2) - (3)].PoseLocationTypeVal);;}
    break;

  case 54:

    {yyReadData = 1;;}
    break;

  case 55:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 56:

    {yyReadData = 1;;}
    break;

  case 57:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 58:

    {(yyval.SolidObjectTypeVal) = 0;;}
    break;

  case 59:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 60:

    {yyReadData = 1;;}
    break;

  case 61:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 62:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 63:

    {(yyval.InternalShapeTypeVal) = 0;;}
    break;

  case 64:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(2) - (3)].InternalShapeTypeVal);;}
    break;

  case 65:

    {yyReadData = 1;;}
    break;

  case 66:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 67:

    {yyReadData = 1;;}
    break;

  case 68:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 69:

    {yyReadData = 1;;}
    break;

  case 70:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 71:

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].PartRefAndPoseTypeListVal));;}
    break;

  case 72:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 73:

    {(yyval.KitDesignTypeListVal) = new std::list<KitDesignType *>;
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 74:

    {(yyval.KitDesignTypeListVal) = (yyvsp[(1) - (2)].KitDesignTypeListVal);
	   (yyval.KitDesignTypeListVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 75:

    {yyReadData = 1;;}
    break;

  case 76:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 77:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 78:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 79:

    {(yyval.KitTrayTypeListVal) = new std::list<KitTrayType *>;;}
    break;

  case 80:

    {(yyval.KitTrayTypeListVal) = (yyvsp[(1) - (2)].KitTrayTypeListVal);
	   (yyval.KitTrayTypeListVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 81:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlIDREFVal), (yyvsp[(8) - (10)].KitTrayTypeVal), (yyvsp[(9) - (10)].PartTypeListVal), (yyvsp[(10) - (10)].XmlBooleanVal));;}
    break;

  case 82:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 83:

    {(yyval.KitTypeListVal) = new std::list<KitType *>;;}
    break;

  case 84:

    {(yyval.KitTypeListVal) = (yyvsp[(1) - (2)].KitTypeListVal);
	   (yyval.KitTypeListVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 85:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (16)].XmlIDVal), (yyvsp[(3) - (16)].PhysicalLocationTypeVal), (yyvsp[(4) - (16)].PhysicalLocationTypeListVal), (yyvsp[(5) - (16)].InternalShapeTypeVal), (yyvsp[(6) - (16)].ExternalShapeTypeVal), (yyvsp[(7) - (16)].AngleUnitTypeVal), (yyvsp[(8) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(9) - (16)].KitDesignTypeListVal), (yyvsp[(10) - (16)].LengthUnitTypeVal), (yyvsp[(11) - (16)].SolidObjectTypeListVal), (yyvsp[(12) - (16)].BoxVolumeTypeListVal), (yyvsp[(13) - (16)].RobotTypeVal), (yyvsp[(14) - (16)].StockKeepingUnitTypeListVal), (yyvsp[(15) - (16)].WeightUnitTypeVal), (yyvsp[(16) - (16)].WorkTableTypeVal));;}
    break;

  case 86:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 87:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 88:

    {yyReadData = 1;;}
    break;

  case 89:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 90:

    {yyReadData = 1;;}
    break;

  case 91:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 92:

    {yyReadData = 1;;}
    break;

  case 93:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 94:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 95:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));;}
    break;

  case 96:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 97:

    {yyReadData = 1;;}
    break;

  case 98:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 99:

    {(yyval.XmlStringVal) = 0;;}
    break;

  case 100:

    {yyReadData = 1;;}
    break;

  case 101:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 102:

    {yyReadData = 1;;}
    break;

  case 103:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 104:

    {yyReadData = 1;;}
    break;

  case 105:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 106:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 107:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 108:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 109:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 110:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 111:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 112:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 113:

    {yyReadData = 1;;}
    break;

  case 114:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 115:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 116:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 117:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 118:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 119:

    {yyReadData = 1;;}
    break;

  case 120:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 121:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 122:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 123:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 124:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 125:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].PhysicalLocationTypeListVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].XmlIDREFVal), (yyvsp[(8) - (8)].XmlNMTOKENVal));;}
    break;

  case 126:

    {(yyval.PartsTrayTypeVal) = (yyvsp[(2) - (3)].PartsTrayTypeVal);;}
    break;

  case 127:

    {(yyval.PhysicalLocationTypeVal) = new PhysicalLocationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlIDREFVal));;}
    break;

  case 128:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 129:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 130:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationTypeVal);;}
    break;

  case 131:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 132:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 133:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 134:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationTypeVal);;}
    break;

  case 135:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 136:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 137:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 138:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 139:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 140:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 141:

    {yyReadData = 1;;}
    break;

  case 142:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 143:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].BoxVolumeTypeListVal));;}
    break;

  case 144:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 145:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 146:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 147:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 148:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 149:

    {yyReadData = 1;;}
    break;

  case 150:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 151:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 152:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].ExternalShapeTypeVal);;}
    break;

  case 153:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(1) - (1)].InternalShapeTypeVal);;}
    break;

  case 154:

    {(yyval.ShapeDesignTypeVal) = (yyvsp[(2) - (3)].ShapeDesignTypeVal);;}
    break;

  case 155:

    {yyReadData = 1;;}
    break;

  case 156:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 157:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 158:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 159:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 160:

    {(yyval.SolidObjectTypeVal) = new SolidObjectType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));;}
    break;

  case 161:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 162:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 163:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorTypeVal);;}
    break;

  case 164:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 165:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 166:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 167:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 168:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 169:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 170:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 171:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);;}
    break;

  case 172:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 173:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 174:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 175:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayWithPartsTypeVal);;}
    break;

  case 176:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 177:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 178:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 179:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorTypeVal);;}
    break;

  case 180:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 181:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 182:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 183:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 184:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 185:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlStringVal), (yyvsp[(4) - (6)].ShapeDesignTypeVal), (yyvsp[(5) - (6)].PositiveDecimalTypeVal), (yyvsp[(6) - (6)].IDREFListVal));;}
    break;

  case 186:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 187:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 188:

    {yyReadData = 1;;}
    break;

  case 189:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 190:

    {yyReadData = 1;;}
    break;

  case 191:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 192:

    {yyReadData = 1;;}
    break;

  case 193:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 194:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].PhysicalLocationTypeListVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].SolidObjectTypeListVal));;}
    break;

  case 195:

    {(yyval.WorkTableTypeVal) = (yyvsp[(2) - (3)].WorkTableTypeVal);;}
    break;

  case 196:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 197:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 198:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 199:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 200:

    {yyReadData = 1;;}
    break;

  case 201:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 202:

    {yyReadData = 1;;}
    break;

  case 203:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 204:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 205:

    {yyReadData = 1;;}
    break;

  case 206:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 207:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlStringVal), (yyvsp[(5) - (9)].PoseLocationTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 208:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 209:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 210:

    {(yyval.EndEffectorTypeVal) = new EndEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.EndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 211:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].XmlStringVal), (yyvsp[(7) - (8)].XmlStringVal), (yyvsp[(8) - (8)].XmlStringVal));
	   (yyval.ExternalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 212:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 213:

    {(yyval.InternalShapeTypeVal) = new InternalShapeType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlStringVal), (yyvsp[(5) - (5)].PoseLocationTypeVal));
	   (yyval.InternalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 214:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 215:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlIDREFVal), (yyvsp[(9) - (11)].KitTrayTypeVal), (yyvsp[(10) - (11)].PartTypeListVal), (yyvsp[(11) - (11)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 216:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (17)].XmlIDVal), (yyvsp[(4) - (17)].PhysicalLocationTypeVal), (yyvsp[(5) - (17)].PhysicalLocationTypeListVal), (yyvsp[(6) - (17)].InternalShapeTypeVal), (yyvsp[(7) - (17)].ExternalShapeTypeVal), (yyvsp[(8) - (17)].AngleUnitTypeVal), (yyvsp[(9) - (17)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (17)].KitDesignTypeListVal), (yyvsp[(11) - (17)].LengthUnitTypeVal), (yyvsp[(12) - (17)].SolidObjectTypeListVal), (yyvsp[(13) - (17)].BoxVolumeTypeListVal), (yyvsp[(14) - (17)].RobotTypeVal), (yyvsp[(15) - (17)].StockKeepingUnitTypeListVal), (yyvsp[(16) - (17)].WeightUnitTypeVal), (yyvsp[(17) - (17)].WorkTableTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 217:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 218:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].KitTypeListVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 219:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 220:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  ;}
    break;

  case 221:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 222:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlIDREFVal), (yyvsp[(9) - (11)].XmlNMTOKENVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlNonNegativeIntegerVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 223:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].XmlIDREFVal), (yyvsp[(9) - (9)].XmlNMTOKENVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 224:

    {(yyval.PartsTrayWithPartsTypeVal) = new PartsTrayWithPartsType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].PartsTrayTypeVal), (yyvsp[(9) - (9)].PartTypeListVal));
	   (yyval.PartsTrayWithPartsTypeVal)->printTypp = true;
	  ;}
    break;

  case 225:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 226:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 227:

    {(yyval.PoseLocationTypeVal) = new PoseLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 228:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].XmlIDREFVal), (yyvsp[(5) - (7)].PointTypeVal), (yyvsp[(6) - (7)].VectorTypeVal), (yyvsp[(7) - (7)].VectorTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 229:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 230:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 231:

    {(yyval.RelativeLocationTypeVal) = new RelativeLocationType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 232:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].EndEffectorTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].BoxVolumeTypeListVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 233:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].PhysicalLocationTypeListVal), (yyvsp[(6) - (15)].InternalShapeTypeVal), (yyvsp[(7) - (15)].ExternalShapeTypeVal), (yyvsp[(8) - (15)].XmlStringVal), (yyvsp[(9) - (15)].PositiveDecimalTypeVal), (yyvsp[(10) - (15)].PositiveDecimalTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeVal), (yyvsp[(12) - (15)].PositiveDecimalTypeVal), (yyvsp[(13) - (15)].PositiveDecimalTypeVal), (yyvsp[(14) - (15)].XmlPositiveIntegerVal), (yyvsp[(15) - (15)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 234:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].PhysicalLocationTypeListVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 235:

    {(yyval.VacuumEffectorTypeVal) = new VacuumEffectorType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].PhysicalLocationTypeListVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 236:

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

