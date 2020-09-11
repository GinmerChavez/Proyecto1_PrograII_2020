#include "fecha.h"

Fecha::Fecha(unsigned int dd, unsigned int mm, int aaaa)
{
	dia = dd;
	mes = mm;
	anno = aaaa;
}


Fecha::Fecha()
{
	dia = 01;
	mes = 01;
	anno = 1970;
}

unsigned int Fecha::getDia() { return this->dia; }
unsigned int Fecha::getMes() { return this->mes; }
int Fecha::getAnno() { return this->anno; }

string Fecha::mostrarFecha()
{
	stringstream s;
	s << dia << "/" << mes << "/" << anno;
	return s.str();
}


void Fecha::setFecha(unsigned int dd, unsigned int mm, int aaaa)
{
	if (esCorrecta(dd, mm, aaaa))
	{
		dia = dd;
		mes = mm;
		anno = aaaa;
	}
	else
	{
		cout << "La Fecha introducida es incorrecta";
	}
}

Fecha* Fecha::getFechaActual()
{
	Fecha* fechaActual = new Fecha(dia, mes, anno);
	time_t ahora = time(0);
	tm* now = localtime(&ahora);																				
	this->dia = (now->tm_mday);	
	this->mes = (now->tm_mon + 1);
	this->anno = (now->tm_year + 1900);

	return fechaActual;
}

double Fecha::diferencia(Fecha* fechaDeVencimiento, Fecha* fechaActual)
{
	double diferencia = 0;
	struct tm a = {0,0,0,fechaDeVencimiento->dia, fechaDeVencimiento->mes-1, fechaDeVencimiento->anno-1900};
	struct tm b = {0,0,0,fechaActual->dia, fechaActual->mes-1, fechaActual->anno-1900};
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	if (x != (time_t)(-1) && y != (time_t)(-1))
	{
		diferencia = difftime(x,y) / (60*60*24);
	}
	return diferencia;
}


bool esCorrecta(unsigned int dd, unsigned int mm, int aaaa)
{
	unsigned int arrayDiasMes[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (aaaa == 0) return false;
	if (dd <= 0 || dd > 31) return false;
	if (mm <= 0 || mm > 12) return false;
	if (mm == 2 && dd > 29) return false;
	if (arrayDiasMes[mm - 1] < dd) return false;
	if (mm == 2 && dd == 29 && !esBisiesto(aaaa)) return false;
	return true;
}


bool esBisiesto(int aaaa)
{
	if ((aaaa % 4 == 0) && (aaaa % 100 != 0) || (aaaa % 400 == 0) )
	{
		return true;
	}
	else
	{
		return false;
	}
}