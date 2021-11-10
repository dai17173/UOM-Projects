#include <stdio.h>
#include <stdlib.h>

#define StackLimit 60   // �� ���� �������� ��� �������, ���������� ��� �� 50

typedef int StackElementType; // � ����� ��� ���������  ��� �������
                             //���������� ����� int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void GetTopElementA(StackType *Stack, StackElementType *topElement);
void GetTopElementB(StackType Stack, StackElementType *topElement);


main(){
    //������ ���������
    StackType A;
    StackElementType topElement;

    // ���������� ��� �������� ��������� ���� ������ �
    CreateStack(&A);
    for(int i=1; i<100; i+=2)
    {
        Push(&A,i);
    }

    // ����� ���������� GetTopElementA
    GetTopElementA(&A, &topElement);
    // �������� �������������
    printf("Top with GetTopElementA = %d\n", topElement);


    // ����� ���������� GetTopElementB
    GetTopElementB(A, &topElement);
    // �������� �������������
    printf("Top with GetTopElementB = %d\n", topElement);



    system("PAUSE");
    return 0;
}

//��������� ��� ���������� GetTopElementA
void GetTopElementA(StackType *Stack, StackElementType *topElement)
{
    Pop(Stack, topElement);
    Push(Stack, *topElement);
}
//��������� ��� ���������� GetTopElement�
void GetTopElementB(StackType Stack, StackElementType *topElement)
{
    *topElement = Stack.Element[Stack.Top];
}

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������:    ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������:     ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������:    ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:     ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


