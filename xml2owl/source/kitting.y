%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#include "kittingClasses.hh"   // for kitting classes

#define YYERROR_VERBOSE
#define YYDEBUG 1

KittingWorkStationFile * KittingWorkStationTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);

%}

%union {
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
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForKittingWorkStationVal> y_XmlHeaderForKittingWorkStation
%type <XmlVersionVal>                 y_XmlVersion
%type <KittingWorkStationFileVal>     y_KittingWorkStationFile
%type <XmlBooleanVal>                 y_XmlBoolean
%type <XmlDecimalVal>                 y_XmlDecimal
%type <XmlIDVal>                      y_XmlID
%type <XmlIDREFVal>                   y_XmlIDREF
%type <XmlNMTOKENVal>                 y_XmlNMTOKEN
%type <XmlNonNegativeIntegerVal>      y_XmlNonNegativeInteger
%type <XmlPositiveIntegerVal>         y_XmlPositiveInteger
%type <XmlStringVal>                  y_XmlString

%type <AngleUnitTypeVal>              y_AngleUnit_AngleUnitType
%type <XmlPositiveIntegerVal>         y_ArrayNumber_XmlPositiveInteger
%type <PositiveDecimalTypeVal>        y_ArrayRadius_PositiveDecimalType
%type <BoxVolumeTypeVal>              y_BoxVolumeType
%type <XmlPositiveIntegerVal>         y_Capacity_XmlPositiveInteger
%type <EndEffectorChangingStationTypeVal> y_ChangingStation_EndEffectorChangingStationType
%type <PositiveDecimalTypeVal>        y_CupDiameter_PositiveDecimalType
%type <XmlStringVal>                  y_Description_XmlString
%type <XmlIDREFVal>                   y_DesignName_XmlIDREF
%type <EndEffectorChangingStationTypeVal> y_EndEffectorChangingStationType
%type <EndEffectorHolderTypeVal>      y_EndEffectorHolderType
%type <EndEffectorHolderTypeVal>      y_EndEffectorHolders_EndEffectorHolderType_u
%type <EndEffectorHolderTypeListVal>  y_EndEffectorHolders_EndEffectorHolderType_uList
%type <XmlIDREFVal>                   y_EndEffectorName_XmlIDREF_0_u
%type <IDREFListVal>                  y_EndEffectorName_XmlIDREF_0_uList
%type <EndEffectorTypeVal>            y_EndEffectorType
%type <EndEffectorTypeVal>            y_EndEffectorTypeAny
%type <EndEffectorTypeVal>            y_EndEffector_EndEffectorType_0
%type <XmlBooleanVal>                 y_Finished_XmlBoolean
%type <PositiveDecimalTypeVal>        y_Height_PositiveDecimalType
%type <XmlDecimalVal>                 y_I_XmlDecimal
%type <XmlDecimalVal>                 y_J_XmlDecimal
%type <XmlDecimalVal>                 y_K_XmlDecimal
%type <XmlIDREFVal>                   y_KitDesignName_XmlIDREF
%type <KitDesignTypeVal>              y_KitDesignType
%type <KitDesignTypeVal>              y_KitDesign_KitDesignType_u
%type <KitDesignTypeListVal>          y_KitDesign_KitDesignType_uList
%type <XmlIDREFVal>                   y_KitTraySkuName_XmlIDREF
%type <KitTrayTypeVal>                y_KitTrayType
%type <KitTrayTypeVal>                y_KitTrays_KitTrayType_0_u
%type <KitTrayTypeListVal>            y_KitTrays_KitTrayType_0_uList
%type <KitTypeVal>                    y_KitType
%type <KitTypeVal>                    y_Kit_KitType_0_u
%type <KitTypeListVal>                y_Kit_KitType_0_uList
%type <KittingWorkstationTypeVal>     y_KittingWorkstationType
%type <LargeContainerTypeVal>         y_LargeContainerType
%type <LargeContainerTypeVal>         y_LargeContainer_LargeContainerType
%type <LengthUnitTypeVal>             y_LengthUnit_LengthUnitType
%type <PositiveDecimalTypeVal>        y_Length_PositiveDecimalType
%type <PositiveDecimalTypeVal>        y_MaximumLoadWeight_PositiveDecimalType
%type <PointTypeVal>                  y_MaximumPoint_PointType
%type <PointTypeVal>                  y_MinimumPoint_PointType
%type <XmlIDVal>                      y_Name_XmlID
%type <SolidObjectTypeVal>            y_Object_SolidObjectType_u
%type <SolidObjectTypeListVal>        y_Object_SolidObjectType_uList
%type <BoxVolumeTypeVal>              y_OtherObstacle_BoxVolumeType_0_u
%type <BoxVolumeTypeListVal>          y_OtherObstacle_BoxVolumeType_0_uList
%type <XmlNonNegativeIntegerVal>      y_PartQuantity_XmlNonNegativeInteger
%type <PartRefAndPoseTypeVal>         y_PartRefAndPoseType
%type <PartRefAndPoseTypeVal>         y_PartRefAndPose_PartRefAndPoseType_u
%type <PartRefAndPoseTypeListVal>     y_PartRefAndPose_PartRefAndPoseType_uList
%type <XmlIDREFVal>                   y_PartSkuName_XmlIDREF
%type <PartTypeVal>                   y_PartType
%type <PartTypeVal>                   y_Part_PartType_0_u
%type <PartTypeListVal>               y_Part_PartType_0_uList
%type <PartsTrayTypeVal>              y_PartsTrayType
%type <PartsTrayTypeVal>              y_PartsTray_PartsTrayType
%type <PhysicalLocationTypeVal>       y_PhysicalLocationType
%type <PhysicalLocationTypeVal>       y_PhysicalLocationTypeAny
%type <PointTypeVal>                  y_PointType
%type <PointTypeVal>                  y_Point_PointType
%type <PhysicalLocationTypeVal>       y_PrimaryLocation_PhysicalLocationType
%type <XmlIDREFVal>                   y_RefObject_XmlIDREF
%type <RobotTypeVal>                  y_RobotType
%type <RobotTypeVal>                  y_Robot_RobotType
%type <PhysicalLocationTypeVal>       y_SecondaryLocation_PhysicalLocationType_0_u
%type <PhysicalLocationTypeListVal>   y_SecondaryLocation_PhysicalLocationType_0_uList
%type <XmlNMTOKENVal>                 y_SerialNumber_XmlNMTOKEN
%type <ShapeDesignTypeVal>            y_ShapeDesignType
%type <ShapeDesignTypeVal>            y_Shape_ShapeDesignType
%type <XmlIDREFVal>                   y_SkuName_XmlIDREF
%type <StockKeepingUnitTypeVal>       y_Sku_StockKeepingUnitType_u
%type <StockKeepingUnitTypeListVal>   y_Sku_StockKeepingUnitType_uList
%type <SolidObjectTypeVal>            y_SolidObjectType
%type <SolidObjectTypeVal>            y_SolidObjectTypeAny
%type <SolidObjectTypeVal>            y_SolidObject_SolidObjectType_0_u
%type <SolidObjectTypeListVal>        y_SolidObject_SolidObjectType_0_uList
%type <StockKeepingUnitTypeVal>       y_StockKeepingUnitType
%type <KitTrayTypeVal>                y_Tray_KitTrayType
%type <VectorTypeVal>                 y_VectorType
%type <WeightUnitTypeVal>             y_WeightUnit_WeightUnitType
%type <PositiveDecimalTypeVal>        y_Weight_PositiveDecimalType
%type <PositiveDecimalTypeVal>        y_Width_PositiveDecimalType
%type <WorkTableTypeVal>              y_WorkTableType
%type <WorkTableTypeVal>              y_WorkTable_WorkTableType
%type <BoxVolumeTypeVal>              y_WorkVolume_BoxVolumeType_u
%type <BoxVolumeTypeListVal>          y_WorkVolume_BoxVolumeType_uList
%type <VectorTypeVal>                 y_XAxis_VectorType
%type <XmlDecimalVal>                 y_X_XmlDecimal
%type <XmlDecimalVal>                 y_Y_XmlDecimal
%type <VectorTypeVal>                 y_ZAxis_VectorType
%type <XmlDecimalVal>                 y_Z_XmlDecimal
%type <BoxyObjectTypeVal>             y_x_BoxyObjectType
%type <EndEffectorChangingStationTypeVal> y_x_EndEffectorChangingStationType
%type <EndEffectorHolderTypeVal>      y_x_EndEffectorHolderType
%type <EndEffectorTypeVal>            y_x_EndEffectorType
%type <GripperEffectorTypeVal>        y_x_GripperEffectorType
%type <KitTrayTypeVal>                y_x_KitTrayType
%type <KitTypeVal>                    y_x_KitType
%type <KittingWorkstationTypeVal>     y_x_KittingWorkstationType
%type <LargeBoxWithEmptyKitTraysTypeVal> y_x_LargeBoxWithEmptyKitTraysType
%type <LargeBoxWithKitsTypeVal>       y_x_LargeBoxWithKitsType
%type <LargeContainerTypeVal>         y_x_LargeContainerType
%type <PartTypeVal>                   y_x_PartType
%type <PartsBinTypeVal>               y_x_PartsBinType
%type <PartsTrayTypeVal>              y_x_PartsTrayType
%type <PartsTrayWithPartsTypeVal>     y_x_PartsTrayWithPartsType
%type <PoseLocationInTypeVal>         y_x_PoseLocationInType
%type <PoseLocationOnTypeVal>         y_x_PoseLocationOnType
%type <PoseLocationTypeVal>           y_x_PoseLocationType
%type <PoseOnlyLocationTypeVal>       y_x_PoseOnlyLocationType
%type <RelativeLocationInTypeVal>     y_x_RelativeLocationInType
%type <RelativeLocationOnTypeVal>     y_x_RelativeLocationOnType
%type <RelativeLocationTypeVal>       y_x_RelativeLocationType
%type <RobotTypeVal>                  y_x_RobotType
%type <VacuumEffectorMultiCupTypeVal> y_x_VacuumEffectorMultiCupType
%type <VacuumEffectorSingleCupTypeVal> y_x_VacuumEffectorSingleCupType
%type <VacuumEffectorTypeVal>         y_x_VacuumEffectorType
%type <WorkTableTypeVal>              y_x_WorkTableType

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

%token <iVal> ANGLEUNITEND
%token <iVal> ANGLEUNITSTART
%token <iVal> ARRAYNUMBEREND
%token <iVal> ARRAYNUMBERSTART
%token <iVal> ARRAYRADIUSEND
%token <iVal> ARRAYRADIUSSTART
%token <iVal> CAPACITYEND
%token <iVal> CAPACITYSTART
%token <iVal> CHANGINGSTATIONEND
%token <iVal> CHANGINGSTATIONSTART
%token <iVal> CUPDIAMETEREND
%token <iVal> CUPDIAMETERSTART
%token <iVal> DESCRIPTIONEND
%token <iVal> DESCRIPTIONSTART
%token <iVal> DESIGNNAMEEND
%token <iVal> DESIGNNAMESTART
%token <iVal> ENDEFFECTORHOLDERSEND
%token <iVal> ENDEFFECTORHOLDERSSTART
%token <iVal> ENDEFFECTORNAMEEND
%token <iVal> ENDEFFECTORNAMESTART
%token <iVal> ENDEFFECTOREND
%token <iVal> ENDEFFECTORSTART
%token <iVal> FINISHEDEND
%token <iVal> FINISHEDSTART
%token <iVal> HEIGHTEND
%token <iVal> HEIGHTSTART
%token <iVal> IEND
%token <iVal> ISTART
%token <iVal> JEND
%token <iVal> JSTART
%token <iVal> KEND
%token <iVal> KSTART
%token <iVal> KITDESIGNNAMEEND
%token <iVal> KITDESIGNNAMESTART
%token <iVal> KITDESIGNEND
%token <iVal> KITDESIGNSTART
%token <iVal> KITTRAYSKUNAMEEND
%token <iVal> KITTRAYSKUNAMESTART
%token <iVal> KITTRAYSEND
%token <iVal> KITTRAYSSTART
%token <iVal> KITEND
%token <iVal> KITSTART
%token <iVal> KITTINGWORKSTATIONEND
%token <iVal> KITTINGWORKSTATIONSTART
%token <iVal> LARGECONTAINEREND
%token <iVal> LARGECONTAINERSTART
%token <iVal> LENGTHUNITEND
%token <iVal> LENGTHUNITSTART
%token <iVal> LENGTHEND
%token <iVal> LENGTHSTART
%token <iVal> MAXIMUMLOADWEIGHTEND
%token <iVal> MAXIMUMLOADWEIGHTSTART
%token <iVal> MAXIMUMPOINTEND
%token <iVal> MAXIMUMPOINTSTART
%token <iVal> MINIMUMPOINTEND
%token <iVal> MINIMUMPOINTSTART
%token <iVal> NAMEEND
%token <iVal> NAMESTART
%token <iVal> OBJECTEND
%token <iVal> OBJECTSTART
%token <iVal> OTHEROBSTACLEEND
%token <iVal> OTHEROBSTACLESTART
%token <iVal> PARTQUANTITYEND
%token <iVal> PARTQUANTITYSTART
%token <iVal> PARTREFANDPOSEEND
%token <iVal> PARTREFANDPOSESTART
%token <iVal> PARTSKUNAMEEND
%token <iVal> PARTSKUNAMESTART
%token <iVal> PARTEND
%token <iVal> PARTSTART
%token <iVal> PARTSTRAYEND
%token <iVal> PARTSTRAYSTART
%token <iVal> POINTEND
%token <iVal> POINTSTART
%token <iVal> PRIMARYLOCATIONEND
%token <iVal> PRIMARYLOCATIONSTART
%token <iVal> REFOBJECTEND
%token <iVal> REFOBJECTSTART
%token <iVal> ROBOTEND
%token <iVal> ROBOTSTART
%token <iVal> SECONDARYLOCATIONEND
%token <iVal> SECONDARYLOCATIONSTART
%token <iVal> SERIALNUMBEREND
%token <iVal> SERIALNUMBERSTART
%token <iVal> SHAPEEND
%token <iVal> SHAPESTART
%token <iVal> SKUNAMEEND
%token <iVal> SKUNAMESTART
%token <iVal> SKUEND
%token <iVal> SKUSTART
%token <iVal> SOLIDOBJECTEND
%token <iVal> SOLIDOBJECTSTART
%token <iVal> TRAYEND
%token <iVal> TRAYSTART
%token <iVal> WEIGHTUNITEND
%token <iVal> WEIGHTUNITSTART
%token <iVal> WEIGHTEND
%token <iVal> WEIGHTSTART
%token <iVal> WIDTHEND
%token <iVal> WIDTHSTART
%token <iVal> WORKTABLEEND
%token <iVal> WORKTABLESTART
%token <iVal> WORKVOLUMEEND
%token <iVal> WORKVOLUMESTART
%token <iVal> XAXISEND
%token <iVal> XAXISSTART
%token <iVal> XEND
%token <iVal> XSTART
%token <iVal> YEND
%token <iVal> YSTART
%token <iVal> ZAXISEND
%token <iVal> ZAXISSTART
%token <iVal> ZEND
%token <iVal> ZSTART


%token <iVal> BOXVOLUMETYPEDECL
%token <iVal> BOXYOBJECTTYPEDECL
%token <iVal> ENDEFFECTORCHANGINGSTATIONTYPEDECL
%token <iVal> ENDEFFECTORHOLDERTYPEDECL
%token <iVal> ENDEFFECTORTYPEDECL
%token <iVal> GRIPPEREFFECTORTYPEDECL
%token <iVal> KITDESIGNTYPEDECL
%token <iVal> KITTRAYTYPEDECL
%token <iVal> KITTYPEDECL
%token <iVal> KITTINGWORKSTATIONTYPEDECL
%token <iVal> LARGEBOXWITHEMPTYKITTRAYSTYPEDECL
%token <iVal> LARGEBOXWITHKITSTYPEDECL
%token <iVal> LARGECONTAINERTYPEDECL
%token <iVal> PARTREFANDPOSETYPEDECL
%token <iVal> PARTTYPEDECL
%token <iVal> PARTSBINTYPEDECL
%token <iVal> PARTSTRAYTYPEDECL
%token <iVal> PARTSTRAYWITHPARTSTYPEDECL
%token <iVal> PHYSICALLOCATIONTYPEDECL
%token <iVal> POINTTYPEDECL
%token <iVal> POSELOCATIONINTYPEDECL
%token <iVal> POSELOCATIONONTYPEDECL
%token <iVal> POSELOCATIONTYPEDECL
%token <iVal> POSEONLYLOCATIONTYPEDECL
%token <iVal> RELATIVELOCATIONINTYPEDECL
%token <iVal> RELATIVELOCATIONONTYPEDECL
%token <iVal> RELATIVELOCATIONTYPEDECL
%token <iVal> ROBOTTYPEDECL
%token <iVal> SHAPEDESIGNTYPEDECL
%token <iVal> STOCKKEEPINGUNITTYPEDECL
%token <iVal> VACUUMEFFECTORMULTICUPTYPEDECL
%token <iVal> VACUUMEFFECTORSINGLECUPTYPEDECL
%token <iVal> VACUUMEFFECTORTYPEDECL
%token <iVal> VECTORTYPEDECL
%token <iVal> WORKTABLETYPEDECL

%%

y_KittingWorkStationFile :
	  y_XmlVersion KITTINGWORKSTATIONSTART y_XmlHeaderForKittingWorkStation
	  y_KittingWorkstationType KITTINGWORKSTATIONEND
	  {$$ = new KittingWorkStationFile($1, $3, $4);
	   KittingWorkStationTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForKittingWorkStation:
	  XMLNSTARGET XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForKittingWorkStation($3);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2);
	    if (strncmp("urn:kitting ", $2, 12))
	      {
		fprintf(stderr,
	           "wrong targetNamespace in schema location %s\n", $2);
		exit(1);
	      }
	  }
	;

