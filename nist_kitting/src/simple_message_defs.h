#ifndef SIMPLE_MESSAGE_DEFS_H
#define SOMPLE_MESSAGE_DEFS_H

#include <stddef.h>		/* sizeof */
#include <stdio.h>		/* printf */
#include <string.h>		/* memcpy */
#include <stdlib.h>		/* malloc */

enum {JOINT_MAX = 10};		/* this is really 10 per the spec */

enum {
  MESSAGE_PORT_DEFAULT = 11000,
  STATE_PORT_DEFAULT = 11002
};

typedef enum {
  MESSAGE_PING = 1,
  MESSAGE_JOINT_POSITION = 10,
  MESSAGE_JOINT = 10,
  MESSAGE_JOINT_TRAJ_PT = 11,	  /* one point */
  MESSAGE_JOINT_TRAJ = 12,	  /* an array of points */
  MESSAGE_ROBOT_STATUS = 13,
  MESSAGE_JOINT_TRAJ_PT_FULL = 14,
  MESSAGE_JOINT_FEEDBACK = 15,
  MESSAGE_READ_INPUT = 20,
  MESSAGE_WRITE_OUTPUT = 21,
  MESSAGE_CART_TRAJ_PT = 31,
  MESSAGE_CART_FEEDBACK = 35,
  MESSAGE_OBJECT_STATE = 40
} message_types;

typedef enum {
  COMM_TOPIC = 1,
  COMM_REQUEST = 2,
  COMM_REPLY = 3
} comm_types;

typedef enum {
  REPLY_NA = 0,
  REPLY_SUCCESS = 1,
  REPLY_FAILURE = 2,
  REPLY_EXECUTING = 3		/* EXTENSION */
} reply_types;

#define JOINT_PMIN_DEFAULT -1000.0
#define JOINT_PMAX_DEFAULT 1000.0
#define JOINT_VMAX_DEFAULT 1000.0

struct joint_info {
  double pos;
  double pmin;
  double pmax;
  double vel;
  double vmax;

  joint_info() {
    pos = 0;
    pmin = JOINT_PMIN_DEFAULT;
    pmax = JOINT_PMAX_DEFAULT;
    vel = 0;
    vmax = JOINT_VMAX_DEFAULT;
  }

  void print_joint_info(const char *prefix = "") {
    printf("%sPosition: %f\n", prefix, pos);
    printf("%sPos Min:  %f\n", prefix, pmin);
    printf("%sPos Max:  %f\n", prefix, pmax);
    printf("%sVelocity: %f\n", prefix, vel);
    printf("%sVel Max:  %f\n", prefix, vmax);
  }

  float get_pos() {
    return pos;
  }

  void set_pos(float _pos) {
    if (_pos < pmin) pos = pmin;
    else if (_pos > pmax) pos = pmax;
    else pos = _pos;
  }

  float get_pmin() {
    return pmin;
  }

  void set_pmin(float _pmin) {
    pmin = _pmin;
  }

  float get_pmax() {
    return pmax;
  }

  void set_pmax(float _pmax) {
    pmax = _pmax;
  }
};

enum {
  ROBOT_MODE_MANUAL = 1,
  ROBOT_MODE_AUTO = 2
};

struct robot_info {
  /* items to be sent out as robot status */
  int drives_powered;
  int e_stopped;
  int error_code;
  int in_error;
  int in_motion;
  int mode;
  int motion_possible;

  /* items to be sent out as joint trajectory information */
  joint_info joint[JOINT_MAX];
  unsigned int joint_number;

  /* Cartesian pose */
  float x, y, z, qx, qy, qz, qw;

  robot_info(unsigned int j = JOINT_MAX) {
    drives_powered = 1;
    e_stopped = 0;
    error_code = 0;
    in_error = 0;
    in_motion = 0;
    mode = ROBOT_MODE_AUTO;
    motion_possible = 1;
    joint_number = j;
    x = 0, y = 0, z = 0;
    qx = 0, qy = 0, qz = 0, qw = 1;
  }

  void print_robot_info(const char *prefix = "") {
    /* FIXME -- add printing of robot status, e.g. estopped */
    for (int t = 0; t < joint_number; t++) {
      printf("%sJoint %d:\n", prefix, t+1);
      joint[t].print_joint_info("  ");
    }
  }

