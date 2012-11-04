AC_DEFUN([ACX_HOST], [
	AC_CANONICAL_HOST
	if test x$host_os = xcygwin ; then
	AC_DEFINE(HAVE_CYGWIN, 1, [Define non-zero if you have Cygwin.])
	elif test x$host_os = xlinux-gnu ; then
	     AC_DEFINE(HAVE_LINUX, 1, [Define non-zero if you have Linux.])
	fi
	AM_CONDITIONAL(HAVE_CYGWIN, test x$host_os = xcygwin)
	AM_CONDITIONAL(HAVE_LINUX, test x$host_os = xlinux-gnu)
	])
