#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 50

typedef struct TNode
{
    char from_num[MAX_LEN];
    int nbcalls;
    int duration;
    struct TNode* next;
}Node;

Node* root;

Node* makeNode(char* number,int nbcalls, int duration)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nbcalls = nbcalls;
    newNode->duration = duration;
    return newNode;
}



int main()
{
    
    return 0;
}