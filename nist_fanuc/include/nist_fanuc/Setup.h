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

    extern bool SetupAppEnvironment();
   extern bool SetupRosEnvironment();
    extern std::string ReadRosParams(ros::NodeHandle &nh);
    std::string ExecuteShellCommand(std::string);
    
#ifdef	__cplusplus
}
#endif

#endif	/* SETUP_H */

