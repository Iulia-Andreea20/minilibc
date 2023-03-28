// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* DONE */
	    int result = syscall(__NR_close, fd);

    /* Check if an error occurred */
    if (result < 0) {
        /* Set the errno variable to the appropriate value */
        errno = -result;
        /* Return -1 to indicate an error */
        return -1;
    }

    /* Return 0 to indicate success */
    return 0;
}
