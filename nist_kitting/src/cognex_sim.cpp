/*
  All items are ASCII strings, 4 decimal places for double values:

  Name:string,Found:1 or 0, Rotation: double radians, Translation X:
  double mm, Translation Y : double mm, Score : double between 0 and 1

  E.g., "Big Gear,1,0.5708,123.4567,-234.5678,0.5105,Medium Gear,0,,,,\n"

  Each line has one group for each part, with a newline separating
  frames of data. All parts show up in all messages, even if they are
  not found, so there is a fixed number of elements in a message, but
  not a fixed message length. If an element doesn’t show up, it is
  represented by a comma immediately followed by another comma. Note
  that the name and if the object was found or not will always be
  present. The names of objects are (in this order): ‘Big Gear’, ‘Medium
  Gear’, ‘Small Gear’, ‘Top Cover’, ‘Bottom Cover’, ‘Bag of Parts’

  The port is 1456. The string is terminated with a newline. 
*/

#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof, size_t */
#include <stdlib.h>		/* atoi, atof */
#include <string.h>
#include <ctype.h>

#include <iostream>
#include <vector>
#include <string>

#include <ulapi.h>

#include <nist_kitting/cognex_db.h>

#define COGNEX_DB_DEFAULT "cognex_sim.txt"

static bool debug = false;

static bool load_object_db(cognex_object_info_db *db, const char *path)
{
  FILE *fp;
  enum {LINELEN = 256};
  char line[LINELEN];
  char linecpy[LINELEN];
  cognex_object_info object_info_in;
  char *ptr, *tok;
  int id = 1;

  fp = fopen(path, "r");
  if (NULL == fp) return false;

  // clear out original db, if any
  db->clear();

  while (! feof(fp)) {
    if (NULL == fgets(line, sizeof(line)-1, fp)) break;
    line[sizeof(line)-1] = 0;
    strcpy(linecpy, line);

    ptr = line;
    while (isspace(*ptr)) ptr++;
    if (isalpha(*ptr) || ('*' == *ptr)) {
      tok = strtok(ptr, ",");
      if (NULL != tok) {
	strncpy(object_info_in.name, tok, sizeof(object_info_in.name));
	object_info_in.name[sizeof(object_info_in.name)-1] = 0;
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.theta = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.x = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.y = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, "\n");
      if (NULL != tok) {
	object_info_in.confidence = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      db->add(id++, object_info_in);
    } else {
      // nothing on line
    }
  }

  return true;
}

struct client_thread_args {
  cognex_object_info_db *db;
  int connection_id;
  double period;
};

static void client_thread_code(client_thread_args *args)
{
  cognex_object_info_db *db = args->db;
  int connection_id = args->connection_id;
  double period = args->period;
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars;

  delete args;

  while (true) {
    db->format(outbuf, sizeof(outbuf)-1);

    nchars = ulapi_socket_write(connection_id, outbuf, strlen(outbuf));
    if (nchars < 0) break;	// client disconnected, probably
    ulapi_sleep(period);
  }

  ulapi_socket_close(connection_id);
}

struct server_thread_args {
  cognex_object_info_db *db;
  int server_id;
  double period;
};

static void server_thread_code(server_thread_args *args)
{
  int connection_id;
  client_thread_args *client_args;
  ulapi_task_struct client_thread;

  while (true) {
    if (debug) printf("waiting for status client connection...\n");
    connection_id = ulapi_socket_get_connection_id(args->server_id);

    if (connection_id < 0) {
      fprintf(stderr, "can't get status client connecton\n");
      return;
    }
    if (debug) printf("got a status client connection on id %d\n", connection_id);

    // spawn client thread
    client_args = new client_thread_args;
    ulapi_task_init(&client_thread);
    client_args->db = args->db;
    client_args->connection_id = connection_id;
    client_args->period = args->period;
    ulapi_task_start(&client_thread, reinterpret_cast<ulapi_task_code>(client_thread_code), reinterpret_cast<void *>(client_args), ulapi_prio_highest(), 0);
  }

  if (debug) printf("status handler done\n");

  ulapi_socket_close(args->server_id);

  return;
}

/*
  Cognex simulator. 

  Run as: ./cognex_sim <args>
  Args:

  -p <#>    : TCP port to serve>
  -t <#>    : <period in seconds between outputs>
  -f <file> : file name of objects, format below
  -d        : turn debug on

  Object file format looks like this: 

  <name> , <present, 0 or 1> , \
  <orientation, rads> , <x pos> , <y pos>, <confidence>

  e.g., "Big_Gear,0,0.5708,123.4567,-234.5678,0.5105"

  Client programs connect to the TCP provided, and receive a stream of
  the objects as defined in the file. 

  This program provides a terminal in the foreground. 

  Enter a blank line to see the object database.
  Enger "load <file>" to load a new file into the database.
  Enter "q" to quit.
*/

int main(int argc, char *argv[])
{
  int option;
  int ival;
  double dval;
  int port = COGNEX_PORT_DEFAULT;
  std::string object_db_path = COGNEX_DB_DEFAULT;
  cognex_object_info_db db;
  double period = 1;
  int server_id;
  ulapi_task_struct server_thread;
  server_thread_args server_args; 

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":p:t:f:d");
    if (option == -1) break;

    switch (option) {
    case 'p':
      ival = atoi(optarg);
      port = ival;
      break;

    case 't':
      dval = atof(optarg);
      period = dval;
      break;

    case 'f':
      object_db_path = std::string(optarg);
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
    } // switch (option)
  }   // while (true) for getopt

  if (! load_object_db(&db, object_db_path.c_str())) {
    fprintf(stderr, "can't load object database %s\n", object_db_path.c_str());
  }

  server_id = ulapi_socket_get_server_id(port);
  if (server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", port);
    return 1;
  }

  // spawn status server thread
  ulapi_task_init(&server_thread);
  server_args.db = &db;
  server_args.server_id = server_id;
  server_args.period = period;
  ulapi_task_start(&server_thread, reinterpret_cast<ulapi_task_code>(server_thread_code), reinterpret_cast<void *>(&server_args), ulapi_prio_highest(), 0);

  bool done = false;
  while (! done) {
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    char *endptr;

    // print prompt
    printf("> ");
    fflush(stdout);
    // get input line
    if (NULL == fgets(inbuf, sizeof(inbuf), stdin)) break;
    // skip leading whitespace
    ptr = inbuf;
    while (isspace(*ptr)) ptr++;
    // strip off trailing whitespace
    endptr = inbuf + strlen(inbuf);
    while ((isspace(*endptr) || 0 == *endptr) && endptr >= ptr) *endptr-- = 0;
    // now 'ptr' is the stripped input string

    do {
      if (0 == *ptr) {		// blank line, print state
	db.print();
	break;
      }

      if ('q' == *ptr) {	// quit
	done = true;
	break;
      }

      if (! strncmp(ptr, "load", strlen("load"))) {
	ptr += strlen("load");
	while (isspace(*ptr)) ptr++;
	if (0 == *ptr) {	// no file provided, use original
	  if (! load_object_db(&db, object_db_path.c_str())) {
	    printf("can't load object database %s\n", object_db_path.c_str());
	  }
	} else {
	  object_db_path = std::string(ptr);
	  if (! load_object_db(&db, object_db_path.c_str())) {
	    printf("can't load object database %s\n", ptr);
	  }
	}
	break;
      }	// matches "load"

      printf("?\n");
    } while (false); // do ... wrapper

  } // while (! done)

  return 0;
}

