#pragma once
#include <iostream>
#include <sstream>
#include"ObjetoBase.h"

using namespace std;

class Nodo
{
private:
	ObjetoBase* dato;
	Nodo* siguiente;

public:
	Nodo(ObjetoBase* dato, Nodo* siguiente);
    ObjetoBase* getDato() const;
    void setDato(ObjetoBase* dato);
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* siguiente);
};