#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
link(argv[1],argv[2]);
unlink(argv[1]);
}

