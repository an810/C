#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30

int n;
int c[N][N];
int x[N];
int d;
int min_distance;
int visited[N];
int Cm;

void input()
{
    scanf("%d", &n);
    Cm = 1e9;
    for (int i=0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            scanf("%d", &c[i][j]);
            if (i!=j && Cm > c[i][j]) Cm=c[i][j];
        }               
    }
        
}

int check(int v, int k)
{
    return visited[v] == 0;
}

void Solution()
{
    if (d+ c[x[n]][x[1]] < min_distance)
    {
        min_distance = d+ c[x[n]][x[1]];
    }
}

void Try(int k)
{
    for (int v=2; v<=n; v++)
    {
        if (check(v,k))
        {
            x[k] = v; visited[v]=1;
            d = d+ c[x[k-1]][x[k]];
            if (k==n) Solution();
            else 
            {
                int g = d+ Cm*(n-k+1);
                if (g<min_distance)
                    Try(k+1);
            }
            visited[v] = 0; 
            d = d - c[x[k-1]][x[k]];
        }
    }
}


int main()
{
    input();
    for (int i=1; i <= n; i++) visited[i] =0;
    d =0;
    x[1]=1; visited[1]=1;
    min_distance = 1e9;
    Try(2);
    printf("%d", min_distance);
    return 0;
}