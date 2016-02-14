#include <string>

using namespace std;


class Expression{
public:
	virtual ~Expression(){}

	virtual void toString(){};

};

class algExpression: public Expression{


	bool unary = true;
	string operador;
	string rId;
	algExpression *left;
	int rInt;
	bool usesID;

	algExpression(string op, algExpression *l,int r): operador(op), left(l){
		usesID = false;
		rInt = r;
	}

	algExpression(string op, algExpression *l,string r): operador(op), rId(r), left(l){
		usesID = true;
	}

	algExpression(int v){
		left = NULL;
		operador = "NULL";
		rInt = v;
		usesID= false;
	}

	algExpression(string id):rId(id){
		left = NULL;
		operador = "NULL";
		usesID = true;
	}

	algExpression(string op, algExpression *l):operador(op),left(l){
		unary = true;
		usesID = false;
	}
};

class boolExpression: public Expression{
public:
	bool unary = false;
	string operador;
	boolExpression *lBool;
	bool boolvalue;
	string idvalue;
	bool usesID;

	algExpression *rAlg;
	algExpression *lAlg;	

	boolExpression(string op, boolExpression *l, bool r):operador(op),lBool(l){
		boolvalue = r;
		usesID = false;
		rAlg = NULL;
		lAlg = NULL;
	}

	boolExpression(string op, boolExpression *l, string id):operador(op),  lBool(l), idvalue(id){
		rAlg = NULL;
		lAlg = NULL;
		usesID = true;
	}

	boolExpression(string op, algExpression *l, algExpression *r): operador(op), rAlg(r), lAlg(l){
		lBool = NULL;
		usesID = false;
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
	}

	boolExpression(string r): idvalue(r){
		lBool = NULL;
		rAlg = NULL;
		lAlg = NULL;
		usesID = true;
	}

};
