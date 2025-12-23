#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble();
void shaker();
void selection();
void insertion();
void shell();
void show();
void getRandomNum();

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    // bubble();
    // selection();
    // insertion();
    // shaker();
    shell();
    show();
}

void bubble(){
    int tmp;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[i]){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }  
        }
    }
}

void shaker(){  //改良版bubble
    int tmp, j;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i <= size / 2; i++){
        for(j = i - 1; j < size - i; j++){  //從左邊開始排
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        for(j = size - i - 1; j >= i; j--){ //從右邊開始排
            if(arr[j] < arr[j - 1]){
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void selection(){  
    int tmp, minIndex;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){  //尋找最小值
                minIndex = j;
            }
        }
        //最小值位置與起始位置調換
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

void insertion(){  //選擇最大或最小值插入最起始位置
    int j, tmp;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void shell(){  //改良版insert
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int gap = size / 2; gap > 0; gap /= 2){  //以gap進行排序，隨後減半gap
        for(int i = gap; i < size; i++){
            int tmp = arr[i];

            int j;
            for(j = i; j >= gap && arr[j - gap] > tmp; j -= gap) arr[j] = arr[j - gap];  //v1根據gap值與v2做調換
            arr[j] = tmp;  //前面已排序，做最後插入
        }
    }
}

void show(){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The list: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void getRandomNum(){  //洗牌法，先把數字放進陣列，接著透過隨機數當作key，讓起始位置與隨機數key位置交換
    int i, r, tmp;
    srand((unsigned)time(NULL));
    for(i = 0; i < MAX_LENGTH; i++){
        arr[i] = i;
    }

    for(i = 0; i < MAX_LENGTH; i++){
        r = rand() % 10;
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }

}
