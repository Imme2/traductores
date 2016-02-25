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
	Expression *exp;
	Instruccion *inst;
	Declaracion *decl;
	ListaIDs *idl;
}


%locations
%start PROGRAMA

%type <idl> LISTA_IDS
%type <inst> EXECUTE SECUENCIA_INSTRUC CONDICIONAL INSTRUCCION INCORPALCANCE DEACTIVATE ACTIVATE ADVANCE ELSE LOOP
%type <decl> CREATE SECUENCIA_DECLAR DECLARATION 
%type <exp>   EXPRESSION;

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

PROGRAMA: CREATE EXECUTE {raiz = new ArbolSintactico($1,$2);}
	| error {$$ = NULL;}
	;

CREATE: TOKEN_CREATE SECUENCIA_DECLAR { $$ = $2;}
	| error {$$ = NULL;}
	;

SECUENCIA_DECLAR: SECUENCIA_DECLAR DECLARATION {$$ = NULL;}
	| DECLARATION  {$$ = NULL;}
	| error {$$ = NULL;}
	;

DECLARATION: TIPO TOKEN_BOT LISTA_IDS SECUENCIA_COMPORT TOKEN_END {$$ = NULL;}
	| TIPO TOKEN_BOT LISTA_IDS TOKEN_END {$$ =NULL;}
	| error {$$ = NULL;}
	;

TIPO: TOKEN_BOOL
	| TOKEN_CHAR
	| TOKEN_INT
	| error {$$ = NULL;}
	;

SECUENCIA_COMPORT: SECUENCIA_COMPORT COMPORTAMIENTO
	| COMPORTAMIENTO
	| error {$$ = NULL;}
	;

COMPORTAMIENTO: TOKEN_ON CONDITION TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END 
	| DEFAULTCOMP
	| error {$$ = NULL;}
	;

DEFAULTCOMP: TOKEN_ON TOKEN_DEFAULT TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END
	;

CONDITION: TOKEN_ACTIVATION 
	| TOKEN_DEACTIVATION
	| EXPRESSION
	| error {$$ = NULL;}
	;

SECUENCIA_ROBOTINSTR: SECUENCIA_ROBOTINSTR ROBOTINSTR { $$ =   -----falta----             new ($1,$2);}
	| ROBOTINSTR 
	| error {$$ = NULL;}
	;

ROBOTINSTR: STORE TOKEN_PUNTO { $$ = new InstruccionRobot($1);}
	| COLLECT TOKEN_PUNTO
	| DROP TOKEN_PUNTO
	| MOVE TOKEN_PUNTO
	| READ TOKEN_PUNTO
	| SEND TOKEN_PUNTO
	| error {$$ = NULL;}
	;

STORE: TOKEN_STORE EXPRESSION { $$ = new Almacenamiento($2);}
	| error {$$ = NULL;}
	;

COLLECT: TOKEN_COLLECT { $$ = new Coleccion();}
	| TOKEN_COLLECT TOKEN_AS ID {$$ = new Expression(string($1),1);} -------------duda-----------
	| error {$$ = NULL;}
	;

DROP: TOKEN_DROP EXPRESSION { $$ = new Soltado($2);}
	| error {$$ = NULL;}
	;

MOVE: DIRECTION EXPRESSION { $$ = new Condicional($2,$4,$5);}
	| error {$$ = NULL;}
	;

READ: TOKEN_READ
	| TOKEN_READ TOKEN_AS ID
	| error {$$ = NULL;}
	;

SEND: TOKEN_SEND
	| error {$$ = NULL;}
	;

DIRECTION: TOKEN_UP
	| TOKEN_DOWN
	| TOKEN_LEFT
	| TOKEN_RIGHT
	| error {$$ = NULL;}
	;

EXECUTE: TOKEN_EXECUTE SECUENCIA_INSTRUC TOKEN_END{ $$ = $2;}
	| error {$$ = NULL;}
	;

SECUENCIA_INSTRUC: INSTRUCCION {$$ = new SecuenciaInstrucciones($1);}
	| SECUENCIA_INSTRUC INSTRUCCION {$$ = new SecuenciaInstrucciones($1,$2);}
	| error {$$ = NULL;}
	;

