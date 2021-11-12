#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Sum_Cube(int num);
int Cube(int digit);
bool IsArmstrong(int num);

main()
{
    int i;
    for ( i=1; i<=999; i++)
        if ( IsArmstrong(i))
            printf("Num %3d Armstrong\n", i);

    system("pause");
    return 0;
}

int Sum_Cube(int num)
{
     int digit1,digit2,digit3,sum;
     digit1 = num / 100;
     digit2 = (num % 100)/10;
     digit3 = num % 10;
     sum = Cube(digit1) + Cube(digit2) + Cube(digit3);
     return sum;
}

int Cube(int digit)
{
    int i,product;
    product = 1;
      for(i=1 ; i<=3 ; i++)
        {
            product = product * digit;
        }
    return product;
}

bool IsArmstrong(int num)
{
    return ( num == Sum_Cube(num) );
}
