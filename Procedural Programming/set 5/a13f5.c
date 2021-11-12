#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>
#include <time.h>

#define ro 10
#define co 10

int populate_data(int R, int C, int rows, int cols, int matrix[rows][cols]);
int print_array(int R, int C, int rows, int cols, int matrix[rows][cols]);
void change_array(int R, int C, int rows, int cols, int matrix[rows][cols]);

main()
{
    int A[ro][co],R,C;


    do{
        printf("Dwse ton arithmo twn grammwn: ");
        R = GetInteger();
    }while (R<1 || R>10);

    do{
        printf("Dwse ton arithmo twn sthlwn: ");
        C = GetInteger();
    }while (C<1 || C>10);

    printf("ARXIKOS PINAKAS \n");
    populate_data(R,C,ro,co,A);
    print_array(R,C,ro,co,A);
    printf("ALLAGMENOS PINAKAS \n");
    change_array(R,C,ro,co,A);

    system("PAUSE");
    return 0;
}


int populate_data(int R, int C, int rows, int cols, int matrix[rows][cols])
{
    srand(time(NULL));

    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            matrix[i][j] = rand()%100;
}


int print_array(int R, int C, int rows, int cols, int matrix[rows][cols])
{
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}


void change_array(int R, int C, int rows, int cols, int matrix[rows][cols])
{
    int B[10];

    for(int i=0; i<R; i++)
    {
        int max = 0;
        for (int j=0; j<C; j++)
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                B[i] = max;
            }
    }

    for(int i=0; i<R; i++)
    {
        bool flag = FALSE;
        for (int j=0; j<C; j++)
            if(matrix[i][j] == B[i] || flag == TRUE)
            {
                matrix[i][j] = B[i];
                flag = TRUE;
            }
    }

    for(int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
