#pragma once
#include"IMaquinaAdministradora.h"
#include"Producto.h"
#include"ProductoNoPerecedero.h"
#include"ProductoPerecedero.h"

class MenuAdministrador
{
private:
	IMaquinaAdministradora* maquinaAdministradora;
public:
	MenuAdministrador(IMaquinaAdministradora* maquinaAdministradora);
	void invocarMenu();
private:
	char mostrarOpciones();
	void insertar();
	void agregarProvisiones();
	void disminuirProvisiones();
	void borrarProducto();
	string consultar();
	void ingresarDinero();
	void retirarDinero();
	Producto* crearProducto();
};