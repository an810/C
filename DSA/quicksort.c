#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp; 
}

int Partition(int *a, int left, int right)
{
    int i = left;   
    int j = right+1;;
    int pivot = a[left];
    while (1)
    {
        i = i+1;
        while (i <= right && a[i] < pivot) i+=1;
        j-=1;
        while( j>= left && pivot < a[j]) j-=1;
        if (i>=j) break;
        swap(&a[i],&a[j]);
    }
    swap(&a[j], &a[left]);
    return j;
}

void quicksort(int *a, int left, int right)
{
    int index;
    if(left < right)
    {
        index = Partition(a, left, right);
        quicksort(a, left, index-1);
        quicksort(a, index+1, right);
    }
}

int main()
{
    int a[5] = {4,2,7,1,6};
    quicksort(a,0,4);
    for (int i=0; i<5; i++) printf("%d ",a[i]);
    return 0;
}