#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


typedef struct
{
    char name[20];
    char phone[10];
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
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
void menu(int *choice);
void BuildBST(BinTreePointer *Root);
void BSTSearchBySubject(BinTreePointer Root, int code);

main()
{
    BinTreePointer ARoot;
    int choice,code;
    BinTreeElementType EmpRec;
    boolean flag;
    BinTreePointer LocPtr;


    //���������� ���� ���
    CreateBST(&ARoot);

    do
    {
        menu(&choice);
        switch(choice)
        {
            case 1: BuildBST(&ARoot); break;

            case 2: printf("Give teacher name? ");
                    fflush(stdin);
                    gets(EmpRec.name);

                    printf("Give teacher phone number? ");
                    fflush(stdin);
                    scanf("%s", EmpRec.phone);

                    printf("Give teacher code? ");
                    scanf("%d", &EmpRec.code);

                    BSTInsert(&ARoot, EmpRec);
                    break;

            case 3: printf("Give teacher name? ");
                    fflush(stdin);
                    gets(EmpRec.name);

                    BSTDelete(&ARoot, EmpRec);
                    break;

            case 4: printf("Give teacher name? ");
                    fflush(stdin);
                    gets(EmpRec.name);

                    BSTSearch(ARoot, EmpRec, &flag, &LocPtr);
                    if(flag == TRUE){
                        printf("%s ",LocPtr->Data.name);
                        printf("%s ",LocPtr->Data.phone);
                        printf("%d ",LocPtr->Data.code);
                        printf("\n");
                    }
                    else
                        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", EmpRec.name);
                    break;

            case 5: printf("Give teacher code? ");
                    scanf("%d", &EmpRec.code);
                    BSTSearchBySubject(ARoot,EmpRec.code);
                    break;

            case 6: InorderTraversal(ARoot); break;
		}
    }while (choice!=7);



    system("PAUSE");
    return 0;
}


//��������� ���������� BSTSearchBySubject
void BSTSearchBySubject(BinTreePointer Root, int code)
{
    if (Root!=NULL) {
        BSTSearchBySubject(Root->LChild,code);
        if(code == Root->Data.code)
        {
            printf("%s ",Root->Data.name);
            printf("%s ",Root->Data.phone);
            printf("%d ",Root->Data.code);
            printf("\n");
        }
        BSTSearchBySubject(Root->RChild,code);
    }
}

//��������� ���������� BuildBST
void BuildBST(BinTreePointer *Root)
{
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType EmpRec;


    if((fp=fopen("I14F5.TXT","r")) == NULL)
        printf("PROBLEM OPENING FILE\n");
    else{
        while(TRUE)
        {
            nscan = fscanf(fp,"%20[^,], %10[^,], %d%c",EmpRec.name,EmpRec.phone,&EmpRec.code,&termch);
            if(nscan==EOF)break;
            if(nscan!=4 || termch!='\n')
            {
                printf("Error\n");
                break;
            }
            BSTInsert(Root, EmpRec);
        }
    }
    fclose(fp);
}

//��������� ���������� menu
void menu(int *choice)
{
    printf("\n           MENOY           \n");
    printf("---------------------------\n");
    printf("1. Create BST \n");
    printf("2. Insert new teacher \n");
    printf("3. Delete a teacher \n");
    printf("4. Search for a teacher \n");
    printf("5. Search by subject \n");
    printf("6. Print teachers \n");
    printf("7. Quit \n\n");
    do
    {
        printf("Epilogh: ");
    	scanf("%d", choice);
    } while (*choice<1  || *choice>7);

}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item.name,LocPtr->Data.name)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.name,LocPtr->Data.name)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item.name);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data.name,Item.name);
        strcpy(LocPtr->Data.phone,Item.phone);
        LocPtr ->Data.code = Item.code;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.name,Parent->Data.name)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue.name,(*LocPtr)->Data.name)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.name,(*LocPtr)->Data.name)>0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.name,(*LocPtr)->Data.name)<0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue.name,(*LocPtr)->Data.name)>0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue.name);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s ",Root->Data.name);
        printf("%s ",Root->Data.phone);
        printf("%d ",Root->Data.code);
        printf("\n");
        InorderTraversal(Root->RChild);
    }
}
