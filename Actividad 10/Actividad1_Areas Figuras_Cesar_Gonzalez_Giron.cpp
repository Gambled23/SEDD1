#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

void menu();
class figuras
{
private:
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
    area = _base * base;
}
int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    char opc, num[100];
    double numeroF;
    // Inicializar objetos
    /*do
    {
        system("cls");
        cout << "\tMenu para areas" << endl
             << "1)Cuadrado" << endl
             << "2)Rectangulo" << endl
             << "3)Triangulo" << endl
             << "4)Poligono regular (5 a 10 lados)" << endl
             << "0)Salir" << endl
             << endl;
        cin >> opc;
        if (isdigit(opc)) // Si dato es numero
        {
            switch (opc)
            {
            case '0':
                cout << "Gracias por su preferencia"<<endl;
                break;
            case '1':
                cout << "Ingresa lado" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    cua1.setLado(numeroF);
                    cua1.calcularArea();
                    cout << "Area: " << cua1.getArea() << endl;
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }

                break;
            case '2':
                cout << "Ingresa base" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    rec1.setBase(numeroF);
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                cout << "Ingresa altura" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    rec1.setAltura(numeroF);
                    rec1.calcularArea();
                    cout << "Area: " << rec1.getArea() << endl;
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                break;
            case '3':
                cout << "Ingresa base" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    tri1.setBase(numeroF);
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                cout << "Ingresa altura" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    tri1.setAltura(numeroF);
                    tri1.calcularArea();
                    cout << "Area: " << tri1.getArea() << endl;
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                break;
            case '4':
                cout << "Ingresa numero de lados (5 a 10)" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    pol1.setNumLados(numeroF);
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                cout << "Ingresa valor del lado" << endl;
                cin >> num;
                if (validacion_isdigit(num) == true)
                {
                    numeroF = atof(num);
                    pol1.setLado(numeroF);
                    pol1.setApotema();
                    pol1.calcularArea();
                    cout << "Area: " << pol1.getArea() << endl;
                }
                else
                {
                    cout << "Has ingresado un caracter que no es un numero";
                }
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            system("PAUSE");
        }
        else
        {
            cout << "El dato ingresado NO es numero\n";
        }
    } while (opc != '0');
    */
}