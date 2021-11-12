#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

main()
{
    int years;
    long Arithmo_Aytok,Orio;
    double Rythmos;


    printf("Dwse ton arxiko arithmo autokinhtwn: ");
    Arithmo_Aytok = GetLong();
    printf("Dwse ton ethsio rythmo ayxhshs: ");
    Rythmos = GetReal();
    printf("Dwse to orio: ");
    Orio = GetLong();
    years = 0;

    while (Arithmo_Aytok <= Orio)
   {
        Arithmo_Aytok = ceil(Arithmo_Aytok*(1+Rythmos));
        years++;
   }
    printf("%ld\n",years);
    printf("%ld\n",Arithmo_Aytok);
    system("pause");
}
