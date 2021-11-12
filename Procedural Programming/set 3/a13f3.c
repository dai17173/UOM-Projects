#include <stdio.h>
#include "genlib.h"

main()
{
    int i;
    double apotel=0;

    for(i=1; i<=100; i++)
    {
        apotel+=(1/(double)i);
    }

    printf("To athroisma einai %g", apotel);
}
