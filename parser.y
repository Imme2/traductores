%error-verbose
%{



#include <cstdio>
#include <iostream>
#include "trees.c"

using namespace std;



extern int yylex(void);

ArbolSintactico *raiz;

void yyerror(char const*);

%}

%union{
	int value;
	char name[200];
	Expresion *exp;
	Instruccion *inst;
	Declaracion *decl;
	ListaIDs *idl;
	InstruccionRobot *instRobot;
	Comportamiento * comp;
	SecuenciaComportamiento * secComp;
}


%locations
%start PROGRAMA

%type <idl> LISTA_IDS
%type <inst> EXECUTE SECUENCIA_INSTRUC CONDICIONAL INSTRUCCION INCORPALCANCE DEACTIVATE ACTIVATE ADVANCE ELSE LOOP
%type <decl> CREATE SECUENCIA_DECLAR DECLARATION 
%type <exp>  EXPRESSION
%type <value> TIPO CODITION DIRECTION
%type <instRobot> SECUENCIA_ROBOTINSTR ROBOTINSTR STORE COLLECT DROP MOVE READ SEND
%type <comp> COMPORTAMIENTO
%type <secComp> SECUENCIA_COMPORT


%token <value> NUM
%token <name> ID
%token <name> CARACTER

%token TOKEN_TRUE TOKEN_FALSE TOKEN_PUNTO TOKEN_DOSPUNT TOKEN_PARABRE TOKEN_PARCIERRA TOKEN_SUMA TOKEN_RESTA TOKEN_MULT TOKEN_DIV TOKEN_MOD TOKEN_CONJ TOKEN_DISY TOKEN_NEG TOKEN_MENOR TOKEN_MAYOR TOKEN_MENORIG TOKEN_MAYORIG TOKEN_CREATE TOKEN_WHILE TOKEN_BOOL TOKEN_INT TOKEN_CHAR TOKEN_IF TOKEN_ELSE TOKEN_SEND TOKEN_EXECUTE TOKEN_ON TOKEN_STORE TOKEN_BOT TOKEN_DESIGUAL TOKEN_IGUAL TOKEN_COMA TOKEN_DEFAULT TOKEN_COLLECT TOKEN_DROP TOKEN_UP TOKEN_DOWN TOKEN_RIGHT TOKEN_LEFT TOKEN_READ TOKEN_AS TOKEN_RECEIVE TOKEN_ADVANCE TOKEN_ACTIVATE TOKEN_ACTIVATION TOKEN_DEACTIVATE TOKEN_DEACTIVATION TOKEN_END 



%left	TOKEN_MENORIG TOKEN_MAYORIG
%left	TOKEN_MENOR TOKEN_MAYOR
%left	TOKEN_IGUAL TOKEN_DESIGUAL
%left	TOKEN_SUMA TOKEN_RESTA
%left	TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left	TOKEN_DISY
%left	TOKEN_CONJ
%right	TOKEN_NEG	


%%

PROGRAMA: CREATE EXECUTE 	{raiz = new ArbolSintactico($1,$2);}
	;

CREATE: TOKEN_CREATE SECUENCIA_DECLAR	 { $$ = $2;}
	;

SECUENCIA_DECLAR: SECUENCIA_DECLAR DECLARATION 	{$$ = new SecuenciaDeclaraciones($1,$2);}
	| DECLARATION  								{$$ = new SecuenciaDeclaraciones($1);}
	;

DECLARATION: TIPO TOKEN_BOT LISTA_IDS SECUENCIA_COMPORT TOKEN_END 	{$$ = new DeclaracionRobot($1,$3,$4);}
	| TIPO TOKEN_BOT LISTA_IDS TOKEN_END 							{$$ = new DeclaracionRobot($1,$3,NULL);}
	;

TIPO: TOKEN_BOOL	{$$ = 0;}
	| TOKEN_INT		{$$ = 1;}
	| TOKEN_CHAR	{$$ = 2;}
	;

SECUENCIA_COMPORT: SECUENCIA_COMPORT COMPORTAMIENTO {$$ = new SecuenciaComportamiento($1,$2);}
	| COMPORTAMIENTO 								{$$ = new SecuenciaComportamiento($1);}
	;

COMPORTAMIENTO: TOKEN_ON CONDITION TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END 	{$$ = new Comportamiento($2,NULL,$4);}
	| TOKEN_ON EXPRESSION TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END 				{$$ = new Comportamiento(0,$2,$4)}
	;

CONDITION: TOKEN_ACTIVATION {$$ = 1;}
	| TOKEN_DEACTIVATION	{$$ = 2;}
	| TOKEN_DEFAULT 		{$$ = 3;}
	;

