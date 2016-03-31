#ifndef tipo_h
#define tipo_h

#include "valores.c"

#define ERRORTIPO -2
#define TIPOBOOL 0
#define TIPOINT 1
#define TIPOCHAR 2
#define TIPOID 3

using namespace std;

class Tipo{
public:
	Valores valor;
	int tipo;

	Tipo(){
		tipo = -2;
		valor.num = 0;
	}

	Tipo(bool a){
		tipo = TIPOBOOL;
		valor.booleano = a;
	}

	Tipo(int a){
		tipo = TIPOINT;
		valor.num = a;
	}

	Tipo(char a){
		tipo = TIPOCHAR;
		valor.caracter = a;
	}

	int obtenerTipo(){
		return tipo;
	}

	Valores obtenerValor(){
		return valor;
	}

	bool operator<(const Tipo& other) const {
		if ((int)valor.num < (int)other.valor.num){
			return true;
		}
		else{
			return false;
		}
	}

};



#endif