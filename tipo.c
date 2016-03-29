#ifndef tipo_h
#define tipo_h

union valores{
	int num;
	bool booleano;
	char caracter;
};


class Tipo{
	valores valor;
	int tipo;

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

	valores obtenerValor(){
		return valor;
	}
};


#endif