  int set_drives_powered(int v) {
    drives_powered = v;
    return 1;
  }

  int get_drives_powered(int *v) {
    *v = drives_powered;
    return 1;
  }

  int set_e_stopped(int v) {
    e_stopped = v;
    return 1;
  }

  int get_e_stopped(int *v) {
    *v = e_stopped;
    return 1;
  }

  int set_error_code(int v) {
    error_code = v;
    return 1;
  }

  int get_error_code(int *v) {
    *v = error_code;
    return 1;
  }

  int set_in_error (int v) {
    in_error  = v;
    return 1;
  }

  int get_in_error(int *v) {
    *v = in_error;
    return 1;
  }

  int set_in_motion(int v) {
    in_motion = v;
    return 1;
  }

  int get_in_motion(int *v) {
    *v = in_motion;
    return 1;
  }

  int set_mode(int v) {
    mode = v;
    return 1;
  }

  int get_mode(int *v) {
    *v = mode;
    return 1;
  }

  int set_motion_possible(int v) {
    motion_possible = v;
    return 1;
  }

  int get_motion_possible(int *v) {
    *v = motion_possible;
    return 1;
  }

  int set_robot_joint_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    joint[index].set_pos(pos);
    return 1;
  }

  int get_robot_joint_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    *pos = joint[index].get_pos();
    return 1;
  }

  int set_robot_joint_min(float pmin, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    joint[index].set_pmin(pmin);
    return 1;
  }

  int get_robot_joint_min(float *pmin, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    *pmin = joint[index].get_pmin();
    return 1;
  }

  int set_robot_joint_max(float pmax, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    joint[index].set_pmax(pmax);
    return 1;
  }

  int get_robot_joint_max(float *pmax, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    *pmax = joint[index].get_pmax();
    return 1;
  }

  int set_robot_cart_pos(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _qw) {
    x = _x;
    y = _y;
    z = _z;
    qx = _qx;
    qy = _qy;
    qz = _qz;
    qw = _qw;
    return 1;
  }

  int get_robot_cart_pos(float *_x, float *_y, float *_z, float *_qx, float *_qy, float *_qz, float *_qw) {
    *_x = x;
    *_y = y;
    *_z = z;
    *_qx = qx;
    *_qy = qy;
    *_qz = qz;
    *_qw = qw;
    return 1;
  }
};

/*
  Ping request:

  LENGTH [4 bytes]
  MSG_ID [4 bytes] = PING (1)
  COMM_TYPE [4 bytes] = REQUEST (2)
  REPLY_TYPE [4 bytes] = N/A

  No data for a ping request.
*/

struct ping_request_message {
  int length;		  /* 4 bytes, constant value should be 3x4 = 12 */
  int message_type;	  /* 4 bytes, constant value 1, PING */
  int comm_type;	  /* 4 bytes, constant value 2, REQUEST */
  int reply_type;	  /* 4 bytes, N/A */

  ping_request_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type);
    message_type = MESSAGE_PING;
    comm_type = COMM_REQUEST;
    reply_type = REPLY_NA;
  }

  void print_ping_request(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
  }

  void read_ping_request(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
  }
};

/*
  Ping reply:

  LENGTH [4 bytes]
  MSG_ID [4 bytes] = PING (1)
  COMM_TYPE [4 bytes] = REPLY (3)
  REPLY_TYPE [4 bytes] = SUCCESS (1) or FAILURE (2)

  No data for a ping reply.
*/

struct ping_reply_message {
  int length;		  /* 4 bytes, constant value should be 3x4 = 12 */
  int message_type;	  /* 4 bytes, constant value 1, PING */
  int comm_type;	  /* 4 bytes, constant value 3, REPLY */
  int reply_type;	  /* 4 bytes, 1 = SUCCESS, 2 = FAILURE */

  ping_reply_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type);
    message_type = MESSAGE_PING;
    comm_type = COMM_REPLY;
    reply_type = REPLY_SUCCESS;	/*  */
  }

  void print_ping_reply(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
  }

  void read_ping_reply(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
  }
};

