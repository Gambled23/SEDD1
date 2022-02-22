#include <iostream>
#include <cstdlib>

using namespace std;
void menu();
// Clases
class cuadrado
{
private:
    double lado;
    double area;

public:
    void setLado(double);
    double getLado();
    void calcularArea(double);
    double getArea();
};
class triangulo
{
private:
    double base;
    double altura;
    double area;

public:
    void setBase(double);
    double getBase();
    void setAltura(double);
    double getAltura();
    void calcularArea(double);
    double getArea();
};
class rectangulo
{
private:
    double base;
    double altura;
    double area;

public:
    void setBase(double);
    double getBase();
    void setAltura(double);
    double getAltura();
    void calcularArea();
    double getArea();
    rectangulo(double, double);
};

//*Constructores triangulo
void triangulo::setBase(double x)
{
    base = x;
}
double triangulo::getBase()
{
    return base;
}
void triangulo::setAltura(double x)
{
    altura = x;
}
double triangulo::getAltura()
{
    return altura;
}
void triangulo::calcularArea(double x)
{
    area = (base * altura) / 2;
}
double triangulo::getArea()
{
    return area;
}
//*Constructores cuadrado
void cuadrado::setLado(double x)
{
    lado = x;
}
double cuadrado::getLado()
{
    return lado;
}
void cuadrado::calcularArea(double x)
{
    area = lado * lado;
}
double cuadrado::getArea()
{
    return area;
}
//*Constructores rectangulo
void rectangulo::setBase(double x)
{
    base = x;
}
double rectangulo::getBase()
{
    return base;
}
void rectangulo::setAltura(double x)
{
    altura = x;
}
double rectangulo::getAltura()
{
    return altura;
}
void rectangulo::calcularArea()
{
    area = base * altura;
}
double rectangulo::getArea()
{
    return area;
}
rectangulo::rectangulo(double _base, double _altura)
{
    base = _base;
    altura = _altura;
}
int main()
{
    rectangulo rect1(12, 5);
    rect1.calcularArea();
    cout << rect1.getArea() << endl;
    system("PAUSE");
    return 0;
}
void menu()
{
    int opc;
    cout << "\tM E N U" << endl
         << "1)Cuadrado" << endl
         << "2)Rectangulo" << endl
         << "3)Triangulo" << endl
         << endl;
    cin >> opc;
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
    default:
        cout << "Opcion incorrecta" << endl;
        break;
    }
}