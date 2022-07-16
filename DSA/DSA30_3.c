#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}

void algo_1(int *a, int size)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int maxsum= a[0];
    for (int i=0; i< size; i++)
    {
        for (int j=i; j<size; j++)
        {
            int sum =0;
            for (int k=i; k<=j; k++)
            {
                sum += a[k];
                if (sum > maxsum) maxsum = sum;
            }
        }
    }
    printf("%d\n", maxsum);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds\n", time_spent);
}

void algo_2(int *a, int n)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int maxsum = INT_MIN;
    for (int i=0; i<n; i++)
    {
        int sum = 0;
        for (int j=i; j<n; j++)
        {
            sum += a[j];
            if (sum > maxsum) maxsum = sum;
        }
    }
    printf("%d\n", maxsum);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds\n", time_spent);
}

void algo_3(int *a, int n)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int s = a[0];
    int e = a[0];
    for (int i=1; i<n; i++)
    {
        e = max(a[i],a[i]+e);
        s = max(s,e);
    }
    printf("%d\n", s);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %.9f seconds\n", time_spent);
}


int main()
{
    int n;
    
    int choice;
    do {
        printf("1. Create array\n");
        printf("2. Algorithm 1\n");
        printf("3. Algorithm 2\n");
        printf("4. Algorithm 3\n");
        printf("5. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the size of array: \n");
                scanf("%d",&n);
                int *a = (int*)malloc(n * sizeof(int));
                for (int i=0; i<n; i++)
                {
                     a[i] = rand() % 100;
                }
                break;
            case 2:
                algo_1(a,n);
                break;
            case 3:
                algo_2(a,n);
                break;
            case 4:
                algo_3(a,n);
                break;
            case 5:
                break;               
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;
}