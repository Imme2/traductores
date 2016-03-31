#ifndef expression_h
#define expression_h

#include <string>
#include <iostream>
#include "mapa.c"
#include "valores.c"
#include "Espacio.c"
#include "Robot.c"
#include "MapaRobots.c"
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

	int lineNo;
	//Recibe dos expresiones y un operador, crea una expresion compuesta

	Expresion(string op, Expresion *l, Expresion *r, int line): operador(op),left(l),right(r){
		unary = false;
		tipo = -1;
		lineNo = line;
	}

	//A continuacion 3 constructores que hacen los tipos basicos
	// para simplificar problemas por caracteres como \n y \t
	// se usa un string para representar a un caracter

	Expresion(string a,int t, int line){
		unary = false;
		tipo = t;
		if (t == 2){
			caracter = string(a);
		}
		if (t == 3){
			id = string(a);
		}
		lineNo = line;

	}

	Expresion(bool v, int t,int line){
		unary = false;
		bval = v;
		tipo = t;
		lineNo = line;
	}

	Expresion(int v, int t,int line){
		unary = false;
		tipo = t;
		val = v;
		lineNo = line;
	}

	// Constructor para las operaciones unarias

	Expresion(string op, Expresion* l, int line):operador(op),left(l){
		tipo = -1;
		unary = true;
		lineNo = line;
	}


	Valores evaluar(Robot* bot, MapaRobots& mapa, Espacio& space, map<string,Valores> tablasimb){
		if (tipo == 0 or tipo == 1 or tipo == 2);
	}

	// Funcion que calcula el tipo de una expresion
	int calcularTipo(MapaDeTipos& mapa,int t){
		int aux,aux2;
		if (tipo == ERRORTIPO){
			return tipo;
		}
		if (tipo >= 0 and tipo != TIPOID){
			return tipo;
		}
		if (tipo == TIPOID){
			if (id == "me"){
				return t;
			}
			else if ((aux = mapa.obtenerTipo(id)) != -1){
				return aux;
			}
			else if (aux == -1){
				cout << "Error evaluando expresion. Linea " << lineNo << "." << endl;
				cout << "Razon: Variable " << id << " no declarada." << endl;
				return ERRORTIPO;
			}
		}
		if (operador == "NEGACION"){
			if (left->calcularTipo(mapa,t) == TIPOBOOL){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "RESTA" and unary){
			if (left->calcularTipo(mapa,t) == TIPOINT){
				return TIPOINT;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "MENOR" or operador == "MAYOR" or operador == "MENORIGUAL" or operador == "MAYORIGUAL"){
			if (left->calcularTipo(mapa,t) == TIPOINT and right->calcularTipo(mapa,t) == TIPOINT){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "IGUAL" or operador == "DESIGUAL"){
			aux = left->calcularTipo(mapa,t);
			if (aux == ERRORTIPO){
				return ERRORTIPO;
			}
			if (aux == right->calcularTipo(mapa,t)){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "CONJUNCION" or operador == "DISYUNCION"){
			if (left->calcularTipo(mapa,t) == TIPOBOOL and right->calcularTipo(mapa,t) == TIPOBOOL){
				return TIPOBOOL;
			}
			else{
				return ERRORTIPO;
			}
		}
		if (operador == "SUMA" or (operador == "RESTA" and !unary) or operador == "MULTIPLICACION" or operador == "DIVISION" or operador == "MODULO"){
			if (left->calcularTipo(mapa,t) == TIPOINT and right->calcularTipo(mapa,t) == TIPOINT){
				return TIPOINT;
			}
			else{
				return ERRORTIPO;
			}
		}
		return ERRORTIPO; // por si acaso cthulu ataca el codigo y hace que salga de ifs.
	}

	//Funcion que recursivamente dice si una expresion compleja contiene el identificador "me"
	bool contieneMe(){
		if (tipo == 3){
			if (id == "me"){
				return true;
			}
		}
		else if (tipo == -1){
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