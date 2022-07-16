#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 50
#define max(a,b) a > b ? a : b

typedef struct TNode
{
    char name[MAX_LEN];
    struct TNode* leftmostchild;
    struct TNode* rightsibling;
}Node;

Node* nodes[10001];

int n;

Node* makeNode(char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->leftmostchild = NULL;
    newNode->rightsibling = NULL;
    return newNode;
}

Node* find(char* name)
{
    for (int i=0; i<n; i++)
    {
        if (strcmp(name, nodes[i]->name) == 0) return nodes[i];
    }
    return NULL;
}

void insertNode(Node* node)
{
    n++;
    nodes[n-1] = node;  
}

void addChild(Node* child, Node* parent)
{
    // if (parent->leftmostchild == NULL)
    // {
    //     parent->leftmostchild = child;
    // } else
    // {
    //     Node* temp = parent->leftmostchild;
    //     while (temp->rightsibling != NULL)
    //     {
    //         temp = temp->rightsibling;
    //     }
    //     temp->rightsibling = child;
    // }
    child->rightsibling = parent->leftmostchild;
    parent->leftmostchild = child;
}

int countNode(Node* r)
{
    if (r==NULL) return 0;
    int cnt = 1;
    Node* temp = r->leftmostchild;
    while (temp != NULL)
    {
        cnt += countNode(temp);
        temp = temp->rightsibling;
    }
    return cnt;
}

int height(Node* r)
{
    if (r==NULL) return 0;
    int h = 0;
    Node* temp = r->leftmostchild;
    while (temp != NULL)
    {
        h = max(h, height(temp));
        temp = temp->rightsibling;
    }
    return h+1;
}

int main()
{
    char child_name[MAX_LEN];
    char parent_name[MAX_LEN];
    while (1)
    {
        scanf("%s", child_name);
        if(strcmp(child_name, "***") == 0) break;
        scanf("%s", parent_name);
        Node* child = find(child_name);
        Node* parent = find(parent_name);
        if(child == NULL)
        {
            child = makeNode(child_name);
            insertNode(child);
        }
        if (parent == NULL)
        {
            parent = makeNode(parent_name);
            insertNode(parent);
        }
        addChild(child, parent);
    }
    char cmd[MAX_LEN], name[MAX_LEN];
    while(1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0) break;
        scanf("%s", name);
        Node* p = find(name);
        if (strcmp(cmd,"descendants") == 0)
        {
            int ans = countNode(p);
            printf("%d\n", ans-1);
        }
        if (strcmp(cmd,"generation") == 0)
        {
            int ans = height(p);
            printf("%d\n", ans-1);
        }

    }
    return 0;
}