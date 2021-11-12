#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define m 10
#define n 3

void ReadData(int row, int col, double temper[row][col]);
double CalculateAverage(int row, int col, double temper[row][col]);
void CalculateAvCity(int row, int col, double temper[row][col], double average[row]);
void CalculateMaxDeviation(int row, int col, double natavg, double temper[row][col], double mdeviation[row]);
void PrintResults(int row, double average[row], double mdeviation[row], double natavg);

main()
{
    double temper[m][n];
    double average[m], mdeviation[m];
    double natavg;

    ReadData(m, n, temper);
    natavg = CalculateAverage(m, n, temper);
    CalculateAvCity(m, n, temper, average);
    CalculateMaxDeviation(m, n, natavg, temper, mdeviation);
    PrintResults(m, average, mdeviation, natavg);

    system("PAUSE");
    return 0;
}


void ReadData(int row, int col, double temper[row][col])
{
   int i,j;

   for (i=0; i<row; i++)
		for (j=0; j<col; j++)
        {
            printf("Temp of City %d During %d 8-hour period: ",i+1,j+1);
            temper[i][j] = GetReal();
        }
}


double CalculateAverage(int row, int col, double temper[row][col])
{
    int i, j;
    double natavg;

    natavg = 0;
    for (i=0; i<row; i++)
      for (j=0; j<col; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(row*col);
    return (natavg);
}


void CalculateAvCity(int row, int col, double temper[row][col], double average[row])
{
    int i, j;

    for (i=0; i<row; i++)
    {
        average[i] = 0;
        for (j=0; j<col; j++)
            average[i] += temper[i][j];
        average[i] = average[i]/col;
    }
}


void CalculateMaxDeviation(int row, int col, double natavg, double temper[row][col], double mdeviation[row])
{
    int i, j;
    double devnat[row][col];

    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);
    for (i=0; i<row; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<col; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }
}


void PrintResults(int row, double average[row], double mdeviation[row], double natavg)
{
    int i;

    printf("%3.1f\n", natavg);
    for (i=0; i<row; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
}
