#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LEN 256
#define max(a,b) a > b ? a : b

typedef struct tnode
{
    char name[MAX_LEN];
    struct tnode* leftmostchild; 
    struct tnode* rightsibling;
}Treenode;

typedef struct lnode
{
    bool isRoot;
    Treenode* nodePtr;
    struct lnode* next;
}Linkedlist;

Treenode* createTreenode(char* name)
{
    Treenode* newTNode = (Treenode*)malloc(sizeof(Treenode));
    strcpy(newTNode->name, name);
    newTNode->leftmostchild = NULL;
    newTNode->rightsibling = NULL;
    return newTNode;
}

Linkedlist* createLinkedlist(char* name)
{
    Linkedlist* newLNode = (Linkedlist*)malloc(sizeof(Linkedlist));
    newLNode->isRoot = true;
    newLNode->nodePtr = createTreenode(name);
    newLNode->next = NULL;
    return newLNode;
}

Linkedlist* find(char* name, Linkedlist* head)
{
    while(head)
    {
        if (strcmp(name, head->nodePtr->name) == 0) return head;
        head = head->next;
    }
    return NULL;
}






int main()
{
    
    return 0;
}