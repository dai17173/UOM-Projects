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
    gets(x);                                 //�������� ��������������
    ypologismoi(x);                         //���������� �����������

    system("PAUSE");
    return 0;
}


void ypologismoi(char x[100])
{
    int mikos,counter=0,athr=0,table[100];

    mikos = strlen(x);
    for(int i=0; i<=mikos; i++)
        if(isdigit(x[i])){
            table[counter] = x[i];        //���������� ������ table ��� ���� ���� �� ����� ��� �� �����
            counter++;
        }
    table[counter]='\0';

    for(int i=0; i<counter; i++){          //��������� ����������� ��� �������� ���������
        athr+= table[i]-48;
        printf("%c", table[i]);
        if (table[i+1]!='\0')
            printf(" + ");
    }
    printf(" = %d\n", athr);
}
