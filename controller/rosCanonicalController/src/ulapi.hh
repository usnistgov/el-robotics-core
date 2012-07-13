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
  \file ulapi.h

  \brief Declarations of the user-level application programming interface,
  ULAPI, for portable communication between user-level processes and 
  real-time tasks conforming to the \ref RTAPI real-time API.
*/

/*!
  \defgroup ULAPI User-Level API

  The User-Level Application Programming Interface (ULAPI) provides a
  portable interface for communicating with real-time tasks conforming
  to the \ref RTAPI real-time API.
*/

#ifndef ULAPI_H
#define ULAPI_H

#include <stdio.h>		/* printf */
#include <string.h>		/* stricmp, strcasecmp */

/* make sure we have enough string space to print numbers as strings */
#ifndef DIGITS_IN
#define DIGITS_IN(x) (sizeof(x) * 3 + 1)
#endif

#if defined(ULAPI_RESULT_CHAR)
typedef char ulapi_result;
#else
typedef int ulapi_result;
#endif

#if defined(ULAPI_INTEGER_LONG)
typedef long int ulapi_integer;
#else
typedef int ulapi_integer;
#endif

#if defined(ULAPI_ID_LONG)
typedef long int ulapi_id;
#else
typedef int ulapi_id;
#endif

#if defined(ULAPI_FLAG_INT)
typedef int ulapi_flag;
#else
typedef char ulapi_flag;
#endif

#if defined(ULAPI_REAL_FLOAT)
typedef float ulapi_real;
#elif defined(ULAPI_REAL_LONG_DOUBLE)
typedef long double ulapi_real;
#else
typedef double ulapi_real;
#endif

enum
{
  UL_USE_DEFAULT = 0,
  UL_USE_UNIX,
  UL_USE_RTAI
};

extern ulapi_real ulapi_time (void);

extern void ulapi_sleep (ulapi_real secs);

enum
{
  ULAPI_OK = 0,
  ULAPI_ERROR,
  ULAPI_IMPL_ERROR,
  ULAPI_BAD_ARGS
};

/*!
  Call this once before any other ULAPI functions, passing
  UL_USE_DEFAULT for the default ULAPI implementation, or one of the
  platform-specific values like UL_USE_UNIX or UL_USE_RTAI to force an
  implementation, if available. Returns ULAPI_OK if successful,
  otherwise ULAPI_RESULT_IMPL_ERROR if the implementation specified by
  \a sel is not available, or ULAPI_RESULT_BAD_ARGS if \a sel is not
  recognized.
*/
extern ulapi_result ulapi_init (ulapi_integer sel);
extern ulapi_result ulapi_exit (void);

extern ulapi_integer ulapi_to_argv (const char *str, char ***argv);
extern void ulapi_free_argv (ulapi_integer argc, char **argv);

/*!
  Set and get the debug level.
*/
enum
{ ULAPI_DEBUG_WARN = 0x01,
  ULAPI_DEBUG_ERROR = 0x02,
  ULAPI_DEBUG_ALL = 0xFF
};

extern void ulapi_set_debug (ulapi_integer mask);

/*!
  As with RTAPI, priorities range from ulapi_prio_lowest() to
  ulapi_prio_highest(), inclusive. To use this API, use one of two
  methods:

  Set your lowest priority task to ulapi_prio_lowest(), and for each
  task of the next lowest priority, set their priorities to
  ulapi_prio_next_higher(previous).

  Or,

  Set your highest priority task to ulapi_prio_highest(), and for each
  task of the next highest priority, set their priorities to
  ulapi_prio_next_lower(previous).
*/

#if defined(ULAPI_PRIO_CHAR)
typedef char ulapi_prio;
#else
typedef int ulapi_prio;
#endif

extern ulapi_prio ulapi_prio_highest (void);
extern ulapi_prio ulapi_prio_lowest (void);
extern ulapi_prio ulapi_prio_next_higher (ulapi_prio prio);
extern ulapi_prio ulapi_prio_next_lower (ulapi_prio prio);

/*!
  Allocates space for a platform-specific data structure that holds
  the task information. Pass this to the \a ulapi_task_ functions.
*/
extern void *ulapi_task_new (void);
extern ulapi_result ulapi_task_delete (void *task);

typedef void (*ulapi_task_code) (void *);

extern ulapi_result ulapi_task_start (void *task,
				      void (*taskcode) (void *),
				      void *taskarg,
				      ulapi_prio prio,
				      ulapi_integer period_nsec);

extern ulapi_result ulapi_task_stop (void *task);
extern ulapi_result ulapi_task_pause (void *task);
extern ulapi_result ulapi_task_resume (void *task);
extern ulapi_result ulapi_task_set_period (void *task,
					   ulapi_integer period_nsec);
