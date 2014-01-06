#ifndef __genericModel
#define __genericModel
#include "ExternalShape.h"
#include "ShapeDesign.h"
#include "SkuObject.h"
#include "SolidObject.h"
#include "StockKeepingUnit.h"
#include <stdio.h> // printf
#include <string>

class GenericModel{
 public:
  GenericModel();
  static std::string getModel(StockKeepingUnit *sku);
  static std::string getModel(SolidObject *object);
};

#endif
