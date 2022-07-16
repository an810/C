#include<stdio.h>

int a[100], n;

void Solution()
{
    for (int i=1; i<=n; i++)
    {
        printf("%d ", a[i] );
    }
    printf("\n");
}

int check(int y, int k)
{
    //return 1 if y!= a[1], a[2],.., a[k-1]
    // otherwise return 0
    for (int j=1; j<=k-1; j++)
    {
        if (y==a[j]) return 0;
    }
    return 1;
}

void Try(int k)
{
    // Sk = {1, 2, 3, ..., n} \ {a[1], a[2], ..., a[k-1]}
    for (int y=1; y<=n; y++)
    {
        if (check(y,k))
        {
            a[k] = y;
            if (k==n) Solution();
            else Try(k+1);
        }
    }

}

int main()
{
    n=3; 
    Try(1);
}