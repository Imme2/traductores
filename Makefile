ContBot: flex.o parser.o arbolSintactico.o instrucciones.o declaraciones.o expresion.o listaids.o mapa.o
	g++ -o ContBot ContBot.c lex.yy.c parser.tab.c

parser.o: flex.o arbolSintactico.o parser.y
	bison -d parser.y

flex.o: scanner.l
	flex scanner.l

arbolSintactico.o: arbolSintactico.c instrucciones.o declaraciones.o
	g++ -o arbolSintactico.o -c arbolSintactico.c

instrucciones.o: instrucciones.c declaraciones.o expresion.o
	g++ -o instrucciones.o -c instrucciones.c

declaraciones.o: declaraciones.c expresion.c
	g++ -o declaraciones.o -c declaraciones.c

expresion.o: expresion.c
	g++ -o expresion.o -c expresion.c

listaids.o: listaids.c
	g++ -o listaids.o -c listaids.c

mapa.o: mapa.c
	g++ -o mapa.o -c mapa.c

clean:
	rm parser.tab.h ContBot lex.yy.c parser.tab.c *.o