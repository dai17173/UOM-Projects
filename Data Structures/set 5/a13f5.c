#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
    char surname[20];
    char name[20];
    int code;
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {FALSE, TRUE} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
void BuildBSTs(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3);
void menu(int *choice);


main()
{
    BinTreePointer ARoot1,ARoot2,ARoot3,LocPtr;
    int choice,code;
    BinTreeElementType EmpRec;
    boolean flag;


    do
    {
        menu(&choice);
        switch(choice)
        {
            case 1: BuildBSTs(&ARoot1,&ARoot2,&ARoot3); break;

            case 2: printf("Give employee surname? ");
                    fflush(stdin);
                    gets(EmpRec.surname);

                    printf("Give employee name? ");
                    fflush(stdin);
                    gets(EmpRec.name);

                    printf("Give employee code (1=office employee, 2=factory employee, 3=sales representative)? ");
                    scanf("%d", &EmpRec.code);

                    if(EmpRec.code == 1)
                        RecBSTInsert(&ARoot1, EmpRec);
                    else if (EmpRec.code == 2)
                        RecBSTInsert(&ARoot2, EmpRec);
                    else if (EmpRec.code == 3)
                        RecBSTInsert(&ARoot3, EmpRec);
                    break;

            case 3: printf("Give employee surname? ");
                    fflush(stdin);
                    gets(EmpRec.surname);

                    printf("Give employee code (1=office employee, 2=factory employee, 3=sales representative)? ");
                    scanf("%d", &EmpRec.code);

                    if(EmpRec.code == 1)
                        RecBSTSearch(ARoot1, EmpRec, &flag, &LocPtr);
                    else if (EmpRec.code == 2)
                        RecBSTSearch(ARoot2, EmpRec, &flag, &LocPtr);
                    else if (EmpRec.code == 3)
                        RecBSTSearch(ARoot3, EmpRec, &flag, &LocPtr);

                    if(flag == TRUE){
                        printf("%s, ",LocPtr->Data.surname);
                        printf("%s, ",LocPtr->Data.name);
                        printf("%d ",LocPtr->Data.code);
                        printf("\n");
                    }
                    else
                        printf("Employee %s not found\n", EmpRec.surname);
                    break;

            case 4: printf("\nBST office employee \n");
                    RecBSTInorder(ARoot1);
                    printf("\nBST factory employee \n");
                    RecBSTInorder(ARoot2);
                    printf("\nBST sales representative \n");
                    RecBSTInorder(ARoot3);
                    break;
		}
    }while (choice!=5);



    system("PAUSE");
    return 0;
}

//Υλοποιηση Συναρτησης BuildBSTs
void BuildBSTs(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3)
{
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType EmpRec;

    CreateBST(Root1);
    CreateBST(Root2);
    CreateBST(Root3);

    if((fp=fopen("I13F5.txt","r")) == NULL)
        printf("PROBLEM OPENING FILE\n");
    else{
        while(TRUE)
        {
            nscan = fscanf(fp,"%20[^ ] %20[^ ] %d%c",EmpRec.surname,EmpRec.name,&EmpRec.code,&termch);
            if(nscan==EOF)break;
            if(nscan!=4 || termch!='\n')
            {
                printf("Error\n");
                break;
            }
            if(EmpRec.code == 1)
                RecBSTInsert(Root1, EmpRec);
            else if (EmpRec.code == 2)
                RecBSTInsert(Root2, EmpRec);
            else if (EmpRec.code == 3)
                RecBSTInsert(Root3, EmpRec);
        }
    }
    fclose(fp);
}

//Υλοποιηση Συναρτησης menu
void menu(int *choice)
{
    printf("\n           MENOY           \n");
    printf("---------------------------\n");
    printf("1. Create BSTs from file \n");
    printf("2. Insert new employee \n");
    printf("3. Search for an employee \n");
    printf("4. Traverse Inorder \n");
    printf("5. Quit \n\n");
    do
    {
        printf("Epilogh: ");
    	scanf("%d", choice);
    } while (*choice<1  || *choice>5);
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy((*Root)->Data.surname,Item.surname);
        strcpy((*Root)->Data.name,Item.name);
        (*Root) ->Data.code = Item.code;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.surname,(*Root)->Data.surname)<0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.surname,(*Root)->Data.surname)>0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %s EINAI HDH STO DDA\n", Item.surname);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.surname,Root->Data.surname)<0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.surname,Root->Data.surname)>0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%s, ",Root->Data.surname);
        printf("%s, ",Root->Data.name);
        printf("%d), ",Root->Data.code);
        RecBSTInorder(Root->RChild);
    }
}
