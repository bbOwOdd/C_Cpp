#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>

/* ===== Token Types ===== */

typedef enum {
    TOK_EOF,

    /* keywords */
    TOK_LET,
    TOK_PRINT,

    /* literals */
    TOK_NUM,
    TOK_IDENT,

    /* symbols */
    TOK_ASSIGN,   // =
    TOK_PLUS,     // +
    TOK_MINUS,    // -
    TOK_MUL,      // *
    TOK_DIV,      // /
    TOK_SEMI,     // ;
    TOK_LPAREN,   // (
    TOK_RPAREN    // )
} TokenType;

/* ===== Token ===== */

typedef struct {
    TokenType type;
    int32_t   value;   // for number
    char      ident;   // for variable name
} Token;

/* ===== API ===== */

void lexer_init(const char *input);
Token lexer_next(void);

#endif
