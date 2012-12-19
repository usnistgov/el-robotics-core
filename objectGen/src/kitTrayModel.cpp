#include "kitTrayModel.h"

KitTrayModel::KitTrayModel()
{
  kitTray = NULL;
}

KitTrayModel::KitTrayModel( KitTray *kitTrayIn )
{
  setKitTray(kitTrayIn);
}

void KitTrayModel::setKitTray( KitTray *kitTrayIn )
{
  kitTray = kitTrayIn;
}

std::string KitTrayModel::getModel()
{
  std::string modelName;
  StockKeepingUnit *sku;
  ShapeDesign *shapeDesign;

  sku = kitTray->gethasKitTray_Sku();
  //  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());
  shapeDesign = sku->gethasSku_Shape();
  shapeDesign->get(shapeDesign->getname());
  modelName = shapeDesign->gethasShapeDesign_Model();
  return modelName;
}
