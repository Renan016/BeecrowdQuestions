#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int com = 0, des = 0;
    int n, i;
    string nome, sinal;
    vector<string>V;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>sinal;
        cin>>nome;
        if(sinal == "+"){
            com++;
        }
        else des++;
        V.push_back(nome);

        reverse(V.begin(), V.end());
    }
    sort(V.begin(), V.end());

    for(i = 0; i<V.size(); i++)
    {
    cout << V[i] << endl;
    }
    cout << "Se comportaram: " << com << " | Nao se comportaram: " << des << endl;


    return 0;
}