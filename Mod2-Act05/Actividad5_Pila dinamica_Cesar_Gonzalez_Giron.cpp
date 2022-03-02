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
    pila = temp->next;
    delete (temp);
};

void display(Nodo *&pila, int cont)
{
    Nodo *temp = pila;
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
};

int main()
{
    Nodo *pila = NULL;
    int value, cont = 0, opc = 1;
};
void menu()
{
    int opc;
    char opcChar[100];
    do
    {
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
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opc != 5);
};