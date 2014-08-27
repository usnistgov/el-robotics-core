/*
  RCS execution wrapper around arbitrary programs. Runs as a socket
  server waiting for a single client. Connected clients write
  commands.  Commands are strings formatted like this:

  "<serial number> <program> <args ...>"

  where
  <serial number> is an integer RCS command number,
  <program> is the path to the executable, e.g., "./myprog",
  <args ...> are any arguments to the program

  When a client is connected, status is returned on the socket as is a
  string like this:

  "<echo serial number> {DONE | EXEC | ERROR}"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include <ctype.h>
#include <ulapi.h>

static  bool debug;

typedef struct {
  ulapi_task_struct *task;
  ulapi_integer id;
  double period;
} server_args;

void server_code(void *args)
{
  ulapi_task_struct *task;
  ulapi_integer client_id;
  double period;
  int nchars;
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  int ival;
  int serial_number;
  char *ptr;
  void *process;

  task = ((server_args *) args)->task;
  client_id = ((server_args *) args)->id;
  period = ((server_args *) args)->period;
  free(args);

  for (;;) {
    nchars = ulapi_socket_read(client_id, inbuf, sizeof(inbuf));
    if (-1 == nchars) {
      break;
    }
    if (0 == nchars) {
      break;
    }

    // FIXME -- add parsing and handling of INIT, HALT, and RUN
    printf("got %d chars: ``%s''\n", nchars, inbuf);
    if (1 == ulapi_sscanf(inbuf, "%i", &ival)) {
      ptr = inbuf;
      while (isspace(*ptr)) ptr++; // skip whitespace
      while (!isspace(*ptr) && (0 != *ptr)) ptr++; // skip the number
      while (isspace(*ptr)) ptr++; // skip whitespace
      printf("handling ``%s''\n", ptr);
      if (! strncmp(ptr, "INIT", strlen("INIT"))) {
	printf("INIT\n");
	serial_number = ival;
      } else if (! strncmp(ptr, "HALT", strlen("HALT"))) {
	printf("HALT\n");
	serial_number = ival;
      } else if (! strncmp(ptr, "RUN", strlen("RUN"))) {
	ptr += strlen("RUN");	     // skip over the RUN
	while (isspace(*ptr)) ptr++; // skip whitespace
	process = ulapi_process_new();
	if (ULAPI_OK == ulapi_process_start(process, ptr)) {
	  printf("starting ``%s''\n", ptr);
	  serial_number = ival;
	} else {
	  printf("can't start process\n");
	}
      } else {
	printf("unknown command\n");
      }
    } else {
      printf("can't parse it\n");
    }
    

    // FIXME -- do this periodically, regardless of chars received,
    // as a new thread for this particular thread
    ulapi_socket_write(client_id, inbuf, nchars);
  }

  ulapi_socket_close(client_id);

  printf("server thread done, closed %d\n", client_id);

  ulapi_task_delete(task);

  return;
}

static void print_help()
{
  printf("-d            turn debug on\n");
  printf("-p <period>   set period in seconds\n");
}

int main(int argc, char *argv[])
{
  int retval;
  int option;
  int ival;
  double dval;
  int port;
  double period;
  ulapi_integer socket_id;
  ulapi_integer client_id;
  ulapi_task_struct *task;
  server_args *server_args_ptr;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":p:t:hd");
    if (option == -1)
      break;

    switch (option) {
    case 'p':
      ival = atoi(optarg);
      if (ival < 0) {
	fprintf(stderr, "bad value for port: %s\n", optarg);
	return 1;
      }
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
    }
  }

  ulapi_init();

  socket_id = ulapi_socket_get_server_id_on_interface(port, NULL);
  if (socket_id < 0) {
    fprintf(stderr, "can't serve port %d\n", (int) port);
    return 1;
  }
  printf("serving port %d\n", (int) port);

  for (;;) {
    printf("waiting for client connection...\n");
    client_id = ulapi_socket_get_connection_id(socket_id);
    if (client_id < 0) {
      break;
    }
    printf("got one on fd %d\n", client_id);

    task = ulapi_task_new();

    server_args_ptr = reinterpret_cast<server_args *>(malloc(sizeof(server_args)));
    server_args_ptr->task = task;
    server_args_ptr->id = client_id;
    server_args_ptr->period = period;
    ulapi_task_start(task, server_code, server_args_ptr, ulapi_prio_lowest(), 0);
  }

  return 0;
}
