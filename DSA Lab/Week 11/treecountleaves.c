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

int countleave(Node* r)
{
    int ans=0;  
    if (r==NULL) return 0;
    if(r->leftchild == NULL) return 1;
    Node *p = r->leftchild;
    while (p != NULL)
    {
        ans += countleave(p);
        p = p->rightsibling;
    }
    return ans;
}


int countkchild(Node*r, int k)
{
    int cnt =0;
    if (r==NULL) return 0;
    int c =0;
    for (Node*p =r->leftchild; p!=NULL; p=p->rightsibling) c++;
    if(c==k) cnt++;
    for (Node*p =r->leftchild; p!=NULL; p=p->rightsibling) cnt += countkchild(p, k);
    return cnt;
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
        } else
        if (!strcmp(cmd, "CountLeaves"))
        {
            int u; scanf("%d", &u);
            Node* p = find(root,u);
            printf("%d ",countleave(p));
        } else
        if (!strcmp(cmd, "CountKChildren"))
        {
            int u,k; scanf("%d%d", &u, &k);
            Node* p = find(root,u);
            printf("%d ",countkchild(p, k));
        } else break;
    }
    return 0;
}