#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 100
#define min(a,b) a < b ? a : b

int n;
int c[N][N];
int ans = 9999;

int x[N];
int mark[N];

void solution()
{
    int sum=0;
    for (int i=1; i<= n; i++) 
    {        
        if (sum > ans) break;
        if (i==1)
        {
            sum += c[0][x[i]];
            sum += c[x[i]][x[i]+n];
        }else
        if (i==n)
        {
            sum+= c[x[n-1]+n][x[n]];
            sum+= c[x[n]][x[n]+n];
            sum+= c[x[n]+n][0];
        }else 
        {
            sum+= c[x[i-1]+n][x[i]];
            sum+= c[x[i]][x[i]+n];
        }
    }
    ans = min(ans, sum);
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
    for (int i=0; i<2*n+1; i++)
    {
        for (int j=0; j<2*n+1; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    Try(1);
    printf("%d",ans);
    return 0;
}