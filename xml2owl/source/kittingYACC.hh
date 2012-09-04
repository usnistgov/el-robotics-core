/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
     DESIGNREFEND = 283,
     DESIGNREFSTART = 284,
     ENDEFFECTORHOLDERSEND = 285,
     ENDEFFECTORHOLDERSSTART = 286,
     ENDEFFECTORREFEND = 287,
     ENDEFFECTORREFSTART = 288,
     ENDEFFECTOREND = 289,
     ENDEFFECTORSTART = 290,
     FINISHEDEND = 291,
     FINISHEDSTART = 292,
     HEIGHTEND = 293,
     HEIGHTSTART = 294,
     IEND = 295,
     ISTART = 296,
     IDEND = 297,
     IDSTART = 298,
     JEND = 299,
     JSTART = 300,
     KEND = 301,
     KSTART = 302,
     KITDESIGNREFEND = 303,
     KITDESIGNREFSTART = 304,
     KITDESIGNEND = 305,
     KITDESIGNSTART = 306,
     KITTRAYSKUREFEND = 307,
     KITTRAYSKUREFSTART = 308,
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
     PARTSKUREFEND = 335,
     PARTSKUREFSTART = 336,
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
     REFEND = 347,
     REFSTART = 348,
     ROBOTEND = 349,
     ROBOTSTART = 350,
     SECONDARYLOCATIONEND = 351,
     SECONDARYLOCATIONSTART = 352,
     SERIALNUMBEREND = 353,
     SERIALNUMBERSTART = 354,
     SHAPEEND = 355,
     SHAPESTART = 356,
     SKUREFEND = 357,
     SKUREFSTART = 358,
     SKUEND = 359,
     SKUSTART = 360,
     SOLIDOBJECTEND = 361,
     SOLIDOBJECTSTART = 362,
     TRAYEND = 363,
     TRAYSTART = 364,
     TRAYSEND = 365,
     TRAYSSTART = 366,
     WEIGHTUNITEND = 367,
     WEIGHTUNITSTART = 368,
     WEIGHTEND = 369,
     WEIGHTSTART = 370,
     WIDTHEND = 371,
     WIDTHSTART = 372,
     WORKTABLEEND = 373,
     WORKTABLESTART = 374,
     WORKVOLUMEEND = 375,
     WORKVOLUMESTART = 376,
     XAXISEND = 377,
     XAXISSTART = 378,
     XEND = 379,
     XSTART = 380,
     YEND = 381,
     YSTART = 382,
     ZAXISEND = 383,
     ZAXISSTART = 384,
     ZEND = 385,
     ZSTART = 386,
     BOXVOLUMETYPEDECL = 387,
     BOXYOBJECTTYPEDECL = 388,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 389,
     ENDEFFECTORHOLDERTYPEDECL = 390,
     ENDEFFECTORTYPEDECL = 391,
     GRIPPEREFFECTORTYPEDECL = 392,
     KITDESIGNTYPEDECL = 393,
     KITTRAYTYPEDECL = 394,
     KITTYPEDECL = 395,
     KITTINGWORKSTATIONTYPEDECL = 396,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 397,
     LARGEBOXWITHKITSTYPEDECL = 398,
     LARGECONTAINERTYPEDECL = 399,
     PARTREFANDPOSETYPEDECL = 400,
     PARTTYPEDECL = 401,
     PARTSBINTYPEDECL = 402,
     PARTSTRAYTYPEDECL = 403,
     PARTSTRAYWITHPARTSTYPEDECL = 404,
     PHYSICALLOCATIONTYPEDECL = 405,
     POINTTYPEDECL = 406,
     POSELOCATIONINTYPEDECL = 407,
     POSELOCATIONONTYPEDECL = 408,
     POSELOCATIONTYPEDECL = 409,
     POSEONLYLOCATIONTYPEDECL = 410,
     RELATIVELOCATIONINTYPEDECL = 411,
     RELATIVELOCATIONONTYPEDECL = 412,
     RELATIVELOCATIONTYPEDECL = 413,
     ROBOTTYPEDECL = 414,
     SHAPEDESIGNTYPEDECL = 415,
     STOCKKEEPINGUNITTYPEDECL = 416,
     VACUUMEFFECTORMULTICUPTYPEDECL = 417,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 418,
     VACUUMEFFECTORTYPEDECL = 419,
     VECTORTYPEDECL = 420,
     WORKTABLETYPEDECL = 421
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


