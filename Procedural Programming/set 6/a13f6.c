#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void decompose(long number,int*plithos,double *mesos_oros,int *max_psif);

main()
{
    int pl=0,max=0;
    double mo;
    long numb;

    do{
        printf("Please insert non-negative number:");
        numb = GetInteger();
    }while (numb<0);
    printf("\n");
    decompose(numb,&pl,&mo,&max);
    printf("Digits: %ld, Average: %.3lf, Max: %d\n",pl+1 ,mo, max);


    system("PAUSE");
    return 0;
}

void decompose(long number,int *plithos,double *mesos_oros,int *max_psif)
{
   int table[100],x,y,athr=0;


   x = number%10;
   y = number/10;
   while(y != 0)
   {
       table[*plithos] = x;
       (*plithos)++;
       x = y%10;
       y = y/10;
   }
   table[*plithos] = x;


   for(int i=0; i<= *plithos; i++){
       athr+=table[i];
   }
   *mesos_oros = (double)athr / ((*plithos)+1);


   for(int i=0; i<=*plithos; i++){
       if(table[i]>*max_psif)
           *max_psif=table[i];
   }

   if (number == 0)
    *plithos=-1;
}
