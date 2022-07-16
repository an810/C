#include<stdio.h>
#include<stdlib.h>


int* getRow(int rowIndex){
    int*ans = calloc(rowIndex + 1, sizeof(int));
    long temp=1;
    ans[0]=1;
    for(int i=1,up=rowIndex;i<=rowIndex;i++,up--){
        temp=temp*up/i;
        ans[i]=temp;
    }
    return ans;
}

int main()
{
    int n;
    int *a = (int*)malloc((n+1)*sizeof(int));
    printf("Enter nth row (0th- first row): \n");
    scanf("%d",&n);
    a = getRow(n);
    for (int i=0; i<=n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}