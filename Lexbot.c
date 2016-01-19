#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "scanner.h"	//Se incluyen aqui el header, que contiene las definiciones
#include "token.c"		// de los tipos, y las clases token y errtoken
#include "errtoken.c"

using namespace std;

#define TABVALOR 4		//por default se dice que una tabulacion tiene valor 4.		

extern int yylex();
extern int yylineno;
extern char* yytext;		// Se usa extern para traer desde lex.yy.c estos valores
extern FILE* yyin;			// y la funcion yylex
extern int yyleng;


// Firma de las funciones
bool tokenizeFile(char* , vector<token>& , vector<errToken>& );
void printTokens(vector<token>& , vector<errToken>&);


// Esta es la funcion principal, aqui se chequean el numero de
// argumentos y se imprimen por la salida estandar los errores
// en caso de que el archivo no se pueda leer o no se le hayan dado
// suficientes argumentos.

int main(int argc,char* argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}
	vector<token> tokens;     		// Se definen las listas de errores y tokens respectivamente
	vector<errToken> errores;		// para ser usadas en las funciones.

	bool listo;
	listo = tokenizeFile(argv[1],tokens,errores);
	if (listo){
		printTokens(tokens,errores);
	}
	else{
		printf("El archivo %s no parece existir o no se puede leer\n",argv[1]);
	}
	return 0;
}

// Esta funcion recibe el nombre del archivo a tokenizar y 
// llama al lexer para encontrar cada token.
// Al encontrar un token este se agrega a la lista de tokens
// o de ser un error, a la lista de errores


bool tokenizeFile(char* nombreArchivo, vector<token>& tokens, vector<errToken>& errores){
	if ((yyin = fopen(nombreArchivo,"r")) != NULL){ //Se modifica el sitio de lectura
		int tipo;									//si el archivo es invalido, esto
		bool comment = false;						//retornara null, por lo que probamos
		int nroFila = 0;							// por esto
		int nroCol = 0;
		while ((tipo = yylex()) != 0) {		// Mientras no se halla terminado el archivo
			if (comment == true){
				// Se verifica si se esta en un comentario multi linea
				// en tal caso no se deben crear tokens pero todavia
				// se deben manejar los numeros de linea y los numeros
				// de columna, por lo que todavia debemos leer
				// hasta llegar al simbolo de cerrar commentario
				switch(tipo){		
					case NEWLINE:	
						nroFila++;	
						nroCol = 0;	
						break;
					case COMMENTCLOSE:
						comment = false;
						nroCol += yyleng;
						break;
					case TAB:
						nroCol += 4;
						break;
					default:
						nroCol += yyleng;
						break;
				}
			}
			else{
				// Si no se esta en comentario, se deben crear tokens para
				// cada match encontrado y se debe manejar igual el numero
				// de columna y fila.
				// En caso de encontrar un token, se agrega el mismo a la
				// lista de tokens con su numero de fila y columna.
				switch(tipo){
					case IDENT:
						tokens.push_back(token(tipo,string(yytext),
												nroFila+1,nroCol+1));
						nroCol += yyleng;
						break;
					case CHARACTER:
						tokens.push_back(token(tipo,string(yytext),
												nroFila+1,nroCol+1));
						nroCol += yyleng;
						break;
					case NUM:
						tokens.push_back(token(tipo,atoi(yytext),
												nroFila+1,nroCol+1));
						nroCol += yyleng;
						break;
					case TAB:
						nroCol += TABVALOR; // Se le da a cada TAB un valor de 4 por default
						break;
					case NEWLINE:
						nroFila++;
						nroCol = 0;
						break;
					case ESPACIO:
						nroCol += 1;
						break;
					case ERR:
						errores.push_back(errToken(string(yytext),nroFila+1,nroCol+1));
						nroCol += yyleng;
						break;
					case COMMENTOPEN:
						nroCol += yyleng;
						comment = true;
						break;
					case COMMENTLN:
						nroFila += 1;
						nroCol = 0;
						break;
					default:
						tokens.push_back(token(tipo,nroFila+1,nroCol+1));
						nroCol += yyleng;
						break;
				}
			}
		}
		fclose(yyin);
		return true;
	}
	else{
		return false;
	}
}


// Esta funcion imprime los tokens o errores,
// en caso de que la lista de errores tenga elementos
// en ella.

void printTokens(vector<token>& tokens, vector<errToken>& errores){
	if (errores.size() != 0){
		for (int i = 0; i < (int)errores.size(); i++){
			cout << errores[i].toString() << endl;
		}
	}
	else{
		if (tokens.size() != 0){
			cout << tokens[0].toString();
			for (int i = 1; i < (int)tokens.size(); i++){
				cout << ", " <<tokens[i].toString();
			}
			cout << endl;
		}
	}

}
