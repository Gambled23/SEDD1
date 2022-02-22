#include <iostream>
#include <cstdlib>
using namespace std;

void Hexadecimal(int *);
int num;
int main(int argc, char **numerorgv)
{
    system("cls");
    cout << "ingrese número :" << endl;
    cin >> num;
    int *numPtr = &num;
    Hexadecimal(numPtr);
    system("PAUSE");
    return 0;
}
void Hexadecimal(int *numero)
{
    int aux, i = 0;
    char hexCadena[50];
    while (*numero != 0)
    {
        aux = *numero % 16;
        if (aux < 10)
            aux = aux + 48;
        else
            aux = aux + 55;
        hexCadena[i] = aux;
        i++;
        *numero = *numero / 16;
    }
    cout << "El numero en hexadecimal es: ";
    for (i = i - 1; i >= 0; i--)
    {
        cout << hexCadena[i];
    }
    cout << endl;
}
