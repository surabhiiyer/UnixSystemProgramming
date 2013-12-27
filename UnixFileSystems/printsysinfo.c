#include<sys/utsname.h>
#include<sys/types.h>
#include<stdio.h>
#include <errno.h>
struct utsname Myhost;
int main()
{
int status=0;
if(status = uname(&Myhost)>=0)
{
printf("System Name = %s \n",Myhost.sysname);
printf("Node name = %s \n",Myhost.nodename);
printf("Version = %s \n",Myhost.version);
printf("Release = %s \n",Myhost.release);
printf("Machine = %s \n",Myhost.machine);
}
else
{
perror("Mistake");
}
return 0;
}

