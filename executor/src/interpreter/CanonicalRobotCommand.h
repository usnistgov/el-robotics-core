/*
 * CanonicalRobotCommand.h
 *
 *  Created on: Jun 28, 2012
 *      Author: zeid
 */

#ifndef CANONICALROBOTCOMMAND_H_
#define CANONICALROBOTCOMMAND_H_

#include "Tools.h"
#include "KittingPlan.h"

class CanonicalRobotCommand {
public:
	CanonicalRobotCommand();
	virtual ~CanonicalRobotCommand();

	void actionInterpreter(string action,vector<string> paramName,KittingPlan *kittingplan);
	void interpretPlan(KittingPlan *kittingplan);
	string getActionName(string myList);
	void take_kit_tray(vector<string> paramList);
	void put_kit_tray(vector<string> paramList);
	void take_kit(vector<string> paramList);
	void put_kit(vector<string> paramList);
	void take_part(vector<string> paramList);
	void put_part(vector<string> paramList);
	void attach_eff(vector<string> paramList,KittingPlan *kittingplan);
	void remove_eff(vector<string> paramList);
	void create_kit(vector<string> paramList);
};

#endif /* CANONICALROBOTCOMMAND_H_ */
