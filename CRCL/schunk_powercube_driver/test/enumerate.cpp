/**
 * \file enumerate.cpp
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

int deviceMap[MAX_MODULES];

int main()
{
	int ret = 0;
	int dev = 0;
	int numModules = 0;

	char pInitString[] = "RS232:1,9600";

	PCube_setDllDebug(1, 0, 0);

	std::cout << "Attempting to open device: " << pInitString << std::endl;

	ret = PCube_openDevice( &dev, pInitString );
	if( ret != 0 )
	{
		std::cout << "Unable to open device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}

	//std::cout << "Scanning for Devices." << std::endl;
	numModules = PCube_getModuleCount( dev );
	std::cout << "Found " << numModules << " PowerCube(s)\n" << std::endl;

	ret = PCube_getModuleIdMap( dev, deviceMap );
	for (int i = 0; i < numModules; ++i)
	{
		unsigned long serialNum = 0;
		unsigned char moduleType = 0;
		unsigned short moduleOS = 0;
		unsigned long state = 0;

		ret = PCube_getModuleSerialNo( dev, deviceMap[i], &serialNum );
		ret = PCube_getModuleType( dev, deviceMap[i], &moduleType );
		ret = PCube_getModuleVersion( dev, deviceMap[i], &moduleOS );
		ret = PCube_getModuleState( dev, deviceMap[i], &state );

		std::string typeStr = (moduleType == TYPEID_MOD_ROTARY) ? "ROTARY" : "LINEAR";
		std::cout << "\nModule[" << i << "] " << deviceMap[i] << ":" << std::endl;
		std::cout << "\tSerial #:         " << serialNum << std::endl;
		std::cout << "\tModule Type:      " << typeStr << std::endl;
		std::cout << "\tSoftware Version: " << std::hex << moduleOS << std::dec << std::endl;
		std::cout << "\tModule State:     0x" << std::hex << state << std::dec << std::endl;
	}

	ret = PCube_closeDevice( dev );
	if( ret != 0 )
	{
		std::cout << "Unable to close device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}
	return 0;
}