extern ulapi_result ulapi_task_init (void);
extern ulapi_result ulapi_self_set_period (ulapi_integer period_nsec);
extern ulapi_result ulapi_wait (ulapi_integer period_nsec);
extern ulapi_result ulapi_task_exit (void);
extern ulapi_result ulapi_task_join (void *task);
extern ulapi_integer ulapi_task_id (void);

/*!
  Returns a pointer to an implementation-defined structure that
  is passed to the other mutex functions, or NULL if no mutex can
  be created.
*/
extern void *ulapi_mutex_new (ulapi_id key);

/*! Deletes the mutex. */
extern ulapi_result ulapi_mutex_delete (void *mutex);

/*| Releases the mutex, signifying that the associated shared resource 
  is now free for another task to take. */
extern ulapi_result ulapi_mutex_give (void *mutex);

/*! Takes the mutex, signifying that the associated shared resource
  will now be used by the task. If the mutex is already taken, this
  blocks the caller until the mutex is given. */
extern ulapi_result ulapi_mutex_take (void *mutex);

extern void *ulapi_sem_new (ulapi_id key);
extern ulapi_result ulapi_sem_delete (void *sem);
extern ulapi_result ulapi_sem_give (void *sem);
extern ulapi_result ulapi_sem_take (void *sem);

/*!
  Returns a pointer to an implementation-defined structure that is
  passed to the other condition variable functions, or NULL if no
  condition variable can be created.
*/
extern void *ulapi_cond_new (ulapi_id key);

/*! Deletes the condition variable. */
extern ulapi_result ulapi_cond_delete (void *cond);

/*| Signals that the condition variable has reached its release value */
extern ulapi_result ulapi_cond_signal (void *cond);

/*| Broadcasts that the condition variable has reached its release value */
extern ulapi_result ulapi_cond_broadcast (void *cond);

/*! Waits until the condition variable has reached its release value */
extern ulapi_result ulapi_cond_wait (void *cond, void *mutex);

/*!
  Allocates space for a platform-specific data structure that holds
  the shared memory configuration. Pass this to \a ulapi_shm_addr
  to get a pointer to the actual shared memory.
*/
extern void *ulapi_shm_new (ulapi_id key, ulapi_integer size);
/*!
  Returns a pointer to the actual shared memory, given a shared memory
  data structure previously created with \a ulapi_shm_new.
 */
extern void *ulapi_shm_addr (void *shm);
/*!
  Deletes shared memory previously allocated with \a ulapi_shm_new.
 */
extern ulapi_result ulapi_shm_delete (void *shm);

extern ulapi_result ulapi_fifo_new (ulapi_integer key, ulapi_integer * fd,
				    ulapi_integer size);
extern ulapi_result ulapi_fifo_delete (ulapi_integer key, ulapi_integer fd,
				       ulapi_integer size);
extern ulapi_integer ulapi_fifo_write (ulapi_integer fd, const char *buf,
				       ulapi_integer size);
extern ulapi_integer ulapi_fifo_read (ulapi_integer fd, char *buf,
				      ulapi_integer size);

/*!
  Connects as a client to the socket server on \a port and \a host.
  Returns the integer socket descriptor for later sends and receives.
*/
extern ulapi_integer ulapi_socket_get_client_id (ulapi_integer port,
						 const char *host);

/*!
  Creates a server connection to the \a port. Returns the integer
  socket descriptor for later use in \a
  ulapi_socket_get_client_connection.
*/
extern ulapi_integer ulapi_socket_get_server_id (ulapi_integer port);

/*!
  Called by a server to gets a connection from a client. Returns the
  integer socket descriptor for later sends and receives.
*/
extern ulapi_integer ulapi_socket_get_connection_id (ulapi_integer id);

/*!
  Gets an fd for broadcast writing. No port is necessary; the port is
  provided when writing via ulapi_socket_broadcast.
*/
extern ulapi_integer ulapi_socket_get_broadcaster_id (void);

/*!
  Gets an fd for broadcast reading.
*/
extern ulapi_integer ulapi_socket_get_broadcastee_id (ulapi_integer port);

/*!
  Sets the socket to be blocking or nonblocking.
*/
extern ulapi_result ulapi_socket_set_nonblocking (ulapi_integer id);
extern ulapi_result ulapi_socket_set_blocking (ulapi_integer id);

extern char *ulapi_address_to_hostname (ulapi_integer address);
extern ulapi_integer ulapi_hostname_to_address (const char *hostname);
extern ulapi_integer ulapi_get_host_address (void);

/*!
  Reads up to \a len bytes from socket \a id into \a buf. Returns the
  number of bytes read, or -1 on error.
 */
extern ulapi_integer ulapi_socket_read (ulapi_integer id, char *buf,
					ulapi_integer len);

