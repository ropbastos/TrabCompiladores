default: scanner.l main.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c
	gcc -o parser lex.yy.o parser.tab.o -lfl

clean:
	rm lex* parser.tab* parser.out* parser

dev:
	bison -v -d parser.y