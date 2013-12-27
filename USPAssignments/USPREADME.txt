USP ASSIGNMENT 1 README


USN: 
1PI10IS134

USN OF TEAM MATE: 
1PI10IS109

________________________________________________________________________________________________________________________________________________

PROGRAM 1: 

------------------------------------------------------------------------------------------------------------------------------------------------
EXECUTION: 
------------------------------------------------------------------------------------------------------------------------------------------------

Please type the following to execute the program: 

$ <filename> <depth> 

Example: 

$ ./a.out 3 

------------------------------------------------------------------------------------------------------------------------------------------------
EXPLANATION:
------------------------------------------------------------------------------------------------------------------------------------------------

A fork() system call spawn processes as leaves of growing binary tree. For example, If we call fork() twice, it will spawn 2^2 = 4 processes.
Similarly, since the binary tree of depth n is supposed to create 2^n - 1 leaves or childern. In our program we used recurssion to spawn the processes. 

The function forkchild() spawns a child process. If the pid < 0 the process outputs a error message and exits the program. Otherwise, it returns the pid. 

The next function is createtee(int level, int max). 
   -The parameters passed are: 
	1. int level, which is used to keep track of the number of levels that has to be created. This is keeps incrementing. 
	2. int max, this helps us stop the recursion when a certain maximum level is reached. This maximum level will be input by 
	   the user via commandline arguemen
   -The forkchild() function is called twice to produce a binary tree. This is given in the if statement. The recursive function is
    called in the same. 

   -The else part consists of the parent process. The random number is generated. And the same is printed along with the output given
    in the question. 
   
   -In the while loop, the parent waits for the child to finish. And the sum of the two children is calculated. 
   -The parent process exits at exit status code of "r".
   -The sum is calculate from bottom to top.  
   -The levels are created from top to bottom.  

In the main, The function createtree(0,depth) is called. depth is passed as the commandline arguement. 

------------------------------------------------------------------------------------------------------------------------------------------------
OUTPUT:
------------------------------------------------------------------------------------------------------------------------------------------------

surabhiiyer@ubuntu:~$ ./a.out 3

Root node is 5297

Level: 0 | I am 5297 | My parent is 2293 | My data = 10  
Level: 1 | I am 5299 | My parent is 5297 | My data = 10  
Level: 1 | I am 5298 | My parent is 5297 | My data = 7  
Level: 2 | I am 5302 | My parent is 5299 | My data = 10  
Level: 2 | I am 5300 | My parent is 5298 | My data = 3  
Level: 2 | I am 5301 | My parent is 5299 | My data = 10  
Level: 2 | I am 5303 | My parent is 5298 | My data = 5  

Root node exiting...

Exit value = 55 Parent Process Id = 5297 

------------------------------------------------------------------------------------------------------------------------------------------------

In the above output. A binary tree is created with 2^3-1 = 7 children. 
Exit value represents the sum that is calculated. And the Parent Process ID in the last line represents the root node that is being exited. 

________________________________________________________________________________________________________________________________________________ 

PROGRAM 2: 

------------------------------------------------------------------------------------------------------------------------------------------------
EXECUTION: 
------------------------------------------------------------------------------------------------------------------------------------------------

Please type the following to execute the program: 

$ <filename> <input filename> 

Example: 

$ ./a.out xyz.txt 

------------------------------------------------------------------------------------------------------------------------------------------------
EXPLANATION:
------------------------------------------------------------------------------------------------------------------------------------------------
The program takes the input file from the command line argument. The main function first opens the file in the read only mode and spawns a child process.If the control is passed to the child process ,then it executes the ps command.If the parent process executes,then it waits for the first child process to terminate and then spawns another child process.If now,child process 2 executes,then it reads from the file and writes the same onto the standard output device file(the terminal) .The parent process waits for the termination of the second process and reads the remaining set of characters from the file and outputs the same.

The system calls used are:
>read()
>fork()
>write()
>getpid()
>execl()
>waitpid()

The result of each of these system calls is printed using perror().	

The ps (i.e., process status) command is used to provide information about the currently running processes, including their process identification numbers (PIDs).  The four items labeled are PID, TTY, TIME and CMD. TIME is the amount of CPU (central processing unit) time in minutes and seconds that the process has been running. CMD is the name of the command that launched the process.

