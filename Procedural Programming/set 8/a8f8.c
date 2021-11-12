#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "ctype.h"
#include <string.h>
#include <math.h>


typedef struct{
    int width;   // ������
    int height;  // ����
    int depth;   // �����
    int area;    // ������
    int volume;  // �����
}box;

void EkxwrDiastaseis(box *aBox);
void YpolEmbadou(box *aBox);
void YpolOgkou(box *aBox);

main()
{
    box kouti;

    // ����� ��� �� ������ ��� ����������
    EkxwrDiastaseis(&kouti);
    // ���������� �� �������� ������ ��� �������
    YpolEmbadou(&kouti);
    // ���������� �� �������� ���� ��� �������
    YpolOgkou(&kouti);

    // �������� �������������
    printf("To emvadon tou koutiou einai %d cm2 \n", kouti.area);
    printf("O ogos tou koutiou einai %d cm3 \n", kouti.volume);


    system("PAUSE");
    return 0;
}
// ��������� ��� �������� ���������
void EkxwrDiastaseis(box *aBox)
{
    printf("Dose to mikos tou koutiou se cm: ");
    (*aBox).width = GetInteger();
    printf("Dose to ypsos tou koutiou se cm: ");
    (*aBox).height = GetInteger();
    printf("Dose to vathos tou koutiou se cm: ");
    (*aBox).depth = GetInteger();
}
// ��������� ����������� �������
void YpolEmbadou(box *aBox)
{
    (*aBox).area = 2*((*aBox).width*(*aBox).height + (*aBox).height*(*aBox).depth + (*aBox).depth*(*aBox).width);
}
// ��������� ����������� �����
void YpolOgkou(box *aBox)
{
    (*aBox).volume = (*aBox).width*(*aBox).height*(*aBox).depth;
}

