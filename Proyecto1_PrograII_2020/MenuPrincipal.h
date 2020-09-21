#pragma once
#include"MenuAdministrador.h"
#include"MenuCobro.h"
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class MenuPrincipal
{
private:
	MenuAdministrador* menuAdministrador;
	MenuCobro* menuCobro;
public:
	MenuPrincipal(MenuAdministrador* menuAdministrador, MenuCobro* menuCobro);
	void invocarMenu();
	~MenuPrincipal();
private:
	char mostrarOpciones();
};