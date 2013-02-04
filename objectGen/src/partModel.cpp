#include "partModel.h"

PartModel::PartModel()
{
  part = NULL;
}

PartModel::PartModel( Part *partIn )
{
  setPart(partIn);
}

void PartModel::setPart( Part *partIn )
{
  part = partIn;
}

std::string PartModel::getModel()
{
  std::string modelName;
  StockKeepingUnit *sku;
  ShapeDesign *shapeDesign;
  ExternalShape *externalShape;
  InternalShape *internalShape;
  ShapeDesign *testShape;

  sku = part->gethasPart_Sku();
  //  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());


  testShape = sku->gethasSku_Shape();
  //  externalShape = (ExternalShape*)sku->gethasSku_Shape();
  externalShape = new ExternalShape(testShape->getname());
  externalShape->get(testShape->getname());
  if( externalShape->getExternalShapeID() > 0 )
    {
      printf( "%s has external model\n", sku->getname().c_str() );
      printf( "external model type: %s name: %s model file name: %s\n",
	      externalShape->gethasExternalShape_ModelTypeName().c_str(),
	      externalShape->gethasExternalShape_ModelName().c_str(),
	      externalShape->gethasExternalShape_ModelFileName().c_str() );
      modelName = externalShape->gethasExternalShape_ModelName();
    }
  else
    {
      printf( "%s is not an external shape\n", sku->getname().c_str() );
    }

  // need shape design to get grasp point
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());

  return modelName;
}
