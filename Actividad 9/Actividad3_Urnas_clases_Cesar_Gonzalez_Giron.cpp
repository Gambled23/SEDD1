#include <iostream>
using namespace std;
double resp;
// a votos totales de atlas
// b votos totales de chivas
// c votos totales de toluca
int opc = 0;

class votos
{
private:
    int votoa = 0, votob = 0, votoc = 0, porcentaje1, porcentaje2, porcentaje3;
    ;

public:
    // getters y setters votos
    void setVotoa();
    void setVotob();
    void setVotoc();
    int getVotoa();
    int getVotob();
    int getVotoc();
    // getters y setters porcentajes
    void setPorcentajesa();
    void setPorcentajesb();
    void setPorcentajesc();
    int getPorcentajesa();
    int getPorcentajesb();
    int getPorcentajesc();
};

// contador de votos
void votos::setVotoa()
{
    votoa = votoa + 1;
}
void votos::setVotob()
{
    votob = votob + 1;
}
void votos::setVotoc()
{
    votoc = votoc + 1;
}
int votos::getVotoa()
{
    return votoa;
}
int votos::getVotob()
{
    return votob;
}
int votos::getVotoc()
{
    return votoc;
}
// Porcentajes de votos
void votos::setPorcentajesa()
{
    porcentaje1 = (votoa * 100) / (votoa + votob + votoc);
}
void votos::setPorcentajesb()
{
    porcentaje2 = (votob * 100) / (votoa + votob + votoc);
}
void votos::setPorcentajesc()
{
    porcentaje3 = (votoc * 100) / (votoa + votob + votoc);
}
int votos::getPorcentajesa()
{
    return porcentaje1;
}
int votos::getPorcentajesb()
{
    return porcentaje2;
}
int votos::getPorcentajesc()
{
    return porcentaje3;
}

int main()
{
    votos votos1;
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
        // Registrar votos
        switch (opc)
        {
        case 1:
            votos1.setVotoa();
            break;
        case 2:
            votos1.setVotob();
            break;
        case 3:
            votos1.setVotoc();
            break;
        default:
            cout << "La opcion ingresada no existe\n";
            break;
        }
        // calcular porcentajes
        votos1.setPorcentajesa();
        votos1.setPorcentajesb();
        votos1.setPorcentajesc();
        // Imprimir todos los datos
        cout << "*********VOTOS**********" << endl;
        cout << " Atlas: " << votos1.getVotoa() << endl;
        cout << " Chivas: " << votos1.getVotob() << endl;
        cout << " Toluca: " << votos1.getVotoc() << endl;
        cout << endl;
        cout << endl;
        cout << "*****PORCENTAJES********" << endl;
        cout << " % Atlas " << votos1.getPorcentajesa() << endl;
        cout << " % Chivas " << votos1.getPorcentajesb() << endl;
        cout << " % Toluca " << votos1.getPorcentajesc() << endl;
        cout << endl;
        cout << endl;
        cout << "Ingresar nuevo voto 1 [si] 2[no]" << endl;
        cin >> resp;
    } while (resp != 2);
    system("pause");
    return 0;
}