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

    //Δημιουργια κενης ουρας
    CreateQ(&AQueue);

    while(TRUE){

        //Εισαγωγη USER_ID
        printf("USERNAME: ");
        scanf("%s", AnItem.userid);
        fflush(stdin);

        //Ελεγχος για να δουμε αμα υπαρχει το USER_ID μεσα στο αρχειο
        if(!search_for_userid(AnItem))
            printf("Wrong user ID");
        else
        {
            CurrPtr = AQueue.Front;
            flag = FALSE;
            // Οσο η ουρα εχει στοιχεια και δεν βρηκαμε USER_ID
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
            // Αν το USER_ID δεν εχει καταχωρηθει στην ουρα
            if(flag == FALSE)
                AddQ(&AQueue,AnItem);

        }
        //Ερωτηση για συνεχεια του προγραμματος
        printf("\nNew insertion Y/N (Y=Yes, N=No)? ");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice == 'N')
            break;
    }
    // Εκτυπωση τον στοιχειων της ουρας
    TraverseQ(AQueue);


    system("PAUSE");
    return 0;
}


//Υλοποιηση boolean search_for_userid
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

//Υλοποιηση TraverseQ
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
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
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
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
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
