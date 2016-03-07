#ifndef expression_h
#define expression_h

#include <string>
#include <iostream>
#define ERRORTIPO -2
#define TIPOBOOL 0
#define TIPOINT 1
#define TIPOCHAR 2
#define TIPOID 3

using namespace std;


//Clase expresion, diferentes constructores para usar el polimorfismo efectivamente

class Expresion{
public:
	int tipo;	// tipo del 0 al 3, indicando si es booleano
				// un id, un caracter o un numero
				// tipo = -1 indica que es una expresion compuesta
				// tipo == 0 -> es un booleano
				// tipo == 1 -> es un numero
				// tipo == 2 -> es un caracter
				// tipo == 3 -> es un ID
	bool unary;
	string operador;
	string id;
	int val;
	bool bval;
	string caracter;

	Expresion *right;
	Expresion *left;

	//Recibe dos expresiones y un operador, crea una expresion compuesta

	Expresion(string op, Expresion *l, Expresion *r): operador(op),left(l),right(r){
		unary = false;
		tipo = -1;
	}

	//A continuacion 3 constructores que hacen los tipos basicos
	// para simplificar problemas por caracteres como \n y \t
	// se usa un string para representar a un caracter

	Expresion(string a,int t){
		unary = false;
		tipo = t;
		if (t == 2){
			caracter = string(a);
		}
		if (t == 3){
			id = string(a);
		}
	}

	Expresion(bool v, int t){
		unary = false;
		bval = v;
		tipo = t;
	}

	Expresion(int v, int t){
		unary = false;
		tipo = t;
		val = v;
	}

	// Constructor para las operaciones unarias

	Expresion(string op, Expresion* l):operador(op),left(l){
		tipo = -1;
		unary = true;
	}


	// Funcion que calcula el tipo de una expresion
	int CalcularTipo(){
		int aux,aux2;
		if (tipo == ERRORTIPO){
			return tipo;
		}
		if (tipo >= 0 and tipo != TIPOID){
			return tipo;
		}
		if (tipo == TIPOID){
			// NECESITAMOS UN MAPA AQUI;
		}
		if (operador == "NEGACION"){
			if (left->CalcularTipo() == TIPOBOOL){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "RESTA" and unary){
			if (left->CalcularTipo() == TIPOINT){
				return TIPOINT;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "MENOR" or operador == "MAYOR" or operador == "MENORIGUAL" or operador == "MAYORIGUAL"){
			if (left->CalcularTipo() == TIPOINT and right->CalcularTipo() == TIPOINT){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "IGUAL" or operador == "DESIGUAL"){
			if (left->CalcularTipo() == right->CalcularTipo()){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "CONJUNCION" or operador == "DISYUNCION"){
			if (left->CalcularTipo() == TIPOBOOL and right->CalcularTipo() == TIPOBOOL){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "SUMA" or (operador == "RESTA" and !unary) or operador == "MULTIPLICACION" or operador == "DIVISION" or operador == "MODULO"){
			if (left->CalcularTipo() == TIPOINT and right->CalcularTipo() == TIPOINT){
				return TIPOINT;
			}
			else{
				return ERRORTIPO;
			}
		}
		cout << "CTHULU HAS ADDED YOU ON FACEBOOK" << endl
		return ERRORTIPO; // por si acaso cthulu ataca el codigo y hace que salga de ifs.
	}

	//Funcion que recursivamente dice si una expresion compleja contiene el identificador "me"
	bool contieneMe(){
		if (tipo == 3){
			if (id == "me"){
				return true;
			}
		}
		else if {tipo == -1}{
			if (unary){
				return left->contieneMe();
			}
			else{
				return left->contieneMe() or right->contieneMe();
			}
		}
		else{
			return false;
		}
	}

	// Gran funcion que imprime el arbol de expresiones
	//  usa el tipo y si es unario o no para
	// 	saber que imprimir
	// Argumento i que nos dice el numero de tabulaciones necesarias.
	void toString(int i){
		if (tipo != -1){
			switch(tipo){
				case 0: // caso booleano
					if (bval){
						cout << "true";
					}
					else{
						cout << "false";
					}
					cout << endl;
					break;
				case 1: // caso numero
					cout << val << endl;
					break;
				case 2: // caso caracter
					cout << caracter << endl;
					break;
				case 3: // caso id
					cout << id << endl;
					break;
			}
			return;
		}
		if (unary){
			cout << "Tipo: Unaria" << endl;

			for (int j = 0; j < i;j++){ //Estas tabulaciones son para mantenernos al
				cout <<"	";			// mismo nivel que el resto del arbol
			}							// en la salida estandar
			cout << "operacion: " << operador << "." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operador unico: ";
			left->toString(i+1);
		}
		else{
			cout << "Tipo: Binaria." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operacion: " << operador << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operador izquierdo: ";
			left->toString(i+1);

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operador Derecho: ";
			right->toString(i+1);
		}
	}

};

	
#endif