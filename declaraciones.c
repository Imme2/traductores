#ifndef declaraciones_h
#define declaraciones_h

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "mapa.c"
#include "expresion.c"
#include "listaids.c"
#include "MapaRobots.c"
#include "Robot.c"
#include "valores.c"
#include "Espacio.c"

#define ERRORTIPO -2
#define TIPOBOOL 0
#define TIPOINT 1
#define TIPOCHAR 2
#define TIPOID 3


using namespace std;



class InstruccionRobot{
public:

	virtual ~InstruccionRobot(){}

	virtual bool verificar(MapaDeTipos&,int){}

	virtual bool ejecutar(Robot*,MapaRobots&, Espacio&, map<string,Valores>&){}

	virtual void toString(int){}
};

class SecuenciaRoboInstruccion: public InstruccionRobot{
public:
	InstruccionRobot *right;
	InstruccionRobot *left;
	int lineNo;

	SecuenciaRoboInstruccion(InstruccionRobot *l,InstruccionRobot *r, int line): left(l),right(r){
		lineNo = line;
	} 

	SecuenciaRoboInstruccion(InstruccionRobot *r,int line): right(r){
		lineNo = line;
		left = NULL;
	}

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		if (left == NULL){
			right->ejecutar(bot,mapa,space,tablasimb)
		}
		else{
			left->ejecutar(bot,mapa,space,tablasimb);
			right->ejecutar(bot,mapa,space,tablasimb);
		}


		return true; // Cualquier error en este punto saldra del programa.
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (left == NULL){
			return right->verificar(mapa,tipo);
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

	Expresion* expr;
	int lineNo;

	Almacenamiento(Expresion* e, int line):expr(e){
		lineNo = line;
	}

	// Necesitamos verificar que el tipo de la expresion es el mismo que el robot

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores> tablasimb){
		bot->valor = expr->evaluar(bot,mapa,space,tablasimb);
		return true;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		int aux = expr->calcularTipo(mapa,tipo);
		if (aux == tipo){
			return true;
		}
		else if (aux == ERRORTIPO){
			return false;
		}
		else{
			cout << "Error en instruccion Store. Linea " << lineNo << "." << endl;
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

			cout << "y se esperaba un tipo";

			if (tipo == TIPOBOOL){
				cout << " Booleano ";
			}
			if (tipo == TIPOINT){
				cout << " Entero ";
			}
			if (tipo == TIPOCHAR){
				cout << " Caracter ";
			}			
			cout << endl;
			return false;
		}
	}
};

class Coleccion: public InstruccionRobot{
public:

	string identificador;
	bool tieneId;
	int lineNo;

	Coleccion(string id,int line):identificador(id){
		tieneId = true;
		lineNo = line;
	}

	Coleccion(int line){
		lineNo = line;
		tieneId = false;
	}

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		if (space.existePos(bot->posx,bot->posy){
			if (space.obtenerTipo(bot->posx,bot->posy) == bot->tipo){
				if (tieneId){
					tablasimb[identificador] = space.obtenerValor(bot->posx,bot->posy);
				}
				else{
					bot->valor = space.obtenerValor(bot->posx,bot->posy);
				}
				space.borrarValor(box->posx,bot->posy);
				return true;
			}
			else{
				cout << "Error en linea " << lineNo << ": Coleccion de valor que no es del mismo tipo que el robot." << endl;
				exit(0);
			}
		}
		else{
			cout << "Error en linea " << lineNo << ": Coleccion en posicion vacia de la matriz." << endl;
			exit(0);
		}
	}


	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tieneId){								// En caso de tener un id solo debemos verificar 
			if (mapa.estaDeclarado(identificador)){ // Que la variable no este declarada

				cout << "Error en instruccion collect. Linea " << lineNo << "." << endl;
				cout << "Razon: La variable " << identificador << " ya fue declarada" << endl; 

				return false;
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
	int lineNo;

	Soltado(Expresion* e,int line): expr(e){
		lineNo = line;
	}

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		space.insertarValor(bot->x,bot->y,expr->evaluar(bot,mapa,space,tablasimb));
		return true;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (expr->calcularTipo(mapa,tipo) == ERRORTIPO){ //Si encontramos un error de tipo
			return false; // solo fallamos pues el responsable del mensaje es la expresion
		}
		else{
			return true;
		}
	}
};

class Movimiento: public InstruccionRobot{
public:

