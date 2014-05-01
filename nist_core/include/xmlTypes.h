///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       XML
//  Workfile:        xmlTypes.h
//  Revision:        1.0 - 18 March, 2014
//
//  Author:          J. Marvel
//
//  Description
//  ===========
//  XML library type defintions
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XML_TYPES_H
#define XML_TYPES_H

#include "..\..\portable.h"
#include "..\..\types.h"

//! @brief Inner-tag parameter attributes (ex <tag name="val">)
//!
struct xmlAttributes
{
  //! @brief The list of parameter names
  //!
  std::vector<std::string> name;

  //! @brief The list of parameter values
  //!
  std::vector<std::string> val;
};

#endif