#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<sys/syscall.h>
double timespec_to_ms(struct timespec *ts)
{
return (ts->tv_sec*1000.0 + ts->tv_nsec/1000000.0);
}
int main()
{
struct timespec start_time,end_time;
long int count = 100000;
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start_time);
while(count!=0)
{
count--;
if (fork() == 0) return;
}
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end_time);
printf("%f\n",timespec_to_ms(&end_time)-timespec_to_ms(&start_time));
return 0;
}

