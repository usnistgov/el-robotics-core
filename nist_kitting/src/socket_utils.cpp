#if !defined(WIN32) && (defined(_WIN32) || defined(__WIN32))
#define WIN32
#endif

#ifdef WIN32

/* turn off sprintf warnings */
#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <stdio.h>		/* printf */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* malloc, free */
#include <ctype.h>		/* isspace */
#include <string.h>		/* strcpy, strrchr */
#include <time.h>		/* clock, CLK_TCK */
#include <windows.h>
#include <winbase.h>
#include <sys/types.h>
#include <sys/stat.h>

static WSADATA wsaData;
static int iResult;
#define WINSTART iResult = WSAStartup(MAKEWORD(2,2), &wsaData); if (iResult !=0) return -1

#else 

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>		/* PF_INET, socket(), listen(), bind(), etc. */
#include <netinet/in.h>		/* struct sockaddr_in */
#include <netdb.h>		/* gethostbyname */
#include <arpa/inet.h>		/* inet_addr */

#define WINSTART
#define closesocket(x) close(x)

#endif	// Unix

#include "nist_kitting/socket_utils.h"

#define DIGITS_IN(x) (sizeof(x) * 3 + 1)

int socket_get_client_id(int port, const char *hostname)
{
  int socket_fd;
  struct sockaddr_in server_addr;
  struct hostent *ent;
  struct in_addr *in_a;

  WINSTART;

  if (NULL == (ent = gethostbyname(hostname))) {
    perror("gethostbyname");
    return -1;
  }
  in_a = (struct in_addr *) ent->h_addr_list[0];

  memset(&server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = PF_INET;
  server_addr.sin_addr.s_addr = in_a->s_addr;
  server_addr.sin_port = htons(port);

  if (-1 == (socket_fd = socket(PF_INET, SOCK_STREAM, 0))) {
    perror("socket");
    return -1;
  }

  if (-1 == connect(socket_fd, 
		    (struct sockaddr *) &server_addr,
		    sizeof(struct sockaddr_in))) {
    perror("connect");
    closesocket(socket_fd);
    return -1;
  }

  return socket_fd;
}

int socket_get_server_id(int port)
{
  int socket_fd;
  struct sockaddr_in myaddr;
  int on;
  struct linger mylinger = { 0 };
  enum {BACKLOG = 5};

  WINSTART;

  if (-1 == (socket_fd = socket(PF_INET, SOCK_STREAM, 0))) {
    perror("socket");
    return -1;
  }

  /*
    Turn off bind address checking, and allow
    port numbers to be reused - otherwise the
    TIME_WAIT phenomenon will prevent binding
    to these address.port combinations for
    (2 * MSL) seconds.
  */
  on = 1;
  if (-1 == 
      setsockopt(socket_fd,
		 SOL_SOCKET,
		 SO_REUSEADDR,
		 (const char *) &on,
		 sizeof(on))) {
    perror("setsockopt");
    closesocket(socket_fd);
    return -1;
  }

  /*
    When connection is closed, there is a need
    to linger to ensure all data is transmitted.
  */
  mylinger.l_onoff = 1;
  mylinger.l_linger = 30;
  if (-1 ==
      setsockopt(socket_fd,
		 SOL_SOCKET,
		 SO_LINGER,
		 (const char *) &mylinger,
		 sizeof(struct linger))) {
    perror("setsockopt");
    closesocket(socket_fd);
    return -1;
  }

  memset(&myaddr, 0, sizeof(struct sockaddr_in));
  myaddr.sin_family = PF_INET;
  myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myaddr.sin_port = htons(port);

  if (-1 == bind(socket_fd, (struct sockaddr *) &myaddr,
		 sizeof(struct sockaddr_in))) {
    perror("bind");
    closesocket(socket_fd);
    return -1;
  }

  if (-1 == listen(socket_fd, BACKLOG)) {
    perror("listen");
    closesocket(socket_fd);
    return -1;
  }

  return socket_fd;
}

int socket_get_connection_id(int socket_fd)
{
#ifndef WIN32
  fd_set rfds;
  int retval;
#endif
  struct sockaddr_in client_addr;
  int client_len;
  int client_fd;

#ifndef WIN32
  do {
    FD_ZERO(&rfds);
    FD_SET(socket_fd, &rfds);
    retval = select(socket_fd + 1, &rfds, NULL, NULL, NULL);
  } while (0 == retval ||
	   ! FD_ISSET(socket_fd, &rfds));

  if (retval == -1) {
    perror("select");
    return -1;
  }
#endif

  memset(&client_addr, 0, sizeof(struct sockaddr_in));
  client_len = sizeof(struct sockaddr_in);
  client_fd = 
    accept(socket_fd,
	   (struct sockaddr *) &client_addr, 
	   &client_len);
  if (-1 == client_fd) {
    perror("accept");
    return -1;
  }
  
  return client_fd;
}

char *address_to_hostname(int address)
{
  static char string[4 * DIGITS_IN(int) + 3 + 1];

  sprintf(string, "%d.%d.%d.%d",
	  (int) ((address >> 24) & 0xFF),
	  (int) ((address >> 16) & 0xFF),
	  (int) ((address >> 8) & 0xFF),
	  (int) (address & 0xFF));

  return string;
}

int hostname_to_address(const char *hostname)
{
  struct hostent * ent;

  ent = gethostbyname(hostname);
  if (NULL == ent) return (127 << 24) + (0 << 16) + (0 << 8) + 1;
  if (4 != ent->h_length) return 0;

  /* FIXME-- could use ntohl here */
  return ((ent->h_addr_list[0][0] & 0xFF) << 24)
    + ((ent->h_addr_list[0][1] & 0xFF) << 16)
    + ((ent->h_addr_list[0][2] & 0xFF) << 8)
    + (ent->h_addr_list[0][3] & 0xFF);
}

int get_host_address(void)
{
  enum {HOSTNAMELEN = 256};
  char hostname[HOSTNAMELEN];

  WINSTART;

  if (0 != gethostname(hostname, HOSTNAMELEN)) return 0;
  hostname[HOSTNAMELEN - 1] = 0; /* force null termination */

  return hostname_to_address(hostname);
}

int socket_read(int id, char *buf, int len)
{
  return recv(id, buf, len, 0);
}

int socket_write(int id, const char *buf, int len)
{
  return send(id, buf, len, 0);
}

int socket_close(int id)
{
  return 0 == closesocket((int) id) ? 0 : -1;
}
