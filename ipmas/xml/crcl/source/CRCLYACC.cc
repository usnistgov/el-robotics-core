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
     MOVETOEND = 300,
     MOVETOSTART = 301,
     NUMPOSITIONSEND = 302,
     NUMPOSITIONSSTART = 303,
     OPENGRIPPEREND = 304,
     OPENGRIPPERSTART = 305,
     OPENTOOLCHANGEREND = 306,
     OPENTOOLCHANGERSTART = 307,
     PERCENTEND = 308,
     PERCENTSTART = 309,
     POINTEND = 310,
     POINTSTART = 311,
     SETABSOLUTEACCELERATIONEND = 312,
     SETABSOLUTEACCELERATIONSTART = 313,
     SETABSOLUTESPEEDEND = 314,
     SETABSOLUTESPEEDSTART = 315,
     SETANGLEUNITSEND = 316,
     SETANGLEUNITSSTART = 317,
     SETENDANGLETOLERANCEEND = 318,
     SETENDANGLETOLERANCESTART = 319,
     SETENDPOINTTOLERANCEEND = 320,
     SETENDPOINTTOLERANCESTART = 321,
     SETINTERMEDIATEPOINTTOLERANCEEND = 322,
     SETINTERMEDIATEPOINTTOLERANCESTART = 323,
     SETLENGTHUNITSEND = 324,
     SETLENGTHUNITSSTART = 325,
     SETRELATIVEACCELERATIONEND = 326,
     SETRELATIVEACCELERATIONSTART = 327,
     SETRELATIVESPEEDEND = 328,
     SETRELATIVESPEEDSTART = 329,
     SPEEDEND = 330,
     SPEEDSTART = 331,
     TOLERANCEEND = 332,
     TOLERANCESTART = 333,
     UNITNAMEEND = 334,
     UNITNAMESTART = 335,
     WAYPOINTEND = 336,
     WAYPOINTSTART = 337,
     XAXISEND = 338,
     XAXISSTART = 339,
     XEND = 340,
     XSTART = 341,
     YEND = 342,
     YSTART = 343,
     ZAXISEND = 344,
     ZAXISSTART = 345,
     ZEND = 346,
     ZSTART = 347,
     CLOSEGRIPPERTYPEDECL = 348,
     CLOSETOOLCHANGERTYPEDECL = 349,
     DWELLTYPEDECL = 350,
     ENDCANONTYPEDECL = 351,
     INITCANONTYPEDECL = 352,
     MESSAGETYPEDECL = 353,
     MIDDLECOMMANDTYPEDECL = 354,
     MOVESTRAIGHTTOTYPEDECL = 355,
     MOVETHROUGHTOTYPEDECL = 356,
     MOVETOTYPEDECL = 357,
     OPENGRIPPERTYPEDECL = 358,
     OPENTOOLCHANGERTYPEDECL = 359,
     SETABSOLUTEACCELERATIONTYPEDECL = 360,
     SETABSOLUTESPEEDTYPEDECL = 361,
     SETANGLEUNITSTYPEDECL = 362,
     SETENDANGLETOLERANCETYPEDECL = 363,
     SETENDPOINTTOLERANCETYPEDECL = 364,
     SETINTERMEDIATEPOINTTOLERANCETYPEDECL = 365,
     SETLENGTHUNITSTYPEDECL = 366,
     SETRELATIVEACCELERATIONTYPEDECL = 367,
     SETRELATIVESPEEDTYPEDECL = 368
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
  MoveToType *                        MoveToTypeVal;
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
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   368

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
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    17,    19,    21,    26,
      33,    34,    40,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    93,    96,    98,   100,
     104,   107,   108,   114,   117,   121,   123,   125,   129,   132,
     136,   137,   143,   145,   147,   151,   154,   155,   161,   162,
     168,   170,   173,   176,   178,   181,   185,   186,   192,   195,
     199,   203,   207,   210,   214,   215,   221,   223,   225,   229,
     232,   234,   236,   240,   243,   244,   250,   255,   259,   264,
     267,   271,   274,   278,   281,   285,   288,   292,   295,   299,
     302,   306,   309,   313,   316,   320,   323,   327,   328,   334,
     335,   341,   342,   348,   349,   355,   360,   364,   368,   369,
     375,   376,   382,   386,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     115,     0,    -1,   121,    18,   116,   124,    17,    -1,    12,
     117,    -1,     9,    11,    -1,     4,    -1,     4,    -1,     4,
      -1,    10,    14,    11,     7,    -1,    10,    14,    11,     5,
      11,     7,    -1,    -1,    16,     6,   123,   118,    15,    -1,
       6,   146,   125,   140,    -1,   126,    -1,   151,    -1,   130,
      -1,   133,    -1,   137,    -1,   154,    -1,   158,    -1,   160,
      -1,   162,    -1,   167,    -1,   170,    -1,   177,    -1,   179,
      -1,   181,    -1,   183,    -1,   185,    -1,   187,    -1,   189,
      -1,   191,    -1,   193,    -1,     6,    -1,     8,    -1,    20,
     128,    19,    -1,    20,   129,    -1,     6,    -1,     8,    -1,
      22,   131,    21,    -1,    22,   132,    -1,    -1,    24,     6,
     135,   118,    23,    -1,     6,   134,    -1,    26,   136,    25,
      -1,     6,    -1,     8,    -1,    28,   138,    27,    -1,    28,
     139,    -1,    30,   175,    29,    -1,    -1,    32,     6,   143,
     118,    31,    -1,     6,    -1,     8,    -1,    34,   144,    33,
      -1,    34,   145,    -1,    -1,    36,     6,   148,   118,    35,
      -1,    -1,    38,     6,   150,   118,    37,    -1,   127,    -1,
     151,   127,    -1,   152,   203,    -1,   203,    -1,     6,   155,
      -1,    40,   153,    39,    -1,    -1,    40,     6,   156,   120,
      39,    -1,     6,   141,    -1,    42,   157,    41,    -1,     6,
     152,   163,    -1,    44,   159,    43,    -1,     6,   141,    -1,
      46,   161,    45,    -1,    -1,    48,     6,   164,   119,    47,
      -1,     6,    -1,     8,    -1,    50,   165,    49,    -1,    50,
     166,    -1,     6,    -1,     8,    -1,    52,   168,    51,    -1,
      52,   169,    -1,    -1,    54,     6,   172,   118,    53,    -1,
       6,   205,   207,   210,    -1,    56,   173,    55,    -1,     6,
     174,   209,   204,    -1,     6,   122,    -1,    58,   176,    57,
      -1,     6,   194,    -1,    60,   178,    59,    -1,     6,   198,
      -1,    62,   180,    61,    -1,     6,   196,    -1,    64,   182,
      63,    -1,     6,   196,    -1,    66,   184,    65,    -1,     6,
     196,    -1,    68,   186,    67,    -1,     6,   200,    -1,    70,
     188,    69,    -1,     6,   171,    -1,    72,   190,    71,    -1,
       6,   171,    -1,    74,   192,    73,    -1,    -1,    76,     6,
     195,   118,    75,    -1,    -1,    78,     6,   197,   118,    77,
      -1,    -1,    80,     6,   199,     4,    79,    -1,    -1,    80,
       6,   201,     4,    79,    -1,     6,   142,   147,   149,    -1,
      82,   175,    81,    -1,    84,   202,    83,    -1,    -1,    86,
       6,   206,   118,    85,    -1,    -1,    88,     6,   208,   118,
      87,    -1,    90,   202,    89,    -1,    -1,    92,     6,   211,
     118,    91,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   281,   286,   292,   300,   308,   316,   321,
     332,   332,   338,   344,   349,   357,   362,   367,   372,   377,
     382,   387,   392,   397,   402,   407,   412,   417,   422,   427,
     432,   437,   442,   450,   455,   460,   462,   467,   472,   477,
     479,   484,   484,   490,   495,   500,   505,   510,   512,   517,
     522,   522,   527,   532,   537,   539,   544,   544,   549,   549,
     554,   558,   566,   569,   575,   580,   585,   585,   590,   595,
     600,   605,   610,   615,   620,   620,   626,   631,   636,   638,
     643,   648,   653,   655,   660,   660,   665,   670,   675,   680,
     685,   691,   696,   701,   706,   711,   716,   722,   727,   733,
     738,   745,   750,   755,   760,   766,   771,   776,   776,   781,
     781,   787,   787,   795,   795,   803,   808,   813,   818,   818,
     823,   823,   828,   833,   833
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
  "MOVETHROUGHTOEND", "MOVETHROUGHTOSTART", "MOVETOEND", "MOVETOSTART",
  "NUMPOSITIONSEND", "NUMPOSITIONSSTART", "OPENGRIPPEREND",
  "OPENGRIPPERSTART", "OPENTOOLCHANGEREND", "OPENTOOLCHANGERSTART",
  "PERCENTEND", "PERCENTSTART", "POINTEND", "POINTSTART",
  "SETABSOLUTEACCELERATIONEND", "SETABSOLUTEACCELERATIONSTART",
  "SETABSOLUTESPEEDEND", "SETABSOLUTESPEEDSTART", "SETANGLEUNITSEND",
  "SETANGLEUNITSSTART", "SETENDANGLETOLERANCEEND",
  "SETENDANGLETOLERANCESTART", "SETENDPOINTTOLERANCEEND",
  "SETENDPOINTTOLERANCESTART", "SETINTERMEDIATEPOINTTOLERANCEEND",
  "SETINTERMEDIATEPOINTTOLERANCESTART", "SETLENGTHUNITSEND",
  "SETLENGTHUNITSSTART", "SETRELATIVEACCELERATIONEND",
  "SETRELATIVEACCELERATIONSTART", "SETRELATIVESPEEDEND",
  "SETRELATIVESPEEDSTART", "SPEEDEND", "SPEEDSTART", "TOLERANCEEND",
  "TOLERANCESTART", "UNITNAMEEND", "UNITNAMESTART", "WAYPOINTEND",
  "WAYPOINTSTART", "XAXISEND", "XAXISSTART", "XEND", "XSTART", "YEND",
  "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND", "ZSTART",
  "CLOSEGRIPPERTYPEDECL", "CLOSETOOLCHANGERTYPEDECL", "DWELLTYPEDECL",
  "ENDCANONTYPEDECL", "INITCANONTYPEDECL", "MESSAGETYPEDECL",
  "MIDDLECOMMANDTYPEDECL", "MOVESTRAIGHTTOTYPEDECL",
  "MOVETHROUGHTOTYPEDECL", "MOVETOTYPEDECL", "OPENGRIPPERTYPEDECL",
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
  "y_MoveThroughTo_MoveThroughToType", "y_MoveToType",
  "y_MoveTo_MoveToType", "y_NumPositions_XmlInteger", "$@7",
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
     365,   366,   367,   368
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   116,   117,   118,   119,   120,   121,   121,
     123,   122,   124,   125,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   129,   130,   130,   131,   132,   133,
     133,   135,   134,   136,   137,   138,   139,   140,   140,   141,
     143,   142,   144,   145,   146,   146,   148,   147,   150,   149,
     151,   151,   152,   152,   153,   154,   156,   155,   157,   158,
     159,   160,   161,   162,   164,   163,   165,   166,   167,   167,
     168,   169,   170,   170,   172,   171,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   195,   194,   197,
     196,   199,   198,   201,   200,   202,   203,   204,   206,   205,
     208,   207,   209,   211,   210
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     1,     1,     4,     6,
       0,     5,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     3,
       2,     0,     5,     2,     3,     1,     1,     3,     2,     3,
       0,     5,     1,     1,     3,     2,     0,     5,     0,     5,
       1,     2,     2,     1,     2,     3,     0,     5,     2,     3,
       3,     3,     2,     3,     0,     5,     1,     1,     3,     2,
       1,     1,     3,     2,     0,     5,     4,     3,     4,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     0,     5,     0,
       5,     0,     5,     0,     5,     4,     3,     3,     0,     5,
       0,     5,     3,     0,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     8,     0,     3,     0,     0,     0,     4,     0,     0,
       2,     9,    52,    53,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    60,    15,    16,    17,
      14,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    54,    33,    34,     0,
      36,    37,    38,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,    79,    80,
      81,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    61,    35,    39,     0,    43,    44,     0,
      64,    65,     0,    68,    69,     0,     0,    63,    71,    72,
      73,    78,    82,     0,    89,    90,     0,    91,    92,     0,
      93,    94,     0,    95,    96,    97,    98,    99,   100,     0,
     101,   102,     0,   103,   104,   105,   106,    45,    46,     0,
      48,    41,    66,     0,     0,     0,     0,    70,    62,    10,
     107,   111,   109,   113,    84,    47,     0,     0,     0,     0,
      49,   116,    74,     0,     0,     0,     0,     0,     0,     5,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    67,     0,     0,    87,     0,
       0,     0,    88,     6,     0,    11,   108,   112,   110,   114,
      85,   118,     0,     0,     0,     0,   122,     0,    75,     0,
     120,     0,    86,    50,     0,     0,   117,     0,     0,   123,
       0,    56,     0,   115,   119,     0,     0,     0,     0,    58,
     121,     0,    51,     0,     0,   124,    57,     0,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,   190,   214,   192,     3,   134,   183,
      15,    44,    45,    46,    69,    70,    47,    73,    74,    48,
     117,   176,    76,    49,   159,   160,   112,   123,   225,   240,
      24,    25,    19,   235,   248,   243,   254,    50,   126,    78,
      51,   120,   177,    80,    52,    82,    53,    84,    54,   167,
     197,    87,    88,    55,    91,    92,    56,   153,   188,   194,
     179,   164,    94,    57,    96,    58,    98,    59,   100,    60,
     102,    61,   104,    62,   106,    63,   108,    64,   110,    65,
     137,   184,   143,   186,   140,   185,   150,   187,   210,   127,
     212,   207,   229,   223,   238,   196,   232,   246
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
      -8,    -7,    14,     8,    17,  -184,    19,     1,    20,    27,
      24,  -184,    26,  -184,     5,    28,    34,  -184,     3,   -10,
    -184,  -184,  -184,  -184,    10,  -184,     7,    11,    38,    41,
      43,    45,    47,    12,    15,    53,    55,    60,    61,    62,
      63,    64,    66,    67,    46,  -184,  -184,  -184,  -184,  -184,
     -10,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,    56,
    -184,  -184,  -184,    57,  -184,    52,    54,    37,    42,    50,
      44,     0,    40,    50,    39,  -184,  -184,    48,  -184,  -184,
    -184,    35,  -184,    71,    31,    13,    32,    18,    29,    21,
      30,    21,    36,    21,    25,    22,    49,    51,    23,    51,
      33,    16,  -184,  -184,  -184,  -184,    89,  -184,  -184,    90,
    -184,  -184,    94,  -184,  -184,    94,   -44,  -184,  -184,  -184,
    -184,  -184,  -184,    97,  -184,  -184,    98,  -184,  -184,   101,
    -184,  -184,   102,  -184,  -184,  -184,  -184,  -184,  -184,   103,
    -184,  -184,   104,  -184,  -184,  -184,  -184,  -184,  -184,    84,
    -184,  -184,  -184,    58,    83,    59,   107,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,   111,   112,   113,    65,
    -184,  -184,  -184,   111,   111,   116,   111,   117,   111,  -184,
      99,  -184,    78,    68,    69,   119,    72,   122,   108,    70,
      73,    74,    79,    75,  -184,  -184,   121,    76,  -184,   100,
      77,   119,  -184,  -184,    82,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,   124,    80,   125,   105,  -184,    85,  -184,   111,
    -184,   127,  -184,  -184,   128,   106,  -184,    86,   111,  -184,
     111,  -184,   129,  -184,  -184,    87,   111,   115,   111,  -184,
    -184,    88,  -184,   114,   111,  -184,  -184,   110,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -183,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,    92,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,    93,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,    81,  -184,  -184,
    -184,    91,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,   -76,  -184,  -184,  -184,  -184,  -184,   -75,    95,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     198,   199,     1,   201,   166,   203,    10,     4,    11,    22,
      26,    23,    27,    67,     5,    68,    28,    71,    85,    72,
      86,    89,   157,    90,   158,   145,     6,   147,     7,    12,
      29,     8,    30,    14,    31,    16,    32,    17,   125,    18,
      33,    21,    34,    66,    75,    20,   237,    77,    35,    79,
      36,    81,    37,    83,    38,   245,    39,   247,    40,    93,
      41,    95,    42,   251,    43,   253,    97,    99,   101,   103,
     105,   257,   107,   109,   111,   114,   116,   119,   115,   118,
     122,   121,   125,   128,   130,   124,   132,   133,   135,   136,
     141,   138,   148,   144,   154,   161,   162,   131,   139,   142,
     163,   146,   149,   169,   170,   152,   156,   171,   172,   173,
     174,   175,   180,   182,   178,   189,   191,   205,   151,   193,
     200,   202,   204,   215,   208,   209,   213,   221,   220,   228,
     230,   233,   224,   239,   241,   249,   227,     0,     0,     0,
     181,   234,   113,     0,   242,   216,   252,   258,     0,   256,
       0,   218,   217,     0,   206,   195,   211,     0,   219,     0,
       0,     0,     0,     0,   222,     0,   226,     0,   236,     0,
       0,   244,   231,     0,   250,     0,   129,     0,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   168
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-184))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     183,   184,    10,   186,    48,   188,     5,    14,     7,     6,
      20,     8,    22,     6,     0,     8,    26,     6,     6,     8,
       8,     6,     6,     8,     8,   101,    18,   103,    11,     9,
      40,    12,    42,     6,    44,    11,    46,    11,    82,    34,
      50,     7,    52,    33,     6,    17,   229,     6,    58,     6,
      60,     6,    62,     6,    64,   238,    66,   240,    68,     6,
      70,     6,    72,   246,    74,   248,     6,     6,     6,     6,
       6,   254,     6,     6,    28,    19,    24,    40,    21,    25,
      30,    39,    82,    43,    45,    41,    51,    16,    57,    76,
      61,    59,    67,    63,    71,     6,     6,    49,    80,    78,
       6,    65,    80,     6,     6,    54,    73,     6,     6,     6,
       6,    27,    29,     6,    56,     4,     4,    39,    69,     6,
       4,     4,    23,    15,    55,     6,     4,     6,    53,    47,
       6,     6,    32,     6,     6,     6,   211,    -1,    -1,    -1,
      81,    36,    50,    -1,    38,    75,    31,    37,    -1,    35,
      -1,    77,    79,    -1,    86,    90,    84,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    89,    -1,    83,    -1,
      -1,    85,    92,    -1,    87,    -1,    83,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,   126
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,   115,   121,    14,     0,    18,    11,    12,   116,
       5,     7,     9,   117,     6,   124,    11,    11,    34,   146,
      17,     7,     6,     8,   144,   145,    20,    22,    26,    40,
      42,    44,    46,    50,    52,    58,    60,    62,    64,    66,
      68,    70,    72,    74,   125,   126,   127,   130,   133,   137,
     151,   154,   158,   160,   162,   167,   170,   177,   179,   181,
     183,   185,   187,   189,   191,   193,    33,     6,     8,   128,
     129,     6,     8,   131,   132,     6,   136,     6,   153,     6,
     157,     6,   159,     6,   161,     6,     8,   165,   166,     6,
       8,   168,   169,     6,   176,     6,   178,     6,   180,     6,
     182,     6,   184,     6,   186,     6,   188,     6,   190,     6,
     192,    28,   140,   127,    19,    21,    24,   134,    25,    40,
     155,    39,    30,   141,    41,    82,   152,   203,    43,   141,
      45,    49,    51,    16,   122,    57,    76,   194,    59,    80,
     198,    61,    78,   196,    63,   196,    65,   196,    67,    80,
     200,    69,    54,   171,    71,   171,    73,     6,     8,   138,
     139,     6,     6,     6,   175,   175,    48,   163,   203,     6,
       6,     6,     6,     6,     6,    27,   135,   156,    56,   174,
      29,    81,     6,   123,   195,   199,   197,   201,   172,     4,
     118,     4,   120,     6,   173,    90,   209,   164,   118,   118,
       4,   118,     4,   118,    23,    39,    86,   205,    55,     6,
     202,    84,   204,     4,   119,    15,    75,    79,    77,    79,
      53,     6,    88,   207,    32,   142,    89,   202,    47,   206,
       6,    92,   210,     6,    36,   147,    83,   118,   208,     6,
     143,     6,    38,   149,    85,   118,   211,   118,   148,     6,
      87,   118,    31,   118,   150,    91,    35,   118,    37
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
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::MoveToE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.MoveTo = (yyvsp[(1) - (1)].MoveToTypeVal);
	  }
    break;

  case 22:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenGripperE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.OpenGripper = (yyvsp[(1) - (1)].OpenGripperTypeVal);
	  }
    break;

  case 23:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::OpenToolChangerE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.OpenToolChanger = (yyvsp[(1) - (1)].OpenToolChangerTypeVal);
	  }
    break;

  case 24:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteAccelerationE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAbsoluteAcceleration = (yyvsp[(1) - (1)].SetAbsoluteAccelerationTypeVal);
	  }
    break;

  case 25:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAbsoluteSpeedE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAbsoluteSpeed = (yyvsp[(1) - (1)].SetAbsoluteSpeedTypeVal);
	  }
    break;

  case 26:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetAngleUnitsE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetAngleUnits = (yyvsp[(1) - (1)].SetAngleUnitsTypeVal);
	  }
    break;

  case 27:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndAngleToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetEndAngleTolerance = (yyvsp[(1) - (1)].SetEndAngleToleranceTypeVal);
	  }
    break;

  case 28:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetEndPointToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetEndPointTolerance = (yyvsp[(1) - (1)].SetEndPointToleranceTypeVal);
	  }
    break;

  case 29:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetIntermediatePointToleranceE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetIntermediatePointTolerance = (yyvsp[(1) - (1)].SetIntermediatePointToleranceTypeVal);
	  }
    break;

  case 30:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetLengthUnitsE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetLengthUnits = (yyvsp[(1) - (1)].SetLengthUnitsTypeVal);
	  }
    break;

  case 31:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeAccelerationE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetRelativeAcceleration = (yyvsp[(1) - (1)].SetRelativeAccelerationTypeVal);
	  }
    break;

  case 32:

    {(yyval.CRCLProgramType_1001_TypeChoicePairVal) = new CRCLProgramType_1001_TypeChoicePair();
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeType = CRCLProgramType_1001_TypeChoicePair::SetRelativeSpeedE;
	   (yyval.CRCLProgramType_1001_TypeChoicePairVal)->CRCLProgramType_1001_TypeValue.SetRelativeSpeed = (yyvsp[(1) - (1)].SetRelativeSpeedTypeVal);
	  }
    break;

  case 33:

    {(yyval.CloseGripperTypeVal) = new CloseGripperType();}
    break;

  case 34:

    {(yyval.CloseGripperTypeVal) = new CloseGripperType();}
    break;

  case 35:

    {(yyval.CloseGripperTypeVal) = (yyvsp[(2) - (3)].CloseGripperTypeVal);}
    break;

  case 36:

    {(yyval.CloseGripperTypeVal) = (yyvsp[(2) - (2)].CloseGripperTypeVal);}
    break;

  case 37:

    {(yyval.CloseToolChangerTypeVal) = new CloseToolChangerType();}
    break;

  case 38:

    {(yyval.CloseToolChangerTypeVal) = new CloseToolChangerType();}
    break;

  case 39:

    {(yyval.CloseToolChangerTypeVal) = (yyvsp[(2) - (3)].CloseToolChangerTypeVal);}
    break;

  case 40:

    {(yyval.CloseToolChangerTypeVal) = (yyvsp[(2) - (2)].CloseToolChangerTypeVal);}
    break;

  case 41:

    {yyReadData = 1;}
    break;

  case 42:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 43:

    {(yyval.DwellTypeVal) = new DwellType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 44:

    {(yyval.DwellTypeVal) = (yyvsp[(2) - (3)].DwellTypeVal);}
    break;

  case 45:

    {(yyval.EndCanonTypeVal) = new EndCanonType();}
    break;

  case 46:

    {(yyval.EndCanonTypeVal) = new EndCanonType();}
    break;

  case 47:

    {(yyval.EndCanonTypeVal) = (yyvsp[(2) - (3)].EndCanonTypeVal);}
    break;

  case 48:

    {(yyval.EndCanonTypeVal) = (yyvsp[(2) - (2)].EndCanonTypeVal);}
    break;

  case 49:

    {(yyval.PoseTypeVal) = (yyvsp[(2) - (3)].PoseTypeVal);}
    break;

  case 50:

    {yyReadData = 1;}
    break;

  case 51:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 52:

    {(yyval.InitCanonTypeVal) = new InitCanonType();}
    break;

  case 53:

    {(yyval.InitCanonTypeVal) = new InitCanonType();}
    break;

  case 54:

    {(yyval.InitCanonTypeVal) = (yyvsp[(2) - (3)].InitCanonTypeVal);}
    break;

  case 55:

    {(yyval.InitCanonTypeVal) = (yyvsp[(2) - (2)].InitCanonTypeVal);}
    break;

  case 56:

    {yyReadData = 1;}
    break;

  case 57:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 58:

    {yyReadData = 1;}
    break;

  case 59:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 60:

    {(yyval.ListCRCLProgramType_1001_TypeChoicePairVal) = new std::list<CRCLProgramType_1001_TypeChoicePair *>;
	   (yyval.ListCRCLProgramType_1001_TypeChoicePairVal)->push_back((yyvsp[(1) - (1)].CRCLProgramType_1001_TypeChoicePairVal));
	  }
    break;

  case 61:

    {(yyval.ListCRCLProgramType_1001_TypeChoicePairVal) = (yyvsp[(1) - (2)].ListCRCLProgramType_1001_TypeChoicePairVal);
	   (yyval.ListCRCLProgramType_1001_TypeChoicePairVal)->push_back((yyvsp[(2) - (2)].CRCLProgramType_1001_TypeChoicePairVal));
	  }
    break;

  case 62:

    {(yyval.ListPoseTypeVal) = (yyvsp[(1) - (2)].ListPoseTypeVal);
	   (yyval.ListPoseTypeVal)->push_back((yyvsp[(2) - (2)].PoseTypeVal));}
    break;

  case 63:

    {(yyval.ListPoseTypeVal) = new std::list<PoseType *>;
	   (yyval.ListPoseTypeVal)->push_back((yyvsp[(1) - (1)].PoseTypeVal));}
    break;

  case 64:

    {(yyval.MessageTypeVal) = new MessageType((yyvsp[(2) - (2)].XmlStringVal));}
    break;

  case 65:

    {(yyval.MessageTypeVal) = (yyvsp[(2) - (3)].MessageTypeVal);}
    break;

  case 66:

    {yyReadData = 1;}
    break;

  case 67:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);}
    break;

  case 68:

    {(yyval.MoveStraightToTypeVal) = new MoveStraightToType((yyvsp[(2) - (2)].PoseTypeVal));}
    break;

  case 69:

    {(yyval.MoveStraightToTypeVal) = (yyvsp[(2) - (3)].MoveStraightToTypeVal);}
    break;

  case 70:

    {(yyval.MoveThroughToTypeVal) = new MoveThroughToType((yyvsp[(2) - (3)].ListPoseTypeVal), (yyvsp[(3) - (3)].XmlIntegerVal));}
    break;

  case 71:

    {(yyval.MoveThroughToTypeVal) = (yyvsp[(2) - (3)].MoveThroughToTypeVal);}
    break;

  case 72:

    {(yyval.MoveToTypeVal) = new MoveToType((yyvsp[(2) - (2)].PoseTypeVal));}
    break;

  case 73:

    {(yyval.MoveToTypeVal) = (yyvsp[(2) - (3)].MoveToTypeVal);}
    break;

  case 74:

    {yyReadData = 1;}
    break;

  case 75:

    {(yyval.XmlIntegerVal) = (yyvsp[(4) - (5)].XmlIntegerVal);}
    break;

  case 76:

    {(yyval.OpenGripperTypeVal) = new OpenGripperType();}
    break;

  case 77:

    {(yyval.OpenGripperTypeVal) = new OpenGripperType();}
    break;

  case 78:

    {(yyval.OpenGripperTypeVal) = (yyvsp[(2) - (3)].OpenGripperTypeVal);}
    break;

  case 79:

    {(yyval.OpenGripperTypeVal) = (yyvsp[(2) - (2)].OpenGripperTypeVal);}
    break;

  case 80:

    {(yyval.OpenToolChangerTypeVal) = new OpenToolChangerType();}
    break;

  case 81:

    {(yyval.OpenToolChangerTypeVal) = new OpenToolChangerType();}
    break;

  case 82:

    {(yyval.OpenToolChangerTypeVal) = (yyvsp[(2) - (3)].OpenToolChangerTypeVal);}
    break;

  case 83:

    {(yyval.OpenToolChangerTypeVal) = (yyvsp[(2) - (2)].OpenToolChangerTypeVal);}
    break;

  case 84:

    {yyReadData = 1;}
    break;

  case 85:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 86:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (4)].XmlDecimalVal), (yyvsp[(3) - (4)].XmlDecimalVal), (yyvsp[(4) - (4)].XmlDecimalVal));}
    break;

  case 87:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);}
    break;

  case 88:

    {(yyval.PoseTypeVal) = new PoseType((yyvsp[(2) - (4)].PointTypeVal), (yyvsp[(3) - (4)].VectorTypeVal), (yyvsp[(4) - (4)].VectorTypeVal));}
    break;

  case 89:

    {(yyval.SetAbsoluteAccelerationTypeVal) = new SetAbsoluteAccelerationType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 90:

    {(yyval.SetAbsoluteAccelerationTypeVal) = (yyvsp[(2) - (3)].SetAbsoluteAccelerationTypeVal);}
    break;

  case 91:

    {(yyval.SetAbsoluteSpeedTypeVal) = new SetAbsoluteSpeedType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 92:

    {(yyval.SetAbsoluteSpeedTypeVal) = (yyvsp[(2) - (3)].SetAbsoluteSpeedTypeVal);}
    break;

  case 93:

    {(yyval.SetAngleUnitsTypeVal) = new SetAngleUnitsType((yyvsp[(2) - (2)].AngleUnitTypeVal));}
    break;

  case 94:

    {(yyval.SetAngleUnitsTypeVal) = (yyvsp[(2) - (3)].SetAngleUnitsTypeVal);}
    break;

  case 95:

    {(yyval.SetEndAngleToleranceTypeVal) = new SetEndAngleToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 96:

    {(yyval.SetEndAngleToleranceTypeVal) = (yyvsp[(2) - (3)].SetEndAngleToleranceTypeVal);}
    break;

  case 97:

    {(yyval.SetEndPointToleranceTypeVal) = new SetEndPointToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 98:

    {(yyval.SetEndPointToleranceTypeVal) = (yyvsp[(2) - (3)].SetEndPointToleranceTypeVal);}
    break;

  case 99:

    {(yyval.SetIntermediatePointToleranceTypeVal) = new SetIntermediatePointToleranceType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 100:

    {(yyval.SetIntermediatePointToleranceTypeVal) = (yyvsp[(2) - (3)].SetIntermediatePointToleranceTypeVal);}
    break;

  case 101:

    {(yyval.SetLengthUnitsTypeVal) = new SetLengthUnitsType((yyvsp[(2) - (2)].LengthUnitTypeVal));}
    break;

  case 102:

    {(yyval.SetLengthUnitsTypeVal) = (yyvsp[(2) - (3)].SetLengthUnitsTypeVal);}
    break;

  case 103:

    {(yyval.SetRelativeAccelerationTypeVal) = new SetRelativeAccelerationType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 104:

    {(yyval.SetRelativeAccelerationTypeVal) = (yyvsp[(2) - (3)].SetRelativeAccelerationTypeVal);}
    break;

  case 105:

    {(yyval.SetRelativeSpeedTypeVal) = new SetRelativeSpeedType((yyvsp[(2) - (2)].XmlDecimalVal));}
    break;

  case 106:

    {(yyval.SetRelativeSpeedTypeVal) = (yyvsp[(2) - (3)].SetRelativeSpeedTypeVal);}
    break;

  case 107:

    {yyReadData = 1;}
    break;

  case 108:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 109:

    {yyReadData = 1;}
    break;

  case 110:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 111:

    {yyReadData = 1;}
    break;

  case 112:

    {(yyval.AngleUnitTypeVal) = new AngleUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.AngleUnitTypeVal)->bad)
	     yyerror("bad UnitName value");
	  }
    break;

  case 113:

    {yyReadData = 1;}
    break;

  case 114:

    {(yyval.LengthUnitTypeVal) = new LengthUnitType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.LengthUnitTypeVal)->bad)
	     yyerror("bad UnitName value");
	  }
    break;

  case 115:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (4)].XmlDecimalVal), (yyvsp[(3) - (4)].XmlDecimalVal), (yyvsp[(4) - (4)].XmlDecimalVal));}
    break;

  case 116:

    {(yyval.PoseTypeVal) = (yyvsp[(2) - (3)].PoseTypeVal);}
    break;

  case 117:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 118:

    {yyReadData = 1;}
    break;

  case 119:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 120:

    {yyReadData = 1;}
    break;

  case 121:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);}
    break;

  case 122:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);}
    break;

  case 123:

    {yyReadData = 1;}
    break;

  case 124:

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

