#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int m[101][51]= {0};
    int p[101][51]= {0};
    int n, pac, qt, peso;
    int i, j, k;
    cin >> n;

    while(n--)
    {
        cin >> pac;

        for(i = 1; i <= pac; i++)
        {
            cin >> qt >> peso;
            for(j = 1; j <= 50; j++)
            {
                m[i][j] = m[i-1][j];
                p[i][j] = p[i-1][j];
                if(peso <= j)
                {
                    if(m[i-1][j] < m[i-1][j-peso]+qt){
                        m[i][j] = m[i-1][j-peso]+qt;
                        p[i][j] = p[i-1][j-peso]+1;
                    }

                }
            }
        }

        cout << m[pac][50] << " brinquedos" << endl;
        for(k = 1; k <= 50; k++)
        {
            if(m[pac][k] == m[pac][50]) break;
        }
        cout << "Peso: " << k << " kg" << endl;
        cout << "sobra(m) " << pac - p[pac][50] << " pacote(s)" << endl;
        cout << endl;
        memset(m, 0, sizeof(m));
    }
    return 0;
}