#ifndef arbolsint_h
#define arbolsint_h

#include "declaraciones.c"
#include "instrucciones.c"
#include <iostream>
using namespace std;

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;
	int lineNo;


	ArbolSintactico(Declaracion *l, Instruccion *r,int line): left(l),right(r){
		lineNo = line;
	};

	bool evaluar(){
		EspacioMovimientos Matriz = EspacioMovimientos();

		if (left->evaluar(MapaRobots)){
			return right->evaluar(MapaRobots,Matriz);

			obtener
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