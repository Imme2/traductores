#include <string>
#include <iostream>
#include <map>
#define ERRORTIPO -2
#define TIPOBOOL 0
#define TIPOINT 1
#define TIPOCHAR 2
#define TIPOID 3


using namespace std;



class InstruccionRobot{
	virtual ~InstruccionRobot(){}

	virtual bool verificar(MapaDeTipos&,int){}

	virtual void toString(int){}
};

class SecuenciaRoboInstruccion: InstruccionRobot{
public:
	InstruccionRobot *right;
	InstruccionRobot *left;

	SecuenciaDeclaraciones(InstruccionRobot* l,InstruccionRobot* r): left(l),right(r){} 

	SecuenciaDeclaraciones(InstruccionRobot* l): left(l){
		right = NULL;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){

		if (right == NULL){
			return left->verificar(mapa,tipo);
		}
		else{
			return left->verificar(mapa,tipo) and right->verificar(mapa,tipo);
		}

	}

	void toString(int i){
		;
	}

};

class Almacenamiento: public InstruccionRobot{
public:

	Expresion* expr; //verificar que tipo = tipo del robot

	Almacenamiento(Expresion* e):expr(e){}

	bool verificar(MapaDeTipos& mapa, int tipo){
		int aux = expr->CalcularTipo(mapa,tipo);
		if (aux == tipo){
			return true
		}
		else if (aux == ERRORTIPO){
			return false
		}
		else{
			cout << "Error en instruccion Store." << endl;
			cout << "Razon: Expresion es de tipo";
			if (aux == TIPOBOOL){
				cout << " Booleano ";
			}
			if (aux == TIPOINT){
				cout << " Entero ";
			}
			if (aux == TIPOCHAR){
				cout << " Caracter ";
			}

			cout << "y se esperaba un tipo"

			if (tipo == TIPOBOOL){
				cout << " Booleano ";
			}
			if (tipo == TIPOINT){
				cout << " Entero ";
			}
			if (tipo == TIPOCHAR){
				cout << " Caracter ";
			}			
			cout << Endl;
			return false
		}
	}
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

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tieneId){								// En caso de tener un id solo debemos verificar 
			if (mapa.estaDeclarado(identificador)){ // Que la variable no este declarada

				cout << "Error en instruccion collect." << endl;
				cout << "Razon: La variable " << identificador << " ya fue declarada" << endl; 

				return false
			}
			else{
				// En el caso de que la variable no este declarada solo la declaramos
				// y retornamos true
				mapa.agregar(identificador,tipo);
				return true;
			}
		}
		else{
			return true;	// En el caso de que no tenga un identificador, no se va a 
							// lanzar ningun error estatico.
		}
	}
};

class Soltado: public InstruccionRobot{
public:
	Expresion* expr;

	Soltado(Expresion* e): expr(e){}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (expr->CalcularTipo(mapa,tipo) == ERRORTIPO){ //Si encontramos un error de tipo
			return false // solo fallamos pues el responsable del mensaje es la expresion
		}
		else{
			return true;
		}
	}
};

class Movimiento: public InstruccionRobot{
public:

	int direccion;
	Expresion* expr;

	Movimiento(int d, Expresion* e): expr(e){
		direccion = d;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		int aux = expr->CalcularTipo(mapa,tipo)
		if (aux == TIPOINT){
			return true // En este caso todo va bien
		}
		else if (aux == ERRORTIPO){
			return false; // En un error del tipo, el warning es responsabilidad de la expresion
		}
		else{
			// Debemos imprimir el error.
			cout << "Error en instruccion Move." << endl;
			cout << "Razon: La expresion debe ser de tipo entero y es de tipo ";

			if (aux == TIPOBOOL){
				cout << "Booleano.";
			}
			else if (aux == TIPOCHAR){
				cout << "Caracter.";
			}
			cout << endl;
			return false;
		}
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

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tieneId){								// En caso de tener un id solo debemos verificar 
			if (mapa.estaDeclarado(identificador)){ // Que la variable no este declarada

				cout << "Error en instruccion collect." << endl;
				cout << "Razon: La variable " << identificador << " ya fue declarada" << endl; 

				return false
			}
			else{
				// En el caso de que la variable no este declarada solo la declaramos
				// y retornamos true
				mapa.agregar(identificador,tipo);
				return true;
			}
		}
		else{
			return true;	// En el caso de que no tenga un identificador, no se va a 
							// lanzar ningun error estatico.
		}
	}


};

