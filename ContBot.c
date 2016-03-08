#include <cstdio>
#include <iostream>
#include <vector>
#include "arbolSintactico.c"
#include <stdlib.h>
using namespace std;

// En las siguientes lineas se "importan" varias funciones y variables
// De tanto el parser como el lexer para que funcionen aqui

// Igualmente se trae la raiz del arbol sintactico y la lista de errores, desde el
// parser y el lexer respectivamente

extern ArbolSintactico* raiz;
extern int yylex();
extern int yyparse();
extern char* errores[];
extern int columnError[];
extern int rowError[];
extern int nroErrores;
extern FILE* yyin;

//Firma de la funcion para poder usarla en el main

void printErrores();

// Funcion principal, chequea el numero de argumentos, y si es correcto
// intenta abrir el archivo y realizar el analisis sintactico
// Al finalizar dicho analisis, de no haber errores se imprime el arbol creado
// por la salida estandar, de haber errores se imprimen dichos errores.

int main(int argc, char *argv[]){
	bool listo;

	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}



	// Se cambia la entrada del lexer para ser el archivo dado.
	if ((yyin = fopen(argv[1],"r")) == NULL){
		printf("El archivo %s no se puede abrir\n",argv[1]);
		return 0;
	}


	listo = yyparse();

	//Se chequea el numero de errores y se imprime lo debido
	if (listo == 0 and nroErrores == 0){
		if (raiz->verificar()){
			raiz->toString(0);
		}
		else{
			printf("YAY\n");
		}
	}
	else{
		printf("Error al realizar el analisis sintactico\n"); 
	}
	if(nroErrores != 0){
		printErrores();
	}

	return 0;

}

// Esta funcion imprime errores detectados por el lexer durante el analisis lexicografico

void printErrores(){
	printf("Se han encontrado caracteres inesperados:\n");
	for (int i = 0 ; i < nroErrores;i++){
		printf("Error: Caracter Inesperado \"%s\" en la fila %d, columna %d.\n",errores[i],rowError[i],columnError[i]);
		free(errores[i]); 	// Se usan apuntadores a caracteres
	}						// ya que flex solo trabaja en C
}							// y por lo tanto se deben liberar