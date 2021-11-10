#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef int ListElementType;           /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������

typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void Larger(ListPointer InList, ListElementType number, ListPointer *OutList);


main(){

    ListPointer AList,BList,PredPtr;
    ListElementType Item;
    int i,plithos,number;

    // ���������� ����� ��
    CreateList(&AList);

    // �������� ��� ������� ��� ��������� ��� �� ��������� ��� ��
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &plithos);

    // �������� ��������� ���� ��
    for(i=0; i<plithos; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, NULL);
    }

    // �������� �� �������� ��� ��
    printf("************Arxiki lista************\n");
    LinkedTraverse(AList);

    // �������� ������� �������
    printf("Doste ton ari8mo katofli (number) gia tin dimiourgia tis neas listas: ");
    scanf("%d", &number);

    // ����� ��� ���������� Larger
    Larger(AList, number, &BList);

    // �������� �� �������� ��� ��
    printf("************Teliki lista************\n");
    LinkedTraverse(BList);


    system("PAUSE");
    return 0;
}


// ��������� ��� ���������� Larger
void Larger(ListPointer InList, ListElementType number, ListPointer *OutList)
{
    ListPointer CurrPtr;


    CurrPtr = InList;
    CreateList(OutList);

    while(CurrPtr != NULL)
    {
        if(CurrPtr->Data >= number)
            LinkedInsert(OutList, CurrPtr->Data, NULL);
        CurrPtr = CurrPtr->Next;
    }
}


void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
  ����������:  ��� �������� ������ List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: True �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr.
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ����
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������,
                ����� ��� �� � ����� ����� ����.
   ����������: ��� ������������� ����������� ����� �� ��� ����� �����
                �� �������������� ��� ��� List.
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf(" %d,",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}
