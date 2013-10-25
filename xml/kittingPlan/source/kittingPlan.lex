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
#include "owlKittingPlanClasses.hh"
#else
#include "kittingPlanClasses.hh" // for classes referenced in kittingPlanYACC.hh
#endif
#include "kittingPlanYACC.hh"    // for tokens, yylval, etc.

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

"</"{W}"A1"{W}">"             {ECH; return A1END;}
"<"{W}"A1"                    {ECH; return A1START;}
"</"{W}"A2"{W}">"             {ECH; return A2END;}
"<"{W}"A2"                    {ECH; return A2START;}
"</"{W}"A"{W}">"              {ECH; return AEND;}
"<"{W}"A"                     {ECH; return ASTART;}
"</"{W}"B1"{W}">"             {ECH; return B1END;}
"<"{W}"B1"                    {ECH; return B1START;}
"</"{W}"B2"{W}">"             {ECH; return B2END;}
"<"{W}"B2"                    {ECH; return B2START;}
"</"{W}"B"{W}">"              {ECH; return BEND;}
"<"{W}"B"                     {ECH; return BSTART;}
"</"{W}"Description"{W}">"    {ECH; return DESCRIPTIONEND;}
"<"{W}"Description"           {ECH; return DESCRIPTIONSTART;}
"</"{W}"ElseIf"{W}">"         {ECH; return ELSEIFEND;}
"<"{W}"ElseIf"                {ECH; return ELSEIFSTART;}
"</"{W}"Else"{W}">"           {ECH; return ELSEEND;}
"<"{W}"Else"                  {ECH; return ELSESTART;}
"</"{W}"EndEffectorHolderName"{W}">" {ECH; return ENDEFFECTORHOLDERNAMEEND;}
"<"{W}"EndEffectorHolderName" {ECH; return ENDEFFECTORHOLDERNAMESTART;}
"</"{W}"EndEffectorName"{W}">" {ECH; return ENDEFFECTORNAMEEND;}
"<"{W}"EndEffectorName"       {ECH; return ENDEFFECTORNAMESTART;}
"</"{W}"I"{W}">"              {ECH; return IEND;}
"<"{W}"I"                     {ECH; return ISTART;}
"</"{W}"If"{W}">"             {ECH; return IFEND;}
"<"{W}"If"                    {ECH; return IFSTART;}
"</"{W}"J"{W}">"              {ECH; return JEND;}
"<"{W}"J"                     {ECH; return JSTART;}
"</"{W}"K"{W}">"              {ECH; return KEND;}
"<"{W}"K"                     {ECH; return KSTART;}
"</"{W}"KitName"{W}">"        {ECH; return KITNAMEEND;}
"<"{W}"KitName"               {ECH; return KITNAMESTART;}
"</"{W}"KitTrayName"{W}">"    {ECH; return KITTRAYNAMEEND;}
"<"{W}"KitTrayName"           {ECH; return KITTRAYNAMESTART;}
"</"{W}"KittingPlan"{W}">"    {ECH; return KITTINGPLANEND;}
"<"{W}"KittingPlan"           {ECH; return KITTINGPLANSTART;}
"</"{W}"Location"{W}">"       {ECH; return LOCATIONEND;}
"<"{W}"Location"              {ECH; return LOCATIONSTART;}
"</"{W}"Name"{W}">"           {ECH; return NAMEEND;}
"<"{W}"Name"                  {ECH; return NAMESTART;}
"</"{W}"NumberOfSteps"{W}">"  {ECH; return NUMBEROFSTEPSEND;}
"<"{W}"NumberOfSteps"         {ECH; return NUMBEROFSTEPSSTART;}
"</"{W}"Object"{W}">"         {ECH; return OBJECTEND;}
"<"{W}"Object"                {ECH; return OBJECTSTART;}
"</"{W}"OrientationStandardDeviation"{W}">" {ECH; return ORIENTATIONSTANDARDDEVIATIONEND;}
"<"{W}"OrientationStandardDeviation" {ECH; return ORIENTATIONSTANDARDDEVIATIONSTART;}
"</"{W}"PartName"{W}">"       {ECH; return PARTNAMEEND;}
"<"{W}"PartName"              {ECH; return PARTNAMESTART;}
"</"{W}"PlanAuthor"{W}">"     {ECH; return PLANAUTHOREND;}
"<"{W}"PlanAuthor"            {ECH; return PLANAUTHORSTART;}
"</"{W}"PlanDateAndTime"{W}">" {ECH; return PLANDATEANDTIMEEND;}
"<"{W}"PlanDateAndTime"       {ECH; return PLANDATEANDTIMESTART;}
"</"{W}"PlanDescription"{W}">" {ECH; return PLANDESCRIPTIONEND;}
"<"{W}"PlanDescription"       {ECH; return PLANDESCRIPTIONSTART;}
"</"{W}"PlanElement"{W}">"    {ECH; return PLANELEMENTEND;}
"<"{W}"PlanElement"           {ECH; return PLANELEMENTSTART;}
"</"{W}"PlanId"{W}">"         {ECH; return PLANIDEND;}
"<"{W}"PlanId"                {ECH; return PLANIDSTART;}
"</"{W}"PlanRoot"{W}">"       {ECH; return PLANROOTEND;}
"<"{W}"PlanRoot"              {ECH; return PLANROOTSTART;}
"</"{W}"PlanVersion"{W}">"    {ECH; return PLANVERSIONEND;}
"<"{W}"PlanVersion"           {ECH; return PLANVERSIONSTART;}
"</"{W}"Point"{W}">"          {ECH; return POINTEND;}
"<"{W}"Point"                 {ECH; return POINTSTART;}
"</"{W}"PositionStandardDeviation"{W}">" {ECH; return POSITIONSTANDARDDEVIATIONEND;}
"<"{W}"PositionStandardDeviation" {ECH; return POSITIONSTANDARDDEVIATIONSTART;}
"</"{W}"Predecessor"{W}">"    {ECH; return PREDECESSOREND;}
"<"{W}"Predecessor"           {ECH; return PREDECESSORSTART;}
"</"{W}"Property"{W}">"       {ECH; return PROPERTYEND;}
"<"{W}"Property"              {ECH; return PROPERTYSTART;}
"</"{W}"RefObjectName"{W}">"  {ECH; return REFOBJECTNAMEEND;}
"<"{W}"RefObjectName"         {ECH; return REFOBJECTNAMESTART;}
"</"{W}"RobotName"{W}">"      {ECH; return ROBOTNAMEEND;}
"<"{W}"RobotName"             {ECH; return ROBOTNAMESTART;}
"</"{W}"SequenceNumber"{W}">" {ECH; return SEQUENCENUMBEREND;}
"<"{W}"SequenceNumber"        {ECH; return SEQUENCENUMBERSTART;}
"</"{W}"Step"{W}">"           {ECH; return STEPEND;}
"<"{W}"Step"                  {ECH; return STEPSTART;}
"</"{W}"Test"{W}">"           {ECH; return TESTEND;}
"<"{W}"Test"                  {ECH; return TESTSTART;}
"</"{W}"ThingName"{W}">"      {ECH; return THINGNAMEEND;}
"<"{W}"ThingName"             {ECH; return THINGNAMESTART;}
"</"{W}"Val"{W}">"            {ECH; return VALEND;}
"<"{W}"Val"                   {ECH; return VALSTART;}
"</"{W}"VarName"{W}">"        {ECH; return VARNAMEEND;}
"<"{W}"VarName"               {ECH; return VARNAMESTART;}
"</"{W}"Variable"{W}">"       {ECH; return VARIABLEEND;}
"<"{W}"Variable"              {ECH; return VARIABLESTART;}
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

