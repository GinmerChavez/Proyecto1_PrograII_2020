#include "Bootstrapper.h"


void Bootstrapper::correrAplicacion()
{
	IList* lista = FabricaDeListas::crearLista();	//Patron Simple Factory
	MonederoElectronico* monedero = new MonederoElectronico();
	Maquina* maquina = new Maquina(12345, "expendedora", monedero, lista);

	MenuAdministrador* menuAdministrador = new MenuAdministrador(maquina);
	MenuCobro* menuCobro = new MenuCobro(maquina);
	MenuPrincipal* menuPrincipal = new MenuPrincipal(menuAdministrador, menuCobro);


	menuPrincipal->invocarMenu();
	
	delete maquina;
	delete menuPrincipal;
}
