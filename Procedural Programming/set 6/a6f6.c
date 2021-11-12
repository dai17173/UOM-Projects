#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 5


void readData(int A[N][4]);
void FindMean(int deik, double *p1, double *p2, int A[N][4]);

main()
{
    int A[N][4];
    double timi1,timi2;

    readData(A);

    FindMean(1, &timi1, &timi2, A);
    printf("Mesos oros barous andrwn: %.1lf \n", timi1);
    printf("Mesos oros barous gynaikwn: %.1lf \n", timi2);
    printf("\n");

    FindMean(2, &timi1, &timi2, A);
    printf("Mesos oros ypsous andrwn: %.1lf \n", timi1);
    printf("Mesos oros ypsous gynaikwn: %.1lf \n", timi2);
    printf("\n");

    FindMean(3, &timi1, &timi2, A);
    printf("Mesos oros hlikias andrwn: %.1lf \n", timi1);
    printf("Mesos oros hlikias gynaikwn: %.1lf \n", timi2);
    printf("\n");


    system("PAUSE");
    return 0;
}


void readData(int A[N][4])
{
    int fylo,baros,ypsos,ilikia;

    for(int i=0; i<N; i++)
    {
        printf("Dwse fylo: ");
        fylo = GetInteger();
        A[i][0] = fylo;

        printf("Dwse baros: ");
        baros = GetInteger();
        A[i][1] = baros;

        printf("Dwse ypsos: ");
        ypsos = GetInteger();
        A[i][2] = ypsos;

        printf("Dwse ilikia: ");
        ilikia = GetInteger();
        A[i][3] = ilikia;

        printf("----- \n");
    }
}

void FindMean(int deik, double *p1, double *p2, int A[N][4])
{
    int plithos1=0,plithos2=0,pl_andr=0,pl_gynaik=0;

    for(int i=0; i<N; i++)
    {
        if (A[i][0] == 0)
        {
            plithos1 = plithos1 + A[i][deik];
            pl_andr++;
        }
        else
        {
            plithos2 = plithos2 + A[i][deik];
            pl_gynaik++;
        }
    }
    *p1 = (double)plithos1/(double)pl_andr;
    *p2 = (double)plithos2/(double)pl_gynaik;
}

