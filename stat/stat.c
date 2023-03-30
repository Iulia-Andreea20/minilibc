// SPDX-License-Identifier: BSD-3-Clause
#include <internal/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int ret; 
    struct stat dummy;

    if (syscall(__NR_stat, path, &dummy) == -1) {
        if (errno == ENOENT) {
            errno = ENOTDIR;
        }
        return -1;
    }
    
	ret = syscall(__NR_stat, path, buf);
    if (ret < 0) 
	{
    	errno = -ret;
        return -1;
    }

    return 0;
}
