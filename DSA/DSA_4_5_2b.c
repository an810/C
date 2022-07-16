#include<stdio.h>

int a[100], n, used[100];

void Solution()
{
    for (int i=1; i<=n; i++)
    {
        printf("%d ", a[i] );
    }
    printf("\n");
}

void Try(int k)
{
    // Sk = {1, 2, 3, ..., n} \ {a[1], a[2], ..., a[k-1]}
    for (int y=1; y<=n; y++)
    {
        if (used[y] == 0)
        {
            a[k] = y; used[y] = 1;
            if (k==n) Solution();
            else Try(k+1);
            used[y] = 0;
        }
    }

}

int main()
{
    n=3; 
    for (int i=0; i<n; i++)
    {
        used[i] =0;
    }
    Try(1);
}