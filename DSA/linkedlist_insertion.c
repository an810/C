#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *makeNode(int x) 
{
    Node* p= (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Allocation is not successfull\n");
        exit(1);
    } else {
        p->data = x;
        p->next = NULL;
        return p;
    }
}

Node *insert_tohead1(Node *head, int x)
{
    Node* newnode = makeNode(x);
    newnode->next = head;
    head = newnode;
}

void insert_tohead2(Node **head, int x)
{
    Node *newnode = makeNode(x);
    newnode->next = *head;
    *head = newnode;
}

int main()
{
    int n, temp;
    Node* head = NULL;
    printf("Enter n =\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter number %d: \n", i+1); scanf("%d",&temp);
        head = insert_tohead1(head, temp);
        // head = insert_tohead2(&head, temp);
    }
    Node* cur = head;
    while ( cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    return 0;
}
