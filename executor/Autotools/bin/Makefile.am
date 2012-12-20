#AM_CXXFLAGS = -O3 -I$(top_srcdir)/src/ -I$(top_srcdir)/src/database/ -I$(top_srcdir)/src/interpreter/ @AM_CXXFLAGS@
AM_CXXFLAGS = -O3  @AM_CXXFLAGS@

INCLUDES = -I$(top_srcdir)/src/ -I$(top_srcdir)/src/database -I$(top_srcdir)/src/interpreter -I$(top_srcdir)/../../objectGen/include
#LDADD = $(top_srcdir)/src/database/libdatabase.a \
#$(top_srcdir)/src/interpreter/libinterpreter.a

bin_PROGRAMS = executor
executor_SOURCES = $(top_srcdir)/src/main.cc $(top_srcdir)/../../objectGen/src/recurseLocation.cpp
executor_LDADD = -L$(top_srcdir)/src/database -L$(top_srcdir)/src/interpreter  -linterpreter -ldatabase -lmysqlcppconn

