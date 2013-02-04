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

  sku = part->gethasPart_Sku();
  //  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());

  externalShape = (ExternalShape*)sku->gethasSku_Shape();
  if( externalShape == NULL )
    printf( "%s has no external model\n", sku->getname().c_str() );
  else
    {
      printf( "%s has external model\n", sku->getname().c_str() );
      printf( "external model type: %s name: %s\n",
	      externalShape->gethasExternalShape_ModelTypeName().c_str(),
	      externalShape->gethasExternalShape_ModelName().c_str() );
      modelName = externalShape->gethasExternalShape_ModelName();
    }

  // need shape design to get grasp point
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());

  return modelName;
}
