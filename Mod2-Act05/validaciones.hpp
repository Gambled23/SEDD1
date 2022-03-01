#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <conio.h>

#pragma once

double validarNumDouble(char dato[])
{
    //memaso
    double numValidado;
    bool bandera = false;
    do
    {
        if (isdigit(dato[0])) // Si dato es numero
        {
            numValidado = atof(dato);
            bandera = true;
        }
        else
        {
            std::cout << "El dato ingresado NO es numero, ingresa otro\n";
            std::cin>>dato;
        }
    } while (bandera == false);
    return numValidado;
}

int validarNumInt(char dato[])
{
    char datoAux [1];
    datoAux[0] = dato[0];
    int numValidado;
    bool bandera = false;
    do
    {
        
        if (isdigit(dato[0])) // Si dato es numero
        {
            //datoAux[0] = dato[0];
            numValidado = atof(dato);
            bandera = true;
        }
        else
        {
            std::cout << "El dato ingresado NO es numero, ingresa otro\n";
            std::cin>>dato;
        }
    } while (bandera == false);
    return numValidado;
}

#endif