#include<stdio.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head;

Node *makeNode(int v) // Allocate memory for a new node
{
    Node* p= (Node*)malloc(sizeof(Node));
    // Node* p = new Node; -> this is the same in C++
    p->data = v; p->next = NULL;
    return p;
}

void printLust(Ndoe* head)
{
    Node* cur = head;
    //for (cur = head; cur != NULL; cur = cur->next)
    //    printf("%d ", cur->data);
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

