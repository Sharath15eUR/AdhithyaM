#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5
#define MAX 10

int count = 0;
pthread_mutex_t mutex;

void *increment_counter(void *thread_id){
    long tid;
    tid = (long)thread_id;

    for (int i = 0; i < MAX; i++){
        pthread_mutex_lock(&mutex);
        count++;
        printf("Thread %ld: Incrementing count to %d\n", tid, count);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int rc;
    long t;

    pthread_mutex_init(&mutex, NULL);

    for(t = 0; t < THREADS; t++){
        rc = pthread_create(&threads[t], NULL, increment_counter, (void *)t);
        }

    for(t =0;t<THREADS;t++){
        pthread_join(threads[t], NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("Final count: %d\n", count);
    pthread_exit(NULL);
}
