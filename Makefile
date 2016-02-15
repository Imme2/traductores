Sintbot: flex.o parser.o trees.o
	g++ -o Sintbot Sintbot.c lex.yy.c parser.tab.c

parser.o: flex.o trees.o
	bison -d parser.y -Wconflicts-sr -Wconflicts-rr

flex.o: 
	flex scanner.l

trees.o:
	g++ -c trees.c

clean:
	rm parser.h Sintbot lex.yy.c parser.c