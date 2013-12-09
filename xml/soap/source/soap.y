%{

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#ifdef OWL
#include "owlSoapClasses.hh"
#else
#include "soapClasses.hh"
#endif

#define YYERROR_VERBOSE
#define YYDEBUG 1

SOAPFile * SOAPTree; // the parse tree

extern int yylex();
int yyReadData = 0;
int yyReadDataList = 0;

int yyerror(const char * s);

%}

%union {
  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForSOAP *                  XmlHeaderForSOAPVal;
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

  SOAPFile *                          SOAPFileVal;

  AngleUnitType *                     AngleUnitTypeVal;
  AnyOrderOrderingConstructType *     AnyOrderOrderingConstructTypeVal;
  AttachEndEffectorType *             AttachEndEffectorTypeVal;
  BoxVolumeType *                     BoxVolumeTypeVal;
  BoxyShapeType *                     BoxyShapeTypeVal;
  CountOrderingConstructType *        CountOrderingConstructTypeVal;
  CreateKitType *                     CreateKitTypeVal;
  CylindricalShapeType *              CylindricalShapeTypeVal;
  DetachEndEffectorType *             DetachEndEffectorTypeVal;
  DomainType *                        DomainTypeVal;
  EffectType *                        EffectTypeVal;
  EndEffectorChangingStationType *    EndEffectorChangingStationTypeVal;
  EndEffectorHolderType *             EndEffectorHolderTypeVal;
  EndEffectorType *                   EndEffectorTypeVal;
  ExistOrderingConstructType *        ExistOrderingConstructTypeVal;
  ExternalShapeType *                 ExternalShapeTypeVal;
  FunctionOperationType *             FunctionOperationTypeVal;
  FunctionToFunctionEqualType *       FunctionToFunctionEqualTypeVal;
  FunctionToFunctionGreaterOrEqualType * FunctionToFunctionGreaterOrEqualTypeVal;
  FunctionToFunctionGreaterType *     FunctionToFunctionGreaterTypeVal;
  FunctionToFunctionLessOrEqualType * FunctionToFunctionLessOrEqualTypeVal;
  FunctionToFunctionLessType *        FunctionToFunctionLessTypeVal;
  FunctionType *                      FunctionTypeVal;
  GripperEffectorType *               GripperEffectorTypeVal;
  HumanType *                         HumanTypeVal;
  InContactWithType *                 InContactWithTypeVal;
  InternalShapeType *                 InternalShapeTypeVal;
  KitDesignType *                     KitDesignTypeVal;
  KitTrayType *                       KitTrayTypeVal;
  KitType *                           KitTypeVal;
  KittingWorkstationType *            KittingWorkstationTypeVal;
  LargeBoxWithEmptyKitTraysType *     LargeBoxWithEmptyKitTraysTypeVal;
  LargeBoxWithKitsType *              LargeBoxWithKitsTypeVal;
  LargeContainerType *                LargeContainerTypeVal;
  LengthUnitType *                    LengthUnitTypeVal;
  std::list<BoxVolumeType *> *        ListBoxVolumeTypeVal;
  std::list<EndEffectorHolderType *> * ListEndEffectorHolderTypeVal;
  std::list<FunctionToFunctionEqualType *> * ListFunctionToFunctionEqualTypeVal;
  std::list<FunctionToFunctionGreaterOrEqualType *> * ListFunctionToFunctionGreaterOrEqualTypeVal;
  std::list<FunctionToFunctionGreaterType *> * ListFunctionToFunctionGreaterTypeVal;
  std::list<FunctionToFunctionLessOrEqualType *> * ListFunctionToFunctionLessOrEqualTypeVal;
  std::list<FunctionToFunctionLessType *> * ListFunctionToFunctionLessTypeVal;
  std::list<FunctionType *> *         ListFunctionTypeVal;
  std::list<KitDesignType *> *        ListKitDesignTypeVal;
  std::list<KitTrayType *> *          ListKitTrayTypeVal;
  std::list<KitType *> *              ListKitTypeVal;
  std::list<PartRefAndPoseType *> *   ListPartRefAndPoseTypeVal;
  std::list<PartType *> *             ListPartTypeVal;
  std::list<PhysicalLocationType *> * ListPhysicalLocationTypeVal;
  std::list<PredicateGroupElementType *> * ListPredicateGroupElementTypeVal;
  std::list<PredicateType *> *        ListPredicateTypeVal;
  std::list<SlotType *> *             ListSlotTypeVal;
  std::list<SolidObjectType *> *      ListSolidObjectTypeVal;
  std::list<StockKeepingUnitType *> * ListStockKeepingUnitTypeVal;
  std::list<XmlIDREF *> *             ListXmlIDREFVal;
  std::list<XmlNMTOKEN *> *           ListXmlNMTOKENVal;
  MechanicalComponentType *           MechanicalComponentTypeVal;
  NoSkuObjectType *                   NoSkuObjectTypeVal;
  OnTopWithContactType *              OnTopWithContactTypeVal;
  PartRefAndPoseType *                PartRefAndPoseTypeVal;
  PartType *                          PartTypeVal;
  PartiallyInType *                   PartiallyInTypeVal;
  PartsBinType *                      PartsBinTypeVal;
  PartsTrayType *                     PartsTrayTypeVal;
  PartsVesselType *                   PartsVesselTypeVal;
  PhysicalLocationType *              PhysicalLocationTypeVal;
  PointType *                         PointTypeVal;
  PoseLocationInType *                PoseLocationInTypeVal;
  PoseLocationOnType *                PoseLocationOnTypeVal;
  PoseLocationType *                  PoseLocationTypeVal;
  PoseOnlyLocationType *              PoseOnlyLocationTypeVal;
  PositiveDecimalType *               PositiveDecimalTypeVal;
  PreconditionType *                  PreconditionTypeVal;
  PredicateGroupElementType *         PredicateGroupElementTypeVal;
  PredicateType *                     PredicateTypeVal;
  PutKitTrayType *                    PutKitTrayTypeVal;
  PutKitType *                        PutKitTypeVal;
  PutPartType *                       PutPartTypeVal;
  RelativeLocationInType *            RelativeLocationInTypeVal;
  RelativeLocationOnType *            RelativeLocationOnTypeVal;
  RelativeLocationType *              RelativeLocationTypeVal;
  RobotType *                         RobotTypeVal;
  SOAPType *                          SOAPTypeVal;
  SkuObjectType *                     SkuObjectTypeVal;
  SlotType *                          SlotTypeVal;
  SolidObjectType *                   SolidObjectTypeVal;
  StockKeepingUnitType *              StockKeepingUnitTypeVal;
  TakeKitTrayType *                   TakeKitTrayTypeVal;
  TakeKitType *                       TakeKitTypeVal;
  TakePartType *                      TakePartTypeVal;
  UnderWithContactType *              UnderWithContactTypeVal;
  VacuumEffectorMultiCupType *        VacuumEffectorMultiCupTypeVal;
  VacuumEffectorSingleCupType *       VacuumEffectorSingleCupTypeVal;
  VacuumEffectorType *                VacuumEffectorTypeVal;
  VectorType *                        VectorTypeVal;
  WeightUnitType *                    WeightUnitTypeVal;
  WorkTableType *                     WorkTableTypeVal;
}

%type <SchemaLocationVal>             y_SchemaLocation
%type <XmlHeaderForSOAPVal>           y_XmlHeaderForSOAP
%type <XmlVersionVal>                 y_XmlVersion
%type <SOAPFileVal>                   y_SOAPFile
%type <XmlBooleanVal>                 y_XmlBoolean
%type <XmlDateTimeVal>                y_XmlDateTime
%type <XmlDecimalVal>                 y_XmlDecimal
%type <XmlIDVal>                      y_XmlID
%type <XmlIDREFVal>                   y_XmlIDREF
%type <XmlNMTOKENVal>                 y_XmlNMTOKEN
%type <XmlNonNegativeIntegerVal>      y_XmlNonNegativeInteger
%type <XmlPositiveIntegerVal>         y_XmlPositiveInteger
%type <XmlStringVal>                  y_XmlString

