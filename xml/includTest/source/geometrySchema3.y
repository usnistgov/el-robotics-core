%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#ifdef OWL
#include "owlGeometrySchema3Classes.hh"
#else
#include "geometrySchema3Classes.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

CirclesAndSpheresFile * CirclesAndSpheresTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);

%}

%union {
  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForCirclesAndSpheres *     XmlHeaderForCirclesAndSpheresVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDouble *                         XmlDoubleVal;
  XmlID *                             XmlIDVal;

  CirclesAndSpheresFile *             CirclesAndSpheresFileVal;

  CircleType *                        CircleTypeVal;
  CirclesAndSpheresType *             CirclesAndSpheresTypeVal;
  std::list<CircleType *> *           ListCircleTypeVal;
  std::list<SphereType *> *           ListSphereTypeVal;
  PointType *                         PointTypeVal;
  SphereType *                        SphereTypeVal;
  VectorType *                        VectorTypeVal;
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForCirclesAndSpheresVal> y_XmlHeaderForCirclesAndSpheres
%type <XmlVersionVal>                 y_XmlVersion
%type <CirclesAndSpheresFileVal>      y_CirclesAndSpheresFile
%type <XmlDoubleVal>                  y_XmlDouble
%type <XmlIDVal>                      y_XmlID

%type <PointTypeVal>                  y_Center_PointType
%type <CircleTypeVal>                 y_CircleInstance_CircleType_u
%type <CircleTypeVal>                 y_CircleType
%type <CirclesAndSpheresTypeVal>      y_CirclesAndSpheresType
%type <XmlDoubleVal>                  y_I_XmlDouble
%type <XmlDoubleVal>                  y_J_XmlDouble
%type <XmlDoubleVal>                  y_K_XmlDouble
%type <ListCircleTypeVal>             y_ListCircleInstance_CircleType_u
%type <ListSphereTypeVal>             y_ListSphereInstance_SphereType_u
%type <XmlIDVal>                      y_Name_XmlID
%type <VectorTypeVal>                 y_Normal_VectorType
%type <PointTypeVal>                  y_PointType
%type <XmlDoubleVal>                  y_Radius_XmlDouble
%type <SphereTypeVal>                 y_SphereInstance_SphereType_u
%type <SphereTypeVal>                 y_SphereType
%type <VectorTypeVal>                 y_VectorType
%type <XmlDoubleVal>                  y_X_XmlDouble
%type <XmlDoubleVal>                  y_Y_XmlDouble
%type <XmlDoubleVal>                  y_Z_XmlDouble

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

%token <iVal> CENTEREND
%token <iVal> CENTERSTART
%token <iVal> CIRCLEINSTANCEEND
%token <iVal> CIRCLEINSTANCESTART
%token <iVal> CIRCLESANDSPHERESEND
%token <iVal> CIRCLESANDSPHERESSTART
%token <iVal> IEND
%token <iVal> ISTART
%token <iVal> JEND
%token <iVal> JSTART
%token <iVal> KEND
%token <iVal> KSTART
%token <iVal> NAMEEND
%token <iVal> NAMESTART
%token <iVal> NORMALEND
%token <iVal> NORMALSTART
%token <iVal> RADIUSEND
%token <iVal> RADIUSSTART
%token <iVal> SPHEREINSTANCEEND
%token <iVal> SPHEREINSTANCESTART
%token <iVal> XEND
%token <iVal> XSTART
%token <iVal> YEND
%token <iVal> YSTART
%token <iVal> ZEND
%token <iVal> ZSTART


%token <iVal> CIRCLETYPEDECL
%token <iVal> SPHERETYPEDECL

%%

y_CirclesAndSpheresFile :
	  y_XmlVersion CIRCLESANDSPHERESSTART y_XmlHeaderForCirclesAndSpheres
	  y_CirclesAndSpheresType CIRCLESANDSPHERESEND
	  {$$ = new CirclesAndSpheresFile($1, $3, $4);
	   CirclesAndSpheresTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForCirclesAndSpheres:
	  XMLNSTARGET XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForCirclesAndSpheres($3);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2, true);
	    if (strncmp("urn:geometry ", $2, 13))
	      {
		fprintf(stderr,
	           "wrong targetNamespace in schema location %s\n", $2);
		exit(1);
	      }
	  }
	;