y_XmlBoolean :
	  DATASTRING
	  {$$ = new XmlBoolean($1);
	   if ($$->bad)
	     yyerror("bad XmlBoolean");
	  }
	;

y_XmlDecimal :
	  DATASTRING
	  {$$ = new XmlDecimal($1);
	   if ($$->bad)
	     yyerror("bad XmlDecimal");
	  }
	;

y_XmlID :
	  DATASTRING
	  {$$ = new XmlID($1);
	   if ($$->bad)
	     yyerror("bad XmlID");
	  }
	;

y_XmlIDREF :
	  DATASTRING
	  {$$ = new XmlIDREF($1);
	   if ($$->bad)
	     yyerror("bad XmlIDREF");
	  }
	;

y_XmlNMTOKEN :
	  DATASTRING
	  {$$ = new XmlNMTOKEN($1);
	   if ($$->bad)
	     yyerror("bad XmlNMTOKEN");
	  }
	;

y_XmlNonNegativeInteger :
	  DATASTRING
	  {$$ = new XmlNonNegativeInteger($1);
	   if ($$->bad)
	     yyerror("bad XmlNonNegativeInteger");
	  }
	;

y_XmlPositiveInteger :
	  DATASTRING
	  {$$ = new XmlPositiveInteger($1);
	   if ($$->bad)
	     yyerror("bad XmlPositiveInteger");
	  }
	;

