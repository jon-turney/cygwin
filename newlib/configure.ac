dnl This is the newlib configure.in file.
dnl Process this file with autoconf to produce a configure script.

AC_INIT([newlib],[NEWLIB_VERSION])
AC_CONFIG_SRCDIR([libc])

dnl Since we can't control what defines autoheader picks up (various autoconf
dnl macros will add their own), filter out all the ones w/out a _ prefix.  All
dnl the ones we want to export use a _ prefix, and all the rest we don't want
dnl to export as it'll pollute the namespace of newlib users.
dnl We also filter out version defines that we want in _newlib_version.h.
dnl NB: newlib.h must be the first AC_CONFIG_HEADERS call for autoheader.
AC_CONFIG_HEADERS(
  [newlib.h:newlib.hin],
  [sed -i.tmp -E -e '/^#define [^_]/d' -e '/^\/\* #undef [^_]/d' -e '/_NEWLIB_VERSION|__NEWLIB_(MINOR|PATCHLEVEL)__|__NEWLIB__/d' newlib.h && rm -f newlib.h.tmp])
AH_TOP([/* NB: The contents are filtered before being installed. */

#ifndef __NEWLIB_H__
#define __NEWLIB_H__ 1

/* Newlib version */
#include <_newlib_version.h>])
AH_BOTTOM([#endif /* !__NEWLIB_H__ */])

AC_CONFIG_HEADERS([_newlib_version.h:_newlib_version.hin])

dnl Can't be done in NEWLIB_CONFIGURE because that confuses automake. 
AC_CONFIG_AUX_DIR(..)

dnl Support --enable-newlib-io-pos-args
dnl This option is actually read in libc/configure.in.  It is repeated
dnl here so that it shows up in the help text.
AC_ARG_ENABLE(newlib-io-pos-args,
[  --enable-newlib-io-pos-args enable printf-family positional arg support],
[case "${enableval}" in
  yes) newlib_io_pos_args=yes ;;
  no)  newlib_io_pos_args=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-io-pos-args option) ;;
 esac], [newlib_io_pos_args=])dnl

dnl Support --enable-newlib-io-c99-formats
AC_ARG_ENABLE(newlib-io-c99-formats,
[  --enable-newlib-io-c99-formats   enable C99 support in IO functions like printf/scanf],
[case "${enableval}" in
  yes) newlib_io_c99_formats=yes;;
  no)  newlib_io_c99_formats=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-io-c99-formats option) ;;
 esac], [newlib_io_c99_formats=])dnl

dnl Support --enable-newlib-register-fini
AC_ARG_ENABLE(newlib-register-fini,
[  --enable-newlib-register-fini   enable finalization function registration using atexit],
[case "${enableval}" in
  yes) newlib_register_fini=yes;;
  no)  newlib_register_fini=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-register-fini option) ;;
 esac], [newlib_register_fini=])dnl

dnl Support --enable-newlib-io-long-long
AC_ARG_ENABLE(newlib-io-long-long,
[  --enable-newlib-io-long-long   enable long long type support in IO functions like printf/scanf],
[case "${enableval}" in
  yes) newlib_io_long_long=yes;;
  no)  newlib_io_long_long=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-io-long-long option) ;;
 esac], [newlib_io_long_long=])dnl

dnl Support --enable-newlib-io-long-double
AC_ARG_ENABLE(newlib-io-long-double,
[  --enable-newlib-io-long-double   enable long double type support in IO functions printf/scanf],
[case "${enableval}" in
  yes) newlib_io_long_double=yes;;
  no)  newlib_io_long_double=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-io-long-double option) ;;
 esac], [newlib_io_long_double=])dnl

dnl If multibyte support is enabled, iconv should be enabled too
dnl Support --enable-newlib-mb
AC_ARG_ENABLE(newlib-mb,
[  --enable-newlib-mb        enable multibyte support],
[case "${enableval}" in
  yes) newlib_mb=yes;;
  no)  newlib_mb=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-mb option) ;;
 esac], [newlib_mb=])dnl

dnl Enable verification of successful memory allocation for _REENT_CHECK family of macros
dnl Support --disable-newlib-reent-check-verify
AC_ARG_ENABLE(newlib-reent-check-verify,
[  --disable-newlib-reent-check-verify        disable checking of _REENT_CHECK memory allocation],
[case "${enableval}" in
  yes) newlib_reent_check_verify=yes;;
  no)  newlib_reent_check_verify=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-reent-check-verify option) ;;
 esac], [newlib_reent_check_verify=])dnl

