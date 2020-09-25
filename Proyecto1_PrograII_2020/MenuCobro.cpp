#include "MenuCobro.h"

MenuCobro::MenuCobro(IMaquinaVendedora* maquinaVendedora)
{
	this->maquinaVendedora = maquinaVendedora;
}

void MenuCobro::invocarMenu()
{
	const char opcionSalida = '3';
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
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	}
	while (opcion != opcionSalida);
}

char MenuCobro::mostrarOpciones()
{
	char opcion;
	system("cls");
	cout << "Menu Cobro - Seleccionar una opcion:" << endl;
	cout << "1) Mostrar productos" << endl;
	cout << "2) Seleccionar producto" << endl;
	cout << "3) Salir" << endl;
	cin >> opcion;
	system("cls");
	return opcion;
}

void MenuCobro::mostrarProductos()
{
	cout << this->maquinaVendedora->toString() <<endl;
	system("pause");
}

void MenuCobro::seleccionarProducto() // hay que hacer excepcion 
{
	try
	{
		string id;
		cout << "Ingrese el nombre del producto que desea escoger: " << endl;
		cin >> id;
		cout << "Producto: " << endl;
		cout << this->maquinaVendedora->mostrarProducto(id)->toString() << endl;
		char opcion;
		cout << "Presione 1, si desea confirmar la compra de este producto." << endl;
		cout << "Presione 2, para salir al menu de cobro." << endl;
		cin >> opcion;
		const char opcionSalida = '2';
		do
		{
			switch (opcion)
			{
			case '1':
				system("cls");
				this->subMenuCompra(id);
				cout << "Producto comprado satisfactoriamente.";
				break;
			case opcionSalida:
				break;
			default:
				cerr << "Opcion invalida, digite otra vez" << endl;
			}

		} while (opcion != opcionSalida);
	}
	catch (exception& e)
	{
		cerr << "Ocurrio un problema al tratar de Seleccionar un producto." << endl;
		cerr << e.what() << endl;
	}
}

void MenuCobro::subMenuCompra(string id) //si tiene que retornar
{
	int monto, cantidad, precio, vuelto;
	cout << "Cuantas unidades desea comprar?" << endl;
	cin >> cantidad;
	cout << "Digite el monto con el que desea pagar" << endl;
	cin >> monto;
	precio = this->maquinaVendedora->mostrarProducto(id)->getPrecio();
	int total = precio * cantidad;
	if (monto >= total)
	{
		this->maquinaVendedora->realizarCompra(id, cantidad, monto);
		vuelto = monto - precio * cantidad;
		cout << "Se entrega " << cantidad << " unidades de " << this->maquinaVendedora->mostrarProducto(id)->getNombre() << endl;
		cout << "Vuelto: " << vuelto << endl;
		cout << this->retornarMonedero()->desgloceVuelto(vuelto);
		cout << "La compra se efectuo exitosamente" <<endl;
		
		system("pause");
	}
	else
	{	
		cout << "Monto insuficiente, necesita " << total - monto << " colones mas para realizar la compra" << endl;
		cout << "No se pudo realizar la compra.";
	}
}

MonederoElectronico* MenuCobro::retornarMonedero()
{
	return this->maquinaVendedora->retornarMonedero();
}



