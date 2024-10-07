#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*print_message(void *arg)
{
	int thread_id = *(int*)arg;
	for(int i=0; i < 10; i++)
	{
		printf("thread: %d, i = %d\n", thread_id, i);
		sleep(1);
	}
	return NULL;	
}

int	main(void)
{
	pthread_t thread1, thread2;
	int id1 = 1, id2 = 2;

	pthread_create(&thread1, NULL, print_message, &id1);
	pthread_create(&thread2, NULL, print_message, &id2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
