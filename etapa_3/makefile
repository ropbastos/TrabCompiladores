default: scanner.l main.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c
	gcc -o parser main.o lex.yy.o parser.tab.o -lfl
	cp parser etapa3
	
clean:
	rm lex* parser.tab* parser.out* parser main.o

dev:
	bison -v -d parser.y