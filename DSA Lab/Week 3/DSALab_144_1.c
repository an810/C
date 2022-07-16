#include<stdio.h>
#include<stdlib.h>
int nCr(int n, int k){
    if (k == 1 || k == n) return 1;
    if (n <= 2) return 1;
    int mod = 1e9 + 7;
    long long int *arr;

    arr = (long long int *)calloc(n, sizeof(long long int));
    arr[0] = 1;arr[1] = 1;
    for (int i = 2; i < n; ++i){
        //printf("%d\n", i);
        arr[i] = 1;
        for (int j = i - 1; j > 0; --j){
            arr[j] += arr[j - 1];
            arr[j] %= mod;
        }
    }
    //for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    return (arr[k] + arr[k - 1]) % mod;
}
int main(){
    
    int n, k;
    scanf("%d%d", &k, &n);
    printf("%d", nCr(n, k));
    
}