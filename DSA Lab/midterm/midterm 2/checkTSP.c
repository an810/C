#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    int *route;
    int num_cons;
    int *visited;
    int check = 1;
    int ans = 0;
    scanf("%d", &n);
    route = (int *)malloc(sizeof(int)*n);
    visited = (int *)malloc(sizeof(int)*n);
    int** dis = (int**)malloc((n+1) * sizeof(int*));
        for (int i = 1; i <= n; i++)
            dis[i] = (int*)malloc((n+1) * sizeof(int));

    for (int i=1; i<=n; i++)
    {
        scanf("%d", &route[i]);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &dis[i][j]);
        }
    }
    scanf("%d", &num_cons);
    int** cons = (int**)malloc((num_cons+1) * sizeof(int*));
    for (int i = 1; i <= num_cons; i++)
        cons[i] = (int*)malloc(2 * sizeof(int));

    for (int i=1; i<=num_cons; i++)
    {
        scanf("%d %d", &cons[i][0], &cons[i][1]);
    }
    for (int i=1; i<=n; i++)
    {
        visited[i] = 0;
    }
    for (int i=1; i<=n; i++)
    {
        visited[route[i]] = 1;
        for (int j=1; j<=num_cons; j++)
        {
            if (route[i] == cons[j][1] && visited[cons[j][0]] == 0)
            {
                check =0;
                break;
            } else if (route[i] == cons[j][0] && visited[cons[j][1]] == 1)
            {
                check = 0;
                break;
            } else continue; 
        }
    }
    if (check == 0)
        {
            printf("-1");
        } else {
            for (int i=1; i<n; i++)
            {
                ans += dis[route[i]][route[(i+1)]];
            }
            ans+= dis[route[n]][route[1]];
            printf("%d", ans);
        }
    return 0;
}
