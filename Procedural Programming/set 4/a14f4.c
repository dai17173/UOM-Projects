#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int max(int a,int b);
int gr(int a,int b,int c);

main()
{
    int a,b,c,Y;

    printf("Dwse a:");
    a = GetInteger();
    printf("Dwse b:");
    b = GetInteger();
    printf("Dwse c:");
    c = GetInteger();

    Y = (2*max(a,b) + 3*gr(a,b,c))/4;
    printf("y=%d", Y);

    system("pause");
    return 0;
}


int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}


int gr(int a,int b,int c)
{
    int max1;
    if (a>b)
        max1 = a;
    else
        max1 = b;
    if (c>max1)
        return c;
    else
        return max1;
}
