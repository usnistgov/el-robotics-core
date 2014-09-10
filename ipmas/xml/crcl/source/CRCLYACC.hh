/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