%type <XmlDecimalVal>                 y_A1_XmlDecimal
%type <AngleUnitTypeVal>              y_AngleUnit_AngleUnitType
%type <AnyOrderOrderingConstructTypeVal> y_AnyOrderOrderingConstructType
%type <AnyOrderOrderingConstructTypeVal> y_AnyOrderOrderingConstruct_AnyOrderOrderingConstructType
%type <XmlPositiveIntegerVal>         y_ArrayNumber_XmlPositiveInteger
%type <PositiveDecimalTypeVal>        y_ArrayRadius_PositiveDecimalType
%type <AttachEndEffectorTypeVal>      y_AttachEndEffectorType
%type <AttachEndEffectorTypeVal>      y_AttachEndEffector_AttachEndEffectorType
%type <MechanicalComponentTypeVal>    y_Base_MechanicalComponentType
%type <BoxVolumeTypeVal>              y_BoxVolumeType
%type <XmlPositiveIntegerVal>         y_Capacity_XmlPositiveInteger
%type <EndEffectorChangingStationTypeVal> y_ChangingStation_EndEffectorChangingStationType
%type <CountOrderingConstructTypeVal> y_CountOrderingConstructType
%type <CountOrderingConstructTypeVal> y_CountOrderingConstruct_CountOrderingConstructType
%type <CreateKitTypeVal>              y_CreateKitType
%type <CreateKitTypeVal>              y_CreateKit_CreateKitType
%type <PositiveDecimalTypeVal>        y_CupDiameter_PositiveDecimalType
%type <XmlStringVal>                  y_Description_XmlString
%type <XmlStringVal>                  y_Description_XmlString_0
%type <XmlIDREFVal>                   y_DesignName_XmlIDREF
%type <DetachEndEffectorTypeVal>      y_DetachEndEffectorType
%type <DetachEndEffectorTypeVal>      y_DetachEndEffector_DetachEndEffectorType
%type <PositiveDecimalTypeVal>        y_Diameter_PositiveDecimalType
%type <DomainTypeVal>                 y_DomainType
%type <DomainTypeVal>                 y_Domain_DomainType
%type <EffectTypeVal>                 y_EffectType
%type <EffectTypeVal>                 y_Effect_EffectType
%type <XmlNMTOKENVal>                 y_EndEffectorChangingStationParameter_XmlNMTOKEN
%type <EndEffectorChangingStationTypeVal> y_EndEffectorChangingStationType
%type <XmlNMTOKENVal>                 y_EndEffectorHolderParameter_XmlNMTOKEN
%type <EndEffectorHolderTypeVal>      y_EndEffectorHolderType
%type <EndEffectorHolderTypeVal>      y_EndEffectorHolder_EndEffectorHolderType_u
%type <XmlIDREFVal>                   y_EndEffectorName_XmlIDREF_0_u
%type <XmlNMTOKENVal>                 y_EndEffectorParameter_XmlNMTOKEN
%type <EndEffectorTypeVal>            y_EndEffectorTypeAny
%type <EndEffectorTypeVal>            y_EndEffector_EndEffectorType_0
%type <ExistOrderingConstructTypeVal> y_ExistOrderingConstructType
%type <ExistOrderingConstructTypeVal> y_ExistOrderingConstruct_ExistOrderingConstructType
%type <XmlNMTOKENVal>                 y_Expression_XmlNMTOKEN
%type <ExternalShapeTypeVal>          y_ExternalShapeType
%type <ExternalShapeTypeVal>          y_ExternalShape_ExternalShapeType_0
%type <FunctionToFunctionEqualTypeVal> y_F1EqualF2_FunctionToFunctionEqualType_0_u
%type <FunctionToFunctionGreaterTypeVal> y_F1GreaterF2_FunctionToFunctionGreaterType_0_u
%type <FunctionToFunctionGreaterOrEqualTypeVal> y_F1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
%type <FunctionToFunctionLessTypeVal> y_F1LessF2_FunctionToFunctionLessType_0_u
%type <FunctionToFunctionLessOrEqualTypeVal> y_F1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
%type <XmlIDREFVal>                   y_F1Name_XmlIDREF
%type <XmlIDREFVal>                   y_F2Name_XmlIDREF
%type <XmlBooleanVal>                 y_Finished_XmlBoolean
%type <XmlIDREFVal>                   y_FunctionName_XmlIDREF
%type <XmlIDREFVal>                   y_FunctionName_XmlIDREF_0
%type <FunctionOperationTypeVal>      y_FunctionOperationType
%type <FunctionOperationTypeVal>      y_FunctionOperation_FunctionOperationType_0
%type <FunctionToFunctionEqualTypeVal> y_FunctionToFunctionEqualType
%type <FunctionToFunctionGreaterOrEqualTypeVal> y_FunctionToFunctionGreaterOrEqualType
%type <FunctionToFunctionGreaterTypeVal> y_FunctionToFunctionGreaterType
%type <FunctionToFunctionLessOrEqualTypeVal> y_FunctionToFunctionLessOrEqualType
%type <FunctionToFunctionLessTypeVal> y_FunctionToFunctionLessType
%type <FunctionTypeVal>               y_FunctionType
%type <FunctionTypeVal>               y_Function_FunctionType_u
%type <PoseLocationTypeVal>           y_GraspPose_PoseLocationType_0
%type <XmlBooleanVal>                 y_HasTop_XmlBoolean
%type <PositiveDecimalTypeVal>        y_Height_PositiveDecimalType
%type <SolidObjectTypeVal>            y_HeldObject_SolidObjectType_0
%type <XmlDecimalVal>                 y_I_XmlDecimal
%type <InContactWithTypeVal>          y_InContactWithType
%type <InContactWithTypeVal>          y_InContactWith_InContactWithType
%type <InternalShapeTypeVal>          y_InternalShapeTypeAny
%type <InternalShapeTypeVal>          y_InternalShape_InternalShapeType_0
%type <XmlDecimalVal>                 y_J_XmlDecimal
%type <XmlDecimalVal>                 y_K_XmlDecimal
%type <XmlIDREFVal>                   y_KitDesignName_XmlIDREF
%type <KitDesignTypeVal>              y_KitDesignType
%type <KitDesignTypeVal>              y_KitDesign_KitDesignType_u
%type <XmlNMTOKENVal>                 y_KitParameter_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_KitTrayParameter_XmlNMTOKEN
%type <XmlIDREFVal>                   y_KitTraySkuName_XmlIDREF
%type <KitTrayTypeVal>                y_KitTrayType
%type <KitTrayTypeVal>                y_KitTray_KitTrayType
%type <KitTrayTypeVal>                y_KitTray_KitTrayType_0_u
%type <KitTypeVal>                    y_KitType
%type <KitTypeVal>                    y_Kit_KitType_0_u
%type <KittingWorkstationTypeVal>     y_KittingWorkstationType
%type <KittingWorkstationTypeVal>     y_KittingWorkstation_KittingWorkstationType
%type <XmlNMTOKENVal>                 y_LargeBoxWithEmptyKitTraysParameter_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_LargeBoxWithKitsParameter_XmlNMTOKEN
%type <LargeContainerTypeVal>         y_LargeContainerType
%type <LargeContainerTypeVal>         y_LargeContainer_LargeContainerType
%type <LengthUnitTypeVal>             y_LengthUnit_LengthUnitType
%type <PositiveDecimalTypeVal>        y_Length_PositiveDecimalType
%type <ListEndEffectorHolderTypeVal>  y_ListEndEffectorHolder_EndEffectorHolderType_u
%type <ListXmlIDREFVal>               y_ListEndEffectorName_XmlIDREF_0_u
%type <ListFunctionToFunctionEqualTypeVal> y_ListF1EqualF2_FunctionToFunctionEqualType_0_u
%type <ListFunctionToFunctionGreaterTypeVal> y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u
%type <ListFunctionToFunctionGreaterOrEqualTypeVal> y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
%type <ListFunctionToFunctionLessTypeVal> y_ListF1LessF2_FunctionToFunctionLessType_0_u
%type <ListFunctionToFunctionLessOrEqualTypeVal> y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
%type <ListFunctionTypeVal>           y_ListFunction_FunctionType_u
%type <ListKitDesignTypeVal>          y_ListKitDesign_KitDesignType_u
%type <ListKitTrayTypeVal>            y_ListKitTray_KitTrayType_0_u
%type <ListKitTypeVal>                y_ListKit_KitType_0_u
%type <ListXmlIDREFVal>               y_ListNotPredicateName_XmlIDREF_0_u
%type <ListSolidObjectTypeVal>        y_ListObjectOnTable_SolidObjectType_0_u
%type <ListSolidObjectTypeVal>        y_ListObject_SolidObjectType_u
%type <ListBoxVolumeTypeVal>          y_ListOtherObstacle_BoxVolumeType_0_u
%type <ListPartRefAndPoseTypeVal>     y_ListPartRefAndPose_PartRefAndPoseType_u
%type <ListPartTypeVal>               y_ListPart_PartType_0_u
%type <ListPredicateGroupElementTypeVal> y_ListPredicateGroupElement_PredicateGroupElementType_u
%type <ListXmlIDREFVal>               y_ListPredicateName_XmlIDREF_0_u
%type <ListXmlIDREFVal>               y_ListPredicateName_XmlIDREF_u
%type <ListPredicateTypeVal>          y_ListPredicate_PredicateType_u
%type <ListXmlNMTOKENVal>             y_ListRequirement_XmlNMTOKEN_u
%type <ListPhysicalLocationTypeVal>   y_ListSecondaryLocation_PhysicalLocationType_0_u
%type <ListStockKeepingUnitTypeVal>   y_ListSku_StockKeepingUnitType_u
%type <ListSlotTypeVal>               y_ListSlot_SlotType_0_u
%type <ListXmlNMTOKENVal>             y_ListVariable_XmlNMTOKEN_u
%type <ListBoxVolumeTypeVal>          y_ListWorkVolume_BoxVolumeType_u
%type <PositiveDecimalTypeVal>        y_MaximumLoadWeight_PositiveDecimalType
%type <PointTypeVal>                  y_MaximumPoint_PointType
%type <MechanicalComponentTypeVal>    y_MechanicalComponentType
%type <PointTypeVal>                  y_MinimumPoint_PointType
%type <XmlStringVal>                  y_ModelFileName_XmlString
%type <XmlStringVal>                  y_ModelFormatName_XmlString
%type <XmlStringVal>                  y_ModelName_XmlString_0
%type <XmlIDVal>                      y_Name_XmlID
%type <XmlIDREFVal>                   y_NotPredicateName_XmlIDREF_0_u
%type <SolidObjectTypeVal>            y_ObjectOnTable_SolidObjectType_0_u
%type <SolidObjectTypeVal>            y_Object_SolidObjectType_u
%type <OnTopWithContactTypeVal>       y_OnTopWithContactType
%type <OnTopWithContactTypeVal>       y_OnTopWithContact_OnTopWithContactType
%type <PositiveDecimalTypeVal>        y_OrientationStandardDeviation_PositiveDecimalType_0
%type <BoxVolumeTypeVal>              y_OtherObstacle_BoxVolumeType_0_u
%type <XmlIDREFVal>                   y_PartName_XmlIDREF_0
%type <XmlNMTOKENVal>                 y_PartParameter_XmlNMTOKEN
%type <XmlNonNegativeIntegerVal>      y_PartQuantity_XmlNonNegativeInteger
%type <XmlIDREFVal>                   y_PartRefAndPoseName_XmlIDREF
%type <PartRefAndPoseTypeVal>         y_PartRefAndPoseType
%type <PartRefAndPoseTypeVal>         y_PartRefAndPose_PartRefAndPoseType_u
%type <XmlIDREFVal>                   y_PartSkuName_XmlIDREF
%type <PartTypeVal>                   y_PartType
%type <PartTypeVal>                   y_Part_PartType_0_u
%type <PartiallyInTypeVal>            y_PartiallyInType
%type <PartiallyInTypeVal>            y_PartiallyIn_PartiallyInType
%type <XmlNMTOKENVal>                 y_PartsTrayParameter_XmlNMTOKEN
%type <PhysicalLocationTypeVal>       y_PhysicalLocationTypeAny
%type <PointTypeVal>                  y_PointType
%type <PointTypeVal>                  y_Point_PointType
%type <PoseLocationTypeVal>           y_PoseLocationTypeAny
%type <XmlPositiveIntegerVal>         y_PositionInOrderedList_XmlPositiveInteger
%type <PositiveDecimalTypeVal>        y_PositionStandardDeviation_PositiveDecimalType_0
%type <PreconditionTypeVal>           y_PreconditionType
%type <PreconditionTypeVal>           y_Precondition_PreconditionType
%type <PredicateGroupElementTypeVal>  y_PredicateGroupElementType
%type <PredicateGroupElementTypeVal>  y_PredicateGroupElement_PredicateGroupElementType_u
%type <XmlIDREFVal>                   y_PredicateName_XmlIDREF_0_u
%type <XmlIDREFVal>                   y_PredicateName_XmlIDREF_u
%type <XmlPositiveIntegerVal>         y_PredicateOccurrence_XmlPositiveInteger
%type <PredicateTypeVal>              y_PredicateType
%type <PredicateTypeVal>              y_Predicate_PredicateType
%type <PredicateTypeVal>              y_Predicate_PredicateType_u
%type <PhysicalLocationTypeVal>       y_PrimaryLocation_PhysicalLocationType
%type <PutKitTrayTypeVal>             y_PutKitTrayType
%type <PutKitTrayTypeVal>             y_PutKitTray_PutKitTrayType
%type <PutKitTypeVal>                 y_PutKitType
%type <PutKitTypeVal>                 y_PutKit_PutKitType
%type <PutPartTypeVal>                y_PutPartType
%type <PutPartTypeVal>                y_PutPart_PutPartType
%type <XmlStringVal>                  y_RCC8Set_XmlString
%type <XmlIDREFVal>                   y_RefObjectName_XmlIDREF
%type <XmlNMTOKENVal>                 y_ReferenceName_XmlNMTOKEN
%type <XmlNMTOKENVal>                 y_Requirement_XmlNMTOKEN_u
%type <XmlNMTOKENVal>                 y_RobotParameter_XmlNMTOKEN
%type <RobotTypeVal>                  y_RobotType
%type <RobotTypeVal>                  y_Robot_RobotType
%type <SOAPTypeVal>                   y_SOAPType
%type <PhysicalLocationTypeVal>       y_SecondaryLocation_PhysicalLocationType_0_u
%type <XmlNMTOKENVal>                 y_SerialNumber_XmlNMTOKEN
%type <XmlIDREFVal>                   y_SkuName_XmlIDREF
%type <StockKeepingUnitTypeVal>       y_Sku_StockKeepingUnitType_u
%type <SlotTypeVal>                   y_SlotType
%type <SlotTypeVal>                   y_Slot_SlotType_0_u
%type <SolidObjectTypeVal>            y_SolidObjectTypeAny
%type <XmlIDREFVal>                   y_StateRelationName_XmlIDREF_0
%type <StockKeepingUnitTypeVal>       y_StockKeepingUnitType
%type <TakeKitTrayTypeVal>            y_TakeKitTrayType
%type <TakeKitTrayTypeVal>            y_TakeKitTray_TakeKitTrayType
%type <TakeKitTypeVal>                y_TakeKitType
%type <TakeKitTypeVal>                y_TakeKit_TakeKitType
%type <TakePartTypeVal>               y_TakePartType
%type <TakePartTypeVal>               y_TakePart_TakePartType
%type <XmlNMTOKENVal>                 y_TargetName_XmlNMTOKEN_0
%type <XmlDateTimeVal>                y_Timestamp_XmlDateTime_0
%type <UnderWithContactTypeVal>       y_UnderWithContactType
%type <UnderWithContactTypeVal>       y_UnderWithContact_UnderWithContactType
%type <XmlPositiveIntegerVal>         y_Value_XmlPositiveInteger
%type <XmlNMTOKENVal>                 y_Variable_XmlNMTOKEN_u
%type <VectorTypeVal>                 y_VectorType
%type <WeightUnitTypeVal>             y_WeightUnit_WeightUnitType
%type <PositiveDecimalTypeVal>        y_Weight_PositiveDecimalType
%type <PositiveDecimalTypeVal>        y_Width_PositiveDecimalType
%type <XmlNMTOKENVal>                 y_WorkTableParameter_XmlNMTOKEN
%type <BoxVolumeTypeVal>              y_WorkVolume_BoxVolumeType_u
%type <VectorTypeVal>                 y_XAxis_VectorType
%type <XmlDecimalVal>                 y_X_XmlDecimal
%type <XmlDecimalVal>                 y_Y_XmlDecimal
%type <VectorTypeVal>                 y_ZAxis_VectorType
%type <XmlDecimalVal>                 y_Z_XmlDecimal
%type <BoxyShapeTypeVal>              y_x_BoxyShapeType
%type <CylindricalShapeTypeVal>       y_x_CylindricalShapeType
%type <EndEffectorChangingStationTypeVal> y_x_EndEffectorChangingStationType
%type <EndEffectorHolderTypeVal>      y_x_EndEffectorHolderType
%type <GripperEffectorTypeVal>        y_x_GripperEffectorType
%type <HumanTypeVal>                  y_x_HumanType
%type <KitTrayTypeVal>                y_x_KitTrayType
%type <KitTypeVal>                    y_x_KitType
%type <KittingWorkstationTypeVal>     y_x_KittingWorkstationType
%type <LargeBoxWithEmptyKitTraysTypeVal> y_x_LargeBoxWithEmptyKitTraysType
%type <LargeBoxWithKitsTypeVal>       y_x_LargeBoxWithKitsType
%type <LargeContainerTypeVal>         y_x_LargeContainerType
%type <MechanicalComponentTypeVal>    y_x_MechanicalComponentType
%type <PartTypeVal>                   y_x_PartType
%type <PartsBinTypeVal>               y_x_PartsBinType
%type <PartsTrayTypeVal>              y_x_PartsTrayType
%type <PoseLocationInTypeVal>         y_x_PoseLocationInType
%type <PoseLocationOnTypeVal>         y_x_PoseLocationOnType
%type <PoseOnlyLocationTypeVal>       y_x_PoseOnlyLocationType
%type <RelativeLocationInTypeVal>     y_x_RelativeLocationInType
%type <RelativeLocationOnTypeVal>     y_x_RelativeLocationOnType
%type <RobotTypeVal>                  y_x_RobotType
%type <VacuumEffectorMultiCupTypeVal> y_x_VacuumEffectorMultiCupType
%type <VacuumEffectorSingleCupTypeVal> y_x_VacuumEffectorSingleCupType
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

