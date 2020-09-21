#include "MenuCobro.h"

MenuCobro::MenuCobro(IMaquinaVendedora* maquinaVendedora)
{
	this->maquinaVendedora;
}

void MenuCobro::invocarMenu()
{
	const char opcionSalida = '4';
	char opcion;
	do
	{
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->mostrarProductos();
			break;
		case '2':
			this->seleccionarProducto();
			break;
		case '3':

		}
	}
	while (opcion != opcionSalida);
}

string MenuCobro::mostrarProductos()
{
	return this->maquinaVendedora->toString();
}

string MenuCobro::seleccionarProducto() // hay que hacer excepcion 
{
	string id;
	cout << "Digite el ID del producto que desea escoger: " << endl;
	cin >> id;
	cout << "Producto: " << endl;
	cout << this->maquinaVendedora->mostrarProducto(id)->toString() << endl;
	cout << "Si desea comprar este producto presione 1 y para salir presione 2" << endl;
	int opcion;
	cin >> opcion; 
	if (opcion == 1)
	{
		system("CLS");
		this->subMenuCompra(id);
		return "Compra hecha";
	}
	else
	{
		return "Fallo en compra";
	}

}

string MenuCobro::subMenuCompra(string id)
{
	
	int monto, cantidad, precio, vuelto;
	
	cout << "Cuantas unidades desea comprar?" << endl;
	cin >> cantidad;
	cout << "Digite el monto con el que desea pagar" << endl;
	cin >> monto;
	precio = this->maquinaVendedora->mostrarProducto(id)->getPrecio();
	if (monto < precio*cantidad)
	{
		cout << "Monto insuficiente, necesita: " << monto - precio << "mas para realizar la compra" << endl;
		return "No se pudo realizar compra"
	}
	else
	{	
		this->maquinaVendedora->realizarCompra(id, cantidad, monto);
		vuelto = monto - precio * cantidad;
		cout << "se entrega" << this->maquinaVendedora->mostrarProducto(id)->getNombre() << endl;
		cout << "Vuelto: " << vuelto << endl;
		return "Se efectuo compra exitosamente" 

	}
}



