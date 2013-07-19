/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
 *********************************************
********************************/
#include "CanonicalRobotCommand.h"
#include "Tools.h"
#include "recurseLocation.h"
#include <iostream>
#include <algorithm>

/*!
  @brief Constructor
 */
CanonicalRobotCommand::CanonicalRobotCommand(FileOperator *fileoperator) {
	m_safe_z = -0.25;
	m_dwell = 0.05;
	m_file_operator = fileoperator;
}
/*!
  @brief Auto-generated destructor stub
 */
CanonicalRobotCommand::~CanonicalRobotCommand() {
}

/*!
  @brief Match each action found in the plan with a function

  @param action_name Action from the plan
  @param paramList List of parameters for the action @a action_name
  @param kittingplan Instance of KittingPlan
 */
void CanonicalRobotCommand::actionInterpreter(string action_name,
		vector<string> paramList,
		KittingPlan *kittingplan){

	if(action_name == "take-kittray")	take_kit_tray(paramList);
	if(action_name == "put-kit-tray") 	put_kit_tray(paramList);
	if(action_name == "take-kit") 		take_kit(paramList);
	if(action_name == "put-kittray") 		put_kit(paramList);
	if(action_name == "take-part") 		take_part(paramList, kittingplan);
	if(action_name == "put-part") 		put_part(paramList, kittingplan);
	if(action_name == "attach-endeffector") 		attach_eff(paramList, kittingplan);
	if(action_name == "remove-endeffector") 		remove_eff(paramList);
	if(action_name == "create-kit") 		create_kit(paramList, kittingplan);
}

/*!
  @brief A canonical robot command for the PDDL action <b>attach-eff</b>
  @param paramList List of parameters for the action <b>attach-eff</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>attach-eff</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::attach_eff(vector<string> paramList,KittingPlan *kittingplan){
}

/*!
  @brief Compile a set of <b>Canonical Robot Commands</b> to perform the PDDL action <b>put-part</b>
  @param xyz Vector that contains the coordinates of the part in the kit
  @param z_axis Z axis used by the robot to put the part in the kit
  @param x_axis X axis used by the robot to put the part in the kit
 */
void CanonicalRobotCommand::canon_put_part(vector<double> xyz, vector<double> x_axis, 
		vector<double> z_axis){

	double part_point_x = xyz.at(0);
	double part_point_y = xyz.at(1);
	double part_point_z = xyz.at(2);

	print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
	print_dwell(m_dwell);
	print_moveto(part_point_x, part_point_y, part_point_z, x_axis, z_axis);
	print_dwell(m_dwell);
	print_opengripper();
	print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
}

/*!
  @brief Generate the canonical robot commands for the PDDL action <b>take-part</b>
  @param xyz Vector that contains the coordinates of the part in the parts tray
  @param z_axis Z axis used by the robot to take the part from the parts tray
  @param x_axis X axis used by the robot to take the part from the parts tray
 */
