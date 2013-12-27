//consists of the struct declaration 
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
struct flight {
    	int flight_no;
	int seats;
};
int main(int argc,char* argv[]) {
    	int fd,num,ticks,i=0,n=5;
    	struct flight *f,*temp;
    	printf("\nEnter the flight number to book the tickets : ");
    	scanf("%d",&num);
    	printf("\nEnter the number of tickets : ");
    	scanf("%d",&ticks);
    	fd = open("sample.txt",O_RDONLY);
    	printf("FD = %d\n",fd);
    	temp = (struct flight*)malloc(sizeof(struct flight)*n);
    	read(fd,temp,sizeof(struct flight)*5);
    	while(i<5) {
            	//printf("\nFlight number = %d\tSeats = %d",temp[i].flight_no,temp[i].seats);
            	if (temp[i].flight_no==num && temp[i].seats>=ticks) {
                    	temp[i].seats-=ticks;
            	}
            	else if(temp[i].flight_no==num)
                    	printf("Limit Reached");
            	i++;
    	}
    	close(fd);
    	fd = open("sample.txt",O_WRONLY);
    	write(fd,temp,sizeof(struct flight)*5);
    	close(fd);
    	return 0;
}

