#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(void)
{
 	int pid;
 	pid = fork();
 	if(pid > 0)
 	{
 		int i = 0;
 		while(i++ < 10)
 		{
 			printf("Parent process running...\n");
 			sleep(1);
 			if(i==3)
 			{
 				kill(pid,SIGKILL);
 				printf("Child process killed!!!!!\n");
 			}
 		}
 	}
 	else if (pid == 0)
 	{
 		int i = 0;
 		while(i++ < 10)
 		{
 			printf("Child process running...\n");
 			sleep(1);
 		}
 	}
 	else
 	{
 		printf("Something bad happened.");
 		exit(EXIT_FAILURE);
 	}
 	return 0;
}
