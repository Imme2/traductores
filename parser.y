%{
#include <cstdio>
#include <iostream>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;
 
void yyerror(const char *s);

arbolSintactico *root;

%}

%union{
	int num;
	string str;
	char carac;
}

%output  "parser.c"
%defines "parser.h"

%token <num> NUM
%token <str> ID
%token <carac> CARACTER




%left	TOKEN_MENORIG TOKEN_MAYORIG
%left	TOKEN_MENOR TOKEN_MAYOR
%left	TOKEN_IGUAL TOKEN_DESIGUAL
%left	TOKEN_SUMA TOKEN_RESTA
%left	TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left	TOKEN_DISY TOKEN_CONJ
%left	TOKEN_PARCIERRA //REVISAR
%right	TOKEN_PARABRE   //REVISAR
%right	TOKEN_NEG	






%%

PROGRAMA: CREATE EXECUTE {root = arbolSintactico($1,$2)}
		| CREATE
		| EXECUTE
		;

CREATE: DECLARATION
	;

EXECUTE: INSTRUCCION { $$ = $1 }
	| INSTRUCCION INSTRUCCION {$$ = Secuenciacion($1,$2)}
	;

INSTRUCCIONES: INSTRUCCION
	| INSTRUCCION INSTRUCCIONES {$$ = Secuenciacion($1,$2) }
	;

INSTRUCCION: 

DECLARATION: TIPO BOT IDENTIFICADOR

INSTRUCCION: 

IDENT: IDENT IDENT
	:

%%

int yyerror(string s){
	extern int yylineno;	// defined and maintained in lex.c
	extern char *yytext;	// defined and maintained in lex.c

	cerr << "ERROR: " << s << " at symbol \"" << yytext;
	cerr << "\" on line " << yylineno << endl;
	exit(1);
}

int yyerror(char *s){
	printf("Error: %s",s);
	return 0;
}