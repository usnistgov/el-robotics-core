#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#if !defined(WIN32) && (defined(_WIN32) || defined(__WIN32))
#define WIN32
#endif

extern int socket_get_client_id(int port, const char *hostname);

extern int socket_get_server_id(int port);

extern int socket_get_connection_id(int socket_fd);

char *address_to_hostname(int address);

extern int hostname_to_address(const char *hostname);

extern int get_host_address(void);

extern int socket_read(int id, char *buf, int len);

extern int socket_write(int id, const char *buf, int len);

extern int socket_close(int id);

#ifdef WIN32
#define socket_snprintf sprintf_s
#else
#define socket_snprintf snprintf
#endif

#endif	/* SOCKET_UTILS_H */
