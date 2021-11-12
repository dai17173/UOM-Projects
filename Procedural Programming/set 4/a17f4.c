#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int total(int x);

main()
{

    printf("Athr 1 ... 100  = %d\n", total(100));
    printf("Athr 1 ... 1000 = %d\n ", total(1000));


    system("pause");
    return 0;
}

int total(int x)
{
    int i,ath=0;
    for(i=1; i<=x; i++)
        ath+=i;
    return ath;
}
