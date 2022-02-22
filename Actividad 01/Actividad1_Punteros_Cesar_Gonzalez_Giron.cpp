#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
    int numero = 0;
    int *ptr = NULL;
    cout << "Ingrese un numero :" << endl;
    cin >> numero;
    ptr = &numero;
    cout << "Valor de la variable : " << *ptr << endl;
    cout << "Direccion de la variable : " << &ptr << endl;
    system("PAUSE");
    return 0;
}