#include <iostream>
#include <map>

using namespace std;

map<int, map<int, int> > G;
map<int, int> MAT;
map<int, int> conjuge0;
map<int, int> conjuge1;
map<int, int> visitado;

int N;

int Aumenta(int no) {
  int i;
  for(auto it = G[no].begin(); it != G[no].end(); it++)
    if(G[no][it->first]==1 && !visitado[it->first]) {
      visitado[it->first]=1;
      if(conjuge0[it->first]==-1 || Aumenta(conjuge0[it->first])) {
      	conjuge0[no] = it->first;
        conjuge0[it->first] = no;
        return 1;
      }
    }
  return 0;
}

int Matching()
{
    int i;
    int aumentou;
    int ncasados;

    for(i=0; i<N; i++)
        conjuge0[i] = -1;
    for(i=0; i<N; i++)
        conjuge1[i] = -1;

    ncasados=0;
    do
    {
        aumentou=0;
        for(i=0; i<N; i++)
            visitado[i] = 0;
        for(i=0; i<N; i++)
            if(conjuge0[i]==-1)
                if(Aumenta(i))
                {
                    aumentou = 1;
                    ncasados++;
                }
    }
    while(aumentou);

    return ncasados;
}



int main()
{
    int n, m, k, x, y;
        while(1){
            cin >> n >> m;
            if(n == 0)break;
            cin >> k;

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    int V = i*m +j;
                if(j<m-1)
                    G[V][V+1] = G[V+1][V] = 1;
                if(i<n-1)
                    G[V][V+m] = G[V+m][V] = 1;
                }
            }

            for(int i=0; i<k; i++){
                    cin >> x >> y;
                    y--; x--;
                    int V = x*m + y;
                    if(y<m-1)
                    G[V][V+1] = G[V+1][V] = 0;
                    if(y>0)
                    G[V][V-1] = G[V-1][V] = 0;
                    if(x < n-1)
                    G[V][V+m] = G[V+m][V] = 0;
                    if(x>0)
                    G[V][V-m] = G[V-m][V] = 0;
            }
            N = n*m;
            cout << Matching() << endl;
            G.clear();
            visitado.clear();
        }

    return 0;
}
