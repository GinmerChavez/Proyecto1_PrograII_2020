#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <sstream>
#include <ctime>

bool esCorrecta(unsigned int dd, unsigned int mm, int aaaa);
bool esBisiesto(int aaaa);

using namespace std;

class Fecha
{
private:
	unsigned int dia;
	unsigned int mes;
	int anno;

public:
	Fecha();
	Fecha(unsigned int d, unsigned int m, int a);
	unsigned int getDia();
	unsigned int getMes();
	int getAnno();
	string mostrarFecha();
	void setFecha(unsigned int d, unsigned int m, int a);
	Fecha* getFechaActual();
	static double diferencia(Fecha*, Fecha*);
};