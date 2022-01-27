#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	int pid = fork();
	if (pid > 0)
	{
		printf("Parent process running having Process ID: %d\n",getpid());
		sleep(3);
	}
	else
	{		
		printf("Process terminated having Process ID: %d\n",getpid());
		exit(0);
	}
	return 0;
}

