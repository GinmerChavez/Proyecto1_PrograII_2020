#include "Nodo.h"

Nodo::Nodo(ObjetoBase* dato, Nodo* siguiente)
{
	this->dato = dato;
	this->siguiente = siguiente;
}

ObjetoBase* Nodo::getDato() const
{
    return dato;
}

void Nodo::setDato(ObjetoBase* dato)
{
    this->dato = dato;
}

Nodo* Nodo::getSiguiente() const
{
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
    this->siguiente = siguiente;
}

