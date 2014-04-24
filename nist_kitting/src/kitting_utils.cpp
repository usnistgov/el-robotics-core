#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 

#include "nist_kitting/kitting_utils.h"

double etime()
{
  using namespace boost::posix_time;

  time_duration t = microsec_clock::local_time() - ptime(min_date_time);
  return 1.0e-6 * t.total_microseconds();
}

#define ROUND(x) ((x) >= 0.0 ? (int) ((x) + 0.5) : (int) ((x) - 0.5))

void esleep(double secs)
{
  boost::this_thread::sleep(boost::posix_time::microseconds(ROUND(secs * 1e6)));
}
