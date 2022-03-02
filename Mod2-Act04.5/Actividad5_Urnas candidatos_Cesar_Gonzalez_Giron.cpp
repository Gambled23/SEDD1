#include <iostream>
#include <cstdlib>
#include "validaciones.hpp"

using namespace std;

int resp, opc;
char respChar[100], opcChar[100];
//a
class urna
{
private:
    int votos = 0;

public:
    void setVoto();
    int getVoto();
};

class candidatoA : public urna
{
private:
    int porcentaje;

public:
    void setPorcentaje();
    int getPorcentaje();
};
class candidatoB : public urna
{
private:
    int porcentaje;

public:
    void setPorcentaje();
    int getPorcentaje();
};
class candidatoC : public urna
{
private:
    int porcentaje;

public:
    void setPorcentaje();
    int getPorcentaje();
};
void urna::setVoto()
{
    votos = votos + 1;
}
int urna::getVoto()
{
    return votos;
}
// Porcentajes de votos
candidatoA CA1;
candidatoB CB1;
candidatoC CC1;
void candidatoA::setPorcentaje()
{
    porcentaje = (CA1.getVoto() * 100) / (CA1.getVoto() + CB1.getVoto() + CC1.getVoto());
}
void candidatoB::setPorcentaje()
{
    porcentaje = (CB1.getVoto() * 100) / (CA1.getVoto() + CB1.getVoto() + CC1.getVoto());
}
void candidatoC::setPorcentaje()
{
    porcentaje = (CC1.getVoto() * 100) / (CA1.getVoto() + CB1.getVoto() + CC1.getVoto());
}
int candidatoA::getPorcentaje()
{
    return porcentaje;
}
int candidatoB::getPorcentaje()
{
    return porcentaje;
}
int candidatoC::getPorcentaje()
{
    return porcentaje;
}

int main()
{

    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "Candidato -> A [1]" << endl;
        cout << "Candidato -> B [2]" << endl;
        cout << "Candidato -> C [3]" << endl;
        cout << "Seleccione opcion" << endl;
        cin >> opcChar;
        opc = validarNumInt(opcChar);
        cout << endl;
        cout << endl;
        // Registrar votos
        switch (opc)
        {
        case 1:
            CA1.setVoto();
            break;
        case 2:
            CB1.setVoto();
            break;
        case 3:
            CC1.setVoto();
            break;
        default:
            cout << "La opcion ingresada no existe\n";
            break;
        }
        // calcular porcentajes
        CA1.setPorcentaje();
        CB1.setPorcentaje();
        CC1.setPorcentaje();
        // Imprimir todos los datos
        cout << "*********VOTOS**********" << endl;
        cout << " Candidato A: " << CA1.getVoto() << endl;
        cout << " Candidato B: " << CB1.getVoto() << endl;
        cout << " Candidato C: " << CC1.getVoto() << endl;
        cout << endl;
        cout << endl;
        cout << "*****PORCENTAJES********" << endl;
        cout << " % Candidato A " << CA1.getPorcentaje() << endl;
        cout << " % Candidato B " << CB1.getPorcentaje() << endl;
        cout << " % Candidato C " << CC1.getPorcentaje() << endl;
        cout << endl;
        cout << endl;
        cout << "Ingresar nuevo voto 1 [si] 2[no]" << endl;
        cin >> respChar;
        resp = validarNumInt(respChar);
    } while (resp != 2);
    system("pause");
    return 0;
}