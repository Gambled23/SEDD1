#include <iostream>
using namespace std;
double votoa = 0, votob = 0, votoc = 0, porcentaje1, porcentaje2, porcentaje3;
double *ptr1, *ptr2, a, b, c, p1, p2, p3, resp;
//a votos totales de atlas
//b votos totales de chivas
//c votos totales de toluca
int opc = 0;
//contador de votos
double setVotoa(double votoa)
{
    votoa = votoa + 1;
    return votoa;
}
double setVotoc(double votob)
{
    votob = votob + 1;
    return votob;
}
double setVotob(double votoc)
{
    votoc = votoc + 1;
    return votoc;
}
//Porcentajes de votos
double setPorcentajesa(double voto1, double voto2, double voto3)
{
    porcentaje1 = (voto1 * 100) / (voto1 + voto2 + voto3);
    return porcentaje1;
}
double setPorcentajesb(double voto1, double voto2, double voto3)
{
    porcentaje2 = (voto2 * 100) / (voto1 + voto2 + voto3);
    return porcentaje2;
}
double setPorcentajesc(double voto1, double voto2, double voto3)
{
    porcentaje3 = (voto3 * 100) / (voto1 + voto2 + voto3);
    return porcentaje3;
}

int main()
{
    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "Candidato -> Atlas [1]" << endl;
        cout << "Candidato -> Chivas [2]" << endl;
        cout << "Candidato -> Toluca [3]" << endl;
        cout << "Seleccione opcion" << endl;
        cin >> opc;
        cout << endl;
        cout << endl;
        //Registrar votos
        switch (opc)
        {
        case 1:
            votoa = setVotoa(votoa);
            ptr1 = &votoa;
            a = *ptr1;
            break;
        case 2:
            votob = setVotob(votob);
            ptr1 = &votob;
            b = *ptr1;
            break;
        case 3:
            votoc = setVotoc(votoc);
            ptr1 = &votoc;
            c = *ptr1;
            break;
        default:
            cout<<"La opcion ingresada no existe\n";
            break;
        }
        //calcular porcentajes
        porcentaje1 = setPorcentajesa(a, b, c);
        ptr2 = &porcentaje1;
        p1 = *ptr2;
        porcentaje2 = setPorcentajesb(a, b, c);
        ptr2 = &porcentaje2;
        p2 = *ptr2;
        porcentaje3 = setPorcentajesc(a, b, c);
        ptr2 = &porcentaje3;
        p3 = *ptr2;
        //Imprimir todos los datos
        cout << "*********VOTOS**********" << endl;
        cout << " Atlas: " << a << endl;
        cout << " Chivas: " << b << endl;
        cout << " Toluca: " << c << endl;
        cout << endl;
        cout << endl;
        cout << "*****PORCENTAJES********" << endl;
        cout << " % Atlas " << p1 << endl;
        cout << " % Chivas " << p2 << endl;
        cout << " % Toluca " << p3 << endl;
        cout << endl;
        cout << endl;
        cout << "Ingresar nuevo voto 1 [si] 2[no]" << endl;
        cin >> resp;
    } while (resp != 2);
    system("pause");
    return 0;
}