#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 256

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* makeNode(int data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;   
}

Node* top; 

int stackEmpty()
{
    return top == NULL;
}

void push(int data)
{
    Node* p = makeNode(data);
    p->next = top;
    top = p;
}

int pop()
{
    int ans = top->data;
    Node* p = top;
    top = p->next;
    free(p);
    return ans;
}
// 6 3 6 + 5 * 9 / -
//  636+5*9/-
int main()
{
    top = NULL;
    char cmd[MAX_LEN];
    gets(cmd);
    int result;
    for (int i=0; i<strlen(cmd); i++)
    {
        if (cmd[i] == ' ') continue;
        if (isdigit(cmd[i]))
        {
            int x = cmd[i] - '0';
            push(x);    
        }
        else 
        {
            int a = pop();
            int b = pop();
            if (cmd[i] == '+')
            {
                push(a+b);
            }
            else if (cmd[i] == '-')
            {
                push(b-a);
            }
            else if (cmd[i] == '*')
            {
                push(a*b);
            }
            else if (cmd[i] == '/')
            {
                push(b/a);
            }
        }
    }
    result = pop();
    printf("%d",result);
    return 0;
}

