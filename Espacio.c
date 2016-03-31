#ifndef espacio_h
#define espacio_h

#include <map>
#include "Tipo.c"
#include "valores.c"

using namespace std;

/* Basicamente una matriz (representada por un mapa para simular infinito espacio) 
que apunta a un "Tipo". este "Tipo" puede ser un caracter, entero o booleano, y de el se
puede saber que es lo que contiene. */
class Espacio{
public:
	map<int,map<int, Tipo > > Matriz;

	Espacio(){
		Matriz.clear();
	}

	int obtenerTipo(int x, int y){
		return Matriz[x][y].obtenerTipo();
	}

	bool existePos(int x, int y){
		if (Matriz.find(x) != Matriz.end()){
			if (Matriz[x].find(y) != Matriz[x].end()){
				return true;
			}
		}
		return false;
	}

	Valores obtenerValor(int x,int y){
		return Matriz[x][y].obtenerValor();
	}

	void borrarValor(int x, int y){
		Matriz[x].erase(y);
		return;
	}

	void insertarValor(int x, int y,Valores v,int t){
		if (t == TIPOBOOL){
			Matriz[x].insert(pair<int,Tipo>(y,Tipo(v.booleano)));
		}
		else if (t == TIPOINT){
			Matriz[x].insert(pair<int,Tipo>(y,Tipo(v.num)));
		}
		else if (t == TIPOCHAR){
			Matriz[x].insert(pair<int,Tipo>(y,Tipo(v.caracter)));
		}
	}

};




#endif