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
#include "kittingPlanClasses.hh"   // for kittingPlan classes

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingPlanFile * KittingPlanTree; // the parse tree

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
     A1END = 269,
     A1START = 270,
     A2END = 271,
     A2START = 272,
     AEND = 273,
     ASTART = 274,
     B1END = 275,
     B1START = 276,
     B2END = 277,
     B2START = 278,
     BEND = 279,
     BSTART = 280,
     DESCRIPTIONEND = 281,
     DESCRIPTIONSTART = 282,
     ELSEIFEND = 283,
     ELSEIFSTART = 284,
     ELSEEND = 285,
     ELSESTART = 286,
     ENDEFFECTORHOLDERNAMEEND = 287,
     ENDEFFECTORHOLDERNAMESTART = 288,
     ENDEFFECTORNAMEEND = 289,
     ENDEFFECTORNAMESTART = 290,
     IEND = 291,
     ISTART = 292,
     IFEND = 293,
     IFSTART = 294,
     JEND = 295,
     JSTART = 296,
     KEND = 297,
     KSTART = 298,
     KITNAMEEND = 299,
     KITNAMESTART = 300,
     KITTRAYNAMEEND = 301,
     KITTRAYNAMESTART = 302,
     KITTINGPLANEND = 303,
     KITTINGPLANSTART = 304,
     LOCATIONEND = 305,
     LOCATIONSTART = 306,
     NAMEEND = 307,
     NAMESTART = 308,
     NUMBEROFSTEPSEND = 309,
     NUMBEROFSTEPSSTART = 310,
     OBJECTEND = 311,
     OBJECTSTART = 312,
     ORIENTATIONSTANDARDDEVIATIONEND = 313,
     ORIENTATIONSTANDARDDEVIATIONSTART = 314,
     PARTNAMEEND = 315,
     PARTNAMESTART = 316,
     PLANAUTHOREND = 317,
     PLANAUTHORSTART = 318,
     PLANDATEANDTIMEEND = 319,
     PLANDATEANDTIMESTART = 320,
     PLANDESCRIPTIONEND = 321,
     PLANDESCRIPTIONSTART = 322,
     PLANELEMENTEND = 323,
     PLANELEMENTSTART = 324,
     PLANIDEND = 325,
     PLANIDSTART = 326,
     PLANROOTEND = 327,
     PLANROOTSTART = 328,
     PLANVERSIONEND = 329,
     PLANVERSIONSTART = 330,
     POINTEND = 331,
     POINTSTART = 332,
     POSITIONSTANDARDDEVIATIONEND = 333,
     POSITIONSTANDARDDEVIATIONSTART = 334,
     PREDECESSOREND = 335,
     PREDECESSORSTART = 336,
     PROPERTYEND = 337,
     PROPERTYSTART = 338,
     REFOBJECTNAMEEND = 339,
     REFOBJECTNAMESTART = 340,
     ROBOTNAMEEND = 341,
     ROBOTNAMESTART = 342,
     SEQUENCENUMBEREND = 343,
     SEQUENCENUMBERSTART = 344,
     STEPEND = 345,
     STEPSTART = 346,
     TESTEND = 347,
     TESTSTART = 348,
     THINGNAMEEND = 349,
     THINGNAMESTART = 350,
     VALEND = 351,
     VALSTART = 352,
     VARNAMEEND = 353,
     VARNAMESTART = 354,
     VARIABLEEND = 355,
     VARIABLESTART = 356,
     XAXISEND = 357,
     XAXISSTART = 358,
     XEND = 359,
     XSTART = 360,
     YEND = 361,
     YSTART = 362,
     ZAXISEND = 363,
     ZAXISSTART = 364,
     ZEND = 365,
     ZSTART = 366,
     ACTIONBASETYPEDECL = 367,
     ACTIONGROUPBASETYPEDECL = 368,
     ANDTYPEDECL = 369,
     ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL = 370,
     ARITHMETICEXPRESSIONTYPEDECL = 371,
     ATTACHENDEFFECTORTYPEDECL = 372,
     BINARYARITHMETICEXPRESSIONTYPEDECL = 373,
     BINARYBOOLEANEXPRESSIONTYPEDECL = 374,
     BOOLEANCONSTANTTYPEDECL = 375,
     BOOLEANEXPRESSIONTYPEDECL = 376,
     CREATEKITTYPEDECL = 377,
     DECIMALTYPEDECL = 378,
     DETACHENDEFFECTORTYPEDECL = 379,
     DIVTYPEDECL = 380,
     ELSETYPEDECL = 381,
     EQUALTYPEDECL = 382,
     FALSETYPEDECL = 383,
     GREATEROREQUALTYPEDECL = 384,
     GREATERTYPEDECL = 385,
     IFACTIONGROUPTYPEDECL = 386,
     KITTINGPLANTYPEDECL = 387,
     LESSOREQUALTYPEDECL = 388,
     LESSTYPEDECL = 389,
     LOCATEPARTTYPEDECL = 390,
     MINUSTYPEDECL = 391,
     MODTYPEDECL = 392,
     NEGATETYPEDECL = 393,
     NOTEQUALTYPEDECL = 394,
     NOTTYPEDECL = 395,
     NUMBEREDPLANELEMENTTYPEDECL = 396,
     ONEOFACTIONGROUPTYPEDECL = 397,
     ORTYPEDECL = 398,
     ORDEREDACTIONGROUPTYPEDECL = 399,
     PARTIALLYORDEREDACTIONGROUPTYPEDECL = 400,
     PHYSICALLOCATIONTYPEDECL = 401,
     PLANELEMENTBASETYPEDECL = 402,
     PLUSTYPEDECL = 403,
     POINTTYPEDECL = 404,
     POSELOCATIONINTYPEDECL = 405,
     POSELOCATIONONTYPEDECL = 406,
     POSELOCATIONTYPEDECL = 407,
     POSEONLYLOCATIONTYPEDECL = 408,
     PROPVALTYPEDECL = 409,
     PUTKITTRAYTYPEDECL = 410,
     PUTKITTYPEDECL = 411,
     PUTPARTTYPEDECL = 412,
     RELATIVELOCATIONINTYPEDECL = 413,
     RELATIVELOCATIONONTYPEDECL = 414,
     RELATIVELOCATIONTYPEDECL = 415,
     ROBOTACTIONBASETYPEDECL = 416,
     SENSORACTIONBASETYPEDECL = 417,
     SOMEOFACTIONGROUPTYPEDECL = 418,
     STEPWITHPREDECESSORSTYPEDECL = 419,
     TAKEKITTRAYTYPEDECL = 420,
     TAKEKITTYPEDECL = 421,
     TAKEPARTTYPEDECL = 422,
     TESTANDSTEPTYPEDECL = 423,
     TIMESTYPEDECL = 424,
     TRUETYPEDECL = 425,
     UNORDEREDACTIONGROUPTYPEDECL = 426,
     VARSETTYPEDECL = 427,
     VARVALTYPEDECL = 428,
     VARIABLEDECLARATIONTYPEDECL = 429,
     VECTORTYPEDECL = 430,
     WHILEACTIONGROUPTYPEDECL = 431
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingPlan *           XmlHeaderForKittingPlanVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDateTime *                       XmlDateTimeVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlID *                             XmlIDVal;
  XmlIDREF *                          XmlIDREFVal;
  XmlNMTOKEN *                        XmlNMTOKENVal;
  XmlPositiveInteger *                XmlPositiveIntegerVal;
  XmlString *                         XmlStringVal;
  XmlToken *                          XmlTokenVal;

  KittingPlanFile *                   KittingPlanFileVal;

  ActionBaseType *                    ActionBaseTypeVal;
  ActionGroupBaseType *               ActionGroupBaseTypeVal;
  AndType *                           AndTypeVal;
  ArithmeticComparisonBooleanExpressionType * ArithmeticComparisonBooleanExpressionTypeVal;
  ArithmeticExpressionType *          ArithmeticExpressionTypeVal;
  AttachEndEffectorType *             AttachEndEffectorTypeVal;
  BinaryArithmeticExpressionType *    BinaryArithmeticExpressionTypeVal;
  BinaryBooleanExpressionType *       BinaryBooleanExpressionTypeVal;
  BooleanConstantType *               BooleanConstantTypeVal;
  BooleanExpressionType *             BooleanExpressionTypeVal;
  CreateKitType *                     CreateKitTypeVal;
  DecimalType *                       DecimalTypeVal;
  DetachEndEffectorType *             DetachEndEffectorTypeVal;
  DivType *                           DivTypeVal;
  ElseType *                          ElseTypeVal;
  EqualType *                         EqualTypeVal;
  FalseType *                         FalseTypeVal;
  GreaterOrEqualType *                GreaterOrEqualTypeVal;
  GreaterType *                       GreaterTypeVal;
  IfActionGroupType *                 IfActionGroupTypeVal;
  KittingPlanType *                   KittingPlanTypeVal;
  LessOrEqualType *                   LessOrEqualTypeVal;
  LessType *                          LessTypeVal;
  LocatePartType *                    LocatePartTypeVal;
  MinusType *                         MinusTypeVal;
  ModType *                           ModTypeVal;
  std::list<XmlNMTOKEN *> *           NMTOKENListVal;
  NegateType *                        NegateTypeVal;
  NotEqualType *                      NotEqualTypeVal;
  NotType *                           NotTypeVal;
  std::list<NumberedPlanElementType *> * NumberedPlanElementTypeListVal;
  NumberedPlanElementType *           NumberedPlanElementTypeVal;
  OneOfActionGroupType *              OneOfActionGroupTypeVal;
  OrType *                            OrTypeVal;
  OrderedActionGroupType *            OrderedActionGroupTypeVal;
  PartiallyOrderedActionGroupType *   PartiallyOrderedActionGroupTypeVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  std::list<PlanElementBaseType *> *  PlanElementBaseTypeListVal;
  PlanElementBaseType *               PlanElementBaseTypeVal;
  PlusType *                          PlusTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  PropValType *                       PropValTypeVal;
  PutKitTrayType *                    PutKitTrayTypeVal;
  PutKitType *                        PutKitTypeVal;
  PutPartType *                       PutPartTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotActionBaseType *               RobotActionBaseTypeVal;
  SensorActionBaseType *              SensorActionBaseTypeVal;
  SomeOfActionGroupType *             SomeOfActionGroupTypeVal;
  std::list<StepWithPredecessorsType *> * StepWithPredecessorsTypeListVal;
  StepWithPredecessorsType *          StepWithPredecessorsTypeVal;
  TakeKitTrayType *                   TakeKitTrayTypeVal;
  TakeKitType *                       TakeKitTypeVal;
  TakePartType *                      TakePartTypeVal;
  std::list<TestAndStepType *> *      TestAndStepTypeListVal;
  TestAndStepType *                   TestAndStepTypeVal;
  TimesType *                         TimesTypeVal;
  TrueType *                          TrueTypeVal;
  UnorderedActionGroupType *          UnorderedActionGroupTypeVal;
  VarSetType *                        VarSetTypeVal;
  VarValType *                        VarValTypeVal;
  std::list<VariableDeclarationType *> * VariableDeclarationTypeListVal;
  VariableDeclarationType *           VariableDeclarationTypeVal;
  VectorType *                        VectorTypeVal;
  WhileActionGroupType *              WhileActionGroupTypeVal;
  std::list<XmlPositiveInteger *> *   positiveIntegerListVal;



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
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNRULES -- Number of states.  */
#define YYNSTATES  561

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

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
     175,   176
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    17,    19,    21,    23,
      25,    27,    29,    31,    36,    43,    47,    51,    55,    56,
      62,    64,    66,    68,    70,    72,    74,    76,    78,    80,
      84,    88,    92,    94,    96,    98,   100,   102,   104,   106,
     108,   110,   112,   114,   115,   121,   125,   126,   129,   133,
     134,   138,   139,   145,   146,   152,   153,   159,   163,   164,
     170,   171,   177,   178,   184,   185,   191,   202,   206,   207,
     213,   214,   220,   225,   226,   232,   234,   237,   238,   239,
     245,   246,   252,   254,   256,   258,   260,   262,   263,   269,
     270,   276,   277,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307,   309,   311,   313,   315,
     317,   319,   323,   324,   330,   334,   335,   341,   347,   351,
     352,   353,   359,   360,   366,   367,   370,   371,   377,   378,
     384,   385,   391,   392,   398,   404,   408,   410,   413,   417,
     421,   423,   426,   430,   432,   435,   440,   444,   445,   451,
     455,   456,   462,   463,   469,   473,   477,   478,   481,   487,
     491,   492,   498,   499,   505,   509,   510,   516,   522,   529,
     535,   540,   547,   553,   559,   563,   569,   575,   582,   588,
     594,   599,   605,   611,   616,   622,   627,   632,   638,   643,
     648,   654,   664,   674,   684,   690,   697,   704,   711,   717,
     723,   729,   735,   741,   747,   753,   757,   762,   768,   773
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     178,     0,    -1,   189,    49,   179,   221,    48,    -1,    11,
     180,    -1,     8,    10,    -1,     4,    -1,     4,    -1,     4,
      -1,     4,    -1,     4,    -1,     4,    -1,     4,    -1,     4,
      -1,     9,    13,    10,     7,    -1,     9,    13,    10,     5,
      10,     7,    -1,    15,   195,    14,    -1,    17,   195,    16,
      -1,    19,   195,    18,    -1,    -1,    19,     6,   194,   182,
      18,    -1,   296,    -1,   298,    -1,   307,    -1,   308,    -1,
     309,    -1,   316,    -1,   320,    -1,   330,    -1,   334,    -1,
      21,   199,    20,    -1,    23,   199,    22,    -1,    25,   199,
      24,    -1,   293,    -1,   299,    -1,   300,    -1,   301,    -1,
     302,    -1,   304,    -1,   305,    -1,   310,    -1,   311,    -1,
     313,    -1,   331,    -1,    -1,    27,     6,   201,   187,    26,
      -1,    29,   272,    28,    -1,    -1,   203,   202,    -1,     6,
     223,   267,    -1,    -1,    31,   204,    30,    -1,    -1,    33,
       6,   207,   185,    32,    -1,    -1,    35,     6,   209,   185,
      34,    -1,    -1,    37,     6,   211,   182,    36,    -1,    39,
     272,    38,    -1,    -1,    41,     6,   214,   182,    40,    -1,
      -1,    43,     6,   216,   182,    42,    -1,    -1,    45,     6,
     218,   185,    44,    -1,    -1,    47,     6,   220,   185,    46,
      -1,     6,   223,   244,   247,   238,   236,   240,   230,   283,
     246,    -1,    51,   235,    50,    -1,    -1,    53,     6,   224,
     183,    52,    -1,    -1,    55,     6,   226,   186,    54,    -1,
       6,   223,   262,   243,    -1,    -1,    57,     6,   229,   185,
      56,    -1,   228,    -1,   230,   228,    -1,    -1,    -1,    59,
       6,   232,     4,    58,    -1,    -1,    61,     6,   234,   185,
      60,    -1,   317,    -1,   318,    -1,   319,    -1,   324,    -1,
     325,    -1,    -1,    63,     6,   237,   188,    62,    -1,    -1,
      65,     6,   239,   181,    64,    -1,    -1,    67,     6,   241,
     187,    66,    -1,   294,    -1,   295,    -1,   297,    -1,   303,
      -1,   306,    -1,   312,    -1,   314,    -1,   315,    -1,   321,
      -1,   322,    -1,   323,    -1,   326,    -1,   327,    -1,   328,
      -1,   329,    -1,   332,    -1,   333,    -1,   335,    -1,    69,
     242,    68,    -1,    -1,    71,     6,   245,   185,    70,    -1,
      73,   242,    72,    -1,    -1,    75,     6,   248,   188,    74,
      -1,     6,   223,   286,   288,   291,    -1,    77,   249,    76,
      -1,    -1,    -1,    79,     6,   252,     4,    78,    -1,    -1,
      81,     6,   254,   186,    80,    -1,    -1,   255,   253,    -1,
      -1,    83,     6,   257,   185,    82,    -1,    -1,    85,     6,
     259,   185,    84,    -1,    -1,    87,     6,   261,   185,    86,
      -1,    -1,    89,     6,   263,   186,    88,    -1,     6,   223,
     262,   255,   243,    -1,    91,   227,    90,    -1,   265,    -1,
     266,   265,    -1,    91,   242,    90,    -1,    91,   242,    90,
      -1,   268,    -1,   269,   268,    -1,    91,   264,    90,    -1,
     270,    -1,   271,   270,    -1,     6,   223,   273,   267,    -1,
      93,   199,    92,    -1,    -1,    95,     6,   275,   185,    94,
      -1,    97,   195,    96,    -1,    -1,    97,     6,   278,   182,
      96,    -1,    -1,    99,     6,   280,   184,    98,    -1,     6,
     223,   277,    -1,   101,   281,   100,    -1,    -1,   283,   282,
      -1,     6,   223,   210,   213,   215,    -1,   103,   284,   102,
      -1,    -1,   105,     6,   287,   182,   104,    -1,    -1,   107,
       6,   289,   182,   106,    -1,   109,   284,   108,    -1,    -1,
     111,     6,   292,   182,   110,    -1,   114,     6,   223,   196,
     197,    -1,   117,     6,   223,   260,   208,   206,    -1,   122,
       6,   223,   219,   217,    -1,   123,     6,   223,   193,    -1,
     124,     6,   223,   260,   208,   206,    -1,   125,     6,   223,
     190,   191,    -1,   127,     6,   223,   190,   191,    -1,   128,
       6,   223,    -1,   129,     6,   223,   190,   191,    -1,   130,
       6,   223,   190,   191,    -1,   131,     6,   223,   212,   203,
     205,    -1,   133,     6,   223,   190,   191,    -1,   134,     6,
     223,   190,   191,    -1,   135,     6,   223,   233,    -1,   136,
       6,   223,   190,   191,    -1,   137,     6,   223,   190,   191,
      -1,   138,     6,   223,   192,    -1,   139,     6,   223,   190,
     191,    -1,   140,     6,   223,   198,    -1,   142,     6,   223,
     266,    -1,   143,     6,   223,   196,   197,    -1,   144,     6,
     223,   266,    -1,   145,     6,   223,   271,    -1,   148,     6,
     223,   190,   191,    -1,   150,     6,   223,   258,   250,   285,
     290,   251,   231,    -1,   151,     6,   223,   258,   250,   285,
     290,   251,   231,    -1,   153,     6,   223,   258,   250,   285,
     290,   251,   231,    -1,   154,     6,   223,   274,   256,    -1,
     155,     6,   223,   260,   219,   222,    -1,   156,     6,   223,
     260,   217,   222,    -1,   157,     6,   223,   260,   233,   222,
      -1,   158,     6,   223,   258,   200,    -1,   159,     6,   223,
     258,   200,    -1,   163,     6,   223,   269,   225,    -1,   165,
       6,   223,   260,   219,    -1,   166,     6,   223,   260,   217,
      -1,   167,     6,   223,   260,   233,    -1,   169,     6,   223,
     190,   191,    -1,   170,     6,   223,    -1,   171,     6,   223,
     269,    -1,   172,     6,   223,   279,   276,    -1,   173,     6,
     223,   279,    -1,   176,     6,   223,   273,   267,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   423,   423,   433,   438,   444,   452,   460,   468,   476,
     484,   492,   500,   508,   513,   524,   529,   534,   539,   539,
     544,   546,   548,   550,   552,   554,   556,   558,   560,   565,
     570,   575,   580,   582,   584,   586,   588,   590,   592,   594,
     596,   598,   600,   605,   605,   611,   617,   618,   624,   630,
     631,   636,   636,   642,   642,   648,   648,   653,   658,   658,
     663,   663,   668,   668,   673,   673,   679,   688,   693,   693,
     698,   698,   704,   710,   710,   715,   718,   725,   726,   726,
     735,   735,   740,   742,   744,   746,   748,   753,   753,   759,
     759,   765,   765,   771,   773,   775,   777,   779,   781,   783,
     785,   787,   789,   791,   793,   795,   797,   799,   801,   803,
     805,   810,   815,   815,   820,   825,   825,   831,   837,   843,
     844,   844,   853,   853,   860,   861,   868,   868,   873,   873,
     879,   879,   885,   885,   891,   898,   903,   906,   913,   918,
     923,   926,   932,   937,   940,   947,   953,   958,   958,   964,
     969,   969,   974,   974,   979,   984,   990,   991,   998,  1004,
    1009,  1009,  1014,  1014,  1019,  1024,  1024,  1029,  1037,  1046,
    1054,  1061,  1070,  1078,  1086,  1093,  1101,  1109,  1117,  1125,
    1133,  1140,  1148,  1156,  1163,  1171,  1178,  1186,  1194,  1202,
    1210,  1218,  1229,  1240,  1251,  1259,  1267,  1275,  1283,  1291,
    1299,  1308,  1316,  1324,  1332,  1340,  1347,  1355,  1363,  1370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BAD", "DATASTRING", "ENCODING",
  "ENDITEM", "ENDVERSION", "SCHEMALOCATION", "STARTVERSION",
  "TERMINALSTRING", "XMLNSPREFIX", "XMLNSTARGET", "XMLVERSION", "A1END",
  "A1START", "A2END", "A2START", "AEND", "ASTART", "B1END", "B1START",
  "B2END", "B2START", "BEND", "BSTART", "DESCRIPTIONEND",
  "DESCRIPTIONSTART", "ELSEIFEND", "ELSEIFSTART", "ELSEEND", "ELSESTART",
  "ENDEFFECTORHOLDERNAMEEND", "ENDEFFECTORHOLDERNAMESTART",
  "ENDEFFECTORNAMEEND", "ENDEFFECTORNAMESTART", "IEND", "ISTART", "IFEND",
  "IFSTART", "JEND", "JSTART", "KEND", "KSTART", "KITNAMEEND",
  "KITNAMESTART", "KITTRAYNAMEEND", "KITTRAYNAMESTART", "KITTINGPLANEND",
  "KITTINGPLANSTART", "LOCATIONEND", "LOCATIONSTART", "NAMEEND",
  "NAMESTART", "NUMBEROFSTEPSEND", "NUMBEROFSTEPSSTART", "OBJECTEND",
  "OBJECTSTART", "ORIENTATIONSTANDARDDEVIATIONEND",
  "ORIENTATIONSTANDARDDEVIATIONSTART", "PARTNAMEEND", "PARTNAMESTART",
  "PLANAUTHOREND", "PLANAUTHORSTART", "PLANDATEANDTIMEEND",
  "PLANDATEANDTIMESTART", "PLANDESCRIPTIONEND", "PLANDESCRIPTIONSTART",
  "PLANELEMENTEND", "PLANELEMENTSTART", "PLANIDEND", "PLANIDSTART",
  "PLANROOTEND", "PLANROOTSTART", "PLANVERSIONEND", "PLANVERSIONSTART",
  "POINTEND", "POINTSTART", "POSITIONSTANDARDDEVIATIONEND",
  "POSITIONSTANDARDDEVIATIONSTART", "PREDECESSOREND", "PREDECESSORSTART",
  "PROPERTYEND", "PROPERTYSTART", "REFOBJECTNAMEEND", "REFOBJECTNAMESTART",
  "ROBOTNAMEEND", "ROBOTNAMESTART", "SEQUENCENUMBEREND",
  "SEQUENCENUMBERSTART", "STEPEND", "STEPSTART", "TESTEND", "TESTSTART",
  "THINGNAMEEND", "THINGNAMESTART", "VALEND", "VALSTART", "VARNAMEEND",
  "VARNAMESTART", "VARIABLEEND", "VARIABLESTART", "XAXISEND", "XAXISSTART",
  "XEND", "XSTART", "YEND", "YSTART", "ZAXISEND", "ZAXISSTART", "ZEND",
  "ZSTART", "ACTIONBASETYPEDECL", "ACTIONGROUPBASETYPEDECL", "ANDTYPEDECL",
  "ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL",
  "ARITHMETICEXPRESSIONTYPEDECL", "ATTACHENDEFFECTORTYPEDECL",
  "BINARYARITHMETICEXPRESSIONTYPEDECL", "BINARYBOOLEANEXPRESSIONTYPEDECL",
  "BOOLEANCONSTANTTYPEDECL", "BOOLEANEXPRESSIONTYPEDECL",
  "CREATEKITTYPEDECL", "DECIMALTYPEDECL", "DETACHENDEFFECTORTYPEDECL",
  "DIVTYPEDECL", "ELSETYPEDECL", "EQUALTYPEDECL", "FALSETYPEDECL",
  "GREATEROREQUALTYPEDECL", "GREATERTYPEDECL", "IFACTIONGROUPTYPEDECL",
  "KITTINGPLANTYPEDECL", "LESSOREQUALTYPEDECL", "LESSTYPEDECL",
  "LOCATEPARTTYPEDECL", "MINUSTYPEDECL", "MODTYPEDECL", "NEGATETYPEDECL",
  "NOTEQUALTYPEDECL", "NOTTYPEDECL", "NUMBEREDPLANELEMENTTYPEDECL",
  "ONEOFACTIONGROUPTYPEDECL", "ORTYPEDECL", "ORDEREDACTIONGROUPTYPEDECL",
  "PARTIALLYORDEREDACTIONGROUPTYPEDECL", "PHYSICALLOCATIONTYPEDECL",
  "PLANELEMENTBASETYPEDECL", "PLUSTYPEDECL", "POINTTYPEDECL",
  "POSELOCATIONINTYPEDECL", "POSELOCATIONONTYPEDECL",
  "POSELOCATIONTYPEDECL", "POSEONLYLOCATIONTYPEDECL", "PROPVALTYPEDECL",
  "PUTKITTRAYTYPEDECL", "PUTKITTYPEDECL", "PUTPARTTYPEDECL",
  "RELATIVELOCATIONINTYPEDECL", "RELATIVELOCATIONONTYPEDECL",
  "RELATIVELOCATIONTYPEDECL", "ROBOTACTIONBASETYPEDECL",
  "SENSORACTIONBASETYPEDECL", "SOMEOFACTIONGROUPTYPEDECL",
  "STEPWITHPREDECESSORSTYPEDECL", "TAKEKITTRAYTYPEDECL", "TAKEKITTYPEDECL",
  "TAKEPARTTYPEDECL", "TESTANDSTEPTYPEDECL", "TIMESTYPEDECL",
  "TRUETYPEDECL", "UNORDEREDACTIONGROUPTYPEDECL", "VARSETTYPEDECL",
  "VARVALTYPEDECL", "VARIABLEDECLARATIONTYPEDECL", "VECTORTYPEDECL",
  "WHILEACTIONGROUPTYPEDECL", "$accept", "y_KittingPlanFile",
  "y_XmlHeaderForKittingPlan", "y_SchemaLocation", "y_XmlDateTime",
  "y_XmlDecimal", "y_XmlID", "y_XmlIDREF", "y_XmlNMTOKEN",
  "y_XmlPositiveInteger", "y_XmlString", "y_XmlToken", "y_XmlVersion",
  "y_A1_ArithmeticExpressionType", "y_A2_ArithmeticExpressionType",
  "y_A_ArithmeticExpressionType", "y_A_XmlDecimal", "$@1",
  "y_ArithmeticExpressionTypeAny", "y_B1_BooleanExpressionType",
  "y_B2_BooleanExpressionType", "y_B_BooleanExpressionType",
  "y_BooleanExpressionTypeAny", "y_Description_XmlString", "$@2",
  "y_ElseIf_TestAndStepType_0_u", "y_ElseIf_TestAndStepType_0_uList",
  "y_ElseType", "y_Else_ElseType_0", "y_EndEffectorHolderName_XmlNMTOKEN",
  "$@3", "y_EndEffectorName_XmlNMTOKEN", "$@4", "y_I_XmlDecimal", "$@5",
  "y_If_TestAndStepType", "y_J_XmlDecimal", "$@6", "y_K_XmlDecimal", "$@7",
  "y_KitName_XmlNMTOKEN", "$@8", "y_KitTrayName_XmlNMTOKEN", "$@9",
  "y_KittingPlanType", "y_Location_PhysicalLocationType", "y_Name_XmlID",
  "$@10", "y_NumberOfSteps_XmlPositiveInteger", "$@11",
  "y_NumberedPlanElementType", "y_Object_XmlNMTOKEN_u", "$@12",
  "y_Object_XmlNMTOKEN_uList",
  "y_OrientationStandardDeviation_PositiveDecimalType_0", "$@13",
  "y_PartName_XmlNMTOKEN", "$@14", "y_PhysicalLocationTypeAny",
  "y_PlanAuthor_XmlToken", "$@15", "y_PlanDateAndTime_XmlDateTime", "$@16",
  "y_PlanDescription_XmlString", "$@17", "y_PlanElementBaseTypeAny",
  "y_PlanElement_PlanElementBaseType", "y_PlanId_XmlNMTOKEN", "$@18",
  "y_PlanRoot_PlanElementBaseType", "y_PlanVersion_XmlToken", "$@19",
  "y_PointType", "y_Point_PointType",
  "y_PositionStandardDeviation_PositiveDecimalType_0", "$@20",
  "y_Predecessor_XmlPositiveInteger_0_u", "$@21",
  "y_Predecessor_XmlPositiveInteger_0_uList", "y_Property_XmlNMTOKEN",
  "$@22", "y_RefObjectName_XmlNMTOKEN", "$@23", "y_RobotName_XmlNMTOKEN",
  "$@24", "y_SequenceNumber_XmlPositiveInteger", "$@25",
  "y_StepWithPredecessorsType", "y_Step_NumberedPlanElementType_u",
  "y_Step_NumberedPlanElementType_uList", "y_Step_PlanElementBaseType",
  "y_Step_PlanElementBaseType_u", "y_Step_PlanElementBaseType_uList",
  "y_Step_StepWithPredecessorsType_u",
  "y_Step_StepWithPredecessorsType_uList", "y_TestAndStepType",
  "y_Test_BooleanExpressionType", "y_ThingName_XmlNMTOKEN", "$@26",
  "y_Val_ArithmeticExpressionType", "y_Val_XmlDecimal", "$@27",
  "y_VarName_XmlIDREF", "$@28", "y_VariableDeclarationType",
  "y_Variable_VariableDeclarationType_0_u",
  "y_Variable_VariableDeclarationType_0_uList", "y_VectorType",
  "y_XAxis_VectorType", "y_X_XmlDecimal", "$@29", "y_Y_XmlDecimal", "$@30",
  "y_ZAxis_VectorType", "y_Z_XmlDecimal", "$@31", "y_x_AndType",
  "y_x_AttachEndEffectorType", "y_x_CreateKitType", "y_x_DecimalType",
  "y_x_DetachEndEffectorType", "y_x_DivType", "y_x_EqualType",
  "y_x_FalseType", "y_x_GreaterOrEqualType", "y_x_GreaterType",
  "y_x_IfActionGroupType", "y_x_LessOrEqualType", "y_x_LessType",
  "y_x_LocatePartType", "y_x_MinusType", "y_x_ModType", "y_x_NegateType",
  "y_x_NotEqualType", "y_x_NotType", "y_x_OneOfActionGroupType",
  "y_x_OrType", "y_x_OrderedActionGroupType",
  "y_x_PartiallyOrderedActionGroupType", "y_x_PlusType",
  "y_x_PoseLocationInType", "y_x_PoseLocationOnType",
  "y_x_PoseOnlyLocationType", "y_x_PropValType", "y_x_PutKitTrayType",
  "y_x_PutKitType", "y_x_PutPartType", "y_x_RelativeLocationInType",
  "y_x_RelativeLocationOnType", "y_x_SomeOfActionGroupType",
  "y_x_TakeKitTrayType", "y_x_TakeKitType", "y_x_TakePartType",
  "y_x_TimesType", "y_x_TrueType", "y_x_UnorderedActionGroupType",
  "y_x_VarSetType", "y_x_VarValType", "y_x_WhileActionGroupType", 0
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
     425,   426,   427,   428,   429,   430,   431
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   189,   190,   191,   192,   194,   193,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     197,   198,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   201,   200,   202,   203,   203,   204,   205,
     205,   207,   206,   209,   208,   211,   210,   212,   214,   213,
     216,   215,   218,   217,   220,   219,   221,   222,   224,   223,
     226,   225,   227,   229,   228,   230,   230,   231,   232,   231,
     234,   233,   235,   235,   235,   235,   235,   237,   236,   239,
     238,   241,   240,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   245,   244,   246,   248,   247,   249,   250,   251,
     252,   251,   254,   253,   255,   255,   257,   256,   259,   258,
     261,   260,   263,   262,   264,   265,   266,   266,   267,   268,
     269,   269,   270,   271,   271,   272,   273,   275,   274,   276,
     278,   277,   280,   279,   281,   282,   283,   283,   284,   285,
     287,   286,   289,   288,   290,   292,   291,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     3,     3,     3,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     0,     2,     3,     0,
       3,     0,     5,     0,     5,     0,     5,     3,     0,     5,
       0,     5,     0,     5,     0,     5,    10,     3,     0,     5,
       0,     5,     4,     0,     5,     1,     2,     0,     0,     5,
       0,     5,     1,     1,     1,     1,     1,     0,     5,     0,
       5,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     5,     3,     0,     5,     5,     3,     0,
       0,     5,     0,     5,     0,     2,     0,     5,     0,     5,
       0,     5,     0,     5,     5,     3,     1,     2,     3,     3,
       1,     2,     3,     1,     2,     4,     3,     0,     5,     3,
       0,     5,     0,     5,     3,     3,     0,     2,     5,     3,
       0,     5,     0,     5,     3,     0,     5,     5,     6,     5,
       4,     6,     5,     5,     3,     5,     5,     6,     5,     5,
       4,     5,     5,     4,     5,     4,     4,     5,     4,     4,
       5,     9,     9,     9,     5,     6,     6,     6,     5,     5,
       5,     5,     5,     5,     5,     3,     4,     5,     4,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    13,     0,     3,     0,     0,     0,     4,     0,     0,
       2,    14,    68,     0,     0,     0,   112,     0,     0,     7,
       0,     0,   115,     0,     0,    69,     9,     0,     0,    89,
       0,     0,   113,    12,     0,     0,    87,     0,     0,   116,
       5,     0,     0,    91,     0,    75,   156,    90,     0,     0,
      73,    76,     0,    88,    11,     0,     0,     0,     0,    66,
     157,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,     0,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
      46,     0,   180,     0,   136,   186,   188,     0,   143,   189,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   206,
       0,     0,     0,     0,   150,   130,     0,     0,    64,     0,
     169,     0,     0,     0,    49,    80,     0,     0,   137,     0,
       0,   144,     0,     0,     0,     0,     0,   200,   141,   201,
     202,   203,   152,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,   209,
       0,     0,    53,     0,   168,     0,    62,   171,     0,    57,
       0,     0,    47,   177,     0,     0,   135,     0,   142,     0,
     195,   196,   197,   139,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,     6,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,   205,   138,   151,
     131,     0,     0,    65,     0,   145,    45,     0,    50,    81,
     132,     0,    72,     0,     0,     0,     0,     0,     0,    67,
      10,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,    54,     0,    63,    48,     0,     0,
       0,   134,   125,     0,     0,     0,     0,     0,    71,     0,
     170,     0,     0,     0,     0,   183,     0,     0,     0,     0,
     208,     0,     0,   167,     0,     0,   173,   175,   176,   178,
     179,   184,     0,   187,    52,     0,   111,   122,     0,     0,
       0,     0,     0,     0,    18,   172,   181,   182,     0,   190,
     147,     0,   194,   204,    29,     0,    15,     0,    31,   133,
       0,   128,     0,     0,     0,     0,     0,   198,   199,     0,
      17,     0,   126,    30,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,   123,     0,     0,
     118,     0,     0,     0,   119,   119,   119,     0,    19,   148,
       0,   129,     0,     0,     0,   159,     0,     0,    77,    77,
      77,     0,   127,   160,     0,     0,     0,     0,   164,   120,
       0,   191,   192,   193,    44,     0,   162,     0,   117,    55,
       0,     0,     0,    78,     0,     0,   165,     0,    58,     0,
     158,     0,     0,   161,     0,     0,     0,     0,    60,   121,
       0,   163,     0,    56,     0,     0,    79,   166,    59,     0,
      61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,    51,   299,    30,   326,    37,   371,
      65,    44,     3,   385,   426,   415,   410,   469,   275,   383,
     423,   392,   226,   467,   497,   252,   194,   308,   253,   244,
     352,   187,   301,   517,   537,   160,   531,   547,   540,   555,
     190,   304,   157,   245,    15,   260,    19,    25,   207,   324,
     197,    55,    66,    56,   521,   542,   162,   254,   318,    41,
      52,    34,    45,    48,    59,    91,   362,    24,    31,    69,
      28,    38,   478,   463,   508,   532,   402,   460,   363,   452,
     486,   439,   476,   155,   241,   311,   398,   200,   164,   165,
     239,   174,   175,   168,   169,   193,   183,   418,   471,   214,
     153,   240,   181,   265,   111,    70,    62,   492,   480,   503,
     525,   515,   535,   494,   528,   545,   227,    92,    93,   276,
      94,   277,   228,   229,   230,   231,    95,   232,   233,    96,
     278,   279,   280,   234,   235,    97,   236,    98,    99,   281,
     319,   320,   321,   282,   100,   101,   102,   322,   323,   103,
     104,   105,   106,   283,   237,   107,   108,   284,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -468