%token <iVal> A1END
%token <iVal> A1START
%token <iVal> ANGLEUNITEND
%token <iVal> ANGLEUNITSTART
%token <iVal> ANYORDERORDERINGCONSTRUCTEND
%token <iVal> ANYORDERORDERINGCONSTRUCTSTART
%token <iVal> ARRAYNUMBEREND
%token <iVal> ARRAYNUMBERSTART
%token <iVal> ARRAYRADIUSEND
%token <iVal> ARRAYRADIUSSTART
%token <iVal> ATTACHENDEFFECTOREND
%token <iVal> ATTACHENDEFFECTORSTART
%token <iVal> BASEEND
%token <iVal> BASESTART
%token <iVal> CAPACITYEND
%token <iVal> CAPACITYSTART
%token <iVal> CHANGINGSTATIONEND
%token <iVal> CHANGINGSTATIONSTART
%token <iVal> COUNTORDERINGCONSTRUCTEND
%token <iVal> COUNTORDERINGCONSTRUCTSTART
%token <iVal> CREATEKITEND
%token <iVal> CREATEKITSTART
%token <iVal> CUPDIAMETEREND
%token <iVal> CUPDIAMETERSTART
%token <iVal> DESCRIPTIONEND
%token <iVal> DESCRIPTIONSTART
%token <iVal> DESIGNNAMEEND
%token <iVal> DESIGNNAMESTART
%token <iVal> DETACHENDEFFECTOREND
%token <iVal> DETACHENDEFFECTORSTART
%token <iVal> DIAMETEREND
%token <iVal> DIAMETERSTART
%token <iVal> DOMAINEND
%token <iVal> DOMAINSTART
%token <iVal> EFFECTEND
%token <iVal> EFFECTSTART
%token <iVal> ENDEFFECTORCHANGINGSTATIONPARAMETEREND
%token <iVal> ENDEFFECTORCHANGINGSTATIONPARAMETERSTART
%token <iVal> ENDEFFECTORHOLDERPARAMETEREND
%token <iVal> ENDEFFECTORHOLDERPARAMETERSTART
%token <iVal> ENDEFFECTORHOLDEREND
%token <iVal> ENDEFFECTORHOLDERSTART
%token <iVal> ENDEFFECTORNAMEEND
%token <iVal> ENDEFFECTORNAMESTART
%token <iVal> ENDEFFECTORPARAMETEREND
%token <iVal> ENDEFFECTORPARAMETERSTART
%token <iVal> ENDEFFECTOREND
%token <iVal> ENDEFFECTORSTART
%token <iVal> EXISTORDERINGCONSTRUCTEND
%token <iVal> EXISTORDERINGCONSTRUCTSTART
%token <iVal> EXPRESSIONEND
%token <iVal> EXPRESSIONSTART
%token <iVal> EXTERNALSHAPEEND
%token <iVal> EXTERNALSHAPESTART
%token <iVal> F1EQUALF2END
%token <iVal> F1EQUALF2START
%token <iVal> F1GREATERF2END
%token <iVal> F1GREATERF2START
%token <iVal> F1GREATEROREQUALF2END
%token <iVal> F1GREATEROREQUALF2START
%token <iVal> F1LESSF2END
%token <iVal> F1LESSF2START
%token <iVal> F1LESSOREQUALF2END
%token <iVal> F1LESSOREQUALF2START
%token <iVal> F1NAMEEND
%token <iVal> F1NAMESTART
%token <iVal> F2NAMEEND
%token <iVal> F2NAMESTART
%token <iVal> FINISHEDEND
%token <iVal> FINISHEDSTART
%token <iVal> FUNCTIONNAMEEND
%token <iVal> FUNCTIONNAMESTART
%token <iVal> FUNCTIONOPERATIONEND
%token <iVal> FUNCTIONOPERATIONSTART
%token <iVal> FUNCTIONEND
%token <iVal> FUNCTIONSTART
%token <iVal> GRASPPOSEEND
%token <iVal> GRASPPOSESTART
%token <iVal> HASTOPEND
%token <iVal> HASTOPSTART
%token <iVal> HEIGHTEND
%token <iVal> HEIGHTSTART
%token <iVal> HELDOBJECTEND
%token <iVal> HELDOBJECTSTART
%token <iVal> IEND
%token <iVal> ISTART
%token <iVal> INCONTACTWITHEND
%token <iVal> INCONTACTWITHSTART
%token <iVal> INTERNALSHAPEEND
%token <iVal> INTERNALSHAPESTART
%token <iVal> JEND
%token <iVal> JSTART
%token <iVal> KEND
%token <iVal> KSTART
%token <iVal> KITDESIGNNAMEEND
%token <iVal> KITDESIGNNAMESTART
%token <iVal> KITDESIGNEND
%token <iVal> KITDESIGNSTART
%token <iVal> KITPARAMETEREND
%token <iVal> KITPARAMETERSTART
%token <iVal> KITTRAYPARAMETEREND
%token <iVal> KITTRAYPARAMETERSTART
%token <iVal> KITTRAYSKUNAMEEND
%token <iVal> KITTRAYSKUNAMESTART
%token <iVal> KITTRAYEND
%token <iVal> KITTRAYSTART
%token <iVal> KITEND
%token <iVal> KITSTART
%token <iVal> KITTINGWORKSTATIONEND
%token <iVal> KITTINGWORKSTATIONSTART
%token <iVal> LARGEBOXWITHEMPTYKITTRAYSPARAMETEREND
%token <iVal> LARGEBOXWITHEMPTYKITTRAYSPARAMETERSTART
%token <iVal> LARGEBOXWITHKITSPARAMETEREND
%token <iVal> LARGEBOXWITHKITSPARAMETERSTART
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
%token <iVal> MODELFILENAMEEND
%token <iVal> MODELFILENAMESTART
%token <iVal> MODELFORMATNAMEEND
%token <iVal> MODELFORMATNAMESTART
%token <iVal> MODELNAMEEND
%token <iVal> MODELNAMESTART
%token <iVal> NAMEEND
%token <iVal> NAMESTART
%token <iVal> NOTPREDICATENAMEEND
%token <iVal> NOTPREDICATENAMESTART
%token <iVal> OBJECTONTABLEEND
%token <iVal> OBJECTONTABLESTART
%token <iVal> OBJECTEND
%token <iVal> OBJECTSTART
%token <iVal> ONTOPWITHCONTACTEND
%token <iVal> ONTOPWITHCONTACTSTART
%token <iVal> ORIENTATIONSTANDARDDEVIATIONEND
%token <iVal> ORIENTATIONSTANDARDDEVIATIONSTART
%token <iVal> OTHEROBSTACLEEND
%token <iVal> OTHEROBSTACLESTART
%token <iVal> PARTNAMEEND
%token <iVal> PARTNAMESTART
%token <iVal> PARTPARAMETEREND
%token <iVal> PARTPARAMETERSTART
%token <iVal> PARTQUANTITYEND
%token <iVal> PARTQUANTITYSTART
%token <iVal> PARTREFANDPOSENAMEEND
%token <iVal> PARTREFANDPOSENAMESTART
%token <iVal> PARTREFANDPOSEEND
%token <iVal> PARTREFANDPOSESTART
%token <iVal> PARTSKUNAMEEND
%token <iVal> PARTSKUNAMESTART
%token <iVal> PARTEND
%token <iVal> PARTSTART
%token <iVal> PARTIALLYINEND
%token <iVal> PARTIALLYINSTART
%token <iVal> PARTSTRAYPARAMETEREND
%token <iVal> PARTSTRAYPARAMETERSTART
%token <iVal> POINTEND
%token <iVal> POINTSTART
%token <iVal> POSITIONINORDEREDLISTEND
%token <iVal> POSITIONINORDEREDLISTSTART
%token <iVal> POSITIONSTANDARDDEVIATIONEND
%token <iVal> POSITIONSTANDARDDEVIATIONSTART
%token <iVal> PRECONDITIONEND
%token <iVal> PRECONDITIONSTART
%token <iVal> PREDICATEGROUPELEMENTEND
%token <iVal> PREDICATEGROUPELEMENTSTART
%token <iVal> PREDICATENAMEEND
%token <iVal> PREDICATENAMESTART
%token <iVal> PREDICATEOCCURRENCEEND
%token <iVal> PREDICATEOCCURRENCESTART
%token <iVal> PREDICATEEND
%token <iVal> PREDICATESTART
%token <iVal> PRIMARYLOCATIONEND
%token <iVal> PRIMARYLOCATIONSTART
%token <iVal> PUTKITTRAYEND
%token <iVal> PUTKITTRAYSTART
%token <iVal> PUTKITEND
%token <iVal> PUTKITSTART
%token <iVal> PUTPARTEND
%token <iVal> PUTPARTSTART
%token <iVal> RCC8SETEND
%token <iVal> RCC8SETSTART
%token <iVal> REFOBJECTNAMEEND
%token <iVal> REFOBJECTNAMESTART
%token <iVal> REFERENCENAMEEND
%token <iVal> REFERENCENAMESTART
%token <iVal> REQUIREMENTEND
%token <iVal> REQUIREMENTSTART
%token <iVal> ROBOTPARAMETEREND
%token <iVal> ROBOTPARAMETERSTART
%token <iVal> ROBOTEND
%token <iVal> ROBOTSTART
%token <iVal> SOAPEND
%token <iVal> SOAPSTART
%token <iVal> SECONDARYLOCATIONEND
%token <iVal> SECONDARYLOCATIONSTART
%token <iVal> SERIALNUMBEREND
%token <iVal> SERIALNUMBERSTART
%token <iVal> SKUNAMEEND
%token <iVal> SKUNAMESTART
%token <iVal> SKUEND
%token <iVal> SKUSTART
%token <iVal> SLOTEND
%token <iVal> SLOTSTART
%token <iVal> STATERELATIONNAMEEND
%token <iVal> STATERELATIONNAMESTART
%token <iVal> TAKEKITTRAYEND
%token <iVal> TAKEKITTRAYSTART
%token <iVal> TAKEKITEND
%token <iVal> TAKEKITSTART
%token <iVal> TAKEPARTEND
%token <iVal> TAKEPARTSTART
%token <iVal> TARGETNAMEEND
%token <iVal> TARGETNAMESTART
%token <iVal> TIMESTAMPEND
%token <iVal> TIMESTAMPSTART
%token <iVal> UNDERWITHCONTACTEND
%token <iVal> UNDERWITHCONTACTSTART
%token <iVal> VALUEEND
%token <iVal> VALUESTART
%token <iVal> VARIABLEEND
%token <iVal> VARIABLESTART
%token <iVal> WEIGHTUNITEND
%token <iVal> WEIGHTUNITSTART
%token <iVal> WEIGHTEND
%token <iVal> WEIGHTSTART
%token <iVal> WIDTHEND
%token <iVal> WIDTHSTART
%token <iVal> WORKTABLEPARAMETEREND
%token <iVal> WORKTABLEPARAMETERSTART
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


