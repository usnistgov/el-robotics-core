#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

extern int socket_get_client_id(int port, const char *hostname);

extern int socket_get_server_id(int port);

extern int socket_get_connection_id(int socket_fd);

char *address_to_hostname(int address);

extern int hostname_to_address(const char *hostname);

extern int get_host_address(void);

extern int socket_read(int id, char *buf, int len);

extern int socket_write(int id, const char *buf, int len);

extern int socket_close(int id);

#endif	/* SOCKET_UTILS_H */
