#ifndef MSG_TYPES_H
#define MSG_TYPES_H

/*
  Well-known topic names
*/
#define KITTING_WS_CMD_TOPIC "kitting_ws_cmd"
#define KITTING_WS_STAT_TOPIC "kitting_ws_stat"
#define KITTING_TASK_CMD_TOPIC "kitting_task_cmd"
#define KITTING_TASK_STAT_TOPIC "kitting_task_stat"
#define KITTING_EMOVE_CMD_TOPIC "kitting_emove_cmd"
#define KITTING_EMOVE_STAT_TOPIC "kitting_emove_stat"
#define KITTING_PRIM_ROBOT_CMD_TOPIC "kitting_prim_robot_cmd"
#define KITTING_PRIM_ROBOT_STAT_TOPIC "kitting_prim_robot_stat"

#define TOPIC_QUEUE_LEN 0

enum {
  KITTING_NOP = 0,
  KITTING_INIT,
  KITTING_HALT,
  KITTING_WS_ASSEMBLE_KIT,
  KITTING_TASK_MOVE_OBJECT,
  KITTING_EMOVE_RUN,
  KITTING_EMOVE_APPROACH,
  KITTING_EMOVE_ACQUIRE,
  KITTING_EMOVE_MOVE,
  KITTING_EMOVE_RELEASE,
  KITTING_EMOVE_DEPART,
  KITTING_PRIM_ROBOT_MOVETO,
  KITTING_PRIM_ROBOT_STOP,
  KITTING_PRIM_ROBOT_OPEN_GRIPPER,
  KITTING_PRIM_ROBOT_CLOSE_GRIPPER,
  /*  */
};

enum {
  RCS_STATE_UNINITIALIZED = 0,
  RCS_STATE_NEW_COMMAND = 1,
  RCS_STATE_S0 = 10,
  RCS_STATE_S1,
  RCS_STATE_S2,
  RCS_STATE_S3,
  RCS_STATE_S4,
  RCS_STATE_S5,
  RCS_STATE_S6,
  RCS_STATE_S7,
  RCS_STATE_S8,
  RCS_STATE_S9,
  RCS_STATE_LAST, /* set your named states to begin at least here */
};

enum {
  RCS_STATUS_UNINITIALIZED = 0,
  RCS_STATUS_DONE,
  RCS_STATUS_EXEC,
  RCS_STATUS_ERROR
};

extern char *kitting_cmd_to_string(int s);
extern char *rcs_state_to_string(int s);
extern char *rcs_status_to_string(int s);

#endif /* MSG_TYPES_H */
