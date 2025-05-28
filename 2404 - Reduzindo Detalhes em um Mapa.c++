#include <bits/stdc++.h>


using namespace std;

struct Aresta{
    int V, W, P;
};

bool Compare(Aresta a1, Aresta a2){
    return(a1.P < a2.P);
}


struct No{
    No *pai;
};

No N[510];

void Link(No *u, No *v){
    v->pai = u->pai;
}

No* FindSet(No *u){
    if(u->pai != u){
        u->pai = FindSet(u->pai);
    }
    return u->pai;
}

void Union(No *u, No *v){
    Link(FindSet(u), FindSet(v));
}



int main()
{
    vector<Aresta> G;
    int R, C, total;
    int V, W, P;
    Aresta Todos;
        cin >> R >> C;

        for(int i=1; i<=R; i++){
           N[i].pai = &N[i];
        }
        for(int i=0; i<C; i++){
            cin >> V >> W >> P;
            Todos.V = V;
            Todos.W = W;
            Todos.P = P;
            G.push_back(Todos);
        }

    sort(G.begin(), G.end(), Compare);
    total = 0;
    for(int i=0; i<G.size(); i++){
        if(FindSet(&N[G[i].V]) != FindSet(&N[G[i].W])){
            total += G[i].P;
            Union(&N[G[i].V], &N[G[i].W]);
        }
    }
        cout << total << endl;
    return 0;
}
