#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ULL unsigned long long
#define M 10007

int h(ULL k)
{
    return k%M;
}

typedef struct node
{
    ULL key;
    struct node *next;
}node;

node *T[M];

node* insertList(node* head, ULL key)
{
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->key = key;
    newNode->next = head;
    return newNode;
}

node* findList(node* head, ULL key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

int find (ULL key)
{
    int i = h(key);
    node* temp = findList(T[i], key);
    if (temp != NULL) return 1;
    else return 0;
}

int insert (ULL key)
{
    int i = h(key);
    node* temp = findList(T[i], key);
    if (temp != NULL) return 0;
    else
    {
        T[i] = insertList(T[i], key);
        return 1;
    }
}

int main()
{
    for (int i = 0; i < M; i++) T[i] = NULL;
    int n = 10;
    ULL k;
    printf("Enter %d elements in the database: ",n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &k);
        insert(k);
    }
    ULL key;
    printf("Find the element you want: key ="); scanf("%d", &key);
    int res = find(key);
    printf("%d", res);
    return 0;
}