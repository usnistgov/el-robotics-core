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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "Operator.hh"
#include "KittingPlan.hh"
#include "KittingPDDLProblem.hh"
#include "Tools.hh"
#include "CanonicalRobotCommand.hh"
#include "IniFile.hh"


int main(int argc, const char* argv[]) {
  std::string problem;
  std::string plan;
  std::string crcl;

  std::string sep = "\n------------------------------------------------------------------\n";
  if (argc<7 || argc>7)
    {
      std::cout << sep;
      std::cout << "                                ERROR -- Wrong Usage !!"
		<<sep;
      std::cout << "Correct Usage: ./executor -problem <kit/problem.pddl> "
		<< "-plan <kit/plan.txt> -output <crcl.txt>\n\n";
      std::cout << "Real example: ./executor -problem "
		<< "a2b3c5/problem-fluents-a2b3c5.pddl "
		<< "-plan a2b3c5/plan_a2b3c5.txt -output test.txt";
      std::cout << sep;
      std::cout << "<problem.pddl>: The name to the problem file for a "
		<< "specific kit.\n";
      std::cout << "The program will automatically search for this file in "
		<< "../../../PDDLplans/<kit/problem.pddl>";
      std::cout <<sep;
      std::cout << "<kit/plan.txt>: The \"name\" of the plan file.\n";
      std::cout << "The program will automatically search for this file in "
		<< "../../../PDDLplans/<kit/plan.txt>	";
      std::cout <<sep;
      std::cout << "<crcl.txt>: The \"name\" of the output crcl file.\n";
      std::cout << "The program will automatically save the new file in "
		<< "../etc/CanonicalRobotCommands/"<<sep;

      std::cout << "                                        -- EXIT --"<<sep;
      exit(0);

    }
  else
    {
      //-- Making sure we typed "-input"
      if (argv[1] == std::string("-problem"))
	problem = argv[2];
      else
	{
	  std::cout << sep;
	  std::cout << "ERROR -- make sure you use the key \"-problem\" "
		    << "for the problem file !!"<<sep;
	  exit(0);
	}

      //-- Making sure we typed "-output"
      if (argv[3] == std::string("-plan"))
	plan = argv[4];
      else
	{
	  std::cout << sep;
	  std::cout << "ERROR -- make sure you use the key \"-plan\" "
		    << "for the plan file !!"<<sep;
	  exit(0);
	}


      if (argv[5] == std::string("-output"))
	crcl = argv[6];
      else
	{
	  std::cout << sep;
	  std::cout << "ERROR -- make sure you use the key \"-output\" "
		    << "for the output CRCL file !!"<<sep;
	  exit(0);
	}

    }

  std::string problem_path = "../../../PDDLplans/";
  std::string plan_path = "../../../PDDLplans/";
  std::string crcl_path = "../etc/CanonicalRobotCommands/";

  std::string problem_file = problem_path.append(problem);
  std::string plan_file = plan_path.append(plan);
  std::string crcl_file = crcl_path.append(crcl);


  FileOperator *fileop = new FileOperator;
  KittingPlan *kittingplan = new KittingPlan;
  KittingPDDLProblem *kittingProb = new KittingPDDLProblem;
  CanonicalRobotCommand *canonicalRobotCommand = 
    new CanonicalRobotCommand();
  
  canonicalRobotCommand->setFileOperator(fileop);

  fileop->setCRCLFile(crcl_file);


  kittingplan->parsePlanInstance(plan_file.c_str());
  kittingplan->storeParam();
  kittingProb->parsePDDLProblem(problem_file.c_str(), kittingplan);
  canonicalRobotCommand->interpretPlan(kittingplan);

  delete kittingplan;
  delete fileop;
  delete kittingProb;
  delete canonicalRobotCommand;
}