/*
  Joint trajectory command: an array of waypoints

  Client request:

  LENGTH [4 bytes] = 14x4 (56)
  MSG ID [4 bytes] = JOINT_TRAJ (12)
  COMM_TYPE [4 bytes] = REQUEST (2)
  REPLY_TYPE [4 bytes] = N/A (0)
  SEQ_NUMBER [4 bytes] - The sequence number is the number assigned by
  ROS to each of the points (i.e. this is always 0 or positive). A
  value of -1 indicates the end of a trajectory, a value of -2
  indicates a stop (in both cases the controller stops, joint data is
  not valid for these special types)
  JOINT_DATA [10 x 4 bytes] (in rads (floats))

  Server reply:

  LENGTH [4 bytes] = 14x4 (56)
  MSG ID [4 bytes] = JOINT_TRAJ (12)
  COMM_TYPE [4 bytes] = REPLY (3)
  REPLY_TYPE [4 bytes] = SUCCESS (1) or FAILURE (2)
  UNUSED [4 bytes] = 0
  UNUSED [10 x 4 byte] = 0..0
*/

struct joint_traj_pt_request_message {
  int length;		  /* 4 bytes, constant value should be 16x4 = 64 */
  int message_type;	  /* 4 bytes, constant value 11, JOINT TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 2, REQUEST */
  int reply_type;	  /* 4 bytes, N/A */
  int seq_number;	  /* 4 bytes, >= 0 */
  float joints[JOINT_MAX]; /* 10 4-byte floats, one per joint */
  float velocity;	   /* 4 bytes */
  float duration;	   /* 4 bytes */

  joint_traj_pt_request_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      sizeof(joints) +
      sizeof(velocity) +
      sizeof(duration);
    message_type = MESSAGE_JOINT_TRAJ_PT;
    comm_type = COMM_REQUEST;
    reply_type = REPLY_NA;
    seq_number = 1;
    for (int t = 0; t < JOINT_MAX; t++) {
      joints[t] = 0;
    }
    velocity = 1;
    duration = 1;
  }

  void print_joint_traj_pt_request(const char *prefix = "") {
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
    printf("%sVelocity:   %f\n", prefix, velocity);
    printf("%sDuration:   %f\n", prefix, duration);
  }

  void read_joint_traj_pt_request(char *inbuf) {
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
    ptr += sizeof(joints);
    memcpy(&velocity, ptr, sizeof(velocity));
    ptr += sizeof(velocity);
    memcpy(&duration, ptr, sizeof(duration));
  }

  int get_seq_number() {
    return seq_number;
  }
  void set_seq_number(int num) {
    seq_number = num;
  }

  int set_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    joints[index] = pos;
    return 1;
  }

  int get_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    *pos = joints[index];
    return 1;
  }

  int set_velocity(float vel) {
    velocity = vel;
    return 1;
  }

  int get_velocity(float *vel) {
    *vel = velocity;
    return 1;
  }
};

struct joint_traj_pt_reply_message {
  int length;		  /* 4 bytes, constant value should be 14x4 = 56 */
  int message_type;	  /* 4 bytes, constant value 11, JOINT_TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 3, REPLY */
  int reply_type;	  /* 4 bytes, 1 = SUCCESS, 2 = FAILURE, 3 = EXEC */
  /* NOTE: this should be the sequence number echo */
  int unused_1;		  /* 4 bytes, N/A */
  float unused_2[JOINT_MAX];	/* 10 4-byte floats, N/A */

  joint_traj_pt_reply_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(unused_2);
    message_type = MESSAGE_JOINT_TRAJ_PT;
    comm_type = COMM_REPLY;
    /* caller will need to set reply_type with method below */
  }

  void print_joint_traj_pt_reply(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
  }

  void read_joint_traj_pt_reply(char *inbuf) {
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
  }

  void set_joint_traj_pt_reply(reply_types reply) {
    reply_type = reply;
  }
};

struct joint_traj_pt_state_message {
  int length;		  /* 4 bytes, constant value should be 14x4 = 56 */
  int message_type;	  /* 4 bytes, constant value 10, JOINT_TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 1, TOPIC */
  int reply_type;	  /* 4 bytes, N/A */
  int unused_1;		  /* 4 bytes, N/A */
  float joints[JOINT_MAX];	/* 10 4-byte floats, N/A */

