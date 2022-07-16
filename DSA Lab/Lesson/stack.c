// Ngăn xếp - bài toán kiểm tra tính hợp lệ của biểu thức ngoặc

/*
Kiểm tra tính hợp lệ của biểu thức ngoặc: một biểu thức ngoặc được biểu diễn bởi 1 xâu kí tự gồm các ký tự (, ), [, ], {, }.
Kiểm tra xem biểu thức ngoặc có hợp lệ hay không
VD: ()[{}()[]] : hợp lệ
    ()[{}([)[]] : không hợp lệ
Thuật toán: 
- Duyệt dãy ngoặc từ trái qua phải 
    + Nếu gặp dấu ngoặc mở thì đẩy ngoặc mở đó vào ngăn xếp
    + Nếu gặp ngoặc đóng (ký hiệu C)
        ~ Nếu ngăn xếp đó không có dấu ngoặc mở thì trả về FLASE
        ~ Ngược lại, lấy một ngoặc mở ra khỏi ngăn xếp ký hiệu O, nếu O và C không khớp nhau thì trả về FALSE
- Kết thúc duyệt, nếu ngăn xếp không rỗng thì trả về FALSE, ngược lại trả về TRUE
*/

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

Node* top; // -> pointer to the top of the stack 

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