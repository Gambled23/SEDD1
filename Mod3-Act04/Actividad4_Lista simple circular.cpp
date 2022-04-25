#include <iostream>
#include "listaSimple.hpp"
#include "validaciones.hpp"
using namespace std;

listaSimple *lista = new listaSimple(); //?Crea una nueva lista

int main()
{
    lista->insertaInicio(1);
    lista->insertaInicio(2);
    lista->insertaInicio(3);
    cout << "Nodos Insertados\n";
    lista->mostrarLista();
    lista->insertarFinal(4);
    lista->insertarFinal(5);
    lista->insertarFinal(6);
    cout << "Nodos Insertados\n";
    lista->mostrarLista();
    cout <<"Remover la primer position:\n";
    lista->eliminarElemento(3); //TODO esta eliminando el elemento 3, debes de hacer que se elimine el elemento en la posicion 1
    lista->mostrarLista();
    system("PAUSE");
    return 0;
}