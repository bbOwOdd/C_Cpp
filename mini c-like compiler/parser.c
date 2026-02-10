#include "parser.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

/* current lookahead token */
static Token cur;

/* ===== helpers ===== */

static void next(void) {
    cur = lexer_next();
}

static void expect(TokenType t) {
    if (cur.type != t) {
        printf("Parse error: expected %d, got %d\n", t, cur.type);
        exit(1);
    }
    next();
}

/* forward declarations */
ASTNode *parse_stmt(void);
static ASTNode *parse_expr(void);
static ASTNode *parse_term(void);
static ASTNode *parse_factor(void);

/* ===== public API ===== */

void parser_init(void) {
    next();
}

/* stmt → let IDENT = expr ;
 *      | print expr ;
 */
ASTNode *parse_stmt(void) {
    if (cur.type == TOK_EOF) return NULL;

    ASTNode *node;
    if (cur.type == TOK_LET) {
        next();

        if (cur.type != TOK_IDENT) {
            printf("Expected identifier after let\n");
            exit(1);
        }
        char name = cur.ident;
        next();

        expect(TOK_ASSIGN);
        ASTNode *expr = parse_expr();
        expect(TOK_SEMI);

        node = ast_make_assign(name, expr);
        return node;
    }

    if (cur.type == TOK_PRINT) {
        next();
        ASTNode *expr = parse_expr();
        expect(TOK_SEMI);

        node = ast_make_print(expr);
        return node;
    }

    printf("Unknown statement\n");
    exit(1);
}

/* expr → term ((+ | -) term)* */
static ASTNode *parse_expr(void) {
    ASTNode *node = parse_term();

    while (cur.type == TOK_PLUS || cur.type == TOK_MINUS) {
        TokenType t = cur.type;
        next();
        ASTNode *rhs = parse_term();

        node = ast_make_binop(
            t == TOK_PLUS ? OP_ADD : OP_SUB,
            node,
            rhs
        );
    }
    return node;
}

/* term → factor ((* | /) factor)* */
static ASTNode *parse_term(void) {
    ASTNode *node = parse_factor();

    while (cur.type == TOK_MUL || cur.type == TOK_DIV) {
        TokenType t = cur.type;
        next();
        ASTNode *rhs = parse_factor();

        node = ast_make_binop(
            t == TOK_MUL ? OP_MUL : OP_DIV,
            node,
            rhs
        );
    }
    return node;
}

/* factor → NUMBER | IDENT | '(' expr ')' */
static ASTNode *parse_factor(void) {
    ASTNode *node;

    if (cur.type == TOK_NUM) {
        node = ast_make_num(cur.value);
        next();
        return node;
    }

    if (cur.type == TOK_IDENT) {
        node = ast_make_var(cur.ident);
        next();
        return node;
    }

    if (cur.type == TOK_LPAREN) {
        next();
        node = parse_expr();
        expect(TOK_RPAREN);
        return node;
    }

    printf("Unexpected token in factor\n");
    exit(1);
}
