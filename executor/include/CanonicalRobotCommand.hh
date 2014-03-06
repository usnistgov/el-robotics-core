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
/*!
 *	\file		CanonicalRobotCommand.hh
 *	\brief 		Test
 *	\class		CanonicalRobotCommand
 *	\brief 		This class provides functions to build <b>Canonical Robot Commands</b> from PDDL actions in the Plan.
 *	\author		Zeid Kootbally, NIST and Stephen Balakirsky, GTRI
 *	\date		May 17, 2012
 */

#ifndef CANONICALROBOTCOMMAND_H_
#define CANONICALROBOTCOMMAND_H_

#include "DatabaseUpdate.hh"
#include "Tools.hh"
#include "KittingPlan.hh"
#include "recurseLocation.h"
//-- Headers to access data from the database
#include "database/DAO.h"
#include "database/KitDesign.h"
#include "database/Kit.h"
#include "database/Part.h"
#include "database/PartRefAndPose.h"
#include "database/PartsTray.h"
#include "database/Point.h"
#include "database/PoseLocation.h"
#include "database/PhysicalLocation.h"
#include "database/Robot.h"
#include "database/ShapeDesign.h"
#include "database/StockKeepingUnit.h"
#include "database/Vector.h"
#include "database/KitTray.h"
#include "Structdef.hh"

// basic file operations
#include <iostream>
#include <fstream>

//-- Functions needed to create a directory
#include<sys/stat.h>
#include<sys/types.h>
#include <errno.h>

// other classes needed
#include "controller.hh"

typedef enum 
  {
    PRECONDITION = 0,
    ACTION,
    EFFECT
  }PDDLPhase;

class CanonicalRobotCommand {
public:
  CanonicalRobotCommand();
  virtual ~CanonicalRobotCommand();

  /* output options */
  void setController(Controller *controller, std::string sensorHostName);
  void setFileOperator(FileOperator *fileoperator);

  void actionInterpreter(string action,vector<string> paramName,
			 KittingPlan *kittingplan, PDDLPhase phase);
  /* plan interpretation actions
     can either use initialize, step, finalize in sequence or
     interpret all by itself. CRCL commands may be retrieved with getNextCRCL
  */
  void initializePlan(KittingPlan *kittingplan);
  int stepPlan(KittingPlan *kittingplan, PDDLPhase phase);
  void finalizePlan(KittingPlan *kittingplan);
  void interpretPlan(KittingPlan *kittingplan);
  std::string getNextCRCL();

  /* generate canonical robot command language commands from PDDL */
  void canon_put_part(vector<double> xyz, vector<double> z_axis, 
		      vector<double> x_axis);
  void canon_take_part(vector<double> xyz, vector<double> z_axis, 
		       vector<double> x_axis);

  /* examine the effects of PDDL actions */
  void effect_put_part(string robot, string slot, string part);
  void effect_take_part(string robot, string part, Frame graspFrame);

  /* examine the PDDL preconditions */
  int precondition_put_part();
  int precondition_take_part();

  /* methods to process pddl actions */
  void attach_eff(vector<string> paramList,KittingPlan *kittingplan, PDDLPhase phase);
  void create_kit(vector<string> paramList, KittingPlan *kittingplan, PDDLPhase phase);
  void look_for_part(vector<string> paramList, KittingPlan *kittingplan, PDDLPhase phase);
  bool look_for_slot(vector<string> paramList, KittingPlan *kittingplan, PDDLPhase phase);
  void put_kit(vector<string> paramList, PDDLPhase phase);
  void put_kit_tray(vector<string> paramList, PDDLPhase phase);
  void put_part(vector<string> paramList,KittingPlan *kittingplan, PDDLPhase phase);
  void remove_eff(vector<string> paramList, PDDLPhase phase);
  void take_kit(vector<string> paramList, PDDLPhase phase);
  void take_kit_tray(vector<string> paramList, PDDLPhase phase);
  void take_part(vector<string> paramList,KittingPlan *kittingplan, PDDLPhase phase);

  RecLoc getPartGoalLocation(string part_name, string slotLocation);
  void sql_put_part(string partName, string goalRefObject);

  //Point* getRobotPoseLocation(string robotName);

private:
  KitTrayLocStruct getKitTrayLocation(string kit_tray_name);
  PartsTrayLocStruct getPartsTrayLocation(string parts_tray_name);

  RecLoc getPartLocation(string part_name, Frame grasp_frame);
  string getPartInstance(string part_name);
  void print_closegripper();
  void print_dwell(double time);
  void print_endcannon(int id);
  void print_initcannon();
  void print_moveto(double x, double y, double z, vector<double> z_axis, 
		    vector<double> x_axis);
  void print_opengripper();
  void processCRCL( string input );

  Controller *m_controller;
  double m_safe_z;
  double m_dwell;
  string m_kit_tray;
  FileOperator* m_file_operator;
  Frame located_frame; // grasp frame to use for located part
  RecurseLocation recurseLocation;
  string located_part; // part located by look_for_part command
  string located_slot; // slot located by look_for_slot command
  DAO* dao;
  vector<string> commandsCRCL;
};

#endif /* CANONICALROBOTCOMMAND_H_ */
