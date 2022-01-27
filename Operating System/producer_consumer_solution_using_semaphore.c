#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define upper 100
#define lower 0
#define buffersize 15

sem_t empty;
sem_t full;
sem_t mutex;

int produce_count=0;
int consumer_count=0;
int buffer[buffersize];

void producer(void *pno)
{
	for (int i=0;i<9;++i)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		int item= (rand()%(upper-lower+1))+lower;
		buffer[produce_count++]=item;
		printf("At index %d item produced: %d\n",(produce_count-1),item);
		sem_post(&mutex);
		sleep(2);
        	sem_post(&full);
	}
}
void consumer(void *cno)
{
	for (int i=0;i<6;++i)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		int item= buffer[consumer_count++];
		printf("At index %d item consumed: %d\n",(consumer_count-1),item);
		sem_post(&mutex);
		sleep(2);
        	sem_post(&empty);	
	}
}
int main()
{
	sem_init(&mutex,0,1);
    	sem_init(&empty,0,buffersize);
    	sem_init(&full,0,0);
	pthread_t prod_t, cons_t;
	pthread_create(&cons_t,NULL,(void *)consumer,NULL);
	pthread_create(&prod_t,NULL,(void *)producer,NULL);
	pthread_join(prod_t,NULL);
	pthread_join(cons_t,NULL);
	sem_destroy(&mutex);
    	sem_destroy(&empty);
    	sem_destroy(&full);
	return 0;
}
