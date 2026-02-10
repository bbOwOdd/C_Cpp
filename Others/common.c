#include <stdio.h>
#include <stdlib.h>

struct GPIO
{
    char name[12];
    unsigned char direction;
    unsigned int val;
    struct GPIO* ptr;
};

union data
{
    unsigned char c;
    int val;
    long int li;
};

enum GPIO_NUM
{
    GPIO_IO1 = 0,
    GPIO_I02,
    GPIO_I03
};


int main(){
    struct GPIO g = 
    {
        .name = "test",
        .direction = 0,
        .val = 10,
        .ptr = NULL
    };

    union data d = 
    {
        .c = 255,
        .val = 15,
        .li = 100000
    };

    enum GPIO_NUM g2 = GPIO_IO1;
    
    printf("%s, %d, %d, %p\n", g.name, g.direction, g.val, g.ptr);
    printf("%d\n", d.c);
    printf("%d\n", GPIO_IO1);

    return 0;
}