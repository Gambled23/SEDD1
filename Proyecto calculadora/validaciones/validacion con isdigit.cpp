#include <iostream>
using namespace std;

int main()
{
    char dato = '\x0'; //Inicializar el dato null
    system("cls");

    cout<<"Ingrese un caracter\n";
    cin>>dato;
    if (isdigit (dato)) //Si dato es numero
    {
        cout<<"El dato ingresado es numero\n";
    }else
    {
        cout<<"El dato ingresado NO es numero\n";
    }
    system("PAUSE>>cls");
    return 0;
}