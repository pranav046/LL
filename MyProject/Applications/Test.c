#if 1

#include "Test.h"

static void PrintLinkedList(node* NODE_p)
{
    while( NODE_p != NULL )
    {
        printf("\r\n Value: %d", NODE_p->data);
        NODE_p = NODE_p -> next;
    }
}

static void InsertElementAtBegining(node ** head_ref_p, int data_p)
{
    node * temp;
    temp = (node*)malloc(sizeof(node));

    temp -> data = data_p;
    temp -> next = *head_ref_p;

    *head_ref_p = temp;
}

static void InsertElementAtEnd(node** head_ref_p, int data_p)
{
    node * p, *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = data_p;

    p = *head_ref_p;

    while(p -> next != NULL)
    {
        p = p -> next;
    }

    p -> next = temp;
    temp -> next = NULL;
}

static void InsertElementAfterANode(node** head_ref_p, int data_p, int item_p)
{
    node *p, *temp;
    p = *head_ref_p;

    while(p != NULL) // check for p -> next ! = NULL
    {
        if(p -> data == item_p)
        {
            temp = (node*)malloc(sizeof(node));
            temp -> data = data_p;
            
            temp -> next = p -> next;
            p -> next = temp;
        }
        p = p -> next;
    }

    printf("\r\n %d not present in given linked list", item_p);
}

static void InsertElementBeforeANode(node** head_ref_p, int data_p, int item_p)
{
    node *p, *temp;

    p = *head_ref_p;

    // case: if data to be inserted before head
    if(item_p == (*head_ref_p) -> data)
    {
        temp = (node*)malloc(sizeof(node));
        temp -> data = data_p;

        temp -> next = *head_ref_p;
        *head_ref_p = temp; 
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
        }
        p = p -> next;
    }

    printf("\r\n %d not not found in linked list", item_p);
}

static void InsertElementAtAPosition(node** head_ref_p, int data_p, int pos_p)
{
    node *p, *temp;
    int iLoop;

    temp = (node*)malloc(sizeof(node));
    temp -> data = data_p;

    if(pos_p == 1)
    {
        temp -> next = *head_ref_p;
        *head_ref_p = temp;
        return;
    }

    p = *head_ref_p;

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

}

#if CreateInOneGo

static void CreateLinkedList(node ** head_ref)
{
    int i = 0, data, n;

    node *temp;

    printf("\r\n Enter No. of Nodes : ");
    scanf("%d",&n);

    if(n == 0)
        return;

    temp = *head_ref;

    for( i = 1; i <= n; i++)
    {
        printf("\r\n Enter the data for node ' %d ' : \r\n", i);
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

static void CreateLinkedList(node** head_ref_p)
{
    int n, element, iLoop;
    printf("\r\n Enter No. of Nodes : ");
    scanf("%d",&n);

    *head_ref_p = NULL;

    if(n == 0)
        return;

    printf("\r\n Enter Value of element to be inserted : ");
    scanf("%d", &element);

    InsertElementAtBegining(head_ref_p, element);
    
    for(iLoop = 2; iLoop <= n; iLoop++)
    {
        printf("\r\n Enter Value ofelement to be inserted : ");
        scanf("%d", &element);

        InsertElementAtEnd(head_ref_p, element);
    }
}

#endif

static void ReverseLinkedList(node** head_ref_p)
{
    node *prevnode, *currnode, *nextnode;
    prevnode = NULL;
    currnode = nextnode = *head_ref_p;
    while(nextnode != NULL)
    {
        nextnode = nextnode -> next;
        currnode -> next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    *head_ref_p = prevnode;

}

int main()
{
    node *Head;
    static volatile int data = 0;
    static volatile int item = 0;
    int req = 0;
    tUserReq user_req;
    while(1)
    {
        printf("\r\n-------------------- Availabe Requests------------------");
        printf("\r\n 1.Create Linked List ");
        printf("\r\n 2.Print Linked List ");
        printf("\r\n 3.Insert Element at Begning ");
        printf("\r\n 4.Insert Element at End ");
        printf("\r\n 5.Insert Element Before a Node ");
        printf("\r\n 6.Insert Element After a Node ");
        printf("\r\n 7.Insert Element at a position ");
        printf("\r\n 8.Reverse Singly Linked List ");
        printf("\r\n 9.Exit ");

        printf("\r\n Enter your Choice: ");
        scanf("%d",&req);
        user_req = (tUserReq)req;

        switch(user_req)
        {
            case eCreateLinkedList:
                CreateLinkedList(&Head);
                break;
            case ePrintLinkedList:
                PrintLinkedList(Head);
                break;
            case eInsertAtBegning:
                printf("\r\n Enter Value of Element to be inserted at begning ");
                scanf("%d",&data);
                InsertElementAtBegining(&Head, data);
                break;
            case eInsertAtEnd:
                printf("\r\n Enter Value of Element to be inserted at End ");
                scanf("%d",&data);
                InsertElementAtEnd(&Head, data);
                break;
            case eInsertBeforeANode:
                printf("\r\n Enter Value of Element to be inserted Before Node ");
                scanf("%d",&data);
                printf("\r\n Enter Value of Node before which data is to be inserted ");
                scanf("%d",&item);
                InsertElementBeforeANode(&Head, data, item);
                break;
            case eInsertAfterANode:
                printf("\r\n Enter Value of Element to be inserted After Node ");
                scanf("%d",&data);
                printf("\r\n Enter Value of Node After which data is to be inserted ");
                scanf("%d",&item);
                InsertElementAfterANode(&Head, data, item);
                break;
            case eInsertAtPosition:
                printf("\r\n Enter Value of Element to be inserted at Position ");
                scanf("%d",&data);
                printf("\r\n Enter Value of position of desired Node ");
                scanf("%d",&item);
                InsertElementAtAPosition(&Head, data, item);
                break;
            case eReverseSinglyLinkedList:
                 ReverseLinkedList(&Head);
                break;
            case eExit:
                 exit(0);
                break;
            default:
            printf("\r\n Wrong Choice entered !! \r\n Try Again");
        }
    }

    return 0;
}

#endif
