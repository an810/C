#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct Node
{
    int val;
    struct Node* leftchild;
    struct Node* rightsibling;
}TreeNode;

TreeNode *root;

TreeNode* makeNode(int val) 
{
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->val = val;
    newnode->leftchild = NULL;
    newnode->rightsibling = NULL;
    return newnode;
}

TreeNode* find(TreeNode *root, int val)
{
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    TreeNode* p = root->leftchild;
    while (p != NULL)
    {
        TreeNode* q = find(p, val);
        if (q != NULL) return q;
        p = p->rightsibling;
    }
    return NULL;
}

void Insert(int val1, int val2)
{
    TreeNode* p = find(root, val2);
    if (p == NULL) return;
    if (p->leftchild == NULL)
    {
        p->leftchild = makeNode(val1);
    } else
    {
        TreeNode* temp = p->leftchild;
        while (temp->rightsibling != NULL) temp = temp->rightsibling;
        temp->rightsibling = makeNode(val1);
    }
}

int height(TreeNode* r)
{
    int count = 0;
    if (r == NULL) return 0;
    TreeNode* temp = r->leftchild;
    while (temp != NULL)
    {
        count = max(count, height(temp));
        temp = temp->rightsibling;
    }
    return count+1;
}

int depth(TreeNode* r)
{
    if (r == NULL) return 0;
    int count = 1;
    if (root==r) return count;
    TreeNode* p = root;
    TreeNode* temp = p->leftchild;
    while (temp != NULL)
    {
        if (temp == r) return count + 1;
        temp = temp->rightsibling;
    }
    return depth(p->leftchild)+1;
}

int main()
{
    char cmd[256];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*")==0) break;
        else if (strcmp(cmd, "MakeRoot")==0)
        {
            int val;
            scanf("%d", &val);
            root = makeNode(val);
        } 
        else if (strcmp(cmd, "Insert")==0)
        {
            int val1, val2;
            scanf("%d%d", &val1, &val2);
            Insert(val1, val2);
        }
        else if (strcmp(cmd, "Height")==0)
        {
            int val;
            scanf("%d", &val);
            printf("%d\n", height(find(root, val)));
        }
        else if (strcmp(cmd, "Depth")==0)
        {
            int val;
            scanf("%d", &val);
            printf("%d\n", depth(find(root, val)));
        }
    }
    
    return 0;
}