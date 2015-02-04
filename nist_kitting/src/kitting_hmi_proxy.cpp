/*
  FIXME -- run a single ws_stat subscriber, and update a global WM
  that all the client threads consult and write back to the HMI app.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

#include <string>

#include <ulapi.h>
#include <inifile.h>

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/ws_cmd.h"
#include "nist_kitting/ws_stat.h"

#define NODE_NAME_DEFAULT "kitting_hmi_proxy"
enum {PORT_DEFAULT = 1234};

static bool debug = false;

static std::string inifile_name("");

/*
  The Workstation status structure, written by the ROS callback
  on the subscribed topic, and read by the handlers for connected
  HMI clients to return WS status to them.
*/

static ulapi_mutex_struct ws_stat_mutex;
static nist_kitting::ws_stat ws_stat_buf;

static void ws_stat_callback(const nist_kitting::ws_stat::ConstPtr& msg)
{
  ulapi_mutex_take(&ws_stat_mutex);
  ws_stat_buf = *msg;
  ulapi_mutex_give(&ws_stat_mutex);
}

struct client_read_task_args {
  ulapi_task_struct *task;
  int id;
};

static void client_read_task_code(client_read_task_args *args)
{
  ulapi_task_struct *task;
  int id;
  enum {INBUF_SIZE = 1024};
  char inbuf[INBUF_SIZE];
  char *ptr;
  char *endptr;
  int nchars;
  ros::NodeHandle nh;
  ros::Publisher pub;
  nist_kitting::ws_cmd ws_cmd;
  int serial_number = 1;

  task = args->task;
  id = args->id;
  free(args);
  
  pub = nh.advertise<nist_kitting::ws_cmd>(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN);

  while (true) {
    nchars = ulapi_socket_read(id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;
    if (nchars < sizeof(inbuf)) inbuf[nchars] = 0;
    else inbuf[sizeof(inbuf)-1] = 0;

    ptr = inbuf;
    // strip off leading and trailing whitespace
    while (isspace(*ptr)) ptr++;
    endptr = ptr + strlen(ptr);
    while (isspace(*endptr)) *endptr-- = 0;
    ulapi_mutex_take(&ws_stat_mutex);

    ws_cmd.cmd.type = KITTING_WS_ASSEMBLE_KIT;
    ws_cmd.assemble_kit.name = std::string(ptr);
    ws_cmd.assemble_kit.quantity = 1;
    ws_cmd.cmd.serial_number = serial_number++;
    pub.publish(ws_cmd);

    ulapi_mutex_give(&ws_stat_mutex);
  }

  ulapi_socket_close(id);

  if (debug) printf("client read handler %d done\n", id);

  ulapi_task_delete(task);

  return;
}

struct client_write_task_args {
  ulapi_task_struct *task;
  int id;
  int period_nsecs;
};

static void client_write_task_code(client_write_task_args *args)
{
  ulapi_task_struct *task;
  int id;
  int period_nsecs;
  enum {OUTBUF_SIZE = 1024};
  char outbuf[OUTBUF_SIZE];
  int nchars;
  nist_kitting::ws_stat ws_stat;

  task = args->task;
  id = args->id;
  period_nsecs = args->period_nsecs;
  free(args);

  while (true) {
    ros::spinOnce();
    ulapi_mutex_take(&ws_stat_mutex);
    ws_stat = ws_stat_buf;
    ulapi_mutex_give(&ws_stat_mutex);

    /*
      uint8 type
      uint8 serial_number
      uint8 state
      uint8 status
      uint8 heartbeat
      float32 period
      float32 cycle
      float32 duration

      extern char *kitting_cmd_to_string(int s);
      extern char *rcs_state_to_string(int s);
      extern char *rcs_status_to_string(int s);
    */

    ulapi_snprintf(outbuf, sizeof(outbuf), "%s %d %s %s %d\n",
		   kitting_cmd_to_string(ws_stat.stat.type),
		   ws_stat.stat.serial_number,
		   rcs_state_to_string(ws_stat.stat.state),
		   rcs_status_to_string(ws_stat.stat.status),
		   ws_stat.stat.heartbeat);
    outbuf[sizeof(outbuf)-1] = 0;
    nchars = ulapi_socket_write(id, outbuf, strlen(outbuf));
    if (nchars <= 0) break;

    ulapi_wait(period_nsecs);
  }

  ulapi_socket_close(id);

  if (debug) printf("client write handler %d done\n", id);

  ulapi_task_delete(task);

  return;
}

static int ini_load(const std::string inifile_name,
		    int *port)
{
  FILE *fp;
  const char *section;
  const char *key;
  const char *inistring;
  int i1;

  if (NULL == (fp = fopen(inifile_name.c_str(), "r"))) {
    fprintf(stderr, "can't open ini file %s\n", inifile_name.c_str());
    return 1;
  }

  if (PORT_DEFAULT == *port) {
    /* no argument overrode it, so we'll look for it */
    section = "hmi";
    key = "port";
    inistring = ini_find(fp, key, section);

    if (NULL == inistring) {
      fprintf(stderr, "missing ini file entry: %s\n", key);
      fclose(fp);
      return 1;
    } else if (1 != sscanf(inistring, "%i", &i1)) {
      fprintf(stderr, "gosh: bad entry: %s = %s\n", key, inistring);
      fclose(fp);
      return 1;
    }
    *port = i1;
  }

  fclose(fp);
  return 0;
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -i <file>    : set the ini file name\n");
  printf("  -n <name>    : set the node name\n");
  printf("  -p <#>       : socket port to serve for HMI application\n");
  printf("  -t <secs>    : period between status writes, in seconds\n");
  printf("  -h           : print this help\n");
  printf("  -d           : turn debug on\n");
}

int main(int argc, char *argv[])
{
  int ros_argc;
  char **ros_argv;
  std::string node_name(NODE_NAME_DEFAULT);
  int option;
  int ival;
  double dval;
  int port = PORT_DEFAULT;
  double period = 1;
  int server_id;
  int connection_id;
  ulapi_task_struct *client_read_task;
  client_read_task_args *client_read_args; 
  ulapi_task_struct *client_write_task;
  client_write_task_args *client_write_args; 
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":i:n:p:t:hd");
    if (option == -1) break;

    switch (option) {
    case 'i':
      inifile_name = std::string(optarg);
      break;

    case 'n':
      // first check for valid name
      if (optarg[0] == '-') {
	fprintf(stderr, "invalid node name: %s\n", optarg);
	return 1;
      }
      node_name = std::string(optarg);
      break;

    case 'p':
      ival = atoi(optarg);
      port = ival;
      break;

    case 't':
      dval = atof(optarg);
      if (dval < FLT_EPSILON) {
	fprintf(stderr, "bad value for period: %s\n", optarg);
	return 1;
      }
      period = dval;
      break;

    case 'h':
      print_help();
      break;

    case 'd':
      debug = true;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", optopt);
      return 1;
      break;

    default:
      fprintf (stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    } // switch (option)
  }   // while (true) for getopt

  if (ULAPI_OK != ulapi_init()) {
    fprintf(stderr, "can't init ulapi\n");
    return 1;
  }

  if (! inifile_name.empty()) {
    if (0 != ini_load(inifile_name, &port)) {
      fprintf(stderr, "error reading ini file %s\n", inifile_name.c_str());
      return 1;
    }
  }

  ulapi_mutex_init(&ws_stat_mutex, 1);

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];
  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle nh;
  ros::Subscriber sub;
  sub = nh.subscribe(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN, ws_stat_callback);

  server_id = ulapi_socket_get_server_id(port);
  if (server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", port);
    return 1;
  }

  bool done = false;
  while (! done) {
    if (debug) printf("waiting for an HMI connection...\n");
    connection_id = ulapi_socket_get_connection_id(server_id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get an HMI connection\n");
      break;
    }
     
    if (debug) printf("got an HMI connection on id %d\n", connection_id);

    // spawn connection tasks for reading and writing

    client_read_task = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*client_read_task)));
    client_read_args = reinterpret_cast<client_read_task_args *>(malloc(sizeof(*client_read_args)));

    ulapi_task_init(client_read_task);
    client_read_args->task = client_read_task;
    client_read_args->id = connection_id;
    ulapi_task_start(client_read_task, reinterpret_cast<ulapi_task_code>(client_read_task_code), reinterpret_cast<void *>(client_read_args), ulapi_prio_highest(), 0);

    client_write_task = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*client_write_task)));
    client_write_args = reinterpret_cast<client_write_task_args *>(malloc(sizeof(*client_write_args)));

    ulapi_task_init(client_write_task);
    client_write_args->task = client_write_task;
    client_write_args->id = connection_id;
    client_write_args->period_nsecs = (int) (period * 1.0e9);
    ulapi_task_start(client_write_task, reinterpret_cast<ulapi_task_code>(client_write_task_code), reinterpret_cast<void *>(client_write_args), ulapi_prio_highest(), 0);

  } // while (true)

  ulapi_socket_close(server_id);

  if (debug) printf("server on %d done\n", server_id);
  
  return 0;
}