y_XmlDouble :
	  DATASTRING
	  {$$ = new XmlDouble($1);
	   if ($$->bad)
	     yyerror("bad XmlDouble");
	  }
	;

y_XmlID :
	  DATASTRING
	  {$$ = new XmlID($1);
	   if ($$->bad)
	     yyerror("bad XmlID");
	  }
	;

y_XmlVersion :
	  STARTVERSION XMLVERSION TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(false);
	   if (strcmp($3, "1.0"))
	     yyerror("version number must be 1.0");
	  }
	| STARTVERSION XMLVERSION TERMINALSTRING
	  ENCODING TERMINALSTRING ENDVERSION
	  {$$ = new XmlVersion(true);
	   if (strcmp($3, "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp($5, "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  }
	;

y_Center_PointType :
	  CENTERSTART y_PointType CENTEREND
	  {$$ = $2;}
	;

y_CircleInstance_CircleType_u :
	  CIRCLEINSTANCESTART y_CircleType CIRCLEINSTANCEEND
	  {$$ = $2;}
	;

y_CircleType :
	   ENDITEM y_Name_XmlID y_Radius_XmlDouble y_Center_PointType
	  y_Normal_VectorType
	  {$$ = new CircleType($2, $3, $4, $5);}
	;

y_CirclesAndSpheresType :
	  ENDITEM y_Name_XmlID y_ListCircleInstance_CircleType_u
	  y_ListSphereInstance_SphereType_u
	  {$$ = new CirclesAndSpheresType($2, $3, $4);}
	;

y_I_XmlDouble :
	  ISTART ENDITEM {yyReadData = 1;} y_XmlDouble IEND
	  {$$ = $4;}
	;

y_J_XmlDouble :
	  JSTART ENDITEM {yyReadData = 1;} y_XmlDouble JEND
	  {$$ = $4;}
	;

y_K_XmlDouble :
	  KSTART ENDITEM {yyReadData = 1;} y_XmlDouble KEND
	  {$$ = $4;}
	;

y_ListCircleInstance_CircleType_u :
	  y_CircleInstance_CircleType_u
	  {$$ = new std::list<CircleType *>;
	   $$->push_back($1);}
	| y_ListCircleInstance_CircleType_u y_CircleInstance_CircleType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListSphereInstance_SphereType_u :
	  y_ListSphereInstance_SphereType_u y_SphereInstance_SphereType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_SphereInstance_SphereType_u
	  {$$ = new std::list<SphereType *>;
	   $$->push_back($1);}
	;

y_Name_XmlID :
	  NAMESTART ENDITEM {yyReadData = 1;} y_XmlID NAMEEND
	  {$$ = $4;}
	;

y_Normal_VectorType :
	  NORMALSTART y_VectorType NORMALEND
	  {$$ = $2;}
	;

y_PointType :
	  ENDITEM y_Name_XmlID y_X_XmlDouble y_Y_XmlDouble y_Z_XmlDouble
	  {$$ = new PointType($2, $3, $4, $5);}
	;

y_Radius_XmlDouble :
	  RADIUSSTART ENDITEM {yyReadData = 1;} y_XmlDouble RADIUSEND
	  {$$ = $4;}
	;

y_SphereInstance_SphereType_u :
	  SPHEREINSTANCESTART y_SphereType SPHEREINSTANCEEND
	  {$$ = $2;}
	;

y_SphereType :
	   ENDITEM y_Name_XmlID y_Radius_XmlDouble y_Center_PointType
	  {$$ = new SphereType($2, $3, $4);}
	;

y_VectorType :
	  ENDITEM y_Name_XmlID y_I_XmlDouble y_J_XmlDouble y_K_XmlDouble
	  {$$ = new VectorType($2, $3, $4, $5);}
	;

y_X_XmlDouble :
	  XSTART ENDITEM {yyReadData = 1;} y_XmlDouble XEND
	  {$$ = $4;}
	;

y_Y_XmlDouble :
	  YSTART ENDITEM {yyReadData = 1;} y_XmlDouble YEND
	  {$$ = $4;}
	;

y_Z_XmlDouble :
	  ZSTART ENDITEM {yyReadData = 1;} y_XmlDouble ZEND
	  {$$ = $4;}
	;

%%

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
