#!/bin/sh

touch NEWS README AUTHORS ChangeLog
mkdir config src lib bin

cat > autoconf.sh <<EOF
aclocal && autoheader && automake --add-missing --copy && autoconf && ./configure CFLAGS="-g -Wall" CXXFLAGS="-g -Wall"
EOF
chmod a+x autoconf.sh

cat > acinclude.m4 <<EOF
AC_DEFUN([ACX_HOST], [
	AC_CANONICAL_HOST
	if test x\$host_os = xcygwin ; then
	AC_DEFINE(HAVE_CYGWIN, 1, [Define non-zero if you have Cygwin.])
	elif test x\$host_os = xlinux-gnu ; then
	     AC_DEFINE(HAVE_LINUX, 1, [Define non-zero if you have Linux.])
	fi
	AM_CONDITIONAL(HAVE_CYGWIN, test x\$host_os = xcygwin)
	AM_CONDITIONAL(HAVE_LINUX, test x\$host_os = xlinux-gnu)
	])
EOF

cat > configure.ac <<EOF
AC_INIT(main, 1.0)
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE(main, 1.0)
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config/config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks the platform.
ACX_HOST

AC_CONFIG_FILES([Makefile lib/Makefile bin/Makefile])

AC_OUTPUT
EOF

cat > Makefile.am <<EOF
SUBDIRS = lib bin
EOF

cat > config/README <<EOF
This directory contains auto-generated configuration files
EOF

cat > lib/Makefile.am <<EOF
lib_LIBRARIES = libhello.a
libhello_a_SOURCES = ../src/hello.c ../src/hello.h
EOF

cat > bin/Makefile.am <<EOF
bin_PROGRAMS = main
main_SOURCES = ../src/main.c
main_LDADD = -L../lib -lhello
EOF

cat > src/hello.c <<EOF
char *hello(void)
{
  return "hello, world";
}
EOF

cat > src/hello.h <<EOF
extern char *hello(void);
EOF
cat > src/main.c <<EOF
#include <stdio.h>
#include "hello.h"

int main(void)
{
  printf("%s\n", hello());
  return 0;
}
EOF

exit 0
