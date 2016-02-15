#include <string>
#include "expresion.c"

using namespace std;

class listaIDs {
public:

	listaIDs *left;
	string right;

	listaIDs(listaIDs *l, string r): left(l), right(r){}

	listaIDs(string r): right(r){
		left = NULL;
	}
};

class declaracion{
public:

	virtual ~declaracion(){}

	virtual void toString(){}

};

class secuenciaDeclaraciones: public declaracion{
public:

	declaracion *right;
	declaracion *left;

	secuenciaDeclaraciones(declaracion* l,declaracion *r): right(r), left(l){} 

	secuenciaDeclaraciones(declaracion *r): right(r){
		left = NULL;
	}

	void toString(){

	}

};


class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(){}

};

class secuenciaInstrucciones: public instruccion{
public:

	instruccion *right;
	instruccion *left;

					//Nota, en el siguiente constructor el compilador me dijo que cambiara
					// el orden al que esta ahora, ni idea porque.
	secuenciaInstrucciones(instruccion* l,instruccion *r): right(r), left(l){} 

	secuenciaInstrucciones(instruccion *r): right(r){
		left = NULL;
	}

	void toString(){

	}

};

class advanceInst: public instruccion{
public:

	listaIDs *ids;
	advanceInst(listaIDs *listid): ids(listid){}

	void toString(){

	}

};

class activateInst: public instruccion{
public:

	listaIDs *ids;
	activateInst(listaIDs *listid): ids(listid){}

	void toString(){

	}

};

class deactivateInst: public instruccion{
public:

	listaIDs *ids;
	deactivateInst(listaIDs *listid): ids(listid){}

	void toString(){

	}

};



class condicional: public instruccion{
public:
	instruccion* success;
	instruccion* failure;
	boolExpression* guardia;

	condicional(boolExpression *g,instruccion* s,instruccion* f): success(s),guardia(g){
		if (f == NULL){
			failure = NULL;
		}
		else{
			failure = f;
		}
	}

	void toString(){

	}


};

class loopInst: public instruccion{
public:

	instruccion *success;
	boolExpression *guardia;

	loopInst(boolExpression* g, instruccion* s): success(s),guardia(g){}

};






class arbolSintactico: public instruccion{
public:

	declaracion *left;
	instruccion *right;

	arbolSintactico(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(){

	}

};

class incorpAlcance: public instruccion{
public:

	declaracion *left;
	instruccion *right;

	incorpAlcance(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(){

	}

};