  joint_traj_pt_state_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(joints);
    /* NOTE: JOINT_POSITION is deprecated, but JOINT_TRAJ_PT gives
       an error in the industrial robot client. */
    message_type = MESSAGE_JOINT_POSITION;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
    /* caller will need to set joints with method below */
  }

  void print_joint_traj_pt_state(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sJoints: ", prefix);
    for (int t = 0; t < JOINT_MAX; t++) {
      printf(" %f", joints[t]);
    }
    printf("\n");
  }

  void read_joint_traj_pt_state(char *inbuf) {
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
  }

  int set_pos(float pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    joints[index] = pos;
    return 1;
  }

  int get_pos(float *pos, int index) {
    if (index < 0 || index >= JOINT_MAX) return 0;
    *pos = joints[index];
    return 1;
  }
};

struct robot_status_message {
  int length;		  /* 4 bytes, constant value should be 10x4 = 40 */
  int message_type;	  /* 4 bytes, constant value 13, ROBOT_STATUS */
  int comm_type;	  /* 4 bytes, constant value 1, TOPIC */
  int reply_type;	  /* 4 bytes, N/A */
  int drives_powered;
  int e_stopped;
  int error_code;
  int in_error;
  int in_motion;
  int mode;
  int motion_possible;

  robot_status_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(drives_powered) +
      sizeof(e_stopped) +
      sizeof(error_code) +
      sizeof(in_error) +
      sizeof(in_motion) +
      sizeof(mode) +
      sizeof(motion_possible);
    message_type = MESSAGE_ROBOT_STATUS;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
  }

  void print_robot_status(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sDrives:     %d\n", prefix, (int) drives_powered);
    printf("%sEstopped:   %d\n", prefix, (int) e_stopped);
    printf("%sError Code: %d\n", prefix, (int) error_code);
    printf("%sIn Motion:  %d\n", prefix, (int) in_motion);
    printf("%sMode:       %d\n", prefix, (int) mode);
    printf("%sMotion OK:  %d\n", prefix, (int) motion_possible);
  }

  void read_robot_status(char *inbuf) {
    char *ptr = inbuf;
    memcpy(&length, ptr, sizeof(length));
    ptr += sizeof(length);
    memcpy(&message_type, ptr, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(&comm_type, ptr, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(&reply_type, ptr, sizeof(reply_type));
    ptr += sizeof(reply_type);
    memcpy(&drives_powered, ptr, sizeof(drives_powered));
    ptr += sizeof(drives_powered);
    memcpy(&e_stopped, ptr, sizeof(e_stopped));
    ptr += sizeof(e_stopped);
    memcpy(&error_code, ptr, sizeof(error_code));
    ptr += sizeof(error_code);
    memcpy(&in_motion, ptr, sizeof(in_motion));
    ptr += sizeof(in_motion);
    memcpy(&mode, ptr, sizeof(mode));
    ptr += sizeof(mode);
    memcpy(&mode, ptr, sizeof(mode));
    ptr += sizeof(mode);
    memcpy(&motion_possible, ptr, sizeof(motion_possible));
  }

  int set_drives_powered(int v) {
    drives_powered = v;
    return 1;
  }

  int get_drives_powered(int *v) {
    *v = drives_powered;
    return 1;
  }

  int set_e_stopped(int v) {
    e_stopped = v;
    return 1;
  }

  int get_e_stopped(int *v) {
    *v = e_stopped;
    return 1;
  }

  int set_error_code(int v) {
    error_code = v;
    return 1;
  }

  int get_error_code(int *v) {
    *v = error_code;
    return 1;
  }

  int set_in_error (int v) {
    in_error  = v;
    return 1;
  }

  int get_in_error(int *v) {
    *v = in_error;
    return 1;
  }

  int set_in_motion(int v) {
    in_motion = v;
    return 1;
  }

  int get_in_motion(int *v) {
    *v = in_motion;
    return 1;
  }

  int set_mode(int v) {
    mode = v;
    return 1;
  }

  int get_mode(int *v) {
    *v = mode;
    return 1;
  }

  int set_motion_possible(int v) {
    motion_possible = v;
    return 1;
  }

  int get_motion_possible(int *v) {
    *v = motion_possible;
    return 1;
  }
};

/* EXTENSIONS for Cartesian motion */

struct cart_traj_pt_request_message {
  int length;		  /* 4 bytes, constant value should be 13x4 = 52 */
  int message_type;	  /* 4 bytes, constant value 31, CART TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 2, REQUEST */
  int reply_type;	  /* 4 bytes, N/A */
  int seq_number;	  /* 4 bytes, >= 0 */
  float x, y, z, qx, qy, qz, qw; /* pose, Cartesian and quaternion */
  float translational_speed;	 /* 4 bytes, > 0 */
  float rotational_speed;	 /* 4 bytes, > 0 */

  cart_traj_pt_request_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      sizeof(x) +
      sizeof(y) +
      sizeof(z) +
      sizeof(qx) +
      sizeof(qy) +
      sizeof(qz) +
      sizeof(qw) +
      sizeof(translational_speed) +
      sizeof(rotational_speed);
    message_type = MESSAGE_CART_TRAJ_PT;
    comm_type = COMM_REQUEST;
    reply_type = REPLY_NA;
    seq_number = 1;
    x = 0, y = 0, z = 0, qx = 0, qy = 0, qz = 0, qw = 1;
    translational_speed = 1;
    rotational_speed = 1;
  }

  void print_cart_traj_pt_request(const char *prefix = "") {
    printf("%sLength:      %d\n", prefix, (int) length);
    printf("%sMsg Type:    %d\n", prefix, (int) message_type);
    printf("%sComm Type:   %d\n", prefix, (int) comm_type);
    printf("%sReply Type:  %d\n", prefix, (int) reply_type);
    printf("%sSeq Num:     %d\n", prefix, (int) seq_number);
    printf("%sPosition:    %f %f %f / %f %f %f %f\n", prefix, x, y, z, qx, qy, qz, qw);
    printf("%sTrans Speed: %f\n", prefix, translational_speed);
    printf("%sRot Speed:   %f\n", prefix, rotational_speed);
  }

  void read_cart_traj_pt_request(char *inbuf) {
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
    memcpy(&x, ptr, sizeof(x));
    ptr += sizeof(x);
    memcpy(&y, ptr, sizeof(y));
    ptr += sizeof(y);
    memcpy(&z, ptr, sizeof(z));
    ptr += sizeof(z);
    memcpy(&qx, ptr, sizeof(qx));
    ptr += sizeof(qx);
    memcpy(&qy, ptr, sizeof(qy));
    ptr += sizeof(qy);
    memcpy(&qz, ptr, sizeof(qz));
    ptr += sizeof(qz);
    memcpy(&qw, ptr, sizeof(qw));
    ptr += sizeof(qw);
    memcpy(&translational_speed, ptr, sizeof(translational_speed));
    ptr += sizeof(translational_speed);
    memcpy(&rotational_speed, ptr, sizeof(rotational_speed));
  }

  int get_seq_number() {
    return seq_number;
  }
  void set_seq_number(int num) {
    seq_number = num;
  }

  int set_pos(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _qw) {
    x = _x;
    y = _y;
    z = _z;
    qx = _qx;
    qy = _qy;
    qz = _qz;
    qw = _qw;
    return 1;
  }
  int get_pos(float *_x, float *_y, float *_z, float *_qx, float *_qy, float *_qz, float *_qw) {
    *_x = x;
    *_y = y;
    *_z = z;
    *_qx = qx;
    *_qy = qy;
    *_qz = qz;
    *_qw = qw;
    return 1;
  }

  int set_translational_speed(float v) {
    translational_speed = v;
    return 1;
  }

  int get_translational_speed(float *v) {
    *v = translational_speed;
    return 1;
  }

  int set_rotational_speed(float v) {
    rotational_speed = v;
    return 1;
  }

  int get_rotational_speed(float *v) {
    *v = rotational_speed;
    return 1;
  }
};

