#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

void swap(int *a, int *b);
int partition(int low, int high);
void quick(int low, int high);
void getRandomNum();
void show();

int main(){

    getRandomNum();
    show();

    int size = sizeof(arr) / sizeof(arr[0]);
    quick(0, size - 1);
    show();
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int low, int high){
    int pivot = arr[high];  //choose the pivot from high index
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){  //current element of index < pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick(int low, int high){
    if(low < high){
        int pi = partition(low, high);  //the index of pivot
        quick(low, pi - 1); //smaller elements go left
        quick(pi + 1, high);  //larger elements go left
    }
}

void getRandomNum(){  //洗牌法，先把數字放進陣列，接著透過隨機數當作key，讓起始位置與隨機數key位置交換
    int i, r, tmp;
    srand((unsigned)time(NULL));
    for(i = 0; i < MAX_LENGTH; i++){
        arr[i] = i;
    }

    for(i = 0; i < MAX_LENGTH; i++){
        r = rand() % 10;
        swap(&arr[i], &arr[r]);
    }
}

void show(){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The list: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}
