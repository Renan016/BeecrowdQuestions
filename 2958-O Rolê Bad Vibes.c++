#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    char texto[30];
    vector<string> V, D;
    cin>>n>>m;

    for(i=0; i<n*m; i++){
        cin >> texto;
        if(texto[1] == 'V')V.push_back(texto);
        else D.push_back(texto);
    }

    sort(V.begin(), V.end());
    sort(D.begin(), D.end());
    reverse(V.begin(), V.end());
    reverse(D.begin(), D.end());
    for(i = 0; i<V.size(); i++)
    {
    cout << V[i] << endl;
    }
     for(i = 0; i<D.size(); i++)
    {
    cout << D[i] << endl;
    }
    return 0;
}