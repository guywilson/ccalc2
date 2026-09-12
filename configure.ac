AC_PREREQ([2.69])
AC_INIT([vbuild], [1.0], [https://github.com/guywilson/ccalc2/issues])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_PROG_CC
AC_PROG_CXX

dnl Keep dependency probes in C++ mode, as the application includes these headers.
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([readline/readline.h readline/history.h gmp.h mpfr.h], [],
  [AC_MSG_ERROR([missing required header; install the development dependencies or set CPPFLAGS=-I/path/to/include])])

dnl Probe providers before consumers so that static-library link order is valid.
AC_SEARCH_LIBS([tgetent], [tinfo ncurses curses], [],
  [AC_MSG_ERROR([a curses/terminfo development library is required])])
AC_CHECK_LIB([history], [add_history], [], [AC_MSG_ERROR([GNU History is required])])
AC_CHECK_LIB([readline], [readline], [], [AC_MSG_ERROR([GNU Readline is required])])
dnl GMP's public names are macros; probe an exported linker symbol.
AC_CHECK_LIB([gmp], [__gmpz_init], [], [AC_MSG_ERROR([libgmp is required])])
AC_CHECK_LIB([mpfr], [mpfr_get_version], [], [AC_MSG_ERROR([libmpfr is required])])
AC_LANG_POP([C++])

AC_PATH_PROG([PANDOC], [pandoc])
AS_IF([test -z "$PANDOC"], [
    AC_MSG_ERROR([pandoc is required to build the manual page])
])

AC_SUBST([MAJOR_VERSION], [1])
AC_SUBST([MINOR_VERSION], [0])
AC_CONFIG_FILES([makefile])
AC_OUTPUT
