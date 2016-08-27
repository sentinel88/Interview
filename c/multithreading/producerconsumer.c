#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define MAX_ELEM 3
#define MAX_ITER 25

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int buffer[MAX_ELEM];
int count = 0;



/* If pthread cond broadcast / signal is called after pthread mutex unlock, then it maybe the case that between the unlock statement and broadcast statement, some other thread may lock the mutex which is not necessarily waiting on the mutex. And, the threads waiting on the condition variable will be blocked as it cannot acquire the mutex */
static void* 
producer(void *arg)
{
	int sleep_time;
	int in = 0;
	int loop = MAX_ITER;
	while (loop--) {
		sleep_time = (random() % 10) + 1;
		sleep(sleep_time);
		pthread_mutex_lock(&mutex);
		while (count == MAX_ELEM) {
			printf("\nProducer cannot produce new element because the buffer is full\n");
			pthread_cond_wait(&cond, &mutex);
		} 
		buffer[in] = (random() % 65535) + 1;
		printf("\nProducer producing next item in the buffer: %d\n", buffer[in]);
		in = (in + 1) % MAX_ELEM;
		count++;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
	}
}


static void*
consumer(void *arg)
{
	int sleep_time;
        int out = 0;
        int loop = MAX_ITER;
	int nextConsumed = 0;
        while (loop--) {
                sleep_time = (random() % 20) + 1;
                sleep(sleep_time);
                pthread_mutex_lock(&mutex);
                while (count == 0) {
                        printf("\nConsumer cannot consume anything as there are no elements in the buffer\n");
                        pthread_cond_wait(&cond, &mutex);
                }
		nextConsumed = buffer[out];
                printf("\nConsumer consuming next item in the buffer: %d\n", nextConsumed);
                out = (out + 1) % MAX_ELEM;
                count--;
                pthread_cond_broadcast(&cond);
                pthread_mutex_unlock(&mutex);
        }
}


int main()
{
	pthread_t prod = 0;
	pthread_t cons = 0;	

	printf("\nProducer Consumer problem\n");
	if (pthread_create(&prod, NULL, &producer, NULL)) {
		printf("\nError creating the producer thread. Exiting\n");
		exit(0);
	}
	if (pthread_create(&cons, NULL, &consumer, NULL)) {
		printf("\nError creating the producer thread. Exiting\n");
		exit(0);
	}
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
		
	return 0;
}
