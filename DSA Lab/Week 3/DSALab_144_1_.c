// De quy co nho 


#include <stdio.h>

#define MAX 1000
#define P 1000000007
int M[MAX][MAX]; //M[k][n] stores the value of C(k,n)//
void initialization(void)
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            M[i][j]=-1;
        }
    }
}
int C(int k, int n)
{
    if (k == 0 || k == n)
        M[k][n] = 1;
    else if (M[k][n] == -1)
        M[k][n] = (C(k,n-1)+C(k-1,n-1))%(int)P;
    return M[k][n];
}
int main(void)
{
    initialization();
    int k; int n;
    scanf("%d %d", &k, &n);
    printf("%d\n", C(k,n));
    return 0;
}