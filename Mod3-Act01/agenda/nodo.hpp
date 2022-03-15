#ifndef NODO_H
#define NODO_H
#pragma once
#include "contacto.hpp"
using namespace std; 

class nodo
{
public:
    contacto dato;
    nodo *siguiente;
    nodo();
    nodo(contacto e)
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