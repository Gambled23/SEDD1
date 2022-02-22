#include <iostream>
#include <cstdlib>
using namespace std;
void binario(int *);
int a = 0;
int main(int argc, char **argv)
{
    system("cls");
    cout << "ingrese numero 1" << endl;
    cin >> a;
    int *aPtr = &a;
    binario(aPtr);
    system("PAUSE");
    return 0;
}
void binario(int *numero)
{
    int i = 0, binario[100];
    int cociente = 0;
    int residuo = 0;
    while (*numero / 2 > 0)
    {
        cociente = *numero / 2;
        residuo = *numero % 2;
        *numero = cociente;
        binario[i] = residuo;
        //cout << residuo;
        i++;
    }
    int aux = i;
    cout << cociente;
    for (size_t j = 0; j < i; j++)
    {
        cout<<binario[aux-1];
        aux--;
    }
    cout<<endl;
}