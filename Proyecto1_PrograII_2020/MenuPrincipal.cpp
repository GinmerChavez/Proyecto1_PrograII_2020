#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(MenuAdministrador* menuAdministrador, MenuCobro* menuCobro)
{
	this->menuAdministrador = menuAdministrador;
	this->menuCobro = menuCobro;
}

void MenuPrincipal::invocarMenu()
{
	const char opcionSalida = '3';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->menuAdministrador->invocarMenu();
			break;
		case '2':
			this->menuCobro->invocarMenu();
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

MenuPrincipal::~MenuPrincipal()
{
	delete menuAdministrador;
	delete menuCobro;
}

char MenuPrincipal::mostrarOpciones()
{
	char opcion;
	system("cls");
	cout << "Menu Principal - Seleccionar una opcion:" << endl;
	cout << "1) Menu Administrador" << endl;
	cout << "2) Menu Cobros" << endl;
	cout << "3) Salir" << endl;
	cin >> opcion;
	system("cls");
	return opcion;
}