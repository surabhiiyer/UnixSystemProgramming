#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include "flight.h" 
int main()
{
struct flight f[10], g[10];
int k, i, fd;
int I; 
for(i=0;i<10;i++)
{
f[i].flight_no=I;
f[i].seat=5;
}
fd = open("106113.txt", O_RDONLY);
if(fd==-1)
perror("open\n");
printf("%d\n",read(fd,g,80));
for(i=0;i<10;i++)
{
printf("Flight no: %d\n", g[i].flight_no);
printf("Seats available: %d\n", g[i].seat);
}
close(fd);
return 0;
}



