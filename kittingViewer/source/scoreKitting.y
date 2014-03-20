%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#include "scoreKittingClasses.hh"   // for scoreKitting classes

#define YYERROR_VERBOSE
#define YYDEBUG 1

ScoreKittingFile * scoreKittingTree; // the parse tree

extern int yysclex();
int yyscReadData = 0;
int yyscReadDataList = 0;

int yyscerror(const char * s);

%}

%union {
  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForScoreKitting *          XmlHeaderForScoreKittingVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlBoolean *                        XmlBooleanVal;
  XmlDouble *                         XmlDoubleVal;
  XmlUnsignedInt *                    XmlUnsignedIntVal;

  ScoreKittingFile *                  ScoreKittingFileVal;

  factorValueOptType *                factorValueOptTypeVal;
  factorValueReqType *                factorValueReqTypeVal;
  nonNegativeReal *                   nonNegativeRealVal;
  scoreKittingType *                  scoreKittingTypeVal;
  taperSideType *                     taperSideTypeVal;
  valueFunctionType *                 valueFunctionTypeVal;
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForScoreKittingVal>   y_XmlHeaderForScoreKitting
%type <XmlVersionVal>                 y_XmlVersion
%type <ScoreKittingFileVal>           y_ScoreKittingFile
%type <XmlBooleanVal>                 y_XmlBoolean
%type <XmlDoubleVal>                  y_XmlDouble
%type <XmlUnsignedIntVal>             y_XmlUnsignedInt

%type <XmlDoubleVal>                  y_bestValue_XmlDouble
%type <factorValueOptTypeVal>         y_commandExecution_factorValueOptType
%type <factorValueOptTypeVal>         y_distance_factorValueOptType
%type <factorValueOptTypeVal>         y_factorValueOptType
%type <factorValueReqTypeVal>         y_factorValueReqType
%type <XmlBooleanVal>                 y_isAdditive_XmlBoolean
%type <factorValueOptTypeVal>         y_rightStuff_factorValueOptType
%type <scoreKittingTypeVal>           y_scoreKittingType
%type <taperSideTypeVal>              y_taperSide_taperSideType
%type <nonNegativeRealVal>            y_taper_nonNegativeReal
%type <factorValueOptTypeVal>         y_time_factorValueOptType
%type <factorValueReqTypeVal>         y_uselessCommands_factorValueReqType
%type <valueFunctionTypeVal>          y_valueFunctionType
%type <valueFunctionTypeVal>          y_valueFunction_valueFunctionType
%type <valueFunctionTypeVal>          y_valueFunction_valueFunctionType_0
%type <XmlUnsignedIntVal>             y_weight_XmlUnsignedInt
%type <nonNegativeRealVal>            y_width_nonNegativeReal

%token <iVal> BAD
%token <sVal> DATASTRING
%token <iVal> ENCODING
%token <iVal> ENDITEM
%token <iVal> ENDVERSION
%token <sVal> SCHEMALOCATION
%token <iVal> STARTVERSION
%token <sVal> TERMINALSTRING
%token <iVal> XMLNSPREFIX
%token <iVal> XMLNSTARGET
%token <iVal> XMLVERSION

%token <iVal> BESTVALUEEND
%token <iVal> BESTVALUESTART
%token <iVal> COMMANDEXECUTIONEND
%token <iVal> COMMANDEXECUTIONSTART
%token <iVal> DISTANCEEND
%token <iVal> DISTANCESTART
%token <iVal> ISADDITIVEEND
%token <iVal> ISADDITIVESTART
%token <iVal> RIGHTSTUFFEND
%token <iVal> RIGHTSTUFFSTART
%token <iVal> SCOREKITTINGEND
%token <iVal> SCOREKITTINGSTART
%token <iVal> TAPERSIDEEND
%token <iVal> TAPERSIDESTART
%token <iVal> TAPEREND
%token <iVal> TAPERSTART
%token <iVal> TIMEEND
%token <iVal> TIMESTART
%token <iVal> USELESSCOMMANDSEND
%token <iVal> USELESSCOMMANDSSTART
%token <iVal> VALUEFUNCTIONEND
%token <iVal> VALUEFUNCTIONSTART
%token <iVal> WEIGHTEND
%token <iVal> WEIGHTSTART
%token <iVal> WIDTHEND
%token <iVal> WIDTHSTART


%token <iVal> FACTORVALUEOPTTYPEDECL
%token <iVal> FACTORVALUEREQTYPEDECL

%%

y_ScoreKittingFile :
	  y_XmlVersion SCOREKITTINGSTART y_XmlHeaderForScoreKitting
	  y_scoreKittingType SCOREKITTINGEND
	  {$$ = new ScoreKittingFile($1, $3, $4);
	   scoreKittingTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForScoreKitting:
	  XMLNSTARGET XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForScoreKitting($3);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2, true);
	    if (strncmp("urn:Kitting ", $2, 12))
	      {
		fprintf(stderr,
	           "wrong targetNamespace in schema location %s\n", $2);
		exit(1);
	      }
	  }
	;

