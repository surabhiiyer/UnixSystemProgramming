#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<wait.h>
#define BUFFSIZE 256

int main(int argc,char*argv[])
{
if(argc<2)
{
printf("Insufficient arguments\n");
printf("Syntax:<filename> <input filename>\n");
exit(0);
}
else if(argc>2)
{
printf("Too many arguments\n");
printf("Syntax:<filename> <input filename>\n");
exit(0);
}
else
{
pid_t pid1,pid2,pid,k;
int fd1,n,i,s;
char buf[BUFFSIZE];
printf("This is the parent process!\n");
fd1=open(argv[1],O_RDONLY|O_CREAT);
perror("Open");
pid1=fork();
sleep(1);
perror("Fork1");
if(pid1==0)//In the first child process
{
int d;
pid1=getpid();
printf("\nWe are now in the first child process.\n");
perror("\nGetpid");
printf("\nThe process id of the first process is:%d\n",pid1);
d=execl("/bin/sh","sh","-c","ps","-l",NULL);
perror("execl");
}

else//In the parent process
{
printf("\nWe are now in the parent process.\n");
printf("\nWaiting for child process 1 to terminate.\n");
pid1=waitpid(pid1,&s,WNOHANG);
sleep(1);
perror("\nWaitpid1");
if(WIFEXITED(s))
printf("\nThe exit status of the first child process:%d\n",WEXITSTATUS(s));
pid2=fork();
sleep(1);
perror("\nFork2");
}

if(pid2==0)//In the second child process
{
pid2=getpid();
printf("\nWe are now in the second child process.\n");
perror("\nGetpid");
printf("\nThe process id of the second child process is:%d\n",pid2);
n=read(fd1,buf,BUFFSIZE);
if(n==0)
printf("End of file was reached\n");
else if(n>0)
{
printf("\nThe no of bytes read from the file are:%d\n",n);
i=write(STDOUT_FILENO,buf,n);
sleep(1);
perror("\nWrite");
}
else
{
printf("\nThe read was unsuccessful\n");
perror("\nRead");
}
}

else//In the parent process
{
printf("\nWe are now in the parent process.\n");
printf("\nWaiting for child process 2 to terminate..\n");
pid2=waitpid(pid2,&s,WNOHANG);
sleep(1);
perror("\nWaitpid");
if(WIFEXITED(s))
printf("\nThe exit status of the second child process:%d\n",WEXITSTATUS(s));
printf("\nParent reading from the file now..\n");
n=read(fd1,buf,BUFFSIZE);
if(n==0)
printf("\nEnd of file was reached\n");
else if(n>0)
{
printf("\nThe no of bytes read from the file are:%d\n",n);
i=write(STDOUT_FILENO,buf,n);
sleep(1);
perror("\nWrite");
}
else
{
printf("\nThe read was unsuccessful\n");
perror("\nRead");
}
}
}
}





