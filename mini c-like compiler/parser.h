#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

void parser_init(void);
ASTNode *parse_stmt(void);       // public: parse one statement

#endif
