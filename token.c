#include <string>
#include "scanner.h"
#include <sstream>

using namespace std;

// Esta es la clase de tokens
// en ella se contiene el tipo de token
// y el numero, identificador o caracter que
// este adentro en caso de ser de alguno de estos tipos
// ademas se encuentra la fila y columna del token.

class token{
	string IdentValue;
	long long NumValue;
	int type;
	int posFila;
	int posColu;
public:

	// Se usan varias funciones constructoras para aprovechar el overload
	// en caso de ser un tipo que necesita un numero o string.

	token(int givenType, int fila, int col){
		type = givenType;
		posFila = fila;
		posColu = col;
	}

	token(int givenType, string identV, int fila, int col){
		type = givenType;
		IdentValue = identV;
		posFila = fila;
		posColu = col;
	}

	token(int givenType, int Num, int fila, int col){
		type = givenType;
		NumValue = Num;
		posFila = fila;
		posColu = col;
	}


	// Una gran funcion que retorna un string, se usa un switch
	// bastante grande para ensamblar en un stringstream el
	// string correcto.
	// Al final de esto se le agrega al string la posicion
	// del token. 

	string toString(){
		ostringstream result;
		switch(type){
			case IDENT:
				result << "TkIdent(\"" << IdentValue << "\")";
				break;
			case NUM:
				result << "TkNum(" << NumValue << ")";
				break;
			case CHARACTER:
				result << "TkCaracter(" << IdentValue << ")";
				break;
			case CREATE:
				result << "TkCreate";
				break;
			case TRU:
				result << "TkTrue";
				break;
			case FAL:
				result << "TkFalse";
				break;
			case ACTIVATE:
				result << "TkActivate";
				break;
			case ACTIVATION:
				result << "TkActivation";
				break;
			case DEACTIVATE:
				result << "TkDeactivate";
				break;
			case DEACTIVATION:
				result << "TkDeactivation";
				break;
			case ADVANCE:
				result << "TkAdvance";
				break;
			case DEFAULT:
				result << "TkDefault";
				break;
			case COLLECT:
				result << "TkCollect";
				break;
			case DISY:
				result << "TkDisyuncion";
				break;
			case CONJ:
				result << "TkConjuncion";
				break;
			case PUNTO:
				result << "TkPunto";
				break;
			case COMA:
				result << "TkComa";
				break;
			case DOSPUNT:
				result << "TkDosPuntos";
				break;
			case PARABRE:
				result << "TkParAbre";
				break;
			case PARCIERR:
				result << "TkParCierra";
				break;
			case SUMA:
				result << "TkSuma";
				break;
			case RESTA:
				result << "TkResta";
				break;
			case MULT:
				result << "TkMult";
				break;
			case DIV:
				result << "TkDiv";
				break;
			case MOD:
				result << "TkMod";
				break;
			case NEG:
				result << "TkNegacion";
				break;
			case MENOR:
				result << "TkMenor";
				break;
			case MENORIG:
				result << "TkMenorIgual";
				break;
			case MAYOR:
				result << "TkMayor";
				break;
			case MAYORIG:
				result << "TkMayorIgual";
				break;
			case IGUAL:
				result << "TkIgual";
				break;
			case DESIGUAL:
				result << "TkDesigual";
				break;
			case WHILE:
				result << "TkWhile";
				break;
			case BOOL:
				result << "TkBool";
				break;
			case INT:
				result << "TkInt";
				break;
			case CHAR:
				result << "TkChar";
				break;
			case IF:
				result << "TkIf";
				break;
			case ELSE:
				result << "TkElse";
				break;
			case SEND:
				result << "TkSend";
				break;
			case EXECUTE:
				result << "TkExecute";
				break;
			case ON:
				result << "TkOn";
				break;
			case STORE:
				result << "TkStore";
				break;
			case BOT:
				result << "TkBot";
				break;
			case ME:
				result << "TkMe";
				break;
			case DROP:
				result << "TkDrop";
				break;
			case UP:
				result << "TkUp";
				break;
			case DOWN:
				result << "TkDown";
				break;
			case RIGHT:
				result << "TkRight";
				break;
			case LEFT:
				result << "TkLeft";
				break;
			case READ:
				result << "TkRead";
				break;
			case AS:
				result << "TkAs";
				break;
			case RECEIVE:
				result << "TkReceive";
				break;
			case END:
				result << "TkEnd";
				break;
		}

		result << " " << posFila << " " << posColu;

		return result.str();
	}

};