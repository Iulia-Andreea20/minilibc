#include <internal/syscall.h>
#include <time.h>
#include <unistd.h>


#define __NR_nanosleep 35

int nanosleep(const struct timespec *req, struct timespec *rem) 
{
    return syscall(__NR_nanosleep, req, rem);
}