#include <string>
#include <iostream>
#include <map>

using namespace std;
 

class InstruccionRobot{
	virtual ~InstruccionRobot(){}

	virtual bool verificar(MapaDeTipos&){}

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
	SecuenciaRoboInstruccion* secRoboInst;

	Comportamiento(int t,Expresion* e, SecuenciaRoboInstruccion* secinst): exp(e), secRoboInst(sec){
		tipoCondicion = t;
	}
};

class SecuenciaComportamiento{
public:

	Comportamiento *right;
	Comportamiento *left;

	SecuenciaComportamiento(Comportamiento* l,Comportamiento* r): left(l),right(r){} 

	SecuenciaComportamiento(Comportamiento* l): left(l){
		right = NULL;
	}

	vector<int> order


	bool verificar(MapaDeTipos& mapa){
		if (right == NULL){
			return left->verificar(mapa);
		}
		else{
			return left->verificar(mapa) and right->verificar(mapa);
		}
	}

	void toString(int i){
		;
	}

};

// clase virtual Declaracion para futuras entregas.

class Declaracion{
public:

	virtual ~Declaracion(){}

	virtual bool verificar(MapaDeTipos&){}

	virtual void toString(int){}

};

//Secuencia de Declaraciones para futuras entregas.

class SecuenciaDeclaraciones: public Declaracion{
public:

	Declaracion *right;
	Declaracion *left;

	SecuenciaDeclaraciones(Declaracion* l,Declaracion* r): right(r), left(l){} 

	SecuenciaDeclaraciones(Declaracion* l): left(l){
		right = NULL;
	}

	bool verificar(MapaDeTipos& mapa){
		if (right == NULL){
			return left->verificar(mapa);
		}
		else{
			return left->verificar(mapa) and right->verificar(mapa);
		}
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

	bool verificar(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();

		for (int i = 0; i < aux.size(); i++){
			if (mapa.estaDeclarado(aux[i])){
				cout << "Error declarando " << aux[i] << endl;
				cout << "Razon: Ya esta declarado" << endl;
				return false;
			}
			else{
				mapa.agregar(aux[i],tipo);
			}
		}
		return comportamiento->verificar();
	}
};




// Funcion principal del programa, que comienza el arbol

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;

	ArbolSintactico(Declaracion *l, Instruccion *r): left(l),right(r){};

	bool verificar(){
		MapaDeTipos PrincMap = MapaDeTipos();
		if (left->verificar(PrincMap)){ // Populamos el mapa
			return right->verificar(PrincMap); // Verificamos los tipos.
		}
		return false;
	}

	void toString(int i){
		right->toString(i);
	}

};
