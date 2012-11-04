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
 *  @brief     Configuration file
 *  @details   The Configuration file contains paths of files used by the project.
 *  @author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  @version   1.0
 *  @date      May 17, 2012
 */


#ifndef CONFIG_H_
#define CONFIG_H_



/*!
@def PLAN_INSTANCE
@brief Name and Path of the Plan Instance File
*/
#define PLAN_FOLDER "../etc/Plan/"
#define PLAN_FILE "plan_a2b2c1.txt"

/*!
@def PDDL_PROBLEM
@brief Name and Path of the PDDL Problem File
*/
#define PDDL_FOLDER "../etc/PDDL/"
#define PDDL_DOMAIN "domain_a2b2c1.pddl"
#define PDDL_PROBLEM "problem_a2b2c1.pddl"

/*!
@def CanonicalRobotCommands directory
@brief Directory that will be used to store canonical robot commands
*/
#define ROBOT_COMMANDS_FOLDER "../etc/CanonicalRobotCommands/"
#define ROBOT_COMMANDS_FILE "canon_commands_a2b2c1.txt"

#endif /* CONFIG_H_ */




