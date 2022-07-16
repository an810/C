#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int a[], int l, int m, int r)
{
    int temp[100000];
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

int binarySearch(int arr[], int l, int r, int key)
{
    if (l<=r)
    {
        int mid = (l+r)/2;
        if (arr[mid] == key) return mid;
        else if (key < arr[mid]) binarySearch(arr, l,mid-1,key);
        else return binarySearch(arr, mid+1, r, key);
    }
    return -1;
}

int main()
{
    int n, M;
    int count=0;
    int index;
    scanf("%d %d", &n, &M);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n-1);
    // for (int i=0; i<n; i++)
    // {
    //     int target = M - a[i];
    //     index = binarySearch(a, i+1, n-1, target);
    //     if (index > 0) count++;
    // }
    int left = 0, right = n-1;
    while (left < right)
    {
        if (a[left] + a[right] == M)
        {
            count++;
            left++;right--;
        } else if (a[left] + a[right] < M) left++;
        else if (a[left] + a[right] > M) right--;
    }
    printf("%d", count);
    return 0;
}