y_XmlString :
	  DATASTRING
	  {$$ = new XmlString($1);
	   if ($$->bad)
	     yyerror("bad XmlString");
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

y_AngleUnit_AngleUnitType :
	  ANGLEUNITSTART ENDITEM {yyReadData = 1;} DATASTRING ANGLEUNITEND
	  {$$ = new AngleUnitType($4);
	   if ($$->bad)
	     yyerror("bad AngleUnit value");
	  }
	;

y_ArrayNumber_XmlPositiveInteger :
	  ARRAYNUMBERSTART ENDITEM {yyReadData = 1;} y_XmlPositiveInteger
	  ARRAYNUMBEREND
	  {$$ = $4;}
	;

y_ArrayRadius_PositiveDecimalType :
	  ARRAYRADIUSSTART ENDITEM {yyReadData = 1;} DATASTRING
	  ARRAYRADIUSEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad ArrayRadius value");
	  }
	;

y_BoxVolumeType :
	   ENDITEM y_Name_XmlID y_MaximumPoint_PointType
	  y_MinimumPoint_PointType
	  {$$ = new BoxVolumeType($2, $3, $4);}
	;

y_Capacity_XmlPositiveInteger :
	  CAPACITYSTART ENDITEM {yyReadData = 1;} y_XmlPositiveInteger
	  CAPACITYEND
	  {$$ = $4;}
	;