TTY (which stands for terminal type) is the name of the console or terminal (i.e., combination of monitor and keyboard) that the user logged into, which can also be found by using the tty command. This information is generally only useful on a multi-user network. 
------------------------------------------------------------------------------------------------------------------------------------------------
OUTPUT:
------------------------------------------------------------------------------------------------------------------------------------------------
shreya@ubuntu:~$ ./a.out xyz.txt
This is the parent process!
Open: Success
Fork1: Success

We are now in the parent process.

Waiting for child process 1 to terminate.
Fork1: Success

We are now in the first child process.

Getpid: Success

The process id of the first process is:5115
  PID TTY          TIME CMD
 5051 pts/1    00:00:00 bash
 5114 pts/1    00:00:00 a.out
 5115 pts/1    00:00:00 sh
 5116 pts/1    00:00:00 ps

Waitpid1: Success

Fork2: Success

We are now in the parent process.


Waiting for child process 2 to terminate..
Fork2: Success

We are now in the second child process.

Getpid: Success

The process id of the second child process is:5117

The no of bytes read from the file are:256
BMW is giving fans of its 3-Series more room and better gas mileage in two important variations of the small luxury sports sedan that it’s rolling out at the New York International Auto Show this week.On Wednesday, the German automaker will formally unve
Waitpid: Success

Parent reading from the file now..

The no of bytes read from the file are:256
il a new 3 Series Gran Turismo, which has a bigger distance between the front and rear wheels to create more rear-seat legroom and cargo space in the trunk. The company also will unveil the 328d in the U.S., a 3-Series equipped with a diesel engine that sh
Write: Success

Write: Success


________________________________________________________________________________________________________________________________________________

REMARKS:
_______________________________________________________________________________________________________________________________________________

The output shows the concurrent execution of the parent and child processes.The parent and the child processes execute in an interleaved fashion.
________________________________________________________________________________________________________________________________________________ 

PROGRAM 3:

------------------------------------------------------------------------------------------------------------------------------------------------
EXECUTION: 
------------------------------------------------------------------------------------------------------------------------------------------------
The program is compiled using the command gcc <filename> -lm. The -lm option is used to link the math object file from the library into the executable output file.

Please type the following to execute the program: 

$<filename> <No of elements to sort> <The range for fibonacci series> <No of iterations in the Buffon needle problem simulation>

Example: 

$ ./a.out 10 5 3 

------------------------------------------------------------------------------------------------------------------------------------------------
EXPLANATION:
------------------------------------------------------------------------------------------------------------------------------------------------ 
This program creates 3 child processes in a way similar to the second problem.The main function first creates a child process by forking it. If the control passes to the child process,the child process executes the heapsort of the input number of elements from the command line ,generated using rand() function.If the parent process is in execution,it forks another child process.The second child process executes the fibonacci series for the input range from the command line,in recursion. The parent process in execution again,spawns a third child process that simulates the buffon needle probability.The parent process finally waits for all the child processes to terminate and exits.
The first child processes uses the heapsort,heapify and adjust functions to carry out the heapsort and the second process uses the printFibonacci function to display the fibonacci series.The third child process uses the iterate function to simulate the needle throwing.The approximate probability is then calculated.It is found to be very close to the exact value for a larger number of iterations.
________________________________________________________________________________________________________________________________________________ 

OUTPUT:
________________________________________________________________________________________________________________________________________________

shreya@ubuntu:~$ ./a.out 10 5 3

The process id of first child process is:5349
The generated random numbers are:
35
86
98
64
13
31
83
7
12
43

The Sorted Elements Are:
7	12	13	31	35	43	64	83	86	98	

The process id of the second process is:5350
The range is:5
Fibonacci Series: 
0 1 1 2 3 5 8 

The process id of the third process is:5351
The number of iterations is:3
Exact probability is:0.636620.
An approximation of the exact probability is:0.666667.

The exit status of the first child process:0
The exit status of the second child process:0
The exit status of the third child process:0

________________________________________________________________________________________________________________________________________________

REMARKS:
_______________________________________________________________________________________________________________________________________________

The output shows the concurrent execution of the parent and child processes.The parent and the child processes execute in an interleaved fashion.
________________________________________________________________________________________________________________________________________________ 

