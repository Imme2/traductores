#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "scanner.h"
#include "token.c"
#include "errtoken.c"

using namespace std;

extern int yylex;
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int yyleng;

vector<token> tokens;
vector<errtoken> errores;

int main(int argc,char* argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}
	else{
		bool listo;
		listo = tokenizeFile(argv[1]);
		if (listo){
			printTokens();
		}
		else{
			printf("El archivo %s no parece existir o no se puede leer\n",argv[1]);
		}
	}
	return 0;
}

bool tokenizeFile(char* nombreArchivo){
	if ((yyin = fopen(archivo,"r")) != NULL){
		int tipo;
		bool comment = false;
		int nroFila = 0;
		int nroCol = 0;
		while ((tipo = yylex()) != 0) {
			if (comment = true){
				switch(tipo){
					case NEWLINE:
						nroFila++;
						nroCol = 0;
					case COMMENTCLOSE:
						comment = false;
						nroCol += yyleng();
					default:
						nroCol += yyleng();
				}
			}
			else{
				switch(tipo){
					case IDENT:
						tokens.push_back(token(tipo,str(yytext()),
												nroFila+1,nroCol+1));
						nroCol += yyleng();
					case CHARACTER:
						tokens.push_back(token(tipo,str(yytext()),
												nroFila+1,nroCol+1));
						nroCol += yyleng();
					case NUM:
						tokens.push_back(token(tipo,atoi(yytext()),
												nroFila+1,nroCol+1))``;
						nroCol += yyleng();
					case TAB:
						nroCol += 4;
					case NEWLINE:
						nroFila += 1;
						nroCol = 0;
					case ESPACIO:
						nroCol += 1;
					case ERR:
						errores.push_back(errtoken(yychar(),nroFila+1,nroCol+1));
						nroCol += yyleng();
					case COMMENTOPEN:
						nroCol += yyleng();
						comment = true;
					case COMMENTLN:
						nroFila += 1;
					default:
						tokens.push_back(token(tipo,nroFila+1,nroCol+1));
						nroCol += yyleng();
				}
			}
		}
	}
	else{
		return false;
	}
}


void printTokens(){
	if (errores.size() != 0){
		for (int i = 0; i < errores.size(); i++){
			cout << errores[i].toString() << endl;
		}
	}
	else{
		cout << tokens[0].toString();
		for (int i = 0; i < tokens.size(); i++){
			cout << ", " <<tokens[i].toString();
		}
	}

}

