#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubblesort(int a[], int n)
{
    int sorted = 0;
    for (int i=0; i<n-1; i++)
    {
        sorted = 1;
        for (int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j+1] = a[j];
                a[j] = temp;
                sorted = 0;
            }
        }
        if (sorted == 1) break;
    }
}

int main()
{
    int a[5]={4,2,1,5,3};
    bubblesort(a,5);
    for (int i=0; i<5; i++) printf("%d ",a[i]);
    return 0;
}