y_ChangingStation_EndEffectorChangingStationType :
	  CHANGINGSTATIONSTART y_EndEffectorChangingStationType
	  CHANGINGSTATIONEND
	  {$$ = $2;}
	;

y_CupDiameter_PositiveDecimalType :
	  CUPDIAMETERSTART ENDITEM {yyReadData = 1;} DATASTRING
	  CUPDIAMETEREND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad CupDiameter value");
	  }
	;

y_Description_XmlString :
	  DESCRIPTIONSTART ENDITEM {yyReadData = 1;} y_XmlString
	  DESCRIPTIONEND
	  {$$ = $4;}
	;

y_DesignName_XmlIDREF :
	  DESIGNNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  DESIGNNAMEEND
	  {$$ = $4;}
	;

y_EndEffectorChangingStationType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_EndEffectorHolders_EndEffectorHolderType_uList
	  {$$ = new EndEffectorChangingStationType($2, $3, $4, $5);}
	;

y_EndEffectorHolderType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_EndEffector_EndEffectorType_0
	  {$$ = new EndEffectorHolderType($2, $3, $4, $5);}
 	| ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
 	  y_SecondaryLocation_PhysicalLocationType_0_uList
 	  {$$ = new EndEffectorHolderType($2, $3, $4, 0);}
	;

y_EndEffectorHolders_EndEffectorHolderType_u :
	  ENDEFFECTORHOLDERSSTART y_EndEffectorHolderType
	  ENDEFFECTORHOLDERSEND
	  {$$ = $2;}
	;

