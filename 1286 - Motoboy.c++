#include <bits/stdc++.h>
using namespace std;
int M[21][31];
int main()
{
    int linha, coluna, tempo, piz;
    int i, j;
    memset(M, 0, sizeof(M));
    while(1)
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

        cout << M[linha][coluna] << " min." << endl;

    }



    return 0;
}