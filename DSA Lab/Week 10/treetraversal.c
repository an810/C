#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TNode
{
    int id; 
    struct TNode* leftchild;
    struct TNode* rightchild;
} Node;

Node *root;

Node* makeNode(int v)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->leftchild = NULL;
    p->rightchild = NULL;
    return p;
}

Node* find(int v, Node* r)
{
    if (r==NULL) return NULL;
    if (r->id == v) return r;
    Node* p = find(v, r->leftchild);
    if (p!=NULL) return p;
    return find(v, r->rightchild);
}

void addLeft(int u, int v)
{
    Node* p = find(v, root);
    if (p== NULL) return;
    Node* q= find(u, root);
    if (q!=NULL) return; 
    if (p->leftchild != NULL) return;
    q = makeNode(u);
    p->leftchild = q;
}

void addRight(int u, int v)
{
    Node* p = find(v, root);
    if (p == NULL) return;  
    Node* q= find(u, root);
    if (q!=NULL) return; 
    if (p->rightchild != NULL) return;
    q = makeNode(u);
    p->rightchild = q;
}

void preorder(Node* r)
{
    if (r== NULL) return;
    printf("%d ", r->id);
    preorder(r->leftchild);
    preorder(r->rightchild);
}

void inorder(Node* r)
{
    if (r== NULL) return;
    inorder(r->leftchild);
    printf("%d ",r->id);
    inorder(r->rightchild);
}

void postorder(Node* r)
{
    if (r==NULL) return;
    postorder(r->leftchild);
    postorder(r->rightchild);
    printf("%d ",r->id);
}

int main()
{
    char cmd[256]="";
    while(1)
    {
        scanf("%s",cmd);
        if (!strcmp(cmd, "MakeRoot"))
        {
            int u; scanf("%d",&u);
            root = makeNode(u);
        }
        if (!strcmp(cmd, "AddLeft"))
        {
            int u, v; scanf("%d %d", &u, &v);
            addLeft(u,v);
        } else
        if (!strcmp(cmd, "AddRight"))
        {
            int u, v; scanf("%d %d", &u, &v);
            addRight(u,v);
        } else
        if (!strcmp(cmd, "PreOrder"))
        {
            preorder(root);
        } else
        if (!strcmp(cmd, "InOrder"))
        {
            inorder(root);
        } else 
        if (!strcmp(cmd, "PostOrder"))
        {
            postorder(root);
        } else 
        if (!strcmp(cmd, "*")) break;
    }
    return 0;
}