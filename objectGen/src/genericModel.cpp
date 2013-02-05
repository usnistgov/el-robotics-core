#include "genericModel.h"

GenericModel::GenericModel()
{
}

std::string GenericModel::getModel(StockKeepingUnit *sku)
{
  std::string modelName;
  ShapeDesign *shapeDesign;
  ExternalShape *externalShape;
  ShapeDesign *testShape;

  sku->get(sku->getname());


  testShape = sku->gethasSku_Shape();
  externalShape = new ExternalShape(testShape->getname());
  externalShape->get(testShape->getname());
  if( externalShape->getExternalShapeID() > 0 )
    {
      /*
      printf( "%s has external model\n", sku->getname().c_str() );
      printf( "external model type: %s name: %s model file name: %s\n",
	      externalShape->gethasExternalShape_ModelTypeName().c_str(),
	      externalShape->gethasExternalShape_ModelName().c_str(),
	      externalShape->gethasExternalShape_ModelFileName().c_str() );
      */
      modelName = externalShape->gethasExternalShape_ModelFileName();
    }
  else
    {
      modelName = "USARPhysObj.unknown";
      //      printf( "%s is not an external shape\n", sku->getname().c_str() );
    }

  // need shape design to get grasp point
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());

  delete externalShape;
  return modelName;
}
