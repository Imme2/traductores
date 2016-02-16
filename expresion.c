#ifndef expression_h
#define expression_h

#include <string>
#include <iostream>

using namespace std;

class Expression{
public:
	virtual ~Expression(){}

	virtual void toString(int){};

};

class algExpression: public Expression{
public:

	bool unary;
	string operador;
	string id;
	algExpression *right;
	algExpression *left;
	int val;
	bool usesID;

	algExpression(string op, algExpression *l,algExpression *r): operador(op), left(l),right(r){
		usesID = false;
		unary = false;
	}

	algExpression(int v){
		left = NULL;
		right = NULL;
		operador = "NULL";
		val = v;
		usesID= false;
		unary = false;
	}

	algExpression(string s):id(s){
		left = NULL;
		right = NULL;
		operador = "NULL";
		usesID = true;
		unary = false;
	}

	algExpression(string op, algExpression *l):operador(op),left(l){
		unary = true;
		usesID = false;
	}

	void toString(int i){
		if (operador == "NULL"){
			if (usesID){
				cout << id << endl;
			}
			else{
				cout << val << endl;
			}
			return;
		}
		if (unary){
		
			cout << "Tipo: Unaria Algebraica." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}	
			cout << "operacion: Resta." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operador unico: ";
			left->toString(i+1);
		}
		else{
			cout << "Tipo: Binaria Algebraica." << endl;
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

class boolExpression: public Expression{
public:
	bool unary;
	string operador;
	boolExpression *lBool;
	boolExpression *rBool;
	bool val;
	string id;
	bool usesID;

	algExpression *rAlg;
	algExpression *lAlg;	

	boolExpression(string op, boolExpression *l, boolExpression *r):operador(op),lBool(l),rBool(l){
		usesID = false;
		rAlg = NULL;
		lAlg = NULL;
		unary = false;
	}

	boolExpression(string op, algExpression *l, algExpression *r): operador(op), rAlg(r), lAlg(l){
		lBool = NULL;
		usesID = false;
		unary = false;
	}

	boolExpression(string op, boolExpression *l):operador(op), lBool(l){
		unary = true;
		usesID = false;
	}

	boolExpression(bool r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;
		usesID = false;
		val = r;
		unary = false;
		operador = "NULL";
	}

	boolExpression(string r): id(r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;
		usesID = true;
		unary = false;
		operador = "NULL";
	}

	void toString(int i){
		if (operador == "NULL"){
			if (usesID){
				cout << id <<endl;
			}
			else{
				cout << val <<endl;
			}
			return;
		}
		if (unary){
		
			cout << "Tipo: Unaria Booleana." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}	
			cout << "operacion: Negacion." << endl;

			for (int j = 0; j < i;j++){
				cout <<"	";
			}
			cout << "operador unico: ";
			lBool->toString(i+1);
		}
		else{

			if (lBool != NULL){
				cout << "Tipo: Binaria Booleana." << endl;

				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operacion: " << operador << endl;

				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operador izquierdo: ";
				lBool->toString(i+1);

				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operador Derecho: ";
				rBool->toString(i+1);
			}
			else{
				cout << "Tipo: Binaria Relacional." << endl;
				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operacion: " << operador << endl;
				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operador izquierdo: ";
				lAlg->toString(i+1);

				for (int j = 0; j < i;j++){
					cout <<"	";
				}
				cout << "operador Derecho: ";
				rAlg->toString(i+1);

			}
		}
	}

};

#endif