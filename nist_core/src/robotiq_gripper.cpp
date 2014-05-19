#include "nist_core/robotiq_gripper.h"
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
using std::cout;

namespace RobotiqGripper
{
	LIBRARY_API RobotiqGripper::RobotiqGripper(){   //test crap
      
	//Initialize gripper input registers (robot output functionalities command)
	  
	  for (int i=0; i<43; i++) commandRegister[i] = 0x00;
	  commandRegister[0] = 0x00; // Start Trans ID @ 1
	  commandRegister[1] = 0x01;
	  commandRegister[2] = 0x00; // Protocol ID
	  commandRegister[3] = 0x00;
	  commandRegister[4] = 0x00;  // Use fixed message size to support both 
	  commandRegister[5] = 0x25;
	  commandRegister[6] = 0x02;  // Slave ID
	  commandRegister[7] = 0x10;  // Function code 16 (Preset Multiple Registers)
	  commandRegister[8] = 0x00;  // Address of first register
	  commandRegister[9] = 0x00;
	  commandRegister[10] = 0x00;  // Write all 15 registers
	  commandRegister[11] = 0x0F; 
	  commandRegister[12] = 0x1E;  // Consisting of 30 bytes of data

	  statusRegister[0] = 0x00; // 
	  statusRegister[1] = 0x01;
	  statusRegister[2] = 0x00; // 
	  statusRegister[3] = 0x00;
	  statusRegister[4] = 0x00;  //  
	  statusRegister[5] = 0x06;
	  statusRegister[6] = 0x02;  // 
	  statusRegister[7] = 0x04;  // 
	  statusRegister[8] = 0x00;  // 
	  statusRegister[9] = 0x00;
	  statusRegister[10] = 0x00;  // 
	  statusRegister[11] = 0x0F; 

	  connectRobotiq(); // Establish Socket Connection

	  setParameter(1,0);  //Reset Gripper
	  
	  setParameter(1,1);  //Activate Gripper

    getStatusRegisters();

    PrevFingerA = ReqEcho_PosFingerA;
		PrevFingerB = ReqEcho_PosFingerB;
		PrevFingerC = ReqEcho_PosFingerC;
		PrevScissor = ReqEcho_PosScissor;
	  
	  /*setParameter(2,1);  //Wide
	 
	  setParameter(2,0);  //Basic
	
	  //setParameter(2,3);  //Pinch
	 

	  cout << "Advanced" << endl;
	   //Advanced Control
	  setSpeedFingerA(50);
	  setSpeedFingerB(100);
	  setSpeedFingerC(150);
	  setPositionFingerA(50);
	  setPositionFingerB(100);
	  setPositionFingerC(150);
	  setParameter(6,1);
	  setParameter(3,1);
	  sendCommand();
	  writeStatus();
	  while (!allFingersAtPos)
	  {
		getStatusRegisters();
		cout << gDTA << " " << gDTB << " " << gDTC << endl;
	  }*/
	  
	}


	LIBRARY_API RobotiqGripper::~RobotiqGripper(){

	}

	void LIBRARY_API RobotiqGripper::connectRobotiq()
    {
      /*
	  nS.sP = 502;
	  settings.globalRunServer = true;
	  nS.address ="192.168.1.11";
	  sN = new Network::socketNet(&settings);
	  sN->attach(nS);
    */
    
//    clientID_ = ulapi_socket_get_client_id (502, "192.168.1.11");
      clientID_ = ulapi_socket_get_client_id (502, "169.254.152.11");

	  //if (!nS.connected)
    if (clientID_ < 0)
    {
      cout << "no connection" << endl;
    }
	  else
	  {
	    cout << "connection success" << endl;
	  }
  }

	void LIBRARY_API RobotiqGripper::setPositionFingerA(int pose)
	{
		if (pose < 0) pose = 0; // no negative positions
		else if (pose > 255) pose = 255; // max position
		unsigned char y = pose;
		commandRegister[16]=y;
	}

