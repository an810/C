#include<stdio.h>
#include<stdlib.h>
void demo1()
{
    int a[10000]; // stactic (fixed size) allocation
    int n;
    printf("Input number of elements: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf("Input the %d element ", i+1);
        scanf("%d", &a[i]);
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("%d", sum);
}
void demo2()
{
    int* a;
    int n;
    printf("Input number of elements: ");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        printf("Input the %d element ", i+1);
        scanf("%d", &a[i]);
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("%d", sum);
    free(a);
}

int main()
{
    demo2();
    return 0;
}