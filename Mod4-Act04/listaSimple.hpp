#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#include "validaciones.hpp"
#pragma once

using namespace std;
int tamLista = 0;
class listaSimple
{
public:
    listaSimple();
    nodo *h; // Puntero que apunta a inicio
    nodo *t; // Puntero que apunta a final
    void inicializa();
    void insertaInicio(int);
    void insertarFinal(int);
    void mostrarLista();
    void tamanoLista();
    void buscarElemento(int);
    void eliminarElemento(int);
    void eliminarLista();
    void modificarElemento(int);
    void buscarPorPosicion(int);

private:
};

listaSimple::listaSimple()
{
    h = nullptr; // Inicia apuntando a null
    t = nullptr; // Apuntador a tail
}

void listaSimple::inicializa()
{
    h = nullptr;
    t = nullptr;
}

//* *OPERACIONES
void listaSimple::insertaInicio(int n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    if (!h)
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente = h;
        h = nuevo_nodo;
    }
    t->siguiente = h;
    tamLista++;
}

void listaSimple::insertarFinal(int n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    if (!h)
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else
    {
        t->siguiente = nuevo_nodo;
        t = nuevo_nodo;
    }
    t->siguiente = h;
    tamLista++;
}

void listaSimple::mostrarLista()
{
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento
    int i = 0;
    while (i < tamLista) // Mientras sigamos apuntando a un dato, y no al nullptr, significa que seguimos en la lista
    {
        i++;
        cout << actual->dato << " - "; // Imprimir el dato en el que nos encontramos
        actual = actual->siguiente;    // Recorrer un nodo
    }
    cout << endl;
}

void listaSimple::tamanoLista()
{
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;
    int i = 0;
    while (actual->siguiente != h) // Mientras sigamos apuntando a un dato, y no al nullptr, significa que seguimos en la lista
    {
        i++;
        actual = actual->siguiente; // Recorrer un nodo
        tamLista = i;
    }
    cout << "La lista tiene " << i << " elementos" << endl;
}

void listaSimple::buscarElemento(int n)
{
    bool bandera = false;
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while (actual->siguiente != h) // Mientras sigamos apuntando a un dato, y no al nullptr, significa que seguimos en la lista
    {
        if (actual->dato == n)
        {
            bandera = true; // Se establece en true si encuentra el elemento n a buscar
        }
        actual = actual->siguiente; // Recorrer un nodo
    }
    if (bandera == true)
    {
        cout << "El elemento " << n << " SI se encuentra en la lista\n";
    }
    else
    {
        cout << "El elemento " << n << " NO se encuentra en la lista\n";
    }
}

void listaSimple::eliminarElemento(int n)
{
    if (h != nullptr)
    {
        nodo *aux_borrar;
        nodo *anterior = nullptr;
        aux_borrar = h;
        int i = 0;
        bool bandera = true;
        while ((i < tamLista) && (aux_borrar->dato != n)) // Recorrer lista
        {
            bandera = false;
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
            i++;
            if (aux_borrar->dato == n)
            {
                bandera = true;
            }
        }
        if (!bandera) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "El elemento no existe en la lista\n";
        }
        else if (anterior == nullptr) // El primer elemento es el que se elimina
        {
            h = h->siguiente;                                      // el inicio de la lista se cambia, pues se elimino el inicio
            cout << "El elemento '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
            tamLista--;
        }
        else // El elemento que se elimina no es el primer elemento
        {
            anterior->siguiente = aux_borrar->siguiente;           // Se apunta el nodo anterior del eliminado al nodo siguiente del eliminado
            cout << "El elemento '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
            if (aux_borrar->siguiente == nullptr)
            {
                t = anterior;
            }
            tamLista--;
        }
    }
    t->siguiente = h;
}

void listaSimple::eliminarLista()
{
    nodo *aux; // Crear auxiliar que apunte al inicio de la lista
    if (h)
    {
        int i = 0;
        while (i < tamLista) // Para hacer la eliminacion de cada nodo hasta que este vacia
        {
            aux = h;
            h = aux->siguiente;
            delete aux;
            i++;
        }
        h = nullptr;
        t = nullptr;
        tamLista = 0;
    }
    else
    {
        cout << "Lista vacia\n";
    }
    cout << "La lista ha sido vaciada\n";
    t = nullptr;
}
void listaSimple::modificarElemento(int n)
{
    nodo *actual = h;
    bool bandera = false;
    int dato;
    char datoChar[100];
    while (actual->siguiente != h and !bandera) // Mientras sigamos apuntando a un dato, y no al nullptr, significa que seguimos en la lista
    {
        if (actual->dato == n)
        {
            bandera = true;
        }
        else
        {
            actual = actual->siguiente; // Recorrer un nodo
        }
    }
    if (bandera)
    {
        cout << "Cual es el nuevo elemento por el que quieres reemplazar el '" << actual->dato << "'?";
        cin >> datoChar;
        dato = validarNumInt(datoChar);
        actual->dato = dato;
        cout << "El elemento ha sido reemplazado\n";
    }
}
void listaSimple::buscarPorPosicion(int n)
{
    nodo *aux = h;
    int i = 1;
    if (h)
    {
        while (i < n)
        {
            aux = aux->siguiente;
            i++;
        }
        cout << "El dato en la posicion " << n << " es '" << aux->dato << "'\n";
    }
    else
    {
        cout << "Lista vacia\n";
    }
}

#endif