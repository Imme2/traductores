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

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int yyleng;

vector<token> tokens;
vector<errToken> errores;

bool tokenizeFile(char* nombreArchivo){
	if ((yyin = fopen(nombreArchivo,"r")) != NULL){
		int tipo;
		bool comment = false;
		int nroFila = 0;
		int nroCol = 0;
		while ((tipo = yylex()) != 0) {
			if (comment == true){
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
						nroCol += 4;
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


void printTokens(){
	if (errores.size() != 0){
		for (int i = 0; i < errores.size(); i++){
			cout << errores[i].toString() << endl;
		}
	}
	else{
		cout << tokens[0].toString();
		for (int i = 1; i < tokens.size(); i++){
			cout << ", " <<tokens[i].toString();
		}
		cout << endl;
	}

}




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

