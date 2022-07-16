//in ma tran xoan oc 
#include <stdio.h>

int a[100][100],i,n, d, gt, hang, cot;


void tao(){
    scanf("%d",&n);
    d=0; gt=1; hang=n-1; cot=n-1;
    while(d<=n/2){
        for (i=d;i<=cot;i++) a[d][i]=gt++;
        for(i=d+1;i<=hang;i++) a[i][cot]=gt++;
        for (i=cot-1;i>=d;i--) a[hang][i]=gt++;
        for (i=hang-1;i>d;i--) a[i][d]=gt++;
        d++; hang--; cot--;
    }
}
void in()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
tao();
in();
return 0;

}

