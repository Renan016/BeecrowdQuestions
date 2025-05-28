#include <iostream>
#include <map>
#include <math.h>

#define MAXN 10001

using namespace std;

map<int, map<int, int> > G;
map<int,int>::iterator it;

const long long INF = pow(2,60);

int fixo[MAXN];
long long dist[MAXN];


void Djikstra(int n, int Inicio)
{

    for(int i=0; i<n; i++)
    {
        fixo[i] = 0;
        dist[i] = INF;
    }
    dist[Inicio] = 0;

    for(int faltam = n; faltam>0; faltam--)
    {
        int no = -1;
        for(int i=0; i<n; i++)
            if(!fixo[i] && (no==-1 || dist[i] < dist[no]))
                no = i;
        fixo[no] = 1;

        if(dist[no] == INF)
            break;

        //for(int i=0; i<n; i++)
        for(it = G[no].begin(); it != G[no].end(); it++)
            if(dist[it->first] > dist[no]+G[no][it->first])
                dist[it->first] = dist[no]+G[no][it->first];
    }
}


int main()
{
    int circulos, setas, A, B;
    int C1, C2, Solve;
    long long bibi, bika;
        G.clear();
        std::ios_base::sync_with_stdio(false) ;
        cin >> circulos >> setas >> A >> B;
            for(int i=0; i<setas; i++){
                cin >> C1 >> C2;
                G[C1-1][C2-1] = 0;
                if((G[C2-1].find(C1-1) == G[C2-1].end()))
                    G[C2-1][C1-1] = 1;
            }
                Djikstra(circulos, A-1);
                bibi = dist[B-1];
                Djikstra(circulos, B-1);
                bika = dist[A-1];

        if(bibi < bika)cout << "Bibi: " << bibi << endl;
        else if(bibi > bika)cout << "Bibika: " << bika << endl;
        else cout << "Bibibibika" << endl;

    return 0;
}

