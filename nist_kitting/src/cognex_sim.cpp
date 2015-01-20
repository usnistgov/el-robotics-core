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

enum {COGNEX_PORT_DEFAULT = 1456};

#define COGNEX_DB_DEFAULT "cognex_sim.txt"

static bool debug = false;

struct object_info {
  enum {OBJECT_NAME_LEN = 80};
  char object_name[OBJECT_NAME_LEN];
  float object_theta;
  float object_x;
  float object_y;
  float object_confidence;
};

// globals
static std::vector<object_info> object_info_db;
static ulapi_mutex_struct object_info_db_mutex;

static bool load_object_db(const char *path)
{
  FILE *fp;
  enum {LINELEN = 256};
  char line[LINELEN];
  char linecpy[LINELEN];
  object_info object_info_in;
  char *ptr, *tok;
  bool keep_name;

  fp = fopen(path, "r");
  if (NULL == fp) return false;

  // clear out original db, if any
  while (! object_info_db.empty()) {
    object_info el = object_info_db.back();
    object_info_db.pop_back();
  }

  while (! feof(fp)) {
    if (NULL == fgets(line, sizeof(line)-1, fp)) break;
    line[sizeof(line)-1] = 0;
    strcpy(linecpy, line);

    ptr = line;
    while (isspace(*ptr)) ptr++;
    if (isalpha(*ptr) || ('*' == *ptr)) {
      tok = strtok(ptr, ",");
      if (NULL != tok) {
	strncpy(object_info_in.object_name, tok, sizeof(object_info_in.object_name));
	object_info_in.object_name[sizeof(object_info_in.object_name)-1] = 0;
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.object_theta = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.object_x = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.object_y = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, "\n");
      if (NULL != tok) {
	object_info_in.object_confidence = atof(tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      object_info_db.push_back(object_info_in);
    } else {
      // nothing on line
    }
  }

  return true;
}

static void print_object_db(void)
{
  object_info object_info_in;

  for (int t = 0; t < object_info_db.size(); t++) {
    object_info_in = object_info_db[t];
    printf("Object %d: %s,%f,%f,%f,%f\n", t+1,
	   object_info_in.object_name,
	   object_info_in.object_theta,
	   object_info_in.object_x,
	   object_info_in.object_y,
	   object_info_in.object_confidence);
  }
}

static bool format_object_db(char *str, size_t size)
{
  object_info object_info_in;
  size_t retval;
  std::string sstr;

  for (int t = 0; t < object_info_db.size(); t++) {
    object_info_in = object_info_db[t];
    retval = ulapi_snprintf(str, size, "%s,%f,%f,%f,%f",
			    object_info_in.object_name,
			    object_info_in.object_theta,
			    object_info_in.object_x,
			    object_info_in.object_y,
			    object_info_in.object_confidence);
    if (t == 0) {
      sstr = str;
    } else {
      sstr += ",";
      sstr += str;
    }
  }

  sstr += "\n";

  strncpy(str, sstr.c_str(), size);
  str[size-1] = 0;
}

struct stat_thread_args {
  int stat_server_id;
  double stat_period;
};

static void stat_thread_code(stat_thread_args *args)
{
  int stat_server_id = args->stat_server_id;
  double stat_period = args->stat_period;
  int stat_connection_id;
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars;

  while (true) {
    if (debug) printf("waiting for status client connection...\n");
    stat_connection_id = ulapi_socket_get_connection_id(stat_server_id);

    if (stat_connection_id < 0) {
      fprintf(stderr, "can't get status client connecton\n");
      return;
    }
    if (debug) printf("got a status client connection on id %d\n", stat_connection_id);

    while (true) {
      ulapi_mutex_take(&object_info_db_mutex);
      format_object_db(outbuf, sizeof(outbuf)-1);
      ulapi_mutex_give(&object_info_db_mutex);

      nchars = ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf));
      if (nchars < 0) break;	// client disconnected, probably
      ulapi_sleep(stat_period);
    }

    ulapi_socket_close(stat_connection_id);
  }

  if (debug) printf("status handler done\n");

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
  int stat_server_id;
  double period = 1;
  ulapi_task_struct stat_thread;
  stat_thread_args stat_args; 

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

  if (! load_object_db(object_db_path.c_str())) {
    fprintf(stderr, "can't load object database %s\n", object_db_path.c_str());
  }

  ulapi_mutex_init(&object_info_db_mutex, 0);

  stat_server_id = ulapi_socket_get_server_id(port);
  if (stat_server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", port);
    return 1;
  }

  // spawn status server thread
  ulapi_task_init(&stat_thread);
  stat_args.stat_server_id = stat_server_id;
  stat_args.stat_period = period;
  ulapi_task_start(&stat_thread, reinterpret_cast<ulapi_task_code>(stat_thread_code), reinterpret_cast<void *>(&stat_args), ulapi_prio_highest(), 0);

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
	print_object_db();
	break;
      }

      if ('q' == *ptr) {	// quit
	done = true;
	break;
      }

      if (! strncmp(ptr, "load", strlen("load"))) {
	ptr += strlen("load");
	while (isspace(*ptr)) ptr++;
	ulapi_mutex_take(&object_info_db_mutex);
	if (0 == *ptr) {	// no file provided, use original
	  if (! load_object_db(object_db_path.c_str())) {
	    printf("can't load object database %s\n", object_db_path.c_str());
	  }
	} else {
	  object_db_path = std::string(ptr);
	  if (! load_object_db(object_db_path.c_str())) {
	    printf("can't load object database %s\n", ptr);
	  }
	}
	ulapi_mutex_give(&object_info_db_mutex);
	break;
      }	// matches "load"

      printf("?\n");
    } while (false); // do ... wrapper

  } // while (! done)

  return 0;
}

