#pragma once
#include"IIterador.h"

class IteradorArrayList : public IIterador
{
private:
	ObjetoBase** arreglo;
	int cantidad;
	int posicionActual;

public:
	IteradorArrayList(ObjetoBase** arreglo, int cantidad);
	virtual bool haySiguiente() override;
	virtual ObjetoBase* actual() override;
};