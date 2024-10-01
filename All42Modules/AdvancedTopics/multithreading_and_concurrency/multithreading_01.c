#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *print_numbers(void *arg)
{
	int thread_id = *(int*)arg;
	for(int i=0; i <= 5; i++)
	{
		printf("Thread %d: %d\n", thread_id, i);
		sleep(1);
	}
	return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2, id3 = 3;

    // Create three threads
    pthread_create(&thread1, NULL, print_numbers, &id1);
    pthread_create(&thread2, NULL, print_numbers, &id2);
    pthread_create(&thread3, NULL, print_numbers, &id3);
    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have finished execution.\n");
    return 0;
}
