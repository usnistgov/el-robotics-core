/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


