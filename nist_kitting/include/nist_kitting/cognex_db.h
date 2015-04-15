#ifndef COGNEX_DB_H
#define COGNEX_DB_H

/*
  cognex_db.h

  Declarations for the Cognex database and interface functions, for
  simulations
*/

#include <map>
#include <ulapi.h>

enum {
  COGNEX_PORT_DEFAULT = 1456
};

struct cognex_object_info {
  enum {OBJECT_NAME_LEN = 80};
  char name[OBJECT_NAME_LEN];
  double theta;
  double x;
  double y;
  double confidence;

  cognex_object_info();
  cognex_object_info(const char *_name, double _theta, double _x, double _y, double _confidence);
};

struct compare_int {
  bool operator() (int i1, int i2) const { return i1 < i2; }
};

class cognex_object_info_db {
public:

  cognex_object_info_db();
  ~cognex_object_info_db();
  void add(int index, cognex_object_info obj);
  void remove(int index);
  void clear(void);
  int size(void);
  int format(char *str, size_t size);
  void print(void);
  ulapi_task_struct *serve(int port, int period_nsecs);

private:
  std::map<int, cognex_object_info, compare_int> db;
  ulapi_mutex_struct mutex;
};

#endif	/* COGNEX_DB_H */
