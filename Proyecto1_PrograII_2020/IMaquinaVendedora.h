#pragma once
#include<iostream>
#include<string>
#include"Producto.h"
using namespace std;

class IMaquinaVendedora
{
public:
	virtual string getNombre() = 0;
	virtual string realizarCompra(string id, int cantidad, int montoPago) = 0;
	virtual string toString() = 0;
	virtual Producto* mostrarProducto(string id) = 0;
};
