
#include <bitset>
#include <iostream>
#include "types.h"
#include "portable.h"
#include "reporter.h"
#include "socknet.h"

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
 
  private: 
	Logger *logger_;

	bool log;

	networkSettings settings;
	networkStruct nS;
	Network::socketNet * sN;

	char commandRegister[43];
	int ackCommand[12];
	char statusRegister[12];
	int ackStatus[24];

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

	void getStatusRegisters();

	void writeStatus();

};
}
