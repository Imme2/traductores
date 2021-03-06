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
	int lineNo;

	//Caso recursivo

	ListaIDs(ListaIDs *l, string r, int line): left(l), right(r){
		lineNo = line;
	}

	//Caso base

	ListaIDs(string r, int line): right(r){
		lineNo = line;
		left = NULL;
	}

	vector<string> obtenerIds(){
		ListaIDs *aux = left;
		vector<string> ids;
		ids.insert(ids.begin(),right);
		while(aux != NULL){
			ids.insert(ids.begin(),aux->right);
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