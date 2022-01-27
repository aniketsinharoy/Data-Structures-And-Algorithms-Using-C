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
		printf("Parent process running having Process ID: %d\n",getpid());
	}
	else if (pid == 0)
	{
		sleep(2);
		printf("Orphan process running having Process ID: %d\n",getpid());
	}
	else 
	{
		printf("Fork error\n");
		exit(1);
	}
	if(pid>0)
	{
		printf("Parent process terminated having Process ID: %d\n",getpid());
	}
	exit(0);
}
