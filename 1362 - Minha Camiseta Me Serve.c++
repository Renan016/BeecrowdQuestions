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

int Num(string c){
    if(c == "XS")
        return 0;
    else if(c == "S")
        return 1;
    else if(c == "M")
        return 2;
    else if(c == "L")
        return 3;
    else if(c == "XL")
        return 4;
    else
        return 5;
}

int main()
{
    int n , j, i, m, cada, casos, x1, x2;
    string c1, c2;
    cin >> casos;
        while(casos--){
            cin >> n >> m;
            cada = n/6;

            for(i=0; i<m; i++){
                    cin >> c1 >> c2;
                    for(j=0; j<cada; j++){
                        x1 = Num(c1)*cada+j+m;
                        x2 = Num(c2)*cada+j+m;
                        G[i][x1] = G[x1][i] = 1;
                        G[x2][i] = G[i][x2] = 1;
                    }
            }
            N=n*m;
            if(Matching() == m){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
            G.clear();
            visitado.clear();
        }

       return 0;
}