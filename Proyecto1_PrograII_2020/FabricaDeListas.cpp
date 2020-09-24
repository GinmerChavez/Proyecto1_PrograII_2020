#include "FabricaDeListas.h"


IList* FabricaDeListas::crearLista(TipoLista tipo)
{
	IList* nuevaLista = nullptr;

	switch (tipo)
	{
	case TipoLista::ArrayList:
		nuevaLista = new ArrayList(8);
		break;
	case TipoLista::LinkedList:
		nuevaLista = new LinkedList();
		break;
	default:
		nuevaLista = new ArrayList(8);
		break;
	}
	return nuevaLista;
}
