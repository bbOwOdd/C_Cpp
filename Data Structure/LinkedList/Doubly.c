#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
}ListNode;

ListNode *createNode(int v);
void push_back(ListNode **head, int v);
void push_front(ListNode **head, int v);
void insertNth(ListNode **head, int pos, int v);
ListNode *search(ListNode **head, int v);
bool modify(ListNode *head, int v);
void deleteNode(ListNode **head, int v);
void sort(ListNode **head);
void reverse(ListNode **head);
void show(ListNode **head);

int main(){
    ListNode *list = NULL;
    return 0;
}

ListNode *createNode(int v){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(!newNode) return NULL;
    newNode->data = v;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void push_back(ListNode **head, int v){
    ListNode *newNode = createNode(v);
    if(!newNode) return;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    ListNode *current = *head;
    while(current->next != NULL) current = current->next;
    newNode->prev = current;
    current->next = newNode;
}

void push_front(ListNode **head, int v){
    ListNode *newNode = createNode(v);
    if(!newNode) return;
    newNode->next = *head;
    if(*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

void insertNth(ListNode **head, int pos, int v){
    ListNode *newNode = createNode(v);
    if(!newNode) return;

    if(pos <= 0 || *head == NULL){
        newNode->next = *head;
        if(*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    ListNode *current = *head;
    for(int i = 0; i < pos - 1 && current->next != NULL; i++){
        current = current->next;
    }

    newNode->next = current->next;
    if(current->next != NULL) current->next->prev = newNode;
    newNode->prev = current;  
    current->next = newNode;
}

ListNode *search(ListNode **head, int v){
    ListNode *current = *head;
    while(current != NULL){
        if(current->data == v) return current;
        current = current->next;
    }

    return NULL;
}

bool modify(ListNode *node, int v){
    if(!node) return false;
    node->data = v;
    return true;
}

void deleteNode(ListNode **head, int v){;
    ListNode *current = *head;
    ListNode *prev = NULL, *next = NULL, *tmp = NULL;
    while(current != NULL){
        if(current->data == v){
            tmp = current;
            if(prev == NULL){
                current = current->next;
                *head = current;
                if(*head != NULL) (*head)->prev = NULL;
            }else{
                next = current->next;
                prev->next = next;
                if(next != NULL) next->prev = prev;
                current = next;
            }
            free(tmp);
            tmp = NULL;
        } else{
            prev = current;
            current = current->next;
        }      
    }
}

void sort(ListNode **head){
    int tmp;
    for(ListNode *i = *head; i != NULL; i = i->next){
        for(ListNode *j = *head; j != NULL; j = j->next){
            if(i->data > j->data){
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void reverse(ListNode **head){
    ListNode *current = *head;
    ListNode *tmp = NULL;

    while (current != NULL) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    if(tmp != NULL) *head = tmp->prev;
}

void show(ListNode **head){
    ListNode *current = *head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}
