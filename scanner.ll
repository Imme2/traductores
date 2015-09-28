%{
#include <scanner.h>	
%}

string  \"[^\n"]+\"

ws      [ \t]+
dig [0-9]
alpha   [A-Za-z]

comment \$-([^-]|-+[^\$])*-\$
commentln \$\$[.^\n]*\n
TkTrue   true
TkFalse false
coma ,
punto \.
dosPuntos :
TkParAbre \(
TkParCierra \)
TkSuma \+
TkResta -
TkMult \*
TkDiv /
TkMod %
TkConjuncion /\\
TkDisyuncion \\/
TkNegacion ~
TkMenorIgual <=
TkMayorIgual >=
TkMenor <
TkMayor >
TkIgual =
TkCreate create
TkWhile while
TkBool bool
TkInt int
TkChar char
TkIf if
TkElse else
TkEnd end
TkSend send
TkExecute execute
TkOn on
TkStore store
TkBot bot
TkMe me
TkSalto \\n
TkTabulador \\t
TkComilla \'
TkDefault default
TkCollect collect
TkDrop drop
TkLeft left
TkRight right
TkUp up
TkDown down
TkRead read
TkAs as
TkReceive receive
TKAdvance advance
TkActivate activate
TkActivation activation
TkDeactivate deactivate
TkDeactivation deactivation
TkIdent [A-Z]({alpha}|{dig}|_)*
TkNum   [0-9]+
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}

%%

"true" 			return TRUE;
"false" 		return FALSE;
"create"		return CREATE;
"activate"		return ACTIVATE;
"activation"	return ACTIVATION;
"deactivate"	return DEACTIVATE;
"deactivation"	return DEACTIVATION;
"("				return PARABRE;
")"				return PARCIERR;
"."				return PUNTO;
","				return COMA;
":"

{TkIdent}		return IDENT;
{TkActivate} 	return ACTIVATE;
{Tk }
%%

int yywrap(){
	return 1;
}
 