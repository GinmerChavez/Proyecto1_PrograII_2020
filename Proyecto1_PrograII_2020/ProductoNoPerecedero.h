#pragma once
#include "Producto.h"

class ProductoNoPerecedero : public Producto
{
private:
	int porcentajeDeDescuento;

public:
	ProductoNoPerecedero(string, int, int, int);
	virtual ~ProductoNoPerecedero() override;
	virtual string toString();

	// Inherited via Producto
	virtual int getPrecio() override;

};