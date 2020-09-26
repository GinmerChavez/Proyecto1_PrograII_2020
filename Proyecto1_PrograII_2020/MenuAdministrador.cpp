#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(IMaquinaAdministradora* maquinaAdministradora)
{
	this->maquinaAdministradora = maquinaAdministradora;
}

void MenuAdministrador::invocarMenu()
{
	const char opcionSalida = '8';
	char opcion;
	do
	{
		try
		{
			opcion = mostrarOpciones();
			switch (opcion)
			{
			case '1':
				this->insertar();
				break;
			case '2':
				this->agregarProvisiones();
				break;
			case '3':
				this->disminuirProvisiones();
				break;
			case '4':
				this->borrarProducto();
				break;
			case '5':
				this->consultar();
				break;
			case '6':
				this->ingresarDinero();
				break;
			case '7':
				this->retirarDinero();
				break;
			default:
				cerr << "Opcion invalida, digite otra vez" << endl;
			}
		}
		catch (exception& e)
		{
			cerr << "Ocurrio un problema realizando la accion: ";
			cerr << e.what() << endl;
			system("pause");
		}
	}
	while (opcion != opcionSalida);
}

char MenuAdministrador::mostrarOpciones()
{
	char opcion;
	system("cls");
	cout << "Menu Administrador - Seleccionar una opcion:" << endl;
	cout << "1) Insertar" << endl;
	cout << "2) Agregar provisiones" << endl;
	cout << "3) Disminuir provisiones" << endl;
	cout << "4) Borrar producto" << endl;
	cout << "5) Consultar producto" << endl;
	cout << "6) Ingresar dinero" << endl;
	cout << "7) Retirar dinero" << endl;
	cout << "8) Salir" << endl;
	cin >> opcion;
	system("cls");
	return opcion;
}

void MenuAdministrador::insertar() //funciona
{
	Producto* producto = crearProducto();
	if (producto)
	{
		this->maquinaAdministradora->insertar(producto);
	}
	else
	{
		throw invalid_argument("Ocurrio un problema al tratar de insertar un producto.");
	}
}

void MenuAdministrador::agregarProvisiones()
{
	string id;
	int provisiones;
	cout << "Ingrese el nombre del producto al cual desea agregarle provisiones" << endl;
	id = leerCadena();
	cout << "Ingrese la cantidad de provisiones que desea agregar" << endl;
	provisiones = leerEntero();
	this->maquinaAdministradora->agregarProvisiones(id, provisiones);
}

void MenuAdministrador::disminuirProvisiones()
{
	string id;
	int provisiones;
	cout << "Ingrese el nombre del producto al cual desea quitarle provisiones" << endl;
	id = leerCadena();
	cout << "Ingrese la cantidad de provisiones que desea quitar" << endl;
	provisiones = leerEntero();
	this->maquinaAdministradora->disminuirProvisiones(id, provisiones);
}

void MenuAdministrador::borrarProducto()
{
	try
	{
		string id;
		cout << "Ingrese el nombre del producto que desea borrar: " << endl;
		id = leerCadena();
		this->maquinaAdministradora->consultar(id);
		this->maquinaAdministradora->borrar(id);
	}
	catch (exception& e)
	{
		cerr << "Ocurrio un problema al tratar de borrar un producto. ";
		cerr << e.what() << endl;
		system("pause");
	}
}
 
void MenuAdministrador::consultar() //funciona
{
		string id;
		cout << "Ingrese el nombre del producto a consultar" << endl;
		id = leerCadena();
		Producto* productoBuscado = this->maquinaAdministradora->consultar(id);
		cout << productoBuscado->toString() <<endl;
		system("pause");
}

void MenuAdministrador::ingresarDinero() //funciona
{
	int dinero = 0;
	cout << "Cuanto dinero desea ingresar a la maquina?" << endl;
	dinero = leerEntero();
	this->maquinaAdministradora->ingresarDinero(dinero);
}

void MenuAdministrador::retirarDinero() //funciona
{
	int dinero = 0;
	cout << "Cuanto dinero desea retirar de la maquina?" << endl;
	dinero = leerEntero();
	this->maquinaAdministradora->retirarDinero(dinero);
	system("pause");
}
	
Producto* MenuAdministrador::crearProducto() //funciona
{
	string nombre;
	int precio, cantidad;
	Producto* prod = nullptr;
	cout << "Nombre:" << endl;
	nombre = leerCadena();
	cout << "Precio: " << endl;
	precio = leerEntero();
	cout << "Cantidad: " << endl;
	cantidad = leerEntero();
	int opcion;
	cout << "Digite 1 si desea que el producto sea perecedero o 2 para no perecedero:" << endl;
	opcion = leerEntero();
	if (opcion == 1) 
	{
		try
		{
			Fecha* fechavencimiento;
			int dia, mes, anno;
			cout << "Digite fecha de vencimiento: " << endl;
			cout << "Dia(dd): " << endl;
			dia = leerEntero();
			cout << "Mes(mm)" << endl;
			mes = leerEntero();
			cout << "Año(aaaa): " << endl;
			anno = leerEntero();
			fechavencimiento = new Fecha(dia, mes, anno);
			if (fechavencimiento)
			{
				prod = new ProductoPerecedero(nombre, precio, cantidad, fechavencimiento);
			}
		}
		catch (exception& e)
		{
			cerr << "Ocurrio un problema al tratar de crear un producto: ";
			cerr << e.what() << endl;
			system("pause");
		}
	}
	if (opcion == 2)
	{
		int porcentajeDescuento;
		cout << "Digite porcentaje de descuento: " << endl;
		porcentajeDescuento = leerEntero();
		if (porcentajeDescuento < 100)
		{
			prod = new ProductoNoPerecedero(nombre, precio, cantidad, porcentajeDescuento);
		}
		else
		{
			throw invalid_argument("El porcentaje de descuento ingresado no es permitido.");
		}
		
	}
	return prod;
}
