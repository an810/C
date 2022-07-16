#include<stdio.h>

int m,n, a[100];

void PrintSolution()
{
    for (int i=1; i<=m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Try(int k)
{
    //Sk = a[k-1]+1, a[k-1]+2,.., n-(m-k)
    for (int y=a[k-1]+1; y<=n-m+k; y++)
    {
        a[k] = y;
        if (k==m) PrintSolution();
        else Try(k+1);
    }
}

int main()
{
    n=5; m=3;
    Try(1);
}