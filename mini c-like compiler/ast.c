#include "ast.h"
#include <stdio.h>

static ASTNode node_pool[AST_POOL_SIZE];
static uint32_t node_used = 0;

void ast_init(void) {
    node_used = 0;
}

ASTNode *ast_alloc(void) {
    if (node_used >= AST_POOL_SIZE) {
        printf("AST pool overflow\n");
        return NULL;
    }
    return &node_pool[node_used++];
}

/* ===== Constructors ===== */

ASTNode *ast_make_num(int32_t v) {
    ASTNode *n = ast_alloc();
    if (!n) return NULL;
    n->type = AST_NUM;
    n->value = v;
    return n;
}

ASTNode *ast_make_binop(BinOp op, ASTNode *l, ASTNode *r) {
    ASTNode *n = ast_alloc();
    if (!n) return NULL;
    n->type = AST_BINOP;
    n->binop.op = op;
    n->binop.left = l;
    n->binop.right = r;
    return n;
}

ASTNode *ast_make_var(char name) {
    ASTNode *n = ast_alloc();
    if (!n) return NULL;
    n->type = AST_VAR;
    n->var_name = name;
    return n;
}

ASTNode *ast_make_assign(char name, ASTNode *expr) {
    ASTNode *n = ast_alloc();
    if (!n) return NULL;
    n->type = AST_ASSIGN;
    n->assign.var_name = name;
    n->assign.expr = expr;
    return n;
}

ASTNode *ast_make_print(ASTNode *expr) {
    ASTNode *n = ast_alloc();
    if (!n) return NULL;
    n->type = AST_PRINT;
    n->print_expr = expr;
    return n;
}
