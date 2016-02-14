#include <string>



class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(){}

};


class secuenciaInstrucciones: public instruccion{
public:

	instruccion *right;
	secuenciaInstrucciones *left;

	secuenciaInstrucciones(secuenciaInstrucciones* r,instruccion *l): left(l), right(r){}

	secuenciaInstrucciones(instruccion *r): right(r){
		left = NULL;
	}

	void toString(){

	}

};

class advanceInst: public instruccion{
public:

	listaIDs *ids;
	advanceInst(listaIDs id): ids(id){}

	void toString(){

	}

};

class activateInst: public instruccion{
public:

	listaIDs *ids;
	activateInst(listaIDs id): ids(id){}

	void toString(){

	}

};

class deactivateInst: public instruccion{
public:

	listaIDs *ids;
	deactivateInst(listaIDs id): ids(id){}

	void toString(){

	}

};

class conditionalInst: public instruccion{

	secuenciaInstrucciones* success;
	secuenciaInstrucciones* failure;
	boolExpression* guardia;

	conditionalInst(boolExpression *g,secuenciaInstrucciones* s,secuenciaInstrucciones* f): guardia(g),success(s){
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

	loopInstr(boolExpression* g, secuenciaInstrucciones* s): guardia(g), success(s){}

};

class Expression{
public:
	virtual ~Expression(){}

	virtual void toString(){};

};

class algExpression: public Expression{


	bool unary = true;
	string operador;
	algExpression *left;
	string rId;
	int rInt;

	algExpression(string op, algExpression *l,int r): left(l), operador(op){
		rInt = r;
	}

	algExpression(string op, algExpression *l,int r): left(l), operador(op), rId(r){}

	algExpression(int v){
		left = NULL;
		operador = NULL;
		rInt = v;
	}

	algExpression(string id):rId(id){
		left = NULL;
		operador = NULL;
	}

	algExpression(string op, algExpression *l):eft(l),operador(op){
		unary = true;
	}
};

class boolExpression: public Expression{
public:
	bool unary = false;
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

	boolExpression(string op, boolExpression *l)operador(op), lBool(l){
		unary = true;
	}

	boolExpression(bool r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;
		idvalue = NULL;
		boolvalue = r;
	}

	boolExpression(string r)idvalue(r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;

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

class arbolSintactico: public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r)left(l),right(r){};

	void toString(){

	}

};

class incorpAlcance: public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r)left(l),right(r){};

	void toString(){

	}

};