dnl Support --enable-newlib-iconv-encodings
AC_ARG_ENABLE(newlib-iconv-encodings,
[  --enable-newlib-iconv-encodings   enable specific comma-separated list of bidirectional iconv encodings to be built-in],
[if test x${enableval} = x; then
   AC_MSG_ERROR(bad value ${enableval} for newlib-iconv-encodings option - use comma-separated encodings list)
 fi
 iconv_encodings=${enableval}
 ], [iconv_encodings=])dnl

dnl Support --enable-newlib-iconv-from-encodings
AC_ARG_ENABLE(newlib-iconv-from-encodings,
[  --enable-newlib-iconv-from-encodings   enable specific comma-separated list of \"from\" iconv encodings to be built-in],
[if test x${enableval} = x; then
   AC_MSG_ERROR(bad value ${enableval} for newlib-iconv-from-encodings option - use comma-separated encodings list)
 fi
 iconv_from_encodings=${enableval}
 ], [iconv_from_encodings=])dnl

dnl Support --enable-newlib-iconv-to-encodings
AC_ARG_ENABLE(newlib-iconv-to-encodings,
[  --enable-newlib-iconv-to-encodings   enable specific comma-separated list of \"to\" iconv encodings to be built-in],
[if test x${enableval} = x; then
   AC_MSG_ERROR(bad value ${enableval} for newlib-iconv-to-encodings option - use comma-separated encodings list)
 fi
 iconv_to_encodings=${enableval}
 ], [iconv_to_encodings=])dnl

dnl Support --enable-newlib-iconv-external-ccs
AC_ARG_ENABLE(newlib-iconv-external-ccs,
[  --enable-newlib-iconv-external-ccs     enable capabilities to load external CCS files for iconv],
[if test "${newlib_iconv_external_ccs+set}" != set; then
   case "${enableval}" in
     yes) newlib_iconv_external_ccs=yes ;;
     no)  newlib_iconv_external_ccs=no ;;
     *)   AC_MSG_ERROR(bad value ${enableval} for newlib-iconv-external-ccs option) ;;
   esac
 fi], [newlib_iconv_external_ccs=${newlib_iconv_external_ccs}])dnl

dnl Support --disable-newlib-atexit-dynamic-alloc
AC_ARG_ENABLE(newlib-atexit-dynamic-alloc,
[  --disable-newlib-atexit-dynamic-alloc    disable dynamic allocation of atexit entries],
[if test "${newlib_atexit_dynamic_alloc+set}" != set; then
  case "${enableval}" in
    yes) newlib_atexit_dynamic_alloc=yes ;;
    no)  newlib_atexit_dynamic_alloc=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-atexit-dynamic-alloc option) ;;
  esac
 fi], [newlib_atexit_dynamic_alloc=${newlib_atexit_dynamic_alloc}])dnl

dnl Support --enable-newlib-global-atexit
dnl Enable atexit data structure as global variables to save memory usage in
dnl _reent.  This is no longer optional.  It is enabled in all Newlib
dnl configurations.
AC_ARG_ENABLE(newlib-global-atexit,
[  --enable-newlib-global-atexit	enable atexit data structure as global],
[if test "${newlib_global_atexit+set}" != set; then
  case "${enableval}" in
    yes) newlib_global_atexit=yes ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-global-atexit option) ;;
  esac
 fi], [newlib_global_atexit=yes])dnl

dnl Support --enable-newlib-reent-small
AC_ARG_ENABLE(newlib-reent-small,
[  --enable-newlib-reent-small   enable small reentrant struct support],
[case "${enableval}" in
  yes) newlib_reent_small=yes;;
  no)  newlib_reent_small=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-reent-small option) ;;
 esac], [newlib_reent_small=])dnl

dnl Support --enable-newlib-reent-binary-compat
AC_ARG_ENABLE(newlib-reent-binary-compat,
[  --enable-newlib-reent-binary-compat   enable backward binary compatibility for struct _reent],
[if test "${newlib_reent_binary_compat+set}" != set; then
  case "${enableval}" in
    yes) newlib_reent_binary_compat=yes ;;
    no)  newlib_reent_binary_compat=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-enable-reent-binary-compat option) ;;
  esac
 fi], [newlib_reent_binary_compat=no])dnl

