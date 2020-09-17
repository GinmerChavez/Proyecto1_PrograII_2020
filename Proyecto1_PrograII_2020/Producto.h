#pragma once
#include <iostream>
#include <sstream>
#include "Colecciones/ObjetoBase.h"

using namespace std;

class Producto : public ObjetoBase
{
protected:
	string nombre;
	int precio;
	int cantidad;

public:
	Producto();
	Producto(string, int, int);
	Producto(const Producto& source) = delete;
	Producto& operator=(const Producto& source) = delete;

	string getNombre() const;
	void setNombre(string nombre);
	virtual int getPrecio() = 0;
	void setPrecioBase(int precio);
	int getCantidad() const;
	void setCantidad(int cantidad);

	virtual ~Producto();
	virtual string toString();
};

