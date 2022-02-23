#include <iostream>
#include <cstdlib>
#include <math.h>
#include "validaciones.hpp"
using namespace std;

void menu();
class figuras
{
protected:
    double base;
    double altura;

public:
    void setBase(double);
    double getBase();
    void setAltura(double);
    double getAltura();
};

class cuadrado : public figuras
{
private:
    double area;

public:
    void calcularArea();
    double getArea();
};

class triangulo : public figuras
{
private:
    double area;

public:
    void calcularArea();
    double getArea();
};

class rectangulo : public figuras
{
private:
    double area;

public:
    void calcularArea();
    double getArea();
};

class poligono : public figuras
{
private:
    double numLados;
    double apotema;
    double area;

public:
    void setNumLados(double);
    double getNumLados();
    void setApotema();
    double getApotema();
    void calcularArea();
    double getArea();
};

void figuras::setBase(double _base)
{
    base = _base;
}
void figuras::setAltura(double _altura)
{
    altura = _altura;
}
double figuras::getBase()
{
    return base;
}
double figuras::getAltura()
{
    return altura;
}
void cuadrado::calcularArea()
{
    area = getBase() * getBase();
}
double cuadrado::getArea()
{
    return area;
}
void triangulo::calcularArea()
{
    area = (getBase() * getAltura()) / 2;
}
double triangulo::getArea()
{
    return area;
}
void rectangulo::calcularArea()
{
    area = getBase() * getAltura();
}
double rectangulo::getArea()
{
    return area;
}
void poligono::setNumLados(double x)
{
    numLados = x;
}
double poligono::getNumLados()
{
    return numLados;
}
void poligono::setApotema()
{
    int angulo;
    angulo = 360 / (numLados);
    apotema = getBase() / (2 * (tan(angulo/2)));
    if (apotema < 0)
    {
        apotema = apotema *-1; 
    }
}
double poligono::getApotema()
{
    return apotema;
}
void poligono::calcularArea()
{
    area = (numLados * getBase() * apotema) / 2;
}
double poligono::getArea()
{
    return area;
}

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    char opcChar[100], numeroChar[100];
    int opc;
    double numero;
    // Inicializar objetos
    cuadrado cua1;
    triangulo tri1;
    rectangulo rec1;
    poligono pol1;
    do
    {
        system("cls");
        cout << "\tMenu para areas" << endl
             << "1)Cuadrado" << endl
             << "2)Rectangulo" << endl
             << "3)Triangulo" << endl
             << "4)Poligono regular (5 a 10 lados)" << endl
             << "0)Salir" << endl
             << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        switch (opc)
        {
        case 1:
            cout<<"Ingresa el valor del lado"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            cua1.setBase(numero);
            cua1.calcularArea();
            cout<<"El area del cuadrado es: "<<cua1.getArea()<<endl;

            break;
        case 2:
            cout<<"Ingresa el valor de la base"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            rec1.setBase(numero);
            cout<<"Ingresa el valor de la altura"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            rec1.setAltura(numero);
            rec1.calcularArea();
            cout<<"El area del rectangulo es: "<<rec1.getArea()<<endl;
            break;
        case 3:
            cout<<"Ingresa el valor de la base"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            tri1.setBase(numero);
            cout<<"Ingresa el valor de la altura"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            tri1.setAltura(numero);
            tri1.calcularArea();
            cout<<"El area del triangulo es: "<<tri1.getArea()<<endl;
            break;
        case 4:
            cout<<"Ingresa el numero de lados"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            pol1.setNumLados(numero);
            cout<<"Ingresa el valor de un lado"<<endl;
            cin>>numeroChar;
            numero = validarNumDouble(numeroChar);
            pol1.setBase(numero);
            pol1.setApotema();
            pol1.calcularArea();
            cout<<"El area del poligono es: "<<pol1.getArea()<<endl;
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