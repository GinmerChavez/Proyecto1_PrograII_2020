#pragma once
#include "fecha.h"
#include "Producto.h"


class ProductoPerecedero : public Producto
{
private:
	Fecha* fechaDeVencimiento;

public:
	ProductoPerecedero(string, int, int, Fecha*);
	virtual string toString();
	virtual ~ProductoPerecedero();

	// Inherited via Producto
	virtual int getPrecio() override;
};
