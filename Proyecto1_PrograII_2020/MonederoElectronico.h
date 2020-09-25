#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include <vector> 
using namespace std;

class MonederoElectronico
{
private:
	int dinero;
	vector<int> Vuelto;
	int Monedas[9] = {1, 5, 10, 25, 50, 100, 500, 1000, 2000};
public:
	MonederoElectronico();
	MonederoElectronico(int dinero);
	int calculaVueltoMinimo(int vuelto);
	string desgloceVuelto(int vuelto);
	void setDinero(int dinero);
	int getDinero();
	~MonederoElectronico();

};