#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a,b) ((a)>(b)?(a):(b))

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{   
    int n;
    int *s, *e, *c;
    scanf("%d", &n);
    int ans =-1;
    s = (int *)malloc(sizeof(int)*n);
    e = (int *)malloc(sizeof(int)*n);
    c = (int *)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &s[i], &e[i], &c[i]);
    }
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (s[i] > s[j])
            {
                swap(&s[i], &s[j]);
                swap(&e[i], &e[j]);
                swap(&c[i], &c[j]);
            }
        }
    }
    int index =0;
    while (index < n)
    {
        int start = s[index];
        int end = e[index];
        int cost = c[index];
        int total_cost = cost;
        for (int i=index+1; i<n; i++)
        {
            if (s[i] > end)
            {
                total_cost += c[i];
                end = e[i];
            }   
        }
        ans = max(ans, total_cost);
        index++;
    }  
    printf("%d\n", ans);
    return 0;
}