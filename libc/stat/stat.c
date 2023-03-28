// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <unistd.h>
int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	/* Check if file exists */
    struct stat dummy;
    if (syscall(__NR_stat, path, &dummy) == -1) {
        if (errno == ENOENT) {
            errno = ENOTDIR; /* as per POSIX */
        }
        return -1;
    }

    /* Call stat system call */
    int ret = syscall(__NR_stat, path, buf);
    if (ret == -1) {
        errno = -ret;
        return -1;
    }

    return 0;
}
