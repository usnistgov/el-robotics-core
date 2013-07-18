# initial information about the project
AC_INIT([executor], [1.0], [zeid.kootbally@nist.gov])

# check if the source folder is available
AC_CONFIG_SRCDIR([src/main.cc])

# check for C++ preprocessor and compiler
AC_PROG_CXX
AC_PROG_CXXCPP
AC_PROG_RANLIB


# use the C++ compiler for the following checks
AC_LANG([C++])

# distribute additional compiler and linker flags among Makefiles
# --> set and change these variables instead of CXXFLAGS or LDFLAGS (for user only)
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([LIBS])

# files to generate via autotools (prepare .am or .in source files)
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])
AC_CONFIG_FILES([src/interpreter/Makefile])
#AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([bin/Makefile])
# Checks for header files.
AC_CONFIG_AUX_DIR([config])

# automake initialization (mandatory) including a check for automake API version >= 1.9
AM_INIT_AUTOMAKE([1.11])


# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([string])
AC_CHECK_HEADERS([iostream])
AC_CONFIG_HEADERS([config/config.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T


#AM_INIT_AUTOMAKE(executor, 1.0)



AC_PROG_INSTALL
#AC_PROG_LIBTOOL

# Checks the platform.
ACX_HOST



AC_OUTPUT
