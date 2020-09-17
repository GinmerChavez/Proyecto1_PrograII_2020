#pragma once
#include"ObjetoBase.h"
#include"IIterable.h"

class IReadOnlyCollection : public IIterable
{
public:
	virtual ObjetoBase* consultarPorPosicion(int posicion) = 0;
	virtual bool contiene(ObjetoBase* elemento) = 0;
	virtual int getCantidad() = 0;
	virtual ~IReadOnlyCollection() = default;
};