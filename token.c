#include <string>
#include <iostream>
#include "scanner.h"
#include <sstream>

using namespace std;

class token{
	string IdentValue;
	long long NumValue;
	char CharValue;
	int type;
	int posFila;
	int posColu;
public:

	token(int givenType, int fila, int col){
		type = givenType;
		posFila = fila;
		posColu = col;
	}

	token(string identV, int fila, int col){
		type = IDENT;
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

	token(char caracter, int fila, int col){
		type = CHARACTER;
		CharValue = caracter;
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
				result << "TkCaracter(" << CharValue << ")";
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
			case EXECUTE:
				result << "TkExecute";
			case DEFAULT:
				result << "TkDefault";
			case COLLECT:
				result << "TkCollect";
			case 
		}

		result << " " << posFila << " " << posColu;

		return result.str();
	}

};