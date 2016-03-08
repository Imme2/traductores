#ifndef instrucciones_h
#define instrucciones_h

#include <iostream>
#include <string>
#include "expresion.c"

using namespace std;

// clase virtual Instruccion, padre de la mayoria de las otras clases

class Instruccion{
public:

	virtual ~Instruccion(){}

	virtual void toString(int){}

};

//Secuencia de Instrucciones, toma ventaja de la estructura de arbol nuevamente para 
// hacer una lista.

class SecuenciaInstrucciones: public Instruccion{
public:

	Instruccion *right;
	Instruccion *left;

	//Se usa de nuevo el polimorfismo para hacer una lista de Instrucciones en forma
	// de arbol

	SecuenciaInstrucciones(Instruccion* l,Instruccion *r): right(r), left(l){} 

	SecuenciaInstrucciones(Instruccion *r): right(r){
		left = NULL;
	}

	//funcion que imprime la version del arbol de la secuencia de Instrucciones,
	// lleva un argumento que nos dice cuantas tabulaciones debemos usar para
	// estar al nivel correcto en la salida estandar

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

// A continuacion las definiciones de clases de varias Instrucciones
// las unicas diferencias radican en lo necesario para cada Instruccion
// se sigue usando el toString(i) para imprimir con i siendo el numero
// de tabulaciones (o la profundidad) del paso en que se encuentra.

class AdvanceInst: public Instruccion{
public:

	ListaIDs *ids;
	AdvanceInst(ListaIDs *listid): ids(listid){}

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

class ActivateInst: public Instruccion{
public:

	ListaIDs *ids;
	ActivateInst(ListaIDs *listid): ids(listid){}

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

class DeactivateInst: public Instruccion{
public:

	ListaIDs *ids;
	
	DeactivateInst(ListaIDs *listid): ids(listid){}

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



class Condicional: public Instruccion{
public:
	Instruccion* success;
	Instruccion* failure;
	Expresion* guardia;

	Condicional(Expresion *g,Instruccion* s,Instruccion* f): success(s),guardia(g){
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

class LoopInst: public Instruccion{
public:

	Instruccion *success;
	Expresion *guardia;

	LoopInst(Expresion* g, Instruccion* s): success(s),guardia(g){}

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
	}

};





//Casi igual a la Instruccion ArbolSintactico, pero se diferencia por claridad

class IncorpAlcance: public Instruccion{
public:

	Declaracion *left;
	Instruccion *right;

	IncorpAlcance(Declaracion *l, Instruccion *r): left(l),right(r){};

	bool verificar()

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "INCORPALCANCE:";
		right->toString(i+1);
	}

};
