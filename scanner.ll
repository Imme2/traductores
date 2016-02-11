%{
#include "scanner.h"
#include "parser.h"
%}


%option bison-bridge

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



"create"        return TOKEN_CREATE;
"activate"      return TOKEN_ACTIVATE;
"activation"    return TOKEN_ACTIVATION;
"deactivate"    return TOKEN_DEACTIVATE;
"deactivation"  return TOKEN_DEACTIVATION;
"advance"       return TOKEN_ADVANCE;
"execute"       return TOKEN_EXECUTE;
"default"       return TOKEN_DEFAULT;
"collect"       return TOKEN_COLLECT;
"receive"       return TOKEN_RECEIVE;
"drop"          return TOKEN_DROP;
"on"            return TOKEN_ON;
"send"          return TOKEN_SEND;
"store"         return TOKEN_STORE;
"bot"           return TOKEN_BOT;
"me"            return TOKEN_ME;
"up"            return TOKEN_UP;
"down"          return TOKEN_DOWN;
"right"         return TOKEN_RIGHT;
"left"          return TOKEN_LEFT;
"read"          return TOKEN_READ;
"as"            return TOKEN_AS;
"end"           return TOKEN_END;


"bool"          return TOKEN_BOOL;
"int"           return TOKEN_INT;
"char"          return TOKEN_CHAR;

"while"         return TOKEN_WHILE;
"if"            return TOKEN_IF;
"else"          return TOKEN_ELSE;

"true"          return TOKEN_TRU;
"false"         return TOKEN_FAL;

{TkIdent}       {yylval.str = string(yytext); return TOKEN_IDENT;}
{Num}           {yylval.num = atoi(yytext); return TOKEN_NUM;}
{caracter}      {yylval.carac = yytext[1]; return TOKEN_CHARACTER;}

"("             return TOKEN_PARABRE;
")"             return TOKEN_PARCIERR;
"."             return TOKEN_PUNTO;
","             return TOKEN_COMA;
":"             return TOKEN_DOSPUNT;
"<"             return TOKEN_MENOR;
">"             return TOKEN_MAYOR;
"<="            return TOKEN_MENORIG;
">="            return TOKEN_MAYORIG;
"="             return TOKEN_IGUAL;
"/="            return TOKEN_DESIGUAL;
"~"             return TOKEN_NEG;
"\\/"           return TOKEN_DISY;
"/\\"           return TOKEN_CONJ;
"+"             return TOKEN_SUMA;
"-"             return TOKEN_RESTA;
"*"             return TOKEN_MULT;
"/"             return TOKEN_DIV;
"%"             return TOKEN_MOD;

{commentOpen}   return TOKEN_COMMENTOPEN;
{commentClose}  return TOKEN_COMMENTCLOSE;
{commentln}     return TOKEN_COMMENTLN;

{espacio}       return TOKEN_ESPACIO;
{salto}         return TOKEN_NEWLINE;
{tab}           return TOKEN_TAB;
{cualquiera}    return TOKEN_ERR;


%%

int yywrap(){
	return TOKEN_1;
}
 