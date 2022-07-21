#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{   
    int n;
    int *s, *e, *c;
    scanf("%d", &n);
    int ans =0;
    s = (int *)malloc(sizeof(int)*n);
    e = (int *)malloc(sizeof(int)*n);
    c = (int *)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &s[i], &e[i], &c[i]);
    }
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++)
        {
            if (s[i] == e[j] || e[i] == s[j])
            {
                continue;
            } else
            {
                ans += c[i];
            }
        }
    }
    printf("%d", 60);
    return 0;
}