void CanonicalRobotCommand::canon_take_part(vector<double> xyz, vector<double> x_axis, 
		vector<double> z_axis){

	double part_point_x = xyz.at(0);
	double part_point_y = xyz.at(1);
	double part_point_z = xyz.at(2);

	print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
	print_dwell(m_dwell);
	print_moveto(part_point_x, part_point_y, part_point_z, x_axis, z_axis);
	print_closegripper();
	print_moveto(part_point_x, part_point_y, m_safe_z, x_axis, z_axis);
	print_dwell(m_dwell);
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
void CanonicalRobotCommand::create_kit(vector<string> paramList, KittingPlan *kittingplan){
	//FileOperator *fileop = new FileOperator;
	int listLength;
	listLength=(int)paramList.size();

	for (vector<string>::size_type i = 0; i < listLength; i++){
		string type;
		type=kittingplan->matchParamType(paramList[i]);
		m_file_operator->stripSpace(type);

		if (!strcmp(type.c_str(),"Kit")){
			//cout <<"Message (\"create kit " << paramList[i] <<"\")"<< endl;
		}

		if (!strcmp(type.c_str(),"KitTray")){
			//cout <<"Message (\"kit tray " << paramList[i] <<"\")"<< endl;
			m_kit_tray=paramList[i];
		}
	}
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
void CanonicalRobotCommand::interpretPlan(KittingPlan *kittingplan){
	int nbAction=0;
	string action(""), actionName("");
	vector<string> paramName;
	//FileOperator *fileop = new FileOperator;
	m_file_operator->createOutputFile();

	print_initcannon();
	print_opengripper();

	for (vector< vector<string> >::size_type u = 0; u < kittingplan->m_actionParamList.size(); u++) {
		actionName=kittingplan->m_actionParamList[u][0];
		nbAction++;
		for (vector<string>::size_type v = 1; v < kittingplan->m_actionParamList[u].size(); v++) {
			paramName.push_back(kittingplan->m_actionParamList[u][v]);
		}
		actionInterpreter(actionName, paramName, kittingplan);
		paramName.clear();
	}
	print_endcannon(2);
}

/*!
  @brief A canonical robot command for the PDDL action <b>put-kit</b>
  @param paramList List of parameters for the action <b>put-kit</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>put-kit</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::put_kit(vector<string> paramList){
	//cout <<endl;
	//cout <<"Message (\"put kit\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>put-kit-tray</b>
  @param paramList List of parameters for the action <b>put-kit-tray</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>put-kit-tray</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::put_kit_tray(vector<string> paramList){
	//cout <<endl;
	//cout <<"Message (\"put kit tray\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>put-part</b>
  @param paramList List of parameters for the action <b>put-part</b>
  (example: <b>put-part</b> robot_1 part_c_1 kit_1 Work_table_1)
  @param kittingplan Instance of KittingPlan
 */
void CanonicalRobotCommand::put_part(vector<string> paramList, KittingPlan *kittingplan){
  FileOperator *fileop = new FileOperator;
  int listLength;
  stringstream ss;//create a stringstream
  RecLoc recLoc;
  KitTrayLocStruct kit_tray_loc_struct;
  string locationPrefix = "part_ref_and_pose_";
  string partName;
  string type;
  Part* part = NULL;
  Kit* kit = NULL;
  KitDesign* kitDesign  = NULL;
  KitTray* kitTray = NULL;

  listLength=(int)paramList.size();  

  /* debug
  printf( "CanonicalRobotCommand debug for list of lenght %d\n", listLength );
  for (vector<string>::size_type i = 0; i < listLength; i++){
    type=kittingplan->matchParamType(paramList[i]);
    fileop->stripSpace(type);
    printf( "\tparam %d is of type %s and value %s\n", (int)i, 
	    type.c_str(), paramList[i].c_str() );
  }
  printf( "End of debug\n\n" );
  //end debug */

  for (vector<string>::size_type i = 0; i < listLength; i++){
    type=kittingplan->matchParamType(paramList[i]);
    fileop->stripSpace(type);

    if (!strcmp(type.c_str(),"Part"))
      {
	part = new Part (paramList[i]);
	part->get(paramList[i]);
	printf( "Part retrieved\n" );
	part->get(paramList[i]);
      }
    else if (!strcmp(type.c_str(),"Kit"))
      {
	kit = new Kit (paramList[i]);
	kit->get(paramList[i]);
	kitDesign = kit->gethasKit_Design();
	if( kitDesign == NULL )
	  {
	    printf( "Error from CanonicalRobotCommand on kit creation of kit (bad design) %s\n", paramList[i].c_str());
	    exit(1);
	  }
	kitTray = kit->gethasKit_Tray();
	if( kitTray == NULL )
	  {
	    printf( "Error from CanonicalRobotCommand on kit creation of kit (bad tray) %s\n", paramList[i].c_str());
	    exit(1);
	  }

      }
  }
  
  //  printf( "KitDesign: %s part: %s locationPrefix: %s\n", 
  // kitDesign->getname().c_str(), part->getname().c_str(), 
  // locationPrefix.c_str());

  partName = locationPrefix + kitDesign->getname().erase(4,7);
  unsigned found = partName.find_last_of("_");
  
  partName = partName.substr(0,found) + "_" + part->getname().erase(0,5);
  //  printf( "Getting location of part %s\n", partName.c_str() );
  recLoc=getPartGoalLocation(partName, kitTray->getname());
  canon_put_part(recLoc.pointXYZ, recLoc.xAxis, recLoc.zAxis);
  //  sql_put_part(partName, kitTray.getname());
  /*

  cout <<"Message (\"put part " << paramList[i] <<"\")"<< endl;
  ss << paramList[i];//add number to the stream
  string s_paramlist = ss.str();
  string message = "\nMessage (\"put part " + s_paramlist +"\")\n";
  fileop->writeData(message);

  */
  if( part != NULL )
    delete part;
  if( kit != NULL )
    delete kit;
  /*
    cannot delete this, why???
  if( kitDesign != NULL )
    delete kitDesign;
  if( kitTray != NULL )
    delete kitTray;
  */
}

/*!
  @brief A canonical robot command for the PDDL action <b>remove-eff</b>
  @param paramList List of parameters for the action <b>remove-eff</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>remove-eff</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::remove_eff(vector<string> paramList){
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
  @brief A canonical robot command for the PDDL action <b>take-kit</b>
  @param paramList List of parameters for the action <b>take-kit</b>
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-kit</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::take_kit(vector<string> paramList){
	//cout <<endl;
	//cout <<"Message (\"take kit\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-kit-tray</b>
  @param paramList List of parameters for the action <b>take-kit-tray</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-kit-tray</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::take_kit_tray(vector<string> paramList){
	//cout <<endl;
	//cout <<"Message (\"take kit tray\")"<< endl;
}

/*!
  @brief A canonical robot command for the PDDL action <b>take-part</b>
  @param paramList List of parameters for the action <b>take-part</b>
  @param kittingplan Instance of KittingPlan
  @todo This function will be written once the <b>Canonical Robot Command</b> for the action <b>take-part</b> is implemented in ROS/USARSim
 */
void CanonicalRobotCommand::take_part(vector<string> paramList, KittingPlan *kittingplan){
	//FileOperator *fileop = new FileOperator;
	int listLength;
	listLength=(int)paramList.size();
	stringstream ss;//create a stringstream
	RecLoc recLoc;

	for (vector<string>::size_type i = 0; i < listLength; i++){
		string type;
		type=kittingplan->matchParamType(paramList[i]);
		m_file_operator->stripSpace(type);

		if (!strcmp(type.c_str(),"Part")){
			ss << paramList[i];//add number to the stream
			string s_paramlist = ss.str();
			string message = "\nMessage (\"take part " + s_paramlist +"\")\n";
			m_file_operator->writeData(message);

			//			cout <<"Message (\"take part " << paramList[i] <<"\")"<< endl;
			recLoc=getPartLocation(paramList[i]);
			canon_take_part(recLoc.pointXYZ, recLoc.xAxis, recLoc.zAxis);
		}
	}
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
  @param partName Name of the part
  @return RecLoc pointXYZ (@a vector), the Z axis (@a Vector), and the X axis (@a Vector) of the part @a part_name

  -# Query the field @a hasSolidObject_PrimaryLocation from the table @a SolidObject to retrieve the name of the pose for the part
  -# Query the field @a hasPoseLocation_Point from the table @a PoseLocation to retrieve the name of the point for the part
  - Query the table @a Point to retrieve the coordinates of the part
  -# Query the field @a hasPoseLocation_XAxis from the table @a PoseLocation to retrieve the name of the X axis for the part
  - Query the table @a Vector to retrieve the vector for the X axis
  -# Query the field @a hasPoseLocation_ZAxis from the table @a PoseLocation to retrieve the name of the Z axis for the part
  - Query the table @a Vector to retrieve the vector for the Z axis
 */
RecLoc CanonicalRobotCommand::getPartLocation(string part_name){

	PartLocStruct partloc;
	RecurseLocation recurseLocation;
	RecLoc recLoc;


	Part *part = new Part(part_name);
	part->get(part_name);
	recurseLocation.clear();
	recurseLocation.recurse(part);
	recurseLocation.computeGlobalLoc();
	recurseLocation.printMe(0);
	recLoc = recurseLocation.getGlobalLoc();

	//  delete part;
	return recLoc;
}

RecLoc CanonicalRobotCommand::getPartGoalLocation(string part_name, 
		string kit_name){

	RecurseLocation recurseLocation;
	RecLoc recLoc;
	KitTray *kitTray = new KitTray(kit_name);
	PartRefAndPose *partRefAndPose = new PartRefAndPose(part_name);
	Point *mypoint;
	Vector *myvector;
	double doubleValue;

	kitTray->get(kit_name);
	recurseLocation.clear();
	recLoc.clear();
	partRefAndPose->get(part_name);
	mypoint = partRefAndPose->gethasPartRefAndPose_Point();
	printf( "Got it! Now getting point.\n" );
	mypoint->get(mypoint->getname());
	recLoc.posePointName = mypoint->getname();
	doubleValue = mypoint->gethasPoint_X();
	recLoc.pointXYZ.push_back(doubleValue);
	doubleValue = mypoint->gethasPoint_Y();
	recLoc.pointXYZ.push_back(doubleValue);
	doubleValue = mypoint->gethasPoint_Z();
	recLoc.pointXYZ.push_back(doubleValue);

	myvector = partRefAndPose->gethasPartRefAndPose_XAxis();
	myvector->get(myvector->getname());
	doubleValue = myvector->gethasVector_I();
	recLoc.xAxis.push_back(doubleValue);
	doubleValue = myvector->gethasVector_J();
	recLoc.xAxis.push_back(doubleValue);
	doubleValue = myvector->gethasVector_K();
	recLoc.xAxis.push_back(doubleValue);
	recLoc.xAxisName = myvector->getname();

	myvector = partRefAndPose->gethasPartRefAndPose_ZAxis();
	myvector->get(myvector->getname());
	doubleValue = myvector->gethasVector_I();
	recLoc.zAxis.push_back(doubleValue);
	doubleValue = myvector->gethasVector_J();
	recLoc.zAxis.push_back(doubleValue);
	doubleValue = myvector->gethasVector_K();
	recLoc.zAxis.push_back(doubleValue);
	recLoc.zAxisName = myvector->getname();

	recurseLocation.addRecLoc(&recLoc);
	recLoc.clear();

	recurseLocation.recurse(kitTray);
	recurseLocation.computeGlobalLoc();
	recurseLocation.printMe(0);
	recLoc = recurseLocation.getGlobalLoc();

	recurseLocation.clear();

	//  delete kitTray;
	//  delete partRefAndPose;
	return recLoc;
}

/*!
  @brief The <b>CloseGripper</b> command

  Close the gripper.
 */
void CanonicalRobotCommand::print_closegripper(){
	//FileOperator *fileop = new FileOperator;
	string message = "CloseGripper () \n";
	m_file_operator->writeData(message);
	//cout << message;
}

/*!
  @brief The <b>Dwell</b> command
  @param time Stay motionless for the given amount of @a time in seconds
 */
void CanonicalRobotCommand::print_dwell(double time){
	//FileOperator *fileop = new FileOperator;
	stringstream ss;//create a stringstream

	ss << time;//add number to the stream
	string s_time = ss.str();
	string message = "Dwell ("+ s_time +")\n";
	m_file_operator->writeData(message);
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
	//FileOperator *fileop = new FileOperator;
	stringstream ss;//create a stringstream

	ss << reason;//add number to the stream
	string s_reason = ss.str();
	string message = "EndCanon (" + s_reason + ") \n";
	m_file_operator->writeData(message);
}

/*!
  @brief The <b>InitCanon</b> command

  Do whatever is necessary to get ready to move. Length and angle units
  are set to the default units. This command will normally be given when
  the plan interpreter opens a plan to be executed.
  Added first move to command to set robot arm in known location
 */
void CanonicalRobotCommand::print_initcannon(){
	//FileOperator *fileop = new FileOperator;
	string message = "InitCanon () \n";
	m_file_operator->writeData(message);
	message = "MoveTo({{.31, 1.24, -0.67}, {0, 0, 1}, {1, 0, 0}})\n";
	m_file_operator->writeData(message);
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
void CanonicalRobotCommand::print_moveto(double point_x, double point_y, double point_z, 
		vector<double> x_axis, vector<double> z_axis){

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

	string message = "MoveTo({{" + s_part_point_x +", " + s_part_point_y + ", " + s_part_point_z+"}, " +
			"{" + s_part_z_axis_i + ", " + s_part_z_axis_j + ", " + s_part_z_axis_k +"}, " +
			"{"+ s_part_x_axis_i +", " + s_part_x_axis_j + ", " + s_part_x_axis_k +"}})\n";

	m_file_operator->writeData(message);
}

/*!
  @brief The <b>OpenGripper</b> command

  Open the gripper.
 */
void CanonicalRobotCommand::print_opengripper(){
	//FileOperator *fileop = new FileOperator;
	string message = "OpenGripper () \n";
	m_file_operator->writeData(message);
}



