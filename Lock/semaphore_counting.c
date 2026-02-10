#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem;

void* worker(void* arg) {
    int id = *(int*)arg;

    sem_wait(&sem);
    printf("Thread %d enter CS\n", id);

    sleep(1);

    printf("Thread %d leave CS\n", id);
    sem_post(&sem);

    return NULL;
}

int main() {
    pthread_t t[10];
    int id[10];

    sem_init(&sem, 0, 3);  // counting semaphore, limit 3 process at a same time

    for(int i = 0; i < 10; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, worker, &id[i]);
    }

    for(int i = 0; i < 10; i++) pthread_join(t[i], NULL);

    sem_destroy(&sem);
    return 0;
}
