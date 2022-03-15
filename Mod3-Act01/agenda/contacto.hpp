#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class contacto
{
public:
    contacto();
    string nombre;
    int id;
};

contacto::contacto()
{
    nombre = "";
    id = 0;
}
#endif