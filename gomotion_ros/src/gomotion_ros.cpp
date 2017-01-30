#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include <ulapi.h>
#include <inifile.h>
#include <go.h>
#include <trajintf.h>

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

#define NODE_NAME "gomotion_ros"

static int debug = 0;

#define MIN_CYCLE_TIME 1.0e-3
#define CONNECT_WAIT_TIME 3.0

#define JOINT_NAME_LEN 32

static int ini_load(char *inifile_name, int *traj_shm_key, double *traj_cycle_time, char servo_name[SERVO_NUM][JOINT_NAME_LEN])
{
  FILE *fp;
  const char *section;
  const char *key;
  const char *inistring;
  char servo_section[INIFILE_MAX_LINELEN];
  int t;

  if (NULL == (fp = fopen(inifile_name, "r"))) {
    fprintf(stderr, "can't open %s\n", inifile_name);
    return 1;
  }

  section = "TRAJ";

  key = "SHM_KEY";

  inistring = ini_find(fp, key, section);
  if (NULL == inistring) {
    fprintf(stderr, "missing entry: [%s] %s\n", section, key);
    fclose(fp);
    return 1;
  } else if (1 != sscanf(inistring, "%i", traj_shm_key)) {
    fprintf(stderr, "bad entry: [%s] %s = %s\n", section, key, inistring);
    fclose(fp);
    return 1;
  }

  key = "CYCLE_TIME";

  inistring = ini_find(fp, key, section);
  if (NULL == inistring) {
    fprintf(stderr, "missing entry: [%s] %s\n", section, key);
    fclose(fp);
    return 1;
  } else if (1 != sscanf(inistring, "%lf", traj_cycle_time)) {
    fprintf(stderr, "bad entry: [%s] %s = %s\n", section, key, inistring);
    fclose(fp);
    return 1;
  } else if (*traj_cycle_time < MIN_CYCLE_TIME) {
    fprintf(stderr, "entry out of range: [%s] %s = %s\n", section, key, inistring);
    fclose(fp);
    return 1;
  }

  for (t = 0; t < SERVO_NUM; t++) {
    snprintf(servo_section, sizeof(servo_section), "SERVO_%d", t+1);
    servo_section[sizeof(servo_section)-1] = 0;
    section = servo_section;

    key = "NAME";
    inistring = ini_find(fp, key, section);
    if (NULL == inistring) {
      servo_name[t][0] = 0;
    } else {
      strncpy(servo_name[t], inistring, sizeof(servo_name[t]));
    }
    servo_name[t][sizeof(servo_name[t])-1] = 0;
  }

  fclose(fp);
  return 0;
}

int main(int argc, char **argv)
{
  int option;
  enum {BUFFERLEN = 256};
  char inifile_name[BUFFERLEN] = "gomotion.ini";
  int traj_shm_key = 1;
  double traj_cycle_time = 1;
  char joint_name[SERVO_NUM][JOINT_NAME_LEN];
  void *traj_shm = NULL;
  traj_comm_struct *traj_comm_ptr;
  traj_stat_struct pp_traj_stat[2], *traj_stat_ptr, *traj_stat_test, *traj_stat_tmp;
  int start_it;
  int got_it;
  double end;
  int heartbeat;
  int ros_argc;
  char **ros_argv;
  const char *node_name = NODE_NAME;
  sensor_msgs::JointState joint_state;

  if (ULAPI_OK != ulapi_init()) {
    return 1;
  } 

  opterr = 0;
  while (1) {
    option = ulapi_getopt(argc, argv, ":i:d");
    if (option == -1)
      break;

    switch (option) {
    case 'i':
      strncpy(inifile_name, ulapi_optarg, BUFFERLEN);
      inifile_name[BUFFERLEN - 1] = 0;
      break;

    case 'd':
      debug = 1;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", ulapi_optopt);
      return 1;
      break;

    default:			/* '?' */
      fprintf (stderr, "unrecognized option -%c\n", ulapi_optopt);
      return 1;
      break;
    }
  }
  // everything else goes as args to ROS

  if (0 != ini_load(inifile_name, &traj_shm_key, &traj_cycle_time, joint_name)) {
    return 1;
  }

  if (go_init()) {
    fprintf(stderr, "go_init error\n");
    return 1;
  }

  // get traj shared memory buffers
  traj_shm = ulapi_rtm_new(traj_shm_key, sizeof(traj_comm_struct));
  if (NULL == traj_shm) {
    fprintf(stderr, "can't get traj comm shm\n");
    return 1;
  }
  traj_comm_ptr = static_cast<traj_comm_struct *>(ulapi_rtm_addr(traj_shm));
  // set up ping-pong buffers
  traj_stat_ptr = &pp_traj_stat[0];
  traj_stat_test = &pp_traj_stat[1];
  // check for running traj
  for (start_it = 0, got_it = 0, end = ulapi_time() + CONNECT_WAIT_TIME;
       ulapi_time() < end;
       ulapi_sleep(0.1)) {
    *traj_stat_ptr = traj_comm_ptr->traj_stat;
    if (traj_stat_ptr->head == traj_stat_ptr->tail &&
	traj_stat_ptr->type == TRAJ_STAT_TYPE) {
      if (! start_it) {
	start_it = 1;
	heartbeat = traj_stat_ptr->heartbeat;
      }
      if (heartbeat != traj_stat_ptr->heartbeat) {
	got_it = 1;
	break;
      }
    }
  }
  if (! got_it) {
    fprintf(stderr, "timed out connecting to traj status\n");
    return 1;
  }

  ros_argc = argc - optind;
  ros_argv = &argv[optind];

  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle n;
  ros::Publisher joint_state_pub = n.advertise<sensor_msgs::JointState>(std::string(NODE_NAME) + std::string("/joint_states"), 1);

  ros::Rate loop_rate(1.0 / traj_cycle_time);

  joint_state.name.resize(SERVO_NUM);
  joint_state.position.resize(SERVO_NUM);
  for (int t = 0; t < SERVO_NUM; t++) {
    joint_state.name[t] = joint_name[t];
    joint_state.position[t] = t;
  }

  while (ros::ok()) {
    // read in traj status and settings, ping-pong style
    *traj_stat_test = traj_comm_ptr->traj_stat;
    if (traj_stat_test->head == traj_stat_test->tail) {
      traj_stat_tmp = traj_stat_ptr;
      traj_stat_ptr = traj_stat_test;
      traj_stat_test = traj_stat_tmp;
    }

    joint_state.header.stamp = ros::Time::now();
    for (int t = 0; t < SERVO_NUM; t++) {
      joint_state.position[t] = traj_stat_ptr->joints[t];
    }
    joint_state_pub.publish(joint_state);

    loop_rate.sleep();
  }

  go_exit();
  ulapi_exit();

  return 0;
}
