#include 


using namespace std;

extern arbolSintactico* raiz;
extern int yyparse();
extern vector<errToken> errores;


int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Numero de argumentos incorrecto, se esperaba 1 se recibieron %i\n",argc-1);
		return 0;
	}

	bool listo;
	listo = yyparse();
	if (listo){
		arbolSintactico.print();
	}
	else{
		printf("El archivo %s no parece existir o no se puede leer\n",argv[1]);
	}
	return 0;

}