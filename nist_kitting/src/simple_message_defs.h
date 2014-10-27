#ifndef SIMPLE_MESSAGE_DEFS_H
#define SOMPLE_MESSAGE_DEFS_H

#include <stddef.h>		/* sizeof */
#include <stdio.h>		/* printf */
#include <string.h>		/* memcpy */

enum {
  JOINT_MESSAGE_PORT_DEFAULT = 11000,
  JOINT_STATE_PORT_DEFAULT = 11002
};

struct joint_info {
  double pos;
  double pmin;
  double pmax;
  double vel;
  double vmax;

  joint_info() {
    pos = 0;
    pmin = -1;
    pmax = 1;
    vel = 0;
    vmax = 1;
  }

  void print_joint_info(const char *prefix = "") {
    printf("%sPosition: %f\n", prefix, pos);
    printf("%sPos Min:  %f\n", prefix, pmin);
    printf("%sPos Max:  %f\n", prefix, pmax);
    printf("%sVelocity: %f\n", prefix, vel);
    printf("%sVel Max:  %f\n", prefix, vmax);
  };

  float get_pos() {
    return pos;
  };
  void set_pos(float _pos) {
    pos = _pos;			/* FIXME -- clamp it to min, max */
  };
};

struct robot_info {
  enum {JOINT_MAX = 10};
  joint_info joint[JOINT_MAX];
  unsigned int joints;

  robot_info(unsigned int j = JOINT_MAX) {
    joints = j;
  };

  void print_robot_info(const char *prefix = "") {
    for (int t = 0; t < joints; t++) {
      printf("%sJoint %d:\n", prefix, t+1);
      joint[t].print_joint_info("  ");
    }
  }

  bool get_robot_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    *pos = joint[index].get_pos();
    return true;
  }

  bool set_robot_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    joint[index].set_pos(pos);
    return true;
  }
};

/*
  Joint command:

  Client request:

  LENGTH [4 bytes] (the bytes in the message, not including this
  length specifier)

  10 [4 bytes[ (MSG_ID – JOINT MESSAGE)

  2 [4 bytes] (COMM_TYPE - REQUEST)
  0 [4 bytes] (REPLY_TYPE – N/A)

  SEQ_NUMBER [4 bytes] - The sequence number is the number assigned by
  ROS to each of the points (i.e. this is always 0 or positive). A
  value of -1 indicates the end of a trajectory, a value of -2
  indicates a stop (in both cases the controller stops, joint data is
  not valid for these special types)

  JOINT_DATA [10 x 4 bytes] (in rads (floats))

  Server reply:

  LENGTH [4 bytes] (the bytes in the message, not including this
  length specifier)

  10 [4 bytes] (MSG_ID – JOINT MESSAGE)

  3 [4 bytes] (COMM_TYPE – RESPONSE)

  REPLY [4 bytes] (1 = SUCCESS, 2 = FAILURE)

  UNUSED [4 bytes] (same position in message as SEQ NUMBER

  UNUSED [10 x 4 bytes] (same position in message as JOINT_DATA
*/

typedef enum {
  MESSAGE_JOINT = 10,
  MESSAGE_JOINT_STATE = 11
} message_types;

typedef enum {
  COMM_TOPIC = 1,
  COMM_REQUEST = 2,
  COMM_REPLY = 3
} comm_types;

typedef enum {
  REPLY_NA = 0,
  REPLY_SUCCESS = 1,
  REPLY_FAILURE = 2
} reply_types;

enum {JOINT_MAX = 10};

struct joint_request_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 2, REQUEST
  int reply_type;	  // 4 bytes, N/A
  int seq_number;	  // 4 bytes, >= 0
  float joints[JOINT_MAX]; // 10 4-byte floats, one per joint

  joint_request_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      sizeof(joints);
    message_type = MESSAGE_JOINT;
    comm_type = COMM_REQUEST;
    reply_type = REPLY_NA;
    seq_number = 1;
    for (int t = 0; t < JOINT_MAX; t++) {
      joints[t] = 0;
    }
  };

  void print_joint_request(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sSeq Num:    %d\n", prefix, (int) seq_number);
    printf("%sJoints: ", prefix);
    for (int t = 0; t < JOINT_MAX; t++) {
      printf(" %f", joints[t]);
    }
    printf("\n");
  };

  void read_joint_request(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
    ptr += sizeof(reply_type);
    memcpy(&seq_number, ptr, sizeof(seq_number));
    ptr += sizeof(seq_number);
    memcpy(joints, ptr, sizeof(joints));
  };

  int get_seq_number() {
    return seq_number;
  };
  void set_seq_number(int num) {
    seq_number = num;
  }

  bool set_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    joints[index] = pos;
    return true;
  };

  bool get_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    *pos = joints[index];
    return true;
  };
};

struct joint_reply_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 2, REQUEST
  int reply_type;	  // 4 bytes, 1 = SUCCESS, 2 = FAILURE
  // NOTE: this should be the sequence number echo
  int unused_1;		  // 4 bytes, N/A
  float unused_2[JOINT_MAX];	// 10 4-byte floats, N/A

  joint_reply_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(unused_2);
    message_type = MESSAGE_JOINT;
    comm_type = COMM_REPLY;
    // caller will need to set reply_type with method below
  };

  void print_joint_reply(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
  };

  void read_joint_reply(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
    ptr += sizeof(reply_type);
    memcpy(&unused_1, ptr, sizeof(unused_1));
    ptr += sizeof(unused_1);
    memcpy(&unused_2, ptr, sizeof(unused_2));
  };

  void set_joint_reply(reply_types reply) {
    reply_type = reply;
  };
};

struct joint_state_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 1, TOPIC
  int reply_type;	  // 4 bytes, N/A
  int unused_1;		  // 4 bytes, N/A
  float joints[JOINT_MAX];	// 10 4-byte floats, N/A

  joint_state_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(joints);
    message_type = MESSAGE_JOINT_STATE;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
    // caller will need to set joints with method below
  };

  void print_joint_state(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sJoints: ", prefix);
    for (int t = 0; t < JOINT_MAX; t++) {
      printf(" %f", joints[t]);
    }
    printf("\n");
  };

  void read_joint_state(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
    ptr += sizeof(reply_type);
    memcpy(&unused_1, ptr, sizeof(unused_1));
    ptr += sizeof(unused_1);
    memcpy(joints, ptr, sizeof(joints));
  };

  bool set_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    joints[index] = pos;
  };

  bool get_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return false;
    *pos = joints[index];
  };
};

#endif	/* SIMPLE_MESSAGE_DEFS_H */
