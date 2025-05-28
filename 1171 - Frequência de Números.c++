#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, n1, num[2001] = {0}, i;
    scanf("%d", &N);
        for(i=0; i<N; i++){
            scanf("%d", &n1);
            num[n1]++;
        }
        for(i=1; i<= 2000; i++){
            if(num[i]>0)printf("%d aparece %d vez(es)\n", i, num[i]);

        }
    return 0;
}