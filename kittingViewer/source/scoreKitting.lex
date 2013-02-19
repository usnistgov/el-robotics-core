%{

/*

This ignores white space outside of meaningful strings of characters.

*/

#ifdef WIN32
#include <io.h>
#define strdup _strdup
#define fileno _fileno
#define isatty _isatty
#define YY_NO_UNISTD_H
#endif
#include <string.h>          // for strdup
#include "scoreKittingClasses.hh" // for classes referenced in scoreKittingYACC.hh
#include "scoreKittingYACC.hh"    // for tokens, yylval, etc.

#ifndef NO_ECHO
#define ECHO_IT 1
#else
#define ECHO_IT 0
#endif
#define ECH if (ECHO_IT) ECHO

extern int yyscReadData;
extern int yyscReadDataList;

%}

W [ \t\n\r]*
%x COMMENT
%x DATA
%x DATALIST

%%

  if (yyscReadData)
    {
      BEGIN(DATA);
      yyscReadData = 0;
    }
  else if (yyscReadDataList)
    {
      BEGIN(DATALIST);
    }

{W}"<!--"               { ECH; BEGIN(COMMENT); /* delete comment start */}
<COMMENT>.              { ECH;  /* delete comment middle */ }
<COMMENT>\n             { ECH;  /* delete comment middle */ }
<COMMENT>"-->"          { ECH; BEGIN(INITIAL); /* delete comment end */ }

<DATA>[^<]*             { ECH; BEGIN(INITIAL);
                          yysclval.sVal = strdup(yysctext);
                          return DATASTRING;
                        }

<DATALIST>[^< \t]*      { ECH;
                          yysclval.sVal = strdup(yysctext);
                          return DATASTRING;
                        }
<DATALIST>{W}           { ECH;}
<DATALIST>"<"           { yyscReadDataList = 0;
                          unput('<');
			  BEGIN(INITIAL);}

"encoding"{W}"="              {ECH; return ENCODING;}
"?>"                          {ECH; return ENDVERSION;}
"<?"                          {ECH; return STARTVERSION;}
"xsi:schemaLocation"{W}"="    {ECH; return SCHEMALOCATION;}
"xml"[ \t]+"version"{W}"="    {ECH; return XMLVERSION;}

"</"{W}"bestValue"{W}">"      {ECH; return BESTVALUEEND;}
"<"{W}"bestValue"             {ECH; return BESTVALUESTART;}
"</"{W}"commandExecution"{W}">" {ECH; return COMMANDEXECUTIONEND;}
"<"{W}"commandExecution"      {ECH; return COMMANDEXECUTIONSTART;}
"</"{W}"distance"{W}">"       {ECH; return DISTANCEEND;}
"<"{W}"distance"              {ECH; return DISTANCESTART;}
"</"{W}"isAdditive"{W}">"     {ECH; return ISADDITIVEEND;}
"<"{W}"isAdditive"            {ECH; return ISADDITIVESTART;}
"</"{W}"rightStuff"{W}">"     {ECH; return RIGHTSTUFFEND;}
"<"{W}"rightStuff"            {ECH; return RIGHTSTUFFSTART;}
"</"{W}"scoreKitting"{W}">"   {ECH; return SCOREKITTINGEND;}
"<"{W}"scoreKitting"          {ECH; return SCOREKITTINGSTART;}
"</"{W}"taperSide"{W}">"      {ECH; return TAPERSIDEEND;}
"<"{W}"taperSide"             {ECH; return TAPERSIDESTART;}
"</"{W}"taper"{W}">"          {ECH; return TAPEREND;}
"<"{W}"taper"                 {ECH; return TAPERSTART;}
"</"{W}"time"{W}">"           {ECH; return TIMEEND;}
"<"{W}"time"                  {ECH; return TIMESTART;}
"</"{W}"uselessCommands"{W}">" {ECH; return USELESSCOMMANDSEND;}
"<"{W}"uselessCommands"       {ECH; return USELESSCOMMANDSSTART;}
"</"{W}"valueFunction"{W}">"  {ECH; return VALUEFUNCTIONEND;}
"<"{W}"valueFunction"         {ECH; return VALUEFUNCTIONSTART;}
"</"{W}"weight"{W}">"         {ECH; return WEIGHTEND;}
"<"{W}"weight"                {ECH; return WEIGHTSTART;}
"</"{W}"width"{W}">"          {ECH; return WIDTHEND;}
"<"{W}"width"                 {ECH; return WIDTHSTART;}

"xmlns"{W}"="{W}"\"urn:Kitting\"" {ECH; return XMLNSTARGET;}

"xmlns:xsi"{W}"="{W}"\"http://www.w3.org/2001/XMLSchema-instance\"" {ECH;
                                           return XMLNSPREFIX;}

">"                           {ECH; return ENDITEM;}

\"[^\"]+\"                 {ECH;
                            int first;
                            int n;
                            for (first = 0; yysctext[first] != '"'; first++);
                            first++;
                            for (n = first; yysctext[n] != '"'; n++);
                            yysctext[n] = 0;
                            yysclval.sVal = strdup(yysctext + first);
                            return TERMINALSTRING;
                           }

{W}                        {ECH;}

.                          {ECH; return BAD;}

%%

int yyscwrap()
{
  return 1;
}