%token <iVal> ACTIONBASETYPEDECL
%token <iVal> ANYORDERORDERINGCONSTRUCTTYPEDECL
%token <iVal> ATTACHENDEFFECTORTYPEDECL
%token <iVal> BOXVOLUMETYPEDECL
%token <iVal> BOXYSHAPETYPEDECL
%token <iVal> COUNTORDERINGCONSTRUCTTYPEDECL
%token <iVal> CREATEKITTYPEDECL
%token <iVal> CYLINDRICALSHAPETYPEDECL
%token <iVal> DETACHENDEFFECTORTYPEDECL
%token <iVal> DOMAINTYPEDECL
%token <iVal> EFFECTTYPEDECL
%token <iVal> ENDEFFECTORCHANGINGSTATIONTYPEDECL
%token <iVal> ENDEFFECTORHOLDERTYPEDECL
%token <iVal> ENDEFFECTORTYPEDECL
%token <iVal> EXISTORDERINGCONSTRUCTTYPEDECL
%token <iVal> EXTERNALSHAPETYPEDECL
%token <iVal> FUNCTIONBOOLEANEXPRESSIONTYPEDECL
%token <iVal> FUNCTIONOPERATIONTYPEDECL
%token <iVal> FUNCTIONTODECIMALBOOLTYPEDECL
%token <iVal> FUNCTIONTODECIMALEQUALTYPEDECL
%token <iVal> FUNCTIONTODECIMALGREATEROREQUALTYPEDECL
%token <iVal> FUNCTIONTODECIMALGREATERTYPEDECL
%token <iVal> FUNCTIONTODECIMALLESSOREQUALTYPEDECL
%token <iVal> FUNCTIONTODECIMALLESSTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONBOOLTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONEQUALTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONGREATEROREQUALTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONGREATERTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONLESSOREQUALTYPEDECL
%token <iVal> FUNCTIONTOFUNCTIONLESSTYPEDECL
%token <iVal> FUNCTIONTYPEDECL
%token <iVal> GRIPPEREFFECTORTYPEDECL
%token <iVal> HUMANTYPEDECL
%token <iVal> INCONTACTWITHTYPEDECL
%token <iVal> INTERNALSHAPETYPEDECL
%token <iVal> KITDESIGNTYPEDECL
%token <iVal> KITTRAYTYPEDECL
%token <iVal> KITTYPEDECL
%token <iVal> KITTINGWORKSTATIONTYPEDECL
%token <iVal> LARGEBOXWITHEMPTYKITTRAYSTYPEDECL
%token <iVal> LARGEBOXWITHKITSTYPEDECL
%token <iVal> LARGECONTAINERTYPEDECL
%token <iVal> MECHANICALCOMPONENTTYPEDECL
%token <iVal> NOSKUOBJECTTYPEDECL
%token <iVal> ONTOPWITHCONTACTTYPEDECL
%token <iVal> ORDEREDLISTORDERINGCONSTRUCTTYPEDECL
%token <iVal> ORDERINGCONSTRUCTTYPEDECL
%token <iVal> PARTREFANDPOSETYPEDECL
%token <iVal> PARTTYPEDECL
%token <iVal> PARTIALLYINTYPEDECL
%token <iVal> PARTSBINTYPEDECL
%token <iVal> PARTSTRAYTYPEDECL
%token <iVal> PARTSVESSELTYPEDECL
%token <iVal> PHYSICALLOCATIONTYPEDECL
%token <iVal> POINTTYPEDECL
%token <iVal> POSELOCATIONINTYPEDECL
%token <iVal> POSELOCATIONONTYPEDECL
%token <iVal> POSELOCATIONTYPEDECL
%token <iVal> POSEONLYLOCATIONTYPEDECL
%token <iVal> PRECONDITIONTYPEDECL
%token <iVal> PREDICATEGROUPELEMENTTYPEDECL
%token <iVal> PREDICATETYPEDECL
%token <iVal> PUTKITTRAYTYPEDECL
%token <iVal> PUTKITTYPEDECL
%token <iVal> PUTPARTTYPEDECL
%token <iVal> RELATIVELOCATIONINTYPEDECL
%token <iVal> RELATIVELOCATIONONTYPEDECL
%token <iVal> RELATIVELOCATIONTYPEDECL
%token <iVal> ROBOTACTIONBASETYPEDECL
%token <iVal> ROBOTTYPEDECL
%token <iVal> SOAPTYPEDECL
%token <iVal> SHAPEDESIGNTYPEDECL
%token <iVal> SKUOBJECTTYPEDECL
%token <iVal> SLOTTYPEDECL
%token <iVal> STATERELATIONTYPEDECL
%token <iVal> STOCKKEEPINGUNITTYPEDECL
%token <iVal> TAKEKITTRAYTYPEDECL
%token <iVal> TAKEKITTYPEDECL
%token <iVal> TAKEPARTTYPEDECL
%token <iVal> UNDERWITHCONTACTTYPEDECL
%token <iVal> VACUUMEFFECTORMULTICUPTYPEDECL
%token <iVal> VACUUMEFFECTORSINGLECUPTYPEDECL
%token <iVal> VACUUMEFFECTORTYPEDECL
%token <iVal> VECTORTYPEDECL
%token <iVal> WORKTABLETYPEDECL

%%

y_SOAPFile :
	  y_XmlVersion SOAPSTART y_XmlHeaderForSOAP
	  y_SOAPType SOAPEND
	  {$$ = new SOAPFile($1, $3, $4);
	   SOAPTree = $$;
	   if (XmlIDREF::idMissing())
	     yyerror("xs:ID missing for xs:IDREF");
	  }
	;

y_XmlHeaderForSOAP:
	  XMLNSTARGET XMLNSPREFIX y_SchemaLocation
	  {$$ = new XmlHeaderForSOAP($3);}
	;

