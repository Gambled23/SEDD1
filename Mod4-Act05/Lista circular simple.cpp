#include <iostream>
#include "listaSimple.hpp"
#include "validaciones.hpp"
using namespace std;

void menu();
listaSimple *lista = new listaSimple(); //?Crea una nueva lista

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    int opc = 1;
    char opcChar[100];
    int dato;
    char datoChar[100];
    while (opc != 0)
    {
        system("cls");
        cout << "\tMenu\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Buscar un elemento\n";
        cout << "5. Eliminar elemento\n";
        cout << "6. Vaciar lista\n";
        cout << "7. Mostrar tamano lista\n";
        cout << "8. Modificar\n";
        cout << "9. Buscar por posicion\n";
        cout << "0. Salir\n\n";
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Ingrese un dato: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->insertaInicio(dato);
            break;
        case 2:
            cout << "Ingrese un dato: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->insertarFinal(dato);
            break;
        case 3:
            lista->mostrarLista();
            break;
        case 4:
            cout << "Ingrese el elemento a buscar: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->buscarElemento(dato);
            break;
        case 5:
            cout << "Ingrese el elemento a eliminar: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->eliminarElemento(dato);
            break;
        case 6:
            lista->eliminarLista();
            break;
        case 7:
            lista->tamanoLista();
            break;
        case 8:
            cout << "Ingrese el elemento a modificar: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->modificarElemento(dato);
            break;
        case 9:
            cout << "Ingrese la posicion a buscar: ";
            cin >> datoChar;
            dato = validarNumInt(datoChar);
            lista->buscarPorPosicion(dato);
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << ("La opcion solicitada no existe\n");
            break;
        }
        system("PAUSE");
    }
}