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



int main()
{

    Nodo *pila = NULL;

    int value, cont = 0, opc = 1;

    

    } while (opc != 0);
};
int menu()
{
    int opc;
    char opcChar;
    do
    {
        /* code */
    } while (opc != 5);
    
    cout << "1) Push" << endl
         << "2) Pop" << endl
         << "3) Mostrar tope" << endl
         << "4) Mostrar pila" << endl
         << "5) Salir" << endl;
    return opc;
};