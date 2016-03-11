/* 
 * File:   Setup.h
 * Author: michalos
 *
 * Created on February 25, 2016, 8:38 AM
 */

/*
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards
 * and Technology (NIST), an agency of the U.S. government, and by statute is
 * not subject to copyright in the United States.  Recipients of this software
 * assume all responsibility associated with its operation, modification,
 * maintenance, and subsequent redistribution.
 *
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 */

#ifndef SETUP_H
#define	SETUP_H

#include <ros/ros.h>
#include <map>
#ifdef	__cplusplus
extern "C" {
#endif
    /*!
     * \brief SetupAppEnvironment will attempt save some of the application settings, e.g., user, nostname.
     * \return bool true if success.
     */
    extern bool SetupAppEnvironment();

    /*!
     * \brief SetupRosEnvironment will attempt to provide an environment equivalent to ROS "source devel/setup.bash".
     * \fixme some of the code is hard coded, but unnecessary if executable run in shell.
     * \return bool true if success.
     */
    extern bool SetupRosEnvironment(std::string pkgpath);

    /*!
     * \brief ReadRosParams will read and record all ros params in system.
     * \param ROS node handle.
     * \return string containing a list of all ros param definitions
     */
    extern std::string ReadRosParams(ros::NodeHandle &nh);

    /*!
     * \brief ExecuteShellCommand  runs a shell script and returns results.
     * \param string is the shell command.
     * \return string containing pipe recording of output
     */
    std::string ExecuteShellCommand(std::string);

#ifdef	__cplusplus
}
#endif

#endif	/* SETUP_H */

