#include "Robot.c"
#include <string>
#include <map>
#include <vector>


using namespace std;

/* Esto esta declarado en robot.c

union valores{
	int num;
	bool booleano;
	char caracter;
};

*/


class MapaRobots{
public:
	vector< map<string, Robot> > listMapas;
	int nivel;
	int currsize;
	MapaRobots(){
		nivel = 1;
		currsize = 16; // Tama;o inicial
		listMapas.resize(currsize);
	}

	~MapaRobots(){
		for (int i = 0; i < listMapas.size(); i++){
			listMapas[i].clear();
		}
		listMapas.clear();
	}

	void nuevoNivel(){
		nivel++;
		if (nivel == currsize){
			currsize = 2*currsize;
			listMapas.resize(currsize);
		}
	}

	bool subirNivel(){
		if (nivel == 1){
			return false;
		}
		else{
			listMapas[nivel - 1].clear();
			nivel--;
			return true;
		}
	}

	bool estaDeclarado(string s){
		if (listMapas[nivel - 1].find(s) != listMapas[nivel - 1].end()){
			return true; 
		}
		return false;
	}

	Robot* obtenerRobot(string s){
		for (int i = nivel-1; i >= 0; i--){
			if (listMapas[i].find(s) != listMapas[i].end()){
				return &listMapas[i][s]; 
			}
		}
		return NULL;
	}

	int obtenerTipo(string s){
		for (int i = nivel - 1; i >= 0;i--){
			if (listMapas[i].find(s) != listMapas[i].end()){
				return listMapas[i][s].obtenerTipo();
			}
		}
		return -1;
	}

	valores obtenerValor(string s){
		for (int i = nivel-1; i >= 0; i--){
			if (listMapas[i].find(s) != listMapas[i].end()){
				return listMapas[i][s].obtenerValor(); 
			}
		}
	}

	void agregar(string s,Robot r){
		if (!estaDeclarado(s)){
			listMapas[nivel-1][s] = r;
		}
	}


}