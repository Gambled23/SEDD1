#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"
using namespace std;

class nodo
{
public:
    int dato;
    nodo *siguiente;
    nodo();
    nodo(int e)
    {
        dato = e;
        siguiente = nullptr;
    };

private:
};

nodo::nodo()
{
    siguiente = nullptr;
}
class cola
{
public:
    nodo *h;
    nodo *t;
    cola();
    void inicializa();
    void queue(int);
    void dequeue();
    void first();
    void last();
    void mostrarCola();
};

cola::cola()
{
    h = nullptr;
    t = nullptr;
}
void cola::inicializa()
{
    h = nullptr;
    t = nullptr;
}
void cola::queue(int n)
{
    nodo *nuevo_nodo = new nodo(n);
    if (h == nullptr) // si es el 1er elemento
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else
    {
        t->siguiente = nuevo_nodo;
        t = nuevo_nodo;
    }
}
void cola::dequeue()
{
    nodo *aux = new nodo();
    aux = h;
    if (h == nullptr) // Si no hay elementos
    {
        cout << "Cola vacia\n";
    }
    else if (h == t) // Si es el unico elemento
    {
        delete (aux);
        h = nullptr;
        t = nullptr;
    }
    else // Si no es el unico elemento
    {
        h = h->siguiente;
        delete (aux);
    }
}
void cola::first()
{
    if (h)
    {
        cout << "El primer elemento es: " << h->dato << endl;
    }
    else
    {
        cout << "Pila vacia\n";
    }
}
void cola::last()
{
    if (h)
    {
        cout << "El ultimo elemento es: " << t->dato << endl;
    }
    else
    {
        cout << "Pila vacia\n";
    }
}
void cola::mostrarCola()
{
    nodo *aux = new nodo();
    aux = h;
    while (aux != nullptr)
    {
        cout << "Nombre de int: " << aux->dato << endl;
        cout << "Codigo de int: " << aux->dato << endl;
        cout << "ID de int: " << aux->dato << endl
             << endl
             << endl;
        aux = aux->siguiente;
    }
}
cola *cola1 = new cola();
int main()
{
    int opc = 0, n;
    char opcChar[100], nChar[100];
    do
    {
        system("cls");
        cout << "1) Encolar" << endl
             << "2) Desencolar" << endl
             << "3) Primer elemento" << endl
             << "4) Ultimo elemento" << endl
             << "5) Mostrar cola" << endl
             << "0) Salir" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Ingrese el elemento a agregar\n";
            cin >> nChar;
            n = validarNumInt(nChar);
            cola1->queue(n);
            break;
        case 2:
            cola1->dequeue();
            break;
        case 3:
            cola1->first();
            break;
        case 4:
            cola1->last();
            break;
        case 5:
            cola1->mostrarCola();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
        system("PAUSE");
    } while (opc != 0);
    return 0;
}