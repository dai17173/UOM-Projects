#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>
#include <time.h>

int populate(int a[50]);
int printArr(int a[50]);
int checkTable(int a[50],int b[50],int x);

main()
{
    int a[50];

    populate(a);
    printArr(a);


    system("pause");
    return 0;
}




int populate(int a[50])
{
    srand(time(NULL));

    for(int i=0; i<50; i++)
        a[i] = rand()%10;
}

int printArr(int a[50])
{
    int x,b[50];

    for(int i=0; i<50; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("-------------- \n");
    printf("Dose arithmo apo to 0 ews to 9: ");
    x = GetInteger();
    printf("\n");
    printf("o Arithmos %d emfanizetai %d fores. \n", x, checkTable(a,b,x));
    printf("Stis Theseis: \n");
    for(int i=0; i<checkTable(a,b,x); i++)
        printf("%d ", b[i]);
    printf("\n");
    printf("-------------- \n");
}

int checkTable(int a[50],int b[50],int x)
{
    int counter = 0;

    for(int i=0; i<50; i++)
        if(a[i]==x)
        {
            b[counter] = i;
            counter++;
        }
    return counter;
}
