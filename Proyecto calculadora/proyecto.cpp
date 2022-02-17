#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>

using namespace std;

//*Prototipos
int *operaciones(int *, int *, char);
// Conversiones
void dec_to_bin_oct(int *, int);
void bin_oct_to_dec(int *, int);
void decimal_hexadecimal(int *);
void hexadecimal_decimal(char []);
// Resto de funciones
void menu();                     // menu de operaciones
int pedir_num();                 // Pedir y validar 1 numero
bool validacion_isdigit(char *); // Para validar si lo ingresado es un numero y no una letra

//?Variables globales
int *ptr1, *ptr2 = nullptr;
char *ptr3;
int a = 0;

int main(int argc, char **argv)
{

    menu();
    system("pause>>cls");
    return 0;
}

void menu()
{
    int n1 = 0, n2 = 0;
    char opc = 'a';
    char hexC[100], *charPtr1;
    while (opc != 'X')
    {
        system("cls");
        cout << " M E N U" << endl;
        cout << "A)Suma" << endl;
        cout << "B)Resta" << endl;
        cout << "C)Multiplicacion" << endl;
        cout << "D)Division" << endl;
        cout << "E)Potencia" << endl;
        cout << "F)Factorial" << endl;
        cout << "G)Decimal - Binario" << endl;
        cout << "H)Binario - Decimal" << endl;
        cout << "I)Decimal - Octal" << endl;
        cout << "J)Octal- Decimal" << endl;
        cout << "K)Decimal - Hexadecimal" << endl;
        cout << "L)Hexadecimal - Decimal" << endl;
        cout << endl
             << "X)Salir" << endl;
        cin >> opc;
        opc = toupper(opc); // Convertir opc a mayusculas para el switch
        ptr3 = &opc;
        if (validacion_isdigit(ptr3) == false) // Si se ingreso un caracter en opc
        {
            switch (opc)
            {
            case 'X':
                cout << "Gracias por tu preferencia" << endl;
                break;
            case 'A': // Suma
                cout << "Ingrese numero 1:" << endl;
                n1 = pedir_num();
                cout << "Ingrese numero 2:" << endl;
                n2 = pedir_num();
                ptr1 = &n1;
                ptr2 = &n2;
                cout << "El resultado de la suma es: " << *operaciones(ptr1, ptr2, '+') << endl;
                break;
            case 'B': // Resta
                cout << "Ingrese numero 1:" << endl;
                n1 = pedir_num();
                cout << "Ingrese numero 2:" << endl;
                n2 = pedir_num();
                ptr1 = &n1;
                ptr2 = &n2;
                cout << "El resultado de la resta es: " << *operaciones(ptr1, ptr2, '-') << endl;
                break;
            case 'C': // Multiplicacion
                cout << "Ingrese numero 1:" << endl;
                n1 = pedir_num();
                cout << "Ingrese numero 2:" << endl;
                n2 = pedir_num();
                ptr1 = &n1;
                ptr2 = &n2;
                cout << "El resultado de la multiplicacion es: " << *operaciones(ptr1, ptr2, '*') << endl;
                break;
            case 'D': // Division
                cout << "Ingrese numero 1:" << endl;
                n1 = pedir_num();
                cout << "Ingrese numero 2:" << endl;
                n2 = pedir_num();
                ptr1 = &n1;
                ptr2 = &n2;
                cout << "El resultado de la division es: " << *operaciones(ptr1, ptr2, '/') << endl;
                break;
            case 'E': // Potencia
                cout << "Ingrese base:" << endl;
                n1 = pedir_num();
                cout << "Ingrese potencia:" << endl;
                n2 = pedir_num();
                ptr1 = &n1;
                ptr2 = &n2;
                cout << "El resultado de la potencia es: " << *operaciones(ptr1, ptr2, '^') << endl;
                break;
            case 'F': // Factorial
                cout << "Ingrese numero 1:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                cout << "El resultado del factorial es: " << *operaciones(ptr1, ptr2, '!') << endl;
                break;
            case 'G': // Decimal-Binario
                cout << "Ingrese numero decimal:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                dec_to_bin_oct(ptr1, 2);
                break;
            case 'H': // Binario-Decimal
                cout << "Ingrese numero binario:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                bin_oct_to_dec(ptr1, 2);
                break;
            case 'I': // Decimal-Octal
                cout << "Ingrese numero decimal:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                dec_to_bin_oct(ptr1, 8);
                break;
            case 'J': // Octal-Decimal
                cout << "Ingrese numero octal:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                bin_oct_to_dec(ptr1, 8);
                break;
            case 'K': // Decimal-Hexadecimal
                cout << "Ingrese numero decimal:" << endl;
                n1 = pedir_num();
                ptr1 = &n1;
                decimal_hexadecimal(ptr1);
                break;
            case 'L': // Hexadecimal-Decimal
            {
                cout << "Ingrese numero hexadecimal:" << endl;
                cin >> hexC;
                strupr(hexC);
                charPtr1 = &hexC[0];
                hexadecimal_decimal(charPtr1); // convierte la cadena a mayusculas antes de enviarla

                // hexadecimal_decimal(charPtr1);
                break;
            }
            default:

                cout << "La opcion indicada no existe" << endl;
                cout << "Recuerda ingresar un caracter de la A-L, o ingresa X para salir" << endl;
                break;
            }
        }
        else // Si se ingreso un caracter en el opc que no es digito
        {
            cout << "Favor de ingresar un caracter de la A-L, NO un numero, o ingresa X para salir" << endl;
        }
        system("PAUSE");
    }
}
// Pedir numeros
int pedir_num()
{
    int aux;
    char n1[100], *n1Ptr, auxChar;
    bool digito = false;
    cin >> n1;
    n1Ptr = &n1[0];
    digito = validacion_isdigit(n1Ptr);
    while (digito == false)
    {
        cout << "Ingrese un numero entero, no otro caracter";
        cin >> n1;
        n1Ptr = &n1[0];
        digito = validacion_isdigit(n1Ptr);
    }
    aux = atoi(n1Ptr); // Convertir el char a int
    return aux;
}
// Validar si es un numero
bool validacion_isdigit(char *a)
{
    bool digito;
    if (isdigit(*a)) // Si dato es numero
    {
        digito = true;
    }
    else
    {
        digito = false;
    }
    return digito;
}
int *operaciones(int *n1, int *n2, char ope)
{
    int *res = (int *)malloc(sizeof(int));
    switch (ope)
    {
    case '+':
        *res = *n1 + *n2;
        break;
    case '-':
        *res = *n1 - *n2;
        break;
    case '*':
        *res = *n1 * *n2;
        break;
    case '/':
        *res = *n1 / *n2;
        break;
    case '!':
        *res = *n1;
        for (int i = 1; i < *n1; i++)
        {
            *res = (*res) * (i);
        }
        break;
    case '^':
        *res = *n1;
        for (int i = 1; i < *n1; i++)
        {
            *res = (*res) * (i);
        }
        break;
    default:
        cout << "Si estas viendo esto hay un error jeje, corrigelo";
        break;
    }
    return res;
}

