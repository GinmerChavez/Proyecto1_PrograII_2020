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
	int Monedas[9] = {1, 5, 10, 25, 50, 100, 500, 1000, 2000 };
public:
	MonederoElectronico();
	MonederoElectronico(int dinero);
	int calculaVueltoMinimo();
	string desgloceVuelto();
	void setDinero(int dinero);
	int getDinero();
	~MonederoElectronico();


};