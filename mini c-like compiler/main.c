#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "ast.h"
#include "symbol.h"
#include "eval.h"

int main(void) {
    const char *code =
        "let a = 10;\n"
        "let b = a * 2 + 3;\n"
        "print b;\n";

    ast_init();
    sym_init();
    lexer_init(code);
    parser_init();

    while (1) {
        ASTNode *stmt = parse_stmt();
        if (!stmt) break;   // if EOF in parse_stmt then return NULL
        eval(stmt);
    }

    return 0;
}
