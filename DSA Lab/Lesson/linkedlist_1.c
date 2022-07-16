// Chèn 1 phần tử vào trước 1 phần tử xác định cho trước

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
    Node *p =h;
    while (p->next != NULL)
    {
        if (p->next->id == v)
        {
            Node* tmp = makeNode(id);
            tmp->next = p->next;
            p->next = tmp;
            return h;
        }
        p = p->next;
    }
    return h;
}

/*
    Ngoài ra còn có cách đệ quy 

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

*/

int main()
{
    Node* h=NULL;
    h=makeNode(1);
    for (int i=2; i<=5; i++)
    {
        h = insertbefore(i,i-1,h);
    }
    printlist(h);
    h = insertbefore(6,3,h);
    printlist(h);
    return 0;
}