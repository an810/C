#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Max_heapify(int *a, int i, int n)
{
    int left = 2*i, right = 2*i+1;
    int indexM = i;
    if (left <= n && a[left] > a[indexM]) indexM = left;
    if (right <= n && a[right] > a[indexM]) indexM = right;
    if (i != indexM)
    {
        int temp = a[indexM];
        a[indexM] = a[i];
        a[i] = temp;
        Max_heapify(a, indexM, n);
    }
}

void build_maxheap(int* a, int n)
{
    for (int i=n/2; i>=1; i--)
        Max_heapify(a, i, n);
}

void Heapsort(int* a, int n)
{
    build_maxheap(a, n);
    for (int i=1; i<=7; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i=n; i>=n/2; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        Max_heapify(a, 1, i-1);
    }
}

int main()
{
    int a[] = {1, 3, 5, -1, 8, -4, 2};
    for (int i=1; i<=7; i++)
        printf("%d ", a[i]);
    printf("\n");
    Heapsort(a,7);  
    for (int i=1; i<=7; i++)
        printf("%d ", a[i]);
    return 0;
}