struct cart_traj_pt_reply_message {
  int length;		  /* 4 bytes, constant value should be 4x4 = 16 */
  int message_type;	  /* 4 bytes, constant value 31, CART_TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 3, REPLY */
  int reply_type;	  /* 4 bytes, 1 = SUCCESS, 2 = FAILURE, 3 = EXEC */
  int seq_number;	  /* 4 bytes, sequence number echo */

  cart_traj_pt_reply_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number);
    message_type = MESSAGE_CART_TRAJ_PT;
    comm_type = COMM_REPLY;
    /* caller will need to set reply_type with method below */
  }

  void print_cart_traj_pt_reply(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sSeq Num:    %d\n", prefix, (int) seq_number);
  }

  void read_cart_traj_pt_reply(char *inbuf) {
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
  }

  void set_cart_traj_pt_reply(reply_types reply) {
    reply_type = reply;
  }

  void set_seq_number(int s) {
    seq_number = s;
  }
};

struct cart_traj_pt_state_message {
  int length;		  /* 4 bytes, constant value should be 14x4 = 56 */
  int message_type;	  /* 4 bytes, constant value 31, CART_TRAJ_PT */
  int comm_type;	  /* 4 bytes, constant value 1, TOPIC */
  int reply_type;	  /* 4 bytes, N/A */
  int seq_number;	  /* 4 bytes, sequence number echo */
  float x, y, z, qx, qy, qz, qw; /* pose, Cartesian and quaternion */
  float translational_speed;	 /* 4 bytes, > 0 */
  float rotational_speed;	 /* 4 bytes, > 0 */
};

