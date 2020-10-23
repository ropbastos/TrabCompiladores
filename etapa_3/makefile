default: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c ast.c
	gcc -o parser main.o ast.o lex.yy.o parser.tab.o -lfl
	cp parser etapa3

clean:
	rm -f lex.* parser.tab* parser.out* parser *.o etapa* diag* out* w*
	
fsm:
	bison -v -d parser.y

diag:
	make
	./etapa3 < tests2 > out.txt
	python3 txt_to_diag.py out.txt diag.txt
	dot diag.txt -Tpng > diag.png

debug: scanner.l main.c ast.c parser.y
	bison -d parser.y
	flex scanner.l
	gcc -g -c lex.yy.c parser.tab.c main.c ast.c
	gcc -o parser main.o ast.o lex.yy.o parser.tab.o -lfl
	cp parser etapa3

val:
	make
	valgrind --leak-check=full ./etapa3 < tests2

valbatch:
	make
	tar xf E3_testes_prof.tgz
	./val_batch_test.zsh
	make clean
