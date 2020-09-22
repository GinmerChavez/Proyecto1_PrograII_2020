#include "Bootstrapper.h"


void Bootstrapper::correrAplicacion()
{
	IList* lista = new ArrayList(8); // Aqui deberiamos hacer una fabrica de listas??
	MonederoElectronico* monedero = new MonederoElectronico();
	
	IMaquinaAdministradora* maquinaAdministradora = new Maquina(12345, "Expendedora", monedero, lista);
	IMaquinaVendedora* maquinaVendedora = new Maquina(12345, "Expendedora", monedero, lista);
	
	MenuAdministrador* menuAdministrador = new MenuAdministrador(maquinaAdministradora);
	MenuCobro* menuCobro = new MenuCobro(maquinaVendedora);
	MenuPrincipal* menuPrincipal = new MenuPrincipal(menuAdministrador, menuCobro);


	menuPrincipal->invocarMenu();

	delete menuPrincipal;

	//Faltan destructores
}
