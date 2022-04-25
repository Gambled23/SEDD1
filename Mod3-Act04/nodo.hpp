#ifndef NODO_H
#define NODO_H
#pragma once
using namespace std; 

class nodo
{
public:
    int dato;
    nodo *siguiente;
    nodo();
    nodo(int e)
    {
        dato = e;
        siguiente = nullptr;
    };

private:
};
nodo::nodo()
{
    siguiente = nullptr;
}
#endif