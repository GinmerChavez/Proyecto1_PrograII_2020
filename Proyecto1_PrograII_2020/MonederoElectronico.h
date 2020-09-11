#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;


class MonederoElectronico
{
private:
	int dinero;
	int *Vuelto;
public:
	MonederoElectronico();
	MonederoElectronico(int dinero);
	int calculaVueltoMinimo();
	string desgloceVuelto();
	void setDinero(int dinero);
	int getDinero();
	~MonederoElectronico();
public:
	int Monedas[5] = {50, 100, 500, 1000, 2000};

};