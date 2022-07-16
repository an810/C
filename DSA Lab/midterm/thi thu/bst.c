#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node 
{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* root = NULL;

Node* makeNode(int val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* find(Node* r, int val)
{
    if (r == NULL) return NULL;
    if (r->val == val) return r;
    Node* p = find(r->left, val);
    if (p != NULL) return p;
    return find(r->right, val);
}

void insert(int val)
{
    Node* p = find(root, val);
    if (p != NULL) return;
    if (root == NULL)
    {
        root = makeNode(val);
        return;
    }
    Node* temp = root;
    while (temp != NULL)
    {
        if (temp->val > val)
        {
            if (temp->left == NULL)
            {
                temp->left = makeNode(val);
                return;
            }
            temp = temp->left;
        } else
        {
            if (temp->right == NULL)
            {
                temp->right = makeNode(val);
                return;
            }
            temp = temp->right;
        }
    }
}

void Preorder(Node* r)
{
    if (r == NULL) return;
    printf("%d ", r->val);
    Preorder(r->left);
    Preorder(r->right);
}

void Postorder(Node* r)
{
    if (r == NULL) return;
    Postorder(r->left);
    Postorder(r->right);
    printf("%d ", r->val);
}


int main()
{
    char cmd[256] = "";
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "insert") == 0)
        {
            int val;
            scanf("%d", &val);
            insert(val);
        }
        else if (strcmp(cmd, "preorder") == 0)
        {
            Preorder(root);
        }
        else if (strcmp(cmd, "inorder") == 0)
        {
            Postorder(root);
        }
        else if (strcmp(cmd, "postorder") == 0)
        {
            Postorder(root);
        }
        else if (strcmp(cmd, "#") == 0)
        {
            break;
        }
    }
    return 0;
}