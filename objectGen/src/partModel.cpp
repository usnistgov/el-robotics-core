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

  sku = part->gethasPart_Sku();
  printf( "getting sku name: \"%s\"\n", sku->getname().c_str() );
  sku->get(sku->getname());
  modelName = sku->gethasSku_Description();
  return modelName;
}