y_SchemaLocation :
	  SCHEMALOCATION TERMINALSTRING
	  {$$ = new SchemaLocation("xsi", $2, true);
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

y_XmlDateTime :
	  DATASTRING
	  {$$ = new XmlDateTime($1);
	   if ($$->bad)
	     yyerror("bad XmlDateTime");
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

y_A1_XmlDecimal :
	  A1START ENDITEM {yyReadData = 1;} y_XmlDecimal A1END
	  {$$ = $4;}
	;

y_AngleUnit_AngleUnitType :
	  ANGLEUNITSTART ENDITEM {yyReadData = 1;} DATASTRING ANGLEUNITEND
	  {$$ = new AngleUnitType($4);
	   if ($$->bad)
	     yyerror("bad AngleUnit value");
	  }
	;

y_AnyOrderOrderingConstructType :
	   ENDITEM y_Name_XmlID
	  y_CountOrderingConstruct_CountOrderingConstructType
	  y_PositionInOrderedList_XmlPositiveInteger
	  {$$ = new AnyOrderOrderingConstructType($2, $3, $4);}
	;

y_AnyOrderOrderingConstruct_AnyOrderOrderingConstructType :
	  ANYORDERORDERINGCONSTRUCTSTART y_AnyOrderOrderingConstructType
	  ANYORDERORDERINGCONSTRUCTEND
	  {$$ = $2;}
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

y_AttachEndEffectorType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_EndEffectorParameter_XmlNMTOKEN
	  y_EndEffectorHolderParameter_XmlNMTOKEN
	  y_EndEffectorChangingStationParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new AttachEndEffectorType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_AttachEndEffector_AttachEndEffectorType :
	  ATTACHENDEFFECTORSTART y_AttachEndEffectorType
	  ATTACHENDEFFECTOREND
	  {$$ = $2;}
	;

y_Base_MechanicalComponentType :
	  BASESTART y_MechanicalComponentType BASEEND
	  {$$ = $2;}
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

y_CountOrderingConstructType :
	   ENDITEM y_Name_XmlID y_Predicate_PredicateType
	  y_PredicateOccurrence_XmlPositiveInteger
	  {$$ = new CountOrderingConstructType($2, $3, $4);}
	;

y_CountOrderingConstruct_CountOrderingConstructType :
	  COUNTORDERINGCONSTRUCTSTART y_CountOrderingConstructType
	  COUNTORDERINGCONSTRUCTEND
	  {$$ = $2;}
	;

y_CreateKitType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_KitParameter_XmlNMTOKEN y_KitTrayParameter_XmlNMTOKEN
	  y_WorkTableParameter_XmlNMTOKEN y_Precondition_PreconditionType
	  y_Effect_EffectType
	  {$$ = new CreateKitType($2, $3, $4, $5, $6, $7, $8);}
	;

y_CreateKit_CreateKitType :
	  CREATEKITSTART y_CreateKitType CREATEKITEND
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

y_Description_XmlString_0 :
	  /* empty */
	  {$$ = 0;}
	| DESCRIPTIONSTART ENDITEM {yyReadData = 1;} y_XmlString
	  DESCRIPTIONEND
	  {$$ = $4;}
	;

y_DesignName_XmlIDREF :
	  DESIGNNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  DESIGNNAMEEND
	  {$$ = $4;}
	;

y_DetachEndEffectorType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_EndEffectorParameter_XmlNMTOKEN
	  y_EndEffectorHolderParameter_XmlNMTOKEN
	  y_EndEffectorChangingStationParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new DetachEndEffectorType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_DetachEndEffector_DetachEndEffectorType :
	  DETACHENDEFFECTORSTART y_DetachEndEffectorType
	  DETACHENDEFFECTOREND
	  {$$ = $2;}
	;

y_Diameter_PositiveDecimalType :
	  DIAMETERSTART ENDITEM {yyReadData = 1;} DATASTRING DIAMETEREND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Diameter value");
	  }
	;

y_DomainType :
	   ENDITEM y_Name_XmlID y_ListRequirement_XmlNMTOKEN_u
	  y_ListVariable_XmlNMTOKEN_u y_ListPredicate_PredicateType_u
	  y_ListFunction_FunctionType_u
	  y_AttachEndEffector_AttachEndEffectorType
	  y_CreateKit_CreateKitType
	  y_DetachEndEffector_DetachEndEffectorType y_TakePart_TakePartType
	  y_TakeKit_TakeKitType y_TakeKitTray_TakeKitTrayType
	  y_PutPart_PutPartType y_PutKit_PutKitType
	  y_PutKitTray_PutKitTrayType
	  {$$ = new DomainType($2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15);}
	;

y_Domain_DomainType :
	  DOMAINSTART y_DomainType DOMAINEND
	  {$$ = $2;}
	;

y_EffectType :
	   ENDITEM y_Name_XmlID y_ListPredicateName_XmlIDREF_0_u
	  y_ListNotPredicateName_XmlIDREF_0_u y_FunctionName_XmlIDREF_0
	  y_FunctionOperation_FunctionOperationType_0
	  y_ListF1LessF2_FunctionToFunctionLessType_0_u
	  y_ListF1EqualF2_FunctionToFunctionEqualType_0_u
	  y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
	  y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u
	  y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
	  {$$ = new EffectType($2, $3, $4, $5, $6, $7, $8, $9, $10, $11);}
	;

y_Effect_EffectType :
	  EFFECTSTART y_EffectType EFFECTEND
	  {$$ = $2;}
	;

y_EndEffectorChangingStationParameter_XmlNMTOKEN :
	  ENDEFFECTORCHANGINGSTATIONPARAMETERSTART ENDITEM {yyReadData =
	  1;} y_XmlNMTOKEN ENDEFFECTORCHANGINGSTATIONPARAMETEREND
	  {$$ = $4;}
	;

y_EndEffectorChangingStationType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_Base_MechanicalComponentType
	  y_ListEndEffectorHolder_EndEffectorHolderType_u
	  {$$ = new EndEffectorChangingStationType($2, $3, $4, $5, $6, $7, $8);}
	;

y_EndEffectorHolderParameter_XmlNMTOKEN :
	  ENDEFFECTORHOLDERPARAMETERSTART ENDITEM {yyReadData = 1;}
	  y_XmlNMTOKEN ENDEFFECTORHOLDERPARAMETEREND
	  {$$ = $4;}
	;

y_EndEffectorHolderType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_EndEffector_EndEffectorType_0
	  {$$ = new EndEffectorHolderType($2, $3, $4, $5, $6, $7);}
	;

y_EndEffectorHolder_EndEffectorHolderType_u :
	  ENDEFFECTORHOLDERSTART y_EndEffectorHolderType
	  ENDEFFECTORHOLDEREND
	  {$$ = $2;}
	;

y_EndEffectorName_XmlIDREF_0_u :
	  ENDEFFECTORNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  ENDEFFECTORNAMEEND
	  {$$ = $4;}
	;

y_EndEffectorParameter_XmlNMTOKEN :
	  ENDEFFECTORPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  ENDEFFECTORPARAMETEREND
	  {$$ = $4;}
	;

y_EndEffectorTypeAny :
	  y_x_GripperEffectorType
	  {$$ = $1;}
	| y_x_VacuumEffectorMultiCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorSingleCupType
	  {$$ = $1;}
	;

y_EndEffector_EndEffectorType_0 :
	  /* empty */
	  {$$ = 0;}
	| ENDEFFECTORSTART y_EndEffectorTypeAny ENDEFFECTOREND
	  {$$ = $2;}
	;

y_ExistOrderingConstructType :
	   ENDITEM y_Name_XmlID y_Predicate_PredicateType
	  {$$ = new ExistOrderingConstructType($2, $3);}
	;

y_ExistOrderingConstruct_ExistOrderingConstructType :
	  EXISTORDERINGCONSTRUCTSTART y_ExistOrderingConstructType
	  EXISTORDERINGCONSTRUCTEND
	  {$$ = $2;}
	;

y_Expression_XmlNMTOKEN :
	  EXPRESSIONSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  EXPRESSIONEND
	  {$$ = $4;}
	;

y_ExternalShapeType :
	   ENDITEM y_Name_XmlID y_Description_XmlString
	  y_GraspPose_PoseLocationType_0 y_ModelFormatName_XmlString
	  y_ModelFileName_XmlString y_ModelName_XmlString_0
	  {$$ = new ExternalShapeType($2, $3, $4, $5, $6, $7);}
	;

y_ExternalShape_ExternalShapeType_0 :
	  /* empty */
	  {$$ = 0;}
	| EXTERNALSHAPESTART y_ExternalShapeType EXTERNALSHAPEEND
	  {$$ = $2;}
	;

y_F1EqualF2_FunctionToFunctionEqualType_0_u :
	  F1EQUALF2START y_FunctionToFunctionEqualType F1EQUALF2END
	  {$$ = $2;}
	;

y_F1GreaterF2_FunctionToFunctionGreaterType_0_u :
	  F1GREATERF2START y_FunctionToFunctionGreaterType F1GREATERF2END
	  {$$ = $2;}
	;

y_F1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u :
	  F1GREATEROREQUALF2START y_FunctionToFunctionGreaterOrEqualType
	  F1GREATEROREQUALF2END
	  {$$ = $2;}
	;

y_F1LessF2_FunctionToFunctionLessType_0_u :
	  F1LESSF2START y_FunctionToFunctionLessType F1LESSF2END
	  {$$ = $2;}
	;

y_F1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u :
	  F1LESSOREQUALF2START y_FunctionToFunctionLessOrEqualType
	  F1LESSOREQUALF2END
	  {$$ = $2;}
	;

y_F1Name_XmlIDREF :
	  F1NAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF F1NAMEEND
	  {$$ = $4;}
	;

y_F2Name_XmlIDREF :
	  F2NAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF F2NAMEEND
	  {$$ = $4;}
	;

y_Finished_XmlBoolean :
	  FINISHEDSTART ENDITEM {yyReadData = 1;} y_XmlBoolean FINISHEDEND
	  {$$ = $4;}
	;

y_FunctionName_XmlIDREF :
	  FUNCTIONNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  FUNCTIONNAMEEND
	  {$$ = $4;}
	;

y_FunctionName_XmlIDREF_0 :
	  /* empty */
	  {$$ = 0;}
	| FUNCTIONNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  FUNCTIONNAMEEND
	  {$$ = $4;}
	;

y_FunctionOperationType :
	   ENDITEM y_Name_XmlID y_FunctionName_XmlIDREF
	  y_Expression_XmlNMTOKEN y_Value_XmlPositiveInteger
	  {$$ = new FunctionOperationType($2, $3, $4, $5);}
	;

y_FunctionOperation_FunctionOperationType_0 :
	  /* empty */
	  {$$ = 0;}
	| FUNCTIONOPERATIONSTART y_FunctionOperationType
	  FUNCTIONOPERATIONEND
	  {$$ = $2;}
	;

y_FunctionToFunctionEqualType :
	   ENDITEM y_Name_XmlID y_F1Name_XmlIDREF y_F2Name_XmlIDREF
	  {$$ = new FunctionToFunctionEqualType($2, $3, $4);}
	;

y_FunctionToFunctionGreaterOrEqualType :
	   ENDITEM y_Name_XmlID y_F1Name_XmlIDREF y_F2Name_XmlIDREF
	  {$$ = new FunctionToFunctionGreaterOrEqualType($2, $3, $4);}
	;

y_FunctionToFunctionGreaterType :
	   ENDITEM y_Name_XmlID y_F1Name_XmlIDREF y_F2Name_XmlIDREF
	  {$$ = new FunctionToFunctionGreaterType($2, $3, $4);}
	;

y_FunctionToFunctionLessOrEqualType :
	   ENDITEM y_Name_XmlID y_F1Name_XmlIDREF y_F2Name_XmlIDREF
	  {$$ = new FunctionToFunctionLessOrEqualType($2, $3, $4);}
	;

y_FunctionToFunctionLessType :
	   ENDITEM y_Name_XmlID y_F1Name_XmlIDREF y_F2Name_XmlIDREF
	  {$$ = new FunctionToFunctionLessType($2, $3, $4);}
	;

y_FunctionType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_ReferenceName_XmlNMTOKEN y_TargetName_XmlNMTOKEN_0
	  {$$ = new FunctionType($2, $3, $4, $5);}
	;

y_Function_FunctionType_u :
	  FUNCTIONSTART y_FunctionType FUNCTIONEND
	  {$$ = $2;}
	;

y_GraspPose_PoseLocationType_0 :
	  /* empty */
	  {$$ = 0;}
	| GRASPPOSESTART y_PoseLocationTypeAny GRASPPOSEEND
	  {$$ = $2;}
	;

y_HasTop_XmlBoolean :
	  HASTOPSTART ENDITEM {yyReadData = 1;} y_XmlBoolean HASTOPEND
	  {$$ = $4;}
	;

y_Height_PositiveDecimalType :
	  HEIGHTSTART ENDITEM {yyReadData = 1;} DATASTRING HEIGHTEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad Height value");
	  }
	;

y_HeldObject_SolidObjectType_0 :
	  /* empty */
	  {$$ = 0;}
	| HELDOBJECTSTART y_SolidObjectTypeAny HELDOBJECTEND
	  {$$ = $2;}
	;

y_I_XmlDecimal :
	  ISTART ENDITEM {yyReadData = 1;} y_XmlDecimal IEND
	  {$$ = $4;}
	;

