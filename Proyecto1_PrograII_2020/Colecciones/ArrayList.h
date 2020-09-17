#include <iostream>
#include <sstream>
#include "IList.h"
#include "IteradorArrayList.h"
using namespace std;

class ArrayList : public IList
{
private:
	ObjetoBase** datos;
	int capacidadActual;
	int cantidad;
	void asegurarCapacidad();

public:
	ArrayList(int capacidadInicial);
	void insertarAlFinal(ObjetoBase* elemento) override;
	void insertarEnPosicion(ObjetoBase* elemento, int posicion) override;
	void borrarEnPosicion(int posicion, bool liberarMemoria = false) override;
	ObjetoBase* consultarPorPosicion(int posicion) override;
	bool contiene(ObjetoBase* elemento) override;
	int getCantidad() override;
	void liberarDatosInternos() override;
	string toString() override;
	IIterador* obtenerIterador() override;
	~ArrayList();
};