#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include "flight.h"
int main()
{
struct flight f[10], g[10];
int fd, fn, i=0;
fd=open("106113.txt", O_RDONLY);
read(fd, f, 80);
printf("Enter the flight you want to take (from 0 to 9) \n");
scanf("%d", &fn);
if(f[fn].seat>0)
{
f[fn].seat--;
close(fd);
fd=open("106113.txt", O_WRONLY);
fcntl(fd, F_SETLK);
write(fd,f,80);
fcntl(fd, F_UNLCK);
}
close(fd);
fd=open("106113.txt", O_RDONLY);
read(fd,g,80);
for(i=0;i<10;i++)
printf("%d\t%d\n", g[i].flight_no, g[i].seat);
return 0;
}


