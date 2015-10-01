%{
#include "scanner.h"    
%}

comment \$-([^-]|-+[^\$])*-\$
commentln \$\$[.^\n]*\n
caracter '([^\n\t]|\\n|\\t|'|\')'
TkIdent [A-Za-z]([A-Za-z]|[0-9]|_)*
Num   [0-9]+

commentOpen \$-
commentClose -\$

salto [ \n]
tab [ \t]
espacio [ \r]
cualquiera .

%%



"create"        return CREATE;
"activate"      return ACTIVATE;
"activation"    return ACTIVATION;
"deactivate"    return DEACTIVATE;
"deactivation"  return DEACTIVATION;
"advance"       return ADVANCE;
"execute"       return EXECUTE;
"default"       return DEFAULT;
"collect"       return COLLECT;
"receive"       return RECEIVE;
"drop"          return DROP;
"on"            return ON;
"send"          return SEND;
"store"         return STORE;
"bot"           return BOT;
"me"            return ME;
"up"            return UP;
"down"          return DOWN;
"right"         return RIGHT;
"left"          return LEFT;
"read"          return READ;
"as"            return AS;
"end"           return END;


"bool"          return BOOL;
"int"           return INT;
"char"          return CHAR;

"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;

"true"          return TRU;
"false"         return FAL;

{TkIdent}       return IDENT;
{Num}           return NUM;
{caracter}      return CHARACTER;

"("             return PARABRE;
")"             return PARCIERR;
"."             return PUNTO;
","             return COMA;
":"             return DOSPUNT;
"<"             return MENOR;
">"             return MAYOR;
"<="            return MENORIG;
">="            return MAYORIG;
"="             return IGUAL;
"/="            return DESIGUAL;
"~"             return NEG;
"\\/"           return DISY;
"/\\"           return CONJ;
"+"             return SUMA;
"-"             return RESTA;
"*"             return MULT;
"/"             return DIV;
"%"             return MOD;

{commentOpen}   return COMMENTOPEN;
{commentClose}  return COMMENTCLOSE;
{commentln}     return COMMENTLN;

{espacio}       return ESPACIO;
{salto}         return NEWLINE;
{tab}           return TAB;
{cualquiera}    return ERR;


%%

int yywrap(){
	return 1;
}
 