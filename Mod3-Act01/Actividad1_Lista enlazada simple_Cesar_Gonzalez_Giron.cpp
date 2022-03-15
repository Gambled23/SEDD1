#include <iostream>
#include <string.h>
#include <cstdlib>
#include "validaciones.hpp"
using namespace std;
int ID = 1;
template <typename T>
class Nodo
{
public:
    Nodo();
    Nodo(T, T);
    ~Nodo();
    Nodo *next;
    T id;
    T nombre;
    void print();
};
template <typename T>
Nodo<T>::Nodo()
{
    id = NULL;
    nombre = NULL;
    next = NULL;
}

template <typename T>
Nodo<T>::Nodo(T id_, T nombre_)
{
    id = id_;
    nombre = nombre_;
    next = NULL;
}

template <typename T>
void Nodo<T>::print()
{
    cout << "Id:" << id << endl;
    cout << "Nombre:" << nombre << endl;
}

template <typename T>
Nodo<T>::~Nodo()
{
}

template <class T>
class List
{
private:
    Nodo<T> *ptrHead;
    int number_nodo;

public:
    List();
    ~List();
    void add_head(T);
    void add_end(T, T);
    void add_sort(T, T);
    void delete_position(int);
    void print();
    void Search(T);
    void SearchName(T);
    void DeleteAll();
    void Order();
    void Edit(int);
};
template <typename T>
List<T>::List()
{
    number_nodo = 0;
    ptrHead = NULL;
}
template <typename T>
List<T>::~List() {}

// Insertar al inicio
template <typename T>
void List<T>::add_head(T nombre_)
{
    /*Nodo<T> *new_nodo = new Nodo<T>(nombre_);
    new_nodo->id = ID;
    ID++;
    Nodo<T> *temp = ptrHead;
    if (!ptrHead)
    {
        ptrHead = new_nodo;
    }
    else
    {
        new_nodo->next = ptrHead;
        ptrHead = new_nodo;
        while (temp)
        {
            temp = temp->next;
        }
    }
    number_nodo++;*/
}

template <typename T>
void List<T>::add_sort(T id_, T nombre_)
{
    Nodo<T> *new_nodo = new Nodo<T>(id_, nombre_);
    Nodo<T> *temp = ptrHead;
    if (!ptrHead)
    {
        ptrHead = new_nodo;
    }
    else
    {
        if (ptrHead->id == id_)
        {
            new_nodo->next = ptrHead;
            ptrHead = new_nodo;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new_nodo->next = temp->next;
            temp->next = new_nodo;
        }
    }
    number_nodo++;
}
template <typename T>
void List<T>::delete_position(int pos)
{
    Nodo<T> *temp = ptrHead;
    Nodo<T> *temp1 = temp->next;
    if (pos < 1 or pos > number_nodo)
    {
        cout << "Fuera de rango\n";
    }
    else if (pos == 1)
    {
        ptrHead = temp->next;
        delete temp;
        number_nodo--;
    }
    else
    {
        for (int i = 2; i <= pos; i++)
        {
            if (i == pos)
            {
                Nodo<T> *aux_nodo = temp1;
                temp->next = temp1->next;
                delete aux_nodo;
                number_nodo--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

template <typename T>
void List<T>::print()
{
    Nodo<T> *temp = ptrHead;
    if (!ptrHead)
    {
        cout << "La Agenda esta vacia\n";
    }
    else
    {
        while (temp)
        {
            temp->print();
            cout << "\n\n";
            temp = temp->next;
        }
    }
}

template <typename T>
void List<T>::Search(T id_)
{
    Nodo<T> *temp = ptrHead;
    int count1 = 1, count2 = 0;
    while (temp)
    {
        if (temp->id == id_)
        {
            cout << "Encontrado en la posicion:" << count1 << endl;
            count2++;
        }
        temp = temp->next;
        count1++;
    }
    if (count2 == 0)
    {
        cout << "No existe el dato\n";
    }
    cout << "\n\n";
}
template <typename T>
void List<T>::SearchName(T nombre_)
{
    Nodo<T> *temp = ptrHead;
    int count1 = 1, count2 = 0;
    while (temp)
    {
        if (temp->nombre == nombre_)
        {
            cout << "Encontrado en la posicion:" << count1 << endl;
            count2++;
        }
        temp = temp->next;
        count1++;
    }
    if (count2 == 0)
    {
        cout << "No existe el dato\n";
    }
    cout << "\n\n";
}

template <typename T>
void List<T>::DeleteAll()
{
    if (ptrHead == NULL)
        cout << "La agenda esta vacia\n";
    else
    {
        Nodo<T> *aux1 = ptrHead;
        Nodo<T> *aux2 = aux1;
        while (aux1 == NULL)
        {
            delete aux1;
            aux1 = aux2->next;
            aux2 = aux2->next;
        }
        ptrHead = NULL;
        number_nodo = 0;
        cout << "Se eliminaron los datos\n";
    }
}

int main()
{
    List<string> list1;
    int element, dimention, pos, dat;
    string id_, nombre_, correo_, numero_, direccion_;
    char opcChar[100];
    int opc;
    do
    {

        cout << "1-.Agregar contacto \n";
        cout << "2-.Buscar contacto.\n";
        cout << "3-.Eliminar contacto.\n";
        cout << "4-.Buscar por posicion\n"; // TODO
        cout << "5-.Invertir\n";            // TODO
        cout << "6-.Buscar por nombre\n";   
        cout << "7-.Ordenar alfabeticamente\n"; // TODO
        cout << "8-.Imprimir datos\n";
        cout << "9-.Modificar\n"; // TODO
        cout << "10-.Eliminar Todo\n";
        cout << "0-.Salir\n";
        cout << "Seleccione un opcion\n";
        cin.sync();
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        
        switch (opc)
        {
        case 1:
            system("cls");
            cin.sync();
            cout << "Nombre \n";
            getline(cin, nombre_);
            list1.add_head(nombre_);
            list1.print();
            break;
        case 2:
            getline(cin, id_);
            cout << "Busca un elemento\n";
            do
            {
                getline(cin, id_);
                if (id_ <= "0" or id_ >= "9")
                {
                    cout << "Ingresa puros numeros" << endl;
                }
            } while (id_ <= "0" or id_ >= "9");
            list1.Search(id_);
            break;
        case 3:
            cout << "Elimina posicion\n";
            cin >> pos;
            list1.delete_position(pos);
            list1.print();
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            cout << "Ingresa el nombre a buscar\n";
            getline(cin, id_);
            list1.SearchName(id_);
            break;
        case 7:
        
            break;
        case 8:
            list1.print();
            break;
        case 9:
            cout << "Ingresa la posicion del dato a modificar\n";
            cin.sync();
            cin >> dat;
            break;
        case 10:
            list1.DeleteAll();
            break;
        case 0:
            cout << "Gracias por su preferencia!" << endl;
            break;
        }
        cout << endl;
        system("pause");
        system("cls");
    } while (opc != 0);
    system("PAUSE");
    return 0;
}