#include <stdio.h>		// sprintf

#include "nist_kitting/msg_types.h"

char *kitting_cmd_to_string(int s)
{
  enum { BUFLEN = 80 };		// make 
  static char buf[BUFLEN];	// warning -- not reentrant

  if (s == KITTING_NOP) sprintf(buf, "Nop");
  else if (s == KITTING_INIT) sprintf(buf, "Init");
  else if (s == KITTING_HALT) sprintf(buf, "Halt");
  else if (s == KITTING_WS_ASSEMBLE_KIT) sprintf(buf, "WsAssembleKit");
  else if (s == KITTING_TASK_MOVE_OBJECT) sprintf(buf, "TaskMoveObject");
  else if (s == KITTING_EMOVE_APPROACH) sprintf(buf, "EmoveApproach");
  else if (s == KITTING_EMOVE_ACQUIRE) sprintf(buf, "EmoveAcquire");
  else if (s == KITTING_EMOVE_MOVE) sprintf(buf, "EmoveMove");
  else if (s == KITTING_EMOVE_RELEASE) sprintf(buf, "EmoveRelease");
  else if (s == KITTING_EMOVE_DEPART) sprintf(buf, "EmoveDepart");
  else if (s == KITTING_PRIM_ROBOT_MOVETO) sprintf(buf, "PrimRobotMoveTo");
  else if (s == KITTING_PRIM_ROBOT_STOP) sprintf(buf, "PrimRobotStop");
  else if (s == KITTING_PRIM_ROBOT_OPEN_GRIPPER) sprintf(buf, "PrimRobotOpenGripper");
  else if (s == KITTING_PRIM_ROBOT_CLOSE_GRIPPER) sprintf(buf, "PrimRobotCloseGripper");
  else sprintf(buf, "?");

  return buf;
}

char *rcs_state_to_string(int s)
{
  enum { BUFLEN = 80 };
  static char buf[BUFLEN];	/* warning-- not reentrant */

  if (s == RCS_STATE_UNINITIALIZED) sprintf(buf, "Uninitialized");
  else if (s == RCS_STATE_NEW_COMMAND) sprintf(buf, "NewCommand");
  else sprintf(buf, "S%d", (int) (s - 10)); /* S0 starts at 10 */

  return buf;
}

char *rcs_status_to_string(int s)
{
  enum { BUFLEN = 80 };
  static char buf[BUFLEN];	/* warning-- not reentrant */

  if (s == RCS_STATUS_UNINITIALIZED) sprintf(buf, "Uninitialized");
  else if (s == RCS_STATUS_DONE) sprintf(buf, "Done");
  else if (s == RCS_STATUS_EXEC) sprintf(buf, "Exec");
  else if (s == RCS_STATUS_ERROR) sprintf(buf, "Error");
  else sprintf(buf, "%d", (int) s);

  return buf;
}
