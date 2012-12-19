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

  sku = part->gethasPart_Sku();
  //  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());
  modelName = shapeDesign->gethasShapeDesign_Model();
  return modelName;
}
