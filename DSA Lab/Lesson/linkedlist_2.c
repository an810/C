// Loại bỏ 1 phần tử khỏi danh sách trong liên kết đơn 

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
    for (Node* p=h; p->next != NULL; p=p->next)
    {
        printf("%d ", p->id);
    }
    printf("\n");
}

Node* removenode(int v, Node* h)
{
    if (h==NULL) return NULL;
    if (h->id == v)
    {
        Node* tmp=h;
        h = h->next;
        free(tmp);
        return h;
    }
    Node* p= h;
    while (p->next != NULL)
    {
        if (p->next->id == v)
        {
            Node* tmp=p->next;
            p->next = tmp->next;
            free(tmp);
            return h;
        }
        p = p->next;
    }
    return h;
}

/*
    Ngoài ra còn có cách đệ quy 
    Node* removenode(int v, Node* h)
    {
        if (h==NULL) return NULL;
        if (h->id == v)
        {
            Node* tmp = h;
            h = h->next;
            free(tmp);
            return h;
        }
        h->next = removenode(v, h->next);
        return h;
    }
*/

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

int main()
{
    Node* h=NULL;
    h = makeNode(1);
    for (int i=2; i<=5; i++)
    {
        h = insertbefore(i,i-1,h);
    }
    printlist(h);
    h = removenode(3,h);
    printlist(h);
    return 0;
}