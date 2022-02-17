#include <iostream>
#include <cstdlib>
 
int factorial(int *numero)
{
    int *aux = numero, aux2 = *numero-1;
    for (size_t i = *aux; i > 1; i--)
    {
        *aux = *aux * (aux2);
        aux2--;
    }
    return(*aux);
}

using namespace std;
int main()
{
    int numero = 0, *numeroPtr;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    numeroPtr = &numero;
    cout<<"El factorial es: "<<factorial(numeroPtr)<<endl;
    system("PAUSE");
    return 0;
}