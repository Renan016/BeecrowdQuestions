#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tempo;
    int velocidade;
    float distancia;
    float litros = 12;
    
    float solve;
    
    
    cin >> tempo; 
    cin >> velocidade;

    distancia = velocidade*tempo;
    
    solve = distancia/litros;

    cout << setprecision(3) << fixed << solve << endl;


    return 0;
}
