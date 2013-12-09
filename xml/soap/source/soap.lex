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
#include "owlSoapClasses.hh"
#else
#include "soapClasses.hh"
#endif
#include "soapYACC.hh"    // for tokens, yylval, etc.

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

"</"{W}"A1"{W}">"             {ECH; return A1END;}
"<"{W}"A1"                    {ECH; return A1START;}
"</"{W}"AngleUnit"{W}">"      {ECH; return ANGLEUNITEND;}
"<"{W}"AngleUnit"             {ECH; return ANGLEUNITSTART;}
"</"{W}"AnyOrderOrderingConstruct"{W}">" {ECH; return ANYORDERORDERINGCONSTRUCTEND;}
"<"{W}"AnyOrderOrderingConstruct" {ECH; return ANYORDERORDERINGCONSTRUCTSTART;}
"</"{W}"ArrayNumber"{W}">"    {ECH; return ARRAYNUMBEREND;}
"<"{W}"ArrayNumber"           {ECH; return ARRAYNUMBERSTART;}
"</"{W}"ArrayRadius"{W}">"    {ECH; return ARRAYRADIUSEND;}
"<"{W}"ArrayRadius"           {ECH; return ARRAYRADIUSSTART;}
"</"{W}"AttachEndEffector"{W}">" {ECH; return ATTACHENDEFFECTOREND;}
"<"{W}"AttachEndEffector"     {ECH; return ATTACHENDEFFECTORSTART;}
"</"{W}"Base"{W}">"           {ECH; return BASEEND;}
"<"{W}"Base"                  {ECH; return BASESTART;}
"</"{W}"Capacity"{W}">"       {ECH; return CAPACITYEND;}
"<"{W}"Capacity"              {ECH; return CAPACITYSTART;}
"</"{W}"ChangingStation"{W}">" {ECH; return CHANGINGSTATIONEND;}
"<"{W}"ChangingStation"       {ECH; return CHANGINGSTATIONSTART;}
"</"{W}"CountOrderingConstruct"{W}">" {ECH; return COUNTORDERINGCONSTRUCTEND;}
"<"{W}"CountOrderingConstruct" {ECH; return COUNTORDERINGCONSTRUCTSTART;}
"</"{W}"CreateKit"{W}">"      {ECH; return CREATEKITEND;}
"<"{W}"CreateKit"             {ECH; return CREATEKITSTART;}
"</"{W}"CupDiameter"{W}">"    {ECH; return CUPDIAMETEREND;}
"<"{W}"CupDiameter"           {ECH; return CUPDIAMETERSTART;}
"</"{W}"Description"{W}">"    {ECH; return DESCRIPTIONEND;}
"<"{W}"Description"           {ECH; return DESCRIPTIONSTART;}
"</"{W}"DesignName"{W}">"     {ECH; return DESIGNNAMEEND;}
"<"{W}"DesignName"            {ECH; return DESIGNNAMESTART;}
"</"{W}"DetachEndEffector"{W}">" {ECH; return DETACHENDEFFECTOREND;}
"<"{W}"DetachEndEffector"     {ECH; return DETACHENDEFFECTORSTART;}
"</"{W}"Diameter"{W}">"       {ECH; return DIAMETEREND;}
"<"{W}"Diameter"              {ECH; return DIAMETERSTART;}
"</"{W}"Domain"{W}">"         {ECH; return DOMAINEND;}
"<"{W}"Domain"                {ECH; return DOMAINSTART;}
"</"{W}"Effect"{W}">"         {ECH; return EFFECTEND;}
"<"{W}"Effect"                {ECH; return EFFECTSTART;}
"</"{W}"EndEffectorChangingStationParameter"{W}">" {ECH; return ENDEFFECTORCHANGINGSTATIONPARAMETEREND;}
"<"{W}"EndEffectorChangingStationParameter" {ECH; return ENDEFFECTORCHANGINGSTATIONPARAMETERSTART;}
"</"{W}"EndEffectorHolderParameter"{W}">" {ECH; return ENDEFFECTORHOLDERPARAMETEREND;}
"<"{W}"EndEffectorHolderParameter" {ECH; return ENDEFFECTORHOLDERPARAMETERSTART;}
"</"{W}"EndEffectorHolder"{W}">" {ECH; return ENDEFFECTORHOLDEREND;}
"<"{W}"EndEffectorHolder"     {ECH; return ENDEFFECTORHOLDERSTART;}
"</"{W}"EndEffectorName"{W}">" {ECH; return ENDEFFECTORNAMEEND;}
"<"{W}"EndEffectorName"       {ECH; return ENDEFFECTORNAMESTART;}
"</"{W}"EndEffectorParameter"{W}">" {ECH; return ENDEFFECTORPARAMETEREND;}
"<"{W}"EndEffectorParameter"  {ECH; return ENDEFFECTORPARAMETERSTART;}
"</"{W}"EndEffector"{W}">"    {ECH; return ENDEFFECTOREND;}
"<"{W}"EndEffector"           {ECH; return ENDEFFECTORSTART;}
"</"{W}"ExistOrderingConstruct"{W}">" {ECH; return EXISTORDERINGCONSTRUCTEND;}
"<"{W}"ExistOrderingConstruct" {ECH; return EXISTORDERINGCONSTRUCTSTART;}
"</"{W}"Expression"{W}">"     {ECH; return EXPRESSIONEND;}
"<"{W}"Expression"            {ECH; return EXPRESSIONSTART;}
"</"{W}"ExternalShape"{W}">"  {ECH; return EXTERNALSHAPEEND;}
"<"{W}"ExternalShape"         {ECH; return EXTERNALSHAPESTART;}
"</"{W}"F1EqualF2"{W}">"      {ECH; return F1EQUALF2END;}
"<"{W}"F1EqualF2"             {ECH; return F1EQUALF2START;}
"</"{W}"F1GreaterF2"{W}">"    {ECH; return F1GREATERF2END;}
"<"{W}"F1GreaterF2"           {ECH; return F1GREATERF2START;}
"</"{W}"F1GreaterOrEqualF2"{W}">" {ECH; return F1GREATEROREQUALF2END;}
"<"{W}"F1GreaterOrEqualF2"    {ECH; return F1GREATEROREQUALF2START;}
"</"{W}"F1LessF2"{W}">"       {ECH; return F1LESSF2END;}
"<"{W}"F1LessF2"              {ECH; return F1LESSF2START;}
"</"{W}"F1LessOrEqualF2"{W}">" {ECH; return F1LESSOREQUALF2END;}
"<"{W}"F1LessOrEqualF2"       {ECH; return F1LESSOREQUALF2START;}
"</"{W}"F1Name"{W}">"         {ECH; return F1NAMEEND;}
"<"{W}"F1Name"                {ECH; return F1NAMESTART;}
"</"{W}"F2Name"{W}">"         {ECH; return F2NAMEEND;}
"<"{W}"F2Name"                {ECH; return F2NAMESTART;}
"</"{W}"Finished"{W}">"       {ECH; return FINISHEDEND;}
"<"{W}"Finished"              {ECH; return FINISHEDSTART;}
"</"{W}"FunctionName"{W}">"   {ECH; return FUNCTIONNAMEEND;}
"<"{W}"FunctionName"          {ECH; return FUNCTIONNAMESTART;}
"</"{W}"FunctionOperation"{W}">" {ECH; return FUNCTIONOPERATIONEND;}
"<"{W}"FunctionOperation"     {ECH; return FUNCTIONOPERATIONSTART;}
"</"{W}"Function"{W}">"       {ECH; return FUNCTIONEND;}
"<"{W}"Function"              {ECH; return FUNCTIONSTART;}
"</"{W}"GraspPose"{W}">"      {ECH; return GRASPPOSEEND;}
"<"{W}"GraspPose"             {ECH; return GRASPPOSESTART;}
"</"{W}"HasTop"{W}">"         {ECH; return HASTOPEND;}
"<"{W}"HasTop"                {ECH; return HASTOPSTART;}
"</"{W}"Height"{W}">"         {ECH; return HEIGHTEND;}
"<"{W}"Height"                {ECH; return HEIGHTSTART;}
"</"{W}"HeldObject"{W}">"     {ECH; return HELDOBJECTEND;}
"<"{W}"HeldObject"            {ECH; return HELDOBJECTSTART;}
"</"{W}"I"{W}">"              {ECH; return IEND;}
"<"{W}"I"                     {ECH; return ISTART;}
"</"{W}"InContactWith"{W}">"  {ECH; return INCONTACTWITHEND;}
"<"{W}"InContactWith"         {ECH; return INCONTACTWITHSTART;}
"</"{W}"InternalShape"{W}">"  {ECH; return INTERNALSHAPEEND;}
"<"{W}"InternalShape"         {ECH; return INTERNALSHAPESTART;}
"</"{W}"J"{W}">"              {ECH; return JEND;}
"<"{W}"J"                     {ECH; return JSTART;}
"</"{W}"K"{W}">"              {ECH; return KEND;}
"<"{W}"K"                     {ECH; return KSTART;}
"</"{W}"KitDesignName"{W}">"  {ECH; return KITDESIGNNAMEEND;}
"<"{W}"KitDesignName"         {ECH; return KITDESIGNNAMESTART;}
"</"{W}"KitDesign"{W}">"      {ECH; return KITDESIGNEND;}
"<"{W}"KitDesign"             {ECH; return KITDESIGNSTART;}
"</"{W}"KitParameter"{W}">"   {ECH; return KITPARAMETEREND;}
"<"{W}"KitParameter"          {ECH; return KITPARAMETERSTART;}
"</"{W}"KitTrayParameter"{W}">" {ECH; return KITTRAYPARAMETEREND;}
"<"{W}"KitTrayParameter"      {ECH; return KITTRAYPARAMETERSTART;}
"</"{W}"KitTraySkuName"{W}">" {ECH; return KITTRAYSKUNAMEEND;}
"<"{W}"KitTraySkuName"        {ECH; return KITTRAYSKUNAMESTART;}
"</"{W}"KitTray"{W}">"        {ECH; return KITTRAYEND;}
"<"{W}"KitTray"               {ECH; return KITTRAYSTART;}
"</"{W}"Kit"{W}">"            {ECH; return KITEND;}
"<"{W}"Kit"                   {ECH; return KITSTART;}
"</"{W}"KittingWorkstation"{W}">" {ECH; return KITTINGWORKSTATIONEND;}
"<"{W}"KittingWorkstation"    {ECH; return KITTINGWORKSTATIONSTART;}
"</"{W}"LargeBoxWithEmptyKitTraysParameter"{W}">" {ECH; return LARGEBOXWITHEMPTYKITTRAYSPARAMETEREND;}
"<"{W}"LargeBoxWithEmptyKitTraysParameter" {ECH; return LARGEBOXWITHEMPTYKITTRAYSPARAMETERSTART;}
"</"{W}"LargeBoxWithKitsParameter"{W}">" {ECH; return LARGEBOXWITHKITSPARAMETEREND;}
"<"{W}"LargeBoxWithKitsParameter" {ECH; return LARGEBOXWITHKITSPARAMETERSTART;}
"</"{W}"LargeContainer"{W}">" {ECH; return LARGECONTAINEREND;}
"<"{W}"LargeContainer"        {ECH; return LARGECONTAINERSTART;}
"</"{W}"LengthUnit"{W}">"     {ECH; return LENGTHUNITEND;}
"<"{W}"LengthUnit"            {ECH; return LENGTHUNITSTART;}
"</"{W}"Length"{W}">"         {ECH; return LENGTHEND;}
"<"{W}"Length"                {ECH; return LENGTHSTART;}
"</"{W}"MaximumLoadWeight"{W}">" {ECH; return MAXIMUMLOADWEIGHTEND;}
"<"{W}"MaximumLoadWeight"     {ECH; return MAXIMUMLOADWEIGHTSTART;}
"</"{W}"MaximumPoint"{W}">"   {ECH; return MAXIMUMPOINTEND;}
"<"{W}"MaximumPoint"          {ECH; return MAXIMUMPOINTSTART;}
"</"{W}"MinimumPoint"{W}">"   {ECH; return MINIMUMPOINTEND;}
"<"{W}"MinimumPoint"          {ECH; return MINIMUMPOINTSTART;}
"</"{W}"ModelFileName"{W}">"  {ECH; return MODELFILENAMEEND;}
"<"{W}"ModelFileName"         {ECH; return MODELFILENAMESTART;}
"</"{W}"ModelFormatName"{W}">" {ECH; return MODELFORMATNAMEEND;}
"<"{W}"ModelFormatName"       {ECH; return MODELFORMATNAMESTART;}
"</"{W}"ModelName"{W}">"      {ECH; return MODELNAMEEND;}
"<"{W}"ModelName"             {ECH; return MODELNAMESTART;}
"</"{W}"Name"{W}">"           {ECH; return NAMEEND;}
"<"{W}"Name"                  {ECH; return NAMESTART;}
"</"{W}"NotPredicateName"{W}">" {ECH; return NOTPREDICATENAMEEND;}
"<"{W}"NotPredicateName"      {ECH; return NOTPREDICATENAMESTART;}
"</"{W}"ObjectOnTable"{W}">"  {ECH; return OBJECTONTABLEEND;}
"<"{W}"ObjectOnTable"         {ECH; return OBJECTONTABLESTART;}
"</"{W}"Object"{W}">"         {ECH; return OBJECTEND;}
"<"{W}"Object"                {ECH; return OBJECTSTART;}
"</"{W}"OnTopWithContact"{W}">" {ECH; return ONTOPWITHCONTACTEND;}
"<"{W}"OnTopWithContact"      {ECH; return ONTOPWITHCONTACTSTART;}
"</"{W}"OrientationStandardDeviation"{W}">" {ECH; return ORIENTATIONSTANDARDDEVIATIONEND;}
"<"{W}"OrientationStandardDeviation" {ECH; return ORIENTATIONSTANDARDDEVIATIONSTART;}
"</"{W}"OtherObstacle"{W}">"  {ECH; return OTHEROBSTACLEEND;}
"<"{W}"OtherObstacle"         {ECH; return OTHEROBSTACLESTART;}
"</"{W}"PartName"{W}">"       {ECH; return PARTNAMEEND;}
"<"{W}"PartName"              {ECH; return PARTNAMESTART;}
"</"{W}"PartParameter"{W}">"  {ECH; return PARTPARAMETEREND;}
"<"{W}"PartParameter"         {ECH; return PARTPARAMETERSTART;}
"</"{W}"PartQuantity"{W}">"   {ECH; return PARTQUANTITYEND;}
"<"{W}"PartQuantity"          {ECH; return PARTQUANTITYSTART;}
"</"{W}"PartRefAndPoseName"{W}">" {ECH; return PARTREFANDPOSENAMEEND;}
"<"{W}"PartRefAndPoseName"    {ECH; return PARTREFANDPOSENAMESTART;}
"</"{W}"PartRefAndPose"{W}">" {ECH; return PARTREFANDPOSEEND;}
"<"{W}"PartRefAndPose"        {ECH; return PARTREFANDPOSESTART;}
"</"{W}"PartSkuName"{W}">"    {ECH; return PARTSKUNAMEEND;}
"<"{W}"PartSkuName"           {ECH; return PARTSKUNAMESTART;}
"</"{W}"Part"{W}">"           {ECH; return PARTEND;}
"<"{W}"Part"                  {ECH; return PARTSTART;}
"</"{W}"PartiallyIn"{W}">"    {ECH; return PARTIALLYINEND;}
"<"{W}"PartiallyIn"           {ECH; return PARTIALLYINSTART;}
"</"{W}"PartsTrayParameter"{W}">" {ECH; return PARTSTRAYPARAMETEREND;}
"<"{W}"PartsTrayParameter"    {ECH; return PARTSTRAYPARAMETERSTART;}
"</"{W}"Point"{W}">"          {ECH; return POINTEND;}
"<"{W}"Point"                 {ECH; return POINTSTART;}
"</"{W}"PositionInOrderedList"{W}">" {ECH; return POSITIONINORDEREDLISTEND;}
"<"{W}"PositionInOrderedList" {ECH; return POSITIONINORDEREDLISTSTART;}
"</"{W}"PositionStandardDeviation"{W}">" {ECH; return POSITIONSTANDARDDEVIATIONEND;}
"<"{W}"PositionStandardDeviation" {ECH; return POSITIONSTANDARDDEVIATIONSTART;}
"</"{W}"Precondition"{W}">"   {ECH; return PRECONDITIONEND;}
"<"{W}"Precondition"          {ECH; return PRECONDITIONSTART;}
"</"{W}"PredicateGroupElement"{W}">" {ECH; return PREDICATEGROUPELEMENTEND;}
"<"{W}"PredicateGroupElement" {ECH; return PREDICATEGROUPELEMENTSTART;}
"</"{W}"PredicateName"{W}">"  {ECH; return PREDICATENAMEEND;}
"<"{W}"PredicateName"         {ECH; return PREDICATENAMESTART;}
"</"{W}"PredicateOccurrence"{W}">" {ECH; return PREDICATEOCCURRENCEEND;}
"<"{W}"PredicateOccurrence"   {ECH; return PREDICATEOCCURRENCESTART;}
"</"{W}"Predicate"{W}">"      {ECH; return PREDICATEEND;}
"<"{W}"Predicate"             {ECH; return PREDICATESTART;}
"</"{W}"PrimaryLocation"{W}">" {ECH; return PRIMARYLOCATIONEND;}
"<"{W}"PrimaryLocation"       {ECH; return PRIMARYLOCATIONSTART;}
"</"{W}"PutKitTray"{W}">"     {ECH; return PUTKITTRAYEND;}
"<"{W}"PutKitTray"            {ECH; return PUTKITTRAYSTART;}
"</"{W}"PutKit"{W}">"         {ECH; return PUTKITEND;}
"<"{W}"PutKit"                {ECH; return PUTKITSTART;}
"</"{W}"PutPart"{W}">"        {ECH; return PUTPARTEND;}
"<"{W}"PutPart"               {ECH; return PUTPARTSTART;}
"</"{W}"RCC8Set"{W}">"        {ECH; return RCC8SETEND;}
"<"{W}"RCC8Set"               {ECH; return RCC8SETSTART;}
"</"{W}"RefObjectName"{W}">"  {ECH; return REFOBJECTNAMEEND;}
"<"{W}"RefObjectName"         {ECH; return REFOBJECTNAMESTART;}
"</"{W}"ReferenceName"{W}">"  {ECH; return REFERENCENAMEEND;}
"<"{W}"ReferenceName"         {ECH; return REFERENCENAMESTART;}
"</"{W}"Requirement"{W}">"    {ECH; return REQUIREMENTEND;}
"<"{W}"Requirement"           {ECH; return REQUIREMENTSTART;}
"</"{W}"RobotParameter"{W}">" {ECH; return ROBOTPARAMETEREND;}
"<"{W}"RobotParameter"        {ECH; return ROBOTPARAMETERSTART;}
"</"{W}"Robot"{W}">"          {ECH; return ROBOTEND;}
"<"{W}"Robot"                 {ECH; return ROBOTSTART;}
"</"{W}"SOAP"{W}">"           {ECH; return SOAPEND;}
"<"{W}"SOAP"                  {ECH; return SOAPSTART;}
"</"{W}"SecondaryLocation"{W}">" {ECH; return SECONDARYLOCATIONEND;}
"<"{W}"SecondaryLocation"     {ECH; return SECONDARYLOCATIONSTART;}
"</"{W}"SerialNumber"{W}">"   {ECH; return SERIALNUMBEREND;}
"<"{W}"SerialNumber"          {ECH; return SERIALNUMBERSTART;}
"</"{W}"SkuName"{W}">"        {ECH; return SKUNAMEEND;}
"<"{W}"SkuName"               {ECH; return SKUNAMESTART;}
"</"{W}"Sku"{W}">"            {ECH; return SKUEND;}
"<"{W}"Sku"                   {ECH; return SKUSTART;}
"</"{W}"Slot"{W}">"           {ECH; return SLOTEND;}
"<"{W}"Slot"                  {ECH; return SLOTSTART;}
"</"{W}"StateRelationName"{W}">" {ECH; return STATERELATIONNAMEEND;}
"<"{W}"StateRelationName"     {ECH; return STATERELATIONNAMESTART;}
"</"{W}"TakeKitTray"{W}">"    {ECH; return TAKEKITTRAYEND;}
"<"{W}"TakeKitTray"           {ECH; return TAKEKITTRAYSTART;}
"</"{W}"TakeKit"{W}">"        {ECH; return TAKEKITEND;}
"<"{W}"TakeKit"               {ECH; return TAKEKITSTART;}
"</"{W}"TakePart"{W}">"       {ECH; return TAKEPARTEND;}
"<"{W}"TakePart"              {ECH; return TAKEPARTSTART;}
"</"{W}"TargetName"{W}">"     {ECH; return TARGETNAMEEND;}
"<"{W}"TargetName"            {ECH; return TARGETNAMESTART;}
"</"{W}"Timestamp"{W}">"      {ECH; return TIMESTAMPEND;}
"<"{W}"Timestamp"             {ECH; return TIMESTAMPSTART;}
"</"{W}"UnderWithContact"{W}">" {ECH; return UNDERWITHCONTACTEND;}
"<"{W}"UnderWithContact"      {ECH; return UNDERWITHCONTACTSTART;}
"</"{W}"Value"{W}">"          {ECH; return VALUEEND;}
"<"{W}"Value"                 {ECH; return VALUESTART;}
"</"{W}"Variable"{W}">"       {ECH; return VARIABLEEND;}
"<"{W}"Variable"              {ECH; return VARIABLESTART;}
"</"{W}"WeightUnit"{W}">"     {ECH; return WEIGHTUNITEND;}
"<"{W}"WeightUnit"            {ECH; return WEIGHTUNITSTART;}
"</"{W}"Weight"{W}">"         {ECH; return WEIGHTEND;}
"<"{W}"Weight"                {ECH; return WEIGHTSTART;}
"</"{W}"Width"{W}">"          {ECH; return WIDTHEND;}
"<"{W}"Width"                 {ECH; return WIDTHSTART;}
"</"{W}"WorkTableParameter"{W}">" {ECH; return WORKTABLEPARAMETEREND;}
"<"{W}"WorkTableParameter"    {ECH; return WORKTABLEPARAMETERSTART;}
"</"{W}"WorkVolume"{W}">"     {ECH; return WORKVOLUMEEND;}
"<"{W}"WorkVolume"            {ECH; return WORKVOLUMESTART;}
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

