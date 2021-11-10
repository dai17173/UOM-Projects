#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {FALSE, TRUE}boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
int BSTDepth(BinTreePointer *Root);

main()
{
    BinTreePointer ARoot;
    int vath;

    //Δημιουργεια κενου ΔΔΑ
    CreateBST(&ARoot);

    //Εισαγωγη χαρακτηρων
    RecBSTInsert(&ARoot,'P');
    RecBSTInsert(&ARoot,'R');
    RecBSTInsert(&ARoot,'O');
    RecBSTInsert(&ARoot,'C');
    RecBSTInsert(&ARoot,'E');
    RecBSTInsert(&ARoot,'D');
    RecBSTInsert(&ARoot,'U');
    RecBSTInsert(&ARoot,'R');
    RecBSTInsert(&ARoot,'E');

    //Η συναρτηση BSTDepth επιστρεφει το βαθος και το εμφανιζουμε
    vath = BSTDepth(&ARoot);
    printf("To vathos toy DDA einai: %d\n", vath);


    system("PAUSE");
    return 0;
}

//Υλοποιηση συναρτησης BSTDepth
int BSTDepth(BinTreePointer *Root)
{
    int LDepth,RDepth;

    if(BSTEmpty(*Root))
        return 0;
    else
    {
        LDepth = BSTDepth(&(*Root)->LChild);
        RDepth = BSTDepth(&(*Root)->RChild);

        if( LDepth>RDepth )
            return LDepth+1;
        else
            return RDepth+1;
    }
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %c EINAI HDH STO DDA\n", Item);
}
