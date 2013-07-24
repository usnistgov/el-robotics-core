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
     DIAMETEREND = 287,
     DIAMETERSTART = 288,
     ENDEFFECTORHOLDEREND = 289,
     ENDEFFECTORHOLDERSTART = 290,
     ENDEFFECTORNAMEEND = 291,
     ENDEFFECTORNAMESTART = 292,
     ENDEFFECTOREND = 293,
     ENDEFFECTORSTART = 294,
     EXTERNALSHAPEEND = 295,
     EXTERNALSHAPESTART = 296,
     FINISHEDEND = 297,
     FINISHEDSTART = 298,
     GRASPPOSEEND = 299,
     GRASPPOSESTART = 300,
     HASTOPEND = 301,
     HASTOPSTART = 302,
     HEIGHTEND = 303,
     HEIGHTSTART = 304,
     HELDOBJECTEND = 305,
     HELDOBJECTSTART = 306,
     IEND = 307,
     ISTART = 308,
     INTERNALSHAPEEND = 309,
     INTERNALSHAPESTART = 310,
     JEND = 311,
     JSTART = 312,
     KEND = 313,
     KSTART = 314,
     KITDESIGNNAMEEND = 315,
     KITDESIGNNAMESTART = 316,
     KITDESIGNEND = 317,
     KITDESIGNSTART = 318,
     KITTRAYSKUNAMEEND = 319,
     KITTRAYSKUNAMESTART = 320,
     KITTRAYEND = 321,
     KITTRAYSTART = 322,
     KITEND = 323,
     KITSTART = 324,
     KITTINGWORKSTATIONEND = 325,
     KITTINGWORKSTATIONSTART = 326,
     LARGECONTAINEREND = 327,
     LARGECONTAINERSTART = 328,
     LENGTHUNITEND = 329,
     LENGTHUNITSTART = 330,
     LENGTHEND = 331,
     LENGTHSTART = 332,
     MAXIMUMLOADWEIGHTEND = 333,
     MAXIMUMLOADWEIGHTSTART = 334,
     MAXIMUMPOINTEND = 335,
     MAXIMUMPOINTSTART = 336,
     MINIMUMPOINTEND = 337,
     MINIMUMPOINTSTART = 338,
     MODELFILENAMEEND = 339,
     MODELFILENAMESTART = 340,
     MODELNAMEEND = 341,
     MODELNAMESTART = 342,
     MODELTYPENAMEEND = 343,
     MODELTYPENAMESTART = 344,
     NAMEEND = 345,
     NAMESTART = 346,
     OBJECTEND = 347,
     OBJECTSTART = 348,
     ORIENTATIONSTANDARDDEVIATIONEND = 349,
     ORIENTATIONSTANDARDDEVIATIONSTART = 350,
     OTHEROBSTACLEEND = 351,
     OTHEROBSTACLESTART = 352,
     PARTNAMEEND = 353,
     PARTNAMESTART = 354,
     PARTQUANTITYEND = 355,
     PARTQUANTITYSTART = 356,
     PARTREFANDPOSENAMEEND = 357,
     PARTREFANDPOSENAMESTART = 358,
     PARTREFANDPOSEEND = 359,
     PARTREFANDPOSESTART = 360,
     PARTSKUNAMEEND = 361,
     PARTSKUNAMESTART = 362,
     PARTEND = 363,
     PARTSTART = 364,
     PARTSTRAYEND = 365,
     PARTSTRAYSTART = 366,
     POINTEND = 367,
     POINTSTART = 368,
     POSITIONSTANDARDDEVIATIONEND = 369,
     POSITIONSTANDARDDEVIATIONSTART = 370,
     PRIMARYLOCATIONEND = 371,
     PRIMARYLOCATIONSTART = 372,
     REFOBJECTNAMEEND = 373,
     REFOBJECTNAMESTART = 374,
     ROBOTEND = 375,
     ROBOTSTART = 376,
     SECONDARYLOCATIONEND = 377,
     SECONDARYLOCATIONSTART = 378,
     SERIALNUMBEREND = 379,
     SERIALNUMBERSTART = 380,
     SHAPEEND = 381,
     SHAPESTART = 382,
     SKUNAMEEND = 383,
     SKUNAMESTART = 384,
     SKUEND = 385,
     SKUSTART = 386,
     SLOTEND = 387,
     SLOTSTART = 388,
     SOLIDOBJECTEND = 389,
     SOLIDOBJECTSTART = 390,
     TIMESTAMPEND = 391,
     TIMESTAMPSTART = 392,
     WEIGHTUNITEND = 393,
     WEIGHTUNITSTART = 394,
     WEIGHTEND = 395,
     WEIGHTSTART = 396,
     WIDTHEND = 397,
     WIDTHSTART = 398,
     WORKVOLUMEEND = 399,
     WORKVOLUMESTART = 400,
     XAXISEND = 401,
     XAXISSTART = 402,
     XEND = 403,
     XSTART = 404,
     YEND = 405,
     YSTART = 406,
     ZAXISEND = 407,
     ZAXISSTART = 408,
     ZEND = 409,
     ZSTART = 410,
     BOXVOLUMETYPEDECL = 411,
     BOXYSHAPETYPEDECL = 412,
     CYLINDRICALSHAPETYPEDECL = 413,
     ENDEFFECTORCHANGINGSTATIONTYPEDECL = 414,
     ENDEFFECTORHOLDERTYPEDECL = 415,
     ENDEFFECTORTYPEDECL = 416,
     EXTERNALSHAPETYPEDECL = 417,
     GRIPPEREFFECTORTYPEDECL = 418,
     HUMANTYPEDECL = 419,
     INTERNALSHAPETYPEDECL = 420,
     KITDESIGNTYPEDECL = 421,
     KITTRAYTYPEDECL = 422,
     KITTYPEDECL = 423,
     KITTINGWORKSTATIONTYPEDECL = 424,
     LARGEBOXWITHEMPTYKITTRAYSTYPEDECL = 425,
     LARGEBOXWITHKITSTYPEDECL = 426,
     LARGECONTAINERTYPEDECL = 427,
     MECHANICALCOMPONENTTYPEDECL = 428,
     PARTREFANDPOSETYPEDECL = 429,
     PARTTYPEDECL = 430,
     PARTSBINTYPEDECL = 431,
     PARTSTRAYTYPEDECL = 432,
     PARTSTRAYWITHPARTSTYPEDECL = 433,
     PHYSICALLOCATIONTYPEDECL = 434,
     POINTTYPEDECL = 435,
     POSELOCATIONINTYPEDECL = 436,
     POSELOCATIONONTYPEDECL = 437,
     POSELOCATIONTYPEDECL = 438,
     POSEONLYLOCATIONTYPEDECL = 439,
     RELATIVELOCATIONINTYPEDECL = 440,
     RELATIVELOCATIONONTYPEDECL = 441,
     RELATIVELOCATIONTYPEDECL = 442,
     ROBOTTYPEDECL = 443,
     SHAPEDESIGNTYPEDECL = 444,
     SLOTTYPEDECL = 445,
     STOCKKEEPINGUNITTYPEDECL = 446,
     VACUUMEFFECTORMULTICUPTYPEDECL = 447,
     VACUUMEFFECTORSINGLECUPTYPEDECL = 448,
     VACUUMEFFECTORTYPEDECL = 449,
     VECTORTYPEDECL = 450,
     WORKTABLETYPEDECL = 451
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
  XmlDateTime *                       XmlDateTimeVal;
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
  CylindricalShapeType *              CylindricalShapeTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  std::list<EndEffectorHolderType *> * EndEffectorHolderTypeListVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
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
  std::list<SlotType *> *             SlotTypeListVal;
  SlotType *                          SlotTypeVal;
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


