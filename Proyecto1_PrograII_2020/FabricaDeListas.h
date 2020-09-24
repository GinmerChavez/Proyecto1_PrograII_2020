#pragma once
#include "Colecciones/IList.h"
#include "Colecciones/ArrayList.h"
#include "Colecciones/LinkedList.h"

enum class TipoLista
{
	ArrayList,
	LinkedList
};

class FabricaDeListas
{
public:
	static IList* crearLista(TipoLista tipo = TipoLista::ArrayList);
};