/*!
  Writes \a len bytes from \a buf to socket \a id. Returns the
  number of bytes written, or -1 on error.
 */
extern ulapi_integer ulapi_socket_write (ulapi_integer id, const char *buf,
					 ulapi_integer len);

/*!
  Broadcasts \a len bytes from \a buf to socket \a id using port -a
  port. Returns the number of bytes written, or -1 on error.
 */
extern ulapi_integer ulapi_socket_broadcast (ulapi_integer id,
					     ulapi_integer port,
					     const char *buf,
					     ulapi_integer len);

/*!
  Closes the socket id, whether that for a client, for a server, or to
  a client, broadcast or otherwise.
 */
extern ulapi_result ulapi_socket_close (ulapi_integer id);

/*
  File descriptor (fd) API
*/

typedef enum
{
  ULAPI_STDIN,
  ULAPI_STDOUT,
  ULAPI_STDERR
} ulapi_stdio;

/*! Allocates space for a file identifier, and returns its pointer. */
extern void *ulapi_fd_new (void);

/*! Deallocates a previously allocated file identifier. */
extern ulapi_result ulapi_fd_delete (void *id);

/*! Copies the stdio file descriptor into \a id. */
extern ulapi_result ulapi_std_open (ulapi_stdio io,	/*!< one of ULAPI_STDIN,STDOUT,STDERR */
				    void *id	/*!< pointer to fd where it will be copied */
  );

/*!
  Opens a connection to a file. Fills in the identifier and
  returns ULAPI_OK if it worked, otherwise returns ULAPI_ERROR.
 */
extern ulapi_result ulapi_fd_open (const char *port, void *id);

/*!
  Sets the file descriptor \a id to be blocking or nonblocking.
*/
extern ulapi_result ulapi_fd_set_nonblocking (void *id);

extern ulapi_result ulapi_fd_set_blocking (void *id);

/*!
  Reads up to \a len bytes from file descriptor \a id into \a
  buf. Returns the number of bytes read, or -1 on error.
 */
extern ulapi_integer ulapi_fd_read (void *id, char *buf, ulapi_integer len);

/*!
  Writes \a len bytes from \a buf to file descriptor \a
  id. Returns the number of bytes written, or -1 on error.
 */
extern ulapi_integer
ulapi_fd_write (void *id, const char *buf, ulapi_integer len);

/*!
  Closes the file descriptor.
 */
extern ulapi_result ulapi_fd_close (void *id);

/*
  Serial communication API, similar to file descriptor API
*/

/*! Allocates space for a serial port identifier, and returns its pointer. */
extern void *ulapi_serial_new (void);

/*! Deallocates a previously allocated serial port identifier. */
extern ulapi_result ulapi_serial_delete (void *id);

/*!
  Opens a connection to a serial port. Fills in the identifier and
  returns ULAPI_OK if it worked, otherwise returns ULAPI_ERROR.
 */
extern ulapi_result ulapi_serial_open (const char *port, void *id);

/*!
  Sets the serial port descriptor \a id to be blocking or nonblocking.
*/
extern ulapi_result ulapi_serial_set_nonblocking (void *id);

extern ulapi_result ulapi_serial_set_blocking (void *id);

/*!
  Reads up to \a len bytes from serial port descriptor \a id into \a
  buf. Returns the number of bytes read, or -1 on error.
 */
extern ulapi_integer
ulapi_serial_read (void *id, char *buf, ulapi_integer len);

/*!
  Writes \a len bytes from \a buf to serial port descriptor \a
  id. Returns the number of bytes written, or -1 on error.
 */
extern ulapi_integer
ulapi_serial_write (void *id, const char *buf, ulapi_integer len);

/*!
  Closes the serial port descriptor.
 */
extern ulapi_result ulapi_serial_close (void *id);

#define ULAPI_DECL_SHARED
#ifdef WIN32
#undef ULAPI_DECL_SHARED
#define ULAPI_DECL_SHARED __declspec(dllexport)
#endif

/*!
  Executes 'prog'. Returns ULAPI_OK if it was able to execute, placing
  the program return value in 'result'. Otherwise, returns ULAPI_ERROR
  and leaves 'result' alone.
*/
extern ulapi_result ulapi_system (const char *prog, int *result);

#define ulapi_print printf
#ifdef WIN32
#define ulapi_snprintf sprintf_s
#define ulapi_strcasecmp _stricmp
#define ulapi_strdup _strdup
#define ulapi_sscanf sscanf_s
#define ulapi_strncpy strncpy_s
#else
#define ulapi_snprintf snprintf
#define ulapi_strcasecmp strcasecmp
#define ulapi_strdup strdup
#define ulapi_sscanf sscanf
#define ulapi_strncpy strncpy
#endif

#endif /* ULAPI_H */
