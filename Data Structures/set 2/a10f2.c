#include <stdio.h>
#include <stdlib.h>

#define StackLimit 10  // �� ���� �������� ��� �������, ���������� ��� �� 10

typedef char StackElementType;  // � ����� ��� ���������  ��� �������
                                //���������� ����� char
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
void TraverseStack(StackType Stack);


main()
{
    StackType Stack1,Stack2,Stack3;

    // ���������� ����� ������� Stack1,Stack2 ��� Stack3
    CreateStack(&Stack1);
    CreateStack(&Stack2);
    CreateStack(&Stack3);

    // �������� ��������� ���� ������ Stack1
    Push(&Stack1,80);
    Push(&Stack1,65);
    Push(&Stack1,83);
    Push(&Stack1,67);
    Push(&Stack1,65);
    Push(&Stack1,76);

    // �������� ��� ��������� ��� Stack1
    printf("\nStack1\n");
    TraverseStack(Stack1);


    //�������� ��� ��������� ��� ��� Stack1 ���� Stack2
    for(int i=Stack1.Top; i>=0; i--){
        Push(&Stack2,Stack1.Element[i]);
        Pop(&Stack1,&Stack1.Element[i]);
    }
    // �������� ��� ��������� ��� Stack2
    printf("\nStack2\n");
    TraverseStack(Stack2);



    //�������� ��� ��������� ��� ��� Stack2 ���� Stack3
    for(int i=Stack2.Top; i>=0; i--){
        Push(&Stack3,Stack2.Element[i]);
        Pop(&Stack2,&Stack2.Element[i]);
    }
    // �������� ��� ��������� ��� Stack3
    printf("\nStack3\n");
    TraverseStack(Stack3);



    //�������� ��� ��������� ��� ��� Stack3 ���� Stack1
    for(int i=Stack3.Top; i>=0; i--){
        Push(&Stack1,Stack3.Element[i]);
        Pop(&Stack3,&Stack3.Element[i]);
    }
    // �������� ��� ��������� ��� Stack1
    printf("\nStack1\n");
    TraverseStack(Stack1);



    system("PAUSE");
    return 0;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, ",Stack.Element[i]);
    }
    printf("\n");
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
