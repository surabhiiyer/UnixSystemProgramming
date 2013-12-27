/* Write a small program that measures the performance of the getpid() (man 2
getpid) system call and the fork (man 2 fork) system call.
*/
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
double timespec_to_ms(struct timespec *ts)
{
return ts->tv_sec*1000.0 + ts->tv_nsec/1000000.0;
}
int main()
{
struct timespec start_time, end_time;
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
/* begin timing */
/* end timing */
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
printf("%f ms\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));
}
/*
The code above measures the CPU time spent in the process executing the code marked
between begin timing and  end timing.
To compile the code, use the following command:
gcc -O0 measureSystemCall.c -o measureSystemCall -lrt
*/
