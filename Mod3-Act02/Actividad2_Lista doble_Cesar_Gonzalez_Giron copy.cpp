#include <iostream>
using namespace std;
int tamanoLST = 0;
template <class TIPO>
class List;
template <class TIPO>
class Node
{
public:
    TIPO dato;
    Node<TIPO> *siguiente;
    Node<TIPO> *anterior;
    Node();
    Node(TIPO e)
    {
        dato = e;
        siguiente = nullptr;
        anterior = nullptr;
    }
    friend class List<TIPO>; // funcion amiga que permite sobrecargar la lista
private:
};
template <class TIPO>
Node<TIPO>::Node()
{
    siguiente = nullptr;
    anterior = nullptr;
}
template <class TIPO>
class List
{ // objeto lista
public:
    List() : h(NULL) {}
    ~List();
    Node<TIPO> *h = nullptr, *t = nullptr;
    void Add(TIPO v);
    void remove(TIPO v);
    void print();
    void siguiente();
    void anterior();
    void ordenar();
    void tamanoLista();
    void primerElemento();
    void ultimoElemento();
private:
    Node<TIPO> *ptrList; // puntero de la lista
};
template <class TIPO>
List<TIPO>::~List() // Destructor de lca clase
{
    h = nullptr;
    t = nullptr;
    Node<TIPO> *aux;
    while (h)
    {
        aux = h;
        h = h->siguiente;
        delete aux;
    }
}
template <class TIPO>
void List<TIPO>::Add(TIPO v) // Agregar al Nodo
{
    Node<TIPO> *nuevo_nodo;
    nuevo_nodo = new Node<TIPO>(v);
    if (h == nullptr) // Si la lista esta vacia
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else // Si no esta vacia
    {
        h->anterior = nuevo_nodo;
        nuevo_nodo->siguiente = h;
        h = nuevo_nodo;
    }
}
template <class TIPO>
void List<TIPO>::remove(TIPO v)
{
    if (h != nullptr)
    {
        Node<TIPO> *aux_borrar;
        aux_borrar = h;
        while ((aux_borrar != nullptr) && (aux_borrar->dato != v)) // Recorrer lista
        {
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == nullptr) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "La ID no existe en la lista\n";
        }
        else if ((aux_borrar == h) and (aux_borrar == t) and (t == h)) // Si es el unico elemento en la lista
        {
            h = nullptr;
            t = h;
            delete aux_borrar;
        }
        else if (aux_borrar->anterior == nullptr) // El primer elemento es el que se elimina
        {
            h = h->siguiente; // el inicio de la lista se cambia, pues se elimino el inicio
            h->anterior = nullptr;
            delete aux_borrar;
        }
        else if (aux_borrar->siguiente == nullptr) // El elemento que se elimina es del final
        {
            t = t->anterior;
            t->siguiente = nullptr;
            delete aux_borrar;
        }
        else // El elemento que se elimina esta en medio
        {
            aux_borrar->anterior->siguiente = aux_borrar->siguiente;
            aux_borrar->siguiente->anterior = aux_borrar->anterior;
            delete aux_borrar;
        }
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}
template <class TIPO>
void List<TIPO>::print()
{
    if (h != nullptr)
    {
        Node<TIPO> *actual;       // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
        actual = h;               // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento
        while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
        {
            cout << actual->dato<<"->";
            actual = actual->siguiente; // Recorrer un nodo
        }
        cout << endl;
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}
template <class TIPO>
void List<TIPO>::tamanoLista()
{
    Node<TIPO> *actual;
    actual = h;
    int i = 0;
    while (actual != nullptr)
    {
        i++;
        actual = actual->siguiente;
    }
    tamanoLST = i;
}
template <class TIPO>
void List<TIPO>::ordenar()
{
    List::tamanoLista();
    Node<TIPO> *actual = h;
    int auxNum;
    for (size_t i = 0; i < tamanoLST; i++)
    {
        actual = h;
        for (size_t j = 0; j < tamanoLST; j++)
        {
            if (actual->siguiente != nullptr)
            {
                if (actual->dato > actual->siguiente->dato)
                {
                    auxNum = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = auxNum;
                }
                actual = actual->siguiente;
            }
        }
    }
}
template <class TIPO>
void List<TIPO>::primerElemento()
{
    cout << "First Node: " << h->dato << endl;
}
template <class TIPO>
void List<TIPO>::ultimoElemento()
{
    cout << "Last Node: " << t->dato << endl;
}
int main()
{
    List<int> list;
    list.Add(20);
    list.Add(10);
    list.Add(40);
    list.Add(30);
    list.ordenar();
    list.print();
    list.primerElemento();
    list.ultimoElemento();
    cout << "\nInsert new nodes: 80,85" << endl;
    list.Add(80);
    list.Add(85);
    list.ordenar();
    list.print();
    list.primerElemento();
    list.ultimoElemento();
    cout << "\nremove Node: 40" << endl;
    list.remove(40);
    list.ordenar();
    list.print();
    system("PAUSE");
}
