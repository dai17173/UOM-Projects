#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    double tm,miktatm,df,dt;

    printf("Dwse ta ka8ara tm tou spitiou? ");
    tm = GetReal();
    printf("Dwse ta mikta tm tou spitiou ? ");
    miktatm = GetReal();
    dt = tm*1.33*61/365;
    printf("Ta DT einai : %.4g\n", dt);
    df = miktatm*0.13*61/365;
    printf("O DF einai : %.3g", df);
}
