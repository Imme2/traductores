#include <string>
#include "expresion.c" //ERRORTIPO se define aqui como -2
#include <iostream>
#include <map>

using namespace std;

// Una simple clase que hace una lista de Ids en forma de arbol

class ListaIDs {
public:

	ListaIDs *left;
	string right;

	//Caso recursivo

	ListaIDs(ListaIDs *l, string r): left(l), right(r){}

	//Caso base

	ListaIDs(string r): right(r){
		left = NULL;
	}

	void estanDeclarados(map< string, int >& ListVar){
		if (left == NULL){
			return ListVar
		}
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


// 

class InstruccionRobot{
	virtual ~InstruccionRobot(){}

	virtual void toString(int){}
};

class SecuenciaRoboInstruccion: InstruccionRobot{
public:
	InstruccionRobot *right;
	InstruccionRobot *left;

	SecuenciaDeclaraciones(InstruccionRobot* l,InstruccionRobot* r): right(r), left(l){} 

	SecuenciaDeclaraciones(InstruccionRobot* r): right(r){
		left = NULL;
	}

	void toString(int i){
		;
	}

};

class Almacenamiento: public InstruccionRobot{
public:

	Expresion* exp; //verificar que tipo = tipo del robot

	Almacenamiento(Expresion* e):exp(e){}

	Tipo CalcularTipo(){
		return exp.CalcularTipo();
	};
};

class Coleccion: public InstruccionRobot{
public:

	string identificador;
	bool tieneId;

	Coleccion(string id):identificador(id){
		tieneId = true;
	}

	Coleccion(){
		tieneId = false;
	}
};

class Soltado: public InstruccionRobot{
public:
	Expresion* exp;

	Soltado(Expresion* e): exp(e){}
};

class Movimiento: public InstruccionRobot{
public:

	int direccion;
	Expresion* exp;

	Movimiento(int d, Expresion* e): exp(e){
		direccion = d;
	}
};

class Leer: public InstruccionRobot{
public:

	string identificador;
	bool tieneId;

	Leer(string id):identificador(id){
		tieneId = true;
	}

	Leer(){
		tieneId = false;
	}
};

class Escribir: public InstruccionRobot{
public:

	Escribir(){}

};


class Comportamiento{
public:
	int tipoCondicion; 	// 0 al 3
						// 0 => Expresion
						// 1 => activacion
						// 2 => desactivacion
						// 3 => default
	Expresion* exp;
	SecuenciaRoboInstruccion secRoboInst;

	Comportamiento(int t,Expresion* e, SecuenciaRoboInstruccion* secinst): exp(e), secRoboInst(sec){
		tipoCondicion = t;
	}
};

class SecuenciaComportamiento{
public:

	Comportamiento *right;
	Comportamiento *left;

	SecuenciaComportamiento(Comportamiento* l,Comportamiento* r): right(r), left(l){} 

	SecuenciaComportamiento(Comportamiento* r): right(r){
		left = NULL;
	}

	void toString(int i){
		;
	}

};

// clase virtual Declaracion para futuras entregas.

class Declaracion{
public:

	virtual ~Declaracion(){}

	virtual void toString(int){}

};

//Secuencia de Declaraciones para futuras entregas.

class SecuenciaDeclaraciones: public Declaracion{
public:

	Declaracion *right;
	Declaracion *left;

	SecuenciaDeclaraciones(Declaracion* l,Declaracion* r): right(r), left(l){} 

	SecuenciaDeclaraciones(Declaracion* r): right(r){
		left = NULL;
	}

	void toString(int i){
		;
	}

};

class DeclaracionRobot: public Declaracion{
public:

	int tipo; 	// tipo == 0 -> es un booleano
				// tipo == 1 -> es un numero
				// tipo == 2 -> es un caracter



	ListaIDs* ids;
	SecuenciaComportamiento* comportamiento;

	DeclaracionRobot(int t,ListaIDs* l,SecuenciaComportamiento* comps): ids(l), comportamiento(comps){
		tipo = t;
	}

	bool verificarTipo(){
		;
	}
};


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

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "INCORPALCANCE:";
		right->toString(i+1);
	}

};


// Funcion principal del programa, que comienza el arbol

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;

	ArbolSintactico(Declaracion *l, Instruccion *r): left(l),right(r){};

	void toString(int i){
		right->toString(i);
	}

};
