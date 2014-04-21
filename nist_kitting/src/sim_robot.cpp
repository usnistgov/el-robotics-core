#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include "nist_kitting/socket_utils.h"

/*
  Socket command protocol is null-terminated ASCII strings:

  <serial number> <cmd> { <arg> { <arg> }+ }* \000

  e.g.,

  "1 INIT"
  "2 MOVETO 1.0 2.3 4.5 0.0 -90.0 0.0"
  "17 HALT"

  Status messages are sent with serial number acks with DONE, EXEC, ERROR, 
  then the position:

  <serial number executing> <status> <x> <y> <z> <qx> <qy> <qz> <qw>

  "2 EXEC POS 0.5 1.7 2.3 0.0 -45.0 0.0"

  Status replies can be triggered with a "?" command, no serial number.
*/

static int handle_message(char *inbuf, int inbuf_len, int client_id)
{
  static int outbuf_len = 256;	// make this at least big enough for an int
  static char *outbuf = (char *) malloc(outbuf_len);
  static int cmdbuf_len = 256;
  static char *cmdbuf = (char *) malloc(cmdbuf_len);
  static int serial_number;
  static enum {DONE, EXEC, ERROR} status = DONE;
  static double x, y, z, qx, qy, qz, qw;
  char *inptr;
  int outchars;
  int i1;
  double d1, d2, d3, d4, d5, d6, d7;

  inbuf[inbuf_len - 1] = 0;

  inptr = inbuf;

#define DO_STATUS_STRING						\
  while (true) {							\
    outchars =								\
      snprintf(outbuf, outbuf_len, "%d %s %f %f %f %f %f %f %f",	\
	       serial_number,						\
	       DONE == status ? "DONE" :				\
	       EXEC == status ? "EXEC" : "ERROR",			\
	       x, y, z, qx, qy, qz, qw);				\
    if (outchars < outbuf_len) break;					\
    outbuf_len = 2 * outchars;						\
    outbuf = (char *) realloc(outbuf, outbuf_len);			\
  }

  if ('?' == inptr[0]) {
    DO_STATUS_STRING;
    socket_write(client_id, outbuf, strlen(outbuf) + 1);
    return 0;
  }

  if (cmdbuf_len < inbuf_len) {
    cmdbuf_len = 2 * inbuf_len;
    cmdbuf = (char *) realloc(cmdbuf, cmdbuf_len);
  }

  if (1 != sscanf(inptr, "%d", &i1)) return -1;
  serial_number = i1;

  while (! isspace(*inptr) && 0 != *inptr) inptr++;
  while (isspace(*inptr)) inptr++;

  if (! strncmp(inptr, "MOVETO ", strlen("MOVETO "))) {
    if (7 == sscanf(inptr, "%*s %lf %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
      status = DONE;
    } else {
      status = ERROR;
    }
    DO_STATUS_STRING;
    socket_write(client_id, outbuf, strlen(outbuf) + 1);
    return 0;
  }
}

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
      handle_message(inbuf, nchars, client_id);
    }

    socket_close(client_id);
    printf("closed %d\n", client_id);
  }

  return 0;
}

