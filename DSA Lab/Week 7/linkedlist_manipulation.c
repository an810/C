#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int val;
    struct Node* next;
}Node;

Node* makeNode(int k)
{
    Node* p= (Node*)malloc(sizeof(Node));
    p->val = k;
    p->next = NULL;
    return p;
}

int check(Node*head, int k)
{
    if (head == NULL) return 0;
    Node* p = head;
    while (p!= NULL)
    {
        if (p->val == k) return 1;
        p=p->next;
    }
    return 0;
}

Node* addfirst(Node* head, int k)
{
    Node* p = makeNode(k);
    p->next = head;
    head = p;
    return head;  
}

Node* addlast(Node* head, int k)
{
    Node* temp = makeNode(k);
    Node* p = head;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    while (p->next != NULL)
    {
        p= p->next;
    }
    p->next = temp;
    return head;
}

Node* addafter(Node* head, int u,int v)
{
    if (head == NULL || check(head,u) == 1 || check(head,v)==0) return head;
    Node* p = head;
    while (p!=NULL)
    {
        if (p->val==v)
        {
            Node* newnode = makeNode(u);
            newnode->next = p->next;
            p->next = newnode;
            return head;
        } else p=p->next;
    }
    return head;    
}

Node* addbefore(Node* head, int u, int v)
{
    if (head == NULL || check(head,u) ==1 || check(head,v)==0) return head;
    if (head->val == v)
    {
        Node* temp = makeNode(u);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* p= head;
    while (p->next != NULL)
    {
        if (p->next->val == v)
        {
            Node* newnode = makeNode(u);
            newnode->next= p->next;
            p->next=newnode;
            return head;
        }
        p=p->next;
    }
    return head;
}

Node *Remove(Node *head,int x)
{
    if (head==NULL)
    {
        return head;
    }
    if (head->val==x) head=head->next;
    Node* temp=head;
    while (temp->next!=NULL)
    {
        if (temp->next->val==x)
        {
            temp->next=temp->next->next;
        } else temp=temp->next;
    }
    return head;
}

Node* reverse(Node* head)   
{
    if (head == NULL || head->next == NULL) return head;
    Node* p = head;
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
    int n;
    scanf("%d",&n);
    Node* head=NULL;
    for (int i=0; i<n; i++)
    {
        int new_val;
        scanf("%d",&new_val);
        head=addlast(head,new_val);
    }
    Node* cur=NULL;
    char cmd[]="";
    while (1)
    {
        scanf("%s",cmd);
        if (!strcmp(cmd,"addfirst"))
        {
            int x;
            scanf("%d",&x);
            if (check(head,x)==0) head=addfirst(head,x);
        } else 
        if (!strcmp(cmd,"addlast"))
        {
            int x;
            scanf("%d",&x);
            if (check(head,x)==0) head=addlast(head,x);
        } else
        if (!strcmp(cmd,"addafter"))
        {
            int u,v;
            scanf("%d%d",&u,&v);
            head=addafter(head,u,v);
        } else
        if (!strcmp(cmd,"addbefore"))
        {
            int u,v;
            scanf("%d%d",&u,&v);
            head=addbefore(head,u,v);
        } else
        if (!strcmp(cmd,"remove")) 
        {
            int x;
            scanf("%d",&x);
            head=Remove(head,x);
        } else
        if (!strcmp(cmd,"reverse")) 
        {
            head=reverse(head);
        } else
        if (!strcmp(cmd,"#")) break;
    }
    cur=head;
    while (cur!=NULL)
    {
        printf("%d ",cur->val);
        cur=cur->next;
    }
};