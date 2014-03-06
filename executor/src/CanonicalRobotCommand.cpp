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
 *	\file		CanonicalRobotCommand.cpp
 *	\brief 		Parse and process canonical robot commands
 *	\class		CanonicalRobotCommand
 *	\author		Zeid Kootbally, NIST and Stephen Balakirsky, GTRI
 *	\date		July 30, 2013
 *      \copyright      Georgia Tech Research Institute
 */
#include "CanonicalRobotCommand.hh"
#include "Tools.hh"
#include "recurseLocation.h"
#include <iostream>
#include <algorithm>

/*!
  @brief Constructor
 */
CanonicalRobotCommand::CanonicalRobotCommand()
{
  m_file_operator = NULL;
  m_controller = NULL;
  m_safe_z = 0.25;
  m_dwell = 0.05;
  located_part = ""; // clear out located part to show that 
  // one has not been found
  located_slot = ""; // clear out located slot to show that 
  // one has not been found
  located_frame.clear(); // clear out located frame to show 
  // that one has not been found
  dao = new DAO("PartsTrayWithParts");
}

/*!
  @brief Auto-generated destructor stub
 */
CanonicalRobotCommand::~CanonicalRobotCommand() {
}

/*! 
  @brief Set the controller to use for action execution

  Commands will be queued in the controllers low-priority action queue
  for execution. The return status of each command will be verified
  before executing the next command.

  @param controller The controller to send actions to.
*/
void CanonicalRobotCommand::setController( Controller *controller,
					   std::string sensorHostName)
{
  m_controller = controller;
  // connect to sensor system if possible
  recurseLocation.sensorConnect(sensorHostName);
}

/*!
  @brief Set the FileOperator if writing to a file

  Commands will be written to the given file.

  @param 
*/
void CanonicalRobotCommand::setFileOperator(FileOperator *fileoperator) 
{
  m_file_operator = fileoperator;
}

/*!
  @brief Match each action found in the plan with a function

  @param action_name Action from the plan
  @param paramList List of parameters for the action @a action_name
  @param kittingplan Instance of KittingPlan
  @param phase enum of PDDLPhase that dictates if we are processing action or effect
 */
void CanonicalRobotCommand::actionInterpreter(string action_name,
					      vector<string> paramList,
					      KittingPlan *kittingplan,
					      PDDLPhase phase)
{
  /*
  printf( "CanonicalRobotCommand::actionInterpreter: action %s phase %d\n",
	  action_name.c_str(), phase );
  */
  if(action_name == "attach-endeffector")	     
    attach_eff(paramList, kittingplan, phase);
  else if(action_name == "create-kit")         
    create_kit(paramList, kittingplan, phase);
  else if(action_name == "look-for-part")      
    look_for_part(paramList, kittingplan, phase);
  else if(action_name == "look-for-slot")
    {
      if( !look_for_slot(paramList, kittingplan, phase) )
	{
	  printf( "Could not find slot. Don't know what to do\n" );
	  exit(1);
	}
    }
  else if(action_name == "put-kit")            
    put_kit(paramList, phase);
  else if(action_name == "put-kittray")
    put_kit_tray(paramList, phase);
  else if(action_name == "put-part")           
    put_part(paramList, kittingplan, phase);
  else if(action_name == "remove-endeffector") 
    remove_eff(paramList, phase);
  else if(action_name == "take-kit")           
    take_kit(paramList, phase);
  else if(action_name == "take-kittray")       
    take_kit_tray(paramList, phase);
  else if(action_name == "take-part")          
    take_part(paramList, kittingplan, phase);
  else 
    printf( "unknown pddl action of %s\n", action_name.c_str() );
}

/*!
  @brief A canonical robot command for the PDDL action <b>attach-eff</b>
  @param paramList List of parameters for the action <b>attach-eff</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>attach-eff</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::attach_eff(vector<string> paramList,
				       KittingPlan *kittingplan, PDDLPhase phase)
{
}

/*!
  @brief A canonical robot command for the PDDL action <b>create-kit</b>
  @param paramList List of parameters for the action <b>create-kit</b>

  The data to be inserted in the table Kit are:
  <ul>
  <li>KitID: ID of the new Kit.
  <li>_NAME: Name of the new Kit.
  <li>hasKit_DesignRef: Kit design associated to this Kit.
  <li>isKit_Finished: 1 if the Kit is finished, 0 otherwise.
  <li>hadByKit_LargeBoxWithKits: The LargeBoxWithKits that is capable of containing this Kit.
  <li>hasKit_Tray: Kit Tray associated to this Kit.
  </ul>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>create-kit</b> is implemented
 */
void CanonicalRobotCommand::create_kit(vector<string> paramList, 
				       KittingPlan *kittingplan, PDDLPhase phase)
{
  int listLength;
  listLength=(int)paramList.size();

  if (phase == EFFECT)
    return;
  for (vector<string>::size_type i = 0; i < listLength; i++)
    {
      string type;
      type=kittingplan->matchParamType(paramList[i]);
      FileOperator::stripSpace(type);

      if (!strcmp(type.c_str(),"Kit"))
	{
	  //cout <<"Message (\"create kit " << paramList[i] <<"\")"<< endl;
	}

      if (!strcmp(type.c_str(),"KitTray"))
	{
	  //cout <<"Message (\"kit tray " << paramList[i] <<"\")"<< endl;
	  m_kit_tray=paramList[i];
	}
    }
}

