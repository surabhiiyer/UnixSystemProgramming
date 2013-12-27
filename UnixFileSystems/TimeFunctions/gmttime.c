#include <stdio.h>
#include <time.h>
int main(void)
{
time_t
t;
struct tm *ts;
char
buf[80];
t = time(NULL);
//ts = localtime(&t);
ts=gmtime(&t);
printf("%d seconds\n",ts->tm_sec);
printf("%d min\n",ts->tm_min);
printf("%d hour\n",ts->tm_hour);
printf("%d day\n",ts->tm_mday);
printf("%d month\n",ts->tm_mon);
printf("%d year since 1900\n",ts->tm_year);
printf("%d day since sunday\n",ts->tm_wday);
printf("%d days since jan\n",ts->tm_yday);
printf("%d daylight saving time\n",ts->tm_isdst);
return 0;
}

