#pragma once
#include"IIterador.h"
#include"Nodo.h"

class IteradorLinkedList : public IIterador
{
private:
	Nodo* punteroActual;

public:
	IteradorLinkedList(Nodo* inicial);
	virtual bool haySiguiente() override;
	virtual ObjetoBase* actual() override;
};