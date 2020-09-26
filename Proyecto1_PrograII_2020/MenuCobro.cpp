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
		try
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
		catch (exception& e)
		{
			cerr << "Ocurrio un probema realizando la accion: ";
			cerr << e.what() <<endl;
			system("pause");
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

void MenuCobro::seleccionarProducto()
{
	try
	{
		string id;
		cout << "Ingrese el nombre del producto que desea escoger: " << endl;
		id = leerCadena();
		cout << endl << this->maquinaVendedora->mostrarProducto(id)->toString() << endl;
		char opcion;
		cout << "Presione 1, si desea confirmar la compra de este producto." << endl;
		cout << "Presione cualquier tecla para retornar al menu de cobro." << endl;
		cin >> opcion;
		if (opcion == '1')
		{
			system("cls");
			this->subMenuCompra(id);
		}

	}
	catch (exception& e)
	{
		cerr << "Ocurrio un problema al tratar de Seleccionar un producto. ";
		cerr << e.what() << endl;
		system("pause");
	}
}

void MenuCobro::subMenuCompra(string id) 
{
	try
	{
		int cantidadEnExistencia = this->maquinaVendedora->mostrarProducto(id)->getCantidad();
		int monto, cantidad, precio, vuelto;
		cout << "Cuantas unidades del producto desea comprar?" << endl;
		cantidad = leerEntero();
		if (cantidad <= cantidadEnExistencia)
		{
			cout << "Digite el monto con el que desea pagar su compra" << endl;
			monto = leerEntero();
			precio = this->maquinaVendedora->mostrarProducto(id)->getPrecio();
			int total = precio * cantidad;
			if (monto >= total)
			{
				vuelto = monto - precio * cantidad;
				if (vuelto <= this->maquinaVendedora->retornarMonedero()->getDinero())
				{
					this->maquinaVendedora->realizarCompra(id, cantidad, monto);
					cout << "Se entrega " << cantidad << " unidad(es) de " << this->maquinaVendedora->mostrarProducto(id)->getNombre() << endl;
					cout << "Vuelto: " << vuelto << endl;
					cout << this->retornarMonedero()->desgloceVuelto(vuelto);
					cout << "La compra se efectuo exitosamente." << endl;
					system("pause");
				}
				else
				{
					cout << "Lo sentimos, la maquina no cuenta con el dinero suficiente para dispensar su vuelto." << endl;
					cout << "Le rogamos se ponga en contacto con el administrador. Gracias!." << endl;
					system("pause");
				}
			}
			else
			{
				cout << "Monto insuficiente, necesita " << total - monto << " colones mas para realizar la compra" << endl;
				cout << "No se pudo realizar la compra." << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Lo sentimos, la cantidad ingresada del producto es mayor que la cantidad disponible." << endl;
			cout << "Su compra no pudo ser efectuada." << endl;
			system("pause");
		}
	}
	catch(exception& e)
	{
		cerr << "Ocurrio un problema al tratar de efectuar una compra. ";
		cerr << e.what() << endl;
		system("pause");
	}
}

MonederoElectronico* MenuCobro::retornarMonedero()
{
	return this->maquinaVendedora->retornarMonedero();
}



