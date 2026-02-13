#include "symbol.h"

static int32_t table[MAX_SYMBOLS];
static uint8_t used[MAX_SYMBOLS];

void sym_init(void) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        used[i] = 0;
        table[i] = 0;
    }
}

int sym_set(char name, int32_t value) {
    int idx = name - 'a';
    if (idx < 0 || idx >= MAX_SYMBOLS) return -1;
    table[idx] = value;
    used[idx] = 1;
    return 0;
}

int sym_get(char name, int32_t *out) {
    int idx = name - 'a';
    if (idx < 0 || idx >= MAX_SYMBOLS || !used[idx]) return -1;
    *out = table[idx];
    return 0;
}
