/*
  ulapi_test.cpp

  Test file for Ulapi functions in a C++ environment. 
*/

#include <stddef.h>		// NULL
#include <iostream>		// std:: cout, cerr, endl

#include <ulapi.h>		// ulapi_mutex_new, ...

using namespace std;

struct shared_struct {
  enum {ARRAY_LEN = 1024};
  int array[ARRAY_LEN];
};

struct args_struct {
  void *mutex;
  void *sem;
  shared_struct *shared;
};

static void writer(args_struct *args)
{
  void *mutex = args->mutex;
  void *sem = args->sem;
  shared_struct *shared = args->shared;
  delete args;

  ulapi_mutex_take(mutex);
  cout << "Writer task started" << endl;
  ulapi_mutex_give(mutex);

  int count = 10;
  while (count-- > 0) {
    ulapi_mutex_take(mutex);
    cout << "Writer writing " << count << endl;
    for (int t = 0; t < shared->ARRAY_LEN; t++) shared->array[t] = count;
    ulapi_mutex_give(mutex);
    ulapi_sem_give(sem);
    ulapi_sleep(1);
  }

  ulapi_task_exit(17);
}

static void reader(args_struct *args)
{
  void *mutex = args->mutex;
  void *sem = args->sem;
  shared_struct *shared = args->shared;
  delete args;

  ulapi_mutex_take(mutex);
  cout << "Reader task started" << endl;
  ulapi_mutex_give(mutex);

  int count;
  while (true) {
    ulapi_sem_take(sem);
    ulapi_mutex_take(mutex);
    cout << "Reader read " << shared->array[0] << " .. " << shared->array[shared->ARRAY_LEN-1] << endl;
    count = shared->array[0];
    ulapi_mutex_give(mutex);
    if (count <= 0) break;
  }

  ulapi_task_exit(43);
}

int main(int argc, char *argv[])
{
  enum {MUTEX_KEY = 1};
  enum {SEM_KEY = 1};
  enum {SHM_KEY = 1};
  args_struct *args_ptr;
  ulapi_task_struct writer_task;
  ulapi_task_struct reader_task;
  void *mutex;
  void *sem;
  void *shm;
  shared_struct *shared_ptr;
  int writer_ret;
  int reader_ret;

  mutex = ulapi_mutex_new(MUTEX_KEY);
  if (NULL == mutex) {
    cerr << "Can't create mutex for key " << MUTEX_KEY << endl;
    return 1;
  }

  sem = ulapi_sem_new(SEM_KEY);
  if (NULL == sem) {
    cerr << "Can't create semaphore for key " << SEM_KEY << endl;
    return 1;
  }

  shm = ulapi_shm_new(SHM_KEY, sizeof(shared_struct));
  if (NULL == shm) {
    cerr << "Can't create shared memory for key " << SHM_KEY << endl;
    return 1;
  }
  shared_ptr = reinterpret_cast<shared_struct *>(ulapi_shm_addr(shm));

  ulapi_task_init(&writer_task);

  args_ptr = new args_struct;
  args_ptr->mutex = mutex;
  args_ptr->sem = sem;
  args_ptr->shared = shared_ptr;

  ulapi_task_start(&writer_task,
		   reinterpret_cast<ulapi_task_code>(writer),
		   reinterpret_cast<void *>(args_ptr),
		   ulapi_prio_highest(), 
		   0);

  ulapi_task_init(&reader_task);

  // reuse this pointer, since the writer will be deleting it by now
  args_ptr = new args_struct;
  args_ptr->mutex = mutex;
  args_ptr->sem = sem;
  args_ptr->shared = shared_ptr;

  ulapi_task_start(&reader_task,
		   reinterpret_cast<ulapi_task_code>(reader),
		   reinterpret_cast<void *>(args_ptr),
		   ulapi_prio_lowest(), 
		   0);

  // wait for writer to finish
  ulapi_task_join(&writer_task, &writer_ret);

  // now wait for reader to finish
  ulapi_task_join(&reader_task, &reader_ret);

  cout << "Test done with values " << writer_ret << " and " << reader_ret << endl;

  return 0;
}
