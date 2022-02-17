#include <iostream>
#include <cstdlib>
#include <math.h>
//TODO: Calcular apotema en la clase del poligono, no preguntarla
using namespace std;
void menu();
double validacion(double);
double pedir_num(double);        // Pedir y validar 1 numero
bool validacion_isdigit(char *); // Para validar si lo ingresado es un numero y no una letra
// Clases
class cuadrado
{
private:
    double lado;
    double area;

public:
    void setLado(double);
    double getLado();
    void calcularArea();
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
    void calcularArea();
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
};
class poligono
{
private:
    double numLados;
    double lado;
    double apotema;
    double area;

public:
    void setNumLados(double);
    double getNumLados();
    void setLado(double);
    double getLado();
    void setApotema();
    double getApotema();
    void calcularArea();
    double getArea();
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
void triangulo::calcularArea()
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
void cuadrado::calcularArea()
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
//*Constructores poligono
void poligono::setNumLados(double x)
{
    numLados = x;
}
double poligono::getNumLados()
{
    return numLados;
}
void poligono::setLado(double x)
{
    lado = x;
}
double poligono::getLado()
{
    return lado;
}
void poligono::setApotema()
{
    int angulo;
    angulo = 360/(2*numLados);
    apotema = lado / 2 * tan(angulo);
}
double poligono::getApotema()
{
    return apotema;
}
void poligono::calcularArea()
{
    area = (numLados * lado * apotema) / 2;
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
    char opc, num[100];
    double numeroF;
    // Inicializar objetos
    triangulo tri1;
    cuadrado cua1;
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
}
// Validar si es un numero
bool validacion_isdigit(char *a)
{
    bool digito;
    if (isdigit(*a)) // Si dato es numero
    {
        digito = true;
    }
    else
    {
        digito = false;
    }
    return digito;
}