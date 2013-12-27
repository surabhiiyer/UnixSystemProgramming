#include<stdio.h>
#include<time.h>
#include<sys/time.h>
int main(int argc,char **argv)
{
struct tm *gm,*local;
time_t
temp1,temp2;
char
buftime[100];
temp1 = time(NULL);
gm = gmtime(&temp1);
temp1 = mktime(gm);
printf("GM time formatted using ctime : %s\n",ctime(&temp1));
temp2 = time(NULL);
local = localtime(&temp2);
printf("Local time : %s\n",asctime(local));
strftime(buftime,100," %a : %b :%c ",local);
printf("Local time : %s\n",buftime);
return 0;
}

