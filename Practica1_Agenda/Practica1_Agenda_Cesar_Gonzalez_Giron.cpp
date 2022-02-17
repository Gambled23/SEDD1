#include <iostream>
#include <cstring>

using namespace std;

struct agenda
{
    int id;
    char nombre[30];
    char direccion[30];
    char email[30];
    char telefono[10];
} a[5];

int index = 0;   //Contador de cuantos espacios quedan disponibles
int indexID = 0; //Contador de cuantos contactos se han anadido en todo el programa, para que no se repita la ID
void RegistrarContacto()
{
    a[index].id = indexID + 1;
    cout << "Usted tiene " << 5 - index << " espacios disponibles\n";
    cout << "Ingrese Nombre: " << endl;
    cin >> a[index].nombre;
    cout << "Ingrese Direccion: " << endl;
    cin >> a[index].direccion;
    cout << "Ingrese Email: " << endl;
    cin >> a[index].email;
    cout << "Ingrese Telefono: " << endl;
    cin >> a[index].telefono;
    cout << "Se ha guardado el contacto en la ID " << a[index].id << endl;
    index++;
    indexID++;
}
int BuscarContacto(int id)
{
    int posicion = -1, x = 0;
    bool ban = false;
    while (x < 5 && ban == false)
    {
        if (id == a[x].id)
        {
            ban = true;
            posicion = x;
        }
        x++;
    }
    return posicion;
}
void MostrarContacto(int pos)
{
    cout << "ID: " << a[pos].id << endl;
    cout << "Nombre: " << a[pos].nombre << endl;
    cout << "Direccion: " << a[pos].direccion << endl;
    cout << "Email: " << a[pos].email << endl;
    cout << "Telefono: " << a[pos].telefono << endl;
}
void EditarContacto(int pos)
{
    int continuarEditando = 0, editar;
    do
    {
        cout << "Que parte del contacto quieres editar?\n";
        cout << "1. Nombre" << endl;
        cout << "2. Direccion" << endl;
        cout << "3. Email" << endl;
        cout << "4. Telefono" << endl;
        cin >> editar;
        //Editar
        switch (editar)
        {
        case 1:
            cout << "Ingrsa el nuevo nombre" << endl;
            cin >> a[pos].nombre;
            cout << "Se ha guardado el nuevo nombre" << endl;
            break;
        case 2:
            cout << "Ingrsa la nueva direccion" << endl;
            cin >> a[pos].direccion;
            cout << "Se ha guardado la nueva direccion" << endl;
            break;
        case 3:
            cout << "Ingrsa el nuevo email" << endl;
            cin >> a[pos].email;
            cout << "Se ha guardado el nuevo email" << endl;
            break;
        case 4:
            cout << "Ingrsa el nuevo telefono" << endl;
            cin >> a[pos].telefono;
            cout << "Se ha guardado el nuevo telefono" << endl;
            break;
        }
        cout << "Quieres seguir editando?\n1. Si\n2. No\n";
        cin >> continuarEditando;
    } while (continuarEditando != 2);
}
void RemoverContacto(int pos)
{
    char vacio[30];
    int remover = 0;
    cout << "Esta seguro que quiere remover el contacto: " << a[pos].nombre << "?\n ";
    cout << "0. No\n 1. Si\n";
    cin >> remover;
    if (remover == 1) //Copia una cadena vacia
    {
        strcpy(a[pos].direccion, vacio);
        strcpy(a[pos].email, vacio);
        strcpy(a[pos].nombre, vacio);
        strcpy(a[pos].telefono, vacio);
        index--;
    }
}

void menu()
{
    int opcMenu = 0, id = 0;
    cout << "1) Registro Contacto" << endl;
    cout << "2) Buscar Contacto" << endl;
    cout << "3) Editar Contacto" << endl;
    cout << "4) Remover Contacto" << endl;
    cout << "5) Salir" << endl;
    cout << "Seleccione una opcion" << endl;
    cin >> opcMenu;
    switch (opcMenu)
    {
    case 1:
        RegistrarContacto();
        break;
    case 2:
        cout << "Ingrese Id a Buscar" << endl;
        cin >> id;
        MostrarContacto(BuscarContacto(id));
        break;
    case 3:
        cout << "Ingrese Id del contacto a editar" << endl;
        cin >> id;
        EditarContacto(BuscarContacto(id));
        break;
    case 4:
        cout << "Ingrese Id del contacto a remover" << endl;
        cin >> id;
        RemoverContacto(BuscarContacto(id));
        break;
    case 5:
        cout << "Hasta pronto" << endl;
        break;
    default:
        cout << "La opcion que ingreso es incorrecta" << endl;
        break;
    }
}
int opc = 0;
int main(int argc, char **argv)
{
    do
    {
        system("cls");
        menu();
        cout << "Continuar?\n  1.Si\n  2.No\n"
             << endl;
        cin >> opc;
    } while (opc != 2);
    return 0;
}