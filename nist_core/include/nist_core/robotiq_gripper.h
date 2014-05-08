
#include <bitset>
#include <iostream>

#include "nist_core\nist_core.h"
#include "nist_core\crcl.h"
#include "nist_core\socknet.h"

#pragma warning (disable: 4251)

using std::bitset;
using namespace std;

namespace RobotiqGripper
{
  // This class is exported from the MathFuncsDll.dll
 
class LIBRARY_API RobotiqGripper {
  public: 

	bool graspedOnClose, graspedOnOpen, allFingersAtPos;

	RobotiqGripper();

	~RobotiqGripper();

	void setPositionFingerA(int);

	void setSpeedFingerA(int); 

	void setForceFingerA(int);

	void setPositionFingerB(int);

	void setSpeedFingerB(int); 

	void setForceFingerB(int);

	void setPositionFingerC(int);

	void setSpeedFingerC(int); 

	void setForceFingerC(int);

	void setPositionScissor(int);

	void setSpeedScissor(int); 

	void setForceScissor(int);

	int setGrip(int);

	void setParameter(int, int);

	void ConvertBinaryToHex(bitset<8>);

	void sendCommand();

  void getStatusRegisters();
 
  private: 
	bool log;

	networkSettings settings;
	networkStruct nS;
	Network::socketNet * sN;

	char commandRegister[43];
	int ackCommand[12];
	char statusRegister[12];
	//int ackStatus[24]; // original
  int ackStatus[128];

	int	ReqEcho_PosFingerA, ReqEcho_PosFingerB, ReqEcho_PosFingerC, ReqEcho_PosScissor, gripperMode;
	int PosFingerA, PosFingerB, PosFingerC, PosScissor;
	int CurFingerA, CurFingerB, CurFingerC, CurScissor;
	int PrevFingerA, PrevFingerB, PrevFingerC, PrevScissor;
	int gACT, gMOD, gGTO, gIMC, gSTA;
	int gDTA, gDTB, gDTC, gDTS, gFLT;

	bitset<8> action_request;
	bitset<8> gripper_options;
	
	enum parameter
   {
      ACTIVATE=1,
      GRIP=2,
	  MOVE=3,
      AUTO_RELEASE=4,
	  AUTO_CENTER=5,
	  ADVANCED_CONTROL=6,
	  SCISSOR_CONTROL=7
	};

	char inbuffer[REQUEST_MSG_SIZE];
	  int option;

	void connectRobotiq();

	void writeHex(string, char*, int);

	void writeHex(string, int [], int);

	void getCommandAck();

	void writeStatus();

};
}