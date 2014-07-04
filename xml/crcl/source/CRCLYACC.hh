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
     NUMPOSITIONSEND = 300,
     NUMPOSITIONSSTART = 301,
     OPENGRIPPEREND = 302,
     OPENGRIPPERSTART = 303,
     OPENTOOLCHANGEREND = 304,
     OPENTOOLCHANGERSTART = 305,
     PERCENTEND = 306,
     PERCENTSTART = 307,
     POINTEND = 308,
     POINTSTART = 309,
     SETABSOLUTEACCELERATIONEND = 310,
     SETABSOLUTEACCELERATIONSTART = 311,
     SETABSOLUTESPEEDEND = 312,
     SETABSOLUTESPEEDSTART = 313,
     SETANGLEUNITSEND = 314,
     SETANGLEUNITSSTART = 315,
     SETENDANGLETOLERANCEEND = 316,
     SETENDANGLETOLERANCESTART = 317,
     SETENDPOINTTOLERANCEEND = 318,
     SETENDPOINTTOLERANCESTART = 319,
     SETINTERMEDIATEPOINTTOLERANCEEND = 320,
     SETINTERMEDIATEPOINTTOLERANCESTART = 321,
     SETLENGTHUNITSEND = 322,
     SETLENGTHUNITSSTART = 323,
     SETRELATIVEACCELERATIONEND = 324,
     SETRELATIVEACCELERATIONSTART = 325,
     SETRELATIVESPEEDEND = 326,
     SETRELATIVESPEEDSTART = 327,
     SPEEDEND = 328,
     SPEEDSTART = 329,
     TOLERANCEEND = 330,
     TOLERANCESTART = 331,
     UNITNAMEEND = 332,
     UNITNAMESTART = 333,
     WAYPOINTEND = 334,
     WAYPOINTSTART = 335,
     XAXISEND = 336,
     XAXISSTART = 337,
     XEND = 338,
     XSTART = 339,
     YEND = 340,
     YSTART = 341,
     ZAXISEND = 342,
     ZAXISSTART = 343,
     ZEND = 344,
     ZSTART = 345,
     CLOSEGRIPPERTYPEDECL = 346,
     CLOSETOOLCHANGERTYPEDECL = 347,
     DWELLTYPEDECL = 348,
     ENDCANONTYPEDECL = 349,
     INITCANONTYPEDECL = 350,
     MESSAGETYPEDECL = 351,
     MIDDLECOMMANDTYPEDECL = 352,
     MOVESTRAIGHTTOTYPEDECL = 353,
     MOVETHROUGHTOTYPEDECL = 354,
     OPENGRIPPERTYPEDECL = 355,
     OPENTOOLCHANGERTYPEDECL = 356,
     SETABSOLUTEACCELERATIONTYPEDECL = 357,
     SETABSOLUTESPEEDTYPEDECL = 358,
     SETANGLEUNITSTYPEDECL = 359,
     SETENDANGLETOLERANCETYPEDECL = 360,
     SETENDPOINTTOLERANCETYPEDECL = 361,
     SETINTERMEDIATEPOINTTOLERANCETYPEDECL = 362,
     SETLENGTHUNITSTYPEDECL = 363,
     SETRELATIVEACCELERATIONTYPEDECL = 364,
     SETRELATIVESPEEDTYPEDECL = 365
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


