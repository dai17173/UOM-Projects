#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{

    long kwdik;
    double et_mis8os,ebdom_amoivi,amoivi_anawra,sinoliki;
    int wres_ebdom;

    printf("Dwse ton kwdiko:");
    kwdik = GetLong();


    if (kwdik>=1000)
    {
        printf("Dwse ton ethsio mistho:");
        et_mis8os = GetReal();
        ebdom_amoivi = et_mis8os/52;
        printf("H ebdomadiaia amoibh einai %g",ebdom_amoivi);
    }
    else
    {
        printf("Dwse tis wres ebdomadiaias ergasias:");
        wres_ebdom = GetInteger();
        printf("Dwse thn amoibh ana wra:");
        amoivi_anawra = GetReal();
        sinoliki = wres_ebdom*amoivi_anawra;
        if (wres_ebdom>40)
            sinoliki = sinoliki + (wres_ebdom-40)*amoivi_anawra*0.5;
        printf("H ebdomadiaia amoibh einai %g", sinoliki);
    }

}
