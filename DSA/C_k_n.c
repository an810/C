// Ckn computation time: mem and w/o mem

#include<stdio.h>
#include<time.h>
#include<string.h>

#define N 100

int D[N][N];

int C1(int n, int k)
{   
    if ((k==0) || (k==n)) return 1;
    else return C1(n-1,k-1) + C1(n-1,k);
}

int C(int n,int k){
    if (D[n][k] == 0) return D[n][k];
    if (k==n || k == 0)
    {
        return 1;
    }
    D[n][k] = C(n - 1, k - 1) + C(n - 1, k);    
    return D[n][k];
}



int main()
{   
    memset(D,0, sizeof(D));
    double time_spent = 0.0;
    clock_t begin = clock();

    printf("%d\n",C(40,30));

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("The elapsed time is %.20Lf seconds\n", time_spent);
    return 0;
}