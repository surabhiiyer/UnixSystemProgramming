#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

static pid_t forkchild(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "Fork failure in pid %d\n", getpid());
        exit(1);
    }

    else 
    {
    	return pid;
    }

}
int createtree(int level,int max)
{ 
    int r; 
    int status;
    
    if (level >= max)
 	{      	 
		return;
	}
    

    if (forkchild()==0 || forkchild()==0) 
	{
		sleep(1);  	
       	 	createtree(level+1,max); 
        }    
	
    else
 	{ 
		srand(getpid());
		r = 1 + rand()%10; 
	        printf("Level: %d | I am %d | My parent is %d | My data = %d  \n", level, getpid(), getppid(), r);  
		
		while (wait(&status) > 0)
	           {
			r=r+WEXITSTATUS(status); 
	 	   }   
	
	    	if(level == 0) 
	           {	
			printf("\nRoot node exiting...\n"); 
			sleep(1); 
	        	printf("\nExit value = %d Parent Process Id = %d \n\n" , r, getpid());      
		   }	 
		
		exit(r); 
	
	}     
}

int main(int argc, char *argv[])
{
	int depth; 	
    	if (argc!=2)
    	{
		printf("\nError!\n"); 
		printf("\nSyntax: <filename> <depth> \n\n"); 
		return(0); 
    	} 
    	else 
    	{	
		depth = atoi(argv[1]); 
    		printf("\nRoot node is %d\n\n", getpid());
    		fflush(0);
    		createtree(0,depth);
    		return(0);
    	}
}