dnl Support --enable-newlib-reent-thread-local
AC_ARG_ENABLE(newlib-reent-thread-local,
[  --enable-newlib-reent-thread-local   enable thread-local storage objects as a replacment for struct _reent members],
[if test "${newlib_reent_thread_local+set}" != set; then
  case "${enableval}" in
    yes) newlib_reent_thread_local=yes ;;
    no)  newlib_reent_thread_local=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-enable-reent-thread-local option) ;;
  esac
 fi], [newlib_reent_thread_local=no])dnl

dnl Support --enable-newlib-global-stdio-streams
dnl This is no longer optional.  It is enabled in all Newlib configurations.
AC_ARG_ENABLE(newlib-global-stdio-streams,
[  --enable-newlib-global-stdio-streams   enable global stdio streams],
[case "${enableval}" in
  yes) newlib_global_stdio_streams=yes;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-global-stdio-streams option) ;;
 esac], [newlib_global_stdio_streams=yes])dnl
 
dnl Support --disable-newlib-fvwrite-in-streamio
AC_ARG_ENABLE(newlib-fvwrite-in-streamio,
[  --disable-newlib-fvwrite-in-streamio    disable iov in streamio],
[if test "${newlib_fvwrite_in_streamio+set}" != set; then
  case "${enableval}" in
    yes) newlib_fvwrite_in_streamio=yes ;;
    no)  newlib_fvwrite_in_streamio=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-fvwrite-in-streamio option) ;;
  esac
 fi], [newlib_fvwrite_in_streamio=yes])dnl

dnl Support --disable-newlib-fseek-optimization
AC_ARG_ENABLE(newlib-fseek-optimization,
[  --disable-newlib-fseek-optimization    disable fseek optimization],
[if test "${newlib_fseek_optimization+set}" != set; then
  case "${enableval}" in
    yes) newlib_fseek_optimization=yes ;;
    no)  newlib_fseek_optimization=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-fseek-optimization option) ;;
  esac
 fi], [newlib_fseek_optimization=yes])dnl
 
dnl Support --enable-newlib-wide-orient
dnl This option is also read in libc/configure.in.  It is repeated
dnl here so that it shows up in the help text.
AC_ARG_ENABLE(newlib_wide_orient,
[  --disable-newlib-wide-orient    Turn off wide orientation in streamio],
[case "${enableval}" in
   yes) newlib_wide_orient=yes ;;
   no)  newlib_wide_orient=no ;;
   *) AC_MSG_ERROR(bad value ${enableval} for newlib-wide-orient) ;;
 esac],[newlib_wide_orient=yes])

dnl Support --enable-newlib-nano-malloc
dnl This option is also read in libc/configure.in.  It is repeated
dnl here so that it shows up in the help text.
AC_ARG_ENABLE(newlib-nano-malloc,
[  --enable-newlib-nano-malloc    use small-footprint nano-malloc implementation],
[if test "${newlib_nano_malloc+set}" != set; then
  case "${enableval}" in
    yes) newlib_nano_malloc=yes ;;
    no)  newlib_nano_malloc=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-nano-malloc option) ;;
  esac
 fi], [newlib_nano_malloc=])dnl
AM_CONDITIONAL(NEWLIB_NANO_MALLOC, test x$newlib_nano_malloc = xyes)

dnl Support --disable-newlib-unbuf-stream-opt
AC_ARG_ENABLE(newlib-unbuf-stream-opt,
[  --disable-newlib-unbuf-stream-opt    disable unbuffered stream optimization in streamio],
[if test "${newlib_unbuf_stream_opt+set}" != set; then
  case "${enableval}" in
    yes) newlib_unbuf_stream_opt=yes ;;
    no)  newlib_unbuf_stream_opt=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-unbuf-stream-opt option) ;;
  esac
 fi], [newlib_unbuf_stream_opt=yes])dnl

dnl Support --enable-lite-exit
dnl Lite exit is a size-reduced implementation of exit that doesn't invoke
dnl clean-up functions such as _fini or global destructors.
AC_ARG_ENABLE(lite-exit,
[  --enable-lite-exit	enable light weight exit],
[if test "${lite_exit+set}" != set; then
  case "${enableval}" in
    yes) lite_exit=yes ;;
    no)  lite_exit=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for lite-exit option) ;;
  esac
 fi], [lite_exit=no])dnl

dnl Support --enable-newlib-nano-formatted-io
dnl This option is also read in libc/configure.in.  It is repeated
dnl here so that it shows up in the help text.
AC_ARG_ENABLE(newlib_nano_formatted_io,
[  --enable-newlib-nano-formatted-io    Use small-footprint nano-formatted-IO implementation],
[case "${enableval}" in
   yes) newlib_nano_formatted_io=yes ;;
   no)  newlib_nano_formatted_io=no ;;
   *) AC_MSG_ERROR(bad value ${enableval} for newlib-nano-formatted-io) ;;
 esac],[newlib_nano_formatted_io=no])
