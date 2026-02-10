CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o lexer.o parser.o ast.o symbol.o eval.o

execute: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c lexer.h parser.h ast.h symbol.h eval.h
	$(CC) $(CFLAGS) -c main.c

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h ast.h lexer.h
	$(CC) $(CFLAGS) -c parser.c

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

symbol.o: symbol.c symbol.h
	$(CC) $(CFLAGS) -c symbol.c

eval.o: eval.c eval.h ast.h symbol.h
	$(CC) $(CFLAGS) -c eval.c

clean:
	rm -f *.o execute