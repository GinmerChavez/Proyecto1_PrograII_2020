#pragma once
#include "fecha.h"
#include "Producto.h"


class ProductoPerecedero : public Producto
{
private:
	fecha* fechaDeVencimiento;

public:
	ProductoPerecedero(string, int, int, fecha*);
	virtual toString();
	virtual ~ProductoPerecedero();

	// Inherited via Producto
	virtual int getPrecioBase() override;
	virtual int getPrecio() override;
};
