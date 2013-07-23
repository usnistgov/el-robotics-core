#AM_CXXFLAGS = -O3 -I$(top_srcdir)/src/ -I$(top_srcdir)/src/database/ -I$(top_srcdir)/src/interpreter/ @AM_CXXFLAGS@
AM_CXXFLAGS = -O3  @AM_CXXFLAGS@

INCLUDES = -I$(top_srcdir)/src/ -I$(top_srcdir)/src/database -I$(top_srcdir)/src/interpreter -I$(top_srcdir)/../../objectGen/include -I$(top_srcdir)/../../AutoGen
#LDADD = $(top_srcdir)/src/database/libdatabase.a \
#$(top_srcdir)/src/interpreter/libinterpreter.a

bin_PROGRAMS = executor
executor_SOURCES = $(top_srcdir)/src/main.cc $(top_srcdir)/../../objectGen/src/recurseLocation.cpp $(topsrcdir)/src/interpreter/libinterpreter.a
executor_LDADD = -L$(top_srcdir)/../../AutoGen -L$(top_srcdir)/src/interpreter  -linterpreter -lsqlKit -lmysqlcppconn
executor_DEPENDENCIES = ../src/interpreter/libinterpreter.a

