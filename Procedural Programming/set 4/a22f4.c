#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

float Ypolog_Fpa(int x,int y);

main()
{

    int plith,i,katigor;
    float timi,fpa,synol_fpa=0, synol_kost=0,synol_poso;


    for (i=1; i<=5; i++)
    {
        printf("Dwse to plithos temaxiwn apo to proion %d: ",i );
        plith = GetInteger();
        printf("Dwse timi gia to proion %d: ",i );
        timi = GetReal();
        printf("Dwse katigoria FPA gia to proion %d: ",i );
        katigor = GetInteger();
        if (katigor<1 || katigor>4)
        {
            printf("Lathos kathgoria FPA \n");
            return 0;
        }

        synol_poso = plith*timi;
        fpa = Ypolog_Fpa(synol_poso,katigor);
        synol_fpa = synol_fpa + fpa;
        synol_kost = synol_kost + synol_poso + fpa;
    }
    printf("Synoliko kostos:%.2f\n",synol_kost );
    printf("Synoliko fpa:%.2f\n",synol_fpa );

    system("pause");
    return 0;

}

float Ypolog_Fpa(int x,int y)
{
    float fpa;

    if (y==2)
        fpa = x*0.06;
    else if (y==3)
        fpa = x*0.13;
    else if (y==4)
        fpa = x*0.19;
    else
        fpa = 0;

    return fpa;
}
