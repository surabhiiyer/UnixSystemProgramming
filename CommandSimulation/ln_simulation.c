#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
link(argv[1],argv[2]);
unlink(argv[2]);
return 0;
}

