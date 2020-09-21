#include "Maquina.h"

Maquina::Maquina(int identificador, string nombre, MonederoElectronico* monedero, IList* productos)
{
    this->identificador = identificador;
    this->nombre = nombre;
    this->productos = productos;
    this->monedero = monedero;
}

Maquina::~Maquina()
{
    this->productos->liberarDatosInternos();
    delete[] productos;
    delete monedero;
}

int Maquina::getIdentificador()
{
    return this->identificador;
}

string Maquina::getNombre()
{
    return this->nombre;
}

void Maquina::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Maquina::toString()
{
    int contador = 0;
    IIterador* ite = this->productos->obtenerIterador();
    stringstream s;
    s << "Nombre de la maquina: " << this->nombre << "con identificador: " << this->identificador;
    s << "Posee la siguiente lista de productos: " << endl;
    while (ite->haySiguiente())
    {
        s << "[" << contador << "]: " << productos->toString() << endl;
        contador++;
    }
    return s.str();
}

void Maquina::insertar(Producto* p)
{
    this->productos->insertarAlFinal(p);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad)
{
    try
    {
        Producto* productoBuscado = this->consultar(idProducto);
        productoBuscado->setCantidad(cantidad);
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de agregar provisiones. ";
        cerr << e.what() << endl;
    }
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad)
{
    try
    {
        Producto* productoBuscado = this->consultar(idProducto);
        productoBuscado->setCantidad(cantidad);
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de disminuir provisiones. ";
        cerr << e.what() << endl;
    }
}

void Maquina::borrar(string id)
{
    try
    {
        Producto* productoBuscado = this->consultar(id);
        if (this->productos->contiene(productoBuscado))
        {
            delete productoBuscado;
            productoBuscado = nullptr;
        }
        throw invalid_argument("El producto no se encuentra contenido en la maquina.");
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de borrar el Producto. ";
        cerr << e.what() << endl;
    }
}

Producto* Maquina::consultar(string id)
{
    if (id.empty())
    {
        throw invalid_argument("El nombre del producto es vacio. ");
    }

    IIterador* ite = this->productos->obtenerIterador();
    Producto* resultado = nullptr;
    while (ite->haySiguiente())
    {
        Producto* actual = dynamic_cast<Producto*>(ite->actual());
        if (actual->getNombre() == id)
        {
            resultado = actual;
            break;
        }
    }
    delete ite;
    return resultado;

    throw invalid_argument("El nombre del Producto provisto no se encuentra en la maquina. ");
}

void Maquina::ingresarDinero(int dinero)
{
    this->monedero->setDinero(dinero);
}

void Maquina::retirarDinero(int cantidad)
{
    int dineroActual = this->monedero->getDinero();
    if (dineroActual >= cantidad)
    {
        this->monedero->setDinero(dineroActual-cantidad);
    }
    else
    {
        cerr << "No es posible retirar esta cantidad de dinero. La maquina actualmente cuenta con " << dineroActual << " colones" << endl;
    }
}

string Maquina::realizarCompra(string id, int cantidad, int montoPago)
{
    //Aqui hace falta una validacion para entero y una validacion para string
    stringstream s;
    try
    {
        int dineroActual = this->monedero->getDinero();
        Producto* productoBuscado = this->consultar(id);
        if (productoBuscado != nullptr)
        {
            if (productoBuscado->getCantidad() >= cantidad)
            {
                if (montoPago >= productoBuscado->getCantidad() * productoBuscado->getPrecio())
                {
                    this->disminuirProvisiones(id, cantidad);
                    this->monedero->setDinero(dineroActual + montoPago);
                    s << "La compra se ha efectuado satisfactoriamente." << endl;
                    s << this->monedero->desgloceVuelto();
                }
                else
                {
                    cout << "El monto de dinero recibido es insuficiente para realizar la compra. " << endl;
                }
            }
            else
            {
                cout << "La cantidad de producto que se desea comprar excede la cantidad disponible en la maquina." << endl;
            }
        }
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de realizar la compra. ";
        cerr << e.what() << endl;
    }
    return s.str();
}

Producto* Maquina::mostrarProducto(string id)
{
    Producto* p = this->consultar(id);
    return p;

}




