// permutation generation
#include<stdio.h>
#include<string.h>
#define N 100

int n;
int x[N];
int mark[N];

void solution()
{
    for (int i=1; i<= n; i++) printf("%d", x[i]);
    printf("\n");
}

void Try(int k) 
{
    for (int v=1; v <= n; v++)
    {
        if (!mark[v])
        {
            x[k]=v;
            mark[v]=1;
            if (k==n) 
            {
                solution();
            } else Try(k+1);
            mark[v]=0;
        }
    }
}

int main()
{
    memset(mark,0,sizeof(mark));
    scanf("%d", &n);
    Try(1);
    return 0;
}