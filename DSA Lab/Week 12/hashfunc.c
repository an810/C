#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int M;
int hash(char* s)
{
    int n = strlen(s);
    int res = 0;
    for (int i=0; i<n; i++)
    {
        res = (res*256 +s[i]) %M;
    }
    return res;
}


int main()
{
    int num;
    scanf("%d %d", &num, &M);
    for (int i= 0; i<num; i++)
    {
        char s[200];
        scanf("%s",s);
        printf("%d\n", hash(s));
    }
    return 0;
}