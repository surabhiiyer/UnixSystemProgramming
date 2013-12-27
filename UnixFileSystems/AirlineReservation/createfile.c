#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
struct flight {
    	int flight_no,seats;
};

int main(int argc,char* argv[]) {
    	int fd,n,i=0;
    	struct flight *f;
    	if (argc==2) {
    	if (strcmp(argv[1],"create")==0) {
    	fd = open("sample.txt",O_WRONLY);
    	printf("FD = %d\n",fd);
    	//printf("\nEnter the number of records : ");
    	//scanf("%d",&n);
    	n=5;
    	f = (struct flight*)malloc(sizeof(struct flight)*n);
    	while(i<n) {
            	printf("Enter the flight number : ");
            	scanf("%d",&f[i].flight_no);
            	printf("Enter the number of seats : ");
            	scanf("%d",&f[i].seats);
            	i++;
    	}
    	write(fd,f,sizeof(struct flight)*5);
    	close(fd);
    	}
}
return 0;
}

