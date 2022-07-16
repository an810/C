// N queens chưa có con hậu nào đặt sẵn trên bàn cờ

#include<stdio.h>
#define N 100

int n;
int x[N];

void Input()
{
    scanf("%d", &n);
}

int check(int v, int k)
{
    for (int i=1; i<=k-1; i++)
    {
        if (x[i]==v) return 0;
        if (x[i]+i==v+k) return 0;
        if (x[i]-i==v-k) return 0;
    }
}

void solution()
{
    for (int i=1;i<=n;i++) printf("%d ", x[i]); printf("\n");
}

void Try(int k)
{
    for (int v=1; v<=n; v++)
    {
        if (check(v,k))
        {
            x[k] = v;
            if (k==n) solution();
            else Try(k+1);
        }
    }
}

int main()
{   
    Input();
    Try(1);
    return 0;
}

