#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TPosition
{
    int row, col;
    int step;
}Position;

typedef struct TNode
{
    Position position;
    struct TNode* next;
}Node;

Node* head=NULL;
Node* tail=NULL;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int n,m;
int A[1000][1000];
int start_row, start_col;
int visited[1000][1000];

Node* makeNode(int r, int c, int step)
{
    Node* p = (Node*)malloc(sizeof(Node));
    (p->position).row = r;
    (p->position).col = c;
    (p->position).step = step;
    p->next = NULL;
    return p;
}

int queueEmpty()
{
    return head == NULL && tail == NULL;
}

void push(int r, int c, int step)
{
    Node* p = makeNode(r, c,step);
    if (head == NULL)
    {
        head =p; tail= p; return;
    }
    tail->next=p; tail=p;
}

Position pop()
{
    Node* tmp = head;
    Position pos = head->position;
    head = head->next;
    if(head==NULL) tail = NULL;
    free(tmp);
    return pos;
}

int check(int r, int c)
{
    return A[r][c] == 0 && !visited[r][c];
}

int finalPosition(int r, int c)
{
    return r<1 || r>n || c<1 || c>m;
}

int solve()
{
    for (int i=0; i<1000; i++)
        for (int j=0; j<1000; j++)
            visited[i][j] =0;
    push(start_row, start_col, 0);
    visited[start_row][start_col] = 1;
    while (!queueEmpty())
    {
        Position p = pop();
        for (int k=0; k<4; k++)
        {
            int new_row = p.row + dr[k];
            int new_col = p.col + dc[k];
            if (finalPosition(new_row, new_col))
            {
                return p.step +1;
            }
            if (check(new_row, new_col))
            {
                push(new_row, new_col, p.step+1);
                visited[new_row][new_col] = 1;
            }
        }
    }
    return -1;
}

void input()
{
    scanf("%d%d%d%d", &n, &m, &start_row, &start_col);
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

int main()
{
    input();
    int ans = solve();
    printf("%d", ans);
    return 0;
}
