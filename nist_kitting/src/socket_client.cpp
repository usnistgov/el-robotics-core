#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi */
#include "nist_kitting/socket_utils.h"

int main(int argc, char *argv[])
{
  enum {BUFFERLEN = 256};
  int port;
  int socket_id;
  int nchars;
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  char *host;
  char *ptr;

  if (argc < 3) {
    fprintf(stderr, "need <host> and <port>\n");
    return 1;
  }

  host = argv[1];
  port = atoi(argv[2]);

  if (port < 0) {
    fprintf(stderr, "port must be a positive integer\n");
    return 1;
  }

  socket_id = socket_get_client_id(port, host);

  if (socket_id < 0) {
    fprintf(stderr, "can't connect to %s:%d\n", host, (int) port);
    return 1;
  }
  printf("connected to %s:%d\n", host, (int) port);

  for (;;) {
    if (NULL == fgets(outbuf, sizeof(outbuf), stdin)) {
      break;
    }
    for (ptr = outbuf; *ptr != '\n' && *ptr != 0; ptr++); *ptr = 0;
    nchars = socket_write(socket_id, outbuf, ptr-outbuf+1);
    printf("wrote %d chars\n", nchars);

    nchars = socket_read(socket_id, inbuf, sizeof(inbuf)-1);
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

  return 0;
}
