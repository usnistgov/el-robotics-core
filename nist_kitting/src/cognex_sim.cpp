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

  The port is 456. The string is terminated with a newline. 
*/

#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof, size_t */
#include <stdlib.h>		/* atoi, atof */
#include <string.h>
#include <ctype.h>

#include <iostream>
#include <vector>

#include <ulapi.h>

enum {COGNEX_PORT_DEFAULT = 456};
static bool debug = false;

struct object_info {
  char *object_name;
  bool object_present;
  float object_theta;
  float object_x;
  float object_y;
  float object_confidence;
};

// globals
static std::vector<object_info> object_info_db;
static char *object_info_message = NULL;

static bool load_object_db(char *path)
{
  FILE *fp;
  enum {LINELEN = 256};
  char line[LINELEN];
  char linecpy[LINELEN];
  object_info object_info_in;
  char *ptr, *tok;
  bool keep_name;

  object_info_in.object_name = NULL;
  keep_name = false;

  fp = fopen(path, "r");
  if (NULL == fp) return false;

  while (! feof(fp)) {
    if (NULL == fgets(line, sizeof(line)-1, fp)) break;
    line[sizeof(line)-1] = 0;
    strcpy(linecpy, line);

    ptr = line;
    while (isspace(*ptr)) ptr++;
    if (isalpha(*ptr)) {
      if ((! keep_name) && (NULL != object_info_in.object_name)) {
	if (debug) printf("deleting name %s\n", object_info_in.object_name);
	delete object_info_in.object_name;
      }
      keep_name = false;
      tok = strtok(ptr, ",");
      if (NULL != tok) {
	object_info_in.object_name = new char[strlen(ptr)];
	strcpy(object_info_in.object_name, tok);
      } else {
	fprintf(stderr, "bad object db entry: %s\n", linecpy);
	continue;
      }

      tok = strtok(NULL, ",");
      if (NULL != tok) {
	object_info_in.object_present = atoi(tok) > 0 ? true : false;
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
      keep_name = true;

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
    printf("%s,%d,%f,%f,%f,%f\n",
	   object_info_in.object_name,
	   object_info_in.object_present,
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
    retval = ulapi_snprintf(str, size, "%s,%d,%f,%f,%f,%f",
			    object_info_in.object_name,
			    object_info_in.object_present,
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
      format_object_db(outbuf, sizeof(outbuf)-1);
      nchars = ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf));
      if (nchars < 0) {
	// client disconnected, probably
	break;
      }
      ulapi_wait(stat_period * 1e9);
    }

    ulapi_socket_close(stat_connection_id);
  }

  if (debug) printf("status handler done\n");

  return;
}

int main(int argc, char *argv[])
{
  int option;
  int ival;
  double dval;
  int port = COGNEX_PORT_DEFAULT;
  int stat_server_id;
  double period = 1;
  ulapi_task_struct stat_thread;
  stat_thread_args stat_args; 
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":p:d");
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

  char object_db_path[] = "src/nist_kitting/src/cognex_sim.txt";
  if (! load_object_db(object_db_path)) {
    fprintf(stderr, "can't load object database %s\n", object_db_path);
  }

  if (debug) print_object_db();

  while (true) {
    if (NULL == fgets(inbuf, sizeof(inbuf)-1, stdin)) {
      // closed input
      break;
    }

    // FIXME -- move some objects around, using mutexed WM struct

  }

  return 0;
}

