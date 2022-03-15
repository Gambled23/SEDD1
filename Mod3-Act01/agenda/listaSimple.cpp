#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#pragma once
using namespace std;
int ID = 1;
int tamanoAgenda;
class listaSimple
{
public:
    listaSimple();
    nodo *h; // Puntero que apunta a inicio
    void inicializa();
    void insertaInicio(contacto);
    void insertarFinal(contacto);
    void buscarID(int);
    void buscarPosicion(int);
    void buscarNombre(string);
    void mostrarLista();
    void tamanoLista();
    void eliminarElemento(int);
    void eliminarLista(); // TODO

private:
};

listaSimple::listaSimple()
{
    h = nullptr; // Inicia apuntando a null
}

void listaSimple::inicializa()
{
    h = nullptr;
}

//* *OPERACIONES
void listaSimple::insertaInicio(contacto n)
{
    nodo *nuevo_nodo = new nodo(n);
    nodo *aux1 = h;
    h = nuevo_nodo;
    nuevo_nodo->siguiente = aux1;
    nuevo_nodo->dato.id = ID;
    ID++;
}

void listaSimple::insertarFinal(contacto n)
{
    nodo *nuevo_nodo = new nodo(n);
    if (h == nullptr)
    {
        h = nuevo_nodo;
    }
    nodo *aux1 = h;
    nodo *aux2;
    while (aux1 != nullptr)
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    aux2->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = aux1;
}
void listaSimple::buscarID(int n)
{
    bool bandera = false;
    nodo *aux = new nodo();
    aux = h;
    while (aux != nullptr and !bandera)
    {
        if (aux->dato.id == n)
        {
            bandera = true;
        }
        else
        {
            aux = aux->siguiente;
        }
    }
    if (bandera)
    {
        cout << "ID: " << aux->dato.id << endl;
        cout << "Nombre: " << aux->dato.nombre << endl;
    }
    else
    {
        cout << "Elemento no encontrado\n";
    }
}
void listaSimple::buscarPosicion(int n)
{
    bool bandera = false;
    nodo *aux = new nodo();
    aux = h;
    int i = 0;
    listaSimple::tamanoLista();
    if (n <= tamanoAgenda)
    {
        do
        {
            aux = aux->siguiente;
            i++;
        } while (i < n);
        if (aux != nullptr)
        {
            cout << "ID: " << aux->dato.id << endl;
            cout << "Nombre: " << aux->dato.nombre << endl;
        }
        else
        {
            cout << "Elemento no encontrado\n";
        }
    }
}
void listaSimple::buscarNombre(string n)
{
    bool bandera = false;
    nodo *aux = new nodo();
    aux = h;
    while (aux != nullptr and !bandera)
    {
        if (aux->dato.nombre == n)
        {
            bandera = true;
        }
        else
        {
            aux = aux->siguiente;
        }
    }
    if (bandera)
    {
        cout << "ID: " << aux->dato.id << endl;
        cout << "Nombre: " << aux->dato.nombre << endl;
    }
    else
    {
        cout << "Elemento no encontrado\n";
    }
}
void listaSimple::mostrarLista()
{
    nodo *actual = new nodo();
    actual = h;
    while (actual != nullptr)
    {
        cout << "Nombre del contacto: " << actual->dato.nombre << endl;
        cout << "ID del contacto: " << actual->dato.id << endl
             << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

void listaSimple::tamanoLista()
{
    nodo *actual = new nodo();
    actual = h;
    int i = 0;
    while (actual != nullptr)
    {
        i++;
        actual = actual->siguiente;
    }
    cout << "La lista tiene " << i << " elementos" << endl;
    tamanoAgenda = i;
}
void listaSimple::eliminarElemento(int n)
{
    if (h != nullptr)
    {
        nodo *aux_borrar;
        nodo *anterior = nullptr;
        aux_borrar = h;
        while ((aux_borrar != nullptr) && (aux_borrar->dato.id != n)) // Recorrer lista
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == nullptr) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "La ID no existe en la lista\n";
        }
        else if (anterior == nullptr) // El primer elemento es el que se elimina
        {
            h = h->siguiente;
            cout << "El contacto con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else // El elemento que se elimina no es el primer elemento
        {
            anterior->siguiente = aux_borrar->siguiente;
            cout << "El contacto con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
    }
    else
    {
        cout << "Lista vacia\n";
    }
}
void listaSimple::eliminarLista()
{
    nodo *aux_borrar;
    do
    {
        aux_borrar = h;
        h = aux_borrar->siguiente;
        delete aux_borrar;
    } while (h != nullptr);
}
#endif