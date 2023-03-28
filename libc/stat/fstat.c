// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/arch/x86_64/syscall_list.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	/* Call fstat system call */
	int ret = syscall(__NR_fstat, fd, st);

	/* Check for errors */
	if (ret == -1) {
		errno = -ret;
		return -1;
	}

	return 0;
}