	void LIBRARY_API RobotiqGripper::setSpeedFingerA(int speed)
	{
		if (speed < 0) speed = 0; // no negative speeds
		else if (speed > 255) speed = 255; // max speed
		unsigned char y = speed;
		commandRegister[17]=y;
	}

	void LIBRARY_API RobotiqGripper::setForceFingerA(int force)
	{
		if (force < 0) force = 0; // no negative speeds
		else if (force > 255) force = 255; // max speed
		unsigned char y = force;
		commandRegister[18]=y;
	}

		void LIBRARY_API RobotiqGripper::setPositionFingerB(int pose)
	{
		if (pose < 0) pose = 0; // no negative positions
		else if (pose > 255) pose = 255; // max position
		unsigned char y = pose;
		commandRegister[19]=y;
	}

	void LIBRARY_API RobotiqGripper::setSpeedFingerB(int speed)
	{
		if (speed < 0) speed = 0; // no negative speeds
		else if (speed > 255) speed = 255; // max speed
		unsigned char y = speed;
		commandRegister[20]=y;
	}

	void LIBRARY_API RobotiqGripper::setForceFingerB(int force)
	{
		if (force < 0) force = 0; // no negative speeds
		else if (force > 255) force = 255; // max speed
		unsigned char y = force;
		commandRegister[21]=y;
	}

	void LIBRARY_API RobotiqGripper::setPositionFingerC(int pose)
	{
		if (pose < 0) pose = 0; // no negative positions
		else if (pose > 255) pose = 255; // max position
		unsigned char y = pose;
		commandRegister[22]=y;
	}

	void LIBRARY_API RobotiqGripper::setSpeedFingerC(int speed)
	{
		if (speed < 0) speed = 0; // no negative speeds
		else if (speed > 255) speed = 255; // max speed
		unsigned char y = speed;
		commandRegister[23]=y;
	}

	void LIBRARY_API RobotiqGripper::setForceFingerC(int force)
	{
		if (force < 0) force = 0; // no negative speeds
		else if (force > 255) force = 255; // max speed
		unsigned char y = force;
		commandRegister[24]=y;
	}

	void LIBRARY_API RobotiqGripper::setPositionScissor(int pose)
	{
		if (pose < 0) pose = 0; // no negative positions
		else if (pose > 255) pose = 255; // max position
		unsigned char y = pose;
		commandRegister[25]=y;
	}

	void LIBRARY_API RobotiqGripper::setSpeedScissor(int speed)
	{
		if (speed < 0) speed = 0; // no negative speeds
		else if (speed > 255) speed = 255; // max speed
		unsigned char y = speed;
		commandRegister[26]=y;
	}

	void LIBRARY_API RobotiqGripper::setForceScissor(int force)
	{
		if (force < 0) force = 0; // no negative speeds
		else if (force > 255) force = 255; // max speed
		unsigned char y = force;
		commandRegister[27]=y;
	}

	

	int LIBRARY_API RobotiqGripper::setGrip(int param)
	{
		int status = 0;
    getStatusRegisters();
    writeStatus();

		if(param == 1){ //grasp

      
			PrevFingerA = ReqEcho_PosFingerA;
			PrevFingerB = ReqEcho_PosFingerB;
			PrevFingerC = ReqEcho_PosFingerC;
			PrevScissor = ReqEcho_PosScissor;

			//writeStatus();

			setParameter(3,1); //GoTo
			sendCommand();

			clock_t startTime = clock();
			clock_t currentTime;
			double time;

			while (true)
	        {

			   getStatusRegisters();
			   if (gDTA == 3 && gDTB == 3 && gDTC == 3)
			   {
				   status = 3;
           getStatusRegisters();
           //writeStatus();
				   break;
			   }
			   else if (gDTA == 2 && gDTB == 2 && gDTC == 2)
			   {
				   status = 2;
           getStatusRegisters();
				   break;
			   }

			   currentTime = clock();
			   time = (currentTime-startTime)/(double) CLOCKS_PER_SEC;
			  
			   if (time > 5) 
			   {
			     status = 0;
				   break;
			   }
			}

            //cout << "save: " << PrevFingerA << " " << PrevFingerB << " " << PrevFingerC << endl;
            return status;
		}
    else 
    { //release
      //cout << "release: " << PrevFingerA << " " << PrevFingerB << " " << PrevFingerC << endl;

			setPositionFingerA(PrevFingerA);
			setPositionFingerB(PrevFingerB);
			setPositionFingerC(PrevFingerC);
			setPositionScissor(PrevScissor);

      PrevFingerA = ReqEcho_PosFingerA;
			PrevFingerB = ReqEcho_PosFingerB;
			PrevFingerC = ReqEcho_PosFingerC;
			PrevScissor = ReqEcho_PosScissor;

			setParameter(3,1);
			sendCommand();

			while (gDTA != 3 && gDTB != 3 && gDTC != 3)
	    {
			  getStatusRegisters();
			}
      //getStatusRegisters();
      //writeStatus();
		}
		
		return status;
	}

