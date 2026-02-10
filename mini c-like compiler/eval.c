#include "eval.h"
#include "symbol.h"
#include <stdio.h>

int32_t eval(ASTNode *node) {
    int32_t l, r;

    switch (node->type) {
        case AST_NUM:
            return node->value;

        case AST_VAR:
            if (sym_get(node->var_name, &l) != 0) {
                printf("Undefined variable: %c\n", node->var_name);
                return 0;
            }
            return l;

        case AST_BINOP:
            l = eval(node->binop.left);
            r = eval(node->binop.right);
            switch (node->binop.op) {
                case OP_ADD: return l + r;
                case OP_SUB: return l - r;
                case OP_MUL: return l * r;
                case OP_DIV: return l / r;
            }
            break;

        case AST_ASSIGN:
            r = eval(node->assign.expr);
            sym_set(node->assign.var_name, r);
            return r;

        case AST_PRINT:
            r = eval(node->print_expr);
            printf("%d\n", r);
            return r;
    }

    return 0;
}
