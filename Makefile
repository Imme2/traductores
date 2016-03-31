all: ContBot MapaRobots.c Robot.c Robot.h declaraciones.c Tipo.c listaids.c mapa.c Espacio.c valores.c

ContBot: flex.o parser.o arbolSintactico.o
	g++ -o ContBot ContBot.c lex.yy.c parser.tab.c

parser.o: flex.o arbolSintactico.o parser.y
	bison -d parser.y

flex.o: scanner.l
	flex scanner.l

arbolSintactico.o: arbolSintactico.c
	g++ -o arbolSintactico.o -c arbolSintactico.c

clean:
	rm parser.tab.h ContBot lex.yy.c parser.tab.c *.o