y_InContactWithType :
	   ENDITEM y_Name_XmlID y_RCC8Set_XmlString
	  {$$ = new InContactWithType($2, $3);}
	;

y_InContactWith_InContactWithType :
	  INCONTACTWITHSTART y_InContactWithType INCONTACTWITHEND
	  {$$ = $2;}
	;

y_InternalShapeTypeAny :
	  y_x_BoxyShapeType
	  {$$ = $1;}
	| y_x_CylindricalShapeType
	  {$$ = $1;}
	;

y_InternalShape_InternalShapeType_0 :
	  /* empty */
	  {$$ = 0;}
	| INTERNALSHAPESTART y_InternalShapeTypeAny INTERNALSHAPEEND
	  {$$ = $2;}
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
	  y_ListPartRefAndPose_PartRefAndPoseType_u
	  {$$ = new KitDesignType($2, $3, $4);}
	;

y_KitDesign_KitDesignType_u :
	  KITDESIGNSTART y_KitDesignType KITDESIGNEND
	  {$$ = $2;}
	;

y_KitParameter_XmlNMTOKEN :
	  KITPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  KITPARAMETEREND
	  {$$ = $4;}
	;

y_KitTrayParameter_XmlNMTOKEN :
	  KITTRAYPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  KITTRAYPARAMETEREND
	  {$$ = $4;}
	;

y_KitTraySkuName_XmlIDREF :
	  KITTRAYSKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  KITTRAYSKUNAMEEND
	  {$$ = $4;}
	;

y_KitTrayType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new KitTrayType($2, $3, $4, $5, $6);}
	;

y_KitTray_KitTrayType :
	  KITTRAYSTART y_KitTrayType KITTRAYEND
	  {$$ = $2;}
	;

y_KitTray_KitTrayType_0_u :
	  KITTRAYSTART y_KitTrayType KITTRAYEND
	  {$$ = $2;}
	;

y_KitType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_DesignName_XmlIDREF
	  y_KitTray_KitTrayType y_ListPart_PartType_0_u
	  y_ListSlot_SlotType_0_u y_Finished_XmlBoolean
	  {$$ = new KitType($2, $3, $4, $5, $6, $7, $8, $9, $10, $11);}
	;

y_Kit_KitType_0_u :
	  KITSTART y_KitType KITEND
	  {$$ = $2;}
	;

y_KittingWorkstationType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_AngleUnit_AngleUnitType
	  y_ChangingStation_EndEffectorChangingStationType
	  y_ListKitDesign_KitDesignType_u y_LengthUnit_LengthUnitType
	  y_ListObject_SolidObjectType_u
	  y_ListOtherObstacle_BoxVolumeType_0_u y_Robot_RobotType
	  y_ListSku_StockKeepingUnitType_u y_WeightUnit_WeightUnitType
	  {$$ = new KittingWorkstationType($2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15);}
	;

y_KittingWorkstation_KittingWorkstationType :
	  KITTINGWORKSTATIONSTART y_KittingWorkstationType
	  KITTINGWORKSTATIONEND
	  {$$ = $2;}
	;

y_LargeBoxWithEmptyKitTraysParameter_XmlNMTOKEN :
	  LARGEBOXWITHEMPTYKITTRAYSPARAMETERSTART ENDITEM {yyReadData = 1;}
	  y_XmlNMTOKEN LARGEBOXWITHEMPTYKITTRAYSPARAMETEREND
	  {$$ = $4;}
	;

y_LargeBoxWithKitsParameter_XmlNMTOKEN :
	  LARGEBOXWITHKITSPARAMETERSTART ENDITEM {yyReadData = 1;}
	  y_XmlNMTOKEN LARGEBOXWITHKITSPARAMETEREND
	  {$$ = $4;}
	;

y_LargeContainerType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new LargeContainerType($2, $3, $4, $5, $6);}
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

y_ListEndEffectorHolder_EndEffectorHolderType_u :
	  y_EndEffectorHolder_EndEffectorHolderType_u
	  {$$ = new std::list<EndEffectorHolderType *>;
	   $$->push_back($1);}
	| y_ListEndEffectorHolder_EndEffectorHolderType_u
	  y_EndEffectorHolder_EndEffectorHolderType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListEndEffectorName_XmlIDREF_0_u :
	  /* empty */
	  {$$ = new std::list<XmlIDREF *>;}
	| y_ListEndEffectorName_XmlIDREF_0_u y_EndEffectorName_XmlIDREF_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListF1EqualF2_FunctionToFunctionEqualType_0_u :
	  /* empty */
	  {$$ = new std::list<FunctionToFunctionEqualType *>;}
	| y_ListF1EqualF2_FunctionToFunctionEqualType_0_u
	  y_F1EqualF2_FunctionToFunctionEqualType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u :
	  /* empty */
	  {$$ = new std::list<FunctionToFunctionGreaterType *>;}
	| y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u
	  y_F1GreaterF2_FunctionToFunctionGreaterType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u :
	  /* empty */
	  {$$ = new std::list<FunctionToFunctionGreaterOrEqualType *>;}
	| y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
	  y_F1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListF1LessF2_FunctionToFunctionLessType_0_u :
	  /* empty */
	  {$$ = new std::list<FunctionToFunctionLessType *>;}
	| y_ListF1LessF2_FunctionToFunctionLessType_0_u
	  y_F1LessF2_FunctionToFunctionLessType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u :
	  /* empty */
	  {$$ = new std::list<FunctionToFunctionLessOrEqualType *>;}
	| y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
	  y_F1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListFunction_FunctionType_u :
	  y_Function_FunctionType_u
	  {$$ = new std::list<FunctionType *>;
	   $$->push_back($1);}
	| y_ListFunction_FunctionType_u y_Function_FunctionType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListKitDesign_KitDesignType_u :
	  y_KitDesign_KitDesignType_u
	  {$$ = new std::list<KitDesignType *>;
	   $$->push_back($1);}
	| y_ListKitDesign_KitDesignType_u y_KitDesign_KitDesignType_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListKitTray_KitTrayType_0_u :
	  /* empty */
	  {$$ = new std::list<KitTrayType *>;}
	| y_ListKitTray_KitTrayType_0_u y_KitTray_KitTrayType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListKit_KitType_0_u :
	  /* empty */
	  {$$ = new std::list<KitType *>;}
	| y_ListKit_KitType_0_u y_Kit_KitType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListNotPredicateName_XmlIDREF_0_u :
	  /* empty */
	  {$$ = new std::list<XmlIDREF *>;}
	| y_ListNotPredicateName_XmlIDREF_0_u
	  y_NotPredicateName_XmlIDREF_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListObjectOnTable_SolidObjectType_0_u :
	  /* empty */
	  {$$ = new std::list<SolidObjectType *>;}
	| y_ListObjectOnTable_SolidObjectType_0_u
	  y_ObjectOnTable_SolidObjectType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListObject_SolidObjectType_u :
	  y_ListObject_SolidObjectType_u y_Object_SolidObjectType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Object_SolidObjectType_u
	  {$$ = new std::list<SolidObjectType *>;
	   $$->push_back($1);}
	;

y_ListOtherObstacle_BoxVolumeType_0_u :
	  /* empty */
	  {$$ = new std::list<BoxVolumeType *>;}
	| y_ListOtherObstacle_BoxVolumeType_0_u
	  y_OtherObstacle_BoxVolumeType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListPartRefAndPose_PartRefAndPoseType_u :
	  y_ListPartRefAndPose_PartRefAndPoseType_u
	  y_PartRefAndPose_PartRefAndPoseType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_PartRefAndPose_PartRefAndPoseType_u
	  {$$ = new std::list<PartRefAndPoseType *>;
	   $$->push_back($1);}
	;

y_ListPart_PartType_0_u :
	  /* empty */
	  {$$ = new std::list<PartType *>;}
	| y_ListPart_PartType_0_u y_Part_PartType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListPredicateGroupElement_PredicateGroupElementType_u :
	  y_ListPredicateGroupElement_PredicateGroupElementType_u
	  y_PredicateGroupElement_PredicateGroupElementType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_PredicateGroupElement_PredicateGroupElementType_u
	  {$$ = new std::list<PredicateGroupElementType *>;
	   $$->push_back($1);}
	;

y_ListPredicateName_XmlIDREF_0_u :
	  /* empty */
	  {$$ = new std::list<XmlIDREF *>;}
	| y_ListPredicateName_XmlIDREF_0_u y_PredicateName_XmlIDREF_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListPredicateName_XmlIDREF_u :
	  y_ListPredicateName_XmlIDREF_u y_PredicateName_XmlIDREF_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_PredicateName_XmlIDREF_u
	  {$$ = new std::list<XmlIDREF *>;
	   $$->push_back($1);}
	;

y_ListPredicate_PredicateType_u :
	  y_ListPredicate_PredicateType_u y_Predicate_PredicateType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Predicate_PredicateType_u
	  {$$ = new std::list<PredicateType *>;
	   $$->push_back($1);}
	;

y_ListRequirement_XmlNMTOKEN_u :
	  y_ListRequirement_XmlNMTOKEN_u y_Requirement_XmlNMTOKEN_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Requirement_XmlNMTOKEN_u
	  {$$ = new std::list<XmlNMTOKEN *>;
	   $$->push_back($1);}
	;

y_ListSecondaryLocation_PhysicalLocationType_0_u :
	  /* empty */
	  {$$ = new std::list<PhysicalLocationType *>;}
	| y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SecondaryLocation_PhysicalLocationType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListSku_StockKeepingUnitType_u :
	  y_ListSku_StockKeepingUnitType_u y_Sku_StockKeepingUnitType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Sku_StockKeepingUnitType_u
	  {$$ = new std::list<StockKeepingUnitType *>;
	   $$->push_back($1);}
	;

y_ListSlot_SlotType_0_u :
	  /* empty */
	  {$$ = new std::list<SlotType *>;}
	| y_ListSlot_SlotType_0_u y_Slot_SlotType_0_u
	  {$$ = $1;
	   $$->push_back($2);}
	;

y_ListVariable_XmlNMTOKEN_u :
	  y_ListVariable_XmlNMTOKEN_u y_Variable_XmlNMTOKEN_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_Variable_XmlNMTOKEN_u
	  {$$ = new std::list<XmlNMTOKEN *>;
	   $$->push_back($1);}
	;

y_ListWorkVolume_BoxVolumeType_u :
	  y_ListWorkVolume_BoxVolumeType_u y_WorkVolume_BoxVolumeType_u
	  {$$ = $1;
	   $$->push_back($2);}
	| y_WorkVolume_BoxVolumeType_u
	  {$$ = new std::list<BoxVolumeType *>;
	   $$->push_back($1);}
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

y_MechanicalComponentType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  {$$ = new MechanicalComponentType($2, $3, $4, $5, $6);}
	;

y_MinimumPoint_PointType :
	  MINIMUMPOINTSTART y_PointType MINIMUMPOINTEND
	  {$$ = $2;}
	;

y_ModelFileName_XmlString :
	  MODELFILENAMESTART ENDITEM {yyReadData = 1;} y_XmlString
	  MODELFILENAMEEND
	  {$$ = $4;}
	;

y_ModelFormatName_XmlString :
	  MODELFORMATNAMESTART ENDITEM {yyReadData = 1;} y_XmlString
	  MODELFORMATNAMEEND
	  {$$ = $4;}
	;

