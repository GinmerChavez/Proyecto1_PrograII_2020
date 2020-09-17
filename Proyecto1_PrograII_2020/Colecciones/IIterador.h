#pragma once
#include"ObjetoBase.h"

class IIterador
{
public:
	virtual bool haySiguiente() = 0;
	virtual ObjetoBase* actual() = 0;
};