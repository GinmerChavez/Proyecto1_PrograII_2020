#pragma once
#include"IMaquinaVendedora.h"
#include "MonederoElectronico.h"
#include "ValidationTools.h"

class MenuCobro
{
private:
	IMaquinaVendedora* maquinaVendedora;

public:
	MenuCobro(IMaquinaVendedora* maquinaVendedora);
	void invocarMenu();
private:
	char mostrarOpciones();
	void mostrarProductos();
	void seleccionarProducto();
	void subMenuCompra(string id);
	MonederoElectronico* retornarMonedero();
};