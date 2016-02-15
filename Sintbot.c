#include <cstdio>
#include <iostream>
#include <vector>
#include "trees.c"
using namespace std;

//extern arbolSintactico* raiz;
//extern int yylex();
extern int yyparse();

/*
extern char* errores[];
extern int columnError[];
extern int rowError[];
extern int nroErrores;
*/

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}

	bool listo;
	listo = yyparse();
	if (listo){
		//arbolSintactico.print();
	}
	else{
		printf("El archivo %s no parece existir o no se puede leer\n",argv[1]);
	}
	return 0;

}