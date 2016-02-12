%{
#include <cstdio>
#include <iostream>
#include <vector>
#include "errtoken.c"
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;
 
void yyerror(const char *s);

arbolSintactico *raiz;
vector<errToken> errores;

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
%right	TOKEN_NEG	






%%

PROGRAMA: CREATE EXECUTE {root = arbolSintactico($1,$2)}
		| CREATE
		| EXECUTE
		| ERROR
		;

CREATE: DECLARATION
	;

EXECUTE: SECUENCIA_INSTRUC { $$ = $1 }

SECUENCIA_INSTRUC: INSTRUCCION {$$ = secuenciaInstrucciones($1);}
	| SECUENCIA_INSTRUC INSTRUCCIONES {$$ = secuenciaInstrucciones($1,$2);}
	;

INSTRUCCION: LOOP
	| ASIGNACION
	| CONDICIONAL
	| ADVANCE
	| ACTIVATE
	| DEACTIVATE
	;

ACTIVATE: TOKEN_ACTIVATE LISTA_IDS
	;

ADVANCE: TOKEN_ADVANCE LISTA_IDS
	;

DEACTIVATE: TOKEN_DEACTIVATE LISTA_IDS
	;

LISTA_IDS: ID
	| LISTA_IDS ID
	;




LOOP:


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