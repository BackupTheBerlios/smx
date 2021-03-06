#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT(smx, 1.1.4, bugs@smxlang.org)
AC_CONFIG_SRCDIR([config.h.in])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

# what does this do
AM_MAINTAINER_MODE

# Checks for libraries.
AC_CHECK_LIB([crypt], [crypt])
AC_CHECK_LIB([crypto], [EVP_EncodeBlock])
AC_CHECK_LIB([odbc], [SQLConnect],[],[
        echo "Error! libodbc is required"
        exit -1
])
AC_CHECK_LIB([sqlite3], [sqlite3_open])
AC_CHECK_LIB([pthread], [pthread_create])
AC_CHECK_LIB([gd], [gdImageCreate])
AC_CHECK_LIB([stdc++], [main],[],[
        echo "Error! libstdc++ is required"
        exit -1
])
AC_CHECK_LIB([tdb], [tdb_fetch])

# sets apache version & include paths
APACHE_APXS
APACHE_APR
AC_SUBST(APXS)
CPPFLAGS="$CPPFLAGS -I $APXS_INCLUDE -I $APR_INCLUDE"

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h fcntl.h limits.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdlib.h string.h sys/file.h sys/ioctl.h sys/socket.h sys/time.h unistd.h wchar.h wctype.h sqlite3.h sql.h pthread.h openssl/evp.h tdb.h signal.h gd.h])

# sets PERL var to full path
AC_PATH_PROG(PERL, perl)

# sets HAVE_PERL conditional
AM_CONDITIONAL(HAVE_PERL, test -n "$PERL")

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_STRUCT_TM

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_FORK
AC_FUNC_MEMCMP
AC_FUNC_MKTIME
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_STAT
AC_FUNC_STRERROR_R
AC_FUNC_STRTOD
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([bzero dup2 gethostbyname gettimeofday inet_ntoa memchr memmove memset mkdir pow putenv rmdir select setenv socket sqrt strchr strerror strpbrk strrchr strspn strstr strtol strtoul tzset])

AC_CONFIG_FILES([Makefile smx/Makefile libsmx/Makefile extperl/Makefile modsmx/Makefile smx.spec])
AC_OUTPUT
