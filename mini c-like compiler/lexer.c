#include "lexer.h"
#include <ctype.h>
#include <stdio.h>

/* input pointer */
static const char *src;

void lexer_init(const char *input) {
    src = input;
}

/* helper: skip whitespace */
static void skip_ws(void) {
    while (*src == ' ' || *src == '\t' || *src == '\n' || *src == '\r') {
        src++;
    }
}

Token lexer_next(void) {
    Token tok;
    skip_ws();

    /* end of input */
    if (*src == '\0') {
        tok.type = TOK_EOF;
        return tok;
    }

    /* number */
    if (isdigit(*src)) {
        int32_t val = 0;
        while (isdigit(*src)) {
            val = val * 10 + (*src - '0');
            src++;
        }
        tok.type = TOK_NUM;
        tok.value = val;
        return tok;
    }

    /* identifier / keyword */
    if (isalpha(*src)) {
        char c = *src++;
        if (c == 'l' && src[0] == 'e' && src[1] == 't') {
            src += 2;
            tok.type = TOK_LET;
            return tok;
        }
        if (c == 'p' &&
            src[0] == 'r' && src[1] == 'i' &&
            src[2] == 'n' && src[3] == 't') {
            src += 4;
            tok.type = TOK_PRINT;
            return tok;
        }
        tok.type = TOK_IDENT;
        tok.ident = c;
        return tok;
    }

    /* symbols */
    switch (*src) {
        case '=': tok.type = TOK_ASSIGN; break;
        case '+': tok.type = TOK_PLUS;   break;
        case '-': tok.type = TOK_MINUS;  break;
        case '*': tok.type = TOK_MUL;    break;
        case '/': tok.type = TOK_DIV;    break;
        case ';': tok.type = TOK_SEMI;   break;
        case '(': tok.type = TOK_LPAREN; break;
        case ')': tok.type = TOK_RPAREN; break;
        default:
            printf("Lexer error: unknown char '%c'\n", *src);
            tok.type = TOK_EOF;
            return tok;
    }

    src++;
    return tok;
}
