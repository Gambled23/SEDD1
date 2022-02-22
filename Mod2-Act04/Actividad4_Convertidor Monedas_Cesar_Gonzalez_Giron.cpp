#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"

using namespace std;
void menu();
void pedirDinero(); // Para ahorrar lineas de codigo

char dineroChar[100];
double dinero;

class moneda
{
private:
    /* data */
public:
};
class peso : public moneda
{
private:
    /* data */
public:
};
class dolar : public moneda
{
private:
    /* data */
public:
};
class euro : public moneda
{
private:
    /* data */
public:
};
class yen : public moneda
{
private:
    /* data */
public:
};
class yuan : public moneda
{
private:
    /* data */
public:
};

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    char opcChar[100];
    int opc = 0;

    while (opc != 9)
    {
        system("cls");
        cout << "1) Peso-Dolar" << endl
             << "2) Dolar-Peso" << endl
             << "3) Peso-Euro" << endl
             << "4) Euro-Peso" << endl
             << "5) Peso-Yen" << endl
             << "6) Yen-Peso" << endl
             << "7) Peso-Yuan" << endl
             << "8) Yuan-Peso" << endl
             << "9) Salir" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout << "Cuantos pesos quieres convertir a dolares?" << endl;
            pedirDinero();

            break;
        case 2:
            cout << "Cuantos dolares quieres convertir a pesos?" << endl;
            pedirDinero();

            break;
        case 3:
            cout << "Cuantos pesos quieres convertir a euros?" << endl;
            pedirDinero();

            break;
        case 4:
            cout << "Cuantos euros quieres convertir a pesos?" << endl;
            pedirDinero();

            break;
        case 5:
            cout << "Cuantos pesos quieres convertir a yenes?" << endl;
            pedirDinero();

            break;
        case 6:
            cout << "Cuantos yenes quieres convertir a pesos?" << endl;
            pedirDinero();

            break;
        case 7:
            cout << "Cuantos pesos quieres convertir a yuanes?" << endl;
            pedirDinero();

            break;
        case 8:
            cout << "Cuantos yuanes quieres convertir a pesos?" << endl;
            pedirDinero();

            break;
        case 9:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }
}
void pedirDinero()
{
    cin >> dineroChar;
    dinero = validarNumDouble(dineroChar);
}