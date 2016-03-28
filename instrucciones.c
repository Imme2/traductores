#ifndef instrucciones_h
#define instrucciones_h

#include <iostream>
#include <string>
#include "expresion.c"
#include "declaraciones.c"
#include "mapa.c"

using namespace std;

// clase virtual Instruccion, padre de la mayoria de las otras clases

class Instruccion{
public:

	virtual ~Instruccion(){}

	virtual bool verificar(MapaDeTipos&){}

	virtual void toString(int){}

};

//Secuencia de Instrucciones, toma ventaja de la estructura de arbol nuevamente para 
// hacer una lista.

class SecuenciaInstrucciones: public Instruccion{
public:

	Instruccion *right;
	Instruccion *left;
	int lineNo;

	//Se usa de nuevo el polimorfismo para hacer una lista de Instrucciones en forma
	// de arbol

	SecuenciaInstrucciones(Instruccion* l,Instruccion *r, int line): right(r), left(l){
		lineNo = line;
	} 

	SecuenciaInstrucciones(Instruccion *r, int line): right(r){
		left = NULL;
		lineNo = line;
	}

	bool verificar(MapaDeTipos& mapa){
		SecuenciaInstrucciones *aux = (SecuenciaInstrucciones*) left;

		if (right->verificar(mapa)){
			while (aux != NULL){
				if (aux->right->verificar(mapa)){
					aux = (SecuenciaInstrucciones*) aux->left;
				}
				else{
					return false;
				}
			}
			return true;
		}
		return false;
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
	int lineNo;
	AdvanceInst(ListaIDs *listid, int line): ids(listid){
		lineNo = line;
	}



	//Para esta instruccion solo debemos verificar que en los ids no este "me"
	// y que todos esten declarados.
	bool verificar(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();

		for (int i = 0 ; i < aux.size();i++){
			if (aux[i] == "me"){
				cout << "Error en instruccion Advance. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador \"me\" no puede ser usado fuera de la declaracion de un robot." << endl;
				return false;
			}
			else if(!mapa.existe(aux[i])){
				cout << "Error en instruccion Advance. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador " << aux[i] << " no ha sido declarado." << endl;
				return false;		
			}
		}
		return true;
	}

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
	int lineNo;
	ActivateInst(ListaIDs *listid,int line): ids(listid){
		lineNo = line;
	}


	//Para esta instruccion solo debemos verificar que en los ids no este "me"
	// y que todos esten declarados.
	bool verificar(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();

		for (int i = 0 ; i < aux.size();i++){
			if (aux[i] == "me"){
				cout << "Error en instruccion Activate. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador \"me\" no puede ser usado fuera de la declaracion de un robot." << endl;
				return false;
			}
			else if (!mapa.existe(aux[i])){
				cout << "Error en instruccion Activate. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador " << aux[i] << " no ha sido declarado." << endl;
				return false;		
			}
		}
		return true;
	}

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
	int lineNo;	
	DeactivateInst(ListaIDs *listid,int line): ids(listid){
		lineNo = line;
	}

	//Para esta instruccion solo debemos verificar que en los ids no este "me"
	// y que todos esten declarados.
	bool verificar(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();

		for (int i = 0 ; i < aux.size();i++){
			if (aux[i] == "me"){
				cout << "Error en instruccion Deactivate. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador \"me\" no puede ser usado fuera de la declaracion de un robot." << endl;
				return false;
			}
			else if (!mapa.existe(aux[i])){
				cout << "Error en instruccion Deactivate. Linea " << lineNo << "." << endl;
				cout << "Razon: el identificador " << aux[i] << " no ha sido declarado." << endl;
				return false;		
			}
		}
		return true;
	}

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
	int lineNo;
	Condicional(Expresion *g,Instruccion* s,Instruccion* f,int line): success(s),guardia(g){
		if (f == NULL){
			failure = NULL;
		}
		else{
			failure = f;
		}
		lineNo = line;
	}


	//Debemos verificar que la guardia sea booleana (sin contener "me"s) y que tanto las
	// instrucciones de success como de failure sean validas.
	bool verificar(MapaDeTipos& mapa){
		if (guardia->contieneMe()){			// Verificamos que la guardia no contenga me's
			cout << "Error en condicional. Linea " << lineNo << "." << endl;
			cout << "Razon: La guardia contiene el identificador \"me\" que no puede ser usado en este contexto." << endl;
			return false;
		}
		int aux = guardia->calcularTipo(mapa,-2);//El argumento tipo no es necesario pues no estamos en
												// una declaracion, asi que solo se coloca -2 (como error de tipo).
		if (aux != 0 and aux != -2){
			cout << "Error en condicional. Linea " << lineNo << "." << endl;
			cout << "Razon: La guardia es de tipo ";

			if (aux == TIPOINT){
				cout << "Entero";
			}
			if (aux == TIPOCHAR){
				cout << "Caracter";
			}

			cout << " cuando se esperaba un booleano." << endl;
			return false;
		}
		if (aux == -2){
			return false; // El error en este caso lo reporta la expresion
		}		

		if (!(success->verificar(mapa))){
			return false;
		}

		if (failure != NULL){
			if (!(failure->verificar(mapa))){
				return false;
			}
		}
		return true;

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
	int lineNo;
	LoopInst(Expresion* g, Instruccion* s,int line): success(s),guardia(g){
		lineNo = line;
	}

	//Debemos verificar que la guardia sea booleana (sin contener "me"s) y que tanto las
	// instrucciones de success como de failure sean validas.
	bool verificar(MapaDeTipos& mapa){
		if (guardia->contieneMe()){			// Verificamos que la guardia no contenga me's
			cout << "Error en instruccion while. Linea " << lineNo <<"." << endl;
			cout << "Razon: La guardia contiene el identificador \"me\" que no puede ser usado en este contexto." << endl;
			return false;
		}
		int aux = guardia->calcularTipo(mapa,-2);//El argumento tipo no es necesario pues no estamos en
												// una declaracion, asi que solo se coloca -2 (como error de tipo).
		if (aux != 0 and aux != -2){
			cout << "Error en instruccion while. Linea " << lineNo <<"." << endl;
			cout << "Razon: La guardia es de tipo ";

			if (aux == TIPOINT){
				cout << "Entero";
			}
			if (aux == TIPOCHAR){
				cout << "Caracter";
			}

			cout << " cuando se esperaba un booleano." << endl;
			return false;
		}
		if (aux == -2){
			return false; // El error en este caso lo reporta la expresion
		}

		if (!(success->verificar(mapa))){
			return false;
		}

		return true;

	}


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
	int lineNo;
	IncorpAlcance(Declaracion *l, Instruccion *r,int line): left(l),right(r){
		lineNo = line;
	};

	bool verificar(MapaDeTipos& mapa){
		mapa.nuevoNivel();
		if (left->verificar(mapa)){ // Verificamos las declaraciones 
			if (left->declararRobots(mapa)){ // Poblamos el mapa
				if (right->verificar(mapa));{ // Verificamos los tipos en las instrucciones.
					mapa.subirNivel();
					return true;
				}
			}
		}
		return false;
	}

	void toString(int i){
		for (int j = 0; j < i;j++){
			cout <<"	";
		}
		cout << "INCORPALCANCE:";
		right->toString(i+1);
	}

};

#endif