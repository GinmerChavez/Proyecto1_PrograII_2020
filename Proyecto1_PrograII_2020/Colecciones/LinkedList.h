#pragma once
#include <iostream>
#include <sstream>
#include "ObjetoBase.h"
#include "IList.h"
#include "Nodo.h"
#include "IteradorLinkedList.h"

using namespace std;

class LinkedList :public IList
{
private:
	Nodo* primero;
	int cantidad;
	void eliminarPrimero();
	void eliminarNodo(bool liberarMemoria, Nodo* eliminar);

public:
	LinkedList();
	void insertarAlFinal(ObjetoBase* elemento) override;	
	void insertarEnPosicion(ObjetoBase* elemento, int posicion) override;
	void borrarEnPosicion(int posicion, bool liberarMemoria = false) override;
	ObjetoBase* consultarPorPosicion(int posicion) override;
	bool contiene(ObjetoBase* elemento) override;
	int getCantidad() override;
	void liberarDatosInternos() override;
	string toString() override;
	IIterador* obtenerIterador() override;
	~LinkedList();
};