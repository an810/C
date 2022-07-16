#include<stdio.h>

#define N 100

int a[N];
int n;

void PrintSolution()
{
    for (int i=1; i<=n; i++)   
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for (int y=0; y<=1; y++)
    {
        a[k]=y;
        if (k==n) PrintSolution();
        else Try(k+1);
    }
}

int main()
{
    n=4; 
    Try(1);
    return 0;
}
