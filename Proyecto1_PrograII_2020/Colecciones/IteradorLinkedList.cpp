#include "IteradorLinkedList.h"

IteradorLinkedList::IteradorLinkedList(Nodo* inicial)
{
	this->punteroActual = inicial;
}

bool IteradorLinkedList::haySiguiente()
{
	return this->punteroActual != nullptr;
}

ObjetoBase* IteradorLinkedList::actual()
{
	if (this->haySiguiente())	
	{
		ObjetoBase* dato = this->punteroActual->getDato();
		this->punteroActual = this->punteroActual->getSiguiente();
		return dato;
	}
	return nullptr;
}
