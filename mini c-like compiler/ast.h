#ifndef AST_H
#define AST_H

#include <stdint.h>

/* ===== AST Node Types ===== */

typedef enum {
    AST_NUM,
    AST_BINOP,
    AST_VAR,
    AST_ASSIGN,
    AST_PRINT
} ASTType;

/* ===== Operators ===== */

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
} BinOp;

/* ===== AST Node ===== */

typedef struct ASTNode {
    ASTType type;

    union {
        /* number */
        int32_t value;

        /* binary operation */
        struct {
            BinOp op;
            struct ASTNode *left;
            struct ASTNode *right;
        } binop;

        /* variable */
        char var_name;

        /* assignment */
        struct {
            char var_name;
            struct ASTNode *expr;
        } assign;

        /* print */
        struct ASTNode *print_expr;
    };
} ASTNode;

/* ===== Node Pool ===== */

#define AST_POOL_SIZE 128

void ast_init(void);
ASTNode *ast_alloc(void);

ASTNode *ast_make_num(int32_t v);
ASTNode *ast_make_binop(BinOp op, ASTNode *l, ASTNode *r);
ASTNode *ast_make_var(char name);
ASTNode *ast_make_assign(char name, ASTNode *expr);
ASTNode *ast_make_print(ASTNode *expr);

#endif
