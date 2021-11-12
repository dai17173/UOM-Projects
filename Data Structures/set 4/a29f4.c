#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef double StackElementType;           /*� ����� ��� ��������� ��� �������
                                        ���������� ����� int */
typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);
double GetCost(StackPointer truck, double weight);
void Reload(StackPointer *truck, double weight);

main()
{
    StackPointer truck;
    StackElementType AnItem;
    double weight,value,cost;

    //���������� ����� �������
    CreateStack(&truck);
    Push(&truck, 3);
    Push(&truck, 2);
    Push(&truck, 1);
    Push(&truck, 0.5);
    Push(&truck, 0.4);


    while(TRUE)
    {
        //�������� ���������
        printf("Give the weight: ");
        scanf("%lf", &weight);
        if(weight<0)
            break;

        printf("Give the value: ");
        scanf("%lf", &value);
        if(value<0)
            break;

        //����� ��� ���������� GetCost
        cost = GetCost(truck, weight);
        if(cost == -1)
            printf("Not enough space available\n");
        else if(cost < value)
            Reload(&truck, weight);
        else
            printf("Not enough value\n");
    }

    //�������� ������� �������
    printf("----Truck----");
    TraverseStack(truck);


    system("PAUSE");
    return 0;
}


//��������� GetCost
double GetCost(StackPointer truck, double weight)
{
    StackPointer CurrPtr;
    double movedWeight,temp,totalWeight;
    boolean flag;



    flag = FALSE;
    movedWeight = 0;
    temp = 0;
    totalWeight = 0;
    CurrPtr = truck;

    if(EmptyStack(truck))
        printf("EMPTY Truck\n");
    else
    {
        while((CurrPtr!=NULL) && (flag==FALSE))
        {
            if(CurrPtr->Data < weight)
                movedWeight+= CurrPtr->Data;
            else
                flag = TRUE;
            CurrPtr = CurrPtr->Next;
        }

        CurrPtr = truck;

        while(CurrPtr!=NULL)
        {
            totalWeight += CurrPtr->Data;
            CurrPtr = CurrPtr->Next;
        }
    }

    temp = totalWeight+weight;
    if(temp > 10)
        return -1;
    else
        return movedWeight*300;
}

//��������� Reload
void Reload(StackPointer *truck, double weight)
{
    StackPointer platform;
    double tmp;
    boolean flag;


    flag = FALSE;
    CreateStack(&platform);
    while((*truck!=NULL) && (flag==FALSE))
    {
        Pop(truck, &tmp);
        if(tmp < weight)
            Push(&platform, tmp);
        else
        {
            Push(truck, tmp);
            flag = TRUE;
        }
    }
    Push(truck, weight);

    printf("----Platform----");
    TraverseStack(platform);

    printf("----Truck----");
    TraverseStack(*truck);

    while(platform!=NULL)
    {
        Pop(&platform, &tmp);
        Push(truck, tmp);
    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("\nEMPTY Stack");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("\n%.1lf", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