/* EXTENSIONS for object location */

struct object_state {
  int id;			/* unique object identifier */
  float x, y, z;		/* Cartesian position */
  float qx, qy, qz, qw;		/* quaternion orientation */
};

struct object_state_message {
  int length;		  /* 4 bytes, constant value should be MxN = XXX */
  int message_type;	  /* 4 bytes, constant value 40, MESSAGE_OBJECT_STATE */
  int comm_type;	  /* 4 bytes, constant value 1, TOPIC */
  int reply_type;	  /* 4 bytes, N/A */
  int seq_number;	  /* 4 bytes, >= 0 */
  object_state *objects;  /* ptr to storage for variable number of objects */
  int number;

  object_state_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      number * sizeof(object_state);
    message_type = MESSAGE_OBJECT_STATE;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
    objects = NULL;
    number = 0;
  }

  object_state_message(int n) {
    number = n;
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      number * sizeof(object_state);
    message_type = MESSAGE_OBJECT_STATE;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
    objects = (object_state *) malloc(n * sizeof(object_state));
  }

  ~object_state_message() {
    if (objects != NULL) free(objects);
  }

  int object_number() {
    return (length - (sizeof(message_type) +
		      sizeof(comm_type) +
		      sizeof(reply_type) +
		      sizeof(seq_number))) / sizeof(object_state);
  }

  void print_object_state(const char *prefix = "") {
    printf("%sLength:     %d\n", prefix, (int) length);
    printf("%sMsg Type:   %d\n", prefix, (int) message_type);
    printf("%sComm Type:  %d\n", prefix, (int) comm_type);
    printf("%sReply Type: %d\n", prefix, (int) reply_type);
    printf("%sSeq Number: %d\n", prefix, (int) seq_number);
    printf("%sObjects:\n", prefix);
    for (int t = 0; t < object_number(); t++) {
      printf("%d : %f %f %f / %f %f %f %f\n", objects[t].id,
	     objects[t].x, objects[t].y, objects[t].z,
	     objects[t].qx, objects[t].qy, objects[t].qz, objects[t].qw);
    }
  }

  int read_object_state(char *inbuf) {
    char *ptr = inbuf;
    int objs;
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
    objs = object_number();
    if (objs <= 0) return -1;
    if (objs > number) {
      number = objs;
      objects = (object_state *) realloc(objects, number * sizeof(object_state));
    }
    memcpy(objects, ptr, number * sizeof(object_state));
    return 0;
  }

  int size() {
    return sizeof(length) +
      sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      number * sizeof(object_state);
  }

  int write_object_state(char *outbuf, int outbuf_len) {
    char *ptr = outbuf;
    memcpy(ptr, &length, sizeof(length));
    ptr += sizeof(length);
    memcpy(ptr, &message_type, sizeof(message_type));
    ptr += sizeof(message_type);
    memcpy(ptr, &comm_type, sizeof(comm_type));
    ptr += sizeof(comm_type);
    memcpy(ptr, &reply_type, sizeof(reply_type));
    ptr += sizeof(reply_type);
    memcpy(ptr, &seq_number, sizeof(seq_number));
    ptr += sizeof(seq_number);
    memcpy(ptr, objects, number * sizeof(object_state));
    return 0;
  }
};

#endif	/* SIMPLE_MESSAGE_DEFS_H */
