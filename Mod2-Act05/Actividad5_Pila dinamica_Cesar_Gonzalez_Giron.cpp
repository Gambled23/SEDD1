#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"

using namespace std;
void menu();
int main()
{

    system("PAUSE");
    return 0;
}

void menu()
{
    //a
    char opcChar[100], elementoChar[100];
    int opc, elemento;
    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Mostrar tope" << endl;
        cout << "4) Mostrar pila" << endl;
        cout << "0) Salir" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Cual elemento quiere ingresar a la pila?: ";
            cin >> elementoChar;
            elemento = validarNumInt(elementoChar);
            break;
        case 2:
            
            cout<<"Se ha sacado el elemento de la lista\n";
            break;
        case 3:
            cout<<"El tope de la lista es: "<<endl;
            break;
        case 4:
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