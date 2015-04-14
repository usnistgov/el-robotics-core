/*
  simple_message_to_cognex.cpp

  Connects to the Simple Message object server, and converts object
  messages to Cognex format for each connected client.
 */

#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof, size_t */
#include <stdlib.h>		/* atoi, atof */
#include <string.h>
#include <ctype.h>

#include <iostream>
#include <map>
#include <string>

#include <ulapi.h>

#include "simple_message_defs.h"

bool debug = false;

enum {
  COGNEX_PORT_DEFAULT = 1456
};

struct cognex_object_info {
  enum {OBJECT_NAME_LEN = 80};
  char name[OBJECT_NAME_LEN];
  double theta;
  double x;
  double y;
  double confidence;

  cognex_object_info() {
    cognex_object_info("", 0, 0, 0, 0);
  }

  cognex_object_info(const char *_name, double _theta, double _x, double _y, double _confidence) {
    strncpy(name, _name, sizeof(name)-1);
    name[sizeof(name)-1] = 0;
    theta = _theta;
    x = _x;
    y = _y;
    confidence = _confidence;
  }
};

struct compare_int {
  bool operator() (int i1, int i2) const { return i1 < i2; }
};

class cognex_object_info_db {
public:
  cognex_object_info_db() {
    ulapi_mutex_init(&mutex, 0);
  }

  ~cognex_object_info_db() {
  }

  void add(int index, cognex_object_info obj) {
    ulapi_mutex_take(&mutex);
    db[index] = obj;
    ulapi_mutex_give(&mutex);
  }

  void remove(int index) {
    ulapi_mutex_take(&mutex);
    db.erase(db.find(index));
    ulapi_mutex_give(&mutex);
  }

  void clear(void) {
    ulapi_mutex_take(&mutex);
    db.clear();
    ulapi_mutex_give(&mutex);
  }

  int size(void) {
    int retval;
    ulapi_mutex_take(&mutex);
    retval = db.size();
    ulapi_mutex_give(&mutex);
    return retval;
  }

  int format(char *str, size_t size) {
    cognex_object_info object_info_in;
    size_t retval;
    std::string sstr;

    ulapi_mutex_take(&mutex);
    for (std::map<int, cognex_object_info>::iterator iter = db.begin(); iter != db.end(); iter++) {
      retval = ulapi_snprintf(str, size, "%s,%f,%f,%f,%f",
			      iter->second.name,
			      iter->second.theta,
			      iter->second.x,
			      iter->second.y,
			      iter->second.confidence);
      if (iter == db.begin()) {
	sstr = str;
      } else {
	sstr += ",";
	sstr += str;
      }
    }
    ulapi_mutex_give(&mutex);

    sstr += "\n";

    strncpy(str, sstr.c_str(), size);
    str[size-1] = 0;

    return 0;
  }

  void print(void) {
    ulapi_mutex_take(&mutex);
    for (std::map<int, cognex_object_info>::iterator iter = db.begin(); iter != db.end(); iter++) {
      printf("%d : %s\n", iter->first, iter->second.name);
    }
    ulapi_mutex_give(&mutex);
  }

  ulapi_task_struct *serve(int port, int period_nsecs);

private:
  std::map<int, cognex_object_info, compare_int> db;
  ulapi_mutex_struct mutex;
};

struct cognex_client_task_args {
  ulapi_task_struct *task;
  int connection_id;
  int period_nsecs;
  cognex_object_info_db *db;
};

static void cognex_client_task_code(cognex_client_task_args *args)
{
  ulapi_task_struct *task = args->task;
  int connection_id = args->connection_id;
  int period_nsecs = args->period_nsecs;
  cognex_object_info_db *db = args->db;
  enum {MSG_LEN = 1024};
  char msg[MSG_LEN];

  free(args);

  while (true) {
    db->format(msg, sizeof(msg)-1);
    if (ulapi_socket_write(connection_id, msg, strlen(msg)) < 0) break;
    ulapi_wait(period_nsecs);
  }

  ulapi_socket_close(connection_id);

  if (debug) printf("cognex client write handler %d done\n", connection_id);

  ulapi_task_delete(task);

  return;
}

struct cognex_server_task_args {
  ulapi_task_struct *task;
  int server_id;
  int period_nsecs;
  cognex_object_info_db *db;
};