SECUENCIA_ROBOTINSTR: SECUENCIA_ROBOTINSTR ROBOTINSTR 	{ $$ = new SecuenciaRoboInstruccion($1,$2;}
	| ROBOTINSTR 										{ $$ = new SecuenciaRoboInstruccion($1);} 
	;

ROBOTINSTR: STORE TOKEN_PUNTO 	{$$ = $1;}
	| COLLECT TOKEN_PUNTO		{$$ = $1;}
	| DROP TOKEN_PUNTO			{$$ = $1;}
	| MOVE TOKEN_PUNTO			{$$ = $1;}
	| READ TOKEN_PUNTO			{$$ = $1;}
	| SEND TOKEN_PUNTO			{$$ = $1;}
	;

STORE: TOKEN_STORE EXPRESSION 	{$$ = new Almacenamiento($2);}
	;

COLLECT: TOKEN_COLLECT 			{$$ = new Coleccion();}
	| TOKEN_COLLECT TOKEN_AS ID {$$ = new Coleccion(string($1));}
	;

DROP: TOKEN_DROP EXPRESSION 	{$$ = new Soltado($2);}
	;

MOVE: DIRECTION EXPRESSION 		{$$ = new Condicional($2,$4,$5);}
	;

READ: TOKEN_READ 				{$$ = new Leer();}
	| TOKEN_READ TOKEN_AS ID 	{$$ = new Leer(string($3));}
	;

SEND: TOKEN_SEND 		{ $$ = new Escribir();}
	;

DIRECTION: TOKEN_UP		{$$ = 0;}
	| TOKEN_DOWN 		{$$ = 1;}
	| TOKEN_LEFT 		{$$ = 2;}
	| TOKEN_RIGHT 		{$$ = 3;}
	;

EXECUTE: TOKEN_EXECUTE SECUENCIA_INSTRUC TOKEN_END 	{$$ = $2;}
	;

SECUENCIA_INSTRUC: INSTRUCCION 			{$$ = new SecuenciaInstrucciones($1);}
	| SECUENCIA_INSTRUC INSTRUCCION 	{$$ = new SecuenciaInstrucciones($1,$2);}
	;

INSTRUCCION: ADVANCE 			{$$ = $1;}
	| ACTIVATE 					{$$ = $1;}
	| DEACTIVATE 				{$$ = $1;}
	| CONDICIONAL 				{$$ = $1;}
	| LOOP 						{$$ = $1;}
	| INCORPALCANCE 			{$$ = $1;}
	;

CONDICIONAL: TOKEN_IF EXPRESSION TOKEN_DOSPUNT SECUENCIA_INSTRUC ELSE TOKEN_END {$$ = new Condicional($2,$4,$5);}
	;

ELSE: TOKEN_ELSE TOKEN_DOSPUNT SECUENCIA_INSTRUC {$$ = $3;}
	| /* Lambda */	{$$ = NULL;}
	;

ACTIVATE: TOKEN_ACTIVATE LISTA_IDS TOKEN_PUNTO 	{ $$ = new ActivateInst($2);}
	;

ADVANCE: TOKEN_ADVANCE LISTA_IDS TOKEN_PUNTO 	{$$ = new AdvanceInst($2);}
	;

DEACTIVATE: TOKEN_DEACTIVATE LISTA_IDS TOKEN_PUNTO 	{$$ = new DeactivateInst($2);}
	;


LOOP: TOKEN_WHILE EXPRESSION TOKEN_DOSPUNT SECUENCIA_INSTRUC TOKEN_END 	{$$ = new LoopInst($2,$4);}
	;

INCORPALCANCE: CREATE EXECUTE 	{$$ = new IncorpAlcance($1,$2);}
	;

LISTA_IDS: ID 					{$$ = new ListaIDs(string($1));}
	| LISTA_IDS TOKEN_COMA ID 	{$$ = new ListaIDs($1,string($3));}
	;

EXPRESSION: TOKEN_PARABRE EXPRESSION TOKEN_PARCIERRA 	{$$ = $2;}
	| TOKEN_NEG EXPRESSION 								{$$ = new Expresion("NEGACION",$2);}
	| TOKEN_RESTA EXPRESSION 							{$$ = new Expresion("RESTA",$2);}
	| EXPRESSION TOKEN_MENOR EXPRESSION 				{$$ = new Expresion("MENOR",$1,$3);}
	| EXPRESSION TOKEN_MAYOR EXPRESSION 				{$$ = new Expresion("MAYOR",$1,$3);}
	| EXPRESSION TOKEN_MENORIG EXPRESSION 				{$$ = new Expresion("MENORIGUAL",$1,$3);}
	| EXPRESSION TOKEN_MAYORIG EXPRESSION 				{$$ = new Expresion("MAYORIGUAL",$1,$3);}
	| EXPRESSION TOKEN_IGUAL EXPRESSION 				{$$ = new Expresion("IGUAL",$1,$3);}
	| EXPRESSION TOKEN_DESIGUAL EXPRESSION 				{$$ = new Expresion("DESIGUAL",$1,$3);}	
	| EXPRESSION TOKEN_CONJ EXPRESSION 					{$$ = new Expresion("CONJUNCION",$1,$3);}
	| EXPRESSION TOKEN_DISY EXPRESSION 					{$$ = new Expresion("DISYUNCION",$1,$3);}
	| EXPRESSION TOKEN_SUMA EXPRESSION 					{$$ = new Expresion("SUMA",$1,$3);}
	| EXPRESSION TOKEN_MULT EXPRESSION 					{$$ = new Expresion("MULTIPLICACION",$1,$3);}
	| EXPRESSION TOKEN_RESTA EXPRESSION 				{$$ = new Expresion("RESTA",$1,$3);}
	| EXPRESSION TOKEN_DIV EXPRESSION 					{$$ = new Expresion("DIVISION",$1,$3);}
	| EXPRESSION TOKEN_MOD EXPRESSION 					{$$ = new Expresion("MODULO",$1,$3);}
	| NUM 												{$$ = new Expresion($1,1);}
	| TOKEN_TRUE 										{$$ = new Expresion(true,0);}
	| TOKEN_FALSE 										{$$ = new Expresion(false,0);}
	| ID 												{$$ = new Expresion(string($1),3);}
	| CARACTER 											{$$ = new Expresion(string($1),2);}
	;



%%


void yyerror(char const* s){
	cout <<"En la fila:" << yylloc.first_line << ", columna" << yylloc.first_column;
	cout <<"ocurrio: " << s << endl;
}