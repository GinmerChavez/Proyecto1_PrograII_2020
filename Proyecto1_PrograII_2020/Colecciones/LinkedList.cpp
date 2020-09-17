#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->primero = nullptr;
	this->cantidad = 0;
}

void LinkedList::insertarAlFinal(ObjetoBase* elemento)
{
	Nodo* nuevo = new Nodo(elemento, nullptr);

	if (this->primero == nullptr)
	{
		this->primero = nuevo;
	}
	else
	{
		Nodo* actual = this->primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	this->cantidad++;
}

void LinkedList::insertarEnPosicion(ObjetoBase* elemento, int posicion)
{
	if (posicion > this->cantidad)
	{
		cerr << "Posicion de insercion invalida" << endl;
		return;
	}

	Nodo* nuevo = new Nodo(elemento, nullptr);
	if (this->primero == nullptr)
	{
		this->primero = nuevo;
	}
	else
	{
		if (posicion == 0)
		{
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}
		else
		{
			Nodo* actual = this->primero;
			for (int i = 0; actual->getSiguiente() != nullptr && i < posicion - 1; i++)
			{
				actual = actual->getSiguiente();
			}
			nuevo->setSiguiente(actual->getSiguiente());
			actual->setSiguiente(nuevo);
		}
	}

	this->cantidad++;
}

void LinkedList::borrarEnPosicion(int posicion, bool liberarMemoria)
{
	if (this->primero == nullptr)
	{
		return;
	}
	else
	{
		Nodo* eliminar;
		if (posicion == 0)
		{
			eliminar = this->primero;
			this->primero = this->primero->getSiguiente();
			eliminarNodo(liberarMemoria, eliminar);
		}
		else
		{
			Nodo* actual = this->primero;
			for (int i = 0; actual->getSiguiente() != nullptr && i < posicion - 1; i++)
			{
				actual = actual->getSiguiente();
			}
			if (actual->getSiguiente() != nullptr)
			{
				eliminar = actual->getSiguiente();
				actual->setSiguiente(eliminar->getSiguiente());
				eliminarNodo(liberarMemoria, eliminar);
			}
		}
	}
}

void LinkedList::eliminarNodo(bool liberarMemoria, Nodo* eliminar)
{
	if (liberarMemoria && eliminar->getDato())
	{
		delete eliminar->getDato();
	}
	delete eliminar;
	this->cantidad--;
}

ObjetoBase* LinkedList::consultarPorPosicion(int posicion)
{
	Nodo* actual = this->primero;
	int i = 0;
	for (int i = 0; i < posicion && actual != nullptr; i++)
	{
		actual = actual->getSiguiente();
	}

	if (actual != nullptr)
	{
		return actual->getDato();
	}
	else
	{
		cerr << "Posicion invalida" << endl;
		return nullptr; // Posicion estaba fuera de los límites de la colección
	}
}

bool LinkedList::contiene(ObjetoBase* elemento)
{
	Nodo* actual = this->primero;
	while (actual != nullptr)
	{
		if (actual->getDato() == elemento)
			return true;
		actual = actual->getSiguiente();
	}
	return false;
}

int LinkedList::getCantidad()
{
	return this->cantidad;
}

string LinkedList::toString()
{
	stringstream s;
	Nodo* actual = this->primero;

	while (actual != nullptr)
	{
		if (actual->getDato())
		{
			s << actual->getDato()->toString() << endl;
		}
		actual = actual->getSiguiente();
	}

	return s.str();
}

IIterador* LinkedList::obtenerIterador()
{
	return new IteradorLinkedList(this->primero);
}


void LinkedList::liberarDatosInternos()
{
	while (primero != nullptr)
	{
		if (primero->getDato()) 
		{
			delete primero->getDato();
		}
		eliminarPrimero();
	}

	this->cantidad = 0;
}

LinkedList::~LinkedList()
{
	while (primero != nullptr)
	{
		eliminarPrimero();
	}
}

void LinkedList::eliminarPrimero()
{
	if (this->primero != nullptr)
	{
		Nodo* eliminado = primero;
		this->primero = this->primero->getSiguiente();
		delete eliminado;
	}
}