// largest rectangle
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 60 
#define max(a,b) (a > b ? a : b)

int a[N][N];
int n,m;

void input()
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d", a[i][j]);
}

int large(int *a)
{
    int ans;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            
        }
    }
    return ans;
}

int main()
{
    
    
    return 0;
}


