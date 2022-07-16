#include<stdio.h>

void InsertionSort(int a[], int n)
{
    for (int k=1; k<=n-1; k++)
    {
        //find the correct position for a[k]
        //a[k-1], a[k-2],.. a[0]
        int pos = k;
        while (pos >= 1 && a[k] < a[pos-1]) pos = pos - 1;
        int temp = a[k];
        for (int j=k-1; j>=pos; j--) a[j+1] = a[j];
        a[pos]= temp;
    }
}

int main()
{
    int a[5] = {3,15,1,7,2};
    InsertionSort(a,5);
    for (int i=0; i<5;i++) printf("%d ",a[i]);
    return 0;
}