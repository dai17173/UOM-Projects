#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main(){

    int N,Number,tmp,j,table[10];

    printf("TO DYNAMOSYNOLO GIA N=");
    scanf("%d", &N);
    printf("\n");

    for(int i=1; i<1<<N; i++)
    {
        Number = i;
        j=1;
        while (Number!=0)
        {
            tmp = Number % 2;
            table[j] = tmp;
            Number = Number / 2;
            j++;
        }

        for(int k=1; k<j; k++)
        {
            if(table[k]==1)
                printf("%d",k);
        }
        printf("\n");
    }

    system("PAUSE");
    return 0;
}
