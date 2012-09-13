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
     ANGLEUNITEND = 269,
     ANGLEUNITSTART = 270,
     ARRAYNUMBEREND = 271,
     ARRAYNUMBERSTART = 272,
     ARRAYRADIUSEND = 273,
     ARRAYRADIUSSTART = 274,
     CAPACITYEND = 275,
     CAPACITYSTART = 276,
     CHANGINGSTATIONEND = 277,
     CHANGINGSTATIONSTART = 278,
     CUPDIAMETEREND = 279,
     CUPDIAMETERSTART = 280,
     DESCRIPTIONEND = 281,
     DESCRIPTIONSTART = 282,
     DESIGNNAMEEND = 283,
     DESIGNNAMESTART = 284,
     ENDEFFECTORHOLDERSEND = 285,
     ENDEFFECTORHOLDERSSTART = 286,
     ENDEFFECTORNAMEEND = 287,
     ENDEFFECTORNAMESTART = 288,
     ENDEFFECTOREND = 289,
     ENDEFFECTORSTART = 290,
     FINISHEDEND = 291,
     FINISHEDSTART = 292,
     HEIGHTEND = 293,
     HEIGHTSTART = 294,
     IEND = 295,
     ISTART = 296,
     JEND = 297,
     JSTART = 298,
     KEND = 299,
     KSTART = 300,
     KITDESIGNNAMEEND = 301,
     KITDESIGNNAMESTART = 302,
     KITDESIGNEND = 303,
     KITDESIGNSTART = 304,
     KITTRAYSKUNAMEEND = 305,
     KITTRAYSKUNAMESTART = 306,
     KITTRAYSEND = 307,
     KITTRAYSSTART = 308,
     KITEND = 309,
     KITSTART = 310,
     KITTINGWORKSTATIONEND = 311,
     KITTINGWORKSTATIONSTART = 312,
     LARGECONTAINEREND = 313,
     LARGECONTAINERSTART = 314,
     LENGTHUNITEND = 315,
     LENGTHUNITSTART = 316,
     LENGTHEND = 317,
     LENGTHSTART = 318,
     MAXIMUMLOADWEIGHTEND = 319,
     MAXIMUMLOADWEIGHTSTART = 320,
     MAXIMUMPOINTEND = 321,
     MAXIMUMPOINTSTART = 322,
     MINIMUMPOINTEND = 323,
     MINIMUMPOINTSTART = 324,
     NAMEEND = 325,
     NAMESTART = 326,
     OBJECTEND = 327,
     OBJECTSTART = 328,
     OTHEROBSTACLEEND = 329,
     OTHEROBSTACLESTART = 330,
     PARTQUANTITYEND = 331,
     PARTQUANTITYSTART = 332,
     PARTREFANDPOSEEND = 333,
     PARTREFANDPOSESTART = 334,
     PARTSKUNAMEEND = 335,
     PARTSKUNAMESTART = 336,
     PARTEND = 337,
     PARTSTART = 338,
     PARTSTRAYEND = 339,
     PARTSTRAYSTART = 340,
     POINTEND = 341,
     POINTSTART = 342,
     PRIMARYLOCATIONEND = 343,
     PRIMARYLOCATIONSTART = 344,
     REFOBJECTEND = 345,
     REFOBJECTSTART = 346,
     ROBOTEND = 347,
     ROBOTSTART = 348,
     SECONDARYLOCATIONEND = 349,
     SECONDARYLOCATIONSTART = 350,
     SERIALNUMBEREND = 351,
     SERIALNUMBERSTART = 352,
     SHAPEEND = 353,
     SHAPESTART = 354,
     SKUNAMEEND = 355,
     SKUNAMESTART = 356,
     SKUEND = 357,
     SKUSTART = 358,
     SOLIDOBJECTEND = 359,
     SOLIDOBJECTSTART = 360,
     TRAYEND = 361,
     TRAYSTART = 362,
     WEIGHTUNITEND = 363,
     WEIGHTUNITSTART = 364,
     WEIGHTEND = 365,
     WEIGHTSTART = 366,
     WIDTHEND = 367,
     WIDTHSTART = 368,
     WORKTABLEEND = 369,
     WORKTABLESTART = 370,
     WORKVOLUMEEND = 371,
     WORKVOLUMESTART = 372,
     XAXISEND = 373,
     XAXISSTART = 374,
     XEND = 375,
     XSTART = 376,
     YEND = 377,
     YSTART = 378,
     ZAXISEND = 379,
     ZAXISSTART = 380,
     ZEND = 381,
     ZSTART = 382,
     BOXVOLUMETYPEDECL = 383,
     BOXYOBJECTTYPEDECL = 384,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 385,
     ENDEFFECTORHOLDERTYPEDECL = 386,
     ENDEFFECTORTYPEDECL = 387,
     GRIPPEREFFECTORTYPEDECL = 388,
     KITDESIGNTYPEDECL = 389,
     KITTRAYTYPEDECL = 390,
     KITTYPEDECL = 391,
     KITTINGWORKSTATIONTYPEDECL = 392,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 393,
     LARGEBOXWITHKITSTYPEDECL = 394,
     LARGECONTAINERTYPEDECL = 395,
     PARTREFANDPOSETYPEDECL = 396,
     PARTTYPEDECL = 397,
     PARTSBINTYPEDECL = 398,
     PARTSTRAYTYPEDECL = 399,
     PARTSTRAYWITHPARTSTYPEDECL = 400,
     PHYSICALLOCATIONTYPEDECL = 401,
     POINTTYPEDECL = 402,
     POSELOCATIONINTYPEDECL = 403,
     POSELOCATIONONTYPEDECL = 404,
     POSELOCATIONTYPEDECL = 405,
     POSEONLYLOCATIONTYPEDECL = 406,
     RELATIVELOCATIONINTYPEDECL = 407,
     RELATIVELOCATIONONTYPEDECL = 408,
     RELATIVELOCATIONTYPEDECL = 409,
     ROBOTTYPEDECL = 410,
     SHAPEDESIGNTYPEDECL = 411,
     STOCKKEEPINGUNITTYPEDECL = 412,
     VACUUMEFFECTORMULTICUPTYPEDECL = 413,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 414,
     VACUUMEFFECTORTYPEDECL = 415,
     VECTORTYPEDECL = 416,
     WORKTABLETYPEDECL = 417
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingWorkStation *    XmlHeaderForKittingWorkStationVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlBoolean *                        XmlBooleanVal;
  XmlDecimal *                        XmlDecimalVal;
  XmlID *                             XmlIDVal;
  XmlIDREF *                          XmlIDREFVal;
  XmlNMTOKEN *                        XmlNMTOKENVal;
  XmlNonNegativeInteger *             XmlNonNegativeIntegerVal;
  XmlPositiveInteger *                XmlPositiveIntegerVal;
  XmlString *                         XmlStringVal;

  KittingWorkStationFile *            KittingWorkStationFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  std::list<BoxVolumeType *> *        BoxVolumeTypeListVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyObjectType *                    BoxyObjectTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  std::list<XmlIDREF *> *             IDREFListVal;
  std::list<KitDesignType *> *        KitDesignTypeListVal;
  KitDesignType *                     KitDesignTypeVal;
  std::list<KitTrayType *> *          KitTrayTypeListVal;
  KitTrayType *                       KitTrayTypeVal;
  std::list<KitType *> *              KitTypeListVal;
  KitType *                           KitTypeVal;
  KittingWorkstationType *            KittingWorkstationTypeVal;
  LargeBoxWithEmptyKitTraysType *     LargeBoxWithEmptyKitTraysTypeVal;
  LargeBoxWithKitsType *              LargeBoxWithKitsTypeVal;
  LargeContainerType *                LargeContainerTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  std::list<PartRefAndPoseType *> *   PartRefAndPoseTypeListVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  std::list<PartType *> *             PartTypeListVal;
  PartType *                          PartTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsTrayWithPartsType *            PartsTrayWithPartsTypeVal;
  std::list<PhysicalLocationType *> * PhysicalLocationTypeListVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotType *                         RobotTypeVal;
  ShapeDesignType *                   ShapeDesignTypeVal;
  std::list<SolidObjectType *> *      SolidObjectTypeListVal;
  SolidObjectType *                   SolidObjectTypeVal;
  std::list<StockKeepingUnitType *> * StockKeepingUnitTypeListVal;
  StockKeepingUnitType *              StockKeepingUnitTypeVal;
  VacuumEffectorMultiCupType *        VacuumEffectorMultiCupTypeVal;
  VacuumEffectorSingleCupType *       VacuumEffectorSingleCupTypeVal;
  VacuumEffectorType *                VacuumEffectorTypeVal;
  VectorType *                        VectorTypeVal;
  WeightUnitType *                    WeightUnitTypeVal;
  WorkTableType *                     WorkTableTypeVal;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


