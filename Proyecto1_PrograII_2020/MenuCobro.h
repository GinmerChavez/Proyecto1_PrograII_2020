#pragma once
#include"IMaquinaVendedora.h"
#include "MonederoElectronico.h"

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
	void seleccionarProducto();
	void subMenuCompra(string id);
	MonederoElectronico* retornarMonedero();
};