{W}"xsi:type"{W}"="{W}"\"ActionBaseType\""  { ECH; return ACTIONBASETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"ActionGroupBaseType\""  { ECH; return ACTIONGROUPBASETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"AndType\""  { ECH; return ANDTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"ArithmeticComparisonBooleanExpressionType\""  { ECH; return ARITHMETICCOMPARISONBOOLEANEXPRESSIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"AttachEndEffectorType\""  { ECH; return ATTACHENDEFFECTORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"BinaryArithmeticExpressionType\""  { ECH; return BINARYARITHMETICEXPRESSIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"BinaryBooleanExpressionType\""  { ECH; return BINARYBOOLEANEXPRESSIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"BooleanConstantType\""  { ECH; return BOOLEANCONSTANTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"CreateKitType\""  { ECH; return CREATEKITTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"DecimalType\""  { ECH; return DECIMALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"DetachEndEffectorType\""  { ECH; return DETACHENDEFFECTORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"DivType\""  { ECH; return DIVTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"EqualType\""  { ECH; return EQUALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"FalseType\""  { ECH; return FALSETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"GreaterOrEqualType\""  { ECH; return GREATEROREQUALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"GreaterType\""  { ECH; return GREATERTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"IfActionGroupType\""  { ECH; return IFACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LessOrEqualType\""  { ECH; return LESSOREQUALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LessType\""  { ECH; return LESSTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LocatePartType\""  { ECH; return LOCATEPARTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"MinusType\""  { ECH; return MINUSTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"ModType\""  { ECH; return MODTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"NegateType\""  { ECH; return NEGATETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"NotEqualType\""  { ECH; return NOTEQUALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"NotType\""  { ECH; return NOTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"OneOfActionGroupType\""  { ECH; return ONEOFACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"OrType\""  { ECH; return ORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"OrderedActionGroupType\""  { ECH; return ORDEREDACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PartiallyOrderedActionGroupType\""  { ECH; return PARTIALLYORDEREDACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PlusType\""  { ECH; return PLUSTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationInType\""  { ECH; return POSELOCATIONINTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationOnType\""  { ECH; return POSELOCATIONONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationType\""  { ECH; return POSELOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseOnlyLocationType\""  { ECH; return POSEONLYLOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PropValType\""  { ECH; return PROPVALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PutKitTrayType\""  { ECH; return PUTKITTRAYTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PutKitType\""  { ECH; return PUTKITTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PutPartType\""  { ECH; return PUTPARTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationInType\""  { ECH; return RELATIVELOCATIONINTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationOnType\""  { ECH; return RELATIVELOCATIONONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationType\""  { ECH; return RELATIVELOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RobotActionBaseType\""  { ECH; return ROBOTACTIONBASETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"SensorActionBaseType\""  { ECH; return SENSORACTIONBASETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"SomeOfActionGroupType\""  { ECH; return SOMEOFACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"TakeKitTrayType\""  { ECH; return TAKEKITTRAYTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"TakeKitType\""  { ECH; return TAKEKITTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"TakePartType\""  { ECH; return TAKEPARTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"TimesType\""  { ECH; return TIMESTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"TrueType\""  { ECH; return TRUETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"UnorderedActionGroupType\""  { ECH; return UNORDEREDACTIONGROUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"VarSetType\""  { ECH; return VARSETTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"VarValType\""  { ECH; return VARVALTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"WhileActionGroupType\""  { ECH; return WHILEACTIONGROUPTYPEDECL; }

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
