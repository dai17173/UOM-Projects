#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

main()
{
    long years, cars;

    cars = 80000;
    years = 0;

    while(cars<=160000)
    {
        years++;
        cars=ceil(cars*(1+0.07));
    }
    printf("%ld\n",years);
    printf("%ld\n",cars);
    system("pause");
}