y_EndEffectorHolders_EndEffectorHolderType_uList :
	  y_EndEffectorHolders_EndEffectorHolderType_u
	  {$$ = new std::list<EndEffectorHolderType *>;
	   $$->push_back($1);}
	| y_EndEffectorHolders_EndEffectorHolderType_uList
	  y_EndEffectorHolders_EndEffectorHolderType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_EndEffectorName_XmlIDREF_0_u :
	  ENDEFFECTORNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  ENDEFFECTORNAMEEND
	  {$$ = $4;}
	;

y_EndEffectorName_XmlIDREF_0_uList :
	  /* empty */
	  {$$ = new std::list<XmlIDREF *>;}
	| y_EndEffectorName_XmlIDREF_0_uList y_EndEffectorName_XmlIDREF_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_EndEffectorType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  {$$ = new EndEffectorType($2, $3, $4, $5, $6, $7);}
	;

y_EndEffectorTypeAny :
	  y_x_GripperEffectorType
	  {$$ = $1;}
	| y_x_VacuumEffectorMultiCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorSingleCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorType
	  {$$ = $1;}
	;

y_EndEffector_EndEffectorType_0 :
	  ENDEFFECTORSTART y_EndEffectorTypeAny ENDEFFECTOREND
	  {$$ = $2;}
	;

y_Finished_XmlBoolean :
	  FINISHEDSTART ENDITEM {yyReadData = 1;} y_XmlBoolean FINISHEDEND
	  {$$ = $4;}
	;

y_Height_PositiveDecimalType :
	  HEIGHTSTART ENDITEM {yyReadData = 1;} DATASTRING HEIGHTEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Height value");
	  }
	;

y_I_XmlDecimal :
	  ISTART ENDITEM {yyReadData = 1;} y_XmlDecimal IEND
	  {$$ = $4;}
	;

y_J_XmlDecimal :
	  JSTART ENDITEM {yyReadData = 1;} y_XmlDecimal JEND
	  {$$ = $4;}
	;

y_K_XmlDecimal :
	  KSTART ENDITEM {yyReadData = 1;} y_XmlDecimal KEND
	  {$$ = $4;}
	;

y_KitDesignName_XmlIDREF :
	  KITDESIGNNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  KITDESIGNNAMEEND
	  {$$ = $4;}
	;

y_KitDesignType :
	   ENDITEM y_Name_XmlID y_KitTraySkuName_XmlIDREF
	  y_PartRefAndPose_PartRefAndPoseType_uList
	  {$$ = new KitDesignType($2, $3, $4);}
	;

y_KitDesign_KitDesignType_u :
	  KITDESIGNSTART y_KitDesignType KITDESIGNEND
	  {$$ = $2;}
	;

y_KitDesign_KitDesignType_uList :
	  y_KitDesign_KitDesignType_u
	  {$$ = new std::list<KitDesignType *>;
	   $$->push_back($1);}
	| y_KitDesign_KitDesignType_uList y_KitDesign_KitDesignType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_KitTraySkuName_XmlIDREF :
	  KITTRAYSKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  KITTRAYSKUNAMEEND
	  {$$ = $4;}
	;

y_KitTrayType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new KitTrayType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_KitTrays_KitTrayType_0_u :
	  KITTRAYSSTART y_KitTrayType KITTRAYSEND
	  {$$ = $2;}
	;

y_KitTrays_KitTrayType_0_uList :
	  /* empty */
	  {$$ = new std::list<KitTrayType *>;}
	| y_KitTrays_KitTrayType_0_uList y_KitTrays_KitTrayType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_KitType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_DesignName_XmlIDREF y_Tray_KitTrayType y_Part_PartType_0_uList
	  y_Finished_XmlBoolean
	  {$$ = new KitType($2, $3, $4, $5, $6, $7, $8);}
	;

y_Kit_KitType_0_u :
	  KITSTART y_KitType KITEND
	  {$$ = $2;}
	;

y_Kit_KitType_0_uList :
	  /* empty */
	  {$$ = new std::list<KitType *>;}
	| y_Kit_KitType_0_uList y_Kit_KitType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_KittingWorkstationType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_AngleUnit_AngleUnitType
	  y_ChangingStation_EndEffectorChangingStationType
	  y_KitDesign_KitDesignType_uList y_LengthUnit_LengthUnitType
	  y_Object_SolidObjectType_uList
	  y_OtherObstacle_BoxVolumeType_0_uList y_Robot_RobotType
	  y_Sku_StockKeepingUnitType_uList y_WeightUnit_WeightUnitType
	  y_WorkTable_WorkTableType
	  {$$ = new KittingWorkstationType($2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14);}
	;

y_LargeContainerType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new LargeContainerType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_LargeContainer_LargeContainerType :
	  LARGECONTAINERSTART y_LargeContainerType LARGECONTAINEREND
	  {$$ = $2;}
	;

y_LengthUnit_LengthUnitType :
	  LENGTHUNITSTART ENDITEM {yyReadData = 1;} DATASTRING
	  LENGTHUNITEND
	  {$$ = new LengthUnitType($4);
	   if ($$->bad)
	     yyerror("bad LengthUnit value");
	  }
	;

y_Length_PositiveDecimalType :
	  LENGTHSTART ENDITEM {yyReadData = 1;} DATASTRING LENGTHEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Length value");
	  }
	;

y_MaximumLoadWeight_PositiveDecimalType :
	  MAXIMUMLOADWEIGHTSTART ENDITEM {yyReadData = 1;} DATASTRING
	  MAXIMUMLOADWEIGHTEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad MaximumLoadWeight value");
	  }
	;

y_MaximumPoint_PointType :
	  MAXIMUMPOINTSTART y_PointType MAXIMUMPOINTEND
	  {$$ = $2;}
	;

