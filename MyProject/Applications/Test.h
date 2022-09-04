#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef enum
{
    eCreateLinkedList = 1u,
    ePrintLinkedList,
    eInsertAtBegning,
    eInsertAtEnd,
    eInsertBeforeANode,
    eInsertAfterANode,
    eInsertAtPosition,
    eReverseSinglyLinkedList,
    eExit
}tUserReq;