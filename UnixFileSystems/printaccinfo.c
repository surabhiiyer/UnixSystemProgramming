#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pwd.h>
int main(int argc,char* argv[])
{
//struct passwd *pwd;
if(argc<1)
{
printf("Mistake\n");
exit(0);
}
struct passwd *pwd;
if( (pwd=getpwnam(argv[1]))==NULL)
{
printf("Error:No such user\n");
exit(0);
}
else
{
printf("%s\n",pwd->pw_name);
printf("%s\n",pwd->pw_passwd);
printf("%d\n",pwd->pw_gid);
printf("%s\n",pwd->pw_shell);
printf("%s\n",pwd->pw_dir);
}
return 0;
}

