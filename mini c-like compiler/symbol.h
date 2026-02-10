#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdint.h>

#define MAX_SYMBOLS 26   /* a-z */

void sym_init(void);
int  sym_set(char name, int32_t value);
int  sym_get(char name, int32_t *out);

#endif
