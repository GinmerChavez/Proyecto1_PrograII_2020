#pragma once
#include <exception>
#include "Producto.h"
#include "MonederoElectronico.h"
#include "IMaquinaAdministradora.h"
#include "IMaquinaVendedora.h"
#include "Colecciones/IList.h"


class Maquina : public IMaquinaAdministradora, IMaquinaVendedora
{
private:
	int identificador;
	string nombre;
	MonederoElectronico* monedero;
	IList* productos;

public:
	Maquina(int, string, MonederoElectronico*, IList*);
	~Maquina();


	// Inherited via IMaquinaAdministradora
	virtual int getIdentificador() override;

	virtual string getNombre() override;

	virtual void setNombre(string) override;

	virtual string toString() override;

	virtual void insertar(Producto*) override;

	virtual void agregarProvisiones(string idProducto, int cantidad) override;

	virtual void disminuirProvisiones(string idProducto, int cantidad) override;

	virtual void borrar(string id) override;

	virtual Producto* consultar(string id) override;

	virtual void ingresarDinero(int) override;

	virtual void retirarDinero(int cantidad) override;


	// Inherited via IMaquinaVendedora
	virtual string realizarCompra(string id, int cantidad, int montoPago) override;

	virtual Producto* mostrarProducto(string id) override;


};
