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

static bool debug;

typedef struct {
  ulapi_task_struct *server_task;
  ulapi_integer client_id;
  double period;
} server_args;

typedef enum {CMD_INIT, CMD_RUN, CMD_HALT} command_type;
typedef enum {EXEC_DONE, EXEC_EXEC, EXEC_ERROR} exec_type;

typedef struct {
  ulapi_task_struct *status_task;
  ulapi_integer client_id;
  double period;
  int serial_number;
  command_type command;
  exec_type exec;
  int heartbeat;
  void *process;
} status_args;

void status_code(void *args)
{
  status_args *status = reinterpret_cast<status_args *>(args);
  ulapi_integer result;
  enum {BUFFERLEN = 256};
  char outbuf[BUFFERLEN];
  int nchars;

  status->heartbeat = 0;

  if (debug) printf("%d\n", status->client_id);

  for (;;) {
    if (CMD_INIT == status->command) {
      if (NULL != status->process) {
	ulapi_process_stop(status->process);
	status->process = NULL;
      }
      status->exec = EXEC_DONE;
    } else if (CMD_HALT == status->command) {
      if (NULL != status->process) {
	ulapi_process_stop(status->process);
	status->process = NULL;
      }
      status->exec = EXEC_DONE;
    } else if (CMD_RUN == status->command) {
      if (NULL != status->process) {
	if (ulapi_process_done(status->process, &result)) {
	  if (0 == result) {
	    status->exec = (result ? EXEC_ERROR :  EXEC_DONE);
	  }
	  status->process = NULL;
	} else {
	}
      } else {
	// unknown command
      }
    }

    /*
      A string something like:
      123 INIT DONE
      456 RUN EXEC
    */
    ulapi_snprintf(outbuf, sizeof(outbuf), "%d %s %s %d",
		   status->serial_number,
		   CMD_INIT == status->command ? "INIT" :
		   CMD_RUN == status->command ? "RUN" :
		   CMD_HALT == status->command ? "HALT" : "?",
		   EXEC_DONE == status->exec ? "DONE" :
		   EXEC_EXEC == status->exec ? "EXEC" :
		   EXEC_ERROR == status->exec ? "ERROR" : "?",
		   status->heartbeat);
    outbuf[sizeof(outbuf)-1] = 0;
    nchars = ulapi_socket_write(status->client_id, outbuf, strlen(outbuf)+1);
    if (nchars < 0) break;
    status->heartbeat++;
    ulapi_wait(status->period * 1e9);
  } // for (;;)

  return;
}

void server_code(void *args)
{
  ulapi_task_struct *server_task;
  ulapi_integer client_id;
  double period;
  int nchars;
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  int ival;
  char *ptr;
  ulapi_task_struct *status_task;
  status_args status;
  void *process;

  // copy in our args
  server_task = ((server_args *) args)->server_task;
  client_id = ((server_args *) args)->client_id;
  period = ((server_args *) args)->period;
  free(args);

  // start a status task for this connection
  status.status_task = ulapi_task_new();
  status.client_id = client_id;
  status.period = period;
  status.serial_number = 1;
  status.command = CMD_INIT;
  status.process = NULL;	// this will be filled in after RUNs below
  status_task = ulapi_task_new();
  ulapi_task_start(status_task, status_code, &status, ulapi_prio_lowest(), 0);

  // read commands for this connection
  for (;;) {
    nchars = ulapi_socket_read(client_id, inbuf, sizeof(inbuf));
    if (-1 == nchars) {
      break;
    }
    if (0 == nchars) {
      break;
    }

    if (debug) printf("got %d chars: ``%s''\n", nchars, inbuf);

    if (1 == ulapi_sscanf(inbuf, "%i", &ival)) {
      ptr = inbuf;
      while (isspace(*ptr)) ptr++; // skip whitespace
      while (!isspace(*ptr) && (0 != *ptr)) ptr++; // skip the number
      while (isspace(*ptr)) ptr++; // skip whitespace
      printf("handling ``%s''\n", ptr);
      if (! strncmp(ptr, "INIT", strlen("INIT"))) {
	if (debug) printf("INIT\n");
	status.serial_number = ival;
	status.command = CMD_INIT;
	status.exec = EXEC_EXEC;
      } else if (! strncmp(ptr, "HALT", strlen("HALT"))) {
	if (debug) printf("HALT\n");
	status.serial_number = ival;
	status.command = CMD_HALT;
	status.exec = EXEC_EXEC;
      } else if (! strncmp(ptr, "RUN", strlen("RUN"))) {
	ptr += strlen("RUN");	     // skip over the RUN
	while (isspace(*ptr)) ptr++; // skip whitespace
	process = ulapi_process_new();
	if (ULAPI_OK == ulapi_process_start(process, ptr)) {
	  if (debug) printf("starting ``%s''\n", ptr);
	  status.serial_number = ival;
	  status.command = CMD_RUN;
	  status.exec = EXEC_EXEC;
	  status.process = process;
	} else {
	  printf("can't start process\n");
	}
      } else {
	printf("unknown command\n");
      }
    } else {
      printf("can't parse it\n");
    }
  }

  ulapi_socket_close(client_id);

  printf("server thread done, closed %d\n", client_id);

  ulapi_task_delete(server_task);

  return;
}

static void print_help()
{
  printf("-p <port>     set TCP port to serve\n");
  printf("-t <time>     set period in seconds\n");
  printf("-h            print help\n");
  printf("-d            turn debug on\n");
}

int main(int argc, char *argv[])
{
  int retval;
  int option;
  int ival;
  double dval;
  int port;
  double period = 1;
  ulapi_integer socket_id;
  ulapi_integer client_id;
  ulapi_task_struct *server_task;
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

    server_task = ulapi_task_new();

    server_args_ptr = reinterpret_cast<server_args *>(malloc(sizeof(server_args)));
    server_args_ptr->server_task = server_task;
    server_args_ptr->client_id = client_id;
    server_args_ptr->period = period;
    ulapi_task_start(server_task, server_code, server_args_ptr, ulapi_prio_lowest(), 0);
  }

  return 0;
}
