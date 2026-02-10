#include <stdlib.h>

int strlen(const char *str);
char* strcpy(char *dest, const char *src);
char* strcat(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
const char* strchr(const char *str, char *c);
void strrev(char *str);

int main(){

    return;
}

int strlen(const char *str){
    int count = 0;
    while(*str != "\0"){
        count++;
        str++;
    }
    return count;
} 

char* strcpy(char *dest, const char *src){
    char *ret = dest;
    assert(src != NULL);
    assert(dest != NULL);
    while(*dest++ = *src++);
    return ret;
}

char* strcat(char *dest, const char *src){
    char *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    while(*dest != "\0") dest++;
    while(*dest++ = *src++);
    return ret;
}

int strcmp(const char *s1, const char *s2){
    while(*s1 && *s2 && *s1 == *s2){
        s1++;
        s2++;
    }
    return *s2 - *s1;
}

const char* strchr(const char *str, char *c){
    assert(*str != NULL);
    while(*str != "\0" && *str != c) str++;
    return *str == c ? str : NULL;
}

void strrev(char *str){
    assert(*str != NULL);
    char tmp;
    int len = strlen(str);

    for(int i = 0; i < len / 2; i++){
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}