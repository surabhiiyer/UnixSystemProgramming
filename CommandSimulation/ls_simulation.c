#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include <math.h>
/*
struct stat
{
	dev_t t_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
};*/
/*
 * int chmod (const char *pn, mode_t mode);
 * int fchmod (int fd, mode_t mode);
 */

void printugid(int, int);

//1. Printing the type of file
int main (int argc, char *argv[])
{
	struct stat statv;
	char xtable[10] = "rwxrwxrwx";
	int st_m, k;
	if (argc > 1)
	{
    	k = lstat(argv[1], &statv);
    	if (k == -1)
    	{
        	printf("File does not exist\n");

       	exit(0);
    	}
    	st_m = statv.st_mode;
    	switch (st_m & S_IFMT)
    	{
        	case S_IFREG: printf("-");
                      	break;
        	case S_IFDIR: printf("d");
                      	break;
        	case S_IFBLK: printf("b");
                      	break;
        	case S_IFCHR: printf("c");
                      	break;
        	case S_IFIFO: printf("p");
                      	break;
        	case S_IFLNK: printf("l");
                      	break;
    	}
//2. Printing the next 9 bits (permissions)

    	char amode[10];
    	int i, j;

    	for (i = 0, j = 1 << 8; i < 9; i++, j>>=1)
    	{
        	amode[i] = st_m & j? xtable[i]:'-';
    	}
    	if (st_m & S_ISUID)
        	amode[2] == 'x'?(amode[2] = 'S'): (amode[2] = 's');
    	if (st_m & S_ISGID)
        	amode[5] == 'x'?(amode[5] = 'G'): (amode[5] = 'g');
    	if (st_m & S_ISVTX)
        	amode[9] == 'x'?(amode[9] = 'T'): (amode[9] = 't');
    	amode[9] = '\0';
    	printf("%s\t", amode);

//3. Printing the number of hard links
    	printf("%d ", statv.st_nlink);
//4. Printing the user id and group id
    	printugid(statv.st_uid, statv.st_gid);

//5. Printing the file size
    	if ((st_m & S_IFMT == S_IFBLK) || (st_m & S_IFMT == S_IFCHR))
    	{
        	printf(" %d  ", statv.st_rdev >> 8);
        	printf(" %d  ", statv.st_rdev & 0x00FF);
    	}
    	else
    	{
        	printf(" %d  ", statv.st_size);
    	}

//6.Printing the time
    	printf(" %s ", ctime(&statv.st_mtime));

//7. Printing the name of the file   
    	printf(" %s  ", argv[1]);
    	printf("\n");
	}
	else
	{
    	printf("Invalid number of arguments\n");
	}

	return 0;
}

void printugid(int st_uid, int st_gid)
{
	struct group *gp;
	struct passwd *pwp;

	gp = getgrgid(st_gid);
	pwp = getpwuid(st_uid);

	if (pwp->pw_name)
    	printf("%s", pwp->pw_name);
   else
    	printf("%d", st_uid);
	if (gp->gr_name)
    	printf("%s", gp->gr_name);
	else
    	printf("%d", st_gid);
}

