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
  std::string retString;

  skuObject->get(object->getname());
  sku = skuObject->gethasSkuObject_Sku();
  if( sku == NULL )
    return "Unknown model";
  retString = getModel(sku);
  delete skuObject;
  return retString;
}

std::string GenericModel::getModel(StockKeepingUnit *sku)
{
  std::string modelName;
  ShapeDesign *shapeDesign;
  ExternalShape *externalShape;

  sku->get(sku->getname());


  externalShape = sku->gethadByExternalShape_StockKeepingUnit();
  if( externalShape->getExternalShapeID() > 0 )
    {
      /*
      printf( "%s has external model\n", sku->getname().c_str() );
      printf( "external model type: %s name: %s model file name: %s\n",
	      externalShape->gethasExternalShape_ModelTypeName().c_str(),
	      externalShape->gethasExternalShape_ModelName().c_str(),
	      externalShape->gethasExternalShape_ModelFileName().c_str() );
      */
      externalShape->get(externalShape->getname());
      modelName = externalShape->gethasExternalShape_ModelFileName() +
	std::string (".") + 
	externalShape->gethasExternalShape_ModelName();
    }
  else
    {
      modelName = "USARPhysObj.Unknown";
      //      printf( "%s is not an external shape\n", sku->getname().c_str() );
    }

  return modelName;
}
