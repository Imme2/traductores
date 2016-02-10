

class arbolSintactico{



	arbolSintactico();

	print()

	virtual arbolSintactico * clone() = 0;

};

class arbol

class secuenciacion{

	secuenciacion* left;
	secuenciacion* right;


	virtual toprint(){}

};


class suma:public secuenciacion{

};

class expresion: public arbolSintactico{


	int value;
	expresion *left;
	expresion *right;
	char* operador;

	expresion(arbolSintactico* l,arbolSintactico* r, char* op){
		left = new arbolSintactico(l);
		right = new arbolSintactico(r);
		operador = m
	}
};

class numero: public expresion{
	
	public:
		int valor;

		numero(int v) valor(v){}

};

class identificador: public expresion{
	public:
		string id;

		identificador(string v) id(v){}; // Magia negra.
};

class suma: public expresion{
	public:

		nodo *izq;
		nodo *der;

		suma(nodo *I, nodo *D): izq(I), der(D){}
};

class mult: public expresion{
	public:

		nodo *izq;
		nodo *der;

		mult(nodo *I, nodo *D): izq(I), der(D){}
};

class div: public arbolSintactico{
	public:

		nodo *izq;
		nodo *der;

		div(nodo *I, nodo *D): izq(I), der(D){}
};

class