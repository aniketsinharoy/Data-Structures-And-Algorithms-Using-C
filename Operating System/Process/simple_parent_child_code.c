#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main (void) 
{
	int pid;
	pid = fork();
	if (pid > 0) 
	{
		sleep(1);
		printf("Parent process running having Process ID: %d\n",getpid());
	}
	else if (pid == 0)
	{
		
		printf("Child process running having Process ID: %d and parent Process ID: %d\n",getpid(),getppid());
	}
	else 
	{
		printf("Fork error\n");
		exit(1);
	}
	printf("Process terminated having Process ID: %d\n",getpid());
	exit(0);
}

