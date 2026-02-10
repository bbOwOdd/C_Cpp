#include <stdio.h>
#include <stdlib.h>

int main(){
    int h = 5;
    printPascal(h);
    
    return 0;
}

void printPascal(int n){
    int a[10][10] = {0};

    // 計算帕斯卡三角形
    for (int i = 0; i < n; i++) {
        a[i][0] = 1;          // 每一列的第一個都是 1
        a[i][i] = 1;          // 每一列的最後一個都是 1
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    // 輸出帕斯卡三角形
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) { // 控制排版（置中）
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}