AM_CONDITIONAL(NEWLIB_NANO_FORMATTED_IO, test x$newlib_nano_formatted_io = xyes)

dnl Support --enable-retargetable-locking
dnl This option is also read in libc/configure.in.  It is repeated
dnl here so that it shows up in the help text.
AC_ARG_ENABLE(newlib-retargetable-locking,
[  --enable-newlib-retargetable-locking    Allow locking routines to be retargeted at link time],
[case "${enableval}" in
   yes) newlib_retargetable_locking=yes ;;
   no)  newlib_retargetable_locking=no ;;
   *) AC_MSG_ERROR(bad value ${enableval} for newlib-retargetable-locking) ;;
 esac],[newlib_retargetable_locking=no])
AM_CONDITIONAL(NEWLIB_RETARGETABLE_LOCKING, test x$newlib_retargetable_locking = xyes)

dnl Support --enable-newlib-long-time_t
AC_ARG_ENABLE(newlib-long-time_t,
[  --enable-newlib-long-time_t   define time_t to long],
[if test "${newlib_long_time_t+set}" != set; then
  case "${enableval}" in
    yes) newlib_long_time_t=yes ;;
    no)  newlib_long_time_t=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-long-time_t option) ;;
  esac
 fi], [newlib_long_time_t=no])dnl

dnl Support --enable-newlib-use-gdtoa
AC_ARG_ENABLE(newlib-use-gdtoa,
[  --enable-newlib-use-gdtoa   Use gdtoa rather than legacy ldtoa],
[if test "${newlib_use_gdtoa+set}" != set; then
  case "${enableval}" in
    yes) newlib_use_gdtoa=yes ;;
    no)  newlib_use_gdtoa=no  ;;
    *)   AC_MSG_ERROR(bad value ${enableval} for newlib-use-gdtoa option) ;;
  esac
 fi], [newlib_use_gdtoa=yes])dnl

dnl Support --enable-newlib-use-malloc-in-execl
AC_ARG_ENABLE(newlib-use-malloc-in-execl,
[  --enable-newlib-use-malloc-in-execl   use malloc instead of alloca in execl, execle and execlp],
[case "${enableval}" in
  yes) newlib_use_malloc_in_execl=yes;;
  no)  newlib_use_malloc_in_execl=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-use-malloc-in-execl option) ;;
 esac], [newlib_use_malloc_in_execl=no])dnl

dnl Support --enable-newlib-hw-misaligned-access
AC_ARG_ENABLE(newlib-hw-misaligned-access,
[  --enable-newlib-hw-misaligned-access   Use hardware word-by-word access instead of byte-by-byte for misaligned memory ],
[if test "${newlib_hw_misaligned_access+set}" != set; then
  case "${enableval}" in
  yes) newlib_hw_misaligned_access=yes;;
  no)  newlib_hw_misaligned_access=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for newlib-hw-misaligned-access option) ;;
  esac
 fi], [newlib_hw_misaligned_access=])dnl

AM_ENABLE_MULTILIB(, ..)
NEWLIB_CONFIGURE(.)

dnl The following is being disabled because the mathfp library is
dnl not up to standard due to inaccuracies caused by some of the
dnl floating-point algorithms used.  If you wish to work on this,
dnl comment out the following line and uncomment out the lines
dnl following it to re-enable the feature.
newlib_hw_fp=false
#AC_ARG_ENABLE(newlib_hw_fp,
#[  --enable-newlib-hw-fp    Turn on hardware floating point math],
#[case "${enableval}" in
#   yes) newlib_hw_fp=true ;;
#   no)  newlib_hw_fp=false ;;
#   *) AC_MSG_ERROR(bad value ${enableval} for --enable-newlib-hw-fp) ;;
# esac],[newlib_hw_fp=false])
AM_CONDITIONAL(NEWLIB_HW_FP, test x$newlib_hw_fp = xtrue)

# These get added in the top-level configure.in, except in the case where
# newlib is being built natively.
LIBC_INCLUDE_GREP=`echo ${CC} | grep \/libc\/include`
if test -z "${LIBC_INCLUDE_GREP}"; then
  CC_FOR_NEWLIB="${CC} -I$PWD/targ-include -I${abs_newlib_basedir}/libc/include"
else
  CC_FOR_NEWLIB="${CC}"
