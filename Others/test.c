#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// find max
#define MAX(a, b) ((a) > (b)) ? a : b

// seconds per year
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL

// return array size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// set, clear, reverse and check bit
#define SET_BIT(a, b) ((a) |= (1 << b))
#define CLEAR_BIT(a, b) ((a) &= ~(1 << b))
#define REVERSE_BIT(a, b) ((a) ^= (1 << b))
#define CHECK_BIT(a, b) ((a) & (1 << b))
void setBit(int a, int b) { a |= (1 << b); }
void clearBit(int a, int b) { a &= ~(1 << b); }
void reverseBit(int a, int b){ a ^= (1 << b); }
void checkBit(int a, int b) { a & (1 << b); }

// power of 2
bool powerOf2(int n){
    return n > 0 && (n & (n - 1)) == 0;
}

// power of 4
bool isPowerOfFour(int n){
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
}

bool multipleOf3(int n){
    while(n > 3) n -= 3;
    return (n == 0 || n == 3);
}

// print MSB & LSB
void printMSBLSB(uint32_t n){
    uint16_t msb = (n >> 16) & 0xFFFF;
    uint16_t lsb = n & 0xFFFF;
    printf("msb: 0x%x, lsb: 0x%x", msb, lsb);
}

// number of 1 bits
int hammingWeight(int n){
    int ans = 0;
    while(n){
        n &= (n - 1);
        ans++;
    }
    return ans;
}

// given 2 integers & print the distance of 1 bit
int hammingDistance(int x, int y){
    int n = x ^ y;
    int ans = 0; 
    while(n){
        n &= (n - 1);
        ans++;
    }
    return ans;
}

