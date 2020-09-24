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
    stringstream s;
    s << "-------------------------------------------------------------------------------------" << endl;
    s << "La maquina " << this->nombre << " con identificador " << this->identificador;
    s << " posee la siguiente lista de productos: " << endl;
    s << "-------------------------------------------------------------------------------------" << endl;
    if (this->productos->getCantidad() > 0)
    {
        s << this->productos->toString() << endl;
    }
    else
    {
        s << "Oops!, Lo sentimos. La maquina no tiene productos aun. Por favor contacte al administrador." << endl;
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
        int cantidadExistente = productoBuscado->getCantidad();
        productoBuscado->setCantidad(cantidadExistente + cantidad);
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de agregar provisiones. ";
        cerr << e.what() << endl;
        system("pause");
    }
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad)
{
    try
    {
        Producto* productoBuscado = this->consultar(idProducto);
        int cantidadExistente = productoBuscado->getCantidad();
        if (cantidadExistente >= cantidad && cantidadExistente > 0)
        {
            productoBuscado->setCantidad(cantidadExistente - cantidad);
        }
        else
        {
            cout << "No se puede disminuir esta cantidad de provisiones para este producto. ";
            cout << "La cantidad en existencia de este producto es " << cantidadExistente << endl;
            system("pause");
        }
        
    }
    catch (exception& e)
    {
        cerr << "Ocurrio un problema al tratar de disminuir provisiones. ";
        cerr << e.what() << endl;
        system("pause");
    }
}

void Maquina::borrar(string id)
{
    int contador = 0;
    IIterador* ite = this->productos->obtenerIterador();
    while (ite->haySiguiente())
    {
        Producto* actual = dynamic_cast<Producto*>(ite->actual());
        if (actual->getNombre() == id)
        {
            this->productos->borrarEnPosicion(contador);
            cout << "Producto borrado satisfactoriamente." << endl;
            system("pause");
            break;
        }
        contador++;
    }
    delete ite;
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
    if (resultado)
    {
        return resultado;
    }
    else
    {
        throw invalid_argument("El nombre del Producto provisto no se encuentra en la maquina. ");
    }
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
                if (montoPago >= cantidad * productoBuscado->getPrecio())
                {
                    int vuelto = montoPago - productoBuscado->getPrecio()*cantidad;
                    this->disminuirProvisiones(id, cantidad);
                    this->monedero->setDinero(dineroActual + montoPago);
                    s << this->monedero->desgloceVuelto(vuelto) << endl;
                    s << "La compra se ha efectuado satisfactoriamente." << endl;


                  
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
    try
    {
        Producto* p;
        p = this->consultar(id);
        return p;
    }
    catch(exception& e)
    {
        cerr << "Ocurrio un problema al tratar de mostrar un producto." << endl;
        cerr << e.what() << endl;
    }
    throw invalid_argument("Ocurrio un problema al mostrar un producto.");
}

MonederoElectronico* Maquina::retornarMonedero()
{
    return this->monedero;
}




