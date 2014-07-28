/**
 * \file schunk_powercube_driver_node.cpp
 * \brief
 *
 * \author Andrew Price
 * \date 7 11, 2014
 *
 * \copyright
 *
 * Copyright (c) 2014, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * This file is provided under the following "BSD-style" License:
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include "schunk_libm5api/m5apiw32.h"

#include <iostream>

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>

const float MAX_POS = 0.0684;
const float MIN_POS = 0.0150;

ros::Publisher jsPub;
ros::Subscriber gripperPosSub;

struct GripperState
{
	float position;
	float velocity;
	float current;
};

GripperState state;

int ret = 0;
int dev = 0;
int modId = 12;
int numOfModules = 0;

float pos = 0.04;
float vel = 0.25;
float acc = 0.25;
char pInitString[] = "RS232:1,9600";

unsigned long stateFlags = 0;
unsigned long serialNum = 0;

void gripper_cb(const std_msgs::Float32ConstPtr position)
{
	pos = position->data;
	if (pos > MAX_POS) { pos = MAX_POS; }
	if (pos < MIN_POS) { pos = MIN_POS; }

	ret = PCube_moveRamp( dev, modId, pos, vel, acc );
	if( ret != 0 )
	{
		std::cout << "Unable to move module: " << modId << ". Error " << ret << std::endl;
		return;
	}
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "schunk_powercube_driver");
	ros::NodeHandle nh;

	gripperPosSub = nh.subscribe("/gripper_position", 1, &gripper_cb);
	jsPub = nh.advertise<sensor_msgs::JointState>("joint_states", 1);

	//PCube_setDllDebug(1, 0, 0);

	std::cout << "Attempting to open device: " << pInitString << std::endl;

	ret = PCube_openDevice( &dev, pInitString );
	if( ret != 0 )
	{
		std::cout << "Unable to open device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}

	numOfModules = PCube_getModuleCount( dev );
	std::cout << "Found " << numOfModules << " PowerCube(s)\n" << std::endl;

	ret = PCube_getModuleSerialNo(dev, modId, &serialNum);
	std::cout << "Device " << modId << " has serial #: " << serialNum << std::endl;

	ret = PCube_resetModule(dev, modId);

	std::cout << "Homing module: " << modId << std::endl;
	ret = PCube_homeModule( dev, modId );
	ret = PCube_waitForHomeEnd(dev, modId, 1e6);
	if( ret != 0 )
	{
		std::cout << "Unable to home module: " << modId << ". Error " << ret << std::endl;
		return -1;
	}
	do
	{
		ret = PCube_getModuleState( dev, modId, &stateFlags );
		if( ret != 0 )
		{
			std::cout << "Unable to get device state: " << modId << ". Error " << ret << std::endl;
			return -1;
		}
	} while(!(stateFlags & STATEID_MOD_HOME) );

	ret = PCube_moveRamp( dev, modId, pos, vel, acc );
	if( ret != 0 )
	{
		std::cout << "Unable to move module: " << modId << ". Error " << ret << std::endl;
		return -1;
	}

	ros::Rate r(10);

	sensor_msgs::JointState js;
	js.name.push_back("gripper_a");
	js.name.push_back("gripper_b");
	js.header.frame_id = "tool_frame";
	js.position.push_back(0); js.position.push_back(0);
	js.velocity.push_back(0); js.velocity.push_back(0);
	js.effort.push_back(0); js.effort.push_back(0);
	while(ros::ok())
	{
		ret = PCube_getModuleState( dev, modId, &stateFlags );

		ret |= PCube_getPos( dev, modId, &state.position );
		ret |= PCube_getVel( dev, modId, &state.velocity );
		ret |= PCube_getCur( dev, modId, &state.current );

		if (0 == ret)
		{
			js.position[0] = MAX_POS - state.position;
			js.velocity[0] = -state.velocity;
			js.effort[0] = state.current;

			js.position[1] = MAX_POS - state.position;
			js.velocity[1] = -state.velocity;
			js.effort[1] = state.current;

			js.header.stamp = ros::Time::now();

			jsPub.publish(js);
		}
		ros::spinOnce();
		r.sleep();
	}

	ret = PCube_closeDevice( dev );
	if( ret != 0 )
	{
		std::cout << "Unable to close device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}
	return 0;
}
