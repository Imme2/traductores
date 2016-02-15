#include <cstdio>
#include <iostream>
#include <vector>
#include "trees.c"
using namespace std;

extern arbolSintactico* raiz;
extern int yylex();
extern int yyparse();
extern char* errores[];
extern int columnError[];
extern int rowError[];
extern int nroErrores;
extern FILE* yyin;


int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}


	if ((yyin = fopen(argv[1],"r")) == NULL){
		printf("El archivo %s no se puede abrir\n",argv[1]);
	}


	bool listo;
	listo = yyparse();
	if (listo == 0){
		raiz->toString(0);
	}
	else{
		printf("wat wat in th ebutt\n");
	}
	return 0;

}