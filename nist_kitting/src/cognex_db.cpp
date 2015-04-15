/*
  cognex_db.cpp

  Cognex database functions for simulations.
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
#include <nist_kitting/cognex_db.h>

cognex_object_info::cognex_object_info() {
  cognex_object_info("", 0, 0, 0, 0);
}

cognex_object_info::cognex_object_info(const char *_name, double _theta, double _x, double _y, double _confidence)
{
  strncpy(name, _name, sizeof(name)-1);
  name[sizeof(name)-1] = 0;
  theta = _theta;
  x = _x;
  y = _y;
  confidence = _confidence;
}

cognex_object_info_db::cognex_object_info_db()
{
  ulapi_mutex_init(&mutex, 0);
}

cognex_object_info_db::~cognex_object_info_db() {}
  
void cognex_object_info_db::add(int index, cognex_object_info obj)
{
  ulapi_mutex_take(&mutex);
  db[index] = obj;
  ulapi_mutex_give(&mutex);
}

void cognex_object_info_db::remove(int index)
{
  ulapi_mutex_take(&mutex);
  db.erase(db.find(index));
  ulapi_mutex_give(&mutex);
}

void cognex_object_info_db::clear(void)
{
  ulapi_mutex_take(&mutex);
  db.clear();
  ulapi_mutex_give(&mutex);
}

int cognex_object_info_db::size(void)
{
  int retval;
  ulapi_mutex_take(&mutex);
  retval = db.size();
  ulapi_mutex_give(&mutex);
  return retval;
}

int cognex_object_info_db::format(char *str, size_t size)
{
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

void cognex_object_info_db::print(void)
{
  ulapi_mutex_take(&mutex);
  for (std::map<int, cognex_object_info>::iterator iter = db.begin(); iter != db.end(); iter++) {
    printf("%d : %s\n", iter->first, iter->second.name);
  }
  ulapi_mutex_give(&mutex);
}

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
    connection_id = ulapi_socket_get_connection_id(server_id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get a cognex client connection\n");
      break;
    }
     
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
