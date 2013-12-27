#include<stdio.h>
#include<fcntl.h>
int main(int argc,int *argv[])
{
int k,j;
k=access(argv[1],F_OK);
j=access(argv[1],R_OK|W_OK);
printf("File exists %d\n",k);
printf("Permissions %d\n",j);
return 0;
}

