// Đảo ngược thứ tự của các phần tử trong linkedlist

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int id;
    struct Node* next;
}Node;

Node* makeNode(int id)
{
    Node* p= (Node*)malloc(sizeof(Node));
    p->id = id;
    p->next = NULL;
    return p;
}

void printlist(Node* h)
{
    for (Node* p=h; p!= NULL;p=p->next )
    {
        printf("%d ", p->id);
    }
    printf("\n");
}

Node* insertbefore(int id, int v, Node* h)
{
    if (h==NULL) return NULL;
    if (h->id == v) 
    {
        Node* tmp = makeNode(id);
        tmp->next = h;
        return tmp;
    }
    h->next = insertbefore(id, v, h->next);
    return h;
}

Node* reverse(Node* h)   
{
    Node* p = h;
    Node* pp = NULL;
    Node* np = NULL;
    while (p != NULL)
    {
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

int main()
{
    Node* h=NULL;
    h=makeNode(1);
    for (int i=2; i<=5; i++)
    {
        h = insertbefore(i,i-1,h);
    }
    printlist(h);
    h = reverse(h);
    printlist(h);
    return 0;
}