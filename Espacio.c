#ifndef espacio_h
#define espacio_h

#include <map>
#include "Tipo.c"

using namespace std;

/* Basicamente una matriz (representada por un mapa para simular infinito espacio) 
que apunta a un "Tipo". este "Tipo" puede ser un caracter, entero o booleano, y de el se
puede saber que es lo que contiene. */
class Espacio{

	map<int,map<int, Tipo >> Matriz;

	Espacio(){
		Matriz.clear();
	}

	int obtenerTipo(int x, int y){
		return Matriz[x][y].obtenerTipo;
	}

	int obtener


};




#endif