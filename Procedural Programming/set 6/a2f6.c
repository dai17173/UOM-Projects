#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int vres_plithos(int *p);
int vres_max_min(int *p, int *MIN, int *MAX, int PLITHOS);

main()
{
    int table[100],plithos,min=99999,max=-1;

    plithos = vres_plithos(table);
    vres_max_min(table, &min, &max, plithos);
    printf("The range of values is %d-%d \n", min, max);


    system("PAUSE");
    return 0;
}


int vres_plithos(int *p)
{
    int x,i=0;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");

    printf("?");
    x = GetInteger();
    while (x != -1){

        *(p+i) = x;
        i++;
        printf("?");
        x = GetInteger();
    }
    return i;
}

int vres_max_min(int *p, int *MIN, int *MAX, int PLITHOS)
{
    for(int i=0; i<PLITHOS; i++)
    {
        if ( *(p+i)< *MIN )
            *MIN = *(p+i);
        if ( *(p+i)> *MAX )
            *MAX = *(p+i);
    }
}
