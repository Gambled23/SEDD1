#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"
using namespace std;
void menu();
class Nodo
{

public:
    int value;
    Nodo *next;
};

void push(Nodo *&pila, int n)
{
    Nodo *temp = new Nodo();
    temp->value = n;
    temp->next = pila;
    pila = temp;
};

void pop(Nodo *&pila)
{
    Nodo *temp = pila;
    if (temp)
    {
        pila = temp->next;
        cout << "Eliminado valor '" << temp->value << "'" << endl;
        delete (temp);
    }
    else
    {
        cout << "Pila vacia" << endl;
    }
};

void display(Nodo *&pila)
{
    Nodo *temp = pila;
    if (temp)
    {
        while (temp != NULL)
        {
            if (temp == pila)
            {
                cout << "\t*" << temp->value << "*";
                temp = temp->next;
            }
            else
            {
                cout << "\t*" << temp->value << "*";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    else
    {
        cout<<"PILA VACIA\n\n";
    }
};

int main()
{
    menu();
    system("PAUSE");
};
void menu()
{
    Nodo *pila = NULL;
    int opc, valor;
    char opcChar[100], valorChar[100];
    do
    {
        system("cls");
        display(pila);
        cout << "1) Push" << endl
             << "2) Pop" << endl
             << "3) Mostrar tope" << endl
             << "4) Mostrar pila" << endl
             << "5) Salir" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Que valor quieres ingresar?" << endl;
            cin >> valorChar;
            valor = validarNumInt(valorChar);
            push(pila, valor);
            break;
        case 2:
            pop(pila);
            break;
        case 3:
            /* code */
            break;
        case 4:
            display(pila);
            break;
        case 5:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        system("PAUSE");
    } while (opc != 5);
};