// reverser 32 bits
unsigned int reverse32Bits(unsigned int n){
    unsigned int ans = 0;
    for(int i = 0; i < 32 && n; i++){
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ans;
}

// reverse hex data
unsigned int reverseHex(unsigned int n){
    unsigned int result = 0;
    for(int i = 0; i < 8; i++){
        result = (result << 4) | (n & 0xF);
        n >>= 4;
    }
    return result;
}

// print binary of a number
void printBinary(unsigned int n){
    int bits = sizeof(n) * 8;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

// print hex of a number
void printHex(unsigned int n){
    printf("0x%x", n);
}

// print 1's complement of a number
void printComplement(unsigned int n){
    unsigned int mask = 0;
    unsigned int tmp = n;
    if(n == 0) return 1;
    while(tmp){ 
        mask = (mask << 1) | 1;
        tmp >>= 1;
    }
    printf("%d", (~n) & mask);
}

// uint8 array to uint32, little endian
int array_to_uint32(const uint8_t *arr, size_t len, uint32_t *result){
    *result = 0;
    for(int i = 0; i < len; i++){
        *result |= ((uint32_t)arr[i]) << (8 * i);
    }
    return 0;
}

// uint8 array to uint32, big endian
int array_to_uint32(const uint8_t *arr, size_t len, uint32_t *result){
    *result = 0;
    for(int i = 0; i < len; i++){
        *result |= ((uint32_t)arr[i]) << (8 * (len - 1 - i));
    }
    return 0;
}

// print the position of MSB & LSB
void highestBit(unsigned int n){
    if(n <= 0) return;
    int pos = 31;
    unsigned int mask = 1U << 31;
    while((n & mask) == 0){
        pos--;
        n >>= 1;
    }
    printf("Position of MSB: %d", pos);
}

void lowestBit(unsigned int n){
    if(n <= 0) return;
    int pos = 0;
    unsigned int mask = 1U;
    while((n & mask) == 0){
        pos++;
        n <<= 1;
    }
    printf("Position of LSB: %d", pos);
}

// GCD & LCM
int gcd(int x, int y){
    return y == 0 ? x: gcd(y, x % y);
}

int lcm(int x, int y){
    return x * y / gcd(x, y);
}

// check prime number
bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// round off
int floor(double x){
    int n = (int)x;
    return n < 0 && x != n ? n - 1 : n;
}

int ceil(double x){
    int n = (int)x;
    return n < 0 && x != n ? n + 1 : n;
}

int round(double x){
    return x >= 0 ? (int)(x + 0.5) : (int)(x - 0.5);
}

// toUpper & toLower, A: 65 a: 97
char convertUpperOrLower(char c){
    if(c >= 'A' && c <= 'Z') return c + 32; //toUppoer
    else if(c >= 'a' && c <= 'z') return c - 32; //toLower
    else return 0;
}

// access a fixed memory location in 64 bits machine
uint64_t* readMem(u_int64_t addr){
    uint64_t *p = addr;
    return *p;
}

uint64_t writeMem(uint64_t addr, uint64_t data){
    uint64_t *p = addr;
    *p = data;
}

void updateMem(unsigned int addrA, unsigned int addrB){
    int *ptr = (int*)addrA; //ex: 0x67a9
    *ptr = addrB; //ex: 0xaa55
}

// check little endian or big endian
void checkLittleOrBig(unsigned int n){
    char *c = (char*)&n;
    if(*c == n) puts("little endian");
    else puts("big endian");
}

// check hex is equal
bool isHexEqual(unsigned short n){
    unsigned short hex[4] = {0};
    hex[0] = (n & 0xF000) >> 12;
    hex[1] = (n & 0x0F00) >> 8;
    hex[2] = (n & 0x00F0) >> 4;
    hex[3] = n & 0x000F;

    if(hex[0] == hex[1] && hex[0] && hex[2] && hex[0] == hex[3]) return true;
    else return false;
}

// fibonacci number
int fib(int n){
    int dp[1001] = {0};
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1] + dp[n - 2];
}

// swap number
void swapNum(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

    // int tmp = *a;
    // *a = *b;
    // *b = tmp;
}

// binary search
int search(int* arr, int target){
    int len = sizeof(arr) / sizeof(arr[0]);
    int left = 0, right = len - 1;
    int mid = (left + right) >> 1;

    while(left <= right){
        if(target == arr[mid]) return mid;
        else if(target < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return arr[left] == target ? left : -1;
}

// given 3 numbers & find max, min
typedef struct ret_val{
    int max;
    int min;
} ret_val;

ret_val findMaxMin(int a, int b, int c){
    ret_val ret = {
        .max = 0,
        .min = 0
    };

    int arr[3] = {a, b, c};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    
    ret.max = arr[0];
    ret.min = arr[2];
    return ret;
}

// highest 1 bit postion (phison)
void highest1Bit(unsigned int n){
    unsigned int mask = 128;
    int count = 7;
    while(((n & mask) >> count) != 1){
        count--;
        n >>= 1;
    }
    printf("Position of highest 1 bit: %d", count);
}

// given a range of a sorted array & print numbers not in given array (phison)
void printNum1(int* arr, int range){
    int* ptr = arr;
    for(int i = 0; i < range; i++){
        if(*ptr == i) ptr++;
        else printf("%d ", i);
    }
}

// extend printNum1 & given b & output, ex: b = 0 output = 0~99, b = 1 output = 100~199 (phison)
void printNum2(int* arr, int b){
    int *ptr = arr;
    while(*ptr < b * 100) ptr++;
    for(int i = b * 100; i < (b + 1) * 100; i++){
        if(*ptr == i) ptr++;
        else printf("%d ", i);
    }
}

// print sum of 1 + 2 + 4 + 7 + ... + 106
void printSumOfNum(){
    int sum = 0, i = 1, j = 1;
    while(j <= 106){
        sum += i;
        i += j;
        j++;
    }
    printf("Sum: %d", sum);
}

// print 9 x 9 table
void print9x9Table(){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %2d  ", i, j, i * j);
        }
        printf("\n");
    }
}

// print pascal triangle
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