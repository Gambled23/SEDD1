#include <iostream>
using namespace std;
double resp;
// a votos totales de atlas
// b votos totales de chivas
// c votos totales de toluca

int opc = 0;

class votosa
{
private:
    int votoa = 0;
    double porcentajea;

public:
    void setVotoa();
    int getVotoa();
    void setPorcentajesa();
    double getPorcentajesa();
};

class votosb
{
private:
    int votob = 0;
    double porcentajeb;

public:
    void setVotob();
    int getVotob();
    void setPorcentajesb();
    double getPorcentajesb();
};

class votosc
{
private:
    int votoc = 0;
    double porcentajec;

public:
    void setVotoc();
    int getVotoc();
    void setPorcentajesc();
    double getPorcentajesc();
};
votosa votosa1;
votosb votosb1;
votosc votosc1;
// contador de votos
void votosa::setVotoa()
{
    votoa = votoa + 1;
}
void votosb::setVotob()
{
    votob = votob + 1;
}
void votosc::setVotoc()
{
    votoc = votoc + 1;
}
int votosa::getVotoa()
{
    return votoa;
}
int votosb::getVotob()
{
    return votob;
}
int votosc::getVotoc()
{
    return votoc;
}
// Porcentajes de votos
void votosa::setPorcentajesa()
{
    porcentajea = (votoa * 100) / (votoa + votosb1.getVotob() + votosc1.getVotoc());
}
void votosb::setPorcentajesb()
{
    porcentajeb = (votob * 100) / (votosa1.getVotoa() + votob + votosc1.getVotoc());
}
void votosc::setPorcentajesc()
{
    porcentajec = (votoc * 100) / (votosa1.getVotoa() + votosb1.getVotob() + votoc);
}
double votosa::getPorcentajesa()
{
    return porcentajea;
}
double votosb::getPorcentajesb()
{
    return porcentajeb;
}
double votosc::getPorcentajesc()
{
    return porcentajec;
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
        // Registrar votos
        switch (opc)
        {
        case 1:
            votosa1.setVotoa();
            break;
        case 2:
            votosb1.setVotob();
            break;
        case 3:
            votosc1.setVotoc();
            break;
        default:
            cout << "La opcion ingresada no existe\n";
            break;
        }
        // calcular porcentajes
        votosa1.setPorcentajesa();
        votosb1.setPorcentajesb();
        votosc1.setPorcentajesc();
        // Imprimir todos los datos
        cout << "*********VOTOS**********" << endl;
        cout << " Atlas: " << votosa1.getVotoa() << endl;
        cout << " Chivas: " << votosb1.getVotob() << endl;
        cout << " Toluca: " << votosc1.getVotoc() << endl;
        cout << endl;
        cout << endl;
        cout << "*****PORCENTAJES********" << endl;
        cout << " % Atlas " << votosa1.getPorcentajesa() << endl;
        cout << " % Chivas " << votosb1.getPorcentajesb() << endl;
        cout << " % Toluca " << votosc1.getPorcentajesc() << endl;
        cout << endl;
        cout << endl;
        cout << "Ingresar nuevo voto 1 [si] 2[no]" << endl;
        cin >> resp;
    } while (resp != 2);
    system("pause");
    return 0;
}