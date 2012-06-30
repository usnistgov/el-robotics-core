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
 This project deals with the executor interpreter for the IPMAS project.



 \author <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 \author <a href="http://www.nist.gov/el/isd/ks/kramer.cfm">Tom Kramer</a> \a kramer\@cme.nist.gov
 \author <a href="http://www.nist.gov/el/isd/ks/balakirsky.cfm">Stephen Balakirsky</a> \a stephen.balakirsky\@nist.gov
 \author Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 <br><a href="http://www.nist.gov/index.html">National Institute of Standards and Technology</a>
 <br><a href="http://www.nist.gov/el/isd/">Intelligent Systems Division</a>
 */

#include "interpreter/FileOperator.h"
#include "interpreter/KittingPlan.h"
#include "interpreter/KittingPDDLProblem.h"
#include "interpreter/Config.h"
#include "interpreter/Tools.h"
#include "interpreter/database.h"
#include "interpreter/CanonicalRobotCommand.h"

int main(int argc, const char* argv[]) {
	FileOperator *fileop = new FileOperator;
	KittingPlan *kittingplan = new KittingPlan;
	KittingPDDLProblem *kittingProb = new KittingPDDLProblem;
	CanonicalRobotCommand *canonicalRobotCommand = new CanonicalRobotCommand;

	kittingplan->parsePlanInstance(PLAN_INSTANCE);
	kittingplan->storeParam();
	kittingProb->parsePDDLProblem(PDDL_PROBLEM, kittingplan);
	canonicalRobotCommand->interpretPlan(kittingplan);
	//kittingplan->matchParamType("robot_1");

	//fileop->readVector(kittingplan->m_paramList);
	//fileop->readMap(kittingplan->m_ParamTypeList);

	//Robot * r = new Robot("robot_1");
	//r->get("robot_1");
	//std::cout << r->getname() << std::endl;
}

