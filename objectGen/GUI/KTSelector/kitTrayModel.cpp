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
  StockKeepingUnit *sku;

  sku = kitTray->gethasKitTray_Sku();
  return (GenericModel::getModel(sku));
}
