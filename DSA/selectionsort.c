#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void SelectionSort(int a[], int n)
{
    for (int k=0; k<n-1; k++)
    {
        //find the smallest a[k].. a[n-1]
        int indexS = k;
        for (int i=k+1; i<=n-1; i++)
        {
            if (a[i]<a[indexS]) indexS = i;
        }
        int temp = a[indexS]; a[indexS] = a[k]; a[k] = temp;
    }
}

int main()
{
    int a[5]={8,4,2,5,6};
    SelectionSort(a,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }   
    return 0;
}