y_MinimumPoint_PointType :
	  MINIMUMPOINTSTART y_PointType MINIMUMPOINTEND
	  {$$ = $2;}
	;

y_Name_XmlID :
	  NAMESTART ENDITEM {yyReadData = 1;} y_XmlID NAMEEND
	  {$$ = $4;}
	;

y_Object_SolidObjectType_u :
	  OBJECTSTART y_SolidObjectType OBJECTEND
	  {$$ = $2;}
	| OBJECTSTART y_SolidObjectTypeAny OBJECTEND
	  {$$ = $2;}
	;

y_Object_SolidObjectType_uList :
	  y_Object_SolidObjectType_u
	  {$$ = new std::list<SolidObjectType *>;
	   $$->push_back($1);}
	| y_Object_SolidObjectType_uList y_Object_SolidObjectType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_OtherObstacle_BoxVolumeType_0_u :
	  OTHEROBSTACLESTART y_BoxVolumeType OTHEROBSTACLEEND
	  {$$ = $2;}
	;

y_OtherObstacle_BoxVolumeType_0_uList :
	  /* empty */
	  {$$ = new std::list<BoxVolumeType *>;}
	| y_OtherObstacle_BoxVolumeType_0_uList
	  y_OtherObstacle_BoxVolumeType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_PartQuantity_XmlNonNegativeInteger :
	  PARTQUANTITYSTART ENDITEM {yyReadData = 1;}
	  y_XmlNonNegativeInteger PARTQUANTITYEND
	  {$$ = $4;}
	;

y_PartRefAndPoseType :
	   ENDITEM y_Name_XmlID y_SkuName_XmlIDREF y_Point_PointType
	  y_XAxis_VectorType y_ZAxis_VectorType
	  {$$ = new PartRefAndPoseType($2, $3, $4, $5, $6);}
	;

y_PartRefAndPose_PartRefAndPoseType_u :
	  PARTREFANDPOSESTART y_PartRefAndPoseType PARTREFANDPOSEEND
	  {$$ = $2;}
	;

y_PartRefAndPose_PartRefAndPoseType_uList :
	  y_PartRefAndPose_PartRefAndPoseType_u
	  {$$ = new std::list<PartRefAndPoseType *>;
	   $$->push_back($1);}
	| y_PartRefAndPose_PartRefAndPoseType_uList
	  y_PartRefAndPose_PartRefAndPoseType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_PartSkuName_XmlIDREF :
	  PARTSKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  PARTSKUNAMEEND
	  {$$ = $4;}
	;

y_PartType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartType($2, $3, $4, $5, $6);}
	;

y_Part_PartType_0_u :
	  PARTSTART y_PartType PARTEND
	  {$$ = $2;}
	;

y_Part_PartType_0_uList :
	  /* empty */
	  {$$ = new std::list<PartType *>;}
	| y_Part_PartType_0_uList y_Part_PartType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_PartsTrayType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartsTrayType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_PartsTray_PartsTrayType :
	  PARTSTRAYSTART y_PartsTrayType PARTSTRAYEND
	  {$$ = $2;}
	;

y_PhysicalLocationType :
	   ENDITEM y_Name_XmlID y_RefObject_XmlIDREF
	  {$$ = new PhysicalLocationType($2, $3);}
	;

y_PhysicalLocationTypeAny :
	  y_x_PoseLocationInType
	  {$$ = $1;}
	| y_x_PoseLocationOnType
	  {$$ = $1;}
	| y_x_PoseLocationType
	  {$$ = $1;}
	| y_x_PoseOnlyLocationType
	  {$$ = $1;}
	| y_x_RelativeLocationInType
	  {$$ = $1;}
	| y_x_RelativeLocationOnType
	  {$$ = $1;}
	| y_x_RelativeLocationType
	  {$$ = $1;}
	;

y_PointType :
	   ENDITEM y_Name_XmlID y_X_XmlDecimal y_Y_XmlDecimal
	  y_Z_XmlDecimal
	  {$$ = new PointType($2, $3, $4, $5);}
	;

y_Point_PointType :
	  POINTSTART y_PointType POINTEND
	  {$$ = $2;}
	;

y_PrimaryLocation_PhysicalLocationType :
	  PRIMARYLOCATIONSTART y_PhysicalLocationTypeAny PRIMARYLOCATIONEND
	  {$$ = $2;}
	;

y_RefObject_XmlIDREF :
	  REFOBJECTSTART ENDITEM {yyReadData = 1;} y_XmlIDREF REFOBJECTEND
	  {$$ = $4;}
	;

y_RobotType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_EndEffector_EndEffectorType_0
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_WorkVolume_BoxVolumeType_uList
	  {$$ = new RobotType($2, $3, $4, $5, $6, $7, $8);}
	;

y_Robot_RobotType :
	  ROBOTSTART y_RobotType ROBOTEND
	  {$$ = $2;}
	;

y_SecondaryLocation_PhysicalLocationType_0_u :
	  SECONDARYLOCATIONSTART y_PhysicalLocationType
	  SECONDARYLOCATIONEND
	  {$$ = $2;}
	| SECONDARYLOCATIONSTART y_PhysicalLocationTypeAny
	  SECONDARYLOCATIONEND
	  {$$ = $2;}
	;

y_SecondaryLocation_PhysicalLocationType_0_uList :
	  /* empty */
	  {$$ = new std::list<PhysicalLocationType *>;}
	| y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_SecondaryLocation_PhysicalLocationType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_SerialNumber_XmlNMTOKEN :
	  SERIALNUMBERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  SERIALNUMBEREND
	  {$$ = $4;}
	;

