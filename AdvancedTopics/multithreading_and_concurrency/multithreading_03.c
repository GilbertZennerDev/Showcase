#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 10
#define NUMBER_OF_ITERATIONS 10

void *print_numbers(void *arg)
{
	int thread_id = *(int *)arg;
	for(int i=0; i<NUMBER_OF_ITERATIONS; i++)
	{
		printf("thread %d and i = %d\n", thread_id, i);
	//	sleep(1);
	}
	return NULL;
}

int	main(void)
{
	pthread_t threads[NUMBER_OF_THREADS];
	int ids[NUMBER_OF_THREADS];
	
	for(int i=0; i <NUMBER_OF_THREADS; i++)
	{
		ids[i] = i;
		pthread_create(&threads[i], NULL, print_numbers, &ids[i]);
	}
		for(int i=0; i < NUMBER_OF_THREADS; i++)
	{	
		pthread_join(threads[i], NULL);
	}

	return 0;
}
