#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define LEN 100

void anagramatismos(char palia[LEN], char nea[LEN]);

main()
{
    char palia[LEN],nea[LEN];

    printf("Word to shuffle :");
    gets(palia);                        //�������� ��������������
    anagramatismos(palia,nea);          //���������� ��������������
    printf("Initial Word: %s, New Word: %s\n", palia, nea);


    system("PAUSE");
    return 0;
}

void anagramatismos(char palia[LEN], char nea[LEN])
{
    int t1,t2,mikos,N;
    char temp;

    strcpy(nea,palia);
    mikos = strlen(palia);
    srand(time(NULL));
    N = rand();                     // ������� ������� �����������

    for(int i=0; i<=N; i++){

        t1 = rand()%(mikos);       // ������ ������� ����������
        do{
            t2 = rand()%(mikos);   // �������� ������� ����������,��� ����� �������� ��� ��� �����
        }while(t1 == t2);
        temp = nea[t1];
        nea[t1] = nea[t2];
        nea[t2] = temp;
    }
}
