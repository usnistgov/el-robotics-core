#include "schunk_libm5api/m5apiw32.h"

#include <iostream>

int main()
{
	int ret = 0;
	int dev = 0;
	int modId = 12;
	int numOfModules = 0;

	float pos = 0.04;
	float vel = 1.0;
	float acc = 1.0;
	char pInitString[] = "RS232:1,9600";

	unsigned long state = 0;

	PCube_setDllDebug(1, 0, 0);

	std::cout << "Attempting to open device: " << pInitString << std::endl;

	ret = PCube_openDevice( &dev, pInitString );
	if( ret != 0 )
	{
		std::cout << "Unable to open device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}

	//std::cout << "Scanning for Devices." << std::endl;
	numOfModules = PCube_getModuleCount( dev );
	std::cout << "Found " << numOfModules << " PowerCubes\n" << std::endl;

	std::cout << "Homing module: " << modId << std::endl;
	ret = PCube_homeModule( dev, modId );
	ret = PCube_waitForHomeEnd(dev, modId, 1e6);
	if( ret != 0 )
	{
		std::cout << "Unable to home module: " << modId << ". Error " << ret << std::endl;
		//return -1;
	}
	do
	{
		ret = PCube_getModuleState( dev, modId, &state );
		if( ret != 0 )
		{
			std::cout << "Unable to get device state: " << modId << ". Error " << ret << std::endl;
			return -1;
		}
	} while( !(state & STATEID_MOD_HOME) );
	ret = PCube_moveRamp( dev, modId, pos, vel, acc );
	if( ret != 0 )
	{
		std::cout << "Unable to move module: " << modId << ". Error " << ret << std::endl;
		return -1;
	}
	ret = PCube_closeDevice( dev );
	if( ret != 0 )
	{
		std::cout << "Unable to close device: " << pInitString << ". Error " << ret << std::endl;
		return -1;
	}
	return 0;
}
