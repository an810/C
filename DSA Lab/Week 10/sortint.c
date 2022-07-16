#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000
void merge(int a[], int l, int m, int r)
{
    int temp[N];
    int id=0, id1=l, id2=m+1;
    while ( id1 <= m && id2 <= r)
    {
        if (a[id1]<=a[id2])
        {
            temp[id] = a[id1];
            id1++; id++;
        } else 
        {
            temp[id] = a[id2];
            id2++; id++;
        }
    }
    while (id1<= m)
    {
        temp[id] = a[id1];
        id1++; id++;
    }
    while (id2<= r)
    {
        temp[id] = a[id2];
        id2++; id++;
    }
    for (int i=l, j=0; i<=r; i++, j++)
    {
        a[i] = temp[j];
    }
}

void mergesort(int a[], int l, int r)
{
    int m;
    if(l< r)
    {
        m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()  
{
    int a[N];
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    mergesort(a,0,n-1);
    for (int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}