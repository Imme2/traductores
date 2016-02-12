%{
#include "scanner.h"
#include "parser.h"
#include "errtoken.c"
#include <vector>

vector<errToken> errores;
int commentLine = 0;
int insideComment = 0;

int colNo

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



"create"        {if (insideComment == 0) return TOKEN__CREATE;}
"activate"      {if (insideComment == 0) return TOKEN__ACTIVATE;}
"activation"    {if (insideComment == 0) return TOKEN__ACTIVATION;}
"deactivate"    {if (insideComment == 0) return TOKEN__DEACTIVATE;}
"deactivation"  {if (insideComment == 0) return TOKEN__DEACTIVATION;}
"advance"       {if (insideComment == 0) return TOKEN__ADVANCE;}
"execute"       {if (insideComment == 0) return TOKEN__EXECUTE;}
"default"       {if (insideComment == 0) return TOKEN__DEFAULT;}
"collect"       {if (insideComment == 0) return TOKEN__COLLECT;}
"receive"       {if (insideComment == 0) return TOKEN__RECEIVE;}
"drop"          {if (insideComment == 0) return TOKEN__DROP;}
"on"            {if (insideComment == 0) return TOKEN__ON;}
"send"          {if (insideComment == 0) return TOKEN__SEND;}
"store"         {if (insideComment == 0) return TOKEN__STORE;}
"bot"           {if (insideComment == 0) return TOKEN__BOT;}
"me"            {if (insideComment == 0) return TOKEN__ME;}
"up"            {if (insideComment == 0) return TOKEN__UP;}
"down"          {if (insideComment == 0) return TOKEN__DOWN;}
"right"         {if (insideComment == 0) return TOKEN__RIGHT;}
"left"          {if (insideComment == 0) return TOKEN__LEFT;}
"read"          {if (insideComment == 0) return TOKEN__READ;}
"as"            {if (insideComment == 0) return TOKEN__AS;}
"end"           {if (insideComment == 0) return TOKEN__END;}


"bool"          {if (insideComment == 0) return TOKEN__BOOL;}
"int"           {if (insideComment == 0) return TOKEN__INT;}
"char"          {if (insideComment == 0) return TOKEN__CHAR;}

"while"         {if (insideComment == 0) return TOKEN__WHILE;}
"if"            {if (insideComment == 0) return TOKEN__IF;}
"else"          {if (insideComment == 0) return TOKEN__ELSE;}

"true"          {if (insideComment == 0) return TOKEN__TRU;}
"false"         {if (insideComment == 0) return TOKEN__FAL;}

{TkIdent}       {yylval.str = string(yytext); if (insideComment == 0) return TOKEN__IDENT;}
{Num}           {yylval.num = atoi(yytext); if (insideComment == 0) return TOKEN__NUM;}
{caracter}      {yylval.carac = yytext[1]; if (insideComment == 0) return TOKEN__CHARACTER;}

"("             {if (insideComment == 0) return TOKEN__PARABRE;}
")"             {if (insideComment == 0) return TOKEN__PARCIERR;}
"."             {if (insideComment == 0) return TOKEN__PUNTO;}
","             {if (insideComment == 0) return TOKEN__COMA;}
":"             {if (insideComment == 0) return TOKEN__DOSPUNT;}
"<"             {if (insideComment == 0) return TOKEN__MENOR;}
">"             {if (insideComment == 0) return TOKEN__MAYOR;}
"<="            {if (insideComment == 0) return TOKEN__MENORIG;}
">="            {if (insideComment == 0) return TOKEN__MAYORIG;}
"="             {if (insideComment == 0) return TOKEN__IGUAL;}
"/="            {if (insideComment == 0) return TOKEN__DESIGUAL;}
"~"             {if (insideComment == 0) return TOKEN__NEG;}
"\\/"           {if (insideComment == 0) return TOKEN__DISY;}
"/\\"           {if (insideComment == 0) return TOKEN__CONJ;}
"+"             {if (insideComment == 0) return TOKEN__SUMA;}
"-"             {if (insideComment == 0) return TOKEN__RESTA;}
"*"             {if (insideComment == 0) return TOKEN__MULT;}
"/"             {if (insideComment == 0) return TOKEN__DIV;}
"%"             {if (insideComment == 0) return TOKEN__MOD;}

{commentOpen}   {if (insideComment == 0) return TOKEN__COMMENTOPEN;}
{commentClose}  {if (insideComment == 0) return TOKEN__COMMENTCLOSE;}
{commentln}     {if (insideComment == 0) return TOKEN__COMMENTLN;}

{espacio}       {colNo;} hacer contar columna aqui
{salto}         {lineno++; insideComment = 1;{if (insideComment == 0) return TOKEN__NEWLINE;}
{tab}           {;} hacer contar columna aqui
{cualquiera}    {;} error aqui


%%

int yywrap(){
	return 1;
}
 