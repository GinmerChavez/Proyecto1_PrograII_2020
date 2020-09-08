#include "ProductoNoPerecedero.h"

ProductoNoPerecedero::ProductoNoPerecedero(string nombre, int precio, int cantidad, int porcentajeDeDescuento) : Producto(nombre, precio, cantidad)
{
    this->porcentajeDeDescuento = porcentajeDeDescuento;
}

ProductoNoPerecedero::~ProductoNoPerecedero()
{
}

string ProductoNoPerecedero::toString()
{
    stringstream s;
    s << Producto::toString();
    s << "Porcentaje de descuento: " << this->porcentajeDeDescuento << endl;
    s << "Precio con descuento: " << this->getPrecio() << endl;
    return s.str();
}

int ProductoNoPerecedero::getPrecioBase()
{
    return this->precio;
}

int ProductoNoPerecedero::getPrecio()
{
    return (this->precio - (this->precio*this->porcentajeDeDescuento)/100);
}

