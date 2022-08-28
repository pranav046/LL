#include <stdio.h>
#include <stdlib.h>

#define CreateOneByOne        0
#define CreateInOneGo         !CreateOneByOne

typedef struct node
{
    int data;
    struct node *next;
}node;

static void PrintLinkedList(node* NODE_p)
{
    while( NODE_p != NULL )
    {
        printf("\r\n Value: %d", NODE_p->data);
        NODE_p = NODE_p -> next;
    }
}


static void InsertElementAtBegining(node * head_ref_p, int data_p)
{
    node * temp;
    temp = (node*)malloc(sizeof(node));

    temp -> data = data_p;
    temp -> next = head_ref_p;

    head_ref_p = temp;
}

static void InsertElementAtEnd(node* head_ref_p, int data_p)
{
    node * p, *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = data_p;

    p = head_ref_p;

    while(p -> next != NULL)
    {
        p = p -> next;
    }

    p -> next = temp;
    temp -> next = NULL;
}

static void InsertElementAfterANode(node* head_ref_p, int data_p, int item_p)
{
    node *p, *temp;
    p = head_ref_p;

    while(p != NULL)
    {
        if(p -> data == item_p)
        {
            temp = (node*)malloc(sizeof(node));
            temp -> data = data_p;
            
            temp -> next = p -> next;
            p -> next = temp;
            return;
        }
        p = p -> next;
    }

    printf("\r\n %d not present in given linked list", item_p);
    return;
}

static void InsertElementBeforeANode(node* head_ref_p, int data_p, int item_p)
{
    node *p, *temp;

    p = head_ref_p;

    // case: if data to be inserted before head
    if(item_p == head_ref_p -> data)
    {
        temp = (node*)malloc(sizeof(node));
        temp -> data = data_p;

        temp -> next = head_ref_p;
        head_ref_p = temp; 
        return;
    }

    while(p != NULL)
    {
        if(p -> next -> data == item_p)
        {
            temp = (node*)malloc(sizeof(node));
            temp -> data = data_p;
            
            temp -> next = p -> next;
            p -> next = temp;
            return;
        }
        p = p -> next;
    }

    printf("\r\n %d not not found in linked list", item_p);
}

static void InsertElementAtAPosition(node* head_ref_p, int data_p, int pos_p)
{
    node *p, *temp;
    int iLoop;

    temp = (node*)malloc(sizeof(node));
    temp -> data = data_p;

    if(pos_p == 1)
    {
        temp -> next = head_ref_p;
        head_ref_p = temp;
        return;
    }

    p = head_ref_p;

    for(iLoop = 1; iLoop < pos_p - 1 && (p != NULL); iLoop++)
    {
        p = p -> next;
    }
    if(p == NULL)
    {
        printf("\r\n There are less than %d elements in Linked list",pos_p);
    }
    else
    {
        temp -> next = p -> next;
        p -> next = temp;
    }
    return;

}

#if CreateInOneGo

static void CreateLinkedList(node * head_ref)
{
    int i = 0, data, n;

    node *temp;

    printf("\r\n Enter No. of Nodes");
    scanf("%d",&n);

    if(n == 0)
        return;

    temp = head_ref;

    for( i = 1; i <= n; i++)
    {
        printf("\r\n Enter the data for node ' %d ' \r\n", i);
        scanf("%d", &data);

        temp -> data = data;

        if(i == n)
        {
            temp -> next = NULL;
        }
        else
        {
            temp -> next = (node*)malloc(sizeof(node));
        }
        temp = temp -> next;
    }
}
#else

static void CreateLinkedList(node* head_ref_p)
{
    int n, element, iLoop;
    printf("\r\n Enter No. of Nodes");
    scanf("%d",&n);

    head_ref_p = NULL;

    if(n == 0)
        return;

    printf("\r\n Enter element to be inserted");
    scanf("%d", &element);

    InsertElementAtBegining(head_ref_p, element);
    
    for(iLoop = 2; iLoop <= n; iLoop++)
    {
        printf("\r\n Enter element to be inserted");
        scanf("%d", &element);

        InsertElementAtEnd(head_ref_p, element);
    }
}

#endif

static void ReverseLinkedList(node* head_ref_p)
{
    node *prevnode, *currnode, *nextnode;
    prevnode = NULL;
    currnode = nextnode = head_ref_p;
    while(nextnode != NULL)
    {
        nextnode = nextnode -> next;
        currnode -> next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head_ref_p = prevnode;
}

int main()
{
    node *Head;

    Head = (node*)malloc(sizeof(node));

    CreateLinkedList(Head);

    PrintLinkedList(Head);

    ReverseLinkedList(Head);

    printf("\r\n Reversed Linked List:");
    
    PrintLinkedList(Head);

    return 0;
}