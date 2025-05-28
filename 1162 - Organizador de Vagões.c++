#include <stdio.h>
#include <stdlib.h>

int Bolha(int v[], int n){
    int j, i, aux, cont=0;
    for(j = n-1; j>0; j--){
        for(i = 0; i<j; i++){
            if(v[i]>v[i+1]){
                cont++;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
    return cont;
}

int main()
{
    int casos, num;
    int tam, S;
        scanf("%d", &casos);
        while(casos--){
            scanf("%d", &tam);
            int vet[tam];
            for(int i=0; i<tam; i++){
                scanf("%d", &vet[i]);
            }
            S = Bolha(vet, tam);
            printf("Optimal train swapping takes %d swaps.\n", S);
        }

    return 0;
}