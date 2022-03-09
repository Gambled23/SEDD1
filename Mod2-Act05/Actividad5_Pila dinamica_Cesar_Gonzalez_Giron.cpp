#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"
using namespace std;
void menu();
class Nodo
{

public:
	int value;
	Nodo *next;
};
int tope = -1;
void push(Nodo *&pila, int n)
{
	Nodo *temp = new Nodo();
	temp->value = n;
	temp->next = pila;
	pila = temp;
	tope++;
};

void pop(Nodo *&pila)
{
	Nodo *temp = pila;
	if (temp)
	{
		pila = temp->next;
		cout << "Eliminado valor '" << temp->value << "'" << endl;
		delete (temp);
		tope--;
	}
	else
	{
		cout << "Pila vacia" << endl;
	}
};

void display(Nodo *&pila)
{
	Nodo *temp = pila;
	if (temp)
	{
		int i = tope;
		system("cls");
		do
		{
			printf("\n\n\t\t%c%c%c%c%c  \n", 201, 205, 205, 205, 187);
			printf("Tope->");
			do
			{
				printf("\t\t%c ", 186, 205);
				cout << temp->value;
				temp = temp->next;
				printf(" %c\n", 186);
				i--;
				if (i >= 0)
				{
					printf("\t\t%c%c%c%c%c\n", 204, 205, 205, 205, 185); // Linea de en medio
				}
				else
				{
					printf("\t\t%c%c%c%c%c\n", 200, 205, 205, 205, 188); // Linea final
				}
			} while (temp);
		} while (temp);
	}
	else
	{
		cout << "PILA VACIA\n\n";
	}
};

int main()
{
	menu();
	system("PAUSE");
};
void menu()
{
	Nodo *pila = NULL;
	int opc, valor;
	char opcChar[100], valorChar[100];
	do
	{
		system("cls");
		display(pila);
		cout << "1) Push" << endl
			 << "2) Pop" << endl
			 << "3) Mostrar pila" << endl
			 << "4) Salir" << endl;
		cin >> opcChar;
		opc = validarNumInt(opcChar);
		switch (opc)
		{
		case 1:
			cout << "Que valor quieres ingresar?" << endl;
			cin >> valorChar;
			valor = validarNumInt(valorChar);
			push(pila, valor);
			break;
		case 2:
			pop(pila);
			break;
		case 3:
			display(pila);
			break;
		case 4:
			cout << "Gracias por su preferencia" << endl;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
		system("PAUSE");
	} while (opc != 4);
};