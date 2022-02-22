#include <iostream>
#include <cstdlib>
using namespace std;
void binario(int);
int a = 0;
int main(int argc, char **argv)
{
    system("cls");
    cout << "ingrese numero 1" << endl;
    cin >> a;
    binario(a);
    return 0;
}
void binario(int numero)
{
    int cociente = 0;
    int residuo = 0;
    while (numero / 2 > 0)
    {
        cociente = numero / 2;
        residuo = numero % 2;
        numero = cociente;
        cout << residuo;
    }
    cout << cociente;
}