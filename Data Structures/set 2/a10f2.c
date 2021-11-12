#include <stdio.h>
#include <stdlib.h>

#define StackLimit 10  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 10

typedef char StackElementType;  // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος char
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

    // Δημιουργια κενων στοιβων Stack1,Stack2 και Stack3
    CreateStack(&Stack1);
    CreateStack(&Stack2);
    CreateStack(&Stack3);

    // Εισαγωγη στοιχειων στην στοιβα Stack1
    Push(&Stack1,80);
    Push(&Stack1,65);
    Push(&Stack1,83);
    Push(&Stack1,67);
    Push(&Stack1,65);
    Push(&Stack1,76);

    // Εκτυπωση των στοιχειων της Stack1
    printf("\nStack1\n");
    TraverseStack(Stack1);


    //Εισαγωγη των στοιχειων απο την Stack1 στην Stack2
    for(int i=Stack1.Top; i>=0; i--){
        Push(&Stack2,Stack1.Element[i]);
        Pop(&Stack1,&Stack1.Element[i]);
    }
    // Εκτυπωση των στοιχειων της Stack2
    printf("\nStack2\n");
    TraverseStack(Stack2);



    //Εισαγωγη των στοιχειων απο την Stack2 στην Stack3
    for(int i=Stack2.Top; i>=0; i--){
        Push(&Stack3,Stack2.Element[i]);
        Pop(&Stack2,&Stack2.Element[i]);
    }
    // Εκτυπωση των στοιχειων της Stack3
    printf("\nStack3\n");
    TraverseStack(Stack3);



    //Εισαγωγη των στοιχειων απο την Stack3 στην Stack1
    for(int i=Stack3.Top; i>=0; i--){
        Push(&Stack1,Stack3.Element[i]);
        Pop(&Stack3,&Stack3.Element[i]);
    }
    // Εκτυπωση των στοιχειων της Stack1
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
