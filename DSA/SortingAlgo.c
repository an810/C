//Insertion sort
#include <stdio.h>
void insertionSort(int A[], int n)
{
    for (int k = 1; k < n; k++) //Find the correct position for A[k], which is the first element in the unsorted array
    {
        int pos = k;
        int temp = A[k];
        while (pos>0 && temp < A[pos-1]) 
        {
            A[pos] = A[pos-1];
            pos = pos-1;
        }
        A[pos] = temp;
    }
}

//Selection sort
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int A[], int n)
{
    int index_min;
    for (int i = 0; i < n-1; i++)
    {
        index_min = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[index_min]) index_min = j;
        }
        swap(&A[i],&A[index_min]);
    }
}

//Bubble sort
#include<stdbool.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int a[], int n)
{
    bool sorted = false;
    for (int i = 1; i <= n-1; i++)
    {
        if (sorted == false)
        {
            sorted = true;
            for (int j = 0; j <= n-i-1; j++)
            {
                if (a[j] > a[j+1])
                {
                    swap(&a[j],&a[j+1]);
                    sorted = false; 
                }
            }
        }
    }
}

//Merge sort 
#define M 10000
void merge(int A[], int first, int mid, int last)
{
    int tempA[M]; 
    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;
    int index = first1;
    for(;(first1<=last1) && (first2<=last2);++index) //So sánh hai subarrays và copy vào arry temp
    {
        if (A[first1] < A[first2])
        {
            tempA[index] = A[first1];
            first1++;
        }
        else
        {
            tempA[index] = A[first2];
            first2++;
        }
    }
    
    for (; first1<=last1; first1++,index++) //Array 2 đã kết thúc, copy phần còn lại của array 1 vào temp
        tempA[index] = A[first1];
    for (; first2<=last2; first2++,index++) //Array 1 đã kết thúc, copy phần còn lại của array 2 vào temp
        tempA[index] = A[first2];
    for (index = first; index <= last; index++) //Copy temp vào A
        A[index] = tempA[index];
}

void mergeSort(int A[], int first, int last)
{
    if (first < last)
    {
        int mid = (first+last)/2;
        mergeSort(A,first,mid);
        mergeSort(A,mid+1,last);
        merge(A,first,mid,last);
    }
}

//Quick sort
//The pivot is the first element of the array
#include <stdio.h>
#include <stdbool.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int Partition(int A[], int left, int right)
{
    int i = left;
    int j = right+1;
    int pivot = A[left];
    while (true)
    {
        i = i+1;
        while (i <= right && A[i] < pivot) i = i+1;
        j = j-1;
        while (j >= left && pivot < A[j]) j = j-1;
        if (i >= j) break;
        swap(&A[i], &A[j]);
    }
    swap(&A[j], &A[left]);
    return j;
}
void quickSort(int A[], int Left, int Right)
{
    int index_pivot;
    if (Left < Right)
    {
        index_pivot = Partition(A, Left, Right);
        quickSort(A, Left, index_pivot-1);
        quickSort(A, index_pivot+1, Right);
    }
}

//Quick sort
//The pivot is the last element of the array
#include <stdio.h>
#include <stdbool.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partitionlast(int A[],int left,int right)
{
    int pivot = A[right];
    int j = left - 1;
    for (int i = left; i < right; i++)
    {
        if (pivot >= A[i])
        {
            j = j+1;
            swap(&A[i],&A[j]);
        }
    }
    A[right] = A[j+1];
    A[j+1] = pivot;
    return j+1;   
}
void quicksort(int A[], int Left, int Right)
{
    int index_Pivot;
    if (Left < Right)
    {
        index_Pivot = partitionlast(A,Left,Right);
        quicksort(A,Left,index_Pivot-1);
        quicksort(A,index_Pivot+1,Right);
    }
}

//Quick sort
//The pivot is the middle element of the array
#include <stdio.h>
#include <stdbool.h>
int quicksort(int arr[],int low,int high)
{
    if(low>=high)
        return 0;

    int mid=(low+high)/2;
    int pivot=arr[mid];
    int i=low,j=high;
    int temp;
    while(i<j)
    {
        if(arr[i]>=pivot && arr[j]<=pivot)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
    quicksort(arr,low,mid);
    quicksort(arr,mid+1,high);
}

// Heap sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void MAX_HEAPIFY(int A[], int i, int n) // A[0] ... A[n-1]
{
    int leftC = 2*i+1;
    int rightC = 2*i+2;
    int indexM = i;
    if (A[leftC] > A[indexM] && leftC < n)
        indexM = leftC;
    if (A[rightC] > A[indexM] && rightC < n)
        indexM = rightC;
    if (i!=indexM)
    {
        swap(&A[i], &A[indexM]);
        MAX_HEAPIFY(A,indexM,n);
    }
}
void BUILD_MAX_HEAP(int A[], int n)
{
    for (int i = (n/2)-1; i>= 0; i--)
        MAX_HEAPIFY(A,i,n);
}
void HEAPSORT(int A[], int n)
{
    BUILD_MAX_HEAP(A,n);
    for (int i = n-1; i >= 1; i--)
    {
        swap(&A[0],&A[i]);
        MAX_HEAPIFY(A,0,i);
    }
}