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
 \mainpage
The interpreter reads a plan file \ref PLAN_INSTANCE and generate a text file that contains Canonical Robot Commands.



 \author <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 \author <a href="http://www.nist.gov/el/isd/ks/kramer.cfm">Tom Kramer</a> \a kramer\@cme.nist.gov
 \author <a href="http://www.nist.gov/el/isd/ks/balakirsky.cfm">Stephen Balakirsky</a> \a stephen.balakirsky\@nist.gov
 \author Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 <br><a href="http://www.nist.gov/index.html">National Institute of Standards and Technology</a>
 <br><a href="http://www.nist.gov/el/isd/">Intelligent Systems Division</a>
 */

#include "interpreter/Operator.h"
#include "interpreter/KittingPlan.h"
#include "interpreter/KittingPDDLProblem.h"
#include "interpreter/Config.h"
#include "interpreter/Tools.h"
#include "interpreter/CanonicalRobotCommand.h"
#include "interpreter/IniFile.h"


int main(int argc, const char* argv[]) {
	FileOperator *fileop = new FileOperator;
	KittingPlan *kittingplan = new KittingPlan;
	KittingPDDLProblem *kittingProb = new KittingPDDLProblem;
	CanonicalRobotCommand *canonicalRobotCommand = new CanonicalRobotCommand;

	//-- Retrieve the PLAN File
	string plan = "";
	plan +=PLAN_FOLDER;
	plan +=PLAN_FILE;

	//-- Retrieve the PDDL Problem File
	string pddl = "";
	pddl +=PDDL_FOLDER;
	pddl +=PDDL_PROBLEM;

	kittingplan->parsePlanInstance(plan.c_str());
	kittingplan->storeParam();
	kittingProb->parsePDDLProblem(pddl.c_str(), kittingplan);
	canonicalRobotCommand->interpretPlan(kittingplan);

	delete kittingplan;
	delete fileop;
	delete kittingProb;
	delete canonicalRobotCommand;

//	IniFile *inifile = new IniFile();
	//inifile->findSection ("etc/plan_a2b2c1.txt", "PLAN");
	//printf ("[seg1] tag1=%s\n", inifile->find ("tag1", "seg1"));
}

