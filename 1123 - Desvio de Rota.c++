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
    int cidades, estradas, rota, conserto;
    int U, V, P, Solve;
    while(1){
        G.clear();
        cin >> cidades >> estradas >> rota >> conserto;
        if(cidades == 0)break;
            for(int i=0; i<estradas; i++){
                cin >> U >> V >> P;
                if(U<rota && V<rota){

                    if(U<V && U+1==V){
                        G[U][V] = P;
                    }
                    else if(V+1==U)G[V][U] = P;
                }
                else if(U<rota||V<rota){
                    if(U>V){
                        G[U][V] = P;
                    }
                    else G[V][U] = P;
                }
                else{
                    G[U][V] = P;
                    G[V][U] = P;
                }
            }
                Djikstra(cidades, conserto);
                Solve = dist[rota-1];

        cout << Solve << endl;
    }



    return 0;
}