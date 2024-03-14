#include <stdio.h>
#include <pthread.h>

void *displayhello(void *arg) {
    printf("Hello ");
    pthread_exit(NULL);
}

void *displayworld(void *arg) {
    printf("World");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, displayhello, NULL);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, displayworld, NULL);
    pthread_join(thread2, NULL);

}
