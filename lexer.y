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
}

%token CREATE
%token EXE
%token <num> NUM
%token <str> ID


%left	MENORIG MAYORIG
%left	SUMA RESTA
%left	MULT DIV MOD
%right	NEG	



%%

PROGRAMA: CREATE EXECUTE {root = arbolSintactico($1,$2)}
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
	return yyerror(string(s));
}