	void LIBRARY_API RobotiqGripper::setParameter(int param, int val) //just action request, add Gripper Options Byte1
	{
		bool value;
		unsigned char request;

		if (val == 1) value = true;
		else value = false;


		switch(param)
		{	
			case ACTIVATE: //set rACT to 0:RESET or 1:ACTIVATE
			  action_request.set(0,value);  
			  request = (unsigned char)action_request.to_ulong();
		      commandRegister[13]=request;
			  sendCommand();
			  if (value)
			  {
	            while (gIMC != 3) getStatusRegisters();
			  }
			  else
			    while (gIMC != 0) getStatusRegisters();
			break;

			case GRIP: 
				setSpeedFingerA(255);
				switch (val)
				{
					case 0: //set rMOD BASIC
					action_request.set(1,false); 
					action_request.set(2,false);
					break;

					case 1: //set rMOD PINCH
					action_request.set(1,false);
					action_request.set(2,true);
					break;

					case 2: //set rMOD WIDE
					action_request.set(1,true);
					action_request.set(2,false);
					break;

					case 3: //set rMOD SCISSOR
					action_request.set(1,true);
					action_request.set(2,true);
					break;

					default:   ;
				}
			request = (unsigned char)action_request.to_ulong();
		    commandRegister[13]=request;
			sendCommand();
	        while (gIMC != 3) getStatusRegisters();
            break;

			case MOVE: //set rGTO 0:STOP or 1:GO
			  action_request.set(3,value);
			  request = (unsigned char)action_request.to_ulong();
		      commandRegister[13]=request;
			  sendCommand();
			break;

			case AUTO_RELEASE: //set rSTR 0:NORMAL or 1:AUTO RELEASE
			  action_request.set(4,value);
			  request = (unsigned char)action_request.to_ulong();
		      commandRegister[13]=request;
			  sendCommand();
			break;

			case AUTO_CENTER: //set rAAC 0:NORMAL or 1:AUTO CENTERING
			  gripper_options.set(1,value);
			  request = (unsigned char)gripper_options.to_ulong();
		      commandRegister[14]=request;
			break;

			case ADVANCED_CONTROL: //set rICF 0:NORMAL or 1:Enable Indvidual Control of Fingers A, B and C
			  gripper_options.set(2,value);
			  request = (unsigned char)gripper_options.to_ulong();
		      commandRegister[14]=request;
			break;

			case SCISSOR_CONTROL: //set rICS 0:NORMAL 1:Individual SCISSOR Control
			  gripper_options.set(3,value);
			  request = (unsigned char)gripper_options.to_ulong();
		      commandRegister[14]=request;
			break;

            default:   ;
        } 
	}

	void LIBRARY_API RobotiqGripper::writeHex(string str, char *buff, int size)
	{
		//cout << resetiosflags;

		//std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase) << std::setw(2) << std::setfill ('0');

		cout << str << ": ";

		for (int i=0; i<size; i++)
	  {
		std::cout << hex << (int)buff[i] << " ";
	  }
	  std::cout << std::endl;
	}

