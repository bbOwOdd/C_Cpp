## Mini C-like Compiler in C

### Overview
This is a small and simple expression language interpreter implemented in C
- Text break down in lexer
- Recursive descent parser for language analysis
- AST using fixed-size node pool (no malloc)
- Fixed-size symbol table (a-z variables)
- Evaluate the output

### Features
- Variable assignment ("let x = 10;")
- Arithmetic operations ("+ - * /")
- Print statements ("print x;")
- All memory structures are fixed size

### Build & Run
make
./test
