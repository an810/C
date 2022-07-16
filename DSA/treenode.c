#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treeNode
{
    char data;
    struct treeNode* leftmost_child;
    struct treeNode* right_siblings;
}treeNode;

treeNode *root;

treeNode* makeNode(char data)
{
    treeNode* p = (treeNode*)malloc(sizeof(treeNode));
    p->data = data;
    p->leftmost_child = NULL;
    p->right_siblings = NULL;
    return p;
}

void preorder(tree)

int main()
{
    
    return 0;
}