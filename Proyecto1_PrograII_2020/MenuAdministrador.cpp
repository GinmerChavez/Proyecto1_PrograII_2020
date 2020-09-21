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

void MenuAdministrador::insertar()
{
	Producto* producto = crearProducto();
	this->maquinaAdministradora->insertar(producto);
}

void MenuAdministrador::agregarProvisiones()
{
	string id;
	int provisiones;
	cout << "Digite el id del producto al cual desea agregarle provisiones" << endl;
	cin >> id;
	cout << "Cuanta cantidad de provisiones desea agregar" << endl;
	cin >> provisiones;
	this->maquinaAdministradora->agregarProvisiones(id, provisiones);
}

void MenuAdministrador::disminuirProvisiones()
{
	string id;
	int provisiones;
	cout << "Digite el id del producto al cual desea quitarle provisiones" << endl;
	cin >> id;
	cout << "Cuanta cantidad de provisiones desea quitar" << endl;
	cin >> provisiones;
	this->maquinaAdministradora->disminuirProvisiones(id, provisiones);
}

void MenuAdministrador::borrarProducto()
{
	string id; 
	cout << "Digite el id del producto que desea borrar" << endl;
	cin >> id;
	this->maquinaAdministradora->borrar(id);
}

string MenuAdministrador::consultar()
{
	string id;
	cout << "Digite el ID del producto a consultar" << endl;
	cin >> id;
	return this->maquinaAdministradora->consultar(id)->toString();
}

void MenuAdministrador::ingresarDinero()
{
	int dinero;
	cout << "Cuanto dinero desea ingresar?" << endl;
	this->maquinaAdministradora->ingresarDinero(dinero);

}

void MenuAdministrador::retirarDinero()
{
	int dinero;
	cout << "Cuanto dinero desea ingresar?" << endl;
	this->maquinaAdministradora->retirarDinero(dinero);
}
	
Producto* MenuAdministrador::crearProducto()
{
	string nombre;
	int precio, cantidad;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Precio: " << endl;
	cin >> precio;
	cout << "Cantidad :" << endl;
	cin >> cantidad;
	int opcion;
	cout << "Digite 1 si desea que el producto sea perecedero o 2 para no perecedero:" << endl;
	cin >> opcion;
	if (opcion == 1) //se ocupa manejo de errores para opciones
	{
		Fecha* fechavencimiento;
		int dia, mes, anno;
		cout << "Digite fecha de vencimiento: " << endl;
		cout << "Dia: " << endl;
		cin >> dia;
		cout << "Mes" << endl;
		cin >> mes;
		cout << "Año: " << endl;
		cin >> anno;
		fechavencimiento = new Fecha(dia, mes, anno); //hacer error handling para formato de fecha

		Producto* prod = new ProductoPerecedero(nombre, precio, cantidad, fechavencimiento);

		return prod;
	}
	if (opcion == 2)
	{
		int porcentajeDescuento;
		cout << "Digite porcentaje de descuento: " << endl;
		cin >> porcentajeDescuento;

		Producto* prod = new ProductoNoPerecedero(nombre, precio, cantidad, porcentajeDescuento);
		return prod;
	}


}
