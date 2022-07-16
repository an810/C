#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char c;
    struct Node* next;
}Node;

Node* makeNode(char x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}

Node* top; 

void initStack()
{
    top = NULL;
}

int stackEmpty()
{
    return top == NULL;
}   

void push(char x)
{
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

char pop()
{
    if (stackEmpty()) return ' ';
    char x = top->c;
    Node* p = top; 
    top = top->next;
    free(p);
    return x;
}

char s[100000];

int match(char a, char b)
{
    if (a == '(' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    return 0;
}

int check(char* s)
{
    initStack();
    for (int i =0; i<strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        } else {
            if (stackEmpty()) return 0;
            char c = pop();
            if (!match(c,s[i])) return 0;
        }
    }
    return stackEmpty();
}

int main()
{
    scanf("%s", s);
    int ans = check(s);
    printf("%d", ans);
    return 0;
}