/*!
  @brief A canonical robot command for the PDDL action <b>look-for-part</b>
  @param paramList List of parameters for the action <b>look-for-part</b>
  (example: <b>look-for-part</b> robot_1 part_c_1 partstray_a kit_1 Work_table_1 end_eff_1)
 */
void CanonicalRobotCommand::look_for_part(vector<string> paramList, 
					  KittingPlan *kittingplan, PDDLPhase phase)
{
  int listLength;
  SkuObject *skuObject = new SkuObject("foo");
  StockKeepingUnit *sku;
  ShapeDesign *shapeDesign;
  PoseLocation *graspPose;
  Point *point;
  Vector *myVector;
  Part *part = new Part(located_part);
  bool found = false;

  if (phase == EFFECT)
    return;
  listLength=(int)paramList.size();

  for (vector<string>::size_type i = 0; i < listLength; i++)
    {
      string type;
      type=kittingplan->matchParamType(paramList[i]);
      m_file_operator->stripSpace(type);
    
      if (!strcmp(type.c_str(),"Part"))
	{
	  //      printf( "Looking for part %s\n", paramList[i].c_str() );
	  located_part = getPartInstance(paramList[i]);
	  processCRCL( "Message (\"Looking for part " + located_part +"\")\n" );
	  if( located_part == "" ) // no part found
	    {
	      printf( "Could not find part! Don't know what to do!\n" );
	      exit(1);
	    }
	  break;
	}
  }

  /* get grasp location */
  // first get sku
  part->get(located_part);
  skuObject->get(part->getname());
  sku = skuObject->gethasSkuObject_Sku();
  sku->get(sku->getname());

  // from sku, get shape
  // first check if there is an internal shape
  shapeDesign = (ShapeDesign*)sku->gethasStockKeepingUnit_InternalShape();
  if( shapeDesign == NULL ) // check for external shape
    {
      shapeDesign = (ShapeDesign*)sku->gethadByExternalShape_StockKeepingUnit();
      if( shapeDesign == NULL )
	{
	  return;
	}
    }
  shapeDesign->get(shapeDesign->getname());

  // from shape design, get grasp pose
  graspPose = shapeDesign->gethadByGraspPose_ShapeDesign();
  graspPose->get(graspPose->getname());
  located_frame.clear();

  // from the grasp pose, get the point
  point = graspPose->gethasPoseLocation_Point();
  located_frame.pose.setPointName(point->getname());
  point->get(located_frame.pose.getPointName());
  located_frame.pose.setPoint(point->gethasPoint_X(), 
			      point->gethasPoint_Y(), 
			      point->gethasPoint_Z());

  // from the grasp pose, get the XAxis vector
  myVector = graspPose->gethasPoseLocation_XAxis();
  located_frame.pose.setXAxisName(myVector->getname());
  myVector->get(located_frame.pose.getXAxisName());
  located_frame.pose.setXAxis(myVector->gethasVector_I(), 
			      myVector->gethasVector_J(), 
			      myVector->gethasVector_K());

  // from the grasp pose, get the ZAxis vector
  myVector = graspPose->gethasPoseLocation_ZAxis();
  located_frame.pose.setZAxisName(myVector->getname());
  myVector->get(located_frame.pose.getZAxisName());
  located_frame.pose.setZAxis(myVector->gethasVector_I(), 
			      myVector->gethasVector_J(), 
			      myVector->gethasVector_K());
  /* need to get the part location in order to update the mySQL database */
  getPartLocation( located_part, located_frame );

  return;
}

/*!
  @brief A canonical robot command for the PDDL action <b>look-for-slot</b>
  @param paramList List of parameters for the action <b>look-for-slot</b>
  @return true - found slot, false - could not find slot
  (example: <b>look-for-slot</b> robot_1 part_c_1 kit_1 Work_table_1)
*/
bool CanonicalRobotCommand::look_for_slot(vector<string> paramList, 
					  KittingPlan *kittingplan, PDDLPhase phase)
{
  int listLength;
  Kit *kit;
  string partName;
  string kitName;
  string skuName;
  vector<Slot*> slots;
  Part *part;
  StockKeepingUnit *sku;
  SkuObject *skuObject = new SkuObject("foo");

  ShapeDesign *shapeDesign;
  PoseLocation *graspPose;
  Point *point;
  Vector *myVector;

  if (phase == EFFECT)
    return true;
  listLength=(int)paramList.size();

  for (vector<string>::size_type i = 0; i < listLength; i++)
    {
      string type;
      type=kittingplan->matchParamType(paramList[i]);
      m_file_operator->stripSpace(type);
    
      if (!strcmp(type.c_str(),"Part"))
	{
	  partName = paramList[i];
	  part = new Part(partName);
	  part->get(partName);
	  skuObject->get(part->getname());
	  sku = skuObject->gethasSkuObject_Sku();
	  skuName = sku->getname();
	  /*
	    printf( "Looking for slot for part %s with sku: %s\n", 
	    partName.c_str(),
	    skuName.c_str());
	  */
	}
      else if (!strcmp(type.c_str(),"Kit"))
	{
	  //	printf( "Looking for slot in kit %s\n", paramList[i].c_str() );
	  kitName = paramList[i];
	}
    }

  /* get slots from kit */
  kit = new Kit(kitName);
  kit->get(kitName);
  slots = kit->gethadBySlot_Kit();
  for (int i=0; i<slots.size(); i++ )
    {
      kit = slots[i]->gethadBySlot_Kit();
      if( DatabaseUpdate::matchSlot(slots[i], kitName, skuName) == true )
	{
	  located_slot = slots[i]->getname();
	  return true;
	}
    }
  printf( "Could not find slot for part %s with SKU %s\n", partName.c_str(), 
	  skuName.c_str() );
  return false;
}


