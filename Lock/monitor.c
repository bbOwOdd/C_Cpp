#include <pthread.h>
#include <stdio.h>

typedef struct monitor_t{
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
    int buffer;
    int full;
} monitor_t;

monitor_t m;

void monitor_init(monitor_t* m) {
    pthread_mutex_init(&m->mutex, NULL);
    pthread_cond_init(&m->not_empty, NULL);
    pthread_cond_init(&m->not_full, NULL);
    m->full = 0;
}

void produce(int value) {
    pthread_mutex_lock(&m.mutex);

    while(m.full) pthread_cond_wait(&m.not_full, &m.mutex);

    m.buffer = value;
    m.full = 1;
    printf("Produced %d\n", value);

    pthread_cond_signal(&m.not_empty);
    pthread_mutex_unlock(&m.mutex);
}

void consume() {
    pthread_mutex_lock(&m.mutex);

    while(!m.full) pthread_cond_wait(&m.not_empty, &m.mutex);

    printf("Consumed %d\n", m.buffer);
    m.full = 0;

    pthread_cond_signal(&m.not_full);
    pthread_mutex_unlock(&m.mutex);
}
