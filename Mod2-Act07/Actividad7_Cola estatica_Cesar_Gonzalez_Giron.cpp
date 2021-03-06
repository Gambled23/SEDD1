#include <iostream>
#include <stdlib.h>
#include "validaciones.hpp"
using namespace std;

class cola
{
private:
    int inicio, fin;
    int dato[10];

public:
    cola();
    int lleno();
    int vacio();
    void llenar();
    void consultar_inicio();
    void consultar_final();
    void mostrar_cola();
    void eliminar();
};
cola::cola()
{
    fin = -1;
    inicio = 0;
}
void cola::llenar()
{
    int x;
    char xChar[100];
    if (lleno() == 0)
    {
        fin++;
        cout << "Ingrese dato " << endl;
        cin >> xChar;
        x = validarNumInt(xChar);
        dato[fin] = x;
    }
}

void cola::consultar_inicio()
{
    if (vacio() == 0)
    {
        cout << "\nEL inicio es  " << dato[0] << endl;
        system("pause");
    }
}

void cola::consultar_final()
{
    if (vacio() == 0)
    {
        cout << "\nEl final es  " << dato[fin] << endl;
        system("pause");
    }
}

void cola::mostrar_cola()
{
    if (vacio() == 0)
    {
        system("cls");
        printf("       ");
        for (int i = fin; i >= 0; i--)
        {
            if (i >= 0)
            {
                printf("%c%c%c", 203, 205, 205);
            }
            else
            {
                printf("%c%c%c", 201, 205, 205);
            }
        }
        printf("%c", 187);
        cout << endl;
        printf("Final->");
        for (int i = fin; i >= 0; i--)
        {
            printf("%c", 186);
            if (dato[i] != -1)
            {
                cout << dato[i] << " ";
            }
            
        }
        printf("%c <- Frente", 186);
        cout << endl;
        printf("       ");
        for (int i = fin; i >= 0; i--)
        {
            if (i >= 0)
            {
                printf("%c%c%c", 202, 205, 205);
            }
            else
            {
                printf("%c%c%c%c", 200, 205, 205, 188);
            }
        }
        printf("%c", 188);
        cout << endl;
    }
}

void cola::eliminar()
{
    if (vacio() == 0)
    {
        for (int i = 0; i <= fin; i++)
        {
            dato[i] = dato[i + 1];
        }
        dato[fin] = -1;
        fin--;
    }
}

int cola::lleno()
{
    if (fin == 9)
    {
        cout << "LA COLA ESTA LLENA" << endl;
        system("pause");
        return 1;
    }
    else
    {
        return 0;
    }
}
int cola::vacio()
{
    if (fin == -1)
    {
        cout << "LA COLA ESTA VACIA" << endl;
        system("pause");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int dato;
    int opcion;
    char opcionChar[100];
    cola c;
    do
    {
        system("cls");
        c.mostrar_cola();
        cout << "" << endl;
        cout << "Menu" << endl;
        cout << "[1]Encolar(push)" << endl;
        cout << "[2]Mostrar inicio" << endl;
        cout << "[3]Mostrar fin" << endl;
        cout << "[4]Des-Encolar(pop)" << endl;
        cout << "[5]Mostrar cola" << endl;
        cout << "[6].Salir" << endl;
        cin >> opcionChar;
        opcion = validarNumInt(opcionChar);

        switch (opcion)
        {
        case 1:
            c.llenar();
            break;
        case 2:
            c.consultar_inicio();
            break;
        case 3:
            c.consultar_final();
            break;
        case 4:
            c.eliminar();
            break;
        case 5:
            c.mostrar_cola();
            break;
        }

    } while (opcion != 6);
}