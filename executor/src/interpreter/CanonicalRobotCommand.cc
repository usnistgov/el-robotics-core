/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
*****************************************************************************/
#include "CanonicalRobotCommand.h"
#include "../interpreter/database.h"
#include "Tools.h"

#include <iostream>
#include <algorithm>

/*!
@brief Auto-generated constructor stub
*/
CanonicalRobotCommand::CanonicalRobotCommand() {
}
/*!
@brief Auto-generated destructor stub
*/
CanonicalRobotCommand::~CanonicalRobotCommand() {
}



void CanonicalRobotCommand::take_kit_tray(vector<string> paramList){
	cout <<endl;
	cout <<"take-kit-tray"<< " ";
}

void CanonicalRobotCommand::put_kit_tray(vector<string> paramList){
	cout <<endl;
	cout <<"put-kit-tray"<< " ";
}

void CanonicalRobotCommand::take_kit(vector<string> paramList){
	cout <<endl;
	cout <<"take-kit"<< " ";
}

void CanonicalRobotCommand::put_kit(vector<string> paramList){
	cout <<endl;
	cout <<"put-kit"<< " ";
}

void CanonicalRobotCommand::take_part(vector<string> paramList){
	cout <<endl;
	cout <<"take-part"<< " ";
}

void CanonicalRobotCommand::put_part(vector<string> paramList){
	cout <<endl;
	cout <<"put-part"<< " ";
}

void CanonicalRobotCommand::attach_eff(vector<string> paramList,KittingPlan *kittingplan){
	cout <<endl;
	cout<< "-- attach-eff -- "<< endl;
	FileOperator *fileop = new FileOperator;
	int listLength;
	listLength=(int)paramList.size();

	for (vector<string>::size_type i = 0; i < listLength; i++){
		string type;
		type=kittingplan->matchParamType(paramList[i]);

		fileop->stripSpace(type);
		//cout <<type << endl;
		//type.erase(remove_if(type.begin(), type.end(), isspace), type.end());

		if (!strcmp(type.c_str(),"Robot"))
		{
			cout << type << endl;

			Robot * r = new Robot(paramList[i]);
			r->get(paramList[i]);
			cout << r->gethasRobot_Description()<<endl;
			cout << r->gethasRobot_Id() << endl;
		}

		if (!strcmp(type.c_str(),"VacuumEffectorSingleCup"))
		{
			cout << type << endl;
			cout<< paramList[i] << endl;
			VacuumEffectorSingleCup * r = new VacuumEffectorSingleCup(paramList[i]);
			r->get(paramList[i]);
			cout << r->getVacuumEffectorSingleCupID()<<endl;
		}

		if (!strcmp(type.c_str(),"EndEffectorHolder"))
		{
			cout << type << endl;
			cout<< paramList[i] << endl;
			EndEffectorHolder * r = new EndEffectorHolder(paramList[i]);
			r->get(paramList[i]);
			EndEffectorChangingStation* ech = r->gethadByEndEffectorHolder_ChangingStation();
			ech->get(ech->getname());
			cout << r->gethadByEndEffectorHolder_ChangingStation()->getEndEffectorChangingStationID() << endl;
		}

	}

	//VacuumEffectorSingleCup * gripper = new VacuumEffectorSingleCup("tray_gripper");
	//cout << gripper->getVacuumEffectorSingleCupID()<<endl;

}

void CanonicalRobotCommand::remove_eff(vector<string> paramList){
	cout <<endl;
	cout <<"remove-eff"<< " ";
}

void CanonicalRobotCommand::create_kit(vector<string> paramList){
	cout <<endl;
	cout <<"create-kit"<< " ";
}


/*!
@brief Reads a line of the plan and interprets it into one or more canonical robot commands.

@param action Action to be interpreted
@return A list of commands associated to the action @a action

*/
void CanonicalRobotCommand::actionInterpreter(string actionName,
		vector<string> paramList,
		KittingPlan *kittingplan){
	FileOperator *fileop = new FileOperator;

	//cout << actionName << endl;
	//fileop->readVector(paramList);

	if(actionName == "take-kit-tray")	take_kit_tray(paramList);
	if(actionName == "put-kit-tray") 	put_kit_tray(paramList);
	if(actionName == "take-kit") 		take_kit(paramList);
	if(actionName == "put-kit") 		put_kit(paramList);
	if(actionName == "take-part") 		take_part(paramList);
	if(actionName == "put-part") 		put_part(paramList);
	if(actionName == "attach-eff") 		attach_eff(paramList, kittingplan);
	if(actionName == "remove-eff") 		remove_eff(paramList);
	if(actionName == "create-kit") 		create_kit(paramList);



/*
	switch(actionName)
	    {
	    case "take-kit-tray":
	    	cout <<"take-kit-tray"<< " ";
	      break;
	    case "put-kit-tray":
	    	cout <<"put-kit-tray"<< " ";
	      break;
	    case "take-kit":
	    	cout <<"take-kit"<< " ";
	      break;
	    case "put-kit":
	    	cout <<"put-kit"<< " ";
	      break;
	    case "take-part":
	    	cout <<"take-part"<< " ";
	      break;
	    case "put-part":
	    	cout <<"put-part"<< " ";
	      break;
	    case "attach-eff":
	    	cout <<"attach-eff"<< " ";
	      break;
	    case "remove-eff":
	    	cout <<"remove-eff"<< " ";
	      break;
	    case "create-kit":
	    	cout <<"create-kit"<< " ";
	    default:
	    	cout <<"Not recognized action"<< " ";
	    }
	  return 1;
	  */
}

/*!
@brief Read the plan stored in KittingPlan::m_actionParamList and interpret each action

@param kittingplan Instance of KittingPlan

*/
void CanonicalRobotCommand::interpretPlan(KittingPlan *kittingplan){

	string action("");
	string actionName("");
	vector<string> paramName;
	for (vector< vector<string> >::size_type u = 0; u < kittingplan->m_actionParamList.size(); u++) {
		actionName=kittingplan->m_actionParamList[u][0];
			for (vector<string>::size_type v = 1; v < kittingplan->m_actionParamList[u].size(); v++) {
				//cout << kittingplan->m_actionParamList[u][v] << " ";
				paramName.push_back(kittingplan->m_actionParamList[u][v]);
				//action += kittingplan->m_actionParamList[u][v];
				//action +=" ";
			}
			//cout << actionName << " --> " << action;

			actionInterpreter(actionName, paramName, kittingplan);
			//action="";
			paramName.clear();
			cout << endl;
		}

	//fileop->readVectorOfVector(kittingplan->m_actionParamList);
}

string CanonicalRobotCommand::getActionName(string myString){

}
