#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void showdata_of_current_element(int data)
{
    printf("Data = %d\n", data);
}

int main()
{
    Node* head;
    Node* second= NULL;
    Node* third= NULL;

    //allocate memory for 3 nodes in the heap
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    Node* cur; 
    for (cur = head; cur != NULL; cur = cur->next)
    {
        showdata_of_current_element(cur->data);
    }
    return 0;
}
