#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(int argc,char* argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
	}
	vector<int> tokens;
	vector<int> errores;
	ifstream archivo;
	archivo.open(argv[1]);
	int token = yylex();
	if (archivo.good()){
		int c = 0;
		while (token){
			if (yylex() == 1){
				printf("yay\n");
				break;
			}
		}
	}
	else{
		printf("El archivo %s no parece existir\n",argv[1]);
	}
}