/*!
  @brief A canonical robot command for the PDDL action <b>put-kit</b>
  @param paramList List of parameters for the action <b>put-kit</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>put-kit</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::put_kit(vector<string> paramList, PDDLPhase phase)
{
  //cout <<endl;
  //cout <<"Message (\"put kit\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>put-kit-tray</b>
  @param paramList List of parameters for the action <b>put-kit-tray</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>put-kit-tray</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::put_kit_tray(vector<string> paramList, PDDLPhase phase)
{
  //cout <<endl;
  //cout <<"Message (\"put kit tray\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>put-part</b>
  @param paramList List of parameters for the action <b>put-part</b>
  (example: <b>put-part</b> robot_1 part_c_1 kit_1 Work_table_1)
  @param kittingplan Instance of KittingPlan
*/
void CanonicalRobotCommand::put_part(vector<string> paramList, 
				     KittingPlan *kittingplan,
				     PDDLPhase phase)
{
  int listLength;
  //  stringstream ss;//create a stringstream
  string type;//, partName;
  Robot* robot = NULL;
  SolidObject* solidObject = NULL;
  EndEffector* endEffector = NULL;
  Slot* slot = new Slot(located_slot);

  RecLoc recLoc;

  listLength=(int)paramList.size();  

  for (vector<string>::size_type i = 0; i < listLength; i++)
    {
      type=kittingplan->matchParamType(paramList[i]);
      FileOperator::stripSpace(type);
      if (!strcmp(type.c_str(),"Robot"))
	{
	  robot = new Robot(paramList[i]);
	  robot->get(paramList[i]);
	}
      /*
	else if (!strcmp(type.c_str(),"Part"))
	partName = paramList[i];
      */
    }
  /* compute the part being held */
  // get the end effector
  endEffector = robot->gethadByEndEffector_Robot();
  endEffector->get(endEffector->getname());
  // get what is being held
  solidObject = endEffector->gethasEndEffector_HeldObject();
  if (phase == ACTION)
    {
      // get the slot
      slot->get(located_slot);

      recLoc=getPartGoalLocation(solidObject->getname(), slot->getname());
      canon_put_part(recLoc.frame.pose.getPoint(), recLoc.frame.pose.getXAxis(), 
		     recLoc.frame.pose.getZAxis());
    }
  else if (phase == EFFECT)
    {
      effect_put_part( robot->getname(), located_slot, solidObject->getname() );

      // clean up
      located_slot = "";
    }
  if( robot != NULL )
    delete robot;
}

/*!
  @brief A canonical robot command for the PDDL action <b>remove-eff</b>
  @param paramList List of parameters for the action <b>remove-eff</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>remove-eff</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::remove_eff(vector<string> paramList, PDDLPhase phase)
{
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-kit</b>
  @param paramList List of parameters for the action <b>take-kit</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-kit</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::take_kit(vector<string> paramList, PDDLPhase phase)
{
  //cout <<endl;
  //cout <<"Message (\"take kit\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-kit-tray</b>
  @param paramList List of parameters for the action <b>take-kit-tray</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-kit-tray</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::take_kit_tray(vector<string> paramList, PDDLPhase phase)
{
  //cout <<endl;
  //cout <<"Message (\"take kit tray\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-part</b>
  @param paramList List of parameters for the action <b>take-part</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-part</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::take_part(vector<string> paramList, 
				      KittingPlan *kittingplan,
				      PDDLPhase phase)
{
  int listLength;
  listLength=(int)paramList.size();
  stringstream ss;//create a stringstream
  RecLoc recLoc;
  string partName, robotName;

  for (vector<string>::size_type i = 0; i < listLength; i++)
    {
      string type;
      type=kittingplan->matchParamType(paramList[i]);
      m_file_operator->stripSpace(type);

      if (!strcmp(type.c_str(),"Part"))
	partName = paramList[i];
      else if (!strcmp(type.c_str(),"Robot"))
	robotName = paramList[i];
    }
  if (phase == ACTION)
    {
      ss << partName;//add number to the stream
      string s_paramlist = ss.str();
      processCRCL( "Message (\"take part " + s_paramlist +"\")\n" );
      //  m_file_operator->writeData(message);

      // cout <<"Message (\"take part " << paramList[i] <<"\")"<< endl;
      if( located_part == "" )
	{
	  printf( "did not call look_for_part before take_part!\n");
	  located_part = partName;
	}
      recLoc = getPartLocation( located_part, located_frame );
			
      canon_take_part(recLoc.frame.pose.getPoint(), recLoc.frame.pose.getXAxis(), 
		      recLoc.frame.pose.getZAxis());
    }
  else if (phase == EFFECT)
    {
      effect_take_part( robotName, located_part, located_frame );
      // part is now taken, so clear located part
      located_part = "";
    }
  return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
  @brief Compile a set of <b>Canonical Robot Commands</b> to perform the PDDL action <b>put-part</b>
  @param xyz Vector that contains the coordinates of the part in the kit
  @param z_axis Z axis used by the robot to put the part in the kit
  @param x_axis X axis used by the robot to put the part in the kit
*/
void CanonicalRobotCommand::canon_put_part(vector<double> xyz, 
					   vector<double> x_axis, 
					   vector<double> z_axis){

  double part_point_x = xyz.at(0);
  double part_point_y = xyz.at(1);
  double part_point_z = xyz.at(2);

  //  commandsCRCL.clear();
  print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
  print_dwell(m_dwell);
  print_moveto(part_point_x, part_point_y, part_point_z, x_axis, z_axis);
  print_dwell(m_dwell);
  print_opengripper();
  print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
  // wait for command to finish
}

