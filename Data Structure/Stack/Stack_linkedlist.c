#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct Stack{
    ListNode* top;
} Stack;

Stack* newStack(){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

bool isEmpty(Stack* st);
int stackTop(Stack* st);
void push(Stack* st, int num);
int pop(Stack* st);
void freeStack(Stack* st);

int main(){
    Stack *st = newStack();
    return 0;
}

bool isEmpty(Stack* st){
    return (st->top == NULL);
}

int stackTop(Stack* st){
    if(isEmpty(st)){
        printf("The stack is empty.\n");
        return -1;
    }
    return st->top->data;
}

void push(Stack* st, int num){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = num;
    newNode->next = st->top;
    st->top = newNode;
}

int pop(Stack* st){
    if(isEmpty(st)){
        printf("The stack is empty.\n");
        return -1;
    }
    ListNode* deleteNode = st->top;
    int x = deleteNode->data;
    st->top = st->top->next;
    free(deleteNode);
    return x;
}

void freeStack(Stack* st){
    while(!isEmpty(st)) pop(st);
    free(st);
}
