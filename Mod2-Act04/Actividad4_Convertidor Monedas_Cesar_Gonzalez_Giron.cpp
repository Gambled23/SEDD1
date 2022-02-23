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
    double moneda;
    double monedaConvertida;
public:
    void setMoneda(double);
    double getMoneda();
    void setMonedaConvertida(double);
    double getMonedaConvertida();
};
class peso : public moneda
{
public:
    void pesoDolar();
    void pesoEuro();
    void pesoYen();
    void pesoYuan();
};
class dolar : public moneda
{
public:
    void convertirMoneda();
};
class euro : public moneda
{
public:
    void convertirMoneda();
};
class yen : public moneda
{
public:
    void convertirMoneda();
};
class yuan : public moneda
{
public:
    void convertirMoneda();
};
void moneda::setMoneda(double _moneda)
{
    moneda = _moneda;
}
double moneda::getMoneda()
{
    return moneda;
}
void moneda::setMonedaConvertida(double _monedaConvertida)
{
    monedaConvertida = _monedaConvertida;
}
double moneda::getMonedaConvertida()
{
    return monedaConvertida;
}
void peso::pesoDolar()
{
    setMonedaConvertida(getMoneda() * 0.049);
}
void peso::pesoEuro()
{
    setMonedaConvertida(getMoneda() * 0.043);
}
void peso::pesoYen()
{
    setMonedaConvertida(getMoneda() * 5.66);
}
void peso::pesoYuan()
{
    setMonedaConvertida(getMoneda() * 0.31);
}
void dolar::convertirMoneda()
{
    setMonedaConvertida(getMoneda() * 20.29);
}
void euro::convertirMoneda()
{
    setMonedaConvertida(getMoneda() * 23);
}
void yen::convertirMoneda()
{
    setMonedaConvertida(getMoneda() * 0.18);
}
void yuan::convertirMoneda()
{
    setMonedaConvertida(getMoneda() * 3.21);
}
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
    peso p1;
    dolar d1;
    euro e1;
    yen yen1;
    yuan yua1;

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
            p1.setMoneda(dinero);
            p1.pesoDolar();
            cout<<dinero<<" pesos son "<<p1.getMonedaConvertida()<<" dolares"<<endl;
            break;
        case 2:
            cout << "Cuantos dolares quieres convertir a pesos?" << endl;
            pedirDinero();
            d1.setMoneda(dinero);
            d1.convertirMoneda();
            cout<<dinero<<" dolares son "<<d1.getMonedaConvertida()<<" pesos"<<endl;
            break;
        case 3:
            cout << "Cuantos pesos quieres convertir a euros?" << endl;
            pedirDinero();
            p1.setMoneda(dinero);
            p1.pesoEuro();
            cout<<dinero<<" pesos son "<<p1.getMonedaConvertida()<<" euros"<<endl;
            break;
        case 4:
            cout << "Cuantos euros quieres convertir a pesos?" << endl;
            pedirDinero();
            e1.setMoneda(dinero);
            e1.convertirMoneda();
            cout<<dinero<<" euros son "<<e1.getMonedaConvertida()<<" pesos"<<endl;
            break;
        case 5:
            cout << "Cuantos pesos quieres convertir a yenes?" << endl;
            pedirDinero();
            p1.setMoneda(dinero);
            p1.pesoYen();
            cout<<dinero<<" pesos son "<<p1.getMonedaConvertida()<<" yenes"<<endl;
            break;
        case 6:
            cout << "Cuantos yenes quieres convertir a pesos?" << endl;
            pedirDinero();
            yen1.setMoneda(dinero);
            yen1.convertirMoneda();
            cout<<dinero<<" yenes son "<<yen1.getMonedaConvertida()<<" pesos"<<endl;
            break;
        case 7:
            cout << "Cuantos pesos quieres convertir a yuanes?" << endl;
            pedirDinero();
            p1.setMoneda(dinero);
            p1.pesoYuan();
            cout<<dinero<<" pesos son "<<p1.getMonedaConvertida()<<" yuanes"<<endl;
            break;
        case 8:
            cout << "Cuantos yuanes quieres convertir a pesos?" << endl;
            pedirDinero();
            yua1.setMoneda(dinero);
            yua1.convertirMoneda();
            cout<<dinero<<" yuanes son "<<yua1.getMonedaConvertida()<<" pesos"<<endl;
            break;
        case 9:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
        system("PAUSE");
    }
}
void pedirDinero()
{
    cin >> dineroChar;
    dinero = validarNumDouble(dineroChar);
}