#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int A[5],i,x,temp;

    for (i=0; i<5; i++)
    {
        printf("Enter number: ");
        A[i] = GetInteger();
    }


    x = A[4];
    for (i=0; i<5; i++)
    {
       temp=A[i];
       A[i]=x;
       x=temp;
    }

    for (i=0; i<5; i++)
        printf("%d ", A[i]);
    printf("\n");

    system("pause");
    return 0;
}
