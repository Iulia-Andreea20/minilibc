// SPDX-License-Identifier: BSD-3-Clause
#include <internal/syscall.h>
#include <unistd.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int result = syscall(__NR_truncate, path, length);

    if (result < 0) {
        errno = -result;
        return -1;
    }

    return 0;
}