{W}"xsi:type"{W}"="{W}"\"BoxyShapeType\""  { ECH; return BOXYSHAPETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"CylindricalShapeType\""  { ECH; return CYLINDRICALSHAPETYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"EndEffectorChangingStationType\""  { ECH; return ENDEFFECTORCHANGINGSTATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"EndEffectorHolderType\""  { ECH; return ENDEFFECTORHOLDERTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"EndEffectorType\""  { ECH; return ENDEFFECTORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"GripperEffectorType\""  { ECH; return GRIPPEREFFECTORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"HumanType\""  { ECH; return HUMANTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"KitTrayType\""  { ECH; return KITTRAYTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"KitType\""  { ECH; return KITTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"KittingWorkstationType\""  { ECH; return KITTINGWORKSTATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LargeBoxWithEmptyKitTraysType\""  { ECH; return LARGEBOXWITHEMPTYKITTRAYSTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LargeBoxWithKitsType\""  { ECH; return LARGEBOXWITHKITSTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"LargeContainerType\""  { ECH; return LARGECONTAINERTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"MechanicalComponentType\""  { ECH; return MECHANICALCOMPONENTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"NoSkuObjectType\""  { ECH; return NOSKUOBJECTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PartType\""  { ECH; return PARTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PartsBinType\""  { ECH; return PARTSBINTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PartsTrayType\""  { ECH; return PARTSTRAYTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PartsVesselType\""  { ECH; return PARTSVESSELTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationInType\""  { ECH; return POSELOCATIONINTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationOnType\""  { ECH; return POSELOCATIONONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseLocationType\""  { ECH; return POSELOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"PoseOnlyLocationType\""  { ECH; return POSEONLYLOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationInType\""  { ECH; return RELATIVELOCATIONINTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationOnType\""  { ECH; return RELATIVELOCATIONONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RelativeLocationType\""  { ECH; return RELATIVELOCATIONTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"RobotType\""  { ECH; return ROBOTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"SkuObjectType\""  { ECH; return SKUOBJECTTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"VacuumEffectorMultiCupType\""  { ECH; return VACUUMEFFECTORMULTICUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"VacuumEffectorSingleCupType\""  { ECH; return VACUUMEFFECTORSINGLECUPTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"VacuumEffectorType\""  { ECH; return VACUUMEFFECTORTYPEDECL; }
{W}"xsi:type"{W}"="{W}"\"WorkTableType\""  { ECH; return WORKTABLETYPEDECL; }

"xmlns"{W}"="{W}"\"urn:kitting\"" {ECH; return XMLNSTARGET;}

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
