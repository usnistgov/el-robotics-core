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
  StockKeepingUnit *sku;

  sku = part->gethasPart_Sku();
  return (GenericModel::getModel(sku));
}
