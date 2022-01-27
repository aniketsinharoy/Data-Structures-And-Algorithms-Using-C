#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main (void) 
{
	int* p = (int*) malloc(2);
	*p=0;
	printf("Zombie porcess having Process ID: %d created...\n",getpid());
	exit(0);
}
