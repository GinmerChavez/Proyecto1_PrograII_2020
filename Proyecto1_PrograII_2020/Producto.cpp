#include "Producto.h"

Producto::Producto()
{
	this->nombre = "Sin nombre";
	this->precio = 0;
	this->cantidad = 0;
}

Producto::Producto(string nombre, int precio, int cantidad)
{
	this->nombre = nombre;
	this->precio = precio;
	this->cantidad = cantidad;
}

string Producto::getNombre() const { return nombre; }
void Producto::setNombre(string nombre) { this->nombre = nombre; }
void Producto::setPrecioBase(int precio) { this->precio = precio; }
int Producto::getCantidad() const { return cantidad; }
void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }

Producto::~Producto()
{
}

string Producto::toString()
{
	stringstream s;
	s << "Nombre del producto: " << this->nombre << endl;
	s << "Precio base: " << this->precio << endl;
	s << "Cantidad en existencia: " << this->cantidad << endl;
	return s.str();
}