	int direccion; 	//Up = 0
				   	//Down =  1
					//Left =  2
					//Right = 3
	Expresion* expr;
	int lineNo;

	Movimiento(int d, Expresion* e,int line): expr(e){
		direccion = d;
		lineNo = line;
	}

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		int aux;
		aux = expr->evaluar(bot,mapa,space,tablasimb);
		if (aux < 0){
			cout << "Error: Intento de movimiento negativo en linea " << lineNo << "." << endl;
			exit(0);
		}
		if (direccion == 0){
			bot->posy += aux;
		}
		else if (direccion == 1){
			bot->posy -= aux;
		}
		else if (direccion == 2){
			bot->posx -= aux;
		}
		else if (direccion == 3){
			bot->posx += aux;
		}
		return true;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		int aux = expr->calcularTipo(mapa,tipo);
		if (aux == TIPOINT){
			return true; // En este caso todo va bien
		}
		else if (aux == ERRORTIPO){
			return false; // En un error del tipo, el warning es responsabilidad de la expresion
		}
		else{
			// Debemos imprimir el error.
			cout << "Error en instruccion Move. Linea " << lineNo << "." << endl;
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
	int lineNo;
	Leer(string id,int line):identificador(id){
		tieneId = true;
		lineNo = line;
	}

	Leer(int line){
		lineNo = line;
		tieneId = false;
	}


	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		string aux;
		cin >> aux;
		if (bot->tipo == TIPOBOOL){
			if (aux == "True" or aux == "1" or aux == "Verdadero" or aux == "true"){
				if (tieneId){
					tablasimb[identificador] = true;
				}
				else{
					bot->valor = true;
				}
			}
			else{ 			// Cualquier cosa que no sea true la consideramos como false.
				if (tieneId){
					tablasimb[identificador] = false;
				}
				else{
					bot->valor = false;
				}
			}
		}
		if (bot->tipo == TIPOINT){
			long int aux2 = strtol(aux);
			if (aux2 == 0 and aux != "0"){
				cout << "Error: " << aux << " no es un entero valido" << endl;
				exit(0);
			}
			else if (aux2 > (1<<31 - 1) or aux2 < -(1<<31)){
				cout << "Error: " << aux2 << " es un entero demasiado grande para representar" << endl;
				cout << "Nota: Esto es C++, no te puedo dar ints infinitos" << endl;
				exit(0);
			}
			else{
				if (tieneId){
					tablasimb[identificador] = aux2;
				}
				else{
					bot->valor = aux2;
				}
			}
		}
		if (bot->tipo == TIPOCHAR){
			if (aux.size() != 1){
				cout << "Error: " << aux << " no es un solo caracter." << endl;
				exit(0);
			}
			else{
				if (tieneId){
					tablasimb[identificador] = aux;
				}
				else{
					bot->valor = aux;
				}
			}
		}
		return true;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tieneId){								// En caso de tener un id solo debemos verificar 
			if (mapa.estaDeclarado(identificador)){ // Que la variable no este declarada

				cout << "Error en instruccion collect. Linea " << lineNo << "." << endl;
				cout << "Razon: La variable " << identificador << " ya fue declarada" << endl; 

				return false;
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

	int lineNo;

	Escribir(int line){
		lineNo = line;
	}

	bool ejecutar(Robot* bot,MapaRobots& mapa, Espacio& space, map<string,Valores>& tablasimb){
		cout << bot->obtenerValor() << endl;
	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		//Esto no genera ningun error estatico.
		return true;
	}
};

class Comport{
public:
	virtual ~Comport(){}

	virtual bool activar(Robot*,MapaRobots&,Espacio&){}
	
	virtual bool desactivar(Robot*,MapaRobots&,Espacio&){}

	virtual bool avanzar(Robot*,MapaRobots&,Espacio&){}

	virtual bool verificar(MapaDeTipos&,int){}


};


class Comportamiento: public Comport{
public:
	int tipoCondicion; 	// 0 al 3
						// 0 => Expresion
						// 1 => activacion
						// 2 => desactivacion
						// 3 => default
	Expresion* expr;
	SecuenciaRoboInstruccion* secRoboInst;
	int lineNo;

	Comportamiento(int t,Expresion* e, InstruccionRobot* secinst, int line): expr(e){
		secRoboInst = (SecuenciaRoboInstruccion*)secinst;
		tipoCondicion = t;
		lineNo = line;
	}

	bool activar(Robot* bot,MapaRobots& mapa, Espacio& space){
		map<id,Valores> aux;
		if (tipoCondicion == 1){
			return secRoboInst->ejecutar(bot,mapa,space,aux);
		}
		return true;
	}

	bool desactivar(Robot* bot,MapaRobots& mapa, Espacio& space){
		if (tipoCondicion == 2){
			return secRoboInst->ejecutar(bot,mapa,space,aux);
		}
		return true;
	}

	bool avanzar(Robot* bot,MapaRobots& mapa, Espacio& space){
		map<id,Valores> aux;
		if (tipoCondicion == 3){
			secRoboInst->ejecutar(bot,mapa,space,aux);
			return true 
		}
		else if (tipoCondicion == 0){
			if (Expresion->evaluar(bot,mapa,space)){
				secRoboInst->ejecutar(bot,mapa,space,aux);
				return true;
			}
		}
		return false;
	}


	bool verificar(MapaDeTipos& mapa, int tipo){
		if (tipoCondicion == 0){
			if (expr->calcularTipo(mapa,tipo) != 0){
				cout << "Error en condicion de comportamiento del robot. Linea " << lineNo << "." << endl;
				cout << "Razon: Tipo de expresion no es booleano." << endl;
				return false;
			}
		}
		mapa.nuevoNivel();
		if (secRoboInst->verificar(mapa,tipo)){
			mapa.subirNivel();
			return true;
		}
		mapa.subirNivel();
		return false;

	}

};

class SecuenciaComportamiento: public Comport{
public:

	Comport *left;
	Comport *right;
	int lineNo;

	SecuenciaComportamiento(Comport* l,Comport* r,int line): left(l),right(r){
		lineNo = line;
	} 

	SecuenciaComportamiento(Comport* r,int line): right(r){
		left = NULL;
		lineNo = line;
	}

	// Funciones de activar y desactivar, solo buscan al comportamiento deseado y lo llaman

	bool activar(Robot* bot,MapaRobots& mapa, Espacio& space){
		if (left == NULL){
			return right->activar(bot,mapa,space);
		}
		else{
			if (left->activar(bot,mapa,space)){
				return right->activar(bot,mapa,space);
			}
		}
		return true;
	}


	bool desactivar(Robot* bot,MapaRobots& mapa, Espacio& space){
		if (left == NULL){
			return right->desactivar(bot,mapa,space);
		}
		else{
			if (left->desactivar(bot,mapa,space)){
				return right->desactivar(bot,mapa,space);
			}
		}
		return true;
	}

	// Funcion de avanzar, busca al primer comportamiento por profundidad.

	bool avanzar(Robot* bot,MapaRobots& mapa, Espacio& space){
		if (left == NULL){
			return right->avanzar(bot,mapa,space);
		}
		else{
			if (!left->avanzar(bot,mapa,space)){
				return right->avanzar(bot,mapa,space
			}
		}
		return true;
	}


	vector<int> obtenerComportamientos(){
		SecuenciaComportamiento *aux = (SecuenciaComportamiento*)left;
		vector<int> tiposdeComp;
		tiposdeComp.push_back(((Comportamiento*)right)->tipoCondicion);

		while(aux != NULL){
			tiposdeComp.insert(tiposdeComp.begin(),((Comportamiento*)aux->right)->tipoCondicion);
			aux = (SecuenciaComportamiento*)aux->left;
		}

		return tiposdeComp;

	}

	bool verificar(MapaDeTipos& mapa, int tipo){
		if (left == NULL){
			return right->verificar(mapa,tipo);
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

	virtual bool ejecutar(MapaRobots&){}

	virtual bool declararRobots(MapaDeTipos&){}

	virtual void toString(int){}

};

//Secuencia de Declaraciones para futuras entregas.

class SecuenciaDeclaraciones: public Declaracion{
public:

	Declaracion *right;
	Declaracion *left;
	int lineNo;

	SecuenciaDeclaraciones(Declaracion* l,Declaracion* r, int line): left(l),right(r){
		lineNo = line;
	} 

	SecuenciaDeclaraciones(Declaracion* r,int line): right(r){
		lineNo = line;
		left = NULL;
	}

	bool verificar(MapaDeTipos& mapa){

		if (left == NULL){
			return right->verificar(mapa);
		}
		else{
			return left->verificar(mapa) and right->verificar(mapa);
		}
	}

	// Ejecucion: Declaracion de los robots en el mapa

	bool ejecutar(MapaRobots& mapa){
		if (left == NULL){
			((DeclaracionRobot *)right)->ejecutar(mapa);
		}
		else{
			left->ejecutar(mapa);
			right->ejecutar(mapa);
		}

		return true; // No hay errores dinamicos que puedan pasar aqui
	}


	bool declararRobots(MapaDeTipos& mapa){
		SecuenciaDeclaraciones* aux = (SecuenciaDeclaraciones*)left;

		if (right->declararRobots(mapa)){
			while(aux != NULL){
				if (aux->right->declararRobots(mapa)){
					aux = (SecuenciaDeclaraciones*)aux->left;
				}
				else{
					return false;
				}
			}
			return true;
		}
		else{
			return false;
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
	Comport* comportamiento;
	int lineNo;


	DeclaracionRobot(int t,ListaIDs* l,Comport* comps, int line): ids(l), comportamiento(comps){
		tipo = t;
		lineNo = line;
	}

	bool declararRobots(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();
		for (int i = 0 ; i < aux.size(); i++){
			if (!mapa.estaDeclarado(aux[i])){
				mapa.agregar(aux[i],tipo);			// Agregamos todos al mapa si no estan en el.
			}
			else{
				cout << "Error al declarar robot " << aux[i] << " en Linea " << lineNo << "." << endl;
				cout << "Razon: El robot ya fue declarado" << endl;	//Si estan en el, solo
				return false;										// Reportamos el error y salimos.
			}
		}

		return true;
	}


	bool ejecutar(MapaRobots& mapa){
		vector<string> aux = ids->obtenerIds();
		for (int i = 0 ; i < aux.size(); i++){
			mapa.agregar(aux[i],Robot(tipo,(SecuenciaComportamiento*)comportamiento,aux[i]));
		}
		return true; // No hay errores dinamicos que puedan pasar aqui.
	}

	bool verificar(MapaDeTipos& mapa){
		vector<string> aux = ids->obtenerIds();
		vector<int> comps = ((SecuenciaComportamiento*)comportamiento) ->obtenerComportamientos();
		
		for (int i = 0; i < aux.size(); i++){
			if (mapa.estaDeclarado(aux[i])){
				cout << "Error declarando " << aux[i] << " en Linea " << lineNo << "." << endl;
				cout << "Razon: Ya esta declarado" << endl;
				return false;
			}
		}

		bool act = false,deact = false, def = false;
		for (int i = 0; i < comps.size(); i++){
			if (comps[i] == 1){
				if (act){
					cout << "Error en comportamientos de ";
					cout << aux[0];
					for (int i = 1; i < aux.size();i++){
						cout << " " << aux[i];
					}
					cout << " en Linea " << lineNo << "." <<endl;
					cout << "Razon: mas de un comportamiento de activacion" << endl;
					return false;
				}
				else{
					act = true;
				}
			}
			else if (comps[i] == 2){
				if (deact){
					cout << "Error en comportamientos de ";
					cout << aux[0];
					for (int i = 1; i < aux.size();i++){
						cout << " " << aux[i];
					}
					cout << " en Linea " << lineNo << "." <<endl;
					cout << "Razon: mas de un comportamiento de desactivacion." << endl;
					return false;
				}
				else{
					deact = true;
				}
			}
			else if (comps[i] == 3 and i != (comps.size() - 1)){
				if (def){
					cout << "Error en comportamientos de ";
					cout << aux[0];
					for (int i = 1; i < aux.size();i++){
						cout << " " << aux[i];
					}
						cout << " en Linea " << lineNo << "." <<endl;
					cout << "Razon: Solo puede haber un comportamiento \"default\"."  << endl;
					return false;
				}
				else{
					def = true
				}
			}
			else if (comps[i] == 0 and def){
				cout << "Error en comportamientos de ";
				cout << aux[0];
				for (int i = 1; i < aux.size();i++){
					cout << " " << aux[i];
				}
					cout << " en Linea " << lineNo << "." <<endl;
				cout << "Razon: Comportamiento \"default\" debe estar despues de todos los de las expresiones."  << endl;
				return false;
			}
		}
		return comportamiento->verificar(mapa,tipo);
	}
};


#endif