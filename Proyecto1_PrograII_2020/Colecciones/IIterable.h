#pragma once
#include"IIterador.h"
#include"ObjetoBase.h"

class IIterable : public ObjetoBase
{
public:
	virtual IIterador* obtenerIterador() = 0;
	~IIterable() = default;
};