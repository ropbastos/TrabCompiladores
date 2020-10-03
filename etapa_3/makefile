default: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c ast.c
	gcc -o parser main.o ast.o lex.yy.o parser.tab.o -lfl
	cp parser etapa3

clean:
	rm lex.* parser.tab* parser.out* parser main.o ast.o etapa*

dev:
	bison -v -d parser.y