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
#ifdef OWL
#include "owlGeometrySchema3Classes.hh"
#else
#include "geometrySchema3Classes.hh"
#endif
#include "geometrySchema3YACC.hh"    // for tokens, yylval, etc.

#ifndef NO_ECHO
#define ECHO_IT 1
#else
#define ECHO_IT 0
#endif
#define ECH if (ECHO_IT) ECHO

extern int yyReadData;
extern int yyReadDataList;

%}

W [ \t\n\r]*
%x COMMENT
%x DATA
%x DATALIST

%%

  if (yyReadData)
    {
      BEGIN(DATA);
      yyReadData = 0;
    }
  else if (yyReadDataList)
    {
      BEGIN(DATALIST);
    }

{W}"<!--"               { ECH; BEGIN(COMMENT); /* delete comment start */}
<COMMENT>.              { ECH;  /* delete comment middle */ }
<COMMENT>\n             { ECH;  /* delete comment middle */ }
<COMMENT>"-->"          { ECH; BEGIN(INITIAL); /* delete comment end */ }

<DATA>[^<]*             { ECH; BEGIN(INITIAL);
                          yylval.sVal = strdup(yytext);
                          return DATASTRING;
                        }

<DATALIST>[^< \t]*      { ECH;
                          yylval.sVal = strdup(yytext);
                          return DATASTRING;
                        }
<DATALIST>{W}           { ECH;}
<DATALIST>"<"           { yyReadDataList = 0;
                          unput('<');
			  BEGIN(INITIAL);}

"encoding"{W}"="              {ECH; return ENCODING;}
"?>"                          {ECH; return ENDVERSION;}
"<?"                          {ECH; return STARTVERSION;}
"xsi:schemaLocation"{W}"="    {ECH; return SCHEMALOCATION;}
"xml"[ \t]+"version"{W}"="    {ECH; return XMLVERSION;}

"</"{W}"Center"{W}">"         {ECH; return CENTEREND;}
"<"{W}"Center"                {ECH; return CENTERSTART;}
"</"{W}"CircleInstance"{W}">" {ECH; return CIRCLEINSTANCEEND;}
"<"{W}"CircleInstance"        {ECH; return CIRCLEINSTANCESTART;}
"</"{W}"CirclesAndSpheres"{W}">" {ECH; return CIRCLESANDSPHERESEND;}
"<"{W}"CirclesAndSpheres"     {ECH; return CIRCLESANDSPHERESSTART;}
"</"{W}"I"{W}">"              {ECH; return IEND;}
"<"{W}"I"                     {ECH; return ISTART;}
"</"{W}"J"{W}">"              {ECH; return JEND;}
"<"{W}"J"                     {ECH; return JSTART;}
"</"{W}"K"{W}">"              {ECH; return KEND;}
"<"{W}"K"                     {ECH; return KSTART;}
"</"{W}"Name"{W}">"           {ECH; return NAMEEND;}
"<"{W}"Name"                  {ECH; return NAMESTART;}
"</"{W}"Normal"{W}">"         {ECH; return NORMALEND;}
"<"{W}"Normal"                {ECH; return NORMALSTART;}
"</"{W}"Radius"{W}">"         {ECH; return RADIUSEND;}
"<"{W}"Radius"                {ECH; return RADIUSSTART;}
"</"{W}"SphereInstance"{W}">" {ECH; return SPHEREINSTANCEEND;}
"<"{W}"SphereInstance"        {ECH; return SPHEREINSTANCESTART;}
"</"{W}"X"{W}">"              {ECH; return XEND;}
"<"{W}"X"                     {ECH; return XSTART;}
"</"{W}"Y"{W}">"              {ECH; return YEND;}
"<"{W}"Y"                     {ECH; return YSTART;}
"</"{W}"Z"{W}">"              {ECH; return ZEND;}
"<"{W}"Z"                     {ECH; return ZSTART;}

"xmlns"{W}"="{W}"\"urn:geometry\"" {ECH; return XMLNSTARGET;}

"xmlns:xsi"{W}"="{W}"\"http://www.w3.org/2001/XMLSchema-instance\"" {ECH;
                                           return XMLNSPREFIX;}

">"                           {ECH; return ENDITEM;}

\"[^\"]+\"                 {ECH;
                            int first;
                            int n;
                            for (first = 0; yytext[first] != '"'; first++);
                            first++;
                            for (n = first; yytext[n] != '"'; n++);
                            yytext[n] = 0;
                            yylval.sVal = strdup(yytext + first);
                            return TERMINALSTRING;
                           }

{W}                        {ECH;}

.                          {ECH; return BAD;}

%%

int yywrap()
{
  return 1;
}
