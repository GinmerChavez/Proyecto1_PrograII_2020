#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico()
{
	this->dinero = 0;
	int monedaMenor = Monedas[0]; //la menor denominacion
	this->Vuelto = new int[100];
	for (int i = 0; i < 100; i++)
	{
		this->Vuelto[i] = 0;
	}

}

MonederoElectronico::MonederoElectronico(int dinero)
{
	this->dinero = dinero;
	int monedaMenor = Monedas[0]; //la menor denominacion
	int mayorVueltoPosible = round(this->dinero / monedaMenor);
	this->Vuelto = new int[mayorVueltoPosible];
	for (int i = 0; i < mayorVueltoPosible; i++)
	{
		this->Vuelto[i] = 0;
	}
}

int MonederoElectronico::calculaVueltoMinimo()
{
	
	int count = 0;
	int size = sizeof(Monedas) / sizeof(Monedas[0]);
	for (int i = size-1; i >=0; i--)
	{
		int nDinero = this->getDinero();
		while (nDinero >= Monedas[i])
		{

			nDinero -= Monedas[i];
			this->setDinero(nDinero);
			this->Vuelto[count] = Monedas[i];
			count++;
		}

		
	}
	return count;
}

string MonederoElectronico::desgloceVuelto()
{
	int numeroMonedas = this->calculaVueltoMinimo();
	stringstream s;
	s << "El cambio es: " << endl;
	for (int i = 0; i < numeroMonedas; i++)
	{
		s << this->Vuelto[i] << endl;
	}
	return s.str();
}

void MonederoElectronico::setDinero(int dinero)
{
	this->dinero = dinero;
}

int MonederoElectronico::getDinero()
{
	return dinero;
}

MonederoElectronico::~MonederoElectronico()
{
	delete this->Vuelto;
}