y_XmlBoolean :
	  DATASTRING
	  {$$ = new XmlBoolean($1);
	   if ($$->bad)
	     yyscerror("bad XmlBoolean");
	  }
	;

y_XmlDouble :
	  DATASTRING
	  {$$ = new XmlDouble($1);
	   if ($$->bad)
	     yyscerror("bad XmlDouble");
	  }
	;

y_XmlUnsignedInt :
	  DATASTRING
	  {$$ = new XmlUnsignedInt($1);
	   if ($$->bad)
	     yyscerror("bad XmlUnsignedInt");
	  }
	;

y_XmlVersion :
	  STARTVERSION XMLVERSION TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(false);
	   if (strcmp($3, "1.0"))
	     yyscerror("version number must be 1.0");
	  }
	| STARTVERSION XMLVERSION TERMINALSTRING
	  ENCODING TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(true);
	   if (strcmp($3, "1.0"))
	     yyscerror("version number must be 1.0");
	   else if (strcmp($5, "UTF-8"))
	     yyscerror("encoding must be UTF-8");
	  }
	;

y_bestValue_XmlDouble :
	  BESTVALUESTART ENDITEM {yyscReadData = 1;} y_XmlDouble
	  BESTVALUEEND
	  {$$ = $4;}
	;

y_commandExecution_factorValueOptType :
	  COMMANDEXECUTIONSTART y_factorValueOptType COMMANDEXECUTIONEND
	  {$$ = $2;}
	;

y_distance_factorValueOptType :
	  DISTANCESTART y_factorValueOptType DISTANCEEND
	  {$$ = $2;}
	;

y_factorValueOptType :
	   ENDITEM y_isAdditive_XmlBoolean y_weight_XmlUnsignedInt
	  y_valueFunction_valueFunctionType_0
	  {$$ = new factorValueOptType($2, $3, $4);}
	;

y_factorValueReqType :
	   ENDITEM y_isAdditive_XmlBoolean y_weight_XmlUnsignedInt
	  y_valueFunction_valueFunctionType
	  {$$ = new factorValueReqType($2, $3, $4);}
	;

y_isAdditive_XmlBoolean :
	  ISADDITIVESTART ENDITEM {yyscReadData = 1;} y_XmlBoolean
	  ISADDITIVEEND
	  {$$ = $4;}
	;

y_rightStuff_factorValueOptType :
	  RIGHTSTUFFSTART y_factorValueOptType RIGHTSTUFFEND
	  {$$ = $2;}
	;

y_scoreKittingType :
	  ENDITEM y_rightStuff_factorValueOptType
	  y_commandExecution_factorValueOptType
	  y_distance_factorValueOptType y_time_factorValueOptType
	  y_uselessCommands_factorValueReqType
	  {$$ = new scoreKittingType($2, $3, $4, $5, $6);}
	;

y_taperSide_taperSideType :
	  TAPERSIDESTART ENDITEM {yyscReadData = 1;} DATASTRING
	  TAPERSIDEEND
	  {$$ = new taperSideType($4);
	   if ($$->bad)
	     yyscerror("bad taperSide value");
	  }
	;

y_taper_nonNegativeReal :
	  TAPERSTART ENDITEM {yyscReadData = 1;} DATASTRING TAPEREND
	  {$$ = new nonNegativeReal($4);
	   if ($$->bad)
	     yyscerror("bad taper value");
	  }
	;

y_time_factorValueOptType :
	  TIMESTART y_factorValueOptType TIMEEND
	  {$$ = $2;}
	;

y_uselessCommands_factorValueReqType :
	  USELESSCOMMANDSSTART y_factorValueReqType USELESSCOMMANDSEND
	  {$$ = $2;}
	;

y_valueFunctionType :
	  ENDITEM y_bestValue_XmlDouble y_width_nonNegativeReal
	  y_taper_nonNegativeReal y_taperSide_taperSideType
	  {$$ = new valueFunctionType($2, $3, $4, $5);}
	;

y_valueFunction_valueFunctionType :
	  VALUEFUNCTIONSTART y_valueFunctionType VALUEFUNCTIONEND
	  {$$ = $2;}
	;

y_valueFunction_valueFunctionType_0 :
	  /* empty */
	  {$$ = 0;}
	| VALUEFUNCTIONSTART y_valueFunctionType VALUEFUNCTIONEND
	  {$$ = $2;}
	;

y_weight_XmlUnsignedInt :
	  WEIGHTSTART ENDITEM {yyscReadData = 1;} y_XmlUnsignedInt
	  WEIGHTEND
	  {$$ = $4;}
	;

y_width_nonNegativeReal :
	  WIDTHSTART ENDITEM {yyscReadData = 1;} DATASTRING WIDTHEND
	  {$$ = new nonNegativeReal($4);
	   if ($$->bad)
	     yyscerror("bad width value");
	  }
	;

%%

/*********************************************************************/

/* yyscerror

Returned Value: int (0)

Called By: yyscparse

This prints whatever string the parser provides.

*/

int yyscerror(      /* ARGUMENTS       */
 const char * s)  /* string to print */
{
  fflush(stdout);
  fprintf(stderr, "\n%s\n", s);
  exit(1);
  return 0;
}

/*********************************************************************/
