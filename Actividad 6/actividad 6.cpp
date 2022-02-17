#include <iostream>
#include <cstdlib>
using namespace std;
void Hexadecimal(int);
int a = 0;
int main(int argc, char **argv)
{
    system("cls");
    cout << "ingrese número :" << endl;
    cin >> a;
    Hexadecimal(a);
    return 0;
}
void Hexadecimal(int numero)
{
    int cociente = 0;
    int residuo = 0;
    while (numero / 16 > 0)
    {
        cociente = numero / 16;
        residuo = numero % 16;
        numero = cociente;
        cout << residuo;
    }
    cout << cociente;
}
