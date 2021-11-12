#include <stdio.h>
#include <stdlib.h>

#define StackLimit 60   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50

typedef int StackElementType; // ο τύπος των στοιχείων  της στοίβας
                             //ενδεικτικά τύπος int
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
    //Δηλωση στοιχειων
    StackType A;
    StackElementType topElement;

    // Δημιουργια και εισαγωγη δεδομενων στην στοιβα Α
    CreateStack(&A);
    for(int i=1; i<100; i+=2)
    {
        Push(&A,i);
    }

    // Κληση συναρτησης GetTopElementA
    GetTopElementA(&A, &topElement);
    // Εκτυπωση αποτελεσματων
    printf("Top with GetTopElementA = %d\n", topElement);


    // Κληση συναρτησης GetTopElementB
    GetTopElementB(A, &topElement);
    // Εκτυπωση αποτελεσματων
    printf("Top with GetTopElementB = %d\n", topElement);



    system("PAUSE");
    return 0;
}

//Υλοποιηση της συναρτησης GetTopElementA
void GetTopElementA(StackType *Stack, StackElementType *topElement)
{
    Pop(Stack, topElement);
    Push(Stack, *topElement);
}
//Υλοποιηση της συναρτησης GetTopElementΒ
void GetTopElementB(StackType Stack, StackElementType *topElement)
{
    *topElement = Stack.Element[Stack.Top];
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται:    Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


