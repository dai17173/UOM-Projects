#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    int kwd,temax,timi;
    double ekpt,teltimi;

    printf("Dwse ton kwdiko tou proiontos: ");
    kwd = GetInteger();
    printf("Dwse ton arithmo twn temaxiwn: ");
    temax = GetInteger();

    timi = (kwd/100)+(kwd%100);
    printf("H timh pwlhshs toy prointos einai %d\n",timi);


    if (temax>=1 && temax<=30)
        ekpt = timi*temax*0.1;
    else if (temax>=31 && temax<=70)
        ekpt = timi*temax*0.2;
    else if (temax>=71)
        ekpt = timi*temax*0.35;
    printf("H ekptwsh einai %g\n", ekpt);


    teltimi = (timi*temax)-ekpt;
    printf("H telikh timh ths paragelias einai %g\n", teltimi);

}
