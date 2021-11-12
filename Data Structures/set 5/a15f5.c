#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {FALSE, TRUE} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
int RightNodeCount(BinTreePointer Root);

main()
{
    BinTreePointer ARoot;
    BinTreeElementType number,count;


    //���������� ���� ���
    CreateBST(&ARoot);

    printf("Enter numbers to insert into tree (-1 to stop) \n");
    while(TRUE)
    {
        //������� �� ��� ��� �������
        printf("Enter number: ");
        scanf("%d", &number);
        if(number == -1) break;
        RecBSTInsert(&ARoot,number);
    }

    //K���� ��� ��������� RightNodeCount � ����� ���������� ���� �������
    count = RightNodeCount(ARoot);
    printf("RightNodeCount = %d \n", count);


    system("PAUSE");
    return 0;
}


//��������� ���������� RightNodeCount
int RightNodeCount(BinTreePointer Root)
{
     BinTreeElementType left,right;

     left=0;
     right=0;

     if(BSTEmpty(Root))
        return 0;
     if( Root->LChild != NULL)
        left = RightNodeCount(Root->LChild);
     if( Root->RChild != NULL)
        right = RightNodeCount(Root->RChild)+1;

    return left+right;
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
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
            printf("To %d EINAI HDH STO DDA\n", Item);
}