static void cognex_server_task_code(cognex_server_task_args *args)
{
  ulapi_task_struct *task = args->task;
  int server_id = args->server_id;
  int period_nsecs = args->period_nsecs;
  cognex_object_info_db *db = args->db;
  int connection_id;
  ulapi_task_struct *client_task;
  cognex_client_task_args *client_args;

  free(args);

  while (true) {
    if (debug) printf("waiting for a cognex connection on %d...\n", server_id);
    connection_id = ulapi_socket_get_connection_id(server_id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get a cognex client connection\n");
      break;
    }
     
    if (debug) printf("got a cognex connection on id %d\n", connection_id);

    client_task = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*client_task)));
    client_args = reinterpret_cast<cognex_client_task_args *>(malloc(sizeof(*client_args)));

    ulapi_task_init(client_task);
    client_args->task = client_task;
    client_args->connection_id = connection_id;
    client_args->period_nsecs = period_nsecs;
    client_args->db = db;
    ulapi_task_start(client_task, reinterpret_cast<ulapi_task_code>(cognex_client_task_code), reinterpret_cast<void *>(client_args), ulapi_prio_highest(), 0);
  }

  ulapi_socket_close(server_id);

  if (debug) printf("cognex server on %d done\n", server_id);

  ulapi_task_delete(task);

  return;
}

ulapi_task_struct *cognex_object_info_db::serve(int port, int period_nsecs)
{
  ulapi_integer server_id;
  ulapi_task_struct *server_task;
  cognex_server_task_args *server_args;

  server_id = ulapi_socket_get_server_id(port);
  if (server_id < 0) {
    return NULL;
  }

  server_task = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*server_task)));
  server_args = reinterpret_cast<cognex_server_task_args *>(malloc(sizeof(*server_args)));

  ulapi_task_init(server_task);
  server_args->task = server_task;
  server_args->server_id = server_id;
  server_args->period_nsecs = period_nsecs;
  server_args->db = this;
  ulapi_task_start(server_task, reinterpret_cast<ulapi_task_code>(cognex_server_task_code), reinterpret_cast<void *>(server_args), ulapi_prio_highest(), 0);

  return server_task;
}

/*
  Arguments:

  -h <name> -- host computer running simple message server
  -s <#>    -- simple message state socket port
  -p <#>    -- port number to server up for Cognex connections
  -t <#>    -- time period to send out Cognex data
  -d        -- turn debug printing on
*/

int main(int argc, char *argv[])
{
  enum {HOST_LEN = 256};
  char host[HOST_LEN] = "localhost";
  int state_port = STATE_PORT_DEFAULT;
  int cognex_port = COGNEX_PORT_DEFAULT;
  double period = 1;
  int option;
  int ival;
  double dval;
  int state_client_id;
  ulapi_task_struct cognex_client_thread;
  cognex_object_info_db db;
  ulapi_task_struct *server_task;
  ulapi_integer retval;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":h:s:p:t:d");
    if (option == -1) break;

    switch (option) {
    case 'h':
      strncpy(host, optarg, sizeof(host));
      host[sizeof(host)-1] = 0;
      break;

    case 's':
      ival = atoi(optarg);
      state_port = ival;
      break;

    case 'p':
      ival = atoi(optarg);
      cognex_port = ival;
      break;

    case 't':
      dval = atof(optarg);
      period = dval;
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

#undef TESTING
#ifdef TESTING
  db.add(1, cognex_object_info("alice", 0.4, 1.2, 3.4, 0.95));
  db.print();

  db.add(1, cognex_object_info("bob", -0.4, -1.2, -3.4, -0.95));
  db.add(2, cognex_object_info("carol", 0.57808, 123.45, -234.56, 0.99));
  db.print();

  db.remove(1);
  db.print();
  db.add(3, cognex_object_info("david", 1, 2, 3, 1));

  return 0;
#endif

  // connect to state server
  state_client_id = ulapi_socket_get_client_id(state_port, host);
  if (state_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, state_port);
    return 1;
  }

  server_task = db.serve(cognex_port, period * 1e9);
  if (server_task == NULL) {
    fprintf(stderr, "can't server port %d\n", cognex_port);
    return 1;
  }

  while (true) {
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    int nchars;
    int nleft;
    int length;
    int message_type;
    object_state_message obj_state;

    nchars = ulapi_socket_read(state_client_id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;
    inbuf[sizeof(inbuf)-1] = 0;
    ptr = inbuf;
    nleft = nchars;

    while (nleft > 0) {
      // get the length and type of the message
      memcpy(&length, ptr, sizeof(length));
      memcpy(&message_type, ptr + sizeof(length), sizeof(message_type));

      // switch on the message type and handle it
      switch (message_type) {
      case MESSAGE_ROBOT_STATUS:
      case MESSAGE_JOINT_POSITION:
	break;

      case MESSAGE_OBJECT_STATE:
	if (0 == obj_state.read_object_state(ptr)) {
	  if (debug) obj_state.print_object_state();
	  for (int t = 0; t < obj_state.number; t++) {
	    db.add(obj_state.objects[t].id, cognex_object_info("FIXME", 0.5708, obj_state.objects[t].x, obj_state.objects[t].y, 0.95));
	  }
	}
	break;

      default:
	// unknown message
	break;
      } // switch (message type)
      nleft -= (sizeof(length) + length);
      ptr += (sizeof(length) + length);
    } // while (nleft)
  }   // while (true)

  ulapi_task_join(server_task, &retval);

  return 0;
}
