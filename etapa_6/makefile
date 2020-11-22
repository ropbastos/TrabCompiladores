default: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c ast.c hash.c stack.c namelists.c errors.c parse_helper.c iloc.c asm.c
	gcc -o parser main.o ast.o hash.o stack.o namelists.o errors.o parse_helper.o iloc.o asm.o lex.yy.o parser.tab.o -lfl
	cp parser etapa6

clean:
	rm -f lex.* parser.tab* parser.out* parser *.o etapa* diag* out*
	
fsm:
	bison -v -d parser.y

diag:
	make
	./etapa6 < tests2 > out.txt
	python3 txt_to_diag.py out.txt diag.txt
	dot diag.txt -Tpng > diag.png

debug: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -g -c lex.yy.c parser.tab.c main.c ast.c hash.c stack.c namelists.c errors.c parse_helper.c iloc.c asm.c
	gcc -o parser main.o ast.o hash.o stack.o namelists.o errors.o parse_helper.o iloc.o asm.o lex.yy.o parser.tab.o -lfl
	cp parser etapa6

val:
	make
	valgrind --leak-check=full ./etapa6 < tests2