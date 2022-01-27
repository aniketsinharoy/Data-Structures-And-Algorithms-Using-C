#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main (void) 
{
	int pid;
	pid = fork();
	pid = fork();
	pid = fork();
	if (pid > 0) 
	{
		sleep(1);
		printf("Process running having Process ID: %d\n",getpid());
	}
	else if (pid == 0)
	{
		printf("Process running having Process ID: %d\n",getpid());
	}
	else 
	{
		printf("Fork error\n");
		exit(1);
	}
	exit(0);
}
