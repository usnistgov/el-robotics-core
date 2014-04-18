#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi */
#include "nist_kitting/socket_utils.h"

int main(int argc, char *argv[])
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  int port;
  int socket_id;
  int client_id;
  int nchars;

  if (argc < 2) {
    fprintf(stderr, "need a port number\n");
    return 1;
  }

  port = atoi(argv[1]);

  if (port < 0) {
    fprintf(stderr, "port must be a positive integer\n");
    return 1;
  }

  socket_id = socket_get_server_id(port);
  if (socket_id < 0) {
    fprintf(stderr, "can't serve port %d\n", (int) port);
    return 1;
  }
  printf("serving port %d\n", (int) port);

  for (;;) {
    printf("waiting for client connection...\n");
    client_id = socket_get_connection_id(socket_id);
    if (client_id < 0) {
      break;
    }
    printf("got one on fd %d\n", client_id);

    for (;;) {
      nchars = socket_read(client_id, inbuf, sizeof(inbuf));
      if (-1 == nchars) {
	break;
      }
      if (0 == nchars) {
	break;
      }
      printf("got %d chars: ``%s''\n", nchars, inbuf);
      socket_write(client_id, inbuf, nchars);
    }

    socket_close(client_id);
    printf("closed %d\n", client_id);
  }

  return 0;
}