class Escribir: public InstruccionRobot{
public:

	Escribir(){}

	bool verificar(MapaDeTipos& mapa, int tipo){
		//Esto no genera ningun error estatico.
		return true;
	}
};


class Comportamiento{
public:
	int tipoCondicion; 	// 0 al 3
						// 0 => Expresion
						// 1 => activacion
						// 2 => desactivacion
						// 3 => default
	Expresion* expr;
	SecuenciaRoboInstruccion* secRoboInst;

	Comportamiento(int t,Expresion* e, SecuenciaRoboInstruccion* secinst): expr(e), secRoboInst(sec){
		tipoCondicion = t;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tipo == 0){
			if (expr->getTipo(mapa,tipo) != 0){
				cout << "Error en condicion de comportamiento del robot." << endl;
				cout << "Razon: Tipo de expresion no es booleano." << endl;
				return false;
			}
			return secRoboInst->verificar(mapa,tipo);
		}
	}

};

class SecuenciaComportamiento{
public:

	SecuenciaComportamiento *right;
	Comportamiento *left;

	SecuenciaComportamiento(Comportamiento* l,SecuenciaComportamiento* r): left(l),right(r){} 

	SecuenciaComportamiento(Comportamiento* l): left(l){
		right = NULL;
	}

	vector<int> obtenerComportamientos(){
		SecuenciaComportamiento *aux = right;
		vector<int> tiposdeComp;
		tiposdeComp.push_back(left->tipoCondicion);

		while (aux != NULL){
			tiposdeComp.push_back(aux->left->tipoCondicion);
			aux = aux->right;
		}

		return tiposdeComp;

	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (right == NULL){
			return left->verificar(mapa,tipo);
		}
		else{
			return left->verificar(mapa,tipo) and right->verificar(mapa,tipo);
		}
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
		vector<int> comps = comportamiento->obtenerComportamientos();

		for (int i = 0; i < aux.size(); i++){
			if (mapa.estaDeclarado(aux[i])){
				cout << "Error declarando " << aux[i] << endl;
				cout << "Razon: Ya esta declarado" << endl;
				return false;
			}
		}


		bool act = false,deact = false;

		for (int i = 0; i < comps.size(); i++){
			if (comps[i] == 1){
				if (act){
					cout << "Error en comportamientos de "
					for (int i = 0; i < aux.size();i++){
						cout << aux[i] << " ";
					}
					cout << endl;
					cout << "Razon: mas de un comportamiento de activacion" << endl;
					return false;
				}
				else{
					act = true;
				}
			}
			if (comps[i] == 2){
				if (deact){
					cout << "Error en comportamientos de "
					cout << aux[0]
					for (int i = 1; i < aux.size();i++){
						cout << aux[i] << " ";
					}
					cout << << endl;
					cout << "Razon: mas de un comportamiento de desactivacion." << endl;
					return false;
				}
			}
			if (comps[i] == 3 and i != comps.size() - 1){
				cout << "Error en comportamientos de "
				for (int i = 0; i < aux.size();i++){
					cout << aux[i] << " ";
				}
				cout << endl;
				cout << "Razon: Comportamiento \"default\" debe ser el ultimo."  << endl;
				return false;
			}

		}


		return comportamiento->verificar(mapa,tipo);
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
			left->declararRobots(PrincMap);
			return right->verificar(PrincMap); // Verificamos los tipos.
		}
		return false;
	}

	void toString(int i){
		right->toString(i);
	}

};