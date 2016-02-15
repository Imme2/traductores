Sintbot: flex.o parser.o trees.o
	g++ -o Sintbot Sintbot.c lex.yy.c parser.c

parser.o: flex.o trees.o
	bison -d parser.y

flex.o: 
	flex scanner.ll

trees.o:
	g++ -c trees.c

clean:
	rm parser.h Sintbot lex.yy.c parser.c