#include <bits/stdc++.h>
using namespace std;
int M[100][1000];
int main()
{
    int linha, n, coluna, tempo, piz;
    int i, j;
    memset(M, 0, sizeof(M));
    cin >> n;
    for(int k=1; k<=n; k++)
    {
        cin >> linha;
        if(linha == 0)break;
        cin >> coluna;

        for(i=1; i<=linha; i++)
        {
            cin >> tempo >> piz;
            for(j=1; j<=coluna; j++)
            {
                M[i][j] = M[i-1][j];

                if(piz<=j)
                {
                    if(M[i-1][j] < (M[i-1][j-piz]+tempo))

                        M[i][j] = (M[i-1][j-piz]+tempo);
                }
            }
        }

        cout << "Galho " << k << ":" << endl;
        cout << "Numero total de enfeites: " << M[linha][coluna] << endl;
        cout << endl;

    }
    return 0;
}