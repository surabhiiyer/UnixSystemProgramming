#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc, char *argv[])
{
struct stat st;
if(argc != 2) {
perror("Usage Error: a.out");
}
if(stat(argv[1], &st)==-1) {
perror("stat");
}
printf("File type: ");
switch(st.st_mode & S_IFMT) {
case S_IFBLK: printf("block device\n"); break;
case S_IFCHR: printf("Char device\n"); break;
case S_IFDIR: printf("Dir\n"); break;
case S_IFIFO: printf("Fifo / pipe\n"); break;
case S_IFLNK: printf("symlink\n"); break;
case S_IFREG: printf("regular file\n"); break;
case S_IFSOCK: printf("socket\n"); break;
default : printf("unknown");
}
printf("Inode number: %ld\n", (long)st.st_ino);
printf("Mode: %lo (octal)\n", (unsigned long) st.st_mode);
printf("Link cnt: %ld\n",(long) st.st_nlink);
printf("Ownership: UID:%ldGID:%ld\n",(long) st.st_uid, (long) st.st_gid);
printf("I/O Blocks: %ld bytes\n", (long) st.st_blksize);
printf("File size: %lld bytes\n", (long long) st.st_size);
printf("Blocks allocated: %lld\n", (long long) st.st_blocks);
}

