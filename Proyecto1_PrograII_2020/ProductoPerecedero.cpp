#include "ProductoPerecedero.h"

ProductoPerecedero::ProductoPerecedero(string nombre, int precioBase, int cantidad, Fecha* fechaDeVencimiento) : Producto(nombre, precioBase, cantidad)
{
	this->fechaDeVencimiento = fechaDeVencimiento;
}

string ProductoPerecedero::toString()
{
	stringstream s;
	s << Producto::toString();
	s << "Consumir preferiblemente antes de: " << fechaDeVencimiento->mostrarFecha() << endl;
	s << "Precio final: " << this->getPrecio() << endl;
	return s.str();
}

ProductoPerecedero::~ProductoPerecedero()
{
}


int ProductoPerecedero::getPrecio()
{
	int precioConDescuento = 0;
	Fecha* fechaActual = new Fecha();
	fechaActual->getFechaActual();
	double diasHastaCaducidad = Fecha::diferencia(this->fechaDeVencimiento, fechaActual);
	if (diasHastaCaducidad <= 7)
	{
		precioConDescuento = this->precio - (this->precio * 0.5);
	}
	else
	{
		precioConDescuento = this->precio;
	}
	return precioConDescuento;
}
