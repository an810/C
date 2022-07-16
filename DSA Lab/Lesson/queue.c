// Hàng đợi - bài toán tìm đường đi trên sơ đồ chuyển trạng thái

/*
    Thuật toán tìm kiếm theo chiều rộng (loang) tim đường đi ngắn nhất trên mô hình chuyển trạng thái 
    - Trạng thái đầu
    - Trạng thái đích
    - Mỗi trạng thái s sẽ có 1 tập N(s) các trạng thái lân cận 
*/

/*
    Bài toán mê cung
    Một mê cung hình chũ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] =1 thể hiện ô (i,j)
    là tường gạch và A[i,j]=0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có 
    thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô 
    trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int row, col;
    int step;
    struct Node* next;
    struct Node* parent;
}Node;

Node* head, *tail;

Node* makeNode(int r, int c, int step, Node* par)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->row = r; p->col = c; p->step = step;
    p->next = NULL; p->parent = par;
    return p;
}

void initQueue()
{
    head = NULL; tail = NULL;
}

int queueEmpty()
{
    return head == NULL && tail == NULL;
}

void push(Node* e)
{
    if (queueEmpty())
    {
        head = e; tail = e; return;
    }
    tail->next = e; tail = e;
}

Node* pop()
{
    if (queueEmpty()) return NULL;
    Node *p = head;
    head = head->next;
    if (head == NULL) tail == NULL;
    return p;
}

int visited[1000][1000];
int A[1000][1000];
int r0, c0, n, m;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

Node* target = NULL;

void initVisited()
{
    for (int i=0; i<=n; i++)
        for (int j = 0; j < m; j++)
        visited[i][j] = 0;        
}

int legal(int r, int c)
{
    return A[r][c] == 0 && visited[r][c] ==0;
}

int isTarget(int r, int c)
{
    return r<1 || r>n || c<1 || c>m;
}

void input()
{
    scanf("%d%d%d%d", &n, &m, &r0, &c0);
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            scanf("%d", &A[i][j]);
}

void solve()
{
    initVisited(); initQueue();
    Node* startNode = makeNode(r0, c0, 0, NULL);
    push(startNode); visited[r0][c0] = 1;
    while(!queueEmpty())
    {
        Node* p = pop();
        for (int k=0; k<4; k++)
        {
            int nr = p->row + dr[k]; 
            int nc = p->col + dc[k];
            if (legal(nr,nc))
            {
                Node* np = makeNode(nr, nc, p->step + 1, p);
                if (isTarget(nr,nc))
                {
                    target = p; // found solution
                    break;
                }
                push(np);
                visited[nr][nc] = 1;
            }
        }
        if (target != NULL) break; // found solution
    }
}

void printPath()
{
    if(target == NULL)
    {
        printf("NOT FOUND\n");
    } else
    {
        Node* stack[1000]; int sz =0;
        Node* p = target;
        while (p!=NULL)
        {
            stack[sz] = p; sz++;
            p=p->parent;
        }
        while (sz > 0)
        {
            p = stack[sz-1];
            printf("%d, %d\n", p->row, p->col);
            sz--;
        }
        printf("Number of steps = %d", target->step);
    }
}

int main()
{
    input(); solve(); printPath();
    return 0;
}
