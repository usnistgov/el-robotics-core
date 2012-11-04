# the program to build (the names of the final binaries)
#bin_PROGRAMS = executor

# list of sources for the 'executor' binary
#executor_SOURCES = main.cc

# additional include paths necessary to compile the C++ library
#AM_CXXFLAGS = -I$(top_srcdir)/src/database -Wall @AM_CXXFLAGS@
#AM_CPPFLAGS = -I$(top_srcdir)/include/database -Wall @AM_CXXFLAGS@

SUBDIRS = database \
interpreter

#executor_LDADD = $(top_builddir)/lib/libinterpreter.a  $(top_builddir)/lib/libdatabase.a $(AM_LDFLAGS) 
#executor_LDADD = $(top_builddir)/src/database/libdatabase.a $(AM_LDFLAGS) 

##########################################################################
# adding the mysqlcppconn library (e.g. with static name 'libmysqlcppconn.a')
##########################################################################

## adding the lib to the files to link
#LIBS="-lmysqlcppconn $LIBS"

## introduce the optional configure parameter for a non-standard install prefix of mysqlcppconn
#AC_ARG_WITH([mysqlcppconn],
#	[AS_HELP_STRING([--with-mysqlcppconn],
#	[try this for a non-standard install prefix of the mysqlcppconn library])],
#	[mysqlcppconnPATHSET=1],
#	[mysqlcppconnPATHSET=0])
	
## if optional parameter used, extend path flags for compliler and linker
#if test $mysqlcppconnPATHSET = 1 ; then
#    # extend the compiler and linker flags according to the path set
#    AM_CXXFLAGS="$AM_CXXFLAGS -I$with_mysqlcppconn/include"
#    AM_LDFLAGS="$AM_LDFLAGS -L$with_mysqlcppconn/lib"
#fi

##########################################################################