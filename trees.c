


class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(){}

};

class arbolSintactico: public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r)left(l),right(r){};

	void toString(){

	}

};

class secuenciaInstrucciones: public instruccion{
public:

	instruccion *right
	secuenciaInstrucciones *left;

	secuenciaInstrucciones(secuenciaInstrucciones* r,instruccion *l)left(l), right(r){}

	secuenciaInstrucciones(instruccion *r)right(r){
		left = NULL;
	}

	void toString(){

	}

};

class advanceInst: public instruccion{
public:

	listaIDs *ids;
	advanceInst(listaIDs id) ids(id){}

	void toString(){

	}

};

class activateInst: public instruccion{
public:

	listaIDs *ids;
	activateInst(listaIDs id) ids(id){}

	vooid toString(){

	}

};

class deactivateInst: public instruccion{
public:

	listaIDs *ids;
	deactivateInst(listaIDs id) ids(id){}

	void toString(){

	}

};

class conditionalInst: public instruccion{

	secuenciaInstrucciones* success;
	secuenciaInstrucciones* failure;
	boolExpression* guardia;

	conditionalInst(boolExpression *g,secuenciaInstrucciones* s,secuenciaInstrucciones* f) guardia(g),success(s){
		if (f == NULL){
			failure == NULL;
		}
		else{
			failure = f;
		}
	}

	void toString(){

	}


};

class loopInstr: public instruccion{


	secuenciaInstrucciones success;
	boolExpression* guardia;

	loopInstr(boolExpression* g, secuenciaInstrucciones* s) guardia(g), success(s){}

};

class Expression{
public:
	virtual ~Expression(){}

	virtual void toString(){};

};

class algExpression: public Expression{

	string operador;
	algExpression *left;
	string rId;
	int rInt;

	algExpression(string op, algExpression *l, )left(l){

	}
};

class boolExpression: public Expression{
public:
	string operador;
	boolExpression *lBool;
	bool boolvalue;
	string idvalue

	algExpression *rAlg;
	algExpression *lAlg;	

	boolExpression(string op, boolExpression *l, bool r)lBool(l), operador(op){
		boolvalue = r;
		idvalue = NULL;
		rAlg = NULL;
		lAlg = NULL;
	}

	boolExpression(string op, boolExpression *l, string id)lBool(l),operador(op), idvalue(id){
		rAlg = NULL;
		lAlg = NULL;
	}

	boolExpression(string op, algExpression *l, algExpression *r) rAlg(r), lAlg(l), operador(op){
		lBool = NULL;
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