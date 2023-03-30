#ifndef _TIME_H_
#define _TIME_H_	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
   long int tv_sec;
   long int tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif