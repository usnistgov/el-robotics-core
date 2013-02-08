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
     BASEEND = 275,
     BASESTART = 276,
     CAPACITYEND = 277,
     CAPACITYSTART = 278,
     CHANGINGSTATIONEND = 279,
     CHANGINGSTATIONSTART = 280,
     CUPDIAMETEREND = 281,
     CUPDIAMETERSTART = 282,
     DESCRIPTIONEND = 283,
     DESCRIPTIONSTART = 284,
     DESIGNNAMEEND = 285,
     DESIGNNAMESTART = 286,
     ENDEFFECTORHOLDERSEND = 287,
     ENDEFFECTORHOLDERSSTART = 288,
     ENDEFFECTORNAMEEND = 289,
     ENDEFFECTORNAMESTART = 290,
     ENDEFFECTOREND = 291,
     ENDEFFECTORSTART = 292,
     EXTERNALSHAPEEND = 293,
     EXTERNALSHAPESTART = 294,
     FINISHEDEND = 295,
     FINISHEDSTART = 296,
     GRASPPOSEEND = 297,
     GRASPPOSESTART = 298,
     HASTOPEND = 299,
     HASTOPSTART = 300,
     HEIGHTEND = 301,
     HEIGHTSTART = 302,
     HELDOBJECTEND = 303,
     HELDOBJECTSTART = 304,
     IEND = 305,
     ISTART = 306,
     INTERNALSHAPEEND = 307,
     INTERNALSHAPESTART = 308,
     JEND = 309,
     JSTART = 310,
     KEND = 311,
     KSTART = 312,
     KITDESIGNNAMEEND = 313,
     KITDESIGNNAMESTART = 314,
     KITDESIGNEND = 315,
     KITDESIGNSTART = 316,
     KITTRAYSKUNAMEEND = 317,
     KITTRAYSKUNAMESTART = 318,
     KITTRAYSEND = 319,
     KITTRAYSSTART = 320,
     KITEND = 321,
     KITSTART = 322,
     KITTINGWORKSTATIONEND = 323,
     KITTINGWORKSTATIONSTART = 324,
     LARGECONTAINEREND = 325,
     LARGECONTAINERSTART = 326,
     LENGTHUNITEND = 327,
     LENGTHUNITSTART = 328,
     LENGTHEND = 329,
     LENGTHSTART = 330,
     MAXIMUMLOADWEIGHTEND = 331,
     MAXIMUMLOADWEIGHTSTART = 332,
     MAXIMUMPOINTEND = 333,
     MAXIMUMPOINTSTART = 334,
     MINIMUMPOINTEND = 335,
     MINIMUMPOINTSTART = 336,
     MODELFILENAMEEND = 337,
     MODELFILENAMESTART = 338,
     MODELNAMEEND = 339,
     MODELNAMESTART = 340,
     MODELTYPENAMEEND = 341,
     MODELTYPENAMESTART = 342,
     NAMEEND = 343,
     NAMESTART = 344,
     OBJECTEND = 345,
     OBJECTSTART = 346,
     OTHEROBSTACLEEND = 347,
     OTHEROBSTACLESTART = 348,
     PARTQUANTITYEND = 349,
     PARTQUANTITYSTART = 350,
     PARTREFANDPOSEEND = 351,
     PARTREFANDPOSESTART = 352,
     PARTSKUNAMEEND = 353,
     PARTSKUNAMESTART = 354,
     PARTEND = 355,
     PARTSTART = 356,
     PARTSTRAYEND = 357,
     PARTSTRAYSTART = 358,
     POINTEND = 359,
     POINTSTART = 360,
     PRIMARYLOCATIONEND = 361,
     PRIMARYLOCATIONSTART = 362,
     REFOBJECTEND = 363,
     REFOBJECTSTART = 364,
     ROBOTEND = 365,
     ROBOTSTART = 366,
     SECONDARYLOCATIONEND = 367,
     SECONDARYLOCATIONSTART = 368,
     SERIALNUMBEREND = 369,
     SERIALNUMBERSTART = 370,
     SHAPEEND = 371,
     SHAPESTART = 372,
     SKUNAMEEND = 373,
     SKUNAMESTART = 374,
     SKUEND = 375,
     SKUSTART = 376,
     SOLIDOBJECTEND = 377,
     SOLIDOBJECTSTART = 378,
     TRAYEND = 379,
     TRAYSTART = 380,
     WEIGHTUNITEND = 381,
     WEIGHTUNITSTART = 382,
     WEIGHTEND = 383,
     WEIGHTSTART = 384,
     WIDTHEND = 385,
     WIDTHSTART = 386,
     WORKTABLEEND = 387,
     WORKTABLESTART = 388,
     WORKVOLUMEEND = 389,
     WORKVOLUMESTART = 390,
     XAXISEND = 391,
     XAXISSTART = 392,
     XEND = 393,
     XSTART = 394,
     YEND = 395,
     YSTART = 396,
     ZAXISEND = 397,
     ZAXISSTART = 398,
     ZEND = 399,
     ZSTART = 400,
     BOXVOLUMETYPEDECL = 401,
     BOXYSHAPETYPEDECL = 402,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 403,
     ENDEFFECTORHOLDERTYPEDECL = 404,
     ENDEFFECTORTYPEDECL = 405,
     EXTERNALSHAPETYPEDECL = 406,
     GRIPPEREFFECTORTYPEDECL = 407,
     INTERNALSHAPETYPEDECL = 408,
     KITDESIGNTYPEDECL = 409,
     KITTRAYTYPEDECL = 410,
     KITTYPEDECL = 411,
     KITTINGWORKSTATIONTYPEDECL = 412,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 413,
     LARGEBOXWITHKITSTYPEDECL = 414,
     LARGECONTAINERTYPEDECL = 415,
     MECHANICALCOMPONENTTYPEDECL = 416,
     PARTREFANDPOSETYPEDECL = 417,
     PARTTYPEDECL = 418,
     PARTSBINTYPEDECL = 419,
     PARTSTRAYTYPEDECL = 420,
     PARTSTRAYWITHPARTSTYPEDECL = 421,
     PHYSICALLOCATIONTYPEDECL = 422,
     POINTTYPEDECL = 423,
     POSELOCATIONINTYPEDECL = 424,
     POSELOCATIONONTYPEDECL = 425,
     POSELOCATIONTYPEDECL = 426,
     POSEONLYLOCATIONTYPEDECL = 427,
     RELATIVELOCATIONINTYPEDECL = 428,
     RELATIVELOCATIONONTYPEDECL = 429,
     RELATIVELOCATIONTYPEDECL = 430,
     ROBOTTYPEDECL = 431,
     SHAPEDESIGNTYPEDECL = 432,
     STOCKKEEPINGUNITTYPEDECL = 433,
     VACUUMEFFECTORMULTICUPTYPEDECL = 434,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 435,
     VACUUMEFFECTORTYPEDECL = 436,
     VECTORTYPEDECL = 437,
     WORKTABLETYPEDECL = 438
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForKittingWorkstation *    XmlHeaderForKittingWorkstationVal;
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

  KittingWorkstationFile *            KittingWorkstationFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  std::list<BoxVolumeType *> *        BoxVolumeTypeListVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  std::list<XmlIDREF *> *             IDREFListVal;
  InternalShapeType *                 InternalShapeTypeVal;
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
  MechanicalComponentType *           MechanicalComponentTypeVal;
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


