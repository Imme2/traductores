#include <string>
#include "expresion.c"
#include <iostream>
using namespace std;

// Una simple clase que hace una lista de Ids en forma de arbol

class listaIDs {
public:

	listaIDs *left;
	string right;

	//Caso recursivo

	listaIDs(listaIDs *l, string r): left(l), right(r){}

	//Caso base

	listaIDs(string r): right(r){
		left = NULL;
	}


	//Toma ventaja de la estructura de arbol para imprimir
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

// clase virtual declaracion para futuras entregas.

class declaracion{
public:

	virtual ~declaracion(){}

	virtual void toString(int){}

};

//Secuencia de declaraciones para futuras entregas.

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

// clase virtual instruccion, padre de la mayoria de las otras clases

class instruccion{
public:

	virtual ~instruccion(){}

	virtual void toString(int){}

};

//Secuencia de instrucciones, toma ventaja de la estructura de arbol nuevamente para 
// hacer una lista.

class secuenciaInstrucciones: public instruccion{
public:

	instruccion *right;
	instruccion *left;

	//Se usa de nuevo el polimorfismo para hacer una lista de instrucciones en forma
	// de arbol

	secuenciaInstrucciones(instruccion* l,instruccion *r): right(r), left(l){} 

	secuenciaInstrucciones(instruccion *r): right(r){
		left = NULL;
	}

	//funcion que imprime la version del arbol de la secuencia de instrucciones,
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

// A continuacion las definiciones de clases de varias instrucciones
// las unicas diferencias radican en lo necesario para cada instruccion
// se sigue usando el toString(i) para imprimir con i siendo el numero
// de tabulaciones (o la profundidad) del paso en que se encuentra.

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
	}

};




// Funcion principal del programa, que comienza el arbol

class arbolSintactico{
public:

	declaracion *left;
	instruccion *right;

	arbolSintactico(declaracion *l, instruccion *r): left(l),right(r){};

	void toString(int i){
		right->toString(i);
	}

};

//Casi igual a la instruccion arbolSintactico, pero se diferencia por claridad

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
