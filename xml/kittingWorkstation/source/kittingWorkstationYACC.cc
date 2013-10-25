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
#include "owlKittingWorkstationClasses.hh"
#else
#include "kittingWorkstationClasses.hh"   // for kitting classes
#endif

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
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  CylindricalShapeType *              CylindricalShapeTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
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
  std::list<KitDesignType *> *        ListKitDesignTypeVal;
  std::list<KitTrayType *> *          ListKitTrayTypeVal;
  std::list<KitType *> *              ListKitTypeVal;
  std::list<PartRefAndPoseType *> *   ListPartRefAndPoseTypeVal;
  std::list<PartType *> *             ListPartTypeVal;
  std::list<PhysicalLocationType *> * ListPhysicalLocationTypeVal;
  std::list<SlotType *> *             ListSlotTypeVal;
  std::list<SolidObjectType *> *      ListSolidObjectTypeVal;
  std::list<StockKeepingUnitType *> * ListStockKeepingUnitTypeVal;
  std::list<XmlIDREF *> *             ListXmlIDREFVal;
  MechanicalComponentType *           MechanicalComponentTypeVal;
  NoSkuObjectType *                   NoSkuObjectTypeVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  PartType *                          PartTypeVal;
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
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotType *                         RobotTypeVal;
  SkuObjectType *                     SkuObjectTypeVal;
  SlotType *                          SlotTypeVal;
  SolidObjectType *                   SolidObjectTypeVal;
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
      94,   100,   101,   107,   108,   114,   123,   131,   135,   136,
     142,   144,   146,   148,   149,   153,   161,   162,   166,   167,
     173,   174,   178,   179,   185,   186,   192,   193,   197,   198,
     204,   206,   208,   209,   213,   214,   220,   221,   227,   228,
     234,   239,   243,   244,   250,   257,   261,   265,   277,   281,
     297,   304,   308,   309,   315,   316,   322,   324,   327,   328,
     331,   333,   336,   337,   340,   341,   344,   345,   348,   351,
     353,   354,   357,   360,   362,   363,   366,   367,   370,   373,
     375,   376,   379,   382,   384,   385,   391,   395,   402,   406,
     407,   413,   414,   420,   421,   422,   428,   429,   435,   439,
     443,   444,   445,   451,   455,   456,   457,   463,   464,   470,
     471,   477,   484,   488,   489,   495,   502,   506,   508,   510,
     512,   514,   516,   522,   526,   528,   530,   532,   533,   534,
     540,   544,   545,   551,   562,   566,   570,   571,   577,   578,
     584,   588,   593,   597,   599,   601,   603,   605,   607,   609,
     611,   613,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   641,   642,   643,   649,   655,   656,   662,   663,
     669,   670,   676,   680,   684,   685,   691,   692,   698,   702,
     703,   709,   719,   728,   738,   747,   759,   767,   775,   788,
     805,   815,   827,   835,   843,   851,   862,   873,   884,   895,
     906,   913,   920,   932,   948,   962
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     196,     0,    -1,   208,    71,   197,   264,    70,    -1,    11,
     198,    -1,     8,    10,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     9,    13,    10,     7,    -1,     9,    13,
      10,     5,    10,     7,    -1,    -1,    15,     6,   210,     4,
      14,    -1,    -1,    17,     6,   212,   206,    16,    -1,    -1,
      19,     6,   214,     4,    18,    -1,    21,   288,    20,    -1,
       6,   296,   287,   289,    -1,    -1,    23,     6,   218,   206,
      22,    -1,    25,   228,    24,    -1,    -1,    27,     6,   221,
       4,    26,    -1,    -1,    29,     6,   223,   207,    28,    -1,
      -1,    31,     6,   225,   203,    30,    -1,    -1,    33,     6,
     227,     4,    32,    -1,     6,   296,   321,   281,   248,   236,
     215,   271,    -1,     6,   296,   321,   281,   248,   236,   234,
      -1,    35,   229,    34,    -1,    -1,    37,     6,   232,   203,
      36,    -1,   358,    -1,   376,    -1,   377,    -1,    -1,    39,
     233,    38,    -1,     6,   296,   222,   239,   292,   290,   294,
      -1,    -1,    41,   235,    40,    -1,    -1,    43,     6,   238,
     199,    42,    -1,    -1,    45,   318,    44,    -1,    -1,    47,
       6,   241,   199,    46,    -1,    -1,    49,     6,   243,     4,
      48,    -1,    -1,    51,   334,    50,    -1,    -1,    53,     6,
     246,   201,    52,    -1,   354,    -1,   355,    -1,    -1,    55,
     247,    54,    -1,    -1,    57,     6,   250,   201,    56,    -1,
      -1,    59,     6,   252,   201,    58,    -1,    -1,    61,     6,
     254,   203,    60,    -1,     6,   296,   257,   279,    -1,    63,
     255,    62,    -1,    -1,    65,     6,   258,   203,    64,    -1,
       6,   296,   321,   281,   329,   327,    -1,    67,   259,    66,
      -1,    67,   259,    66,    -1,     6,   296,   321,   281,   248,
     236,   224,   260,   280,   283,   237,    -1,    69,   262,    68,
      -1,     6,   296,   321,   281,   248,   236,   209,   219,   273,
     267,   277,   278,   325,   282,   339,    -1,     6,   296,   321,
     281,   329,   327,    -1,    73,   265,    72,    -1,    -1,    75,
       6,   268,     4,    74,    -1,    -1,    77,     6,   270,     4,
      76,    -1,   230,    -1,   271,   230,    -1,    -1,   272,   231,
      -1,   256,    -1,   273,   256,    -1,    -1,   274,   261,    -1,
      -1,   275,   263,    -1,    -1,   276,   298,    -1,   277,   299,
      -1,   299,    -1,    -1,   278,   302,    -1,   279,   310,    -1,
     310,    -1,    -1,   280,   314,    -1,    -1,   281,   326,    -1,
     282,   331,    -1,   331,    -1,    -1,   283,   333,    -1,   284,
     345,    -1,   345,    -1,    -1,    79,     6,   286,     4,    78,
      -1,    81,   316,    80,    -1,     6,   296,   321,   281,   248,
     236,    -1,    83,   316,    82,    -1,    -1,    85,     6,   291,
     207,    84,    -1,    -1,    87,     6,   293,   207,    86,    -1,
      -1,    -1,    89,     6,   295,   207,    88,    -1,    -1,    91,
       6,   297,   202,    90,    -1,    93,   334,    92,    -1,    95,
     334,    94,    -1,    -1,    -1,    97,     6,   301,     4,    96,
      -1,    99,   216,    98,    -1,    -1,    -1,   101,     6,   304,
     203,   100,    -1,    -1,   103,     6,   306,   205,   102,    -1,
      -1,   105,     6,   308,   203,   104,    -1,     6,   296,   329,
     317,   346,   351,    -1,   107,   309,   106,    -1,    -1,   109,
       6,   312,   203,   108,    -1,     6,   296,   321,   281,   329,
     327,    -1,   111,   313,   110,    -1,   370,    -1,   371,    -1,
     372,    -1,   373,    -1,   374,    -1,     6,   296,   347,   349,
     352,    -1,   113,   316,   112,    -1,   370,    -1,   371,    -1,
     372,    -1,    -1,    -1,   115,     6,   320,     4,   114,    -1,
     117,   315,   116,    -1,    -1,   119,     6,   323,   203,   118,
      -1,     6,   296,   321,   281,   248,   236,   222,   234,   285,
     284,    -1,   121,   324,   120,    -1,   123,   315,   122,    -1,
      -1,   125,     6,   328,   204,   124,    -1,    -1,   127,     6,
     330,   203,   126,    -1,   129,   335,   128,    -1,     6,   296,
     307,   303,    -1,   131,   332,   130,    -1,   356,    -1,   357,
      -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,   362,
      -1,   363,    -1,   364,    -1,   365,    -1,   366,    -1,   367,
      -1,   368,    -1,   369,    -1,   375,    -1,   376,    -1,   377,
      -1,   378,    -1,     6,   296,   222,   248,   236,   341,   272,
      -1,    -1,    -1,   133,     6,   337,   200,   132,    -1,     6,
     296,   245,   249,   251,    -1,    -1,   135,     6,   340,     4,
     134,    -1,    -1,   137,     6,   342,     4,   136,    -1,    -1,
     139,     6,   344,     4,   138,    -1,   141,   216,   140,    -1,
     143,   338,   142,    -1,    -1,   145,     6,   348,   201,   144,
      -1,    -1,   147,     6,   350,   201,   146,    -1,   149,   338,
     148,    -1,    -1,   151,     6,   353,   201,   150,    -1,   153,
       6,   296,   222,   239,   269,   343,   242,   240,    -1,   154,
       6,   296,   222,   239,   226,   242,   240,    -1,   155,     6,
     296,   321,   281,   248,   236,   215,   271,    -1,   156,     6,
     296,   321,   281,   248,   236,   234,    -1,   159,     6,   296,
     321,   281,   248,   236,   222,   341,   285,   244,    -1,   160,
       6,   296,   321,   281,   248,   236,    -1,   163,     6,   296,
     321,   281,   329,   327,    -1,   164,     6,   296,   321,   281,
     248,   236,   224,   260,   280,   283,   237,    -1,   165,     6,
     296,   321,   281,   248,   236,   209,   219,   273,   267,   277,
     278,   325,   282,   339,    -1,   166,     6,   296,   321,   281,
     248,   236,   266,   274,    -1,   167,     6,   296,   321,   281,
     248,   236,   266,   275,   253,   217,    -1,   168,     6,   296,
     321,   281,   329,   327,    -1,   169,     6,   296,   321,   281,
     248,   236,    -1,   172,     6,   296,   321,   281,   329,   327,
      -1,   173,     6,   296,   321,   281,   329,   327,   311,   305,
     280,    -1,   174,     6,   296,   321,   281,   329,   327,   311,
     305,   280,    -1,   178,     6,   296,   322,   336,   317,   346,
     351,   319,   300,    -1,   179,     6,   296,   322,   336,   317,
     346,   351,   319,   300,    -1,   181,     6,   296,   322,   336,
     317,   346,   351,   319,   300,    -1,   182,     6,   296,   322,
     336,   222,    -1,   183,     6,   296,   322,   336,   222,    -1,
     185,     6,   296,   321,   281,   248,   236,   222,   234,   285,
     284,    -1,   190,     6,   296,   321,   281,   248,   236,   222,
     341,   285,   244,   220,   269,   211,   213,    -1,   191,     6,
     296,   321,   281,   248,   236,   222,   341,   285,   244,   220,
     269,    -1,   194,     6,   296,   321,   281,   248,   236,   276,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   448,   448,   458,   463,   469,   477,   485,   493,   501,
     509,   517,   525,   533,   541,   546,   557,   557,   565,   565,
     571,   571,   580,   585,   591,   591,   597,   603,   603,   612,
     612,   618,   618,   624,   624,   632,   642,   651,   657,   657,
     663,   665,   667,   673,   674,   679,   687,   688,   693,   693,
     699,   700,   705,   705,   710,   710,   719,   720,   725,   725,
     730,   732,   738,   739,   744,   744,   749,   749,   754,   754,
     760,   766,   771,   771,   777,   784,   789,   794,   804,   809,
     822,   829,   834,   834,   843,   843,   851,   854,   862,   863,
     869,   872,   879,   880,   887,   888,   895,   896,   903,   906,
     913,   914,   921,   925,   932,   933,   940,   941,   948,   951,
     958,   959,   965,   968,   974,   974,   983,   988,   996,  1001,
    1001,  1007,  1007,  1014,  1015,  1015,  1020,  1020,  1025,  1030,
    1036,  1037,  1037,  1046,  1052,  1053,  1053,  1058,  1058,  1064,
    1064,  1070,  1076,  1081,  1081,  1087,  1094,  1099,  1101,  1103,
    1105,  1107,  1112,  1118,  1123,  1125,  1127,  1133,  1134,  1134,
    1143,  1148,  1148,  1154,  1165,  1170,  1176,  1176,  1182,  1182,
    1187,  1192,  1198,  1203,  1205,  1207,  1209,  1211,  1213,  1215,
    1217,  1219,  1221,  1223,  1225,  1227,  1229,  1231,  1233,  1235,
    1237,  1242,  1251,  1252,  1252,  1258,  1264,  1264,  1273,  1273,
    1281,  1281,  1289,  1294,  1299,  1299,  1304,  1304,  1309,  1314,
    1314,  1319,  1329,  1339,  1352,  1364,  1378,  1389,  1399,  1412,
    1428,  1440,  1453,  1463,  1474,  1484,  1496,  1508,  1519,  1530,
    1541,  1550,  1559,  1573,  1589,  1604
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
  "y_EndEffectorName_XmlIDREF_0_u", "$@9", "y_EndEffectorTypeAny",
  "y_EndEffector_EndEffectorType_0", "y_ExternalShapeType",
  "y_ExternalShape_ExternalShapeType_0", "y_Finished_XmlBoolean", "$@10",
  "y_GraspPose_PoseLocationType_0", "y_HasTop_XmlBoolean", "$@11",
  "y_Height_PositiveDecimalType", "$@12", "y_HeldObject_SolidObjectType_0",
  "y_I_XmlDecimal", "$@13", "y_InternalShapeTypeAny",
  "y_InternalShape_InternalShapeType_0", "y_J_XmlDecimal", "$@14",
  "y_K_XmlDecimal", "$@15", "y_KitDesignName_XmlIDREF", "$@16",
  "y_KitDesignType", "y_KitDesign_KitDesignType_u",
  "y_KitTraySkuName_XmlIDREF", "$@17", "y_KitTrayType",
  "y_KitTray_KitTrayType", "y_KitTray_KitTrayType_0_u", "y_KitType",
  "y_Kit_KitType_0_u", "y_KittingWorkstationType", "y_LargeContainerType",
  "y_LargeContainer_LargeContainerType", "y_LengthUnit_LengthUnitType",
  "$@18", "y_Length_PositiveDecimalType", "$@19",
  "y_ListEndEffectorHolder_EndEffectorHolderType_u",
  "y_ListEndEffectorName_XmlIDREF_0_u", "y_ListKitDesign_KitDesignType_u",
  "y_ListKitTray_KitTrayType_0_u", "y_ListKit_KitType_0_u",
  "y_ListObjectOnTable_SolidObjectType_0_u",
  "y_ListObject_SolidObjectType_u",
  "y_ListOtherObstacle_BoxVolumeType_0_u",
  "y_ListPartRefAndPose_PartRefAndPoseType_u", "y_ListPart_PartType_0_u",
  "y_ListSecondaryLocation_PhysicalLocationType_0_u",
  "y_ListSku_StockKeepingUnitType_u", "y_ListSlot_SlotType_0_u",
  "y_ListWorkVolume_BoxVolumeType_u",
  "y_MaximumLoadWeight_PositiveDecimalType", "$@20",
  "y_MaximumPoint_PointType", "y_MechanicalComponentType",
  "y_MinimumPoint_PointType", "y_ModelFileName_XmlString", "$@21",
  "y_ModelFormatName_XmlString", "$@22", "y_ModelName_XmlString_0", "$@23",
  "y_Name_XmlID", "$@24", "y_ObjectOnTable_SolidObjectType_0_u",
  "y_Object_SolidObjectType_u",
  "y_OrientationStandardDeviation_PositiveDecimalType_0", "$@25",
  "y_OtherObstacle_BoxVolumeType_0_u", "y_PartName_XmlIDREF_0", "$@26",
  "y_PartQuantity_XmlNonNegativeInteger", "$@27",
  "y_PartRefAndPoseName_XmlIDREF", "$@28", "y_PartRefAndPoseType",
  "y_PartRefAndPose_PartRefAndPoseType_u", "y_PartSkuName_XmlIDREF",
  "$@29", "y_PartType", "y_Part_PartType_0_u", "y_PhysicalLocationTypeAny",
  "y_PointType", "y_Point_PointType", "y_PoseLocationTypeAny",
  "y_PositionStandardDeviation_PositiveDecimalType_0", "$@30",
  "y_PrimaryLocation_PhysicalLocationType", "y_RefObjectName_XmlIDREF",
  "$@31", "y_RobotType", "y_Robot_RobotType",
  "y_SecondaryLocation_PhysicalLocationType_0_u",
  "y_SerialNumber_XmlNMTOKEN", "$@32", "y_SkuName_XmlIDREF", "$@33",
  "y_Sku_StockKeepingUnitType_u", "y_SlotType", "y_Slot_SlotType_0_u",
  "y_SolidObjectTypeAny", "y_StockKeepingUnitType",
  "y_Timestamp_XmlDateTime_0", "$@34", "y_VectorType",
  "y_WeightUnit_WeightUnitType", "$@35", "y_Weight_PositiveDecimalType",
  "$@36", "y_Width_PositiveDecimalType", "$@37",
  "y_WorkVolume_BoxVolumeType_u", "y_XAxis_VectorType", "y_X_XmlDecimal",
  "$@38", "y_Y_XmlDecimal", "$@39", "y_ZAxis_VectorType", "y_Z_XmlDecimal",
  "$@40", "y_x_BoxyShapeType", "y_x_CylindricalShapeType",
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
     445,   446,   447,   448,   449
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   208,   210,   209,   212,   211,
     214,   213,   215,   216,   218,   217,   219,   221,   220,   223,
     222,   225,   224,   227,   226,   228,   229,   230,   232,   231,
     233,   233,   233,   234,   234,   235,   236,   236,   238,   237,
     239,   239,   241,   240,   243,   242,   244,   244,   246,   245,
     247,   247,   248,   248,   250,   249,   252,   251,   254,   253,
     255,   256,   258,   257,   259,   260,   261,   262,   263,   264,
     265,   266,   268,   267,   270,   269,   271,   271,   272,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   280,   281,   281,   282,   282,
     283,   283,   284,   284,   286,   285,   287,   288,   289,   291,
     290,   293,   292,   294,   295,   294,   297,   296,   298,   299,
     300,   301,   300,   302,   303,   304,   303,   306,   305,   308,
     307,   309,   310,   312,   311,   313,   314,   315,   315,   315,
     315,   315,   316,   317,   318,   318,   318,   319,   320,   319,
     321,   323,   322,   324,   325,   326,   328,   327,   330,   329,
     331,   332,   333,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   335,   336,   337,   336,   338,   340,   339,   342,   341,
     344,   343,   345,   346,   348,   347,   350,   349,   351,   353,
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
       5,     0,     5,     0,     5,     8,     7,     3,     0,     5,
       1,     1,     1,     0,     3,     7,     0,     3,     0,     5,
       0,     3,     0,     5,     0,     5,     0,     3,     0,     5,
       1,     1,     0,     3,     0,     5,     0,     5,     0,     5,
       4,     3,     0,     5,     6,     3,     3,    11,     3,    15,
       6,     3,     0,     5,     0,     5,     1,     2,     0,     2,
       1,     2,     0,     2,     0,     2,     0,     2,     2,     1,
       0,     2,     2,     1,     0,     2,     0,     2,     2,     1,
       0,     2,     2,     1,     0,     5,     3,     6,     3,     0,
       5,     0,     5,     0,     0,     5,     0,     5,     3,     3,
       0,     0,     5,     3,     0,     0,     5,     0,     5,     0,
       5,     6,     3,     0,     5,     6,     3,     1,     1,     1,
       1,     1,     5,     3,     1,     1,     1,     0,     0,     5,
       3,     0,     5,    10,     3,     3,     0,     5,     0,     5,
       3,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     0,     0,     5,     5,     0,     5,     0,     5,
       0,     5,     3,     3,     0,     5,     0,     5,     3,     0,
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
       2,    15,   126,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,    62,     8,     0,
       0,     0,     0,     0,     0,   160,     0,     0,    46,   107,
     127,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,     0,     0,     0,     0,   192,   192,   192,   192,   192,
       0,     0,    63,   165,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    16,
       0,     0,     0,   193,     0,     0,     0,     0,     0,   230,
     231,    50,    50,    50,     0,     0,     0,     0,    90,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
      91,     0,   162,     6,     0,     0,   153,     0,     0,     0,
     157,   157,   157,     0,     0,   154,   155,   156,     0,     0,
       0,     0,     0,     0,    17,   106,     0,    71,    82,     0,
     100,    99,   194,     0,     0,     0,   203,     0,     0,   130,
     130,   130,    13,     0,    51,    84,     0,     0,    33,     0,
       0,   121,     0,   123,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,    98,   204,     0,     0,
       0,     0,   208,   158,     0,   227,   228,   229,    30,     0,
     200,     0,     0,    54,     0,   212,     0,   119,     0,    45,
      46,    72,     0,    70,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   101,     0,     0,
     206,     0,   152,    58,     0,     0,     0,   131,     0,     0,
     211,     0,     0,    52,     0,     0,   124,     0,     0,     0,
       0,   102,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     7,     0,
       0,   209,     0,    64,     0,   195,     0,     0,    85,     0,
      34,     0,     0,   122,     0,     0,     0,     0,     0,     0,
     142,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,     0,
     133,     0,   164,     0,     0,     0,   108,    79,   205,     0,
       0,     0,     0,    66,   159,     0,   201,    55,     5,     0,
     120,     0,     0,     0,     0,    86,    35,    73,     0,     0,
      62,    62,    62,    62,     0,    62,    62,    62,    62,     0,
      62,     0,     0,     0,    62,    62,    62,    62,     0,     0,
     106,     0,   170,   196,   207,     0,    59,     0,     0,   132,
      53,   125,     0,    22,     0,     0,    87,   168,     0,    46,
      46,    46,    46,     0,    46,    46,    46,    46,     0,    46,
       0,     0,     0,    46,    46,    46,    46,     0,     0,    23,
      62,    62,     0,   210,    65,     0,   106,     0,    37,     0,
       0,     0,    43,     0,   216,     0,   217,     0,     0,     0,
       0,   222,   223,   224,     0,     0,     0,     0,     0,    96,
     116,     0,    46,    46,     0,    67,    62,   106,     0,   141,
       0,     0,   214,     0,   166,     0,     0,     0,     0,    92,
      94,     0,     0,     0,    43,     0,     0,   235,   118,     0,
       0,   197,    46,    62,   169,   213,     0,    40,    41,    42,
       0,     0,     0,    31,     0,   104,     0,     0,     0,   220,
       0,   143,     0,   104,   104,     0,     0,     0,     0,    97,
      43,    88,   117,    46,    44,   198,     0,    56,    10,     0,
       0,     0,     0,   110,     0,     0,    81,     0,    93,     0,
       0,     0,    95,     0,   137,   225,   226,     0,    56,    56,
       0,     0,   191,    43,     0,   114,     0,   215,   167,     0,
       0,    75,     0,     0,   105,     0,   106,     0,    68,     0,
       0,     0,   221,     0,     0,     0,   232,   113,     0,     0,
     128,     0,     0,    89,    36,     0,     0,     0,    32,   106,
       0,     0,     0,     0,   218,   111,   100,     0,    76,     0,
       0,    78,    24,   144,    11,     0,     0,   112,     0,     0,
       0,   163,    38,   199,     0,    57,     0,     0,   146,    48,
       0,     0,     0,     0,     0,   106,     0,   138,   202,    27,
       0,   234,     0,   115,     0,   106,     0,     0,   172,     0,
      80,    69,    62,    12,     0,     0,     0,     0,     0,    74,
       0,     0,     0,   134,     0,    46,    25,     0,    18,     0,
     233,    39,     0,    49,   139,     0,   171,   219,     0,    28,
       0,    20,   145,     0,   135,     0,     0,     0,     0,     0,
     104,    19,     0,   140,     0,   110,    21,   136,     0,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,   389,   134,   329,    39,   111,   559,
     635,   674,   173,     3,    77,   104,   677,   700,   690,   707,
     347,   322,   602,   656,    91,   639,   675,    99,   143,   506,
     560,   151,   242,   106,   435,   395,   613,   662,   526,   502,
      75,    63,   624,   666,   121,   245,   342,   180,   292,   587,
     231,   332,    58,    48,   285,   382,   335,   428,   571,   629,
     128,   108,   186,   298,   562,   535,   568,   600,   572,    15,
     538,   509,   131,   187,   149,   239,   396,   582,   109,   539,
     540,   517,   160,   225,   253,   563,    37,   326,   593,   606,
     557,   616,   419,   393,   459,   183,   295,   153,   246,   249,
     345,    19,    25,   549,   161,   235,   337,   277,   696,   709,
     543,   604,   683,   703,   300,   254,   512,   573,   621,   594,
      31,   114,    95,   144,   169,   286,    24,    65,    92,   324,
     278,    49,   476,   532,   399,   469,   327,   651,   625,   206,
     374,    80,   112,   138,   377,   462,   531,   584,   177,   289,
     607,   116,   164,   279,   229,   330,   140,   282,   380,    59,
      60,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    32,    33,    34,    35,    36,
     221,   222,   223,   224
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -560
static const yytype_int16 yypact[] =
{
      26,    27,    43,   -12,    52,  -560,    75,    89,    87,   112,
     113,  -560,   126,  -560,    46,    68,   132,  -560,   134,    25,
    -560,  -560,  -560,  -126,  -560,   139,   138,   141,   142,   143,
     144,    29,  -560,  -560,  -560,  -560,  -560,   -30,  -560,    63,
      46,    46,    46,    46,    46,  -560,  -104,  -126,   115,  -560,
    -560,    35,    35,    35,    35,    35,   151,   152,   105,  -560,
    -560,    38,   155,   147,   157,    31,    31,    31,    31,    31,
      46,    46,  -560,  -560,    46,   125,   160,   145,  -560,   161,
      55,    55,    55,   140,   140,   140,   140,   140,  -560,  -560,
     165,   109,   169,  -560,   168,    32,    32,    32,   170,  -560,
    -560,   133,   133,   133,   173,    46,   156,   175,  -560,   -24,
    -560,    61,   178,    46,    90,   195,    54,    54,    54,  -560,
     -89,   128,   176,   119,   194,    25,  -560,    46,   148,   205,
    -560,   117,  -560,  -560,    81,    69,  -560,    46,    73,   195,
     120,   120,   120,   230,   192,  -560,  -560,  -560,   231,    99,
     237,   199,   244,   167,  -560,  -560,   193,  -560,  -560,   -39,
     117,  -560,  -560,   251,   131,   226,  -560,   136,   276,   188,
     188,   188,  -560,   268,  -560,  -560,   300,   199,  -560,   301,
     261,  -560,   303,   221,   -30,   307,   207,   311,   310,   312,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   324,
     325,   326,   328,   331,   332,   336,   223,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   -67,  -560,  -560,   337,   197,
     338,   289,  -560,  -560,   343,  -560,  -560,  -560,  -560,   346,
    -560,   261,   347,  -560,   348,  -560,   230,  -560,   349,  -560,
     115,  -560,   351,   207,  -560,   279,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,  -560,   352,   353,  -560,   232,   356,
    -560,   357,  -560,  -560,   358,   306,   362,  -560,   292,   368,
    -560,   341,   370,  -560,   290,   230,  -560,   359,   169,    46,
     271,  -560,  -560,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    46,   280,    46,   259,   375,   -87,  -560,  -560,   238,
     356,  -560,   356,  -560,   377,  -560,   270,   381,  -560,   248,
    -560,   339,   384,  -560,   305,   230,   385,   355,   329,   265,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   323,
    -560,    25,  -560,    46,   267,   390,  -560,  -560,  -560,   252,
     356,   350,   356,  -560,  -560,   309,  -560,  -560,  -560,   361,
    -560,   327,    46,   379,   397,  -560,   355,  -560,   402,    55,
     -30,   -30,   -30,   -30,   -42,   -30,   -30,   -30,   -30,   -42,
     -30,   -42,   -42,   -42,   -30,   -30,   -30,   -30,   168,   330,
    -560,   140,  -560,  -560,  -560,   264,  -560,   360,   356,  -560,
    -560,  -560,    25,  -560,    46,   383,  -560,  -560,    32,   115,
     115,   115,   115,   284,   115,   115,   115,   115,   284,   115,
     284,   284,   284,   115,   115,   115,   115,   340,   168,  -560,
     -30,   363,   415,  -560,  -560,   364,  -560,    25,  -560,   169,
      54,   359,   382,   140,  -560,   417,  -560,   393,   147,   354,
     354,  -560,  -560,  -560,   333,   333,   140,   140,   140,  -560,
    -560,   344,   115,   115,   291,  -560,   -30,  -560,   302,  -560,
     355,  -130,  -560,   293,  -560,   423,   365,   145,   425,  -560,
    -560,   427,   334,   334,   382,   293,   293,   342,  -560,   140,
     293,  -560,   115,   -30,  -560,   355,   396,  -560,  -560,  -560,
     430,   367,   434,  -560,   433,  -560,   109,    46,   372,   373,
     -28,  -560,   442,  -560,  -560,   367,   367,   367,   -39,  -560,
     382,  -560,  -560,   115,  -560,  -560,   443,   399,  -560,   335,
     169,    46,   386,   345,   -24,    25,  -560,   433,  -560,   445,
     447,   431,  -560,   169,  -560,   345,   345,   366,   399,   399,
     369,   367,   418,   382,   453,  -560,   -39,  -560,  -560,   428,
      25,  -560,   454,   -22,  -560,   117,  -560,   398,  -560,    46,
     395,   459,  -560,   371,   462,   352,   366,  -560,   440,   440,
    -560,   366,   463,  -560,  -560,   376,   464,   421,  -560,  -560,
      46,   374,   467,   468,  -560,  -560,   117,   -42,  -560,   169,
      25,  -560,  -560,  -560,  -560,   378,   380,  -560,   469,   128,
     128,   366,  -560,  -560,   400,  -560,   -42,    25,  -560,  -560,
      46,   387,   -67,   284,   416,  -560,   473,  -560,  -560,  -560,
     465,  -560,   169,  -560,   284,  -560,   384,   388,  -560,   232,
    -560,  -560,   -30,  -560,   461,   477,   479,   470,   450,  -560,
     -42,   446,   481,   389,   -87,   115,  -560,   466,  -560,   485,
    -560,  -560,   284,  -560,  -560,   488,  -560,  -560,   393,  -560,
     473,  -560,  -560,   169,  -560,   365,   480,   491,   394,   169,
    -560,  -560,   482,  -560,   401,   345,  -560,  -560,   -22,  -560
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -560,  -560,  -560,  -560,  -167,  -560,  -306,  -560,  -262,  -560,
    -560,  -198,  -226,  -560,    28,  -560,  -560,  -560,  -560,  -560,
      33,   -97,  -560,  -560,    -4,  -100,  -560,   -76,  -560,  -185,
    -560,  -560,  -560,  -560,  -560,  -384,  -560,  -560,  -560,  -492,
    -560,  -152,  -204,  -560,     5,   274,  -560,   391,  -560,  -468,
    -560,  -560,  -560,  -161,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -102,  -560,  -560,   -51,  -187,  -560,  -560,  -560,  -560,
    -560,    39,   -41,  -560,  -527,  -560,    22,  -560,   -11,  -560,
    -560,  -560,   -71,   -96,  -560,  -506,   -91,  -143,  -186,   -80,
    -501,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   -40,  -560,  -560,  -154,   -56,  -560,  -560,  -560,  -560,
      19,  -560,  -560,  -560,  -560,   281,    50,  -560,  -560,  -560,
     489,  -391,   -63,  -560,   -10,  -560,  -120,    47,  -560,  -560,
    -115,  -560,  -373,  -560,  -341,  -560,  -313,  -560,  -560,  -520,
    -560,    37,  -560,   403,  -146,  -560,  -432,  -560,  -560,  -560,
    -559,   -82,  -560,  -560,  -560,  -560,  -101,  -560,  -560,  -560,
    -560,  -560,  -560,    40,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   419,   420,   424,  -560,  -560,
    -560,    42,    44,  -560
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      51,    52,    53,    54,    55,   155,   226,   130,   100,   101,
     102,   103,   436,   376,   117,   118,   141,   142,    96,    97,
     294,   622,   545,   250,   379,    46,   381,   457,   580,   190,
      85,    86,   275,   569,    87,     1,   348,   575,   576,   107,
       4,   570,   325,     5,   577,   578,   579,   637,   375,    56,
      57,   129,    26,    27,   276,    28,    29,    30,   581,     6,
     203,   204,     7,   443,   184,   125,   617,   491,   448,   344,
     450,   451,   452,   135,   425,   481,   427,   483,   484,   485,
     611,    47,   637,   546,   547,   398,     8,   156,   551,    26,
      27,   614,    28,    47,    10,    12,    11,   165,   297,    66,
      67,    68,    69,    81,    82,    83,    84,   122,   123,   623,
     608,   609,   660,   661,   236,   237,   188,   189,    14,   391,
     190,   191,   465,    16,   192,   193,   194,   195,   196,   197,
     198,   170,   171,   199,   200,   201,    17,    18,    20,    21,
      22,   436,    23,    38,    40,    45,   202,    41,    42,    43,
      44,   203,   204,    50,    64,   205,    62,    70,    71,    72,
      73,    74,    76,    78,    79,    88,    89,    93,    94,    98,
      90,   105,   107,   110,   113,   115,   119,   124,   120,   132,
     126,   127,   133,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   137,   136,   139,   715,   148,   152,   498,   154,   150,
     157,   158,   159,   162,   163,   166,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   172,   168,   174,   175,   176,   439,
     440,   441,   442,   178,   444,   445,   446,   447,   179,   449,
     181,   420,   182,   453,   454,   455,   456,   227,   185,   349,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   228,   230,
     670,   369,   233,   371,   232,   234,   653,   471,   472,   473,
     474,   679,   477,   478,   479,   480,   238,   482,   589,   492,
     493,   486,   487,   488,   489,   664,   240,   243,   244,   247,
     248,   603,   466,   251,   252,   255,   256,   274,   257,   702,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   460,
     267,   268,   269,   421,   270,   522,   438,   271,   272,   692,
     519,   520,   273,   280,   283,   461,   284,   497,   281,   287,
     288,   291,   432,   302,   293,   296,   470,   299,   321,   323,
     328,   325,   553,   331,   333,   334,   336,   654,   338,   499,
     552,   376,   339,   340,   341,   496,   343,   350,   370,   372,
     346,   373,   378,   383,   384,   385,   386,   387,   388,   390,
     394,   392,   398,   397,   467,   422,   423,   503,   424,   433,
     678,   583,   426,   434,   418,   429,   523,   430,   437,   475,
     514,   515,   516,   458,   463,   431,   464,   468,    46,   494,
     490,   501,   495,   504,   505,   521,   518,   508,   524,   533,
     530,   537,   534,   541,   554,   548,   555,   542,   558,   561,
     567,   708,   511,   550,   566,   596,   556,   714,   574,   585,
     586,   598,   591,   599,   601,   612,   592,   615,   618,   588,
     620,   610,   130,   631,   628,   632,   634,   638,   644,   642,
     619,   645,   226,   649,   650,   659,   671,   673,   663,   633,
     657,   687,   676,   686,   648,   688,   691,   694,   693,   689,
     695,   701,   699,   682,   704,   712,   711,   565,   713,   681,
     716,   717,   706,   536,   500,   627,   507,   605,   636,   640,
     655,   685,   643,   705,   719,   290,   597,   668,   710,   510,
     658,   590,   525,   595,   626,   564,   684,   665,   646,   718,
     652,   641,   544,   698,   301,   513,    61,   669,   697,   145,
     146,   527,   167,   528,   147,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,     0,     0,     0,   672,     0,     0,     0,   241,     0,
       0,     0,     0,     0,   680,     0,     0,     0,     0,     0,
     647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     667
};

