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
  StockKeepingUnit *sku;

  sku = partsTray->gethasPartsTray_Sku();
  return (GenericModel::getModel(sku));
}
