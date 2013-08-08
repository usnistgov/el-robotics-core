# this is example-file: src/interpreter/Makefile.am

# additional include paths necessary to compile the C++ library
#AM_CXXFLAGS = -I$(top_srcdir)/src/database -Wall -Wextra @AM_CXXFLAGS@ 

AM_CXXFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/../../AutoGen -I$(top_srcdir)/../../objectGen/include -g


###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

noinst_LIBRARIES = libinterpreter.a

# where to install the headers on the system
#libinterpreter_adir = $(top_srcdir)/src/interpreter
libinterpreter_adir = $(top_srcdir)/src/interpreter
#libinterpreter_adir = $(top_srcdir)/lib

# the list of header files that belong to the library (to be installed later)
libinterpreter_a_HEADERS = IniFile.h \
CanonicalRobotCommand.h \
KittingPDDLProblem.h \
KittingPlan.h \
Operator.h  \
DatabaseUpdate.h

libinterpreter_a_SOURCES = $(libinterpreter_a_HEADERS) \
			IniFile.cc \
			CanonicalRobotCommand.cc \
			KittingPDDLProblem.cc \
			KittingPlan.cc \
			Operator.cc \
			DatabaseUpdate.cpp

#INCLUDES = -I$(top_srcdir)/src/database

#INCLUDE = -I@top_srcdir@/

