#include <iostream>
#include <cstdlib>
#include "nodo.hpp"
#include "validaciones.hpp"
#include "listaSimple.cpp"
using namespace std;

void menu();
contacto contactoAux;
listaSimple *lista = new listaSimple();
int main()
{
    menu();
    system("PAUSE");
    return 0;
}
void menu()
{
    char opcChar[100], auxChar[100];
    int opc, aux;
    string auxStr;
    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "1) Agregar contacto" << endl;
        cout << "2) Buscar por ID" << endl;
        cout << "3) Buscar por posicion" << endl;
        cout << "4) Buscar por nombre" << endl;
        cout << "5) Eliminar contacto" << endl;
        cout << "6) Invertir" << endl;
        cout << "7) Ordenar alfabeticamente" << endl; //!Ya funciona pero las ID no se cambian
        cout << "8) Imprimir datos" << endl;
        cout << "9) Modificar" << endl;
        cout << "10) Eliminar todo" << endl;
        cout << "0) Salir" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Ingresa el nombre del contacto:\n";
            cin.sync();
            getline(cin, contactoAux.nombre);
            lista->insertaInicio(contactoAux);
            break;
        case 2:
            cout << "Ingresa el ID del contacto a buscar:\n";
            cin >> auxChar;
            aux = validarNumInt(auxChar);
            lista->buscarID(aux);
            break;
        case 3:
            cout << "Ingresa la posicion del contacto a buscar:\n";
            cin >> auxChar;
            aux = validarNumInt(auxChar);
            lista->buscarPosicion(aux);
            break;
        case 4:
            cout << "Ingresa el nombre del contacto a buscar:\n";
            cin.sync();
            getline(cin, auxStr);
            lista->buscarNombre(auxStr);
            break;
        case 5:
            cout << "Ingresa la ID del contacto a eliminar:\n";
            cin >> auxChar;
            aux = validarNumInt(auxChar);
            lista->eliminarElemento(aux);
            break;
        case 6:
            lista->invertir();
            break;
        case 7:
            lista->ordenarAlfabeticamente();
            break;
        case 8:
            lista->mostrarLista();
            break;
        case 9:
            cout << "Ingresa la ID del contacto a modificar:\n";
            cin >> auxChar;
            aux = validarNumInt(auxChar);
            lista->modificarDato(aux);
            break;
        case 10:
            lista->eliminarLista();
            break;
        case 0:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
        system("PAUSE");
    } while (opc != 0);
}