#include <stdio.h>
#define QueueLimit 53 //�� ���� �������� ��� �����

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void DisplayQA(QueueType *Q);
void DisplayQB(QueueType Q);

main()
{
    QueueType AQueue;

    // ���������� �����
    CreateQ(&AQueue);

    //��������� ��� ���� �� ���� ��������� �������� 1 ��� 100
    for(int i=1; i<100; i+=2)
    {
        AddQ(&AQueue,i);
    }

    // ����� ���������� DisplayQA
    DisplayQA(&AQueue);
    // ����� ���������� DisplayQ�
    DisplayQB(AQueue);


    system("PAUSE");
    return 0;
}

//��������� ���������� DisplayQA
void DisplayQA(QueueType *Q)
{
    QueueElementType item;
    QueueType TempQ;

    printf("Elements with DisplayQA: ");
    while(!EmptyQ(*Q))
    {
        RemoveQ(Q,&item);
        AddQ(&TempQ,item);
        printf("%d ", item);
    }
    RemoveQ(&TempQ,&item);
    RemoveQ(&TempQ,&item);
    printf("\n");

    while(!EmptyQ(TempQ))
    {
        RemoveQ(&TempQ,&item);
        AddQ(Q,item);
    }
}

//��������� ���������� DisplayQB
void DisplayQB(QueueType Queue)
{
	int current;
	current = Queue.Front;
	printf("Elements with DisplayQB: ");
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}


void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}

