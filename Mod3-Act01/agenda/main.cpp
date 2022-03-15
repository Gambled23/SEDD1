#include <iostream>
#include <cstdlib>
#include "nodo.hpp"
using namespace std;

void menu();
int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    int opc;
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
        cout << "7) Ordenar alfabeticamente" << endl;
        cout << "8) Imprimir datos" << endl;
        cout << "9) Modificar" << endl;
        cout << "10) Eliminar todo" << endl;
        cout << "0) Salir" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
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