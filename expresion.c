#ifndef expression_h
#define expression_h

#include <string>

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
		;
	}
};

class boolExpression: public Expression{
public:
	bool unary;
	string operador;
	boolExpression *lBool;
	boolExpression *rBool;
	bool boolvalue;
	string idvalue;
	bool usesID;

	algExpression *rAlg;
	algExpression *lAlg;	

	boolExpression(string op, boolExpression *l, boolExpression *r):operador(op),lBool(l),rBool(l){
		boolvalue = r;
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
		boolvalue = r;
		unary = false;
	}

	boolExpression(string r): idvalue(r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;
		usesID = true;
		unary = false;
	}

	void toString(int i){
		;
	}

};

#endif