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

	virtual void toString(int){}

};

class secuenciaDeclaraciones: public declaracion{
public:

	declaracion *right;
	declaracion *left;

	secuenciaDeclaraciones(declaracion* l,declaracion *r): right(r), left(l){} 

	secuenciaDeclaraciones(declaracion *r): right(r){
		left = NULL;
	}

	void toString(int i){
		;
	}

};


class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(int){}

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

	void toString(int i){

		if (left != NULL){
			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "SECUENCIACION: " << endl;
			left->toString(i+1);
			right->toString(i+1);
			return;
		}
		right->toString(i);
	}

};

class advanceInst: public instruccion{
public:

	listaIDs *ids;
	advanceInst(listaIDs *listid): ids(listid){}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "AVANCE:" << endl;
		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}
		cout << "- var: ";
		ids->toString();
		cout << endl;
	}

};

class activateInst: public instruccion{
public:

	listaIDs *ids;
	activateInst(listaIDs *listid): ids(listid){}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "ACTIVACION: "<< endl;
		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}
		cout << "- var:";
		ids->toString();
		cout << endl;
	}

};

class deactivateInst: public instruccion{
public:

	listaIDs *ids;
	deactivateInst(listaIDs *listid): ids(listid){}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "DESACTIVACION: " << endl;
		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}
		cout << "- var:";
		ids->toString();
		cout << endl;
	}

};



class condicional: public instruccion{
public:
	instruccion* success;
	instruccion* failure;
	Expression* guardia;

	condicional(Expression *g,instruccion* s,instruccion* f): success(s),guardia(g){
		if (f == NULL){
			failure = NULL;
		}
		else{
			failure = f;
		}
	}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}		
		cout << "CONDICIONAL:" << endl;

		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}
		cout << "-guardia: ";
		guardia->toString(i+2);

		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}		
		cout << "-exito: ";
		cout << endl;
		success->toString(i+2);

		if (failure !=  NULL){
			for (int j = 0; j < i+1;j++){
				cout <<"	";
			}		
			cout << "-fracaso";
			cout << endl;
			failure->toString(i+2);
		}
	}


};

class loopInst: public instruccion{
public:

	instruccion *success;
	Expression *guardia;

	loopInst(Expression* g, instruccion* s): success(s),guardia(g){}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}		
		cout << "LOOP:" << endl;

		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}		
		cout << "-guardia: ";
		guardia->toString(i+2);

		for (int j = 0; j < i+1;j++){
			cout <<"	";
		}
		cout << "-exito: " << endl;
		success->toString(i+2);
		cout << endl;
	}

};






class arbolSintactico: public instruccion{
public:

	declaracion *left;
	instruccion *right;

	arbolSintactico(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(int i){
		right->toString(i);
	}

};

class incorpAlcance: public instruccion{
public:

	declaracion *left;
	instruccion *right;

	incorpAlcance(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "INCORPALCANCE:";
		right->toString(i+1);
	}

};
