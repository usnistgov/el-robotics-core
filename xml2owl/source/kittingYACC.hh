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
     HASTOPEND = 293,
     HASTOPSTART = 294,
     HEIGHTEND = 295,
     HEIGHTSTART = 296,
     IEND = 297,
     ISTART = 298,
     JEND = 299,
     JSTART = 300,
     KEND = 301,
     KSTART = 302,
     KITDESIGNNAMEEND = 303,
     KITDESIGNNAMESTART = 304,
     KITDESIGNEND = 305,
     KITDESIGNSTART = 306,
     KITTRAYSKUNAMEEND = 307,
     KITTRAYSKUNAMESTART = 308,
     KITTRAYSEND = 309,
     KITTRAYSSTART = 310,
     KITEND = 311,
     KITSTART = 312,
     KITTINGWORKSTATIONEND = 313,
     KITTINGWORKSTATIONSTART = 314,
     LARGECONTAINEREND = 315,
     LARGECONTAINERSTART = 316,
     LENGTHUNITEND = 317,
     LENGTHUNITSTART = 318,
     LENGTHEND = 319,
     LENGTHSTART = 320,
     MAXIMUMLOADWEIGHTEND = 321,
     MAXIMUMLOADWEIGHTSTART = 322,
     MAXIMUMPOINTEND = 323,
     MAXIMUMPOINTSTART = 324,
     MINIMUMPOINTEND = 325,
     MINIMUMPOINTSTART = 326,
     NAMEEND = 327,
     NAMESTART = 328,
     OBJECTEND = 329,
     OBJECTSTART = 330,
     OTHEROBSTACLEEND = 331,
     OTHEROBSTACLESTART = 332,
     PARTQUANTITYEND = 333,
     PARTQUANTITYSTART = 334,
     PARTREFANDPOSEEND = 335,
     PARTREFANDPOSESTART = 336,
     PARTSKUNAMEEND = 337,
     PARTSKUNAMESTART = 338,
     PARTEND = 339,
     PARTSTART = 340,
     PARTSTRAYEND = 341,
     PARTSTRAYSTART = 342,
     POINTEND = 343,
     POINTSTART = 344,
     PRIMARYLOCATIONEND = 345,
     PRIMARYLOCATIONSTART = 346,
     REFOBJECTEND = 347,
     REFOBJECTSTART = 348,
     ROBOTEND = 349,
     ROBOTSTART = 350,
     SECONDARYLOCATIONEND = 351,
     SECONDARYLOCATIONSTART = 352,
     SERIALNUMBEREND = 353,
     SERIALNUMBERSTART = 354,
     SHAPEEND = 355,
     SHAPESTART = 356,
     SKUNAMEEND = 357,
     SKUNAMESTART = 358,
     SKUEND = 359,
     SKUSTART = 360,
     SOLIDOBJECTEND = 361,
     SOLIDOBJECTSTART = 362,
     TRAYEND = 363,
     TRAYSTART = 364,
     WEIGHTUNITEND = 365,
     WEIGHTUNITSTART = 366,
     WEIGHTEND = 367,
     WEIGHTSTART = 368,
     WIDTHEND = 369,
     WIDTHSTART = 370,
     WORKTABLEEND = 371,
     WORKTABLESTART = 372,
     WORKVOLUMEEND = 373,
     WORKVOLUMESTART = 374,
     XAXISEND = 375,
     XAXISSTART = 376,
     XEND = 377,
     XSTART = 378,
     YEND = 379,
     YSTART = 380,
     ZAXISEND = 381,
     ZAXISSTART = 382,
     ZEND = 383,
     ZSTART = 384,
     BOXVOLUMETYPEDECL = 385,
     BOXYOBJECTTYPEDECL = 386,
     BOXYSHAPETYPEDECL = 387,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 388,
     ENDEFFECTORHOLDERTYPEDECL = 389,
     ENDEFFECTORTYPEDECL = 390,
     GRIPPEREFFECTORTYPEDECL = 391,
     KITDESIGNTYPEDECL = 392,
     KITTRAYTYPEDECL = 393,
     KITTYPEDECL = 394,
     KITTINGWORKSTATIONTYPEDECL = 395,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 396,
     LARGEBOXWITHKITSTYPEDECL = 397,
     LARGECONTAINERTYPEDECL = 398,
     PARTREFANDPOSETYPEDECL = 399,
     PARTTYPEDECL = 400,
     PARTSBINTYPEDECL = 401,
     PARTSTRAYTYPEDECL = 402,
     PARTSTRAYWITHPARTSTYPEDECL = 403,
     PHYSICALLOCATIONTYPEDECL = 404,
     POINTTYPEDECL = 405,
     POSELOCATIONINTYPEDECL = 406,
     POSELOCATIONONTYPEDECL = 407,
     POSELOCATIONTYPEDECL = 408,
     POSEONLYLOCATIONTYPEDECL = 409,
     RELATIVELOCATIONINTYPEDECL = 410,
     RELATIVELOCATIONONTYPEDECL = 411,
     RELATIVELOCATIONTYPEDECL = 412,
     ROBOTTYPEDECL = 413,
     SHAPEDESIGNTYPEDECL = 414,
     STOCKKEEPINGUNITTYPEDECL = 415,
     VACUUMEFFECTORMULTICUPTYPEDECL = 416,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 417,
     VACUUMEFFECTORTYPEDECL = 418,
     VECTORTYPEDECL = 419,
     WORKTABLETYPEDECL = 420
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
  BoxyShapeType *                     BoxyShapeTypeVal;
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


