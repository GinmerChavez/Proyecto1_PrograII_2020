#pragma once
#include <string>

class IMaquinaVendedora
{
public:
	virtual string getNombre() = 0;
	virtual string realizarCompra(string id, int cantidad, int montoPago) = 0;
	virtual string toString() = 0;
};
