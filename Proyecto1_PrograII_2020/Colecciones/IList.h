#pragma once
#include <iostream>
#include <sstream>
#include "ObjetoBase.h"
#include "IReadOnlyCollection.h"

using namespace std;

class IList : public IReadOnlyCollection
{
public:
	virtual void insertarAlFinal(ObjetoBase* elemento) = 0;
	virtual void insertarEnPosicion(ObjetoBase* elemento, int posicion) = 0;
	virtual void borrarEnPosicion(int posicion, bool liberarMemoria = false) = 0;
	virtual void liberarDatosInternos() = 0;
	virtual ~IList() = default;
};