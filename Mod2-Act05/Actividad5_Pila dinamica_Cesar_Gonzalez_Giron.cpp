#include <iostream>

#include <cstdlib>

using namespace std;

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

int menu()
{

    int opc;

    cout << "\n  1.- Apilar"

            "\n   2.- Desapilar"

            "\n   0.- Salir"
         << endl;

    cin >> opc;

    return opc;
};

int main()
{

    Nodo *pila = NULL;

    int value, cont = 0, opc = 1;

    do
    {

        switch (menu())
        {

        case 1:

            cont++;

            push(pila, cont);

            system("CLS");

            display(pila, cont);

            break;

        case 2:

            cont--;

            pop(pila);

            system("CLS");

            display(pila, cont);

            break;

        case 0:

            opc = 0;

            break;

        default:
            std::cout << "\nOpcion no disponible" << '\n';
        }

    } while (opc != 0);
};