void dec_to_bin_oct(int *a, int conv)
{
    int binInt[100];
    int i = 99;
    int cociente = 0;
    int residuo = 0;
    while (*a / conv > 0)
    {
        cociente = *a / conv;
        residuo = *a % conv;
        *a = cociente;
        binInt[i] = residuo;
        i--;
    }
    binInt[i] = cociente;
    cout << "El numero convertido es: ";
    for (size_t j = i; j < 100; j++)
    {
        cout << binInt[j];
    }
    cout << endl;
}
void bin_oct_to_dec(int *a, int sistema)
{
    int n1 = 0, i = 0, aux;
    while (*a != 0)
    {
        aux = *a % 10;
        *a /= 10;
        n1 += aux * pow(sistema, i);
        i++;
    }
    cout << "El numero en decimal es: " << n1 << endl;
}
void decimal_hexadecimal(int *a)
{
    int aux, i = 0;
    char hexCadena[50];
    while (*a != 0)
    {
        aux = *a % 16;
        if (aux < 10)
            aux = aux + 48;
        else
            aux = aux + 55;
        hexCadena[i] = aux;
        i++;
        *a = *a / 16;
    }
    cout << "El numero en hexadecimal es: ";
    for (i = i - 1; i >= 0; i--)
    {
        cout << hexCadena[i];
    }
    cout << endl;
}
void hexadecimal_decimal(char a[])
{
    int tam = strlen(a);
    int aux1 = 1;
    int aux2 = 0;
    for (int i = tam - 1; i >= 0; i--)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            aux2 += (a[i] - 48) * aux1;
            aux1 = aux1 * 16;
        }
        else if (a[i] >= 'A' && a[i] <= 'F')
        {
            aux2 += (a[i] - 55) * aux1;
            aux1 = aux1 * 16;
        }
    }
    cout << "El numero en decimal es: " << aux2 << endl;
}