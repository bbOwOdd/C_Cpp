#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct Queue{
    ListNode* front;
    ListNode* back;
} Queue;

Queue* newQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;
    return q;
}

bool isEmpty(Queue *q);
void enqueue(Queue *q, int num);
int dequeue(Queue *q);
void freeQueue(Queue* q);

int main(){
    Queue *q = newQueue();
    return 0;
}

bool isEmpty(Queue *q){
    return (q->front == NULL);
}

void enqueue(Queue *q, int num){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = num;
    newNode->next = NULL;

    if(!isEmpty(q)){
        q->back->next = newNode;
        q->back = newNode;
    } else {
        q->front = q->back = newNode;
    }
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("The queue is empty.\n");
        return -1;
    }

    ListNode* deleteNode = q->front;
    int n = deleteNode->data;
    q->front = q->front->next;

    // 如果隊列變空，更新 back 指標
    if(q->front == NULL) q->back = NULL;

    free(deleteNode);
    return n;
}

void freeQueue(Queue* q){
    while(!isEmpty(q)) dequeue(q);
    free(q);
}