y_ModelName_XmlString_0 :
	  /* empty */
	  {$$ = 0;}
	| MODELNAMESTART ENDITEM {yyReadData = 1;} y_XmlString MODELNAMEEND
	  {$$ = $4;}
	;

y_Name_XmlID :
	  NAMESTART ENDITEM {yyReadData = 1;} y_XmlID NAMEEND
	  {$$ = $4;}
	;

y_NotPredicateName_XmlIDREF_0_u :
	  NOTPREDICATENAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  NOTPREDICATENAMEEND
	  {$$ = $4;}
	;

y_ObjectOnTable_SolidObjectType_0_u :
	  OBJECTONTABLESTART y_SolidObjectTypeAny OBJECTONTABLEEND
	  {$$ = $2;}
	;

y_Object_SolidObjectType_u :
	  OBJECTSTART y_SolidObjectTypeAny OBJECTEND
	  {$$ = $2;}
	;

y_OnTopWithContactType :
	   ENDITEM y_Name_XmlID y_RCC8Set_XmlString
	  {$$ = new OnTopWithContactType($2, $3);}
	;

y_OnTopWithContact_OnTopWithContactType :
	  ONTOPWITHCONTACTSTART y_OnTopWithContactType ONTOPWITHCONTACTEND
	  {$$ = $2;}
	;

y_OrientationStandardDeviation_PositiveDecimalType_0 :
	  /* empty */
	  {$$ = 0;}
	| ORIENTATIONSTANDARDDEVIATIONSTART ENDITEM {yyReadData = 1;}
	  DATASTRING ORIENTATIONSTANDARDDEVIATIONEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad OrientationStandardDeviation value");
	  }
	;

y_OtherObstacle_BoxVolumeType_0_u :
	  OTHEROBSTACLESTART y_BoxVolumeType OTHEROBSTACLEEND
	  {$$ = $2;}
	;

y_PartName_XmlIDREF_0 :
	  /* empty */
	  {$$ = 0;}
	| PARTNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF PARTNAMEEND
	  {$$ = $4;}
	;

y_PartParameter_XmlNMTOKEN :
	  PARTPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  PARTPARAMETEREND
	  {$$ = $4;}
	;

y_PartQuantity_XmlNonNegativeInteger :
	  PARTQUANTITYSTART ENDITEM {yyReadData = 1;}
	  y_XmlNonNegativeInteger PARTQUANTITYEND
	  {$$ = $4;}
	;

y_PartRefAndPoseName_XmlIDREF :
	  PARTREFANDPOSENAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  PARTREFANDPOSENAMEEND
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

y_PartSkuName_XmlIDREF :
	  PARTSKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  PARTSKUNAMEEND
	  {$$ = $4;}
	;

y_PartType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartType($2, $3, $4, $5, $6);}
	;

y_Part_PartType_0_u :
	  PARTSTART y_PartType PARTEND
	  {$$ = $2;}
	;

y_PartiallyInType :
	   ENDITEM y_Name_XmlID y_RCC8Set_XmlString
	  {$$ = new PartiallyInType($2, $3);}
	;

y_PartiallyIn_PartiallyInType :
	  PARTIALLYINSTART y_PartiallyInType PARTIALLYINEND
	  {$$ = $2;}
	;

y_PartsTrayParameter_XmlNMTOKEN :
	  PARTSTRAYPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  PARTSTRAYPARAMETEREND
	  {$$ = $4;}
	;

y_PhysicalLocationTypeAny :
	  y_x_PoseLocationInType
	  {$$ = $1;}
	| y_x_PoseLocationOnType
	  {$$ = $1;}
	| y_x_PoseOnlyLocationType
	  {$$ = $1;}
	| y_x_RelativeLocationInType
	  {$$ = $1;}
	| y_x_RelativeLocationOnType
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

y_PoseLocationTypeAny :
	  y_x_PoseLocationInType
	  {$$ = $1;}
	| y_x_PoseLocationOnType
	  {$$ = $1;}
	| y_x_PoseOnlyLocationType
	  {$$ = $1;}
	;

y_PositionInOrderedList_XmlPositiveInteger :
	  POSITIONINORDEREDLISTSTART ENDITEM {yyReadData = 1;}
	  y_XmlPositiveInteger POSITIONINORDEREDLISTEND
	  {$$ = $4;}
	;

y_PositionStandardDeviation_PositiveDecimalType_0 :
	  /* empty */
	  {$$ = 0;}
	| POSITIONSTANDARDDEVIATIONSTART ENDITEM {yyReadData = 1;}
	  DATASTRING POSITIONSTANDARDDEVIATIONEND
	  {$$ = new PositiveDecimalType($4);
	   if ($$->bad)
	     yyerror("bad PositionStandardDeviation value");
	  }
	;

y_PreconditionType :
	   ENDITEM y_Name_XmlID y_ListPredicateName_XmlIDREF_u
	  y_FunctionName_XmlIDREF_0
	  y_FunctionOperation_FunctionOperationType_0
	  y_ListF1LessF2_FunctionToFunctionLessType_0_u
	  y_ListF1EqualF2_FunctionToFunctionEqualType_0_u
	  y_ListF1GreaterOrEqualF2_FunctionToFunctionGreaterOrEqualType_0_u
	  y_ListF1GreaterF2_FunctionToFunctionGreaterType_0_u
	  y_ListF1LessOrEqualF2_FunctionToFunctionLessOrEqualType_0_u
	  {$$ = new PreconditionType($2, $3, $4, $5, $6, $7, $8, $9, $10);}
	;

y_Precondition_PreconditionType :
	  PRECONDITIONSTART y_PreconditionType PRECONDITIONEND
	  {$$ = $2;}
	;

y_PredicateGroupElementType :
	   ENDITEM y_Name_XmlID y_ReferenceName_XmlNMTOKEN
	  y_TargetName_XmlNMTOKEN_0 y_StateRelationName_XmlIDREF_0
	  {$$ = new PredicateGroupElementType($2, $3, $4, $5);}
	;

y_PredicateGroupElement_PredicateGroupElementType_u :
	  PREDICATEGROUPELEMENTSTART y_PredicateGroupElementType
	  PREDICATEGROUPELEMENTEND
	  {$$ = $2;}
	;

y_PredicateName_XmlIDREF_0_u :
	  PREDICATENAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  PREDICATENAMEEND
	  {$$ = $4;}
	;

y_PredicateName_XmlIDREF_u :
	  PREDICATENAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  PREDICATENAMEEND
	  {$$ = $4;}
	;

y_PredicateOccurrence_XmlPositiveInteger :
	  PREDICATEOCCURRENCESTART ENDITEM {yyReadData = 1;}
	  y_XmlPositiveInteger PREDICATEOCCURRENCEEND
	  {$$ = $4;}
	;

y_PredicateType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_ListPredicateGroupElement_PredicateGroupElementType_u
	  {$$ = new PredicateType($2, $3, $4);}
	;

y_Predicate_PredicateType :
	  PREDICATESTART y_PredicateType PREDICATEEND
	  {$$ = $2;}
	;

y_Predicate_PredicateType_u :
	  PREDICATESTART y_PredicateType PREDICATEEND
	  {$$ = $2;}
	;

y_PrimaryLocation_PhysicalLocationType :
	  PRIMARYLOCATIONSTART y_PhysicalLocationTypeAny PRIMARYLOCATIONEND
	  {$$ = $2;}
	;

y_PutKitTrayType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_KitTrayParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new PutKitTrayType($2, $3, $4, $5, $6, $7);}
	;

y_PutKitTray_PutKitTrayType :
	  PUTKITTRAYSTART y_PutKitTrayType PUTKITTRAYEND
	  {$$ = $2;}
	;

y_PutKitType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_KitParameter_XmlNMTOKEN
	  y_LargeBoxWithKitsParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new PutKitType($2, $3, $4, $5, $6, $7, $8);}
	;

y_PutKit_PutKitType :
	  PUTKITSTART y_PutKitType PUTKITEND
	  {$$ = $2;}
	;

y_PutPartType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_PartParameter_XmlNMTOKEN
	  y_KitParameter_XmlNMTOKEN y_PartsTrayParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new PutPartType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_PutPart_PutPartType :
	  PUTPARTSTART y_PutPartType PUTPARTEND
	  {$$ = $2;}
	;

y_RCC8Set_XmlString :
	  RCC8SETSTART ENDITEM {yyReadData = 1;} y_XmlString RCC8SETEND
	  {$$ = $4;}
	;

y_RefObjectName_XmlIDREF :
	  REFOBJECTNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  REFOBJECTNAMEEND
	  {$$ = $4;}
	;

y_ReferenceName_XmlNMTOKEN :
	  REFERENCENAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  REFERENCENAMEEND
	  {$$ = $4;}
	;

y_Requirement_XmlNMTOKEN_u :
	  REQUIREMENTSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  REQUIREMENTEND
	  {$$ = $4;}
	;

y_RobotParameter_XmlNMTOKEN :
	  ROBOTPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  ROBOTPARAMETEREND
	  {$$ = $4;}
	;

y_RobotType :
	   ENDITEM y_Name_XmlID y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Description_XmlString
	  y_EndEffector_EndEffectorType_0
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_ListWorkVolume_BoxVolumeType_u
	  {$$ = new RobotType($2, $3, $4, $5, $6, $7, $8, $9, $10);}
	;

y_Robot_RobotType :
	  ROBOTSTART y_RobotType ROBOTEND
	  {$$ = $2;}
	;

y_SOAPType :
	   ENDITEM y_Name_XmlID y_KittingWorkstation_KittingWorkstationType
	  y_Domain_DomainType y_InContactWith_InContactWithType
	  y_UnderWithContact_UnderWithContactType
	  y_PartiallyIn_PartiallyInType
	  y_OnTopWithContact_OnTopWithContactType
	  {$$ = new SOAPType($2, $3, $4, $5, $6, $7, $8);}
	;

y_SecondaryLocation_PhysicalLocationType_0_u :
	  SECONDARYLOCATIONSTART y_PhysicalLocationTypeAny
	  SECONDARYLOCATIONEND
	  {$$ = $2;}
	;

y_SerialNumber_XmlNMTOKEN :
	  SERIALNUMBERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  SERIALNUMBEREND
	  {$$ = $4;}
	;

y_SkuName_XmlIDREF :
	  SKUNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF SKUNAMEEND
	  {$$ = $4;}
	;

y_Sku_StockKeepingUnitType_u :
	  SKUSTART y_StockKeepingUnitType SKUEND
	  {$$ = $2;}
	;

y_SlotType :
	   ENDITEM y_Name_XmlID y_PartRefAndPoseName_XmlIDREF
	  y_PartName_XmlIDREF_0
	  {$$ = new SlotType($2, $3, $4);}
	;

y_Slot_SlotType_0_u :
	  SLOTSTART y_SlotType SLOTEND
	  {$$ = $2;}
	;

y_SolidObjectTypeAny :
	  y_x_EndEffectorChangingStationType
	  {$$ = $1;}
	| y_x_EndEffectorHolderType
	  {$$ = $1;}
	| y_x_GripperEffectorType
	  {$$ = $1;}
	| y_x_HumanType
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
	| y_x_MechanicalComponentType
	  {$$ = $1;}
	| y_x_PartType
	  {$$ = $1;}
	| y_x_PartsBinType
	  {$$ = $1;}
	| y_x_PartsTrayType
	  {$$ = $1;}
	| y_x_RobotType
	  {$$ = $1;}
	| y_x_VacuumEffectorMultiCupType
	  {$$ = $1;}
	| y_x_VacuumEffectorSingleCupType
	  {$$ = $1;}
	| y_x_WorkTableType
	  {$$ = $1;}
	;

