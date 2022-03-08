#include <iostream>
#include <stdlib.h>
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
    if (lleno() == 0)
    {
        fin++;
        cout << "Ingrese dato " << endl;
        cin >> x;
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
        for (int i = fin; i >= 0; i--)
        {
            if (dato[i] != -1)
            {
                cout << "  " << dato[i];
            }
        }
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
        cin >> opcion;
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