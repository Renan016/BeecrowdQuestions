#include <stdio.h>
#include <stdlib.h>
//#define MAX 231

void quicksort(int v[], int ini, int fim){
    int i = ini, j = fim, pivo, aux;

    pivo = v[(ini + fim) / 2];
    while(i <= j)
    {
        while(v[i] < pivo && i < fim)i++;
        while(v[j] > pivo && j > ini)j--;
        if(i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    
    if(j > ini)
        quicksort(v, ini, j);
    if(i < fim)
        quicksort(v, i, fim);
}

int main()
{
    int teste, h;

    scanf("%d", &teste);

    while(teste--)
    {
        int qualt;
        scanf("%d", &qualt);

        int *alt = (int*)malloc(qualt * sizeof(int));

        for(int i = 0; i < qualt; i++)
        {
            scanf("%d", &h);
            alt[i] = h;
        }

        quicksort(alt, 0, qualt - 1);

        for(int j = 0; j < qualt; j++)
        {
            printf("%d", alt[j]);
            if(j != qualt - 1)
                printf(" ");
        }
        printf("\n");

        free(alt);
    }

    return 0;
}