default: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c ast.c hash.c stack.c namelists.c errors.c parse_helper.c iloc.c
	gcc -o parser main.o ast.o hash.o stack.o namelists.o errors.o parse_helper.o iloc.o lex.yy.o parser.tab.o -lfl
	cp parser etapa5

clean:
	rm -f lex.* parser.tab* parser.out* parser *.o etapa* diag* out*
	
fsm:
	bison -v -d parser.y

diag:
	make
	./etapa4 < tests2 > out.txt
	python3 txt_to_diag.py out.txt diag.txt
	dot diag.txt -Tpng > diag.png

debug: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -g -c lex.yy.c parser.tab.c main.c ast.c hash.c stack.c namelists.c errors.c parse_helper.c iloc.c
	gcc -o parser main.o ast.o hash.o stack.o namelists.o errors.o parse_helper.o iloc.o lex.yy.o parser.tab.o -lfl
	cp parser etapa5

val:
	make
	valgrind --leak-check=full ./etapa5 < tests2