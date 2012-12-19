#include "partsTrayModel.h"

PartsTrayModel::PartsTrayModel()
{
  partsTray = NULL;
}

PartsTrayModel::PartsTrayModel( PartsTray *partsTrayIn )
{
  setPartsTray(partsTrayIn);
}

void PartsTrayModel::setPartsTray( PartsTray *partsTrayIn )
{
  partsTray = partsTrayIn;
}

std::string PartsTrayModel::getModel()
{
  std::string modelName;
  StockKeepingUnit *sku;
  ShapeDesign *shapeDesign;

  sku = partsTray->gethasPartsTray_Sku();
  //  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());
  modelName = shapeDesign->gethasShapeDesign_Model();
  return modelName;
}