INSTRUCCION: ADVANCE {$$ = $1;}
	| ACTIVATE { $$ = $1;}
	| DEACTIVATE { $$ = $1;}
	| CONDICIONAL { $$ = $1;}
	| LOOP { $$ = $1;}
	| INCORPALCANCE { $$ = $1;}
	| error {$$ = NULL;}
	;

CONDICIONAL: TOKEN_IF EXPRESSION TOKEN_DOSPUNT  SECUENCIA_INSTRUC ELSE TOKEN_END { $$ = new Condicional($2,$4,$5);}
	| error {$$ = NULL;}
	;

ELSE: TOKEN_ELSE TOKEN_DOSPUNT SECUENCIA_INSTRUC {$$ = $3;}
	| /* Lambda */	{$$ = NULL;}
	| error {$$ = NULL;}
	;

ACTIVATE: TOKEN_ACTIVATE LISTA_IDS TOKEN_PUNTO { $$ = new ActivateInst($2);}
	| error {$$ = NULL;}
	;

ADVANCE: TOKEN_ADVANCE LISTA_IDS TOKEN_PUNTO {$$ = new AdvanceInst($2);}
	| error {$$ = NULL;}
	;

DEACTIVATE: TOKEN_DEACTIVATE LISTA_IDS TOKEN_PUNTO {$$ = new DeactivateInst($2);}
	| error {$$ = NULL;}
	;


LOOP: TOKEN_WHILE EXPRESSION TOKEN_DOSPUNT SECUENCIA_INSTRUC TOKEN_END { $$ = new LoopInst($2,$4);}
	| error {$$ = NULL;}
	;

INCORPALCANCE: CREATE EXECUTE { $$ = new IncorpAlcance($1,$2);}
	| error {$$ = NULL;}
	;

LISTA_IDS: ID {$$ = new ListaIDs(string($1));}
	| LISTA_IDS TOKEN_COMA ID {$$ = new ListaIDs($1,string($3));}
	| error {$$ = NULL;}
	;

EXPRESSION: TOKEN_PARABRE EXPRESSION TOKEN_PARCIERRA {$$ = $2;}
	| TOKEN_NEG EXPRESSION { $$ = new Expression("NEGACION",$2);}
	| TOKEN_RESTA EXPRESSION {$$ = new Expression("RESTA",$2);}
	| EXPRESSION TOKEN_MENOR EXPRESSION {$$ = new Expression("MENOR",$1,$3);}
	| EXPRESSION TOKEN_MAYOR EXPRESSION {$$ = new Expression("MAYOR",$1,$3);}
	| EXPRESSION TOKEN_MENORIG EXPRESSION {$$ = new Expression("MENORIGUAL",$1,$3);}
	| EXPRESSION TOKEN_MAYORIG EXPRESSION {$$ = new Expression("MAYORIGUAL",$1,$3);}
	| EXPRESSION TOKEN_IGUAL EXPRESSION {$$ = new Expression("IGUAL",$1,$3);}
	| EXPRESSION TOKEN_DESIGUAL EXPRESSION {$$ = new Expression("DESIGUAL",$1,$3);}	
	| EXPRESSION TOKEN_CONJ EXPRESSION {$$ = new Expression("CONJUNCION",$1,$3);}
	| EXPRESSION TOKEN_DISY EXPRESSION {$$ = new Expression("DISYUNCION",$1,$3);}
	| EXPRESSION TOKEN_SUMA EXPRESSION {$$ = new Expression("SUMA",$1,$3);}
	| EXPRESSION TOKEN_MULT EXPRESSION {$$ = new Expression("MULTIPLICACION",$1,$3);}
	| EXPRESSION TOKEN_RESTA EXPRESSION {$$ = new Expression("RESTA",$1,$3);}
	| EXPRESSION TOKEN_DIV EXPRESSION {$$ = new Expression("DIVISION",$1,$3);}
	| EXPRESSION TOKEN_MOD EXPRESSION {$$ = new Expression("MODULO",$1,$3);}
	| NUM {$$ = new Expression($1,0);}
	| TOKEN_TRUE {$$ = new Expression(true,3);}
	| TOKEN_FALSE {$$ = new Expression(false,3);}
	| ID {$$ = new Expression(string($1),1);}
	| CARACTER {$$ = new Expression(string($1),2);}
	| error {$$ = NULL;}
	;



%%


void yyerror(char const* s){
	cout <<"En la fila:" << yylloc.first_line << ", columna" << yylloc.first_column;
	cout <<"ocurrio: " << s << endl;
}