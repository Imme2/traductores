#ifndef expression_h
#define expression_h

#include <string>
#include <iostream>

using namespace std;


//Clase expresion, diferentes constructores para usar el polimorfismo efectivamente

class Expression{
public:
	int tipo; 	// tipo del 0 al 3, indicando si es booleano
				// un id, un caracter o un numero
				// tipo = -1 indica que es una expresion compuesta
				// tipo == 0 -> es un numero
				// tipo == 1 -> es un ID
				// tipo == 2 -> es un caracter
				// tipo == 3 -> es un booleano
	bool unary;
	string operador;
	string id;
	int val;
	bool bval;
	string caracter;

	Expression *right;
	Expression *left;

	//Recibe dos expresiones y un operador, crea una expresion compuesta

	Expression(string op, Expression *l, Expression *r): operador(op),left(l),right(r){
		unary = false;
		tipo = -1;
	}

	//A continuacion 3 constructores que hacen los tipos basicos
	// para simplificar problemas por caracteres como \n y \t
	// se usa un string para representar a un caracter

	Expression(string a,int t){
		unary = false;
		tipo = t;
		if (t == 2){
			caracter = string(a);
		}
		if (t == 1){
			id = string(a);
		}
	}

	Expression(bool v, int t){
		unary = false;
		bval = v;
		tipo = t;
	}

	Expression(int v, int t){
		unary = false;
		tipo = t;
		val = v;
	}

	// Constructor para las operaciones unarias

	Expression(string op, Expression* l):operador(op),left(l){
		tipo = -1;
		unary = true;
	}

	int CalcularTipo(){
		int aux,aux2;
		if (tipo != -1){
			return tipo;
		}


	}

	// Gran funcion que imprime el arbol de expresiones
	//  usa el tipo y si es unario o no para
	// 	saber que imprimir
	// Argumento i que nos dice el numero de tabulaciones necesarias.
	void toString(int i){
		if (tipo != -1){
			switch(tipo){
				case 0: // caso numero
					cout << val << endl;
					break;
				case 1: // caso id
					cout << id << endl;
					break;
				case 2: // caso caracter
					cout << caracter << endl;
					break;
				case 3: // caso booleano
					if (bval){
						cout << "true";
					}
					else{
						cout << "false";
					}
					cout << endl;
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