/*!
  @brief Generate the canonical robot commands for the PDDL action <b>take-part</b>
  @param xyz Vector that contains the coordinates of the part in the parts tray
  @param z_axis Z axis used by the robot to take the part from the parts tray
  @param x_axis X axis used by the robot to take the part from the parts tray
*/
void CanonicalRobotCommand::canon_take_part(vector<double> xyz, 
					    vector<double> x_axis, 
					    vector<double> z_axis)
{

  double part_point_x = xyz.at(0);
  double part_point_y = xyz.at(1);
  double part_point_z = xyz.at(2);

  //  commandsCRCL.clear();
  print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
  print_dwell(m_dwell);
  print_moveto(part_point_x, part_point_y, part_point_z, x_axis, z_axis);
  print_closegripper();
  print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
  print_dwell(m_dwell);
}

/////////////////////////////////////////////////////////////////////////////////////////
void CanonicalRobotCommand::effect_put_part( string robotName, string slotName, string partName){
  Slot* slot = new Slot(slotName);
  Part* part = new Part(partName);

  slot->get(slotName);
  part->get(partName);

  /*
  Frame frame;
  PartRefAndPose* partRefAndPose;
  Point* mypoint;
  Vector* vector;
  Kit* kit;

  partRefAndPose = slot->gethasSlot_PartRefAndPose();
  partRefAndPose->get(partRefAndPose->getname());
  mypoint = partRefAndPose->gethasPartRefAndPose_Point();
  mypoint->get(mypoint->getname());
  frame.pose.setPointName(mypoint->getname());
  frame.pose.setPoint( mypoint->gethasPoint_X(),
		  mypoint->gethasPoint_Y(),
		  mypoint->gethasPoint_Z());

  vector = partRefAndPose->gethasPartRefAndPose_XAxis();
  vector->get(vector->getname());
  frame.pose.setXAxisName(vector->getname());
  frame.pose.setXAxis(vector->gethasVector_I(),
		 vector->gethasVector_J(),
		 vector->gethasVector_K());

  vector = partRefAndPose->gethasPartRefAndPose_ZAxis();
  vector->get(vector->getname());
  frame.pose.setZAxisName(vector->getname());
  frame.pose.setZAxis(vector->gethasVector_I(),
		 vector->gethasVector_J(),
		 vector->gethasVector_K());
  kit = slot->gethadBySlot_Kit();  
  */

  // release part in database
  DatabaseUpdate::releaseByRobot( robotName, partName, slotName );

  // put part in slot
  slot->sethasSlot_Part(part);
  slot->set(slot->getname());
  //   delete slot; causes dump
    delete part;
}

/*!
  @brief Modifies database to reflect that part has been taken
  Items modified:
  <ul>
  <li> Set the parts "hadByPart_PartsTrayWithParts" field to be empty
  </ul>
  @param part Part that is being taken
*/
void CanonicalRobotCommand::effect_take_part(string robotName, string partName,
					     Frame graspFrame){
  Part *part = new Part(partName);

  // temporarilly set part supply to part_b_supply_ir
  //  PartsTrayWithParts *parttray = new PartsTrayWithParts("part_b_supply_ir");
  //  parttray->get("part_b_supply_ir");
  
  part->get(partName);
  part->sethadByPart_PartsVessel(NULL);
  part->set(part->getname());
  DatabaseUpdate::graspByRobot( robotName, part->getname(), graspFrame);
}

/////////////////////////////////////////////////////////////////////////////////////////
int CanonicalRobotCommand::precondition_put_part(){
  return 1;
}
int CanonicalRobotCommand::precondition_take_part(){
  return 1;
}

/*!
  @brief Step 1 of interpretPlan

  The three routines of initializePlan, stepPlan, and finalizePlan
  take the place of the interpretPlan routine. This allow us to
  step through the plan one PDDL action at a time and interact with
  the robot.

  This routine justs opens the file and sends out basic initialization
  commands.

  @param kittingplan Instance of KittingPlan
*/
void CanonicalRobotCommand::initializePlan(KittingPlan *kittingplan)
{
  if( m_file_operator != NULL )
    m_file_operator->createOutputFile();

  printf( "CanonicalRobotCommand::initializePlan called\n" );
  print_initcannon();
  print_opengripper();
}

