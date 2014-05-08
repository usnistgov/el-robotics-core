/*
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*/

/*!
  \file sockettest.c

  \brief Tests client and server socket communication.
*/

#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* malloc, free, atoi */
#include <string.h>		/* strncpy, strlen */
#include "ulapi.h"

typedef struct {
  void * task;
  ulapi_integer id;
} server_args;

void server_code(void * args)
{
  void * task;
  ulapi_integer client_id;
  ulapi_integer nchars;
  enum {BUFFERLEN = 80};
  char inbuf[BUFFERLEN];

  task = ((server_args *) args)->task;
  client_id = ((server_args *) args)->id;

  for (;;) {
    nchars = ulapi_socket_read(client_id, inbuf, sizeof(inbuf));
    if (-1 == nchars) {
      break;
    }
    if (0 == nchars) {
      break;
    }
    printf("got %d chars: ``%s''\n", nchars, inbuf);
    ulapi_socket_write(client_id, inbuf, nchars);
  }

  ulapi_socket_close(client_id);

  printf("server thread done, closed %d\n", client_id);

  ulapi_task_delete(task);
  free(args);

  return;
}

int main(int argc, char *argv[])
{
  enum {BUFFERLEN = 80};
  int option;
  int is_client;
  int is_broadcastee;
  ulapi_integer port;
  ulapi_integer socket_id;
  ulapi_integer client_id;
  ulapi_integer broadcast_id;
  ulapi_integer nchars;
  char host[BUFFERLEN] = "localhost";
  char intf[BUFFERLEN] = "localhost";
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  char *intfptr;
  char *ptr;
  void *task;
  server_args * server_args_ptr;

  intfptr = NULL;
  opterr = 0;
  is_client = 0;	 /* start as server unless host is provided */
  is_broadcastee = 0;	 /* client reads as usual, not broadcast port */
  port = -1;		 /* start with invalid port number */

  for (;;) {
    option = getopt(argc, argv, ":p:h:i:b");
    if (option == -1)
      break;

    switch (option) {
    case 'p':
      port = atoi(optarg);
      break;

    case 'h':
      strncpy(host, optarg, sizeof(host));
      host[sizeof(host) - 1] = 0;
      is_client = 1;
      break;

    case 'i':
      strncpy(intf, optarg, sizeof(intf));
      intf[sizeof(intf) - 1] = 0;
      intfptr = intf;
      break;

    case 'b':
      is_client = 1;
      is_broadcastee = 1;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", optopt);
      return 1;
      break;

    default:			/* '?' */
      fprintf(stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    }
  }
  if (optind < argc) {
    fprintf(stderr, "extra non-option characters: %s\n", argv[optind]);
    return 1;
  }

  if (port < 0) {
    fprintf(stderr, "need a port\n");
    return 1;
  }

  if (ULAPI_OK != ulapi_init()) {
    fprintf(stderr, "ulapi_init error\n");
    return 1;
  }

  if (is_client) {
    if (is_broadcastee) {
      socket_id = ulapi_socket_get_broadcastee_id_on_interface(port, intfptr);
      if (socket_id < 0) {
	fprintf(stderr, "can't connect to %s:%d\n", host, (int) port);
	ulapi_exit();
	return 1;
      } else {
	printf("listening to broadcasts on port %d\n", (int) port);
      }
    } else {
      socket_id = ulapi_socket_get_client_id(port, host);
      if (socket_id < 0) {
	fprintf(stderr, "can't connect to %s on port %d\n", host, (int) port);
	ulapi_exit();
	return 1;
      } else {
	printf("connected to %s on port %d\n", host, (int) port);
      }
    }

    for (;;) {
      if (! is_broadcastee) {
	if (NULL == fgets(outbuf, sizeof(outbuf), stdin)) {
	  break;
	}
	for (ptr = outbuf; *ptr != '\n' && *ptr != 0; ptr++); *ptr = 0;
	nchars = ulapi_socket_write(socket_id, outbuf, ptr-outbuf+1);
	printf("wrote %d chars\n", nchars);
      }
      nchars = ulapi_socket_read(socket_id, inbuf, sizeof(inbuf)-1);
      if (-1 == nchars) {
	fprintf(stderr, "connection closed\n");
	break;
      }
      if (0 == nchars) {
	fprintf(stderr, "end of file\n");
	break;
      }
      inbuf[nchars] = 0;
      printf("read %d chars: ``%s''\n", nchars, inbuf);
    }
  } else {
    socket_id = ulapi_socket_get_server_id_on_interface(port, intfptr);
    if (socket_id < 0) {
      fprintf(stderr, "can't serve port %d on interface %s\n", (int) port, NULL == intfptr ? "default" : intfptr);
      ulapi_exit();
      return 1;
    }
    printf("serving port %d on interface %s\n", (int) port, NULL == intfptr ? "default" : intfptr);

    broadcast_id = ulapi_socket_get_broadcaster_id_on_interface(port, intfptr);
    if (0 > broadcast_id) {
      fprintf(stderr, "can't broadcast to %d, ignoring\n", (int) port);
    }

    for (;;) {
      printf("waiting for client connection...\n");
      client_id = ulapi_socket_get_connection_id(socket_id);
      if (client_id < 0) {
	break;
      }
      printf("got one on fd %d\n", client_id);

      if (0 <= broadcast_id) {
		  ulapi_socket_write(broadcast_id, "you have a neighbor", strlen("you have a neighbor"));
	  }

      task = ulapi_task_new();

      server_args_ptr = malloc(sizeof(server_args));
      server_args_ptr->task = task;
      server_args_ptr->id = client_id;
      ulapi_task_start(task, server_code, server_args_ptr, ulapi_prio_lowest(), 0);
    }
  }

  ulapi_exit();
  return 0;
}

