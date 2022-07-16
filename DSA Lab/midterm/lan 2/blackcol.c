#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 1000

// int main()
// {
//     int n,m, ans=0;
//     int **a=(int**)malloc(n*sizeof(int*));
//     int *col = (int*)malloc(m*sizeof(int));
//     scanf("%d %d", &n,&m);
//     for (int i=0; i<n; i++)
//     {
//         a[i] = (int*)malloc(m*sizeof(int));
//         for (int j=0; j<m; j++)
//         {
//             scanf("%d", &a[i][j]);
//         }
//     }
//     for (int i=0; i<m; i++)
//     {
//         col[i]=0;
//     }
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<m; j++)
//         {
//             if (a[i][j]==1) col[j]++;
//         }
//     }
//     for (int i=0; i<m; i++)
//     {
//         if (col[i]== n) ans++;
//     }
//     printf("%d", ans);
//     return 0;
// }

int main()
{
    int n,m, ans=0;
    int a[Max][Max];
    int col[Max];
    scanf("%d %d", &n,&m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<m; i++)
    {
        col[i]=0;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (a[i][j]==1) col[j]++;
        }
    }
    for (int i=0; i<m; i++)
    {
        if (col[i] == n) ans++;
    }
    printf("%d", ans);
    return 0;
}