#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int top;
    int capacity;
    int *data;
} Stack;

Stack* newStack(int size){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->data = (int*)malloc(size * sizeof(int));
    st->top = -1;
    st->capacity = size - 1;
    return st;
}

bool isEmpty(Stack* st);
int stackTop(Stack* st);
bool isFull(Stack *st);
void push(Stack* st, int num);
int pop(Stack* st);
void freeStack(Stack* st);

int main(){
    Stack* st = new_stack(5);
    return 0;
}

bool isEmpty(Stack *st){
    return (st->top == -1);
}

int stackTop(Stack *st){
    if(isEmpty(st)){
        printf("The stack is empty.\n");
        return -1;
    }
    return st->data[st->top];
}

bool isFull(Stack *st){
    return (st->top == st->capacity);
}

void push(Stack *st, int num){
    if(isFull(st)) printf("The stack is full.\n");
    else st->data[++st->top] = num;
}

int pop(Stack *st){
    if(isEmpty(st)){
        printf("The stack is empty.\n");
        return -1;
    }
    return st->data[st->top--];
}

void freeStack(Stack *st){
    free(st->data);
    free(st);
}
