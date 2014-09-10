/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
*****************************************************************************/
/*!
 *	\file   Structdef.hh
 *	\brief  Structures used to define the location for different structures
 *	\author <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *	\date   May 17, 2012
*/
#ifndef STRUCTDEF_H_
#define STRUCTDEF_H_



/*!
* \struct PartLocStruct Structdef.hh
* \brief Represents a part location
* \var PartLocStruct::point
* Member \a point contains the coordinates of the part
* \var PartLocStruct::x_axis
* Member \a x_axis represents the X axis for the part
* \var PartLocStruct::z_axis
* Member \a z_axis represents the Z axis for the part
*/
struct PartLocStruct
{
	Point* point;
	Vector* x_axis;
	Vector* z_axis;
};


/**
 *  @struct		PartsTrayLocStruct
 *  @brief		This structure represents a parts tray location
 *  @var		PartsTrayLocStruct::point
 *  Member @a point contains the coordinates of the parts tray
 *  @var		PartsTrayLocStruct::x_axis
 *  Member @a x_axis represents the X axis for the parts tray
 *  @var		PartsTrayLocStruct::z_axis
 *  Member @a z_axis represents the Z axis for the parts tray
 */
struct PartsTrayLocStruct
{
	Point* point;
	Vector* x_axis;
	Vector* z_axis;
};

/**
 *  @struct		KitTrayLocStruct
 *  @brief		This structure represents a kit tray location
 *  @var		KitTrayLocStruct::point
 *  Member @a point contains the coordinates of the kit tray
 *  @var		KitTrayLocStruct::x_axis
 *  Member @a x_axis represents the X axis for the kit tray
 *  @var		KitTrayLocStruct::z_axis
 *  Member @a z_axis represents the Z axis for the kit tray
 */
struct KitTrayLocStruct
{
	Point* point;
	Vector* x_axis;
	Vector* z_axis;
};




#endif /* STRUCTDEF_H_ */