static const yytype_int16 yycheck[] =
{
      40,    41,    42,    43,    44,   125,   160,   109,    84,    85,
      86,    87,   396,   326,    96,    97,   117,   118,    81,    82,
     246,    43,   514,   184,   330,    55,   332,   418,   548,   159,
      70,    71,    99,    61,    74,     9,   298,   543,   544,    63,
      13,    69,   129,     0,   545,   546,   547,   606,   135,   153,
     154,    75,   178,   179,   121,   181,   182,   183,   550,    71,
     190,   191,    10,   404,   155,   105,   586,   458,   409,   295,
     411,   412,   413,   113,   380,   448,   382,   450,   451,   452,
     581,   123,   641,   515,   516,   127,    11,   127,   520,   178,
     179,   583,   181,   123,     5,     8,     7,   137,   250,    52,
      53,    54,    55,    66,    67,    68,    69,   102,   103,   131,
     578,   579,   639,   640,   170,   171,   155,   156,     6,   345,
     159,   160,   428,    10,   163,   164,   165,   166,   167,   168,
     169,   141,   142,   172,   173,   174,    10,    91,    70,     7,
       6,   525,   117,     4,     6,   116,   185,     6,     6,     6,
       6,   190,   191,    90,   119,   194,    41,     6,     6,    54,
     122,     6,    15,     6,   133,    40,     6,     6,   113,    29,
      25,     6,    63,     4,     6,   143,     6,     4,    45,   118,
      24,     6,     4,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,     6,   112,   149,   710,    77,    87,   469,    14,    33,
      62,     6,    95,   132,   145,   142,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,     4,   115,    44,     6,   139,   400,
     401,   402,   403,     6,   405,   406,   407,   408,    49,   410,
       6,   371,    85,   414,   415,   416,   417,     6,    65,   299,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   147,    53,
     653,   321,     6,   323,   148,    97,   627,   439,   440,   441,
     442,   664,   444,   445,   446,   447,    28,   449,   560,   460,
     461,   453,   454,   455,   456,   646,     6,     6,    47,     6,
      89,   573,   432,     6,   107,     4,     6,    94,     6,   692,
       6,     6,     6,     6,     6,     6,     6,     6,     6,   420,
       6,     6,     6,   373,     6,   496,   399,     6,     6,   680,
     492,   493,     6,     6,     6,   421,    57,   467,   151,     6,
       4,     4,   392,    74,     6,     6,   438,     6,     6,     6,
       4,   129,   523,     6,     6,    59,     4,   629,    76,   470,
     522,   684,     4,    32,     4,   466,    86,   106,    98,   120,
      21,     6,   144,     6,   114,     4,   138,    48,     4,    84,
      35,     6,   127,    64,   434,   128,     6,   473,   146,    20,
     662,   553,    52,     6,    81,    96,   497,    46,     6,   125,
     486,   487,   488,    83,   150,    88,    56,    34,    55,     4,
      80,    39,    58,     6,    31,   134,    82,    73,   126,     6,
     137,     6,    67,     6,    38,    93,     6,   103,     4,     6,
      67,   703,   109,   519,    72,   565,    79,   709,     6,     6,
      51,     6,    66,     6,    23,    37,   111,     4,    30,   124,
       6,    92,   564,    68,    66,     6,     4,    27,     4,     6,
     590,    50,   626,     6,     6,     6,    60,     4,    78,   108,
     102,     4,    17,    22,   110,     6,    36,     6,    42,    19,
     101,     6,    26,   105,     6,     4,    16,   537,   104,   666,
      18,   100,   700,   507,   471,   596,   478,   141,   605,   609,
     630,   672,   136,   698,   718,   241,   567,   130,   705,   480,
     140,   561,   500,   564,   595,   536,   669,   647,   619,   715,
     626,   611,   513,   685,   253,   485,    47,   652,   684,   120,
     120,   501,   139,   501,   120,   501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,   177,    -1,
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
       5,     7,     8,   198,     6,   264,    10,    10,    91,   296,
      70,     7,     6,   117,   321,   297,   178,   179,   181,   182,
     183,   315,   370,   371,   372,   373,   374,   281,     4,   202,
       6,     6,     6,     6,     6,   116,    55,   123,   248,   326,
      90,   296,   296,   296,   296,   296,   153,   154,   247,   354,
     355,   315,    41,   236,   119,   322,   322,   322,   322,   322,
       6,     6,    54,   122,     6,   235,    15,   209,     6,   133,
     336,   336,   336,   336,   336,   296,   296,   296,    40,     6,
      25,   219,   323,     6,   113,   317,   317,   317,    29,   222,
     222,   222,   222,   222,   210,     6,   228,    63,   256,   273,
       4,   203,   337,     6,   316,   143,   346,   346,   346,     6,
      45,   239,   239,   239,     4,   296,    24,     6,   255,    75,
     256,   267,   118,     4,   200,   296,   112,     6,   338,   149,
     351,   351,   351,   223,   318,   370,   371,   372,    77,   269,
      33,   226,    87,   292,    14,   321,   296,    62,     6,    95,
     277,   299,   132,   145,   347,   296,   142,   338,   115,   319,
     319,   319,     4,   207,    44,     6,   139,   343,     6,    49,
     242,     6,    85,   290,   281,    65,   257,   268,   155,   156,
     159,   160,   163,   164,   165,   166,   167,   168,   169,   172,
     173,   174,   185,   190,   191,   194,   334,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   375,   376,   377,   378,   278,   299,     6,   147,   349,
      53,   245,   148,     6,    97,   300,   300,   300,    28,   270,
       6,   242,   227,     6,    47,   240,   293,     6,    89,   294,
     248,     6,   107,   279,   310,     4,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,    94,    99,   121,   302,   325,   348,
       6,   151,   352,     6,    57,   249,   320,     6,     4,   344,
     240,     4,   243,     6,   207,   291,     6,   236,   258,     6,
     309,   310,    74,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,     6,   216,     6,   324,   129,   282,   331,     4,   201,
     350,     6,   246,     6,    59,   251,     4,   301,    76,     4,
      32,     4,   241,    86,   207,   295,    21,   215,   203,   296,
     106,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   296,
      98,   296,   120,     6,   335,   135,   331,   339,   144,   201,
     353,   201,   250,     6,   114,     4,   138,    48,     4,   199,
      84,   207,     6,   288,    35,   230,   271,    64,   127,   329,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,    81,   287,
     321,   296,   128,     6,   146,   201,    52,   201,   252,    96,
      46,    88,   296,    20,     6,   229,   230,     6,   317,   248,
     248,   248,   248,   329,   248,   248,   248,   248,   329,   248,
     329,   329,   329,   248,   248,   248,   248,   316,    83,   289,
     281,   222,   340,   150,    56,   201,   321,   296,    34,   330,
     346,   236,   236,   236,   236,   125,   327,   236,   236,   236,
     236,   327,   236,   327,   327,   327,   236,   236,   236,   236,
      80,   316,   248,   248,     4,    58,   281,   321,   203,   351,
     215,    39,   234,   222,     6,    31,   224,   209,    73,   266,
     266,   109,   311,   311,   222,   222,   222,   276,    82,   236,
     236,   134,   248,   281,   126,   271,   233,   358,   376,   377,
     137,   341,   328,     6,    67,   260,   219,     6,   265,   274,
     275,     6,   103,   305,   305,   234,   341,   341,    93,   298,
     222,   341,   236,   248,    38,     6,    79,   285,     4,   204,
     225,     6,   259,   280,   273,   296,    72,    67,   261,    61,
      69,   253,   263,   312,     6,   280,   280,   285,   285,   285,
     334,   234,   272,   236,   342,     6,    51,   244,   124,   203,
     296,    66,   111,   283,   314,   267,   321,   259,     6,     6,
     262,    23,   217,   203,   306,   141,   284,   345,   244,   244,
      92,   285,    37,   231,   234,     4,   286,   334,    30,   321,
       6,   313,    43,   131,   237,   333,   277,   281,    66,   254,
     296,    68,     6,   108,     4,   205,   216,   345,    27,   220,
     220,   284,     6,   136,     4,    50,   281,   296,   110,     6,
       6,   332,   278,   329,   203,   321,   218,   102,   140,     6,
     269,   269,   232,    78,   329,   321,   238,   296,   130,   325,
     327,    60,   281,     4,   206,   221,    17,   211,   203,   327,
     281,   199,   105,   307,   282,   248,    22,     4,     6,    19,
     213,    36,   329,    42,     6,   101,   303,   339,   236,    26,
     212,     6,   327,   308,     6,   224,   206,   214,   203,   304,
     260,    16,     4,   104,   203,   280,    18,   100,   283,   237
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

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(2) - (8)].XmlIDVal), (yyvsp[(3) - (8)].PhysicalLocationTypeVal), (yyvsp[(4) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (8)].InternalShapeTypeVal), (yyvsp[(6) - (8)].ExternalShapeTypeVal), (yyvsp[(7) - (8)].MechanicalComponentTypeVal), (yyvsp[(8) - (8)].ListEndEffectorHolderTypeVal));;}
    break;

  case 36:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].PhysicalLocationTypeVal), (yyvsp[(4) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (7)].InternalShapeTypeVal), (yyvsp[(6) - (7)].ExternalShapeTypeVal), (yyvsp[(7) - (7)].EndEffectorTypeVal));;}
    break;

  case 37:

    {(yyval.EndEffectorHolderTypeVal) = (yyvsp[(2) - (3)].EndEffectorHolderTypeVal);;}
    break;

  case 38:

    {yyReadData = 1;;}
    break;

  case 39:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
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

    {(yyval.EndEffectorTypeVal) = 0;;}
    break;

  case 44:

    {(yyval.EndEffectorTypeVal) = (yyvsp[(2) - (3)].EndEffectorTypeVal);;}
    break;

  case 45:

    {(yyval.ExternalShapeTypeVal) = new ExternalShapeType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].PoseLocationTypeVal), (yyvsp[(5) - (7)].XmlStringVal), (yyvsp[(6) - (7)].XmlStringVal), (yyvsp[(7) - (7)].XmlStringVal));;}
    break;

  case 46:

    {(yyval.ExternalShapeTypeVal) = 0;;}
    break;

  case 47:

    {(yyval.ExternalShapeTypeVal) = (yyvsp[(2) - (3)].ExternalShapeTypeVal);;}
    break;

  case 48:

    {yyReadData = 1;;}
    break;

  case 49:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 50:

    {(yyval.PoseLocationTypeVal) = 0;;}
    break;

  case 51:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(2) - (3)].PoseLocationTypeVal);;}
    break;

  case 52:

    {yyReadData = 1;;}
    break;

  case 53:

    {(yyval.XmlBooleanVal) = (yyvsp[(4) - (5)].XmlBooleanVal);;}
    break;

  case 54:

    {yyReadData = 1;;}
    break;

  case 55:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Height value");
	  ;}
    break;

  case 56:

    {(yyval.SolidObjectTypeVal) = 0;;}
    break;

  case 57:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 58:

    {yyReadData = 1;;}
    break;

  case 59:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 60:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].BoxyShapeTypeVal);;}
    break;

  case 61:

    {(yyval.InternalShapeTypeVal) = (yyvsp[(1) - (1)].CylindricalShapeTypeVal);;}
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

    {(yyval.KitDesignTypeVal) = new KitDesignType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].ListPartRefAndPoseTypeVal));;}
    break;

  case 71:

    {(yyval.KitDesignTypeVal) = (yyvsp[(2) - (3)].KitDesignTypeVal);;}
    break;

  case 72:

    {yyReadData = 1;;}
    break;

  case 73:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 74:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 75:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 76:

    {(yyval.KitTrayTypeVal) = (yyvsp[(2) - (3)].KitTrayTypeVal);;}
    break;

  case 77:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(2) - (11)].XmlIDVal), (yyvsp[(3) - (11)].PhysicalLocationTypeVal), (yyvsp[(4) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (11)].InternalShapeTypeVal), (yyvsp[(6) - (11)].ExternalShapeTypeVal), (yyvsp[(7) - (11)].XmlIDREFVal), (yyvsp[(8) - (11)].KitTrayTypeVal), (yyvsp[(9) - (11)].ListPartTypeVal), (yyvsp[(10) - (11)].ListSlotTypeVal), (yyvsp[(11) - (11)].XmlBooleanVal));;}
    break;

  case 78:

    {(yyval.KitTypeVal) = (yyvsp[(2) - (3)].KitTypeVal);;}
    break;

  case 79:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(2) - (15)].XmlIDVal), (yyvsp[(3) - (15)].PhysicalLocationTypeVal), (yyvsp[(4) - (15)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (15)].InternalShapeTypeVal), (yyvsp[(6) - (15)].ExternalShapeTypeVal), (yyvsp[(7) - (15)].AngleUnitTypeVal), (yyvsp[(8) - (15)].EndEffectorChangingStationTypeVal), (yyvsp[(9) - (15)].ListKitDesignTypeVal), (yyvsp[(10) - (15)].LengthUnitTypeVal), (yyvsp[(11) - (15)].ListSolidObjectTypeVal), (yyvsp[(12) - (15)].ListBoxVolumeTypeVal), (yyvsp[(13) - (15)].RobotTypeVal), (yyvsp[(14) - (15)].ListStockKeepingUnitTypeVal), (yyvsp[(15) - (15)].WeightUnitTypeVal));;}
    break;

  case 80:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 81:

    {(yyval.LargeContainerTypeVal) = (yyvsp[(2) - (3)].LargeContainerTypeVal);;}
    break;

  case 82:

    {yyReadData = 1;;}
    break;

  case 83:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad LengthUnit value");
	  ;}
    break;

  case 84:

    {yyReadData = 1;;}
    break;

  case 85:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Length value");
	  ;}
    break;

  case 86:

    {(yyval.ListEndEffectorHolderTypeVal) = new std::list<EndEffectorHolderType *>;
	   (yyval.ListEndEffectorHolderTypeVal)->push_back((yyvsp[(1) - (1)].EndEffectorHolderTypeVal));;}
    break;

  case 87:

    {(yyval.ListEndEffectorHolderTypeVal) = (yyvsp[(1) - (2)].ListEndEffectorHolderTypeVal);
	   (yyval.ListEndEffectorHolderTypeVal)->push_back((yyvsp[(2) - (2)].EndEffectorHolderTypeVal));;}
    break;

  case 88:

    {(yyval.ListXmlIDREFVal) = new std::list<XmlIDREF *>;;}
    break;

  case 89:

    {(yyval.ListXmlIDREFVal) = (yyvsp[(1) - (2)].ListXmlIDREFVal);
	   (yyval.ListXmlIDREFVal)->push_back((yyvsp[(2) - (2)].XmlIDREFVal));;}
    break;

  case 90:

    {(yyval.ListKitDesignTypeVal) = new std::list<KitDesignType *>;
	   (yyval.ListKitDesignTypeVal)->push_back((yyvsp[(1) - (1)].KitDesignTypeVal));;}
    break;

  case 91:

    {(yyval.ListKitDesignTypeVal) = (yyvsp[(1) - (2)].ListKitDesignTypeVal);
	   (yyval.ListKitDesignTypeVal)->push_back((yyvsp[(2) - (2)].KitDesignTypeVal));;}
    break;

  case 92:

    {(yyval.ListKitTrayTypeVal) = new std::list<KitTrayType *>;;}
    break;

  case 93:

    {(yyval.ListKitTrayTypeVal) = (yyvsp[(1) - (2)].ListKitTrayTypeVal);
	   (yyval.ListKitTrayTypeVal)->push_back((yyvsp[(2) - (2)].KitTrayTypeVal));;}
    break;

  case 94:

    {(yyval.ListKitTypeVal) = new std::list<KitType *>;;}
    break;

  case 95:

    {(yyval.ListKitTypeVal) = (yyvsp[(1) - (2)].ListKitTypeVal);
	   (yyval.ListKitTypeVal)->push_back((yyvsp[(2) - (2)].KitTypeVal));;}
    break;

  case 96:

    {(yyval.ListSolidObjectTypeVal) = new std::list<SolidObjectType *>;;}
    break;

  case 97:

    {(yyval.ListSolidObjectTypeVal) = (yyvsp[(1) - (2)].ListSolidObjectTypeVal);
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 98:

    {(yyval.ListSolidObjectTypeVal) = (yyvsp[(1) - (2)].ListSolidObjectTypeVal);
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(2) - (2)].SolidObjectTypeVal));;}
    break;

  case 99:

    {(yyval.ListSolidObjectTypeVal) = new std::list<SolidObjectType *>;
	   (yyval.ListSolidObjectTypeVal)->push_back((yyvsp[(1) - (1)].SolidObjectTypeVal));;}
    break;

  case 100:

    {(yyval.ListBoxVolumeTypeVal) = new std::list<BoxVolumeType *>;;}
    break;

  case 101:

    {(yyval.ListBoxVolumeTypeVal) = (yyvsp[(1) - (2)].ListBoxVolumeTypeVal);
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 102:

    {(yyval.ListPartRefAndPoseTypeVal) = (yyvsp[(1) - (2)].ListPartRefAndPoseTypeVal);
	   (yyval.ListPartRefAndPoseTypeVal)->push_back((yyvsp[(2) - (2)].PartRefAndPoseTypeVal));;}
    break;

  case 103:

    {(yyval.ListPartRefAndPoseTypeVal) = new std::list<PartRefAndPoseType *>;
	   (yyval.ListPartRefAndPoseTypeVal)->push_back((yyvsp[(1) - (1)].PartRefAndPoseTypeVal));;}
    break;

  case 104:

    {(yyval.ListPartTypeVal) = new std::list<PartType *>;;}
    break;

  case 105:

    {(yyval.ListPartTypeVal) = (yyvsp[(1) - (2)].ListPartTypeVal);
	   (yyval.ListPartTypeVal)->push_back((yyvsp[(2) - (2)].PartTypeVal));;}
    break;

  case 106:

    {(yyval.ListPhysicalLocationTypeVal) = new std::list<PhysicalLocationType *>;;}
    break;

  case 107:

    {(yyval.ListPhysicalLocationTypeVal) = (yyvsp[(1) - (2)].ListPhysicalLocationTypeVal);
	   (yyval.ListPhysicalLocationTypeVal)->push_back((yyvsp[(2) - (2)].PhysicalLocationTypeVal));;}
    break;

  case 108:

    {(yyval.ListStockKeepingUnitTypeVal) = (yyvsp[(1) - (2)].ListStockKeepingUnitTypeVal);
	   (yyval.ListStockKeepingUnitTypeVal)->push_back((yyvsp[(2) - (2)].StockKeepingUnitTypeVal));;}
    break;

  case 109:

    {(yyval.ListStockKeepingUnitTypeVal) = new std::list<StockKeepingUnitType *>;
	   (yyval.ListStockKeepingUnitTypeVal)->push_back((yyvsp[(1) - (1)].StockKeepingUnitTypeVal));;}
    break;

  case 110:

    {(yyval.ListSlotTypeVal) = new std::list<SlotType *>;;}
    break;

  case 111:

    {(yyval.ListSlotTypeVal) = (yyvsp[(1) - (2)].ListSlotTypeVal);
	   (yyval.ListSlotTypeVal)->push_back((yyvsp[(2) - (2)].SlotTypeVal));;}
    break;

  case 112:

    {(yyval.ListBoxVolumeTypeVal) = (yyvsp[(1) - (2)].ListBoxVolumeTypeVal);
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(2) - (2)].BoxVolumeTypeVal));;}
    break;

  case 113:

    {(yyval.ListBoxVolumeTypeVal) = new std::list<BoxVolumeType *>;
	   (yyval.ListBoxVolumeTypeVal)->push_back((yyvsp[(1) - (1)].BoxVolumeTypeVal));;}
    break;

  case 114:

    {yyReadData = 1;;}
    break;

  case 115:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad MaximumLoadWeight value");
	  ;}
    break;

  case 116:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 117:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].InternalShapeTypeVal), (yyvsp[(6) - (6)].ExternalShapeTypeVal));;}
    break;

  case 118:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 119:

    {yyReadData = 1;;}
    break;

  case 120:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 121:

    {yyReadData = 1;;}
    break;

  case 122:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 123:

    {(yyval.XmlStringVal) = 0;;}
    break;

  case 124:

    {yyReadData = 1;;}
    break;

  case 125:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 126:

    {yyReadData = 1;;}
    break;

  case 127:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 128:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 129:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(2) - (3)].SolidObjectTypeVal);;}
    break;

  case 130:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 131:

    {yyReadData = 1;;}
    break;

  case 132:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  ;}
    break;

  case 133:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
    break;

  case 134:

    {(yyval.XmlIDREFVal) = 0;;}
    break;

  case 135:

    {yyReadData = 1;;}
    break;

  case 136:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 137:

    {yyReadData = 1;;}
    break;

  case 138:

    {(yyval.XmlNonNegativeIntegerVal) = (yyvsp[(4) - (5)].XmlNonNegativeIntegerVal);;}
    break;

  case 139:

    {yyReadData = 1;;}
    break;

  case 140:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 141:

    {(yyval.PartRefAndPoseTypeVal) = new PartRefAndPoseType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].XmlIDREFVal), (yyvsp[(4) - (6)].PointTypeVal), (yyvsp[(5) - (6)].VectorTypeVal), (yyvsp[(6) - (6)].VectorTypeVal));;}
    break;

  case 142:

    {(yyval.PartRefAndPoseTypeVal) = (yyvsp[(2) - (3)].PartRefAndPoseTypeVal);;}
    break;

  case 143:

    {yyReadData = 1;;}
    break;

  case 144:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 145:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(2) - (6)].XmlIDVal), (yyvsp[(3) - (6)].PhysicalLocationTypeVal), (yyvsp[(4) - (6)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (6)].XmlIDREFVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));;}
    break;

  case 146:

    {(yyval.PartTypeVal) = (yyvsp[(2) - (3)].PartTypeVal);;}
    break;

  case 147:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 148:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 149:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 150:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 151:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 152:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 153:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 154:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 155:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 156:

    {(yyval.PoseLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 157:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 158:

    {yyReadData = 1;;}
    break;

  case 159:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  ;}
    break;

  case 160:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 161:

    {yyReadData = 1;;}
    break;

  case 162:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 163:

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].PhysicalLocationTypeVal), (yyvsp[(4) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(5) - (10)].InternalShapeTypeVal), (yyvsp[(6) - (10)].ExternalShapeTypeVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].EndEffectorTypeVal), (yyvsp[(9) - (10)].PositiveDecimalTypeVal), (yyvsp[(10) - (10)].ListBoxVolumeTypeVal));;}
    break;

  case 164:

    {(yyval.RobotTypeVal) = (yyvsp[(2) - (3)].RobotTypeVal);;}
    break;

  case 165:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 166:

    {yyReadData = 1;;}
    break;

  case 167:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 168:

    {yyReadData = 1;;}
    break;

  case 169:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 170:

    {(yyval.StockKeepingUnitTypeVal) = (yyvsp[(2) - (3)].StockKeepingUnitTypeVal);;}
    break;

  case 171:

    {(yyval.SlotTypeVal) = new SlotType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlIDREFVal), (yyvsp[(4) - (4)].XmlIDREFVal));;}
    break;

  case 172:

    {(yyval.SlotTypeVal) = (yyvsp[(2) - (3)].SlotTypeVal);;}
    break;

  case 173:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorChangingStationTypeVal);;}
    break;

  case 174:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].EndEffectorHolderTypeVal);;}
    break;

  case 175:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].GripperEffectorTypeVal);;}
    break;

  case 176:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].HumanTypeVal);;}
    break;

  case 177:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTrayTypeVal);;}
    break;

  case 178:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KitTypeVal);;}
    break;

  case 179:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].KittingWorkstationTypeVal);;}
    break;

  case 180:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithEmptyKitTraysTypeVal);;}
    break;

  case 181:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeBoxWithKitsTypeVal);;}
    break;

  case 182:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].LargeContainerTypeVal);;}
    break;

  case 183:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].MechanicalComponentTypeVal);;}
    break;

  case 184:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartTypeVal);;}
    break;

  case 185:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsBinTypeVal);;}
    break;

  case 186:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].PartsTrayTypeVal);;}
    break;

  case 187:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].RobotTypeVal);;}
    break;

  case 188:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorMultiCupTypeVal);;}
    break;

  case 189:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].VacuumEffectorSingleCupTypeVal);;}
    break;

  case 190:

    {(yyval.SolidObjectTypeVal) = (yyvsp[(1) - (1)].WorkTableTypeVal);;}
    break;

  case 191:

    {(yyval.StockKeepingUnitTypeVal) = new StockKeepingUnitType((yyvsp[(2) - (7)].XmlIDVal), (yyvsp[(3) - (7)].XmlStringVal), (yyvsp[(4) - (7)].InternalShapeTypeVal), (yyvsp[(5) - (7)].ExternalShapeTypeVal), (yyvsp[(6) - (7)].PositiveDecimalTypeVal), (yyvsp[(7) - (7)].ListXmlIDREFVal));;}
    break;

  case 192:

    {(yyval.XmlDateTimeVal) = 0;;}
    break;

  case 193:

    {yyReadData = 1;;}
    break;

  case 194:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);;}
    break;

  case 195:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 196:

    {yyReadData = 1;;}
    break;

  case 197:

    {(yyval.WeightUnitTypeVal) = new WeightUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.WeightUnitTypeVal)->bad)
	     yyerror("bad WeightUnit value");
	  ;}
    break;

  case 198:

    {yyReadData = 1;;}
    break;

  case 199:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Weight value");
	  ;}
    break;

  case 200:

    {yyReadData = 1;;}
    break;

  case 201:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad Width value");
	  ;}
    break;

  case 202:

    {(yyval.BoxVolumeTypeVal) = (yyvsp[(2) - (3)].BoxVolumeTypeVal);;}
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

    {(yyval.EndEffectorChangingStationTypeVal) = new EndEffectorChangingStationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].MechanicalComponentTypeVal), (yyvsp[(9) - (9)].ListEndEffectorHolderTypeVal));
	   (yyval.EndEffectorChangingStationTypeVal)->printTypp = true;
	  ;}
    break;

  case 214:

    {(yyval.EndEffectorHolderTypeVal) = new EndEffectorHolderType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].EndEffectorTypeVal));
	   (yyval.EndEffectorHolderTypeVal)->printTypp = true;
	  ;}
    break;

  case 215:

    {(yyval.GripperEffectorTypeVal) = new GripperEffectorType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].PositiveDecimalTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].SolidObjectTypeVal));
	   (yyval.GripperEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 216:

    {(yyval.HumanTypeVal) = new HumanType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.HumanTypeVal)->printTypp = true;
	  ;}
    break;

  case 217:

    {(yyval.KitTrayTypeVal) = new KitTrayType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.KitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 218:

    {(yyval.KitTypeVal) = new KitType((yyvsp[(3) - (12)].XmlIDVal), (yyvsp[(4) - (12)].PhysicalLocationTypeVal), (yyvsp[(5) - (12)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (12)].InternalShapeTypeVal), (yyvsp[(7) - (12)].ExternalShapeTypeVal), (yyvsp[(8) - (12)].XmlIDREFVal), (yyvsp[(9) - (12)].KitTrayTypeVal), (yyvsp[(10) - (12)].ListPartTypeVal), (yyvsp[(11) - (12)].ListSlotTypeVal), (yyvsp[(12) - (12)].XmlBooleanVal));
	   (yyval.KitTypeVal)->printTypp = true;
	  ;}
    break;

  case 219:

    {(yyval.KittingWorkstationTypeVal) = new KittingWorkstationType((yyvsp[(3) - (16)].XmlIDVal), (yyvsp[(4) - (16)].PhysicalLocationTypeVal), (yyvsp[(5) - (16)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (16)].InternalShapeTypeVal), (yyvsp[(7) - (16)].ExternalShapeTypeVal), (yyvsp[(8) - (16)].AngleUnitTypeVal), (yyvsp[(9) - (16)].EndEffectorChangingStationTypeVal), (yyvsp[(10) - (16)].ListKitDesignTypeVal), (yyvsp[(11) - (16)].LengthUnitTypeVal), (yyvsp[(12) - (16)].ListSolidObjectTypeVal), (yyvsp[(13) - (16)].ListBoxVolumeTypeVal), (yyvsp[(14) - (16)].RobotTypeVal), (yyvsp[(15) - (16)].ListStockKeepingUnitTypeVal), (yyvsp[(16) - (16)].WeightUnitTypeVal));
	   (yyval.KittingWorkstationTypeVal)->printTypp = true;
	  ;}
    break;

  case 220:

    {(yyval.LargeBoxWithEmptyKitTraysTypeVal) = new LargeBoxWithEmptyKitTraysType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].PhysicalLocationTypeVal), (yyvsp[(5) - (9)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (9)].InternalShapeTypeVal), (yyvsp[(7) - (9)].ExternalShapeTypeVal), (yyvsp[(8) - (9)].LargeContainerTypeVal), (yyvsp[(9) - (9)].ListKitTrayTypeVal));
	   (yyval.LargeBoxWithEmptyKitTraysTypeVal)->printTypp = true;
	  ;}
    break;

  case 221:

    {(yyval.LargeBoxWithKitsTypeVal) = new LargeBoxWithKitsType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].LargeContainerTypeVal), (yyvsp[(9) - (11)].ListKitTypeVal), (yyvsp[(10) - (11)].XmlIDREFVal), (yyvsp[(11) - (11)].XmlPositiveIntegerVal));
	   (yyval.LargeBoxWithKitsTypeVal)->printTypp = true;
	  ;}
    break;

  case 222:

    {(yyval.LargeContainerTypeVal) = new LargeContainerType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.LargeContainerTypeVal)->printTypp = true;
	  ;}
    break;

  case 223:

    {(yyval.MechanicalComponentTypeVal) = new MechanicalComponentType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].InternalShapeTypeVal), (yyvsp[(7) - (7)].ExternalShapeTypeVal));
	   (yyval.MechanicalComponentTypeVal)->printTypp = true;
	  ;}
    break;

  case 224:

    {(yyval.PartTypeVal) = new PartType((yyvsp[(3) - (7)].XmlIDVal), (yyvsp[(4) - (7)].PhysicalLocationTypeVal), (yyvsp[(5) - (7)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (7)].XmlIDREFVal), (yyvsp[(7) - (7)].XmlNMTOKENVal));
	   (yyval.PartTypeVal)->printTypp = true;
	  ;}
    break;

  case 225:

    {(yyval.PartsBinTypeVal) = new PartsBinType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].ListPartTypeVal));
	   (yyval.PartsBinTypeVal)->printTypp = true;
	  ;}
    break;

  case 226:

    {(yyval.PartsTrayTypeVal) = new PartsTrayType((yyvsp[(3) - (10)].XmlIDVal), (yyvsp[(4) - (10)].PhysicalLocationTypeVal), (yyvsp[(5) - (10)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (10)].XmlIDREFVal), (yyvsp[(7) - (10)].XmlNMTOKENVal), (yyvsp[(8) - (10)].XmlIDREFVal), (yyvsp[(9) - (10)].XmlNonNegativeIntegerVal), (yyvsp[(10) - (10)].ListPartTypeVal));
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

    {(yyval.RobotTypeVal) = new RobotType((yyvsp[(3) - (11)].XmlIDVal), (yyvsp[(4) - (11)].PhysicalLocationTypeVal), (yyvsp[(5) - (11)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (11)].InternalShapeTypeVal), (yyvsp[(7) - (11)].ExternalShapeTypeVal), (yyvsp[(8) - (11)].XmlStringVal), (yyvsp[(9) - (11)].EndEffectorTypeVal), (yyvsp[(10) - (11)].PositiveDecimalTypeVal), (yyvsp[(11) - (11)].ListBoxVolumeTypeVal));
	   (yyval.RobotTypeVal)->printTypp = true;
	  ;}
    break;

  case 233:

    {(yyval.VacuumEffectorMultiCupTypeVal) = new VacuumEffectorMultiCupType((yyvsp[(3) - (15)].XmlIDVal), (yyvsp[(4) - (15)].PhysicalLocationTypeVal), (yyvsp[(5) - (15)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (15)].InternalShapeTypeVal), (yyvsp[(7) - (15)].ExternalShapeTypeVal), (yyvsp[(8) - (15)].XmlStringVal), (yyvsp[(9) - (15)].PositiveDecimalTypeVal), (yyvsp[(10) - (15)].PositiveDecimalTypeVal), (yyvsp[(11) - (15)].SolidObjectTypeVal), (yyvsp[(12) - (15)].PositiveDecimalTypeVal), (yyvsp[(13) - (15)].PositiveDecimalTypeVal), (yyvsp[(14) - (15)].XmlPositiveIntegerVal), (yyvsp[(15) - (15)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorMultiCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 234:

    {(yyval.VacuumEffectorSingleCupTypeVal) = new VacuumEffectorSingleCupType((yyvsp[(3) - (13)].XmlIDVal), (yyvsp[(4) - (13)].PhysicalLocationTypeVal), (yyvsp[(5) - (13)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (13)].InternalShapeTypeVal), (yyvsp[(7) - (13)].ExternalShapeTypeVal), (yyvsp[(8) - (13)].XmlStringVal), (yyvsp[(9) - (13)].PositiveDecimalTypeVal), (yyvsp[(10) - (13)].PositiveDecimalTypeVal), (yyvsp[(11) - (13)].SolidObjectTypeVal), (yyvsp[(12) - (13)].PositiveDecimalTypeVal), (yyvsp[(13) - (13)].PositiveDecimalTypeVal));
	   (yyval.VacuumEffectorSingleCupTypeVal)->printTypp = true;
	  ;}
    break;

  case 235:

    {(yyval.WorkTableTypeVal) = new WorkTableType((yyvsp[(3) - (8)].XmlIDVal), (yyvsp[(4) - (8)].PhysicalLocationTypeVal), (yyvsp[(5) - (8)].ListPhysicalLocationTypeVal), (yyvsp[(6) - (8)].InternalShapeTypeVal), (yyvsp[(7) - (8)].ExternalShapeTypeVal), (yyvsp[(8) - (8)].ListSolidObjectTypeVal));
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

