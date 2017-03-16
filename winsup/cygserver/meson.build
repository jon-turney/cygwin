# meson.build for cygserver
#
# This file is part of Cygwin.
#
# This software is a copyrighted work licensed under the terms of the
# Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
# details.

project('cygserver', 'cpp')

if get_option('enable-debugging')
  conf.set('DEBUGGING', 1)
endif

# ccwrap/c++wrap things...
add_global_arguments('-nostdinc', language: 'cpp')

headers = include_directories('../cygwin')
system_headers = include_directories('../../winsup/cygwin/include', '../../newlib/libc/include', is_system: true)

# should be learnt with `gcc -print-file-name=include`
compiler_headers = include_directories('/usr/lib/gcc/x86_64-pc-cygwin/5.4.0/include', is_system: true)

# should be controlled by --with-windows-headers, defaulting to ...
windows_headers = include_directories('/usr/include/w32api', is_system: true)

add_global_arguments('-D__OUTSIDE_CYGWIN__', language: 'cpp')
add_global_arguments('-DSYSCONFDIR=$sysconfdir', language: 'cpp')

cygserver_sources = [
	'bsd_helper.cc',
	'bsd_log.cc',
	'bsd_mutex.cc',
	'client.cc',
	'cygserver.cc',
	'msg.cc',
	'process.cc',
	'pwdgrp.cc',
	'sem.cc',
	'setpwd.cc',
	'shm.cc',
	'sysv_msg.cc',
	'sysv_sem.cc',
	'sysv_shm.cc',
	'threaded_queue.cc',
	'transport.cc',
	'transport_pipes.cc']

executable('cygserver',
	cygserver_sources,
	include_directories : [headers, system_headers, compiler_headers, windows_headers],
	link_args: ['-lntdll', '-static', '-static-libgcc'],
	install: true)

install_data('README',
	install_dir : '$docdir/Cygwin/cygserver.README')

install_data('cygserver.conf',
	install_dir : '$sysconfdir/defaults/etc/cygserver.conf')
