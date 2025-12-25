#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue{
    int front;
    int back;
    int capacity;
    int *data;
} Queue;

Queue* newQueue(int size){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = size + 1; //多一格空間區分空與滿
    q->data = (int*)malloc(q->capacity * sizeof(int));
    q->front = 0;
    q->back = 0;
    return q;
}

bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int num);
int dequeue(Queue* q);
void freeQueue(Queue* q);

int main(){
    Queue *q = newQueue(5);
    return 0;
}

bool isEmpty(Queue* q){
    return (q->front == q->back);
}

bool isFull(Queue* q){
    return ((q->back + 1) % q->capacity == q->front);
}

void enqueue(Queue* q, int num){
    if(isFull(q)){
        printf("The queue is full.\n");
        return;
    }
    q->data[q->back] = num;
    q->back = (q->back + 1) % q->capacity;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("The queue is empty.\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return value;
}

void freeQueue(Queue* q){
    free(q->data);
    free(q);
}
