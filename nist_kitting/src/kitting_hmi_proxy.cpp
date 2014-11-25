/*
  FIXME -- run a single ws_stat subscriber, and update a global WM
  that all the client threads consult and write back to the HMI app.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <string>

#include <ulapi.h>
#include <inifile.h>
#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/ws_cmd.h"
#include "nist_kitting/ws_stat.h"

enum {NODE_NAME_LEN = 80};
#define NODE_NAME_DEFAULT "kitting_hmi_proxy"
enum {PORT_DEFAULT = 1234};

static bool debug = false;

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

struct client_task_args {
  ulapi_task_struct *task;
  int id;
};

static void client_task_code(client_task_args *args)
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

  task = args->task;
  id = args->id;
  free(args);
  
  pub = nh.advertise<nist_kitting::ws_cmd>(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN);

  while (true) {
    nchars = ulapi_socket_read(id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;
    inbuf[sizeof(inbuf)-1] = 0;

    ptr = inbuf;
    // strip off leading and trailing whitespace
    while (isspace(*ptr)) ptr++;
    endptr = ptr + strlen(ptr);
    while (isspace(*endptr)) *endptr-- = 0;
    ulapi_mutex_take(&ws_stat_mutex);

    ws_cmd.cmd.type = KITTING_WS_ASSEMBLE_KIT;
    ws_cmd.assemble_kit.name = std::string(ptr);
    ws_cmd.assemble_kit.quantity = 1;
    ws_cmd.cmd.serial_number = ws_stat_buf.stat.serial_number;
    ws_cmd.cmd.serial_number++;
    pub.publish(ws_cmd);

    ulapi_mutex_give(&ws_stat_mutex);
  }

  ulapi_socket_close(id);

  if (debug) printf("client handler %d done\n", id);

  ulapi_task_delete(task);

  return;
}

static int ini_load(char *inifile_name, int *port)
{
  FILE *fp;
  const char *section;
  const char *key;
  const char *inistring;
  int i1;

  if (NULL == (fp = fopen(inifile_name, "r"))) {
    fprintf(stderr, "can't open ini file %s\n", inifile_name);
    return 1;
  }

  if (PORT_DEFAULT == *port) {
    /* no argument overrode it, so we'll look for it */
    section = NULL;
    key = "SOCKET_PORT";
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

/*
  Usage: <args> {-- <ROS args>}

  Args:
  -p <#>    -- socket port to serve for HMI application
  -i <file> -- ini file to use for socket port
  -d        -- turn debug printing on
*/

int main(int argc, char *argv[])
{
  int ros_argc;
  char **ros_argv;
  char node_name[NODE_NAME_LEN] = NODE_NAME_DEFAULT;
  enum {BUFFERLEN = 256};
  char inifile_name[BUFFERLEN] = "";
  int option;
  int ival;
  int port = PORT_DEFAULT;
  int server_id;
  int connection_id;
  ulapi_task_struct *client_task;
  client_task_args *client_args; 
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":i:p:d");
    if (option == -1) break;

    switch (option) {
    case 'i':
      strncpy(inifile_name, optarg, sizeof(inifile_name));
      inifile_name[sizeof(inifile_name)-1] = 0;
      break;

    case 'p':
      ival = atoi(optarg);
      port = ival;
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

  if (0 != *inifile_name) {
    if (0 != ini_load(inifile_name, &port)) {
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
    connection_id = ulapi_socket_get_connection_id(server_id);
    if (connection_id < 0) break;

    if (debug) printf("waiting for joint state connection...\n");
    connection_id = ulapi_socket_get_connection_id(server_id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get a joint state connection connectons\n");
      break;
    }
     
    if (debug) printf("got a joint state connection on id %d\n", connection_id);

    // spawn a connection task
    client_task = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*client_task)));
    client_args = reinterpret_cast<client_task_args *>(malloc(sizeof(*client_args)));

    ulapi_task_init(client_task);
    client_args->task = client_task;
    client_args->id = connection_id;
    ulapi_task_start(client_task, reinterpret_cast<ulapi_task_code>(client_task_code), reinterpret_cast<void *>(client_args), ulapi_prio_highest(), 0);
  } // while (true)

  ulapi_socket_close(server_id);

  if (debug) printf("server on %d done\n", server_id);
  
  return 0;
}
