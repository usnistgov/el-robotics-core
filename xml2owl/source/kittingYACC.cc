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
     MODELFORMATNAMEEND = 341,
     MODELFORMATNAMESTART = 342,
     MODELNAMEEND = 343,
     MODELNAMESTART = 344,
     NAMEEND = 345,
     NAMESTART = 346,
     OBJECTONTABLEEND = 347,
     OBJECTONTABLESTART = 348,
     OBJECTEND = 349,
     OBJECTSTART = 350,
     ORIENTATIONSTANDARDDEVIATIONEND = 351,
     ORIENTATIONSTANDARDDEVIATIONSTART = 352,
     OTHEROBSTACLEEND = 353,
     OTHEROBSTACLESTART = 354,
     PARTNAMEEND = 355,
     PARTNAMESTART = 356,
     PARTQUANTITYEND = 357,
     PARTQUANTITYSTART = 358,
     PARTREFANDPOSENAMEEND = 359,
     PARTREFANDPOSENAMESTART = 360,
     PARTREFANDPOSEEND = 361,
     PARTREFANDPOSESTART = 362,
     PARTSKUNAMEEND = 363,
     PARTSKUNAMESTART = 364,
     PARTEND = 365,
     PARTSTART = 366,
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
     SKUNAMEEND = 381,
     SKUNAMESTART = 382,
     SKUEND = 383,
     SKUSTART = 384,
     SLOTEND = 385,
     SLOTSTART = 386,
     TIMESTAMPEND = 387,
     TIMESTAMPSTART = 388,
     WEIGHTUNITEND = 389,
     WEIGHTUNITSTART = 390,
     WEIGHTEND = 391,
     WEIGHTSTART = 392,
     WIDTHEND = 393,
     WIDTHSTART = 394,
     WORKVOLUMEEND = 395,
     WORKVOLUMESTART = 396,
     XAXISEND = 397,
     XAXISSTART = 398,
     XEND = 399,
     XSTART = 400,
     YEND = 401,
     YSTART = 402,
     ZAXISEND = 403,
     ZAXISSTART = 404,
     ZEND = 405,
     ZSTART = 406,
     BOXVOLUMETYPEDECL = 407,
     BOXYSHAPETYPEDECL = 408,
     CYLINDRICALSHAPETYPEDECL = 409,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 410,
     ENDEFFECTORHOLDERTYPEDECL = 411,
     ENDEFFECTORTYPEDECL = 412,
     EXTERNALSHAPETYPEDECL = 413,
     GRIPPEREFFECTORTYPEDECL = 414,
     HUMANTYPEDECL = 415,
     INTERNALSHAPETYPEDECL = 416,
     KITDESIGNTYPEDECL = 417,
     KITTRAYTYPEDECL = 418,
     KITTYPEDECL = 419,
     KITTINGWORKSTATIONTYPEDECL = 420,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 421,
     LARGEBOXWITHKITSTYPEDECL = 422,
     LARGECONTAINERTYPEDECL = 423,
     MECHANICALCOMPONENTTYPEDECL = 424,
     NOSKUOBJECTTYPEDECL = 425,
     PARTREFANDPOSETYPEDECL = 426,
     PARTTYPEDECL = 427,
     PARTSBINTYPEDECL = 428,
     PARTSTRAYTYPEDECL = 429,
     PARTSVESSELTYPEDECL = 430,
     PHYSICALLOCATIONTYPEDECL = 431,
     POINTTYPEDECL = 432,
     POSELOCATIONINTYPEDECL = 433,
     POSELOCATIONONTYPEDECL = 434,
     POSELOCATIONTYPEDECL = 435,
     POSEONLYLOCATIONTYPEDECL = 436,
     RELATIVELOCATIONINTYPEDECL = 437,
     RELATIVELOCATIONONTYPEDECL = 438,
     RELATIVELOCATIONTYPEDECL = 439,
     ROBOTTYPEDECL = 440,
     SHAPEDESIGNTYPEDECL = 441,
     SKUOBJECTTYPEDECL = 442,
     SLOTTYPEDECL = 443,
     STOCKKEEPINGUNITTYPEDECL = 444,
     VACUUMEFFECTORMULTICUPTYPEDECL = 445,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 446,
     VACUUMEFFECTORTYPEDECL = 447,
     VECTORTYPEDECL = 448,
     WORKTABLETYPEDECL = 449
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
  NoSkuObjectType *                   NoSkuObjectTypeVal;
  std::list<PartRefAndPoseType *> *   PartRefAndPoseTypeListVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  std::list<PartType *> *             PartTypeListVal;
  PartType *                          PartTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsVesselType *                   PartsVesselTypeVal;
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
  SkuObjectType *                     SkuObjectTypeVal;
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
#define YYLAST   610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  195
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  184
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNRULES -- Number of states.  */
#define YYNSTATES  720

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   449

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
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194
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
     264,   271,   275,   279,   280,   283,   295,   299,   300,   303,
     319,   326,   330,   331,   337,   338,   344,   345,   351,   355,
     362,   366,   367,   373,   374,   380,   381,   382,   388,   389,
     395,   399,   400,   403,   407,   409,   412,   413,   414,   420,
     424,   425,   428,   429,   430,   436,   437,   443,   444,   450,
     457,   461,   463,   466,   467,   473,   480,   484,   485,   488,
     490,   492,   494,   496,   498,   504,   508,   510,   512,   514,
     515,   516,   522,   526,   527,   533,   544,   548,   552,   553,
     556,   557,   563,   564,   570,   574,   576,   579,   584,   588,
     589,   592,   594,   596,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   620,   622,   624,   626,   628,
     636,   637,   638,   644,   650,   651,   657,   658,   664,   665,
     671,   675,   677,   680,   684,   685,   691,   692,   698,   702,
     703,   709,   719,   728,   738,   747,   759,   767,   775,   788,
     805,   815,   827,   835,   843,   851,   862,   873,   884,   895,
     906,   913,   920,   932,   948,   962
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     196,     0,    -1,   208,    71,   197,   269,    70,    -1,    11,
     198,    -1,     8,    10,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     9,    13,    10,     7,    -1,     9,    13,
      10,     5,    10,     7,    -1,    -1,    15,     6,   210,     4,
      14,    -1,    -1,    17,     6,   212,   206,    16,    -1,    -1,
      19,     6,   214,     4,    18,    -1,    21,   279,    20,    -1,
       6,   287,   278,   280,    -1,    -1,    23,     6,   218,   206,
      22,    -1,    25,   228,    24,    -1,    -1,    27,     6,   221,
       4,    26,    -1,    -1,    29,     6,   223,   207,    28,    -1,
      -1,    31,     6,   225,   203,    30,    -1,    -1,    33,     6,
     227,     4,    32,    -1,     6,   287,   317,   323,   250,   238,
     215,   231,    -1,     6,   287,   317,   323,   250,   238,   236,
      -1,    35,   229,    34,    -1,   230,    -1,   231,   230,    -1,
      -1,    37,     6,   233,   203,    36,    -1,    -1,   234,   232,
      -1,   358,    -1,   376,    -1,   377,    -1,    -1,    39,   235,
      38,    -1,     6,   287,   222,   241,   283,   281,   285,    -1,
      -1,    41,   237,    40,    -1,    -1,    43,     6,   240,   199,
      42,    -1,    -1,    45,   314,    44,    -1,    -1,    47,     6,
     243,   199,    46,    -1,    -1,    49,     6,   245,     4,    48,
      -1,    -1,    51,   333,    50,    -1,    -1,    53,     6,   248,
     201,    52,    -1,   354,    -1,   355,    -1,    -1,    55,   249,
      54,    -1,    -1,    57,     6,   252,   201,    56,    -1,    -1,
      59,     6,   254,   201,    58,    -1,    -1,    61,     6,   256,
     203,    60,    -1,     6,   287,   260,   305,    -1,    63,   257,
      62,    -1,   258,    -1,   259,   258,    -1,    -1,    65,     6,
     261,   203,    64,    -1,     6,   287,   317,   323,   326,   324,
      -1,    67,   262,    66,    -1,    67,   262,    66,    -1,    -1,
     265,   264,    -1,     6,   287,   317,   323,   250,   238,   224,
     263,   310,   332,   239,    -1,    69,   266,    68,    -1,    -1,
     268,   267,    -1,     6,   287,   317,   323,   250,   238,   209,
     219,   259,   272,   292,   296,   321,   329,   338,    -1,     6,
     287,   317,   323,   326,   324,    -1,    73,   270,    72,    -1,
      -1,    75,     6,   273,     4,    74,    -1,    -1,    77,     6,
     275,     4,    76,    -1,    -1,    79,     6,   277,     4,    78,
      -1,    81,   312,    80,    -1,     6,   287,   317,   323,   250,
     238,    -1,    83,   312,    82,    -1,    -1,    85,     6,   282,
     207,    84,    -1,    -1,    87,     6,   284,   207,    86,    -1,
      -1,    -1,    89,     6,   286,   207,    88,    -1,    -1,    91,
       6,   288,   202,    90,    -1,    93,   333,    92,    -1,    -1,
     290,   289,    -1,    95,   333,    94,    -1,   291,    -1,   292,
     291,    -1,    -1,    -1,    97,     6,   294,     4,    96,    -1,
      99,   216,    98,    -1,    -1,   296,   295,    -1,    -1,    -1,
     101,     6,   298,   203,   100,    -1,    -1,   103,     6,   300,
     205,   102,    -1,    -1,   105,     6,   302,   203,   104,    -1,
       6,   287,   326,   313,   346,   351,    -1,   107,   303,   106,
      -1,   304,    -1,   305,   304,    -1,    -1,   109,     6,   307,
     203,   108,    -1,     6,   287,   317,   323,   326,   324,    -1,
     111,   308,   110,    -1,    -1,   310,   309,    -1,   370,    -1,
     371,    -1,   372,    -1,   373,    -1,   374,    -1,     6,   287,
     347,   349,   352,    -1,   113,   312,   112,    -1,   370,    -1,
     371,    -1,   372,    -1,    -1,    -1,   115,     6,   316,     4,
     114,    -1,   117,   311,   116,    -1,    -1,   119,     6,   319,
     203,   118,    -1,     6,   287,   317,   323,   250,   238,   222,
     236,   276,   345,    -1,   121,   320,   120,    -1,   123,   311,
     122,    -1,    -1,   323,   322,    -1,    -1,   125,     6,   325,
     204,   124,    -1,    -1,   127,     6,   327,   203,   126,    -1,
     129,   334,   128,    -1,   328,    -1,   329,   328,    -1,     6,
     287,   301,   297,    -1,   131,   330,   130,    -1,    -1,   332,
     331,    -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,
     360,    -1,   361,    -1,   362,    -1,   363,    -1,   364,    -1,
     365,    -1,   366,    -1,   367,    -1,   368,    -1,   369,    -1,
     375,    -1,   376,    -1,   377,    -1,   378,    -1,     6,   287,
     222,   250,   238,   340,   234,    -1,    -1,    -1,   133,     6,
     336,   200,   132,    -1,     6,   287,   247,   251,   253,    -1,
      -1,   135,     6,   339,     4,   134,    -1,    -1,   137,     6,
     341,     4,   136,    -1,    -1,   139,     6,   343,     4,   138,
      -1,   141,   216,   140,    -1,   344,    -1,   345,   344,    -1,
     143,   337,   142,    -1,    -1,   145,     6,   348,   201,   144,
      -1,    -1,   147,     6,   350,   201,   146,    -1,   149,   337,
     148,    -1,    -1,   151,     6,   353,   201,   150,    -1,   153,
       6,   287,   222,   241,   274,   342,   244,   242,    -1,   154,
       6,   287,   222,   241,   226,   244,   242,    -1,   155,     6,
     287,   317,   323,   250,   238,   215,   231,    -1,   156,     6,
     287,   317,   323,   250,   238,   236,    -1,   159,     6,   287,
     317,   323,   250,   238,   222,   340,   276,   246,    -1,   160,
       6,   287,   317,   323,   250,   238,    -1,   163,     6,   287,
     317,   323,   326,   324,    -1,   164,     6,   287,   317,   323,
     250,   238,   224,   263,   310,   332,   239,    -1,   165,     6,
     287,   317,   323,   250,   238,   209,   219,   259,   272,   292,
     296,   321,   329,   338,    -1,   166,     6,   287,   317,   323,
     250,   238,   271,   265,    -1,   167,     6,   287,   317,   323,
     250,   238,   271,   268,   255,   217,    -1,   168,     6,   287,
     317,   323,   326,   324,    -1,   169,     6,   287,   317,   323,
     250,   238,    -1,   172,     6,   287,   317,   323,   326,   324,
      -1,   173,     6,   287,   317,   323,   326,   324,   306,   299,
     310,    -1,   174,     6,   287,   317,   323,   326,   324,   306,
     299,   310,    -1,   178,     6,   287,   318,   335,   313,   346,
     351,   315,   293,    -1,   179,     6,   287,   318,   335,   313,
     346,   351,   315,   293,    -1,   181,     6,   287,   318,   335,
     313,   346,   351,   315,   293,    -1,   182,     6,   287,   318,
     335,   222,    -1,   183,     6,   287,   318,   335,   222,    -1,
     185,     6,   287,   317,   323,   250,   238,   222,   236,   276,
     345,    -1,   190,     6,   287,   317,   323,   250,   238,   222,
     340,   276,   246,   220,   274,   211,   213,    -1,   191,     6,
     287,   317,   323,   250,   238,   222,   340,   276,   246,   220,
     274,    -1,   194,     6,   287,   317,   323,   250,   238,   290,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   444,   444,   454,   459,   465,   473,   481,   489,   497,
     505,   513,   521,   529,   537,   542,   553,   553,   561,   561,
     567,   567,   576,   581,   587,   587,   593,   599,   599,   608,
     608,   614,   614,   620,   620,   628,   638,   647,   653,   656,
     663,   663,   670,   671,   677,   679,   681,   687,   688,   693,
     701,   702,   707,   707,   713,   714,   719,   719,   724,   724,
     733,   734,   739,   739,   744,   746,   752,   753,   758,   758,
     763,   763,   768,   768,   774,   780,   785,   788,   794,   794,
     800,   807,   812,   818,   819,   825,   835,   841,   842,   848,
     861,   868,   873,   873,   882,   882,   890,   890,   899,   904,
     912,   917,   917,   923,   923,   930,   931,   931,   936,   936,
     941,   947,   948,   955,   960,   963,   970,   971,   971,   980,
     986,   987,   995,   996,   996,  1001,  1001,  1007,  1007,  1013,
    1019,  1024,  1027,  1034,  1034,  1040,  1047,  1053,  1054,  1060,
    1062,  1064,  1066,  1068,  1073,  1079,  1084,  1086,  1088,  1094,
    1095,  1095,  1104,  1109,  1109,  1115,  1126,  1131,  1138,  1139,
    1146,  1146,  1152,  1152,  1157,  1162,  1165,  1171,  1177,  1183,
    1184,  1190,  1192,  1194,  1196,  1198,  1200,  1202,  1204,  1206,
    1208,  1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,  1229,
    1238,  1239,  1239,  1245,  1251,  1251,  1260,  1260,  1268,  1268,
    1276,  1281,  1284,  1290,  1295,  1295,  1300,  1300,  1305,  1310,
    1310,  1315,  1325,  1335,  1348,  1360,  1374,  1385,  1395,  1408,
    1424,  1436,  1449,  1459,  1470,  1480,  1492,  1504,  1515,  1526,
    1537,  1546,  1555,  1569,  1585,  1600
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
  "MODELFORMATNAMEEND", "MODELFORMATNAMESTART", "MODELNAMEEND",
  "MODELNAMESTART", "NAMEEND", "NAMESTART", "OBJECTONTABLEEND",
  "OBJECTONTABLESTART", "OBJECTEND", "OBJECTSTART",
  "ORIENTATIONSTANDARDDEVIATIONEND", "ORIENTATIONSTANDARDDEVIATIONSTART",
  "OTHEROBSTACLEEND", "OTHEROBSTACLESTART", "PARTNAMEEND", "PARTNAMESTART",
  "PARTQUANTITYEND", "PARTQUANTITYSTART", "PARTREFANDPOSENAMEEND",
  "PARTREFANDPOSENAMESTART", "PARTREFANDPOSEEND", "PARTREFANDPOSESTART",
  "PARTSKUNAMEEND", "PARTSKUNAMESTART", "PARTEND", "PARTSTART", "POINTEND",
  "POINTSTART", "POSITIONSTANDARDDEVIATIONEND",
  "POSITIONSTANDARDDEVIATIONSTART", "PRIMARYLOCATIONEND",
  "PRIMARYLOCATIONSTART", "REFOBJECTNAMEEND", "REFOBJECTNAMESTART",
  "ROBOTEND", "ROBOTSTART", "SECONDARYLOCATIONEND",
  "SECONDARYLOCATIONSTART", "SERIALNUMBEREND", "SERIALNUMBERSTART",
  "SKUNAMEEND", "SKUNAMESTART", "SKUEND", "SKUSTART", "SLOTEND",
  "SLOTSTART", "TIMESTAMPEND", "TIMESTAMPSTART", "WEIGHTUNITEND",
  "WEIGHTUNITSTART", "WEIGHTEND", "WEIGHTSTART", "WIDTHEND", "WIDTHSTART",
  "WORKVOLUMEEND", "WORKVOLUMESTART", "XAXISEND", "XAXISSTART", "XEND",
  "XSTART", "YEND", "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "BOXVOLUMETYPEDECL", "BOXYSHAPETYPEDECL", "CYLINDRICALSHAPETYPEDECL",
  "ENDEFFECTORCHANGINGSTATIONTYPEDECL", "ENDEFFECTORHOLDERTYPEDECL",
  "ENDEFFECTORTYPEDECL", "EXTERNALSHAPETYPEDECL",
  "GRIPPEREFFECTORTYPEDECL", "HUMANTYPEDECL", "INTERNALSHAPETYPEDECL",
  "KITDESIGNTYPEDECL", "KITTRAYTYPEDECL", "KITTYPEDECL",
  "KITTINGWORKSTATIONTYPEDECL", "LARGEBOXWITHEMPTYKITTRAYSTYPEDECL",
  "LARGEBOXWITHKITSTYPEDECL", "LARGECONTAINERTYPEDECL",
  "MECHANICALCOMPONENTTYPEDECL", "NOSKUOBJECTTYPEDECL",
  "PARTREFANDPOSETYPEDECL", "PARTTYPEDECL", "PARTSBINTYPEDECL",
  "PARTSTRAYTYPEDECL", "PARTSVESSELTYPEDECL", "PHYSICALLOCATIONTYPEDECL",
  "POINTTYPEDECL", "POSELOCATIONINTYPEDECL", "POSELOCATIONONTYPEDECL",
  "POSELOCATIONTYPEDECL", "POSEONLYLOCATIONTYPEDECL",
  "RELATIVELOCATIONINTYPEDECL", "RELATIVELOCATIONONTYPEDECL",
  "RELATIVELOCATIONTYPEDECL", "ROBOTTYPEDECL", "SHAPEDESIGNTYPEDECL",
  "SKUOBJECTTYPEDECL", "SLOTTYPEDECL", "STOCKKEEPINGUNITTYPEDECL",
  "VACUUMEFFECTORMULTICUPTYPEDECL", "VACUUMEFFECTORSINGLECUPTYPEDECL",
  "VACUUMEFFECTORTYPEDECL", "VECTORTYPEDECL", "WORKTABLETYPEDECL",
  "$accept", "y_KittingWorkstationFile",
  "y_XmlHeaderForKittingWorkstation", "y_SchemaLocation", "y_XmlBoolean",
  "y_XmlDateTime", "y_XmlDecimal", "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN",
  "y_XmlNonNegativeInteger", "y_XmlPositiveInteger", "y_XmlString",
  "y_XmlVersion", "y_AngleUnit_AngleUnitType", "$@1",
  "y_ArrayNumber_XmlPositiveInteger", "$@2",
  "y_ArrayRadius_PositiveDecimalType", "$@3",
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
  "y_ModelFormatName_XmlString", "$@22", "y_ModelName_XmlString_0", "$@23",
  "y_Name_XmlID", "$@24", "y_ObjectOnTable_SolidObjectType_0_u",
  "y_ObjectOnTable_SolidObjectType_0_uList", "y_Object_SolidObjectType_u",
  "y_Object_SolidObjectType_uList",
  "y_OrientationStandardDeviation_PositiveDecimalType_0", "$@25",
  "y_OtherObstacle_BoxVolumeType_0_u",
  "y_OtherObstacle_BoxVolumeType_0_uList", "y_PartName_XmlIDREF_0", "$@26",
  "y_PartQuantity_XmlNonNegativeInteger", "$@27",
  "y_PartRefAndPoseName_XmlIDREF", "$@28", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u",
  "y_PartRefAndPose_PartRefAndPoseType_uList", "y_PartSkuName_XmlIDREF",
  "$@29", "y_PartType", "y_Part_PartType_0_u", "y_Part_PartType_0_uList",
  "y_PhysicalLocationTypeAny", "y_PointType", "y_Point_PointType",
  "y_PoseLocationTypeAny",
  "y_PositionStandardDeviation_PositiveDecimalType_0", "$@30",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObjectName_XmlIDREF",
  "$@31", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SecondaryLocation_PhysicalLocationType_0_uList",
  "y_SerialNumber_XmlNMTOKEN", "$@32", "y_SkuName_XmlIDREF", "$@33",
  "y_Sku_StockKeepingUnitType_u", "y_Sku_StockKeepingUnitType_uList",
  "y_SlotType", "y_Slot_SlotType_0_u", "y_Slot_SlotType_0_uList",
  "y_SolidObjectTypeAny", "y_StockKeepingUnitType",
  "y_Timestamp_XmlDateTime_0", "$@34", "y_VectorType",
  "y_WeightUnit_WeightUnitType", "$@35", "y_Weight_PositiveDecimalType",
  "$@36", "y_Width_PositiveDecimalType", "$@37",
  "y_WorkVolume_BoxVolumeType_u", "y_WorkVolume_BoxVolumeType_uList",
  "y_XAxis_VectorType", "y_X_XmlDecimal", "$@38", "y_Y_XmlDecimal", "$@39",
  "y_ZAxis_VectorType", "y_Z_XmlDecimal", "$@40", "y_x_BoxyShapeType",
  "y_x_CylindricalShapeType", "y_x_EndEffectorChangingStationType",
  "y_x_EndEffectorHolderType", "y_x_GripperEffectorType", "y_x_HumanType",
  "y_x_KitTrayType", "y_x_KitType", "y_x_KittingWorkstationType",
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
     445,   446,   447,   448,   449
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   208,   210,   209,   212,   211,
     214,   213,   215,   216,   218,   217,   219,   221,   220,   223,
     222,   225,   224,   227,   226,   228,   229,   230,   231,   231,
     233,   232,   234,   234,   235,   235,   235,   236,   236,   237,
     238,   238,   240,   239,   241,   241,   243,   242,   245,   244,
     246,   246,   248,   247,   249,   249,   250,   250,   252,   251,
     254,   253,   256,   255,   257,   258,   259,   259,   261,   260,
     262,   263,   264,   265,   265,   266,   267,   268,   268,   269,
     270,   271,   273,   272,   275,   274,   277,   276,   278,   279,
     280,   282,   281,   284,   283,   285,   286,   285,   288,   287,
     289,   290,   290,   291,   292,   292,   293,   294,   293,   295,
     296,   296,   297,   298,   297,   300,   299,   302,   301,   303,
     304,   305,   305,   307,   306,   308,   309,   310,   310,   311,
     311,   311,   311,   311,   312,   313,   314,   314,   314,   315,
     316,   315,   317,   319,   318,   320,   321,   322,   323,   323,
     325,   324,   327,   326,   328,   329,   329,   330,   331,   332,
     332,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   334,
     335,   336,   335,   337,   339,   338,   341,   340,   343,   342,
     344,   345,   345,   346,   348,   347,   350,   349,   351,   353,
     352,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378
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
       6,     3,     3,     0,     2,    11,     3,     0,     2,    15,
       6,     3,     0,     5,     0,     5,     0,     5,     3,     6,
       3,     0,     5,     0,     5,     0,     0,     5,     0,     5,
       3,     0,     2,     3,     1,     2,     0,     0,     5,     3,
       0,     2,     0,     0,     5,     0,     5,     0,     5,     6,
       3,     1,     2,     0,     5,     6,     3,     0,     2,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     1,     0,
       0,     5,     3,     0,     5,    10,     3,     3,     0,     2,
       0,     5,     0,     5,     3,     1,     2,     4,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     0,     5,     5,     0,     5,     0,     5,     0,     5,
       3,     1,     2,     3,     0,     5,     0,     5,     3,     0,
       5,     9,     8,     9,     8,    11,     7,     7,    12,    16,
       9,    11,     7,     7,     7,    10,    10,    10,    10,    10,
       6,     6,    11,    15,    13,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    14,     0,     3,     0,     0,     0,     4,     0,     0,
       2,    15,   108,     0,   158,     0,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,    66,     8,     0,
       0,     0,     0,     0,     0,   152,     0,     0,    50,   159,
     109,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,     0,     0,     0,     0,   190,   190,   190,   190,   190,
       0,     0,    67,   157,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    16,
       0,     0,     0,   191,     0,     0,     0,     0,     0,   230,
     231,    54,    54,    54,     0,     0,     0,     0,    76,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
      77,     0,   154,     6,     0,     0,   145,     0,     0,     0,
     149,   149,   149,     0,     0,   146,   147,   148,     0,     0,
       0,     0,     0,     0,    17,   158,     0,    75,    92,     0,
     114,   120,   192,     0,     0,     0,   203,     0,     0,   116,
     116,   116,    13,     0,    55,    94,     0,     0,    33,     0,
       0,   103,     0,   105,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   115,     0,   204,     0,     0,
       0,     0,   208,   150,     0,   227,   228,   229,    30,     0,
     198,     0,     0,    58,     0,   212,     0,   101,     0,    49,
      50,    78,     0,   131,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,   121,     0,     0,
     206,     0,   144,    62,     0,     0,     0,   117,     0,     0,
     211,     0,     0,    56,     0,     0,   106,     0,     0,     0,
       0,   132,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     7,     0,
       0,   209,     0,    68,     0,   193,     0,     0,    95,     0,
      34,     0,     0,   104,     0,     0,     0,     0,     0,     0,
     130,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,     0,
     119,     0,   156,     0,     0,     0,   166,    89,   205,     0,
       0,     0,     0,    70,   151,     0,   199,    59,     5,     0,
     102,     0,     0,     0,     0,    38,    35,    79,     0,     0,
      66,    66,    66,    66,     0,    66,    66,    66,    66,     0,
      66,     0,     0,     0,    66,    66,    66,    66,     0,     0,
     158,     0,   164,   194,   207,     0,    63,     0,     0,   118,
      57,   107,     0,    22,     0,     0,    39,   162,     0,    50,
      50,    50,    50,     0,    50,    50,    50,    50,     0,    50,
       0,     0,     0,    50,    50,    50,    50,     0,     0,    23,
      66,    66,     0,   210,    69,     0,   158,     0,    37,     0,
       0,     0,    47,     0,   216,     0,   217,     0,     0,     0,
       0,   222,   223,   224,     0,     0,     0,     0,     0,   111,
      98,     0,    50,    50,     0,    71,    66,   158,     0,   129,
       0,     0,   214,     0,   160,     0,     0,     0,     0,    83,
      87,     0,     0,     0,    47,     0,     0,   235,   100,     0,
       0,   195,    50,    66,   163,   213,     0,    44,    45,    46,
       0,     0,     0,    31,     0,   137,     0,     0,     0,   220,
       0,   133,     0,   137,   137,     0,     0,     0,     0,   112,
      47,    42,    99,    50,    48,   196,     0,    60,    10,     0,
       0,     0,     0,   169,     0,     0,    91,     0,    84,     0,
       0,     0,    88,     0,   125,   225,   226,     0,    60,    60,
       0,     0,   189,    47,     0,    96,     0,   215,   161,     0,
       0,    81,     0,   138,     0,     0,   158,     0,    72,     0,
       0,     0,   221,     0,     0,     0,   201,   232,     0,     0,
     110,     0,     0,    43,    36,     0,     0,     0,    32,   158,
       0,     0,     0,     0,   218,   170,   120,     0,    82,     0,
       0,    86,    24,   134,    11,     0,     0,   202,     0,     0,
       0,   155,    40,   197,     0,    61,     0,     0,   136,    52,
       0,     0,     0,     0,     0,   158,     0,   126,   200,    27,
       0,   234,     0,    97,     0,   158,     0,     0,   168,     0,
      90,    73,    66,    12,     0,     0,     0,     0,     0,    80,
       0,     0,     0,   122,     0,    50,    25,     0,    18,     0,
     233,    41,     0,    53,   127,     0,   167,   219,     0,    28,
       0,    20,   135,     0,   123,     0,     0,     0,     0,     0,
     137,    19,     0,   128,     0,   169,    21,   124,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,   389,   134,   329,    39,   111,   559,
     635,   674,   173,     3,    77,   104,   677,   700,   690,   707,
     347,   322,   602,   656,    91,   639,   675,    99,   143,   506,
     560,   151,   242,   106,   435,   395,   396,   613,   662,   582,
     526,   502,    75,    63,   624,   666,   121,   245,   342,   180,
     292,   587,   231,   332,    58,    48,   285,   382,   335,   428,
     571,   629,   128,   108,   109,   186,   298,   562,   535,   568,
     539,   600,   572,   540,    15,   538,   509,   131,   187,   149,
     239,   557,   616,   419,   393,   459,   183,   295,   153,   246,
     249,   345,    19,    25,   549,   517,   160,   161,   235,   337,
     277,   226,   696,   709,   543,   604,   683,   703,   300,   253,
     254,   512,   573,   621,   593,   563,    31,   114,    95,   144,
     169,   286,    24,    65,    92,   324,   278,    49,    37,   476,
     532,   399,   469,   326,   327,   651,   625,   594,   206,   374,
      80,   112,   138,   377,   462,   531,   584,   177,   289,   606,
     607,   116,   164,   279,   229,   330,   140,   282,   380,    59,
      60,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    32,    33,    34,    35,    36,
     221,   222,   223,   224
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -561
static const yytype_int16 yypact[] =
{
      26,    27,    43,   -12,    52,  -561,    74,    89,    87,   112,
     113,  -561,   116,  -561,    36,    65,   129,  -561,   134,    24,
    -561,  -561,  -561,  -126,  -561,   138,   137,   139,   141,   142,
     143,    28,  -561,  -561,  -561,  -561,  -561,   -30,  -561,    61,
      36,    36,    36,    36,    36,  -561,   -46,  -126,   111,  -561,
    -561,    34,    34,    34,    34,    34,   148,   151,   104,  -561,
    -561,    38,   155,   147,   157,    31,    31,    31,    31,    31,
      36,    36,  -561,  -561,    36,   125,   160,   144,  -561,   161,
      55,    55,    55,   145,   145,   145,   145,   145,  -561,  -561,
     164,   108,   168,  -561,   167,    32,    32,    32,   170,  -561,
    -561,   132,   132,   132,   174,    36,   156,   173,  -561,   -24,
    -561,    63,   178,    36,    90,   195,    54,    54,    54,  -561,
     -89,   128,   175,   119,   196,    24,  -561,    36,   149,   203,
    -561,   117,  -561,  -561,    81,    69,  -561,    36,    73,   195,
     120,   120,   120,   230,   192,  -561,  -561,  -561,   231,    99,
     237,   199,   244,   172,  -561,  -561,   187,  -561,  -561,   -35,
    -561,   117,  -561,   252,   131,   226,  -561,   136,   276,   188,
     188,   188,  -561,   268,  -561,  -561,   300,   199,  -561,   301,
     261,  -561,   303,   221,   -30,   307,   207,   311,   310,   312,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   324,
     325,   326,   328,   331,   332,   336,   223,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,   -67,  -561,   337,   193,
     340,   291,  -561,  -561,   343,  -561,  -561,  -561,  -561,   346,
    -561,   261,   347,  -561,   348,  -561,   230,  -561,   349,  -561,
     111,  -561,   350,  -561,   207,   279,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,  -561,   352,   353,  -561,   232,   356,
    -561,   357,  -561,  -561,   358,   306,   364,  -561,   295,   368,
    -561,   341,   370,  -561,   290,   230,  -561,   359,   168,    36,
     271,  -561,  -561,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    36,   280,    36,   259,   375,  -561,   -87,  -561,   238,
     356,  -561,   356,  -561,   377,  -561,   270,   381,  -561,   248,
    -561,   339,   384,  -561,   305,   230,   385,   355,   329,   265,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,   323,
    -561,    24,  -561,    36,   267,   390,  -561,  -561,  -561,   253,
     356,   351,   356,  -561,  -561,   302,  -561,  -561,  -561,   361,
    -561,   327,    36,   382,   399,  -561,   355,  -561,   402,    55,
     -30,   -30,   -30,   -30,   -41,   -30,   -30,   -30,   -30,   -41,
     -30,   -41,   -41,   -41,   -30,   -30,   -30,   -30,   167,   330,
    -561,   145,  -561,  -561,  -561,   264,  -561,   360,   356,  -561,
    -561,  -561,    24,  -561,    36,   383,  -561,  -561,    32,   111,
     111,   111,   111,   284,   111,   111,   111,   111,   284,   111,
     284,   284,   284,   111,   111,   111,   111,   338,   167,  -561,
     -30,   365,   415,  -561,  -561,   363,  -561,    24,  -561,   168,
      54,   359,   386,   145,  -561,   416,  -561,   392,   147,   354,
     354,  -561,  -561,  -561,   333,   333,   145,   145,   145,  -561,
    -561,   342,   111,   111,   292,  -561,   -30,  -561,   304,  -561,
     355,  -130,  -561,   294,  -561,   422,   362,   144,   426,  -561,
    -561,   427,   334,   334,   386,   294,   294,   345,  -561,   145,
     294,  -561,   111,   -30,  -561,   355,   396,  -561,  -561,  -561,
     429,   367,   432,  -561,   433,  -561,   108,    36,   372,   373,
     -28,  -561,   442,  -561,  -561,   367,   367,   367,   -35,  -561,
     386,  -561,  -561,   111,  -561,  -561,   443,   400,  -561,   335,
     168,    36,   387,   344,   -24,    24,  -561,   433,  -561,   444,
     446,   431,  -561,   168,  -561,   344,   344,   366,   400,   400,
     369,   367,   419,   386,   453,  -561,   -35,  -561,  -561,   428,
      24,  -561,   454,  -561,   -22,   117,  -561,   397,  -561,    36,
     398,   458,  -561,   371,   461,   352,  -561,   366,   440,   440,
    -561,   366,   462,  -561,  -561,   376,   465,   423,  -561,  -561,
      36,   374,   466,   468,  -561,  -561,   117,   -41,  -561,   168,
      24,  -561,  -561,  -561,  -561,   378,   379,  -561,   469,   128,
     128,   366,  -561,  -561,   403,  -561,   -41,    24,  -561,  -561,
      36,   388,   -67,   284,   417,  -561,   472,  -561,  -561,  -561,
     470,  -561,   168,  -561,   284,  -561,   384,   380,  -561,   232,
    -561,  -561,   -30,  -561,   456,   478,   477,   467,   452,  -561,
     -41,   447,   484,   391,   -87,   111,  -561,   473,  -561,   485,
    -561,  -561,   284,  -561,  -561,   487,  -561,  -561,   392,  -561,
     472,  -561,  -561,   168,  -561,   362,   479,   490,   394,   168,
    -561,  -561,   482,  -561,   401,   344,  -561,  -561,   -22,  -561
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -561,  -561,  -561,  -561,  -170,  -561,  -306,  -561,  -262,  -561,
    -561,  -198,  -226,  -561,    25,  -561,  -561,  -561,  -561,  -561,
      33,   -99,  -561,  -561,     1,  -100,  -561,   -76,  -561,  -185,
    -561,  -561,  -561,  -561,  -561,  -379,    14,  -561,  -561,  -561,
    -561,  -492,  -561,  -152,  -203,  -561,   -53,   275,  -561,   389,
    -561,  -468,  -561,  -561,  -561,  -161,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -102,   -19,  -561,  -561,   -47,  -183,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,    44,   -39,  -561,  -527,
    -561,  -501,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,   -40,  -561,  -561,  -561,  -155,   -72,   -56,  -561,
    -561,   -97,  -561,  -561,    13,  -561,  -561,  -561,  -561,   277,
    -561,    45,  -561,  -561,  -561,  -506,   488,  -391,   -63,  -561,
     -25,  -561,  -120,    47,  -561,  -561,  -118,  -561,   -91,  -373,
    -561,  -341,  -561,  -315,  -137,  -561,  -561,  -179,  -520,  -561,
      37,  -561,   404,  -147,  -561,  -432,  -561,  -561,  -561,  -560,
     -73,   -81,  -561,  -561,  -561,  -561,  -104,  -561,  -561,  -561,
    -561,  -561,  -561,    39,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,   421,   424,   425,  -561,  -561,
    -561,    41,    46,  -561
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      51,    52,    53,    54,    55,   155,   225,   130,   100,   101,
     102,   103,   376,   141,   142,   117,   118,   436,    96,    97,
     294,   622,   545,   250,   379,    46,   381,   457,   580,   190,
      85,    86,   275,   569,    87,     1,   348,   575,   576,   107,
       4,   570,   325,     5,   577,   578,   579,   637,   375,   122,
     123,   129,    26,    27,   276,    28,    29,    30,   581,     6,
     203,   204,     7,   443,   184,   125,   617,   491,   448,   344,
     450,   451,   452,   135,   425,   481,   427,   483,   484,   485,
     611,   637,    47,   546,   547,     8,   398,   156,   551,    26,
      27,   614,    28,    47,    10,    12,    11,   165,   297,    66,
      67,    68,    69,    81,    82,    83,    84,    56,    57,   623,
     608,   609,   660,   661,   236,   237,   170,   171,    14,   391,
     188,   189,   465,    16,   190,   191,    17,    18,   192,   193,
     194,   195,   196,   197,   198,    20,    21,   199,   200,   201,
      22,    23,    38,    40,    45,    41,   436,    42,    43,    44,
     202,    50,    62,    64,    70,   203,   204,    71,    72,   205,
      73,    74,    76,    78,    79,    88,    89,    93,    94,    90,
     105,   107,   110,   113,    98,   115,   119,   120,   124,   127,
     126,   132,   133,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   137,   136,   139,   715,   148,   152,   498,   150,   158,
     154,   157,   159,   162,   163,   166,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   172,   168,   174,   175,   176,   439,
     440,   441,   442,   178,   444,   445,   446,   447,   179,   449,
     181,   420,   185,   453,   454,   455,   456,   182,   227,   349,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   228,   230,
     670,   369,   233,   371,   232,   234,   653,   471,   472,   473,
     474,   679,   477,   478,   479,   480,   238,   482,   589,   492,
     493,   486,   487,   488,   489,   664,   240,   243,   244,   247,
     248,   603,   466,   251,   252,   255,   256,   274,   257,   702,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   460,
     267,   268,   269,   421,   270,   522,   438,   271,   272,   692,
     519,   520,   273,   280,   281,   461,   283,   497,   284,   287,
     288,   291,   432,   302,   293,   296,   299,   470,   321,   323,
     328,   325,   553,   331,   333,   334,   499,   654,   336,   376,
     552,   338,   339,   340,   341,   496,   343,   350,   370,   372,
     346,   373,   378,   383,   384,   385,   386,   387,   388,   390,
     394,   392,   398,   397,   467,   422,   423,   503,   429,   424,
     678,   583,   433,   426,   418,   434,   523,   430,   437,   475,
     514,   515,   516,   458,   463,   431,   464,   468,   490,   494,
      46,   495,   504,   505,   518,   501,   521,   508,   533,   534,
     524,   530,   537,   541,   554,   555,   558,   542,   548,   561,
     567,   708,   511,   550,   566,   596,   556,   714,   574,   585,
     598,   586,   599,   591,   601,   592,   612,   615,   618,   588,
     620,   610,   130,   628,   632,   634,   631,   638,   642,   644,
     619,   225,   649,   645,   650,   659,   673,   671,   686,   633,
     657,   663,   687,   688,   648,   682,   689,   676,   691,   693,
     694,   701,   695,   704,   712,   711,   681,   565,   713,   699,
     716,   717,   706,   507,   500,   627,   636,   605,   536,   640,
     655,   685,   643,   705,   525,   719,   290,   564,   668,   658,
     597,   590,   710,   626,   510,   595,   544,   665,   646,   652,
     513,   301,   684,   698,   669,    61,   718,   697,   641,     0,
     527,   145,   528,   167,   146,   147,     0,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,     0,     0,     0,   672,     0,   241,     0,     0,     0,
       0,     0,     0,     0,   680,     0,     0,     0,     0,     0,
     647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     667
};

