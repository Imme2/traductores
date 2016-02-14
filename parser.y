%{
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
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
	int value;
	string name;
	char carac;
}

%output  "parser.c"
%defines "parser.h"

%locations

%token <value> NUM
%token <string> ID
%token <carac> CARACTER




%left	TOKEN_MENORIG TOKEN_MAYORIG
%left	TOKEN_MENOR TOKEN_MAYOR
%left	TOKEN_IGUAL TOKEN_DESIGUAL
%left	TOKEN_SUMA TOKEN_RESTA
%left	TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left	TOKEN_DISY
%left	TOKEN_CONJ
%right	TOKEN_NEG	


%%

PROGRAMA: CREATE EXECUTE {root = arbolSintactico($1,$2);}
	;

CREATE: TOKEN_CREATE SECUENCIA_DECLAR { $$ = $2;}
	;

SECUENCIA_DECLAR: SECUENCIA_DECLAR DECLARATION {$$ = secuenciaDeclaraciones($1,$2);}
	| DECLARATION  {$$ = secuenciaDeclaraciones($1);}
	;

DECLARATION: TYPE TOKEN_BOT LISTA_IDS SECUENCIA_COMPORT DEFAULTCOMP TOKEN_END
	| TYPE TOKEN_BOT LISTA_IDS TOKEN_END
	;

TYPE: TOKEN_BOOL
	| TOKEN_CHAR
	| TOKEN_INT
	;

SECUENCIA_COMPORT: SECUENCIA_COMPORT COMPORTAMIENTO
	| COMPORTAMIENTO
	| /* Lambda */
	;

COMPORTAMIENTO: TOKEN_ON CONDITION TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END
	;

DEFAULTCOMP: TOKEN_ON TOKEN_DEFAULT TOKEN_DOSPUNT SECUENCIA_ROBOTINSTR TOKEN_END
	| /* Lambda */
	;

CONDITION: TOKEN_ACTIVATION
	| TOKEN_DEACTIVATION
	| BOOLEXPRESSION
	;

SECUENCIA_ROBOTINSTR: SECUENCIA_ROBOTINSTR ROBOTINSTR
	| ROBOTINSTR 
	;

ROBOTINSTR: STORE TOKEN_PUNTO
	| COLLECT TOKEN_PUNTO
	| DROP TOKEN_PUNTO
	| MOVE TOKEN_PUNTO
	| READ TOKEN_PUNTO
	| SEND TOKEN_PUNTO
	;

STORE: TOKEN_STORE EXPRESSION
	;

COLLECT: TOKEN_COLLECT 
	| TOKEN_COLLECT TOKEN_AS ID
	;

DROP: TOKEN_DROP EXPRESSION
	;

MOVE: DIRECTION ALGEXPRESSION
	;

READ: TOKEN_READ
	| TOKEN_READ TOKEN_AS ID
	;

SEND: TOKEN_SEND
	;

DIRECTION: TOKEN_UP
	| TOKEN_DOWN
	| TOKEN_LEFT
	| TOKEN_RIGHT
	;

EXECUTE: TOKEN_EXECUTE SECUENCIA_INSTRUC { $$ = $2;}
	;

SECUENCIA_INSTRUC: INSTRUCCION {$$ = secuenciaInstrucciones($1);}
	| SECUENCIA_INSTRUC TOKEN_COMA INSTRUCCION {$$ = secuenciaInstrucciones($1,$3);}
	;

INSTRUCCION: ADVANCE {$$ = $1;}
	| ACTIVATE { $$ = $1;}
	| DEACTIVATE { $$ = $1;}
	| CONDICIONAL { $$ = $1;}
	| LOOP { $$ = $1;}
	| INCORPALCANCE { $$ = $1;}
	;

CONDICIONAL: TOKEN_IF BOOLEXPRESSION TOKEN_DOSPUNT  SECUENCIA_INSTRUC ELSE TOKEN_END { $$ = conditionalInstruction($2,$4,$5)}
	;

ELSE: TOKEN_ELSE TOKEN_DOSPUNT SECUENCIA_INSTRUC {$$ = $3 }
	| /* Lambda */	{$$ = NULL;}
	;

ACTIVATE: TOKEN_ACTIVATE LISTA_IDS TOKEN_PUNTO { $$ = activateInstr($2);}
	;

ADVANCE: TOKEN_ADVANCE LISTA_IDS TOKEN_PUNTO {$$ = advanceInst($2);}
	;

DEACTIVATE: TOKEN_DEACTIVATE LISTA_IDS TOKEN_PUNTO {$$ = deactivateInstr($2);}
	;

LOOP: TOKEN_WHILE BOOLEXPRESSION TOKEN_DOSPUNT SECUENCIA_INSTRUC TOKEN_END {}
	;

INCORPALCANCE: CREATE EXECUTE { $$ = arbolSintactico($1,$2);}
	;

LISTA_IDS: ID {$$ = listaIDs($1->name)}
	| LISTA_IDS TOKEN_COMA ID {$$ = listaIDs($1,$3->name)}
	;

EXPRESSION: ALGEXPRESSION
	| BOOLEXPRESSION
	| CARACTER
	;

BOOLEXPRESSION: TOKEN_PARABRE BOOLEXPRESSION TOKEN_PARCIERRA
	| TOKEN_NEG BOOLEXPRESSION
	| BOOLEXPRESSION TOKEN_CONJ BOOLVALUE
	| BOOLEXPRESSION TOKEN_DISY BOOLVALUE
	| BOOLEXPRESSION TOKEN_IGUAL BOOLVALUE
	| BOOLEXPRESSION TOKEN_DESIGUAL BOOLVALUE
	| ALGEXPRESSION TOKEN_MENOR ALGEXPRESSION
	| ALGEXPRESSION TOKEN_MAYOR ALGEXPRESSION
	| ALGEXPRESSION TOKEN_MENORIG ALGEXPRESSION
	| ALGEXPRESSION TOKEN_MAYORIG ALGEXPRESSION
	| ALGEXPRESSION TOKEN_IGUAL ALGEXPRESSION
	| ALGEXPRESSION TOKEN_DESIGUAL ALGEXPRESSION
	| BOOLVALUE
	;

ALGEXPRESSION: ALGEXPRESSION BINARYOPERATION NUMVALUE
	| UNARYOPERATION ALGEXPRESSION
	| TOKEN_PARABRE ALGEXPRESSION TOKEN_PARCIERRA
	| NUMVALUE
	;

BINARYOPERATION: TOKEN_MULT
	| TOKEN_SUMA
	| TOKEN_RESTA
	| TOKEN_DIV
	| TOKEN_MOD
	;

UNARYOPERATION: TOKEN_RESTA
	;

BOOLVALUE: TOKEN_TRUE {$$ = TRUE}
	| TOKEN_FALSE {$$ = FALSE;}
	| ID {$$ = $1->name;}
	;


NUMVALUE: NUM {$$ = $1->value;}
	| ID {$$ = $1->name;}
	;


%%

int yyerror(char* s){
	extern char *yytext;
	string s1 = string(s);


	cout << "ERROR: " << s << " at symbol \"" << yytext;
	cout << "\" on line " << yylloc.first_line;
	cout << " on column " << yylloc.first_column << endl;
	exit(0);
}