fi
AC_SUBST(CC_FOR_NEWLIB)

m4_include([libc/acinclude.m4])
m4_include([libm/acinclude.m4])

if test -z "${with_multisubdir}"; then
  have_multisubdir=no
else
  have_multisubdir=yes
fi
AM_CONDITIONAL(HAVE_DOC, test x$have_multisubdir = xno)

# Some run-time support libraries provided by GCC (e.g. libgomp) use configure
# checks to detect certain features, e.g. availability of thread-local storage.
# The configure script generates a test program and tries to compile and link
# it.  It should use target libraries and startfiles of the build tree if
# available and not random ones from the installation prefix for this
# procedure.  The search directories specified by -B are a bit special, see
# for_each_path() in gcc.c of the GCC sources.  First a search is performed on
# all search paths with the multilib directory appended (if desired), then a
# second search is performed on demand with the base directory only.  For each
# multilib there is a "newlib" subdirectory.  This directory is specified by a
# -B option for the support libraries.  In order to find the newlib artifacts
# (ctr0.o, libc.a, libg.a and libm.a) they must be located in a proper multilib
# subdirectory withing the build directory.
AM_CONDITIONAL(HAVE_MULTISUBDIR, test x$have_multisubdir = xyes)

CRT0=
CRT0_DIR=
if test "x${have_crt0}" = "xyes"; then
  CRT0=crt0.o
  CRT0_DIR=libc/sys/${sys_dir}/
fi
AM_CONDITIONAL(HAVE_CRT0, test x$have_crt0 = xyes)
AC_SUBST(CRT0)
AC_SUBST(CRT0_DIR)

CRT1=${crt1}
CRT1_DIR=
if test -n "${crt1_dir}"; then
  CRT1_DIR=${crt1_dir}/
fi
AC_SUBST(CRT1)
AC_SUBST(CRT1_DIR)

# Put a plausible default for CC_FOR_BUILD in Makefile.
if test -z "$CC_FOR_BUILD"; then
  if test "x$cross_compiling" = "xno"; then
    CC_FOR_BUILD='$(CC)'
  else
    CC_FOR_BUILD=gcc
  fi
fi
AC_SUBST(CC_FOR_BUILD)

# Also set EXEEXT_FOR_BUILD.
if test "x$cross_compiling" = "xno"; then
  EXEEXT_FOR_BUILD='$(EXEEXT)'
else
  AC_CACHE_CHECK([for build system executable suffix], newlib_cv_build_exeext,
    [cat > ac_c_test.c << 'EOF'
int main() {
/* Nothing needed here */
}
EOF
    ${CC_FOR_BUILD} -o ac_c_test am_c_test.c 1>&5 2>&5
    newlib_cv_build_exeext=`echo ac_c_test.* | grep -v ac_c_test.c | sed -e s/ac_c_test//`
    rm -f ac_c_test*
    test x"${newlib_cv_build_exeext}" = x && newlib_cv_build_exeext=no])
  EXEEXT_FOR_BUILD=""
  test x"${newlib_cv_build_exeext}" != xno && EXEEXT_FOR_BUILD=${newlib_cv_build_exeext}
fi
AC_SUBST(EXEEXT_FOR_BUILD)

AC_DEFINE(_NEWLIB_VERSION, "NEWLIB_VERSION", [The newlib version in string format.])
AC_DEFINE(__NEWLIB__, NEWLIB_MAJOR_VERSION, [The newlib major version number.])
AC_DEFINE(__NEWLIB_MINOR__, NEWLIB_MINOR_VERSION, [The newlib minor version number.])
AC_DEFINE(__NEWLIB_PATCHLEVEL__, NEWLIB_PATCHLEVEL_VERSION, [The newlib patch level.])

if test "${newlib_elix_level}" -gt "0"; then
  AC_DEFINE_UNQUOTED(_ELIX_LEVEL, ${newlib_elix_level}, [EL/IX level])
fi

if test "${newlib_reent_check_verify}" = "yes"; then
  AC_DEFINE(_REENT_CHECK_VERIFY, 1, [Verify _REENT_CHECK macros allocate memory successfully.])
fi

if test "${newlib_io_c99_formats}" = "yes"; then
  AC_DEFINE(_WANT_IO_C99_FORMATS, 1, [Enable C99 formats support (e.g. %a, %zu, ...) in IO functions like printf/scanf.])
fi

if test "${newlib_register_fini}" = "yes"; then
  AC_DEFINE(_WANT_REGISTER_FINI, 1, [Register application finalization function using atexit.])
