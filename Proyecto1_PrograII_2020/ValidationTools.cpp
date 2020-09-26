#include "ValidationTools.h"

string leerCadena()
{
	string x;
	cin.ignore(1024, '\n');
	getline(cin, x);
	return x;
}

int leerEntero()
{
	int n;
	bool continuar = true;
	while (true)
	{
		if (cin >> n) {
			cin.clear(); // Limpia el estado del flujo..
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto..Por favor, ingrese un numero entero." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}
