#include<stdio.h>
#define N 1000000
int main()
{
    int n, cnt = 1, max=0, a[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n-1; i++)
    {
        if (a[i] < a[i+1])
        {
            cnt++;
            if (max < cnt) max = cnt;
        } else {
            cnt = 1;
            continue;
        }
    }
    printf("%d ",max);
    return 0;
}