static const yytype_int16 yypact[] =
{
      -2,    -1,    49,     6,    42,  -468,    46,    16,    51,    57,
      59,  -468,    62,  -468,    14,    29,    72,  -468,    77,    20,
    -468,  -468,  -468,    81,    18,   102,  -468,   104,    61,  -468,
      71,   123,  -468,   124,    66,  -468,  -468,    74,   127,  -468,
     142,    85,  -468,  -468,    80,   152,  -468,   153,   101,  -468,
    -468,   106,   127,  -468,   159,  -468,   101,  -468,   110,   162,
    -468,  -468,   -54,  -468,  -468,   108,   123,   -71,   170,  -468,
    -468,  -468,   121,   172,   174,   175,   176,   177,   178,   185,
     186,   188,   189,   190,   204,   206,   207,   208,   209,   212,
     214,   149,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
      14,   122,  -468,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,  -468,   126,  -468,   137,   179,   137,   191,   164,   136,
     136,   138,   137,   137,   137,   140,   137,   137,   137,   140,
     129,   139,   227,  -468,   228,   201,   231,   203,   201,   243,
    -468,   244,  -468,   245,  -468,   136,   136,   246,  -468,   138,
     179,   203,   164,   -71,  -468,   -47,   179,   203,   164,   140,
     247,   157,   -15,   165,  -468,  -468,   249,   224,  -468,   252,
    -468,   224,    14,   221,    19,  -468,    14,   171,  -468,    14,
     173,  -468,   211,   211,   211,   180,   254,  -468,  -468,  -468,
    -468,  -468,  -468,   -16,  -468,   258,   259,   260,   261,   262,
     263,   265,   266,   267,   268,   269,   192,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,   -71,  -468,
     277,   123,  -468,   276,  -468,   123,  -468,  -468,   139,  -468,
     243,   279,  -468,  -468,   123,   194,  -468,   194,  -468,    58,
    -468,  -468,  -468,  -468,  -468,   283,   282,   284,   285,   286,
     287,   288,   289,   290,   291,   193,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,  -468,   210,  -468,   202,
     213,   123,  -468,   255,   123,   165,   274,    14,   273,   248,
     298,   236,  -468,   300,   301,   303,   304,   305,   264,  -468,
    -468,  -468,  -468,  -468,   308,  -468,   215,    14,    14,    14,
      14,    14,    14,    14,    14,    14,  -468,   294,   302,  -468,
     302,   302,   302,   302,   302,   293,   294,  -468,  -468,  -468,
    -468,   292,   123,  -468,   272,  -468,  -468,   165,  -468,  -468,
    -468,   -71,  -468,   -63,    14,    14,    14,    14,    14,  -468,
    -468,   270,  -468,   306,   302,   302,   302,   309,   302,   225,
     302,   129,   -15,   296,   -16,   310,   310,   310,   310,   310,
     310,   -15,  -468,   296,  -468,   297,  -468,  -468,   308,   253,
     316,  -468,  -468,   238,   238,   238,   238,   238,  -468,   324,
    -468,   310,   310,   310,   -16,  -468,   310,   325,   250,   310,
    -468,   312,   -15,  -468,   320,   -16,  -468,  -468,  -468,  -468,
    -468,  -468,   311,  -468,  -468,   251,  -468,  -468,   330,   271,
     271,   271,   313,   313,  -468,  -468,  -468,  -468,   319,  -468,
    -468,   332,  -468,  -468,  -468,   321,  -468,   326,  -468,  -468,
     308,  -468,   335,   241,   241,   241,   339,  -468,  -468,   277,
    -468,   123,  -468,  -468,  -468,   275,   123,    14,   278,   340,
     240,   240,   240,  -468,   329,   256,   123,  -468,   280,   257,
    -468,    14,   281,   340,   295,   295,   295,   162,  -468,  -468,
     299,  -468,   345,   307,   315,  -468,   314,   347,   317,   317,
     317,   331,  -468,  -468,   350,   318,   352,   322,  -468,  -468,
     353,  -468,  -468,  -468,  -468,   277,  -468,   354,  -468,  -468,
     355,   323,   361,  -468,   327,   277,  -468,   277,  -468,   362,
    -468,   328,   363,  -468,   333,   277,   334,   277,  -468,  -468,
     336,  -468,   337,  -468,   338,   277,  -468,  -468,  -468,   342,
    -468
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -468,  -468,  -468,  -468,  -468,  -467,  -468,  -468,   -66,  -395,
    -128,   341,  -468,  -207,  -226,  -468,  -468,  -468,  -371,    25,
     -21,  -468,  -377,   -70,  -468,  -468,  -468,  -468,  -468,   184,
    -468,   219,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
    -162,  -468,  -160,  -468,  -468,  -142,   -88,  -468,  -468,  -468,
    -468,   343,  -468,  -468,  -434,  -468,  -161,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -172,    17,  -468,  -468,  -468,
    -468,  -468,  -468,  -359,  -406,  -468,  -468,  -468,  -468,  -468,
    -468,  -264,  -468,     3,  -468,   125,  -468,  -468,   -68,   239,
    -301,  -155,   237,   216,  -468,   141,   144,  -468,  -468,  -468,
    -468,  -468,     7,  -468,  -468,  -468,  -468,  -106,  -362,  -468,
    -468,  -468,  -468,  -365,  -468,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468,  -468
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      72,   205,   484,   435,   355,   421,   361,     1,   206,   203,
     202,   204,     4,   424,   432,   210,   209,   211,   400,    67,
     208,    10,   132,    11,   208,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   448,   173,   455,    73,    68,   250,     5,
     251,    74,     7,    75,   457,     6,   397,     8,   534,    12,
      76,   261,   262,    14,    77,   475,   297,    18,   544,    16,
     546,    78,    17,    79,    80,   522,   523,    20,   552,    21,
     554,   464,   465,    22,    81,    82,    83,    26,   559,   509,
     510,    23,    84,    27,    85,    86,    87,   198,   198,   215,
      88,    89,   481,   482,   248,    90,    29,   266,   255,   267,
      32,   257,   216,   217,   218,   219,   495,   496,   220,   221,
     268,   269,   270,    35,   222,   223,    33,    36,   224,    40,
      39,    43,   271,   386,   387,   388,   389,   390,   272,   158,
     440,   441,   442,   443,    42,   170,   171,   172,    46,   176,
     177,   178,    47,   273,    49,   225,    50,   274,    54,    53,
     427,   428,   429,   430,   431,    60,    64,   411,   412,   413,
      57,   416,    63,   419,    71,   300,   110,   112,   113,   303,
     114,   115,   116,   117,   118,   445,   446,   447,   309,   399,
     449,   119,   120,   453,   121,   122,   123,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   313,   314,
     124,   315,   125,   126,   127,   128,   316,   317,   129,   357,
     130,   131,   133,   152,   154,   161,   156,   163,   180,   167,
     159,   173,   182,   184,   185,   351,   186,   188,   354,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   189,   192,
     195,   196,   199,   212,   213,   242,   238,   243,   246,   249,
     264,   256,   259,   258,   285,   286,   287,   288,   289,   290,
     263,   291,   292,   293,   294,   295,   403,   404,   405,   406,
     407,   298,   302,   310,   296,   307,   395,   325,   327,   336,
     328,   329,   330,   331,   332,   333,   334,   335,   349,   350,
     348,   353,   356,   358,   360,   361,   364,   365,   359,   366,
     367,   368,   370,   372,   369,   382,   396,   384,   391,   422,
     417,   436,   437,   438,   408,   409,   394,   425,   414,   434,
     444,   450,   454,   451,   456,   458,   461,   470,   472,   459,
     466,   477,   474,   473,   479,   483,   491,   498,   462,   493,
     499,   513,   516,   519,   490,   487,   526,   524,   529,   533,
     536,   538,   502,   530,   501,   541,   539,   550,   548,   511,
     553,   393,   433,   468,   507,   247,   520,   191,   558,   166,
     401,   512,   312,   505,   560,   201,   179,   506,   420,   489,
       0,   306,   305,    58,   556,     0,     0,     0,     0,    61,
       0,     0,     0,   504,     0,   485,   549,     0,     0,     0,
     488,     0,     0,     0,   514,     0,     0,     0,     0,     0,
     500,     0,   518,     0,     0,     0,     0,     0,     0,   527,
       0,   543,     0,     0,     0,     0,     0,     0,     0,   551,
       0,     0,     0,     0,     0,     0,     0,   557
};

