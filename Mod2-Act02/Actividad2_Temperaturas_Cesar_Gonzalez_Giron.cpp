#include <iostream>
#include <cstdlib>

// TODO: Validaciones
using namespace std;
void menu();
double pedirNum(char[]);
// Celsius-Kelvin
class celsiusKelvin
{
private:
    double temperatura;
    double conversion;

public:
    void setTemperatura(double);
    double getTemperatura();
    double calcularTemperatura();
};
void celsiusKelvin::setTemperatura(double x)
{
    temperatura = x;
}
double celsiusKelvin::getTemperatura()
{
    return temperatura;
}
double celsiusKelvin::calcularTemperatura()
{
    conversion = temperatura + 273.15;
    return conversion;
}
// Kelvin-Celsius
class kelvinCelsius
{
private:
    double temperatura;
    double conversion;

public:
    void setTemperatura(double);
    double getTemperatura();
    double calcularTemperatura();
};
void kelvinCelsius::setTemperatura(double x)
{
    temperatura = x;
}
double kelvinCelsius::getTemperatura()
{
    return temperatura;
}
double kelvinCelsius::calcularTemperatura()
{
    conversion = temperatura - 273.15;
    return conversion;
}
// Celsius-Fahrenheit
class celsiusFahrenheit
{
private:
    double temperatura;
    double conversion;

public:
    void setTemperatura(double);
    double getTemperatura();
    double calcularTemperatura();
};
void celsiusFahrenheit::setTemperatura(double x)
{
    temperatura = x;
}
double celsiusFahrenheit::getTemperatura()
{
    return temperatura;
}
double celsiusFahrenheit::calcularTemperatura()
{
    conversion = (temperatura * 9 / 5) + 32;
    return conversion;
}
// Fahrenheit-Celsius
class fahrenheitCelsius
{
private:
    double temperatura;
    double conversion;

public:
    void setTemperatura(double);
    double getTemperatura();
    double calcularTemperatura();
};
void fahrenheitCelsius::setTemperatura(double x)
{
    temperatura = x;
}
double fahrenheitCelsius::getTemperatura()
{
    return temperatura;
}
double fahrenheitCelsius::calcularTemperatura()
{
    conversion = (temperatura - 32) * 5 / 9;
    return conversion;
}
int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    celsiusKelvin celKev1;
    kelvinCelsius kelvCel1;
    celsiusFahrenheit celFah1;
    fahrenheitCelsius fahCel1;
    char temperaturaChar[100];
    double temperatura;
    char opcChar[1];
    int opc;
    while (opc != 5)
    {
            system("cls");
            cout << "\tM E N U" << endl
                 << "1)Calcius-Kelvin" << endl
                 << "2)Kelvin-Celsius" << endl
                 << "3)Celsius-Fahrenheit" << endl
                 << "4)Fahrenheit-Celsios" << endl
                 << "5)Salir" << endl
                 << endl;
            cin >> opcChar;
            opc = pedirNum(opcChar);
            switch (opc)
            {
            case 1:
                cout << "Ingresa la temperatura que deseas convertir" << endl;
                cin >> temperaturaChar;
                temperatura = pedirNum(temperaturaChar);
                celKev1.setTemperatura(temperatura);
                cout << temperatura << " celsius es igual a " << celKev1.calcularTemperatura() << " kelvin" << endl;
                break;
            case 2:
                cout << "Ingresa la temperatura que deseas convertir" << endl;
                cin >> temperaturaChar;
                temperatura = pedirNum(temperaturaChar);
                kelvCel1.setTemperatura(temperatura);
                cout << temperatura << " kelvin es igual a " << kelvCel1.calcularTemperatura() << " celsius" << endl;
                break;
            case 3:
                cout << "Ingresa la temperatura que deseas convertir" << endl;
                cin >> temperaturaChar;
                temperatura = pedirNum(temperaturaChar);
                celFah1.setTemperatura(temperatura);
                cout << temperatura << " celsius es igual a " << celFah1.calcularTemperatura() << " fahrenheit" << endl;
                break;
            case 4:
                cout << "Ingresa la temperatura que deseas convertir" << endl;
                cin >> temperaturaChar;
                temperatura = pedirNum(temperaturaChar);
                fahCel1.setTemperatura(temperatura);
                cout << temperatura << " fahrenheit es igual a " << fahCel1.calcularTemperatura() << " celsius" << endl;
                break;
            case 5:
                cout << "Gracias por su preferencia" << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            system("PAUSE");
    }
}

double pedirNum(char dato[])
{
    double numValidado;
    bool bandera = false;
    do
    {
        if (isdigit(dato[0])) // Si dato es numero
        {
            numValidado = atof(dato);
            bandera = true;
        }
        else
        {
            cout << "El dato ingresado NO es numero, ingresa otro\n";
            cin>>dato;
        }
    } while (bandera == false);
    return numValidado;
}