#ifndef expression_h
#define expression_h

#include <string>
#include <iostream>

using namespace std;

class Expression{
public:
	int tipo;
	bool unary;
	string operador;
	string id;
	int val;
	bool bval;
	string caracter;

	Expression *right;
	Expression *left;

	Expression(string op, Expression *l, Expression *r): operador(op),left(l),right(r){
		unary = false;
		tipo = -1;
	}

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

	Expression(string op, Expression* l):operador(op),left(l){
		tipo = -1;
		unary = true;
	}

	void toString(int i){
		if (tipo != -1){
			switch(tipo){
				case 0: 
					cout << val << endl;
					break;
				case 1:
					cout << id << endl;
					break;
				case 2:
					cout << caracter << endl;
					break;
				case 3:
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

			for (int j = 0; j < i;j++){
				cout <<"	";
			}	
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