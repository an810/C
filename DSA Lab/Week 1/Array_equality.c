#include<stdio.h>
#define MAX 1000

int a[MAX],b[MAX];
int n,m;
int T;
int main()
{
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        for (int i=0; i<m; i++) scanf("%d", &b[i]);
        int ans = 0;
        if (n!=m)
        {
            ans = 0;
        }else {
            ans = 1;
            for (int i=0; i<n; i++)
            {
                if (a[i]!=b[i])
                {
                  ans = 0;
                  break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}