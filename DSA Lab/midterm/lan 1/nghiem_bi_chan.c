#include <stdio.h>

#define N 100

int a[N];
int x[N][2];
int n, m, T;
int cnt = 0;

void solution(void)
{
    cnt++;
}

void Input(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d  %d", &x[i][0], &x[i][1]);
    }
}

int check(int v, int k)
{
    if (k == n)
    {
        if (T + v != m)
        {
            return 0;
        }
    }
    return 1;
}

void Try(int k)
{
    for (int v = x[k][0]; v <= x[k][1]; v++)
    {
        if (check(v * a[k], k))
        {
            T += (v * a[k]);
            if (k == n)
            {
                solution();
            }
            else
            {
                Try(k + 1);
            }
            T -= (v * a[k]);
        }
    }
}

int main()
{
    T=0;
    Input();
    Try(1);
    printf("%d", cnt);
    return 0;
}
