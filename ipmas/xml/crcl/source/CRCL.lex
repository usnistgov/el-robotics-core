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
#include "owlCRCLClasses.hh"
#else
#include "CRCLClasses.hh"
#endif
#include "CRCLYACC.hh"    // for tokens, yylval, etc.

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
"xsi:noNamespaceSchemaLocation"{W}"=" {ECH; return SCHEMALOCATION;}
"xml"[ \t]+"version"{W}"="    {ECH; return XMLVERSION;}

"</"{W}"Acceleration"{W}">"   {ECH; return ACCELERATIONEND;}
"<"{W}"Acceleration"          {ECH; return ACCELERATIONSTART;}
"</"{W}"CRCLProgram"{W}">"    {ECH; return CRCLPROGRAMEND;}
"<"{W}"CRCLProgram"           {ECH; return CRCLPROGRAMSTART;}
"</"{W}"CloseGripper"{W}">"   {ECH; return CLOSEGRIPPEREND;}
"<"{W}"CloseGripper"          {ECH; return CLOSEGRIPPERSTART;}
"</"{W}"CloseToolChanger"{W}">" {ECH; return CLOSETOOLCHANGEREND;}
"<"{W}"CloseToolChanger"      {ECH; return CLOSETOOLCHANGERSTART;}
"</"{W}"DwellTime"{W}">"      {ECH; return DWELLTIMEEND;}
"<"{W}"DwellTime"             {ECH; return DWELLTIMESTART;}
"</"{W}"Dwell"{W}">"          {ECH; return DWELLEND;}
"<"{W}"Dwell"                 {ECH; return DWELLSTART;}
"</"{W}"EndCanon"{W}">"       {ECH; return ENDCANONEND;}
"<"{W}"EndCanon"              {ECH; return ENDCANONSTART;}
"</"{W}"EndPosition"{W}">"    {ECH; return ENDPOSITIONEND;}
"<"{W}"EndPosition"           {ECH; return ENDPOSITIONSTART;}
"</"{W}"I"{W}">"              {ECH; return IEND;}
"<"{W}"I"                     {ECH; return ISTART;}
"</"{W}"InitCanon"{W}">"      {ECH; return INITCANONEND;}
"<"{W}"InitCanon"             {ECH; return INITCANONSTART;}
"</"{W}"J"{W}">"              {ECH; return JEND;}
"<"{W}"J"                     {ECH; return JSTART;}
"</"{W}"K"{W}">"              {ECH; return KEND;}
"<"{W}"K"                     {ECH; return KSTART;}
"</"{W}"Message"{W}">"        {ECH; return MESSAGEEND;}
"<"{W}"Message"               {ECH; return MESSAGESTART;}
"</"{W}"MoveStraightTo"{W}">" {ECH; return MOVESTRAIGHTTOEND;}
"<"{W}"MoveStraightTo"        {ECH; return MOVESTRAIGHTTOSTART;}
"</"{W}"MoveThroughTo"{W}">"  {ECH; return MOVETHROUGHTOEND;}
"<"{W}"MoveThroughTo"         {ECH; return MOVETHROUGHTOSTART;}
"</"{W}"MoveTo"{W}">"         {ECH; return MOVETOEND;}
"<"{W}"MoveTo"                {ECH; return MOVETOSTART;}
"</"{W}"NumPositions"{W}">"   {ECH; return NUMPOSITIONSEND;}
"<"{W}"NumPositions"          {ECH; return NUMPOSITIONSSTART;}
"</"{W}"OpenGripper"{W}">"    {ECH; return OPENGRIPPEREND;}
"<"{W}"OpenGripper"           {ECH; return OPENGRIPPERSTART;}
"</"{W}"OpenToolChanger"{W}">" {ECH; return OPENTOOLCHANGEREND;}
"<"{W}"OpenToolChanger"       {ECH; return OPENTOOLCHANGERSTART;}
"</"{W}"Percent"{W}">"        {ECH; return PERCENTEND;}
"<"{W}"Percent"               {ECH; return PERCENTSTART;}
"</"{W}"Point"{W}">"          {ECH; return POINTEND;}
"<"{W}"Point"                 {ECH; return POINTSTART;}
"</"{W}"SetAbsoluteAcceleration"{W}">" {ECH; return SETABSOLUTEACCELERATIONEND;}
"<"{W}"SetAbsoluteAcceleration" {ECH; return SETABSOLUTEACCELERATIONSTART;}
"</"{W}"SetAbsoluteSpeed"{W}">" {ECH; return SETABSOLUTESPEEDEND;}
"<"{W}"SetAbsoluteSpeed"      {ECH; return SETABSOLUTESPEEDSTART;}
"</"{W}"SetAngleUnits"{W}">"  {ECH; return SETANGLEUNITSEND;}
"<"{W}"SetAngleUnits"         {ECH; return SETANGLEUNITSSTART;}
"</"{W}"SetEndAngleTolerance"{W}">" {ECH; return SETENDANGLETOLERANCEEND;}
"<"{W}"SetEndAngleTolerance"  {ECH; return SETENDANGLETOLERANCESTART;}
"</"{W}"SetEndPointTolerance"{W}">" {ECH; return SETENDPOINTTOLERANCEEND;}
"<"{W}"SetEndPointTolerance"  {ECH; return SETENDPOINTTOLERANCESTART;}
"</"{W}"SetIntermediatePointTolerance"{W}">" {ECH; return SETINTERMEDIATEPOINTTOLERANCEEND;}
"<"{W}"SetIntermediatePointTolerance" {ECH; return SETINTERMEDIATEPOINTTOLERANCESTART;}
"</"{W}"SetLengthUnits"{W}">" {ECH; return SETLENGTHUNITSEND;}
"<"{W}"SetLengthUnits"        {ECH; return SETLENGTHUNITSSTART;}
"</"{W}"SetRelativeAcceleration"{W}">" {ECH; return SETRELATIVEACCELERATIONEND;}
"<"{W}"SetRelativeAcceleration" {ECH; return SETRELATIVEACCELERATIONSTART;}
"</"{W}"SetRelativeSpeed"{W}">" {ECH; return SETRELATIVESPEEDEND;}
"<"{W}"SetRelativeSpeed"      {ECH; return SETRELATIVESPEEDSTART;}
"</"{W}"Speed"{W}">"          {ECH; return SPEEDEND;}
"<"{W}"Speed"                 {ECH; return SPEEDSTART;}
"</"{W}"Tolerance"{W}">"      {ECH; return TOLERANCEEND;}
"<"{W}"Tolerance"             {ECH; return TOLERANCESTART;}
"</"{W}"UnitName"{W}">"       {ECH; return UNITNAMEEND;}
"<"{W}"UnitName"              {ECH; return UNITNAMESTART;}
"</"{W}"Waypoint"{W}">"       {ECH; return WAYPOINTEND;}
"<"{W}"Waypoint"              {ECH; return WAYPOINTSTART;}
"</"{W}"XAxis"{W}">"          {ECH; return XAXISEND;}
"<"{W}"XAxis"                 {ECH; return XAXISSTART;}
"</"{W}"X"{W}">"              {ECH; return XEND;}
"<"{W}"X"                     {ECH; return XSTART;}
"</"{W}"Y"{W}">"              {ECH; return YEND;}
"<"{W}"Y"                     {ECH; return YSTART;}
"</"{W}"ZAxis"{W}">"          {ECH; return ZAXISEND;}
"<"{W}"ZAxis"                 {ECH; return ZAXISSTART;}
"</"{W}"Z"{W}">"              {ECH; return ZEND;}
"<"{W}"Z"                     {ECH; return ZSTART;}

"xmlns:xsi"{W}"="{W}"\"http://www.w3.org/2001/XMLSchema-instance\"" {ECH;
                                           return XMLNSPREFIX;}

">"                           {ECH; return ENDITEM;}
"/>"                          {ECH; return ENDWHOLEITEM;}

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
