#include <stdio.h>
#include <string.h>
#include<stdlib.h>


char * multiply(char * num1, char * num2){
    if(*num1=='0' || *num2=='0') return "0";
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1+len2;
    int *arr = (int*)malloc(sizeof(int)*len); //the number of digits of the result - len is the top;
    memset(arr, 0, sizeof(int)*len); //this is critical;
    for(int i=len1-1; i > -1; i--)
        for(int j=len2-1; j > -1; j--)
            arr[i+j+1] += (num1[i]-'0')*(num2[j]-'0'); //collect result of each position;
    for(int i=len-1; i > 0; i--) //restore the carry for each position and get the final result;
    {
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    char *s = (char*)malloc(sizeof(char)*(len+1)); //converting the digits result to string;
    int index = 0;
    int i = 0;
    if(arr[i]==0) i++; //in case the zero position has no carry, if it does, ignore it;
    while(i < len)
        s[index++] = arr[i++]+'0';
    s[index] = '\0';
    return s;
}

/*int main()
{
    char s1[101],s2[101],s[101];
    scanf(" %s",s1);
    scanf(" %s",s2);
    multiply(s1,s2);
    printf("%s",s);
    return 0;
}*/
/*
#include <stdio.h>
#include <string.h>
 
int main()
{
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;
    char s1[101],s2[101];
    scanf(" %s",s1);
    scanf(" %s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(ans[i] > 0)
            break;
    }
    printf("Product : ");
    for(;i >= 0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
*/