y_ShapeDesignType :
	   ENDITEM y_Name_XmlID y_Description_XmlString
	  {$$ = new ShapeDesignType($2, $3);}
	;

y_Shape_ShapeDesignType :
	  SHAPESTART y_ShapeDesignType SHAPEEND
	  {$$ = $2;}
	;

y_SkuName_XmlIDREF :
	  SKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF SKUNAMEEND
	  {$$ = $4;}
	;

y_Sku_StockKeepingUnitType_u :
	  SKUSTART y_StockKeepingUnitType SKUEND
	  {$$ = $2;}
	;

y_Sku_StockKeepingUnitType_uList :
	  y_Sku_StockKeepingUnitType_u
	  {$$ = new std::list<StockKeepingUnitType *>;
	   $$->push_back($1);}
	| y_Sku_StockKeepingUnitType_uList y_Sku_StockKeepingUnitType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_SolidObjectType :
	  ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  {$$ = new SolidObjectType($2, $3, $4);}
	;

y_SolidObjectTypeAny :
	  y_x_BoxyObjectType
	  {$$ = $1;}
	| y_x_EndEffectorChangingStationType
	  {$$ = $1;}
	| y_x_EndEffectorHolderType
	  {$$ = $1;}
	| y_x_EndEffectorType
	  {$$ = $1;}
	| y_x_GripperEffectorType
	  {$$ = $1;}
	| y_x_KitTrayType
	  {$$ = $1;}
	| y_x_KitType
	  {$$ = $1;}
	| y_x_KittingWorkstationType
	  {$$ = $1;}
	| y_x_LargeBoxWithEmptyKitTraysType
	  {$$ = $1;}
	| y_x_LargeBoxWithKitsType
	  {$$ = $1;}
	| y_x_LargeContainerType
	  {$$ = $1;}
	| y_x_PartType
	  {$$ = $1;}
	| y_x_PartsBinType
	  {$$ = $1;}
	| y_x_PartsTrayType
	  {$$ = $1;}
	| y_x_PartsTrayWithPartsType
	  {$$ = $1;}
	| y_x_RobotType
	  {$$ = $1;}
	| y_x_VacuumEffectorMultiCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorSingleCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorType
	  {$$ = $1;}
	| y_x_WorkTableType
	  {$$ = $1;}
	;

y_SolidObject_SolidObjectType_0_u :
	  SOLIDOBJECTSTART y_SolidObjectType SOLIDOBJECTEND
	  {$$ = $2;}
	| SOLIDOBJECTSTART y_SolidObjectTypeAny SOLIDOBJECTEND
	  {$$ = $2;}
	;

y_SolidObject_SolidObjectType_0_uList :
	  /* empty */
	  {$$ = new std::list<SolidObjectType *>;}
	| y_SolidObject_SolidObjectType_0_uList
	  y_SolidObject_SolidObjectType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_StockKeepingUnitType :
	   ENDITEM y_Name_XmlID y_Description_XmlString
	  y_Shape_ShapeDesignType y_Weight_PositiveDecimalType
	  y_EndEffectorName_XmlIDREF_0_uList
	  {$$ = new StockKeepingUnitType($2, $3, $4, $5, $6);}
	;

y_Tray_KitTrayType :
	  TRAYSTART y_KitTrayType TRAYEND
	  {$$ = $2;}
	;

y_VectorType :
	   ENDITEM y_Name_XmlID y_I_XmlDecimal y_J_XmlDecimal
	  y_K_XmlDecimal
	  {$$ = new VectorType($2, $3, $4, $5);}
	;

y_WeightUnit_WeightUnitType :
	  WEIGHTUNITSTART ENDITEM {yyReadData = 1;} DATASTRING
	  WEIGHTUNITEND
	  {$$ = new WeightUnitType($4);
	   if ($$->bad)
	     yyerror("bad WeightUnit value");
	  }
	;

y_Weight_PositiveDecimalType :
	  WEIGHTSTART ENDITEM {yyReadData = 1;} DATASTRING WEIGHTEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Weight value");
	  }
	;

y_Width_PositiveDecimalType :
	  WIDTHSTART ENDITEM {yyReadData = 1;} DATASTRING WIDTHEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Width value");
	  }
	;

y_WorkTableType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType
	  y_SolidObject_SolidObjectType_0_uList
	  {$$ = new WorkTableType($2, $3, $4, $5, $6, $7, $8);}
	;

y_WorkTable_WorkTableType :
	  WORKTABLESTART y_WorkTableType WORKTABLEEND
	  {$$ = $2;}
	;

y_WorkVolume_BoxVolumeType_u :
	  WORKVOLUMESTART y_BoxVolumeType WORKVOLUMEEND
	  {$$ = $2;}
	;

y_WorkVolume_BoxVolumeType_uList :
	  y_WorkVolume_BoxVolumeType_u
	  {$$ = new std::list<BoxVolumeType *>;
	   $$->push_back($1);}
	| y_WorkVolume_BoxVolumeType_uList y_WorkVolume_BoxVolumeType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_XAxis_VectorType :
	  XAXISSTART y_VectorType XAXISEND
	  {$$ = $2;}
	;

y_X_XmlDecimal :
	  XSTART ENDITEM {yyReadData = 1;} y_XmlDecimal XEND
	  {$$ = $4;}
	;

y_Y_XmlDecimal :
	  YSTART ENDITEM {yyReadData = 1;} y_XmlDecimal YEND
	  {$$ = $4;}
	;

y_ZAxis_VectorType :
	  ZAXISSTART y_VectorType ZAXISEND
	  {$$ = $2;}
	;

y_Z_XmlDecimal :
	  ZSTART ENDITEM {yyReadData = 1;} y_XmlDecimal ZEND
	  {$$ = $4;}
	;

