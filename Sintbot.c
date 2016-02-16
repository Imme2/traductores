#include <cstdio>
#include <iostream>
#include <vector>
#include "trees.c"
#include <stdlib.h>
using namespace std;

extern arbolSintactico* raiz;
extern int yylex();
extern int yyparse();
extern char* errores[];
extern int columnError[];
extern int rowError[];
extern int nroErrores;
extern FILE* yyin;

void printErrores();

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


	if (listo == 0 and nroErrores == 0){
		raiz->toString(0);
	}
	else{
		printf("Error al realizar el analisis sintactico\n");
	}
	if(nroErrores != 0){
		printErrores();
	}
	
	return 0;

}

void printErrores(){
	printf("Se han encontrado caracteres inesperados:\n");
	for (int i = 0 ; i < nroErrores;i++){
		printf("Error: Caracter Inesperado \"%s\" en la fila %d, columna %d.\n",errores[i],rowError[i],columnError[i]);
		free(errores[i]);
	}
}