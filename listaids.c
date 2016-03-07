#ifndef listaids_h
#define listaids_h

#include <string>
#include <vector>
#include <iostream>

using namespace std;



// Una simple clase que hace una lista de Ids en forma de arbol

class ListaIDs {
public:

	ListaIDs *left;
	string right;

	//Caso recursivo

	ListaIDs(ListaIDs *l, string r): left(l), right(r){}

	//Caso base

	ListaIDs(string r): right(r){
		left = NULL;
	}

	vector<string> obtenerIds(){
		ListaIDs *aux = left;
		vector<string> ids;
		ids.push_back(right);
		while(aux != NULL){
			ids.push_back(aux->right);
			aux = aux->left;
		}
		return ids;
	}

	//Toma ventaja de la estructura de arbol para imprimir
	void toString(){
		if (left != NULL){
			left->toString();
			cout << ", " << right; 
		}
		else{
			cout << right;
		}
	}
};

#endif