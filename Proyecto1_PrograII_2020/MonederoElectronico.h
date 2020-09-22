#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//deberia de funcionar como un monedero real

class MonederoElectronico
{
private:
	int dinero;
	int *Vuelto;
	int Monedas[9] = {1, 5, 10, 25, 50, 100, 500, 1000, 2000};
public:
	MonederoElectronico();
	MonederoElectronico(int dinero);
	int calculaVueltoMinimo(int vuelto);
	string desgloceVuelto(int vuelto);
	void setDinero(int dinero);
	int getDinero();
	~MonederoElectronico();

/*
	Esta mal hecho, necesita funcionar como un monedero real, guardar plata y guardar en un arreglo
	las monedas y billetes que tiene. Tambien tiene que actualizar monedas y billetes cada vez que se paga 
	y se da vuelto
	
	-Hay que hacer un arreglo que guarde el dinero
	-Hacer logica 
	
*/
};