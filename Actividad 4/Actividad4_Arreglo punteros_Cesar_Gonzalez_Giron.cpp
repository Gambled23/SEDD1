#include <iostream>
#include <cstdlib>

using namespace std;
int mayor(int *); //prototipo funcion
int vector[] = {78, 5, 7, 9, 20, 15};

int main()
{
    int *pv;
    pv = &vector[0];
    int m = mayor(*&pv);
    cout << "El numero mayor es:" << m;
    system("PAUSE");
    return 0;
}

int mayor(int *pv)
{
    int may = 0;
    for (int i = 0; i < 6; i++)
    {
        if (*(pv+i) > may)
            may = *(pv+i);
    }
    return may;
}