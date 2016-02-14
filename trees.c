


class instruccion{
public:

	virtual instruccion

	virtual toString(){}

};

class arbolSintactico, public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r)left(l),right(r){};

	toString(){

	}

};

class secuenciaInstrucciones, public instruccion{
public:

	instruccion *right
	secuenciaInstrucciones *left;

	secuenciaInstrucciones(secuenciaInstrucciones* r,instruccion *l)left(l), right(r){}

	secuenciaInstrucciones(instruccion *r)right(r){
		left = NULL;
	}

	toString(){

	}

};

class advanceinst, public instruction{
public:

	listaIDs *ids;
	advanceinst(listaIDs id) ids(id){}

	toString(){

	}

};

class listaIDs {
public:

	listaIDs *left;
	string right;

	listaIDs(listaIDs l, string r) left(l), right(r){}

	listaIDs(string r) right(r){
		left = NULL;
	}
};

class operBin, public instruccion{
	
};

class operUnaria, public instruccion{
	
};

class asignacion, public instruccion{

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