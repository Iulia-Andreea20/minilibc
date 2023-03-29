// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int e = syscall(__NR_open, filename, flags);
	if(e < 0) 
	{
		errno = -e;
		return -1;
	}
	
	return e;
}
