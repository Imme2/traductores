#include <string>

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


class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(){}

};

class secuenciaInstrucciones: public instruccion{
public:

	instruccion *right;
	secuenciaInstrucciones *left;

					//Nota, en el siguiente constructor el compilador me dijo que cambiara
					// el orden al que esta ahora, ni idea porque.
	secuenciaInstrucciones(secuenciaInstrucciones* l,instruccion *r): right(r), left(l){} 

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






class arbolSintactico: public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r): left(l),right(r){};

	void toString(){

	}

};

class incorpAlcance: public instruccion{
public:

	secuenciaDeclaraciones *left;
	secuenciaInstrucciones *right;

	arbolSintactico(secuenciaDeclaraciones *l, secuenciaInstrucciones *r): left(l),right(r){};

	void toString(){

	}

};
