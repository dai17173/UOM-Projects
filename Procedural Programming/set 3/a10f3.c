#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main()
{
    int i,x;

    for(x=1; x<=10; x++)
    {
        printf("%4d", x);
        for(i=1; i<=10; i++)
            printf("%4d", x*i);
        printf("\n");

    }
}
