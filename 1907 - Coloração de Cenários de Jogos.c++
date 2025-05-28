#include <bits/stdc++.h>


using namespace std;

struct No{
    No *pai;
};

No N[1100000];

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
    string Linha, LinhaDCima;
    int n, M, i, j, P;
    cin >> n >> M;
    set<No *>S;

        for(i=0; i<n; i++){
                cin >> Linha;
            for(j=0; j<M; j++){
                P = i*M+j;
                if(Linha[j] == 'o')N[P].pai = NULL;
                else{
                    N[P].pai = &N[P];
                    if(j>0){
                        if(Linha[j-1] == '.')
                                Union(&N[P], &N[P-1]);
                        }
                        if(i>0){
                            if(LinhaDCima[j] == '.')
                                Union(&N[P], &N[P-M]);
                        }
                    }
                }
                LinhaDCima = Linha;
            }
    for(int i=0; i<n*M; i++){
        if(N[i].pai != NULL)
        S.insert(FindSet(&N[i]));
    }
        cout << S.size() << endl;

    return 0;
}
