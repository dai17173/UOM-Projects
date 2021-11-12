#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main()
{
    int age,min,max;

    min = 9999;
    max = 0;

    while(TRUE)
    {
        printf("Dwse ilikia: ");
        age = GetInteger();
        if (age == -1) break;
        if (age<min)
            min = age;
        if (age>max)
            max = age;
    }
    printf("H megalyteri ilikia einai %d\n", max);
    printf("H mikroteri ilikia einai %d", min);
}
