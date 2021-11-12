#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void ypologismoi(char x[100]);

main()
{
    char x[100];

    printf("Dose ena alfarithmitiko: ");
    gets(x);                                 //εισαγωγη αλφαριθμητικου
    ypologismoi(x);                         //διαδικασια υπολογισμου

    system("PAUSE");
    return 0;
}


void ypologismoi(char x[100])
{
    int mikos,counter=0,athr=0,table[100];

    mikos = strlen(x);
    for(int i=0; i<=mikos; i++)
        if(isdigit(x[i])){
            table[counter] = x[i];        //δημιουργια πινακα table που εχει μονο τα ψηφια απο το αλφαρ
            counter++;
        }
    table[counter]='\0';

    for(int i=0; i<counter; i++){          //υπολογισμ αθροισματος και εμφανιση δεδομενων
        athr+= table[i]-48;
        printf("%c", table[i]);
        if (table[i+1]!='\0')
            printf(" + ");
    }
    printf(" = %d\n", athr);
}
