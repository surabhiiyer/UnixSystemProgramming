#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<wait.h>
#include<math.h>
#include<time.h>

 
void heapsort(int[],int);
void heapify(int[],int);
void adjust(int[],int);
void printFibonacci(int);
int  iterate(int *);

int L=1,G=1;
int m,n,r,c,s;
double d,a,j,p,e,result;

//______________________________________________________________________________________________________________________________________________

void heapsort(int arr[],int m)
{
int i,t;
heapify(arr,m);
for(i=m-1;i>0;i--)
{
t = arr[0];
arr[0] = arr[i];
arr[i] = t;
adjust(arr,i);
}
}
 
//______________________________________________________________________________________________________________________________________________ 
void heapify(int arr[],int m)
{
int k,i,j,item;
for(k=1;k<m;k++)
{
item = arr[k];
i = k;
j = (i-1)/2; 
while((i>0)&&(item>arr[j]))
{
arr[i] = arr[j];
i = j;
j = (i-1)/2;
}
arr[i] = item;
}
}
//______________________________________________________________________________________________________________________________________________ 
void adjust(int arr[],int m)
{
int i,j,item;
j = 0;
item = arr[j];
i = 2*j+1;
while(i<=m-1)
{
if(i+1 <= m-1)
if(arr[i] <arr[i+1])
i++;
if(item<arr[i])
{
arr[j] = arr[i];
j = i;
i = 2*j+1;
}
else
break;
}
arr[j] = item;
}
//______________________________________________________________________________________________________________________________________________

void printFibonacci(int n)
{
static long int first=0,second=1,sum;
if(n>0)
{
sum = first + second;
first = second;
second = sum;
printf("%ld ",sum);
printFibonacci(n-1);
}
}

//______________________________________________________________________________________________________________________________________________

int iterate(int *p)
{
d=rand()%2;
//printf("The  distance from one (fixed) tip of the needle to the lower dividing line is:%lf.\n\n",d);
c=2*M_PI;
a=rand()%c;
//printf("The angle between the needle and a dividing line is:%lf.\n\n",a);
result=sin(a);
e=d+(L*(result));
if(e<0 || e>G)
{
//printf("The needle crosses a dividing line.\n\n");
(*p)++;
return *p;
}
//else
//printf("The needle does not cross the dividing line.\n\n");
}

//______________________________________________________________________________________________________________________________________________

int main(int argc,char*argv[])
{
if( argc < 4 )
{
printf("Insufficient arguments.\n");
printf("Syntax:<filename> <No of elements to sort> <The range for fibonacci series> <No of iterations in the Buffon needle problem simulation>\n");
exit(0);
}
if(argc>4)
{
printf("Too many arguments\n");
printf("Syntax:<filename> <No of elements to sort> <The range for fibonacci series> <No of iterations in the Buffon needle problem simulation>\n");
exit(0);
}
m=atoi(argv[1]);
n=atoi(argv[2]);
r=atoi(argv[3]);
pid_t pid1,pid2,pid3,pid,k;
pid1=fork();
sleep(1);


if(pid1==0)//In the first child process
{
pid1=getpid();
printf("\nThe process id of first child process is:%d\n",pid1);
int i,arr[50],j;
printf("The generated random numbers are:\n");
srand(time(NULL));
for(i=0;i<m;i++)
{
arr[i]=rand()%100;
printf("%d\n",arr[i]);
}
heapsort(arr,m);
printf("\nThe Sorted Elements Are:\n");
for(i=0;i<m;i++)
printf("%d\t",arr[i]);
printf("\n");
exit(0);
}

else//In the parent process
{
pid2=fork();
sleep(1);
}


if(pid2==0)//In the second child process
{
pid2=getpid();
printf("\nThe process id of the second process is:%d\n",pid2); 
long int i=0,j=1,f;
printf("The range is:%d\n",n);
printf("Fibonacci Series: \n");
printf("%d %d ",0,1);
printFibonacci(n);
printf("\n");
return 0;
exit(0);
}


else//In the parent process
{
pid3=fork();
sleep(1);
}


if(pid3==0)//In the third child process
{
pid3=getpid();
printf("\nThe process id of the third process is:%d\n",pid3);
int i,t=0;
printf("The number of iterations is:%d\n",r);
srand(time(NULL));
for(i=1;i<=r;i++)
{
//printf("Iteration:%d\n",i);
iterate(&t);
}
j=(float)t/r;
p=(2/M_PI)*(L/G);
printf("Exact probability is:%lf.\n",p);
printf("An approximation of the exact probability is:%lf.\n\n",j);
exit(0);
}


else//In the parent process
{
//printf("Waiting for child process 1 to terminate..\n");
pid1=waitpid(pid1,&s,WNOHANG);
if(WIFEXITED(s))
printf("The exit status of the first child process:%d",WEXITSTATUS(s));
sleep(1);
//printf("\nWaiting for child process 2 to terminate..\n");
pid2=waitpid(pid2,&s,WNOHANG);
if(WIFEXITED(s))
printf("\nThe exit status of the second child process:%d\n",WEXITSTATUS(s));
sleep(1);
//printf("\nWaiting for child process 3 to terminate..\n");
pid3=waitpid(pid3,&s,WNOHANG);
if(WIFEXITED(s))
printf("The exit status of the third child process:%d\n",WEXITSTATUS(s));
}


}





