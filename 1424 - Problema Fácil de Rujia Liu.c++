#include <bits/stdc++.h>

using namespace std;

int main()
{

     map<int, map<int, int> >G;
     int num, posicao, v, n, m;
     int i;
     while(cin >> n >> m){
        for(i=0; i<n; i++){
            cin >> v;
            G[v][G[v].size()+1] = i+1;
        }
        for(i=0; i<m; i++){
            cin >> posicao >> num;
            if(G[num].find(posicao) == G[num].end()){
                cout << 0 << endl;
            }
            else cout << G[num][posicao] << endl;
        }
        G.clear();
     }

    return 0;
}
