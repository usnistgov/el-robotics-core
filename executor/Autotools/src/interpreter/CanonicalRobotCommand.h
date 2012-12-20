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
*	\file		CanonicalRobotCommand.h
*	\brief 		Test
*	\class		CanonicalRobotCommand
*	\brief 		This class provides functions to build <b>Canonical Robot Commands</b> from PDDL actions in the Plan.
*	\author		<a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
*	\date		May 17, 2012
*/

#ifndef CANONICALROBOTCOMMAND_H_
#define CANONICALROBOTCOMMAND_H_


#include "Tools.h"
#include "KittingPlan.h"
#include "recurseLocation.h"
//-- Headers to access data from the database

#include "database/KitDesign.h"
#include "database/Kit.h"
#include "database/Part.h"
#include "database/PartRefAndPose.h"
#include "database/PartsTray.h"
#include "database/Point.h"
#include "database/PoseLocation.h"
#include "database/PhysicalLocation.h"
#include "database/Robot.h"
#include "database/Vector.h"
#include "database/KitTray.h"
#include "Structdef.h"

// basic file operations
#include <iostream>
#include <fstream>

//-- Functions needed to create a directory
#include<sys/stat.h>
#include<sys/types.h>
#include <errno.h>


class CanonicalRobotCommand {
public:
	CanonicalRobotCommand();
	virtual ~CanonicalRobotCommand();

	void actionInterpreter(string action,vector<string> paramName,KittingPlan *kittingplan);
	void interpretPlan(KittingPlan *kittingplan);


	void attach_eff(vector<string> paramList,KittingPlan *kittingplan);
	void canon_put_part(vector<double> xyz, vector<double> z_axis, vector<double> x_axis);
	void canon_take_part(vector<double> xyz, vector<double> z_axis, vector<double> x_axis);
	void create_kit(vector<string> paramList, KittingPlan *kittingplan);

	RecLoc getPartGoalLocation(string part_name, string kit_name);
	void put_kit(vector<string> paramList);
	void put_kit_tray(vector<string> paramList);
	void put_part(vector<string> paramList,KittingPlan *kittingplan);
	void remove_eff(vector<string> paramList);
	void take_kit(vector<string> paramList);
	void take_kit_tray(vector<string> paramList);
	void take_part(vector<string> paramList,KittingPlan *kittingplan);

	//Point* getRobotPoseLocation(string robotName);

private:
	KitTrayLocStruct getKitTrayLocation(string kit_tray_name);
	PartsTrayLocStruct getPartsTrayLocation(string parts_tray_name);
	RecLoc getPartLocation(string part_name);
	void print_closegripper();
	void print_dwell(double time);
	void print_endcannon(int id);
	void print_initcannon();
	void print_moveto(double x, double y, double z, vector<double> z_axis, 
			  vector<double> x_axis);
	void print_opengripper();

	double m_safe_z;
	double m_dwell;
	string m_kit_tray;
};

#endif /* CANONICALROBOTCOMMAND_H_ */
