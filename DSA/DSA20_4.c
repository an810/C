#include<stdio.h>
#include<time.h>
#include<string.h>
/*
long long C(int n, int k)
{
    
    if ((k==0) || ( k==n)) return 1;
    else return C(n-1,k-1) +C(n-1,k);
}

int main()
{
    double time_spent = 0.0;
    clock_t begin = clock();
    printf("%ld\n",C(50,15));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);


    return 0;
}
*/


int Palindrome(char* s, int start, int end)
{
    if (start >= end) return 1;
    else {
        if (s[start] == s[end])
            Palindrome(s, start+1, end-1);
        else return 0;
    }
}

int main()
{
    char s[] = "NOKKINGLLON";
    printf("%d", Palindrome(s,0,strlen(s)-1));
    return 0;
}