y_x_BoxyObjectType :
	  BOXYOBJECTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType
	  {$$ = new BoxyObjectType($3, $4, $5, $6, $7, $8);
	   $$->printTypp = true;
	  }
	;

y_x_EndEffectorChangingStationType :
	  ENDEFFECTORCHANGINGSTATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_EndEffectorHolders_EndEffectorHolderType_uList
	  {$$ = new EndEffectorChangingStationType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_EndEffectorHolderType :
	  ENDEFFECTORHOLDERTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_EndEffector_EndEffectorType_0
	  {$$ = new EndEffectorHolderType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_EndEffectorType :
	  ENDEFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  {$$ = new EndEffectorType($3, $4, $5, $6, $7, $8);
	   $$->printTypp = true;
	  }
	;

y_x_GripperEffectorType :
	  GRIPPEREFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  {$$ = new GripperEffectorType($3, $4, $5, $6, $7, $8);
	   $$->printTypp = true;
	  }
	;

y_x_KitTrayType :
	  KITTRAYTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new KitTrayType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_KitType :
	  KITTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_DesignName_XmlIDREF y_Tray_KitTrayType y_Part_PartType_0_uList
	  y_Finished_XmlBoolean
	  {$$ = new KitType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_KittingWorkstationType :
	  KITTINGWORKSTATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_AngleUnit_AngleUnitType
	  y_ChangingStation_EndEffectorChangingStationType
	  y_KitDesign_KitDesignType_uList y_LengthUnit_LengthUnitType
	  y_Object_SolidObjectType_uList
	  y_OtherObstacle_BoxVolumeType_0_uList y_Robot_RobotType
	  y_Sku_StockKeepingUnitType_uList y_WeightUnit_WeightUnitType
	  y_WorkTable_WorkTableType
	  {$$ = new KittingWorkstationType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15);
	   $$->printTypp = true;
	  }
	;

y_x_LargeBoxWithEmptyKitTraysType :
	  LARGEBOXWITHEMPTYKITTRAYSTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_LargeContainer_LargeContainerType
	  y_KitTrays_KitTrayType_0_uList
	  {$$ = new LargeBoxWithEmptyKitTraysType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_LargeBoxWithKitsType :
	  LARGEBOXWITHKITSTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_LargeContainer_LargeContainerType y_Kit_KitType_0_uList
	  y_KitDesignName_XmlIDREF y_Capacity_XmlPositiveInteger
	  {$$ = new LargeBoxWithKitsType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_LargeContainerType :
	  LARGECONTAINERTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new LargeContainerType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PartType :
	  PARTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PartsBinType :
	  PARTSBINTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_PartSkuName_XmlIDREF
	  y_PartQuantity_XmlNonNegativeInteger
	  {$$ = new PartsBinType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PartsTrayType :
	  PARTSTRAYTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType y_SkuName_XmlIDREF
	  y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartsTrayType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PartsTrayWithPartsType :
	  PARTSTRAYWITHPARTSTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_PartsTray_PartsTrayType y_Part_PartType_0_uList
	  {$$ = new PartsTrayWithPartsType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationInType :
	  POSELOCATIONINTYPEDECL ENDITEM y_Name_XmlID y_RefObject_XmlIDREF
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  {$$ = new PoseLocationInType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationOnType :
	  POSELOCATIONONTYPEDECL ENDITEM y_Name_XmlID y_RefObject_XmlIDREF
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  {$$ = new PoseLocationOnType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationType :
	  POSELOCATIONTYPEDECL ENDITEM y_Name_XmlID y_RefObject_XmlIDREF
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  {$$ = new PoseLocationType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PoseOnlyLocationType :
	  POSEONLYLOCATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObject_XmlIDREF y_Point_PointType y_XAxis_VectorType
	  y_ZAxis_VectorType
	  {$$ = new PoseOnlyLocationType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationInType :
	  RELATIVELOCATIONINTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObject_XmlIDREF y_Description_XmlString
	  {$$ = new RelativeLocationInType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationOnType :
	  RELATIVELOCATIONONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObject_XmlIDREF y_Description_XmlString
	  {$$ = new RelativeLocationOnType($3, $4, $5);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationType :
	  RELATIVELOCATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObject_XmlIDREF
	  {$$ = new RelativeLocationType($3, $4);
	   $$->printTypp = true;
	  }
	;

y_x_RobotType :
	  ROBOTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_EndEffector_EndEffectorType_0
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_WorkVolume_BoxVolumeType_uList
	  {$$ = new RobotType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_VacuumEffectorMultiCupType :
	  VACUUMEFFECTORMULTICUPTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_CupDiameter_PositiveDecimalType y_Length_PositiveDecimalType
	  y_ArrayNumber_XmlPositiveInteger
	  y_ArrayRadius_PositiveDecimalType
	  {$$ = new VacuumEffectorMultiCupType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12);
	   $$->printTypp = true;
	  }
	;

y_x_VacuumEffectorSingleCupType :
	  VACUUMEFFECTORSINGLECUPTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_CupDiameter_PositiveDecimalType y_Length_PositiveDecimalType
	  {$$ = new VacuumEffectorSingleCupType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_VacuumEffectorType :
	  VACUUMEFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Description_XmlString y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_CupDiameter_PositiveDecimalType y_Length_PositiveDecimalType
	  {$$ = new VacuumEffectorType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_WorkTableType :
	  WORKTABLETYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_SecondaryLocation_PhysicalLocationType_0_uList
	  y_Length_PositiveDecimalType y_Width_PositiveDecimalType
	  y_Height_PositiveDecimalType
	  y_SolidObject_SolidObjectType_0_uList
	  {$$ = new WorkTableType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
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
