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
#include "owlCRCLClasses.hh"
#else
#include "CRCLClasses.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

CRCLProgramFile * CRCLProgramTree; // the parse tree

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
     ENDWHOLEITEM = 263,
     SCHEMALOCATION = 264,
     STARTVERSION = 265,
     TERMINALSTRING = 266,
     XMLNSPREFIX = 267,
     XMLNSTARGET = 268,
     XMLVERSION = 269,
     ACCELERATIONEND = 270,
     ACCELERATIONSTART = 271,
     CRCLPROGRAMEND = 272,
     CRCLPROGRAMSTART = 273,
     CLOSEGRIPPEREND = 274,
     CLOSEGRIPPERSTART = 275,
     CLOSETOOLCHANGEREND = 276,
     CLOSETOOLCHANGERSTART = 277,
     DWELLTIMEEND = 278,
     DWELLTIMESTART = 279,
     DWELLEND = 280,
     DWELLSTART = 281,
     ENDCANONEND = 282,
     ENDCANONSTART = 283,
     ENDPOSITIONEND = 284,
     ENDPOSITIONSTART = 285,
     IEND = 286,
     ISTART = 287,
     INITCANONEND = 288,
     INITCANONSTART = 289,
     JEND = 290,
     JSTART = 291,
     KEND = 292,
     KSTART = 293,
     MESSAGEEND = 294,
     MESSAGESTART = 295,
     MOVESTRAIGHTTOEND = 296,
     MOVESTRAIGHTTOSTART = 297,
     MOVETHROUGHTOEND = 298,
     MOVETHROUGHTOSTART = 299,
     NUMPOSITIONSEND = 300,
     NUMPOSITIONSSTART = 301,
     OPENGRIPPEREND = 302,
     OPENGRIPPERSTART = 303,
     OPENTOOLCHANGEREND = 304,
     OPENTOOLCHANGERSTART = 305,
     PERCENTEND = 306,
     PERCENTSTART = 307,
     POINTEND = 308,
     POINTSTART = 309,
     SETABSOLUTEACCELERATIONEND = 310,
     SETABSOLUTEACCELERATIONSTART = 311,
     SETABSOLUTESPEEDEND = 312,
     SETABSOLUTESPEEDSTART = 313,
     SETANGLEUNITSEND = 314,
     SETANGLEUNITSSTART = 315,
     SETENDANGLETOLERANCEEND = 316,
     SETENDANGLETOLERANCESTART = 317,
     SETENDPOINTTOLERANCEEND = 318,
     SETENDPOINTTOLERANCESTART = 319,
     SETINTERMEDIATEPOINTTOLERANCEEND = 320,
     SETINTERMEDIATEPOINTTOLERANCESTART = 321,
     SETLENGTHUNITSEND = 322,
     SETLENGTHUNITSSTART = 323,
     SETRELATIVEACCELERATIONEND = 324,
     SETRELATIVEACCELERATIONSTART = 325,
     SETRELATIVESPEEDEND = 326,
     SETRELATIVESPEEDSTART = 327,
     SPEEDEND = 328,
     SPEEDSTART = 329,
     TOLERANCEEND = 330,
     TOLERANCESTART = 331,
     UNITNAMEEND = 332,
     UNITNAMESTART = 333,
     WAYPOINTEND = 334,
     WAYPOINTSTART = 335,
     XAXISEND = 336,
     XAXISSTART = 337,
     XEND = 338,
     XSTART = 339,
     YEND = 340,
     YSTART = 341,
     ZAXISEND = 342,
     ZAXISSTART = 343,
     ZEND = 344,
     ZSTART = 345,
     CLOSEGRIPPERTYPEDECL = 346,
     CLOSETOOLCHANGERTYPEDECL = 347,
     DWELLTYPEDECL = 348,
     ENDCANONTYPEDECL = 349,
     INITCANONTYPEDECL = 350,
     MESSAGETYPEDECL = 351,
     MIDDLECOMMANDTYPEDECL = 352,
     MOVESTRAIGHTTOTYPEDECL = 353,
     MOVETHROUGHTOTYPEDECL = 354,
     OPENGRIPPERTYPEDECL = 355,
     OPENTOOLCHANGERTYPEDECL = 356,
     SETABSOLUTEACCELERATIONTYPEDECL = 357,
     SETABSOLUTESPEEDTYPEDECL = 358,
     SETANGLEUNITSTYPEDECL = 359,
     SETENDANGLETOLERANCETYPEDECL = 360,
     SETENDPOINTTOLERANCETYPEDECL = 361,
     SETINTERMEDIATEPOINTTOLERANCETYPEDECL = 362,
     SETLENGTHUNITSTYPEDECL = 363,
     SETRELATIVEACCELERATIONTYPEDECL = 364,
     SETRELATIVESPEEDTYPEDECL = 365
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForCRCLProgram *           XmlHeaderForCRCLProgramVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlInteger *                        XmlIntegerVal;
  XmlString *                         XmlStringVal;

  CRCLProgramFile *                   CRCLProgramFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  CRCLProgramType *                   CRCLProgramTypeVal;
  CRCLProgramType_1001_TypeChoicePair * CRCLProgramType_1001_TypeChoicePairVal;
  CRCLProgramType_1001_Type *         CRCLProgramType_1001_TypeVal;
  CloseGripperType *                  CloseGripperTypeVal;
  CloseToolChangerType *              CloseToolChangerTypeVal;
  DwellType *                         DwellTypeVal;
  EndCanonType *                      EndCanonTypeVal;
  InitCanonType *                     InitCanonTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  std::list<CRCLProgramType_1001_TypeChoicePair *> * ListCRCLProgramType_1001_TypeChoicePairVal;
  std::list<PoseType *> *             ListPoseTypeVal;
  MessageType *                       MessageTypeVal;
  MoveStraightToType *                MoveStraightToTypeVal;
  MoveThroughToType *                 MoveThroughToTypeVal;
  OpenGripperType *                   OpenGripperTypeVal;
  OpenToolChangerType *               OpenToolChangerTypeVal;
  PointType *                         PointTypeVal;
  PoseType *                          PoseTypeVal;
  SetAbsoluteAccelerationType *       SetAbsoluteAccelerationTypeVal;
  SetAbsoluteSpeedType *              SetAbsoluteSpeedTypeVal;
  SetAngleUnitsType *                 SetAngleUnitsTypeVal;
  SetEndAngleToleranceType *          SetEndAngleToleranceTypeVal;
  SetEndPointToleranceType *          SetEndPointToleranceTypeVal;
  SetIntermediatePointToleranceType * SetIntermediatePointToleranceTypeVal;
  SetLengthUnitsType *                SetLengthUnitsTypeVal;
  SetRelativeAccelerationType *       SetRelativeAccelerationTypeVal;
  SetRelativeSpeedType *              SetRelativeSpeedTypeVal;
  VectorType *                        VectorTypeVal;



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
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

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
     105,   106,   107,   108,   109,   110
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    17,    19,    21,    26,
      33,    34,    40,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    91,    94,    96,    98,   102,
     105,   106,   112,   115,   119,   121,   123,   127,   130,   134,
     135,   141,   143,   145,   149,   152,   153,   159,   160,   166,
     168,   171,   174,   176,   179,   183,   184,   190,   193,   197,
     201,   205,   206,   212,   214,   216,   220,   223,   225,   227,
     231,   234,   235,   241,   246,   250,   255,   258,   262,   265,
     269,   272,   276,   279,   283,   286,   290,   293,   297,   300,
     304,   307,   311,   314,   318,   319,   325,   326,   332,   333,
     339,   340,   346,   351,   355,   359,   360,   366,   367,   373,
     377,   378
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     112,     0,    -1,   118,    18,   113,   121,    17,    -1,    12,
     114,    -1,     9,    11,    -1,     4,    -1,     4,    -1,     4,
      -1,    10,    14,    11,     7,    -1,    10,    14,    11,     5,
      11,     7,    -1,    -1,    16,     6,   120,   115,    15,    -1,
       6,   143,   122,   137,    -1,   123,    -1,   148,    -1,   127,
      -1,   130,    -1,   134,    -1,   151,    -1,   155,    -1,   157,
      -1,   162,    -1,   165,    -1,   172,    -1,   174,    -1,   176,
      -1,   178,    -1,   180,    -1,   182,    -1,   184,    -1,   186,
      -1,   188,    -1,     6,    -1,     8,    -1,    20,   125,    19,
      -1,    20,   126,    -1,     6,    -1,     8,    -1,    22,   128,
      21,    -1,    22,   129,    -1,    -1,    24,     6,   132,   115,
      23,    -1,     6,   131,    -1,    26,   133,    25,    -1,     6,
      -1,     8,    -1,    28,   135,    27,    -1,    28,   136,    -1,
      30,   170,    29,    -1,    -1,    32,     6,   140,   115,    31,
      -1,     6,    -1,     8,    -1,    34,   141,    33,    -1,    34,
     142,    -1,    -1,    36,     6,   145,   115,    35,    -1,    -1,
      38,     6,   147,   115,    37,    -1,   124,    -1,   148,   124,
      -1,   149,   198,    -1,   198,    -1,     6,   152,    -1,    40,
     150,    39,    -1,    -1,    40,     6,   153,   117,    39,    -1,
       6,   138,    -1,    42,   154,    41,    -1,     6,   149,   158,
      -1,    44,   156,    43,    -1,    -1,    46,     6,   159,   116,
      45,    -1,     6,    -1,     8,    -1,    48,   160,    47,    -1,
      48,   161,    -1,     6,    -1,     8,    -1,    50,   163,    49,
      -1,    50,   164,    -1,    -1,    52,     6,   167,   115,    51,
      -1,     6,   200,   202,   205,    -1,    54,   168,    53,    -1,
       6,   169,   204,   199,    -1,     6,   119,    -1,    56,   171,
      55,    -1,     6,   189,    -1,    58,   173,    57,    -1,     6,
     193,    -1,    60,   175,    59,    -1,     6,   191,    -1,    62,
     177,    61,    -1,     6,   191,    -1,    64,   179,    63,    -1,
       6,   191,    -1,    66,   181,    65,    -1,     6,   195,    -1,
      68,   183,    67,    -1,     6,   166,    -1,    70,   185,    69,
      -1,     6,   166,    -1,    72,   187,    71,    -1,    -1,    74,
       6,   190,   115,    73,    -1,    -1,    76,     6,   192,   115,
      75,    -1,    -1,    78,     6,   194,     4,    77,    -1,    -1,
      78,     6,   196,     4,    77,    -1,     6,   139,   144,   146,
      -1,    80,   170,    79,    -1,    82,   197,    81,    -1,    -1,
      84,     6,   201,   115,    83,    -1,    -1,    86,     6,   203,
     115,    85,    -1,    88,   197,    87,    -1,    -1,    90,     6,
     206,   115,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   265,   265,   275,   280,   286,   294,   302,   310,   315,
     326,   326,   332,   338,   343,   351,   356,   361,   366,   371,
     376,   381,   386,   391,   396,   401,   406,   411,   416,   421,
     426,   431,   439,   444,   449,   451,   456,   461,   466,   468,
     473,   473,   479,   484,   489,   494,   499,   501,   506,   511,
     511,   516,   521,   526,   528,   533,   533,   538,   538,   543,
     547,   555,   558,   564,   569,   574,   574,   579,   584,   589,
     594,   599,   599,   605,   610,   615,   617,   622,   627,   632,
     634,   639,   639,   644,   649,   654,   659,   664,   670,   675,
     680,   685,   690,   695,   701,   706,   712,   717,   724,   729,
     734,   739,   745,   750,   755,   755,   760,   760,   766,   766,
     774,   774,   782,   787,   792,   797,   797,   802,   802,   807,
     812,   812
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BAD", "DATASTRING", "ENCODING",
  "ENDITEM", "ENDVERSION", "ENDWHOLEITEM", "SCHEMALOCATION",
  "STARTVERSION", "TERMINALSTRING", "XMLNSPREFIX", "XMLNSTARGET",
  "XMLVERSION", "ACCELERATIONEND", "ACCELERATIONSTART", "CRCLPROGRAMEND",
  "CRCLPROGRAMSTART", "CLOSEGRIPPEREND", "CLOSEGRIPPERSTART",
  "CLOSETOOLCHANGEREND", "CLOSETOOLCHANGERSTART", "DWELLTIMEEND",
  "DWELLTIMESTART", "DWELLEND", "DWELLSTART", "ENDCANONEND",
  "ENDCANONSTART", "ENDPOSITIONEND", "ENDPOSITIONSTART", "IEND", "ISTART",
  "INITCANONEND", "INITCANONSTART", "JEND", "JSTART", "KEND", "KSTART",
  "MESSAGEEND", "MESSAGESTART", "MOVESTRAIGHTTOEND", "MOVESTRAIGHTTOSTART",
  "MOVETHROUGHTOEND", "MOVETHROUGHTOSTART", "NUMPOSITIONSEND",
  "NUMPOSITIONSSTART", "OPENGRIPPEREND", "OPENGRIPPERSTART",
  "OPENTOOLCHANGEREND", "OPENTOOLCHANGERSTART", "PERCENTEND",
  "PERCENTSTART", "POINTEND", "POINTSTART", "SETABSOLUTEACCELERATIONEND",
  "SETABSOLUTEACCELERATIONSTART", "SETABSOLUTESPEEDEND",
  "SETABSOLUTESPEEDSTART", "SETANGLEUNITSEND", "SETANGLEUNITSSTART",
  "SETENDANGLETOLERANCEEND", "SETENDANGLETOLERANCESTART",
  "SETENDPOINTTOLERANCEEND", "SETENDPOINTTOLERANCESTART",
  "SETINTERMEDIATEPOINTTOLERANCEEND", "SETINTERMEDIATEPOINTTOLERANCESTART",
  "SETLENGTHUNITSEND", "SETLENGTHUNITSSTART", "SETRELATIVEACCELERATIONEND",
  "SETRELATIVEACCELERATIONSTART", "SETRELATIVESPEEDEND",
  "SETRELATIVESPEEDSTART", "SPEEDEND", "SPEEDSTART", "TOLERANCEEND",
  "TOLERANCESTART", "UNITNAMEEND", "UNITNAMESTART", "WAYPOINTEND",
  "WAYPOINTSTART", "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND",
  "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "CLOSEGRIPPERTYPEDECL", "CLOSETOOLCHANGERTYPEDECL", "DWELLTYPEDECL",
  "ENDCANONTYPEDECL", "INITCANONTYPEDECL", "MESSAGETYPEDECL",
  "MIDDLECOMMANDTYPEDECL", "MOVESTRAIGHTTOTYPEDECL",
  "MOVETHROUGHTOTYPEDECL", "OPENGRIPPERTYPEDECL",
  "OPENTOOLCHANGERTYPEDECL", "SETABSOLUTEACCELERATIONTYPEDECL",
  "SETABSOLUTESPEEDTYPEDECL", "SETANGLEUNITSTYPEDECL",
  "SETENDANGLETOLERANCETYPEDECL", "SETENDPOINTTOLERANCETYPEDECL",
  "SETINTERMEDIATEPOINTTOLERANCETYPEDECL", "SETLENGTHUNITSTYPEDECL",
  "SETRELATIVEACCELERATIONTYPEDECL", "SETRELATIVESPEEDTYPEDECL", "$accept",
  "y_CRCLProgramFile", "y_XmlHeaderForCRCLProgram", "y_SchemaLocation",
  "y_XmlDecimal", "y_XmlInteger", "y_XmlString", "y_XmlVersion",
  "y_Acceleration_XmlDecimal", "$@1", "y_CRCLProgramType",
  "y_CRCLProgramType_1001_CRCLProgr1002", "y_CRCLProgramType_1001_Type",
  "y_CRCLProgramType_1001_TypeChoicePair", "y_CloseGripperType",
  "y_CloseGripperType_Whole", "y_CloseGripper_CloseGripperType",
  "y_CloseToolChangerType", "y_CloseToolChangerType_Whole",
  "y_CloseToolChanger_CloseToolChan1003", "y_DwellTime_XmlDecimal", "$@2",
  "y_DwellType", "y_Dwell_DwellType", "y_EndCanonType",
  "y_EndCanonType_Whole", "y_EndCanon_EndCanonType",
  "y_EndPosition_PoseType", "y_I_XmlDecimal", "$@3", "y_InitCanonType",
  "y_InitCanonType_Whole", "y_InitCanon_InitCanonType", "y_J_XmlDecimal",
  "$@4", "y_K_XmlDecimal", "$@5",
  "y_ListCRCLProgramType_1001_TypeChoicePair",
  "y_ListWaypoint_PoseType_1_u", "y_MessageType", "y_Message_MessageType",
  "y_Message_XmlString", "$@6", "y_MoveStraightToType",
  "y_MoveStraightTo_MoveStraightToType", "y_MoveThroughToType",
  "y_MoveThroughTo_MoveThroughToType", "y_NumPositions_XmlInteger", "$@7",
  "y_OpenGripperType", "y_OpenGripperType_Whole",
  "y_OpenGripper_OpenGripperType", "y_OpenToolChangerType",
  "y_OpenToolChangerType_Whole", "y_OpenToolChanger_OpenToolChangerType",
  "y_Percent_XmlDecimal", "$@8", "y_PointType", "y_Point_PointType",
  "y_PoseType", "y_SetAbsoluteAccelerationType",
  "y_SetAbsoluteAcceleration_SetAbs1004", "y_SetAbsoluteSpeedType",
  "y_SetAbsoluteSpeed_SetAbsoluteSp1005", "y_SetAngleUnitsType",
  "y_SetAngleUnits_SetAngleUnitsType", "y_SetEndAngleToleranceType",
  "y_SetEndAngleTolerance_SetEndAng1006", "y_SetEndPointToleranceType",
  "y_SetEndPointTolerance_SetEndPoi1007",
  "y_SetIntermediatePointToleranceType",
  "y_SetIntermediatePointTolerance_1008", "y_SetLengthUnitsType",
  "y_SetLengthUnits_SetLengthUnitsType", "y_SetRelativeAccelerationType",
  "y_SetRelativeAcceleration_SetRel1009", "y_SetRelativeSpeedType",
  "y_SetRelativeSpeed_SetRelativeSp1010", "y_Speed_XmlDecimal", "$@9",
  "y_Tolerance_XmlDecimal", "$@10", "y_UnitName_AngleUnitType", "$@11",
  "y_UnitName_LengthUnitType", "$@12", "y_VectorType",
  "y_Waypoint_PoseType_1_u", "y_XAxis_VectorType", "y_X_XmlDecimal",
  "$@13", "y_Y_XmlDecimal", "$@14", "y_ZAxis_VectorType", "y_Z_XmlDecimal",
  "$@15", 0
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
     365
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   111,   112,   113,   114,   115,   116,   117,   118,   118,
     120,   119,   121,   122,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   126,   127,   127,   128,   129,   130,   130,
     132,   131,   133,   134,   135,   136,   137,   137,   138,   140,
     139,   141,   142,   143,   143,   145,   144,   147,   146,   148,
     148,   149,   149,   150,   151,   153,   152,   154,   155,   156,
     157,   159,   158,   160,   161,   162,   162,   163,   164,   165,
     165,   167,   166,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   190,   189,   192,   191,   194,   193,
     196,   195,   197,   198,   199,   201,   200,   203,   202,   204,
     206,   205
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     1,     1,     4,     6,
       0,     5,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     1,     3,     2,
       0,     5,     2,     3,     1,     1,     3,     2,     3,     0,
       5,     1,     1,     3,     2,     0,     5,     0,     5,     1,
       2,     2,     1,     2,     3,     0,     5,     2,     3,     3,
       3,     0,     5,     1,     1,     3,     2,     1,     1,     3,
       2,     0,     5,     4,     3,     4,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     0,     5,     0,     5,     0,     5,
       0,     5,     4,     3,     3,     0,     5,     0,     5,     3,
       0,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     8,     0,     3,     0,     0,     0,     4,     0,     0,
       2,     9,    51,    52,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    59,    15,    16,    17,    14,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    53,    32,    33,     0,    35,    36,
      37,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    76,    77,    78,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    60,
      34,    38,     0,    42,    43,     0,    63,    64,     0,    67,
      68,     0,     0,    62,    70,    75,    79,     0,    86,    87,
       0,    88,    89,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,     0,    98,    99,     0,   100,   101,   102,
     103,    44,    45,     0,    47,    40,    65,     0,     0,     0,
       0,    69,    61,    10,   104,   108,   106,   110,    81,    46,
       0,     0,     0,     0,    48,   113,    71,     0,     0,     0,
       0,     0,     0,     5,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    66,
       0,     0,    84,     0,     0,     0,    85,     6,     0,    11,
     105,   109,   107,   111,    82,   115,     0,     0,     0,     0,
     119,     0,    72,     0,   117,     0,    83,    49,     0,     0,
     114,     0,     0,   120,     0,    55,     0,   112,   116,     0,
       0,     0,     0,    57,   118,     0,    50,     0,     0,   121,
      56,     0,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,   184,   208,   186,     3,   128,   177,
      15,    43,    44,    45,    67,    68,    46,    71,    72,    47,
     113,   170,    74,    48,   153,   154,   108,   119,   219,   234,
      24,    25,    19,   229,   242,   237,   248,    49,   122,    76,
      50,   116,   171,    78,    51,    80,    52,   161,   191,    83,
      84,    53,    87,    88,    54,   147,   182,   188,   173,   158,
      90,    55,    92,    56,    94,    57,    96,    58,    98,    59,
     100,    60,   102,    61,   104,    62,   106,    63,   131,   178,
     137,   180,   134,   179,   144,   181,   204,   123,   206,   201,
     223,   217,   232,   190,   226,   240
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
      -3,   -12,    10,    -2,    17,  -178,    19,     1,    20,    24,
      22,  -178,    26,  -178,     5,    27,    28,  -178,     3,    -8,
    -178,  -178,  -178,  -178,     8,  -178,     7,    11,    37,    39,
      41,    43,    14,    15,    45,    47,    53,    55,    60,    61,
      62,    63,    64,    44,  -178,  -178,  -178,  -178,  -178,    -8,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,    54,  -178,  -178,
    -178,    56,  -178,    50,    51,    35,    40,    48,    42,     0,
      38,  -178,  -178,    46,  -178,  -178,  -178,    33,  -178,    68,
      30,    12,    31,     9,    32,    13,    29,    13,    34,    13,
      36,    16,    25,    52,    49,    52,    57,    18,  -178,  -178,
    -178,  -178,    89,  -178,  -178,    90,  -178,  -178,    92,  -178,
    -178,    92,   -42,  -178,  -178,  -178,  -178,    93,  -178,  -178,
      94,  -178,  -178,    96,  -178,  -178,    97,  -178,  -178,  -178,
    -178,  -178,  -178,    99,  -178,  -178,   100,  -178,  -178,  -178,
    -178,  -178,  -178,    80,  -178,  -178,  -178,    58,    79,    59,
     103,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
     106,   107,   108,    65,  -178,  -178,  -178,   106,   106,   109,
     106,   111,   106,  -178,    98,  -178,    77,    66,    67,   113,
      69,   118,   102,    70,    71,    72,    75,    73,  -178,  -178,
     117,    74,  -178,    95,    76,   113,  -178,  -178,    81,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,   119,    78,   123,   101,
    -178,    83,  -178,   106,  -178,   124,  -178,  -178,   125,   104,
    -178,    82,   106,  -178,   106,  -178,   126,  -178,  -178,    84,
     106,   105,   106,  -178,  -178,    85,  -178,   110,   106,  -178,
    -178,   112,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -178,  -177,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,    86,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,    87,  -178,  -178,  -178,    23,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
     -72,  -178,  -178,  -178,  -178,  -178,   -71,    88,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     192,   193,     4,   195,   160,   197,    10,     1,    11,    22,
       5,    23,    26,    65,    27,    66,     6,    69,    28,    70,
      81,    85,    82,    86,   151,   139,   152,   141,     7,    12,
      14,     8,    29,    16,    30,    21,    31,    17,   121,    18,
      32,    64,    33,    73,    20,    75,   231,    77,    34,    79,
      35,    89,    36,    91,    37,   239,    38,   241,    39,    93,
      40,    95,    41,   245,    42,   247,    97,    99,   101,   103,
     105,   251,   107,   110,   112,   115,   114,   111,   118,   117,
     121,   124,   126,   120,   127,   129,   130,   133,   132,   136,
     138,   135,   145,   125,   143,   155,   156,   140,   157,   163,
     164,   142,   165,   166,   146,   167,   168,   169,   174,   176,
     183,   185,   172,   194,   187,   196,   199,   209,   148,   203,
     202,   198,   207,   215,   214,   224,   222,   218,   150,   227,
     233,   235,   243,     0,   221,   109,   246,   228,   175,     0,
       0,     0,   236,   210,   159,   250,     0,   212,   211,   252,
     200,   205,   213,   189,     0,     0,     0,     0,     0,     0,
     216,     0,     0,   220,   230,   238,     0,     0,   225,   244,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-178))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     177,   178,    14,   180,    46,   182,     5,    10,     7,     6,
       0,     8,    20,     6,    22,     8,    18,     6,    26,     8,
       6,     6,     8,     8,     6,    97,     8,    99,    11,     9,
       6,    12,    40,    11,    42,     7,    44,    11,    80,    34,
      48,    33,    50,     6,    17,     6,   223,     6,    56,     6,
      58,     6,    60,     6,    62,   232,    64,   234,    66,     6,
      68,     6,    70,   240,    72,   242,     6,     6,     6,     6,
       6,   248,    28,    19,    24,    40,    25,    21,    30,    39,
      80,    43,    49,    41,    16,    55,    74,    78,    57,    76,
      61,    59,    67,    47,    78,     6,     6,    63,     6,     6,
       6,    65,     6,     6,    52,     6,     6,    27,    29,     6,
       4,     4,    54,     4,     6,     4,    39,    15,    69,     6,
      53,    23,     4,     6,    51,     6,    45,    32,    71,     6,
       6,     6,     6,    -1,   205,    49,    31,    36,    79,    -1,
      -1,    -1,    38,    73,   121,    35,    -1,    75,    77,    37,
      84,    82,    77,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    87,    81,    83,    -1,    -1,    90,    85,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,   112,   118,    14,     0,    18,    11,    12,   113,
       5,     7,     9,   114,     6,   121,    11,    11,    34,   143,
      17,     7,     6,     8,   141,   142,    20,    22,    26,    40,
      42,    44,    48,    50,    56,    58,    60,    62,    64,    66,
      68,    70,    72,   122,   123,   124,   127,   130,   134,   148,
     151,   155,   157,   162,   165,   172,   174,   176,   178,   180,
     182,   184,   186,   188,    33,     6,     8,   125,   126,     6,
       8,   128,   129,     6,   133,     6,   150,     6,   154,     6,
     156,     6,     8,   160,   161,     6,     8,   163,   164,     6,
     171,     6,   173,     6,   175,     6,   177,     6,   179,     6,
     181,     6,   183,     6,   185,     6,   187,    28,   137,   124,
      19,    21,    24,   131,    25,    40,   152,    39,    30,   138,
      41,    80,   149,   198,    43,    47,    49,    16,   119,    55,
      74,   189,    57,    78,   193,    59,    76,   191,    61,   191,
      63,   191,    65,    78,   195,    67,    52,   166,    69,   166,
      71,     6,     8,   135,   136,     6,     6,     6,   170,   170,
      46,   158,   198,     6,     6,     6,     6,     6,     6,    27,
     132,   153,    54,   169,    29,    79,     6,   120,   190,   194,
     192,   196,   167,     4,   115,     4,   117,     6,   168,    88,
     204,   159,   115,   115,     4,   115,     4,   115,    23,    39,
      84,   200,    53,     6,   197,    82,   199,     4,   116,    15,
      73,    77,    75,    77,    51,     6,    86,   202,    32,   139,
      87,   197,    45,   201,     6,    90,   205,     6,    36,   144,
      81,   115,   203,     6,   140,     6,    38,   146,    83,   115,
     206,   115,   145,     6,    85,   115,    31,   115,   147,    89,
      35,   115,    37
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

    {(yyval.CRCLProgramFileVal) = new CRCLProgramFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForCRCLProgramVal), (yyvsp[(4) - (5)].CRCLProgramTypeVal));
	   CRCLProgramTree = (yyval.CRCLProgramFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
    break;

  case 3:

    {(yyval.XmlHeaderForCRCLProgramVal) = new XmlHeaderForCRCLProgram((yyvsp[(2) - (2)].SchemaLocationVal));}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal), false);
	  }
    break;

  case 5:

    {(yyval.XmlDecimalVal) = new XmlDecimal((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDecimalVal)->bad)
	     yyerror("bad XmlDecimal");
	  }
    break;

  case 6:

    {(yyval.XmlIntegerVal) = new XmlInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlIntegerVal)->bad)
	     yyerror("bad XmlInteger");
	  }
    break;

  case 7:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  }
    break;

  case 8:

    {(yyval.XmlVersionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  }
    break;

  case 9:

    {(yyval.XmlVersionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if ((strcmp((yyvsp[(5) - (6)].sVal), "UTF-8")) && (strcmp((yyvsp[(5) - (6)].sVal), "utf-8")))
	     yyerror("encoding must be UTF-8");
	  }
    break;

  case 10:

    {yyReadData = 1;}
    break;

  case 11:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 12:

    {(yyval.CRCLProgramTypeVal) = new CRCLProgramType((yyvsp[(2) - (4)].InitCanonTypeVal), (yyvsp[(3) - (4)].CRCLProgramType_1001_TypeVal), (yyvsp[(4) - (4)].EndCanonTypeVal));}
    break;

  case 13:

    {(yyval.CRCLProgramType_1001_TypeVal) = (yyvsp[(1) - (1)].CRCLProgramType_1001_TypeVal);}
    break;

  case 14:

    {(yyval.CRCLProgramType_1001_TypeVal) = new CRCLProgramType_1001_Type((yyvsp[(1) - (1)].ListCRCLProgramType_1001_TypeChoicePairVal));
	   if ((yyvsp[(1) - (1)].ListCRCLProgramType_1001_TypeChoicePairVal)->size() < 1)
	     yyerror("at least 1 choice is required");
	  }
    break;

  case 15:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::CloseGripperE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.CloseGripper = (yyvsp[(1) - (1)].CloseGripperTypeVal);
	  }
    break;

  case 16:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::CloseToolChangerE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.CloseToolChanger = (yyvsp[(1) - (1)].CloseToolChangerTypeVal);
	  }
    break;

  case 17:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::DwellE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.Dwell = (yyvsp[(1) - (1)].DwellTypeVal);
	  }
    break;

  case 18:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MessageE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.Message = (yyvsp[(1) - (1)].MessageTypeVal);
	  }
    break;

  case 19:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MoveStraightToE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.MoveStraightTo = (yyvsp[(1) - (1)].MoveStraightToTypeVal);
	  }
    break;

  case 20:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MoveThroughToE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.MoveThroughTo = (yyvsp[(1) - (1)].MoveThroughToTypeVal);
	  }
    break;

  case 21:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenGripperE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.OpenGripper = (yyvsp[(1) - (1)].OpenGripperTypeVal);
	  }
    break;

  case 22:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenToolChangerE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.OpenToolChanger = (yyvsp[(1) - (1)].OpenToolChangerTypeVal);
	  }
    break;

  case 23:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteAccelerationE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAbsoluteAcceleration = (yyvsp[(1) - (1)].SetAbsoluteAccelerationTypeVal);
	  }
    break;

  case 24:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteSpeedE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAbsoluteSpeed = (yyvsp[(1) - (1)].SetAbsoluteSpeedTypeVal);
	  }
    break;

  case 25:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAngleUnitsE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAngleUnits = (yyvsp[(1) - (1)].SetAngleUnitsTypeVal);
	  }
    break;

  case 26:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndAngleToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetEndAngleTolerance = (yyvsp[(1) - (1)].SetEndAngleToleranceTypeVal);
	  }
    break;

  case 27:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndPointToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetEndPointTolerance = (yyvsp[(1) - (1)].SetEndPointToleranceTypeVal);
	  }
    break;

  case 28:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetIntermediatePointToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetIntermediatePointTolerance = (yyvsp[(1) - (1)].SetIntermediatePointToleranceTypeVal);
	  }
    break;

  case 29:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetLengthUnitsE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetLengthUnits = (yyvsp[(1) - (1)].SetLengthUnitsTypeVal);
	  }
    break;

  case 30:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeAccelerationE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetRelativeAcceleration = (yyvsp[(1) - (1)].SetRelativeAccelerationTypeVal);
	  }
    break;

  case 31:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeSpeedE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetRelativeSpeed = (yyvsp[(1) - (1)].SetRelativeSpeedTypeVal);
	  }
    break;

  case 32:

    {(yyval.CloseGripperTypeVal) = new CloseGripperType();}
    break;

  case 33:

    {(yyval.CloseGripperTypeVal) = new CloseGripperType();}
    break;

  case 34:

    {(yyval.CloseGripperTypeVal) = (yyvsp[(2) - (3)].CloseGripperTypeVal);}
    break;

  case 35:

    {(yyval.CloseGripperTypeVal) = (yyvsp[(2) - (2)].CloseGripperTypeVal);}
    break;

  case 36:

    {(yyval.CloseToolChangerTypeVal) = new CloseToolChangerType();}
    break;

  case 37:

    {(yyval.CloseToolChangerTypeVal) = new CloseToolChangerType();}
    break;

  case 38:

    {(yyval.CloseToolChangerTypeVal) = (yyvsp[(2) - (3)].CloseToolChangerTypeVal);}
    break;

  case 39:

    {(yyval.CloseToolChangerTypeVal) = (yyvsp[(2) - (2)].CloseToolChangerTypeVal);}
    break;

  case 40:

    {yyReadData = 1;}
    break;

  case 41:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 42:

    {(yyval.DwellTypeVal) = new DwellType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 43:

    {(yyval.DwellTypeVal) = (yyvsp[(2) - (3)].DwellTypeVal);}
    break;

  case 44:

    {(yyval.EndCanonTypeVal) = new EndCanonType();}
    break;

  case 45:

    {(yyval.EndCanonTypeVal) = new EndCanonType();}
    break;

  case 46:

    {(yyval.EndCanonTypeVal) = (yyvsp[(2) - (3)].EndCanonTypeVal);}
    break;

  case 47:

    {(yyval.EndCanonTypeVal) = (yyvsp[(2) - (2)].EndCanonTypeVal);}
    break;

  case 48:

    {(yyval.PoseTypeVal) = (yyvsp[(2) - (3)].PoseTypeVal);}
    break;

  case 49:

    {yyReadData = 1;}
    break;

  case 50:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 51:

    {(yyval.InitCanonTypeVal) = new InitCanonType();}
    break;

  case 52:

    {(yyval.InitCanonTypeVal) = new InitCanonType();}
    break;

  case 53:

    {(yyval.InitCanonTypeVal) = (yyvsp[(2) - (3)].InitCanonTypeVal);}
    break;

  case 54:

    {(yyval.InitCanonTypeVal) = (yyvsp[(2) - (2)].InitCanonTypeVal);}
    break;

  case 55:

    {yyReadData = 1;}
    break;

  case 56:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 57:

    {yyReadData = 1;}
    break;

  case 58:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 59:

    {(yyval.ListCRCLProgramType_1001_TypeChoicePairVal) = new std::list<CRCLProgramType_1001_TypeChoicePair *>;
	   (yyval.ListCRCLProgramType_1001_TypeChoicePairVal)->push_back((yyvsp[(1) - (1)].CRCLProgramType_1001_TypeChoicePairVal));
	  }
    break;

  case 60:

    {(yyval.ListCRCLProgramType_1001_TypeChoicePairVal) = (yyvsp[(1) - (2)].ListCRCLProgramType_1001_TypeChoicePairVal);
	   (yyval.ListCRCLProgramType_1001_TypeChoicePairVal)->push_back((yyvsp[(2) - (2)].CRCLProgramType_1001_TypeChoicePairVal));
	  }
    break;

  case 61:

    {(yyval.ListPoseTypeVal) = (yyvsp[(1) - (2)].ListPoseTypeVal);
	   (yyval.ListPoseTypeVal)->push_back((yyvsp[(2) - (2)].PoseTypeVal));}
    break;

  case 62:

    {(yyval.ListPoseTypeVal) = new std::list<PoseType *>;
	   (yyval.ListPoseTypeVal)->push_back((yyvsp[(1) - (1)].PoseTypeVal));}
    break;

  case 63:

    {(yyval.MessageTypeVal) = new MessageType((yyvsp[(2) - (2)].XmlStringVal));}
    break;

  case 64:

    {(yyval.MessageTypeVal) = (yyvsp[(2) - (3)].MessageTypeVal);}
    break;

  case 65:

    {yyReadData = 1;}
    break;

  case 66:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 67:

    {(yyval.MoveStraightToTypeVal) = new MoveStraightToType((yyvsp[(2) - (2)].PoseTypeVal));}
    break;

  case 68:

    {(yyval.MoveStraightToTypeVal) = (yyvsp[(2) - (3)].MoveStraightToTypeVal);}
    break;

  case 69:

    {(yyval.MoveThroughToTypeVal) = new MoveThroughToType((yyvsp[(2) - (3)].ListPoseTypeVal), (yyvsp[(3) - (3)].XmlIntegerVal));}
    break;

  case 70:

    {(yyval.MoveThroughToTypeVal) = (yyvsp[(2) - (3)].MoveThroughToTypeVal);}
    break;

  case 71:

    {yyReadData = 1;}
    break;

  case 72:

    {(yyval.XmlIntegerVal) = (yyvsp[(4) - (5)].XmlIntegerVal);}
    break;

  case 73:

    {(yyval.OpenGripperTypeVal) = new OpenGripperType();}
    break;

  case 74:

    {(yyval.OpenGripperTypeVal) = new OpenGripperType();}
    break;

  case 75:

    {(yyval.OpenGripperTypeVal) = (yyvsp[(2) - (3)].OpenGripperTypeVal);}
    break;

  case 76:

    {(yyval.OpenGripperTypeVal) = (yyvsp[(2) - (2)].OpenGripperTypeVal);}
    break;

  case 77:

    {(yyval.OpenToolChangerTypeVal) = new OpenToolChangerType();}
    break;

  case 78:

    {(yyval.OpenToolChangerTypeVal) = new OpenToolChangerType();}
    break;

  case 79:

    {(yyval.OpenToolChangerTypeVal) = (yyvsp[(2) - (3)].OpenToolChangerTypeVal);}
    break;

  case 80:

    {(yyval.OpenToolChangerTypeVal) = (yyvsp[(2) - (2)].OpenToolChangerTypeVal);}
    break;

  case 81:

    {yyReadData = 1;}
    break;

  case 82:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 83:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (4)].XmlDecimalVal), (yyvsp[(3) - (4)].XmlDecimalVal), (yyvsp[(4) - (4)].XmlDecimalVal));}
    break;

  case 84:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 85:

    {(yyval.PoseTypeVal) = new PoseType((yyvsp[(2) - (4)].PointTypeVal), (yyvsp[(3) - (4)].VectorTypeVal), (yyvsp[(4) - (4)].VectorTypeVal));}
    break;

  case 86:

    {(yyval.SetAbsoluteAccelerationTypeVal) = new SetAbsoluteAccelerationType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 87:

    {(yyval.SetAbsoluteAccelerationTypeVal) = (yyvsp[(2) - (3)].SetAbsoluteAccelerationTypeVal);}
    break;

  case 88:

    {(yyval.SetAbsoluteSpeedTypeVal) = new SetAbsoluteSpeedType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 89:

    {(yyval.SetAbsoluteSpeedTypeVal) = (yyvsp[(2) - (3)].SetAbsoluteSpeedTypeVal);}
    break;

  case 90:

    {(yyval.SetAngleUnitsTypeVal) = new SetAngleUnitsType((yyvsp[(2) - (2)].AngleUnitTypeVal));}
    break;

  case 91:

    {(yyval.SetAngleUnitsTypeVal) = (yyvsp[(2) - (3)].SetAngleUnitsTypeVal);}
    break;

  case 92:

    {(yyval.SetEndAngleToleranceTypeVal) = new SetEndAngleToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 93:

    {(yyval.SetEndAngleToleranceTypeVal) = (yyvsp[(2) - (3)].SetEndAngleToleranceTypeVal);}
    break;

  case 94:

    {(yyval.SetEndPointToleranceTypeVal) = new SetEndPointToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 95:

    {(yyval.SetEndPointToleranceTypeVal) = (yyvsp[(2) - (3)].SetEndPointToleranceTypeVal);}
    break;

  case 96:

    {(yyval.SetIntermediatePointToleranceTypeVal) = new SetIntermediatePointToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 97:

    {(yyval.SetIntermediatePointToleranceTypeVal) = (yyvsp[(2) - (3)].SetIntermediatePointToleranceTypeVal);}
    break;

  case 98:

    {(yyval.SetLengthUnitsTypeVal) = new SetLengthUnitsType((yyvsp[(2) - (2)].LengthUnitTypeVal));}
    break;

  case 99:

    {(yyval.SetLengthUnitsTypeVal) = (yyvsp[(2) - (3)].SetLengthUnitsTypeVal);}
    break;

  case 100:

    {(yyval.SetRelativeAccelerationTypeVal) = new SetRelativeAccelerationType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 101:

    {(yyval.SetRelativeAccelerationTypeVal) = (yyvsp[(2) - (3)].SetRelativeAccelerationTypeVal);}
    break;

  case 102:

    {(yyval.SetRelativeSpeedTypeVal) = new SetRelativeSpeedType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 103:

    {(yyval.SetRelativeSpeedTypeVal) = (yyvsp[(2) - (3)].SetRelativeSpeedTypeVal);}
    break;

  case 104:

    {yyReadData = 1;}
    break;

  case 105:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 106:

    {yyReadData = 1;}
    break;

  case 107:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 108:

    {yyReadData = 1;}
    break;

  case 109:

    {(yyval.AngleUnitTypeVal) = new AngleUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.AngleUnitTypeVal)->bad)
	     yyerror("bad UnitName value");
	  }
    break;

  case 110:

    {yyReadData = 1;}
    break;

  case 111:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad UnitName value");
	  }
    break;

  case 112:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (4)].XmlDecimalVal), (yyvsp[(3) - (4)].XmlDecimalVal), (yyvsp[(4) - (4)].XmlDecimalVal));}
    break;

  case 113:

    {(yyval.PoseTypeVal) = (yyvsp[(2) - (3)].PoseTypeVal);}
    break;

  case 114:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 115:

    {yyReadData = 1;}
    break;

  case 116:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 117:

    {yyReadData = 1;}
    break;

  case 118:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 119:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 120:

    {yyReadData = 1;}
    break;

  case 121:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
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