	void LIBRARY_API RobotiqGripper::writeHex(string str, int buff[], int size)
	{
	  //cout << resetiosflags;

	  //std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase) << std::setw(2) << std::setfill ('0');

	  cout << str << ": ";
		
	  for (int i=0; i<size; i++)
	  {
		std::cout << hex << buff[i] << " ";
	  }
	  std::cout << std::endl;
	}

	void LIBRARY_API RobotiqGripper::sendCommand()
	{
    int sent = ulapi_socket_write(clientID_, commandRegister, 43);
    /*
	  sN->sendData(commandRegister, nS, 43);
    */
	  getCommandAck();
	  getStatusRegisters();
	}

	void LIBRARY_API RobotiqGripper::getCommandAck()
	{
//	  while (!sN->dataWaiting (nS)){Sleep (50);}
	  
      int get;
      get = ulapi_socket_read(clientID_, inbuffer, 8192);
      //if (sN->getData (inbuffer, nS))
      {
	//	  for (int x = 0; x < nS.bytesRead; ++x)
      for (int x = 0; x < get; ++x)
		  {
			  ackCommand[x] = (int)inbuffer[x];
			  ackCommand[x] = (ackCommand[x] < 0)?(ackCommand[x]+256):(ackCommand[x]);
		  }
      }
	}

	void LIBRARY_API RobotiqGripper::getStatusRegisters()
	{
	  Sleep(200);
    int sent = ulapi_socket_write(clientID_, statusRegister, 12), get;
//	  sN->sendData(statusRegister, nS, 12);

//	  while (!sN->dataWaiting (nS)){Sleep (50);}
	  
      get = ulapi_socket_read (clientID_, inbuffer, 8192);
//      if (sN->getData (inbuffer, nS))
      {
//		  for (int i = 0; i < nS.bytesRead; ++i)
      for (int i = 0; i < get; ++i)
		  {
			  ackStatus[i] = (int)inbuffer[i];
			  ackStatus[i] = (ackStatus[i] < 0)?(ackStatus[i]+256):(ackStatus[i]);
		  }

		  bitset<8> gripper_status(ackStatus[9]);

		  //extract Initialization Status
		  if(gripper_status.test(0)) gACT = true;
		  else gACT = false;

		  //extract gripper mode 0:Basic 1:Pinch 2:Wide 3:Scissor
		  if(!gripper_status.test(1) && !gripper_status.test(2)) gMOD = 0;
		  else if (!gripper_status.test(1) && gripper_status.test(2)) gMOD = 1;
		  else if (gripper_status.test(1) && !gripper_status.test(2)) gMOD = 2;
		  else gMOD = 3;

		  //extract Stop/GoTo status
		  if(gripper_status.test(3)) gGTO = 1;
		  else gGTO = 0;

		  //extract setup status
		  if(!gripper_status.test(4) && !gripper_status.test(5)) gIMC = 0;
		  else if(gripper_status.test(4) && !gripper_status.test(5)) gIMC = 1;
		  else if(!gripper_status.test(4) && gripper_status.test(5)) gIMC = 2;
		  else  gIMC = 3;

		  //extract motion status
		  if(!gripper_status.test(6) && !gripper_status.test(7)) gSTA = 0;
		  else if(gripper_status.test(6) && !gripper_status.test(7)) gSTA = 1;
		  else if(!gripper_status.test(6) && gripper_status.test(7)) gSTA = 2;
		  else  gSTA = 3;

		  bitset<8> object_status(ackStatus[10]);

		  //extract FingerA status
		  if(!object_status.test(0) && !object_status.test(1)) gDTA = 0;
		  else if(object_status.test(0) && !object_status.test(1)) gDTA = 1;
		  else if(!object_status.test(0) && object_status.test(1)) gDTA = 2;
		  else  gDTA = 3;

		  //extract FingerB status
		  if(!object_status.test(2) && !object_status.test(3)) gDTB = 0;
		  else if(object_status.test(2) && !object_status.test(3)) gDTB = 1;
		  else if(!object_status.test(2) && object_status.test(3)) gDTB = 2;
		  else  gDTB = 3;

		  //extract FingerC status
		  if(!object_status.test(4) && !object_status.test(5)) gDTC = 0;
		  else if(object_status.test(4) && !object_status.test(5)) gDTC = 1;
		  else if(!object_status.test(4) && object_status.test(5)) gDTC = 2;
		  else  gDTC = 3;

		  //extract Scissor status
		  if(!object_status.test(6) && !object_status.test(7)) gDTS = 0;
		  else if(object_status.test(6) && !object_status.test(7)) gDTS = 1;
		  else if(!object_status.test(6) && object_status.test(7)) gDTS = 2;
		  else  gDTS = 3;

		  //cout << gDTA << " " << gDTB << " " << gDTC  << endl;

		  if (gDTA == 1 && gDTB == 1 && gDTC == 1) graspedOnClose = true;
		  else graspedOnClose = false;

		  if (gDTA == 2 && gDTB == 2 && gDTC == 2) graspedOnOpen = true;
		  else graspedOnOpen = false;

		  if (gDTA == 3 && gDTB == 3 && gDTC == 3) allFingersAtPos = true;
		  else allFingersAtPos = false;

		  //extract Fault Status
		  gFLT = ackStatus[11];

		  //extract FingerA Stats
		  ReqEcho_PosFingerA = ackStatus[12];
		  PosFingerA = ackStatus[13];
		  CurFingerA = ackStatus[14];

		  //extract FingerB Stats
		  ReqEcho_PosFingerB = ackStatus[15];
		  PosFingerB = ackStatus[16];
		  CurFingerB = ackStatus[17];

		  //extract FingerC Stats
		  ReqEcho_PosFingerC = ackStatus[18];
		  PosFingerC = ackStatus[19];
		  CurFingerC = ackStatus[20];

		  //extract Scissor Stats
		  ReqEcho_PosScissor = ackStatus[21];
		  PosScissor = ackStatus[22];
		  CurScissor = ackStatus[23];
      }


	}

