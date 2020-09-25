#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico()
{
	this->dinero = 0;
	int monedaMenor = Monedas[0]; //la menor denominacion

}


int MonederoElectronico::calculaVueltoMinimo(int vuelto)
{
	
	int count = 0;
	int size = sizeof(this->Monedas) / sizeof(this->Monedas[0]);
	int nDinero = vuelto;
	for (int i = size-1; i >=0; i--)
	{
		while (nDinero >= this->Monedas[i])
		{
			nDinero -= this->Monedas[i];
			Vuelto.push_back(this->Monedas[i]);

		}
			count++;
	}
	return count;
}

string MonederoElectronico::desgloceVuelto(int vuelto)
{
	int numeroMonedas = this->calculaVueltoMinimo(vuelto);
	stringstream s;
	s << "El cambio es: " << endl;

		for (int i = 0; i < Vuelto.size() ; i++)
	{
			if (this->Vuelto[i] == 0)
			{
				s << "";
				continue;
			}
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

}
