#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t sem;

void* worker(void* arg) {
    sem_wait(&sem);
    printf("Access resource\n");
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem, 0, 1); // binary semaphore, limit 1 process at a same time

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    return 0;
}
