#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    int imeres;
    long amoivi;
    double posdwrou,dwro;

    printf("Dwse tis hmeres ergasias tou etous: ");
    imeres = GetInteger();
    printf("Dwse thn hmerhsia amoibh: ");
    amoivi = GetLong();
    printf("Dwse to pososto dwroy : ");
    posdwrou = GetReal();
    dwro = imeres*amoivi*posdwrou;
    printf("To dwro einai %g",dwro);

}