static const yytype_int16 yycheck[] =
{
      66,   173,   469,   398,   305,   382,    69,     9,    55,   171,
     170,   172,    13,   384,   391,   177,   176,   178,    81,    73,
     175,     5,   110,     7,   179,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   414,    91,   422,   117,   101,    29,     0,
      31,   122,    10,   124,   425,    49,   357,    11,   525,     8,
     131,   203,   204,     6,   135,   460,   238,    53,   535,    10,
     537,   142,    10,   144,   145,   509,   510,    48,   545,     7,
     547,   440,   441,     6,   155,   156,   157,     6,   555,   495,
     496,    71,   163,    75,   165,   166,   167,   165,   166,   114,
     171,   172,   464,   465,   192,   176,     4,   123,   196,   125,
       6,   199,   127,   128,   129,   130,   481,   482,   133,   134,
     136,   137,   138,    52,   139,   140,    65,     4,   143,    63,
       6,     4,   148,   340,   341,   342,   343,   344,   154,   136,
     404,   405,   406,   407,    70,   142,   143,   144,     6,   146,
     147,   148,    67,   169,    74,   170,     4,   173,    57,     6,
     386,   387,   388,   389,   390,     6,     4,   374,   375,   376,
      64,   378,    62,   380,    66,   241,     6,    56,     6,   245,
       6,     6,     6,     6,     6,   411,   412,   413,   254,   361,
     416,     6,     6,   419,     6,     6,     6,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   150,   151,
       6,   153,     6,     6,     6,     6,   158,   159,     6,   307,
       6,    72,   100,    97,    87,    61,    47,    91,    99,    91,
      39,    91,    93,     6,     6,   301,    35,     6,   304,   327,
     328,   329,   330,   331,   332,   333,   334,   335,    45,     6,
       6,     6,     6,     6,    97,     6,    91,    33,     6,    38,
       6,    90,    51,    90,     6,     6,     6,     6,     6,     6,
      90,     6,     6,     6,     6,     6,   364,   365,   366,   367,
     368,     4,     6,    89,    92,     6,   352,     4,     6,    96,
       6,     6,     6,     6,     6,     6,     6,     6,    96,    86,
      90,    46,    28,    30,     6,    69,     6,     6,    60,     6,
       6,     6,     4,    98,    50,    21,    44,    15,    25,    23,
      95,    68,     6,    85,    54,    19,    34,    17,    19,    32,
       6,     6,    20,    83,    14,    24,     6,    18,     6,    88,
      27,     6,    16,    22,   103,     6,     6,    18,    77,   109,
      94,     6,    37,     6,    76,    80,     6,    26,     6,     6,
       6,     6,   105,    41,    84,     4,    43,     4,     6,   497,
      36,   346,   393,   443,    79,   191,    59,   158,    40,   140,
     363,    82,   257,   102,    42,   169,   149,   493,   381,   477,
      -1,   250,   248,    52,    58,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,   491,    -1,   471,    78,    -1,    -1,    -1,
     476,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
     486,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     9,   178,   189,    13,     0,    49,    10,    11,   179,
       5,     7,     8,   180,     6,   221,    10,    10,    53,   223,
      48,     7,     6,    71,   244,   224,     6,    75,   247,     4,
     183,   245,     6,    65,   238,    52,     4,   185,   248,     6,
      63,   236,    70,     4,   188,   239,     6,    67,   240,    74,
       4,   181,   237,     6,    57,   228,   230,    64,   188,   241,
       6,   228,   283,    62,     4,   187,   229,    73,   101,   246,
     282,    66,   185,   117,   122,   124,   131,   135,   142,   144,
     145,   155,   156,   157,   163,   165,   166,   167,   171,   172,
     176,   242,   294,   295,   297,   303,   306,   312,   314,   315,
     321,   322,   323,   326,   327,   328,   329,   332,   333,   335,
       6,   281,    56,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    72,   223,   100,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,    97,   277,    87,   260,    47,   219,   260,    39,
     212,    61,   233,    91,   265,   266,   266,    91,   270,   271,
     260,   260,   260,    91,   268,   269,   260,   260,   260,   269,
      99,   279,    93,   273,     6,     6,    35,   208,     6,    45,
     217,   208,     6,   272,   203,     6,     6,   227,   265,     6,
     264,   270,   219,   217,   233,   242,    55,   225,   268,   219,
     217,   233,     6,    97,   276,   114,   127,   128,   129,   130,
     133,   134,   139,   140,   143,   170,   199,   293,   299,   300,
     301,   302,   304,   305,   310,   311,   313,   331,    91,   267,
     278,   261,     6,    33,   206,   220,     6,   206,   223,    38,
      29,    31,   202,   205,   234,   223,    90,   223,    90,    51,
     222,   222,   222,    90,     6,   280,   123,   125,   136,   137,
     138,   148,   154,   169,   173,   195,   296,   298,   307,   308,
     309,   316,   320,   330,   334,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,    92,   242,     4,   182,
     185,   209,     6,   185,   218,   273,   272,     6,   204,   185,
      89,   262,   262,   150,   151,   153,   158,   159,   235,   317,
     318,   319,   324,   325,   226,     4,   184,     6,     6,     6,
       6,     6,     6,     6,     6,     6,    96,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,    90,    96,
      86,   185,   207,    46,   185,   267,    28,   223,    30,    60,
       6,    69,   243,   255,     6,     6,     6,     6,     6,    50,
       4,   186,    98,   223,   223,   223,   223,   223,   223,   223,
     223,   223,    21,   196,    15,   190,   190,   190,   190,   190,
     190,    25,   198,   196,    34,   185,    44,   267,   263,   242,
      81,   243,   253,   223,   223,   223,   223,   223,    54,    19,
     193,   190,   190,   190,    19,   192,   190,    95,   274,   190,
     279,   199,    23,   197,   195,    17,   191,   191,   191,   191,
     191,   191,   199,   197,    32,   186,    68,     6,    85,   258,
     258,   258,   258,   258,     6,   191,   191,   191,   195,   191,
       6,    83,   256,   191,    20,   199,    14,   195,    24,    88,
     254,     6,    77,   250,   250,   250,    27,   200,   200,   194,
      18,   275,     6,    22,    16,   186,   259,     6,   249,   103,
     285,   285,   285,     6,   182,   185,   257,    80,   185,   223,
      76,     6,   284,   109,   290,   290,   290,   201,    18,    94,
     185,    84,   105,   286,   223,   102,   284,    79,   251,   251,
     251,   187,    82,     6,   107,   288,    37,   210,   108,     6,
      59,   231,   231,   231,    26,   287,     6,   111,   291,     6,
      41,   213,   252,     6,   182,   289,     6,   211,     6,    43,
     215,     4,   232,   104,   182,   292,   182,   214,     6,    78,
       4,   106,   182,    36,   182,   216,    58,   110,    40,   182,
      42
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

    {(yyval.KittingPlanFileVal) = new KittingPlanFile((yyvsp[(1) - (5)].XmlVersionVal), (yyvsp[(3) - (5)].XmlHeaderForKittingPlanVal), (yyvsp[(4) - (5)].KittingPlanTypeVal));
	   KittingPlanTree = (yyval.KittingPlanFileVal);
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  ;}
    break;

  case 3:

    {(yyval.XmlHeaderForKittingPlanVal) = new XmlHeaderForKittingPlan((yyvsp[(2) - (2)].SchemaLocationVal));;}
    break;

  case 4:

    {(yyval.SchemaLocationVal) = new SchemaLocation("xsi", (yyvsp[(2) - (2)].sVal), false);
	  ;}
    break;

  case 5:

    {(yyval.XmlDateTimeVal) = new XmlDateTime((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlDateTimeVal)->bad)
	     yyerror("bad XmlDateTime");
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

    {(yyval.XmlPositiveIntegerVal) = new XmlPositiveInteger((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlPositiveIntegerVal)->bad)
	     yyerror("bad XmlPositiveInteger");
	  ;}
    break;

  case 11:

    {(yyval.XmlStringVal) = new XmlString((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlStringVal)->bad)
	     yyerror("bad XmlString");
	  ;}
    break;

  case 12:

    {(yyval.XmlTokenVal) = new XmlToken((yyvsp[(1) - (1)].sVal));
	   if ((yyval.XmlTokenVal)->bad)
	     yyerror("bad XmlToken");
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

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);;}
    break;

  case 16:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);;}
    break;

  case 17:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);;}
    break;

  case 18:

    {yyReadData = 1;;}
    break;

  case 19:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 20:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].DecimalTypeVal);;}
    break;

  case 21:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].DivTypeVal);;}
    break;

  case 22:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].MinusTypeVal);;}
    break;

  case 23:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].ModTypeVal);;}
    break;

  case 24:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].NegateTypeVal);;}
    break;

  case 25:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].PlusTypeVal);;}
    break;

  case 26:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].PropValTypeVal);;}
    break;

  case 27:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].TimesTypeVal);;}
    break;

  case 28:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(1) - (1)].VarValTypeVal);;}
    break;

  case 29:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);;}
    break;

  case 30:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);;}
    break;

  case 31:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);;}
    break;

  case 32:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].AndTypeVal);;}
    break;

  case 33:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].EqualTypeVal);;}
    break;

  case 34:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].FalseTypeVal);;}
    break;

  case 35:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].GreaterOrEqualTypeVal);;}
    break;

  case 36:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].GreaterTypeVal);;}
    break;

  case 37:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].LessOrEqualTypeVal);;}
    break;

  case 38:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].LessTypeVal);;}
    break;

  case 39:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].NotEqualTypeVal);;}
    break;

  case 40:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].NotTypeVal);;}
    break;

  case 41:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].OrTypeVal);;}
    break;

  case 42:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(1) - (1)].TrueTypeVal);;}
    break;

  case 43:

    {yyReadData = 1;;}
    break;

  case 44:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 45:

    {(yyval.TestAndStepTypeVal) = (yyvsp[(2) - (3)].TestAndStepTypeVal);;}
    break;

  case 46:

    {(yyval.TestAndStepTypeListVal) = new std::list<TestAndStepType *>;;}
    break;

  case 47:

    {(yyval.TestAndStepTypeListVal) = (yyvsp[(1) - (2)].TestAndStepTypeListVal);
	   (yyval.TestAndStepTypeListVal)->push_back((yyvsp[(2) - (2)].TestAndStepTypeVal));;}
    break;

  case 48:

    {(yyval.ElseTypeVal) = new ElseType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].PlanElementBaseTypeVal));;}
    break;

  case 49:

    {(yyval.ElseTypeVal) = 0;;}
    break;

  case 50:

    {(yyval.ElseTypeVal) = (yyvsp[(2) - (3)].ElseTypeVal);;}
    break;

  case 51:

    {yyReadData = 1;;}
    break;

  case 52:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 53:

    {yyReadData = 1;;}
    break;

  case 54:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 55:

    {yyReadData = 1;;}
    break;

  case 56:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 57:

    {(yyval.TestAndStepTypeVal) = (yyvsp[(2) - (3)].TestAndStepTypeVal);;}
    break;

  case 58:

    {yyReadData = 1;;}
    break;

  case 59:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 60:

    {yyReadData = 1;;}
    break;

  case 61:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 62:

    {yyReadData = 1;;}
    break;

  case 63:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 64:

    {yyReadData = 1;;}
    break;

  case 65:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 66:

    {(yyval.KittingPlanTypeVal) = new KittingPlanType((yyvsp[(2) - (10)].XmlIDVal), (yyvsp[(3) - (10)].XmlNMTOKENVal), (yyvsp[(4) - (10)].XmlTokenVal), (yyvsp[(5) - (10)].XmlDateTimeVal), (yyvsp[(6) - (10)].XmlTokenVal), (yyvsp[(7) - (10)].XmlStringVal), (yyvsp[(8) - (10)].NMTOKENListVal), (yyvsp[(9) - (10)].VariableDeclarationTypeListVal), (yyvsp[(10) - (10)].PlanElementBaseTypeVal));;}
    break;

  case 67:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(2) - (3)].PhysicalLocationTypeVal);;}
    break;

  case 68:

    {yyReadData = 1;;}
    break;

  case 69:

    {(yyval.XmlIDVal) = (yyvsp[(4) - (5)].XmlIDVal);;}
    break;

  case 70:

    {yyReadData = 1;;}
    break;

  case 71:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 72:

    {(yyval.NumberedPlanElementTypeVal) = new NumberedPlanElementType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].XmlPositiveIntegerVal), (yyvsp[(4) - (4)].PlanElementBaseTypeVal));;}
    break;

  case 73:

    {yyReadData = 1;;}
    break;

  case 74:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 75:

    {(yyval.NMTOKENListVal) = new std::list<XmlNMTOKEN *>;
	   (yyval.NMTOKENListVal)->push_back((yyvsp[(1) - (1)].XmlNMTOKENVal));;}
    break;

  case 76:

    {(yyval.NMTOKENListVal) = (yyvsp[(1) - (2)].NMTOKENListVal);
	   (yyval.NMTOKENListVal)->push_back((yyvsp[(2) - (2)].XmlNMTOKENVal));;}
    break;

  case 77:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 78:

    {yyReadData = 1;;}
    break;

  case 79:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  ;}
    break;

  case 80:

    {yyReadData = 1;;}
    break;

  case 81:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 82:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationInTypeVal);;}
    break;

  case 83:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseLocationOnTypeVal);;}
    break;

  case 84:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].PoseOnlyLocationTypeVal);;}
    break;

  case 85:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationInTypeVal);;}
    break;

  case 86:

    {(yyval.PhysicalLocationTypeVal) = (yyvsp[(1) - (1)].RelativeLocationOnTypeVal);;}
    break;

  case 87:

    {yyReadData = 1;;}
    break;

  case 88:

    {(yyval.XmlTokenVal) = (yyvsp[(4) - (5)].XmlTokenVal);;}
    break;

  case 89:

    {yyReadData = 1;;}
    break;

  case 90:

    {(yyval.XmlDateTimeVal) = (yyvsp[(4) - (5)].XmlDateTimeVal);;}
    break;

  case 91:

    {yyReadData = 1;;}
    break;

  case 92:

    {(yyval.XmlStringVal) = (yyvsp[(4) - (5)].XmlStringVal);;}
    break;

  case 93:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].AttachEndEffectorTypeVal);;}
    break;

  case 94:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].CreateKitTypeVal);;}
    break;

  case 95:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].DetachEndEffectorTypeVal);;}
    break;

  case 96:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].IfActionGroupTypeVal);;}
    break;

  case 97:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].LocatePartTypeVal);;}
    break;

  case 98:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].OneOfActionGroupTypeVal);;}
    break;

  case 99:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].OrderedActionGroupTypeVal);;}
    break;

  case 100:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PartiallyOrderedActionGroupTypeVal);;}
    break;

  case 101:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutKitTrayTypeVal);;}
    break;

  case 102:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutKitTypeVal);;}
    break;

  case 103:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].PutPartTypeVal);;}
    break;

  case 104:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].SomeOfActionGroupTypeVal);;}
    break;

  case 105:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakeKitTrayTypeVal);;}
    break;

  case 106:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakeKitTypeVal);;}
    break;

  case 107:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].TakePartTypeVal);;}
    break;

  case 108:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].UnorderedActionGroupTypeVal);;}
    break;

  case 109:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].VarSetTypeVal);;}
    break;

  case 110:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(1) - (1)].WhileActionGroupTypeVal);;}
    break;

  case 111:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);;}
    break;

  case 112:

    {yyReadData = 1;;}
    break;

  case 113:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 114:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);;}
    break;

  case 115:

    {yyReadData = 1;;}
    break;

  case 116:

    {(yyval.XmlTokenVal) = (yyvsp[(4) - (5)].XmlTokenVal);;}
    break;

  case 117:

    {(yyval.PointTypeVal) = new PointType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 118:

    {(yyval.PointTypeVal) = (yyvsp[(2) - (3)].PointTypeVal);;}
    break;

  case 119:

    {(yyval.PositiveDecimalTypeVal) = 0;;}
    break;

  case 120:

    {yyReadData = 1;;}
    break;

  case 121:

    {(yyval.PositiveDecimalTypeVal) = new PositiveDecimalType((yyvsp[(4) - (5)].sVal));
	   if ((yyval.PositiveDecimalTypeVal)->bad)
	     yyerror("bad PositionStandardDeviation value");
	  ;}
    break;

  case 122:

    {yyReadData = 1;;}
    break;

  case 123:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 124:

    {(yyval.positiveIntegerListVal) = new std::list<XmlPositiveInteger *>;;}
    break;

  case 125:

    {(yyval.positiveIntegerListVal) = (yyvsp[(1) - (2)].positiveIntegerListVal);
	   (yyval.positiveIntegerListVal)->push_back((yyvsp[(2) - (2)].XmlPositiveIntegerVal));;}
    break;

  case 126:

    {yyReadData = 1;;}
    break;

  case 127:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 128:

    {yyReadData = 1;;}
    break;

  case 129:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 130:

    {yyReadData = 1;;}
    break;

  case 131:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 132:

    {yyReadData = 1;;}
    break;

  case 133:

    {(yyval.XmlPositiveIntegerVal) = (yyvsp[(4) - (5)].XmlPositiveIntegerVal);;}
    break;

  case 134:

    {(yyval.StepWithPredecessorsTypeVal) = new StepWithPredecessorsType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlPositiveIntegerVal), (yyvsp[(4) - (5)].positiveIntegerListVal), (yyvsp[(5) - (5)].PlanElementBaseTypeVal));;}
    break;

  case 135:

    {(yyval.NumberedPlanElementTypeVal) = (yyvsp[(2) - (3)].NumberedPlanElementTypeVal);;}
    break;

  case 136:

    {(yyval.NumberedPlanElementTypeListVal) = new std::list<NumberedPlanElementType *>;
	   (yyval.NumberedPlanElementTypeListVal)->push_back((yyvsp[(1) - (1)].NumberedPlanElementTypeVal));;}
    break;

  case 137:

    {(yyval.NumberedPlanElementTypeListVal) = (yyvsp[(1) - (2)].NumberedPlanElementTypeListVal);
	   (yyval.NumberedPlanElementTypeListVal)->push_back((yyvsp[(2) - (2)].NumberedPlanElementTypeVal));;}
    break;

  case 138:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);;}
    break;

  case 139:

    {(yyval.PlanElementBaseTypeVal) = (yyvsp[(2) - (3)].PlanElementBaseTypeVal);;}
    break;

  case 140:

    {(yyval.PlanElementBaseTypeListVal) = new std::list<PlanElementBaseType *>;
	   (yyval.PlanElementBaseTypeListVal)->push_back((yyvsp[(1) - (1)].PlanElementBaseTypeVal));;}
    break;

  case 141:

    {(yyval.PlanElementBaseTypeListVal) = (yyvsp[(1) - (2)].PlanElementBaseTypeListVal);
	   (yyval.PlanElementBaseTypeListVal)->push_back((yyvsp[(2) - (2)].PlanElementBaseTypeVal));;}
    break;

  case 142:

    {(yyval.StepWithPredecessorsTypeVal) = (yyvsp[(2) - (3)].StepWithPredecessorsTypeVal);;}
    break;

  case 143:

    {(yyval.StepWithPredecessorsTypeListVal) = new std::list<StepWithPredecessorsType *>;
	   (yyval.StepWithPredecessorsTypeListVal)->push_back((yyvsp[(1) - (1)].StepWithPredecessorsTypeVal));;}
    break;

  case 144:

    {(yyval.StepWithPredecessorsTypeListVal) = (yyvsp[(1) - (2)].StepWithPredecessorsTypeListVal);
	   (yyval.StepWithPredecessorsTypeListVal)->push_back((yyvsp[(2) - (2)].StepWithPredecessorsTypeVal));;}
    break;

  case 145:

    {(yyval.TestAndStepTypeVal) = new TestAndStepType((yyvsp[(2) - (4)].XmlIDVal), (yyvsp[(3) - (4)].BooleanExpressionTypeVal), (yyvsp[(4) - (4)].PlanElementBaseTypeVal));;}
    break;

  case 146:

    {(yyval.BooleanExpressionTypeVal) = (yyvsp[(2) - (3)].BooleanExpressionTypeVal);;}
    break;

  case 147:

    {yyReadData = 1;;}
    break;

  case 148:

    {(yyval.XmlNMTOKENVal) = (yyvsp[(4) - (5)].XmlNMTOKENVal);;}
    break;

  case 149:

    {(yyval.ArithmeticExpressionTypeVal) = (yyvsp[(2) - (3)].ArithmeticExpressionTypeVal);;}
    break;

  case 150:

    {yyReadData = 1;;}
    break;

  case 151:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 152:

    {yyReadData = 1;;}
    break;

  case 153:

    {(yyval.XmlIDREFVal) = (yyvsp[(4) - (5)].XmlIDREFVal);;}
    break;

  case 154:

    {(yyval.VariableDeclarationTypeVal) = new VariableDeclarationType((yyvsp[(2) - (3)].XmlIDVal), (yyvsp[(3) - (3)].XmlDecimalVal));;}
    break;

  case 155:

    {(yyval.VariableDeclarationTypeVal) = (yyvsp[(2) - (3)].VariableDeclarationTypeVal);;}
    break;

  case 156:

    {(yyval.VariableDeclarationTypeListVal) = new std::list<VariableDeclarationType *>;;}
    break;

  case 157:

    {(yyval.VariableDeclarationTypeListVal) = (yyvsp[(1) - (2)].VariableDeclarationTypeListVal);
	   (yyval.VariableDeclarationTypeListVal)->push_back((yyvsp[(2) - (2)].VariableDeclarationTypeVal));;}
    break;

  case 158:

    {(yyval.VectorTypeVal) = new VectorType((yyvsp[(2) - (5)].XmlIDVal), (yyvsp[(3) - (5)].XmlDecimalVal), (yyvsp[(4) - (5)].XmlDecimalVal), (yyvsp[(5) - (5)].XmlDecimalVal));;}
    break;

  case 159:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 160:

    {yyReadData = 1;;}
    break;

  case 161:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 162:

    {yyReadData = 1;;}
    break;

  case 163:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 164:

    {(yyval.VectorTypeVal) = (yyvsp[(2) - (3)].VectorTypeVal);;}
    break;

  case 165:

    {yyReadData = 1;;}
    break;

  case 166:

    {(yyval.XmlDecimalVal) = (yyvsp[(4) - (5)].XmlDecimalVal);;}
    break;

  case 167:

    {(yyval.AndTypeVal) = new AndType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].BooleanExpressionTypeVal));
	   (yyval.AndTypeVal)->printTypp = true;
	  ;}
    break;

  case 168:

    {(yyval.AttachEndEffectorTypeVal) = new AttachEndEffectorType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));
	   (yyval.AttachEndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 169:

    {(yyval.CreateKitTypeVal) = new CreateKitType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.CreateKitTypeVal)->printTypp = true;
	  ;}
    break;

  case 170:

    {(yyval.DecimalTypeVal) = new DecimalType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlDecimalVal));
	   (yyval.DecimalTypeVal)->printTypp = true;
	  ;}
    break;

  case 171:

    {(yyval.DetachEndEffectorTypeVal) = new DetachEndEffectorType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].XmlNMTOKENVal));
	   (yyval.DetachEndEffectorTypeVal)->printTypp = true;
	  ;}
    break;

  case 172:

    {(yyval.DivTypeVal) = new DivType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.DivTypeVal)->printTypp = true;
	  ;}
    break;

  case 173:

    {(yyval.EqualTypeVal) = new EqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.EqualTypeVal)->printTypp = true;
	  ;}
    break;

  case 174:

    {(yyval.FalseTypeVal) = new FalseType((yyvsp[(3) - (3)].XmlIDVal));
	   (yyval.FalseTypeVal)->printTypp = true;
	  ;}
    break;

  case 175:

    {(yyval.GreaterOrEqualTypeVal) = new GreaterOrEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.GreaterOrEqualTypeVal)->printTypp = true;
	  ;}
    break;

  case 176:

    {(yyval.GreaterTypeVal) = new GreaterType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.GreaterTypeVal)->printTypp = true;
	  ;}
    break;

  case 177:

    {(yyval.IfActionGroupTypeVal) = new IfActionGroupType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].TestAndStepTypeVal), (yyvsp[(5) - (6)].TestAndStepTypeListVal), (yyvsp[(6) - (6)].ElseTypeVal));
	   (yyval.IfActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 178:

    {(yyval.LessOrEqualTypeVal) = new LessOrEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.LessOrEqualTypeVal)->printTypp = true;
	  ;}
    break;

  case 179:

    {(yyval.LessTypeVal) = new LessType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.LessTypeVal)->printTypp = true;
	  ;}
    break;

  case 180:

    {(yyval.LocatePartTypeVal) = new LocatePartType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlNMTOKENVal));
	   (yyval.LocatePartTypeVal)->printTypp = true;
	  ;}
    break;

  case 181:

    {(yyval.MinusTypeVal) = new MinusType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.MinusTypeVal)->printTypp = true;
	  ;}
    break;

  case 182:

    {(yyval.ModTypeVal) = new ModType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.ModTypeVal)->printTypp = true;
	  ;}
    break;

  case 183:

    {(yyval.NegateTypeVal) = new NegateType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].ArithmeticExpressionTypeVal));
	   (yyval.NegateTypeVal)->printTypp = true;
	  ;}
    break;

  case 184:

    {(yyval.NotEqualTypeVal) = new NotEqualType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.NotEqualTypeVal)->printTypp = true;
	  ;}
    break;

  case 185:

    {(yyval.NotTypeVal) = new NotType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].BooleanExpressionTypeVal));
	   (yyval.NotTypeVal)->printTypp = true;
	  ;}
    break;

  case 186:

    {(yyval.OneOfActionGroupTypeVal) = new OneOfActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].NumberedPlanElementTypeListVal));
	   (yyval.OneOfActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 187:

    {(yyval.OrTypeVal) = new OrType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].BooleanExpressionTypeVal));
	   (yyval.OrTypeVal)->printTypp = true;
	  ;}
    break;

  case 188:

    {(yyval.OrderedActionGroupTypeVal) = new OrderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].NumberedPlanElementTypeListVal));
	   (yyval.OrderedActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 189:

    {(yyval.PartiallyOrderedActionGroupTypeVal) = new PartiallyOrderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].StepWithPredecessorsTypeListVal));
	   (yyval.PartiallyOrderedActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 190:

    {(yyval.PlusTypeVal) = new PlusType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.PlusTypeVal)->printTypp = true;
	  ;}
    break;

  case 191:

    {(yyval.PoseLocationInTypeVal) = new PoseLocationInType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].PointTypeVal), (yyvsp[(6) - (9)].VectorTypeVal), (yyvsp[(7) - (9)].VectorTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 192:

    {(yyval.PoseLocationOnTypeVal) = new PoseLocationOnType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].PointTypeVal), (yyvsp[(6) - (9)].VectorTypeVal), (yyvsp[(7) - (9)].VectorTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].PositiveDecimalTypeVal));
	   (yyval.PoseLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 193:

    {(yyval.PoseOnlyLocationTypeVal) = new PoseOnlyLocationType((yyvsp[(3) - (9)].XmlIDVal), (yyvsp[(4) - (9)].XmlNMTOKENVal), (yyvsp[(5) - (9)].PointTypeVal), (yyvsp[(6) - (9)].VectorTypeVal), (yyvsp[(7) - (9)].VectorTypeVal), (yyvsp[(8) - (9)].PositiveDecimalTypeVal), (yyvsp[(9) - (9)].PositiveDecimalTypeVal));
	   (yyval.PoseOnlyLocationTypeVal)->printTypp = true;
	  ;}
    break;

  case 194:

    {(yyval.PropValTypeVal) = new PropValType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.PropValTypeVal)->printTypp = true;
	  ;}
    break;

  case 195:

    {(yyval.PutKitTrayTypeVal) = new PutKitTrayType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutKitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 196:

    {(yyval.PutKitTypeVal) = new PutKitType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutKitTypeVal)->printTypp = true;
	  ;}
    break;

  case 197:

    {(yyval.PutPartTypeVal) = new PutPartType((yyvsp[(3) - (6)].XmlIDVal), (yyvsp[(4) - (6)].XmlNMTOKENVal), (yyvsp[(5) - (6)].XmlNMTOKENVal), (yyvsp[(6) - (6)].PhysicalLocationTypeVal));
	   (yyval.PutPartTypeVal)->printTypp = true;
	  ;}
    break;

  case 198:

    {(yyval.RelativeLocationInTypeVal) = new RelativeLocationInType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationInTypeVal)->printTypp = true;
	  ;}
    break;

  case 199:

    {(yyval.RelativeLocationOnTypeVal) = new RelativeLocationOnType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlStringVal));
	   (yyval.RelativeLocationOnTypeVal)->printTypp = true;
	  ;}
    break;

  case 200:

    {(yyval.SomeOfActionGroupTypeVal) = new SomeOfActionGroupType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].PlanElementBaseTypeListVal), (yyvsp[(5) - (5)].XmlPositiveIntegerVal));
	   (yyval.SomeOfActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 201:

    {(yyval.TakeKitTrayTypeVal) = new TakeKitTrayType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakeKitTrayTypeVal)->printTypp = true;
	  ;}
    break;

  case 202:

    {(yyval.TakeKitTypeVal) = new TakeKitType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakeKitTypeVal)->printTypp = true;
	  ;}
    break;

  case 203:

    {(yyval.TakePartTypeVal) = new TakePartType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlNMTOKENVal), (yyvsp[(5) - (5)].XmlNMTOKENVal));
	   (yyval.TakePartTypeVal)->printTypp = true;
	  ;}
    break;

  case 204:

    {(yyval.TimesTypeVal) = new TimesType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].ArithmeticExpressionTypeVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.TimesTypeVal)->printTypp = true;
	  ;}
    break;

  case 205:

    {(yyval.TrueTypeVal) = new TrueType((yyvsp[(3) - (3)].XmlIDVal));
	   (yyval.TrueTypeVal)->printTypp = true;
	  ;}
    break;

  case 206:

    {(yyval.UnorderedActionGroupTypeVal) = new UnorderedActionGroupType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].PlanElementBaseTypeListVal));
	   (yyval.UnorderedActionGroupTypeVal)->printTypp = true;
	  ;}
    break;

  case 207:

    {(yyval.VarSetTypeVal) = new VarSetType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].XmlIDREFVal), (yyvsp[(5) - (5)].ArithmeticExpressionTypeVal));
	   (yyval.VarSetTypeVal)->printTypp = true;
	  ;}
    break;

  case 208:

    {(yyval.VarValTypeVal) = new VarValType((yyvsp[(3) - (4)].XmlIDVal), (yyvsp[(4) - (4)].XmlIDREFVal));
	   (yyval.VarValTypeVal)->printTypp = true;
	  ;}
    break;

  case 209:

    {(yyval.WhileActionGroupTypeVal) = new WhileActionGroupType((yyvsp[(3) - (5)].XmlIDVal), (yyvsp[(4) - (5)].BooleanExpressionTypeVal), (yyvsp[(5) - (5)].PlanElementBaseTypeVal));
	   (yyval.WhileActionGroupTypeVal)->printTypp = true;
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

