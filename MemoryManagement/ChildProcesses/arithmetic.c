#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int performWork(int sel,int a[],int n);
int Nnatural(int a[]);
int Nnatural(int a[])
{
int i,n;
printf("Enter the range\n");
scanf("%d",&n);
for(i=0;i<n;i++)
a[i]=i+1;
printf("Generated\n");
return n;
}
int Neven(int a[])
{
int i,n,j=0;
printf("Enter the range\n");
scanf("%d",&n);
for(i=2,j=0;i<=n;i+=2,j++)
{
a[j]=i;
printf("%d\t",a[j]);
}
printf("\nGenerated\n");
return j;
}
int performWork(int sel,int a[],int n)
{
int i,sum=0,sub=0;
switch(sel)
{
case 1 : for(i=0;i<n;i++)
sum = sum+a[i];
printf("%d\n",sum);
break;
case 2 : for(i=n-1;i!=0;i--)
sub = sub - (a[i]-a[i-1]);
break;
default : printf("No such choice\n");
exit(0);
}
}
int main()
{
char ch = 'y';
int sel = 0;
int cnt=0;
printf("Welcome!!!\n");
int a[20];
pid_t pid;
printf("Enter the type of numbers\n");
printf("1. N natural numbers\n");
//printf("2. N even natuaral numbers\n");
printf("Please Enter your Choice\n");
scanf("%d",&sel);
switch(sel)
{
case 1 : cnt = Nnatural(a);
break;
case 2 : cnt = Neven(a);
break;
default : printf("No such choice\n");
exit(0);
}
printf("Enter the operation to be performed\n");
printf("1. addition\n");
printf("2. Subtraction\n");
printf("Please Enter your choice\n");
scanf("%d",&sel);
pid = fork();
if(pid==-1)
{
perror("Enidu\n");
exit(0);
}
else if(pid == 0)
{
performWork(sel,a,cnt);
}
else
{
printf("Okay\n");
}
return 0;
}

