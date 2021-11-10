#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct QueueNode *QueuePointer;

typedef struct
{
    char userid[8];
}QueueElementType;


typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {FALSE, TRUE} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
boolean search_for_userid(QueueElementType item);
void TraverseQ(QueueType Queue);


main()
{
    QueueType AQueue;
    QueuePointer CurrPtr;
    QueueElementType AnItem;
    boolean flag;
    char choice;

    //���������� ����� �����
    CreateQ(&AQueue);

    while(TRUE){

        //�������� USER_ID
        printf("USERNAME: ");
        scanf("%s", AnItem.userid);
        fflush(stdin);

        //������� ��� �� ����� ��� ������� �� USER_ID ���� ��� ������
        if(!search_for_userid(AnItem))
            printf("Wrong user ID");
        else
        {
            CurrPtr = AQueue.Front;
            flag = FALSE;
            // ��� � ���� ���� �������� ��� ��� ������� USER_ID
            while((CurrPtr!=NULL) && (flag == FALSE))
            {
                if(strcmp(CurrPtr, AnItem.userid) == 0)
                {
                    printf("You have logged in to the system from another terminal.New access is forbidden.");
                    flag = TRUE;
                }
                else
                    CurrPtr = CurrPtr->Next;
            }
            // �� �� USER_ID ��� ���� ����������� ���� ����
            if(flag == FALSE)
                AddQ(&AQueue,AnItem);

        }
        //������� ��� �������� ��� ������������
        printf("\nNew insertion Y/N (Y=Yes, N=No)? ");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice == 'N')
            break;
    }
    // �������� ��� ��������� ��� �����
    TraverseQ(AQueue);


    system("PAUSE");
    return 0;
}


//��������� boolean search_for_userid
boolean search_for_userid(QueueElementType item)
{
    FILE *fp;
    char str[8];


    if((fp=fopen("I11F4.dat","r")) == NULL)
        printf("PROBLEM OPENING FILE\n");
    else{
        while(!feof(fp))
        {
            fscanf(fp,"%s",&str);
            if(strcmp(str,item.userid) == 0)
            {
                fclose(fp);
                return TRUE;
            }
        }
    }
    fclose(fp);
    return FALSE;
}

//��������� TraverseQ
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
   {
   	    printf("EMPTY Queue\n");
   }
   else
   {
   	    CurrPtr = Queue.Front;
        while ( CurrPtr!=NULL )
        {
            printf("%s ", CurrPtr);
            CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}

void CreateQ(QueueType *Queue)
/* ����������: ���������� ��� ���� ����������� ����.
   ����������: ��� ���� ����������� ����
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����������� ����.
   ����������: ������� �� � ����������� ���� ����� ����.
   ����������: True �� � ���� ����� ����, false  �����������
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ����������� ���� Queue ��� ���  �������� Item.
   ����������: ��������� �� �������� Item ��� ����� ��� ������������ ����� Queue.
   ����������: ��� ������������� ����
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;

    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����������� ����.
   ����������: ������� �� �������� Item ��� ���  ������ ��� ������������ �����,
                �� ��� �����  ����.
   ����������: �� �������� Item ��� ��� ������������� ����������� ����.
   ������:     ������ ����� �����, �� � ���� �����  ����
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
