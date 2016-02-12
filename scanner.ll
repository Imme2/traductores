%{
#include "scanner.h"
#include "parser.h"
#include "errtoken.c"
#include <vector>

vector<errToken> errores;
int commentLine = 0;
int insideComment = 0;

int colNo = 0;

%define YY_USER_ACTION yyloc.first_line = yyloc.last_line = yylineno; \
	yyloc.first_column = colNum; yyloc.last_column = colNo + yyleng - 1; \
	colNo += yyleng;


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



"create"        {if (insideComment == 0) return TOKEN_CREATE;}
"activate"      {if (insideComment == 0) return TOKEN_ACTIVATE;}
"activation"    {if (insideComment == 0) return TOKEN_ACTIVATION;}
"deactivate"    {if (insideComment == 0) return TOKEN_DEACTIVATE;}
"deactivation"  {if (insideComment == 0) return TOKEN_DEACTIVATION;}
"advance"       {if (insideComment == 0) return TOKEN_ADVANCE;}
"execute"       {if (insideComment == 0) return TOKEN_EXECUTE;}
"default"       {if (insideComment == 0) return TOKEN_DEFAULT;}
"collect"       {if (insideComment == 0) return TOKEN_COLLECT;}
"receive"       {if (insideComment == 0) return TOKEN_RECEIVE;}
"drop"          {if (insideComment == 0) return TOKEN_DROP;}
"on"            {if (insideComment == 0) return TOKEN_ON;}
"send"          {if (insideComment == 0) return TOKEN_SEND;}
"store"         {if (insideComment == 0) return TOKEN_STORE;}
"bot"           {if (insideComment == 0) return TOKEN_BOT;}
"me"            {if (insideComment == 0) return TOKEN_ME;}
"up"            {if (insideComment == 0) return TOKEN_UP;}
"down"          {if (insideComment == 0) return TOKEN_DOWN;}
"right"         {if (insideComment == 0) return TOKEN_RIGHT;}
"left"          {if (insideComment == 0) return TOKEN_LEFT;}
"read"          {if (insideComment == 0) return TOKEN_READ;}
"as"            {if (insideComment == 0) return TOKEN_AS;}
"end"           {if (insideComment == 0) return TOKEN_END;}

"bool"          {if (insideComment == 0) return TOKEN_BOOL;}
"int"           {if (insideComment == 0) return TOKEN_INT;}
"char"          {if (insideComment == 0) return TOKEN_CHAR;}

"while"         {if (insideComment == 0) return TOKEN_WHILE;}
"if"            {if (insideComment == 0) return TOKEN_IF;}
"else"          {if (insideComment == 0) return TOKEN_ELSE;}

"true"          {if (insideComment == 0) return TOKEN_TRU;}
"false"         {if (insideComment == 0) return TOKEN_FAL;}

{TkIdent}       {yylval.str = string(yytext); if (insideComment == 0) return TOKEN_IDENT;}
{Num}           {yylval.num = atoi(yytext); if (insideComment == 0) return TOKEN_NUM;}
{caracter}      {yylval.carac = yytext[1]; if (insideComment == 0) return TOKEN_CHARACTER;}

"("             {if (insideComment == 0 && commentLine == 0) return TOKEN_PARABRE;}
")"             {if (insideComment == 0) return TOKEN_PARCIERR;}
"."             {if (insideComment == 0) return TOKEN_PUNTO;}
","             {if (insideComment == 0) return TOKEN_COMA;}
":"             {if (insideComment == 0) return TOKEN_DOSPUNT;}
"<"             {if (insideComment == 0) return TOKEN_MENOR;}
">"             {if (insideComment == 0) return TOKEN_MAYOR;}
"<="            {if (insideComment == 0) return TOKEN_MENORIG;}
">="            {if (insideComment == 0) return TOKEN_MAYORIG;}
"="             {if (insideComment == 0) return TOKEN_IGUAL;}
"/="            {if (insideComment == 0) return TOKEN_DESIGUAL;}
"~"             {if (insideComment == 0) return TOKEN_NEG;}
"\\/"           {if (insideComment == 0) return TOKEN_DISY;}
"/\\"           {if (insideComment == 0) return TOKEN_CONJ;}
"+"             {if (insideComment == 0) return TOKEN_SUMA;}
"-"             {if (insideComment == 0) return TOKEN_RESTA;}
"*"             {if (insideComment == 0) return TOKEN_MULT;}
"/"             {if (insideComment == 0) return TOKEN_DIV;}
"%"             {if (insideComment == 0) return TOKEN_MOD;}

{commentOpen}   {if (commentLine == 0) insideComment = 1;}
{commentClose}  {if (commentLine == 0) insideComment = 0;}
{commentln}     {if (insideComment == 0) commentLine = 1;}

{espacio}       {colNo;} hacer contar columna aqui
{salto}         {lineno++; commentLine = 0;{if (insideComment == 0) return TOKEN_NEWLINE;}
{tab}           {;} hacer contar columna aqui
{cualquiera}    {;} error aqui


%%

int yywrap(){
	return 1;
}
 