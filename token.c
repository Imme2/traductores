#include <string>
#include "scanner.h"
#include <sstream>

using namespace std;

class token{
	string IdentValue;
	long long NumValue;
	int type;
	int posFila;
	int posColu;
public:

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

	string toString(){
		ostringstream result;
		switch(type){
			case IDENT:
				result << "TkIdent(\"" << IdentValue << "\")";
			case NUM:
				result << "TkNum(" << NumValue << ")";
			case CHARACTER:
				result << "TkCaracter(" << IdentValue << ")";
			case CREATE:
				result << "TkCreate";
			case TRU:
				result << "TkTrue";
			case FAL:
				result << "TkFalse";
			case ACTIVATE:
				result << "TkActivate";
			case ACTIVATION:
				result << "TkActivation";
			case DEACTIVATE:
				result << "TkDeactivate";
			case DEACTIVATION:
				result << "TkDeactivation";
			case ADVANCE:
				result << "TkAdvance";
			case DEFAULT:
				result << "TkDefault";
			case COLLECT:
				result << "TkCollect";
			case DISY:
				result << "TkDisyuncion";
			case CONJ:
				result << "TkConjuncion";
			case PUNTO:
				result << "TkPunto";
			case COMA:
				result << "TkComa";
			case DOSPUNT:
				result << "TkDosPuntos";
			case PARABRE:
				result << "TkParAbre";
			case PARCIERR:
				result << "TkParCierra";
			case SUMA:
				result << "TkSuma";
			case RESTA:
				result << "TkResta";
			case MULT:
				result << "TkMult";
			case DIV:
				result << "TkDiv";
			case MOD:
				result << "TkMod";
			case NEG:
				result << "TkNegacion";
			case MENOR:
				result << "TkMenor";
			case MENORIG:
				result << "TkMenorIgual";
			case MAYOR:
				result << "TkMayor";
			case MAYORIG:
				result << "TkMayorIgual";
			case IGUAL:
				result << "TkIgual";
			case DESIGUAL:
				result << "TkDesigual";
			case WHILE:
				result << "TkWhile";
			case BOOL:
				result << "TkBool";
			case INT:
				result << "TkInt";
			case CHAR:
				result << "TkChar";
			case IF:
				result << "TkIf";
			case ELSE:
				result << "TkElse";
			case SEND:
				result << "TkSend";
			case EXECUTE:
				result << "TkExecute";
			case ON:
				result << "TkOn";
			case STORE:
				result << "TkStore";
			case BOT:
				result << "TkBot";
			case ME:
				result << "TkMe";
			case DROP:
				result << "TkDrop";
			case UP:
				result << "TkUp";
			case DOWN:
				result << "TkDown";
			case RIGHT:
				result << "TkRight";
			case LEFT:
				result << "TkLeft";
			case READ:
				result << "TkRead";
			case AS:
				result << "TkAs";
			case RECEIVE:
				result << "TkReceive";
		}

		result << " " << posFila << " " << posColu;

		return result.str();
	}

};