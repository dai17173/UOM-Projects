#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    double profit,saleAmount;
    long purchaseAmount;
    int rate;

    printf("Dwse thn katharh axia: ");
    purchaseAmount = GetLong();

    printf("Dwse to pososto kerdous: ");
    rate = GetInteger();

    profit = purchaseAmount * ((double)rate/100);
    printf("To kerdos einai %g\n",profit);

    saleAmount = purchaseAmount+profit;
    printf("To synoliko poso einai %g",saleAmount);
}