	void LIBRARY_API RobotiqGripper::writeStatus()
	{
		//cout << resetiosflags;

		cout << endl << "GRIPPER STATUS" << endl;

		cout << "  Initialization: ";

		/*cout << "gACT = " << gACT  << endl;
		cout << "gMOD = " << gMOD  << endl;
		cout << "gGTO = " << gGTO  << endl;
		cout << "gIMC = " << gIMC  << endl;
		cout << "gSTA = " << gSTA  << endl;
		cout << "gDTA = " << gDTA  << endl;
		cout << "gDTB = " << gDTB  << endl;
		cout << "gDTC = " << gDTC  << endl;
		cout << "gDTS = " << gDTS  << endl;
		cout << "gFLT = " << gFLT  << endl;*/


		switch(gACT)
		{	
			case 0: 
			  cout << "Gripper reset"<< endl;
			break;
			case 1: 
              cout << "Gripper activation"<< endl;
			break;
			default:   ;
		}

		cout << "  Grasp Mode: ";
		switch(gMOD)
		{	
			case 0:
			  cout << "Basic"<< endl;
			break;
			case 1: 
              cout << "Pinch"<< endl;
			break;
			case 2:
			  cout << "Wide" << endl;
			break;
			case 3:
			  cout << "Scissor" << endl;
			break;
			default:   ;
		}

		cout << "  Stop/Goto: ";
		switch(gGTO)
		{	
			case 0: 
			  cout << "Stopped"<< endl;
			break;
			case 1: 
              cout << "GoTo Request"<< endl;
			break;
			default:   ;
		}

		cout << "  Setup: ";
		switch(gIMC)
		{	
			case 0:
			  cout << "Reset or auto-release state"<< endl;
			break;
			case 1: 
              cout << "Activation in progress"<< endl;
			break;
			case 2:
			  cout << "Mode change in progress" << endl;
		    break;
			case 3:
			  cout << "Activation/Mode change complete" << endl;
			break;
			default:   ;
		}

		cout << "  Motion: ";
		switch(gSTA)
		{	
			case 0:
			  cout << "Moving to goal pos"<< endl;
			break;
			case 1: 
              cout << "Stopped (1 or 2 fingers stopped before goal pose)"<< endl;
			break;
			case 2:
			  cout << "Stopped (all fingers stopped before goal pose)" << endl;
			break;
			case 3:
			  cout << "Stopped (all fingers reached goal pose" << endl;
			break;
			default:   ;
		}

		cout << endl << "OBJECT STATUS" << endl;

		cout << "  FingerA: ";
		switch(gDTA)
		{	
			case 0:
			  cout << "in motion"<< endl;
			break;
			case 1: 
              cout << "stopped (contact on open)"<< endl;
			break;
			case 2:
			  cout << "stopped (contact on close)" << endl;
			break;
			case 3:
			  cout << "at requested position" << endl;
			break;
			default:   ;
		}

		cout << "  FingerB: ";
		switch(gDTB)
		{	
			case 0:
			  cout << "in motion"<< endl;
			break;
			case 1: 
              cout << "stopped (contact on open)"<< endl;
			break;
			case 2:
			  cout << "stopped (contact on close)" << endl;
			break;
			case 3:
			  cout << "at requested position" << endl;
			break;
			default:   ;
		}

		cout << "  FingerC: ";
		switch(gDTC)
		{	
			case 0:
			  cout << "in motion"<< endl;
			break;
			case 1: 
              cout << "stopped (contact on open)"<< endl;
			break;
			case 2:
			  cout << "stopped (contact on close)" << endl;
			break;
			case 3:
			  cout << "at requested position" << endl;
			break;
			default:   ;
		}

		cout << "  Scissor: ";
		switch(gDTS)
		{	
			case 0:
			  cout << "in motion"<< endl;
			break;
			case 1: 
              cout << "stopped (contact on open)"<< endl;
			break;
			case 2:
			  cout << "stopped (contact on close)" << endl;
			break;
			case 3:
			  cout << "at requested position" << endl;
			break;
			default:   ;
		}

		cout << endl << "OBJECT STATUS" << endl;

		switch(gFLT)
		{	
			case 0:
			  cout << "  No Fault"<< endl;
			break;
			case 5: 
              cout << "  Priority Fault: Action delayed, activation(reactivation) must be completed prior to action"<< endl;
			break;
			case 6:
			  cout << "  Priority Fault: Action delayed, mode change must be completed prior to action" << endl;
			break;
			case 7:
			  cout << "  Priority Fault: The activation bit must be set prior to action" << endl;
			break;
			case 9:
			  cout << "  Minor Fault: The communicatin chip is not ready (may be booting)" << endl;
			break;
			case 10:
			  cout << "  Minor Fault: Changing mode fault, interferences detected on Scissor (for less than 20 seconds)" << endl;
			break;
			case 11:
			  cout << "  Minor Fault: Automatic release in progress" << endl;
			break;
			case 13:
			  cout << "  Major Fault: Activation fault, verify that no interference or other error occured" << endl;
			break;
			case 14:
			  cout << "  Major Fault: Changing mode fault, interferences detected on Scissor (for more than 20 seconds)" << endl;
			break;
			case 15:
			  cout << "  Major Fault: Automatic  release completed.  Reset and activation is required." << endl;
			break;
			default:   ;
		}

		cout << endl << "GRIPPER DATA" << endl;
		cout << "  Finger A" << endl;
		cout << "    Req Echo = " << ReqEcho_PosFingerA << endl;
		cout << "    Position = " << PosFingerA << endl;
		cout << "    Current  = " << CurFingerA << endl;

		cout << "  Finger B" << endl;
		cout << "    Req Echo = " << ReqEcho_PosFingerB << endl;
		cout << "    Position = " << PosFingerB << endl;
		cout << "    Current  = " << CurFingerB << endl;

		cout << "  Finger C" << endl;
		cout << "    Req Echo = " << ReqEcho_PosFingerC << endl;
		cout << "    Position = " << PosFingerC << endl;
		cout << "    Current  = " << CurFingerC << endl;

		cout << "  Scissor" << endl;
		cout << "    Req Echo = " << ReqEcho_PosScissor << endl;
		cout << "    Position = " << PosScissor << endl;
		cout << "    Current  = " << CurScissor << endl;
	}

}


