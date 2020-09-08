#include "ProductoPerecedero.h"

ProductoPerecedero::ProductoPerecedero(string nombre, int precioBase, int cantidad, fecha* fechaDeVencimiento) : Producto(nombre, precioBase, cantidad)
{
	this->fechaDeVencimiento = fechaDeVencimiento;
}

ProductoPerecedero::~ProductoPerecedero()
{
}

int ProductoPerecedero::getPrecioBase()
{
	return this->precio;
}

int ProductoPerecedero::getPrecio()
{
	
}