/*
  decompose a single step of the plan
  @return 1 on success, 0 on failure
*/
int CanonicalRobotCommand::stepPlan(KittingPlan *kittingplan, PDDLPhase phase)
{
  string action(""), actionName("");
  vector<string> paramName;

  if( kittingplan->m_actionParamList.size() < 1 )
    return 0;

  actionName=kittingplan->m_actionParamList[0][0];
  printf( "CanonicalRobotCommand::stepPlan: %s is next PDDL action to execute in phase %d\n", 
	  actionName.c_str(), phase );
  //  if( phase == ACTION )
  for (vector<string>::size_type v = 1; 
       v < kittingplan->m_actionParamList[0].size(); v++) 
    {
      paramName.push_back(kittingplan->m_actionParamList[0][v]);
    }
  if( phase == ACTION || phase == EFFECT )
    {
      actionInterpreter(actionName, paramName, kittingplan, phase);
      if( phase == EFFECT )
	kittingplan->m_actionParamList.erase(kittingplan->m_actionParamList.begin());
    }
  else
    printf( "CanonicalRobotCommand::stepPlan: unknown phase\n");
}

void CanonicalRobotCommand::finalizePlan(KittingPlan *kittingplan)
{
  print_endcannon(2); 
}

/*!
  @brief Read the plan stored in KittingPlan::m_actionParamList and interpret each action
  The different steps are:
  <ul>
  <li> Create the output file that will contain the canonical robot commands
  <li> Write the command InitCanon () in the output file
  <li> Write the command OpenGripper () in the output file
  <li> Retrieve each action and their parameters from KittingPlan::m_actionParamList and call the appropriate functions to print the robot commands in the output file
  <li> Write the command EndCanon () in the output file
  </ul>
  @param kittingplan Instance of KittingPlan
*/
void CanonicalRobotCommand::interpretPlan(KittingPlan *kittingplan)
{
  string action(""), actionName("");
  vector<string> paramName;

  if( m_file_operator != NULL )
    m_file_operator->createOutputFile();

  print_initcannon();
  print_opengripper();

  for (vector< vector<string> >::size_type u = 0; 
       u < kittingplan->m_actionParamList.size(); u++) 
    {
      actionName=kittingplan->m_actionParamList[u][0];
      for (vector<string>::size_type v = 1; 
	   v < kittingplan->m_actionParamList[u].size(); v++) 
	{
	  paramName.push_back(kittingplan->m_actionParamList[u][v]);
	}
      actionInterpreter(actionName, paramName, kittingplan, ACTION);
      actionInterpreter(actionName, paramName, kittingplan, EFFECT);
      // this is where we should execute actions and check for results
      // did action work?
      paramName.clear();
    }
  print_endcannon(2); 
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-kit</b>
  @param paramList List of parameters for the action <b>take-kit</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-kit</b> is implemented in ROS/USARSim
*/
void CanonicalRobotCommand::sql_put_part(string partName, string goalRefObject){
  //cout <<endl;
  //cout <<"Message (\"take kit\")"<< endl;
}


/*!
  @brief Retrieve the location of the kit tray @a kit_tray_name
  @param kit_tray_name Name of the kit tray
  @return KitTrayLocStruct Pose (@a Point), the Z axis (@a Vector), and the X axis (@a Vector) of the kit tray @a kit_tray_name

  -# Query the field @aasSolidObject_PrimaryLocation from the table @a PoseLocation to retrieve the pose location for the kit tray
  -# Query the field @a hasPoseLocation_Point from the table @a PoseLocation to retrieve the name of the point for the kit tray
  - Query the table @a Point to retrieve the coordinates of the parts tray
  -# Query the field @a hasPoseLocation_XAxis from the table @a PoseLocation to retrieve the name of the X axis for the kit tray
  - Query the table @a Vector to retrieve the vector for the X axis
  -# Query the field @a hasPoseLocation_ZAxis from the table @a PoseLocation to retrieve the name of the Z axis for the kit tray
  - Query the table @a Vector to retrieve the vector for the Z axis
*/
KitTrayLocStruct CanonicalRobotCommand::getKitTrayLocation(string kit_tray_name){

  KitTrayLocStruct kit_tray_loc_struct;

  KitTray* kit_tray = new KitTray(kit_tray_name);
  kit_tray->get(kit_tray_name);

  PoseLocation* kit_tray_pose = new PoseLocation(kit_tray->gethasSolidObject_PrimaryLocation()->getname());
  kit_tray_pose->get(kit_tray_pose->getname());

  //--Retrieve hasPoseLocation_Point
  Point * kit_tray_point = kit_tray_pose->gethasPoseLocation_Point();
  //--Retrieve hasPoseLocation_XAxis
  Vector * kit_tray_x_axis  = kit_tray_pose->gethasPoseLocation_XAxis();
  //--Retrieve hasPoseLocation_ZAxis
  Vector * kit_tray_z_axis  = kit_tray_pose->gethasPoseLocation_ZAxis();

  kit_tray_loc_struct.point=kit_tray_point;
  kit_tray_loc_struct.x_axis=kit_tray_x_axis;
  kit_tray_loc_struct.z_axis=kit_tray_z_axis;

  return kit_tray_loc_struct;
}

/*!
  @brief Retrieve the location of the parts tray @a part_tray_name
  @param part_tray_name Name of the parts tray
  @return PartsTrayLocStruct Pose (@a Point), the Z axis (@a Vector), and the X axis (@a Vector) of the parts tray @a part_tray_name

  -# Query the field @a hasPoseLocation_Point from the table @a PoseLocation to retrieve the name of the point for the parts tray
  - Query the table @a Point to retrieve the coordinates of the parts tray
  -# Query the field @a hasPoseLocation_XAxis from the table @a PoseLocation to retrieve the name of the X axis for the parts tray
  - Query the table @a Vector to retrieve the vector for the X axis
  -# Query the field @a hasPoseLocation_ZAxis from the table @a PoseLocation to retrieve the name of the Z axis for the parts tray
  - Query the table @a Vector to retrieve the vector for the Z axis
*/
PartsTrayLocStruct CanonicalRobotCommand::getPartsTrayLocation(string part_tray_name){

  PartsTrayLocStruct parts_tray_loc_struct;

  PartsTray* part_tray = new PartsTray(part_tray_name);
  part_tray->get(part_tray_name);

  //part_tray->gethasSolidObject_PrimaryLocation()->get("part_b_tray_pose");
  PoseLocation* part_tray_pose = new PoseLocation(part_tray->gethasSolidObject_PrimaryLocation()->getname());
  part_tray_pose->get(part_tray_pose->getname());

  //--Retrieve hasPoseLocation_Point
  Point * part_tray_point = part_tray_pose->gethasPoseLocation_Point();
  //--Retrieve hasPoseLocation_XAxis
  Vector * part_tray_x_axis  = part_tray_pose->gethasPoseLocation_XAxis();
  //--Retrieve hasPoseLocation_ZAxis
  Vector * part_tray_z_axis  = part_tray_pose->gethasPoseLocation_ZAxis();

  parts_tray_loc_struct.point=part_tray_point;
  parts_tray_loc_struct.x_axis=part_tray_x_axis;
  parts_tray_loc_struct.z_axis=part_tray_z_axis;

  return parts_tray_loc_struct;
}

/*!
  @brief Retrieve the location of the part @a part_name
  This routine will return the grasp point of the given part.
  @param partName Name of the part
  @param grasp_frame The grasp frame that has been decided to be optimal for this particular part
  @return RecLoc pointXYZ (@a vector), the Z axis (@a Vector), and the X axis (@a Vector) of the part @a part_name

  -# Query the field @a hasSolidObject_PrimaryLocation from the table @a SolidObject to retrieve the name of the pose for the part
  -# Query the field @a hasPoseLocation_Point from the table @a PoseLocation to retrieve the name of the point for the part
  - Query the table @a Point to retrieve the coordinates of the part
  -# Query the field @a hasPoseLocation_XAxis from the table @a PoseLocation to retrieve the name of the X axis for the part
  - Query the table @a Vector to retrieve the vector for the X axis
  -# Query the field @a hasPoseLocation_ZAxis from the table @a PoseLocation to retrieve the name of the Z axis for the part
  - Query the table @a Vector to retrieve the vector for the Z axis
*/
RecLoc CanonicalRobotCommand::getPartLocation(string part_name, Frame grasp_frame){
  double x,y,z;
  PartLocStruct partloc;
  RecLoc recLoc;
  Part *part = new Part(part_name);

  part->get(part_name);
  recurseLocation.clear();

  // add grasp to transform
  recLoc.frame = grasp_frame;
  recurseLocation.addRecLoc(&recLoc);
  recLoc.clear();

  /* now get location of part */
  recurseLocation.recurse(part);
  recurseLocation.computeGlobalLoc();
  //  recurseLocation.printMe(0);
  recLoc = recurseLocation.getGlobalLoc();

  //  delete part;
  return recLoc;
}

/*!
  @param part_name part to get instance of
  @return part instance or "" if no part found
 */
string CanonicalRobotCommand::getPartInstance(string part_name)
{
  std::map<std::string, std::vector<std::string> > results;
  std::vector<std::string> attributes;
  std::string myPartsVessel;
  PartsVessel *partsVessel = new PartsVessel("PartsVessel");
  bool found = false;

  double doubleValue;
  PartLocStruct partloc;
  Part *part = new Part(part_name);
  std::vector<Part*> availableParts;
  Point *point;
  PoseLocation *graspPose;
  ShapeDesign *shapeDesign;
  StockKeepingUnit *sku, *partsVessel_PartSku;
  SkuObject *skuObject = new SkuObject("foo");
  Vector *vector;
  DAO* mydao = new DAO("Part");
  //  RecLoc recLoc;

  part->get(part_name);

  /* find part vessel that contains this kind of part */
  // first get sku
  skuObject->get(part->getname());
  sku = skuObject->gethasSkuObject_Sku();
  sku->get(sku->getname());
  //  printf("Sku name: %s\n", sku->getname().c_str());
  // get the name of all PartsVessels
  attributes.push_back("_NAME");
  results = mydao->getAll(attributes, "PartsVessel");
  for(unsigned int i=0; (int) i<results["_NAME"].size();i++)
    {
      myPartsVessel = results["_NAME"][i];
      partsVessel->get(myPartsVessel);
      //      printf( "PartsVessel: %s\n", partsVessel->getname().c_str());
      // get the SKU of the parts in the vessel
      partsVessel_PartSku = partsVessel->gethasPartsVessel_PartSku();
      partsVessel_PartSku->get(partsVessel_PartSku->getname());
      if( sku->getname() == partsVessel_PartSku->getname() )
	{
	  // found the correct part tray
	  found = true;
	  printf( "found parts tray %s for parts of SKU %s\n", partsVessel->getname().c_str(), sku->getname().c_str() );
	  break;
	}
      //      else
      //	printf( "parts tray %s does not have %s as parts\n", partsTray_PartSku->getname().c_str(), sku->getname().c_str() );
    }
  if( !found )
    {
      printf( "could not find parts tray that matches\n" );
      return "";
    }
  
  // get vector of parts
  availableParts = partsVessel->gethadByPart_PartsVessel();
  printf( "found %d parts in tray. Specific part %s\n", 
	  (int)availableParts.size(),
	  availableParts.at(0)->getname().c_str());

  return availableParts.at(0)->getname();
}

/*!
  @Brief Compute the goal location to send the robot gripper to in world coordinates
  When the part that is being held by the robot is in its slot, the slot frame
  and the part frame will be coincident. This will allow for the transform of
  Gripper -> Part (really slot) -> kit -> table -> workcell
*/
RecLoc CanonicalRobotCommand::getPartGoalLocation(string part_name, string slot_location)
{
  SolidObject* solidObject = new SolidObject(part_name);
  PoseLocation *poseLocation = new PoseLocation("foo");
  PhysicalLocation *physicalLocation;
  PartRefAndPose *partRefAndPose;
  Kit* kit;
  Point *mypoint;
  Vector *vectorXAxis, *vectorZAxis;
  double doubleValue;
  Slot *slot;
  RecLoc recLoc;

  recurseLocation.clear();
  /* compute the inverse transform to get grasp (0,0,0) wrt part */
  solidObject->get(part_name);
  physicalLocation = solidObject->gethasSolidObject_PrimaryLocation();
  physicalLocation->get(physicalLocation->getname());

  poseLocation->get(physicalLocation->getname());
  mypoint = poseLocation->gethasPoseLocation_Point();
  mypoint->get(mypoint->getname());
  recLoc.frame.pose.setPointName(mypoint->getname());
  recLoc.frame.pose.setPoint( mypoint->gethasPoint_X(),
			 mypoint->gethasPoint_Y(),
			 mypoint->gethasPoint_Z());

  vectorXAxis = poseLocation->gethasPoseLocation_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  recLoc.frame.pose.setXAxisName(vectorXAxis->getname());
  recLoc.frame.pose.setXAxis(vectorXAxis->gethasVector_I(),
			vectorXAxis->gethasVector_J(),
			vectorXAxis->gethasVector_K());

  vectorZAxis = poseLocation->gethasPoseLocation_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  recLoc.frame.pose.setZAxisName(vectorZAxis->getname());
  recLoc.frame.pose.setZAxis(vectorZAxis->gethasVector_I(),
			vectorZAxis->gethasVector_J(),
			vectorZAxis->gethasVector_K());
  // invert frame
  recLoc.frame.pose = recLoc.frame.pose.invert();

  // add to transform
  recurseLocation.addRecLoc(&recLoc);

  /* since part and slot are same frame, we can now add the slot frame to kit transform
     to the transform chain */
  recLoc.clear();
  slot = new Slot(slot_location);
  slot->get(slot_location);
  partRefAndPose = slot->gethasSlot_PartRefAndPose();
  partRefAndPose->get(partRefAndPose->getname());
  mypoint = partRefAndPose->gethasPartRefAndPose_Point();
  mypoint->get(mypoint->getname());
  recLoc.frame.pose.setPointName(mypoint->getname());
  recLoc.frame.pose.setPoint( mypoint->gethasPoint_X(),
			 mypoint->gethasPoint_Y(),
			 mypoint->gethasPoint_Z());

  vectorXAxis = partRefAndPose->gethasPartRefAndPose_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  recLoc.frame.pose.setXAxisName(vectorXAxis->getname());
  recLoc.frame.pose.setXAxis(vectorXAxis->gethasVector_I(),
			vectorXAxis->gethasVector_J(),
			vectorXAxis->gethasVector_K());

  vectorZAxis = partRefAndPose->gethasPartRefAndPose_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  recLoc.frame.pose.setZAxisName(vectorZAxis->getname());
  recLoc.frame.pose.setZAxis(vectorZAxis->gethasVector_I(),
			vectorZAxis->gethasVector_J(),
			vectorZAxis->gethasVector_K());
  // add to transform
  recurseLocation.addRecLoc(&recLoc);

  /* now recurse on kit */ 
  kit = slot->gethadBySlot_Kit();
  kit->get(kit->getname());
  recurseLocation.recurse(kit);
  recurseLocation.computeGlobalLoc();
  /*
  printf("Slot location:\n");
  recurseLocation.printMe(0);
  */
  recLoc = recurseLocation.getGlobalLoc();

  delete solidObject;
  delete poseLocation;
  delete slot;
  return recLoc;
}

/*!
  @brief The <b>CloseGripper</b> command

  Close the gripper.
 */
void CanonicalRobotCommand::print_closegripper()
{
  processCRCL( "CloseGripper () \n" );
  //  m_file_operator->writeData(message);
}

/*!
  @brief The <b>Dwell</b> command
  @param time Stay motionless for the given amount of @a time in seconds
 */
void CanonicalRobotCommand::print_dwell(double time)
{
  stringstream ss;//create a stringstream

  ss << time;//add number to the stream
  string s_time = ss.str();
  processCRCL( "Dwell ("+ s_time +")\n" );
  //  m_file_operator->writeData(message);
}

/*!
  @brief The <b>EndCanon</b> command

  Do whatever is necessary to stop executing canonical robot
  commands. No specific action is required. The robot controller should
  not execute any canonical robot command except InitCanon after
  executing EndCanon and should signal an error if it is given one.
  This command will normally be given when execution of a plan is complete.
  It may also be given if the plan interpreter detects an error in the
  plan or is unable to proceed for any other reason. A value of 0 for
  reason indicates that execution of a plan has completed successfully.
  A positive value of reason indicates not.

  @param reason Reason used to indicate if the execution of a plan has been completed or not
 */
void CanonicalRobotCommand::print_endcannon(int reason){
  stringstream ss;//create a stringstream

  ss << reason;//add number to the stream
  string s_reason = ss.str();
  processCRCL( "EndCanon (" + s_reason + ") \n" );
  //  m_file_operator->writeData(message);
}

/*!
  @brief The <b>InitCanon</b> command

  Do whatever is necessary to get ready to move. Length and angle units
  are set to the default units. This command will normally be given when
  the plan interpreter opens a plan to be executed.
  Added first move to command to set robot arm in known location
*/
void CanonicalRobotCommand::print_initcannon(){
    processCRCL( "InitCanon () \n" );
  //  m_file_operator->writeData(message);
  //  message = "MoveTo({{0, 0, 0.5}, {0, 0, -1}, {1, 0, 0}})\n";
  //  m_file_operator->writeData(message);
}

/*!
  @brief The <b>MoveTo</b> command

  Move the controlled point along any convenient trajectory from the
  current pose to the given pose, and stop there.


  Before generating the <b>MoveTo</b> command, the two following steps are performed:
  <ul>
  <li>Retrieve the @a part_z_axis_i, @a part_z_axis_j, and @a part_z_axis_k components for the Z axis from @a z_axis
  <li>Retrieve the @a part_x_axis_i, @a part_x_axis_j, and @a part_x_axis_k components for the X axis from @a x_axis
  </ul>
  The structure of the <b>MoveTo</b> command is then built as follows:
  <ul>
  <li><b>MoveTo</b>({{@a part_point_x, @a part_point_y, @a part_point_z},{@a part_z_axis_i, @a part_z_axis_j, @a part_z_axis_k},{@a part_x_axis_i, @a part_x_axis_j, @a part_x_axis_k}}
  </ul>
  @param point_x The x location of the point
  @param point_y The y location of the point
  @param point_z The z location of the point
  @param x_axis vector containing the pointing direction of the forward axis (unit vector)
  @param z_axis vector containing the pointing direction of the up axis (unit vector)

*/
void CanonicalRobotCommand::print_moveto(double point_x, double point_y, 
					 double point_z, vector<double> x_axis,
					 vector<double> z_axis)
{
  stringstream ss;
  string s_part_point_x, s_part_point_y, s_part_point_z;
  string s_part_z_axis_i, s_part_z_axis_j, s_part_z_axis_k;
  string s_part_x_axis_i, s_part_x_axis_j, s_part_x_axis_k;

  ss << point_x;
  ss >> s_part_point_x;
  ss.str("");
  ss.clear();

  ss << point_y;
  ss >> s_part_point_y;
  ss.str("");
  ss.clear();

  ss << point_z;
  ss >> s_part_point_z;
  ss.str("");
  ss.clear();

  ss << z_axis.at(0);
  ss >> s_part_z_axis_i;
  ss.str("");
  ss.clear();

  ss << z_axis.at(1);
  ss >> s_part_z_axis_j;
  ss.str("");
  ss.clear();

  ss << z_axis.at(2);
  ss >> s_part_z_axis_k;
  ss.str("");
  ss.clear();

  ss << x_axis.at(0);
  ss >> s_part_x_axis_i;
  ss.str("");
  ss.clear();

  ss << x_axis.at(1);
  ss >> s_part_x_axis_j;
  ss.str("");
  ss.clear();

  ss << x_axis.at(2);
  ss >> s_part_x_axis_k;
  ss.str("");
  ss.clear();

  processCRCL( "MoveTo({{" + s_part_point_x +", " + 
	       s_part_point_y + ", " + s_part_point_z+"}, " +
	       "{" + s_part_z_axis_i + ", " + s_part_z_axis_j + 
	       ", " + s_part_z_axis_k +"}, " +
	       "{"+ s_part_x_axis_i +", " + s_part_x_axis_j + ", " + 
	       s_part_x_axis_k +"}})\n" );

  //  m_file_operator->writeData(message);
}

/*!
  @brief The <b>OpenGripper</b> command

  Open the gripper.
*/
void CanonicalRobotCommand::print_opengripper(){
    processCRCL( "OpenGripper () \n" );
  //  m_file_operator->writeData(message);
}

/*!
  @brief Deals with execution of command
  @param commandStr - String to process

  This will either send the command to the controller for execution
  or will write it out to file. The behavior is controlled with the
  m_file_operator class variable that is set at instance creationtime. 
  If m_file_operator != NULL, then the command is written to file.
*/
void CanonicalRobotCommand::processCRCL( string commandStr )
{
  if( m_file_operator != NULL )
    m_file_operator->writeData(commandStr);
  else
    cout << "CanonicalRobotCommand.cpp::processCRCL: " << commandStr;

  // need to push onto CRCL stack for this command
  commandsCRCL.push_back(commandStr);
}

std::string CanonicalRobotCommand::getNextCRCL()
{
  std::string retString;
  if( commandsCRCL.size() > 0 )
    {
      retString = commandsCRCL[0];
      commandsCRCL.erase(commandsCRCL.begin());
      return retString;
    }
  else
    return "";
}
