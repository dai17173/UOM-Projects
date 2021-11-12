#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int M,N,i,j;
    long A[100][100],B[100],C[100],diag1=0,diag2=0;

    printf("Dwse ton arithmo twn grammwn: ");
    N = GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    M = GetInteger();


    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            printf("Thesi [%d,%d]: ", i, j);
            A[i][j] = GetLong();
        }

    for(i=0; i<N; i++)
    {
        diag1 += A[i][i];
        diag2 += A[i][N-i-1];
        for(j=0; j<M; j++)
        {
            B[i] += A[i][j];
            C[j] += A[i][j];
        }
    }

    printf("Table: \n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf("%4d", A[i][j]);
        printf("| = %d\n", B[i]);
    }

    printf("------------\n");
    for(j=0; j<M; j++)
        printf("%4d", C[j]);

    printf("\n");

    if (N == M)
        printf("Sum Diag 1: %d,   Diag 2: %d\n", diag1, diag2);

    system("pause");
    return 0;
}
