#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "validaciones.hpp"
using namespace std;

class pila
{
private:
    int datos[10], tope;

public:
    pila();
    void push();
    void pop();
    int vacia();
    int llena();
    void mostrar_tope();
    void mostrar_pila();
    void gotoxy(int, int);
};

pila::pila()
{
    tope = -1;
}
void pila::push()
{
    int x;
    char xChar[1];

    if (llena() == 0)
    {
        cout << "ingresa numero" << endl;
        cin >> xChar;
        x = validarNumInt(xChar);
        tope++;
        datos[tope] = x;
    }
}
void pila::pop()
{
    if (vacia() == 0)
    {
        datos[tope] = 0;
        tope--;
    }
}
void pila::mostrar_tope()
{
    if (vacia() == 0)
    {
        system("cls");
        cout << "El tope es:  " << datos[tope] << endl;
        system("pause");
    }
}

void pila::mostrar_pila()
{
    int i;
    if (vacia() == 0)
    {
        system("cls");
        printf("\n\n\t\t%c%c%c%c%c  \n", 201, 205, 205, 205, 187);
        printf("Tope->");
        i = tope;
        do
        {
            printf("\t\t%c ", 186, 205);
            cout << datos[i];
            printf(" %c\n", 186);
            i--;
            if (i >= 0)
            {
                printf("\t\t%c%c%c%c%c\n", 204, 205, 205, 205, 185); // Linea de en medio
            }
            else
            {
                printf("\t\t%c%c%c%c%c\n", 200, 205, 205, 205, 188); // Linea final
            }

        } while (i >= 0);
        // system("pause");
    }
}

int pila::vacia()
{
    if (tope == -1)
    {
        system("cls");
        cout << "LA PILA ESTA VACIA" << endl;
        system("pause");

        return 1;
    }
    else
    {
        return 0;
    }
}
int pila::llena()
{
    if (tope == 9)
    {
        system("cls");
        cout << "LA PILA ESTA LLENA " << endl;
        system("pause");
        return 1;
    }
    else
    {
        return 0;
    }
}

void pila::gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int main()
{
    pila p;
    int opcion;
    char opcionChar[100];

    do
    {
        system("cls");
        p.mostrar_pila();
        cout << "\n\n[1].ingresar numero\n[2].Eliminar tope\n[3].Mostrar tope\n[4].Mostrar pila\n[5].salir" << endl;
        cin >> opcionChar;
        opcion = validarNumInt(opcionChar);
        switch (opcion)
        {
        case 1: // system("cls");
            p.push();
            break;
        case 2:
            p.pop();
            break;
        case 3:
            p.mostrar_tope();
            break;
        case 4:
            p.mostrar_pila();
            break;
        case 5:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion incorrecta " << endl;
            system("pause");
        }
    } while (opcion != 5);
}