#include <stdbool.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

ListNode* createNode(int v);
void push_back(ListNode **head, int v);
void push_front(ListNode **head, int v);
void show(ListNode *head);
void insertNth(ListNode **head, int pos, int v);
void reverse(ListNode **head);
void delete(ListNode **head, int v);
ListNode* search(ListNode *head, int v);
int modify(ListNode *node, int v);
void freeList(ListNode *head);
ListNode* deleteDupilicate(ListNode *head);
void sort(ListNode *head);
bool hasCycle(ListNode *head);
ListNode *mergeTwoListsList(Node *list1, ListNode *list2);
ListNode *copyList(ListNode *head);

int main(){

    ListNode *list = NULL;
    return 0;
}

ListNode* createNode(int v){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(!newNode) return NULL;
    newNode->data = v;
    newNode->next = NULL;
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
    while(current != NULL) current = current->next;
    current->next = newNode;
}

void push_front(ListNode **head, int v){
    ListNode *newNode = createNode(v);
    if(!newNode) return;
    newNode->next = *head;
    *head = newNode;
}

void show(ListNode *head){
    ListNode *current = head;
    if(!current) return;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }

    // if(!head) return;
    // printf("%d ", head->data);
    // show(head->next);
}

ListNode* search(ListNode *head, int v){
    ListNode *current = head;
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

void insertNth(ListNode **head, int v, int pos) {
    ListNode* newNode = createNode(v);
    if(!newNode) return;

    if(pos <= 0 || *head == NULL){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    ListNode *current = *head;
    for(int i = 0; i < pos - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(ListNode **head, int v){
    ListNode *prev = NULL, *next = NULL, *tmp = NULL;
    ListNode *current = *head;
    if(!current) return;

    while (current != NULL) {
        if(current->data == v){
            tmp = current;
            if(prev == NULL){
                current = current->next;
                *head = current;
            }else{
                next = current->next;
                prev->next = next;
                current = next;
            }
            free(tmp);
            tmp = NULL;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

void sort(ListNode *head) {
    if (head == NULL || head->next == NULL) return;

    int tmp;
    for (ListNode *i = head; i != NULL; i = i->next) {
        for (ListNode *j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void reverse(ListNode **head){
    ListNode *prev, *next, *current;
    current = *head;
    prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void freeList(ListNode *head){
    ListNode *current = head;
    ListNode *next = NULL;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

ListNode* deleteDupilicate(ListNode *head){ //already sorted
    ListNode *current = head;
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data) current->next = current->next->next;
        else current = current->next;
    }

    return head;
}

bool hasCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }

    return false;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){  //already sorted
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->data <= list2->data){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

void deleteEvenNode(ListNode **head){
    ListNode *prev = NULL, *next = NULL, *tmp = NULL;
    ListNode *current = head;
    if(!current) return;

    while(current != NULL){
        if(!(current->data & 1)){   //even node
            tmp = current;
            if(prev == NULL){
                current = current->next;
                *head = current;
            }else{
                next = current->next;
                prev->next = next;
                current = next;
            }
            free(tmp);
            tmp = NULL;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

ListNode *copyList(ListNode *head){
    if(head == NULL) return NULL;

    ListNode *tmp;
    ListNode *current = head;
    ListNode *newList = (ListNode*)malloc(sizeof(ListNode));
    newList->next = NULL;
    newList->data = current->data;
    tmp = newList;
    current = current->next;

    while(current != NULL){
        tmp->next = (ListNode*)malloc(sizeof(ListNode));
        tmp = tmp->next;
        tmp->data = current->data;
        tmp->next = NULL;
        current = current->next;
    }

    return newList;
}

