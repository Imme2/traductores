Sintbot: flex.o parser.o trees.o
	g++ -o SintBot Sintbot.c lex.yy.c parser.tab.c

parser.o: flex.o trees.o
	bison -d parser.y

flex.o: 
	flex scanner.l

trees.o:
	g++ -c trees.c

clean:
	rm parser.tab.h Sintbot lex.yy.c parser.tab.c trees.o