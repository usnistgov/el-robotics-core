/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
 *****************************************************************************/
#include "genericModel.h"

GenericModel::GenericModel()
{
}
std::string GenericModel::getModel(SolidObject *object)
{
  SkuObject *skuObject = new SkuObject("foo");
  StockKeepingUnit *sku;
  NoSkuObject *noSku = new NoSkuObject("foo");
  std::string retString;
  
  skuObject->get(object->getname());
  sku = skuObject->gethasSkuObject_Sku();
  if( sku == NULL )
    {
      noSku->get(object->getname());
      retString = getModel(noSku);
    }
  else 
    retString = getModel(sku);
  delete skuObject;
  delete noSku;
  return retString;
}

std::string GenericModel::getModel(StockKeepingUnit *sku)
{
  std::string modelName;
  ExternalShape *externalShape;

  sku->get(sku->getname());
  externalShape = sku->gethadByExternalShape_StockKeepingUnit();
  modelName = getModel( externalShape );
  return modelName;
}

std::string GenericModel::getModel(NoSkuObject *noSku)
{
  std::string modelName;
  ExternalShape *externalShape;

  noSku->get(noSku->getname());

  externalShape = noSku->gethadByExternalShape_NoSkuObject();
  modelName = getModel( externalShape );
  return modelName;
}

std::string GenericModel::getModel(ExternalShape *externalShape)
{
  std::string modelName = "Unknown_model";

  if( externalShape == NULL )
    return modelName;

  if( externalShape->getExternalShapeID() > 0 )
    {
      externalShape->get(externalShape->getname());
      modelName = externalShape->gethasExternalShape_ModelFileName() +
	std::string (".") + 
	externalShape->gethasExternalShape_ModelName();
    }
  return modelName;
}
