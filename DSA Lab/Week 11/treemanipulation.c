#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// general tree

typedef struct Node
{
    int val;
    struct Node* leftchild;
    struct Node* rightsibling;
}Node;

Node* root;

Node* makeNode(int u)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = u;
    p->rightsibling = NULL; p->leftchild = NULL;
    return p;
}

Node* find(Node* r,int u)
{
    if(r == NULL) return NULL;
    if (r->val == u) return r;
    Node* p = r->leftchild;
    while (p != NULL)
    {
        Node* q= find(p,u);
        if (q!= NULL) return q;
        p = p->rightsibling;
    }
    return NULL;
}

void Insert(int u, int v)
{
    Node* p = find(root, v);
    if (p==NULL) return;
    if (p->leftchild == NULL)
    {
        p->leftchild = makeNode(u);
    } else
    {
        Node* temp= p->leftchild;
        while (temp->rightsibling != NULL) temp = temp->rightsibling;
        temp->rightsibling = makeNode(u);
    }
}
    
void preorder(Node* r)
{
    if (r == NULL) return;
    printf("%d ", r->val);
    preorder(r->leftchild);
    preorder(r->rightsibling);
}

void inorder(Node* r)
{
    if (r== NULL) return;
    if (r->leftchild)
    {
        inorder(r->leftchild);
    }
    printf("%d ",r->val);
    if(r->leftchild == NULL) return;
    Node* temp = r->leftchild->rightsibling;
    while(temp)
    {
        inorder(temp);
        temp = temp->rightsibling;
    }
}

void postorder(Node* r)
{
    if (r== NULL) return;
    postorder(r->leftchild);
    printf("%d ", r->val);
    postorder(r->rightsibling);
}


int main()
{
    char cmd[256]= "";
    while (1)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "MakeRoot"))
        {
            int u; scanf("%d",&u);
            root = makeNode(u);
        } else 
        if (!strcmp(cmd, "Insert"))
        {
            int u,v; scanf("%d%d", &u, &v);
            Insert(u,v);
        } else
        if (!strcmp(cmd, "InOrder"))
        {
            inorder(root);
        } else
        if (!strcmp(cmd, "PreOrder"))
        {
            preorder(root);
        } else
        if (!strcmp(cmd, "PostOrder"))
        {
            postorder(root);
        } else break;
    }
    return 0;
}