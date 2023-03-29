// SPDX-License-Identifier: BSD-3-Clause
#include <internal/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	if (fd < 0) 
	{
		errno = EBADF;
		return -1;
	}

	int ret = syscall(__NR_fstat, fd, st);

	if (ret < 0) 
	{
		errno = -ret;
		return -1;
	}

	return 0;
}
