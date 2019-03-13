#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(int argc, char *argv[]) // main
{
	pid_t ppid,cpid,pid; // id's of processors
	int status =0; 
	ppid = 	getpid(); // id of current process

	if((cpid=fork())<0) // failed to fork
	{
		printf("Failed to fork process\n");
          	exit(1);
	}
	else if (cpid == 0) // fork successful , child process
	{
		printf("calling execl...\n");
		int ret = execl("./file2","file2",argv[1],argv[2],NULL); // executing file2 ,taking in arguements from terminal

		printf("Failed execl ... ret = %d\n",ret); // will only get here if execl fails 
		exit(1);
	}
	printf("Waiting for child process\n");
	while((pid = wait(&status)) >0); // waiting for child to finish
	printf("Parent (PID = %d): Done\n",ppid);
	
}
