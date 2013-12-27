#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<time.h>
//struct tm Mytime;
int main()
{
time_t samaya;
time(&samaya);
struct tm *Mytime = localtime(&samaya);
printf("%d-%d-%d\n",Mytime->tm_year+1900,(Mytime->tm_mon+1)%12,Mytime->tm_mday);
printf("Asc time = %s ",asctime(Mytime));
//printf("Asc time =%s ",strftime(Mytime));
return 0;
}

