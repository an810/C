#include<stdio.h>
#include<stdlib.h>


int x[7],n;
int visited[10];
int ans;



int check(int v, int k)
{
    if (visited[v]==1) return 0;
    if (k<6) return 1;
    int sum = x[0]*100+x[1]*10+x[2]-x[3]*100-62+x[4]*1000+x[5]*100+v*10+x[2];
    if (sum == n) return 1;
    else return 0;
}

void Try(int k)
{
    for (int v=1; v<=9; v++)
    {
        if (check(v,k))
        {
            x[k]=v;
            visited[v]=1;
            if(k==6) ans++;
            else Try(k+1);
            visited[v]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int v=1; v<=9; v++) visited[v]=0;
    ans=0;
    Try(0);    
    printf("%d",ans);
    return 0;
}