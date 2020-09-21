#pragma once
#include"IMaquinaVendedora.h"

class MenuCobro
{
private:
	IMaquinaVendedora* maquinaVendedora;

public:
	MenuCobro(IMaquinaVendedora* maquinaVendedora);
	void invocarMenu();
private:
	char mostrarOpciones();
	string mostrarProductos();
	string seleccionarProducto();
	string subMenuCompra(string id);

};