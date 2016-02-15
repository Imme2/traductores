#include <string>
#include "expresion.c"
#include <iostream>
using namespace std;

class listaIDs {
public:

	listaIDs *left;
	string right;

	listaIDs(listaIDs *l, string r): left(l), right(r){}

	listaIDs(string r): right(r){
		left = NULL;
	}

	void toString(){
		if (left != NULL){
			left->toString();
			cout << ", " << right; 
		}
		else{
			cout << right;
		}
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
		;
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
		cout << "SECUENCIACION: " << endl;
		cout << "	";
		left->toString();
		cout << endl;
		cout << "	";
		right->toString();
		cout << endl;
	}

};

class advanceInst: public instruccion{
public:

	listaIDs *ids;
	advanceInst(listaIDs *listid): ids(listid){}

	void toString(){
		cout << "AVANCE:" << endl;
		cout << "	- var: ";
		ids->toString();
		cout << endl;
	}

};

class activateInst: public instruccion{
public:

	listaIDs *ids;
	activateInst(listaIDs *listid): ids(listid){}

	void toString(){
		cout << "ACTIVACION: "<< endl;
		cout << "	- var:";
		ids->toString();
		cout << endl;
	}

};

class deactivateInst: public instruccion{
public:

	listaIDs *ids;
	deactivateInst(listaIDs *listid): ids(listid){}

	void toString(){
		cout << "DESACTIVACION: " << endl;
		cout << "	- var:";
		cout << endl;
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
		cout << "CONDICIONAL:" << endl;
		cout << "	-guardia: ";
		guardia.toString();

		cout << "	-exito: ";
		success.toString();
		cout << endl;

		if (failure !=  NULL){
			cout << "	-fracaso";
			failure.toString();
			cout << endl;
		}
	}


};

class loopInst: public instruccion{
public:

	instruccion *success;
	boolExpression *guardia;

	loopInst(boolExpression* g, instruccion* s): success(s),guardia(g){}

	void toString(){
		cout << "LOOP:" << endl;
		cout << "	-guardia: ";
		guardia.toString();
		cout << endl;


		cout << "	-exito: ";
		success.toString();
		cout << endl;
	}

};






class arbolSintactico: public instruccion{
public:

	declaracion *left;
	instruccion *right;

	arbolSintactico(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(){
		right->toString();
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
