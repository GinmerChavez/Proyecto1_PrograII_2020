#include "IteradorArrayList.h"

IteradorArrayList::IteradorArrayList(ObjetoBase** arreglo, int cantidad)
{
	this->arreglo = arreglo;
	this->cantidad = cantidad;
	this->posicionActual = 0;
}

bool IteradorArrayList::haySiguiente()
{
	if (this->posicionActual >= this->cantidad)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// 1 - Guardo el elemento actual
// 2 - Avanzo en la posición actual
// 3 - Retorno el elemento guardado

ObjetoBase* IteradorArrayList::actual()
{
	if (this->haySiguiente()) {
		ObjetoBase* dato = this->arreglo[this->posicionActual];
		this->posicionActual++;
		return dato;
	}
	return nullptr;
}

