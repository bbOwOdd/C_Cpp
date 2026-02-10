#include <stdio.h>

int main(){
    int n = 7;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            printf(" ");
        }
        for(int k = 0; k <= 2 * i; k++){
            printf("*");
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 2; j++){
            printf(" ");
        }
        printf("***\n");
    }
    return 0;
}