fi

if test "${newlib_io_long_long}" = "yes"; then
  AC_DEFINE(_WANT_IO_LONG_LONG, 1, [Define to enable long long type support in IO functions like printf/scanf.])
fi

if test "${newlib_io_long_double}" = "yes"; then
  AC_DEFINE(_WANT_IO_LONG_DOUBLE, 1, [Define to enable long double type support in IO functions like printf/scanf.])
fi

if test "${newlib_io_pos_args}" = "yes"; then
  AC_DEFINE(_WANT_IO_POS_ARGS, 1, [Positional argument support in printf functions enabled.])
fi

if test "${newlib_reent_small}" = "yes"; then
  AC_DEFINE(_WANT_REENT_SMALL, 1, [Optional reentrant struct support.  Used mostly on platforms with very restricted storage.])
fi

if test "${newlib_reent_binary_compat}" = "yes"; then
  AC_DEFINE(_WANT_REENT_BACKWARD_BINARY_COMPAT, 1, [Define to enable backward binary compatibility for struct _reent.])
fi

if test "${newlib_reent_thread_local}" = "yes"; then
  AC_DEFINE(_WANT_REENT_THREAD_LOCAL, 1, [Define to enable thread-local storage objects as a replacment for struct _reent members.])
fi

_mb_len_max=1
if test "${newlib_mb}" = "yes"; then
  AC_DEFINE(_MB_CAPABLE, 1, [Multibyte supported.])
  _mb_len_max=8
fi
AC_DEFINE_UNQUOTED(_MB_LEN_MAX, $_mb_len_max, [Multibyte max length.])

dnl These are AC_SUBST instead of AC_DEFINE as they're hand maintained in a
dnl dedicated _newlib_version.h, and we don't want them in newlib.h.
AC_SUBST([NEWLIB_VERSION])
AC_SUBST([NEWLIB_MAJOR_VERSION])
AC_SUBST([NEWLIB_MINOR_VERSION])
AC_SUBST([NEWLIB_PATCHLEVEL_VERSION])

if test "${newlib_iconv}" = "yes"; then
  AC_DEFINE(_ICONV_ENABLED, 1, [ICONV enabled.])
fi

