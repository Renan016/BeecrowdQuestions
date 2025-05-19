#include <iostream>
#include <iomanip>

using namespace std;

double CalcMedia(double N1, double N2, double N3, double N4){
    double solve;
    solve = (2*N1 + 3*N2 + 4*N3 + 1*N4)/10;
 return solve;
}


int main()
{
    double N1, N2, N3, N4;
    double media;
    double exame;
    cin >> N1 >> N2 >> N3 >> N4;

    media = CalcMedia(N1, N2, N3, N4);

    cout << "Media: " << setprecision(1) << fixed << media << endl;

    if(media >= 7.0){
        cout << "Aluno aprovado." << endl;
    }

    else if(media < 5.0){
        cout << "Aluno reprovado." << endl;
    }

    else if(media>=5 && media<7){
        cout << "Aluno em exame." << endl;
        cin >> exame;
        cout << "Nota do exame: " << setprecision(1) << fixed << exame << endl;
        media = (media+exame)/2;

        if(media >= 5){
            cout << "Aluno aprovado." << endl;
            cout << "Media final: " << setprecision(1) << fixed << media << endl;

        }
        else {
                cout << "Aluno reprovado." << endl;
                cout << "Media final: " << setprecision(1) << fixed << media << endl;
        }
    }

    return 0;
}
