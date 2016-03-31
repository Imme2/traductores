#ifndef arbolsint_h
#define arbolsint_h


#include "MapaRobots.c"
#include "Espacio.c"
#include "Robot.c"
#include "declaraciones.c"
#include "instrucciones.c"
#include <iostream>
#include "valores.c"
#include "Robot.c"

using namespace std;

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;
	int lineNo;


	ArbolSintactico(Declaracion *l, Instruccion *r,int line): left(l),right(r){
		lineNo = line;
	};

	bool ejecutar(){
		Espacio Matriz = Espacio();
		if (left->ejecutar(MapaRobots)){
			return right->ejecutar(Matriz,MapaRobots);
		}
	}


	bool verificar(){
		MapaDeTipos PrincMap = MapaDeTipos();

		if (left->verificar(PrincMap)){ // Verificamos las declaraciones 
			if (left->declararRobots(PrincMap)){ // Poblamos el mapa
				return right->verificar(PrincMap); // Verificamos los tipos en las instrucciones.
			}
		}
		return false;
	}

	void toString(int i){
		right->toString(i);
	}

};

#endif