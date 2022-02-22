#include <iostream>
#include <cstdlib>

double pedirNum(char[]);
using namespace std;
int main()
{
    char num[100];
    cin>>num;
    cout << pedirNum(num);
    system("PAUSE");
    return 0;
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