if test "x${newlib_iconv_external_ccs}" = "xyes"; then
  if test "x${newlib_iconv}" = "x"; then
      AC_MSG_ERROR(--enable-newlib-iconv-external-ccs option can't be used if iconv library is disabled, use --enable-newlib-iconv to enable it.)
  fi
  AC_DEFINE(_ICONV_ENABLE_EXTERNAL_CCS, 1, [Enable ICONV external CCS files loading capabilities.])
fi

if test "${newlib_atexit_dynamic_alloc}" = "yes"; then
  AC_DEFINE(_ATEXIT_DYNAMIC_ALLOC, 1, [If atexit() may dynamically allocate space for cleanup functions.])
fi

if test "${newlib_fvwrite_in_streamio}" = "yes"; then
  AC_DEFINE(_FVWRITE_IN_STREAMIO, 1, [Define if ivo supported in streamio.])
fi

if test "${newlib_fseek_optimization}" = "yes"; then
  AC_DEFINE(_FSEEK_OPTIMIZATION, 1, [Define if fseek functions support seek optimization.])
fi

if test "${newlib_wide_orient}" = "yes"; then
  AC_DEFINE(_WIDE_ORIENT, 1, [Define if wide char orientation is supported.])
fi

if test "${newlib_nano_malloc}" = "yes"; then
  AC_DEFINE(_NANO_MALLOC, 1, [nano version of malloc is used.])
fi

if test "${newlib_unbuf_stream_opt}" = "yes"; then
  AC_DEFINE(_UNBUF_STREAM_OPT, 1, [Define if unbuffered stream file optimization is supported.])
fi

if test "${lite_exit}" = "yes"; then
  AC_DEFINE(_LITE_EXIT, 1, [Define if lite version of exit supported.])
fi

if test "${newlib_nano_formatted_io}" = "yes"; then
  AC_DEFINE(_NANO_FORMATTED_IO, 1, [Define if small footprint nano-formatted-IO implementation used.])
fi

if test "${newlib_retargetable_locking}" = "yes"; then
  AC_DEFINE(_RETARGETABLE_LOCKING, 1, [Define if using retargetable functions for default lock routines.])
fi

if test "${newlib_long_time_t}" = "yes"; then
  AC_DEFINE(_WANT_USE_LONG_TIME_T, 1, [Define to use type long for time_t.])
fi

if test "${newlib_use_gdtoa}" = "yes"; then
  AC_DEFINE(_WANT_USE_GDTOA, 1, [Define if using gdtoa rather than legacy ldtoa.])
fi

if test "${newlib_use_malloc_in_execl}" = "yes"; then
  AC_DEFINE(_EXECL_USE_MALLOC, 1, [Define if using malloc for execl, execle and execlp.])
fi

if test "x${newlib_hw_misaligned_access}" = "x"; then
  AC_CACHE_CHECK([if $CC has enabled misaligned hardware access],
              [newlib_cv_hw_misaligned_access], [dnl
  cat > conftest.c <<EOF
#if __riscv_misaligned_fast || __riscv_misaligned_slow
void misalign_access_supported(void) {}
#else
#error "misaligned access is not supported"
#endif
EOF
  newlib_cv_hw_misaligned_access=no
  if AC_TRY_COMMAND([${CC-cc} $CFLAGS $CPPFLAGS -c conftest.c])
  then
    newlib_cv_hw_misaligned_access=yes
  fi
  rm -f conftest*])
  newlib_hw_misaligned_access=$newlib_cv_hw_misaligned_access
fi

if test "${newlib_hw_misaligned_access}" = "yes"; then
  AC_DEFINE(_HAVE_HW_MISALIGNED_ACCESS, 1, [Define if hardware has little to no penalty for misaligned memory access.])
fi

dnl
dnl Parse --enable-newlib-iconv-encodings option argument
dnl

if test "x${iconv_encodings}" != "x" \
   || test "x${iconv_to_encodings}" != "x" \
   || test "x${iconv_from_encodings}" != "x"; then
  if test "x${newlib_iconv}" = "x"; then
      AC_MSG_ERROR([--enable-newlib-iconv-encodings, --enable-newlib-iconv-from-encodings and --enable-newlib-iconv-to-encodings option can't be used if iconv library is disabled, use --enable-newlib-iconv to enable it.])
  fi
  
  dnl Normalize encodings names and delete commas
  iconv_encodings=`echo "${iconv_encodings}" | sed -e 's/,/ /g' -e 's/-/_/g' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
  iconv_to_encodings=`echo "${iconv_to_encodings}" | sed -e 's/,/ /g' -e 's/-/_/g' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
  iconv_from_encodings=`echo "${iconv_from_encodings}" | sed -e 's/,/ /g' -e 's/-/_/g' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
 
  dnl Get the list of available encodings excluding comments
  dnl Join line with previous if the first character is whitespace
  available_encodings=`cat "${srcdir}/libc/iconv/encoding.aliases" | sed -e '/^#.*/d'`
  
  dnl Check if required encodings are supported
  dnl Convert aliases to names
  
  dnl iconv_encodings
  iconv_encodings1="${iconv_encodings}"
  iconv_encodings=""
  for encoding in ${iconv_encodings1}; do
      result=`echo "${available_encodings}" | grep -e "\(^\| \)${encoding}\( \|\$\)"`
      if test $? != "0"; then
	  AC_MSG_ERROR(${encoding} is not supported - see ${srcdir}/libc/iconv/encoding.aliases file for the list of available encodings)
      fi
      encoding1=`echo "${result}" | sed -e 's/\(^[[^ ]]*\).*$/\1/'`
      iconv_encodings="${iconv_encodings} ${encoding1}"
  done
  dnl Enable appropriate option in newlib.h
  for encoding in ${iconv_encodings}; do
      opt=_ICONV_TO_ENCODING_`echo "${encoding}" | sed -e 'y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/'`
      eval "$opt=1"
      opt=_ICONV_FROM_ENCODING_`echo "${encoding}" | sed -e 'y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/'`
      eval "$opt=1"
  done

  dnl iconv_to_encodings
  iconv_encodings1="${iconv_to_encodings}"
  iconv_to_encodings=""
  for encoding in ${iconv_encodings1}; do
      result=`echo "${available_encodings}" | grep -e "\(^\| \)${encoding}\( \|\$\)"`
      if test $? != "0"; then
	  AC_MSG_ERROR(${encoding} is not supported - see ${srcdir}/libc/iconv/encoding.aliases file for the list of available encodings)
      fi
      encoding1=`echo "${result}" | sed -e 's/\(^[[^ ]]*\).*$/\1/'`
      iconv_to_encodings="${iconv_to_encodings} ${encoding1}"
  done
  dnl Enable appropriate option in newlib.h
  for encoding in ${iconv_to_encodings}; do
      opt=_ICONV_TO_ENCODING_`echo "${encoding}" | sed -e 'y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/'`
      eval "$opt=1"
  done

  dnl iconv_from_encodings
  iconv_encodings1="${iconv_from_encodings}"
  iconv_from_encodings=""
  for encoding in ${iconv_encodings1}; do
      result=`echo "${available_encodings}" | grep -e "\(^\| \)${encoding}\( \|\$\)"`
      if test $? != "0"; then
	  AC_MSG_ERROR(${encoding} is not supported - see ${srcdir}/libc/iconv/encoding.aliases file for the list of available encodings)
      fi
      encoding1=`echo "${result}" | sed -e 's/\(^[[^ ]]*\).*$/\1/'`
      iconv_from_encodings="${iconv_from_encodings} ${encoding1}"
  done
  dnl Enable appropriate option in newlib.h
  for encoding in ${iconv_from_encodings}; do
      opt=_ICONV_FROM_ENCODING_`echo "${encoding}" | sed -e 'y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/'`
      eval "$opt=1"
  done
fi;
NEWLIB_ICONV_DEFINES

AC_CACHE_CHECK(for .preinit_array/.init_array/.fini_array support,
	       newlib_cv_initfinit_array, [dnl
cat > conftest.c <<EOF
int _start (void) { return 0; }
int __start (void) { return 0; }
int foo (void) { return 1; }
int (*fp) (void) __attribute__ ((section (".init_array"))) = foo;
EOF
if AC_TRY_COMMAND([${CC} $CFLAGS $CPPFLAGS -c -o conftest conftest.c
							1>&AS_MESSAGE_LOG_FD])
then
  if ${READELF} -S conftest | grep -e INIT_ARRAY > /dev/null; then
    newlib_cv_initfinit_array=yes
  else
    newlib_cv_initfinit_array=no
  fi
else
  newlib_cv_initfinit_array=no
fi
rm -f conftest*])
if test $newlib_cv_initfinit_array = yes; then
  AC_DEFINE(_HAVE_INITFINI_ARRAY, 1, [Define if the linker supports .preinit_array/.init_array/.fini_array sections.])
fi

AC_CACHE_CHECK(if $CC accepts -fno-tree-loop-distribute-patterns with \
__attribute__ ((__optimize__)), newlib_cv_cc_loop_to_function, [dnl
cat > conftest.c <<EOF
void
__attribute__ ((__optimize__ ("-fno-tree-loop-distribute-patterns")))
foo (void) {}
EOF
newlib_cv_cc_loop_to_function=no
if AC_TRY_COMMAND([${CC-cc} $CFLAGS $CPPFLAGS -c
			    -fno-tree-loop-distribute-patterns conftest.c])
then
  newlib_cv_cc_loop_to_function=yes
fi
rm -f conftest*])
if test $newlib_cv_cc_loop_to_function = yes; then
  AC_DEFINE(_HAVE_CC_INHIBIT_LOOP_TO_LIBCALL, 1, [Define if compiler supports -fno-tree-loop-distribute-patterns.])
fi

AC_TYPE_LONG_DOUBLE
dnl Export the setting for our installed headers to check.
if test $ac_cv_type_long_double = yes; then
  AC_DEFINE(_HAVE_LONG_DOUBLE, 1, [Define if the platform supports long double type.])
fi
AM_CONDITIONAL(HAVE_LONG_DOUBLE, test x"$ac_cv_type_long_double" = x"yes")

AC_CACHE_CHECK(whether long double equals double,
	       newlib_cv_ldbl_eq_dbl, [dnl
cat > conftest.c <<EOF
#include <float.h>
#if DBL_MANT_DIG == LDBL_MANT_DIG  &&  LDBL_MIN_EXP == DBL_MIN_EXP  && \
    LDBL_MAX_EXP == DBL_MAX_EXP
  #define _LDBL_EQ_DBL
 #else
  #error "LDBL != DBL"
#endif
EOF
if AC_TRY_COMMAND([${CC} $CFLAGS $CPPFLAGS -c -o conftest.o conftest.c
							1>&AS_MESSAGE_LOG_FD])
then
  newlib_cv_ldbl_eq_dbl=yes;
else
  newlib_cv_ldbl_eq_dbl=no;
fi
rm -f conftest*])
if test $newlib_cv_ldbl_eq_dbl = yes; then
  AC_DEFINE(_LDBL_EQ_DBL, 1, [Define if the platform long double type is equal to double.])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