static const yytype_int16 yycheck[] =
{
      40,    41,    42,    43,    44,   125,   161,   109,    84,    85,
      86,    87,   327,   117,   118,    96,    97,   396,    81,    82,
     246,    43,   514,   184,   330,    55,   332,   418,   548,   159,
      70,    71,    99,    61,    74,     9,   298,   543,   544,    63,
      13,    69,   129,     0,   545,   546,   547,   607,   135,   102,
     103,    75,   178,   179,   121,   181,   182,   183,   550,    71,
     190,   191,    10,   404,   155,   105,   586,   458,   409,   295,
     411,   412,   413,   113,   380,   448,   382,   450,   451,   452,
     581,   641,   123,   515,   516,    11,   127,   127,   520,   178,
     179,   583,   181,   123,     5,     8,     7,   137,   250,    52,
      53,    54,    55,    66,    67,    68,    69,   153,   154,   131,
     578,   579,   639,   640,   170,   171,   141,   142,     6,   345,
     155,   156,   428,    10,   159,   160,    10,    91,   163,   164,
     165,   166,   167,   168,   169,    70,     7,   172,   173,   174,
       6,   117,     4,     6,   116,     6,   525,     6,     6,     6,
     185,    90,    41,   119,     6,   190,   191,     6,    54,   194,
     122,     6,    15,     6,   133,    40,     6,     6,   113,    25,
       6,    63,     4,     6,    29,   143,     6,    45,     4,     6,
      24,   118,     4,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,     6,   112,   149,   710,    77,    87,   469,    33,     6,
      14,    62,    95,   132,   145,   142,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,     4,   115,    44,     6,   139,   400,
     401,   402,   403,     6,   405,   406,   407,   408,    49,   410,
       6,   371,    65,   414,   415,   416,   417,    85,     6,   299,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   147,    53,
     653,   321,     6,   323,   148,    97,   627,   439,   440,   441,
     442,   664,   444,   445,   446,   447,    28,   449,   560,   460,
     461,   453,   454,   455,   456,   646,     6,     6,    47,     6,
      89,   573,   432,     6,   107,     4,     6,    94,     6,   692,
       6,     6,     6,     6,     6,     6,     6,     6,     6,   420,
       6,     6,     6,   373,     6,   496,   399,     6,     6,   680,
     492,   493,     6,     6,   151,   421,     6,   467,    57,     6,
       4,     4,   392,    74,     6,     6,     6,   438,     6,     6,
       4,   129,   523,     6,     6,    59,   470,   629,     4,   684,
     522,    76,     4,    32,     4,   466,    86,   106,    98,   120,
      21,     6,   144,     6,   114,     4,   138,    48,     4,    84,
      35,     6,   127,    64,   434,   128,     6,   473,    96,   146,
     662,   553,    20,    52,    81,     6,   497,    46,     6,   125,
     486,   487,   488,    83,   150,    88,    56,    34,    80,     4,
      55,    58,     6,    31,    82,    39,   134,    73,     6,    67,
     126,   137,     6,     6,    38,     6,     4,   103,    93,     6,
      67,   703,   109,   519,    72,   565,    79,   709,     6,     6,
       6,    51,     6,    66,    23,   111,    37,     4,    30,   124,
       6,    92,   564,    66,     6,     4,    68,    27,     6,     4,
     590,   626,     6,    50,     6,     6,     4,    60,    22,   108,
     102,    78,     4,     6,   110,   105,    19,    17,    36,    42,
       6,     6,   101,     6,     4,    16,   666,   537,   104,    26,
      18,   100,   700,   478,   471,   596,   605,   141,   507,   609,
     630,   672,   136,   698,   500,   718,   241,   536,   130,   140,
     567,   561,   705,   595,   480,   564,   513,   647,   619,   626,
     485,   254,   669,   685,   652,    47,   715,   684,   611,    -1,
     501,   120,   501,   139,   120,   120,    -1,   501,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,    -1,    -1,    -1,   655,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     650
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   196,   208,    13,     0,    71,    10,    11,   197,
       5,     7,     8,   198,     6,   269,    10,    10,    91,   287,
      70,     7,     6,   117,   317,   288,   178,   179,   181,   182,
     183,   311,   370,   371,   372,   373,   374,   323,     4,   202,
       6,     6,     6,     6,     6,   116,    55,   123,   250,   322,
      90,   287,   287,   287,   287,   287,   153,   154,   249,   354,
     355,   311,    41,   238,   119,   318,   318,   318,   318,   318,
       6,     6,    54,   122,     6,   237,    15,   209,     6,   133,
     335,   335,   335,   335,   335,   287,   287,   287,    40,     6,
      25,   219,   319,     6,   113,   313,   313,   313,    29,   222,
     222,   222,   222,   222,   210,     6,   228,    63,   258,   259,
       4,   203,   336,     6,   312,   143,   346,   346,   346,     6,
      45,   241,   241,   241,     4,   287,    24,     6,   257,    75,
     258,   272,   118,     4,   200,   287,   112,     6,   337,   149,
     351,   351,   351,   223,   314,   370,   371,   372,    77,   274,
      33,   226,    87,   283,    14,   317,   287,    62,     6,    95,
     291,   292,   132,   145,   347,   287,   142,   337,   115,   315,
     315,   315,     4,   207,    44,     6,   139,   342,     6,    49,
     244,     6,    85,   281,   323,    65,   260,   273,   155,   156,
     159,   160,   163,   164,   165,   166,   167,   168,   169,   172,
     173,   174,   185,   190,   191,   194,   333,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   375,   376,   377,   378,   291,   296,     6,   147,   349,
      53,   247,   148,     6,    97,   293,   293,   293,    28,   275,
       6,   244,   227,     6,    47,   242,   284,     6,    89,   285,
     250,     6,   107,   304,   305,     4,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,    94,    99,   121,   295,   321,   348,
       6,   151,   352,     6,    57,   251,   316,     6,     4,   343,
     242,     4,   245,     6,   207,   282,     6,   238,   261,     6,
     303,   304,    74,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,     6,   216,     6,   320,   129,   328,   329,     4,   201,
     350,     6,   248,     6,    59,   253,     4,   294,    76,     4,
      32,     4,   243,    86,   207,   286,    21,   215,   203,   287,
     106,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   287,
      98,   287,   120,     6,   334,   135,   328,   338,   144,   201,
     353,   201,   252,     6,   114,     4,   138,    48,     4,   199,
      84,   207,     6,   279,    35,   230,   231,    64,   127,   326,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,    81,   278,
     317,   287,   128,     6,   146,   201,    52,   201,   254,    96,
      46,    88,   287,    20,     6,   229,   230,     6,   313,   250,
     250,   250,   250,   326,   250,   250,   250,   250,   326,   250,
     326,   326,   326,   250,   250,   250,   250,   312,    83,   280,
     323,   222,   339,   150,    56,   201,   317,   287,    34,   327,
     346,   238,   238,   238,   238,   125,   324,   238,   238,   238,
     238,   324,   238,   324,   324,   324,   238,   238,   238,   238,
      80,   312,   250,   250,     4,    58,   323,   317,   203,   351,
     215,    39,   236,   222,     6,    31,   224,   209,    73,   271,
     271,   109,   306,   306,   222,   222,   222,   290,    82,   238,
     238,   134,   250,   323,   126,   231,   235,   358,   376,   377,
     137,   340,   325,     6,    67,   263,   219,     6,   270,   265,
     268,     6,   103,   299,   299,   236,   340,   340,    93,   289,
     222,   340,   238,   250,    38,     6,    79,   276,     4,   204,
     225,     6,   262,   310,   259,   287,    72,    67,   264,    61,
      69,   255,   267,   307,     6,   310,   310,   276,   276,   276,
     333,   236,   234,   238,   341,     6,    51,   246,   124,   203,
     287,    66,   111,   309,   332,   272,   317,   262,     6,     6,
     266,    23,   217,   203,   300,   141,   344,   345,   246,   246,
      92,   276,    37,   232,   236,     4,   277,   333,    30,   317,
       6,   308,    43,   131,   239,   331,   292,   323,    66,   256,
     287,    68,     6,   108,     4,   205,   216,   344,    27,   220,
     220,   345,     6,   136,     4,    50,   323,   287,   110,     6,
       6,   330,   296,   326,   203,   317,   218,   102,   140,     6,
     274,   274,   233,    78,   326,   317,   240,   287,   130,   321,
     324,    60,   323,     4,   206,   221,    17,   211,   203,   324,
     323,   199,   105,   301,   329,   250,    22,     4,     6,    19,
     213,    36,   326,    42,     6,   101,   297,   338,   238,    26,
     212,     6,   324,   302,     6,   224,   206,   214,   203,   298,
     263,    16,     4,   104,   203,   310,    18,   100,   332,   239
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

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
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

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
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

    {yyReadData = 1;;}
    break;

  case 104:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 105:

    {(yyval.XmlStringVal) = 0;;}
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

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;;}
    break;

  case 112:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 113:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 114:

    {(yyval.SolidObjectTypeListVal) = new std::list<SolidObjectType *>;
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 115:

    {(yyval.SolidObjectTypeListVal) = (yyvsp[(1) - (2)].SolidObjectTypeListVal);
	   (yyval.SolidObjectTypeListVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 116:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 117:

    {yyReadData = 1;;}
    break;

  case 118:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  ;}
    break;

  case 119:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 120:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 121:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 122:

    {(yyval.XmlIDREFVal) = 0;;}
    break;

  case 123:

    {yyReadData = 1;;}
    break;

  case 124:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 125:

    {yyReadData = 1;;}
    break;

  case 126:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 127:

    {yyReadData = 1;;}
    break;

  case 128:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 129:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 130:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 131:

    {(yyval.PartRefAndPoseTypeListVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 132:

    {(yyval.PartRefAndPoseTypeListVal) = (yyvsp[(1) - (2)].PartRefAndPoseTypeListVal);
	   (yyval.PartRefAndPoseTypeListVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 133:

    {yyReadData = 1;;}
    break;

  case 134:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 135:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].PhysicalLocationTypeListVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 136:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 137:

    {(yyval.PartTypeListVal) = new std::list<PartType *>;;}
    break;

  case 138:

    {(yyval.PartTypeListVal) = (yyvsp[(1) - (2)].PartTypeListVal);
	   (yyval.PartTypeListVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 139:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 140:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 141:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 142:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 143:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 144:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 145:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 146:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 147:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 148:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 149:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 150:

    {yyReadData = 1;;}
    break;

  case 151:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  ;}
    break;

  case 152:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 153:

    {yyReadData = 1;;}
    break;

  case 154:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 155:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].PhysicalLocationTypeListVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].BoxVolumeTypeListVal));;}
    break;

  case 156:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 157:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 158:

    {(yyval.PhysicalLocationTypeListVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 159:

    {(yyval.PhysicalLocationTypeListVal) = (yyvsp[(1) - (2)].PhysicalLocationTypeListVal);
	   (yyval.PhysicalLocationTypeListVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 160:

    {yyReadData = 1;;}
    break;

  case 161:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 162:

    {yyReadData = 1;;}
    break;

  case 163:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 164:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 165:

    {(yyval.StockKeepingUnitTypeListVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 166:

    {(yyval.StockKeepingUnitTypeListVal) = (yyvsp[(1) - (2)].StockKeepingUnitTypeListVal);
	   (yyval.StockKeepingUnitTypeListVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 167:

    {(yyval.SlotTypeVal) = new SlotType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));;}
    break;

  case 168:

    {(yyval.SlotTypeVal) = (yyvsp[(2) - (3)].SlotTypeVal);;}
    break;

  case 169:

    {(yyval.SlotTypeListVal) = new std::list<SlotType *>;;}
    break;

  case 170:

    {(yyval.SlotTypeListVal) = (yyvsp[(1) - (2)].SlotTypeListVal);
	   (yyval.SlotTypeListVal)->push_back((yyvsp[(2) - (2)].SlotTypeVal));;}
    break;

  case 171:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 172:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 173:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 174:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].HumanTypeVal);;}
    break;

  case 175:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 176:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 177:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 178:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 179:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 180:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 181:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);;}
    break;

  case 182:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 183:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 184:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 185:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 186:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 187:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 188:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 189:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].InternalShapeTypeVal), (yyvsp[(5) - (7)].ExternalShapeTypeVal), (yyvsp[(6) - (7)].PositiveDecimalTypeVal), (yyvsp[(7) - (7)].IDREFListVal));;}
    break;

  case 190:

    {(yyval.XmlDateTimeVal) = 0;;}
    break;

  case 191:

    {yyReadData = 1;;}
    break;

  case 192:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);;}
    break;

  case 193:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 194:

    {yyReadData = 1;;}
    break;

  case 195:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 196:

    {yyReadData = 1;;}
    break;

  case 197:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 198:

    {yyReadData = 1;;}
    break;

  case 199:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 200:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 201:

    {(yyval.BoxVolumeTypeListVal) = new std::list<BoxVolumeType *>;
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 202:

    {(yyval.BoxVolumeTypeListVal) = (yyvsp[(1) - (2)].BoxVolumeTypeListVal);
	   (yyval.BoxVolumeTypeListVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 203:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 204:

    {yyReadData = 1;;}
    break;

  case 205:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 206:

    {yyReadData = 1;;}
    break;

  case 207:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 208:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 209:

    {yyReadData = 1;;}
    break;

  case 210:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 211:

    {(yyval.BoxyShapeTypeVal) = new BoxyShapeType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlStringVal), (yyvsp[(5) - (9)].PoseLocationTypeVal), (yyvsp[(6) - (9)].PositiveDecimalTypeVal), (yyvsp[(7) - (9)].PositiveDecimalTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].XmlBooleanVal));
	   (yyval.BoxyShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 212:

    {(yyval.CylindricalShapeTypeVal) = new CylindricalShapeType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].XmlStringVal), (yyvsp[(5) - (8)].PoseLocationTypeVal), (yyvsp[(6) - (8)].PositiveDecimalTypeVal), (yyvsp[(7) - (8)].PositiveDecimalTypeVal), (yyvsp[(8) - (8)].XmlBooleanVal));
	   (yyval.CylindricalShapeTypeVal)->printTypp = true;
	  ;}
    break;

  case 213:

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].EndEffectorHolderTypeListVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 214:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].PhysicalLocationTypeListVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 215:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 216:

    {(yyval.HumanTypeVal) = new HumanType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.HumanTypeVal)->printTypp = true;
	  ;}
    break;

  case 217:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 218:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].PhysicalLocationTypeListVal), (yyvsp[(6) - (12)].InternalShapeTypeVal), (yyvsp[(7) - (12)].ExternalShapeTypeVal), (yyvsp[(8) - (12)].XmlIDREFVal), (yyvsp[(9) - (12)].KitTrayTypeVal), (yyvsp[(10) - (12)].PartTypeListVal), (yyvsp[(11) - (12)].SlotTypeListVal), (yyvsp[(12) - (12)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 219:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (16)].XmlIDVal), (yyvsp[(4) - (16)].PhysicalLocationTypeVal), (yyvsp[(5) - (16)].PhysicalLocationTypeListVal), (yyvsp[(6) - (16)].InternalShapeTypeVal), (yyvsp[(7) - (16)].ExternalShapeTypeVal), (yyvsp[(8) - (16)].AngleUnitTypeVal), (yyvsp[(9) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (16)].KitDesignTypeListVal), (yyvsp[(11) - (16)].LengthUnitTypeVal), (yyvsp[(12) - (16)].SolidObjectTypeListVal), (yyvsp[(13) - (16)].BoxVolumeTypeListVal), (yyvsp[(14) - (16)].RobotTypeVal), (yyvsp[(15) - (16)].StockKeepingUnitTypeListVal), (yyvsp[(16) - (16)].WeightUnitTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 220:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].PhysicalLocationTypeListVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].KitTrayTypeListVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 221:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].PhysicalLocationTypeListVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].KitTypeListVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 222:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 223:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  ;}
    break;

  case 224:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].PhysicalLocationTypeListVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 225:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].PartTypeListVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 226:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].PhysicalLocationTypeListVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].PartTypeListVal));
	   (yyval.PartsTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 227:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 228:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 229:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].XmlIDREFVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].PointTypeVal), (yyvsp[(7) - (10)].VectorTypeVal), (yyvsp[(8) - (10)].VectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].PositiveDecimalTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 230:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 231:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlIDREFVal), (yyvsp[(5) - (6)].XmlDateTimeVal), (yyvsp[(6) - (6)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
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

