#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
	printf("PID : %4d, PPID: %4d\n", getpid(), getppid());
	printf("UID : %4d, GID: %4d\n", getuid(), getgid());
	printf("EUID: %4d, EGID: %4d\n", geteuid(), getegid());
	printf("PATH=%s\n", getenv("PATH"));
	exit(0);
}