y_StateRelationName_XmlIDREF_0 :
	  /* empty */
	  {$$ = 0;}
	| STATERELATIONNAMESTART ENDITEM {yyReadData = 1;} y_XmlIDREF
	  STATERELATIONNAMEEND
	  {$$ = $4;}
	;

y_StockKeepingUnitType :
	   ENDITEM y_Name_XmlID y_Description_XmlString
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Weight_PositiveDecimalType
	  y_ListEndEffectorName_XmlIDREF_0_u
	  {$$ = new StockKeepingUnitType($2, $3, $4, $5, $6, $7);}
	;

y_TakeKitTrayType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_KitTrayParameter_XmlNMTOKEN
	  y_LargeBoxWithEmptyKitTraysParameter_XmlNMTOKEN
	  y_EndEffectorParameter_XmlNMTOKEN y_Precondition_PreconditionType
	  y_Effect_EffectType
	  {$$ = new TakeKitTrayType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_TakeKitTray_TakeKitTrayType :
	  TAKEKITTRAYSTART y_TakeKitTrayType TAKEKITTRAYEND
	  {$$ = $2;}
	;

y_TakeKitType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_KitParameter_XmlNMTOKEN
	  y_EndEffectorParameter_XmlNMTOKEN y_Precondition_PreconditionType
	  y_Effect_EffectType
	  {$$ = new TakeKitType($2, $3, $4, $5, $6, $7, $8);}
	;

y_TakeKit_TakeKitType :
	  TAKEKITSTART y_TakeKitType TAKEKITEND
	  {$$ = $2;}
	;

y_TakePartType :
	   ENDITEM y_Name_XmlID y_Description_XmlString_0
	  y_RobotParameter_XmlNMTOKEN y_PartParameter_XmlNMTOKEN
	  y_PartsTrayParameter_XmlNMTOKEN y_EndEffectorParameter_XmlNMTOKEN
	  y_Precondition_PreconditionType y_Effect_EffectType
	  {$$ = new TakePartType($2, $3, $4, $5, $6, $7, $8, $9);}
	;

y_TakePart_TakePartType :
	  TAKEPARTSTART y_TakePartType TAKEPARTEND
	  {$$ = $2;}
	;

y_TargetName_XmlNMTOKEN_0 :
	  /* empty */
	  {$$ = 0;}
	| TARGETNAMESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  TARGETNAMEEND
	  {$$ = $4;}
	;

y_Timestamp_XmlDateTime_0 :
	  /* empty */
	  {$$ = 0;}
	| TIMESTAMPSTART ENDITEM {yyReadData = 1;} y_XmlDateTime
	  TIMESTAMPEND
	  {$$ = $4;}
	;

y_UnderWithContactType :
	   ENDITEM y_Name_XmlID y_RCC8Set_XmlString
	  {$$ = new UnderWithContactType($2, $3);}
	;

y_UnderWithContact_UnderWithContactType :
	  UNDERWITHCONTACTSTART y_UnderWithContactType UNDERWITHCONTACTEND
	  {$$ = $2;}
	;

y_Value_XmlPositiveInteger :
	  VALUESTART ENDITEM {yyReadData = 1;} y_XmlPositiveInteger
	  VALUEEND
	  {$$ = $4;}
	;

y_Variable_XmlNMTOKEN_u :
	  VARIABLESTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN VARIABLEEND
	  {$$ = $4;}
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

y_WorkTableParameter_XmlNMTOKEN :
	  WORKTABLEPARAMETERSTART ENDITEM {yyReadData = 1;} y_XmlNMTOKEN
	  WORKTABLEPARAMETEREND
	  {$$ = $4;}
	;

y_WorkVolume_BoxVolumeType_u :
	  WORKVOLUMESTART y_BoxVolumeType WORKVOLUMEEND
	  {$$ = $2;}
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

y_x_BoxyShapeType :
	  BOXYSHAPETYPEDECL ENDITEM y_Name_XmlID y_Description_XmlString
	  y_GraspPose_PoseLocationType_0 y_Length_PositiveDecimalType
	  y_Width_PositiveDecimalType y_Height_PositiveDecimalType
	  y_HasTop_XmlBoolean
	  {$$ = new BoxyShapeType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_CylindricalShapeType :
	  CYLINDRICALSHAPETYPEDECL ENDITEM y_Name_XmlID
	  y_Description_XmlString y_GraspPose_PoseLocationType_0
	  y_Diameter_PositiveDecimalType y_Height_PositiveDecimalType
	  y_HasTop_XmlBoolean
	  {$$ = new CylindricalShapeType($3, $4, $5, $6, $7, $8);
	   $$->printTypp = true;
	  }
	;

y_x_EndEffectorChangingStationType :
	  ENDEFFECTORCHANGINGSTATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_Base_MechanicalComponentType
	  y_ListEndEffectorHolder_EndEffectorHolderType_u
	  {$$ = new EndEffectorChangingStationType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_EndEffectorHolderType :
	  ENDEFFECTORHOLDERTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_EndEffector_EndEffectorType_0
	  {$$ = new EndEffectorHolderType($3, $4, $5, $6, $7, $8);
	   $$->printTypp = true;
	  }
	;

y_x_GripperEffectorType :
	  GRIPPEREFFECTORTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Description_XmlString
	  y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_HeldObject_SolidObjectType_0
	  {$$ = new GripperEffectorType($3, $4, $5, $6, $7, $8, $9, $10, $11);
	   $$->printTypp = true;
	  }
	;

y_x_HumanType :
	  HUMANTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  {$$ = new HumanType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_KitTrayType :
	  KITTRAYTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new KitTrayType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_KitType :
	  KITTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_DesignName_XmlIDREF
	  y_KitTray_KitTrayType y_ListPart_PartType_0_u
	  y_ListSlot_SlotType_0_u y_Finished_XmlBoolean
	  {$$ = new KitType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12);
	   $$->printTypp = true;
	  }
	;

y_x_KittingWorkstationType :
	  KITTINGWORKSTATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_AngleUnit_AngleUnitType
	  y_ChangingStation_EndEffectorChangingStationType
	  y_ListKitDesign_KitDesignType_u y_LengthUnit_LengthUnitType
	  y_ListObject_SolidObjectType_u
	  y_ListOtherObstacle_BoxVolumeType_0_u y_Robot_RobotType
	  y_ListSku_StockKeepingUnitType_u y_WeightUnit_WeightUnitType
	  {$$ = new KittingWorkstationType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16);
	   $$->printTypp = true;
	  }
	;

y_x_LargeBoxWithEmptyKitTraysType :
	  LARGEBOXWITHEMPTYKITTRAYSTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_LargeContainer_LargeContainerType y_ListKitTray_KitTrayType_0_u
	  {$$ = new LargeBoxWithEmptyKitTraysType($3, $4, $5, $6, $7, $8, $9);
	   $$->printTypp = true;
	  }
	;

y_x_LargeBoxWithKitsType :
	  LARGEBOXWITHKITSTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_LargeContainer_LargeContainerType y_ListKit_KitType_0_u
	  y_KitDesignName_XmlIDREF y_Capacity_XmlPositiveInteger
	  {$$ = new LargeBoxWithKitsType($3, $4, $5, $6, $7, $8, $9, $10, $11);
	   $$->printTypp = true;
	  }
	;

y_x_LargeContainerType :
	  LARGECONTAINERTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new LargeContainerType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_MechanicalComponentType :
	  MECHANICALCOMPONENTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  {$$ = new MechanicalComponentType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PartType :
	  PARTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  {$$ = new PartType($3, $4, $5, $6, $7);
	   $$->printTypp = true;
	  }
	;

y_x_PartsBinType :
	  PARTSBINTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  y_PartSkuName_XmlIDREF y_PartQuantity_XmlNonNegativeInteger
	  y_ListPart_PartType_0_u
	  {$$ = new PartsBinType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PartsTrayType :
	  PARTSTRAYTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_SkuName_XmlIDREF y_SerialNumber_XmlNMTOKEN
	  y_PartSkuName_XmlIDREF y_PartQuantity_XmlNonNegativeInteger
	  y_ListPart_PartType_0_u
	  {$$ = new PartsTrayType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationInType :
	  POSELOCATIONINTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlIDREF y_Timestamp_XmlDateTime_0
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseLocationInType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PoseLocationOnType :
	  POSELOCATIONONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlIDREF y_Timestamp_XmlDateTime_0
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseLocationOnType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_PoseOnlyLocationType :
	  POSEONLYLOCATIONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlIDREF y_Timestamp_XmlDateTime_0
	  y_Point_PointType y_XAxis_VectorType y_ZAxis_VectorType
	  y_PositionStandardDeviation_PositiveDecimalType_0
	  y_OrientationStandardDeviation_PositiveDecimalType_0
	  {$$ = new PoseOnlyLocationType($3, $4, $5, $6, $7, $8, $9, $10);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationInType :
	  RELATIVELOCATIONINTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlIDREF y_Timestamp_XmlDateTime_0
	  y_Description_XmlString
	  {$$ = new RelativeLocationInType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_RelativeLocationOnType :
	  RELATIVELOCATIONONTYPEDECL ENDITEM y_Name_XmlID
	  y_RefObjectName_XmlIDREF y_Timestamp_XmlDateTime_0
	  y_Description_XmlString
	  {$$ = new RelativeLocationOnType($3, $4, $5, $6);
	   $$->printTypp = true;
	  }
	;

y_x_RobotType :
	  ROBOTTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Description_XmlString
	  y_EndEffector_EndEffectorType_0
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_ListWorkVolume_BoxVolumeType_u
	  {$$ = new RobotType($3, $4, $5, $6, $7, $8, $9, $10, $11);
	   $$->printTypp = true;
	  }
	;

y_x_VacuumEffectorMultiCupType :
	  VACUUMEFFECTORMULTICUPTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Description_XmlString
	  y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_HeldObject_SolidObjectType_0 y_CupDiameter_PositiveDecimalType
	  y_Length_PositiveDecimalType y_ArrayNumber_XmlPositiveInteger
	  y_ArrayRadius_PositiveDecimalType
	  {$$ = new VacuumEffectorMultiCupType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15);
	   $$->printTypp = true;
	  }
	;

y_x_VacuumEffectorSingleCupType :
	  VACUUMEFFECTORSINGLECUPTYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0 y_Description_XmlString
	  y_Weight_PositiveDecimalType
	  y_MaximumLoadWeight_PositiveDecimalType
	  y_HeldObject_SolidObjectType_0 y_CupDiameter_PositiveDecimalType
	  y_Length_PositiveDecimalType
	  {$$ = new VacuumEffectorSingleCupType($3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13);
	   $$->printTypp = true;
	  }
	;

y_x_WorkTableType :
	  WORKTABLETYPEDECL ENDITEM y_Name_XmlID
	  y_PrimaryLocation_PhysicalLocationType
	  y_ListSecondaryLocation_PhysicalLocationType_0_u
	  y_InternalShape_InternalShapeType_0
	  y_ExternalShape_ExternalShapeType_0
	  y_ListObjectOnTable_SolidObjectType_0_u
	  {$$ = new WorkTableType($3, $4, $5, $6, $7, $8);
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
